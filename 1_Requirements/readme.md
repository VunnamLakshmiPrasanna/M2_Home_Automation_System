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
| LLR1.2 | According to the values of __Keypad__ opening,closing of doors shall be controlled || LLR2.2 | Number of Lights and Fans On __LCD__ Screen |
     
| ID | Low Level Requirements for HL3|  |ID | Low Level Requirements for HL4|
| -------- | -------------- | ---- | -------- | -------------- |
| LLR3.1 |  Device shall open when the __Password__ is matched | | LLR4.1 | __Temperature Sensor__ shall detect the room temperature |
| LLR3.2 | Device shall ask to Re-Enter the __Password__ again if entered one is wrong || LLR4.2 | The temperature detected by  __Temperature Sensor__ shall be printed on LCD Screen |
