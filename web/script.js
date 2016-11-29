var wsUri = "ws://127.0.0.1:9002/";
var output;

function init() {
   output = document.getElementById("script_one");
   startWebSockets();
}

function startWebSockets() {
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
   writeToScreen('<span class="label label-warning">Connected</span>');
   //doSend("WebSocket rocks");
}

function clickSend(){
    
    doSend(document.getElementById("inputText").value);
}

function runScript(value)
{
    if (value == 1)
	{
	doSend("run_1");
	}
    if (value == 2)
	{
	doSend("run_2");
	}
    if (value == 3)
	{
	doSend("run_3");
	}
    if (value == 4)
	{
	doSend("run_4");
	}

}


function clickClose(){
    websocket.send("stop-listening");
    //websocket.close();
}

function onMessage(evt) {
   writeToScreen('<span class="label label-primary"><strong> \> </strong>'+evt.data+'</span>');
}

function onError(evt) {
   writeToScreen('<span class="label label-danger"><strong>Error: </strong>'+evt.data+'</span>');
}

function doSend(message) {
   writeToScreen('<span class="label label-success">'+message+'</span>');
   websocket.send(message);
}

function writeToScreen(message) {
   var pre = document.createElement("p");
   pre.style.wordWrap = "break-word";
   pre.innerHTML = message;
   output.appendChild(pre);
}

window.addEventListener("load", init, false);
