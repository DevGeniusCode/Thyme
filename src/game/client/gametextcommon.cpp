/**
 * @file
 *
 * @author xezon
 *
 * @brief Common structures for Game Localization. (Thyme Feature)
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "gametextcommon.h"
#include "utility/enumerator.h"

namespace Thyme
{

constexpr const char *const s_localization_us = "English";
constexpr const char *const s_localization_en = "";
constexpr const char *const s_localization_de = "German";
constexpr const char *const s_localization_fr = "French";
constexpr const char *const s_localization_es = "Spanish";
constexpr const char *const s_localization_it = "Italian";
constexpr const char *const s_localization_ja = "Japanese";
constexpr const char *const s_localization_jb = "";
constexpr const char *const s_localization_ko = "Korean";
constexpr const char *const s_localization_zh = "Chinese";
constexpr const char *const s_localization___ = "";
constexpr const char *const s_localization_bp = "Brazilian";
constexpr const char *const s_localization_pl = "Polish";
constexpr const char *const s_localization_un = "Unknown";
constexpr const char *const s_localization_ru = "Russian";
constexpr const char *const s_localization_ar = "Arabic";
constexpr const char *const s_localization_uk = "Ukrainian";
constexpr const char *const s_localization_sv = "Swedish";
constexpr const char *const s_localization_ab = "Abkhazian";
constexpr const char *const s_localization_aa = "Afar";
constexpr const char *const s_localization_af = "Afrikaans";
constexpr const char *const s_localization_ak = "Akan";
constexpr const char *const s_localization_sq = "Albanian";
constexpr const char *const s_localization_am = "Amharic";
constexpr const char *const s_localization_an = "Aragonese";
constexpr const char *const s_localization_hy = "Armenian";
constexpr const char *const s_localization_as = "Assamese";
constexpr const char *const s_localization_av = "Avaric";
constexpr const char *const s_localization_ae = "Avestan";
constexpr const char *const s_localization_ay = "Aymara";
constexpr const char *const s_localization_az = "Azerbaijani";
constexpr const char *const s_localization_bm = "Bambara";
constexpr const char *const s_localization_ba = "Bashkir";
constexpr const char *const s_localization_eu = "Basque";
constexpr const char *const s_localization_be = "Belarusian";
constexpr const char *const s_localization_bn = "Bengali";
constexpr const char *const s_localization_bi = "Bislama";
constexpr const char *const s_localization_bs = "Bosnian";
constexpr const char *const s_localization_br = "Breton";
constexpr const char *const s_localization_bg = "Bulgarian";
constexpr const char *const s_localization_my = "Burmese";
constexpr const char *const s_localization_ca = "Catalan";
constexpr const char *const s_localization_ch = "Chamorro";
constexpr const char *const s_localization_ce = "Chechen";
constexpr const char *const s_localization_ny = "Chichewa";
constexpr const char *const s_localization_cu = "Slavonic";
constexpr const char *const s_localization_cv = "Chuvash";
constexpr const char *const s_localization_kw = "Cornish";
constexpr const char *const s_localization_co = "Corsican";
constexpr const char *const s_localization_cr = "Cree";
constexpr const char *const s_localization_hr = "Croatian";
constexpr const char *const s_localization_cs = "Czech";
constexpr const char *const s_localization_da = "Danish";
constexpr const char *const s_localization_dv = "Divehi";
constexpr const char *const s_localization_nl = "Dutch";
constexpr const char *const s_localization_dz = "Dzongkha";
constexpr const char *const s_localization_eo = "Esperanto";
constexpr const char *const s_localization_et = "Estonian";
constexpr const char *const s_localization_ee = "Ewe";
constexpr const char *const s_localization_fo = "Faroese";
constexpr const char *const s_localization_fj = "Fijian";
constexpr const char *const s_localization_fi = "Finnish";
constexpr const char *const s_localization_fy = "Frisian";
constexpr const char *const s_localization_ff = "Fulah";
constexpr const char *const s_localization_gd = "Gaelic";
constexpr const char *const s_localization_gl = "Galician";
constexpr const char *const s_localization_lg = "Ganda";
constexpr const char *const s_localization_ka = "Georgian";
constexpr const char *const s_localization_el = "Greek";
constexpr const char *const s_localization_kl = "Kalaallisut";
constexpr const char *const s_localization_gn = "Guarani";
constexpr const char *const s_localization_gu = "Gujarati";
constexpr const char *const s_localization_ht = "Haitian";
constexpr const char *const s_localization_ha = "Hausa";
constexpr const char *const s_localization_he = "Hebrew";
constexpr const char *const s_localization_hz = "Herero";
constexpr const char *const s_localization_hi = "Hindi";
constexpr const char *const s_localization_ho = "HiriMotu";
constexpr const char *const s_localization_hu = "Hungarian";
constexpr const char *const s_localization_is = "Icelandic";
constexpr const char *const s_localization_io = "Ido";
constexpr const char *const s_localization_ig = "Igbo";
constexpr const char *const s_localization_id = "Indonesian";
constexpr const char *const s_localization_iu = "Inuktitut";
constexpr const char *const s_localization_ik = "Inupiaq";
constexpr const char *const s_localization_ga = "Irish";
constexpr const char *const s_localization_jv = "Javanese";
constexpr const char *const s_localization_kn = "Kannada";
constexpr const char *const s_localization_kr = "Kanuri";
constexpr const char *const s_localization_ks = "Kashmiri";
constexpr const char *const s_localization_kk = "Kazakh";
constexpr const char *const s_localization_km = "Khmer";
constexpr const char *const s_localization_ki = "Kikuyu";
constexpr const char *const s_localization_rw = "Kinyarwanda";
constexpr const char *const s_localization_ky = "Kyrgyz";
constexpr const char *const s_localization_kv = "Komi";
constexpr const char *const s_localization_kg = "Kongo";
constexpr const char *const s_localization_kj = "Kuanyama";
constexpr const char *const s_localization_ku = "Kurdish";
constexpr const char *const s_localization_lo = "Lao";
constexpr const char *const s_localization_la = "Latin";
constexpr const char *const s_localization_lv = "Latvian";
constexpr const char *const s_localization_li = "Limburgan";
constexpr const char *const s_localization_ln = "Lingala";
constexpr const char *const s_localization_lt = "Lithuanian";
constexpr const char *const s_localization_lu = "LubaKatanga";
constexpr const char *const s_localization_lb = "Luxembourgish";
constexpr const char *const s_localization_mk = "Macedonian";
constexpr const char *const s_localization_mg = "Malagasy";
constexpr const char *const s_localization_ms = "Malay";
constexpr const char *const s_localization_ml = "Malayalam";
constexpr const char *const s_localization_mt = "Maltese";
constexpr const char *const s_localization_gv = "Manx";
constexpr const char *const s_localization_mi = "Maori";
constexpr const char *const s_localization_mr = "Marathi";
constexpr const char *const s_localization_mh = "Marshallese";
constexpr const char *const s_localization_mn = "Mongolian";
constexpr const char *const s_localization_na = "Nauru";
constexpr const char *const s_localization_nv = "Navajo";
constexpr const char *const s_localization_nd = "NorthNdebele";
constexpr const char *const s_localization_nr = "SouthNdebele";
constexpr const char *const s_localization_ng = "Ndonga";
constexpr const char *const s_localization_ne = "Nepali";
constexpr const char *const s_localization_no = "Norwegian";
constexpr const char *const s_localization_nb = "NorwegianBokmal";
constexpr const char *const s_localization_nn = "NorwegianNynorsk";
constexpr const char *const s_localization_oc = "Occitan";
constexpr const char *const s_localization_oj = "Ojibwa";
constexpr const char *const s_localization_or = "Oriya";
constexpr const char *const s_localization_om = "Oromo";
constexpr const char *const s_localization_os = "Ossetian";
constexpr const char *const s_localization_pi = "Pali";
constexpr const char *const s_localization_ps = "Pushto";
constexpr const char *const s_localization_fa = "Persian";
constexpr const char *const s_localization_pt = "Portuguese";
constexpr const char *const s_localization_pa = "Punjabi";
constexpr const char *const s_localization_qu = "Quechua";
constexpr const char *const s_localization_ro = "Romanian";
constexpr const char *const s_localization_rm = "Romansh";
constexpr const char *const s_localization_rn = "Rundi";
constexpr const char *const s_localization_se = "Sami";
constexpr const char *const s_localization_sm = "Samoan";
constexpr const char *const s_localization_sg = "Sango";
constexpr const char *const s_localization_sa = "Sanskrit";
constexpr const char *const s_localization_sc = "Sardinian";
constexpr const char *const s_localization_sr = "Serbian";
constexpr const char *const s_localization_sn = "Shona";
constexpr const char *const s_localization_sd = "Sindhi";
constexpr const char *const s_localization_si = "Sinhala";
constexpr const char *const s_localization_sk = "Slovak";
constexpr const char *const s_localization_sl = "Slovenian";
constexpr const char *const s_localization_so = "Somali";
constexpr const char *const s_localization_st = "SouthernSotho";
constexpr const char *const s_localization_su = "Sundanese";
constexpr const char *const s_localization_sw = "Swahili";
constexpr const char *const s_localization_ss = "Swati";
constexpr const char *const s_localization_tl = "Tagalog";
constexpr const char *const s_localization_ty = "Tahitian";
constexpr const char *const s_localization_tg = "Tajik";
constexpr const char *const s_localization_ta = "Tamil";
constexpr const char *const s_localization_tt = "Tatar";
constexpr const char *const s_localization_te = "Telugu";
constexpr const char *const s_localization_th = "Thai";
constexpr const char *const s_localization_bo = "Tibetan";
constexpr const char *const s_localization_ti = "Tigrinya";
constexpr const char *const s_localization_to = "Tonga";
constexpr const char *const s_localization_ts = "Tsonga";
constexpr const char *const s_localization_tn = "Tswana";
constexpr const char *const s_localization_tr = "Turkish";
constexpr const char *const s_localization_tk = "Turkmen";
constexpr const char *const s_localization_tw = "Twi";
constexpr const char *const s_localization_ug = "Uighur";
constexpr const char *const s_localization_ur = "Urdu";
constexpr const char *const s_localization_uz = "Uzbek";
constexpr const char *const s_localization_ve = "Venda";
constexpr const char *const s_localization_vi = "Vietnamese";
constexpr const char *const s_localization_vo = "Volapuk";
constexpr const char *const s_localization_wa = "Walloon";
constexpr const char *const s_localization_cy = "Welsh";
constexpr const char *const s_localization_wo = "Wolof";
constexpr const char *const s_localization_xh = "Xhosa";
constexpr const char *const s_localization_ii = "SichuanYi";
constexpr const char *const s_localization_yi = "Yiddish";
constexpr const char *const s_localization_yo = "Yoruba";
constexpr const char *const s_localization_za = "Zhuang";
constexpr const char *const s_localization_zu = "Zulu";

constexpr const char *const s_localizations[] = {
    s_localization_us,
    s_localization_en,
    s_localization_de,
    s_localization_fr,
    s_localization_es,
    s_localization_it,
    s_localization_ja,
    s_localization_jb,
    s_localization_ko,
    s_localization_zh,
    s_localization___,
    s_localization_bp,
    s_localization_pl,
    s_localization_un,
    s_localization_ru,
    s_localization_ar,
    s_localization_uk,
    s_localization_sv,
    s_localization_ab,
    s_localization_aa,
    s_localization_af,
    s_localization_ak,
    s_localization_sq,
    s_localization_am,
    s_localization_an,
    s_localization_hy,
    s_localization_as,
    s_localization_av,
    s_localization_ae,
    s_localization_ay,
    s_localization_az,
    s_localization_bm,
    s_localization_ba,
    s_localization_eu,
    s_localization_be,
    s_localization_bn,
    s_localization_bi,
    s_localization_bs,
    s_localization_br,
    s_localization_bg,
    s_localization_my,
    s_localization_ca,
    s_localization_ch,
    s_localization_ce,
    s_localization_ny,
    s_localization_cu,
    s_localization_cv,
    s_localization_kw,
    s_localization_co,
    s_localization_cr,
    s_localization_hr,
    s_localization_cs,
    s_localization_da,
    s_localization_dv,
    s_localization_nl,
    s_localization_dz,
    s_localization_eo,
    s_localization_et,
    s_localization_ee,
    s_localization_fo,
    s_localization_fj,
    s_localization_fi,
    s_localization_fy,
    s_localization_ff,
    s_localization_gd,
    s_localization_gl,
    s_localization_lg,
    s_localization_ka,
    s_localization_el,
    s_localization_kl,
    s_localization_gn,
    s_localization_gu,
    s_localization_ht,
    s_localization_ha,
    s_localization_he,
    s_localization_hz,
    s_localization_hi,
    s_localization_ho,
    s_localization_hu,
    s_localization_is,
    s_localization_io,
    s_localization_ig,
    s_localization_id,
    s_localization_iu,
    s_localization_ik,
    s_localization_ga,
    s_localization_jv,
    s_localization_kn,
    s_localization_kr,
    s_localization_ks,
    s_localization_kk,
    s_localization_km,
    s_localization_ki,
    s_localization_rw,
    s_localization_ky,
    s_localization_kv,
    s_localization_kg,
    s_localization_kj,
    s_localization_ku,
    s_localization_lo,
    s_localization_la,
    s_localization_lv,
    s_localization_li,
    s_localization_ln,
    s_localization_lt,
    s_localization_lu,
    s_localization_lb,
    s_localization_mk,
    s_localization_mg,
    s_localization_ms,
    s_localization_ml,
    s_localization_mt,
    s_localization_gv,
    s_localization_mi,
    s_localization_mr,
    s_localization_mh,
    s_localization_mn,
    s_localization_na,
    s_localization_nv,
    s_localization_nd,
    s_localization_nr,
    s_localization_ng,
    s_localization_ne,
    s_localization_no,
    s_localization_nb,
    s_localization_nn,
    s_localization_oc,
    s_localization_oj,
    s_localization_or,
    s_localization_om,
    s_localization_os,
    s_localization_pi,
    s_localization_ps,
    s_localization_fa,
    s_localization_pt,
    s_localization_pa,
    s_localization_qu,
    s_localization_ro,
    s_localization_rm,
    s_localization_rn,
    s_localization_se,
    s_localization_sm,
    s_localization_sg,
    s_localization_sa,
    s_localization_sc,
    s_localization_sr,
    s_localization_sn,
    s_localization_sd,
    s_localization_si,
    s_localization_sk,
    s_localization_sl,
    s_localization_so,
    s_localization_st,
    s_localization_su,
    s_localization_sw,
    s_localization_ss,
    s_localization_tl,
    s_localization_ty,
    s_localization_tg,
    s_localization_ta,
    s_localization_tt,
    s_localization_te,
    s_localization_th,
    s_localization_bo,
    s_localization_ti,
    s_localization_to,
    s_localization_ts,
    s_localization_tn,
    s_localization_tr,
    s_localization_tk,
    s_localization_tw,
    s_localization_ug,
    s_localization_ur,
    s_localization_uz,
    s_localization_ve,
    s_localization_vi,
    s_localization_vo,
    s_localization_wa,
    s_localization_cy,
    s_localization_wo,
    s_localization_xh,
    s_localization_ii,
    s_localization_yi,
    s_localization_yo,
    s_localization_za,
    s_localization_zu
};

static_assert(s_localization_us == s_localizations[size_t(LanguageID::US)]);
static_assert(s_localization_en == s_localizations[size_t(LanguageID::UK)]);
static_assert(s_localization_de == s_localizations[size_t(LanguageID::GERMAN)]);
static_assert(s_localization_fr == s_localizations[size_t(LanguageID::FRENCH)]);
static_assert(s_localization_es == s_localizations[size_t(LanguageID::SPANISH)]);
static_assert(s_localization_it == s_localizations[size_t(LanguageID::ITALIAN)]);
static_assert(s_localization_ja == s_localizations[size_t(LanguageID::JAPANESE)]);
static_assert(s_localization_jb == s_localizations[size_t(LanguageID::JABBER)]);
static_assert(s_localization_ko == s_localizations[size_t(LanguageID::KOREAN)]);
static_assert(s_localization_zh == s_localizations[size_t(LanguageID::CHINESE)]);
static_assert(s_localization___ == s_localizations[size_t(LanguageID::UNUSED_1)]);
static_assert(s_localization_bp == s_localizations[size_t(LanguageID::BRAZILIAN)]);
static_assert(s_localization_pl == s_localizations[size_t(LanguageID::POLISH)]);
static_assert(s_localization_un == s_localizations[size_t(LanguageID::UNKNOWN)]);
static_assert(s_localization_ru == s_localizations[size_t(LanguageID::RUSSIAN)]);
static_assert(s_localization_ar == s_localizations[size_t(LanguageID::ARABIC)]);
static_assert(s_localization_uk == s_localizations[size_t(LanguageID::UKRAINIAN)]);
static_assert(s_localization_sv == s_localizations[size_t(LanguageID::SWEDISH)]);
static_assert(s_localization_ab == s_localizations[size_t(LanguageID::ABKHAZIAN)]);
static_assert(s_localization_aa == s_localizations[size_t(LanguageID::AFAR)]);
static_assert(s_localization_af == s_localizations[size_t(LanguageID::AFRIKAANS)]);
static_assert(s_localization_ak == s_localizations[size_t(LanguageID::AKAN)]);
static_assert(s_localization_sq == s_localizations[size_t(LanguageID::ALBANIAN)]);
static_assert(s_localization_am == s_localizations[size_t(LanguageID::AMHARIC)]);
static_assert(s_localization_an == s_localizations[size_t(LanguageID::ARAGONESE)]);
static_assert(s_localization_hy == s_localizations[size_t(LanguageID::ARMENIAN)]);
static_assert(s_localization_as == s_localizations[size_t(LanguageID::ASSAMESE)]);
static_assert(s_localization_av == s_localizations[size_t(LanguageID::AVARIC)]);
static_assert(s_localization_ae == s_localizations[size_t(LanguageID::AVESTAN)]);
static_assert(s_localization_ay == s_localizations[size_t(LanguageID::AYMARA)]);
static_assert(s_localization_az == s_localizations[size_t(LanguageID::AZERBAIJANI)]);
static_assert(s_localization_bm == s_localizations[size_t(LanguageID::BAMBARA)]);
static_assert(s_localization_ba == s_localizations[size_t(LanguageID::BASHKIR)]);
static_assert(s_localization_eu == s_localizations[size_t(LanguageID::BASQUE)]);
static_assert(s_localization_be == s_localizations[size_t(LanguageID::BELARUSIAN)]);
static_assert(s_localization_bn == s_localizations[size_t(LanguageID::BENGALI)]);
static_assert(s_localization_bi == s_localizations[size_t(LanguageID::BISLAMA)]);
static_assert(s_localization_bs == s_localizations[size_t(LanguageID::BOSNIAN)]);
static_assert(s_localization_br == s_localizations[size_t(LanguageID::BRETON)]);
static_assert(s_localization_bg == s_localizations[size_t(LanguageID::BULGARIAN)]);
static_assert(s_localization_my == s_localizations[size_t(LanguageID::BURMESE)]);
static_assert(s_localization_ca == s_localizations[size_t(LanguageID::CATALAN)]);
static_assert(s_localization_ch == s_localizations[size_t(LanguageID::CHAMORRO)]);
static_assert(s_localization_ce == s_localizations[size_t(LanguageID::CHECHEN)]);
static_assert(s_localization_ny == s_localizations[size_t(LanguageID::CHICHEWA)]);
static_assert(s_localization_cu == s_localizations[size_t(LanguageID::SLAVONIC)]);
static_assert(s_localization_cv == s_localizations[size_t(LanguageID::CHUVASH)]);
static_assert(s_localization_kw == s_localizations[size_t(LanguageID::CORNISH)]);
static_assert(s_localization_co == s_localizations[size_t(LanguageID::CORSICAN)]);
static_assert(s_localization_cr == s_localizations[size_t(LanguageID::CREE)]);
static_assert(s_localization_hr == s_localizations[size_t(LanguageID::CROATIAN)]);
static_assert(s_localization_cs == s_localizations[size_t(LanguageID::CZECH)]);
static_assert(s_localization_da == s_localizations[size_t(LanguageID::DANISH)]);
static_assert(s_localization_dv == s_localizations[size_t(LanguageID::DIVEHI)]);
static_assert(s_localization_nl == s_localizations[size_t(LanguageID::DUTCH)]);
static_assert(s_localization_dz == s_localizations[size_t(LanguageID::DZONGKHA)]);
static_assert(s_localization_eo == s_localizations[size_t(LanguageID::ESPERANTO)]);
static_assert(s_localization_et == s_localizations[size_t(LanguageID::ESTONIAN)]);
static_assert(s_localization_ee == s_localizations[size_t(LanguageID::EWE)]);  
static_assert(s_localization_fo == s_localizations[size_t(LanguageID::FAROESE)]);
static_assert(s_localization_fj == s_localizations[size_t(LanguageID::FIJIAN)]);
static_assert(s_localization_fi == s_localizations[size_t(LanguageID::FINNISH)]);
static_assert(s_localization_fy == s_localizations[size_t(LanguageID::FRISIAN)]);
static_assert(s_localization_ff == s_localizations[size_t(LanguageID::FULAH)]);
static_assert(s_localization_gd == s_localizations[size_t(LanguageID::GAELIC)]);
static_assert(s_localization_gl == s_localizations[size_t(LanguageID::GALICIAN)]);
static_assert(s_localization_lg == s_localizations[size_t(LanguageID::GANDA)]);
static_assert(s_localization_ka == s_localizations[size_t(LanguageID::GEORGIAN)]);
static_assert(s_localization_el == s_localizations[size_t(LanguageID::GREEK)]);
static_assert(s_localization_kl == s_localizations[size_t(LanguageID::KALAALLISUT)]);
static_assert(s_localization_gn == s_localizations[size_t(LanguageID::GUARANI)]);
static_assert(s_localization_gu == s_localizations[size_t(LanguageID::GUJARATI)]);
static_assert(s_localization_ht == s_localizations[size_t(LanguageID::HAITIAN)]);
static_assert(s_localization_ha == s_localizations[size_t(LanguageID::HAUSA)]);
static_assert(s_localization_he == s_localizations[size_t(LanguageID::HEBREW)]);
static_assert(s_localization_hz == s_localizations[size_t(LanguageID::HERERO)]);
static_assert(s_localization_hi == s_localizations[size_t(LanguageID::HINDI)]);
static_assert(s_localization_ho == s_localizations[size_t(LanguageID::HIRIMOTU)]);
static_assert(s_localization_hu == s_localizations[size_t(LanguageID::HUNGARIAN)]);
static_assert(s_localization_is == s_localizations[size_t(LanguageID::ICELANDIC)]);
static_assert(s_localization_io == s_localizations[size_t(LanguageID::IDO)]);
static_assert(s_localization_ig == s_localizations[size_t(LanguageID::IGBO)]);
static_assert(s_localization_id == s_localizations[size_t(LanguageID::INDONESIAN)]);
static_assert(s_localization_iu == s_localizations[size_t(LanguageID::INUKTITUT)]);
static_assert(s_localization_ik == s_localizations[size_t(LanguageID::INUPIAQ)]);
static_assert(s_localization_ga == s_localizations[size_t(LanguageID::IRISH)]);
static_assert(s_localization_jv == s_localizations[size_t(LanguageID::JAVANESE)]);
static_assert(s_localization_kn == s_localizations[size_t(LanguageID::KANNADA)]);
static_assert(s_localization_kr == s_localizations[size_t(LanguageID::KANURI)]);
static_assert(s_localization_ks == s_localizations[size_t(LanguageID::KASHMIRI)]);
static_assert(s_localization_kk == s_localizations[size_t(LanguageID::KAZAKH)]);
static_assert(s_localization_km == s_localizations[size_t(LanguageID::KHMER)]);
static_assert(s_localization_ki == s_localizations[size_t(LanguageID::KIKUYU)]);
static_assert(s_localization_rw == s_localizations[size_t(LanguageID::KINYARWANDA)]);
static_assert(s_localization_ky == s_localizations[size_t(LanguageID::KYRGYZ)]);
static_assert(s_localization_kv == s_localizations[size_t(LanguageID::KOMI)]);
static_assert(s_localization_kg == s_localizations[size_t(LanguageID::KONGO)]);
static_assert(s_localization_kj == s_localizations[size_t(LanguageID::KUANYAMA)]);
static_assert(s_localization_ku == s_localizations[size_t(LanguageID::KURDISH)]);
static_assert(s_localization_lo == s_localizations[size_t(LanguageID::LAO)]);
static_assert(s_localization_la == s_localizations[size_t(LanguageID::LATIN)]);
static_assert(s_localization_lv == s_localizations[size_t(LanguageID::LATVIAN)]);
static_assert(s_localization_li == s_localizations[size_t(LanguageID::LIMBURGAN)]);
static_assert(s_localization_ln == s_localizations[size_t(LanguageID::LINGALA)]);
static_assert(s_localization_lt == s_localizations[size_t(LanguageID::LITHUANIAN)]);
static_assert(s_localization_lu == s_localizations[size_t(LanguageID::LUBAKATANGA)]);
static_assert(s_localization_lb == s_localizations[size_t(LanguageID::LUXEMBOURGISH)]);
static_assert(s_localization_mk == s_localizations[size_t(LanguageID::MACEDONIAN)]);
static_assert(s_localization_mg == s_localizations[size_t(LanguageID::MALAGASY)]);
static_assert(s_localization_ms == s_localizations[size_t(LanguageID::MALAY)]);
static_assert(s_localization_ml == s_localizations[size_t(LanguageID::MALAYALAM)]);
static_assert(s_localization_mt == s_localizations[size_t(LanguageID::MALTESE)]);
static_assert(s_localization_gv == s_localizations[size_t(LanguageID::MANX)]);
static_assert(s_localization_mi == s_localizations[size_t(LanguageID::MAORI)]);
static_assert(s_localization_mr == s_localizations[size_t(LanguageID::MARATHI)]);
static_assert(s_localization_mh == s_localizations[size_t(LanguageID::MARSHALLESE)]);
static_assert(s_localization_mn == s_localizations[size_t(LanguageID::MONGOLIAN)]);
static_assert(s_localization_na == s_localizations[size_t(LanguageID::NAURU)]);
static_assert(s_localization_nv == s_localizations[size_t(LanguageID::NAVAJO)]);
static_assert(s_localization_nd == s_localizations[size_t(LanguageID::NORTHNDEBELE)]);
static_assert(s_localization_nr == s_localizations[size_t(LanguageID::SOUTHNDEBELE)]);
static_assert(s_localization_ng == s_localizations[size_t(LanguageID::NDONGA)]);
static_assert(s_localization_ne == s_localizations[size_t(LanguageID::NEPALI)]);
static_assert(s_localization_no == s_localizations[size_t(LanguageID::NORWEGIAN)]);
static_assert(s_localization_nb == s_localizations[size_t(LanguageID::NORWEGIANBOKMAL)]);
static_assert(s_localization_nn == s_localizations[size_t(LanguageID::NORWEGIANNYNORSK)]);
static_assert(s_localization_oc == s_localizations[size_t(LanguageID::OCCITAN)]);
static_assert(s_localization_oj == s_localizations[size_t(LanguageID::OJIBWA)]);
static_assert(s_localization_or == s_localizations[size_t(LanguageID::ORIYA)]);
static_assert(s_localization_om == s_localizations[size_t(LanguageID::OROMO)]);
static_assert(s_localization_os == s_localizations[size_t(LanguageID::OSSETIAN)]);
static_assert(s_localization_pi == s_localizations[size_t(LanguageID::PALI)]);
static_assert(s_localization_ps == s_localizations[size_t(LanguageID::PASHTO)]);
static_assert(s_localization_fa == s_localizations[size_t(LanguageID::PERSIAN)]);
static_assert(s_localization_pt == s_localizations[size_t(LanguageID::PORTUGUESE)]);
static_assert(s_localization_pa == s_localizations[size_t(LanguageID::PUNJABI)]);
static_assert(s_localization_qu == s_localizations[size_t(LanguageID::QUECHUA)]);
static_assert(s_localization_ro == s_localizations[size_t(LanguageID::ROMANIAN)]);
static_assert(s_localization_rm == s_localizations[size_t(LanguageID::ROMANSH)]);
static_assert(s_localization_rn == s_localizations[size_t(LanguageID::RUNDI)]);
static_assert(s_localization_se == s_localizations[size_t(LanguageID::SAMI)]);
static_assert(s_localization_sm == s_localizations[size_t(LanguageID::SAMOAN)]);
static_assert(s_localization_sg == s_localizations[size_t(LanguageID::SANGO)]);
static_assert(s_localization_sa == s_localizations[size_t(LanguageID::SANSKRIT)]);
static_assert(s_localization_sc == s_localizations[size_t(LanguageID::SARDINIAN)]);
static_assert(s_localization_sr == s_localizations[size_t(LanguageID::SERBIAN)]);
static_assert(s_localization_sn == s_localizations[size_t(LanguageID::SHONA)]);
static_assert(s_localization_sd == s_localizations[size_t(LanguageID::SINDHI)]);
static_assert(s_localization_si == s_localizations[size_t(LanguageID::SINHALA)]);
static_assert(s_localization_sk == s_localizations[size_t(LanguageID::SLOVAK)]);
static_assert(s_localization_sl == s_localizations[size_t(LanguageID::SLOVENIAN)]);
static_assert(s_localization_so == s_localizations[size_t(LanguageID::SOMALI)]);
static_assert(s_localization_st == s_localizations[size_t(LanguageID::SOUTHERNSOTHO)]);
static_assert(s_localization_su == s_localizations[size_t(LanguageID::SUNDANESE)]);
static_assert(s_localization_sw == s_localizations[size_t(LanguageID::SWAHILI)]);
static_assert(s_localization_ss == s_localizations[size_t(LanguageID::SWATI)]);
static_assert(s_localization_tl == s_localizations[size_t(LanguageID::TAGALOG)]);
static_assert(s_localization_ty == s_localizations[size_t(LanguageID::TAHITIAN)]);
static_assert(s_localization_tg == s_localizations[size_t(LanguageID::TAJIK)]);
static_assert(s_localization_ta == s_localizations[size_t(LanguageID::TAMIL)]);
static_assert(s_localization_tt == s_localizations[size_t(LanguageID::TATAR)]);
static_assert(s_localization_te == s_localizations[size_t(LanguageID::TELUGU)]);
static_assert(s_localization_th == s_localizations[size_t(LanguageID::THAI)]);
static_assert(s_localization_bo == s_localizations[size_t(LanguageID::TIBETAN)]);
static_assert(s_localization_ti == s_localizations[size_t(LanguageID::TIGRINYA)]);
static_assert(s_localization_to == s_localizations[size_t(LanguageID::TONGA)]);
static_assert(s_localization_ts == s_localizations[size_t(LanguageID::TSONGA)]);
static_assert(s_localization_tn == s_localizations[size_t(LanguageID::TSWANA)]);
static_assert(s_localization_tr == s_localizations[size_t(LanguageID::TURKISH)]);
static_assert(s_localization_tk == s_localizations[size_t(LanguageID::TURKMEN)]);
static_assert(s_localization_tw == s_localizations[size_t(LanguageID::TWI)]);
static_assert(s_localization_ug == s_localizations[size_t(LanguageID::UIGHUR)]);
static_assert(s_localization_ur == s_localizations[size_t(LanguageID::URDU)]);
static_assert(s_localization_uz == s_localizations[size_t(LanguageID::UZBEK)]);
static_assert(s_localization_ve == s_localizations[size_t(LanguageID::VENDA)]);
static_assert(s_localization_vi == s_localizations[size_t(LanguageID::VIETNAMESE)]);
static_assert(s_localization_vo == s_localizations[size_t(LanguageID::VOLAPUK)]);
static_assert(s_localization_wa == s_localizations[size_t(LanguageID::WALLOON)]);
static_assert(s_localization_cy == s_localizations[size_t(LanguageID::WELSH)]);
static_assert(s_localization_wo == s_localizations[size_t(LanguageID::WOLOF)]);
static_assert(s_localization_xh == s_localizations[size_t(LanguageID::XHOSA)]);
static_assert(s_localization_ii == s_localizations[size_t(LanguageID::SICHUANYI)]);
static_assert(s_localization_yi == s_localizations[size_t(LanguageID::YIDDISH)]);
static_assert(s_localization_yo == s_localizations[size_t(LanguageID::YORUBA)]);
static_assert(s_localization_za == s_localizations[size_t(LanguageID::ZHUANG)]);
static_assert(s_localization_zu == s_localizations[size_t(LanguageID::ZULU)]);


static_assert(ARRAY_SIZE(s_localizations) == g_languageCount);

bool Name_To_Language(const char *localization, LanguageID &language)
{
    rts::enumerator<LanguageID> it;

    for (const char *name : s_localizations) {
        if (0 == strcasecmp(localization, name)) {
            language = it.value();
            return true;
        }
        ++it;
    }
    return false;
}

const char *Get_Language_Name(LanguageID language)
{
    return s_localizations[static_cast<size_t>(language)];
}

} // namespace Thyme
