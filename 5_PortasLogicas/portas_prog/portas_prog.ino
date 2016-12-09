int led_a = 13;
int led_b = 12;
int led_r = 11;

int a = 0;
int b = 0;

void and_gate() {
    for(a = 0; a<=1; a++){
    for(b = 0; b<=1; b++){
      if (a == 1){
        digitalWrite(led_a, HIGH);
      } else {
        digitalWrite(led_a, LOW);
      }

      if (b == 1){
        digitalWrite(led_b, HIGH);
      } else {
        digitalWrite(led_b, LOW);  
      }
      
      if(a == 1 && b == 1) {
        digitalWrite(led_r, HIGH);
      }
      
      delay(2000);
      digitalWrite(led_r, LOW);
      digitalWrite(led_a, LOW);
      digitalWrite(led_b, LOW);
    }
   }  
}

void or_gate() {
   for(a = 0; a<=1; a++){
    for(b = 0; b<=1; b++){
      if (a == 1){
        digitalWrite(led_a, HIGH);
      } else {
        digitalWrite(led_a, LOW);
      }

      if (b == 1){
        digitalWrite(led_b, HIGH);
      } else {
        digitalWrite(led_b, LOW);  
      }
      
      if(a == 1 || b == 1) {
        digitalWrite(led_r, HIGH);
      }
      
      delay(2000);
      digitalWrite(led_r, LOW);
      digitalWrite(led_a, LOW);
      digitalWrite(led_b, LOW);
    }
   }  
}

void nand_gate() {
    for(a = 0; a<=1; a++){
      for(b = 0; b<=1; b++){
        if (a == 1){
          digitalWrite(led_a, HIGH);
        } else {
          digitalWrite(led_a, LOW);
        }
  
        if (b == 1){
          digitalWrite(led_b, HIGH);
        } else {
          digitalWrite(led_b, LOW);  
        }
        
        if(a == 1 && b == 1) {
          digitalWrite(led_r, LOW);
        } else {
          digitalWrite(led_r, HIGH);
        }
        
        delay(2000);
        digitalWrite(led_r, LOW);
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
      }
   }    
}

void nor_gate() {
    for(a = 0; a<=1; a++){
      for(b = 0; b<=1; b++){
        if (a == 1){
          digitalWrite(led_a, HIGH);
        } else {
          digitalWrite(led_a, LOW);
        }
  
        if (b == 1){
          digitalWrite(led_b, HIGH);
        } else {
          digitalWrite(led_b, LOW);  
        }
        
        if(a == 1 || b == 1) {
          digitalWrite(led_r, LOW);
        } else {
          digitalWrite(led_r, HIGH);
        }
        
        delay(2000);
        digitalWrite(led_r, LOW);
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
      }
   }    
}

void not_gate() {
  for(a = 0; a<=1; a++){
        if (a == 1){
          digitalWrite(led_a, HIGH);
        } else {
          digitalWrite(led_a, LOW);
        }
        
        if(a == 1) {
          digitalWrite(led_r, LOW);
        } else {
          digitalWrite(led_r, HIGH);
        }
        
        delay(2000);
        digitalWrite(led_r, LOW);
        digitalWrite(led_a, LOW);
        digitalWrite(led_b, LOW);
   }
       
}

void setup() {
    pinMode(led_a, OUTPUT);
    pinMode(led_b, OUTPUT);
    pinMode(led_r, OUTPUT);
}

void loop() {
    and_gate();
    delay(2000);
    or_gate();
    delay(2000);
    nand_gate();
    delay(2000);
    nor_gate();
    delay(2000);
    not_gate();
    delay(2000);
}



