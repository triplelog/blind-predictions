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
for i in range(0,len(vars)):
	print(i, vars[i])

usedvars = [117,119,120,121]


for i in usedvars:
	print(i, vars[i], allCCES[10][i], allCCES[100][i])

ratings = {'T':{},'D':{},'R':{}}
for i in range(1,8):
	ratings['T'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['D'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
	ratings['R'][i]={1:0,2:0,3:0,4:0,5:0,6:0,7:0}


for i in range(0,len(allCCES)):
	try:
		me = int(allCCES[i][117])
		T = int(allCCES[i][119])
		D = int(allCCES[i][120])
		R = int(allCCES[i][121])
		if me > 7 or T > 7 or D > 7 or R > 7:
			continue
	except:
		continue
	ratings['T'][me][T]+=1
	ratings['D'][me][D]+=1
	ratings['R'][me][R]+=1

for i in range(1,8):
	print(i)
	print('T ',ratings['T'][i])
	print('D ',ratings['D'][i])
	print('R ',ratings['R'][i])


