const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
}
void loop() 
{
  tempc = gettemp();
  Serial.print(tempc);
}


// this is the function to get the temperature of the atmoshpere.
float gettemp()
{
  vout=analogRead(sensor);
  // just to account for inaccuracies in the LM35 readings
  vout+=-5.5;
  vout=(vout*500)/1023;// Storing value in Degree Celsius
  tempf=(vout*1.8)+32; // Converting to Fahrenheit 
  delay(1000); //Delay of 1 second for ease of viewing 
  return vout;
}
