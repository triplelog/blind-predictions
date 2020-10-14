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
var Papa = require('papaparse');

const options = {
  key: fs.readFileSync('/etc/letsencrypt/live/inlinemath.com/privkey.pem'),
  cert: fs.readFileSync('/etc/letsencrypt/live/inlinemath.com/fullchain.pem')
};





var express = require('express');
var app = express();
app.use('/',express.static('static'));
app.use(myParser.urlencoded({ extended: true }));
app.use(myParser.json());
app.use(myParser.raw());

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
	var locations = "DC";
  	ws.on('message', function incoming(message) {
  		console.log(performance.now());
		var dm = JSON.parse(message);
		console.log(performance.now());
		if (dm.operation == 'key'){
			if (tempKeys[dm.message]){
				username = tempKeys[dm.message].username;
			}
		}
		else if (dm.type == "update"){
			if (dm.locations){
				locations = dm.locations;
			}
			
			for (var state in csvdata['states']){
				for (var col in csvdata['states'][state]){
					if (!columns[col]){
						columns[col]=true;
					}
				}
			}
	
			var colArray = [{'title':'ID','field':'id'}];
			for (var col in columns){
				if (col == 'econPreddelo20'){
					colArray.push({'title':col,'field':col});
				}
			}
	
			var tableData = [];
			for (var state in csvdata['states']){
				if (locations == 50 && state == "DC"){
					continue;
				}
				var row = csvdata['states'][state];
				row['id']=state;
				tableData.push(row);
			}
			var jsonmessage = {'tableData':tableData,'columns':colArray};
			ws.send(JSON.stringify(jsonmessage));
		}
		
		
		
  	});
});

var startTime = performance.now();


//load all data into memory
var csvdata = {};
var columns = {};
csvdata['convert']={};
csvdata['convert']['states']={"AK":"AK","AL":"AL","AR":"AR","AZ":"AZ","CA":"CA","CO":"CO","CT":"CT","DC":"DC","DE":"DE","FL":"FL","GA":"GA","HI":"HI","IA":"IA","ID":"ID","IL":"IL","IN":"IN","KS":"KS","KY":"KY","LA":"LA","MA":"MA","MD":"MD","ME":"ME","MI":"MI","MN":"MN","MO":"MO","MS":"MS","MT":"MT","NC":"NC","ND":"ND","NE":"NE","NH":"NH","NJ":"NJ","NM":"NM","NV":"NV","NY":"NY","OH":"OH","OK":"OK","OR":"OR","PA":"PA","RI":"RI","SC":"SC","SD":"SD","TN":"TN","TX":"TX","UT":"UT","VA":"VA","VT":"VT","WA":"WA","WI":"WI","WV":"WV","WY":"WY"};
csvdata['convert']['cds']={"AL-1":"AL-1","AL-2":"AL-2","AL-3":"AL-3","AL-4":"AL-4","AL-5":"AL-5","AL-6":"AL-6","AL-7":"AL-7","AK-1":"AK-1","AZ-1":"AZ-1","AZ-2":"AZ-2","AZ-3":"AZ-3","AZ-4":"AZ-4","AZ-5":"AZ-5","AZ-6":"AZ-6","AZ-7":"AZ-7","AZ-8":"AZ-8","AZ-9":"AZ-9","AR-1":"AR-1","AR-2":"AR-2","AR-3":"AR-3","AR-4":"AR-4","CA-1":"CA-1","CA-2":"CA-2","CA-3":"CA-3","CA-4":"CA-4","CA-5":"CA-5","CA-6":"CA-6","CA-7":"CA-7","CA-8":"CA-8","CA-9":"CA-9","CA-10":"CA-10","CA-11":"CA-11","CA-12":"CA-12","CA-13":"CA-13","CA-14":"CA-14","CA-15":"CA-15","CA-16":"CA-16","CA-17":"CA-17","CA-18":"CA-18","CA-19":"CA-19","CA-20":"CA-20","CA-21":"CA-21","CA-22":"CA-22","CA-23":"CA-23","CA-24":"CA-24","CA-25":"CA-25","CA-26":"CA-26","CA-27":"CA-27","CA-28":"CA-28","CA-29":"CA-29","CA-30":"CA-30","CA-31":"CA-31","CA-32":"CA-32","CA-33":"CA-33","CA-34":"CA-34","CA-35":"CA-35","CA-36":"CA-36","CA-37":"CA-37","CA-38":"CA-38","CA-39":"CA-39","CA-40":"CA-40","CA-41":"CA-41","CA-42":"CA-42","CA-43":"CA-43","CA-44":"CA-44","CA-45":"CA-45","CA-46":"CA-46","CA-47":"CA-47","CA-48":"CA-48","CA-49":"CA-49","CA-50":"CA-50","CA-51":"CA-51","CA-52":"CA-52","CA-53":"CA-53","CO-1":"CO-1","CO-2":"CO-2","CO-3":"CO-3","CO-4":"CO-4","CO-5":"CO-5","CO-6":"CO-6","CO-7":"CO-7","CT-1":"CT-1","CT-2":"CT-2","CT-3":"CT-3","CT-4":"CT-4","CT-5":"CT-5","DE-1":"DE-1","FL-1":"FL-1","FL-2":"FL-2","FL-3":"FL-3","FL-4":"FL-4","FL-5":"FL-5","FL-6":"FL-6","FL-7":"FL-7","FL-8":"FL-8","FL-9":"FL-9","FL-10":"FL-10","FL-11":"FL-11","FL-12":"FL-12","FL-13":"FL-13","FL-14":"FL-14","FL-15":"FL-15","FL-16":"FL-16","FL-17":"FL-17","FL-18":"FL-18","FL-19":"FL-19","FL-20":"FL-20","FL-21":"FL-21","FL-22":"FL-22","FL-23":"FL-23","FL-24":"FL-24","FL-25":"FL-25","FL-26":"FL-26","FL-27":"FL-27","GA-1":"GA-1","GA-2":"GA-2","GA-3":"GA-3","GA-4":"GA-4","GA-5":"GA-5","GA-6":"GA-6","GA-7":"GA-7","GA-8":"GA-8","GA-9":"GA-9","GA-10":"GA-10","GA-11":"GA-11","GA-12":"GA-12","GA-13":"GA-13","GA-14":"GA-14","HI-1":"HI-1","HI-2":"HI-2","ID-1":"ID-1","ID-2":"ID-2","IL-1":"IL-1","IL-2":"IL-2","IL-3":"IL-3","IL-4":"IL-4","IL-5":"IL-5","IL-6":"IL-6","IL-7":"IL-7","IL-8":"IL-8","IL-9":"IL-9","IL-10":"IL-10","IL-11":"IL-11","IL-12":"IL-12","IL-13":"IL-13","IL-14":"IL-14","IL-15":"IL-15","IL-16":"IL-16","IL-17":"IL-17","IL-18":"IL-18","IN-1":"IN-1","IN-2":"IN-2","IN-3":"IN-3","IN-4":"IN-4","IN-5":"IN-5","IN-6":"IN-6","IN-7":"IN-7","IN-8":"IN-8","IN-9":"IN-9","IA-1":"IA-1","IA-2":"IA-2","IA-3":"IA-3","IA-4":"IA-4","KS-1":"KS-1","KS-2":"KS-2","KS-3":"KS-3","KS-4":"KS-4","KY-1":"KY-1","KY-2":"KY-2","KY-3":"KY-3","KY-4":"KY-4","KY-5":"KY-5","KY-6":"KY-6","LA-1":"LA-1","LA-2":"LA-2","LA-3":"LA-3","LA-4":"LA-4","LA-5":"LA-5","LA-6":"LA-6","ME-1":"ME-1","ME-2":"ME-2","MD-1":"MD-1","MD-2":"MD-2","MD-3":"MD-3","MD-4":"MD-4","MD-5":"MD-5","MD-6":"MD-6","MD-7":"MD-7","MD-8":"MD-8","MA-1":"MA-1","MA-2":"MA-2","MA-3":"MA-3","MA-4":"MA-4","MA-5":"MA-5","MA-6":"MA-6","MA-7":"MA-7","MA-8":"MA-8","MA-9":"MA-9","MI-1":"MI-1","MI-2":"MI-2","MI-3":"MI-3","MI-4":"MI-4","MI-5":"MI-5","MI-6":"MI-6","MI-7":"MI-7","MI-8":"MI-8","MI-9":"MI-9","MI-10":"MI-10","MI-11":"MI-11","MI-12":"MI-12","MI-13":"MI-13","MI-14":"MI-14","MN-1":"MN-1","MN-2":"MN-2","MN-3":"MN-3","MN-4":"MN-4","MN-5":"MN-5","MN-6":"MN-6","MN-7":"MN-7","MN-8":"MN-8","MS-1":"MS-1","MS-2":"MS-2","MS-3":"MS-3","MS-4":"MS-4","MO-1":"MO-1","MO-2":"MO-2","MO-3":"MO-3","MO-4":"MO-4","MO-5":"MO-5","MO-6":"MO-6","MO-7":"MO-7","MO-8":"MO-8","MT-1":"MT-1","NE-1":"NE-1","NE-2":"NE-2","NE-3":"NE-3","NV-1":"NV-1","NV-2":"NV-2","NV-3":"NV-3","NV-4":"NV-4","NH-1":"NH-1","NH-2":"NH-2","NJ-1":"NJ-1","NJ-2":"NJ-2","NJ-3":"NJ-3","NJ-4":"NJ-4","NJ-5":"NJ-5","NJ-6":"NJ-6","NJ-7":"NJ-7","NJ-8":"NJ-8","NJ-9":"NJ-9","NJ-10":"NJ-10","NJ-11":"NJ-11","NJ-12":"NJ-12","NM-1":"NM-1","NM-2":"NM-2","NM-3":"NM-3","NY-1":"NY-1","NY-2":"NY-2","NY-3":"NY-3","NY-4":"NY-4","NY-5":"NY-5","NY-6":"NY-6","NY-7":"NY-7","NY-8":"NY-8","NY-9":"NY-9","NY-10":"NY-10","NY-11":"NY-11","NY-12":"NY-12","NY-13":"NY-13","NY-14":"NY-14","NY-15":"NY-15","NY-16":"NY-16","NY-17":"NY-17","NY-18":"NY-18","NY-19":"NY-19","NY-20":"NY-20","NY-21":"NY-21","NY-22":"NY-22","NY-23":"NY-23","NY-24":"NY-24","NY-25":"NY-25","NY-26":"NY-26","NY-27":"NY-27","NC-1":"NC-1","NC-2":"NC-2","NC-3":"NC-3","NC-4":"NC-4","NC-5":"NC-5","NC-6":"NC-6","NC-7":"NC-7","NC-8":"NC-8","NC-9":"NC-9","NC-10":"NC-10","NC-11":"NC-11","NC-12":"NC-12","NC-13":"NC-13","ND-1":"ND-1","OH-1":"OH-1","OH-2":"OH-2","OH-3":"OH-3","OH-4":"OH-4","OH-5":"OH-5","OH-6":"OH-6","OH-7":"OH-7","OH-8":"OH-8","OH-9":"OH-9","OH-10":"OH-10","OH-11":"OH-11","OH-12":"OH-12","OH-13":"OH-13","OH-14":"OH-14","OH-15":"OH-15","OH-16":"OH-16","OK-1":"OK-1","OK-2":"OK-2","OK-3":"OK-3","OK-4":"OK-4","OK-5":"OK-5","OR-1":"OR-1","OR-2":"OR-2","OR-3":"OR-3","OR-4":"OR-4","OR-5":"OR-5","PA-1":"PA-1","PA-2":"PA-2","PA-3":"PA-3","PA-4":"PA-4","PA-5":"PA-5","PA-6":"PA-6","PA-7":"PA-7","PA-8":"PA-8","PA-9":"PA-9","PA-10":"PA-10","PA-11":"PA-11","PA-12":"PA-12","PA-13":"PA-13","PA-14":"PA-14","PA-15":"PA-15","PA-16":"PA-16","PA-17":"PA-17","PA-18":"PA-18","RI-1":"RI-1","RI-2":"RI-2","SC-1":"SC-1","SC-2":"SC-2","SC-3":"SC-3","SC-4":"SC-4","SC-5":"SC-5","SC-6":"SC-6","SC-7":"SC-7","SD-1":"SD-1","TN-1":"TN-1","TN-2":"TN-2","TN-3":"TN-3","TN-4":"TN-4","TN-5":"TN-5","TN-6":"TN-6","TN-7":"TN-7","TN-8":"TN-8","TN-9":"TN-9","TX-1":"TX-1","TX-2":"TX-2","TX-3":"TX-3","TX-4":"TX-4","TX-5":"TX-5","TX-6":"TX-6","TX-7":"TX-7","TX-8":"TX-8","TX-9":"TX-9","TX-10":"TX-10","TX-11":"TX-11","TX-12":"TX-12","TX-13":"TX-13","TX-14":"TX-14","TX-15":"TX-15","TX-16":"TX-16","TX-17":"TX-17","TX-18":"TX-18","TX-19":"TX-19","TX-20":"TX-20","TX-21":"TX-21","TX-22":"TX-22","TX-23":"TX-23","TX-24":"TX-24","TX-25":"TX-25","TX-26":"TX-26","TX-27":"TX-27","TX-28":"TX-28","TX-29":"TX-29","TX-30":"TX-30","TX-31":"TX-31","TX-32":"TX-32","TX-33":"TX-33","TX-34":"TX-34","TX-35":"TX-35","TX-36":"TX-36","UT-1":"UT-1","UT-2":"UT-2","UT-3":"UT-3","UT-4":"UT-4","VT-1":"VT-1","VA-1":"VA-1","VA-2":"VA-2","VA-3":"VA-3","VA-4":"VA-4","VA-5":"VA-5","VA-6":"VA-6","VA-7":"VA-7","VA-8":"VA-8","VA-9":"VA-9","VA-10":"VA-10","VA-11":"VA-11","WA-1":"WA-1","WA-2":"WA-2","WA-3":"WA-3","WA-4":"WA-4","WA-5":"WA-5","WA-6":"WA-6","WA-7":"WA-7","WA-8":"WA-8","WA-9":"WA-9","WA-10":"WA-10","WV-1":"WV-1","WV-2":"WV-2","WV-3":"WV-3","WI-1":"WI-1","WI-2":"WI-2","WI-3":"WI-3","WI-4":"WI-4","WI-5":"WI-5","WI-6":"WI-6","WI-7":"WI-7","WI-8":"WI-8","WY-1":"WY-1","AL-0":"AL-1","AL-AL":"AL-1","AK-0":"AK-1","AK-AL":"AK-1","AZ-0":"AZ-1","AZ-AL":"AZ-1","AR-0":"AR-1","AR-AL":"AR-1","CA-0":"CA-1","CA-AL":"CA-1","CO-0":"CO-1","CO-AL":"CO-1","CT-0":"CT-1","CT-AL":"CT-1","DE-0":"DE-1","DE-AL":"DE-1","FL-0":"FL-1","FL-AL":"FL-1","GA-0":"GA-1","GA-AL":"GA-1","HI-0":"HI-1","HI-AL":"HI-1","ID-0":"ID-1","ID-AL":"ID-1","IL-0":"IL-1","IL-AL":"IL-1","IN-0":"IN-1","IN-AL":"IN-1","IA-0":"IA-1","IA-AL":"IA-1","KS-0":"KS-1","KS-AL":"KS-1","KY-0":"KY-1","KY-AL":"KY-1","LA-0":"LA-1","LA-AL":"LA-1","ME-0":"ME-1","ME-AL":"ME-1","MD-0":"MD-1","MD-AL":"MD-1","MA-0":"MA-1","MA-AL":"MA-1","MI-0":"MI-1","MI-AL":"MI-1","MN-0":"MN-1","MN-AL":"MN-1","MS-0":"MS-1","MS-AL":"MS-1","MO-0":"MO-1","MO-AL":"MO-1","MT-0":"MT-1","MT-AL":"MT-1","NE-0":"NE-1","NE-AL":"NE-1","NV-0":"NV-1","NV-AL":"NV-1","NH-0":"NH-1","NH-AL":"NH-1","NJ-0":"NJ-1","NJ-AL":"NJ-1","NM-0":"NM-1","NM-AL":"NM-1","NY-0":"NY-1","NY-AL":"NY-1","NC-0":"NC-1","NC-AL":"NC-1","ND-0":"ND-1","ND-AL":"ND-1","OH-0":"OH-1","OH-AL":"OH-1","OK-0":"OK-1","OK-AL":"OK-1","OR-0":"OR-1","OR-AL":"OR-1","PA-0":"PA-1","PA-AL":"PA-1","RI-0":"RI-1","RI-AL":"RI-1","SC-0":"SC-1","SC-AL":"SC-1","SD-0":"SD-1","SD-AL":"SD-1","TN-0":"TN-1","TN-AL":"TN-1","TX-0":"TX-1","TX-AL":"TX-1","UT-0":"UT-1","UT-AL":"UT-1","VT-0":"VT-1","VT-AL":"VT-1","VA-0":"VA-1","VA-AL":"VA-1","WA-0":"WA-1","WA-AL":"WA-1","WV-0":"WV-1","WV-AL":"WV-1","WI-0":"WI-1","WI-AL":"WI-1","WY-0":"WY-1","WY-AL":"WY-1"};
csvdata['convert']['counties']={};

