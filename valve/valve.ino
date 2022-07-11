#include "routes.h"

void setup() {
  Serial.begin(9600);

  pinMode(PUMP_PIN, OUTPUT); 

  start_server();

  first_pump("/open/first");
  second_pump("/open/second");
}

void loop() {
  listen_connection();
}
