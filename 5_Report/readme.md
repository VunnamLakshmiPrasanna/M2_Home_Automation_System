 # Home Automation System with Keypad Interface (H.A.S.K.I)
 ## Refer Report.docx or Report.pdf for the Report

<!-- 
---
# Table of content
1. About the H.A.S.K.I
    1. Description
    1. Identifying features
    1. State of art
    1. 5W's & 1H and S.W.O.T analysis
1. Requirements
    1. High level requirements
    1. Low level requirements
1. Block Diagram and Blocks explination
    1. Block Diagram
    1. Sensors
    1. Actuators
    1. Micro controller and memory
    1. Sub-system and others
 1. Architecture
    1. Behavioural Diagram
        1. High Level Flow chart Behavioural Diagram
        1. Low Level Flow chart Behavioural Diagram
    1. Structural Diagram
        1. High Level UML Use Case Structural Diagram
        1. Low Level UML Use Case Structural Diagram
1. Test plan and Output
    1. High level test plan
    1. Low level test plan
1. Application

---
# 1 About the H.A.S.K.I
## 1.1 Description
* This project is an Home Automation System with Keypad Interface (H.A.S.K.I). This system helps to control Light, Fans and Doors of our house. There is a keypad present which enables a feature on pressing each number. For example if we press 1 then it opens our maindoor and if we press 2 it closes our main door.There are several features such as fixing a password to our system and even temperature is displayed on our LCD.   
---
## 1.2 Identifying features
* Keypad shall be provided to ease the access of available features.
* Automatic door opening and closing shall be provided along with automatic stop switches to stop once opened completely.
* LCD Display shall be provided to know the option we press.
* Room Temperature shall be displayed on LCD.
* Number of Fans and lights on or off shall be displayed on LCD.
* Security lock is provided to unlock the system.
---
## 1.3 State of art
* The main focus of this project is to control Doors,Fans and Lights through a remote. A security code shall be fixed which ensures security to our house even when remote is misplaced. A LCD screen can be seen which displays the option we enter and also the present status of number of Lights and Fans on or off can be seen. By combining all these features a final product is made known as H.A.S.K.I. As the technology is increasing rapidly these kind of automations are very useful in our daily lives.
---
 ## 1.4 5W's 1H
