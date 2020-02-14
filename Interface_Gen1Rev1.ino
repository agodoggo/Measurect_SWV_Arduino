//Code Written by Aditi Pilani, Agoston Walter, Alexis Onsi, and Rhianne Hsu for BME 464 Design Project Measurect

//************************GLOBAL VARIABLES USED************** 

//*********************************************************************

#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <EEPROM.h>
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();



void setup() {
  //  initialization
  
  //  Sets up pins and Serial
  //  Serial.begin(9600);

  //  Sets up LCD screen
  lcd.setCursor(0,0);
  lcd.begin(16,2);
}

//**********Loop is controlled by 5 buttons, which call on different functions*******

void loop() { 
  main:
  uint8_t buttons = lcd.readButtons();
  if(buttons){
    lcd.setCursor(0,0);
    // LEFT BUTTON TRIGGERS INSPIRATORY/EXPIRATORY CAP. MEASUREMENTS
    // If Right button is pressed after left button, respirometer enters expiratory cap. mode
    // If after 1 second,  no left button is pressed, respirometer continues with inspiratory cap. mode
    if(buttons & BUTTON_LEFT){
      Start_Measurements();
    }
    
    //RIGHT BUTTON PAUSES/PLAYS MEASUREMENTS
    if(buttons & BUTTON_RIGHT){
      Pause_Play();
    }

    //UP BUTTON STOPS MEASUREMENTS
    if(buttons & BUTTON_UP){
      Stop_Measurements();
    }

    //DOWN BUTTON TRIGGERS CALIBRATION MODE
    if(buttons & BUTTON_DOWN){
      calibrate();
    }
    //SELECT BUTTON CHANGES PNEUMOTECH 
//    if(buttons & BUTTON_SELECT){
//      //Selection Mode
//      changePtech();
//    }

      
  }
}

//************************************FUNCTIONS USED************************************

void Start_Measurements(){
  lcd.clear();
  lcd.print("Start");
  lcd.setCursor(0,1);
  lcd.print("Measurement");
  delay(2000);
  lcd.clear();
//  goto main;
}

void Pause_Play(){
  lcd.clear();
  lcd.print("Pause");
  lcd.setCursor(0,1);
  lcd.print("Play");
  delay(2000);
  lcd.clear();
//  goto main;
}
void Stop_Measurements(){
  lcd.clear();
  lcd.print("Stopping");
  lcd.setCursor(0,1);
  lcd.print("Measurement");
  delay(2000);
  lcd.clear();
//  goto main;
}
void calibrate(){
  lcd.clear();
  lcd.print("Calibrate");
  lcd.setCursor(0,1);
  lcd.print("Selected");
  delay(2000);
  lcd.clear();
//  goto main;
}
