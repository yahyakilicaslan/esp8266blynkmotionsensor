#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

char auth[] = "efd722b668f24b9c92c58b8478883f35";
char ssid[] = "okhan";
char pass[] = "atakan2009";
//char server[] = "xxx.xxx.xxx.xxx";

#define ledPin 02 
#define pirPin 00

int pirState;
int val;
int x;

SimpleTimer timer;

BLYNK_CONNECTED() {
      Blynk.syncVirtual(V0);
  }

BLYNK_WRITE(V0){
 x = param.asInt();
 }

void PIRval(){
val = digitalRead(pirPin);
    if (val == HIGH) {
      digitalWrite(ledPin, HIGH);  
      }
      else {
        digitalWrite(ledPin, LOW); 
      }
   }

  void pir(){
  if (x == 1){
    if (digitalRead(pirPin) == HIGH){
 Blynk.notify("EVDE HAREKET ALGILANDI!");
 }
    }
  }

void setup(){
  //Blynk.begin (auth, ssid, pass, server, 8080);//local server
   // You can change server:
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);

  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  timer.setInterval(1000L, PIRval);
 timer.setInterval(1000L, pir);
   }

void loop(){
   Blynk.run();
   timer.run();
}
