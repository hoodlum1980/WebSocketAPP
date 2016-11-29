var wsUri = "ws://127.0.0.1:9002/";
var output;

function init() {
   output = document.getElementById("script_one");
   testWebSocket();
}

function testWebSocket() {
   websocket = new WebSocket(wsUri);

   websocket.onopen = function(evt) {
      onOpen(evt)
   };

   websocket.onmessage = function(evt) {
      onMessage(evt)
   };

   websocket.onerror = function(evt) {
      onError(evt)
   };
}

function onOpen(evt) {
   writeToScreen("CONNECTED");
   //doSend("WebSocket rocks");
}

function clickSend(){
    
    doSend(document.getElementById("inputText").value);
}

function runScript()
{
    doSend("run");
}


function clickClose(){
    websocket.send("stop-listening");
    //websocket.close();
}

function onMessage(evt) {
   writeToScreen('<span style = "color: blue;">RESPONSE: ' +
      evt.data+'</span>');
}

function onError(evt) {
   writeToScreen('<span style="color: red;">ERROR:</span> ' + evt.data);
}

function doSend(message) {
   writeToScreen("SENT: " + message);
   websocket.send(message);
}

function writeToScreen(message) {
   var pre = document.createElement("p");
   pre.style.wordWrap = "break-word";
   pre.innerHTML = message;
   output.appendChild(pre);
}

window.addEventListener("load", init, false);