csvdata['states']={"AK":{},"AL":{},"AR":{},"AZ":{},"CA":{},"CO":{},"CT":{},"DC":{},"DE":{},"FL":{},"GA":{},"HI":{},"IA":{},"ID":{},"IL":{},"IN":{},"KS":{},"KY":{},"LA":{},"MA":{},"MD":{},"ME":{},"M0":{},"M1":{},"M2":{},"MI":{},"MN":{},"MO":{},"MS":{},"MT":{},"NC":{},"ND":{},"NE":{},"N0":{},"N1":{},"N2":{},"N3":{},"NH":{},"NJ":{},"NM":{},"NV":{},"NY":{},"OH":{},"OK":{},"OR":{},"PA":{},"RI":{},"SC":{},"SD":{},"TN":{},"TX":{},"UT":{},"VA":{},"VT":{},"WA":{},"WI":{},"WV":{},"WY":{}}
csvdata['cds']={"AL-1":{"state":"AL"},"AL-2":{"state":"AL"},"AL-3":{"state":"AL"},"AL-4":{"state":"AL"},"AL-5":{"state":"AL"},"AL-6":{"state":"AL"},"AL-7":{"state":"AL"},"AK-1":{"state":"AK"},"AZ-1":{"state":"AZ"},"AZ-2":{"state":"AZ"},"AZ-3":{"state":"AZ"},"AZ-4":{"state":"AZ"},"AZ-5":{"state":"AZ"},"AZ-6":{"state":"AZ"},"AZ-7":{"state":"AZ"},"AZ-8":{"state":"AZ"},"AZ-9":{"state":"AZ"},"AR-1":{"state":"AR"},"AR-2":{"state":"AR"},"AR-3":{"state":"AR"},"AR-4":{"state":"AR"},"CA-1":{"state":"CA"},"CA-2":{"state":"CA"},"CA-3":{"state":"CA"},"CA-4":{"state":"CA"},"CA-5":{"state":"CA"},"CA-6":{"state":"CA"},"CA-7":{"state":"CA"},"CA-8":{"state":"CA"},"CA-9":{"state":"CA"},"CA-10":{"state":"CA"},"CA-11":{"state":"CA"},"CA-12":{"state":"CA"},"CA-13":{"state":"CA"},"CA-14":{"state":"CA"},"CA-15":{"state":"CA"},"CA-16":{"state":"CA"},"CA-17":{"state":"CA"},"CA-18":{"state":"CA"},"CA-19":{"state":"CA"},"CA-20":{"state":"CA"},"CA-21":{"state":"CA"},"CA-22":{"state":"CA"},"CA-23":{"state":"CA"},"CA-24":{"state":"CA"},"CA-25":{"state":"CA"},"CA-26":{"state":"CA"},"CA-27":{"state":"CA"},"CA-28":{"state":"CA"},"CA-29":{"state":"CA"},"CA-30":{"state":"CA"},"CA-31":{"state":"CA"},"CA-32":{"state":"CA"},"CA-33":{"state":"CA"},"CA-34":{"state":"CA"},"CA-35":{"state":"CA"},"CA-36":{"state":"CA"},"CA-37":{"state":"CA"},"CA-38":{"state":"CA"},"CA-39":{"state":"CA"},"CA-40":{"state":"CA"},"CA-41":{"state":"CA"},"CA-42":{"state":"CA"},"CA-43":{"state":"CA"},"CA-44":{"state":"CA"},"CA-45":{"state":"CA"},"CA-46":{"state":"CA"},"CA-47":{"state":"CA"},"CA-48":{"state":"CA"},"CA-49":{"state":"CA"},"CA-50":{"state":"CA"},"CA-51":{"state":"CA"},"CA-52":{"state":"CA"},"CA-53":{"state":"CA"},"CO-1":{"state":"CO"},"CO-2":{"state":"CO"},"CO-3":{"state":"CO"},"CO-4":{"state":"CO"},"CO-5":{"state":"CO"},"CO-6":{"state":"CO"},"CO-7":{"state":"CO"},"CT-1":{"state":"CT"},"CT-2":{"state":"CT"},"CT-3":{"state":"CT"},"CT-4":{"state":"CT"},"CT-5":{"state":"CT"},"DE-1":{"state":"DE"},"FL-1":{"state":"FL"},"FL-2":{"state":"FL"},"FL-3":{"state":"FL"},"FL-4":{"state":"FL"},"FL-5":{"state":"FL"},"FL-6":{"state":"FL"},"FL-7":{"state":"FL"},"FL-8":{"state":"FL"},"FL-9":{"state":"FL"},"FL-10":{"state":"FL"},"FL-11":{"state":"FL"},"FL-12":{"state":"FL"},"FL-13":{"state":"FL"},"FL-14":{"state":"FL"},"FL-15":{"state":"FL"},"FL-16":{"state":"FL"},"FL-17":{"state":"FL"},"FL-18":{"state":"FL"},"FL-19":{"state":"FL"},"FL-20":{"state":"FL"},"FL-21":{"state":"FL"},"FL-22":{"state":"FL"},"FL-23":{"state":"FL"},"FL-24":{"state":"FL"},"FL-25":{"state":"FL"},"FL-26":{"state":"FL"},"FL-27":{"state":"FL"},"GA-1":{"state":"GA"},"GA-2":{"state":"GA"},"GA-3":{"state":"GA"},"GA-4":{"state":"GA"},"GA-5":{"state":"GA"},"GA-6":{"state":"GA"},"GA-7":{"state":"GA"},"GA-8":{"state":"GA"},"GA-9":{"state":"GA"},"GA-10":{"state":"GA"},"GA-11":{"state":"GA"},"GA-12":{"state":"GA"},"GA-13":{"state":"GA"},"GA-14":{"state":"GA"},"HI-1":{"state":"HI"},"HI-2":{"state":"HI"},"ID-1":{"state":"ID"},"ID-2":{"state":"ID"},"IL-1":{"state":"IL"},"IL-2":{"state":"IL"},"IL-3":{"state":"IL"},"IL-4":{"state":"IL"},"IL-5":{"state":"IL"},"IL-6":{"state":"IL"},"IL-7":{"state":"IL"},"IL-8":{"state":"IL"},"IL-9":{"state":"IL"},"IL-10":{"state":"IL"},"IL-11":{"state":"IL"},"IL-12":{"state":"IL"},"IL-13":{"state":"IL"},"IL-14":{"state":"IL"},"IL-15":{"state":"IL"},"IL-16":{"state":"IL"},"IL-17":{"state":"IL"},"IL-18":{"state":"IL"},"IN-1":{"state":"IN"},"IN-2":{"state":"IN"},"IN-3":{"state":"IN"},"IN-4":{"state":"IN"},"IN-5":{"state":"IN"},"IN-6":{"state":"IN"},"IN-7":{"state":"IN"},"IN-8":{"state":"IN"},"IN-9":{"state":"IN"},"IA-1":{"state":"IA"},"IA-2":{"state":"IA"},"IA-3":{"state":"IA"},"IA-4":{"state":"IA"},"KS-1":{"state":"KS"},"KS-2":{"state":"KS"},"KS-3":{"state":"KS"},"KS-4":{"state":"KS"},"KY-1":{"state":"KY"},"KY-2":{"state":"KY"},"KY-3":{"state":"KY"},"KY-4":{"state":"KY"},"KY-5":{"state":"KY"},"KY-6":{"state":"KY"},"LA-1":{"state":"LA"},"LA-2":{"state":"LA"},"LA-3":{"state":"LA"},"LA-4":{"state":"LA"},"LA-5":{"state":"LA"},"LA-6":{"state":"LA"},"ME-1":{"state":"ME"},"ME-2":{"state":"ME"},"MD-1":{"state":"MD"},"MD-2":{"state":"MD"},"MD-3":{"state":"MD"},"MD-4":{"state":"MD"},"MD-5":{"state":"MD"},"MD-6":{"state":"MD"},"MD-7":{"state":"MD"},"MD-8":{"state":"MD"},"MA-1":{"state":"MA"},"MA-2":{"state":"MA"},"MA-3":{"state":"MA"},"MA-4":{"state":"MA"},"MA-5":{"state":"MA"},"MA-6":{"state":"MA"},"MA-7":{"state":"MA"},"MA-8":{"state":"MA"},"MA-9":{"state":"MA"},"MI-1":{"state":"MI"},"MI-2":{"state":"MI"},"MI-3":{"state":"MI"},"MI-4":{"state":"MI"},"MI-5":{"state":"MI"},"MI-6":{"state":"MI"},"MI-7":{"state":"MI"},"MI-8":{"state":"MI"},"MI-9":{"state":"MI"},"MI-10":{"state":"MI"},"MI-11":{"state":"MI"},"MI-12":{"state":"MI"},"MI-13":{"state":"MI"},"MI-14":{"state":"MI"},"MN-1":{"state":"MN"},"MN-2":{"state":"MN"},"MN-3":{"state":"MN"},"MN-4":{"state":"MN"},"MN-5":{"state":"MN"},"MN-6":{"state":"MN"},"MN-7":{"state":"MN"},"MN-8":{"state":"MN"},"MS-1":{"state":"MS"},"MS-2":{"state":"MS"},"MS-3":{"state":"MS"},"MS-4":{"state":"MS"},"MO-1":{"state":"MO"},"MO-2":{"state":"MO"},"MO-3":{"state":"MO"},"MO-4":{"state":"MO"},"MO-5":{"state":"MO"},"MO-6":{"state":"MO"},"MO-7":{"state":"MO"},"MO-8":{"state":"MO"},"MT-1":{"state":"MT"},"NE-1":{"state":"NE"},"NE-2":{"state":"NE"},"NE-3":{"state":"NE"},"NV-1":{"state":"NV"},"NV-2":{"state":"NV"},"NV-3":{"state":"NV"},"NV-4":{"state":"NV"},"NH-1":{"state":"NH"},"NH-2":{"state":"NH"},"NJ-1":{"state":"NJ"},"NJ-2":{"state":"NJ"},"NJ-3":{"state":"NJ"},"NJ-4":{"state":"NJ"},"NJ-5":{"state":"NJ"},"NJ-6":{"state":"NJ"},"NJ-7":{"state":"NJ"},"NJ-8":{"state":"NJ"},"NJ-9":{"state":"NJ"},"NJ-10":{"state":"NJ"},"NJ-11":{"state":"NJ"},"NJ-12":{"state":"NJ"},"NM-1":{"state":"NM"},"NM-2":{"state":"NM"},"NM-3":{"state":"NM"},"NY-1":{"state":"NY"},"NY-2":{"state":"NY"},"NY-3":{"state":"NY"},"NY-4":{"state":"NY"},"NY-5":{"state":"NY"},"NY-6":{"state":"NY"},"NY-7":{"state":"NY"},"NY-8":{"state":"NY"},"NY-9":{"state":"NY"},"NY-10":{"state":"NY"},"NY-11":{"state":"NY"},"NY-12":{"state":"NY"},"NY-13":{"state":"NY"},"NY-14":{"state":"NY"},"NY-15":{"state":"NY"},"NY-16":{"state":"NY"},"NY-17":{"state":"NY"},"NY-18":{"state":"NY"},"NY-19":{"state":"NY"},"NY-20":{"state":"NY"},"NY-21":{"state":"NY"},"NY-22":{"state":"NY"},"NY-23":{"state":"NY"},"NY-24":{"state":"NY"},"NY-25":{"state":"NY"},"NY-26":{"state":"NY"},"NY-27":{"state":"NY"},"NC-1":{"state":"NC"},"NC-2":{"state":"NC"},"NC-3":{"state":"NC"},"NC-4":{"state":"NC"},"NC-5":{"state":"NC"},"NC-6":{"state":"NC"},"NC-7":{"state":"NC"},"NC-8":{"state":"NC"},"NC-9":{"state":"NC"},"NC-10":{"state":"NC"},"NC-11":{"state":"NC"},"NC-12":{"state":"NC"},"NC-13":{"state":"NC"},"ND-1":{"state":"ND"},"OH-1":{"state":"OH"},"OH-2":{"state":"OH"},"OH-3":{"state":"OH"},"OH-4":{"state":"OH"},"OH-5":{"state":"OH"},"OH-6":{"state":"OH"},"OH-7":{"state":"OH"},"OH-8":{"state":"OH"},"OH-9":{"state":"OH"},"OH-10":{"state":"OH"},"OH-11":{"state":"OH"},"OH-12":{"state":"OH"},"OH-13":{"state":"OH"},"OH-14":{"state":"OH"},"OH-15":{"state":"OH"},"OH-16":{"state":"OH"},"OK-1":{"state":"OK"},"OK-2":{"state":"OK"},"OK-3":{"state":"OK"},"OK-4":{"state":"OK"},"OK-5":{"state":"OK"},"OR-1":{"state":"OR"},"OR-2":{"state":"OR"},"OR-3":{"state":"OR"},"OR-4":{"state":"OR"},"OR-5":{"state":"OR"},"PA-1":{"state":"PA"},"PA-2":{"state":"PA"},"PA-3":{"state":"PA"},"PA-4":{"state":"PA"},"PA-5":{"state":"PA"},"PA-6":{"state":"PA"},"PA-7":{"state":"PA"},"PA-8":{"state":"PA"},"PA-9":{"state":"PA"},"PA-10":{"state":"PA"},"PA-11":{"state":"PA"},"PA-12":{"state":"PA"},"PA-13":{"state":"PA"},"PA-14":{"state":"PA"},"PA-15":{"state":"PA"},"PA-16":{"state":"PA"},"PA-17":{"state":"PA"},"PA-18":{"state":"PA"},"RI-1":{"state":"RI"},"RI-2":{"state":"RI"},"SC-1":{"state":"SC"},"SC-2":{"state":"SC"},"SC-3":{"state":"SC"},"SC-4":{"state":"SC"},"SC-5":{"state":"SC"},"SC-6":{"state":"SC"},"SC-7":{"state":"SC"},"SD-1":{"state":"SD"},"TN-1":{"state":"TN"},"TN-2":{"state":"TN"},"TN-3":{"state":"TN"},"TN-4":{"state":"TN"},"TN-5":{"state":"TN"},"TN-6":{"state":"TN"},"TN-7":{"state":"TN"},"TN-8":{"state":"TN"},"TN-9":{"state":"TN"},"TX-1":{"state":"TX"},"TX-2":{"state":"TX"},"TX-3":{"state":"TX"},"TX-4":{"state":"TX"},"TX-5":{"state":"TX"},"TX-6":{"state":"TX"},"TX-7":{"state":"TX"},"TX-8":{"state":"TX"},"TX-9":{"state":"TX"},"TX-10":{"state":"TX"},"TX-11":{"state":"TX"},"TX-12":{"state":"TX"},"TX-13":{"state":"TX"},"TX-14":{"state":"TX"},"TX-15":{"state":"TX"},"TX-16":{"state":"TX"},"TX-17":{"state":"TX"},"TX-18":{"state":"TX"},"TX-19":{"state":"TX"},"TX-20":{"state":"TX"},"TX-21":{"state":"TX"},"TX-22":{"state":"TX"},"TX-23":{"state":"TX"},"TX-24":{"state":"TX"},"TX-25":{"state":"TX"},"TX-26":{"state":"TX"},"TX-27":{"state":"TX"},"TX-28":{"state":"TX"},"TX-29":{"state":"TX"},"TX-30":{"state":"TX"},"TX-31":{"state":"TX"},"TX-32":{"state":"TX"},"TX-33":{"state":"TX"},"TX-34":{"state":"TX"},"TX-35":{"state":"TX"},"TX-36":{"state":"TX"},"UT-1":{"state":"UT"},"UT-2":{"state":"UT"},"UT-3":{"state":"UT"},"UT-4":{"state":"UT"},"VT-1":{"state":"VT"},"VA-1":{"state":"VA"},"VA-2":{"state":"VA"},"VA-3":{"state":"VA"},"VA-4":{"state":"VA"},"VA-5":{"state":"VA"},"VA-6":{"state":"VA"},"VA-7":{"state":"VA"},"VA-8":{"state":"VA"},"VA-9":{"state":"VA"},"VA-10":{"state":"VA"},"VA-11":{"state":"VA"},"WA-1":{"state":"WA"},"WA-2":{"state":"WA"},"WA-3":{"state":"WA"},"WA-4":{"state":"WA"},"WA-5":{"state":"WA"},"WA-6":{"state":"WA"},"WA-7":{"state":"WA"},"WA-8":{"state":"WA"},"WA-9":{"state":"WA"},"WA-10":{"state":"WA"},"WV-1":{"state":"WV"},"WV-2":{"state":"WV"},"WV-3":{"state":"WV"},"WI-1":{"state":"WI"},"WI-2":{"state":"WI"},"WI-3":{"state":"WI"},"WI-4":{"state":"WI"},"WI-5":{"state":"WI"},"WI-6":{"state":"WI"},"WI-7":{"state":"WI"},"WI-8":{"state":"WI"},"WY-1":{"state":"WY"}};

