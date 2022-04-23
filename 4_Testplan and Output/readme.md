# 1.1 HIGH LEVEL TEST PLAN

| Test ID | Description | Input | Expected output | Actual Output | Passed Or Not |
| --- | --- | --- | --- | --- | --- |
| 01 | Thermistor | Room Temperature(25°C) | Temperature(25°C) | Temperature(25°C) | ✅ |
| 01 | Thermistor | Room Temperature(35°C) | Temperature(35°C) | Temperature(35°C) | ✅ |
| 02 | Keypad | 1 | 1(Door Opens) | 1(Door Opens) | ✅ |
| 03 | Keypad | 2 | 2(Door Closes) | 2(Door Closes) | ✅ |
| 04 | Keypad | 3 | 3(Ligh1 On or Off) | 3(Light On or off) | ✅ |
| 05 | Keypad | 4 | 4(Ligh On or Off) | 4(Light On or off) | ✅ |
| 06 | Keypad | 5 | 5(Ligh On or Off) | 5(Light On or off) | ✅ |
| 07 | Keypad | 6 | 6(Fan On or Off) | 6(Fan On or off) | ✅ |
| 08 | Keypad | 7 | 7(Fan On or off) | 7(Fan On or off) | ✅ |
| 09 | Keypad | 8 | 8(Fan On or Off) | 8(Fan On or off) | ✅ |
| 08 | Keypad | * | * (No of Fan On and Light On) | * (No of Fan On and Light On) | ✅ |
| 09 | Keypad | 0 | 0 (Resets Password) | 0 (Resets Password) | ✅ |
| 10 | Keypad | # | # (Restarts our system) | * (Restarted our system) | ✅ |

### Here below are the some of the *unity test/ unity framework* test plans there are so many but I have only mentiones some of the test cases here.

# 1.2 LOW LEVEL TEST PLAN

| Test ID | Description | Input | Expected output | Actual Output | Passed Or Not |
| --- | --- | --- | --- | --- | --- |

| Test ID (for LCD)| Description | Input | Expected output | Actual Output | passed/not |
| --- | --- | --- | --- | --- | --- |
| 01 | Check for LCD_Char() | A  | A |  A | ✅ |
| 02 | Check for LCD_String() | Manjunadh | Manjunadh | Manjunadh | ✅ |
| 03 | Check for LCD_String() | Home | Home | Home | ✅ |


| Test ID (for ADC)| Description | Input | Expected output | Actual Output | passed/not |
| --- | --- | --- | --- | --- | --- |
| 01 | Check for ADC_Read() | 0V | 0 | 0 | ✅ |
| 02 | Check for ADC_Read() | 5V | 1023 |  1023 | ✅ |

| Test ID (for mapping, map)| Description | Input | Expected output | Actual Output | passed/not |
| --- | --- | --- | --- | --- | --- |
| 01 | Check for map() | map(20, 492, 478, 20, 35) | 525 |  525 | ✅ |
| 02 | Check for map() | map(25, 492, 478, 20, 35) | 520 |  520 | ✅ |
| 03 | Check for map() | map(30, 492, 478, 20, 35) | 515 |  515 | ✅ |
| 04 | Check for map() | map(35, 492, 478, 20, 35) | 509 |  509 | ✅ |
---
