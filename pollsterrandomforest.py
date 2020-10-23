import numpy
import time
import random
import csv
import math
import json
import sklearn
from sklearn.ensemble import RandomForestClassifier
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
				act1 = float(row[21]) #d percentage?
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
				error = (act1-act2)-(pred1-pred2) #need to flip this in 2004 for consistent d/r?
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

poppollsters = []
for pollster in pollsters.keys():
	l = 0
	for poll in pollsters[pollster]['polls']:
		if poll[1]==2012 and poll[2] !="US":
			l+=1
	if l>4:
		poppollsters.append(pollster)

print(poppollsters)


states2012 = []
polls2012 = []
for state in actuals.keys():
	try:
		x = actuals[state][2016]
		x = actuals[state][2012]
		x = actuals[state][2008]
	except:
		continue
	rperc = round(100.0-(actuals[state][2012]/2+50))
	#for i in range(0,rperc):
	#	states2012.append(1)
	#for i in range(rperc,100):
	#	states2012.append(0)
	states2012.append(rperc)
	polls = {}
	pollArray = [actuals[state][2008]]
	for pollster in poppollsters:
		for poll in pollsters[pollster]['polls']:
			if poll[1]==2012 and poll[2]==state:
				try:
					if polls[pollster][0]>=poll[0]:
						continue
				except:
					pass
				polls[pollster]=[poll[0],poll[5]]
		
		try:
			x = polls[pollster]
			pollArray.append(polls[pollster][1])
		except:
			pollArray.append(actuals[state][2008])
	#for i in range(0,100):
	polls2012.append(pollArray)

			
clf = RandomForestClassifier(n_estimators=1000)
clf = clf.fit(polls2012,states2012)
	

states2016 = []
polls2016 = []
for state in actuals.keys():
	try:
		x = actuals[state][2016]
		x = actuals[state][2012]
		x = actuals[state][2008]
	except:
		continue
	rperc = round(100.0-(actuals[state][2016]/2+50))

	states2016.append(rperc)
	
	polls = {}
	pollArray = [actuals[state][2012]]
	for pollster in poppollsters:
		for poll in pollsters[pollster]['polls']:
			if poll[1]==2016 and poll[2]==state:
				try:
					if polls[pollster][0]>=poll[0]:
						continue
				except:
					pass
				polls[pollster]=[poll[0],poll[5]]
		
		try:
			x = polls[pollster]
			pollArray.append(polls[pollster][1])
		except:
			pollArray.append(actuals[state][2012])

	polls2016.append(pollArray)
	print(state)

predictions = clf.predict(polls2016)

print(predictions)
print(states2016)
print(states2012)
print(abs(predictions-states2016))
print(numpy.mean(abs(predictions-states2016)))
s = 0
n = 0
for i in range(0,len(states2012)):
	s += abs(states2012[i]-states2016[i])
	n += 1

print(s*1.0/n)
print(soto)










rep_sum_error = 0
rep_n = 0
x = []
bydtoe = {}
for pollster in pollsters.keys():
	l = len(pollsters[pollster]['polls'])
	if l < 5:
		for i in range(0,l):
			rep_sum_error += pollsters[pollster]['polls'][i][4]
			rep_n += 1
			x.append(pollsters[pollster]['polls'][i][4])
			#print(pollsters[pollster]['polls'][i][4])
	else:
		for i in range(0,l):
			try:
				bydtoe[pollsters[pollster]['polls'][i][0]]['sse']+=pollsters[pollster]['polls'][i][4]*pollsters[pollster]['polls'][i][4]
			except:
				bydtoe[pollsters[pollster]['polls'][i][0]]={'sse':0,'n':0}
			bydtoe[pollsters[pollster]['polls'][i][0]]['n']+=1
print(rep_sum_error,rep_n,rep_sum_error/rep_n)
print(numpy.std(x))
#for i in range(0,30):
#	if i in bydtoe.keys():
#		print(i,", ",bydtoe[i]['sse']/bydtoe[i]['n'])

def mySort(e):
  return e[1]*1000-e[0]

rep_sum_error = 0
rep_n = 0
xm = []
xs = []
for pollster in pollsters.keys():
	l = len(pollsters[pollster]['polls'])
	if l >= 20:
		
		polls = pollsters[pollster]['polls']
		polls.sort(key=mySort)
		
		x = []
		for i in range(0,l):
			x.append(pollsters[pollster]['polls'][i][4])

		xm.append(numpy.mean(x))
		xs.append(numpy.std(x))

