import numpy
import time
import random
import csv
import math
import json
pollsters = {}
actuals = {}
def readcsv(filen):
	allgamesa  ={}
	with open(filen, 'r') as csvfile:
		spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
		for row in spamreader:
			if row[0] == "poll_id":
				continue
			try:
				pollster = row[9]
				date = row[10]
				edate = row[20]
				year = int(row[3])
				state = row[5]
				pred1 = float(row[14])
				pred2 = float(row[17])
				sample = float(row[11])
				act1 = float(row[21])
				act2 = float(row[22])
				partisan = row[28]
				if partisan != "":
					continue
					
				month = date[0:2]
				days = int(date[3:-5])
				if month == "11":
					days += 31
				eday = int(edate[3:-5])
				dtoe = 31+eday-days
				error = (act1-act2)-(pred1-pred2) #need to flip this in 2004 for consistent d/r
				pred = pred1-pred2
				
			except:
				print(row)
				continue
			if dtoe > 30:
				continue
			try:
				
				pollsters[pollster]["polls"].append([dtoe,year,state,sample,error,pred])
			except:
				pollsters[pollster] = {"polls":[]}
				pollsters[pollster]["polls"].append([dtoe,year,state,sample,error,pred])
				
			try:
				actuals[state][year]=act1-act2
			except:
				actuals[state]={}
				actuals[state][year]=act1-act2



readcsv("data/pres-polls.csv")

rep_sum_error = 0
rep_n = 0
x = []

for pollster in pollsters.keys():
	l = len(pollsters[pollster]['polls'])
	if l < 5:
		for i in range(0,l):
			rep_sum_error += pollsters[pollster]['polls'][i][4]
			rep_n += 1
			x.append(pollsters[pollster]['polls'][i][4])
			#print(pollsters[pollster]['polls'][i][4])
print(rep_sum_error,rep_n,rep_sum_error/rep_n)
print(numpy.std(x))

def mySort(e):
  return e[1]*1000-e[0]

for pollster in pollsters.keys():
	l = len(pollsters[pollster]['polls'])
	if l >= 5:
		
		polls = pollsters[pollster]['polls']
		polls.sort(key=mySort)
		for year in [2004,2008,2012,2016]:
			rep_sum_error = 0
			rep_n = 0
			x = []
			for i in range(0,l):
				#et = 1000*pollsters[pollster]['polls'][i][4]
				#probB = nd.pdf(et)
				if pollsters[pollster]['polls'][i][1]>= year:
					break
				rep_sum_error += pollsters[pollster]['polls'][i][4]
				rep_n += 1
				x.append(pollsters[pollster]['polls'][i][4])
			if rep_n>4:
				pollsters[pollster][year]={'mean':rep_sum_error/rep_n,'stdev':numpy.std(x)}

for state in ["US","FL","OH","MI","WI","PA","GA"]:
	for year in [2016]:#2004,2008,2012,2016]:

		probsum = 0
		for pollster in pollsters.keys():
			try:
				pp = pollsters[pollster][year]
			except:
				continue
			l = len(pollsters[pollster]['polls'])
			for i in range(0,l):
				if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
					#print(pollster,pollsters[pollster]['polls'][i],pollsters[pollster][year])
					donot = 0
					
					
		for diff in range(-100,101):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]-pollsters[pollster][year]['mean'])
						sigma = pollsters[pollster][year]['stdev']
						p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),1.0/pollsters[pollster]['polls'][i][0])
			probsum += p
		halfsum = 0
		for diff in range(-100,101):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]-pollsters[pollster][year]['mean'])
						sigma = pollsters[pollster][year]['stdev']
						p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),1.0/pollsters[pollster]['polls'][i][0])
			halfsum += p
			if halfsum >= probsum/2:
				print(state,year, diff/10.0, actuals[state][year])
				break
			
