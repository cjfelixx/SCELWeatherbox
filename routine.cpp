#include "routine.h"

void routine(int *count)
{
  long wait_ms = 1000;
  unsigned long transmit_timer = millis();

  make_packet(*count);

  (*count)++;

  if((*count) >= 60){
    send_packet();
    clear_packet();
    (*count) = 0;
    
  }
 while ((millis() - transmit_timer) <= wait_ms); 
}
