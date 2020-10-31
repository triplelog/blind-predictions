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
from sklearn.ensemble import GradientBoostingClassifier
import xml.etree.ElementTree as ET

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

def readpolls(filen,year):
    allgamesa  ={}
    with open(filen, 'r') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
        for row in spamreader:
        	try:
        		y = int(row[3])
        		district = row[5]
        		bias = float(row[25])
        		partisan = row[28]
        	except:
        		continue
        	if y != year or district == "US" or partisan != "":
        		continue
        	try:
        		allgamesa[district][0]+=bias
        		allgamesa[district][1]+=1
        	except:
        		allgamesa[district]=[0,0]
        		allgamesa[district][0]+=bias
        		allgamesa[district][1]+=1
    return allgamesa

def readfips(filen):
	allgamesa  ={}
	with open(filen, 'r') as csvfile:
		spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
		for row in spamreader:
			try:
				allgamesa[int(row[3])]=row[2]
			except:
				continue
	return allgamesa   
	   
def readtsv(filen):
        allgamesa  =[]
        with open(filen, 'r') as csvfile:
                spamreader = csv.reader(csvfile, delimiter='\t', quotechar='"')
                for row in spamreader:
                        allgamesa.append(row)
        return allgamesa
              
allCCES = readtsv("data/cces2019.tsv")
pollError = readpolls("data/house-polls.csv",2018)
stateFIPS = readfips("data/1976-2016-president.csv")
vars = []
tree = ET.parse('data/cces2019vars.xml')
root = tree.getroot()
for node in root.findall('./*'):
	print(node.tag)
	if node.tag == '{http://www.icpsr.umich.edu/DDI}dataDscr':
		for node2 in node.findall('./*'):
			if node2.tag == '{http://www.icpsr.umich.edu/DDI}var':
				#print(node2.attrib)
				#print(node2.get('name'))
				for node3 in node2.findall('./*'):
					if node3.tag == '{http://www.icpsr.umich.edu/DDI}labl':
						vars.append(node3.text)
						

print(len(vars))
print(len(allCCES[0]))
#for i in range(0,len(vars)):
#	print(i, vars[i])

usedvars = [1,3,4,5,6,8,18,25,64,65,75,77,137,139,140,146,147,151,198,212,213,249,250,251,270]
usedvars.append(271)
vars[271]="Poll Error"
races = {1:'White',2:'Black',3:'Hispanic',4:'Asian'}
hispanic = {1:'Yes',2:'No'}
party = {1:"D",7:'R'}
ideology = {1:"L",5:"C"}
religion = {1:"Protestant",2:"Catholic",3:"Mormon",4:"Orthodox",5:"Jewish",6:"Muslim",7:"Buddhist",8:"Hindu",9:"Atheist",10:"Agnostic",11:"NIP",12:"Other"}
for i in usedvars:
	print(i, vars[i], allCCES[10][i], allCCES[100][i])

partyID = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
vote = {1:0,2:0}
goodVoters = []

goodDistricts = {}
for i in range(0,len(allCCES)):
	voter = allCCES[i]
	try:
		if int(voter[139]) > 7:
			continue
		if int(voter[77]) > 2:
			continue
		if int(voter[249]) <0:
			continue
		if int(voter[251]) < 0:
			continue
	except:
		continue
	partyID[int(voter[139])]+=1
	vote[int(voter[77])]+=1

	d = stateFIPS[int(voter[249])]+"-"+str(voter[251])

	try:
		if pollError[d][1]>1:
			voter[271]=pollError[d][0]/pollError[d][1]
			voter[269]=d
			try:
				goodDistricts[d]+=1
			except:
				goodDistricts[d]=1
		else:
			continue
	except:
		continue
	goodVoters.append(voter)
print(goodDistricts)
print(len(goodDistricts.keys()))
print(partyID)
for i in range(1,8):
	print(i,100*partyID[i]/len(goodVoters))
print(len(goodVoters))

trainX = []
trainY = []
testX = []
testY = []
testDistrict = []
for voter in goodVoters:
	try:
		xArr = [int(voter[3]),int(voter[5]),int(voter[6]),int(voter[75]),int(voter[139]),int(voter[151]),int(voter[213])]
		error = voter[271]
	
	except:
		continue
	if random.random()<.5:
		trainX.append(xArr)
		trainY.append(error)
	else:
		testX.append(xArr)
		testY.append(error)
		testDistrict.append(voter[269])
	
print(len(trainY))	


clf = GradientBoostingRegressor(n_estimators=1000)
clf = clf.fit(trainX,trainY)
imp = clf.feature_importances_
print(imp)

predictions = clf.predict(testX)
sse = 0
districtPred = {}
for i in range(0,len(predictions)):
	try:
		d = testDistrict[i]
		districtPred[d][0]+=predictions[i]
		districtPred[d][1]+=1
	except:
		d = testDistrict[i]
		districtPred[d]=[0,0]
		districtPred[d][0]+=predictions[i]
		districtPred[d][1]+=1
xx = []
yy = []
for d in districtPred.keys():
	p = districtPred[d][0]/districtPred[d][1]
	a = pollError[d][0]/pollError[d][1]
	xx.append(p)
	yy.append(a)
	print(p,a)
	sse += (p*2-a)**2
print(sse/len(districtPred.keys()))
print(numpy.corrcoef(xx,yy))



