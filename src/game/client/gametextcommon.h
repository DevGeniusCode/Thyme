/**
 * @file
 *
 * @author xezon
 *
 * @brief Common structures for Game Localization.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#include "asciistring.h"
#include "bittype.h"
#include "unicodestring.h"
#include "utility/type_traits.h"
#include <vector>

// This enum applies to RA2/YR and Generals/ZH, BFME ID's are slightly different.
enum class LanguageID : int32_t
{
    // Official game languages.
    US = 0,
    UK = 1,
    GERMAN = 2,
    FRENCH = 3,
    SPANISH = 4,
    ITALIAN = 5,
    JAPANESE = 6,
    JABBER = 7,
    KOREAN = 8,
    CHINESE = 9,
    UNUSED_1 = 10,
    BRAZILIAN = 11,
    POLISH = 12,

    // Unspecified language. Default in GameTextFile class.
    UNKNOWN = 13,

    // Community game languages.
    RUSSIAN = 14,
    ARABIC = 15,
    UKRAINIAN = 16,
    SWEDISH = 17,
    ABKHAZIAN = 18,
    AFAR = 19,
    AFRIKAANS = 20,
    AKAN = 21,
    ALBANIAN = 22,
    AMHARIC = 23,
    ARAGONESE = 24,
    ARMENIAN = 25,
    ASSAMESE = 26,
    AVARIC = 27,
    AVESTAN = 28,
    AYMARA = 29,
    AZERBAIJANI = 30,
    BAMBARA = 31,
    BASHKIR = 32,
    BASQUE = 33,
    BELARUSIAN = 34,
    BENGALI = 35,
    BISLAMA = 36,
    BOSNIAN = 37,
    BRETON = 38,
    BULGARIAN = 39,
    BURMESE = 40,
    CATALAN = 41,
    CHAMORRO = 42,
    CHECHEN = 43,
    CHICHEWA = 44,
    SLAVONIC = 45,
    CHUVASH = 46,
    CORNISH = 47,
    CORSICAN = 48,
    CREE = 49,
    CROATIAN = 50,
    CZECH = 51,
    DANISH = 52,
    DIVEHI = 53,
    DUTCH = 54,
    DZONGKHA = 55,
    ESPERANTO = 56,
    ESTONIAN = 57,
    EWE = 58,
    FAROESE = 59,
    FIJIAN = 60,
    FINNISH = 61,
    FRISIAN = 62,
    FULAH = 63,
    GAELIC = 64,
    GALICIAN = 65,
    GANDA = 66,
    GEORGIAN = 67,
    GREEK = 68,
    KALAALLISUT = 69,
    GUARANI = 70,
    GUJARATI = 71,
    HAITIAN = 72,
    HAUSA = 73,
    HEBREW = 74,
    HERERO = 75,
    HINDI = 76,
    HIRIMOTU = 77,
    HUNGARIAN = 78,
    ICELANDIC = 79,
    IDO = 80,
    IGBO = 81,
    INDONESIAN = 82,
    INUKTITUT = 83,
    INUPIAQ = 84,
    IRISH = 85,
    JAVANESE = 86,
    KANNADA = 87,
    KANURI = 88,
    KASHMIRI = 89,
    KAZAKH = 90,
    KHMER = 91,
    KIKUYU = 92,
    KINYARWANDA = 93,
    KYRGYZ = 94,
    KOMI = 95,
    KONGO = 96,
    KUANYAMA = 97,
    KURDISH = 98,
    LAO = 99,
    LATIN = 100,
    LATVIAN = 101,
    LIMBURGAN = 102,
    LINGALA = 103,
    LITHUANIAN = 104,
    LUBAKATANGA = 105,
    LUXEMBOURGISH = 106,
    MACEDONIAN = 107,
    MALAGASY = 108,
    MALAY = 109,
    MALAYALAM = 110,
    MALTESE = 111,
    MANX = 112,
    MAORI = 113,
    MARATHI = 114,
    MARSHALLESE = 115,
    MONGOLIAN = 116,
    NAURU = 117,
    NAVAJO = 118,
    NORTHNDEBELE = 119,
    SOUTHNDEBELE = 120,
    NDONGA = 121,
    NEPALI = 122,
    NORWEGIAN = 123,
    NORWEGIANBOKMAL = 124,
    NORWEGIANNYNORSK = 125,
    OCCITAN = 126,
    OJIBWA = 127,
    ORIYA = 128,
    OROMO = 129,
    OSSETIAN = 130,
    PALI = 131,
    PASHTO = 132,
    PERSIAN = 133,
    PORTUGUESE = 134,
    PUNJABI = 135,
    QUECHUA = 136,
    ROMANIAN = 137,
    ROMANSH = 138,
    RUNDI = 139,
    SAMI = 140,
    SAMOAN = 141,
    SANGO = 142,
    SANSKRIT = 143,
    SARDINIAN = 144,
    SERBIAN = 145,
    SHONA = 146,
    SINDHI = 147,
    SINHALA = 148,
    SLOVAK = 149,
    SLOVENIAN = 150,
    SOMALI = 151,
    SOUTHERNSOTHO = 152,
    SUNDANESE = 153,
    SWAHILI = 154,
    SWATI = 155,
    TAGALOG = 156,
    TAHITIAN = 157,
    TAJIK = 158,
    TAMIL = 159,
    TATAR = 160,
    TELUGU = 161,
    THAI = 162,
    TIBETAN = 163,
    TIGRINYA = 164,
    TONGA = 165,
    TSONGA = 166,
    TSWANA = 167,
    TURKISH = 168,
    TURKMEN = 169,
    TWI = 170,
    UIGHUR = 171,
    URDU = 172,
    UZBEK = 173,
    VENDA = 174,
    VIETNAMESE = 175,
    VOLAPUK = 176,
    WALLOON = 177,
    WELSH = 178,
    WOLOF = 179,
    XHOSA = 180,
    SICHUANYI = 181,
    YIDDISH = 182,
    YORUBA = 183,
    ZHUANG = 184,
    ZULU = 185,

    COUNT
};

DEFINE_RTS_UNDERLYING_TYPE(LanguageID, int32_t);

constexpr size_t g_languageCount = static_cast<size_t>(LanguageID::COUNT);

struct CSFHeader
{
    uint32_t id;
    int32_t version;
    int32_t num_labels;
    int32_t num_strings;
    int32_t skip;
    LanguageID langid;
};

struct StringInfo
{
    Utf8String label;
    Utf16String text;
    Utf8String speech;
};

struct NoString
{
    NoString *next;
    Utf16String text;
};

namespace Thyme
{

struct MultiStringInfo
{
    Utf8String label;
    Utf16String text[g_languageCount];
    Utf8String speech[g_languageCount];
};

using StringInfos = std::vector<StringInfo>;
using MultiStringInfos = std::vector<MultiStringInfo>;

bool Name_To_Language(const char *localization, LanguageID &language);
const char *Get_Language_Name(LanguageID language);

} // namespace Thyme
