int pot = 1; // Pin para lectura analogica del potenciometro (A1)
float inPot; // Variable para el valor de la lectura del pin A1
int outPWM = 6; // Pin para salida pwm al motor
float rpm; // Contador para las rpm

int pinA = 3; // Pin para interrupciones
volatile int cont = 0; // Variable para conteo de pulsos
unsigned long previousMillis = 0; // Variable para tomar tiempo
long interval = 100; // Intervalo de tiempo para muestreo

void setup()
{
    pinMode(pinA, INPUT); // Configuracion de pin 3 como entrada para interrupciones
    pinMode(outPWM, OUTPUT); // Configuracion de salida del pin 6 para PWM
    Serial.begin(9600); // Comunicacion serial
    attachInterrupt(1, interrupcion, RISING); // Interrupciones en flanco de subida
}

void loop()
{
    unsigned long currentMillis = millis(); // Tiempo actual transcurrido

    // Se cumple si la resta del tiempo actual menos la ultima muestra es mayor a 1000
    if((currentMillis - previousMillis) >= interval)
    {
        previousMillis = currentMillis; // Actualizacion de 'previousMillis'
        rpm = 10*cont*(60.0/374.0); // RPM del eje principal
        cont = 0; // Pulsos a 0
    }

    inPot = analogRead(pot)*(100.0/1023.0) // Lectura del potenciometro de 0 - 100
    analogWrite(outPWM, inPot*(255.0/100.0)); // PWM de 0 - 255

    Serial.print("Lectura POT: ");
    Serial.println(inPot);
    Serial.print("RPM: ");
    Serial.println(rpm);

}

void interrupcion()
{
    cont++; // Nuevo conteo de pulsos
}

