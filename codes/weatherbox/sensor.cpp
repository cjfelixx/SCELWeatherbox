/*  File: sensors.cpp
    Function definitions for sensors
*/

/* Libraries */
#include "sensor.h"
#include "config.h"

/* Set pins */
OneWire oneWire(PIN_ROOF_TEMP);              /* Temperature pins and objects */
DallasTemperature dallas_roof_sen(&oneWire);
SHT1x sht1x(PIN_HUMID_DATA, PIN_HUMID_CLK);
Adafruit_BMP085 bmp085;                       /* Pressure object */


/* Initialization */
void sensor_init(void)
{
 bmp085.begin();      
}

/* Humidity */
long sensorHumidity(void)
{
    long value = sht1x.readHumidity();
    return value;
}

/* Pressure */
long sensorPressure(void)
{
    long value =  bmp085.readPressure();
    return value; 
}

/* Temperature Sensor */
long sensorRoofTempdecic(void)      
{
    long value =  0;
    dallas_roof_sen.requestTemperatures();
    value = dallas_roof_sen.getTempCByIndex(0);
    return value;
}

/*Solar Irradiance */
long sensorSolarIrrd(void)
{
  long sensorValue = analogRead(PIN_APOGEE_V) * 5000.0/1023;
  return sensorValue* 0.5;
}





/*Battery */
long sensorBattery(void)
{
    long value = analogRead(PIN_BATT_V)*5000.0/1023;
    return value;
}


/* Solar Panel */
/* Times 2 to account for voltage divider, add 700 to account for voltage drop across diode on charging chip. */ 
long sensorPanelmV(void)
{
    long value = 2*analogRead(PIN_SOLAR_V)*5000.0/1023;
    return value;
}



