var senateArray = [];

for (var i=0;i<Object.keys(senateData).length;i++) {
	if (Object.keys(senateData)[i] != 'dc'){
		if (senateData[Object.keys(senateData)[i]][2014].length>0) {
			senateArray.push({'abbrev':Object.keys(senateData)[i],'pred20':senateData[Object.keys(senateData)[i]]['rpred'],'act14':senateData[Object.keys(senateData)[i]][2014][0]});
			if (senateData[Object.keys(senateData)[i]]['pres16']>.5){
				var elo = (senateData[Object.keys(senateData)[i]]['pres16']-.5)*2000;
				var dprob = 1.0/(1+Math.pow(10.0,elo/75));
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer6').style.fill = "hsl(0,100%,"+(50+dprob*100)+"%)";
			}
			else {
				var elo = (senateData[Object.keys(senateData)[i]]['pres16']-.5)*2000;
				var dprob = 1.0/(1+Math.pow(10.0,elo/75));
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer6').style.fill = "hsl(240,100%,"+(50+(1-dprob)*100)+"%)";
			}
			/*if (senateData[Object.keys(senateData)[i]]['pres12']>.5){
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer2').style.fill = 'red';
			}
			else {
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer2').style.fill = 'blue';
			}*/
			if (senateData[Object.keys(senateData)[i]][2014][0]>.5){
				var elo = (senateData[Object.keys(senateData)[i]][2014][0]-.5)*2000;
				var dprob = 1.0/(1+Math.pow(10.0,elo/75));
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer5').style.fill = "hsl(0,100%,"+(50+dprob*100)+"%)";
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-inner').style.fillOpacity = '1';
			}
			else if (senateData[Object.keys(senateData)[i]][2014][0]<.5){
				var elo = (senateData[Object.keys(senateData)[i]][2014][0]-.5)*2000;
				var dprob = 1.0/(1+Math.pow(10.0,elo/75));
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer5').style.fill = "hsl(240,100%,"+(50+(1-dprob)*100)+"%)";
				document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-inner').style.fillOpacity = '1';
			}
			
			if (senateData[Object.keys(senateData)[i]][2018].length > 0){
				if (senateData[Object.keys(senateData)[i]][2018][0]>.5){
					var elo = (senateData[Object.keys(senateData)[i]][2018][0]-.5)*2000;
					var dprob = 1.0/(1+Math.pow(10.0,elo/75));
					document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer4').style.fill = "hsl(0,100%,"+(50+dprob*100)+"%)";
				}
				else if (senateData[Object.keys(senateData)[i]][2018][0]<.5){
					var elo = (senateData[Object.keys(senateData)[i]][2018][0]-.5)*2000;
					var dprob = 1.0/(1+Math.pow(10.0,elo/75));
					document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer4').style.fill = "hsl(240,100%,"+(50+(1-dprob)*100)+"%)";
				}
			}
			else if (senateData[Object.keys(senateData)[i]][2016].length > 0){
				if (senateData[Object.keys(senateData)[i]][2016][0]>.5){
					var elo = (senateData[Object.keys(senateData)[i]][2016][0]-.5)*2000;
					var dprob = 1.0/(1+Math.pow(10.0,elo/75));
					document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer4').style.fill = "hsl(0,100%,"+(50+dprob*100)+"%)";
				}
				else if (senateData[Object.keys(senateData)[i]][2016][0]<.5){
					var elo = (senateData[Object.keys(senateData)[i]][2016][0]-.5)*2000;
					var dprob = 1.0/(1+Math.pow(10.0,elo/75));
					document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-outer4').style.fill = "hsl(240,100%,"+(50+(1-dprob)*100)+"%)";
				}
			}
		}
		else {
			document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-inner').style.fillOpacity = '0';
			document.getElementById(Object.keys(senateData)[i].toUpperCase()+'-inner').style.fill = 'white';
		}
	}
}


