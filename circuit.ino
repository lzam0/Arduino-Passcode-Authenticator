/*
	Student IDs: 
    100385659 - Leihl Zambrano
    100383866 - Mark Pinguel

	The objective of this program is to have a user input 6 values by pressing
    the push button. When button pressed, LED light next to button stays toggled
    on.
    
   	I am using switch cases for when user inputs code != code, as it easier
    to identify with a particular grouping.
    
    -----------------------------------------------------------------------------------
    IF USER INPUT IS WRONG 
    
    -If wrong, increment attempt counter by 1, and make red light flash for 3 seconds.
    -If user has 3 attempts then Lock system for 3 seconds. 
    A buzzer will play with a red and orange/yellow light will flash for 3 seconds.
    
    Inputs are all reset after each attempt.
    -----------------------------------------------------------------------------------
    
    -----------------------------------------------------------------------------------
    IF USER INPUT IS CORREECT
    
    -If user input is correct (using a for loop), green light will flash for 3 seconds
    -Quick blue flashing light activates indicating code reset

    Move onto new stage called "blueLock"
    -If buttons (1 3 6) are pressed while a slow blue light lights up when correct

    Move onto new stage called "admin"
    - User enters 4 digit admin code with the correct LED turning blue

    Move onto new stage called "newCode"
    - User enters new 6 digit code
    - Turn off blue LED
    - New code accepted results in 3 short buzzes
    -----------------------------------------------------------------------------------
    
*/

//================================================================================== 
// Variables

const int btn1 = 2; //first button is pin 2
const int btn2 = 3; //second is pin 3
const int btn3 = 4; //third is pin 4
const int btn4 = 5; //fourth is pin 5
const int btn5 = 6; //third is pin 6
const int btn6 = 7; //fourth is pin 7
const int LED[] = {14,15,16,17,18,19};

int attempt = 1; // attempts of user

const int redLED = 8; //red LED is on pin 8
const int greenLED = 10; //green LED is pin 9
const int orangeLED = 9; //green LED is pin 10
const int buzzer = 11; //green LED is pin 11
const int blueLED = 12; //blue LED is pin 12

// Must delcare entered section
void userInput1(int button);
void blueEnter1(int button);
void adminEnter1(int button);
void newCodeInput1(int button);

int correct = 0; // if user input is correct 
// 0 = User input | 1 = Blue Code Input | 2 = Admin Code Input | 3 = New Code Input
int next = 0; // if correct continue to next stage

int code[] = {1,1,1,1,1,1}; //the desired code is entered in this array,
int entered[6]; // user input
int newCode[6]; // new code by user

int blueCode[] = {1,3,6}; // blue Code
int blueInput[3]; // User input for blue Code

int adminCode[] = {2,2,4,4}; // Admin code
int adminInput[4]; // User input for admin code

unsigned long prevTime = 0;
    unsigned long prevTime2 = 0;
    const unsigned long eventLedOn = 2000;
	const unsigned long eventLedOff = 3000; 


//================================================================================== 

void setup(){ //run once at sketch startup
  Serial.begin(9600); //begin Serial
  
  pinMode(btn1, INPUT_PULLUP); //button 1 is an input
  pinMode(btn2, INPUT_PULLUP); //button 2 is an input
  pinMode(btn3, INPUT_PULLUP); //button 3 is an input
  pinMode(btn4, INPUT_PULLUP); //button 4 is an input
  pinMode(btn5, INPUT_PULLUP); //button 3 is an input
  pinMode(btn6, INPUT_PULLUP); //button 4 is an input

  pinMode(redLED, OUTPUT);     //the red LED is an output
  pinMode(greenLED, OUTPUT);   // the green LED is an output
  pinMode(orangeLED, OUTPUT);  // the orange LED is an output
  pinMode(blueLED, OUTPUT);    // the blue LED is an output
  pinMode(buzzer, OUTPUT);     // the buzzer is an output

  
  digitalWrite(redLED, LOW); //turn the red LED on
  
  for (int i = 0; i < 6;i++){ //work through numbers 0-6
    Serial.print("CODE : ");Serial.println(code[i]);
    pinMode(LED[i],OUTPUT);
  }
}

