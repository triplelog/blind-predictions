
function cpp_ready() {
	postMessage("ready");
}
importScripts('wasmpredict.js');

var predictcpp = Module.cwrap("makePrediction","string",["number","number"]);
var updatecpp = Module.cwrap("updateProbability","string",["number","number","number"]);



function updateWins(wins){
	wins['type']="wins";
	postMessage(wins);
}
function updateMap(states){
	//var wins = {'type':"states","val":states};
	var wins = {'type':"result","val":states};
	postMessage(wins);
}
function predictjs(n){
	//predictcpp(2016,n);
	predictcpp(2020,n);
}
function updatejs(state,prob,year){
	updatecpp(state,prob,year);
}


onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "predict"){
		if (message[1]){
			predictjs(message[1]);
		}
		else {
			predictjs(100);
		}
		
	}
	else if (message[0] == "update"){
		updatejs(message[1],message[2],message[3]);
	}
}



