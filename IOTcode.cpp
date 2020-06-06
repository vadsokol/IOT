// библиотека для работы программного Serial
#include <SoftwareSerial.h>

// создаём объект для работы с программным Serial
// и передаём ему пины TX и RX
SoftwareSerial mySerial(8, 9);

// serial-порт к которому подключён Wi-Fi модуль
#define WIFI_SERIAL    mySerial

const int ldrPin = A0;
const int ledPin1 = 4;
const int ledPin2 = 3;
const int ledPin3 = 2;

int ldrValue = 0;
int ldrlevel1 = 500;
int ldrlevel2 = 600;
int ldrlevel3 = 700;

void setup()
{
    // открываем последовательный порт для мониторинга действий в программе
    // и передаём скорость 9600 бод
    Serial.begin(9600);
    while (!Serial) {
        // ждём, пока не откроется монитор последовательного порта
        // для того, чтобы отследить все события в программе
    }
    Serial.print("Serial init OK\r\n");
    // открываем Serial-соединение с Wi-Fi модулем на скорости 115200 бод
    WIFI_SERIAL.begin(115200);
    pinMode(ldrValue, INPUT);
    // порты лампочек
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
}

void loop()
{
    // если приходят данные из Wi-Fi модуля - отправим их в порт компьютера
    if (WIFI_SERIAL.available()) {
        Serial.write(WIFI_SERIAL.read());
    }
    // если приходят данные из компьютера - отправим их в Wi-Fi модуль
    if (Serial.available()) {
        WIFI_SERIAL.write(Serial.read());
    }
    ldrValue = analogRead(ldrPin);
    if (ldrValue < ldrlevel1) {
        digitalWrite(ledPin3, HIGH);
        Serial.print("Light level - dark: ");
        Serial.println(ldrValue);
    }
    else if (ldrValue < ldrlevel2) {
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin2, HIGH);
        Serial.print("Light level - dim: ");
    }
    else if (ldrValue < ldrlevel3) {
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin1, HIGH);
        Serial.print("Light level - bright: ");
        Serial.print(ldrValue);
    }
    else {
        digitalWrite(ledPin1, LOW);
        Serial.println("Okay");
    }

    delay(250);
}