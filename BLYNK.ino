/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  WARNING!
    It's rather tricky to get it working, please read this article:
    https://github.com/blynkkk/blynk-library/wiki/ESP8266-with-AT-firmware

  You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - Arduino Mega 2560 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "f47d9fcd9e3d4401ba0d9c6e03affb56";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NETVIRTUA_41";
char pass[] = "58659698a";

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

BlynkTimer timer;

int sensorinfra1 = 6;
int sensorinfra2 = 7;
int sensorinfra3 = 8;
int sensorinfra4 = 9;



void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  int S1 = digitalRead(sensorinfra1);  
  int S2 = digitalRead(sensorinfra2);  
  int S3 = digitalRead(sensorinfra3); 
  int S4 = digitalRead(sensorinfra4);  
  Blynk.virtualWrite(V2, S1);
  Blynk.virtualWrite(V3, S2);
  Blynk.virtualWrite(V4, S3);
  Blynk.virtualWrite(V5, S4);

//  WiFiClient client;
//if (client.connect("api.thingspeak.com", 80)) {
//    client.print("POST /update HTTP/1.1\n");
//    client.print("Host: api.thingspeak.com\n");
//    client.print("Connection: close\n");
//    client.print("X-THINGSPEAKAPIKEY: " + apiKeyThingspeak1 + "\n");
//    client.print("Content-Type: application/x-www-form-urlencoded\n");
//    client.print("Content-Length: ");
//    client.print(postStr.length());
//    client.print("\n\n");
//    client.print(postStr);
//  Blynk.virtualWrite(V0, S1);
//  Blynk.virtualWrite(V0, S2);
//  Blynk.virtualWrite(V0, S3);
//  Blynk.virtualWrite(V0, S4);
//}
//  
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(sensorinfra1, INPUT);  
  pinMode(sensorinfra2, INPUT);  
  pinMode(sensorinfra3, INPUT);  
  pinMode(sensorinfra4, INPUT);  

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8442);
  
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

