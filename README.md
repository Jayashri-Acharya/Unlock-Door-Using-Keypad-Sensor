# IoT-Based Door Unlock System

An IoT-based smart door locking system developed using Arduino UNO, a 4x4 keypad, servo motor, and LCD display. The system provides secure access control by allowing users to unlock a door using a predefined password entered through the keypad.

## Features

- Password-based door access control
- 4-digit secure authentication
- LCD display for user interaction
- Servo motor-based door locking and unlocking
- Automatic door relocking after a specified delay
- Password masking using '*' characters
- Clear input functionality using keypad
- Low-cost and easy-to-deploy security solution

## Hardware Components

- Arduino UNO
- 4x4 Matrix Keypad
- Servo Motor
- 16x2 LCD Display with I2C Module
- Jumper Wires
- Breadboard
- Power Supply

## Software Requirements

- Arduino IDE
- Embedded C

### Libraries Used

- Keypad.h
- Servo.h
- Password.h
- LiquidCrystal_I2C.h

## Working

1. The system initializes and prompts the user to enter a password.
2. The user enters a 4-digit password using the keypad.
3. The entered digits are masked on the LCD display.
4. The microcontroller compares the entered password with the stored password.
5. If the password is correct:
   - The servo motor unlocks the door.
   - LCD displays "Correct Password" and "Door Unlocked".
   - After a few seconds, the door automatically locks again.
6. If the password is incorrect:
   - LCD displays "Wrong Password".
   - Access is denied.
7. The user can clear the input and try again.

## Project Structure

```text
IOT_Door_Unlock_System/
├── Arduino_Code.ino
├── circuit_diagram.png
├── project_report.pdf
├── images/
│   └── final_model.jpg
└── README.md
```

## Applications

- Smart Home Security
- Office Access Control
- Laboratories and Restricted Areas
- Hotel Room Access Systems
- Educational IoT Projects

## Benefits

- Eliminates the need for physical keys
- Cost-effective security solution
- Easy password modification
- Compact and portable design
- Can be enhanced with Wi-Fi, GSM, RFID, or biometric authentication

## Future Enhancements

- Mobile App Integration
- Wi-Fi-Based Remote Unlocking
- OTP Verification
- RFID Authentication
- Fingerprint Sensor Integration
- Email/SMS Alert Notifications
- Access Log Management

## Technologies Used

- Arduino UNO
- Embedded C
- IoT Concepts
- Keypad Interface
- Servo Motor Control
- LCD Display Interface

## Author

Jayashri Acharya
Bachelor of Computer Applications (BCA)
Trisha Vidya College of Commerce and Management
