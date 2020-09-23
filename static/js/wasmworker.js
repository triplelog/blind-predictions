
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var predictcpp = Module.cwrap("makePrediction","string",[]);
var updatecpp = Module.cwrap("updateProbability","string",["number","number"]);



function predictjs(){
	predictcpp();
}
function updatejs(state,prob){
	updatecpp(state,prob);
}


onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "predict"){
		console.log('message recieved');
		predictjs();
	}
	else if (message[0] == "update"){
		updatejs(message[1],message[2]);
	}
	postMessage(result);
}



