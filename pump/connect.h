#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <time.h>

#include "version.h"
#include "variables.h"


extern ESP8266WebServer server(80);


extern void start_server() {
  int patiens = 0;
  Serial.println();


  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);


  Serial.printf("Connecting to wifi");
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");

  while (WiFi.status() != WL_CONNECTED && patiens < 50)
  {
    delay(500);
    patiens++;
    Serial.print(".");
  }

  if (patiens == 50) { 
    Serial.println(" offline ready!");
  }
  else {
    Serial.println(" connected");
    Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
  }

  if (MDNS.begin(DNS_NAME)) { Serial.println("MDNS responder started"); }

  server.begin();
}

extern void listen_connection() {
  server.handleClient();
  MDNS.update();
}







