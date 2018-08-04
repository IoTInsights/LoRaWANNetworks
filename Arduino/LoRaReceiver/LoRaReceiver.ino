/**
MIT License

Copyright (c) 2018 Bernd Wiegmann https://www.iotinsights.de/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**/

/*
This is the example "Simple LoRa Receiver"
from the book "IoT Networks with LoRaWAN" https://leanpub.com/iot-networks-with-lorawan
*/

#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println(F("Starting LoRa Receiver"));

  if (!LoRa.begin(868100000)) { // Initialize the LoRa module
    Serial.println(F("Starting LoRa Receiver failed!"));
    while (1);
  }

  LoRa.setSignalBandwidth(125000);
  LoRa.setSpreadingFactor(8);
}

void loop() {
  int packetSize = LoRa.parsePacket();    // try to parse packet
  if (packetSize > 0) {                   // Received a packet
    Serial.print(F("Received packet '"));

    while (LoRa.available()) {            // read while data is available
      Serial.print((char)LoRa.read());    // print the data to the serial port
    }

    Serial.print(F("' with RSSI "));
    Serial.println(LoRa.packetRssi());    // Print the RSSI
  }
}

