
// creating an array of 5 that will store the five values of voltages
float volt_arr[5];
float each_volt_arr[5];
bool drain_it[5];
float current_val = 0;
float total_voltage = 0;

void setup() {
  // put your setup code here, to run once:
  
  
 // initialize serial communication at 9600 bits per second:
 Serial.begin(9600);

  
  // set the pins as inputs to take in the voltage values of the batteries.
  
  pinMode(18,INPUT);
  pinMode(17,INPUT);
  pinMode(19,INPUT);
  pinMode(16,INPUT);
  pinMode(15,INPUT);
  pinMode(14,INPUT); //using this pin to take in a voltage to measure the current flowing through the battery

  //set the pins as outputs to control the transistor
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT); //will be used to trip the relay.
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pop_vol_arr();
  batteryon();
  delay(1000);
}

//this function will check the voltage level of the battery pack
//if greater than 20.5V it will set pin 7 low...turning of the transistor..battery stops charging. 
void batteryon()
{
  if((total_voltage > 20.0 )|| (total_voltage < 16.0))
  {
    Serial.println("The battery is not charging");
    digitalWrite(5,LOW);
  }
  else
  {
    Serial.println("The battery is charging");
     digitalWrite(5,HIGH);
  }
 
}


//function to get the temperature of the environment....LM35 outputs 0.1 mV/degree


//write a function to obtain the current in the system
void getcurrent()
{
  float temp = 0;
  // we are using a 10 ohm resistor so the value stored in current_val will be the current in mA.
  temp = analogRead(16);
  Serial.println(temp);
  current_val = temp * (5/1023.0);
  Serial.print("The current is : ");
  Serial.println(current_val);
  delay(2000);
}


//function to turn on the transistors to drain the battery
void drain()
{
  Serial.println("Transistors Turned on: ");
  for(int i =0; i<5; i++)
  {
    
    if(drain_it[i] == true)
    {
      Serial.print("True for voltage ");
      Serial.println(i+1);
      digitalWrite(2+i,HIGH);
    }
    else
    {
      Serial.print("False for voltage ");
      Serial.println(i+1);
      digitalWrite(2+i,LOW);
    }
  }
 // delay(3000);
}

//function to determine if we need to drain the battery
void vol_drain()
{
  
  float vol = 3.75;
  for(int i =0; i<5; i++)
  {
    Serial.print("Input voltage ");
    Serial.println(i+1);
    Serial.println(volt_arr[i]);
    delay(3000);
    Serial.println("Calculating the voltage difference...");
    each_volt_arr[i] = volt_arr[i] - vol;
    total_voltage += volt_arr[i];
    Serial.println(each_volt_arr[i]);
    
    
    if(each_volt_arr[i]>0)
    {
      drain_it[i] = true;
    }
    else
    {
      drain_it[i] = false;
    }
    Serial.println("Should I drain...");
    Serial.println(drain_it[i]);
    delay(3000);
  }
  
}

void pop_vol_arr()
{
  //iterate over the pins to attain the voltage.Pins 15 to 19
  float sum = 0;
  float curtemp = 0;
  float volt = 0;
  for(int i =0; i<10; i++)
  {
    volt += (analogRead(15) * (4.6/1023.0));
    
  }
  total_voltage = volt/2;
  Serial.println(total_voltage);
}
