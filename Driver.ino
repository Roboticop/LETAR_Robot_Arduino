#include <SabertoothSimplified.h>

SabertoothSimplified ST;

int serialBaudRate = 10000;
string data = "";

void setup() {
    SabertoothXPinSerial.begin(9600);
    Serial.begin(serialBaudRate);
}

void loop() {
    if (Serial.available() > 0) {
        data = Serial.readStringUntil('\n');
    }
    if (data == "F") {
        ST.motor(1, 127);
        ST.motor(2, -127);
    } else if (data == "B") {
        ST.motor(1, -127);
        ST.motor(2, 127);
    } else if (data == "L") {
        ST.motor(1, -127);
        ST.motor(2, -127);
    } else if (data == "R") {
        ST.motor(1, 127);
        ST.motor(2, 127);
    } else {
        ST.motor(1, 0);
        ST.motor(2, 0);
    }
}