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
<text id="svg-ne3" transform="matrix(1,0,0,1,105.651,45.8515)" class="districtText" font-size="60" stroke="none" x="1160" y="1100">3</text>\n</g>'''
	file1.writelines([line])
	
	
file1.writelines(end)