//================================================================================== 
// Main fuction
void loop(){ //run repeatedly
  if (next == 0){ // user input
    
    if (digitalRead(btn1) == LOW){ //if button1 is pressed
      userInput1(1); //call userInput and pass it a 1

      delay(250);

    }
    else if (digitalRead(btn2) == LOW){ //if button 2 is pressed
      userInput1(2); //call userInput2 and pass it a 2

      delay(250); 

    }
    else if (digitalRead(btn3) == LOW){ //if button 3 is pressed
      userInput1(3); //call userInput3 and pass it a 3

      delay(250); 

    }
    else if (digitalRead(btn4) == LOW){ //if button 4 is pressed
      userInput1(4); //call userInput4 and pass it a 4

      delay(250); 

    }
      else if (digitalRead(btn5) == LOW){ //if button 5 is pressed
      userInput1(5); //call userInput5 and pass it a 5

      delay(250);

    }
      else if (digitalRead(btn6) == LOW){ //if button 6 is pressed
      userInput1(6); //call userInput6 and pass it a 6

      delay(250);
      
    }
  }
  else if (next == 1){ // blue lock 3 inputs
    
    if (digitalRead(btn1) == LOW){
      blueEnter1(1);
      
      delay(250);
    }
        
    if (digitalRead(btn2) == LOW){
      blueEnter1(2);
      delay(250);
    } 
        
    if (digitalRead(btn3) == LOW){
      blueEnter1(3);
      
      delay(250);
  	}
    
    if (digitalRead(btn4) == LOW){
      blueEnter1(4);
      
      delay(250);
  	}
    
    if (digitalRead(btn5) == LOW){
      blueEnter1(5);
      
      delay(250);
  	}
    
    if (digitalRead(btn6) == LOW){
      blueEnter1(6);
      
      delay(250);
  	}
  }
  
  else if (next == 2){ // Admin code
    
    if (digitalRead(btn1) == LOW){
      adminEnter1(1);
      delay(250);
    }
    
   if (digitalRead(btn2) == LOW){
      adminEnter1(2);
      delay(250);
   }
   
   if (digitalRead(btn3) == LOW){
      adminEnter1(3);
      delay(250);
   }
   if (digitalRead(btn4) == LOW){
      adminEnter1(4);
      delay(250);
   }
    
   if (digitalRead(btn5) == LOW){
      adminEnter1(5);
      delay(250);
   }
   
   if (digitalRead(btn6) == LOW){
      adminEnter1(6);
      delay(250);
   }
   
  }
  
  if (next == 3){ // New Code for user
    if (digitalRead(btn1) == LOW){ //if button1 is pressed
      newCodeInput1(1); //call userInput and pass it a 1
      delay(250);//wait, needed for correct functioning, otherwise
    }
    else if (digitalRead(btn2) == LOW){ //if button 2 is pressed
      newCodeInput1(2); //call userInput2 and pass it a 2

      delay(250); //wait

    }
    else if (digitalRead(btn3) == LOW){ //if button 3 is pressed
      newCodeInput1(3); //call userInput3 and pass it a 3

      delay(250); //wait

    }
    else if (digitalRead(btn4) == LOW){ //if button 4 is pressed
      newCodeInput1(4); //call userInput4 and pass it a 4

      delay(250); //wait

    }
      else if (digitalRead(btn5) == LOW){ //if button 5 is pressed
      newCodeInput1(5); //call userInput5 and pass it a 5

      delay(250); //wait

    }
      else if (digitalRead(btn6) == LOW){ //if button 6 is pressed
      newCodeInput1(6); //call userInput6 and pass it a 6

      delay(250); //wait
      
    }
  }
  

}

//================================================================================== 

