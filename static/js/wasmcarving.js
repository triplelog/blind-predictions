
function cpp_ready() {
	postMessage("ready");
	
}

function displayNow(dAdv=1,bAdv=1,loc=true) {
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
			var bdems = blackv*bd*dAdv*bAdv;
			var breps = blackv*(1-bd*dAdv*bAdv);
			sums[6]+=bdems-blackv*bd*dAdv;//black dem diff
			sums[7]+=breps-blackv*(1-bd*dAdv);//black rep diff
			sums[8]+=whitev*.5*bd*dAdv;//white dem total
			sums[9]+=whitev*(1-.5*bd*dAdv);//white rep total
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
	
	var originalMap = {};
	
	for (var i=0;i<jsPoints.length;i++){
		//var yeardiff = (sums[2]+sums[3])/(sums[0]+sums[1])*(parseInt(jsPoints[i].d)-parseInt(jsPoints[i].r)) - (parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16));
		//var yeardiff = (sums[2])/(sums[0])*(parseInt(jsPoints[i].d)) - (parseInt(jsPoints[i].d16));
		
		//var yeardiff = (jsPoints[i].yeard[0]*whitedemMul+jsPoints[i].yeard[1])-(jsPoints[i].yearr[0]*whiterepMul+jsPoints[i].yearr[1]);
		
		
		var yeardiff = parseInt(jsPoints[i].d16)-parseInt(jsPoints[i].r16);
		
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
		
		if (loc){
			originalMap[parseInt(jsPoints[i].ox)*1000+parseInt(jsPoints[i].oy)]=[parseInt(jsPoints[i].x),parseInt(jsPoints[i].y)]
		}
		
	}
	
	var avgP = sumP/jsPoints.length;
	
	var exCount = 0;
	
	var svgCities = {'city-0':{'name':"Columbia", 'opath':[[90, 70], [90, 69], [90, 70], [90, 69], [90, 70], [90, 69], [90, 70], [90, 69], [91, 69], [91, 70], [90, 70], [91, 70], [90, 70], [91, 70], [90, 70], [91, 70], [91, 69], [92, 69], [92, 68], [91, 68], [91, 69], [91, 68], [91, 67], [91, 68], [92, 68], [91, 68], [91, 69], [91, 68], [92, 68], [92, 69], [93, 69], [93, 70], [93, 71], [94, 71], [94, 72], [94, 73], [94, 74], [95, 74], [94, 74], [95, 74], [95, 73], [95, 72], [95, 73], [95, 72], [96, 72], [96, 73], [96, 72], [95, 72], [95, 71], [95, 72], [96, 72], [96, 71], [95, 71], [96, 71], [95, 71], [96, 71], [95, 71], [96, 71], [96, 72], [97, 72], [96, 72], [97, 72], [97, 71], [98, 71], [98, 70], [97, 71], [97, 70], [98, 70], [97, 70], [98, 70], [98, 69], [98, 70], [98, 69], [98, 70], [99, 70], [98, 70], [98, 71], [98, 72], [97, 72], [98, 72], [97, 72], [98, 72], [97, 72], [98, 72], [97, 72], [97, 73], [98, 73], [97, 73], [98, 73], [98, 74], [97, 74], [97, 75], [98, 75], [99, 75], [99, 74], [99, 75], [99, 74], [100, 74], [99, 74], [100, 74], [100, 73], [100, 72], [101, 72], [101, 71], [102, 71], [102, 70], [102, 71], [102, 70], [103, 70], [102, 70], [103, 70], [103, 69], [103, 70], [103, 69], [103, 70], [103, 69], [103, 70], [104, 70], [103, 70], [103, 69], [104, 69], [104, 70], [104, 69], [105, 69], [104, 69], [104, 68], [104, 67], [104, 68], [104, 67], [105, 67], [106, 67], [106, 68], [105, 68], [106, 68], [105, 68], [105, 69], [105, 68], [105, 69], [106, 69], [107, 69], [107, 70], [108, 70], [108, 71], [109, 71], [109, 72], [110, 72], [110, 73], [110, 74], [110, 75], [109, 75], [108, 75], [107, 75], [106, 75], [106, 76], [105, 76], [104, 76], [103, 76], [102, 76], [102, 77], [103, 77], [102, 77], [102, 76], [102, 77], [101, 77], [102, 77], [101, 77], [101, 78], [100, 78], [101, 78], [100, 78], [100, 77], [100, 78], [100, 77], [100, 78], [100, 79], [100, 78], [100, 79], [101, 79], [100, 79], [99, 79], [98, 79], [99, 79], [99, 80], [98, 80], [98, 79], [98, 80], [98, 79], [97, 79], [98, 79], [98, 78], [98, 79], [98, 78], [98, 77], [98, 78], [98, 77], [98, 78], [97, 78], [97, 77], [96, 77], [97, 77], [97, 78], [96, 78], [97, 78], [96, 78], [96, 79], [96, 78], [96, 77], [95, 77], [95, 76], [95, 75], [94, 75], [93, 75], [93, 74], [92, 74], [93, 74], [92, 74], [93, 74], [93, 73], [93, 74], [93, 73], [93, 74], [94, 74], [93, 74], [94, 74], [94, 75], [94, 74], [94, 73], [94, 72], [93, 72], [92, 72], [93, 72], [92, 72], [93, 72], [92, 72], [93, 72], [93, 71], [92, 71], [92, 72], [92, 71], [91, 71], [92, 71], [91, 71], [91, 70], [91, 71], [90, 71], [90, 72], [90, 71], [90, 70], [90, 71], [90, 70]],'path':[]}};
	svgCities['city-1']={'name':"Greenville", 'opath':[[36, 22], [36, 21], [36, 22], [36, 21], [37, 21], [37, 20], [38, 20], [38, 19], [39, 19], [39, 20], [40, 20], [40, 21], [40, 20], [40, 21], [41, 21], [41, 22], [41, 21], [41, 22], [40, 22], [41, 22], [40, 22], [41, 22], [40, 22], [41, 22], [42, 22], [42, 23], [42, 22], [42, 23], [41, 24], [41, 23], [41, 24], [41, 25], [41, 24], [41, 25], [40, 25], [40, 24], [40, 25], [40, 26], [40, 27], [40, 26], [39, 26], [39, 25], [39, 24], [39, 25], [39, 24], [38, 24], [38, 25], [38, 24], [38, 25], [38, 24], [37, 24], [38, 24], [37, 24], [37, 23], [37, 24], [37, 23], [37, 22], [36, 22]],'path':[]};
	
	
	//svgCities['city-1']={'name':"Greenville", 'opath':,'path':[]};
	
	
	
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
		
		if (jsPoints[i].county > 0){
			hue = 120;
			
		}
		
		var id = 'cell-'+jsPoints[i].x+'-'+jsPoints[i].y;
		svgPoints[id]='hsl('+hue+',80%,'+lum+'%)';
		
		if (loc){
			for (city in svgCities){
				svgCities[city].path = [];
				var opath = svgCities[city].opath
				for (var ii=0;ii<opath.length;ii++){
					if (originalMap[opath[ii][0]*1000+opath[ii][1]]){
						svgCities[city].path.push(originalMap[opath[ii][0]*1000+opath[ii][1]]);
					}
				}
				
			}
		}
	}
	console.log(dAdv,minP,maxP, avgP, maxD,exCount, jsPoints.length);
	
	if (loc){
		postMessage({'points':svgPoints,'cities':svgCities});
	}
	else {
		postMessage({'points':svgPoints,'cities':{}});
	}
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
		displayNow(message[1],message[2],false);
	}
}