csvdata['counties']={}

csvdata['convert']['states']['ME-1']="M1";
csvdata['convert']['states']['ME-2']="M2";
csvdata['convert']['states']['NE-1']="N1";
csvdata['convert']['states']['NE-2']="N2";
csvdata['convert']['states']['NE-3']="N3";

/*
var districts = {'al': ['3', '2', '7', '5', '4', '1', '6'], 'ak': ['0'], 'az': ['6', '2', '9', '4', '1', '7', '5', '8', '3'], 'ar': ['2', '3', '4', '1'], 'ca': ['30', '6', '29', '34', '11', '5', '15', '28', '33', '17', '26', '25', '24', '23', '38', '48', '49', '45', '2', '43', '51', '22', '40', '44', '36', '42', '41', '35', '50', '37', '10', '27', '31', '9', '52', '53', '21', '18', '14', '13', '4', '32', '3', '8', '39', '47', '16', '19', '20', '7', '1', '12', '46'], 'co': ['2', '4', '3', '6', '5', '7', '1'], 'ct': ['1', '5', '3', '2', '4'], 'de': ['0'], 'fl': ['19', '20', '25', '26', '27', '11', '6', '4', '24', '22', '21', '7', '8', '17', '23', '5', '2', '18', '16', '13', '12', '9', '3', '10', '14', '15', '1'], 'ga': ['1', '7', '2', '6', '3', '13', '11', '12', '9', '14', '4', '8', '10', '5'], 'hi': ['1', '2'], 'id': ['1', '2'], 'il': ['2', '12', '15', '17', '13', '11', '4', '18', '1', '3', '7', '9', '6', '8', '5', '10', '14', '16'], 'in': ['4', '5', '2', '7', '1', '9', '3', '6', '8'], 'ia': ['1', '3', '4', '2'], 'ks': ['3', '1', '2', '4'], 'ky': ['6', '2', '3', '5', '1', '4'], 'la': ['5', '1', '6', '2', '3', '4'], 'me': ['2', '1'], 'md': ['4', '5', '1', '3', '7', '8', '6', '2'], 'ma': ['2', '1', '8', '9', '4', '6', '7', '5', '3'], 'mi': ['2', '3', '13', '4', '6', '12', '1', '11', '8', '5', '14', '10', '9', '7'], 'mn': ['2', '7', '1', '8', '3', '5', '6', '4'], 'ms': ['1', '3', '4', '2'], 'mo': ['8', '3', '7', '4', '6', '5', '2', '1'], 'mt': ['0'], 'ne': ['3', '2', '1'], 'nv': ['2', '4', '3', '1'], 'nh': ['1', '2'], 'nj': ['5', '11', '9', '3', '8', '7', '12', '1', '2', '4', '6', '10'], 'nm': ['1', '2', '3'], 'ny': ['22', '5', '6', '14', '12', '8', '7', '24', '23', '26', '20', '19', '17', '3', '11', '4', '9', '10', '27', '15', '13', '25', '21', '16', '2', '18', '1'], 'nc': ['3', '9', '12', '10', '7', '6', '2', '1', '11', '4', '13', '5', '8'], 'nd': ['0'], 'oh': ['4', '1', '16', '2', '12', '3', '15', '5', '6', '7', '13', '11', '14', '9', '8', '10'], 'ok': ['3', '4', '5', '2', '1'], 'or': ['4', '3', '2', '1', '5'], 'pa': ['9', '18', '8', '3', '10', '14', '7', '15', '12', '1', '17', '11', '13', '2', '5', '4', '16', '6'], 'ri': ['1', '2'], 'sc': ['7', '2', '6', '1', '3', '5', '4'], 'sd': ['0'], 'tn': ['8', '9', '6', '3', '7', '1', '2', '4', '5'], 'tx': ['26', '14', '6', '15', '18', '22', '9', '2', '7', '36', '10', '8', '29', '19', '27', '34', '32', '24', '33', '30', '4', '13', '1', '28', '35', '16', '5', '25', '23', '11', '12', '31', '3', '21', '20', '17'], 'ut': ['3', '2', '1', '4'], 'vt': ['0'], 'va': ['1', '2', '6', '4', '3', '11', '10', '5', '9', '8', '7'], 'wa': ['2', '3', '1', '10', '5', '7', '6', '4', '8', '9'], 'wv': ['1', '2', '3'], 'wi': ['8', '6', '5', '7', '1', '2', '3', '4'], 'wy': ['0']}

for (var d in districts){
	for (var i=0;i<districts[d].length;i++){
		var cdID = d.toUpperCase()+"-"+(i+1);
		csvdata['cds'][cdID]={'state':d.toUpperCase()};
		csvdata['convert']['cds'][cdID]=cdID;
		if (i==0){
			csvdata['convert']['cds'][d.toUpperCase()+"-"+(i)]=cdID;
			csvdata['convert']['cds'][d.toUpperCase()+"-AL"]=cdID;
		}
	}
	
	
}
console.log(JSON.stringify(csvdata['convert']['cds']));
console.log(JSON.stringify(csvdata['cds']));*/


