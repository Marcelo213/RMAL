
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
      int X1 = X1S.toInt();
        Serial.println(X1S);
        Serial.println(X1);
        Serial.println(" ");
      X2S = position1[1];
      int X2 = X2S.toInt();
        Serial.println(X2S);
        Serial.println(X2);
        Serial.println(" ");
      X3S = position1[2];
      int X3 = X3S.toInt();
        Serial.println(X3S);
        Serial.println(X3);
        Serial.println(" ");
      X4S = position1[3];
      int X4 = X4S.toInt();
        Serial.println(X4S);
        Serial.println(X4);
        Serial.println(" ");
      X5S = position1[4];
      int X5 = X5S.toInt();
        Serial.println(X5S);
        Serial.println(X5);
        Serial.println(" ");
      
      summation = (X1+X2+X3+X4+X5); 
       // Serial.println(summation);
        //Serial.println(Aval);
    
    Y = summation%2;
   Serial.print("Is the data odd(0) or even(1): ");  
   Serial.println(Y);
   Serial.println(" ");
       
      
     // || ((YS == 1) && (Aval = "0")))
     
  
  
   /*String YS = String(Y);
   Serial.print("The Y string is: ");
   Serial.println(YS);*/

   Aval = command[6]; 
   int Aval1 = Aval.toInt();
   Serial.print("The parity mode is: ");
   Serial.println(Aval1);
   Serial.println(" ");
   
   if ((Y == 0 && Aval1 == 0)||(Y == 1 && Aval1 == 1)){
       Serial.print("The state is: ");
       Serial.println("1_ERROR_1");
       }
      } else {
        Serial.println("Communication Success.");
      }

  }
   
}
  
