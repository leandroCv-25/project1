#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include <dht.h>

#include "tasks_common.h"
#include "DHT_task.h"

static const char *TAG = "DHT";

// Global variables
//========================================
float temperature, humidity;

float getHumidity() { return humidity; }
float getTemperature() { return temperature; }

/**
 * DHT Sensor task
 */
static void DHT_task(void *pvParameter)
{

	printf("Starting DHT task\n\n");
#ifdef CONFIG_EXAMPLE_INTERNAL_PULLUP
	gpio_set_pull_mode(DHT_GPIO, GPIO_PULLUP_ONLY);
#endif

	while (true)
	{

		if (dht_read_float_data(SENSOR_TYPE, DHT_GPIO, &humidity, &temperature) == ESP_OK)
		{
			printf("Humidity: %.1f%% Temp: %.1fC\n", getHumidity(), getTemperature());
		}
		else
		{
			ESP_LOGI(TAG, "Could not read data from sensor");
		}

		// Wait at least 2 seconds before reading again
		// The interval of the whole process must be more than 2 seconds
		vTaskDelay(4000 / portTICK_RATE_MS);
	}
}

void DHT_task_start(void)
{
	xTaskCreatePinnedToCore(&DHT_task, "DHT_task", DHT_TASK_STACK_SIZE, NULL, DHT_TASK_PRIORITY, NULL, DHT_TASK_CORE_ID);
}