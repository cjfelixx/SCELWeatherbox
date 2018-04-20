/*Internal Libraries*/
#include "sensors.h"
#include "config.h"
#include "SI114X.h"

/*Objects*/
Adafruit_BME280 bme; //I2C wiring
SI114X SI1145 = SI114X(); 

void sensor_init(void)
{
   bme.begin();
}

/*Humidity*/ 
long sHumidity(void)
{
  long val = bme.readHumidity();
  return val; //in percentage
}

/*Pressure*/
long sPressure(void)
{
  long val = bme.readPressure();
  return val; //unit in hPa
}

/*Temperature*/ 
long sTemperature(void)
{
  long val = bme.readTemperature();
  return val; //in C
}

/*Solar Irradiance*/
long sSolIrrad(void)
{
  long val = SI1145.ReadVisible();
  return val; //check datasheet for this calc
}

/*Battery*/
long battStatus(void)
{
  long val = analogRead(PIN_BATT_V)*(5000.0/1023);
  return val;
}

/*SOLAR PANEL*/
/* Times 2 to account for voltage divider, add 700 to account for voltage drop across diode on charging chip. */ 
long panelStatus(void)
{
  long val = 2*(analogRead(PIN_SOLAR_V)*(5000.0/1023));
  return val;
}
