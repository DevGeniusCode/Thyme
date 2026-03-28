/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief String class handing "wide" chars.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "unicodestring.h"
#include "asciistring.h"
#include "errorcodes.h"
#include "memdynalloc.h"
#include <captainslog.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

#if defined BUILD_WITH_ICU
#include <unicode/ustring.h>
#include <unicode/ubidi.h>
#elif defined PLATFORM_WINDOWS
#include <wctype.h>
#endif

#ifndef GAME_DLL
SimpleCriticalSectionClass *g_unicodeStringCriticalSection = nullptr;
#endif

Utf16String const Utf16String::s_emptyString;

Utf16String::Utf16String(const unichar_t *s) : m_data(nullptr)
{
    if (s != nullptr) {
        const size_type len = static_cast<size_type>(u_strlen(s));

        if (len > 0) {
            Ensure_Unique_Buffer_Of_Size(len + 1, false, s, nullptr);
        }
    }
}

Utf16String::Utf16String(Utf16String const &string) : m_data(string.m_data)
{
    // #TODO Remove critical section and put atomic reference counter when standalone.

    ScopedCriticalSectionClass cs(g_unicodeStringCriticalSection);

    if (m_data != nullptr) {
        ++m_data->ref_count;
    }
}

Utf16String::~Utf16String()
{
    Release_Buffer();
}

void Utf16String::Validate() {}

const unichar_t *Utf16String::Peek() const
{
    captainslog_dbgassert(m_data != nullptr, "null string ptr");

    return m_data->Peek();
}

unichar_t *Utf16String::Peek()
{
    captainslog_dbgassert(m_data != nullptr, "null string ptr");

    return m_data->Peek();
}

void Utf16String::Release_Buffer()
{
    ScopedCriticalSectionClass cs(g_unicodeStringCriticalSection);

    Validate();

    if (m_data != nullptr) {
        if (--m_data->ref_count == 0) {
            g_dynamicMemoryAllocator->Free_Bytes(m_data);
        }

        m_data = nullptr;
    }
}

void Utf16String::Ensure_Unique_Buffer_Of_Size(
    size_type chars_needed, bool keep_data, const unichar_t *str_to_cpy, const unichar_t *str_to_cat)
{
    Validate();

    if (m_data != nullptr && m_data->ref_count == 1 && m_data->num_chars_allocated >= chars_needed) {
        if (str_to_cpy != nullptr) {
            // #BUGFIX Originally uses u_strcpy here. Use memmove to support overlaps gracefully.
            captainslog_dbgassert(u_strlen(str_to_cpy) == chars_needed - 1, "Length does not match");
            memmove(Peek(), str_to_cpy, chars_needed * sizeof(value_type));
        }

        if (str_to_cat != nullptr) {
            u_strcat(Peek(), str_to_cat);
        }

    } else {
        const int required_size = sizeof(unichar_t) * chars_needed + sizeof(UnicodeStringData);

        captainslog_relassert(required_size <= MAX_LEN, CODE_02, "Size exceeds max len");

        const int alloc_size = g_dynamicMemoryAllocator->Get_Actual_Allocation_Size(required_size);
        UnicodeStringData *new_data =
            reinterpret_cast<UnicodeStringData *>(g_dynamicMemoryAllocator->Allocate_Bytes_No_Zero(alloc_size));

        new_data->ref_count = 1;
        new_data->num_chars_allocated = (alloc_size - sizeof(UnicodeStringData)) / sizeof(unichar_t);
#ifdef GAME_DEBUG_STRUCTS
        new_data->debug_ptr = new_data->Peek();
#endif

        if (m_data != nullptr && keep_data) {
            u_strcpy(new_data->Peek(), Peek());
        } else {
            *new_data->Peek() = U_CHAR('\0');
        }

        if (str_to_cpy != nullptr) {
            u_strcpy(new_data->Peek(), str_to_cpy);
        }

        if (str_to_cat != nullptr) {
            u_strcat(new_data->Peek(), str_to_cat);
        }

        Release_Buffer();
        m_data = new_data;
        Validate();
    }
}

Utf16String::size_type Utf16String::Get_Length() const
{
    if (m_data != nullptr) {
        return static_cast<size_type>(u_strlen(m_data->Peek()));
    }

    return 0;
}