![5w1h-questions-and-answer (2)](https://user-images.githubusercontent.com/94365143/154832159-976b2ffb-0ea9-4f5c-9d91-a3252c811f75.png)
## Swot Analysis
![image](https://user-images.githubusercontent.com/94365143/154832952-fa8c759f-44fd-47b2-9c2e-6c8b3ba21813.png)

---
# 2 Requirements
## 2.1 High Level Requirements
| ID | High Level Requirements |
| -------- | -------------- |
| HLR1 | System shall control Fan,Light,Doors by pressing a number on Keypad |
| HLR2 | There shall be a LCD to display the numbers we press |
| HLR3 | A password shall be provided for our system |
| HLR4 | System shall detect temperaure |

## 2.2 Low Level Requirements

| ID | Low Level Requirements for HL1|       |ID | Low Level Requirements for HL2|
| -------- | -------------- | ---- |-------- | -------------- |
| LLR1.1 |  According to the values of __Keypad__  Fan,Light shall be controlled | | LLR2.1 | Entered value on keypad shall be displayed on __LCD__ Screen |
| LLR1.2 | According to the values of __Kaypad__ opening,closing of doors shall be controlled || LLR2.2 | Number of Lights and Fans On __LCD__ Screen |
     
| ID | Low Level Requirements for HL3|  |ID | Low Level Requirements for HL4|
| -------- | -------------- | ---- | -------- | -------------- |
| LLR3.1 |  Device shall open when the __Password__ is matched | | LLR4.1 | __Temperature Sensor__ shall detect the room temperature |
| LLR3.2 | Device shall ask to Re-Enter the __Password__ again if entered one is wrong || LLR4.2 | The temperature detected by  __Temperature Sensor__ shall be printed on LCD Screen |
---

# 3 Block Diagram and Blocks explination
## 3.1 BLOCK DIAGRAM
![csmicrowaveoven drawio (1)](https://user-images.githubusercontent.com/94365143/155744126-970fa92c-6787-4c1e-af1d-46a8aad3d82f.png)
## 3.2 SENSORS
* ### Temperature Sensor (Thermistor)
    * This Thermistor is a resistor whose resistance is dependent on temperature here this change in resistence produces change in voltage, this voltage is taken as input to micro controller.
* ### Keypad:
    *  Provides an interface to press a number which helps in controlling Fan,Light and Doors of our house.
* ### Front Stop Switch(MicroSwitch):
    * Stops the door automatically by pressing switch itself when door is completely opened.
* ### Back Stop Switch(MicroSwitch):
    * Stops the door automatically by pressing switch itself when door is completely opened. 

## 3.3 ACTUATORS
* ### LCD Display:
    * Displays each and every value we enter in our keypad along with Temperature.
* ### Light:
    * Lightning inside the room is controlled by light.
* ### Fan:
    * Temperature inside room is controlled by fan.
* ### Motor:
    * Helps in opening and closing our doors.
    
## 3.4 MICRO CONTROLLER AND MEMORY
* ### EEPROM
    * Here this is actually inside the microcontroller
* ### Clock
    * Here we are using internal clock of our micro controller.
* ### MicroController:
    * This is the main component which controls all the above mentioned part or thins of our embedded system.This interfaces keypad and LCD and controlls the fan,light and doors depending on the value we pressed on keypad.
   
 ## 3.5 SUBSYSTEM & OTHERS
* ### Motor Driver Unit:
    * Helps in driving the motor for our door and fan by providing required power for them(we use motor driver L293). 
 ---
# 4 Architecture
* ## 4.1 Behavioural Diagram
    * ### 4.1.1 High Level Flow chart Behavioural Diagram
    ![Homeautomation drawio](https://user-images.githubusercontent.com/94365143/155739910-02eb973e-1fea-4e46-8f63-48e638b3feba.png)
    * ### 4.1.2 Low Level Flow chart Behavioural Diagram
    ![Homeautomationlow drawio (2)](https://user-images.githubusercontent.com/94365143/155739932-ad8d6c8a-44a6-4d26-9d3e-b6906c108c80.png)
* ## 4.2 Structural Diagram
    * ### 4.2.1 High Level UML Use Case Structural Diagram
    ![Homeautomationumlhigh drawio](https://user-images.githubusercontent.com/94365143/155739956-2e768765-460a-49b6-a80b-ecabe5c1a1cd.png)
    * ### 4.2.2 Low Level UML Use Case Structural Diagram
    ![Homeautomationumllow drawio (2)](https://user-images.githubusercontent.com/94365143/155742932-9ed19b51-e759-4085-9508-23bef2a91e94.png)

 ---

# 5 Test plan and output

# 5.1 HIGH LEVEL TEST PLAN

| Test ID | Description | Input | Expected output | Actual Output | Passed Or Not |
| --- | --- | --- | --- | --- | --- |
| 01 | Thermistor | Room Temperature(25Â°C) | Temperature(25Â°C) | Temperature(25Â°C) | To be Done |
| 01 | Thermistor | Room Temperature(35Â°C) | Temperature(35Â°C) | Temperature(35Â°C) | To be Done |
| 02 | Keypad | 1 | 1(Door Opens) | 1(Door Opens) | To be Done |
| 03 | Keypad | 2 | 2(Door Closes) | 2(Door Closes) | To be Done |
| 04 | Keypad | 3 | 3(Ligh On) | 3(Ligh On) | To be Done |
| 05 | Keypad | 3 | 3(Light Off) | 3(Light Off) | To be Done |
| 06 | Keypad | 4 | 4(Fan On) | 4(Fan On) | To be Done |
| 07 | Keypad | 4 | 4(Fan Off) | 4(Fan Off) | To be Done |
| 08 | Keypad | * | * (No of Fan On and Light On) | * (No of Fan On and Light On) | To be Done |
| 09 | Keypad | # | # (Restarts our system) | * (Restarted our system) | To be Done |

### Here below are the some of the *unity test/ unity framework* test plans there are so many but I have only mentiones some of the test cases here.

# 5.2 LOW LEVEL TEST PLAN

| Test ID | Description | Input | Expected output | Actual Output | Passed Or Not |
| --- | --- | --- | --- | --- | --- |

| Test ID (for LCD)| Description | Input | Expected output | Actual Output | passed/not |
| --- | --- | --- | --- | --- | --- |
| 01 | Check for LCD_Char() | A  | A |  A | To be done |
| 02 | Check for LCD_String() | Manjunadh | Manjunadh | Manjunadh | To be done |
| 03 | Check for LCD_String() | Home | Home | Home | To be done |


| Test ID (for ADC)| Description | Input | Expected output | Actual Output | passed/not |
| --- | --- | --- | --- | --- | --- |
| 01 | Check for ADC_Read() | To be done | To be done |  To be done | To be done |
| 02 | Check for ADC_Read() | To be done | To be done |  To be done | To be done |

| Test ID (for mapping, map)| Description | Input | Expected output | Actual Output | passed/not |
| --- | --- | --- | --- | --- | --- |
| 01 | Check for map() | To be done | To be done |  To be done | To be done |
| 02 | Check for map() | To be done | To be done |  To be done | To be done |
| 03 | Check for map() | To be done | To be done |  To be done | To be done |
---
# 6 Application
* This system can be used in Automation of Houses,Industries,Stadiums etc...
* This system can be used in Light Control of Houses,Industries,Stadiums etc...
* This system can be used in Fan Control of Houses,Industries,Stadiums etc...
* This system can be used in Door Control of Houses,Industries,Stadiums etc...
* This system can be used in Automatic Temperature Detector of Houses,Industries,Stadiums etc...
* This system can be used to know number of appliances "On" status of Houses,Industries,Stadiums etc... 
---

 -->

