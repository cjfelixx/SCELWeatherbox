/*Internal Libraries*/
#include "sensors.h"
#include "config.h"

/*Objects*/
SHT1x sht1x(H_DATA_PIN, H_CLK_PIN);
Adafruit_BME280 bme;

void sensor_init(void){
   bme280.begin();
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
  long val = analogRead(APOGEE_PIN)*(5000.0/1023);
  return (val/2) //check datasheet for this calc
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
