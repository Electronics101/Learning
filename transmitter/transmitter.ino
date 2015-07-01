#include <VirtualWire.h>


char *controller;

void setup() {
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(1);
vw_setup(8000);// speed of data transfer Kbps
}

void loop() {
 controller="1"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,HIGH);
delay(10);
controller="0"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,LOW);
delay(10);

}
