#include <LiquidCrystal.h>
#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10 //SS_PIN is defined as a constant with value 10
#define RST_PIN 9 //RST_PIN is defined as a constant with value 9
RFID rfid(SS_PIN, RST_PIN); //An instance of the RFID class is initialized with the SS_PIN and RST_PIN constants
String rfidCard; //Variable rfidCard is declares as a string
LiquidCrystal lcd(8, 7, 6, 5, 4, 2); //An instance of the LiquidCrystal class is initialized with pin numbers 8, 7, 6, 5, 4, 
//These pins are used to communicate with the LCD.
void setup() {
  //Initializing the LCD display
  lcd.begin(16, 2);
  lcd.clear(); //This command clears the LCD screen
  lcd.setCursor(4, 0); //This command sets the cursor in column 4, row 0
  lcd.print("Welcome!"); //This command displays "Welcome!" on the LCD screen
  lcd.setCursor(0, 1); //This command sets the cursor in column 0, row 1
  lcd.print("Please tap card"); //This command displays "Please tap card" on the LCD screen
  SPI.begin(); //Initializing the SPI bus 
  rfid.init(); //Initializing the RFID reader
}
void loop() {
  if (rfid.isCard()) { //This method checks if an RFID card/tag is present
    if (rfid.readCardSerial()) { //This method reads the serial number of the card/tag
      lcd.clear(); //The LCD is cleared
      //The serial number is converted to a String and stored to rfidCard variable
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      lcd.setCursor(0, 0); //This command sets the cursor in column 0, row 0
      lcd.print("Card UID is:"); //This command displays "Card UID is:" on the LCD screen
      lcd.setCursor(0, 1); //This command sets the cursor in column 0, row 1
      lcd.print(rfidCard); //This command displays card/tag UID on the LCD screen
      delay(3000); //The program waits 3 seconds before clearing the screen again
    }
    rfid.halt(); //This method stops the communication with the card
  }
  setup(); //Reset the program and start again
}