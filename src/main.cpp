#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <SPI.h>


// Create the BNO055 instance
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Initialize the BNO055
  if (!bno.begin()) {
    Serial.print("No BNO055 detected. Check wiring or I2C address!");
    while (1);
  }
  delay(1000);
}

void loop() {
  // Get the orientation data
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  // Print the orientation data
  Serial.print("Orientation: ");
  Serial.print("Yaw(X): ");
  Serial.print(euler.x());
  Serial.print(" Pitch(Y): ");
  Serial.print(euler.y());
  Serial.print(" Roll(Z): ");
  Serial.println(euler.z());
  // Delay between readings
  delay(100);
}
