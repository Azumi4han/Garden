#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>


#include "version.h"
#include "variables.h"

const char* ssid = WIFI_NAME;
const char* password = WIFI_PASSWORD;

extern ESP8266WebServer server(80);


extern void start_server() {
  Serial.println();

  WiFi.begin(ssid, password);

  Serial.printf("Connecting to %s ", ssid);
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");

  while (WiFi.status() != WL_CONNECTED && !time(nullptr))
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" connected");
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());

  if (MDNS.begin(DNS_NAME)) { Serial.println("MDNS responder started"); }
  
  server.begin();
}

extern void listen_connection() {;
  server.handleClient();
  MDNS.update();
}


extern void check_time() {
  if (WiFi.status())
}






