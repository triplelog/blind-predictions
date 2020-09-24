
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var predictcpp = Module.cwrap("makePrediction","string",["number"]);
var updatecpp = Module.cwrap("updateProbability","string",["number","number","number"]);



function predictjs(){
	predictcpp(2016);
	predictcpp(2020);
}
function updatejs(state,prob,year){
	updatecpp(state,prob,year);
}


onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "predict"){
		console.log('message recieved');
		predictjs();
	}
	else if (message[0] == "update"){
		updatejs(message[1],message[2],message[3]);
	}
	postMessage(result);
}



