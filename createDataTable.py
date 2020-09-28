initial = ['{% extends "templates/electoral.html" %}\n{% block dataTable %}\n<table id="dataTable">']
end = ['</table>\n{% endblock %}']
file1 = open('templates/electoraltable.html', 'w')
file1.writelines(initial) 
 
print("hello")
# Using readlines() 
file2 = open('dataOut/presidential81216.csv', 'r') 
lines = file2.readlines() 

file20 = open('data/economist2020.csv', 'r') 
lines20 = file20.readlines() 

states16 = {}
states20 = {}
count = 0
# Strips the newline character 
i = 0
for line in lines:
	i+=1
	lineSplit = line.strip().split(",")
	if lineSplit[0] == "2012":
		states16[lineSplit[1]]={"2012":float(lineSplit[7])}
	elif lineSplit[0] == "2016":
		states16[lineSplit[1]]["pred"]=float(lineSplit[2])
		states20[lineSplit[1]]={"2016":float(lineSplit[7])}
i = 0
for line in lines20:
	i+=1
	lineSplit = line.strip().split(",")
	if i > 1:
		states20[lineSplit[3]]["pred"]=float(lineSplit[6])

statesOrdered = []
i = 0
for state in states16.keys():
	prod = (.5-states16[state]["2012"])**2+(.5-states16[state]["pred"])**2
	states16[state]["prod"]=prod
	states16[state]["year"]=2016
	states16[state]["id"]=i
	states16[state]["name"]=state
	ii = 0
	added = False
	for s in statesOrdered:
		if prod < s["prod"]:
			statesOrdered.insert(ii,states16[state])
			added = True
			break;
		ii+=1
	if not added:
		statesOrdered.append(states16[state])
	i+=1
i = 0	
for state in states20.keys():
	prod = (.5-states20[state]["2016"])**2+(.5-states20[state]["pred"])**2
	states20[state]["prod"]=prod
	states20[state]["year"]=2020
	states20[state]["id"]=i
	states20[state]["name"]=state
	ii = 0
	added = False
	for s in statesOrdered:
		if prod < s["prod"]:
			statesOrdered.insert(ii,states20[state])
			added = True
			break;
		ii+=1
	if not added:
		statesOrdered.append(states20[state])	
	i+=1	

