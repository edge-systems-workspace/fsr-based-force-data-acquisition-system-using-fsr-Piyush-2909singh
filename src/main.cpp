#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Force Measurement System using FSR
 * @author Piyush-2909singh
 * @date 2026-02-21
 *
 * @details
 * Reads analog force data from FSR sensor and
 * displays structured output via Serial Monitor.
 */

// FSR connected to Analog Pin A0
#define FSR_PIN A0

// Variable to store sensor reading
int sensorValue = 0;

void setup() {
    // Initialize Serial communication at 9600 baud
    Serial.begin(9600);

    // System initialization message
    Serial.println("FSR System Initialized...");
    Serial.println("-------------------------");
}

void loop() {
    // Read analog value from FSR (Range: 0 - 1023)
    sensorValue = analogRead(FSR_PIN);

    //print raw adc
    Serial.print("Raw ADC Value: ");
    Serial.print(sensorValue);

    // Threshold logic to detect pressure levels
    if (sensorValue < 10) {
        Serial.println(" - Status: No Pressure");
    } else if (sensorValue < 200) {
        Serial.println(" - Status: Light Touch");
    } else if (sensorValue < 500) {
        Serial.println(" - Status: Medium Squeeze");
    } else {
        Serial.println(" - Status: Big Squeeze!");
    }

    // Delay for stability
    delay(500);
}