## Required Hardware

**Controller**
1. Arduino Mega or Due
1. 20 - 25 NPN transistors
1. a LOT of jumper wires. long, medium, short, M-M, M-F, color coded
1. a PCB
1. 20 - 25 resistors w/ 2.2k Ohms(Due only)
1. a breadborad(Due only)

**Display**

1. Arduino UNO WiFi Rev.2, NANO 33 IoT, MKR 1010, MKR VIDOR 4000 WiFi for Web Client
1. Arduino NANO 33 IoT for WebSocket Server
1. More jumper wires. long, M-M, M-F, color coded
1. 2 - 4 bread boards
1. 20 - 25 resistors w/ 2.2k Ohms(If your using the Due for the Controller)

## Required libraries

- [WifiNINA](https://www.arduino.cc/en/Reference/WiFiNINA)
- [ESP8266-Websocket](https://github.com/morrissinger/ESP8266-Websocket)

## How to use it

- Plug in the GameCube controller.
- Open the serial monitor of the Arduino wired to the GameCube controller, switch the baud rate to 115200 and the drop down menu to No Line Ending.
- Once the WebSocket and WebClient are online, open the Client's IP adress in a browser.
- In the Serial monitor, type "test" to see that every button works as expected.
- Make custom functions and commands, Push the tech to it's limit, have fun with it!
