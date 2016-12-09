
//Incluidas bibliotecas responsáveis pelo display LCD e receptor infravermelho
#include <LiquidCrystal.h>
#include <IRremote.h>

int led = 13;
int i = 0;

IRrecv irrecv(12); //Configuração do pino receptor de sinal IR
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //COnfiguração dos pinos conectados com display LCD
decode_results resultado;

void setup() {
  pinMode(led, OUTPUT);
  lcd.begin(20, 4); //Inicialização do display LCD
  irrecv.enableIRIn(); //Abilita receptor
  lcd.clear();
  lcd.print("cmn06s1");
  lcd.setCursor(0,4);
  lcd.print("eletr0nica anal0gica e digital");
  Serial.begin(9600);
}

const char * retorna_integrante(double opt) {
  const char *vetor[50];
  int c = 0;
  if(opt == 3772790473) {
    c = 1;
  } else if(opt == 3772786903) {
    c = 2;
  } else if(opt == 3772819543) {
    c = 3;  
  } else if(opt == 3772803223) {
    c = 4;
  } else if(opt == 3772806793) {
    c = 5; 
  }
  
  switch(c) {
  	case 1:
    	*vetor = "Allex";
    	break;
    case 2:
    	*vetor = "Daniel";
    	break;
    case 3:
    	*vetor = "Heryck";
    	break;
    case 4:
    	*vetor = "Paul0";
    	break;
    case 5:
    	*vetor = "Renan";
    	break;
    default:
      *vetor = "";
      break;
  }
  
  return *vetor;
}


void loop() {
  
  if (irrecv.decode(&resultado)){        // Se um dado for recebido
        lcd.clear();
        digitalWrite(led, HIGH);             // Pisca LED
        delay(100);
        digitalWrite(led, LOW);
        lcd.print(retorna_integrante(resultado.value));
        Serial.println(resultado.value, DEC);
        irrecv.resume();
      	delay(1000);
  } else{
        for(i=0;i<20;i++) {
           if(irrecv.decode(&resultado)){
              break;
            }
           lcd.scrollDisplayLeft();
           delay(450);  
        }  
  }
}