function orderStates() {
	senateArray.sort((a, b) => parseFloat(a['pred20']) - parseFloat(b['pred20']));
	var maxD = 0;
	var maxR = 0;
	document.getElementById('pres2016TR').innerHTML = '';
	document.getElementById('pres2016R').innerHTML = '';
	document.getElementById('pres2016TL').innerHTML = '';
	document.getElementById('pres2016L').innerHTML = '';
	for (var i=0;i<senateArray.length;i++) {
		if (2==2) {
			if (2==2) {
				var presyear = senateArray[i]['pred20'];
				var elo = (presyear-.5)*2000;
				var dprob = 1.0/(1+Math.pow(10.0,elo/75));
				if (dprob<.5) {
					document.getElementById(senateArray[i]['abbrev'].toUpperCase()+'-inner').style.fill = "hsl(0,100%,"+(50+dprob*100)+"%)";
					var newspan = document.createElement("span");
					newspan.classList.add("pres-cell");
					newspan.classList.add("stateface");
					newspan.classList.add("stateface-replace");
		
					newspan.classList.add("stateface-"+senateArray[i]['abbrev']);
					if (senateArray[i]['act14'] >= .5) {
						newspan.classList.add("rep");
					}
					else {
						newspan.classList.add("dem");
					}
					var numBlocks = parseInt(presyear*200)-100;
					if (numBlocks < maxR + 1) {
						numBlocks = maxR + 1;
						maxR++;
					}
					else {
						maxR = numBlocks;
					}
					if (numBlocks < 27) {
						newspan.style.left = 'calc(var(--block-width) * '+(numBlocks-1)+')';
				
						var myel = document.getElementById('pres2016TR');
						myel.appendChild(newspan);
					}
					else {
						newspan.style.top = 'calc(var(--block-width) * '+(numBlocks-27)+')';
				
						var myel = document.getElementById('pres2016R');
						myel.appendChild(newspan);
					}
				}
			}
		}
	}
	for (var i=senateArray.length-1;i>-1;i--) {
		if (2==2) {
			if (2==2) {
				var presyear = senateArray[i]['pred20'];
				var elo = (presyear-.5)*2000;
				var dprob = 1.0/(1+Math.pow(10.0,elo/75));
				if (dprob>=.5) {
					document.getElementById(senateArray[i]['abbrev'].toUpperCase()+'-inner').style.fill = "hsl(240,100%,"+(50+(1-dprob)*100)+"%)";
					var newspan = document.createElement("span");
					newspan.classList.add("pres-cell");
					newspan.classList.add("stateface");
					newspan.classList.add("stateface-replace");
		
					newspan.classList.add("stateface-"+senateArray[i]['abbrev']);
					if (senateArray[i]['act14'] >= .5) {
						newspan.classList.add("rep");
					}
					else {
						newspan.classList.add("dem");
					}
					var numBlocks = 100-parseInt(presyear*200);
					if (numBlocks < maxD + 1) {
						numBlocks = maxD + 1;
						maxD++;
					}
					else {
						maxD = numBlocks;
					}
					if (numBlocks < 27) {
						newspan.style.right = 'calc(var(--block-width) * '+(numBlocks-1)+')';
				
						var myel = document.getElementById('pres2016TL');
						myel.appendChild(newspan);
					}
					else {
						newspan.style.top = 'calc(var(--block-width) * '+(numBlocks-27)+')';
				
						var myel = document.getElementById('pres2016L');
						myel.appendChild(newspan);
					}
				}
			}
		}
	}
}
orderStates();


var startCoords = [0,0];
var startDemVotes = 0;
var startGopVotes = 0;
var currentState = {};

for (var i=0;i<senateArray.length;i++) {

	document.getElementById(senateArray[i]['abbrev'].toUpperCase()+'-inner').addEventListener("mousedown", statemousedown);

}

document.addEventListener("mouseup", function(event) {
  stateStart = '';
  document.removeEventListener("mousemove", statemousemove);
}, false);

function statemousedown(evt) {
	var myState = evt.target.id.substring(0,2).toLowerCase();

	for (var i=0; i<senateArray.length; ++i) {
		if (senateArray[i]['abbrev'] == myState) {
	  		currentState = senateArray[i];
	  		break;
	  	}
	}

  console.log(currentState);
  //drawChart(d.key);
  startCoords[0]= evt.clientX;
  startCoords[1]= evt.clientY;
  
  startDemVotes = (1-currentState['pred20'])*1000000+0;
  startGopVotes = currentState['pred20']*1000000+0;
  console.log(startDemVotes, startGopVotes);
  document.addEventListener("mousemove", statemousemove);
}

