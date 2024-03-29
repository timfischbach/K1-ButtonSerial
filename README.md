# K1-ButtonSerial
This project is a lazy attempt to simulate button presses to a Creality K1 (Max) mainboard. This code works on all Arduino boards.

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/X7X3UJC3Q)

![20240222_200101](https://github.com/timfischbach/K1-ButtonSerial/assets/59933715/3adc5839-b8d2-4edf-89e0-44a23ef52615)
## How does it work?
Most MCUs check their Button Pins for high or low voltage levels (mostly combined with input pullup resistors) to detect button presses.
I connected an Arduino Uno R3 to the button testpoints of the K1 mainboard to simulate those high and low levels of voltages.
Interestingly, the Arduino Pin is floating, when defined as Input via pinMode(). That's ideal for our simulation, so the button gpios of the K1 Board are not exposed to voltages and thus minimizing possible interferrences and damages.
The reset button triggers when a low voltage is applied (GND) and the boot button triggers at a high voltage.
The Arduino receives via serial the user input and correspondingly executes certain button combos, to achieve the user interaction on the mainboard remotely.
## Wiring
Solder some wires to the red marked Testpoints (located under the buttons of the board) and connect those to the Arduino correspondingly to the provided layout.
IMPORTANT: Ground connection (green marked) is only necessary, if the K1 mainboard is not connected to the same PC as the Arduino!

![20240222_200029](https://github.com/timfischbach/K1-ButtonSerial/assets/59933715/f88ce5b3-b03a-4254-b426-e8ba6a85b61e)
![Screenshot 2024-02-22 201719](https://github.com/timfischbach/K1-ButtonSerial/assets/59933715/cfecf358-95ac-4efb-a315-d61c7f248483)
## Upload the program to the Arduino
- Open the project file of your liking (For beginners, use the .ino file, which works with Arduino IDE)
- Set up the upload settings
- Upload the code to the Arduino
- The Arduino is now ready to use. Connect it now to the PC of your liking
## Connect to the Arduino via serial
Open the Arduino serial port with any program of your liking. The baud rate is 9600 baud.
After that, you should see a menu, like shown in the picture. 
If you press r, the K1 board gets reset.
If you press b, the K1 board gets reset and set into boot mode.

![Screenshot 2024-02-22 202820](https://github.com/timfischbach/K1-ButtonSerial/assets/59933715/60431af9-9585-4144-a5cf-724a5e6bbf26)
## Happy Hacking :)