void Utf16String::Clear()
{
    Release_Buffer();
}

unichar_t Utf16String::Get_Char(size_type index) const
{
    captainslog_dbgassert(index >= 0, "Index must be equal or larger than 0.");
    captainslog_dbgassert(index < Get_Length(), "Index must be smaller than length.");

    if (m_data != nullptr) { // #TODO Remove condition if possible; Utf8String does not have it
        return m_data->Peek()[index];
    }

    return U_CHAR('\0');
}

const unichar_t *Utf16String::Str() const
{
    static const unichar_t *TheNullChr = U_CHAR("");

    if (m_data != nullptr) {
        return Peek();
    }

    return TheNullChr;
}

unichar_t *Utf16String::Get_Buffer_For_Read(size_type len)
{
    captainslog_dbgassert(len > 0, "No need to allocate 0 len strings.");

    Ensure_Unique_Buffer_Of_Size(len + 1, false, nullptr, nullptr);

    return Peek();
}

void Utf16String::Set(const unichar_t *str)
{
    if (m_data != nullptr || str != m_data->Peek()) {
        const size_type len = str ? static_cast<size_type>(u_strlen(str)) : 0;

        if (len != 0) {
            Ensure_Unique_Buffer_Of_Size(len + 1, false, str, nullptr);
        } else {
            Release_Buffer();
        }
    }
}

void Utf16String::Set(Utf16String const &string)
{
    ScopedCriticalSectionClass cs(g_unicodeStringCriticalSection);

    if (&string != this) {
        Release_Buffer();
        m_data = string.m_data;

        if (string.m_data != nullptr) {
            ++m_data->ref_count;
        }
    }
}

/**
 * Converts a Utf8 string to Utf16
 */
void Utf16String::Translate_Internal(const char *utf8_string, const size_type utf8_len)
{
    Release_Buffer();

#if defined BUILD_WITH_ICU
    // Use ICU converters.
    if (utf8_len > 0) {
        int32_t utf16_len;
        UErrorCode error = U_ZERO_ERROR;
        // Get utf16 string length.
        u_strFromUTF8(nullptr, 0, &utf16_len, utf8_string, utf8_len, &error);

        if (U_SUCCESS(error) && utf16_len > 0) {
            // Allocate and fill new utf16 string.
            unichar_t *utf16_buffer = Get_Buffer_For_Read(utf16_len);
            u_strFromUTF8(utf16_buffer, utf16_len, nullptr, utf8_string, utf8_len, &error);

            if (U_FAILURE(error)) {
                Clear();
            } else {
                // Add null terminator manually.
                utf16_buffer[utf16_len] = U_CHAR('\0');
            }
        }
    }
#elif defined PLATFORM_WINDOWS
    // Use WIN32 API converters.
    if (utf8_len > 0) {
        // Get utf16 string length.
        const size_type utf16_len = MultiByteToWideChar(CP_UTF8, 0, utf8_string, utf8_len, nullptr, 0);

        if (utf16_len > 0) {
            // Allocate and fill new utf16 string.
            unichar_t *utf16_buffer = Get_Buffer_For_Read(utf16_len);
            MultiByteToWideChar(CP_UTF8, 0, utf8_string, utf8_len, utf16_buffer, utf16_len);

            // Add null terminator manually.
            utf16_buffer[utf16_len] = U_CHAR('\0');
        }
    }
#else
    // Naive copy, this is what the original does.
    for (size_type i = 0; i < utf8_len; ++i) {
        unichar_t c = static_cast<unichar_t>(utf8_string[i]);
        Concat(c);
    }
#endif
}

void Utf16String::Translate(Utf8String const &utf8_string)
{
    Translate_Internal(utf8_string.Str(), utf8_string.Get_Length());
}

void Utf16String::Translate(const char *utf8_string)
{
    const size_type utf8_len = static_cast<size_type>(strlen(utf8_string));
    Translate_Internal(utf8_string, utf8_len);
}

void Utf16String::Concat(unichar_t c)
{
    unichar_t str[2];

    str[0] = c;
    str[1] = U_CHAR('\0');
    Concat(str);
}

