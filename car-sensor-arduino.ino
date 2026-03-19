// --- Adicionando Bibliotecas ---------------------------------------- //
#include <Ultrasonic.h> // Biblioteca para uso do Sensor Ultrassônico
#include <Wire.h> // Complemento da biblioteca da Tela LCD
#include <LiquidCrystal_I2C.h> // Biblioteca para uso da Tela LCD
// -------------------------------------------------------------------- //

//

// --- Declarando Variáveis -------------------------------------------------- //
int ledRed = 13; //
int ledYel = 12; // Leds
int ledGre = 11; //

int buzzer = 8; // Buzzer

LiquidCrystal_I2C lcd(0x27, 16, 2); // Tela LCD
HC_SR04 distancia(7, 6); // Sensor Ultrassõnico
// -------------------------------------------------------------------------- //

//

// --- Bloco de Construção---------------------------------------------------- //
void setup() {
  pinMode(ledRed, OUTPUT); //
  pinMode(ledYel, OUTPUT); // Declarando os LEDs
  pinMode(ledGre, OUTPUT); // como saídas
  pinMode(buzzer, OUTPUT); //

  lcd.init();      // Iniciando Tela LCD
  lcd.backlight(); // Ligando Tela de Fundo
  lcd.clear();     // Limpando a tela (para garantir que não tenha nada escrito)

  noTone(buzzer); // Buzzer Desliga (garantir que não tenha som)

  Serial.begin(9600); // Iniciando Monitor Serial
}
// --------------------------------------------------------------------------- //

//

// --- Bloco de Execução do Código ------------------------------------------- //
void loop() {
  digitalWrite(ledRed, LOW); //
  digitalWrite(ledYel, LOW); // Desligando todos os leds
  digitalWrite(ledGre, LOW); //
  
  if(distancia.distance() > 30) { // Se distância maior que 30:
   lcd.print("      "); // Imprime os espaço na Tela
   lcd.print(distancia.distance()); // Imprime a distância captada pelo sensor
   lcd.print(" cm"); // Imprime a unidade de medida
   lcd.setCursor(3, 1); // Set o cursor para posição definida
   lcd.print("         "); // Imprime os espaço na Tela
   delay(500); // Delay de 500 millisegundos
   lcd.clear(); // Limpa a tela
  } 
  
  else if(distancia.distance() > 20 & distancia.distance() <= 30) {
    lcd.print("      "); // Imprime os espaço na Tela
    lcd.print(distancia.distance()); // Imprime a distância captada pelo sensor
    lcd.print(" cm"); // Imprime a unidade de medida
    printGreen(); // Chama a função "printGreen" que está definida no final do código
    delay(500); // Delay de 500 millisegundos
    lcd.clear(); // Limpa a tela
  } 
  
  else if(distancia.distance() > 10 & distancia.distance() <= 20) {
    lcd.print("      "); // Imprime os espaço na Tela
    lcd.print(distancia.distance()); // Imprime a distância captada pelo sensor
    lcd.print(" cm"); // Imprime a unidade de medida
    printYellow(); // Chama a função "printYellow" que está definida no final do código
    delay(500); // Delay de 500 millisegundos
    lcd.clear(); // Limpa a tela
  } 
  
  else if(distancia.distance() <= 10) {
    lcd.print("      "); // Imprime os espaço na Tela
    lcd.print(distancia.distance()); // Imprime a distância captada pelo sensor
    lcd.print(" cm"); // Imprime a unidade de medida
    printRed(); // Chama a função "printRed" que está definida no final do código
    delay(500); // Delay de 500 millisegundos
    lcd.clear(); // Limpa a tela
  } 
  
  Serial.println(distancia.distance()); // Imprimi a distância captada pelo sensor no Monitor Serial
}
// ------------------------------------------------------------------------------------------------ //

//

// --- Definindo Funções a serem executadas ----------------------------- //

void printGreen() { // Definindo a função "PrintGreen"
  digitalWrite(ledGre, HIGH); // Liga o Led Verde
  lcd.setCursor(3, 1); // Set o cursor para posição definida
  lcd.print(" Cuidado! "); // Imprime na tela LCD a mensagem entre aspas
}

void printYellow() { // Definindo a função "PrintYellow"
  digitalWrite(ledYel, HIGH); // Liga o Led Amarelo
  lcd.setCursor(3, 1); // Set o cursor para posição definida
  lcd.print("Bem Perto!"); // Imprime na tela LCD a mensagem entre aspas
  tone(buzzer, 350); // Buzzer emite um som 
}

void printRed() { // Definindo a função "PrintRed"
  digitalWrite(ledRed, HIGH); // Liga o Led Vermelho
  lcd.setCursor(3, 1); // Set o cursor para posição definida
  lcd.print("VAI BATER!"); // Imprime na tela LCD a mensagem entre aspas
  tone(buzzer, 200); // Buzzer emite um som
}
// ---------------------------------------------------------------------- //
