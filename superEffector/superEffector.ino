
const int analogInPin = 5; // CdSを接続するアナログ入力ピン
const int ledPin = 3; // LEDを接続するピン
int sensorValue; // センサー値用
int outputValue; // 送信データ用

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}
 
void loop()
{
    sensorValue = analogRead(analogInPin); // 10bit入力 0〜1023
    if(sensorValue > 512) digitalWrite(ledPin, LOW); else digitalWrite(ledPin, HIGH); // 閾値でLEDのON/OFF
    outputValue = map(sensorValue, 0, 1023, 0, 255); // シリアル通信用に10bitから8bit（0〜255）変換
    Serial.write(outputValue); // センサー値をシリアル送信
}
