
float volt = 0;
bool PSU = true;
int Relaypin =3;
int voltpin = 17;
void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  pinMode(voltpin,INPUT);
  pinMode(Relaypin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pop_vol_arr();
 
  delay(1000);
}

void pop_vol_arr()
{
  //iterate over the pins to attain the voltage.Pins 15 to 1
  volt = (analogRead(voltpin) * (4.6/1023.0));
  volt = volt*5.0
  ;
  Serial.println("voltage:");
  Serial.println(volt);
  delay(1000);
    if((volt > 19.5))
  {
    //is a PSU and battery is fully charged
    Serial.println("LOW");
    digitalWrite(Relaypin,LOW);
    // cuts the power 
  }
  else if( volt <19.5)
  {
    //battery is charged and no PSU
    Serial.println("HIGH");
    digitalWrite(Relaypin,HIGH);
    //
  }

} 


void batteryon()
{

  if((volt < 19.5))
  {
     pop_vol_arr();
    //is a PSU and battery is fully charged
    Serial.println("HIGH");
    digitalWrite(2,HIGH);
    // cuts the power 
  }
  else
  {
     pop_vol_arr();
    //battery is charged and no PSU
    Serial.println("LOW");
    digitalWrite(2,LOW);
    //
  }
}
