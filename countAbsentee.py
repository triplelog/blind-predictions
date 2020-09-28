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
        with open(filen, 'r', encoding="iso-8859-1") as csvfile:
                spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
                for row in spamreader:
                        allgamesa.append(row)
        return allgamesa
        
allAbs = readcsv("data/absentee_20201103.csv")
count = 0
demcount = 0
gcount = 0
counties = {}
dates = {}
for i in range(1,len(allAbs)):
	if allAbs[i][39] == "ACCEPTED":
		count+=1
		if allAbs[i][0] == "GUILFORD":
			gcount+=1
		if allAbs[i][35] == "DEM":
			demcount+=1
			if allAbs[i][38] not in dates.keys():	
				dates[allAbs[i][38]] = [0,0,0]
			dates[allAbs[i][38]][0]+=1
			if allAbs[i][0] == "GUILFORD":
				dates[allAbs[i][38]][1]+=1
			dates[allAbs[i][38]][2]=dates[allAbs[i][38]][1]/dates[allAbs[i][38]][0]

print(count,demcount, gcount)
for i in range(15,28):
	date = "09/"+str(i)+"/2020"
	print(date, dates[date])

	