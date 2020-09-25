
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var predictcpp = Module.cwrap("makePrediction","string",["number","number"]);
var updatecpp = Module.cwrap("updateProbability","string",["number","number","number"]);


var wins = {};
function predictjs(n){
	wins = {};
	predictcpp(2016,n);
	return wins;
	//predictcpp(2020);
}
function updatejs(state,prob,year){
	updatecpp(state,prob,year);
}


onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "predict"){
		if (message[1]){
			wins = predictjs(message[1]);
		}
		else {
			wins = predictjs(100);
		}
		
		wins['type']="wins";
		postMessage(wins);
	}
	else if (message[0] == "update"){
		updatejs(message[1],message[2],message[3]);
	}
}



