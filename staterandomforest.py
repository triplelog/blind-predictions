import time
import sys
import random
import csv
import math
import json
import numpy
import sklearn
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.ensemble import RandomForestRegressor
from sklearn.ensemble import AdaBoostRegressor
from sklearn.ensemble import GradientBoostingRegressor

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
        
allPres = readcsv("data/1976-2016-president.csv")


candidates = {};
states = {}
for i in range(1,len(allPres)):
	if (len(allPres[i]) < 10):
		continue

	year = int(allPres[i][0])
	party = allPres[i][8][0:8].lower()
	if (party == "democrat"):
		party = "D"
		try:
			candidates[allPres[i][7]][year]="D"
		except:
			candidates[allPres[i][7]]={}
			candidates[allPres[i][7]][year]="D"
	if (party == "republic"):
		party = "R"
		try:
			candidates[allPres[i][7]][year]="R"
		except:
			candidates[allPres[i][7]]={}
			candidates[allPres[i][7]][year]="R"

for i in range(1,len(allPres)):
	if (len(allPres[i]) < 10):
		continue

	year = int(allPres[i][0])
	party = allPres[i][8][0:8].lower()
	if (party == "democrat"):
		party = "D"
	elif (party == "republic"):
		party = "R"
	else:
		try:
			party = candidates[allPres[i][7]][year]
		except:
			continue

	
	try:
		x = states[allPres[i][2]]
	except:
		states[allPres[i][2]]={}
	
	
	if (party == "D"):
		try:
			states[allPres[i][2]]['dvotes'+str(year)]+=int(allPres[i][10])
		except:
			states[allPres[i][2]]['dvotes'+str(year)]=int(allPres[i][10])

		states[allPres[i][2]]['tvotes'+str(year)]=int(allPres[i][11])

		try:
			x = states[allPres[i][2]]['rvotes'+str(year)]
			states[allPres[i][2]]['dmov'+str(year)]= 100*(states[allPres[i][2]]['dvotes'+str(year)]/states[allPres[i][2]]['tvotes'+str(year)] - states[allPres[i][2]]['rvotes'+str(year)]/states[allPres[i][2]]['tvotes'+str(year)])
			states[allPres[i][2]]['rmov'+str(year)]= -1*states[allPres[i][2]]['dmov'+str(year)]
		except:
			pass

	elif (party == "R"):
		try:
			states[allPres[i][2]]['rvotes'+str(year)]+=int(allPres[i][10]);
		except:
			states[allPres[i][2]]['rvotes'+str(year)]=int(allPres[i][10]);
		states[allPres[i][2]]['tvotes'+str(year)]=int(allPres[i][11]);
		
		try:
			x = states[allPres[i][2]]['dvotes'+str(year)]
			states[allPres[i][2]]['dmov'+str(year)]= 100*(states[allPres[i][2]]['dvotes'+str(year)]/states[allPres[i][2]]['tvotes'+str(year)] - states[allPres[i][2]]['rvotes'+str(year)]/states[allPres[i][2]]['tvotes'+str(year)])
			states[allPres[i][2]]['rmov'+str(year)]= -1*states[allPres[i][2]]['dmov'+str(year)]
		except:
			pass
	

predyear = 2016
for state in states.keys():
	x = []
	y = []
	for i in range(0,9):
		year = 1980+i*4
		yearRow = []
		for ostate in states.keys():
			if state != ostate:
				yearRow.append(states[ostate]['dmov'+str(year)]-states[ostate]['dmov'+str(year-4)])
		for ii in range(0,i*i+1):
			x.append(yearRow)
			y.append(round(states[state]['dmov'+str(year)]-states[state]['dmov'+str(year-4)]))
	clf = AdaBoostRegressor(random_state=1, n_estimators=1000)
	clf = clf.fit(x,y)
	imp = clf.feature_importances_
	idx = 0
	for ostate in states.keys():
		if state != ostate:
			if state =="SC":
				print(ostate,imp[idx])
			idx+=1

	p = []
	for ostate in states.keys():
		if state != ostate:
			p.append(states[ostate]['dmov'+str(predyear)]-states[ostate]['dmov'+str(predyear-4)])
	predictions = clf.predict([p])
	print(state,predictions[0]+states[state]['dmov'+str(predyear-4)],round(states[state]['dmov'+str(predyear)]))

