initial = ['{% extends "templates/index.html" %}\n{% block dataTable %}\n<table id="dataTable">']
end = ['</table>\n{% endblock %}']
file1 = open('templates/datatable.html', 'w')
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
			if state["2012"] > .5:
				line += '<td>+'+str(round(state["2012"]*2000-1000)/10.0)+'</td>'
			else:
				line += '<td>-'+str(round(1000-state["2012"]*2000)/10.0)+'</td>'
			
		else:
			if state["2016"] > .5:
				line += '<td>+'+str(round(state["2016"]*2000-1000)/10.0)+'</td>'
			else:
				line += '<td>-'+str(round(1000-state["2016"]*2000)/10.0)+'</td>'
		line += '<td>+'+str(round(state["pred"]*2000-1000)/10.0)+'</td>'
		line += '<td><input type="text"></input></td>'
		line += '</tr>'
	else:
		line = '\n<tr data-id="'+str(state["id"])+'" data-year="'+str(state["year"])+'" data-party="R">'
		#line += '<td>'+state["name"]+'</td>'
		if state["year"] == 2016:
			if state["2012"] < .5:
				line += '<td>+'+str(round((1-state["2012"])*2000-1000)/10.0)+'</td>'
			else:
				line += '<td>-'+str(round(1000-(1-state["2012"])*2000)/10.0)+'</td>'
			
		else:
			if state["2016"] < .5:
				line += '<td>+'+str(round((1-state["2016"])*2000-1000)/10.0)+'</td>'
			else:
				line += '<td>-'+str(round(1000-(1-state["2016"])*2000)/10.0)+'</td>'
		line += '<td>+'+str(round((1-state["pred"])*2000-1000)/10.0)+'</td>'
		line += '<td><input type="text"></input></td>'
		line += '</tr>'
	file1.writelines([line])

file1.writelines(end)
file1.close()

