#include "sdcard_init.h"
#include "sdkconfig.h"

#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "driver/sdmmc_host.h"
 
#define MOUNT_POINT "/sdcard"

 
static const char *TAG = "SDCARD_INIT";
 
esp_err_t sdcard_init_for_ff(){
    esp_err_t ret;

    ESP_LOGI(TAG, "Initializing SD card");
 
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
#ifdef SD_FORMAT_IF_MOUNT_FAILED
        .format_if_mount_failed = true,
#else
        .format_if_mount_failed = false,
#endif 
        .max_files = 5,
        .allocation_unit_size = 16 * 1024
    };

    sdmmc_card_t *card;
    const char mount_point[] = MOUNT_POINT;
    
 
#ifdef CONFIG_SD_INIT_INTERFACE_VSPI
    ESP_LOGI(TAG, "Using SPI peripheral");

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    host.slot = VSPI_HOST; // 使用VSPI总线防止冲突
    spi_bus_config_t bus_cfg = {
        .mosi_io_num = CONFIG_SD_PIN_NUM_MOSI,
        .miso_io_num = CONFIG_SD_PIN_NUM_MISO,
        .sclk_io_num = CONFIG_SD_PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,
    };
    ret = spi_bus_initialize(host.slot, &bus_cfg, host.slot);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize bus.");
        return ret;
    }
    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = CONFIG_SD_PIN_NUM_CS;
    slot_config.host_id = host.slot;
 
    ESP_LOGI(TAG, "Mounting filesystem");
    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
 

#endif // CONFIG_SD_INIT_INTERFACE_VSPI
#ifdef CONFIG_SD_INIT_INTERFACE_HSPI
    
    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    host.slot = VSPI_HOST; 

    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = CONFIG_SD_PIN_NUM_CS;
    slot_config.host_id = host.slot;
 
    ESP_LOGI(TAG, "Mounting filesystem");
    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
 
#endif // CONFIG_SD_INIT_INTERFACE_HSPI
#ifdef CONFIG_SD_INIT_INTERFACE_SDMMC
    ESP_LOGI(TAG, "Using SDMMC peripheral");
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();

    // This initializes the slot without card detect (CD) and write protect (WP) signals.
    // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

    // Set bus width to use:
#ifdef CONFIG_SDMMC_BUS_WIDTH_4
    slot_config.width = 4;
#else
    slot_config.width = 1;
#endif

    // On chips where the GPIOs used for SD card can be configured, set them in
    // the slot_config structure:
#ifdef CONFIG_SOC_SDMMC_USE_GPIO_MATRIX
    slot_config.clk = CONFIG_SDMMC_PIN_CLK;
    slot_config.cmd = CONFIG_SDMMC_PIN_CMD;
    slot_config.d0 = CONFIG_SDMMC_PIN_D0;
#ifdef CONFIG_SDMMC_BUS_WIDTH_4
    slot_config.d1 = CONFIG_SDMMC_PIN_D1;
    slot_config.d2 = CONFIG_SDMMC_PIN_D2;
    slot_config.d3 = CONFIG_SDMMC_PIN_D3;
#endif  // CONFIG_SDMMC_BUS_WIDTH_4
#endif  // CONFIG_SOC_SDMMC_USE_GPIO_MATRIX

    // Enable internal pullups on enabled pins. The internal pullups
    // are insufficient however, please make sure 10k external pullups are
    // connected on the bus. This is for debug / example purpose only.
    slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP;

    ESP_LOGI(TAG, "Mounting filesystem");
    ret = esp_vfs_fat_sdmmc_mount(mount_point, &host, &slot_config, &mount_config, &card);

#endif // CONFIG_SD_INIT_INTERFACE_SDMMC

    if(ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount filesystem. "
                     "If you want the card to be formatted, set the CONFIG_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        } else {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                     "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
        }
        return ESP_FAIL;
    }


 
    ESP_LOGI(TAG, "Filesystem mounted");
    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);
    return ESP_OK;
}