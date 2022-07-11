#include "routes.h"


void setup() {
  Serial.begin(9600);
  pinMode(WATERING_PIN, OUTPUT); 
  routes(
    "/start", 
    "/stop", 
    "/open", 
    "/close"
  );
  start_server();
}

void loop() {
  listen_connection();
  run_by_time(state);
}

