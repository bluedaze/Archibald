This parser was written by Sean Pedigo for the JPL internship. This is an easily extensible parser which sends signals over i2c.  
  
The following parts were used:  

Part | Link
------------ | -------------
Arduino Nano 33 BLE | https://store.arduino.cc/usa/nano-33-ble  
Romeo V2 - a Robot Control Board with Motor Driver | https://www.dfrobot.com/product-844.html  
JGA25-371 Geared Motor with Encoder | https://www.seeedstudio.com/JGA25-371-Geared-Motor-with-Encoder-p-4125.html  
Devastator Tank Mobile Robot Platform | https://www.dfrobot.com/product-1477.html  

Command | Result
------------ | -------------
engine start | start
engine stop | stop
engine left | left
engine right | right
engine reverse | reverse

There are currently plans to extend our robot further with a variety of parts, however the immediate future involve installing and using ROS on a jetson nano and using lora radios.

Part | Link
------------ | -------------
2.4G WIRELESS MODULE NRF24L01+PA | https://www.seeedstudio.com/2-4G-WIRELESS-MODULE-NRF24L01-PA.html
Jetson Nano | https://www.seeedstudio.com/NVIDIA-Jetson-Nano-Development-Kit-B01-p-4437.html

Commands are written in a noun verb structure. ie noun: 'engine' verb: 'start'.  
