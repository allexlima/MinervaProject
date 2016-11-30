//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Projeto IV - Eletrônica Analógica e Digital
// 
// Made by Danielbispov Danielbispov
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/3325780-projeto-iv-eletronica-analogica-e-digital

//Incluidas bibliotecas responsáveis pelo display LCD e receptor infravermelho
#include <LiquidCrystal.h>
#include <IRremote.h>

int led = 13;

IRrecv irrecv(12); //Configuração do pino receptor de sinal IR
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //COnfiguração dos pinos conectados com display LCD
decode_results resultado;
char* turma = "CMN06S1 Eletronica Analogica e Digital ";
char* instrucao = "Bem Vindo! Pressione alguma tecla (1-5)";

void setup() {
  pinMode(led, OUTPUT);
  lcd.begin(16,2); //Inicialização do display LCD
  irrecv.enableIRIn(); //Abilita receptor
}

const char * retorna_integrante(int opt) {
  static char* array;
  switch(opt) {
  	case 16582903:
    	array = "Allex Lima";
    	break;
    case 16615543:
    	array = "Daniel Bispo";
    	break;
    case 16599223:
    	array = "Heryck Michael";
    	break;
    case 16591063:
    	array = "Paulo Moraes";
    	break;
    case 16623703:
    	array = "Renan Barroncas";
    	break;
  }
  return array;
}


void loop() {
  	
    if (irrecv.decode(&resultado)){        // Se um dado for recebido
        lcd.clear();
        digitalWrite(led, HIGH);             // Pisca LED
        delay(100);
        digitalWrite(led, LOW);
        lcd.clear();                         // Limpa a tela do LCD
        lcd.print(retorna_integrante(resultado.value));    // Retorna o integrante correspondente
        irrecv.resume();
      	delay(4500);
    } else {                               // Exibe mensagem de boas vindas
          lcd.setCursor(0,0);
          lcd.print(instrucao);
          lcd.setCursor(0,2);
          lcd.print(turma);
          lcd.scrollDisplayLeft();
          delay(150);
  		//}
    }
  }