//checks if the code entered is correct by comparing the code[] array with the entered[] array
void validation(){
  
  // Loop through input list and code list (6 values required)
  for (int i = 0; i < 6; i++) {
    Serial.println(entered[i]); // print entered list
    if (entered[i] != code[i]) { // Compare index of entered and code
      correct = 0;
      attempt += 1; // increment the amount of attempts
      break; // if correct = 0, stop the for loop
    }else{
      correct = 1;
    }
  }
  
  if (correct == 1){
    // Correct code
    Serial.println("Correct");
    Serial.print("Attempt ");Serial.println(attempt);

    close_all(); // Turn off all LEDs

    // Blink Green LED for 3 seconds
    blinkLED(greenLED);
	
    // Quick Blue flashing light
    quickFlash();
    
    Serial.println("Enter Blue Code");
    next = 1;
    
    for (int i = 0; i < 7; i++){ //reset entered list
      entered[i] = 0;     
    }
  }
  
  if (correct == 0){
    // Wrong code
    Serial.println("Wrong");
    Serial.print("Attempt ");Serial.println(attempt);

    if (attempt < 4){
      Serial.println("Blink red LED");
      blinkLED(redLED);
    }
    
    if (attempt == 4){ // if wrong and this is the 3rd attempt
      // reset attempt 
      attempt = 1;
      
      // turn on buzzer
      tone(buzzer, 3000);


      // flashing red and orange LED
      // for loop, stop until condition is met
      for (int i = 0; i < 3; i++){
        digitalWrite(redLED,HIGH);
        digitalWrite(orangeLED,HIGH);
        delay(600);
        digitalWrite(redLED,LOW);
        digitalWrite(orangeLED,LOW);
        delay(600);
      }
      
      // turn off buzzer
      noTone(buzzer);
      delay(3000); // LOCK SYSTEM FOR 3 SECONDS
    }
    
    for (int i = 0; i < 7; i++){ //reset entered list
      entered[i] = 0;     
    }
  }
  
  close_all(); // turn off all leds
}

// ==================================================================================

void blueCheck(){
  Serial.println(next); // should be 1
  int wrong = 0;
  // Loop through input list and code list (6 values required)
  for (int i = 0; i < 3; i++) {
    if (blueInput[i] != blueCode[i]) { // Compare index of entered and code
      wrong = 1;
      break; // if correct = 0, stop the for loop
    }
  }
  
  if (wrong == 0){ // correct then progress to next stage
    Serial.println("Correct Blue Code");
    blinkLED(blueLED);
    next = 2;
    Serial.println("Enter Admin Code");
  }
  else{
    Serial.println("Wrong Blue Code");
    attempt+= 1; // increment attemp because it is wrong
    next = 0; // restart to the beginning
  }
  
  for (int i = 0; i < 3; i++){ //reset blue input list
      blueInput[i] = 0;     
    }
  close_all(); // turn off all lights
}
// ==================================================================================
// admin check

void adminCheck(){
  Serial.println(next); // should be 2
  int wrong = 0;
  
  // Loop through input list and code list (6 values required)
  for (int i = 0; i < 4; i++) {
    if (adminInput[i] != adminCode[i]) { // Compare index of entered and code
      wrong = 1;
      break; // if correct = 0, stop the for loop
    }
  }
  
  if (wrong == 0){ // correct code
    digitalWrite(blueLED, HIGH);
    Serial.println("Correct ADMIN CODE");
    
    Serial.println("Enter New Code");
    next = 3;
    Serial.println(next);
  }
  else{
    Serial.println("Wrong Admin Code");
    attempt+= 1; // increment attemp because it is wrong
    next = 0; // restart to the beginning
  }
  
  for (int i = 0; i < 6; i++){ //reset admin enter list
     adminInput[i] = 0;     
  }
  close_all(); // turn off all leds
}

// ==================================================================================

void codeChange(){
  Serial.println("Code Change Section"); // should be 3
  
  // check if list is full
  bool loop = true;
  
  while (loop == true){
    // Make new code as entered list
    for (int i = 0; i<6;i++){
      code[i] = newCode[i];
    }
    delay(250); // delay

    Serial.println("Passcode created");

    delay(250); // delay

    digitalWrite(blueLED, LOW); // Turn off blue LED

    // Print the new code
    for (int i = 0; i<6;i++){
        Serial.print(code[i]);
      }

    // 3 short buzzes
    for (int i = 0; i<3; i++){
        tone(buzzer, 3000);
        //digitalWrite(buzzer, HIGH);
        delay(500);
        noTone(buzzer);
        delay(500);
    }


    Serial.println("Reset");

    next = 0;

    for (int i = 0; i < 6; i++){ //reset enter list
       newCode[i] = 0;   
    }
    break;
  }
  
  close_all(); // turn off all leds

}

  
// ===================================================================================

