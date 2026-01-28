/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
int p = A0;
int n = 0;
int m = 0;

int mm=0;
int nn=0;
int datad[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int nomer = sizeof(datad) / sizeof(datad[0]); // Размер массива

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A2);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(100);        // delay in between reads for stability  
 int sensorV = sensorValue/5;
 if ((n >=10) &&(n <20))
 {
  datad[m]=sensorV;
  m+=1;
  }
if(n<=20){
 n+=1;
 }

 if (n==20)
 {

  //for (int i = 0; i < nomer; i++) {
    //Serial.print(datad[i]);
    //Serial.print(" ");
    
  //}
  
  //Serial.println(" ");
   // Алгоритм пузырьковой сортировки
  for (int i = 0; i < nomer-1; i++) {
    for (int j = 0; j < nomer - i - 1; j++) {
      if (datad[j] > datad[j + 1]) {
        // Обмен элементов
        int temp = datad[j];
        datad[j] = datad[j + 1];
        datad[j + 1] = temp;
      }
    }
  }

  // Вывод результата
  //for (int i = 0; i < nomer; i++) {
    //Serial.print(datad[i]);
    //Serial.print(" ");
    
  //}
  //Serial.println(" ");
  mm =datad[0];
  nn= datad[9];
 
  //Serial.print("m= ");
   //Serial.print(mm);
  // Serial.print("n= ");
  // Serial.print(nn);
  }

  
  if ((sensorV<mm) || (sensorV>nn)){
  tone(p, sensorV);
  }
  else
  {
    tone(p, -1);
    }
}
