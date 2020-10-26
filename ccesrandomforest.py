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

def readtsv(filen):
        allgamesa  =[]
        with open(filen, 'r') as csvfile:
                spamreader = csv.reader(csvfile, delimiter='\t', quotechar='"')
                for row in spamreader:
                        allgamesa.append(row)
        return allgamesa
              
allCCES = readtsv("data/cces2019.tsv")

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

usedvars = [1,3,4,5,6,8,18,77,139,140,146,147,151,250]
races = {1:'White',2:'Black',3:'Hispanic',4:'Asian'}
hispanic = {1:'Yes',2:'No'}
party = {1:"D",7:'R'}
ideology = {1:"L",5:"C"}
religion = {1:"Protestant",2:"Catholic",3:"Mormon",4:"Orthodox",5:"Jewish",6:"Muslim",7:"Buddhist",8:"Hindu",9:"Atheist",10:"Agnostic",11:"NIP",12:"Other"}
for i in usedvars:
	print(i, vars[i])

partyID = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
goodVoters = []
for i in range(0,len(allCCES)):
	voter = allCCES[i]
	try:
		if int(voter[139]) > 7:
			continue
		if int(voter[77]) > 2:
			continue
	except:
		continue
	partyID[int(voter[139])]+=1
	goodVoters.append(voter)
print(partyID)
for i in range(1,8):
	print(i,100*partyID[i]/len(goodVoters))
print(len(goodVoters))

sseAll = []
for ii in range(0,1000):
	sampleID = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	nv = 0
	sse = 0
	for i in range(0,1000):
		x = random.randint(0,len(goodVoters)-1)
		voter = goodVoters[x]
		sampleID[int(voter[139])]+=1
		nv+=1
	for i in range(1,8):
		se = (100*sampleID[i]/nv-100*partyID[i]/len(goodVoters))*(100*sampleID[i]/nv-100*partyID[i]/len(goodVoters))
		sse+=se
	sseAll.append(sse)
print(numpy.mean(sseAll))
print(numpy.std(sseAll))

sseAll = []

for ii in range(0,1000):
	sampleID = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	nv = 0
	sse = 0
	while nv < 1000:
		x = random.randint(0,len(goodVoters)-1)
		voter = goodVoters[x]
		probAnswer = 1.0/float(voter[1])
		r = random.random()
		if r >= probAnswer:
			continue
		sampleID[int(voter[139])]+=1
		nv+=1

	for i in range(1,8):
		se = (100*sampleID[i]/nv-100*partyID[i]/len(goodVoters))*(100*sampleID[i]/nv-100*partyID[i]/len(goodVoters))
		sse+=se
	sseAll.append(sse)
print(numpy.mean(sseAll))
print(numpy.std(sseAll))


sseAll = []

for ii in range(0,1000):
	sampleID = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	nv = 0
	sse = 0
	wv = 0
	while nv < 1000:
		x = random.randint(0,len(goodVoters)-1)
		voter = goodVoters[x]
		probAnswer = random.random()
		r = random.random()
		if r >= probAnswer:
			continue
		sampleID[int(voter[139])]+=1.0/probAnswer
		nv+=1
		wv+=1.0/probAnswer

	for i in range(1,8):
		se = (100*sampleID[i]/wv-100*partyID[i]/len(goodVoters))*(100*sampleID[i]/wv-100*partyID[i]/len(goodVoters))
		sse+=se
	sseAll.append(sse)
print(numpy.mean(sseAll))
print(numpy.std(sseAll))

asse = 0
for iii in range(0,10):
	trainX = []
	trainY = []
	testX = []
	testY = []
	allGoodX = []
	allGoodY = []
	sampleID = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	for i in range(0,400):
		testX.append([])
		testY.append([])
	for i in range(0,len(goodVoters)):
		voter = goodVoters[i]
		try:
			#x = [int(voter[3]),int(voter[4]),int(voter[5]),int(voter[6]),int(voter[18]),int(voter[151])]
			#x = [int(voter[6]),int(voter[3]),int(voter[4]),int(voter[5]),int(voter[146]),int(voter[151])]
			x = [int(voter[151])]
		except:
			continue
		if random.random()<1000.0/15223:
			trainX.append(x)
			trainY.append(int(voter[139]))
		else:
			g = random.randint(0,399)
			testX[g].append(x)
			testY[g].append(int(voter[139]))
		allGoodX.append(x)
		allGoodY.append(int(voter[139]))
	#print(len(trainY))
	clfC = GradientBoostingClassifier(n_estimators=1000)
	clfC = clfC.fit(trainX,trainY)
	predAll = clfC.predict(allGoodX)
	nv = 0
	for ii in predAll:
		sampleID[ii]+=1
		nv+=1
	sse = 0
	for i in range(1,8):
		se = (100*sampleID[i]/nv-100*partyID[i]/len(goodVoters))*(100*sampleID[i]/nv-100*partyID[i]/len(goodVoters))
		sse+=se
	print(sampleID,sse)
	clf = GradientBoostingRegressor(n_estimators=1000)
	clf = clf.fit(trainX,trainY)
	imp = clf.feature_importances_
	#print(imp)
	allX = []
	allY = []
	sse = 0
	for i in range(0,400):
		predictions = clf.predict(testX[i])
		sumPred = 0
		for ii in predictions:
			sumPred += ii
		#print(sumPred,sum(testY[i]))
		allX.append(sumPred)
		allY.append(sum(testY[i]))
		sse += (sumPred-sum(testY[i]))*(sumPred-sum(testY[i]))
	#print(imp,numpy.corrcoef(allX,allY), sse)
	asse += sse
print(asse/4000)


