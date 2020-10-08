file2 = open('correlations.csv', 'r') 
lines = file2.readlines() 

states = ['AK', 'AL', 'AZ', 'AR', 'CA', 'GA', 'DE', 'CT', 'CO', 'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'FL', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'MD', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VA', 'WA', 'WV', 'WI', 'WY', 'DC']
districts = {'al': ['3', '2', '7', '5', '4', '1', '6'], 'ak': ['0'], 'az': ['6', '2', '9', '4', '1', '7', '5', '8', '3'], 'ar': ['2', '3', '4', '1'], 'ca': ['30', '6', '29', '34', '11', '5', '15', '28', '33', '17', '26', '25', '24', '23', '38', '48', '49', '45', '2', '43', '51', '22', '40', '44', '36', '42', '41', '35', '50', '37', '10', '27', '31', '9', '52', '53', '21', '18', '14', '13', '4', '32', '3', '8', '39', '47', '16', '19', '20', '7', '1', '12', '46'], 'co': ['2', '4', '3', '6', '5', '7', '1'], 'ct': ['1', '5', '3', '2', '4'], 'de': ['0'], 'fl': ['19', '20', '25', '26', '27', '11', '6', '4', '24', '22', '21', '7', '8', '17', '23', '5', '2', '18', '16', '13', '12', '9', '3', '10', '14', '15', '1'], 'ga': ['1', '7', '2', '6', '3', '13', '11', '12', '9', '14', '4', '8', '10', '5'], 'hi': ['1', '2'], 'id': ['1', '2'], 'il': ['2', '12', '15', '17', '13', '11', '4', '18', '1', '3', '7', '9', '6', '8', '5', '10', '14', '16'], 'in': ['4', '5', '2', '7', '1', '9', '3', '6', '8'], 'ia': ['1', '3', '4', '2'], 'ks': ['3', '1', '2', '4'], 'ky': ['6', '2', '3', '5', '1', '4'], 'la': ['5', '1', '6', '2', '3', '4'], 'me': ['2', '1'], 'md': ['4', '5', '1', '3', '7', '8', '6', '2'], 'ma': ['2', '1', '8', '9', '4', '6', '7', '5', '3'], 'mi': ['2', '3', '13', '4', '6', '12', '1', '11', '8', '5', '14', '10', '9', '7'], 'mn': ['2', '7', '1', '8', '3', '5', '6', '4'], 'ms': ['1', '3', '4', '2'], 'mo': ['8', '3', '7', '4', '6', '5', '2', '1'], 'mt': ['0'], 'ne': ['3', '2', '1'], 'nv': ['2', '4', '3', '1'], 'nh': ['1', '2'], 'nj': ['5', '11', '9', '3', '8', '7', '12', '1', '2', '4', '6', '10'], 'nm': ['1', '2', '3'], 'ny': ['22', '5', '6', '14', '12', '8', '7', '24', '23', '26', '20', '19', '17', '3', '11', '4', '9', '10', '27', '15', '13', '25', '21', '16', '2', '18', '1'], 'nc': ['3', '9', '12', '10', '7', '6', '2', '1', '11', '4', '13', '5', '8'], 'nd': ['0'], 'oh': ['4', '1', '16', '2', '12', '3', '15', '5', '6', '7', '13', '11', '14', '9', '8', '10'], 'ok': ['3', '4', '5', '2', '1'], 'or': ['4', '3', '2', '1', '5'], 'pa': ['9', '18', '8', '3', '10', '14', '7', '15', '12', '1', '17', '11', '13', '2', '5', '4', '16', '6'], 'ri': ['1', '2'], 'sc': ['7', '2', '6', '1', '3', '5', '4'], 'sd': ['0'], 'tn': ['8', '9', '6', '3', '7', '1', '2', '4', '5'], 'tx': ['26', '14', '6', '15', '18', '22', '9', '2', '7', '36', '10', '8', '29', '19', '27', '34', '32', '24', '33', '30', '4', '13', '1', '28', '35', '16', '5', '25', '23', '11', '12', '31', '3', '21', '20', '17'], 'ut': ['3', '2', '1', '4'], 'vt': ['0'], 'va': ['1', '2', '6', '4', '3', '11', '10', '5', '9', '8', '7'], 'wa': ['2', '3', '1', '10', '5', '7', '6', '4', '8', '9'], 'wv': ['1', '2', '3'], 'wi': ['8', '6', '5', '7', '1', '2', '3', '4'], 'wy': ['0']}
districtList = []
i = 0
for line in lines:
	if i == 0:
		i+=1
		continue
	lineSplit = line.strip().split(",")
	if lineSplit[0] not in states and lineSplit[0] != 'DC':
		states.append(lineSplit[0])
	i+=1