function loadAllData() {
	fs.readFile("predictions16.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var econPred16 = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
	
		for (var i=1;i<econPred16.data.length;i++){
			if (econPred16.data[i].length < 5){
				continue;
			}
			csvdata['states'][econPred16.data[i][0]]['econPreddwin16']=parseFloat(econPred16.data[i][4]);
			csvdata['states'][econPred16.data[i][0]]['econPreddelo16']=(parseFloat(econPred16.data[i][1])-.5)*2000;
		}
		//console.log(JSON.stringify(csvdata['convert']['states']));
	})
	fs.readFile("predictions.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var econPred20 = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
	
		for (var i=1;i<econPred20.data.length;i++){
			if (econPred20.data[i].length < 8){
				continue;
			}
			csvdata['states'][econPred20.data[i][3]]['econPreddwin20']=parseFloat(econPred20.data[i][7]);
			csvdata['states'][econPred20.data[i][3]]['econPreddelo20']=(parseFloat(econPred20.data[i][6])-.5)*2000;
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("data/state_priors_08_12_16.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
	
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 8){
				continue;
			}
			if (data.data[i][4] != "0"){
				continue;
			}
			var year = parseInt(data.data[i][0])-2000;
			csvdata['states'][data.data[i][1]]['econPreddelo'+year]=(parseFloat(data.data[i][2])-.5)*2000;
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("ev.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
	
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 11){
				continue;
			}
			csvdata['states'][data.data[i][0]]['ev10']=parseInt(data.data[i][8]);
			csvdata['states'][data.data[i][0]]['closing']=parseFloat(data.data[i][10]);
			//csvdata['states'][data.data[i][0]]['closing']=parseFloat(data.data[i][10]);
			csvdata['states'][data.data[i][0]]['name']=data.data[i][7];
			csvdata['convert']['states'][data.data[i][7].toUpperCase()]=data.data[i][0];
		}
		csvdata['states']["M0"]['ev10']=2;
		csvdata['states']["M1"]['ev10']=1;
		csvdata['states']["M2"]['ev10']=1;
		csvdata['states']["N0"]['ev10']=2;
		csvdata['states']["N1"]['ev10']=1;
		csvdata['states']["N2"]['ev10']=1;
		csvdata['states']["N3"]['ev10']=1;
		csvdata['states']["M0"]['name']='Maine';
		csvdata['states']["M1"]['name']='Maine 1st';
		csvdata['states']["M2"]['name']='Maine 2nd';
		csvdata['states']["N0"]['name']='Nebraska';
		csvdata['states']["N1"]['name']='Nebraska 1st';
		csvdata['states']["N2"]['name']='Nebraska 2nd';
		csvdata['states']["N3"]['name']='Nebraska 3rd';
		csvdata['states']["M0"]['closing']=csvdata['states']['ME']['closing'];
		csvdata['states']["M1"]['closing']=csvdata['states']['ME']['closing'];
		csvdata['states']["M2"]['closing']=csvdata['states']['ME']['closing'];
		csvdata['states']["N0"]['closing']=csvdata['states']['NE']['closing'];
		csvdata['states']["N1"]['closing']=csvdata['states']['NE']['closing'];
		csvdata['states']["N2"]['closing']=csvdata['states']['NE']['closing'];
		csvdata['states']["N3"]['closing']=csvdata['states']['NE']['closing'];
		
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("2018vep.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
	
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 10){
				continue;
			}
			csvdata['states'][data.data[i][0]]['vep']=parseInt(data.data[i][8]);
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("data/presidential_state_toplines_2020.csv", 'utf8', function(err, fileData) {
		if (err){
			console.log(err);
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
		var modeldate = data.data[1][3];
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 15){
				continue;
			}
			if (data.data[i][3] != modeldate){
				continue;
			}
			var state = csvdata['convert']['states'][data.data[i][7].toUpperCase()];
			if (state=='ME'){state="M0";}
			if (state=='NE'){state="N0";}
			csvdata['states'][state]['538Preddwin20']=parseFloat(data.data[i][11]);
			csvdata['states'][state]['538Preddelo20']=(parseFloat(data.data[i][14])-parseFloat(data.data[i][13]))*10;
			csvdata['states'][state]['538tipping']=parseFloat(data.data[i][8]);
			csvdata['states'][state]['538vpi']=parseFloat(data.data[i][9]);
			
			if (state=='M0'){
				state="ME";
				csvdata['states'][state]['538Preddwin20']=parseFloat(data.data[i][11]);
				csvdata['states'][state]['538Preddelo20']=(parseFloat(data.data[i][14])-parseFloat(data.data[i][13]))*10;
				csvdata['states'][state]['538vpi']=parseFloat(data.data[i][9]);
				if (csvdata['states'][state]['538tipping']){
					csvdata['states'][state]['538tipping']+=parseFloat(data.data[i][8]);
				}
				else {
					csvdata['states'][state]['538tipping']=parseFloat(data.data[i][8]);
				}
				
			}
			else if (state=='M1' || state =='M2'){
				state="ME";
				if (csvdata['states'][state]['538tipping']){
					csvdata['states'][state]['538tipping']+=parseFloat(data.data[i][8]);
				}
				else {
					csvdata['states'][state]['538tipping']=parseFloat(data.data[i][8]);
				}
			}
			if (state=='N0'){
				state="NE";
				csvdata['states'][state]['538Preddwin20']=parseFloat(data.data[i][11]);
				csvdata['states'][state]['538Preddelo20']=(parseFloat(data.data[i][14])-parseFloat(data.data[i][13]))*10;
				csvdata['states'][state]['538vpi']=parseFloat(data.data[i][9]);
				if (csvdata['states'][state]['538tipping']){
					csvdata['states'][state]['538tipping']+=parseFloat(data.data[i][8]);
				}
				else {
					csvdata['states'][state]['538tipping']=parseFloat(data.data[i][8]);
				}
				
			}
			else if (state=='N1' || state =='N2' || state =='N3'){
				state="NE";
				if (csvdata['states'][state]['538tipping']){
					csvdata['states'][state]['538tipping']+=parseFloat(data.data[i][8]);
				}
				else {
					csvdata['states'][state]['538tipping']=parseFloat(data.data[i][8]);
				}
			}
			
			
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("data/senate_state_toplines_2020.csv", 'utf8', function(err, fileData) {
		if (err){
			console.log(err);
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
		var modeldate = data.data[1][3];
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 15){
				continue;
			}
			if (data.data[i][3] != modeldate){
				continue;
			}
			var state = csvdata['convert']['states'][data.data[i][2].substr(0,2).toUpperCase()];
			
			if (data.data[i][4] != "_classic"){
				continue;
			}
			
			if (data.data[i][2] == "GA-S3"){
				if (csvdata['states'][state]['538tippingSen']){
					csvdata['states'][state]['538tippingSen']+=parseFloat(data.data[i][27]);
				}
				else {
					csvdata['states'][state]['538tippingSen']=parseFloat(data.data[i][27]);
				}
			}
			else {
				csvdata['states'][state]['538PredSendwin20']=parseFloat(data.data[i][25]);
				csvdata['states'][state]['538PredSendelo20']=parseFloat(data.data[i][65])*10;
				csvdata['states'][state]['538tippingSen']=parseFloat(data.data[i][27]);
			}
			
			
			
			
			
			
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("data/538pred.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});

		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 10){
				continue;
			}
			if (data.data[i][5] != data.data[i][4]){
				continue;
			}
			if (data.data[i][6] != "polls-plus" && data.data[i][6] != ""){
				continue;
			}
			if (data.data[i][2] == "US"){
				continue;
			}
			var year = parseInt(data.data[i][0])-2000;
			var state = csvdata['convert']['states'][data.data[i][2]];
			if (data.data[i][7] =="D"){
				csvdata['states'][state]['538Preddwin'+year]=parseFloat(data.data[i][11]);
				if (data.data[i][9] != ""){
					if (csvdata['states'][state]['538Preddelo'+year]){
						csvdata['states'][state]['538Preddelo'+year]+=parseFloat(data.data[i][9])*10
					}
					else {
						csvdata['states'][state]['538Preddelo'+year]=parseFloat(data.data[i][9])*10
					}
				}
			}
			else if (data.data[i][7] =="R" && data.data[i][9] != ""){
				
				if (csvdata['states'][state]['538Preddelo'+year]){
					csvdata['states'][state]['538Preddelo'+year]-=parseFloat(data.data[i][9])*10
				}
				else {
					csvdata['states'][state]['538Preddelo'+year]=-1*parseFloat(data.data[i][9])*10
				}
			}
			
			
			
			
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("data/us_senate_elections.csv", 'utf8', function(err, fileData) {
		if (err){
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});

		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 10){
				continue;
			}
			if (data.data[i][6] != data.data[i][5]){
				continue;
			}
			if (data.data[i][7] != "polls-plus" && data.data[i][7] != "classic" && data.data[i][7] != ""){
				continue;
			}
			if (data.data[i][2] == "US"){
				continue;
			}
			var year = parseInt(data.data[i][0])-2000;
			var state = csvdata['convert']['states'][data.data[i][2]];
			var str = '538PredSen';
			if (data.data[i][4] == "TRUE" || data.data[i][4] == "1"){
				str += 'Spec';
			}
			if (data.data[i][8] =="D"){
				csvdata['states'][state][str+'dwin'+year]=parseFloat(data.data[i][12]);
				if (data.data[i][10] != ""){
					if (csvdata['states'][state][str+'delo'+year]){
						csvdata['states'][state][str+'delo'+year]+=parseFloat(data.data[i][10])*10
					}
					else {
						csvdata['states'][state][str+'delo'+year]=parseFloat(data.data[i][10])*10
					}
				}
			}
			else if (data.data[i][8] =="R" && data.data[i][10] != ""){
				
				if (csvdata['states'][state][str+'delo'+year]){
					csvdata['states'][state][str+'delo'+year]-=parseFloat(data.data[i][10])*10
				}
				else {
					csvdata['states'][state][str+'delo'+year]=-1*parseFloat(data.data[i][10])*10
				}
			}
			
			
			
			
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	fs.readFile("data/1976-2016-president.csv", 'utf8', function(err, fileData) {//From MIT elect lab
		if (err){
			crash;
		}
		var data = Papa.parse(fileData, {
			delimiter: ",",
			skipEmptyLines: false,
			quoteChar: '"',
		});
		var candidates = {};
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 10){
				continue;
			}
			var year = parseInt(data.data[i][0]);
			var party = data.data[i][8].substr(0,8).toLowerCase();
			if (party == "democrat"){
				party = "D";
				if (candidates[data.data[i][7]]){
					candidates[data.data[i][7]][year]="D";
				}
				else {
					candidates[data.data[i][7]]={};
					candidates[data.data[i][7]][year]="D";
				}
			}
			if (party == "republic"){
				party = "R";
				if (candidates[data.data[i][7]]){
					candidates[data.data[i][7]][year]="R";
				}
				else {
					candidates[data.data[i][7]]={};
					candidates[data.data[i][7]][year]="R";
				}
			}
		}
		for (var i=1;i<data.data.length;i++){
			if (data.data[i].length < 10){
				continue;
			}
			var party = data.data[i][8].substr(0,8).toLowerCase();
			var year = parseInt(data.data[i][0]);
			if (party == "democrat"){
				party = "D";
			}
			else if (party == "republic"){
				party = "R";
			}
			else if (candidates[data.data[i][7]] && candidates[data.data[i][7]][year]){
				party = candidates[data.data[i][7]][year];
			}
			else {
				continue;
			}
			
			csvdata['convert']['states'][data.data[i][3]]=data.data[i][2];//FIPS
			csvdata['convert']['states']['0'+data.data[i][3]]=data.data[i][2];//FIPS
			csvdata['convert']['states']['CEN'+data.data[i][4]]=data.data[i][2];//CENSUS
			csvdata['convert']['states']['IC'+data.data[i][4]]=data.data[i][2];//ICPSR
			
			
			
			if (party == "D"){
				if (csvdata['states'][data.data[i][2]]['dvotes'+year]){
					csvdata['states'][data.data[i][2]]['dvotes'+year]+=parseInt(data.data[i][10]);
				}
				else {
					csvdata['states'][data.data[i][2]]['dvotes'+year]=parseInt(data.data[i][10]);
				}
				csvdata['states'][data.data[i][2]]['tvotes'+year]=parseInt(data.data[i][11]);
			}
			else if (party == "R"){
				if (csvdata['states'][data.data[i][2]]['rvotes'+year]){
					csvdata['states'][data.data[i][2]]['rvotes'+year]+=parseInt(data.data[i][10]);
				}
				else {
					csvdata['states'][data.data[i][2]]['rvotes'+year]=parseInt(data.data[i][10]);
				}
				csvdata['states'][data.data[i][2]]['tvotes'+year]=parseInt(data.data[i][11]);
			}
			
			
			
			
		}
		//console.log(JSON.stringify(csvdata['states']));
	})
	
	
	
	
	
}

loadAllData();


app.get(['/predict','/predict.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/datatable.html',{

		}));
		res.end();
	}
);

