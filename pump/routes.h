#include "connect.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


WiFiClient wifiClient;

extern bool state = false;


extern void start_watering() {
  server.send(200, "text/plain", "started");
  state = true;
  digitalWrite(WATERING_PIN, HIGH);
}

extern void stop_watering() {
  server.send(200, "text/plain", "stopped");
  state = false;
  digitalWrite(WATERING_PIN, LOW);
}


extern void open_valve_request() {
  server.send(200, "text/plain", "stopped");
  digitalWrite(WATERING_PIN, LOW);
}

extern void open_valve_first_request() {
  HTTPClient http;
  server.send(200, "text/plain", "first valve is now open / second valve is closed");
  http.begin(wifiClient, "http://valve.local/open/first");
  http.GET();
  http.end();
}

extern void open_valve_second_request() {
  HTTPClient http;
  server.send(200, "text/plain", "second valve is now open / first valve is closed");
  http.begin(wifiClient, "http://valve.local/open/second");
  int shttp.GET();
  http.end();
}

extern void routes(char* first, char* second, char* third, char* fourth) {
  server.on(first, start_watering);
  server.on(second, stop_watering);
  server.on(third, open_valve_first_request);
  server.on(fourth, open_valve_second_request);
}


void switch_valve(struct tm * structure) {

  switch (structure->tm_min) {
    case 00:

      break;

    case 55:
      open_valve_first_request();
      break;
  }
}


extern void run_by_time(bool state) {
  if (WiFi.status() == WL_CONNECTED && state == false) {
    time_t seconds;
    struct tm *timeStruct;

    seconds = time(NULL);

    timeStruct = localtime(&seconds);


  /**
  *  when time is 8 or 20, then we set pin to HIGH
  */
  switch (timeStruct->tm_hour) {
    case 8:
      switch_valve(timeStruct);
      digitalWrite(WATERING_PIN, HIGH);
      break;

    case 22:
      switch_valve(timeStruct);
      digitalWrite(WATERING_PIN, HIGH);
      break;

    default:
      digitalWrite(WATERING_PIN, LOW);
      break; 
  }

   printf("Current time : %d:%d:%d\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec);
   delay(10);
  }
}
