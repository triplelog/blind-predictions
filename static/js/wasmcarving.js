
function cpp_ready() {
	postMessage("ready");
	
}

function displayNow(dAdv=1,bAdv=1) {
	var maxP = 0; var minP = 1000000000; var sumP = 0;
	var maxD = 0;
	var sums = [0,0,0,0,0,0];
	var svgPoints = {};
	for (var i=0;i<jsPoints.length;i++){
		sums[0]+=parseInt(jsPoints[i].d);
		sums[1]+=parseInt(jsPoints[i].r);
		sums[2]+=parseInt(jsPoints[i].d16);
		sums[3]+=parseInt(jsPoints[i].r16);
		sums[4]+=parseInt(jsPoints[i].white);
		sums[5]+=parseInt(jsPoints[i].black);
	}
	var wmax = 0;
	var wmin = 100;
	for (var i=0;i<jsPoints.length;i++){
		//var yeardiff = (sums[2]+sums[3])/(sums[0]+sums[1])*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r)) - (parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16));
		//var yeardiff = (sums[2])/(sums[0])*(parseInt(jsPoints[i].d)) - (parseInt(jsPoints[i].d16));
		var whitepct;
		if (parseInt(jsPoints[i].white)+parseInt(jsPoints[i].black) > 0){
			whitepct = parseFloat(jsPoints[i].white)/(parseInt(jsPoints[i].white)+parseInt(jsPoints[i].black));
		}
		else {
			whitepct = sums[5]/(sums[4]+sums[5]);
		}
		 
		if (whitepct > wmax){wmax = whitepct;}
		if (whitepct < wmin){wmin = whitepct;}
		var whitediff = parseInt(jsPoints[i].d16)*whitepct*dAdv - (parseInt(jsPoints[i].r16))*whitepct;
		var blackdiff = parseInt(jsPoints[i].d16)*(1-whitepct)*bAdv - (parseInt(jsPoints[i].r16))*(1-whitepct);
		var yeardiff = whitediff+blackdiff;
		
		
		jsPoints[i].yeardiff = yeardiff;
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
	console.log(wmax, wmin);
	var avgP = sumP/jsPoints.length;
	
	var exCount = 0;
	for (var i=0;i<jsPoints.length;i++){
		//var yeardiff = (sums[2]+sums[3])/(sums[0]+sums[1])*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r)) - (parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16));
		//var yeardiff = (sums[2])/(sums[0])*(parseInt(jsPoints[i].d)) - (parseInt(jsPoints[i].d16));
		var yeardiff = jsPoints[i].yeardiff;
		
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
		
		var id = 'cell-'+jsPoints[i].x+'-'+jsPoints[i].y;
		svgPoints[id]='hsl('+hue+',80%,'+lum+'%)';
	}
	//console.log(dAdv,minP,maxP, avgP, maxD,exCount, jsPoints.length);

	postMessage(svgPoints);
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
		displayNow(message[1],message[2]);
	}
}



