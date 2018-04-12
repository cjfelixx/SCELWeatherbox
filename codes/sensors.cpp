/*Internal Libraries*/
#include "sensors.h"
#include "config.h"

/*Objects*/
Adafruit_BME280 bme;

void sensor_init(void){
   bme.begin();
}

/*Humidity*/
long sHumidity(void){
  long val = bme.readHumidity();
}

/*Pressure*/
long sPressure(void){
  long val = bme.readPressure();
}

/*Temperature*/
long sTemperature(void){
  long val = bme.readTemperature();
}

/*Solar Irradiance*/
long sSolIrrad(void){
  long val = SI1145.ReadVisible();
  return (val) //check datasheet for this calc
}

/*Battery*/
long battStatus(void){
  long val = analogRead(BATT_PIN)*(5000.0/1023);
  return val;
}

/*SOLAR PANEL*/
long panelStatus(void){
  long val = 2 * (analogRead(PANEL_PIN)*(5000.0/1023);
  return val;
}


/* Solar Panel */
/* Times 2 to account for voltage divider, add 700 to account for voltage drop across diode on charging chip. */ 
long sensorPanelmV(void)
{
    long value = 2*analogRead(PIN_SOLAR_V)*5000.0/1023;
    return value;
}
