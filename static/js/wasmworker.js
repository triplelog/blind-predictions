
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var lcpp = Module.cwrap("LatexIt","string",["string"]);



function ljs(input){
	lcpp(input);
}


onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "markdown"){
		
	}
	postMessage(result);
}



