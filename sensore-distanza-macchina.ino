//////////////////////////// PIN DEFINE & VARIABILI
#define ledRosso  2
#define ledVerde  3 
#define buzzer  4

int pinTrigger =   10;
int  pinEcho = 9;

int distanza;



//////////////////////////// SETUP INIZIALE
void setup() {
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  pinMode(ledVerde, OUTPUT); //inizializza il ledVerde
  pinMode(ledRosso, OUTPUT); //inizializza il ledRosso

  Serial.begin(9600);


}



////////////////////////////  VOID LOOP
void loop() {
  int distanza = CalcolaDistanza(pinEcho, pinTrigger);
  
  PrintDistanza(distanza);
  

  if(distanza < 20){
    tone(buzzer,800,100);
    digitalWrite(ledRosso, HIGH); //accendi led rosso
    digitalWrite(ledVerde, LOW); //spegni led verde
    delay(100);
   }else if (distanza >=20 && distanza< 39){
      tone(buzzer,800,200);
      digitalWrite(ledRosso, HIGH); //accendi led rosso
      digitalWrite(ledVerde, LOW); //spegni led verde
      delay(200);
      
    }else if (distanza >=40 && distanza<= 60){
      tone(buzzer,800,300);
      digitalWrite(ledRosso, HIGH); //accendi led rosso
      digitalWrite(ledVerde, LOW); //spegni led verde
      delay(300);
    }else{
      digitalWrite(ledVerde, HIGH); //accendi led verde
      delay(400);
     }
   
  
  digitalWrite(ledRosso, LOW); //spegni led rosso
  delay(100);

}
