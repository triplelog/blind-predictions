'use strict';
const { PerformanceObserver, performance } = require('perf_hooks');
var fs = require("fs");
const assert = require('assert');



const https = require('https');
var fs = require("fs");
var myParser = require("body-parser");
var qs = require('querystring');
const { exec } = require('child_process');
var nunjucks = require('nunjucks');
var crypto = require("crypto");

const options = {
  key: fs.readFileSync('/etc/letsencrypt/live/inlinemath.com/privkey.pem'),
  cert: fs.readFileSync('/etc/letsencrypt/live/inlinemath.com/fullchain.pem')
};





var express = require('express');
var app = express();
app.use('/',express.static('static'));


const server1 = https.createServer(options, app);

server1.listen(12312);

const server = https.createServer(options, (req, res) => {
  res.writeHead(200);
  res.end('\n');
}).listen(8081);

const WebSocket = require('ws');
//const wss = new WebSocket.Server({ port: 8080 , origin: 'http://tabdn.com'});
const wss = new WebSocket.Server({ server });
wss.on('connection', function connection(ws) {
	var username = '';
  	ws.on('message', function incoming(message) {
  		console.log(performance.now());
		var dm = JSON.parse(message);
		console.log(performance.now());
		if (dm.operation == 'key'){
			if (tempKeys[dm.message]){
				username = tempKeys[dm.message].username;
			}
		}
		
		
		
  	});
});

var startTime = performance.now();




app.get(['/predict','/predict.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/datatable.html',{

		}));
		res.end();
	}
);

app.get(['/electoral','/electoral.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/electoral.html',{

		}));
		res.end();
	}
);

app.get(['/map','/map.html'],
	function(req, res){
		
		var eData = [{'abbrev': 'dc', 'votes16': 295553, 'ev10': 3, 'pres08': 0.06599232, 'pres12': 0.07412351, 'rperc': 0.04304812}, {'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		for (var i=0;i<eData.length;i++){
			//eData[i].rpred = eData[i].rperc;
			eData[i].rpred = eData[i].pres08;
			eData[i].pres16 = eData[i].rperc;
			delete eData[i].rperc;
		}
		res.write(nunjucks.render('templates/map.html',{
			electoralData: eData,

		}));
		res.end();
	}
);

app.post(['/map','/map.html'],
	function(req, res){
		console.log(req.body);
		var eData = [{'abbrev': 'dc', 'votes16': 295553, 'ev10': 3, 'pres08': 0.06599232, 'pres12': 0.07412351, 'rperc': 0.04304812}, {'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		for (var i=0;i<eData.length;i++){
			//eData[i].rpred = eData[i].rperc;
			eData[i].rpred = eData[i].pres08;
			eData[i].pres16 = eData[i].rperc;
			delete eData[i].rperc;
		}
		res.write(nunjucks.render('templates/map.html',{
			electoralData: eData,

		}));
		res.end();
	}
);




app.get(['/','/index','/index.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/index.html',{

		}));
		res.end();
	}
);

app.get(['*'],
	function(req, res){
		

		res.redirect('../');
	}
);



