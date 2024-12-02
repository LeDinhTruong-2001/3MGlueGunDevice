#define Step 5 
#define dir 4

#define limit_up 6
#define limit_down 7

#define t20 21
#define g20 20

#define up 8
#define down 9
char formattedStr[8]; // Mảng để lưu trữ dữ liệu đã định dạng
#include <SoftwareSerial.h>
#include <AccelStepper.h>
AccelStepper mystepper(1, Step, dir, 25);
int tocdo, buoc; 
int LU, LD, u, d, tang, giam ;
//SoftwareSerial mySerial(18,19); // Sử dụng SoftwareSerial cho việc gửi và nhận dữ liệu UART

// ct con chạy motor
void run()
{
  digitalWrite(Step, HIGH);
  delayMicroseconds(tocdo);
  digitalWrite(Step, LOW);
  delayMicroseconds(tocdo);
  //delay(7);
}

//ct con motor trở về vị trí setpoint

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //mySerial.begin(9600);
  pinMode(limit_up, INPUT_PULLUP); // chế độ input, điện trở kéo lên
  pinMode(limit_down, INPUT_PULLUP);// chế độ input, điện trở kéo lên
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(Step, OUTPUT); // chế độ output
  pinMode(dir, OUTPUT); // chế độ output
  pinMode(t20, INPUT_PULLUP);
  pinMode(g20, INPUT_PULLUP);
  // NGAT CHO BUTTON
  
  
  //attachInterrupt(digitalPinToInterrupt(18), UARTDataReceived, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  LU = digitalRead(limit_up);
  LD = digitalRead(limit_down);
  u = digitalRead(up);
  d = digitalRead(down);
  tang = digitalRead(t20);
  giam = digitalRead(g20);
  buoc = 100;

  // nút vật lí up
  if(u==1 && d==1 && LU==0){
    digitalWrite(dir, HIGH);
    for(int i =0; i<buoc*2; i++)
    {
    tocdo=700;
    run();
    }
  }

  //nút vật lí down
  if(d==0 && u==0 && LD ==0){
    digitalWrite(dir, LOW);
    for(int i =0; i<buoc; i++)
    {
      tocdo = 1000;
      run();
    }
  }
}

