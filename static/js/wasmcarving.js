
function cpp_ready() {
	postMessage("ready");
	
}

function displayNow(dAdv=1) {
	var svg = '<svg style="width: 60vw;" viewBox="-1 -1 '+(parseInt(maxX)+2)+' '+(parseInt(maxY)+2)+'" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink"  version="1.2" baseProfile="tiny">';
	var maxP = 0; var minP = 1000000000; var sumP = 0;
	var maxD = 0;
	var sums = [0,0,0,0];
	for (var i=0;i<jsPoints.length;i++){
		sums[0]+=parseInt(jsPoints[i].d);
		sums[1]+=parseInt(jsPoints[i].r);
		sums[2]+=parseInt(jsPoints[i].d16);
		sums[3]+=parseInt(jsPoints[i].r16);
	}
	console.log(sums);
	for (var i=0;i<jsPoints.length;i++){
		//var yeardiff = (sums[2]+sums[3])/(sums[0]+sums[1])*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r)) - (parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16));
		//var yeardiff = (sums[2])/(sums[0])*(parseInt(jsPoints[i].d)) - (parseInt(jsPoints[i].d16));
		var yeardiff = parseInt(jsPoints[i].d16)*dAdv - (parseInt(jsPoints[i].r16));
		
		if (parseInt(jsPoints[i].val)>maxP){
			maxP = parseInt(jsPoints[i].val);
			//console.log(maxP,jsPoints[i].x,jsPoints[i].y);
		}
		if (parseInt(jsPoints[i].val)<minP){
			minP = parseInt(jsPoints[i].val);
		}
		//sumP += parseInt(jsPoints[i].val);
		if (yeardiff>0){
			sumP += yeardiff;
			if (yeardiff > maxD){
				maxD = yeardiff;
			}
		}
		else {
			sumP += -1*yeardiff;
			if (-1*yeardiff > maxD){
				maxD = -1*yeardiff;
			}
		}
		
	}
	var avgP = sumP/jsPoints.length;
	
	var exCount = 0;
	for (var i=0;i<jsPoints.length;i++){
		//var yeardiff = (sums[2]+sums[3])/(sums[0]+sums[1])*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r)) - (parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16));
		//var yeardiff = (sums[2])/(sums[0])*(parseInt(jsPoints[i].d)) - (parseInt(jsPoints[i].d16));
		var yeardiff = parseInt(jsPoints[i].d16)*dAdv - (parseInt(jsPoints[i].r16));
		
		var hue = 0;
		var lum = 50;
		if (yeardiff>0){
			hue = 240;
			lum = 100-25*(yeardiff)/avgP;
		}
		else {
			lum = 100-25*(-1*yeardiff)/avgP;
		}


		if (lum<25){exCount++; lum = 25;}
		
		//hue = 240*parseInt(jsPoints[i].ox)/100;
		//lum = 100*parseInt(jsPoints[i].oy)/100;
		var block = parseInt(Math.round(jsPoints[i].ox/10)*10+Math.round(jsPoints[i].oy/10));
		svg += '<rect width="1" height="1" x="'+jsPoints[i].x+'" y="'+jsPoints[i].y+'" fill="hsl('+hue+',80%,'+lum+'%)" stroke="hsl('+hue+',80%,'+lum+'%)" class="county-'+block+'"></rect>';
	}
	console.log(minP,maxP, avgP, maxD,exCount, jsPoints.length);
	svg += '</svg>';
	postMessage(svg);
	pointsOut = [];
}

var pointsOut = [];
var jsPoints;
var maxX;
var maxY;
importScripts('wasmcarve.js');





onmessage = function(e) {
	var message = e.data;
	var result = [];
	if (message[0] == "update"){
		displayNow(message[1]);
	}
}



