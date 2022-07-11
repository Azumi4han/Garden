#include "connect.h"

extern void first_pump(char* path) {
  server.on(path, [](){
    server.send(200, "text/plain", "first pump is now open / second pump is closed");
    digitalWrite(PUMP_PIN, HIGH);
  });
}

extern void second_pump(char* path) {
  server.on(path, [](){
    server.send(200, "text/plain", "second pump is now open / first pump is closed");
    digitalWrite(PUMP_PIN, LOW);
  });
}