for state in statesOrdered:
	if state["pred"]>.5:
		line = '\n<tr data-id="'+str(state["id"])+'" data-year="'+str(state["year"])+'" data-party="D">'
		#line += '<td>'+state["name"]+'</td>'
		if state["year"] == 2016:
			line += '<td>+'+str(round(state["2012"]*2000-1000)/10.0)+'</td>'
			
		else:
			line += '<td>+'+str(round(state["2016"]*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round(state["pred"]*2000-1000)/10.0)+'</td>'
		line += '<td><input style="display: none;" value="'+str(round(state["pred"]*2000-1000)/10.0)+'" type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-D-poll"></input><input type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-D"></input></td>'
		line += '</tr>'
	else:
		line = '\n<tr data-id="'+str(state["id"])+'" data-year="'+str(state["year"])+'" data-party="R">'
		#line += '<td>'+state["name"]+'</td>'
		if state["year"] == 2016:
			line += '<td>+'+str(round((1-state["2012"])*2000-1000)/10.0)+'</td>'
			
		else:
			line += '<td>+'+str(round((1-state["2016"])*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round((1-state["pred"])*2000-1000)/10.0)+'</td>'
		line += '<td><input style="display: none;" value="'+str(round((1-state["pred"])*2000-1000)/10.0)+'" type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-R-poll"></input><input type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-R"></input></td>'
		line += '</tr>'
	line = line.replace('+-','-')
	file1.writelines([line])

file1.writelines(end)
file1.close()


initial = ['{% extends "templates/senate.html" %}\n{% block dataTable %}\n<table id="dataTable">']
end = ['</table>\n{% endblock %}']
file1 = open('templates/senatetable.html', 'w')
file1.writelines(initial) 

senateData = {'al': {'pres08': 0.60890903, 'pres12': 0.61216229, 'pres16': 0.64374144, 2006: [], 2008: [0.63436655], 2010: [0.65250101], 2012: [], 2014: [1.0], 2016: [0.6407024], 2018: [0.48]}, 'ak': {'pres08': 0.61064785, 'pres12': 0.5731529, 'pres16': 0.58385655, 2006: [], 2008: [0.49340245], 2010: [0.60204528], 2012: [], 2014: [0.51135248], 2016: [0.79237048], 2018: []}, 'az': {'pres08': 0.54313901, 'pres12': 0.5461338, 'pres16': 0.51890023, 2006: [0.55081266], 2008: [], 2010: [0.62944331], 2012: [0.51586059], 2014: [.5686], 2016: [0.56860915], 2018: [0.49]}, 'ar': {'pres08': 0.60171721, 'pres12': 0.62154405, 'pres16': 0.64285138, 2006: [], 2008: [0.0], 2010: [0.61048104], 2012: [], 2014: [0.58895833], 2016: [0.62299334], 2018: []}, 'ca': {'pres08': 0.3772155, 'pres12': 0.38127189, 'pres16': 0.33871779, 2006: [0.37074264], 2008: [], 2010: [0.4469534], 2012: [0.37475716], 2014: [], 2016: [0.0], 2018: [0.0]}, 'co': {'pres08': 0.45449365, 'pres12': 0.47252012, 'pres16': 0.47316667, 2006: [], 2008: [0.44593471], 2010: [0.49138188], 2012: [], 2014: [0.51029203], 2016: [0.46995547], 2018: []}, 'ct': {'pres08': 0.38681662, 'pres12': 0.41227423, 'pres16': 0.42858452, 2006: [0.1949818], 2008: [], 2010: [0.45158195], 2012: [0.43259142], 2014: [], 2016: [0.37506846], 2018: [0.42]}, 'de': {'pres08': 0.37361861, 'pres12': 0.40553045, 'pres16': 0.44001379, 2006: [0.29019438], 2008: [0.35313487], 2010: [0.41422921], 2012: [0.30358291], 2014: [0.43064259], 2016: [], 2018: [0.4]}, 'dc': {'pres08': 0.06599232, 'pres12': 0.07412351, 'pres16': 0.04304812, 2006: [], 2008: [], 2010: [], 2012: [], 2014: [], 2016: [], 2018: []}, 'fl': {'pres08': 0.4858034, 'pres12': 0.49557748, 'pres16': 0.50618835, 2006: [0.38716405], 2008: [], 2010: [0.70766787], 2012: [0.43327351], 2014: [], 2016: [0.53980578], 2018: [0.51]}, 'ga': {'pres08': 0.52628336, 'pres12': 0.53956649, 'pres16': 0.52661173, 2006: [], 2008: [0.31525622], 2010: [0.59921654], 2012: [], 2014: [0.53915937], 2016: [0.57175417], 2018: []}, 'hi': {'pres08': 0.27006274, 'pres12': 0.28296151, 'pres16': 0.32558663, 2006: [0.37481237], 2008: [], 2010: [0.22381407], 2012: [0.37398457], 2014: [0.28421294], 2016: [0.23206356], 2018: [0.28]}, 'id': {'pres08': 0.6302459, 'pres12': 0.66421387, 'pres16': 0.68310177, 2006: [], 2008: [0.6283206], 2010: [0.7406148], 2012: [], 2014: [0.65328362], 2016: [0.70459902], 2018: []}, 'il': {'pres08': 0.37265736, 'pres12': 0.41422477, 'pres16': 0.40979949, 2006: [], 2008: [0.29604426], 2010: [0.50846441], 2012: [], 2014: [0.44361346], 2016: [0.42032449], 2018: []}, 'in': {'pres08': 0.49478047, 'pres12': 0.55200375, 'pres16': 0.6011731, 2006: [1.0], 2008: [], 2010: [0.57707812], 2012: [0.46944677], 2014: [], 2016: [0.55130669], 2018: [0.53]}, 'ia': {'pres08': 0.45151222, 'pres12': 0.47040648, 'pres16': 0.55063548, 2006: [], 2008: [0.3729219], 2010: [0.6589727], 2012: [], 2014: [0.54349482], 2016: [0.62760265], 2018: []}, 'ks': {'pres08': 0.57612276, 'pres12': 0.61113327, 'pres16': 0.6111147, 2006: [], 2008: [0.62225807], 2010: [0.72657045], 2012: [], 2014: [1.0], 2016: [0.65854281], 2018: []}, 'ky': {'pres08': 0.58233428, 'pres12': 0.61542772, 'pres16': 0.65670629, 2006: [], 2008: [0.5296562], 2010: [0.55740479], 2012: [], 2014: [0.57980287], 2016: [0.57274552], 2018: []}, 'la': {'pres08': 0.59457174, 'pres12': 0.58746826, 'pres16': 0.60171677, 2006: [], 2008: [0.46736119], 2010: [0.60018691], 2012: [], 2014: [0.52308918], 2016: [0.6065461], 2018: []}, 'me': {'pres08': 0.41170475, 'pres12': 0.42140079, 'pres16': 0.48403209, 2006: [0.78190647], 2008: [0.61383512], 2010: [], 2012: [0.36758826], 2014: [0.6848842], 2016: [], 2018: [0.46]}, 'md': {'pres08': 0.37069913, 'pres12': 0.36678274, 'pres16': 0.3598375, 2006: [0.44913586], 2008: [], 2010: [0.36503012], 2012: [0.31988415], 2014: [], 2016: [0.36944741], 2018: [0.36]}, 'ma': {'pres08': 0.36802922, 'pres12': 0.38214319, 'pres16': 0.35348721, 2006: [0.30594329], 2008: [0.31954391], 2010: [], 2012: [0.46222761], 2014: [0.38039881], 2016: [], 2018: [0.4]}, 'mi': {'pres08': 0.41628698, 'pres12': 0.45199468, 'pres16': 0.50117668, 2006: [0.42027743], 2008: [0.35069675], 2010: [], 2012: [0.39247231], 2014: [0.43076489], 2016: [], 2018: [0.47]}, 'mn': {'pres08': 0.44770625, 'pres12': 0.46058774, 'pres16': 0.49168306, 2006: [0.39520086], 2008: [0.49993567], 2010: [], 2012: [0.31880698], 2014: [0.44668105], 2016: [], 2018: [0.39, 0.46]}, 'ms': {'pres08': 0.56641931, 'pres12': 0.55801899, 'pres16': 0.59089847, 2006: [0.64582582], 2008: [0.61435046, 1.0], 2010: [], 2012: [0.58497246], 2014: [0.61250809], 2016: [], 2018: [0.54, 0.59]}, 'mo': {'pres08': 0.50067579, 'pres12': 0.54778667, 'pres16': 0.59818561, 2006: [0.48828579], 2008: [], 2010: [0.57170253], 2012: [0.41642216], 2014: [], 2016: [0.51460769], 2018: [0.52]}, 'mt': {'pres08': 0.51169403, 'pres12': 0.57034232, 'pres16': 0.61109664, 2006: [0.49550398], 2008: [0.27084022], 2010: [], 2012: [0.48010454], 2014: [0.5905309], 2016: [], 2018: [0.49]}, 'ne': {'pres08': 0.57609074, 'pres12': 0.6112939, 'pres16': 0.63547674, 2006: [0.36117208], 2008: [0.58948417], 2010: [], 2012: [0.57774433], 2014: [0.67141916], 2016: [], 2018: [0.58]}, 'nv': {'pres08': 0.43613262, 'pres12': 0.46592458, 'pres16': 0.48706291, 2006: [0.57456391], 2008: [], 2010: [0.46972576], 2012: [0.50640453], 2014: [], 2016: [0.4867684], 2018: [0.48]}, 'nh': {'pres08': 0.45131459, 'pres12': 0.47166248, 'pres16': 0.49802972, 2006: [], 2008: [0.46727682], 2010: [0.61987508], 2012: [], 2014: [0.48372457], 2016: [0.49928206], 2018: []}, 'nj': {'pres08': 0.4213537, 'pres12': 0.41048034, 'pres16': 0.4271581, 2006: [0.45381917], 2008: [0.42817144], 2010: [], 2012: [0.40079838], 2014: [0.43118622], 2016: [], 2018: [0.46]}, 'nm': {'pres08': 0.423351, 'pres12': 0.44704795, 'pres16': 0.45349205, 2006: [0.0009095], 2008: [0.38672009], 2010: [], 2012: [0.47024206], 2014: [0.4444119], 2016: [], 2018: [0.46]}, 'ny': {'pres08': 0.34236143, 'pres12': 0.33957305, 'pres16': 0.36588494, 2006: [0.31005976], 2008: [], 2010: [0.28912171, 0.32047667], 2012: [0.25521923], 2014: [], 2016: [0.26488753], 2018: [0.33]}, 'nc': {'pres08': 0.49834037, 'pres12': 0.51034035, 'pres16': 0.51903746, 2006: [], 2008: [0.45627065], 2010: [0.56011479], 2012: [], 2014: [0.50814164], 2016: [0.5295356], 2018: []}, 'nd': {'pres08': 0.54408656, 'pres12': 0.60111208, 'pres16': 0.69809243, 2006: [0.30022418], 2008: [], 2010: [0.77431769], 2012: [0.49540874], 2014: [], 2016: [0.82222304], 2018: [0.55]}, 'oh': {'pres08': 0.47666159, 'pres12': 0.48485943, 'pres16': 0.54267685, 2006: [0.43824268], 2008: [], 2010: [0.59060974], 2012: [0.46855014], 2014: [], 2016: [0.6096339], 2018: [0.47]}, 'ok': {'pres08': 0.65645081, 'pres12': 0.6677232, 'pres16': 0.69304737, 2006: [], 2008: [0.59125435], 2010: [0.72994506], 2012: [], 2014: [0.70433441, 0.70069755], 2016: [0.73375957], 2018: []}, 'or': {'pres08': 0.41586279, 'pres12': 0.43728833, 'pres16': 0.43844161, 2006: [], 2008: [0.4822608], 2010: [0.40683808], 2012: [], 2014: [0.3981479], 2016: [0.37074179], 2018: []}, 'pa': {'pres08': 0.44770296, 'pres12': 0.47268066, 'pres16': 0.50375536, 2006: [0.41316242], 2008: [], 2010: [0.51008495], 2012: [0.45369023], 2014: [], 2016: [0.5074518], 2018: [0.44]}, 'ri': {'pres08': 0.35801862, 'pres12': 0.35983254, 'pres16': 0.41689296, 2006: [0.46481365], 2008: [0.26595516], 2010: [], 2012: [0.35043714], 2014: [0.29297096], 2016: [], 2018: [0.38]}, 'sc': {'pres08': 0.54544429, 'pres12': 0.55308255, 'pres16': 0.57460256, 2006: [], 2008: [0.57656381], 2010: [0.68980125], 2012: [], 2014: [0.59569856, 0.62230132], 2016: [0.6379825], 2018: []}, 'sd': {'pres08': 0.54295707, 'pres12': 0.59218499, 'pres16': 0.65971858, 2006: [], 2008: [0.37508308], 2010: [1.0], 2012: [], 2014: [0.63056851], 2016: [0.71827862], 2018: []}, 'tn': {'pres08': 0.57631472, 'pres12': 0.60351072, 'pres16': 0.63624343, 2006: [0.51379506], 2008: [0.6730593], 2010: [], 2012: [0.68093205], 2014: [0.66003874], 2016: [], 2018: [0.54]}, 'tx': {'pres08': 0.55935937, 'pres12': 0.58007897, 'pres16': 0.54713226, 2006: [0.63120576], 2008: [0.56135139], 2010: [], 2012: [0.58154549], 2014: [0.64175457], 2016: [], 2018: [0.51]}, 'ut': {'pres08': 0.64526361, 'pres12': 0.74626189, 'pres16': 0.62382898, 2006: [0.6674911], 2008: [], 2010: [0.65274435], 2012: [0.68537887], 2014: [], 2016: [0.71578547], 2018: [0.63]}, 'vt': {'pres08': 0.31100818, 'pres12': 0.31752741, 'pres16': 0.34813574, 2006: [0.33100771], 2008: [], 2010: [0.32457809], 2012: [0.2596582], 2014: [], 2016: [0.350267], 2018: [0.3]}, 'va': {'pres08': 0.46817416, 'pres12': 0.48032623, 'pres16': 0.47173624, 2006: [0.49800823], 2008: [0.3415165], 2010: [], 2012: [0.47042306], 2014: [0.49583796], 2016: [], 2018: [0.43]}, 'wa': {'pres08': 0.41247973, 'pres12': 0.42371702, 'pres16': 0.41213069, 2006: [0.41259443], 2008: [], 2010: [0.47635174], 2012: [0.39549009], 2014: [], 2016: [0.4098699], 2018: [0.4]}, 'wv': {'pres08': 0.56673744, 'pres12': 0.63674298, 'pres16': 0.72161052, 2006: [0.22950978], 2008: [0.36262174], 2010: [0.4480444], 2012: [0.37582743], 2014: [0.64316035], 2016: [], 2018: [0.48]}, 'wi': {'pres08': 0.42944322, 'pres12': 0.4653657, 'pres16': 0.50407989, 2006: [0.30456392], 2008: [], 2010: [0.00013123], 2012: [0.4714785], 2014: [], 2016: [0.51733264], 2018: [0.45]}, 'wy': {'pres08': 0.66562023, 'pres12': 0.71160634, 'pres16': 0.7570532, 2006: [0.70094636], 2008: [0.75716225, 0.73441117], 2010: [], 2012: [0.77748259], 2014: [0.80536139], 2016: [], 2018: [0.67]}}


print("hello")
# Using readlines() 
file2 = open('dataOut/presidential81216.csv', 'r') 
lines = file2.readlines() 

file20 = open('data/economist2020.csv', 'r') 
lines20 = file20.readlines() 

states16 = {}
states20 = {}
count = 0
# Strips the newline character 
i = 0
for line in lines:
	i+=1
	lineSplit = line.strip().split(",")
	if lineSplit[0] == "2012":
		states16[lineSplit[1]]={"2012":float(lineSplit[7])}
	elif lineSplit[0] == "2016":
		states16[lineSplit[1]]["pred"]=float(lineSplit[2])
		states20[lineSplit[1]]={"2016":float(lineSplit[7])}
i = 0
for line in lines20:
	i+=1
	lineSplit = line.strip().split(",")
	if i > 1:
		states20[lineSplit[3]]["pred"]=float(lineSplit[6])

statesOrdered = []
i = 0
for state in states16.keys():
	prod = (.5-states16[state]["2012"])**2+(.5-states16[state]["pred"])**2
	if len(senateData[state.lower()][2016])== 0:
		i+=1
		continue
	if len(senateData[state.lower()][2010])> 0:
		states16[state]["sLast"]=senateData[state.lower()][2010][0]
	else:
		states16[state]["sLast"]=senateData[state.lower()][2014][0]
	if len(senateData[state.lower()][2014])>0:
		states16[state]["sOther"]=senateData[state.lower()][2014][0]
	elif len(senateData[state.lower()][2012])>0:
		states16[state]["sOther"]=senateData[state.lower()][2012][0]

	states16[state]["prod"]=prod
	states16[state]["year"]=2016
	states16[state]["id"]=i
	states16[state]["name"]=state
	ii = 0
	added = False
	for s in statesOrdered:
		if prod < s["prod"]:
			statesOrdered.insert(ii,states16[state])
			added = True
			break;
		ii+=1
	if not added:
		statesOrdered.append(states16[state])
	i+=1
i = 0	
for state in states20.keys():
	prod = (.5-states20[state]["2016"])**2+(.5-states20[state]["pred"])**2
	if len(senateData[state.lower()][2014])== 0:
		i+=1
		continue
	if len(senateData[state.lower()][2014])> 0:
		states20[state]["sLast"]=senateData[state.lower()][2014][0]
		
	if len(senateData[state.lower()][2018])>0:
		states20[state]["sOther"]=senateData[state.lower()][2018][0]
	elif len(senateData[state.lower()][2016])>0:
		states20[state]["sOther"]=senateData[state.lower()][2016][0]
		
	states20[state]["prod"]=prod
	states20[state]["year"]=2020
	states20[state]["id"]=i
	states20[state]["name"]=state
	ii = 0
	added = False
	for s in statesOrdered:
		if prod < s["prod"]:
			statesOrdered.insert(ii,states20[state])
			added = True
			break;
		ii+=1
	if not added:
		statesOrdered.append(states20[state])	
	i+=1	

for state in statesOrdered:
	if state["pred"]>.5:
		line = '\n<tr data-id="'+str(state["id"])+'" data-year="'+str(state["year"])+'" data-party="D">'
		#line += '<td>'+state["name"]+'</td>'
		if state["year"] == 2016:
			line += '<td>+'+str(round(state["2012"]*2000-1000)/10.0)+'</td>'
			
		else:
			line += '<td>+'+str(round(state["2016"]*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round(state["pred"]*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round((1-state["sOther"])*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round((1-state["sLast"])*2000-1000)/10.0)+'</td>'
		line += '<td><input style="display: none;" value="'+str(round(state["pred"]*2000-1000)/10.0)+'" type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-D-poll"></input><input type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-D"></input></td>'
		line += '</tr>'
	else:
		line = '\n<tr data-id="'+str(state["id"])+'" data-year="'+str(state["year"])+'" data-party="R">'
		#line += '<td>'+state["name"]+'</td>'
		if state["year"] == 2016:
			line += '<td>+'+str(round((1-state["2012"])*2000-1000)/10.0)+'</td>'
		else:
			line += '<td>+'+str(round((1-state["2016"])*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round((1-state["pred"])*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round(state["sOther"]*2000-1000)/10.0)+'</td>'
		line += '<td>+'+str(round(state["sLast"]*2000-1000)/10.0)+'</td>'
		line += '<td><input style="display: none;" value="'+str(round((1-state["pred"])*2000-1000)/10.0)+'" type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-R-poll"></input><input type="text" name="'+str(state["name"])+'-'+str(state["year"])+'-R"></input></td>'
		line += '</tr>'
	line = line.replace('+-','-')
	file1.writelines([line])

file1.writelines(end)
file1.close()