void Utf16String::Concat(const unichar_t *s)
{
    const size_type add_len = static_cast<size_type>(u_strlen(s));

    if (add_len > 0) {
        if (m_data != nullptr) {
            const size_type cur_len = static_cast<size_type>(u_strlen(Peek()));
            Ensure_Unique_Buffer_Of_Size(cur_len + add_len + 1, true, nullptr, s);
        } else {
            Set(s);
        }
    }
}

void Utf16String::Trim()
{
    // No string, no Trim.
    if (m_data == nullptr) {
        return;
    }

    unichar_t *str = Peek();

    // Find first none space in string if not the first.
    for (unichar_t i = *str; i != U_CHAR('\0'); i = *(++str)) {
        if (!u_isspace(i)) {
            break;
        }
    }

    // If we had some spaces and moved Str, Set string to that position.
    if (str != Peek()) {
        Set(str);
    }

    // Oops, Set call broke the string.
    if (m_data == nullptr) {
        return;
    }

    const size_type len = static_cast<size_type>(u_strlen(Peek()));

    for (size_type i = len - 1; i >= 0; --i) {
        if (!u_isspace(Get_Char(i))) {
            break;
        }

        Remove_Last_Char();
    }
}

namespace {

/**
 * @section SAGE_RTL_SYSTEM SAGE Engine Hebrew RTL-to-Visual Conversion System
 * * OVERVIEW:
 * The SAGE engine renders text strictly from Left-to-Right (LTR). To support Right-to-Left (RTL)
 * languages like Hebrew, we must pre-process strings into a "Visual" layout.
 * A simple character reversal is insufficient because it breaks numbers, punctuation,
 * and engine-specific placeholders.
 *
 * THE CORE CHALLENGE: "Atomic Tokens"
 * The engine utilizes custom placeholders (e.g., {%s}, {&G}, {\n}, %02d) for dynamic
 * data injection and UI formatting. A naive reversal would turn "{%s}" into "s%{",
 * which the engine's parser would fail to recognize, leading to broken UI and missing data.
 *
 * THE SOLUTION: Token-Safe BiDi Pipeline
 * This implementation follows a 4-stage pipeline to ensure linguistic correctness
 * while preserving engine-level logic:
 *
 * 1. TOKEN IDENTIFICATION (is_token_at):
 * The string is scanned for SAGE-specific patterns (bracketed variables, printf
 * specifiers, and UI hotkeys).
 *
 * 2. PUA MASKING (ProcessBiDiLine - Phase 1):
 * Each identified token is "masked" by replacing it with a single character from the
 * Unicode Private Use Area (PUA), starting at 0xE000. Since these are single characters,
 * they are immune to internal reversal. By treating them as LTR-strong characters,
 * we ensure the BiDi algorithm positions them correctly relative to Hebrew text.
 *
 * 3. REORDERING (ICU or Fallback):
 * - If BUILD_WITH_ICU is defined: Uses the industry-standard Unicode Bidirectional
 * Algorithm (ubidi_writeReordered) to handle mirroring (e.g., parentheses),
 * numeric runs, and neutral character bias.
 * - Fallback: A manual algorithm that mirrors specific brackets and ensures
 * alphanumeric runs (numbers/English) stay LTR within the reversed Hebrew string.
 *
 * 4. TOKEN EXPANSION (ProcessBiDiLine - Phase 2):
 * The PUA characters are replaced back with their original, uncorrupted
 * multi-character sequences (e.g., 0xE000 -> "{%s}").
 *
 * VERTICAL INTEGRITY (Utf16String::Reverse):
 * To prevent the entire document from being inverted vertically, the system processes
 * text line-by-line. It recognizes both standard '\n' and the engine's legacy "{\n}"
 * tag as valid line boundaries, ensuring the top-to-bottom reading order is preserved.
 *
 * TEST CASES:
 * - Input (Logical):  "Price: {%d} credits"
 * - Output (Visual): "credits {%d} :Price" (Assuming Hebrew words for Price/Credits)
 * - Input (Logical):  "Class "A""
 * - Output (Visual): ""A" ssalC" (With correct quote mirroring)
 */

// Checks for explicit SAGE engine placeholders so they can be isolated from BiDi logic.
static bool is_token_at(const unichar_t* str, size_t i, size_t len, size_t& out_len) {
    if (str[i] == '{') {
        // Matches engine placeholders like {%s}, {&G}, {%.0f%%}
        if (i + 1 < len && (str[i+1] == '%' || str[i+1] == '&')) {
            size_t j = i + 2;
            while (j < len && str[j] != '}') j++;
            if (j < len && str[j] == '}') {
                out_len = j - i + 1;
                return true;
            }
        }
    }
    else if (str[i] == '%') {
        // Matches literal "%%"
        if (i + 1 < len && str[i+1] == '%') {
            out_len = 2;
            return true;
        }
        // Matches unbracketed formatters like %02d, %2.2d, %ls, etc.
        size_t j = i + 1;
        while (j < len && str[j] >= '0' && str[j] <= '9') j++;
        if (j < len && str[j] == '.') {
            j++;
            while (j < len && str[j] >= '0' && str[j] <= '9') j++;
        }
        bool found_letter = false;
        while (j < len && ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))) {
            found_letter = true;
            j++;
        }
        if (found_letter) {
            out_len = j - i;
            return true;
        }
    }
    return false;
}