print(numpy.mean(xm),numpy.std(xm))
print(numpy.mean(xs),numpy.std(xs))			
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
				denomerror = 1.0 + (1.5-1.0)*pollsters[pollster]['polls'][i][0]/21
				x.append(pollsters[pollster]['polls'][i][4]/denomerror)
				if pollsters[pollster]['polls'][i][1] == year-4:
					x.append(pollsters[pollster]['polls'][i][4]/denomerror)
					
			if len(x)>0:
				pollsters[pollster][year]={'mean':(0.0+sum(x))/(10.0+len(x)),'stdev':(100.0+len(x)*numpy.std(x))/(10.0+len(x)),'weight':len(x)/10.0}
			if len(x)>9:
				pollsters[pollster][year]['weight']=1.0
			else:
				continue
				
			pairs = {}
			for ii in range(4,37):
				sigma = ii*1.0/2
				pairs[ii]={}
				for iii in range(-20,21):
					mu = iii*.5
					p = 1
					for i in range(0,l):
						if pollsters[pollster]['polls'][i][1]>= year:
							break
						adjpred = pollsters[pollster]['polls'][i][4] - mu
						pb = 35/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0)
						p *= pb
					pairs[ii][iii]=p*1.0/2.50663/10.0*math.pow(2.7183,-.5*((sigma-20.0)/10.0)**2.0)*1.0/2.50663/1.0*math.pow(2.7183,-.5*((mu-0)/1.0)**2.0)
			probsum = 0
			for iiii in range(-500,501):
				p = 0
				for ii in range(4,37):
					sigma = ii*1.0/2
					for iii in range(-20,21):
						mu = iii*.5
						adjpred = iiii*.1 - mu
						pp = pairs[ii][iii]*35/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0)
						p += pp
				probsum += p
			halfsum = 0
			print(pollster,probsum)
			pollsters[pollster][year]['preds']={}
			for iiii in range(-500,501):
				p = 0
				for ii in range(4,37):
					sigma = ii*1.0/2
					for iii in range(-20,21):
						mu = iii*.5
						adjpred = iiii*.1 - mu
						p += pairs[ii][iii]*35/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0)
				pollsters[pollster][year]['preds'][iiii]=p/probsum

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
					#if state == "NC" and year ==2016:
						#print(pollster,pollsters[pollster]['polls'][i],pollsters[pollster][year])
					donot = 0
					
					
		for diff in range(-400,401):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]['preds']
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						#adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]+pollsters[pollster][year]['mean'])
						#sigma = pollsters[pollster][year]['stdev']
						#p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),pollsters[pollster][year]['weight']/pollsters[pollster]['polls'][i][0])
						ddiff = round(diff-pollsters[pollster]['polls'][i][5]*10.0)
						if ddiff < -500:
							ddiff = -500
						if ddiff > 500:
							ddiff = 500
						p *= math.pow(pollsters[pollster][year]['preds'][ddiff],1.0/pollsters[pollster]['polls'][i][0])
			probsum += p
		halfsum = 0
		for diff in range(-400,401):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]['preds']
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						#adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]+pollsters[pollster][year]['mean'])
						#sigma = pollsters[pollster][year]['stdev']
						#p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),pollsters[pollster][year]['weight']/pollsters[pollster]['polls'][i][0])
						ddiff = round(diff-pollsters[pollster]['polls'][i][5]*10.0)
						if ddiff < -500:
							ddiff = -500
						if ddiff > 500:
							ddiff = 500
						p *= math.pow(pollsters[pollster][year]['preds'][ddiff],1.0/pollsters[pollster]['polls'][i][0])
			halfsum += p
			if halfsum >= probsum/2:
				print(state,year, diff/10.0, actuals[state][year])
				if year == 2016:
					sse += (diff/10.0 - actuals[state][year])**2
					#print(sse)
				break
		dprob = 0
		halfsum = 0
		for diff in range(-400,0):
			p = 1
			for pollster in pollsters.keys():
				try:
					pp = pollsters[pollster][year]['preds']
				except:
					continue
				l = len(pollsters[pollster]['polls'])
				for i in range(0,l):
					if pollsters[pollster]['polls'][i][1]== year and pollsters[pollster]['polls'][i][2] == state:
						#adjpred = diff/10.0-(pollsters[pollster]['polls'][i][5]+pollsters[pollster][year]['mean'])
						#sigma = pollsters[pollster][year]['stdev']
						#p *= math.pow(1/2.50663/sigma*math.pow(2.7183,-.5*((adjpred)/sigma)**2.0),pollsters[pollster][year]['weight']/pollsters[pollster]['polls'][i][0])
						ddiff = round(diff-pollsters[pollster]['polls'][i][5]*10.0)
						if ddiff < -500:
							ddiff = -500
						if ddiff > 500:
							ddiff = 500
						p *= math.pow(pollsters[pollster][year]['preds'][ddiff],1.0/pollsters[pollster]['polls'][i][0])
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
			
