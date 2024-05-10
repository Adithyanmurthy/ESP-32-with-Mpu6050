#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize MPU6050
  mpu.initialize();
  
  // Verify connection
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
    while (1); // Stop here if connection failed
  }
}

void loop() {
  // Read raw accelerometer and gyroscope data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  // Convert raw data to meaningful values
  float accel_x = ax / 16384.0; // Accelerometer sensitivity scale factor
  float accel_y = ay / 16384.0;
  float accel_z = az / 16384.0;
  
  float gyro_x = gx / 131.0; // Gyroscope sensitivity scale factor
  float gyro_y = gy / 131.0;
  float gyro_z = gz / 131.0;
  
  // Print sensor data
  Serial.print("Accelerometer (g): ");
  Serial.print(accel_x);
  Serial.print(", ");
  Serial.print(accel_y);
  Serial.print(", ");
  Serial.println(accel_z);
  
  Serial.print("Gyroscope (°/s): ");
  Serial.print(gyro_x);
  Serial.print(", ");
  Serial.print(gyro_y);
  Serial.print(", ");
  Serial.println(gyro_z);
  
  Serial.println();
  
  delay(1000); // Delay between readings
}
