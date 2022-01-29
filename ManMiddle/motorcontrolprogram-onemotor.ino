
String position1; 
String position2;
String position3;
String X1S;
String X2S;
String X3S;
String X4S;
String X5S;
String Aval;
long summation;
int Y;

void setup() {
  Serial.begin(9600);
}


void loop() {
   // MXXXXXA

  if(Serial.available()){
    String command = Serial.readString();
   
    if (command.startsWith("M")){

      position1 = command.substring(1,6);
      
      X1S = position1[0];
      int  X1 = X1S.toInt();
      X2S = position1[1];
      int X2 = X2S.toInt();
      X3S = position1[2];
      int X3 = X3S.toInt();
      X4S = position1[3];
      int X4 = X4S.toInt();
      X5S = position1[4];
      int X5 = X5S.toInt();
      
      
      summation = (X1+X2+X3+X4+X5); 
       // Serial.println(summation);
        //Serial.println(Aval);
    
    Y = summation%2;
     
   //  Serial.println(Y);
       
       
      
     // || ((YS == 1) && (Aval = "0")))
   Aval = command[6]; 
  
   String YS = String(Y);
   Serial.println(YS);
   Serial.println(Aval);
   int Aval1 = Aval.toInt();
   if ((Y == 0 && Aval1 == 1)||(Y == 1 && Aval1 == 0)){
       Serial.println("1_ERROR_1");
       }
      }

  }
   
}
  
