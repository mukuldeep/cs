#include <Wire.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;
static float accumulated_yaw=0.0;
static float yaw_correction=0.093; /* Sync this value with your device */
static float yaw_to_degree_const=7; /* Sync this value with your device */

void setup() {
  Serial.begin(9600);
  /* wait for serial */
  while (!Serial)
    delay(10);

  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }

  /* Accelerometer range */
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  
  /* Gyro range in degree */
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  
  /* Filter bandwidth */
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
    sensors_event_t accel, gyro, temp;
    mpu.getEvent(&accel, &gyro , &temp);
	
    accumulated_yaw+=(gyro.gyro.x)+yaw_correction;
    float angle=-accumulated_yaw*yaw_to_degree_const;
	
    Serial.print("yaw:");
    Serial.print(accumulated_yaw);
    Serial.print(" angle:");
    Serial.println(angle);

    delay(100); /* Minimum interval between reading */
}
