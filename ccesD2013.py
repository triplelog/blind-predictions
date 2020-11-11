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
              
allCCES = readtsv("data/cces2013.tsv")
pollError = readpolls("data/house-polls.csv",2018)
stateFIPS = readfips("data/1976-2016-president.csv")
vars = []
tree = ET.parse('data/cces2013vars.xml')
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

usedvars = [107,109,110,111,112,115,116,117,212,214,216]


for i in usedvars:
	print(i, vars[i], allCCES[10][i], allCCES[100][i])

ratings = {'T':{},'Y':{},'D':{},'R':{},'DH':{},'RH':{}}
for i in range(1,8):
	ratings['T'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['Y'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['D'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['R'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['DH'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['RH'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}

npeople = 0
allV = []
allValues = {1:0,2:0,3:0,4:0,5:0,6:0,7:0}
dToD = {0:0,1:0,2:0,3:0,4:0,5:0,6:0}
dToR = {0:0,1:0,2:0,3:0,4:0,5:0,6:0}
for i in range(0,len(allCCES)):
	try:
		me = int(allCCES[i][107])
		T = int(allCCES[i][109])
		Y = int(allCCES[i][110])
		D = int(allCCES[i][111])
		R = int(allCCES[i][112])
		H = int(allCCES[i][117])
		if me > 7 or T > 7 or D > 7 or R > 7 or Y > 7:
			continue
	except:
		continue
	
	ratings['T'][me][T]+=1
	ratings['Y'][me][Y]+=1
	ratings['D'][me][D]+=1
	ratings['R'][me][R]+=1
	dToD[abs(me-D)]+=1
	dToR[abs(me-R)]+=1
	if H < 8:
		if allCCES[i][212][0:8] == "Democrat":
			ratings['DH'][me][H]+=1
		elif allCCES[i][212][0:8] == "Republic":
			ratings['RH'][me][H]+=1
	npeople+=1
	allV.append(me)
	allValues[me]+=1


for i in range(1,8):
	print(i)
	n = [0,0,0,0,0,0]
	s = [0,0,0,0,0,0]
	
	for ii in range(1,8):
		n[0]+=ratings['T'][i][ii]
		s[0]+=ratings['T'][i][ii]*ii
		n[1]+=ratings['Y'][i][ii]
		s[1]+=ratings['Y'][i][ii]*ii
		n[2]+=ratings['D'][i][ii]
		s[2]+=ratings['D'][i][ii]*ii
		n[3]+=ratings['R'][i][ii]
		s[3]+=ratings['R'][i][ii]*ii
		n[4]+=ratings['DH'][i][ii]
		s[4]+=ratings['DH'][i][ii]*ii
		n[5]+=ratings['RH'][i][ii]
		s[5]+=ratings['RH'][i][ii]*ii
		
	print('T ',ratings['T'][i],s[0]/n[0])
	print('Y ',ratings['Y'][i],s[1]/n[1])
	print('D ',ratings['D'][i],s[2]/n[2])
	print('R ',ratings['R'][i],s[3]/n[3])
	print('DH ',ratings['DH'][i],s[4]/n[4])
	print('RH ',ratings['RH'][i],s[5]/n[5])

print(dToD)
print(dToR)
print(allValues)
print(allValues[1]+allValues[2]+allValues[3])
print(allValues[5]+allValues[6]+allValues[7])
print(numpy.median(allV))
print(numpy.mean(allV))
