
function cpp_ready() {
	postMessage("ready");
	
}

function displayNow(dAdv=1,bAdv=1) {
	var maxP = 0; var minP = 1000000000; var sumP = 0;
	var maxD = 0;
	var sums = [0,0,0,0,0,0,0,0,0,0];
	var svgPoints = {};
	for (var i=0;i<jsPoints.length;i++){
		sums[0]+=parseInt(jsPoints[i].d);
		sums[1]+=parseInt(jsPoints[i].r);
		sums[2]+=parseInt(jsPoints[i].d16);
		sums[3]+=parseInt(jsPoints[i].r16);
		sums[4]+=parseInt(jsPoints[i].white);
		sums[5]+=parseInt(jsPoints[i].black);
		
		var whitepct;
		if (parseInt(jsPoints[i].white)+parseInt(jsPoints[i].black) > 0){
			whitepct = parseFloat(jsPoints[i].white)/(parseInt(jsPoints[i].white)+parseInt(jsPoints[i].black));
		}
		else {
			whitepct = sums[5]/(sums[4]+sums[5]);
		}
		
		var v = parseInt(jsPoints[i].d16)+parseInt(jsPoints[i].r16);
		
		var whitev = v*whitepct;
		var blackv = v*(1-whitepct);
		if (whitev+blackv > 0){
			var bd = parseInt(jsPoints[i].d16)/(.5*whitev+blackv);
			var bdems = blackv*bd*bAdv;
			var breps = blackv*(1-bd*bAdv);
			sums[6]+=bdems-blackv*bd;//black dem diff
			sums[7]+=breps-blackv*(1-bd);//black rep diff
			sums[8]+=whitev*.5*bd;//white dem total
			sums[9]+=whitev*(1-.5*bd);//white rep total
			jsPoints[i].yeard = [whitev*.5*bd,bdems];
			jsPoints[i].yearr = [whitev*(1-.5*bd),breps];
		}
		else {
			jsPoints[i].yeard = [0,0];
			jsPoints[i].yearr = [0,0];
		}
		
		
		
	}
	var whitedemMul = (sums[8]-sums[6])/sums[8];
	var whiterepMul = (sums[9]-sums[7])/sums[9];
	for (var i=0;i<jsPoints.length;i++){
		//var yeardiff = (sums[2]+sums[3])/(sums[0]+sums[1])*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r)) - (parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16));
		//var yeardiff = (sums[2])/(sums[0])*(parseInt(jsPoints[i].d)) - (parseInt(jsPoints[i].d16));
		
		var yeardiff = (jsPoints[i].yeard[0]*whitedemMul+jsPoints[i].yeard[1])-(jsPoints[i].yearr[0]*whiterepMul+jsPoints[i].yearr[1]);
		
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



