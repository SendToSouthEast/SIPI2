#include "main.h"


lv_style_t sipi2_oald10_headword_style;
lv_style_t sipi2_oald10_pos_style;
lv_style_t sipi2_oald10_phon_style;
lv_style_t sipi2_oald10_def_style;
lv_style_t sipi2_oald10_senseline_style;
lv_style_t sipi2_oald10_chn_style;
lv_style_t sipi2_oald10_examples_style;
lv_style_t sipi2_oald10_examplechn_style;
lv_style_t sipi2_oald10_shcut_style;
lv_style_t sipi2_oald10_shcutline_style;
lv_style_t sipi2_oald10_idiomheading_style;
lv_style_t sipi2_oald10_idm_style;

void oald10StylesInit(){
    lv_style_init(&sipi2_oald10_headword_style);
    lv_style_set_text_font(&sipi2_oald10_headword_style, &lv_font_montserrat_16);
    lv_style_set_text_color(&sipi2_oald10_headword_style, lv_palette_main(LV_PALETTE_RED));



    lv_style_init(&sipi2_oald10_pos_style);
    lv_style_set_text_font(&sipi2_oald10_pos_style, &lv_font_montserrat_12);
    lv_style_set_text_color(&sipi2_oald10_pos_style, lv_color_make(139, 0, 0));
    


    lv_style_init(&sipi2_oald10_phon_style);
    lv_style_set_text_font(&sipi2_oald10_phon_style, &arial);
    lv_style_set_text_color(&sipi2_oald10_phon_style, lv_color_make(86, 0, 79));


    lv_style_init(&sipi2_oald10_def_style);
    lv_style_set_text_font(&sipi2_oald10_def_style, &LV_FONT_MONTSERRAT_12);
    lv_style_set_text_color(&sipi2_oald10_def_style, lv_color_make(0, 52, 114));

    lv_style_init(&sipi2_oald10_senseline_style);
    lv_style_set_border_side(&sipi2_oald10_senseline_style, LV_BORDER_SIDE_FULL);
    lv_style_set_border_color(&sipi2_oald10_senseline_style, lv_color_make(0, 52, 114));
    lv_style_set_border_width(&sipi2_oald10_senseline_style, 1);


    lv_style_init(&sipi2_oald10_chn_style);
    lv_style_set_text_font(&sipi2_oald10_chn_style, &simhei);
    lv_style_set_text_color(&sipi2_oald10_chn_style, lv_color_make(190, 0, 47));


    lv_style_init(&sipi2_oald10_examples_style);
    lv_style_set_text_font(&sipi2_oald10_examples_style, &lv_font_montserrat_10);
    lv_style_set_text_color(&sipi2_oald10_examples_style, lv_palette_main(LV_PALETTE_TEAL));


    lv_style_init(&sipi2_oald10_examplechn_style);
    lv_style_set_text_font(&sipi2_oald10_examplechn_style, &simhei);
    lv_style_set_text_color(&sipi2_oald10_examplechn_style, lv_color_black());


    lv_style_init(&sipi2_oald10_shcut_style);
    lv_style_set_text_font(&sipi2_oald10_shcut_style, &simhei);
    lv_style_set_text_color(&sipi2_oald10_shcut_style, lv_color_make(199, 110, 6));


    lv_style_init(&sipi2_oald10_shcutline_style);
    lv_style_set_border_side(&sipi2_oald10_shcutline_style, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_border_color(&sipi2_oald10_shcutline_style, lv_color_make(199, 110, 6));
    lv_style_set_border_width(&sipi2_oald10_shcutline_style, 2);


    lv_style_init(&sipi2_oald10_idiomheading_style);
    lv_style_set_text_font(&sipi2_oald10_idiomheading_style, &lv_font_montserrat_12);
    lv_style_set_text_color(&sipi2_oald10_idiomheading_style, lv_color_make(39, 161, 176));

    lv_style_init(&sipi2_oald10_idm_style);
    lv_style_set_text_font(&sipi2_oald10_idm_style, &lv_font_montserrat_12);
    lv_style_set_text_color(&sipi2_oald10_idm_style, lv_color_make(0, 0, 139));
}