function statemousemove(evt) {
	
	var currentCoords = [evt.clientX,evt.clientY];
	if (currentCoords[0]>startCoords[0]) {
		currentState['pred20']= Math.round((100+Math.pow(currentCoords[0]-startCoords[0],1.1))*startGopVotes/100)/1000000;
	}
	else {
		currentState['pred20']= 1-Math.round((100-currentCoords[0]+startCoords[0])*startDemVotes/100)/1000000;
	}
	
	var demPercent = Math.floor((1-currentState['pred20']) * 20) * 5;
	demPercent = Math.floor((1-currentState['pred20']) * 100) * 5 - 200;
	if (demPercent < 0){
		demPercent = 0;
	}
	else if (demPercent > 95) {
		demPercent = 95;
	}


	orderStates();
	//div.attr('class',"state-boundary dem-" + demPercent + '-state state'+d.key);
	//d3.selectAll(".state"+d.key).attr('class',"state-boundary dem-" + demPercent + '-state state'+d.key);
	//updateTotals();
	
}


var myWorker = new Worker('js/wasmworker.js');
var stateList = [];
var stateMap = {};
for (var i=0;i<Object.keys(senateData).length;i++) {
	stateList.push(Object.keys(senateData)[i]);
}
stateList.sort();
for (var i=0;i<51;i++){
	stateMap[stateList[i]]=i;
}
myWorker.onmessage = function(e) {
	if (e.data == "ready"){
		setTimeout(predictNow,50);
	}
	else if (e.data['type'] == "wins"){
		
		var histS = e.data.HistogramS;
		document.getElementById('dwinp').textContent = "";
		document.getElementById('rwinp').textContent = "";
		var data = {
		  labels: [],
		  series: [
			[],
			[]
		  ]
		};
		var demTotal = [];
		var repTotal = {};
		var minDem = 100;
		for (var i in histS){
			document.getElementById('dwinp').textContent += (35+parseInt(i))+":"+histS[i]+", ";
			if (demTotal.length == 0){
				demTotal.push(parseInt(histS[i]));
			}
			else {
				demTotal.push(parseInt(histS[i])+demTotal[demTotal.length-1]);
			}
			
			if (35+parseInt(i)<minDem){
				minDem = 35+parseInt(i);
			}
		}
		for (var i=minDem+demTotal.length-1;i>=minDem;i--){
			if (repTotal[100-i+1]){
				repTotal[100-i]=repTotal[100-i+1]+parseInt(histS[i]);
			}
			else {
				repTotal[100-i] = parseInt(histS[i]);
			}
			console.log(repTotal);
		}
		for (var i=6;i<16;i++){	
			data.labels.push(""+(minDem+i));
			data.series[0].push(1000 - demTotal[i-1]);
			data.series[1].push(repTotal[100-(minDem+i)]);
		}
		console.log(data);
		document.getElementById('dwinp').style.textDecoration = "none";
  		document.getElementById('rwinp').style.textDecoration = "none";
  		

		var options = {
		  seriesBarDistance: 10,
		  high: 1000,
		  low: 0,
		  divisor: 100,
		  axisY: {
			ticks: [0, 100, 200, 300, 400, 500, 600, 700, 800, 900]
		  }
		};

		

		new Chartist.Bar('#simulationsChart', data, options);
	}
}
function predictNow(){

	for (var i=0;i<51;i++){
		var stateAbbrev = stateList[i];
		var dprob = .001;
		myWorker.postMessage(["update",i,dprob,"2016"]);
	
	}
	for (var i=0;i<senateArray.length;i++){
		var state = stateMap[senateArray[i].abbrev];
		var year = "2016";
		var rpred = senateArray[i]["pred20"];
		if (rpred){
			var elo = (rpred-.5)*2000;
			var dprob = 1.0/(1+Math.pow(10.0,elo/75));
			console.log(senateArray[i].abbrev,dprob);
			myWorker.postMessage(["update",state,dprob,year]);
		}

		
	}
	myWorker.postMessage(["predict",100]);
	myWorker.postMessage(["predict",1000]);
}