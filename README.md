# Ultrasonic-sensor-interfacing-with-stm32
# Description of sensor HC-SR-04:
Ultrasound is high-pitched sound waves with frequencies higher than the audible limit of human hearing.
It works by sending out a sound wave at ultrasonic frequency and waits for it to bounce back from the object.
The HC-SR04 is a typical ultrasonic sensor which is used in many projects such as obstacle detector and electronic distance measurement tapes.

# Range:
The sensor is small, easy to use in any robotics project and offers excellent non-contact range detection between 2 cm to 400 cm (that’s about an inch to 13 feet) 
with an accuracy of 3mm. Since it operates on 5 volts, it can be hooked directly to an STM32 or any other 5V logic microcontrollers.

# working
It all starts, when a pulse of at least 10 µS (10 microseconds) in duration is applied to the Trigger pin.
In response to that the sensor transmits a sonic burst of eight pulses at 40 KHz. 
This 8-pulse pattern makes the “ultrasonic signature” from the device unique,
allowing the receiver to differentiate the transmitted pattern from the ambient ultrasonic noise.
The eight ultrasonic pulses travel through the air away from the transmitter.
Meanwhile the Echo pin goes HIGH to start forming the beginning of the echo-back signal.

# project:
This project uses input capturing of Timer3 which measures width of the Pulse from Echo pin using Timer interrupt
we will capture Rising edge time,falling edge of the pulse using the INPUT capture of Timer3 in ISR

# formula :
calculate the range through the time interval between sending trigger signal and
receiving echo signal. 
Formula: uS / 58 = centimeters or uS / 148 =inch; or: 
The range = high level time * velocity (340M/S) /2 

# working gif link below
![image](https://user-images.githubusercontent.com/64159350/126761905-2ac87811-cc30-42bc-a39d-2d42071474e7.gif)
![image](https://user-images.githubusercontent.com/64159350/126761997-3379ef61-f4c4-4780-801a-db98af22e771.gif)
