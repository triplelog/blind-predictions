import numpy
import time
import random
import csv
import math
import json
pollsters = {}
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
				error = pred1-pred2-(act1-act2) #need to flip this in 2004 for consistent d/r
				if year == 2004:
					error = pred2-pred1-(act2-act1)
				
			except:
				print(row)
				continue
			try:
				
				pollsters[pollster]["polls"].append([dtoe,year,state,sample,error])
			except:
				pollsters[pollster] = {"polls":[]}
				pollsters[pollster]["polls"].append([dtoe,year,state,sample,error])
			



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
		rep_sum_error = 0
		rep_n = 0
		x = []
		polls = pollsters[pollster]['polls']
		polls.sort(key=mySort)
		print(polls)
		for i in range(0,l):
			#et = 1000*pollsters[pollster]['polls'][i][4]
			#probB = nd.pdf(et)
			rep_sum_error += pollsters[pollster]['polls'][i][4]
			rep_n += 1
			x.append(pollsters[pollster]['polls'][i][4])
		pollsters[pollster]['elo']={'mean':rep_sum_error/rep_n,'stdev':numpy.std(x)}

for year in [2000,2004,2008,2012,2016]:
	donot = 0
			