void blinkLED(int LED){// Blink LED for 3 seconds
  // Loop 3 times using for loop
  for (int i = 0; i < 3; i++) { //
    digitalWrite(LED, HIGH);
    delay(600);
    digitalWrite(LED, LOW);
    delay(600);
  }
}

void quickFlash(){ // have blue LED light flash fast
  for (int i = 0; i < 6; i++){
    digitalWrite(blueLED, HIGH);
    delay(300);
    digitalWrite(blueLED, LOW);
    delay(300);
  }
}


void close_all(){ // Reset all LED lights
  // By using for loop turn off lights
  for (int i = 0; i < 6; i++){
    digitalWrite(LED[i], LOW);
  }
}


//================================================================================== 
// Setting button input into a user input list

void userInput1(int button){ //check the first element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[0] != 0){ //if it is not a zero, i.e. it has already been inputted
    userInput2(button); //move on to checkEntered2, passing it "button"
  }
  
  else if(entered[0] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[0] = button; //set the first element as the button that has been pressed
    Serial.print("1: ");Serial.println(entered[0]); //for debugging
  }
}

void userInput2(int button){ //check the second element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[1] != 0){ //if it is not a zero, i.e. it has already been inputted
    userInput3(button); //move on to checkEntered3, passing it "button"
  }
  
  else if(entered[1] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[1] = button; //set the second element as the button that has been pressed
    Serial.print("2: ");Serial.println(entered[1]); //for debugging
  }
}

void userInput3(int button){  //check the third element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[2] != 0){ //if it is not a zero, i.e. it has already been inputted
    userInput4(button); //call the compareCode function//move on to checkEntered4, passing it "button"
  }
  
  else if (entered[2] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[2] = button; //set the third element as the button that has been pressed
    Serial.print("3: ");Serial.println(entered[2]); //for debugging
  }
}

void userInput4(int button){  //check the third element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[3] != 0){ //if it is not a zero, i.e. it has already been inputted
    userInput5(button); //move on to checkEntered4, passing it "button"
  }
  
  else if (entered[3] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[3] = button; //set the third element as the button that has been pressed
    Serial.print("4: ");Serial.println(entered[3]); //for debugging
  }
}

void userInput5(int button){  //check the third element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[4] != 0){ //if it is not a zero, i.e. it has already been inputted
    userInput6(button); //move on to checkEntered4, passing it "button"
  }
  
  else if (entered[4] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[4] = button; //set the third element as the button that has been pressed
    Serial.print("5: ");Serial.println(entered[4]); //for debugging
  }
}

void userInput6(int button){ //check the fourth element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (entered[5] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    entered[5] = button; //set the final element as the button that has been pressed
    Serial.print("6: ");Serial.println(entered[5]);
    delay(100);
    validation(); //call the validation function
  }
}

//================================================================================== 

// Can only input 3 numbers
void blueEnter1(int button){ //check the first element of the blueInput[] array
  digitalWrite(LED[button-1],HIGH);
  if (blueInput[0] != 0){ //if it is not a zero, i.e. it has already been inputted
    blueEnter2(button); //move on to blueEnter2, passing it "button"
  }
  
  else if(blueInput[0] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    blueInput[0] = button; //set the first element as the button that has been pressed
    Serial.print("Blue Input 1: ");Serial.println(blueInput[0]);
  }
}

void blueEnter2(int button){ //check the second element of the blueInput[] array
  digitalWrite(LED[button-1],HIGH);
  if (blueInput[1] != 0){ //if it is not a zero, i.e. it has already been inputted
    blueEnter3(button); //move on to blueEnter3, passing it "button"
  }
  
  else if(blueInput[1] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    blueInput[1] = button; //set the second element as the button that has been pressed
    Serial.print("Blue Input 2: ");Serial.println(blueInput[1]);
  }
}

void blueEnter3(int button){ //check the second element of the blueInput[] array
  digitalWrite(LED[button-1],HIGH);

  if(blueInput[2] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    blueInput[2] = button; //set the second element as the button that has been pressed
    Serial.print("Blue Input 3: ");Serial.println(blueInput[2]);
    delay(100);
    blueCheck();
  }
}

// ==================================================================================

