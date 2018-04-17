/* File: schema.h */
//need to include the structs for the bme 280, and sunlight grove sensor//
/* External Library */
#include <stdint.h>

#ifndef SCHEMA_H
#define SCHEMA_H

/* Schema for Weatherbox Packets */
typedef struct {
    uint16_t schema;
    uint16_t address;    // Address of Arduino 
    uint32_t uptime_ms;   // Time since start of program
    uint16_t batt_mv[6]; // Battery Voltage (in milli volts)
    uint16_t panel_mv[6];  // Panel Voltage (in milli volts)
    uint16_t bme280_Temp; //Temperature value
    uint16_t bme280_Humid; //Humidity value
    uint16_t bme280_Press; //Pressure value
    uint16_t sunlight_grove_sensor; //Sunlight value

} schema_1;

/* Struct for Health Check */
typedef struct {
  uint16_t schema;  //Schema ID number
  uint16_t address; //ADdress of Arduino
  uint32_t uptime_ms; //Time since the start of program
  uint16_t batt_mv; //Battery voltage (millivolts)
} schema_5;

#endif
