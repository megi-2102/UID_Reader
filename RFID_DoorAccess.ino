#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
//Defines the pins used for the RFID reader
#define SS_PIN 10
#define RST_PIN 9
Servo lockServo; //Creates an instance of the servo motor
//Creates an instance of the RFID reader and LCD display
MFRC522 rfid(SS_PIN, RST_PIN); 
LiquidCrystal lcd(8, 7, 6, 5, 4, 2); 
//Define the ID of the RFID tag that can unlock the door
byte tagID[] = {0x1A, 0x54, 0x0A, 0xB0}; 

void setup() {
  lcd.begin(16, 2); //Initializing the LCD display
  lcd.print("Door locked!"); //Prints message "Door locked!" on the LCD
  lockServo.write(0); //Moves the servo to position 0 degrees (lock position)
  delay(2000); //Waits 2 seconds 
  lcd.clear(); //Clears the LCD screen
 //Initializing the servo motor attached to pin 3 of the Arduino
  lockServo.attach(3); 
  //Initializing the SPI bus and RFID reader
  SPI.begin();
  rfid.PCD_Init();
  
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("Please tap card");
}

void loop() {
  //Checks if a card is present
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    //Gets the ID of the card
    byte* cardID = rfid.uid.uidByte;
   
    boolean granted = false; //Sets the access to false by default
    // Compares the ID of the card to the ID of the authorized tag
    if (memcmp(cardID, tagID, 4) == 0) {
      granted = true; //Grants access
      //Prints message "Door unlocked!" on the LCD screen
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Door unlocked!");
        //Moves the servo position at 90 degrees (unlock position)
        lockServo.write(90);
        delay(3000); //Staying unlocked for 3 seconds
        lcd.clear(); //Clears the LCD screen
        setup(); //Resets the program
      }
     
  else if(granted == false) 
     {
       //If the ID doesn't match, deny access
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Access denied!");
      delay(3000); //3 seconds delay
      setup(); //Resets the program
    }
  delay(1000); //1 second dealy 
}
}