// Admin Check system
void adminEnter1(int button){ //check the first element of the adminInput[] array
  digitalWrite(LED[button-1],HIGH);
  if (adminInput[0] != 0){ //if it is not a zero, i.e. it has already been inputted
    adminEnter2(button); //move on to adminEnter2, passing it "button"
  }
  
  else if(adminInput[0] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    adminInput[0] = button; //set the first element as the button that has been pressed
    Serial.print("Admin Input 1: ");Serial.println(adminInput[0]); //for debugging
  }
}

void adminEnter2(int button){ //check the second element of the adminInput[] array
  digitalWrite(LED[button-1],HIGH);
  if (adminInput[1] != 0){ //if it is not a zero, i.e. it has already been inputted
    adminEnter3(button); //move on to adminEnter3, passing it "button"
  }
  
  else if(entered[1] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    adminInput[1] = button; //set the second element as the button that has been pressed
    Serial.print("Admin Input 2: ");Serial.println(adminInput[1]); //for debugging
  }
}

void adminEnter3(int button){  //check the third element of the adminInput[] array
  digitalWrite(LED[button-1],HIGH);
  if (adminInput[2] != 0){ //if it is not a zero, i.e. it has already been inputted
    adminEnter4(button); //move on to adminEnter4, passing it "button"
  }
  
  else if (entered[2] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    adminInput[2] = button; //set the third element as the button that has been pressed
    Serial.print("Admin Input 3: ");Serial.println(adminInput[2]); //for debugging
  }
}

void adminEnter4(int button){  //check the third element of the adminInput[] array
  digitalWrite(LED[button-1],HIGH);

  if (entered[3] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    adminInput[3] = button; //set the third element as the button that has been pressed
    Serial.print("Admin Input 4: ");Serial.println(adminInput[3]); //for debugging
    
    delay(250);
    
    adminCheck();
  }
}

// ==================================================================================

void newCodeInput1(int button){ //check the first element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (newCode[0] != 0){ //if it is not a zero, i.e. it has already been inputted
    newCodeInput2(button); //move on to newCodeInput2, passing it "button"
  }
  
  else if(newCode[0] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    newCode[0] = button; //set the first element as the button that has been pressed
    Serial.print("New Code Input 1: ");Serial.println(newCode[0]); //for debugging
  }
}

void newCodeInput2(int button){ //check the second element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (newCode[1] != 0){ //if it is not a zero, i.e. it has already been inputted
    newCodeInput3(button); //move on to newCodeInput3, passing it "button"
  }
  
  else if(newCode[1] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    newCode[1] = button; //set the second element as the button that has been pressed
    Serial.print("New Code Input 2: ");Serial.println(newCode[1]); //for debugging
  }
}

void newCodeInput3(int button){  //check the third element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (newCode[2] != 0){ //if it is not a zero, i.e. it has already been inputted
    newCodeInput4(button); //move on to newCodeInput4, passing it "button"
  }
  
  else if (newCode[2] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    newCode[2] = button; //set the third element as the button that has been pressed
    Serial.print("New Code Input 3: ");Serial.println(newCode[2]); //for debugging
  }
}

void newCodeInput4(int button){  //check the third element of the entered[] array
  digitalWrite(LED[button-1],HIGH);
  if (newCode[3] != 0){ //if it is not a zero, i.e. it has already been inputted
    newCodeInput5(button); //move on to newCodeInput5, passing it "button"
  }
  
  else if (newCode[3] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    newCode[3] = button; //set the third element as the button that has been pressed
    Serial.print("New Code Input 4: ");Serial.println(newCode[3]); //for debugging
  }
}

void newCodeInput5(int button){  //check the third element of the newCode[] array
  digitalWrite(LED[button-1],HIGH);
  if (newCode[4] != 0){ //if it is not a zero, i.e. it has already been inputted
    newCodeInput6(button); //move on to newCodeInput6, passing it "button"
  }
  
  else if (newCode[4] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    newCode[4] = button; //set the third element as the button that has been pressed
    Serial.print("New Code Input 5: ");Serial.println(newCode[4]); //for debugging
  }
}

void newCodeInput6(int button){ //check the fourth element of the newCode[] array
  digitalWrite(LED[button-1],HIGH);
  if (newCode[5] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    newCode[5] = button; //set the final element as the button that has been pressed
    Serial.print("New Code Input 6: ");Serial.println(newCode[5]);
    delay(100);
    codeChange(); //call the validation function
  }
}


