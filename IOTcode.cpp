// ���������� ��� ������ ������������ Serial
#include <SoftwareSerial.h>

// ������ ������ ��� ������ � ����������� Serial
// � ������� ��� ���� TX � RX
SoftwareSerial mySerial(8, 9);

// serial-���� � �������� ��������� Wi-Fi ������
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
    // ��������� ���������������� ���� ��� ����������� �������� � ���������
    // � ������� �������� 9600 ���
    Serial.begin(9600);
    while (!Serial) {
        // ���, ���� �� ��������� ������� ����������������� �����
        // ��� ����, ����� ��������� ��� ������� � ���������
    }
    Serial.print("Serial init OK\r\n");
    // ��������� Serial-���������� � Wi-Fi ������� �� �������� 115200 ���
    WIFI_SERIAL.begin(115200);
    pinMode(ldrValue, INPUT);
    // ����� ��������
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
}

void loop()
{
    // ���� �������� ������ �� Wi-Fi ������ - �������� �� � ���� ����������
    if (WIFI_SERIAL.available()) {
        Serial.write(WIFI_SERIAL.read());
    }
    // ���� �������� ������ �� ���������� - �������� �� � Wi-Fi ������
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