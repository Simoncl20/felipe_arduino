
# include <SoftwareSerial.h>
# include <Servo.h>

const int bluetoothTx = 10;  // Pin TX del módulo HC-06 conectado al pin RX del Arduino
const int bluetoothRx = 11;  // Pin RX del módulo HC-06 conectado al pin TX del Arduino

// Definición de pines del sensor infrarrojo y servo motor
const int sensorPin = 7;     // Pin del sensor infrarrojo
const int servoPin = 2;      // Pin del x motor


// Pines del motor
#define forward 3
#define forward2 6
#define backward 4
#define backward2 5
#define buzzer 9

Servo myServo;               // Objeto de la librería Servo
int sensorValue = "HIGH";             // Valor leído por el sensor
int servoAngle = 0;          // Ángulo inicial del servo Inicializado en Falso 
bool objectDetected = false; // Indica si se detectó un objeto Se inicializa en falso

SoftwareSerial bluetoothSerial(bluetoothTx, bluetoothRx);



void setup() {
  pinMode(sensorPin, INPUT);        // Configurar el pin del sensor como entrada
  myServo.attach(servoPin);         // Conectar el servo al pin correspondiente
  myServo.write(servoAngle);        // Establecer el ángulo inicial del servo
  Serial.begin(9600);               // Iniciar comunicación serial para depuración
  bluetoothSerial.begin(9600);      // Iniciar comunicación serial con el módulo Bluetooth HC-06
  pinMode(forward, OUTPUT);
  pinMode(backward,OUTPUT);
  pinMode(forward2, OUTPUT);
  pinMode(backward2,OUTPUT);

}

void loop() {         // Establecer el ángulo del servo
  sensorValue = digitalRead(sensorPin);
    while(sensorValue == 0){
        servoAngle = 0;
        myServo.write(servoAngle);
        analogWrite(forward,0);
        analogWrite(forward2,0);
        bluetoothSerial.write("Tomando_foto");
        delay(1000);
        char data = bluetoothSerial.read();
        delay(500);
        Serial.println(data);
        
        switch (data) {
            case 'A':
              Serial.println("Llego una señal de Integrados");
              servoAngle = 100;
              myServo.write(servoAngle);
              sensorValue = 1;
              delay(2000); 
              break;
            case 'B':
              Serial.println("Llego una señal de Relee");
              servoAngle = 240;
              myServo.write(servoAngle);
              sensorValue = 1;
              delay(2000);
              break;
            case 'C':
              Serial.println("Llego una señal de Potenciometro");
              servoAngle = 350;
              myServo.write(servoAngle);
              sensorValue = 1;
              break;
            default:
              Serial.println("No se reconoce la señal");
              break;
        }
    
    }
    analogWrite(forward,255);
    analogWrite(forward2,255);
    sensorValue = digitalRead(sensorPin);
    if (sensorValue == 0){
      delay(2000);}

    Serial.println("El motor debe estar avanzando");
    
  }