app.get(['/electoral','/electoral.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/electoraltable.html',{

		}));
		res.end();
	}
);

app.get(['/senate','/senate.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/senatetable.html',{

		}));
		res.end();
	}
);

app.get(['/house','/house.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/house.html',{

		}));
		res.end();
	}
);

app.get(['/map','/map.html'],
	function(req, res){
		
		var eData = [{'abbrev': 'dc', 'votes16': 295553, 'ev10': 3, 'pres08': 0.06599232, 'pres12': 0.07412351, 'rperc': 0.04304812}, {'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		for (var i=0;i<eData.length;i++){
			eData[i].rpred = eData[i].rperc;
			//eData[i].rpred = eData[i].pres08;
			eData[i].pres16 = eData[i].rperc;
			delete eData[i].rperc;
		}
		res.write(nunjucks.render('templates/map.html',{
			electoralData: eData,

		}));
		res.end();
	}
);

app.get(['/housemap','/housemap.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/housedata.html',{
			//electoralData: eData,

		}));
		res.end();
	}
);

app.get(['/carving','/carving.html'],
	function(req, res){
		
		
		res.write(nunjucks.render('templates/carving.html',{
			//electoralData: eData,

		}));
		res.end();
	}
);


app.post(['/housemap','/housemap.html'],
	function(req, res){
		console.log(req.body);
		
		res.write(nunjucks.render('templates/housedata.html',{
			//electoralData: eData,
			districts: false,
			

		}));
		res.end();
	}
);

