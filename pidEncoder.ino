int pinA = 3;
volatile int contador = 0;

void setup()
{
    pinMode(pinA, INPUT); // Configuracion de pin 3 como entrada
    Serial.begin(9600); // Comunicacion serial
    attachInterrupt(1, interrupcion, RISING); // Interrupciones en flanco de subida
}

void loop()
{
    Serial.print("Pulsos: ");
    Serial.println(contador);
}

void interrupcion()
{
    contador++;
}

