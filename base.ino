#include <SoftwareSerial.h>
#include <Servo.h>

// Definición de pines del módulo Bluetooth HC-06
const int bluetoothTx = 10;  // Pin TX del módulo HC-06 conectado al pin RX del Arduino
const int bluetoothRx = 11;  // Pin RX del módulo HC-06 conectado al pin TX del Arduino

// Definición de pines del sensor infrarrojo y servo motor
const int sensorPin = 2;     // Pin del sensor infrarrojo
const int servoPin = 9;      // Pin del servo motor

// Variables
int sensorValue;             // Valor leído por el sensor
bool objectDetected = false; // Indica si z se detectó un objeto
Servo myServo;               // Objeto de la librería Servo
int servoAngle = 0;          // Ángulo inicial del servo

SoftwareSerial bluetoothSerial(bluetoothTx, bluetoothRx);  // Objeto de la librería SoftwareSerial para la comunicación Bluetooth

void setup() {
  pinMode(sensorPin, INPUT);        // Configurar el pin del sensor como entrada
  myServo.attach(servoPin);         // Conectar el servo al pin correspondiente
  myServo.write(servoAngle);        // Establecer el ángulo inicial del servo
  Serial.begin(9600);               // Iniciar comunicación serial para depuración
  bluetoothSerial.begin(9600);      // Iniciar comunicación serial con el módulo Bluetooth HC-06
}

void loop() {
  // Leer el valor del sensor
  sensorValue = digitalRead(sensorPin);

  // Comprobar si se detectó un objeto
  if (sensorValue == HIGH && !objectDetected) {
    objectDetected = true;
    // apagar la banda
    //delay (15000) 15 s para que tome la foto y eso
    BluetoothSerial.write("tomar foto")}
  else if (sensorValue == LOW) {
    objectDetected = false;
  }

  // Imprimir información para depuración
 // Serial.print("Sensosr: ");
 // Serial.print(sensorValue);
  //Serial.print(" - Object detected: ");
  //Serial.println(objectDetected);

  // Leer y procesar el texto recibido por Bluetooth
  if (bluetoothSerial.available()) {
    String receivedText = bluetoothSerial.readStringUntil(',');
    receivedText.trim();(receivedText); // Cambiar el ángulo del servo basado en el texto recibido por Bluetooth
  }
    processBluetoothCommand

  if(Serial.available()) {
    bluetoothSerial.write(Serial.read()); // si llega un dato por el monitor serie se envía al puerto BT
  }
  delay(100);  // Pequeña pausa entre iteraciones
}

// Función para cambiar el ángulo del servo basado en el texto recibido por Bluetooth
void changeServoAngle() {
  myServo.write(servoAngle);
  delay(500);// Pausa para permitir que el servo se mueva
  //prender la banda 
}

// Función para procesar los comandos recibidos por Bluetooth
void processBluetoothCommand(String command) {
  if (command == "PCB") {
    servoAngle = 0;
    myServo.write(servoAngle);}
  else if (command == "angle2"){
    servoAngle = 120;
    myServo.write(servoAngle);}
  else {
    servoAngle = 270;
    myServo.write(servoAngle);}
  }