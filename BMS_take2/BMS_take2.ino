
float volt = 0;
bool PSU = true;
void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  pinMode(16,INPUT);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pop_vol_arr();
  batteryon();
  delay(1000);
}

void pop_vol_arr()
{
  
  //iterate over the pins to attain the voltage.Pins 15 to 1
  volt = (analogRead(16) * (4.6/1023.0));
  volt = volt *5;
  Serial.println("voltage:");
  Serial.println(volt);
}


//ensures the battery is not overcharged or discharged.
void batteryon()
{
  if((volt < 19.5))
  {
    //is a PSU and battery is fully charged
    Serial.println("HIGH");
    digitalWrite(2,HIGH);
    // cuts the power 
  }
  else
  {
    //battery is charged and no PSU
    Serial.println("LOW");
    digitalWrite(2,LOW);
    //
  }
}


//we can have to sources of inputs....the battery and the PSU. The PSU should always have peferance. The battery 
//could only be on when the voltage is greater than 15V
//less than that we need it to charge this means pin2 is low...so the amp can only get power from the PSU.
