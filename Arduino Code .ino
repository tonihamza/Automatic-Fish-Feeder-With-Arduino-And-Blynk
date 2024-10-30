#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Blynk and WiFi credentials
char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_SSID";
char pass[] = "Your_Password";

// Servo Setup
Servo trapdoorServo;   // Servo 1 for trap door
Servo cylinderServo;   // Servo 2 for rotating cylinder

int trapdoorServoPin = D1;
int cylinderServoPin = D2;

// Feeding variables
int portionCount = 1;   // Default number of portions
bool isFeeding = false; // Tracks if feeding is in progress

// Blynk virtual pin for manual single portion feeding (V1)
BLYNK_WRITE(V1) {
    if (param.asInt() == 1 && !isFeeding) {
        feedFish(1);   // Single portion feed
    }
}

// Blynk virtual pin for selecting number of portions (V2)
BLYNK_WRITE(V2) {
    portionCount = param.asInt();   // Update portion count
}

// Blynk virtual pin for automated feeding (V3)
BLYNK_WRITE(V3) {
    if (param.asInt() == 1 && !isFeeding) {
        feedFish(portionCount);     // Start feeding with selected portion count
    }
}

// Feeding routine
void feedFish(int portions) {
    isFeeding = true;
    // Step 1: Open trap door
    trapdoorServo.write(90);       // Open trap door
    delay(500);    
    for (int i = 0; i < portions; i++) {
        // Step 2: Rotate cylinder to dispense food
        cylinderServo.write(180);      // Rotate to fill food
        delay(500);                    // Hold for food to load
        cylinderServo.write(0);        // Return to initial position
        delay(500);                    // Allow food to drop
    }
    // Step 3: Close trap door
    trapdoorServo.write(0);        // Close trap door
    delay(500);                    // Small delay between portions if multiple
    isFeeding = false;
}

void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);

    // Setup WiFi and Blynk connection
    WiFi.begin(ssid, pass);
    Blynk.begin(auth, ssid, pass);

    // Initialize Servos
    trapdoorServo.attach(trapdoorServoPin);
    cylinderServo.attach(cylinderServoPin);

    // Set initial servo positions
    trapdoorServo.write(0);            // Close trap door initially
    cylinderServo.write(0);            // Set cylinder to start position
}

void loop() {
    Blynk.run();   // Runs Blynk connectivity
}
