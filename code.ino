void setup() {
}

void loop() {

}#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo;
char c;

SoftwareSerial BT(11, 10); //藍芽端接收腳對應Arduino傳送腳, 藍芽端傳送腳對應Arduino接收腳

// 前進(四輪前進)
void forward() {
  RU_P6_1_9__forward();
  RD_P6_5_13__forward();
  LU_P7_1_9__forward();
  LD_P7_5_13__forward();
}

// 後退(四輪後退)
void backward() {
  RU_P6_1_9__backward();
  RD_P6_5_13__backward();
  LU_P7_1_9__backward();
  LD_P7_5_13__backward();
}

// 停止(四輪停止)
void stop() {
  RU_P6_1_9__stop();
  RD_P6_5_13__stop();
  LU_P7_1_9__stop();
  LD_P7_5_13__stop();
}

// 左移(右前、左後往前，左前、右後往後)
void left() {
  RU_P6_1_9__forward();
  RD_P6_5_13__backward();
  LU_P7_1_9__backward();
  LD_P7_5_13__forward();
}

// 右移(右前、左後往後，左前、右後往前)
void right() {
  RU_P6_1_9__backward();
  RD_P6_5_13__forward();
  LU_P7_1_9__forward();
  LD_P7_5_13__backward();
}

// 左轉(右邊前進，左邊後退)
void turn_left() {
  RU_P6_1_9__forward();
  RD_P6_5_13__forward();
  LU_P7_1_9__backward();
  LD_P7_5_13__backward();
}

// 右轉(右邊後退，左邊前進)
void turn_right() {
  RU_P6_1_9__backward();
  RD_P6_5_13__backward();
  LU_P7_1_9__forward();
  LD_P7_5_13__forward();
}

// 機構上舉(一次增加15度)
void up() {
  if ((servo.read()) < 90) {
    servo.write(((servo.read()) + 15));
  }
}

// 機構下放(一次減少30度)
void down() {
  servo.write(((servo.read()) - 30));
}

// 右前輪接到P6的1、9腳位_前進
void RU_P6_1_9__forward() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

// 右前輪接到P6的1、9腳位_停止
void RU_P6_1_9__stop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

// 右前輪接到P6的1、9腳位_後退
void RU_P6_1_9__backward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}

// 右後輪接到P6的5、13腳位_前進
void RD_P6_5_13__forward() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

// 右後輪接到P6的5、13腳位_停止
void RD_P6_5_13__stop() {
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

// 右後輪接到P6的5、13腳位_後退
void RD_P6_5_13__backward() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

// 左前輪接到P7的1、9腳位_前進
void LU_P7_1_9__forward() {
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

// 左前輪接到P7的1、9腳位_停止
void LU_P7_1_9__stop() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

// 左前輪接到P7的1、9腳位_後退
void LU_P7_1_9__backward() {
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

// 左後輪接到P7的5、13腳位_前進
void LD_P7_5_13__forward() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

// 左後輪接到P7的5、13腳位_停止
void LD_P7_5_13__stop() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

// 左後輪接到P7的5、13腳位_後退
void LD_P7_5_13__backward() {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}


void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  servo.attach(13);

}

void loop() {
  if (BT.available()) {
    c = BT.read();
    if (c == 'w') {
      forward();
    } else if (c == 'x') {
      backward();
    } else if (c == 'a') {
      left();
    } else if (c == 'd') {
      right();
    } else if (c == 'z') {
      turn_left();
    } else if (c == 'c') {
      turn_right();
    } else if (c == 's') {
      stop();
    } else if (c == '0') {
      up();
    } else if (c == '1') {
      down();
    }
  }
}
