import time
import sys
import random
import csv
import math
import json

def pywin(dperc):
	return 1.0/(1.0+((1.01-dperc)/(dperc+.01))**7.5)
def undopywin(x,tvotes):
	ndistricts = tvotes*1.0/200000
	exp = 2.0+4.0/ndistricts
	a = (1.0/x-1.0)**(1.0/exp)
	return (1.01-.01*a)/(a+1)
	
def writecsv(parr, filen):
        with open(filen, 'w') as csvfile:
                spamwriter = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
                for i in range(0,len(parr)):
                        try:
                                spamwriter.writerow(parr[i])
                        except:
                                print(parr[i], i)



def readcsv(filen):
        allgamesa  =[]
        with open(filen, 'r') as csvfile:
                spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
                for row in spamreader:
                        allgamesa.append(row)
        return allgamesa
        
allPres = readcsv("1976-2016-president.csv")

actualEV = {'AL':9,'AK':3,'AZ':11,'AR':6,'CA':55,'CO':9,'CT':7,'DE':3,'DC':3,'FL':29,'GA':16,'HI':4,'ID':4,'IL':20,'IN':11,'IA':6,'KS':6,'KY':8,'LA':8,'ME':4,'MD':10,'MA':11,'MI':16,'MN':10,'MS':6,'MO':10,'MT':3,'NE':5,'NV':6,'NH':4,'NJ':14,'NM':5,'NY':29,'NC':15,'ND':3,'OH':18,'OK':7,'OR':7,'PA':20,'RI':4,'SC':9,'SD':3,'TN':11,'TX':38,'UT':6,'VT':3,'VA':13,'WA':12,'WV':5,'WI':10,'WY':3}
actualEV00s = {'AL':9,'AK':3,'AZ':10,'AR':6,'CA':55,'CO':9,'CT':7,'DE':3,'DC':3,'FL':27,'GA':15,'HI':4,'ID':4,'IL':21,'IN':11,'IA':7,'KS':6,'KY':8,'LA':9,'ME':4,'MD':10,'MA':12,'MI':17,'MN':10,'MS':6,'MO':11,'MT':3,'NE':5,'NV':5,'NH':4,'NJ':15,'NM':5,'NY':31,'NC':15,'ND':3,'OH':20,'OK':7,'OR':7,'PA':21,'RI':4,'SC':8,'SD':3,'TN':11,'TX':34,'UT':5,'VT':3,'VA':13,'WA':11,'WV':5,'WI':10,'WY':3}
actualEV90s = {'AL':9,'AK':3,'AZ':8,'AR':6,'CA':54,'CO':8,'CT':8,'DE':3,'DC':3,'FL':25,'GA':13,'HI':4,'ID':4,'IL':22,'IN':12,'IA':7,'KS':6,'KY':8,'LA':9,'ME':4,'MD':10,'MA':12,'MI':18,'MN':10,'MS':7,'MO':11,'MT':3,'NE':5,'NV':4,'NH':4,'NJ':15,'NM':5,'NY':33,'NC':14,'ND':3,'OH':21,'OK':8,'OR':7,'PA':23,'RI':4,'SC':8,'SD':3,'TN':11,'TX':32,'UT':5,'VT':3,'VA':13,'WA':11,'WV':5,'WI':11,'WY':3}


states = {}

		
for myYear in [2000,2004,2008,2012,2016]:

	for i in allPres[1:]:
		year = int(i[0])
		state = i[2]
		party = i[8]
		votes = int(i[10])
		if year == myYear and party == 'republican':
			if state not in states.keys():
				states[state]={}
			states[state][myYear]={'pres':[votes]}
	
	for i in allPres[1:]:
		year = int(i[0])
		state = i[2]
		party = i[8]
		votes = int(i[10])
		if year == myYear and party[:8] == 'democrat':
			states[state][myYear]['pres'].append(votes)



for state in states.keys():
	#print(state,round(states[state][2000]['pres'][0]/(sum(states[state][2000]['pres'])),3),round(states[state][2004]['pres'][0]/(sum(states[state][2004]['pres'])),3),round(states[state][2008]['pres'][0]/(sum(states[state][2008]['pres'])),3),round(states[state][2012]['pres'][0]/(sum(states[state][2012]['pres'])),3),round(states[state][2016]['pres'][0]/(sum(states[state][2016]['pres'])),3))
	donot = 0

just141618 = {}
orderedStates = []
for state in states.keys():
	just141618[state.lower()]={'votes16':sum(states[state][2016]['pres']),'ev10':actualEV[state],'pres08':round(states[state][2008]['pres'][0]/(sum(states[state][2008]['pres'])),8),'pres12':round(states[state][2012]['pres'][0]/(sum(states[state][2012]['pres'])),8),'pres16':round(states[state][2016]['pres'][0]/(sum(states[state][2016]['pres'])),8)}
	isLast = True
	for idx,i in enumerate(orderedStates):
		if just141618[state.lower()]['pres16']<i['pres16']:
			isLast = False
			orderedStates.insert(idx,{'abbrev':state.lower(),'votes16':sum(states[state][2016]['pres']),'ev10':actualEV[state],'pres08':round(states[state][2008]['pres'][0]/(sum(states[state][2008]['pres'])),8),'pres12':round(states[state][2012]['pres'][0]/(sum(states[state][2012]['pres'])),8),'pres16':round(states[state][2016]['pres'][0]/(sum(states[state][2016]['pres'])),8)})
			break
	if isLast:
		orderedStates.append({'abbrev':state.lower(),'votes16':sum(states[state][2016]['pres']),'ev10':actualEV[state],'pres08':round(states[state][2008]['pres'][0]/(sum(states[state][2008]['pres'])),8),'pres12':round(states[state][2012]['pres'][0]/(sum(states[state][2012]['pres'])),8),'pres16':round(states[state][2016]['pres'][0]/(sum(states[state][2016]['pres'])),8)})
			
print(orderedStates)
	
	