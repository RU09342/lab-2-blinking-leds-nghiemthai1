# Off Board Blink

## How does this work
The central processor of the MSP430G2 LaunchPad is taken out of its development tool and is put on a bread board.
With the program that was implemented on the chip previously, the 2 LEDs on the breadboard will blink at 2 different rates. 

## Explaination
'IMG_1426' is the schematic for the Off Board Blink project. 
It's made of a breadboard, wires, a 3V battery, MSP430G2553, and resistors. 
The 3V battery will supply enough power to the G2553. 
The negative terminal of the battery is connected to the VDD pin of the G2553 and the possitive terminal to the VCC pin. 
Two 1k registors are connected from the pins of the G2553 to the two LEDs to make sure the diode won't be over-powered. 
A 10k registor is also needed to connect the RST pin to the VCC pin of the G2553 to make sure the circuit won't reset all the time.

## How to implement this project
You going to need a breadboard, wires, a 3V battery, MSP430G2553, and resistors in order to implement this project.
Follow the schematic provided in 'IMG_1426' to build the circuit. 
Make sure you program your G2 chip with the provided project of "MSP430G2553".
After you connect the circuit to the battery, the 2 LEDs should blink at different rate. 