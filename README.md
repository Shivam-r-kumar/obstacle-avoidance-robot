\# 🚗 Obstacle Avoidance Robot (Arduino)



This project is an \*\*Obstacle Avoidance Robot\*\* using \*\*Arduino\*\*, \*\*Ultrasonic Sensor (HC-SR04)\*\*, and \*\*Adafruit Motor Driver Shield (AFMotor Library)\*\*.  

The robot detects obstacles in front and automatically avoids them by reversing and turning.



---



\## 🧠 Working Logic

1\. Ultrasonic sensor continuously measures distance

2\. If distance < threshold (30 cm):

&nbsp;  - Robot stops

&nbsp;  - Moves backward

&nbsp;  - Turns left

3\. If no obstacle:

&nbsp;  - Robot moves forward



---



\## 🧰 Components Used

\- Arduino Uno

\- Adafruit Motor Driver Shield (L293D based)

\- DC Motors (4)

\- Ultrasonic Sensor (HC-SR04)

\- Robot chassis \& wheels

\- Battery / Power supply

\- Jumper wires



---



\## 🔌 Pin Configuration (As per Code)



\### 🔊 Ultrasonic Sensor (HC-SR04)

| Sensor Pin | Arduino Pin |

|-----------|-------------|

| VCC       | 5V          |

| GND       | GND         |

| TRIG      | A0          |

| ECHO      | A1          |



```cpp

\#define TRIG A0

\#define ECHO A1



