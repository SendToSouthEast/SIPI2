#include "main.h"


void gameInitGrid(lv_obj_t *thisScr, lv_coord_t width, lv_coord_t height, int rows, int cols, lv_coord_t x,lv_coord_t y) {
    canvas = lv_canvas_create(obj);
    lv_obj_set_pos(canvas,x,y);
    lv_coord_t w = width * cols;
    lv_coord_t h = height * rows;
    lv_obj_set_size(canvas,w,h);

    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(SCREEN_WIDTH, SCREEN_HEIGHT)];
    lv_canvas_set_buffer(canvas, cbuf, SCREEN_WIDTH, SCREEN_WIDTH, LV_IMG_CF_TRUE_COLOR);

    gridWidth = width;
    gridHeight = height;
    gridSizeX = rows;
    gridSizeY = cols;

    lv_canvas_fill_bg(canvas, lv_color_white(), LV_OPA_COVER);
}

void gameDrawFill(lv_color_t color) {
    lv_canvas_fill_bg(canvas, color, LV_OPA_COVER);
}

void gameDrawPixel(int x, int y, lv_color_t color) {
    int x1 = x * gridWidth;
    int y1 = y * gridHeight;

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = color;

    lv_canvas_draw_rect(canvas,x1,y1,gridWidth,gridHeight,&rect_dsc);
}

void gameDrawRow(int row, lv_color_t color) {
    int i;
    for (i = 0; i < gridSizeX; i++) {
        gameDrawPixel(i, row, color);
    }
}

void gameDrawCol(int col, lv_color_t color) {
    int i;
    for (i = 0; i < gridSizeY; i++) {
        gameDrawPixel(col, i, color);
    }
}

void gameDrawArray(int arr[][2], int len, lv_color_t color) {
    int i;
    for (i = 0; i < len; i++) {
        gameDrawPixel(arr[i][0], arr[i][1], color);
    }
}