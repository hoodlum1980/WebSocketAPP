var wsUri = "ws://127.0.0.1:9002/";
var output;

function init() {
   output = document.getElementById("script_1");
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
	output = document.getElementById("script_"+value);
	output.innerHTML = "";
	doSend("run_"+value);
}


function parseData(data){
	var splited = data.split("/");
	output = document.getElementById("script_"+splited[1]);
    writeToScreen('<span class="label label-primary"><strong> \> </strong>'+splited[0]+'</span>');
}

function clickStop(value){
    websocket.send("stop_"+value);
    //websocket.close();
}

function onMessage(evt) {
	parseData(evt.data);
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
