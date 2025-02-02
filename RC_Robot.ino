//Project Title : Multitasking_Robot //
//Team Name : ElectroFreaks //
// College Name : Jain College of Engineering and Research, Belagavi //
// Team Leader Name : Krishna Gondkar //
// Contact Number : 9980585839 //

#define enA 10  // Enable1 L298 Pin enA 
#define in1 9   // Motor1 L298 Pin in1 
#define in2 8   // Motor1 L298 Pin in2 
#define in3 7   // Motor2 L298 Pin in3 
#define in4 6   // Motor2 L298 Pin in4 
#define enB 5   // Enable2 L298 Pin enB 

int bt_data;
int Speed = 130;

void setup(){
  
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
 
  pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
  pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
  pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
  pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
  pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
  pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

 // pinMode(2, OUTPUT); // Dc motor Connection

  delay(1000);
}

void loop(){
  // If some data is sent, reads it and saves it in state
  if(Serial.available() > 0){     
    bt_data = Serial.read(); 
    Serial.println(bt_data);
    if(bt_data > 20){Speed = bt_data;}      
  }

  analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
  analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

  if(bt_data == 2)
  {
    forword();
    }  // if the bt_data is '1' the DC motor will go forward
  
  else if(bt_data == 3)
  {
    backword();
    }  // if the bt_data is '2' the motor will reverse
  
  else if(bt_data == 1)
  {
    turnLeft();
    
    }  // if the bt_data is '3' the motor will turn left
  
  else if(bt_data == 4
  )
  {
    turnRight();
  } // if the bt_data is '4' the motor will turn right
  
  else if(bt_data == 5)
  {
    Stop(); 
    
    }     // if the bt_data '5' the motor will stop

//else if(bt_data == 8)
//   {
//     digitalWrite(2, HIGH); // DC motor Turn On
//     }

// else if(bt_data == 9)
//   {
//     digitalWrite(2, LOW); // Dc motor Turn OFF 
//     }
   delay(30);
 }

void forword(){  // forward
  digitalWrite(in1, HIGH); // Right Motor forward Pin 
  digitalWrite(in2, LOW);  // Right Motor backward Pin 
  digitalWrite(in3, LOW);  // Left Motor backward Pin 
  digitalWrite(in4, HIGH); // Left Motor forward Pin 
}

void backword(){ // backward
  digitalWrite(in1, LOW);  // Right Motor forward Pin 
  digitalWrite(in2, HIGH); // Right Motor backward Pin 
  digitalWrite(in3, HIGH); // Left Motor backward Pin 
  digitalWrite(in4, LOW);  // Left Motor forward Pin 
}

void turnRight(){ // turn right
  digitalWrite(in1, LOW);  // Right Motor forward Pin 
  digitalWrite(in2, HIGH); // Right Motor backward Pin  
  digitalWrite(in3, LOW);  // Left Motor backward Pin 
  digitalWrite(in4, HIGH); // Left Motor forward Pin 
}

void turnLeft(){ // turn left
  digitalWrite(in1, HIGH); // Right Motor forward Pin 
  digitalWrite(in2, LOW);  // Right Motor backward Pin 
  digitalWrite(in3, HIGH); // Left Motor backward Pin 
  digitalWrite(in4, LOW);  // Left Motor forward Pin 
}

void Stop(){ // stop
  digitalWrite(in1, LOW); // Right Motor forward Pin 
  digitalWrite(in2, LOW); // Right Motor backward Pin 
  digitalWrite(in3, LOW); // Left Motor backward Pin 
  digitalWrite(in4, LOW); // Left Motor forward Pin 
}
