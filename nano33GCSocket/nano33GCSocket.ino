// (COM7) nano 33 IoT


/* 
 *  Stick notes:
 *  range: -22px to 22px
 *  X-axis: MargLeft== transformRotateY
 *  Y-axis: MargTop== transformRotateX
*/
#define A         3
#define B         4
#define X         5
#define Z         6
#define CUp       7
#define CRight    8
#define CDown     9
#define R         10
#define CLeft     A7
#define Up        A6
#define Down      A5 //
#define Right     A4 //
#define Left      A3
#define start     A2 //
#define L         A1 //

#define HardLeft  A0
#define SoftLeft  11
#define SoftRight 12
#define HardRight 13
String changes = "";

#include <WiFiNINA.h>
#include <WebSocketServer.h>
#include "arduino_secrets.h"

int pin2 = 2;

bool connection = false;
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
const int socketPort = 8080;
bool sockON = false;
bool finished = true;
WiFiServer socketServer(socketPort);
WebSocketServer webSocketServer;
WiFiClient socketClient;

bool fourties() {
  delay(400);
  return true;
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(X, INPUT);
  pinMode(L, INPUT);
  pinMode(R, INPUT);
  pinMode(Z, INPUT);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Up, INPUT);
  pinMode(Down, INPUT);
  pinMode(CLeft, INPUT);
  pinMode(CRight, INPUT);
  pinMode(CUp, INPUT);
  pinMode(CDown, INPUT);
  pinMode(start, INPUT);
  pinMode(HardLeft, INPUT);
  pinMode(HardRight, INPUT);
  pinMode(SoftLeft, INPUT);
  pinMode(SoftRight, INPUT);
  WiFiConnect();
}

void loop() {
  if(digitalRead(A) == HIGH){
    changes+= "A,";
  }
  if(digitalRead(B) == HIGH){
    changes+= "B,";
  }
  if(digitalRead(X) == HIGH){
    changes+= "X,";
  }
  if(digitalRead(Z) == HIGH){
    changes+= "Z,";
  }
  if(digitalRead(CUp) == HIGH){
    changes+= "CUp,";
  }
  if(digitalRead(CRight) == HIGH){
    changes+= "CRight,";
  }
  if(digitalRead(CDown) == HIGH){
    changes+= "CDown,";
  }
  if(digitalRead(CLeft) == HIGH){
    changes+= "CLeft,";
  }
  if(digitalRead(Up) == HIGH){
    changes+= "Up,";
  }
  if(digitalRead(Down) == HIGH){
    changes+= "Down,";
  }
  if(digitalRead(Right) == HIGH){
    changes+= "Right,";
  }
  if(digitalRead(Left) == HIGH){
    changes+= "Left,";
  }
  if(digitalRead(start) == HIGH){
    changes+= "start,";
  }
  if(digitalRead(L) == HIGH){
    changes+= "L,";
  }
  if(digitalRead(R) == HIGH){
    changes+= "R,";
  }
  if(digitalRead(HardLeft) == HIGH){
    changes+= "HardLeft,";
  }
  if(digitalRead(SoftLeft) == HIGH){
    changes+= "SoftLeft,";
  }
  if(digitalRead(SoftRight) == HIGH){
    changes+= "SoftRight,";
  }
  if(digitalRead(HardRight) == HIGH){
    changes+= "HardRight,";
  }
  
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW);
    WiFi.end();
    WiFiConnect();
  }

  if (!socketClient.connected()) {
    socketClient = socketServer.available();
    if (socketClient.connected() && webSocketServer.handshake(socketClient)) {
      sockON = true;
      digitalWrite(pin2, LOW);
      delay(1000);
    } else {
      sockON = false;
      delay(600);
      socketClient.stop();
    }
  }

  if (sockON) {
    if (changes.length() > 0) {
      changes.remove(changes.length() -1);
      digitalWrite(pin2, HIGH);
      webSocketServer.sendData(changes);
      digitalWrite(pin2, LOW);
      changes = "";
      finished = true;
    } else if(changes.length() == 0 && finished == true) {
      finished = false;
      webSocketServer.sendData("");
    }
  }
}

void WiFiConnect() {  
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(400);
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(400);
  }
  WiFi.begin(ssid, pass);
  int retry = 0;
  while (WiFi.status() != WL_CONNECTED) {
    if (retry % 5 == 0 && retry != 0) {
        WiFi.begin(ssid, pass);
    }
    digitalWrite(2, HIGH);
    delay(250);
    digitalWrite(2, LOW);
    delay(750);
  }
  socketServer.begin();
  for (int i = 0; i < 5; i++) {
    digitalWrite(2, HIGH);
    delay((1000 - (200 * i)) /2);
    digitalWrite(2, LOW);
    delay((1000 - (200 * i)) /2);
  }
}
