**UID Reader (Arduino RFID + LCD Project)**
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
♦ Overview ♦

This project is an Arduino-based RFID card reader that displays the UID (Unique Identifier) of scanned RFID cards on a 16x2 LCD screen. It uses an RFID RC522 module with SPI communication and a LiquidCrystal LCD to provide real-time feedback when a card is tapped.

♦ Hardware Requirements ♦

• Arduino Uno (or compatible board)

• RFID RC522 module

• 16x2 LCD display

• Jumper wires and breadboard

♦ Pin Connections ♦

• RFID Module → Arduino

  • SDA (SS) → Pin 10

  • RST → Pin 9

  • MOSI → Pin 11

  • MISO → Pin 12

  • SCK → Pin 13

  • VCC → 3.3V

  • GND → GND

• LCD → Arduino

  • RS → Pin 8

  • E → Pin 7

  • D4 → Pin 6
  
  • D5 → Pin 5
  
  • D6 → Pin 4
  
  • D7 → Pin 2
  
  • VCC → 5V
  
  • GND → GND

♦ Software Requirements ♦

• Arduino IDE

• LiquidCrystal library

• RFID library

• SPI library (built-in with Arduino IDE)

♦ How It Works ♦

1. On startup, the LCD displays a welcome message:
"Welcome!"
"Please tap card"

2. When a card is tapped, the system reads its UID.

3. The UID is displayed on the LCD for 3 seconds.

4. The system resets and waits for the next card.

♦ Files ♦

UID_Reader.ino → Main Arduino sketch
