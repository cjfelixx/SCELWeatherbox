/* File: sensors.h
   Header file for Sensor functions
*/

/* Libraries */
#include <SHT1x.h>                  /* Humidity Sensor */
#include <OneWire.h>                /*Temperature Sensor */
#include <DallasTemperature.h>      /* Temperature Sensor */
#include <Adafruit_BMP085.h>        /*Pressure Sensor */

/* Create instances of object */
extern SHT1x sht1x;
extern OneWire oneWire;
extern DallasTemperature dallas_roof_sen;
extern Adafruit_BMP085 bmp085;

/*Initialization Function */
void sensor_init(void);

/* Sensor Functions */
long sensorPressure(void);
long sensorSolarIrrd(void);
long sensorHumidity(void);         
long sensorRoofTempdecic(void);             
long sensorBattery(void);
long sensorPanelmV(void);

