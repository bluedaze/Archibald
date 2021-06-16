![Alt Text](https://i.imgur.com/oFvHeAo.png)

### This parser was written by Sean Pedigo for the JPL internship.  
##### This is an easily extensible parser which sends signals over i2c.  
  
## Parts Used  

<img align="left" height="310" width="232" src="https://i.imgur.com/iFnLEYq.jpg">

Part | Link
------------ | -------------
Arduino Nano 33 BLE | https://bit.ly/3cN2Wfv  
Romeo V2 - a Robot Control Board with Motor Driver | https://bit.ly/35sbV1J  
JGA25-371 Geared Motor with Encoder | https://bit.ly/3xoWjbe  
Devastator Tank Mobile Robot Platform | https://bit.ly/3pZtqzQ  

## Commands 
##### Commands are written in a noun verb structure. ie noun: 'engine' verb: 'start'.  
<img align="left" height="303" width="180" src="https://i.imgur.com/ImjASxp.png">


Noun | Verb | Result
------------ | ------------- | -------------
engine | start | starts accelerating forward  
engine | stop | stops moving  
engine | left | turns left  
engine | right | turns right  
engine | reverse | reverses engines  

## In Development
##### Developers are working to extend the robot with the Jetson Nano, ROS, and LORA.
##### Coding incoming, ETA Unknown.

Part | Link
------------ | -------------
2.4G WIRELESS MODULE NRF24L01+PA | https://www.seeedstudio.com/2-4G-WIRELESS-MODULE-NRF24L01-PA.html
Jetson Nano | https://www.seeedstudio.com/NVIDIA-Jetson-Nano-Development-Kit-B01-p-4437.html
