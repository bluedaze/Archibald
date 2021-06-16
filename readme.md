This parser was written by Sean Pedigo for the JPL internship. This is an easily extensible parser which sends signals over i2c.  
  
The following parts were used:  
  
Arduino Nano 33 BLE: https://store.arduino.cc/usa/nano-33-ble  
Romeo V2 - a Robot Control Board with Motor Driver: https://www.dfrobot.com/product-844.html  
JGA25-371 Geared Motor with Encoder: https://www.seeedstudio.com/JGA25-371-Geared-Motor-with-Encoder-p-4125.html  
Devastator Tank Mobile Robot Platform: https://www.dfrobot.com/product-1477.html  

There are currently plans to extend our robot further using lora radios.  

The part we have started working with for this is the following:  
2.4G WIRELESS MODULE NRF24L01+PA: https://www.seeedstudio.com/2-4G-WIRELESS-MODULE-NRF24L01-PA.html  

Commands are written in a noun verb structure. ie noun: 'engine' verb: 'start'.  
First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column