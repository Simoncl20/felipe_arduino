
# include <SoftwareSerial.h>
# include <Servo.h>


const int bluetoothTx = 10;  // Pin TX del módulo HC-06 conectado al pin RX del Arduino
const int bluetoothRx = 11;  // Pin RX del módulo HC-06 conectado al pin TX del Arduino

// Definición de pines del sensor infrarrojo y servo motor
const int sensorPin = 2;     // Pin del sensor infrarrojo
const int servoPin = 9;      // Pin del servo motor

Servo myServo;               // Objeto de la librería Servo
int sensorValue = "HIGH";             // Valor leído por el sensor
int servoAngle = 90;          // Ángulo inicial del servo Inicializado en Falso 
bool objectDetected = false; // Indica si se detectó un objeto Se inicializa en falso

SoftwareSerial bluetoothSerial(bluetoothTx, bluetoothRx);


void setup() {
  pinMode(sensorPin, INPUT);        // Configurar el pin del sensor como entrada
  myServo.attach(servoPin);         // Conectar el servo al pin correspondiente
  myServo.write(servoAngle);        // Establecer el ángulo inicial del servo
  Serial.begin(9600);               // Iniciar comunicación serial para depuración
  bluetoothSerial.begin(9600);      // Iniciar comunicación serial con el módulo Bluetooth HC-06
}

void loop() {
  sensorValue = digitalRead(sensorPin); // Leer el valor del sensor
  Serial.println("Hello World");
  Serial.println(sensorValue); // Imprimir información para depuración
}