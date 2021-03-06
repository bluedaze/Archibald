                                   
# ᴀᴅᴠᴀɴᴄᴇᴅ sʏsᴛᴇᴍs ɢʀᴏᴜᴘ ᴘʀᴏᴊᴇᴄᴛ
          
### This parser was written by Sean Pedigo for the JPL internship.  
##### This is an easily extensible parser which receives signals over i2c.

This project involves interprocess communication using i2c. The parent module ( an Arduino 33 BLE) sends messages to a child module ( The Romeo v2 ) over i2c. The child module then tokenizes all of the words, and then the parser calls functions based upon relevent keywords. 

This parser is very similar to how a context free grammar specification would work in BNF. With this in mind, further development could allow one to start extending the parser to write a domain specific programming language which would allow a programmer to create algorithms that could be sent over the serial interface, stored in flash memory and executed later.
  
## Parts Used  

<img align="left" width="232" height="310" src="https://i.imgur.com/iFnLEYq.jpg">

<br/>
<br/>
<br/>

Part | Link
------------ | -------------
Arduino Nano 33 BLE | https://bit.ly/3cN2Wfv  
Romeo V2 - a Robot Control Board with Motor Driver | https://bit.ly/35sbV1J  
JGA25-371 Geared Motor with Encoder | https://bit.ly/3xoWjbe  
Devastator Tank Mobile Robot Platform | https://bit.ly/3pZtqzQ
  
<br/>
  
## Commands 
##### Commands are written in a noun verb structure. ie noun: 'engine' verb: 'start'.

<img align="right" height="178" width="406" src="https://i.imgur.com/ImjASxp.png">

Noun | Verb | Result
------------ | ------------- | -------------
engine | start | starts accelerating forward  
engine | stop | stops moving  
engine | left | turns left  
engine | right | turns right  
engine | reverse | reverses engines  

Part | Link
------------ | -------------
2.4G WIRELESS MODULE NRF24L01+PA | https://bit.ly/3wwHmUs  
Jetson Nano | https://bit.ly/3zxses4  

## DEMO
https://www.youtube.com/watch?v=QDIc7w09_gA


https://user-images.githubusercontent.com/35676690/122307989-702aa480-ced9-11eb-89ac-9a5e9215ba48.mp4

You can see it in operation here:

https://www.youtube.com/watch?v=96I0G4uKvU4

https://user-images.githubusercontent.com/35676690/150652650-5c2b606e-3f83-432c-b4bc-28c51e448029.mp4

###### Sadly I lost access to this shortly after the person I was working with at the university was transferred to another department. He took it with him as the parts belonged to him so I was not able to continue with it.

###### I was attempting a modular approach which became increasingly difficult as headers files made it very difficult to work with.

###### I added a radio and a controller to the project. You can dig more into the source code here:

Code | Link
------------ | -------------
receiver | https://github.com/bluedaze/Mortimer-Receiver  
transceiver  | https://github.com/bluedaze/Lennard-Dispatch  
controller | https://github.com/bluedaze/Roscoe-Input  
