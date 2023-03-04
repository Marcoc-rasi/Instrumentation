// Puertos digitales de entrada
int Conmutador = 2;
int Pd204_puerta = 3;
int Pd204_antiRatas = 8;
int HC_SR04_Echo=13;
int PIR = 10;
int Push_Botton = 11;

// Puertos digitales de salida

int MOC3012 = 9;
int HC_SR04_Trig = 12;

// Puertos analogicos de entrada

// Puertos analogicos de salida
int in1_HW_095 = 5;
int in2_HW_095 = 6;
void setup() {
  
//Inicializar la comunicación en serie a 9600 bits por segundo:
  Serial.begin(9600);
  // Puertos digitales de entrada
  pinMode(Conmutador, INPUT);
  pinMode(Pd204_puerta, INPUT);
  pinMode(Pd204_antiRatas, INPUT);
  pinMode(HC_SR04_Echo, INPUT);
  pinMode(PIR, INPUT);
  pinMode(Push_Botton,INPUT);

  // Puertos digitales de salida
  pinMode(in1_HW_095, OUTPUT);
  pinMode(in2_HW_095, OUTPUT);
  pinMode(MOC3012, OUTPUT);
  pinMode(HC_SR04_Trig, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// Leer la entrada del Conmutador:
  //int Estado_Conmutador = digitalRead(Conmutador);
  //int Estado_Pd204 = digitalRead(Pd204);
  // Imprime en el puerto serial el estado del conmutador:
  //Serial.println(Estado_Conmutador);
   Esperar_gato(); 
   CerrarPuerta();
  
  /////////////////////////////////////
  
}
void Esperar_gato(){
  int No_hay_gatos = 0;
  while(No_hay_gatos ==0){
      int Estado_Pir = digitalRead(PIR);
      int Estado_Pd204_antiRatas = digitalRead(Pd204_antiRatas);
      int Estado_Push_Botton = digitalRead(Push_Botton);
  
  
      //Serial.println(Estado_Pir);1 si detecta presencia
      //Serial.println(Estado_Pd204_antiRatas);// 1 Si cumple con la altua
      //Serial.println(Estado_Push_Botton);1 si esta presionado
      if(Estado_Pir == 1 & Estado_Pd204_antiRatas == 0 & Estado_Push_Botton == 1){
      AbrirPuerta();
      No_hay_gatos = 1;// se encontro un gato
     // Serial.println(digitalRead(Conmutador));
      }
  }
}
void AbrirPuerta(){
  
  if(digitalRead(Conmutador) == 0){
    //cuando abrimos la puerta encendemos el motor
      analogWrite(in1_HW_095, 255);
      analogWrite(in2_HW_095, 0);
      
      while(digitalRead(Conmutador) == 0){
        Serial.println("La Puerta se esta abriendo");
        }
      
      //cuando salimos el motor sigue girando para apagarlo
      //mandamos a cero la terminal que encendimos 
      analogWrite(in1_HW_095,0);
      digitalWrite(MOC3012, HIGH);
      Serial.println("La Puerta esta abierta");
  }
  else{
    Serial.println("La Puerta esta abierta");
  }
}

void CerrarPuerta(){
  //cuando cerramos la puerta la puerta encendemos el motor, en sentido contrario
  int avanzo = 0;
  Serial.println("La Puerta se esta cerrando");
      while(digitalRead(Pd204_puerta) == 1){
        double Distancia = Disparar_Sensor_Ultrasonico();
        if(Distancia<25){
          analogWrite(in2_HW_095, 0);
          if(avanzo == 1){
             AbrirPuerta();
             avanzo = 0;
          }
          delay(1000);
          Serial.println("Hay un obstaculo, esperamos");
        }
        else{
          
          if(avanzo == 0){
          avanzo = 1;
          Serial.println("No Hay un obstaculo, esperar 5 seg para cerrar");
          delay(5000);
          analogWrite(in1_HW_095, 0);
          analogWrite(in2_HW_095, 255);
          }
        }
      }
      
      //cuando salimos el motor sigue girando para apagarlo
      //mandamos a cero la terminal que encendimos 
      analogWrite(in2_HW_095,0);
      Serial.println("La puerta esta cerrada");
      digitalWrite(MOC3012, LOW);
      
}
double Disparar_Sensor_Ultrasonico(){
  
  double duracion;
  double distancia;

  digitalWrite(HC_SR04_Trig,LOW);
  delayMicroseconds(4);
  
  digitalWrite(HC_SR04_Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_SR04_Trig,LOW);

  duracion=pulseIn(HC_SR04_Echo,HIGH);
  duracion=duracion/2;
  
  distancia=duracion/29;

  Serial.println(distancia);

  delay(50);
  return distancia;
}
