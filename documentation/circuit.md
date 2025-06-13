# Electrical Circuit

This document holds the circuit layout with version history and used microcontroller pins documentation.

- [Current Version](#current-circuit-diagram)
- [Version history](#version-history)
- [Pins](#components-and-pins)

## Current Circuit Diagram

**Main features:** microcontroller, speaker, compass, distance sensor are powered by 4S battery pack (6V) through a stepdown converter; Motors are powered with 2S LiPo batteries (7.4V) with implemented AD conversion for voltage tracking from one of the batteries. Both power sources are additionally protected with fuses - 400mA and slow 800mA repectively, - and are controlled with DPDT toggle switch.

Remarks:
- Only bridge the ground, power rows MUST NOT be bridged
- Due to the limited functionality of the tool, on diagram ground wires are colored blue, while the real life wires are black

![Circuit Diagram](/documentation/images/circuit_image_v5.svg)
*Link to the project: https://app.cirkitdesigner.com/project/20f3ba8c-a90e-4b3a-8cf0-a0710fcb53cf*


## Version history

### Version 1: 
First rough draft only with initial components: microcontroller, compass, speaker module, distance sensor, servo motors and LiPo batteries connected in 2S.
![V1](/documentation/images/circuit_image_v1.svg)

<br>

### Version 2:
Addition of second power source, intially planned 3S AA battery pack (4.8V), and two SPST (single pole single throw) toggle switches for both power circuits.
![V2](/documentation/images/circuit_image_v2.svg)

<br>

### Version 3:
Move to the half breadboard, change of the second power source to 4S AA battery pack (6V) due to availability and, as microcontroller accepts only 5V input, addition of step-down converter. Change of singular toggle switches to DPDT (double pole double throw), as well as addition of two LEDs with PWM control.
![V3](/documentation/images/circuit_image_v3.svg)

<br>

### Version 4:
Addition of the AD conversion from one of the LiPo batteries (3.7V) with usage of voltage divider (2 resistors).
![V4](/documentation/images/circuit_image_v4.svg)

<br>

### Version 5 (Final):
Addition of two fuses for both power sources for additional safety measures.
![V5](/documentation/images/circuit_image_v5.svg)

<br>


## Components and pins:
Currently free GPIO pins: 26, 0, 4, 25, 36, 39, 35


<br>

Speaker [MP3](/documentation/datasheets/speaker-datasheet.pdf)

| Module Pin | Wire color | Controller Pin |        
|:----------:|:----------:|:--------------:|   
| GND | Black | Ground row |
| VCC | White* | 5V row |
| TX | Grey | 19 |
| RX | Purple | 23 |

'*' - on diagram marked as red

<br>
<br>

Distance Sensor [HC-SR04](/documentation/datasheets/distance-datasheets.pdf)
| Module Pin | Wire color | Controller Pin |
|:----------:|:----------:|:--------------:|
| VCC | Red | 5V row |
| Trig | Pink | 13 |
| Echo | Green | 15 |
| GND | Black | Ground row |

<br>
<br>

Compass [CMPS2](/documentation/datasheets/compass-datasheet.pdf)

| Module Pin | Wire color | Controller Pin |
|:----------:|:----------:|:--------------:|
| VCC | Red | 3.3V |
| GND | Black | Ground row |
| SCL | Green | 22 |
| SDA | Pink | 21 |

<br>
<br>

 Servo Motors [Parallax](/documentation/datasheets/motor-datasheets.pdf) 
| Module Pin | Wire color | Controller Pin |
|:----------:|:----------:|:--------------:|
| GND | Black | Ground row |
| VCC | Red | 7.4V row |
| Pulse | White | 14 and 12 |

<br>
<br>

Red LEDs
| Module Pin | Wire color | Controller Pin |
|:----------:|:----------:|:--------------:|
| Cathnode | Black | Ground row* |
| Anode | Red - Orange | 2 |

'*' - through 220 ohm resistor

<br>
<br>

**AD conversion** takes pin 34 and requires 47K ohm (ground) and 12K ohm (in between) resistors.
