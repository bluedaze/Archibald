![Alt Text](https://i.imgur.com/oFvHeAo.png)

## This parser was written by Sean Pedigo for the JPL internship. This is an easily extensible parser which sends signals over i2c.  
  
## The following parts were used:  

Part | Link
------------ | -------------
Arduino Nano 33 BLE | https://store.arduino.cc/usa/nano-33-ble  
Romeo V2 - a Robot Control Board with Motor Driver | https://www.dfrobot.com/product-844.html  
JGA25-371 Geared Motor with Encoder | https://www.seeedstudio.com/JGA25-371-Geared-Motor-with-Encoder-p-4125.html  
Devastator Tank Mobile Robot Platform | https://www.dfrobot.com/product-1477.html  

## Commands are written in a noun verb structure. ie noun: 'engine' verb: 'start'.  
<img align="right" width="100" height="100" src="https://i.imgur.com/BXurcEi.jpg">


Noun | Verb | Result
------------ | ------------- | -------------
engine | start | starts accelerating forward  
engine | stop | stops moving  
engine | left | turns left  
engine | right | turns right  
engine | reverse | reverses engines  

## Future Plans
#### Right now we are working with the Jetson Nano, ROS, and LORA.
#### Coding incoming, ETA Unknown.

Part | Link
------------ | -------------
2.4G WIRELESS MODULE NRF24L01+PA | https://www.seeedstudio.com/2-4G-WIRELESS-MODULE-NRF24L01-PA.html
Jetson Nano | https://www.seeedstudio.com/NVIDIA-Jetson-Nano-Development-Kit-B01-p-4437.html
