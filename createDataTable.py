initial = ['{% extends "templates/index.html" %}\n{% block dataTable %}\n<table>']
end = ['</table>\n{% endblock %}']
file1 = open('templates/datatable.html', 'w')
file1.writelines(initial) 
 
print("hello")
# Using readlines() 
file2 = open('dataOut/presidential81216.csv', 'r') 
lines = file2.readlines() 

states = {}
count = 0
# Strips the newline character 
i = 0
for line in lines:
	i+=1
	lineSplit = line.strip().split(",")
	if lineSplit[0] == "2012":
		states[lineSplit[1]]={"2012":float(lineSplit[7])}
	elif lineSplit[0] == "2016":
		states[lineSplit[1]]["pred"]=float(lineSplit[2])
i = 0
for state in states.keys():
	line = '<tr data-id="'+str(i)+'">'
	line += '<td>'+state+'</td>'
	line += '<td>'+str(states[state]["2012"])+'</td>'
	line += '<td>'+str(states[state]["pred"])+'</td>'
	line += '<td><input type="text"></input></td>'
	line += '</tr>'
	file1.writelines([line])
	i+=1
file1.writelines(end)
file1.close()

