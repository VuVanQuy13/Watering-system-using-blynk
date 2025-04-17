#define BLYNK_TEMPLATE_ID "TMPL6MngP7VxA"
#define BLYNK_TEMPLATE_NAME "Do an 2"
#define BLYNK_AUTH_TOKEN "VYApby_oYlScQ9H1ajv3o567sS_8yxqR"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>

// Khai báo đối tượng LCD I2C với địa chỉ 0x27 và kích thước 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Khai báo chân kết nối
const int sensorPin = 34;  // Chân nhận tín hiệu từ LM358
const int relayPin = 23;   // Chân điều khiển relay

char auth[] = "VYApby_oYlScQ9H1ajv3o567sS_8yxqR";
char ssid[] = "BellBell";
char pass[] = "33333333";

void setup() {
  // Khởi tạo giao tiếp LCD và bật đèn nền
  lcd.init(); 
  lcd.backlight();
  // Khởi tạo chân GPIO
  pinMode(sensorPin, INPUT); // Đọc tín hiệu từ LM358
  pinMode(relayPin, OUTPUT); // Điều khiển relay
  digitalWrite(relayPin, LOW); // Tắt relay ban đầu

  // khởi tạo Blynk
  Blynk.begin(auth, ssid, pass);
  Serial.begin(115200);
}
void loop() {
Blynk.run();
  // Đọc tín hiệu từ LM358
  int sensorValue = digitalRead(sensorPin);
 // Đọc trạng thái của relay
  int relayState = digitalRead(relayPin);
 // Hiển thị trên LCD
lcd.clear();

  // Gửi dữ liệu lên Blynk
  Blynk.virtualWrite(V0, sensorValue); // Độ ẩm
  Blynk.virtualWrite(V1, relayState); // Relay
  
 if (sensorValue == HIGH) {
    // Khi độ ẩm cao, tắt relay và hiển thị trạng thái
    digitalWrite(relayPin, HIGH);  // Bật relay
    lcd.setCursor(0, 0);
    lcd.print("Humidity: High");
    lcd.setCursor(0, 1);
    lcd.print("Relay : OFF");
    Serial.println("Humidity: High,Relay: OFF");
  } else {
    // Khi độ ẩm thấp, bật relay và hiển thị trạng thái
    digitalWrite(relayPin, LOW);  // Tắt relay
    lcd.setCursor(0, 0);
    lcd.print("Humidity: Low");
    lcd.setCursor(0, 1);
    lcd.print("Relay: ON");
    Serial.println("Humidity: Low,Relay: ON");
  }

  delay(1000); // Đợi 1 giây trước khi lặp lại
}
