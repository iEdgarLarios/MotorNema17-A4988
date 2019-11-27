const int steppin = 2;
const int dirpin = 3;
const int steppin2 = 4;
const int dirpin2 = 5;
const int tiempo = 700;
char tecla;
char ending;
//char aux;

void setup() {
  pinMode(steppin,OUTPUT);
  pinMode(dirpin,OUTPUT);
  pinMode(steppin2,OUTPUT);
  pinMode(dirpin2,OUTPUT);
  Serial.begin(9600);
}

/*
void prueba(char aux){  
  switch(aux){
    case 'w':
      straight();
    break;
  
    case 's':
      backwards();
    break;
  
    case 'a':
      left();
    break;
  
    case 'd':
      right();
    break;
    
    default:
      //Serial.println("Invalid input!");
    break;
  }
}

*/
void forward(){
  Serial.println("Cambiando dirección ");
  Serial.println("Avanzando ");
  digitalWrite(dirpin, true);
  digitalWrite(dirpin2, 0); 
  for(int x = 0; x < 750; x++){  
    digitalWrite(steppin,HIGH);      
    delayMicroseconds(tiempo);
    digitalWrite(steppin,LOW);
    delayMicroseconds(tiempo);

    digitalWrite(steppin2,HIGH);      
    delayMicroseconds(tiempo);
    digitalWrite(steppin2,LOW);
    delayMicroseconds(tiempo);
  }
}

void backwards(){
  Serial.println("Cambiando direccion ");
  Serial.println("Retrocediendo ");
  digitalWrite(dirpin, 0);
  digitalWrite(dirpin2, true);
  for(int x = 0; x < 750; x++){  
    digitalWrite(steppin,HIGH);    
    delayMicroseconds(tiempo);
    digitalWrite(steppin,LOW);
    delayMicroseconds(tiempo);

    digitalWrite(steppin2,HIGH);    
    delayMicroseconds(tiempo);
    digitalWrite(steppin2,LOW);
    delayMicroseconds(tiempo);  
  }
}

void right(){
  //Wheels counter-clock wise 
  Serial.println("Cambiando direccion");
  Serial.println("Girando a la derecha");
  digitalWrite(dirpin, 0);
  digitalWrite(dirpin2, 0); 

  for(int x = 0; x < 750; x++){  
    digitalWrite(steppin,HIGH);      
    delayMicroseconds(tiempo);
    digitalWrite(steppin,LOW);
    delayMicroseconds(tiempo);

    digitalWrite(steppin2,HIGH);      
    delayMicroseconds(tiempo);
    digitalWrite(steppin2,LOW);
    delayMicroseconds(tiempo);
  }
}

void left(){
  //Wheels clockwise
  Serial.println("Cambiando direccion ");
  Serial.println("Girando a la izquierda ");
  digitalWrite(dirpin, true);
  digitalWrite(dirpin2, true); 
  for(int x = 0; x < 750; x++){  
    digitalWrite(steppin,HIGH);      
    delayMicroseconds(tiempo);
    digitalWrite(steppin,LOW);
    delayMicroseconds(tiempo);

    digitalWrite(steppin2,HIGH);      
    delayMicroseconds(tiempo);
    digitalWrite(steppin2,LOW);
    delayMicroseconds(tiempo);
  }
  
}

void loop() {
  if(Serial.available())
    //delay(3000);
    
    tecla = Serial.read();
    
    if(tecla == 'w'){
      Serial.println('w');
      forward();
    }

    if(tecla == 's'){
      Serial.println('s');
      backwards();
    }

    if(tecla == 'a'){
      Serial.println('a');
      left();
    }

    if(tecla == 'd'){
      Serial.println('d');
      right();
    }
    //prueba(tecla);
    Serial.flush();    
}
