#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BUT_BUT2
#define LV_ATTRIBUTE_IMG_BUT_BUT2
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BUT_BUT2 uint8_t but_but2_map[] = {
  0xfb, 0xfb, 0xfb, 0xff, 	/*Color of index 0*/
  0x29, 0x29, 0x29, 0xff, 	/*Color of index 1*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x3e, 0x0d, 0xc0, 0x7f, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x7f, 0xcc, 0x6d, 0xe1, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf8, 0x10, 0xc0, 0xf6, 0xff, 0x80, 0x30, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x70, 0x3f, 0xf1, 0x80, 0x18, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x18, 0x0f, 0x19, 0x80, 0x0c, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x07, 0x1f, 0x00, 0x0c, 0x00, 0x00, 
  0x00, 0x00, 0x0c, 0x60, 0x00, 0x00, 0x04, 0x03, 0xbd, 0x00, 0x0c, 0x00, 0x00, 
  0x00, 0x00, 0x1d, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xe1, 0x80, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0x37, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xc0, 0x06, 0x00, 0x00, 
  0x00, 0x01, 0x2e, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x60, 0x06, 0x00, 0x00, 
  0x00, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x40, 0x30, 0x20, 0x06, 0x00, 0x00, 
  0x00, 0x01, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x60, 0x18, 0x30, 0x04, 0x00, 0x00, 
  0x00, 0x01, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x30, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0x60, 0x04, 0x00, 0x00, 0x00, 0x10, 0x0c, 0x10, 0x04, 0x00, 0x00, 
  0x00, 0x20, 0x60, 0x04, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x18, 0x06, 0x00, 0x00, 
  0x00, 0x78, 0xc0, 0x04, 0x00, 0x00, 0x00, 0x08, 0x06, 0x18, 0x04, 0x00, 0x00, 
  0x00, 0xc1, 0xc0, 0x04, 0x00, 0x00, 0x00, 0x0c, 0x06, 0x18, 0x04, 0x00, 0x00, 
  0x00, 0x83, 0x80, 0x04, 0x00, 0x00, 0x00, 0x0c, 0x02, 0x18, 0x06, 0x00, 0x00, 
  0x00, 0xc6, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x06, 0x18, 0x04, 0x00, 0x00, 
  0x00, 0xcc, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x02, 0x08, 0x06, 0x00, 0x00, 
  0x00, 0x6c, 0x00, 0x02, 0x00, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x06, 0x00, 0x00, 
  0x00, 0x67, 0xc0, 0x02, 0x00, 0x00, 0xc0, 0x03, 0xc3, 0xc0, 0x06, 0x00, 0x00, 
  0x00, 0x33, 0xc0, 0x02, 0x00, 0x00, 0xc0, 0x07, 0xe7, 0xe8, 0x02, 0x00, 0x00, 
  0x00, 0x31, 0x80, 0x03, 0x00, 0x00, 0xc0, 0x07, 0x30, 0x78, 0x03, 0x00, 0x00, 
  0x00, 0x13, 0x00, 0x03, 0x00, 0x00, 0xc0, 0x0d, 0x30, 0x6c, 0x03, 0x00, 0x00, 
  0x00, 0x1b, 0x00, 0x01, 0x00, 0x00, 0xc0, 0x0f, 0xb9, 0xec, 0x01, 0x80, 0x00, 
  0x00, 0x13, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x19, 0xed, 0xc4, 0x00, 0xe0, 0x00, 
  0x00, 0x12, 0x00, 0x01, 0x8c, 0x00, 0x40, 0x19, 0xc6, 0xc6, 0x00, 0x78, 0x00, 
  0x00, 0x36, 0x00, 0x30, 0x99, 0x80, 0x60, 0x1f, 0xc6, 0xc2, 0x00, 0x3c, 0x00, 
  0x00, 0x32, 0x00, 0x10, 0xd9, 0xf0, 0x7a, 0x0f, 0xec, 0xe3, 0x78, 0x0e, 0x00, 
  0x00, 0x36, 0x00, 0x10, 0x78, 0x3f, 0x7e, 0x0f, 0xbd, 0xc1, 0xff, 0x03, 0x00, 
  0x00, 0x26, 0x00, 0x10, 0x38, 0x0e, 0x0e, 0x1b, 0x8f, 0x81, 0xe3, 0xc3, 0x00, 
  0x00, 0x26, 0x00, 0x30, 0x00, 0x00, 0x06, 0x33, 0xe3, 0x80, 0xe0, 0xe1, 0x80, 
  0x00, 0x62, 0x00, 0x10, 0x00, 0x00, 0x03, 0x60, 0x31, 0x00, 0xf0, 0x30, 0x80, 
  0x00, 0xc7, 0x00, 0x31, 0xe0, 0x00, 0x01, 0xc0, 0x18, 0x00, 0x70, 0x18, 0xc0, 
  0x00, 0x83, 0x00, 0x1f, 0xe0, 0x00, 0x01, 0x03, 0x18, 0x00, 0x78, 0x18, 0xc0, 
  0x01, 0x83, 0x27, 0x18, 0x00, 0x00, 0x06, 0x0f, 0x18, 0x00, 0x38, 0x0c, 0xc0, 
  0x01, 0x01, 0xb1, 0xfd, 0x00, 0x0c, 0x1e, 0x0f, 0x18, 0x00, 0x1c, 0x0c, 0xc0, 
  0x03, 0x01, 0xf1, 0xff, 0xc0, 0x0f, 0x3c, 0x1b, 0x18, 0x00, 0x1c, 0x0c, 0xc0, 
  0x02, 0x01, 0xdb, 0x80, 0xe0, 0x01, 0xff, 0x0f, 0x30, 0x00, 0x0e, 0x06, 0xc0, 
  0x06, 0x01, 0x8e, 0x00, 0x30, 0x00, 0x5b, 0x84, 0x60, 0x00, 0x06, 0x27, 0x80, 
  0x04, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x11, 0x80, 0xc0, 0x00, 0x00, 0x37, 0x80, 
  0x0c, 0x00, 0x08, 0x03, 0x98, 0x00, 0x07, 0x01, 0x80, 0x00, 0x00, 0x26, 0x00, 
  0x0c, 0x00, 0x18, 0x07, 0x8c, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x7e, 0x00, 
  0x08, 0x03, 0x10, 0x00, 0x0c, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x78, 0x00, 
  0x18, 0x07, 0x00, 0x01, 0x4c, 0x3e, 0x06, 0xc0, 0x00, 0x00, 0x00, 0xf0, 0x00, 
  0x18, 0x04, 0x00, 0x01, 0xcc, 0xfc, 0x07, 0xc0, 0x00, 0x00, 0x01, 0xe0, 0x00, 
  0x10, 0x2c, 0x00, 0x00, 0x18, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x11, 0xbc, 0x00, 0x00, 0x10, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x33, 0x9c, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x32, 0x1c, 0x00, 0x01, 0xef, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x16, 0x0e, 0x00, 0x01, 0xe2, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t but_but2 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 100,
  .header.h = 77,
  .data_size = 1009,
  .data = but_but2_map,
};