#states.append('DC')
#print(states)
for state in districts.keys():
	if state != 'DC':
		cdList = districts[state.lower()]
		for i in range(0,len(cdList)):
			cdList[i] = int(cdList[i])
		cdList.sort()
		for i in range(0,len(cdList)):
			cdList[i] = str(cdList[i])
		for i in range(0,len(cdList)):
			districtList.append(state.lower()+"-"+cdList[i])
			if state.lower()+"-"+cdList[i] == "hi-1":
				districtList.append(state.lower()+"-"+cdList[i])
				districtList.append(state.lower()+"-"+cdList[i])
				districtList.append(state.lower()+"-"+cdList[i])
				districtList.append(state.lower()+"-"+cdList[i])
				districtList.append(state.lower()+"-"+cdList[i])
			if state.lower()+"-"+cdList[i] == "ma-9":
				districtList.append(state.lower()+"-"+cdList[i])
				districtList.append(state.lower()+"-"+cdList[i])
			if state.lower()+"-"+cdList[i] == "va-2":
				districtList.append(state.lower()+"-"+cdList[i])
#print(districtList)
initial = ['']
end = ['']
file1 = open('static/maps/electoralsvg.svg', 'w')
file1.writelines(initial) 

print("hello")
# Using readlines() 
file2 = open('static/maps/EC20.svg', 'r') 
lines = file2.readlines() 
  
count = 0
# Strips the newline character 
idx = 0
skip = 0
for i in range(0,len(lines)):
	line = lines[i]
	if skip > 0:
		skip-=1
		continue
	startState = '<g fill="none" stroke="#000000" stroke-opacity="1" stroke-width="3.07087"'
	if line[:len(startState)] == startState:
		line = ""
		line += '<g id="svg-'+states[idx].lower()+'" stroke-opacity="1" stroke-width="3.07087" stroke-linecap="square" stroke-linejoin="bevel" transform="matrix(1,0,0,1,105.651,45.8515)"'
		line += ' font-family="MS Shell Dlg 2" font-size="34.375" font-weight="400" font-style="normal">\n'
		skip = 2
		idx+=1
	if i+1<len(lines) and lines[i+1][0:6] == '</svg>':
			line = '''<text id="svg-me1" transform="matrix(1,0,0,1,105.651,45.8515)" class="districtText" font-size="60" stroke="none" x="2640" y="130">1</text>
<text id="svg-me2" transform="matrix(1,0,0,1,105.651,45.8515)" class="districtText" font-size="60" stroke="none" x="2680" y="130">2</text>
<text id="svg-ne1" transform="matrix(1,0,0,1,105.651,45.8515)" class="districtText" font-size="60" stroke="none" x="1100" y="1100">1</text>
<text id="svg-ne2" transform="matrix(1,0,0,1,105.651,45.8515)" class="districtText" font-size="60" stroke="none" x="1130" y="1100">2</text>
<text id="svg-ne3" transform="matrix(1,0,0,1,105.651,45.8515)" class="districtText" font-size="60" stroke="none" x="1160" y="1100">3</text>\n</g>\n'''
	file1.writelines([line])
	
	
file1.writelines(end)
file1.close()

file1 = open('static/maps/housesvg.svg', 'w')
file1.writelines(initial) 

print("hello")
# Using readlines() 
file2 = open('static/maps/CDs21.svg', 'r') 
lines = file2.readlines() 
  
count = 0
# Strips the newline character 
idx = 0
for i in range(0,len(lines)):
	line = lines[i]
	startState = '<path vector-effect="none" fill-rule="evenodd"'
	
	if line[:len(startState)] == startState:
		if idx>59:
			cdID = districtList[idx-60]
		else:
			cdID = "state-"+str(idx)
		lineEnd = line[len(startState):]
		line = '<path id="'+cdID+'" vector-effect="none" fill-rule="evenodd"'+lineEnd
		idx+=1
	file1.writelines([line])
	
	
file1.writelines(end)