#include <SPI.h>
#include <WiFi.h>

WiFiClient client;
char clientServer[] = "hiddentreasurehack.azurewebsites.net";
IPAddress ip(192,168,2,3);

char ssid[] = "fbguest";     //  your network SSID (name) 
char pass[] = "m0vefast";    // your network password
int status = WL_IDLE_STATUS;

int timer = 0;
int last = LOW;
int buttonState = 0;         // variable for reading the pushbutton status
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin


void setup() {
  // Serial port enable
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
    pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
    
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
//    status = WiFi.begin(ssid);

    // wait 10 seconds for connection:
    delay(10000);
  }   
    printWifiStatus();
}

void loop() {
 
    if (digitalRead(7)==HIGH && last == HIGH)
  {
    timer++;
  }
  else
  {
    //reset timer
    timer = 0;
  }
  
  last = digitalRead(7);
  
  buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        digitalWrite(6, LOW);
        
      if(client.connect(clientServer, 80)){
          Serial.println("connected");
          Serial.println("GET /1/ HTTP/1.0");
          client.println("GET /1/ HTTP/1.0");
          client.println("Host: hiddentreasurehack.azurewebsites.net");
          client.println("User-Agent: Intel Edison");
          client.println("Content-Type: application/json");
//          client.print("Content-Length: ");
//          client.println(PostData.length());
//          client.println();
//          client.println(PostData);
          client.println();
          client.println("Connection: close");

          while(client.connected() && !client.available()) 
          {
            Serial.println("SWTF");
            delay(1); //waits for data
          }
          while (client.connected() && client.available()) { //connected or data available
            char c = client.read(); //gets byte from ethernet buffer
            Serial.print(c); //prints byte to serial monitor 
          }
          Serial.println();
          Serial.println("disconnecting.");
          Serial.println("==================");
          Serial.println();
          client.stop(); //stop client
        } else {

          Serial.println("not enough");
        }
    }
    else {
        // turn LED off:
        digitalWrite(ledPin, LOW);
    }
  
  if(timer > 3)
  {
        timer = 0;
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
          
      if(client.connect(clientServer, 80)){
          Serial.println("connected");
          Serial.println("GET /2/ HTTP/1.0");
          client.println("GET /2/ HTTP/1.0");
          client.println("Host: hiddentreasurehack.azurewebsites.net");
          client.println("User-Agent: Intel Edison");
          client.println("Content-Type: application/json");
//          client.print("Content-Length: ");
//          client.println(PostData.length());
//          client.println();
//          client.println(PostData);
          client.println();
          client.println("Connection: close");

          while(client.connected() && !client.available()) 
          {
            Serial.println("SWTF");
            delay(1); //waits for data
          }
          while (client.connected() && client.available()) { //connected or data available
            char c = client.read(); //gets byte from ethernet buffer
            Serial.print(c); //prints byte to serial monitor 
          }
          Serial.println();
          Serial.println("disconnecting.");
          Serial.println("==================");
          Serial.println();
          client.stop(); //stop client
        } else {

          Serial.println("not enough");
        }
  }
  delay(1000);
  Serial.println(timer);

}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  
    // check firmware version
  Serial.print("Firmware version: ");
  Serial.println(WiFi.firmwareVersion());
}


