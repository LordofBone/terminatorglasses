#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  if (! matrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");

  matrix.setRotation(0);

  delay(500);
  
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  delay(500);
}

void loop() {

  delay(50);
  
  mpu6050.update();

  Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
  Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
  Serial.println("");
  
  if (mpu6050.getGyroZ() >= 10.0){
    matrix.clear();
    // move eye left
    centre(4);
    
    up1left1(4);
    down1left1(4);

    left1(128);
    left2(4);

    up1(1);
    down1(1);

    down1left2(1);
    up1left2(1);
    //delay(1000);
    return;

  }

  if (mpu6050.getGyroZ() <= -10.0){
    matrix.clear();
    // move eye right
    centre(4);
    
    up1right1(4);
    down1right1(4);

    right1(128);
    right2(4);

    up1(1);
    down1(1);

    down1right2(1);
    up1right2(1);
    //delay(1000);
    return;

  }

  if (mpu6050.getGyroY() <= -10.0){
    matrix.clear();
    // move eye up
    centre(4);
    
    up1(128);
    up2(4);
    left1(1);
    right1(1);

    up1left1(4);
    up1right1(4);
    up2right1(1);
    up2left1(1);
    //delay(1000);
    return;
    
  }

  if (mpu6050.getGyroY() >= 10.0){
    matrix.clear();
    // move eye down
    centre(4);

    down1(128);
    down2(4);
    left1(1);
    right1(1);

    down1left1(4);
    down1right1(4);
    down2right1(1);
    down2left1(1);
    //delay(1000);
    return;
    
  }

  else {
    matrix.clear();
    // centre eye
    centre(128);
    
    up1(4);
    down1(4);
    right1(4);
    left1(4);
  
    up1left1(1);
    up1right1(1);
    down1right1(1);
    down1left1(1);
    //delay(1000);
    return;
  }
  
}

// centre pixel
void centre(int bright){
  matrix.drawPixel(1, 8, bright);
}

// right 1
void right1(int bright){
  matrix.drawPixel(2, 8, bright);
}

// right 2
void right2(int bright){
  matrix.drawPixel(3, 8, bright);
}

// up 1 right 1
void up1right1(int bright){
  matrix.drawPixel(5, 8, bright);
}

// up 1
void up1(int bright){
  matrix.drawPixel(6, 8, bright);
}

// left 1
void left1(int bright){
  matrix.drawPixel(0, 8, bright);
}

// up 2 right 1
void up2right1(int bright){
  matrix.drawPixel(5, 7, bright);
}

// up 2 right 2
void up2right2(int bright){
  matrix.drawPixel(6, 7, bright);
}

// down 1 left 1
void down1left1(int bright){
  matrix.drawPixel(10, 7, bright);
}

// down 1
void down1(int bright){
  matrix.drawPixel(11, 7, bright);
}

// down 1 right 1
void down1right1(int bright){
  matrix.drawPixel(12, 7, bright);
}

// down 1 right 2
void down1right2(int bright){
  matrix.drawPixel(13, 7, bright);
}

// down 2 right 2
void down2right2(int bright){
  matrix.drawPixel(14, 7, bright);
}

// left 2
void left2(int bright){
  matrix.drawPixel(15, 7, bright);
}

// down 1 left 2
void down1left2(int bright){
  matrix.drawPixel(9, 7, bright);
}

// up 1 right 2
void up1right2(int bright){
  matrix.drawPixel(4, 8, bright);
}

// up 2
void up2(int bright){
  matrix.drawPixel(4, 7, bright);
}

//up 2 left 1
void up2left1(int bright){
  matrix.drawPixel(3, 7, bright);
}

// up 2 left 2
void up2left2(int bright){
  matrix.drawPixel(2, 7, bright);
}

// up 1 left 2
void up1left2(int bright){
  matrix.drawPixel(1, 7, bright);
}

// up 1 left 1
void up1left1(int bright){
  matrix.drawPixel(0, 7, bright);
}

// down 2
void down2(int bright){
  matrix.drawPixel(8, 0, bright);
}

// down 2 left 1
void down2left1(int bright){
  matrix.drawPixel(9, 0, bright);
}

// down 2 left 2
void down2left2(int bright){
  matrix.drawPixel(10, 0, bright);
}

// down 2 right 1
void down2right1(int bright){
  matrix.drawPixel(15, 0, bright);
}
