# arduinoTheremin

A theremin is a musical instrument that you play without touching. It has two sensors, both of which track how far an object (typically a human hand) is from the sensor. One sensor controls the pitch of the output signal, and the other controls its volume. 

My build uses 2 HC-SR04 ultrasonic sensors as the inputs and 1 piezoelectric buzzer to produce the output signal. 

The biggest challenge I faced was probably figuring out a way to control the volume with the HC-SR04 sensor. I figured I would have to use a digital potentiometer and model a relationship between the distance and input signal, so that I could perform an analogWrite() command to the buzzer, but I did not have access to a digipot. Instead, after doing some digging, I found a library that modified the tone() function in a way that allowed users to change the volume of the output signal digitally, which was pretty simple to model using the distance sensor. 
