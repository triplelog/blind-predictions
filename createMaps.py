file2 = open('correlations.csv', 'r') 
lines = file2.readlines() 

states = ['AK', 'AL', 'AZ', 'AR', 'CA', 'GA', 'DE', 'CT', 'CO', 'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'FL', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'MD', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VA', 'WA', 'WV', 'WI', 'WY', 'DC']
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
		if idx == 0:
			line = '''<text id="svg-me1" class="districtText" font-size="3" stroke="none" x="260.5" y="93">1</text>
<text id="svg-me2" class="districtText" font-size="3" stroke="none" x="263.5" y="93">2</text>
<text id="svg-ne1" class="districtText" font-size="3" stroke="none" x="189.5" y="102.5">1</text>
<text id="svg-ne2" class="districtText" font-size="3" stroke="none" x="192.5" y="102.5">2</text>
<text id="svg-ne3" class="districtText" font-size="3" stroke="none" x="195.5" y="102.5">3</text>\n'''
		else:
			line = ""
		line += '<g id="svg-'+states[idx].lower()+'" style="pointer-events: all;" stroke-opacity="1" stroke-width="3.07087" stroke-linecap="square" stroke-linejoin="bevel" transform="matrix(1,0,0,1,105.651,45.8515)"'
		line += ' font-family="MS Shell Dlg 2" font-size="34.375" font-weight="400" font-style="normal">\n'
		skip = 2
		idx+=1
	file1.writelines([line])
	
	
file1.writelines(end)