app.post(['/senatemap','/senatemap.html'],
	function(req, res){
		var userData16 = {};
		var userData20 = {};
		for (var i in req.body){
			if (req.body[i] != ''){
				var p = parseFloat(req.body[i]);
				var state = i.split('-');
				if (state.length > 4){
					continue;
				}
				if (state[1]=="2016"){
					userData16[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				else if (state[1]=="2020"){
					userData20[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				
			}
		}
		for (var i in req.body){
			if (req.body[i] != ''){
				var p = parseFloat(req.body[i]);
				var state = i.split('-');
				if (state.length > 3){
					continue;
				}
				if (state[1]=="2016"){
					userData16[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				else if (state[1]=="2020"){
					userData20[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				
			}
		}
		for (var i in req.body){
			if (req.body[i] != ''){
				var p = parseFloat(req.body[i]);
				var state = i.split('-');
				if (state[1]=="2016" && state.length>4){
					userData16[state[0].toLowerCase()]["pres20"]=p;
				}
				else if (state[1]=="2020" && state.length>4){
					userData20[state[0].toLowerCase()]["pres20"]=p;
				}
				else if (state[1]=="2016" && state.length>3){
					userData16[state[0].toLowerCase()]["sen20"]=p;
				}
				else if (state[1]=="2020" && state.length>3){
					userData20[state[0].toLowerCase()]["sen20"]=p;
				}
				
			}
		}
		var eData = {'al': {'pres08': 0.60890903, 'pres12': 0.61216229, 'pres16': 0.64374144, 2006: [], 2008: [0.63436655], 2010: [0.65250101], 2012: [], 2014: [1.0], 2016: [0.6407024], 2018: [0.48]}, 'ak': {'pres08': 0.61064785, 'pres12': 0.5731529, 'pres16': 0.58385655, 2006: [], 2008: [0.49340245], 2010: [0.60204528], 2012: [], 2014: [0.51135248], 2016: [0.79237048], 2018: []}, 'az': {'pres08': 0.54313901, 'pres12': 0.5461338, 'pres16': 0.51890023, 2006: [0.55081266], 2008: [], 2010: [0.62944331], 2012: [0.51586059], 2014: [.5686], 2016: [0.56860915], 2018: [0.49]}, 'ar': {'pres08': 0.60171721, 'pres12': 0.62154405, 'pres16': 0.64285138, 2006: [], 2008: [0.0], 2010: [0.61048104], 2012: [], 2014: [0.58895833], 2016: [0.62299334], 2018: []}, 'ca': {'pres08': 0.3772155, 'pres12': 0.38127189, 'pres16': 0.33871779, 2006: [0.37074264], 2008: [], 2010: [0.4469534], 2012: [0.37475716], 2014: [], 2016: [0.0], 2018: [0.0]}, 'co': {'pres08': 0.45449365, 'pres12': 0.47252012, 'pres16': 0.47316667, 2006: [], 2008: [0.44593471], 2010: [0.49138188], 2012: [], 2014: [0.51029203], 2016: [0.46995547], 2018: []}, 'ct': {'pres08': 0.38681662, 'pres12': 0.41227423, 'pres16': 0.42858452, 2006: [0.1949818], 2008: [], 2010: [0.45158195], 2012: [0.43259142], 2014: [], 2016: [0.37506846], 2018: [0.42]}, 'de': {'pres08': 0.37361861, 'pres12': 0.40553045, 'pres16': 0.44001379, 2006: [0.29019438], 2008: [0.35313487], 2010: [0.41422921], 2012: [0.30358291], 2014: [0.43064259], 2016: [], 2018: [0.4]}, 'dc': {'pres08': 0.06599232, 'pres12': 0.07412351, 'pres16': 0.04304812, 2006: [], 2008: [], 2010: [], 2012: [], 2014: [], 2016: [], 2018: []}, 'fl': {'pres08': 0.4858034, 'pres12': 0.49557748, 'pres16': 0.50618835, 2006: [0.38716405], 2008: [], 2010: [0.70766787], 2012: [0.43327351], 2014: [], 2016: [0.53980578], 2018: [0.51]}, 'ga': {'pres08': 0.52628336, 'pres12': 0.53956649, 'pres16': 0.52661173, 2006: [], 2008: [0.31525622], 2010: [0.59921654], 2012: [], 2014: [0.53915937], 2016: [0.57175417], 2018: []}, 'hi': {'pres08': 0.27006274, 'pres12': 0.28296151, 'pres16': 0.32558663, 2006: [0.37481237], 2008: [], 2010: [0.22381407], 2012: [0.37398457], 2014: [0.28421294], 2016: [0.23206356], 2018: [0.28]}, 'id': {'pres08': 0.6302459, 'pres12': 0.66421387, 'pres16': 0.68310177, 2006: [], 2008: [0.6283206], 2010: [0.7406148], 2012: [], 2014: [0.65328362], 2016: [0.70459902], 2018: []}, 'il': {'pres08': 0.37265736, 'pres12': 0.41422477, 'pres16': 0.40979949, 2006: [], 2008: [0.29604426], 2010: [0.50846441], 2012: [], 2014: [0.44361346], 2016: [0.42032449], 2018: []}, 'in': {'pres08': 0.49478047, 'pres12': 0.55200375, 'pres16': 0.6011731, 2006: [1.0], 2008: [], 2010: [0.57707812], 2012: [0.46944677], 2014: [], 2016: [0.55130669], 2018: [0.53]}, 'ia': {'pres08': 0.45151222, 'pres12': 0.47040648, 'pres16': 0.55063548, 2006: [], 2008: [0.3729219], 2010: [0.6589727], 2012: [], 2014: [0.54349482], 2016: [0.62760265], 2018: []}, 'ks': {'pres08': 0.57612276, 'pres12': 0.61113327, 'pres16': 0.6111147, 2006: [], 2008: [0.62225807], 2010: [0.72657045], 2012: [], 2014: [1.0], 2016: [0.65854281], 2018: []}, 'ky': {'pres08': 0.58233428, 'pres12': 0.61542772, 'pres16': 0.65670629, 2006: [], 2008: [0.5296562], 2010: [0.55740479], 2012: [], 2014: [0.57980287], 2016: [0.57274552], 2018: []}, 'la': {'pres08': 0.59457174, 'pres12': 0.58746826, 'pres16': 0.60171677, 2006: [], 2008: [0.46736119], 2010: [0.60018691], 2012: [], 2014: [0.52308918], 2016: [0.6065461], 2018: []}, 'me': {'pres08': 0.41170475, 'pres12': 0.42140079, 'pres16': 0.48403209, 2006: [0.78190647], 2008: [0.61383512], 2010: [], 2012: [0.36758826], 2014: [0.6848842], 2016: [], 2018: [0.46]}, 'md': {'pres08': 0.37069913, 'pres12': 0.36678274, 'pres16': 0.3598375, 2006: [0.44913586], 2008: [], 2010: [0.36503012], 2012: [0.31988415], 2014: [], 2016: [0.36944741], 2018: [0.36]}, 'ma': {'pres08': 0.36802922, 'pres12': 0.38214319, 'pres16': 0.35348721, 2006: [0.30594329], 2008: [0.31954391], 2010: [], 2012: [0.46222761], 2014: [0.38039881], 2016: [], 2018: [0.4]}, 'mi': {'pres08': 0.41628698, 'pres12': 0.45199468, 'pres16': 0.50117668, 2006: [0.42027743], 2008: [0.35069675], 2010: [], 2012: [0.39247231], 2014: [0.43076489], 2016: [], 2018: [0.47]}, 'mn': {'pres08': 0.44770625, 'pres12': 0.46058774, 'pres16': 0.49168306, 2006: [0.39520086], 2008: [0.49993567], 2010: [], 2012: [0.31880698], 2014: [0.44668105], 2016: [], 2018: [0.39, 0.46]}, 'ms': {'pres08': 0.56641931, 'pres12': 0.55801899, 'pres16': 0.59089847, 2006: [0.64582582], 2008: [0.61435046, 1.0], 2010: [], 2012: [0.58497246], 2014: [0.61250809], 2016: [], 2018: [0.54, 0.59]}, 'mo': {'pres08': 0.50067579, 'pres12': 0.54778667, 'pres16': 0.59818561, 2006: [0.48828579], 2008: [], 2010: [0.57170253], 2012: [0.41642216], 2014: [], 2016: [0.51460769], 2018: [0.52]}, 'mt': {'pres08': 0.51169403, 'pres12': 0.57034232, 'pres16': 0.61109664, 2006: [0.49550398], 2008: [0.27084022], 2010: [], 2012: [0.48010454], 2014: [0.5905309], 2016: [], 2018: [0.49]}, 'ne': {'pres08': 0.57609074, 'pres12': 0.6112939, 'pres16': 0.63547674, 2006: [0.36117208], 2008: [0.58948417], 2010: [], 2012: [0.57774433], 2014: [0.67141916], 2016: [], 2018: [0.58]}, 'nv': {'pres08': 0.43613262, 'pres12': 0.46592458, 'pres16': 0.48706291, 2006: [0.57456391], 2008: [], 2010: [0.46972576], 2012: [0.50640453], 2014: [], 2016: [0.4867684], 2018: [0.48]}, 'nh': {'pres08': 0.45131459, 'pres12': 0.47166248, 'pres16': 0.49802972, 2006: [], 2008: [0.46727682], 2010: [0.61987508], 2012: [], 2014: [0.48372457], 2016: [0.49928206], 2018: []}, 'nj': {'pres08': 0.4213537, 'pres12': 0.41048034, 'pres16': 0.4271581, 2006: [0.45381917], 2008: [0.42817144], 2010: [], 2012: [0.40079838], 2014: [0.43118622], 2016: [], 2018: [0.46]}, 'nm': {'pres08': 0.423351, 'pres12': 0.44704795, 'pres16': 0.45349205, 2006: [0.0009095], 2008: [0.38672009], 2010: [], 2012: [0.47024206], 2014: [0.4444119], 2016: [], 2018: [0.46]}, 'ny': {'pres08': 0.34236143, 'pres12': 0.33957305, 'pres16': 0.36588494, 2006: [0.31005976], 2008: [], 2010: [0.28912171, 0.32047667], 2012: [0.25521923], 2014: [], 2016: [0.26488753], 2018: [0.33]}, 'nc': {'pres08': 0.49834037, 'pres12': 0.51034035, 'pres16': 0.51903746, 2006: [], 2008: [0.45627065], 2010: [0.56011479], 2012: [], 2014: [0.50814164], 2016: [0.5295356], 2018: []}, 'nd': {'pres08': 0.54408656, 'pres12': 0.60111208, 'pres16': 0.69809243, 2006: [0.30022418], 2008: [], 2010: [0.77431769], 2012: [0.49540874], 2014: [], 2016: [0.82222304], 2018: [0.55]}, 'oh': {'pres08': 0.47666159, 'pres12': 0.48485943, 'pres16': 0.54267685, 2006: [0.43824268], 2008: [], 2010: [0.59060974], 2012: [0.46855014], 2014: [], 2016: [0.6096339], 2018: [0.47]}, 'ok': {'pres08': 0.65645081, 'pres12': 0.6677232, 'pres16': 0.69304737, 2006: [], 2008: [0.59125435], 2010: [0.72994506], 2012: [], 2014: [0.70433441, 0.70069755], 2016: [0.73375957], 2018: []}, 'or': {'pres08': 0.41586279, 'pres12': 0.43728833, 'pres16': 0.43844161, 2006: [], 2008: [0.4822608], 2010: [0.40683808], 2012: [], 2014: [0.3981479], 2016: [0.37074179], 2018: []}, 'pa': {'pres08': 0.44770296, 'pres12': 0.47268066, 'pres16': 0.50375536, 2006: [0.41316242], 2008: [], 2010: [0.51008495], 2012: [0.45369023], 2014: [], 2016: [0.5074518], 2018: [0.44]}, 'ri': {'pres08': 0.35801862, 'pres12': 0.35983254, 'pres16': 0.41689296, 2006: [0.46481365], 2008: [0.26595516], 2010: [], 2012: [0.35043714], 2014: [0.29297096], 2016: [], 2018: [0.38]}, 'sc': {'pres08': 0.54544429, 'pres12': 0.55308255, 'pres16': 0.57460256, 2006: [], 2008: [0.57656381], 2010: [0.68980125], 2012: [], 2014: [0.59569856, 0.62230132], 2016: [0.6379825], 2018: []}, 'sd': {'pres08': 0.54295707, 'pres12': 0.59218499, 'pres16': 0.65971858, 2006: [], 2008: [0.37508308], 2010: [1.0], 2012: [], 2014: [0.63056851], 2016: [0.71827862], 2018: []}, 'tn': {'pres08': 0.57631472, 'pres12': 0.60351072, 'pres16': 0.63624343, 2006: [0.51379506], 2008: [0.6730593], 2010: [], 2012: [0.68093205], 2014: [0.66003874], 2016: [], 2018: [0.54]}, 'tx': {'pres08': 0.55935937, 'pres12': 0.58007897, 'pres16': 0.54713226, 2006: [0.63120576], 2008: [0.56135139], 2010: [], 2012: [0.58154549], 2014: [0.64175457], 2016: [], 2018: [0.51]}, 'ut': {'pres08': 0.64526361, 'pres12': 0.74626189, 'pres16': 0.62382898, 2006: [0.6674911], 2008: [], 2010: [0.65274435], 2012: [0.68537887], 2014: [], 2016: [0.71578547], 2018: [0.63]}, 'vt': {'pres08': 0.31100818, 'pres12': 0.31752741, 'pres16': 0.34813574, 2006: [0.33100771], 2008: [], 2010: [0.32457809], 2012: [0.2596582], 2014: [], 2016: [0.350267], 2018: [0.3]}, 'va': {'pres08': 0.46817416, 'pres12': 0.48032623, 'pres16': 0.47173624, 2006: [0.49800823], 2008: [0.3415165], 2010: [], 2012: [0.47042306], 2014: [0.49583796], 2016: [], 2018: [0.43]}, 'wa': {'pres08': 0.41247973, 'pres12': 0.42371702, 'pres16': 0.41213069, 2006: [0.41259443], 2008: [], 2010: [0.47635174], 2012: [0.39549009], 2014: [], 2016: [0.4098699], 2018: [0.4]}, 'wv': {'pres08': 0.56673744, 'pres12': 0.63674298, 'pres16': 0.72161052, 2006: [0.22950978], 2008: [0.36262174], 2010: [0.4480444], 2012: [0.37582743], 2014: [0.64316035], 2016: [], 2018: [0.48]}, 'wi': {'pres08': 0.42944322, 'pres12': 0.4653657, 'pres16': 0.50407989, 2006: [0.30456392], 2008: [], 2010: [0.00013123], 2012: [0.4714785], 2014: [], 2016: [0.51733264], 2018: [0.45]}, 'wy': {'pres08': 0.66562023, 'pres12': 0.71160634, 'pres16': 0.7570532, 2006: [0.70094636], 2008: [0.75716225, 0.73441117], 2010: [], 2012: [0.77748259], 2014: [0.80536139], 2016: [], 2018: [0.67]}};
		for (var i in eData){
			eData[i].rpred = eData[i].pres16;
			eData[i].pres20 = eData[i].pres16;
			eData[i].sen20 = eData[i].pres16;
			if (userData20[i]){
				if (userData20[i].party == 'R'){
					eData[i].rpred = userData20[i].user/200+.5;
					eData[i].pres20 = userData20[i].pres20/200+.5;
					eData[i].sen20 = userData20[i].sen20/200+.5;
				}
				else if (userData20[i].party == 'D'){
					eData[i].rpred = .5-userData20[i].user/200;
					eData[i].pres20 = .5-userData20[i].pres20/200;
					eData[i].sen20 = .5-userData20[i].sen20/200;
				}
				
			}
			eData[i].rpred16 = eData[i].pres16;
			if (userData16[i]){
				if (userData16[i].party == 'R'){
					eData[i].rpred16 = userData16[i].user/200+.5;
				}
				else if (userData16[i].party == 'D'){
					eData[i].rpred16 = .5-userData16[i].user/200;
				}
				
			}
		}
		res.write(nunjucks.render('templates/senatemap.html',{
			senateData: eData,

		}));
		res.end();
	}
);

app.get(['/senatemap','/senatemap.html'],
	function(req, res){
		
		var senateData = {'al': {'pres08': 0.60890903, 'pres12': 0.61216229, 'pres16': 0.64374144, 2006: [], 2008: [0.63436655], 2010: [0.65250101], 2012: [], 2014: [1.0], 2016: [0.6407024], 2018: [0.48]}, 'ak': {'pres08': 0.61064785, 'pres12': 0.5731529, 'pres16': 0.58385655, 2006: [], 2008: [0.49340245], 2010: [0.60204528], 2012: [], 2014: [0.51135248], 2016: [0.79237048], 2018: []}, 'az': {'pres08': 0.54313901, 'pres12': 0.5461338, 'pres16': 0.51890023, 2006: [0.55081266], 2008: [], 2010: [0.62944331], 2012: [0.51586059], 2014: [.5686], 2016: [0.56860915], 2018: [0.49]}, 'ar': {'pres08': 0.60171721, 'pres12': 0.62154405, 'pres16': 0.64285138, 2006: [], 2008: [0.0], 2010: [0.61048104], 2012: [], 2014: [0.58895833], 2016: [0.62299334], 2018: []}, 'ca': {'pres08': 0.3772155, 'pres12': 0.38127189, 'pres16': 0.33871779, 2006: [0.37074264], 2008: [], 2010: [0.4469534], 2012: [0.37475716], 2014: [], 2016: [0.0], 2018: [0.0]}, 'co': {'pres08': 0.45449365, 'pres12': 0.47252012, 'pres16': 0.47316667, 2006: [], 2008: [0.44593471], 2010: [0.49138188], 2012: [], 2014: [0.51029203], 2016: [0.46995547], 2018: []}, 'ct': {'pres08': 0.38681662, 'pres12': 0.41227423, 'pres16': 0.42858452, 2006: [0.1949818], 2008: [], 2010: [0.45158195], 2012: [0.43259142], 2014: [], 2016: [0.37506846], 2018: [0.42]}, 'de': {'pres08': 0.37361861, 'pres12': 0.40553045, 'pres16': 0.44001379, 2006: [0.29019438], 2008: [0.35313487], 2010: [0.41422921], 2012: [0.30358291], 2014: [0.43064259], 2016: [], 2018: [0.4]}, 'dc': {'pres08': 0.06599232, 'pres12': 0.07412351, 'pres16': 0.04304812, 2006: [], 2008: [], 2010: [], 2012: [], 2014: [], 2016: [], 2018: []}, 'fl': {'pres08': 0.4858034, 'pres12': 0.49557748, 'pres16': 0.50618835, 2006: [0.38716405], 2008: [], 2010: [0.70766787], 2012: [0.43327351], 2014: [], 2016: [0.53980578], 2018: [0.51]}, 'ga': {'pres08': 0.52628336, 'pres12': 0.53956649, 'pres16': 0.52661173, 2006: [], 2008: [0.31525622], 2010: [0.59921654], 2012: [], 2014: [0.53915937], 2016: [0.57175417], 2018: []}, 'hi': {'pres08': 0.27006274, 'pres12': 0.28296151, 'pres16': 0.32558663, 2006: [0.37481237], 2008: [], 2010: [0.22381407], 2012: [0.37398457], 2014: [0.28421294], 2016: [0.23206356], 2018: [0.28]}, 'id': {'pres08': 0.6302459, 'pres12': 0.66421387, 'pres16': 0.68310177, 2006: [], 2008: [0.6283206], 2010: [0.7406148], 2012: [], 2014: [0.65328362], 2016: [0.70459902], 2018: []}, 'il': {'pres08': 0.37265736, 'pres12': 0.41422477, 'pres16': 0.40979949, 2006: [], 2008: [0.29604426], 2010: [0.50846441], 2012: [], 2014: [0.44361346], 2016: [0.42032449], 2018: []}, 'in': {'pres08': 0.49478047, 'pres12': 0.55200375, 'pres16': 0.6011731, 2006: [1.0], 2008: [], 2010: [0.57707812], 2012: [0.46944677], 2014: [], 2016: [0.55130669], 2018: [0.53]}, 'ia': {'pres08': 0.45151222, 'pres12': 0.47040648, 'pres16': 0.55063548, 2006: [], 2008: [0.3729219], 2010: [0.6589727], 2012: [], 2014: [0.54349482], 2016: [0.62760265], 2018: []}, 'ks': {'pres08': 0.57612276, 'pres12': 0.61113327, 'pres16': 0.6111147, 2006: [], 2008: [0.62225807], 2010: [0.72657045], 2012: [], 2014: [1.0], 2016: [0.65854281], 2018: []}, 'ky': {'pres08': 0.58233428, 'pres12': 0.61542772, 'pres16': 0.65670629, 2006: [], 2008: [0.5296562], 2010: [0.55740479], 2012: [], 2014: [0.57980287], 2016: [0.57274552], 2018: []}, 'la': {'pres08': 0.59457174, 'pres12': 0.58746826, 'pres16': 0.60171677, 2006: [], 2008: [0.46736119], 2010: [0.60018691], 2012: [], 2014: [0.52308918], 2016: [0.6065461], 2018: []}, 'me': {'pres08': 0.41170475, 'pres12': 0.42140079, 'pres16': 0.48403209, 2006: [0.78190647], 2008: [0.61383512], 2010: [], 2012: [0.36758826], 2014: [0.6848842], 2016: [], 2018: [0.46]}, 'md': {'pres08': 0.37069913, 'pres12': 0.36678274, 'pres16': 0.3598375, 2006: [0.44913586], 2008: [], 2010: [0.36503012], 2012: [0.31988415], 2014: [], 2016: [0.36944741], 2018: [0.36]}, 'ma': {'pres08': 0.36802922, 'pres12': 0.38214319, 'pres16': 0.35348721, 2006: [0.30594329], 2008: [0.31954391], 2010: [], 2012: [0.46222761], 2014: [0.38039881], 2016: [], 2018: [0.4]}, 'mi': {'pres08': 0.41628698, 'pres12': 0.45199468, 'pres16': 0.50117668, 2006: [0.42027743], 2008: [0.35069675], 2010: [], 2012: [0.39247231], 2014: [0.43076489], 2016: [], 2018: [0.47]}, 'mn': {'pres08': 0.44770625, 'pres12': 0.46058774, 'pres16': 0.49168306, 2006: [0.39520086], 2008: [0.49993567], 2010: [], 2012: [0.31880698], 2014: [0.44668105], 2016: [], 2018: [0.39, 0.46]}, 'ms': {'pres08': 0.56641931, 'pres12': 0.55801899, 'pres16': 0.59089847, 2006: [0.64582582], 2008: [0.61435046, 1.0], 2010: [], 2012: [0.58497246], 2014: [0.61250809], 2016: [], 2018: [0.54, 0.59]}, 'mo': {'pres08': 0.50067579, 'pres12': 0.54778667, 'pres16': 0.59818561, 2006: [0.48828579], 2008: [], 2010: [0.57170253], 2012: [0.41642216], 2014: [], 2016: [0.51460769], 2018: [0.52]}, 'mt': {'pres08': 0.51169403, 'pres12': 0.57034232, 'pres16': 0.61109664, 2006: [0.49550398], 2008: [0.27084022], 2010: [], 2012: [0.48010454], 2014: [0.5905309], 2016: [], 2018: [0.49]}, 'ne': {'pres08': 0.57609074, 'pres12': 0.6112939, 'pres16': 0.63547674, 2006: [0.36117208], 2008: [0.58948417], 2010: [], 2012: [0.57774433], 2014: [0.67141916], 2016: [], 2018: [0.58]}, 'nv': {'pres08': 0.43613262, 'pres12': 0.46592458, 'pres16': 0.48706291, 2006: [0.57456391], 2008: [], 2010: [0.46972576], 2012: [0.50640453], 2014: [], 2016: [0.4867684], 2018: [0.48]}, 'nh': {'pres08': 0.45131459, 'pres12': 0.47166248, 'pres16': 0.49802972, 2006: [], 2008: [0.46727682], 2010: [0.61987508], 2012: [], 2014: [0.48372457], 2016: [0.49928206], 2018: []}, 'nj': {'pres08': 0.4213537, 'pres12': 0.41048034, 'pres16': 0.4271581, 2006: [0.45381917], 2008: [0.42817144], 2010: [], 2012: [0.40079838], 2014: [0.43118622], 2016: [], 2018: [0.46]}, 'nm': {'pres08': 0.423351, 'pres12': 0.44704795, 'pres16': 0.45349205, 2006: [0.0009095], 2008: [0.38672009], 2010: [], 2012: [0.47024206], 2014: [0.4444119], 2016: [], 2018: [0.46]}, 'ny': {'pres08': 0.34236143, 'pres12': 0.33957305, 'pres16': 0.36588494, 2006: [0.31005976], 2008: [], 2010: [0.28912171, 0.32047667], 2012: [0.25521923], 2014: [], 2016: [0.26488753], 2018: [0.33]}, 'nc': {'pres08': 0.49834037, 'pres12': 0.51034035, 'pres16': 0.51903746, 2006: [], 2008: [0.45627065], 2010: [0.56011479], 2012: [], 2014: [0.50814164], 2016: [0.5295356], 2018: []}, 'nd': {'pres08': 0.54408656, 'pres12': 0.60111208, 'pres16': 0.69809243, 2006: [0.30022418], 2008: [], 2010: [0.77431769], 2012: [0.49540874], 2014: [], 2016: [0.82222304], 2018: [0.55]}, 'oh': {'pres08': 0.47666159, 'pres12': 0.48485943, 'pres16': 0.54267685, 2006: [0.43824268], 2008: [], 2010: [0.59060974], 2012: [0.46855014], 2014: [], 2016: [0.6096339], 2018: [0.47]}, 'ok': {'pres08': 0.65645081, 'pres12': 0.6677232, 'pres16': 0.69304737, 2006: [], 2008: [0.59125435], 2010: [0.72994506], 2012: [], 2014: [0.70433441, 0.70069755], 2016: [0.73375957], 2018: []}, 'or': {'pres08': 0.41586279, 'pres12': 0.43728833, 'pres16': 0.43844161, 2006: [], 2008: [0.4822608], 2010: [0.40683808], 2012: [], 2014: [0.3981479], 2016: [0.37074179], 2018: []}, 'pa': {'pres08': 0.44770296, 'pres12': 0.47268066, 'pres16': 0.50375536, 2006: [0.41316242], 2008: [], 2010: [0.51008495], 2012: [0.45369023], 2014: [], 2016: [0.5074518], 2018: [0.44]}, 'ri': {'pres08': 0.35801862, 'pres12': 0.35983254, 'pres16': 0.41689296, 2006: [0.46481365], 2008: [0.26595516], 2010: [], 2012: [0.35043714], 2014: [0.29297096], 2016: [], 2018: [0.38]}, 'sc': {'pres08': 0.54544429, 'pres12': 0.55308255, 'pres16': 0.57460256, 2006: [], 2008: [0.57656381], 2010: [0.68980125], 2012: [], 2014: [0.59569856, 0.62230132], 2016: [0.6379825], 2018: []}, 'sd': {'pres08': 0.54295707, 'pres12': 0.59218499, 'pres16': 0.65971858, 2006: [], 2008: [0.37508308], 2010: [1.0], 2012: [], 2014: [0.63056851], 2016: [0.71827862], 2018: []}, 'tn': {'pres08': 0.57631472, 'pres12': 0.60351072, 'pres16': 0.63624343, 2006: [0.51379506], 2008: [0.6730593], 2010: [], 2012: [0.68093205], 2014: [0.66003874], 2016: [], 2018: [0.54]}, 'tx': {'pres08': 0.55935937, 'pres12': 0.58007897, 'pres16': 0.54713226, 2006: [0.63120576], 2008: [0.56135139], 2010: [], 2012: [0.58154549], 2014: [0.64175457], 2016: [], 2018: [0.51]}, 'ut': {'pres08': 0.64526361, 'pres12': 0.74626189, 'pres16': 0.62382898, 2006: [0.6674911], 2008: [], 2010: [0.65274435], 2012: [0.68537887], 2014: [], 2016: [0.71578547], 2018: [0.63]}, 'vt': {'pres08': 0.31100818, 'pres12': 0.31752741, 'pres16': 0.34813574, 2006: [0.33100771], 2008: [], 2010: [0.32457809], 2012: [0.2596582], 2014: [], 2016: [0.350267], 2018: [0.3]}, 'va': {'pres08': 0.46817416, 'pres12': 0.48032623, 'pres16': 0.47173624, 2006: [0.49800823], 2008: [0.3415165], 2010: [], 2012: [0.47042306], 2014: [0.49583796], 2016: [], 2018: [0.43]}, 'wa': {'pres08': 0.41247973, 'pres12': 0.42371702, 'pres16': 0.41213069, 2006: [0.41259443], 2008: [], 2010: [0.47635174], 2012: [0.39549009], 2014: [], 2016: [0.4098699], 2018: [0.4]}, 'wv': {'pres08': 0.56673744, 'pres12': 0.63674298, 'pres16': 0.72161052, 2006: [0.22950978], 2008: [0.36262174], 2010: [0.4480444], 2012: [0.37582743], 2014: [0.64316035], 2016: [], 2018: [0.48]}, 'wi': {'pres08': 0.42944322, 'pres12': 0.4653657, 'pres16': 0.50407989, 2006: [0.30456392], 2008: [], 2010: [0.00013123], 2012: [0.4714785], 2014: [], 2016: [0.51733264], 2018: [0.45]}, 'wy': {'pres08': 0.66562023, 'pres12': 0.71160634, 'pres16': 0.7570532, 2006: [0.70094636], 2008: [0.75716225, 0.73441117], 2010: [], 2012: [0.77748259], 2014: [0.80536139], 2016: [], 2018: [0.67]}};

		res.write(nunjucks.render('templates/senatemap.html',{
			senateData: senateData,

		}));
		res.end();
	}
);

app.post(['/presmap','/presmap.html'],
	function(req, res){
		var nAdv = 0;
		var uncertainty = 0;
		var correlationDivisor = 0;
		var correlationPower = 0;
		if (req.body['nAdv']){
			nAdv = parseInt(req.body['nAdv'])/1000;
		}
		if (req.body['uncertainty']){
			uncertainty = parseInt(req.body['uncertainty'])+75;
		}
		if (req.body['nAdv']){
			correlationDivisor = parseInt(req.body['correlationDivisor'])+333;
		}
		if (req.body['nAdv']){
			correlationPower = parseFloat(req.body['correlationPower'])/100+3;
		}
		var eData = [{'abbrev': 'dc', 'votes16': 295553, 'ev10': 3, 'pres08': 0.06599232, 'pres12': 0.07412351, 'rperc': 0.04304812}, {'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		for (var i=0;i<eData.length;i++){
			eData[i].rpred = eData[i].rperc+nAdv;
			eData[i].pres16 = eData[i].rperc;
			delete eData[i].rperc;
		}
		res.write(nunjucks.render('templates/map.html',{
			electoralData: eData,
			uncertainty: uncertainty,
			correlationDivisor: correlationDivisor,
			correlationPower: correlationPower,

		}));
		res.end();
	}
);

app.post(['/map','/map.html'],
	function(req, res){
		var userData16 = {};
		var userData20 = {};
		for (var i in req.body){
			if (req.body[i] != ''){
				var p = parseFloat(req.body[i]);
				var state = i.split('-');
				if (state[1]=="2016"){
					userData16[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				else if (state[1]=="2020"){
					userData20[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				
			}
		}
		for (var i in req.body){
			if (req.body[i] != ''){
				var p = parseFloat(req.body[i]);
				var state = i.split('-');
				if (state.length > 3){
					continue;
				}
				if (state[1]=="2016"){
					userData16[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				else if (state[1]=="2020"){
					userData20[state[0].toLowerCase()]={'party':state[2],'user':p};
				}
				
			}
		}
		var eData = [{'abbrev': 'dc', 'votes16': 295553, 'ev10': 3, 'pres08': 0.06599232, 'pres12': 0.07412351, 'rperc': 0.04304812}, {'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		for (var i=0;i<eData.length;i++){
			eData[i].rpred = eData[i].rperc;
			if (userData20[eData[i].abbrev]){
				if (userData20[eData[i].abbrev].party == 'R'){
					eData[i].rpred = userData20[eData[i].abbrev].user/200+.5;
				}
				else if (userData20[eData[i].abbrev].party == 'D'){
					eData[i].rpred = .5-userData20[eData[i].abbrev].user/200;
				}
				
			}
			eData[i].rpred16 = eData[i].rperc;
			if (userData16[eData[i].abbrev]){
				if (userData16[eData[i].abbrev].party == 'R'){
					eData[i].rpred16 = userData16[eData[i].abbrev].user/200+.5;
				}
				else if (userData16[eData[i].abbrev].party == 'D'){
					eData[i].rpred16 = .5-userData16[eData[i].abbrev].user/200;
				}
				
			}
			eData[i].pres16 = eData[i].rperc;
			delete eData[i].rperc;
		}
		res.write(nunjucks.render('templates/map.html',{
			electoralData: eData,
			uncertainty: 75,
			correlationDivisor: 160,
			correlationPower: 3,

		}));
		res.end();
	}
);



app.get(['/','/draw','/draw.html'],
	function(req, res){
		
		var hData = [{'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		var tipping = [{'abbrev': 'Wyoming', 'seats': 1, 'rwin': 0.99865, 'half': 1}, {'abbrev': 'Wisconsin', 'seats': 104, 'rwin': 0.1315}, {'abbrev': 'West_Virginia', 'seats': 1, 'rwin': 0.986725, 'half': 1}, {'abbrev': 'Washington', 'seats': 1, 'rwin': 0.0075}, {'abbrev': 'Virginia', 'seats': 7, 'rwin': 0.0124}, {'abbrev': 'Vermont', 'seats': 1, 'rwin': 0.007925, 'half': 1}, {'abbrev': 'Utah', 'seats': 1, 'rwin': 0.9643, 'half': 1}, {'abbrev': 'Texas', 'seats': 8, 'rwin': 0.6852}, {'abbrev': 'Tennessee', 'seats': 1, 'rwin': 0.9631, 'half': 1}, {'abbrev': 'South_Dakota', 'seats': 1, 'rwin': 0.975575, 'half': 1}, {'abbrev': 'South_Carolina', 'seats': 1, 'rwin': 0.880675}, {'abbrev': 'Rhode_Island', 'seats': 1, 'rwin': 0.002375, 'half': 1}, {'abbrev': 'Pennsylvania', 'seats': 182, 'rwin': 0.12695}, {'abbrev': 'Oregon', 'seats': 3, 'rwin': 0.030725}, {'abbrev': 'Oklahoma', 'seats': 1, 'rwin': 0.993975, 'half': 1}, {'abbrev': 'Ohio', 'seats': 16, 'rwin': 0.4867}, {'abbrev': 'North_Dakota', 'seats': 1, 'rwin': 0.992875, 'half': 1}, {'abbrev': 'North_Carolina', 'seats': 38, 'rwin': 0.344825}, {'abbrev': 'New_York', 'seats': 1, 'rwin': 0.000175, 'half': 1}, {'abbrev': 'New_Mexico', 'seats': 7, 'rwin': 0.02845}, {'abbrev': 'New_Jersey', 'seats': 5, 'rwin': 0.015825}, {'abbrev': 'New_Hampshire', 'seats': 9, 'rwin': 0.151225}, {'abbrev': 'Nevada', 'seats': 23, 'rwin': 0.1407}, {'abbrev': 'Nebraska', 'seats': 1, 'rwin': 0.9883, 'half': 1}, {'abbrev': 'NE-3', 'seats': 1, 'rwin': 0.999625, 'half': 1}, {'abbrev': 'NE-2', 'seats': 8, 'rwin': 0.23315}, {'abbrev': 'NE-1', 'seats': 1, 'rwin': 0.94365, 'half': 1}, {'abbrev': 'Montana', 'seats': 1, 'rwin': 0.88695, 'half': 1}, {'abbrev': 'Missouri', 'seats': 1, 'rwin': 0.8987, 'half': 1}, {'abbrev': 'Mississippi', 'seats': 2, 'rwin': 0.86485}, {'abbrev': 'Minnesota', 'seats': 41, 'rwin': 0.09155}, {'abbrev': 'Michigan', 'seats': 86, 'rwin': 0.09}, {'abbrev': 'Massachusetts', 'seats': 1, 'rwin': 0.0007, 'half': 1}, {'abbrev': 'Maryland', 'seats': 1, 'rwin': 0.000375, 'half': 1}, {'abbrev': 'Maine', 'seats': 2, 'rwin': 0.10175}, {'abbrev': 'ME-2', 'seats': 3, 'rwin': 0.527175}, {'abbrev': 'ME-1', 'seats': 1, 'rwin': 0.019425, 'half': 1}, {'abbrev': 'Louisiana', 'seats': 1, 'rwin': 0.9273}, {'abbrev': 'Kentucky', 'seats': 1, 'rwin': 0.984925, 'half': 1}, {'abbrev': 'Kansas', 'seats': 1, 'rwin': 0.92505, 'half': 1}, {'abbrev': 'Iowa', 'seats': 5, 'rwin': 0.546625}, {'abbrev': 'Indiana', 'seats': 1, 'rwin': 0.949175, 'half': 1}, {'abbrev': 'Illinois', 'seats': 1, 'rwin': 0.00085, 'half': 1}, {'abbrev': 'Idaho', 'seats': 1, 'rwin': 0.996275, 'half': 1}, {'abbrev': 'Hawaii', 'seats': 1, 'rwin': 0.00785, 'half': 1}, {'abbrev': 'Georgia', 'seats': 13, 'rwin': 0.551575}, {'abbrev': 'Florida', 'seats': 121, 'rwin': 0.2628}, {'abbrev': 'District_of_Columbia', 'seats': 1, 'rwin': 0.0, 'half': 1}, {'abbrev': 'Delaware', 'seats': 1, 'rwin': 0.00015, 'half': 1}, {'abbrev': 'Connecticut', 'seats': 1, 'rwin': 0.002725, 'half': 1}, {'abbrev': 'Colorado', 'seats': 17, 'rwin': 0.06215}, {'abbrev': 'California', 'seats': 2, 'rwin': 0.001375}, {'abbrev': 'Arkansas', 'seats': 1, 'rwin': 0.979425, 'half': 1}, {'abbrev': 'Arizona', 'seats': 33, 'rwin': 0.3321}, {'abbrev': 'Alaska', 'seats': 1, 'rwin': 0.77235}, {'abbrev': 'Alabama', 'seats': 1, 'rwin': 0.9794, 'half': 1}]
		
		for (var i=0;i<hData.length;i++){
			hData[i].ev10 -= 2;
		}	
		for (var i=0;i<tipping.length;i++){
			tipping[i].name = tipping[i].abbrev;
			tipping[i].abbrev = tipping[i].abbrev.substr(0,7);
		}	
		tipping.sort(function(a,b){return b.seats - a.seats;})

		res.write(nunjucks.render('templates/draw.html',{
			states: tipping,
			load: "ptip",
			saveAs: "ptip",
			districts: false,
			val: 'seats',
			height: 24,
			width: 32,
		}));
		res.end();
	}
);

app.get(['/','/diycsv','/diycsv.html'],
	function(req, res){
		
		
		
		
		
		res.write(nunjucks.render('templates/diycsv.html',{

		}));
		res.end();
	}
);

app.get(['/','/index','/index.html'],
	function(req, res){
		
		var eData = [{'abbrev': 'dc', 'votes16': 295553, 'ev10': 3, 'pres08': 0.06599232, 'pres12': 0.07412351, 'rperc': 0.04304812}, {'abbrev': 'hi', 'votes16': 395738, 'ev10': 4, 'pres08': 0.27006274, 'pres12': 0.28296151, 'rperc': 0.32558663}, {'abbrev': 'ca', 'votes16': 13237598, 'ev10': 55, 'pres08': 0.3772155, 'pres12': 0.38127189, 'rperc': 0.33871779}, {'abbrev': 'vt', 'votes16': 273942, 'ev10': 3, 'pres08': 0.31100818, 'pres12': 0.31752741, 'rperc': 0.34813574}, {'abbrev': 'ma', 'votes16': 3086089, 'ev10': 11, 'pres08': 0.36802922, 'pres12': 0.38214319, 'rperc': 0.35348721}, {'abbrev': 'md', 'votes16': 2621097, 'ev10': 10, 'pres08': 0.37069913, 'pres12': 0.36678274, 'rperc': 0.3598375}, {'abbrev': 'ny', 'votes16': 6906931, 'ev10': 29, 'pres08': 0.34236143, 'pres12': 0.33957305, 'rperc': 0.36588494}, {'abbrev': 'il', 'votes16': 5236744, 'ev10': 20, 'pres08': 0.37265736, 'pres12': 0.41422477, 'rperc': 0.40979949}, {'abbrev': 'wa', 'votes16': 2964465, 'ev10': 12, 'pres08': 0.41247973, 'pres12': 0.42371702, 'rperc': 0.41213069}, {'abbrev': 'ri', 'votes16': 433068, 'ev10': 4, 'pres08': 0.35801862, 'pres12': 0.35983254, 'rperc': 0.41689296}, {'abbrev': 'nj', 'votes16': 3750211, 'ev10': 14, 'pres08': 0.4213537, 'pres12': 0.41048034, 'rperc': 0.4271581}, {'abbrev': 'ct', 'votes16': 1570787, 'ev10': 7, 'pres08': 0.38681662, 'pres12': 0.41227423, 'rperc': 0.42858452}, {'abbrev': 'or', 'votes16': 1784509, 'ev10': 7, 'pres08': 0.41586279, 'pres12': 0.43728833, 'rperc': 0.43844161}, {'abbrev': 'de', 'votes16': 420730, 'ev10': 3, 'pres08': 0.37361861, 'pres12': 0.40553045, 'rperc': 0.44001379}, {'abbrev': 'nm', 'votes16': 704901, 'ev10': 5, 'pres08': 0.423351, 'pres12': 0.44704795, 'rperc': 0.45349205}, {'abbrev': 'va', 'votes16': 3750916, 'ev10': 13, 'pres08': 0.46817416, 'pres12': 0.48032623, 'rperc': 0.47173624}, {'abbrev': 'co', 'votes16': 2541354, 'ev10': 9, 'pres08': 0.45449365, 'pres12': 0.47252012, 'rperc': 0.47316667}, {'abbrev': 'me', 'votes16': 693328, 'ev10': 4, 'pres08': 0.41170475, 'pres12': 0.42140079, 'rperc': 0.48403209}, {'abbrev': 'nv', 'votes16': 1051318, 'ev10': 6, 'pres08': 0.43613262, 'pres12': 0.46592458, 'rperc': 0.48706291}, {'abbrev': 'mn', 'votes16': 2690654, 'ev10': 10, 'pres08': 0.44770625, 'pres12': 0.46058774, 'rperc': 0.49168306}, {'abbrev': 'nh', 'votes16': 694316, 'ev10': 4, 'pres08': 0.45131459, 'pres12': 0.47166248, 'rperc': 0.49802972}, {'abbrev': 'mi', 'votes16': 4548382, 'ev10': 16, 'pres08': 0.41628698, 'pres12': 0.45199468, 'rperc': 0.50117668}, {'abbrev': 'pa', 'votes16': 5897174, 'ev10': 20, 'pres08': 0.44770296, 'pres12': 0.47268066, 'rperc': 0.50375536}, {'abbrev': 'wi', 'votes16': 2787820, 'ev10': 10, 'pres08': 0.42944322, 'pres12': 0.4653657, 'rperc': 0.50407989}, {'abbrev': 'fl', 'votes16': 9122861, 'ev10': 29, 'pres08': 0.4858034, 'pres12': 0.49557748, 'rperc': 0.50618835}, {'abbrev': 'az', 'votes16': 2413568, 'ev10': 11, 'pres08': 0.54313901, 'pres12': 0.5461338, 'rperc': 0.51890023}, {'abbrev': 'nc', 'votes16': 4551947, 'ev10': 15, 'pres08': 0.49834037, 'pres12': 0.51034035, 'rperc': 0.51903746}, {'abbrev': 'ga', 'votes16': 3967067, 'ev10': 16, 'pres08': 0.52628336, 'pres12': 0.53956649, 'rperc': 0.52661173}, {'abbrev': 'oh', 'votes16': 5235169, 'ev10': 18, 'pres08': 0.47666159, 'pres12': 0.48485943, 'rperc': 0.54267685}, {'abbrev': 'tx', 'votes16': 8562915, 'ev10': 38, 'pres08': 0.55935937, 'pres12': 0.58007897, 'rperc': 0.54713226}, {'abbrev': 'ia', 'votes16': 1454652, 'ev10': 6, 'pres08': 0.45151222, 'pres12': 0.47040648, 'rperc': 0.55063548}, {'abbrev': 'sc', 'votes16': 2010762, 'ev10': 9, 'pres08': 0.54544429, 'pres12': 0.55308255, 'rperc': 0.57460256}, {'abbrev': 'ak', 'votes16': 279841, 'ev10': 3, 'pres08': 0.61064785, 'pres12': 0.5731529, 'rperc': 0.58385655}, {'abbrev': 'ms', 'votes16': 1185845, 'ev10': 6, 'pres08': 0.56641931, 'pres12': 0.55801899, 'rperc': 0.59089847}, {'abbrev': 'mo', 'votes16': 2665579, 'ev10': 10, 'pres08': 0.50067579, 'pres12': 0.54778667, 'rperc': 0.59818561}, {'abbrev': 'in', 'votes16': 2590412, 'ev10': 11, 'pres08': 0.49478047, 'pres12': 0.55200375, 'rperc': 0.6011731}, {'abbrev': 'la', 'votes16': 1958792, 'ev10': 8, 'pres08': 0.59457174, 'pres12': 0.58746826, 'rperc': 0.60171677}, {'abbrev': 'mt', 'votes16': 456949, 'ev10': 3, 'pres08': 0.51169403, 'pres12': 0.57034232, 'rperc': 0.61109664}, {'abbrev': 'ks', 'votes16': 1098023, 'ev10': 6, 'pres08': 0.57612276, 'pres12': 0.61113327, 'rperc': 0.6111147}, {'abbrev': 'ut', 'votes16': 825885, 'ev10': 6, 'pres08': 0.64526361, 'pres12': 0.74626189, 'rperc': 0.62382898}, {'abbrev': 'ne', 'votes16': 780455, 'ev10': 5, 'pres08': 0.57609074, 'pres12': 0.6112939, 'rperc': 0.63547674}, {'abbrev': 'tn', 'votes16': 2393620, 'ev10': 11, 'pres08': 0.57631472, 'pres12': 0.60351072, 'rperc': 0.63624343}, {'abbrev': 'ar', 'votes16': 1065366, 'ev10': 6, 'pres08': 0.60171721, 'pres12': 0.62154405, 'rperc': 0.64285138}, {'abbrev': 'al', 'votes16': 2047802, 'ev10': 9, 'pres08': 0.60890903, 'pres12': 0.61216229, 'rperc': 0.64374144}, {'abbrev': 'ky', 'votes16': 1831825, 'ev10': 8, 'pres08': 0.58233428, 'pres12': 0.61542772, 'rperc': 0.65670629}, {'abbrev': 'sd', 'votes16': 345179, 'ev10': 3, 'pres08': 0.54295707, 'pres12': 0.59218499, 'rperc': 0.65971858}, {'abbrev': 'id', 'votes16': 598820, 'ev10': 4, 'pres08': 0.6302459, 'pres12': 0.66421387, 'rperc': 0.68310177}, {'abbrev': 'ok', 'votes16': 1369511, 'ev10': 7, 'pres08': 0.65645081, 'pres12': 0.6677232, 'rperc': 0.69304737}, {'abbrev': 'nd', 'votes16': 310552, 'ev10': 3, 'pres08': 0.54408656, 'pres12': 0.60111208, 'rperc': 0.69809243}, {'abbrev': 'wv', 'votes16': 678165, 'ev10': 5, 'pres08': 0.56673744, 'pres12': 0.63674298, 'rperc': 0.72161052}, {'abbrev': 'wy', 'votes16': 230392, 'ev10': 3, 'pres08': 0.66562023, 'pres12': 0.71160634, 'rperc': 0.7570532}];
		for (var i=0;i<eData.length;i++){
			eData[i].rpred = eData[i].rperc;
			delete eData[i].rperc;
		}
		res.write(nunjucks.render('templates/index.html',{
			electoralData: eData,
		}));
		res.end();
	}
);

app.get(['*'],
	function(req, res){
		

		res.redirect('../');
	}
);