#ifndef BUILD_WITH_ICU
static unichar_t mirror_char(unichar_t c) {
    switch (c) {
        case '(': return ')'; case ')': return '(';
        case '[': return ']'; case ']': return '[';
        case '{': return '}'; case '}': return '{';
        case '<': return '>'; case '>': return '<';
        default: return c;
    }
}

// Helper block to safely encapsulate digit testing, including Arabic-Indic numerals
static bool is_digit(unichar_t c) {
    return (c >= '0' && c <= '9') ||
           (c >= 0x0660 && c <= 0x0669) || // Arabic-Indic digits
           (c >= 0x06F0 && c <= 0x06F9);   // Eastern Arabic-Indic digits
}

static bool is_ltr_or_num_or_pua(unichar_t c) {
    return is_digit(c) ||
           (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= 0xE000 && c <= 0xE0FF); // Custom Private Use Area tokens
}

static Utf16String reverse_line_fallback(const unichar_t* buffer, size_t* start, size_t end) {
    Utf16String reversed_line;
    size_t i = *start;

    if (i > end) return reversed_line;
    size_t len = end - i + 1;
    unichar_t* temp = new unichar_t[len + 1];

    for (size_t k = 0; k < len; ++k) {
        temp[k] = mirror_char(buffer[end - k]);
    }
    temp[len] = U_CHAR('\0');

    size_t run_start = 0;
    while (run_start < len) {
        if (is_ltr_or_num_or_pua(temp[run_start])) {
            size_t run_end = run_start;
            while (run_end + 1 < len) {
                if (is_ltr_or_num_or_pua(temp[run_end + 1])) {
                run_end++;
                } else if ((temp[run_end + 1] == ':' || temp[run_end + 1] == '.' || temp[run_end + 1] == ',') &&
                           is_digit(temp[run_end]) &&
                           run_end + 2 < len &&
                           is_digit(temp[run_end + 2])) {
                    // Prevent splitting digits separated by standard neutral punctuation (colons, periods, commas).
                    // This ensures time formats like '1:00' and decimals like '1.00' stay as a single LTR run.
                    run_end += 2;
                } else {
                    break;
                }
            }
            size_t rl = run_end - run_start + 1;
            for (size_t k = 0; k < rl / 2; ++k) {
                std::swap(temp[run_start + k], temp[run_end - k]);
            }
            run_start = run_end + 1;
        } else {
            run_start++;
        }
    }

    reversed_line += temp;
    delete[] temp;
    *start = end + 1;
    return reversed_line;
}
#endif

