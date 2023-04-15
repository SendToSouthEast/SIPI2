#include "init.h"
#include "main.h"

#include "driver/gpio.h"
#include "driver/uart.h"

#define BUF_SIZE (128)   //缓冲区定义

static const char *TAG = "SIPI2_INIT";

static uint32_t key_get_key();


static QueueHandle_t uart_queue; //队列句柄
uint8_t  uartbuf[BUF_SIZE];
char uartCharBuf;
bool uartavailable = 0;

//检查
char cheakUartKeyboard(){
    if(uartavailable){
        uartavailable = 0;
        return uartCharBuf;
    }
    else return 0;
}

static void uart_event_task(void *pvParameters)
{
    uart_event_t event;
    for(;;) {
        //阻塞接收串口队列，
        //这个队列在底层发送，用户只需在应用层接收即可
        if(xQueueReceive(uart_queue, (void * )&event, (portTickType)portMAX_DELAY)) {
            switch(event.type) {//各种串口事件
                case UART_DATA:
                    uart_read_bytes(EX_UART_NUM, uartbuf, event.size, portMAX_DELAY); //阻塞接收
                    uartCharBuf = (char)uartbuf[0];
                    uartavailable = 1;
                    break;
                //Event of HW FIFO overflow detected
                case UART_FIFO_OVF: //硬件fifo溢出
                    SIPI_LOGI(TAG, "hw fifo overflow");
                    // If fifo overflow happened, you should consider adding flow control for your application.
                    // The ISR has already reset the rx FIFO,
                    // As an example, we directly flush the rx buffer here in order to read more data.
                    uart_flush_input(EX_UART_NUM);
                    xQueueReset(uart_queue);
                    break;
                //Event of UART ring buffer full
                case UART_BUFFER_FULL: //环形缓冲区满
                    SIPI_LOGI(TAG, "ring buffer full");
                    // If buffer full happened, you should consider encreasing your buffer size
                    // As an example, we directly flush the rx buffer here in order to read more data.
                    uart_flush_input(EX_UART_NUM);
                    xQueueReset(uart_queue);
                    break;
                //Event of UART RX break detected
                case UART_BREAK:
                    SIPI_LOGI(TAG, "uart rx break");
                    break;
                //Event of UART parity check error
                case UART_PARITY_ERR:
                    SIPI_LOGI(TAG, "uart parity error");
                    break;
                //Event of UART frame error
                case UART_FRAME_ERR:
                    SIPI_LOGI(TAG, "uart frame error");
                    break;
                //UART_PATTERN_DET
                case UART_PATTERN_DET:
                    break;
                //Others
                default:
                    SIPI_LOGI(TAG, "uart event type: %d", event.type);
                    break;
            }
        }
    }
    vTaskDelete(NULL);
}

void UART2_INIT(){
    	/* Configure parameters of an UART driver,
     * communication pins and install the driver */
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    //Install UART driver, and get the queue.
    uart_driver_install(EX_UART_NUM, BUF_SIZE * 2, BUF_SIZE * 2, 20, &uart_queue, 0);
    uart_param_config(EX_UART_NUM, &uart_config);
    uart_set_rx_full_threshold(EX_UART_NUM,126);

    //Set UART pins (using UART0 default pins ie no changes.)
    uart_set_pin(EX_UART_NUM, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    //Create a task to handler UART event from ISR
    xTaskCreate(uart_event_task, "uart_event_task", 2048, NULL, 12, NULL); //创建串口任务
}

void GPIO_INIT(){
    // 暂时废除esp32硬件直连按键
    // gpio_set_direction(SIPI_KEY_UP, GPIO_MODE_INPUT);
    // gpio_set_direction(SIPI_KEY_DOWN, GPIO_MODE_INPUT);
    // gpio_set_direction(SIPI_KEY_LEFT, GPIO_MODE_INPUT);
    // gpio_set_direction(SIPI_KEY_RIGHT, GPIO_MODE_INPUT);

    // gpio_set_direction(SIPI_KEY_YES, GPIO_MODE_INPUT);
    // gpio_set_direction(SIPI_KEY_NO, GPIO_MODE_INPUT);
}



static uint32_t key_get_key(){
    // 暂时废除esp32硬件直连按键
    // if(!gpio_get_level(SIPI_KEY_UP)){
    //     return SIPI_KEY_UP;
    // }
    // if(!gpio_get_level(SIPI_KEY_DOWN)){
    //     return SIPI_KEY_DOWN;
    // }
    // if(!gpio_get_level(SIPI_KEY_RIGHT)){
    //     return SIPI_KEY_RIGHT;
    // }
    // if(!gpio_get_level(SIPI_KEY_LEFT)){
    //     return SIPI_KEY_LEFT;
    // }
    // if(!gpio_get_level(SIPI_KEY_YES)){
    //     return SIPI_KEY_YES;
    // }
    return 0;
}

void key_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    // 暂时废除esp32硬件直连按键
    static uint32_t last_key = 0;
 
    /*Get whether the a key is pressed and save the pressed key*/
    //uint32_t act_key = key_get_key();
    uint8_t act_key = cheakLVKey();


    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;
        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
            case LV_KEY_LEFT:
                act_key = LV_KEY_PREV;
                break;
            case LV_KEY_RIGHT:
                act_key = LV_KEY_NEXT;
                break;
            case LV_KEY_UP:
                act_key = LV_KEY_UP;//LV_KEY_HOME;
                break;
            case LV_KEY_DOWN:
                act_key = LV_KEY_DOWN;//LV_KEY_ENTER;
                break;
            case LV_KEY_ENTER:
                act_key = LV_KEY_ENTER;//LV_KEY_ENTER;
                break;
        }
        
        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
 
    data->key = last_key;
}

void SIPI_LOGI(const char* tag, const char* format, ...) {
    va_list args;
    va_start(args, format);

    char message[256];
    vsnprintf(message, 256, format, args);
    
#ifdef USEESP32
    ESP_LOGI(tag, "%s", message);
#endif

#ifdef USEWINDOWS
    LV_LOG_USER("[%s]: %s", tag, message);
#endif

    va_end(args);
}