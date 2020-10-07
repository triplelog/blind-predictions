initial = ['std::map<int,std::vector<double> > createCorrelations(){\nstd::map<int,std::vector<double> > correlations;\n']
end = ['return correlations;\n}\n']
file1 = open('data.cpp', 'w')
file1.writelines(initial) 
 
print("hello")
# Using readlines() 
file2 = open('correlations.csv', 'r') 
lines = file2.readlines() 
  
count = 0
# Strips the newline character 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	lineText = "{"
	for ii in range(1,52):
		lineText += " "+lineSplit[ii]
		if ii < 51:
			lineText += ","
		else:
			lineText += " }"
	line1 = 'double arr'+lineSplit[0]+'[] = '+lineText+';\n';
	line2 = 'std::vector<double> vect'+lineSplit[0]+';\n';
	line3 = "";
	for ii in range(0,51):
		line3 += 'vect'+lineSplit[0]+'.push_back(arr'+lineSplit[0]+'['+str(ii)+']); ';
	line4 = '\ncorrelations['+str(i-2)+']= vect'+lineSplit[0]+';\n'
	file1.writelines([line1,line2,line3,line4])
file1.writelines(end)

initial = ['std::vector<std::string> createStates(){\nstd::vector<std::string> states;\n']
end = ['return states;\n}\n']
file1.writelines(initial) 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	lineText = "{"
	for ii in range(1,52):
		lineText += lineSplit[ii]
		if ii < 51:
			lineText += ","
		else:
			lineText += "}"
	line2 = 'states.push_back("'+lineSplit[0]+'");\n'
	file1.writelines([line2])
file1.writelines(end)


initial = ['std::vector<double> createPredictions16(){\nstd::vector<double> predictions;\n']
end = ['return predictions;\n}\n']
file2 = open('predictions16.csv', 'r') 
lines = file2.readlines() 

file1.writelines(initial) 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	pred = float(lineSplit[4])
	if pred > .99999:
		pred = .99999
	elif pred < .00001:
		pred = .00001
	#print(lineSplit[3],pred)
	line2 = 'predictions.push_back('+str(pred)+');\n'
	file1.writelines([line2])
file1.writelines(end)


initial = ['std::vector<double> createPredictions20(){\nstd::vector<double> predictions;\n']
end = ['return predictions;\n}\n']
file2 = open('predictions.csv', 'r') 
lines = file2.readlines() 

file1.writelines(initial) 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	pred = float(lineSplit[7])
	if pred > .99999:
		pred = .99999
	elif pred < .00001:
		pred = .00001
	#print(lineSplit[3],pred)
	line2 = 'predictions.push_back('+str(pred)+');\n'
	file1.writelines([line2])
file1.writelines(end)


initial = ['std::vector<double> addResults20(){\nstd::vector<double> predictions;\n']
end = ['return predictions;\n}\n']
file2 = open('results20.csv', 'r') 
lines = file2.readlines() 

file1.writelines(initial) 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	predMin = int(lineSplit[1])
	predMax = int(lineSplit[2])

	#print(lineSplit[3],pred)
	line2 = 'predictions.push_back('+str(predMin)+');\n'
	line2 += 'predictions.push_back('+str(predMax)+');\n'
	file1.writelines([line2])
file1.writelines(end)


initial = ['std::vector<int> createEV(){\nstd::vector<int> evs;\n']
end = ['return evs;\n}\n']
file2 = open('ev.csv', 'r') 
lines = file2.readlines() 

file1.writelines(initial) 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	ev = int(lineSplit[8])

	line2 = 'evs.push_back('+str(ev)+');\n'
	file1.writelines([line2])
file1.writelines(end)


initial = ['std::vector<int> createVEPEV(){\nstd::vector<int> vepevs;\n']
end = ['return vepevs;\n}\n']
file2 = open('2018vep.csv', 'r') 
lines = file2.readlines() 

file1.writelines(initial) 
i = 0
for line in lines:
	i+=1
	if i==1:
		continue
	lineSplit = line.strip().split(",")
	ev = int(lineSplit[9])

	line2 = 'vepevs.push_back('+str(ev)+');\n'
	file1.writelines([line2])
file1.writelines(end)
file1.close()


