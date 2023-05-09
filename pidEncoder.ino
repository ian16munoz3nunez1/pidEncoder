int pinA = 3; // Pin para interrupciones
volatile int contador = 0; // Variable para conteo de pulsos
unsigned long previousMillis = 0; // Variable para tomar tiempo
long interval = 1000; // Intervalo de tiempo para muestreo

void setup()
{
    pinMode(pinA, INPUT); // Configuracion de pin 3 como entrada para interrupciones
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
        Serial.print("Pulsos/seg: ");
        Serial.println(contador);
        contador = 0; // Pulsos a 0
    }

}

void interrupcion()
{
    contador++; // Nuevo conteo de pulsos
}

