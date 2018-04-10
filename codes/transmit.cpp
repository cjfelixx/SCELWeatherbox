/* File: transmit.cpp  */

/* Libraries */
#include "transmit.h"

/* Uncomment for serial debug */
//#define DEBUG

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name: clear_Packet                                  *
 * Returns:  Nothing                                   *
 * Description: Initializes/Clears Packet to Zero.     *
 *                                                     *
 *                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void clear_Packet(void) {

  #ifdef DEBUG
  Serial.print("Begin:clear\n");
  #endif

  /* Variables for indexes */
  int i,j,k;

  /* Clear/init values in packet */
  Gpacket.address = EEPROM.read(2) | (EEPROM.read(3) << 8);;
  Gpacket.uptime_ms = 0;
  Gpacket.bmp085_press_pa = 0;
  Gpacket.humidity_centi_pct = 0;
  Gpacket.dallas_roof_c = 0;

  /* Clear/init values with multiple points */ 
  for(i = 0 ; i < 60; i++){
    j = i/10;
    k = i/3;

    /* Polled every 10 seconds */
    Gpacket.batt_mv[j] = 0;
    Gpacket.panel_mv[j] = 0;
    /* Polled every 3 seconds */
    Gpacket.apogee_w_m2[k] = 0;
  }

  #ifdef DEBUG
  Serial.print("End:clear\n");
  #endif
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name: construct_Packet                                * 
 * Returns: Nothing                                      *
 * Description: Creates a packet with data from sensors. *
 *                                                       *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void construct_Packet(int Gcount) {
  
  /* Set Global Count */
  int i = Gcount;

  #ifdef DEBUG
  Serial.print("Begin:con\n");
  #endif
  
  /* Set Packet Schema # */
  Gpacket.schema = 297;
  
  /* Initialize  Sensor Variables */
  long BatterymV = 0;
  long SolarIrrmV = 0;
  long SolarIrr_w_m2 = 0;
  long Humiditypct = 0;
  long PanelmV = 0;
  long Pressurepa = 0;
  long Tempdecic = 0;
  long Dallas_RoofTemp_c = 0;
  unsigned long uptime;

  /* Get Polling Sensor Data */ 
  BatterymV = sensorBattery();
  PanelmV = sensorPanelmV();
  SolarIrrmV = sensorSolarIrrd();
    
  /* Pack Polling Data */
  Gpacket.panel_mv[i/10] = PanelmV;
  Gpacket.batt_mv[i/10] = BatterymV;
  Gpacket.apogee_w_m2[i/3] = SolarIrrmV;
    
  /* Get and Pack Non-Polling Data */
  Humiditypct = sensorHumidity();
  Pressurepa = sensorPressure();
  Tempdecic = sensorRoofTempdecic();
  Gpacket.bmp085_press_pa = Pressurepa;
  Gpacket.humidity_centi_pct = Humiditypct;
  Gpacket.dallas_roof_c = Tempdecic;
    
  /*Update uptime */
  uptime = millis();
  Gpacket.uptime_ms = uptime;
   
  /* Debug Statements */    
  #ifdef DEBUG
  Serial.print("\nPanelmV Data:");
  Serial.println(PanelmV);
  Serial.print("\nBatterymV Data:");
  Serial.println(BatterymV);
  Serial.print("\nSolarIrrmV Data:");
  Serial.println(SolarIrrmV);
  Serial.print("\nHumiditypct Data:");
  Serial.println(Humiditypct);
  Serial.print("\nPressurepa Data:");
  Serial.println(Pressurepa);
  Serial.print("\nRoofTempdecic Data:");
  Serial.println(Tempdecic);
  Serial.print("End:con\n");
  #endif
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Name: transmit_Packet                                 *
 * Returns: Nothing                                      *
 * Description: Sends Packet using Xbbe arduino library. *
 * sent as a binary packet.                              *  
 *                                                       * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void transmit_Packet(void) {

  /* Variable to contain length */
  int len = 0;

  /* Obtain address of receiving end */
  XBeeAddress64 addr64 = XBeeAddress64(0x0,0x0);
    
  /* Packet to be transmitted */
  uint8_t payload[MAX_SIZE];

  /* Clear the payload */
  memset(payload, '\0', sizeof(payload));

  /* Obtain length of the packet */
  len = sizeof(Gpacket);

  /* Transfer information into payload */
  memcpy(payload, &Gpacket, len);

 /* Transfer the payload */
  ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
  Gxbee.send(zbTx); //!!Prints packet to serial monitor
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Name: construct_Test                                    *
 * Returns: Nothing                                        *
 * Description: Constructs a hard coded packet for testing.*
 *                                                         *
 *                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void construct_Test(void){
  /* Hard-coded data to put into packet */
  long batt_mv_raw = 1;
  long panel_mv_raw = 2;
  long apogee_raw = 3;
  long pressure_raw = 4;
  long humidity_raw = 5;
  long dallas_rooftemp_decic = 6;
  unsigned long uptime = 1000;

  /* Debug */
  Serial.println(F("Generating - BIN"));

  /* Store values into packet */
  Gpacket.batt_mv[n/10] = batt_mv_raw;
  Gpacket.panel_mv[n/10] = panel_mv_raw;
  Gpacket.apogee_w_m2[n/3] = apogee_raw;
  Gpacket.bmp085_press_pa = pressure_raw;
  Gpacket.humidity_centi_pct = humidity_raw;
  Gpacket.uptime_ms = uptime;
  Gpacket.dallas_roof_c = dallas_rooftemp_decic;
}
