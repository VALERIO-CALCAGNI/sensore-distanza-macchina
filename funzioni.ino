int CalcolaDistanza(int pinEcho, int pinTrigger){
  // imposta l'uscita del trigger LOW
  digitalWrite(pinTrigger, LOW);
  
  // imposta l'uscita del trigger HIGH per 10 microsecondi
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  
  // calcolo del tempo attraverso il pin di echo
  long durata = pulseIn(pinEcho, HIGH);
  
  if( durata > 38000 ){
    Serial.println("Fuori portata");// dopo 38ms è fuori dalla portata del sensore
    return -1;
  }else{
    return (durata/58.31);
  }
}



void PrintDistanza(int distanza){
  Serial.print("distanza: ");
  
  if(distanza == -1){
    Serial.println("Fuori portata");
  }
  else{ 
    Serial.print(distanza); 
    Serial.println(" cm");
  }
}
