
# include <SoftwareSerial.h>
# include <Servo.h>


const int bluetoothTx = 10;  // Pin TX del módulo HC-06 conectado al pin RX del Arduino
const int bluetoothRx = 11;  // Pin RX del módulo HC-06 conectado al pin TX del Arduino

// Definición de pines del sensor infrarrojo y servo motor
const int sensorPin = 2;     // Pin del sensor infrarrojo
const int servoPin = 9;      // Pin del servo motor

Servo myServo;               // Objeto de la librería Servo
int sensorValue;             // Valor leído por el sensor
int servoAngle = 0;          // Ángulo inicial del servo Inicializado en Falso 
bool objectDetected = false; // Indica si se detectó un objeto Se inicializa en falso

SoftwareSerial bluetoothSerial(bluetoothTx, bluetoothRx)


void setup() {
  pinMode(sensorPin, INPUT);        // Configura el pin del sensor como entrada.
  Serial.begin(9600);          // Inicia la comunicación serial por USB
  bluetoothSerial.begin(9600);        // Inicia la comunicación serial con el módulo Bluetooth
}

void loop() {
  if (mySerial.available()) {
    char command = bluetoothSerial.read();
    // Procesa el comando recibido desde el módulo Bluetooth
    Serial.println(command);   // Envía el comando a través de la comunicación serial por USB
  }
}