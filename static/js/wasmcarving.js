
function cpp_ready() {
	postMessage("ready");
	
}

function displayNow() {
	var svg = '<svg style="width: 60vw;" viewBox="-1 -1 '+(parseInt(maxX)+2)+' '+(parseInt(maxY)+2)+'" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink"  version="1.2" baseProfile="tiny">';
	var maxP = 0; var minP = 1000000000; var sumP = 0;
	for (var i=0;i<jsPoints.length;i++){
		if (parseInt(jsPoints[i].val)>maxP){
			maxP = parseInt(jsPoints[i].val);
		}
		if (parseInt(jsPoints[i].val)<minP){
			minP = parseInt(jsPoints[i].val);
		}
		sumP += parseInt(jsPoints[i].val);
	}
	var avgP = sumP/jsPoints.length;
	console.log(minP,maxP, avgP);
	for (var i=0;i<jsPoints.length;i++){
		svg += '<circle r=".5" cx="'+jsPoints[i].x+'" cy="'+jsPoints[i].y+'" fill="rgb('+(parseInt(jsPoints[i].val)*125/avgP)+',0,'+(250-parseInt(jsPoints[i].val)*125/avgP)+')" stroke="none"></circle>';
	}
	svg += '</svg>';
	postMessage(svg);
}
var points = [];
var pointsOut = [];
var jsPoints;
var maxX;
var maxY;
importScripts('wasmcarve.js');





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



