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
				
				pollsters[pollster]["polls"].append([math.log(dtoe+1),year,state,sample,error,pred])
			except:
				pollsters[pollster] = {"polls":[]}
				pollsters[pollster]["polls"].append([math.log(dtoe+1),year,state,sample,error,pred])
				
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

rep_sum_error = 0
rep_n = 0
xm = []
xs = []
for pollster in pollsters.keys():
	l = len(pollsters[pollster]['polls'])
	if l >= 25:
		
		polls = pollsters[pollster]['polls']
		polls.sort(key=mySort)
		
		x = []
		for i in range(0,l):
			x.append(pollsters[pollster]['polls'][i][4])

		xm.append(numpy.mean(x))
		xs.append(numpy.std(x))

print(xm)
print(xs)			
for pollster in pollsters.keys():
	l = len(pollsters[pollster]['polls'])
	if l >= 5:
		
		polls = pollsters[pollster]['polls']
		polls.sort(key=mySort)
		for year in [2004,2008,2012,2016,2020]:
		
			x = []

			for i in range(0,l):
				#et = 1000*pollsters[pollster]['polls'][i][4]
				#probB = nd.pdf(et)
				if pollsters[pollster]['polls'][i][1]>= year:
					break
					
				x.append(pollsters[pollster]['polls'][i][4])
				if pollsters[pollster]['polls'][i][1] == year-4:
					x.append(pollsters[pollster]['polls'][i][4])
			pollsters[pollster][year]={'mean':(0.0+sum(x))/(10.0+len(x)),'stdev':(60.0+len(x)*numpy.std(x))/(10.0+len(x)),'weight':1.0}
			if len(x)>9:
				pollsters[pollster][year]['weight']=1.0
			if len(x)>4:
				pollsters[pollster][year]['weight']=.5

#for state in ["US","FL","OH","MI","WI","PA","GA"]:
sse = 0
brier = 0
bn = 0
brieru = 0

for state in ['FL','NC','NV','OH','AZ','IA','NH','PA','GA','CO','MI','WI','VA','NM','MN']:
	for year in [2004,2008,2012,2016]:

		probsum = 0
		
		for pollster in pollsters.keys():
			try:
				pp = pollsters[pollster][year]
			except:
				continue
			l = len(pollsters[pollster]['polls'])
			for i in range(0,l):
				if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
					if state == "CO" and year ==2016:
						print(pollster,pollsters[pollster]['polls'][i],pollsters[pollster][year])
					donot = 0
					
					
		for diff in range(-500,501):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]+pollsters[pollster][year]['mean'])
						sigma = pollsters[pollster][year]['stdev']
						p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),pollsters[pollster][year]['weight']/pollsters[pollster]['polls'][i][0])
			probsum += p
		halfsum = 0
		for diff in range(-500,501):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]+pollsters[pollster][year]['mean'])
						sigma = pollsters[pollster][year]['stdev']
						p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),pollsters[pollster][year]['weight']/pollsters[pollster]['polls'][i][0])
			halfsum += p
			if halfsum >= probsum/2:
				print(state,year, diff/10.0, actuals[state][year])
				if year == 2016:
					sse += (diff/10.0 - actuals[state][year])**2
					#print(sse)
				break
		dprob = 0
		halfsum = 0
		for diff in range(-500,0):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]+pollsters[pollster][year]['mean'])
						sigma = pollsters[pollster][year]['stdev']
						p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),pollsters[pollster][year]['weight']/pollsters[pollster]['polls'][i][0])
			halfsum += p
		rprob = halfsum/probsum
		#print(state,year, rprob, actuals[state][year])
		if year == 2016:
			if actuals[state][year] < 0:
				brier += (rprob-1)**2
				
			else:
				brier += (rprob-0)**2
			brieru += .5**2
			bn += 1
print(sse,(brieru/bn-brier/bn)/(brieru/bn))
			
