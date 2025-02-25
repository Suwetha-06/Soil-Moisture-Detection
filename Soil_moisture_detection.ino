#define SOIL_SENSOR A0  // Soil Moisture Sensor connected to A0
#define RELAY_PIN 7     // Relay module connected to digital pin 7
#define THRESHOLD 400   // Soil moisture threshold value (Adjust as needed)

void setup() {
    Serial.begin(9600);  // Start serial communication
    pinMode(RELAY_PIN, OUTPUT);  // Set relay pin as OUTPUT
    digitalWrite(RELAY_PIN, LOW); // Ensure relay is OFF initially
}

void loop() {
    int moistureValue = analogRead(SOIL_SENSOR);  // Read soil moisture value
    Serial.print("Soil Moisture Level: ");
    Serial.println(moistureValue);

    if (moistureValue < THRESHOLD) {  
        digitalWrite(RELAY_PIN, HIGH); // Turn ON the motor (Dry soil)
        Serial.println("Soil is dry! Pump is ON.");
    } else {
        digitalWrite(RELAY_PIN, LOW); // Turn OFF the motor (Wet soil)
        Serial.println("Soil is wet! Pump is OFF.");
    }

    delay(2000); // Wait 2 seconds before next reading
}
