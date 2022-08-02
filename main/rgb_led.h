#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_
//RGB LED GPIOs
#define RGB_LED_RED_GPIO 21
#define RGB_LED_GREEN_GPIO 22
#define RGB_LED_BLUE_GPIO 23

//RGB LED Color mix channels
#define RGB_LED_CHANNEL_NUM 3

//RGB LED configuration
typedef struct
{
    int channel;
    int gpio;
    int mode;
    int timer_index;
}ledc_info_t;

ledc_info_t ledc_ch[RGB_LED_CHANNEL_NUM];

//Color to indicate WiFi aplication has started
void rgb_led_wifi_app_started(void);

//Color to indicate http server has started
void rgb_led_http_server_started(void);

//Color to indicate Wifi is connected
void rgb_led_wifi_connected(void);


#endif