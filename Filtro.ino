void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

double y1=0,y2=0,y3=0,y4=0,y5=0,y6=0,y7=0;
double van=0.0;
double arr[7]={0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double aux=0.0;
double t;
double x;

void loop() {
  delay(10);
  y7= analogRead(A0);
  arr[0]=y1; 
  arr[1]=y2; 
  arr[2]=y3;
  arr[3]=y4; 
  arr[4]=y5; 
  arr[5]=y6;
  arr[6]=y7;
  
  for(int i=0;i<7;i++)
  {
      for(int j=0;j<6;j++)
      {
        if(arr[j]>arr[j+1])
        {
         aux=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=aux;
        }
    }
  }
  van=(arr[3]*5)/1023;
  x=(van*0.3)/5;
  t=x/0.01;
  Serial.println(t,9);
  y1=y2;
  y2=y3;
  y3=y4;
  y4=y5;
  y5=y6;
  y6=y7;
  y7=0;
  
}
