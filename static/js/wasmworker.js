
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var predictcpp = Module.cwrap("makePrediction","string",[]);



function predictjs(){
	predictcpp();
}


onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "predict"){
		console.log('message recieved');
		predictjs();
	}
	postMessage(result);
}