// Shared helper function that runs BiDi logic safely on a single line
// preserving Custom Engine Tokens via PUA (Private Use Area) masking.
static Utf16String ProcessBiDiLine(const unichar_t* line_buf, size_t line_len, bool visualToLogical) {
    if (line_len == 0) return Utf16String();

    std::vector<Utf16String> tokens;
    unichar_t *working = new unichar_t[line_len + 1];
    size_t w_idx = 0;

    // 1. Scan line and replace engine tokens with sequential PUA characters
    // to shield them from BiDi manipulation
    for (size_t i = 0; i < line_len; ) {
        size_t tok_len = 0;
        if (is_token_at(line_buf, i, line_len, tok_len)) {
            unichar_t* tok_buf = new unichar_t[tok_len + 1];
            for (size_t k = 0; k < tok_len; ++k) tok_buf[k] = line_buf[i + k];
            tok_buf[tok_len] = U_CHAR('\0');

            tokens.push_back(Utf16String(tok_buf));
            delete[] tok_buf;

            // U+E000 acts as a strong LTR 'letter' mapping to the protected token
            working[w_idx++] = static_cast<unichar_t>(0xE000 + tokens.size() - 1);
            i += tok_len;
        } else {
            working[w_idx++] = line_buf[i++];
        }
    }
    working[w_idx] = U_CHAR('\0');
    size_t working_len = w_idx;

    unichar_t* reordered = new unichar_t[working_len + 1];
    int32_t out_len = 0;

#if defined BUILD_WITH_ICU
    UErrorCode errorCode = U_ZERO_ERROR;
    UBiDi* bidi = ubidi_openSized(working_len, 0, &errorCode);
    if (U_SUCCESS(errorCode)) {
        // Tells the BiDi Engine whether to work forward or backward!
        ubidi_setInverse(bidi, visualToLogical);
        ubidi_setPara(bidi, working, working_len, UBIDI_RTL, nullptr, &errorCode);
        if (U_SUCCESS(errorCode)) {
            out_len = ubidi_writeReordered(bidi, reordered, working_len + 1,
                                 UBIDI_DO_MIRRORING | UBIDI_REMOVE_BIDI_CONTROLS,
                                 &errorCode);
        }
        ubidi_close(bidi);
    }
    if (U_FAILURE(errorCode)) {
        for(size_t k = 0; k <= working_len; ++k) reordered[k] = working[k];
        out_len = working_len;
    }
#else
    // The manual fallback mirrors perfectly in both directions, so we don't
    // even need to alter its logic to support Visual-To-Logical reversals!
    size_t start = 0;
    Utf16String reversed = reverse_line_fallback(working, &start, working_len > 0 ? working_len - 1 : 0);
    out_len = reversed.Get_Length();
    for(size_t k = 0; k < out_len; ++k) reordered[k] = reversed.Get_Char(k);
    reordered[out_len] = U_CHAR('\0');
#endif

    // 2. Expand PUA characters back to their exact original token string
    size_t final_len = 0;
    for (int32_t i = 0; i < out_len; ++i) {
        unichar_t c = reordered[i];
        if (c >= 0xE000 && c < 0xE000 + tokens.size()) {
            final_len += tokens[c - 0xE000].Get_Length();
        } else {
            final_len += 1;
        }
    }

    unichar_t* final_out = new unichar_t[final_len + 1];
    size_t f_idx = 0;
    for (int32_t i = 0; i < out_len; ++i) {
        unichar_t c = reordered[i];
        if (c >= 0xE000 && c < 0xE000 + tokens.size()) {
            const unichar_t* tok_str = tokens[c - 0xE000].Str();
            size_t t_len = tokens[c - 0xE000].Get_Length();
            for(size_t k = 0; k < t_len; ++k) {
                final_out[f_idx++] = tok_str[k];
            }
        } else {
            final_out[f_idx++] = c;
        }
    }
    final_out[final_len] = U_CHAR('\0');
    Utf16String res(final_out);

    delete[] final_out;
    delete[] reordered;
    delete[] working;

    return res;
}

} // namespace

void Utf16String::Reverse(bool visualToLogical)
{
    // Generates a legacy visual LTR layout from logical RTL text (or vice versa).
    if (m_data == nullptr) return;

    size_type len = Get_Length();
    if (len <= 1) return;

    unichar_t *original = Peek();
    Utf16String final_result;

    size_t start = 0;
    while (start < len) {
        // Find next boundary separator: standard '\n' OR legacy engine tag "{\n}"
        size_t end = start;
        bool is_bracket_nl = false;

        while (end < len) {
            if (original[end] == '\n') break;
            if (end + 2 < len && original[end] == '{' && original[end+1] == '\n' && original[end+2] == '}') {
                is_bracket_nl = true;
                break;
            }
            end++;
        }

        // Extract the line independently to guarantee vertical order
        size_t line_len = end - start;
        unichar_t* line_buf = new unichar_t[line_len + 1];
        for (size_t k = 0; k < line_len; ++k) {
            line_buf[k] = original[start + k];
        }
        line_buf[line_len] = U_CHAR('\0');

        // Apply string BiDi manipulation safely on line chunk
        Utf16String processed_line = ProcessBiDiLine(line_buf, line_len, visualToLogical);
        final_result += processed_line;
        delete[] line_buf;

        // Reattach exact line separator untouched
        if (end < len) {
            if (is_bracket_nl) {
                final_result += U_CHAR('{');
                final_result += U_CHAR('\n');
                final_result += U_CHAR('}');
                start = end + 3;
            } else {
                final_result += U_CHAR('\n');
                start = end + 1;
            }
        } else {
            start = end;
        }
    }

    Set(final_result);
}

