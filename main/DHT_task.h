/* 

	DHT22 temperature sensor driver

*/

#ifndef DHT_H_  
#define DHT_H_

#define SENSOR_TYPE DHT_TYPE_DHT11
// #define SENSOR_TYPE DHT_TYPE_AM2301
// #define SENSOR_TYPE DHT_TYPE_SI7021

#define DHT_GPIO			25

/**
 * Starts DHT sensor task
 */
void DHT_task_start(void);
float 	getHumidity();
float 	getTemperature();

#endif
