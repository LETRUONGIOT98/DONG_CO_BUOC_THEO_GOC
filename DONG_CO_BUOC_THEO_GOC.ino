#include <Stepper.h>

#define STEPS 200 // Số bước cho mỗi vòng (360 độ)
#define BUTTON_PIN 2 // Chân nút được kết nối

Stepper stepper(STEPS, 8, 9, 10, 11);

int previousButtonState = HIGH; // Trạng thái trước đó của nút
int currentPosition = 0; // Vị trí hiện tại của động cơ

void setup() {
  stepper.setSpeed(30);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int currentButtonState = digitalRead(BUTTON_PIN);

  // Kiểm tra xem nút có được nhấn hay không
  if (currentButtonState == LOW && previousButtonState == HIGH) {
    // Nếu nút được nhấn, thực hiện xoay 180 độ hoặc quay về 0 độ
    if (currentPosition == 0) {
      stepper.step(180 * (STEPS / 360)); // Quay 180 độ
      currentPosition = 180;
    } else {
      stepper.step(-180 * (STEPS / 360)); // Quay về 0 độ
      currentPosition = 0;
    }
  }

  previousButtonState = currentButtonState;
}
