/* File: Transmit.h */

/* Libraries */
#include "schema.h"
#include "config.h"
#include "sensor.h"

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

#define MAX_SIZE 80

/* Global Variable for Packet */
extern schema_1 Gpacket;

/* Gloabal XBee object */
extern XBee Gxbee;

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

/* Clear Packet */
void clear_Packet(void);

/*Construct Packet */
void construct_Packet(int Gcount);

/* Transmit Packet */
void transmit_Packet(void);

/* Test Packet */
void construct_Test(void);

#endif







