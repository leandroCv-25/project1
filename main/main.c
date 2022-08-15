/*
 *Aplication entry point
 */

#include "nvs_flash.h"

#include "DHT_task.h"
#include "wifi_app.h"
#include "wifi_reset_button.h"

void app_main(void)
{
    // INITIALISE NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);

    // start Wi_FI
    wifi_app_start();

    // Configure Wifi reset button
    wifi_reset_button_config();

    // Start DHT22 Sensor task
    DHT_task_start();
}