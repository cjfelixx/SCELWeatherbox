/* Sensors Libraries*/
#include <Wire.h>
#include <XBee.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "Arduino.h"
#include "SI114X.h"

/*Initialization Function*/
void sensor_init(void);

/*Sensor Functions*/
long sPressure(void);
long sSolIrrad(void);
long sHumidity(void);
long sTemperature(void);
long batteryStatus(void);
long panelStatus(void);
