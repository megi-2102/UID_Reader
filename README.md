**RFID Arduino Project**
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
♦ Overview ♦

This repository contains two Arduino-based RFID projects:

1. UID Reader – reads RFID card UIDs and displays them on a 16x2 LCD.

2. Door Access Simulation – reads RFID cards, compares them to an authorized ID, and controls a servo to simulate a door lock/unlock system.

Both projects use an RFID RC522 module (or MFRC522), SPI communication, and a LiquidCrystal LCD.

♦ Hardware Requirements ♦

• Arduino Uno (or compatible board)
    
• RFID RC522 or MFRC522 module
    
• 16x2 LCD display
    
• Servo motor (for door access project)
    
• Jumper wires and breadboard

♦ Pin Connections ♦

RFID Module → Arduino

    • SDA (SS) → Pin 10
  
    • RST → Pin 9
  
    • MOSI → Pin 11
  
    • MISO → Pin 12
  
    • SCK → Pin 13
  
    • VCC → 3.3V
  
    • GND → GND

LCD → Arduino

    • RS → Pin 8
  
    • E → Pin 7
  
    • D4 → Pin 6
    
    • D5 → Pin 5
    
    • D6 → Pin 4
    
    • D7 → Pin 2
    
    • VCC → 5V
    
    • GND → GND
    
Servo (Door Access Project Only)

    • Signal → Pin 3
    
    • VCC → 5V
    
    • GND → GND

♦ Software Requirements ♦

• Arduino IDE

• LiquidCrystal library

• MFRC522/RFID library

• Servo library (built-in with Arduino IDE)

• SPI library (built-in with Arduino IDE)

♦ Projects ♦

1. UID_Reader.ino

    • Displays the UID of a scanned RFID card on the LCD

    • Shows a welcome message on startup:

        Welcome!
        Please tap card

   • Displays the card UID for 3 seconds, then resets for the next scan

2. UID_Reader.ino

    • Simulates a door access system using a servo motor.
    
    • Compares the scanned RFID card UID to a predefined authorized UID.
    
    • If the card matches:

        • Displays “Door unlocked!” on the LCD
        
        • Moves the servo to 90° (unlock position) for 3 seconds
        
        • Resets the system

    • If the card does not match:
    
    • Displays “Access denied!” for 3 seconds
    
    • Resets the system

♦ How It Works ♦

1. On startup, the LCD displays a welcome message.

2. When an RFID card is tapped, the system reads its UID.

3. Depending on the project:

    • UID Reader → Displays the UID on the LCD.
    
    • Door Access → Checks if the UID matches the authorized tag, then unlocks or denies access.

4. After a delay, the system resets and waits for the next scan.

♦ Future Improvements ♦

• Add buzzer or LED feedback for card scans.

• Store multiple authorized UIDs for the door access system.

• Log scanned UIDs to an SD card or send them over Serial/WiFi.
   
♦ Files ♦

• UID_Reader.ino → Main UID display sketch
• RFID_DoorAccess.ino → Door access simulation sketch
