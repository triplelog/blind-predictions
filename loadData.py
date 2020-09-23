initial = ['']
end = ['']
file1 = open('dataOut/presidential81216.csv', 'w')
file1.writelines(initial) 
 
print("hello")
# Using readlines() 
file2 = open('data/state_priors_08_12_16.csv', 'r') 
lines = file2.readlines() 
  
count = 0
# Strips the newline character 
i = 0
for line in lines:
	i+=1
	lineSplit = line.strip().split(",")
	if lineSplit[4] == "0" or i == 1:
		file1.writelines([line])
file1.writelines(end)
file1.close()


