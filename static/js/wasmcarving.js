
function cpp_ready() {
	postMessage("ready");
	
}

function displayNow() {
	var svg = '<svg style="width: 60vw;" viewBox="-1 -1 '+(parseInt(maxX)+2)+' '+(parseInt(maxY)+2)+'" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink"  version="1.2" baseProfile="tiny">';
	var maxP = 0; var minP = 1000000000; var sumP = 0;
	var maxD = 0;
	for (var i=0;i<jsPoints.length;i++){
		if (parseInt(jsPoints[i].val)>maxP){
			maxP = parseInt(jsPoints[i].val);
			//console.log(maxP,jsPoints[i].x,jsPoints[i].y);
		}
		if (parseInt(jsPoints[i].val)<minP){
			minP = parseInt(jsPoints[i].val);
		}
		//sumP += parseInt(jsPoints[i].val);
		if (parseInt(jsPoints[i].d)>parseInt(jsPoints[i].r)){
			sumP += parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r);
			if (parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r) > maxD){
				maxD = parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r);
			}
		}
		else {
			sumP += parseInt(jsPoints[i].r)-parseInt(jsPoints[i].d);
			if (parseInt(jsPoints[i].r)-parseInt(jsPoints[i].d) > maxD){
				maxD = parseInt(jsPoints[i].r)-parseInt(jsPoints[i].d);
			}
		}
		
	}
	var avgP = sumP/jsPoints.length;
	console.log(minP,maxP, avgP, maxD);
	
	for (var i=0;i<jsPoints.length;i++){
		var hue = 0;
		var lum = 50;
		if (parseInt(jsPoints[i].d)>parseInt(jsPoints[i].r)){
			hue = 240;
			lum = 100-75*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r))/maxD;
		}
		else {
			lum = 100-75*(parseInt(jsPoints[i].r)-parseInt(jsPoints[i].d))/maxD;
		}


		if (lum<25){lum = 25;}
		
		//hue = 240*parseInt(jsPoints[i].ox)/100;
		//lum = 100*parseInt(jsPoints[i].oy)/100;
		var block = parseInt(Math.round(jsPoints[i].ox/10)*10+Math.round(jsPoints[i].oy/10));
		svg += '<rect width="1" height="1" x="'+jsPoints[i].x+'" y="'+jsPoints[i].y+'" fill="hsl('+hue+',80%,'+lum+'%)" stroke="hsl('+hue+',80%,'+lum+'%)" class="county-'+block+'"></rect>';
	}
	svg += '</svg>';
	postMessage(svg);
	pointsOut = [];
	jsPoints = [];
}

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



