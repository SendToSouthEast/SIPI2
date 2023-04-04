/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ARIAL
#define ARIAL 1
#endif

#if ARIAL

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfd,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x24, 0x4b, 0xf9, 0x44, 0x9f, 0xd2, 0x28,

    /* U+0024 "$" */
    0x27, 0xeb, 0x47, 0x16, 0xb5, 0x71, 0x0,

    /* U+0025 "%" */
    0x62, 0x49, 0x25, 0xc, 0x80, 0xb8, 0x94, 0x4a,
    0x47,

    /* U+0026 "&" */
    0x30, 0x91, 0x21, 0x8d, 0x51, 0xa3, 0x39,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x4a, 0x49, 0x24, 0x48,

    /* U+0029 ")" */
    0x88, 0x92, 0x49, 0x50,

    /* U+002A "*" */
    0x2f, 0x60,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0xc0,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x24, 0xa4, 0xa4,

    /* U+0030 "0" */
    0x7b, 0x38, 0x61, 0x86, 0x1c, 0xde,

    /* U+0031 "1" */
    0x2e, 0x92, 0x49,

    /* U+0032 "2" */
    0x79, 0x14, 0x43, 0x18, 0x84, 0x3f,

    /* U+0033 "3" */
    0x74, 0x42, 0x60, 0x86, 0x2e,

    /* U+0034 "4" */
    0x8, 0x62, 0x8a, 0x4b, 0xf0, 0x82,

    /* U+0035 "5" */
    0x7d, 0x7, 0x93, 0x7, 0x14, 0xde,

    /* U+0036 "6" */
    0x79, 0x38, 0x2e, 0xc6, 0x1c, 0xde,

    /* U+0037 "7" */
    0xfc, 0x21, 0x8, 0x21, 0x4, 0x10,

    /* U+0038 "8" */
    0x72, 0x28, 0x9c, 0xce, 0x18, 0x5e,

    /* U+0039 "9" */
    0x7b, 0x18, 0x61, 0x7c, 0x18, 0x9e,

    /* U+003A ":" */
    0x84,

    /* U+003B ";" */
    0x86,

    /* U+003C "<" */
    0x4, 0xec, 0x30, 0x38, 0x10,

    /* U+003D "=" */
    0xf8, 0x3e,

    /* U+003E ">" */
    0x81, 0x81, 0x86, 0x62, 0x0,

    /* U+003F "?" */
    0x74, 0x62, 0x33, 0x10, 0x4,

    /* U+0040 "@" */
    0x1f, 0x6, 0x19, 0x35, 0xc9, 0x9a, 0x13, 0x44,
    0x68, 0x92, 0xfc, 0x60, 0x63, 0xf0,

    /* U+0041 "A" */
    0x18, 0x18, 0x2c, 0x24, 0x64, 0x7e, 0x42, 0x83,

    /* U+0042 "B" */
    0xfa, 0x18, 0x7e, 0x86, 0x18, 0x7e,

    /* U+0043 "C" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x51, 0x9e,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0x61, 0x7c,

    /* U+0045 "E" */
    0xfe, 0x8, 0x3f, 0x82, 0x8, 0x3f,

    /* U+0046 "F" */
    0xfe, 0x8, 0x3e, 0x82, 0x8, 0x20,

    /* U+0047 "G" */
    0x3c, 0x43, 0x81, 0x80, 0x8f, 0x81, 0x41, 0x3e,

    /* U+0048 "H" */
    0x83, 0x6, 0xf, 0xf8, 0x30, 0x60, 0xc1,

    /* U+0049 "I" */
    0xff,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x86, 0x2e,

    /* U+004B "K" */
    0x85, 0x12, 0x47, 0xd, 0x11, 0x23, 0x43,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x1f,

    /* U+004D "M" */
    0xc3, 0xc3, 0xc3, 0xa5, 0xa5, 0x99, 0x99, 0x99,

    /* U+004E "N" */
    0x83, 0x86, 0x8d, 0x99, 0xb1, 0x61, 0xc1,

    /* U+004F "O" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0050 "P" */
    0xfa, 0x18, 0x61, 0xfa, 0x8, 0x20,

    /* U+0051 "Q" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x4e, 0x3f,

    /* U+0052 "R" */
    0xfc, 0x82, 0x82, 0xfc, 0x88, 0x84, 0x86, 0x82,

    /* U+0053 "S" */
    0x7a, 0x38, 0x18, 0x1e, 0x18, 0x5e,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x71, 0xbe,

    /* U+0056 "V" */
    0x81, 0x42, 0x42, 0x64, 0x24, 0x24, 0x18, 0x18,

    /* U+0057 "W" */
    0x86, 0x28, 0xc5, 0x29, 0x25, 0x24, 0x94, 0x62,
    0x8c, 0x61, 0x84,

    /* U+0058 "X" */
    0x42, 0x24, 0x3c, 0x18, 0x18, 0x24, 0x66, 0xc3,

    /* U+0059 "Y" */
    0x82, 0x89, 0xb1, 0x41, 0x2, 0x4, 0x8,

    /* U+005A "Z" */
    0xfe, 0x8, 0x20, 0x82, 0xc, 0x30, 0x7f,

    /* U+005B "[" */
    0xea, 0xaa, 0xb0,

    /* U+005C "\\" */
    0x91, 0x24, 0x49,

    /* U+005D "]" */
    0xd5, 0x55, 0x70,

    /* U+005E "^" */
    0x21, 0x94, 0x94, 0x80,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x80,

    /* U+0061 "a" */
    0x74, 0x47, 0xd8, 0xfc,

    /* U+0062 "b" */
    0x84, 0x3d, 0x18, 0xc6, 0x3e,

    /* U+0063 "c" */
    0x76, 0x61, 0x8, 0xb8,

    /* U+0064 "d" */
    0x8, 0x5f, 0x18, 0xc6, 0x2f,

    /* U+0065 "e" */
    0x72, 0x2f, 0xa0, 0xc9, 0xe0,

    /* U+0066 "f" */
    0x74, 0xe4, 0x44, 0x44,

    /* U+0067 "g" */
    0x7c, 0x63, 0x18, 0xbe, 0x2e,

    /* U+0068 "h" */
    0x84, 0x3d, 0x18, 0xc6, 0x31,

    /* U+0069 "i" */
    0xbf,

    /* U+006A "j" */
    0x45, 0x55, 0x70,

    /* U+006B "k" */
    0x84, 0x25, 0x4e, 0x52, 0x53,

    /* U+006C "l" */
    0xff,

    /* U+006D "m" */
    0xf7, 0x44, 0x62, 0x31, 0x18, 0x8c, 0x44,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0xc4,

    /* U+006F "o" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0070 "p" */
    0xf6, 0x63, 0x18, 0xfa, 0x10,

    /* U+0071 "q" */
    0x7c, 0xe3, 0x18, 0xbc, 0x21,

    /* U+0072 "r" */
    0xf2, 0x49, 0x0,

    /* U+0073 "s" */
    0x74, 0x78, 0x38, 0xb8,

    /* U+0074 "t" */
    0x4b, 0xa4, 0x93,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xbc,

    /* U+0076 "v" */
    0x85, 0x24, 0x8c, 0x30, 0xc0,

    /* U+0077 "w" */
    0x89, 0x2c, 0x95, 0x4a, 0xc6, 0x61, 0x30,

    /* U+0078 "x" */
    0x49, 0xe3, 0xc, 0x4b, 0x30,

    /* U+0079 "y" */
    0xc5, 0x24, 0x8c, 0x30, 0xc2, 0x18,

    /* U+007A "z" */
    0xfc, 0x21, 0x8, 0x43, 0xf0,

    /* U+007B "{" */
    0x69, 0x28, 0x92, 0x4c,

    /* U+007C "|" */
    0xff, 0xc0,

    /* U+007D "}" */
    0xc9, 0x22, 0x92, 0x58,

    /* U+007E "~" */
    0xe0, 0x70,

    /* U+00A0 " " */
    0x0,

    /* U+00B7 "·" */
    0x80,

    /* U+00D7 "×" */
    0xdb, 0x9d, 0xb0,

    /* U+00E0 "à" */
    0x20, 0x1d, 0x11, 0xf6, 0x3f,

    /* U+00E1 "á" */
    0x30, 0x1d, 0x11, 0xf6, 0x3f,

    /* U+00E6 "æ" */
    0x77, 0xa2, 0x17, 0xfe, 0x20, 0x9c, 0xdd, 0xe0,

    /* U+00E8 "è" */
    0x20, 0x7, 0x22, 0xfa, 0xc, 0x9e,

    /* U+00E9 "é" */
    0x10, 0x7, 0x22, 0xfa, 0xc, 0x9e,

    /* U+00EB "ë" */
    0x50, 0x7, 0x22, 0xfa, 0xc, 0x9e,

    /* U+00EC "ì" */
    0x45, 0x55,

    /* U+00ED "í" */
    0x8a, 0xaa,

    /* U+00F0 "ð" */
    0x39, 0x67, 0xb3, 0x86, 0x1c, 0xde,

    /* U+00F3 "ó" */
    0x10, 0x7, 0xb3, 0x86, 0x1c, 0xde,

    /* U+011B "ě" */
    0x70, 0x7, 0x22, 0xfa, 0xc, 0x9e,

    /* U+014B "ŋ" */
    0xf4, 0x63, 0x18, 0xc4, 0x23,

    /* U+01CE "ǎ" */
    0x30, 0x1d, 0x11, 0xf6, 0x3f,

    /* U+01D4 "ǔ" */
    0x51, 0x23, 0x18, 0xc6, 0x2f,

    /* U+0251 "ɑ" */
    0x7c, 0x63, 0x18, 0xbc,

    /* U+0252 "ɒ" */
    0xf4, 0x63, 0x18, 0xf8,

    /* U+0254 "ɔ" */
    0x74, 0x42, 0x18, 0xb8,

    /* U+0259 "ə" */
    0x79, 0x30, 0x7f, 0x44, 0xe0,

    /* U+025A "ɚ" */
    0x78, 0x46, 0x1f, 0x90, 0xf8, 0xc3, 0xc0,

    /* U+025B "ɛ" */
    0xf9, 0x68, 0x97,

    /* U+025C "ɜ" */
    0xf9, 0x61, 0x9e,

    /* U+025D "ɝ" */
    0x70, 0x9c, 0x36, 0x8, 0x88, 0x70,

    /* U+0261 "ɡ" */
    0x7c, 0x63, 0x18, 0xbe, 0x2e,

    /* U+026A "ɪ" */
    0xe9, 0x25, 0xc0,

    /* U+0283 "ʃ" */
    0x74, 0x44, 0x44, 0x44, 0x4c,

    /* U+028A "ʊ" */
    0xcd, 0x28, 0x61, 0xcd, 0xe0,

    /* U+028C "ʌ" */
    0x30, 0xc3, 0x12, 0x4a, 0x10,

    /* U+0292 "ʒ" */
    0x7c, 0x21, 0xe, 0x4, 0x14, 0xce,

    /* U+02C8 "ˈ" */
    0xc0,

    /* U+02CA "ˊ" */
    0x40,

    /* U+02CC "ˌ" */
    0xc0,

    /* U+02D0 "ː" */
    0x84,

    /* U+03A0 "Π" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,

    /* U+03A3 "Σ" */
    0xff, 0x6, 0xc, 0x31, 0x8c, 0x3f,

    /* U+03A6 "Φ" */
    0x3e, 0x24, 0xa2, 0x31, 0x18, 0x8a, 0x48, 0xf8,
    0x10,

    /* U+03B1 "α" */
    0x77, 0x38, 0xa2, 0x8d, 0xd0,

    /* U+03B2 "β" */
    0x74, 0x63, 0x68, 0xc6, 0x3e, 0x84, 0x0,

    /* U+03B3 "γ" */
    0x8c, 0x54, 0xa5, 0x10, 0x84,

    /* U+03B4 "δ" */
    0x7c, 0x87, 0x32, 0x86, 0x1c, 0xde,

    /* U+03B5 "ε" */
    0xf8, 0x68, 0x97,

    /* U+03B7 "η" */
    0xf4, 0x63, 0x18, 0xc4, 0x21,

    /* U+03B8 "θ" */
    0x7b, 0x18, 0x7f, 0x86, 0x1c, 0xde,

    /* U+03BB "λ" */
    0x20, 0x83, 0xc, 0x31, 0x24, 0xa1,

    /* U+03BC "μ" */
    0x8c, 0x63, 0x18, 0xfe, 0x10,

    /* U+03C0 "π" */
    0xff, 0x22, 0x22, 0x22, 0x22, 0x22,

    /* U+03C3 "σ" */
    0x7f, 0x9a, 0x14, 0x2c, 0xcf, 0x0,

    /* U+03C4 "τ" */
    0xf9, 0x8, 0x42, 0x10,

    /* U+03C6 "φ" */
    0x5d, 0x26, 0x4c, 0x9d, 0x4f, 0x4, 0x8,

    /* U+03C7 "χ" */
    0x45, 0x22, 0x8c, 0x30, 0xa4, 0xb1,

    /* U+03C9 "ω" */
    0x41, 0x44, 0x62, 0x31, 0x1c, 0x9b, 0xb8,

    /* U+0411 "Б" */
    0xfa, 0x8, 0x3e, 0x86, 0x18, 0x7e,

    /* U+0413 "Г" */
    0xfc, 0x21, 0x8, 0x42, 0x10,

    /* U+0414 "Д" */
    0x3e, 0x22, 0x22, 0x22, 0x22, 0x62, 0x42, 0xff,
    0x81, 0x81,

    /* U+0416 "Ж" */
    0xc4, 0x64, 0x90, 0xd6, 0xf, 0x83, 0x58, 0x49,
    0x11, 0x16, 0x23,

    /* U+0417 "З" */
    0x79, 0x10, 0x46, 0x6, 0x14, 0x5e,

    /* U+0418 "И" */
    0x87, 0xe, 0x2c, 0xdb, 0x34, 0x70, 0xe1,

    /* U+041B "Л" */
    0x7d, 0x14, 0x51, 0x45, 0x14, 0x71,

    /* U+041C "М" */
    0xc3, 0xc3, 0xc3, 0xa5, 0xa5, 0x99, 0x99, 0x99,

    /* U+041D "Н" */
    0x83, 0x6, 0xf, 0xf8, 0x30, 0x60, 0xc1,

    /* U+041E "О" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0422 "Т" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8,

    /* U+0425 "Х" */
    0x42, 0x24, 0x3c, 0x18, 0x18, 0x24, 0x66, 0xc3,

    /* U+042A "Ъ" */
    0xf0, 0x8, 0x4, 0x3, 0xe1, 0x8, 0x84, 0x42,
    0x3e,

    /* U+042B "Ы" */
    0x80, 0xc0, 0x60, 0x3f, 0x18, 0x4c, 0x26, 0x13,
    0xf1,

    /* U+042C "Ь" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x7e,

    /* U+042D "Э" */
    0x79, 0x88, 0x8, 0xf0, 0x30, 0x71, 0x3c,

    /* U+0436 "ж" */
    0x49, 0x15, 0x7, 0x5, 0x46, 0xb2, 0x48,

    /* U+0437 "з" */
    0xf9, 0x61, 0x9e,

    /* U+0438 "и" */
    0x8c, 0xeb, 0x5c, 0xc4,

    /* U+0439 "й" */
    0x70, 0x23, 0x3a, 0xd7, 0x31,

    /* U+043A "к" */
    0x95, 0x31, 0x4b, 0x48,

    /* U+043B "л" */
    0x7d, 0x14, 0x51, 0x47, 0x10,

    /* U+043C "м" */
    0xc7, 0x8e, 0xad, 0x5a, 0xb2, 0x40,

    /* U+043E "о" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0441 "с" */
    0x76, 0x61, 0x8, 0xb8,

    /* U+0447 "ч" */
    0x8c, 0x62, 0xf0, 0x84,

    /* U+0449 "щ" */
    0x91, 0x48, 0xa4, 0x52, 0x29, 0x17, 0xfc, 0x2,

    /* U+044A "ъ" */
    0xe0, 0x40, 0xf1, 0x12, 0x27, 0x80,

    /* U+044B "ы" */
    0x83, 0x7, 0xcc, 0x58, 0xbe, 0x40,

    /* U+044D "э" */
    0xf4, 0x4f, 0x19, 0xb8,

    /* U+044E "ю" */
    0x9e, 0xb3, 0xe1, 0xa1, 0xb3, 0x9e,

    /* U+0451 "ё" */
    0x50, 0x7, 0x22, 0xfa, 0xc, 0x9e,

    /* U+0454 "є" */
    0x7c, 0x79, 0x1c, 0xb8,

    /* U+04D9 "ә" */
    0x79, 0x30, 0x7f, 0x44, 0xe0,

    /* U+200B "​" */
    0x0,

    /* U+2014 "—" */
    0xff, 0xf0,

    /* U+2018 "‘" */
    0x60,

    /* U+2019 "’" */
    0xc0,

    /* U+201C "“" */
    0x16, 0x80,

    /* U+201D "”" */
    0xb4, 0x0,

    /* U+2026 "…" */
    0x88, 0x80,

    /* U+2211 "∑" */
    0xff, 0x81, 0x81, 0x3, 0x3, 0x4, 0x18, 0x20,
    0x83, 0x7, 0xf0,

    /* U+2502 "│" */
    0xff, 0xfc,

    /* U+250C "┌" */
    0xfc, 0x21, 0x8, 0x42, 0x10,

    /* U+2510 "┐" */
    0xf8, 0x42, 0x10, 0x84, 0x21,

    /* U+2514 "└" */
    0x84, 0x21, 0x8, 0x42, 0x1f,

    /* U+2518 "┘" */
    0x8, 0x42, 0x10, 0x84, 0x3f,

    /* U+251C "├" */
    0x84, 0x21, 0x8, 0x43, 0xff, 0x84, 0x21, 0x8,
    0x40,

    /* U+2524 "┤" */
    0x8, 0x42, 0x10, 0x87, 0xff, 0x8, 0x42, 0x10,
    0x84,

    /* U+2534 "┴" */
    0x8, 0x4, 0x2, 0x1, 0x0, 0x80, 0x40, 0x21,
    0xff,

    /* U+253C "┼" */
    0x8, 0x4, 0x2, 0x1, 0x0, 0x80, 0x43, 0xff,
    0xff, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80, 0x40,

    /* U+25A0 "■" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+25CB "○" */
    0x7b, 0x38, 0x73, 0x78
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 53, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 68, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 4, .adv_w = 107, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 107, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 18, .adv_w = 171, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 27, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 37, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 35, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 39, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 43, .adv_w = 75, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 45, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 49, .adv_w = 53, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 50, .adv_w = 64, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 51, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 53, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 107, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 53, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 53, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 113, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 118, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 120, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 125, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 195, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 144, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 117, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 149, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 53, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 149, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 149, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 139, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 117, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 181, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 117, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 53, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 326, .adv_w = 53, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 53, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 332, .adv_w = 90, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 336, .adv_w = 107, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 337, .adv_w = 64, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 338, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 107, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 53, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 370, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 43, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 43, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 379, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 43, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 160, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 107, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 406, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 411, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 53, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 139, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 448, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 457, .adv_w = 50, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 459, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 463, .adv_w = 112, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 465, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 467, .adv_w = 112, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 470, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 171, .box_w = 10, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 53, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 53, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 516, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 533, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 538, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 107, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 142, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 88, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 88, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 573, .adv_w = 121, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 579, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 584, .adv_w = 68, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 43, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 592, .adv_w = 109, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 597, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 105, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 608, .adv_w = 64, .box_w = 1, .box_h = 2, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 609, .adv_w = 64, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 610, .adv_w = 64, .box_w = 1, .box_h = 2, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 611, .adv_w = 53, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 119, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 153, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 111, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 110, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 646, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 651, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 657, .adv_w = 86, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 665, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 671, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 111, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 682, .adv_w = 132, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 119, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 76, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 698, .adv_w = 125, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 705, .adv_w = 101, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 711, .adv_w = 150, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 718, .adv_w = 126, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 724, .adv_w = 104, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 729, .adv_w = 130, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 739, .adv_w = 177, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 116, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 756, .adv_w = 138, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 126, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 769, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 149, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 117, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 799, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 152, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 816, .adv_w = 170, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 126, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 138, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 838, .adv_w = 128, .box_w = 9, .box_h = 6, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 845, .adv_w = 88, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 107, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 852, .adv_w = 107, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 84, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 866, .adv_w = 132, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 107, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 877, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 100, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 885, .adv_w = 158, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 893, .adv_w = 120, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 138, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 98, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 909, .adv_w = 144, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 98, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 925, .adv_w = 107, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 930, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 931, .adv_w = 192, .box_w = 12, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 933, .adv_w = 43, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 934, .adv_w = 43, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 935, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 937, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 939, .adv_w = 192, .box_w = 9, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 941, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 952, .adv_w = 120, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 954, .adv_w = 136, .box_w = 5, .box_h = 8, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 959, .adv_w = 136, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 964, .adv_w = 136, .box_w = 5, .box_h = 8, .ofs_x = 4, .ofs_y = 3},
    {.bitmap_index = 969, .adv_w = 136, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 974, .adv_w = 136, .box_w = 5, .box_h = 14, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 983, .adv_w = 136, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 992, .adv_w = 136, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1001, .adv_w = 136, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1017, .adv_w = 116, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 116, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x17, 0x37, 0x40, 0x41, 0x46, 0x48, 0x49,
    0x4b, 0x4c, 0x4d, 0x50, 0x53, 0x7b, 0xab, 0x12e,
    0x134, 0x1b1, 0x1b2, 0x1b4, 0x1b9, 0x1ba, 0x1bb, 0x1bc,
    0x1bd, 0x1c1, 0x1ca, 0x1e3, 0x1ea, 0x1ec, 0x1f2, 0x228,
    0x22a, 0x22c, 0x230, 0x300, 0x303, 0x306, 0x311, 0x312,
    0x313, 0x314, 0x315, 0x317, 0x318, 0x31b, 0x31c, 0x320,
    0x323, 0x324, 0x326, 0x327, 0x329, 0x371, 0x373, 0x374,
    0x376, 0x377, 0x378, 0x37b, 0x37c, 0x37d, 0x37e, 0x382,
    0x385, 0x38a, 0x38b, 0x38c, 0x38d, 0x396, 0x397, 0x398,
    0x399, 0x39a, 0x39b, 0x39c, 0x39e, 0x3a1, 0x3a7, 0x3a9,
    0x3aa, 0x3ab, 0x3ad, 0x3ae, 0x3b1, 0x3b4, 0x439, 0x1f6b,
    0x1f74, 0x1f78, 0x1f79, 0x1f7c, 0x1f7d, 0x1f86, 0x2171, 0x2462,
    0x246c, 0x2470, 0x2474, 0x2478, 0x247c, 0x2484, 0x2494, 0x249c,
    0x2500, 0x252b
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 9516, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 106, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t arial = {
#else
lv_font_t arial = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if ARIAL*/

