# Smart_Home
## This software will be a Smart Home Control System that contains sub systems such as:
### 1- Fire Alarm System
#### This use case should read temperature from temperature sensor if it low than 50 c will display “Fine” and update temperature on lcd. if the temperature increases to above 50 c with 10% hysteresis display ” Heat” and turn on alarm led present on  “yellow led” and read smoke sensor if above 40% turn on fire led present on “red led” and turn on “buzzer “ and display “Fire”.
#### NOTE : The temp reversible with 10% hysteresis and smoke unreversible
#### state machine  for fire alarm system ![image](https://github.com/EL-Gohary1/Smart_Home/assets/135604535/57a6d89a-3a11-4c04-b8df-b089d8812faf)
### 2- Control system on LEDS, Window by servo motor and LCD 
#### Receive specific commands from owner by UART communication protocol by through Bluetooth module to turn on or off 4 Ledes by send command like “LEDON 1#” or “LEDOFF 2#” to “LEDON 3#” or Control on window by servo motor by send command like “SERVO 45#” the degree from 0 to 180. or Display number on lcd by send command “LCD 679#”
#### NOTE : The command must end by '#'
### 3- Smart light Control system.
#### Wait to Take threshold of brightness from user and compare it with the actual brightness to turn on or off blue led 
#### NOTE : to Efit threshold press on 'c' button 
### This system will be designed to maximize the comfortable living For More Information about the SRS should be Explained On DOC Folder
