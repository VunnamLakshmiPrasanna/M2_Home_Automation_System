# 1 Block Diagram and Blocks explination
## 1.1 BLOCK DIAGRAM
![csmicrowaveoven drawio (1)](https://user-images.githubusercontent.com/94365143/155744126-970fa92c-6787-4c1e-af1d-46a8aad3d82f.png)
## 1.2 SENSORS
* ### Temperature Sensor (Thermistor)
    * This Thermistor is a resistor whose resistance is dependent on temperature here this change in resistence produces change in voltage, this voltage is taken as input to micro controller.
* ### Keypad:
    *  Provides an interface to press a number which helps in controlling Fan,Light and Doors of our house.
* ### Front Stop Switch(MicroSwitch):
    * Stops the door automatically by pressing switch itself when door is completely opened.
* ### Back Stop Switch(MicroSwitch):
    * Stops the door automatically by pressing switch itself when door is completely opened. 

## 1.3 ACTUATORS
* ### LCD Display:
    * Displays each and every value we enter in our keypad along with Temperature.
* ### Light:
    * Lightning inside the room is controlled by light.
* ### Fan:
    * Temperature inside room is controlled by fan.
* ### Motor:
    * Helps in opening and closing our doors.
    
## 1.4 MICRO CONTROLLER AND MEMORY
* ### EEPROM
    * Here this is actually inside the microcontroller
* ### Clock
    * Here we are using internal clock of our micro controller.
* ### MicroController:
    * This is the main component which controls all the above mentioned part or thins of our embedded system.This interfaces keypad and LCD and controlls the fan,light and doors depending on the value we pressed on keypad.
   
 ## 1.5 SUBSYSTEM & OTHERS
* ### Motor Driver Unit:
    * Helps in driving the motor for our door and fan by providing required power for them(we use motor driver L293). 
 ---
# 2 Architecture
* ## 2.1 Behavioural Diagram
    * ### 2.1.1 High Level Flow chart Behavioural Diagram
    ![Homeautomation drawio](https://user-images.githubusercontent.com/94365143/155739910-02eb973e-1fea-4e46-8f63-48e638b3feba.png)
    * ### 2.1.2 Low Level Flow chart Behavioural Diagram
    ![Homeautomationlow drawio (2)](https://user-images.githubusercontent.com/94365143/155739932-ad8d6c8a-44a6-4d26-9d3e-b6906c108c80.png)
* ## 2.2 Structural Diagram
    * ### 2.2.1 High Level UML Use Case Structural Diagram
    ![Homeautomationumlhigh drawio](https://user-images.githubusercontent.com/94365143/155739956-2e768765-460a-49b6-a80b-ecabe5c1a1cd.png)
    * ### 2.2.2 Low Level UML Use Case Structural Diagram
    ![Homeautomationumllow drawio (2)](https://user-images.githubusercontent.com/94365143/155742932-9ed19b51-e759-4085-9508-23bef2a91e94.png)

 ---
 
 # Best Methods Followed
* Exact Mapping of code to avoid confusions
* Mentioning of both High level and Low level Behavioral and structural diagrams for better understanding
* Followed the exact symbols to make the understanding easier
* Detailed explanation in Low level Behavioural and Structural Diagrams