void Utf16String::To_Lower()
{
    unichar_t buf[MAX_FORMAT_BUF_LEN];

    if (m_data == nullptr) {
        return;
    }

    u_strcpy(buf, Peek());

    for (unichar_t *c = buf; *c != U_CHAR('\0'); ++c) {
        //*c = towlower(*c);
        *c = u_tolower(*c);
    }

    Set(buf);
}

void Utf16String::Remove_Last_Char()
{
    if (m_data == nullptr) {
        return;
    }

    const size_type len = static_cast<size_type>(u_strlen(Peek()));

    if (len > 0) {
        Ensure_Unique_Buffer_Of_Size(len + 1, true);
        Peek()[len] = U_CHAR('\0');
    }
}

void Utf16String::Format(const unichar_t *format, ...)
{
    va_list va;

    va_start(va, format);
    Format_VA(format, va);
    va_end(va);
}

void Utf16String::Format(Utf16String format, ...)
{
    va_list va;

    va_start(va, format);
    Format_VA(format, va);
    va_end(va);
}

void Utf16String::Format_VA(const unichar_t *format, va_list args)
{
    unichar_t buf[MAX_FORMAT_BUF_LEN];
    const size_type res = u_vsnprintf_u(buf, ARRAY_SIZE(buf), format, args);
    captainslog_relassert(res > 0, 0xDEAD0002, "Unable to format buffer.");

    Set(buf);
}

void Utf16String::Format_VA(Utf16String &format, va_list args)
{
    unichar_t buf[MAX_FORMAT_BUF_LEN];
    const size_type res = u_vsnprintf_u(buf, ARRAY_SIZE(buf), format.Str(), args);
    captainslog_relassert(res > 0, 0xDEAD0002, "Unable to format buffer");

    Set(buf);
}

bool Utf16String::Next_Token(Utf16String *tok, Utf16String delims)
{
    if (m_data == nullptr) {
        return false;
    }

    if (*Peek() == U_CHAR('\0') || this == tok) {
        return false;
    }

    // If no separators provided, default to white space.
    if (delims == nullptr) {
        delims = U_CHAR(" \n\r\t");
    }

#if BUILD_WITH_ICU
    unichar_t *start = Peek();

    // Find next instance of token or end of string
    for (unichar_t c = *start; c != U_CHAR('\0'); c = *(++start)) {
        if (u_strchr(delims.Str(), c) == nullptr) {
            break;
        }
    }

    if (*start == U_CHAR('\0')) {
        Release_Buffer();
        tok->Release_Buffer();

        return false;
    }

    unichar_t *end = start;

    // Find next instance of token or end of string.
    for (unichar_t c = *end; c != U_CHAR('\0'); c = *(++end)) {
        if (u_strchr(delims.Str(), c) != nullptr) {
            break;
        }
    }

    if (end <= start) {
        Release_Buffer();
        tok->Release_Buffer();

        return false;
    }

    // Copy found region into provided Utf8String, then move this string
    // to start of next section.
    unichar_t *tokstr = tok->Get_Buffer_For_Read(end - start + 1);
    memcpy(tokstr, start, end - start);
    tokstr[end - start] = U_CHAR('\0');
    Set(end);

    return true;
#else
    const unichar_t *start = Str();

    const size_type pos = static_cast<size_type>(wcscspn(Peek(), delims.Str()));

    // Check if the position of the next token is not the start of data anyway.
    if (&(Peek()[pos]) > Peek()) {
        unichar_t *read_buffer = tok->Get_Buffer_For_Read(pos + 1);
        memcpy(read_buffer, Peek(), pos);
        read_buffer[pos] = U_CHAR('\0');
        Set(&(Peek()[pos]));

        return true;
    }

    return false;
#endif
}
