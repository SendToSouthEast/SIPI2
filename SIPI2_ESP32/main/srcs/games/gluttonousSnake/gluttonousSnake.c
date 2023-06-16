/**
 * @brief 贪吃蛇游戏
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_WHITE lv_color_hex(0xFFFFFF)   // 白色
#define COLOR_BLACK lv_color_hex(0x000000)   // 黑色
#define COLOR_RED   lv_color_hex(0xFF0000)   // 红色
#define COLOR_GREEN lv_color_hex(0x00FF00)   // 绿色
#define COLOR_BLUE  lv_color_hex(0x0000FF)   // 蓝色


// 坐标结构体
typedef struct {
    int x;
    int y;
} Coord;

// 游戏状态枚举类型
typedef enum GameStatus {
    GAME_RUNNING,       // 游戏运行中
    GAME_PAUSE,         // 游戏暂停
    GAME_OVER,          // 游戏结束
    GAME_WIN            // 游戏胜利

} GameStatus;

// 贪吃蛇结构体
typedef struct {
    Coord* body;        // 蛇身坐标数组
    int length;         // 蛇长
    int direction;      // 方向：1左 2上 3右 4下
} Snake;

// 食物结构体
typedef struct {
    Coord pos;          // 食物的坐标
} Food;



// 清空屏幕
void gameClearScreen(lv_color_t color);

// 控制游戏逻辑和操作
void gameChangeSnakeDirection(Snake* s, int direction);
void gameMoveSnake(Snake* s);
Coord gameGetNextPos(Coord currentPos, int direction);
int gameIsCollided(Snake* s, Coord pos);
void gameAddFood(Food* food, Snake* s);
void gameReset(Snake* s, Food* food);
void gameCheckWin(Snake* s);

// UI绘制
void gameDrawSnake(Snake* s, lv_color_t color);
void gameDrawFood(Food* food, lv_color_t color);

// 获取随机数（用于生成食物）
int getRandomNumber(int min, int max);

Snake snake;
Food food;
GameStatus gameStatus;
lv_color_t bgColor;
lv_color_t snakeColor;
lv_color_t foodColor;

void game() {


    // 初始化蛇、食物
    snake.body = (Coord*)malloc(sizeof(Coord) * 200);
    snake.length = 2;
    snake.direction = 3;    // 初始方向向右
    snake.body[0].x = 1;    // 初始位置
    snake.body[0].y = 1;
    snake.body[1].x = 0;
    snake.body[1].y = 1;

    food.pos.x = 0;
    food.pos.y = 0;

    gameStatus = GAME_RUNNING;
    bgColor = COLOR_BLACK;
    snakeColor = COLOR_GREEN;
    foodColor = COLOR_RED;

    gameAddFood(&food, &snake);
}
void gameDrawSnakeTask(){
    LV_LOG_USER("11111");
        // 控制游戏逻辑
        if (gameStatus == GAME_RUNNING) {
            gameMoveSnake(&snake);
            if (gameIsCollided(&snake, food.pos)) {
                snake.length++;
                gameAddFood(&food, &snake);
            }
            if (gameIsSelfCollided(&snake) || gameIsBorderCollided(&snake)) {
                gameStatus = GAME_OVER;
            }
            if (snake.length >= 200) {
                gameStatus = GAME_WIN;  // 游戏胜利
            }
            gameCheckWin(&snake);


        // 绘制屏幕
        gameClearScreen(bgColor);
        gameDrawSnake(&snake, snakeColor);
        gameDrawFood(&food, foodColor);

        // 检查键盘事件
        int ch = getchar();
        switch (ch) {
            case 'w':   // 上
                if (snake.direction != 4) {
                    gameChangeSnakeDirection(&snake, 2);
                }
                break;
            case 'a':   // 左
                if (snake.direction != 3) {
                    gameChangeSnakeDirection(&snake, 1);
                }
                break;
            case 's':   // 下
                if (snake.direction != 2) {
                    gameChangeSnakeDirection(&snake, 4);
                }
                break;
            case 'd':   // 右
                if (snake.direction != 1) {
                    gameChangeSnakeDirection(&snake, 3);
                }
                break;
            case '\n':
            case '\r':
            case ' ':
                // 暂停/继续游戏
                if (gameStatus == GAME_RUNNING) {
                    gameStatus = GAME_OVER;
                } else if (gameStatus == GAME_OVER) {
                    gameStatus = GAME_RUNNING;
                }
                break;
            case 'q':
            case 'Q':
                // 退出游戏
                free(snake.body);
                exit(0);
        }
        }
}

void gameClearScreen(lv_color_t color) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            gameDrawPixel(j, i, color);
        }
    }
}

void gameChangeSnakeDirection(Snake* s, int direction) {
    s->direction = direction;
}

void gameMoveSnake(Snake* s) {
    // 把蛇身体的每个部分向前移动一格
    for (int i = s->length - 1; i > 0; i--) {
        s->body[i] = s->body[i - 1];
    }
    // 根据方向移动蛇头
    Coord nextPos = gameGetNextPos(s->body[0], s->direction);
    s->body[0] = nextPos;
}

Coord gameGetNextPos(Coord currentPos, int direction) {
    Coord nextPos = currentPos;
    switch (direction) {
        case 1:     // 左
            nextPos.x--;
            break;
        case 2:     // 上
            nextPos.y--;
            break;
        case 3:     // 右
            nextPos.x++;
            break;
        case 4:     // 下
            nextPos.y++;
            break;
    }
    return nextPos;
}

int gameIsCollided(Snake* s, Coord pos) {
    return s->body[0].x == pos.x && s->body[0].y == pos.y;
}

int gameIsSelfCollided(Snake* s) {
    // 从第二个坐标开始遍历，因为蛇头肯定不会碰到自己
    for (int i = 1; i < s->length; i++) {
        if (s->body[0].x == s->body[i].x && s->body[0].y == s->body[i].y) {
            return 1;
        }
    }
    return 0;
}

int gameIsBorderCollided(Snake* s) {
    if (s->body[0].x < 0 || s->body[0].x >= gridSizeX||
        s->body[0].y < 0 || s->body[0].y >= gridSizeX) {
        return 1;
    }
    return 0;
}

void gameAddFood(Food* food, Snake* s) {
    int x, y;
    do {
        x = getRandomNumber(0, gridSizeX - 1);
        y = getRandomNumber(0, gridSizeY - 1);
    } while (gameIsCollided(s, (Coord){x, y}));
    food->pos.x = x;
    food->pos.y = y;
}

void gameReset(Snake* s, Food* food) {
    s->length = 2;
    s->direction = 3;
    s->body[0].x = 1;
    s->body[0].y = 1;
    s->body[1].x = 0;
    s->body[1].y = 1;
    gameAddFood(food, s);
}

void gameCheckWin(Snake* s) {
    if (s->length >= 200) {
        printf("You win!\n");
        exit(0);
    }
}

void gameDrawSnake(Snake* s, lv_color_t color) {
    for (int i = 0; i < s->length; i++) {
        gameDrawPixel(s->body[i].x, s->body[i].y, color);
    }
}

void gameDrawFood(Food* food, lv_color_t color) {
    gameDrawPixel(food->pos.x, food->pos.y, color);
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}


void gluttonousSnakeSceneInit(){
    LV_LOG_USER("11111");
    gameInitGrid(lv_scr_act(), 8, 8, 16, 16,0,0);
    //gameDrawRow(1, lv_color_black());
    game();
    gameDrawSnakeTask();
}