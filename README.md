# WebSocketAPP

Application which provides running C++ scripts via web browser using websockets.

This application has server side, where is C++ program which handles websocket messages. This server runs the other C/C++ programs each in the new Thread. Standard output from these programs is sended to the website.

Client side is webside with basic javascript which handles incoming outputs which are sended via websockets. These outputs are displayed on the website.

In this version number of the maximum running scripts is set to 4. "Names" of the scripts which you want to run must be changed in the code.

In the future, it should has option to add script dynamic. And there will be option for sending name of the script which u want to run in specific thread.

![Alt text](Screenshot_2016-11-30_18-22-56.png?raw=true "screenshot web")


![Alt text](Screenshot_2016-11-30_18-41-20.png?raw=true "screenshot web")
