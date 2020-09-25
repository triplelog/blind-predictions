
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var predictcpp = Module.cwrap("makePrediction","string",["number"]);
var updatecpp = Module.cwrap("updateProbability","string",["number","number","number"]);



function predictjs(){
	var wins = {};
	predictcpp(2016);
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
		var wins = predictjs();
		wins['type']="wins";
		postMessage(wins);
	}
	else if (message[0] == "update"){
		updatejs(message[1],message[2],message[3]);
	}
}



