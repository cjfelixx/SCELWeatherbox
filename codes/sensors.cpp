/* File: weatherbox.ino */
/* The main driver for the weatherbox */


/* Libraries */
#include "config.h"
#include "sensors.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"
#include "SI114X.h"

/* External Libraries */
#include <OneWire.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <XBee.h>

/* Global Variables for Packet */
schema_1 Gpacket;

/* Global Xbee object */
XBee Gxbee = XBee();

/* Global count variable */
int G_count = 0;

void setup() {

    /* Initialization */
    sensor_init();
    Serial.begin(9600);
    Gxbee.begin(Serial); 

    /*Packet Initialization */
    clear_Packet();
}


void loop() {
    routine(&G_count);
}     
