import fiona
import time
import sys
import random
import csv
import math
import json
import pyproj
import shapely
import shapely.ops as ops
from shapely.geometry.polygon import Polygon
from functools import partial

def readcsv(filen):
        allgamesa  =[]
        with open(filen, 'r', encoding='mac_roman') as csvfile:
                spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
                for row in spamreader:
                        allgamesa.append(row)
        return allgamesa

def computeArea(pgon,ptype):
	area = 0
	if ptype=='MultiPolygon':
		for i in range(0,len(pgon)):
			for ii in range(0,len(pgon[i])):
				geom = Polygon(pgon[i][ii])
				geom_area = ops.transform(
					partial(
						pyproj.transform,
						pyproj.Proj(init='EPSG:4326'),
						pyproj.Proj(
							proj='aea',
							lat1=geom.bounds[1],
							lat2=geom.bounds[3])),
					geom)

				area += geom_area.area  
	else:
		for i in range(0,len(pgon)):
			geom = Polygon(pgon[i])
			geom_area = ops.transform(
				partial(
					pyproj.transform,
					pyproj.Proj(init='EPSG:4326'),
					pyproj.Proj(
						proj='aea',
						lat1=geom.bounds[1],
						lat2=geom.bounds[3])),
				geom)

			area += geom_area.area 
		
	return area,geom_area.centroid   

stateCodes = readcsv('statecodes.csv')
stateAbbrevs = {}
for i in stateCodes:
	stateRaw3 = '0'+str(i[1])
	stateId = stateRaw3[-2:]
	stateName = i[0]
	stateA = i[2]
	#print('<option value="'+stateId+'">'+stateName)
	stateAbbrevs[stateId]=stateA
	

#print(soto)
def topartisan(pdens,pW,pT):
	return pdens

popFile = readcsv('popData/ACS_17_5YR_B01001_with_ann.csv')[2:]

whiteFile = readcsv('popData/ACS_17_5YR_B01001H_with_ann.csv')[2:]
blackFile = readcsv('popData/ACS_17_5YR_B01001B_with_ann.csv')[2:]
latinoFile = readcsv('popData/ACS_17_5YR_B01001I_with_ann.csv')[2:]
asianFile = readcsv('popData/ACS_17_5YR_B01001D_with_ann.csv')[2:]

#eduFile = readcsv(thestate+'/ACS_17_5YR_B15003_with_ann.csv')[2:]
#ageFile = readcsv(thestate+'/ACS_17_5YR_B01001_with_ann.csv')[2:]


popTotals = {}
for i in popFile:
	geoid = str(i[1])
	population = int(i[3])
	popTotals[geoid]=[population,0,0,0,0,0]
for i in popFile:
	geoid = str(i[1])
	population = 0
	for ii in range(15,24):
		if ii%2==1:
			population+=int(i[ii])
	for ii in range(63,72):
		if ii%2==1:
			population+=int(i[ii])
	popTotals[geoid][1]=population
for i in popFile:
	geoid = str(i[1])
	population = 0
	for ii in range(25,28):
		if ii%2==1:
			population+=int(i[ii])
	for ii in range(73,76):
		if ii%2==1:
			population+=int(i[ii])
	popTotals[geoid][2]=population
for i in popFile:
	geoid = str(i[1])
	population = 0
	for ii in range(29,32):
		if ii%2==1:
			population+=int(i[ii])
	for ii in range(77,80):
		if ii%2==1:
			population+=int(i[ii])
	popTotals[geoid][3]=population
for i in popFile:
	geoid = str(i[1])
	population = 0
	for ii in range(33,36):
		if ii%2==1:
			population+=int(i[ii])
	for ii in range(81,84):
		if ii%2==1:
			population+=int(i[ii])
	popTotals[geoid][4]=population
for i in popFile:
	geoid = str(i[1])
	population = 0
	for ii in range(37,52):
		if ii%2==1:
			population+=int(i[ii])
	for ii in range(85,100):
		if ii%2==1:
			population+=int(i[ii])
	popTotals[geoid][5]=population

#for i in eduFile:
#	geoid = str(i[1])
#	college = int(i[47])+int(i[49])+int(i[51])
#	popTotals[geoid][2]=college
#for i in ageFile:
#	geoid = str(i[1])
#	oldage = int(i[37])
#	for ii in range(39,52):
#		if ii%2==1:
#			oldage+=int(i[ii])
#	popTotals[geoid][2]=oldage
def getcd(fileData):
	tractToCD = {}
	for i in fileData:
		countyRaw3 = '00'+str(i[2])
		countyId = countyRaw3[-3:]
		tractRaw3 = '00000'+str(i[1])
		dotIndex = i[1].find('.')
		if dotIndex > -1:
			tractId = tractRaw3[-9:-3]
		else:
			tractId = tractRaw3[-6:]
		geoid = countyId+tractId
		if geoid not in tractToCD.keys():
			tractToCD[geoid]=[i[3]]
		else:
			tractToCD[geoid].append(i[3])
	return tractToCD
def densities(stateId):
	oneCD = False
	try:
		cdFile = readcsv('cds/state_'+stateId+'_2018.csv')[2:]
	except:
		oneCD = True
	try:
		if int(cdFile[0][0]) != int(stateId):
			oneCD = True
	except:
		oneCD = True
	if not oneCD:
		cdData = getcd(cdFile)
	else:
		cdData = 0

	shape = fiona.open("tracts/tl_2018_"+stateId+"_tract/tl_2018_"+stateId+"_tract.shp")

	blockShapes = fiona.open("tracts/tl_2018_"+stateId+"_tract/tl_2018_"+stateId+"_tract.shp")

	blockGrps = {}
	cds = {}

	breakDensities = [.000026,.000091,.000255,.00051,.00082,.00121,.00171,.0025,.0043]
	i = 0
	
	for i in range(0,len(shape)):
		try:
			shprop = shape[i]
		except:
			continue
		try:
			blkgrpid = str(shprop['properties']['GEOID'])
			polydata = computeArea(shprop['geometry']['coordinates'],shprop['geometry']['type'])
			
			if not oneCD:
				cdIds = cdData[blkgrpid[2:11]]
			else:
				cdIds = ['0']

			for cdId in cdIds:
				if cdId not in cds.keys():
					cds[cdId]=[0,0,0,0,[[1,0],[2,0],[3,0],[4,0],[5,0],[6,0],[7,0],[8,0],[9,0],[10,0]]]
					for ii in range(0,10):
						cds[cdId][4][ii].append(0)
						cds[cdId][4][ii].append(0)
						cds[cdId][4][ii].append(0)
						cds[cdId][4][ii].append(0)
			
				cds[cdId][0] += popTotals[blkgrpid][0]/len(cdIds)*topartisan(popTotals[blkgrpid][0]/polydata[0],popTotals[blkgrpid][1],popTotals[blkgrpid][0])
				cds[cdId][1] += popTotals[blkgrpid][0]/len(cdIds)
				cds[cdId][2] += polydata[0]/len(cdIds)
				cds[cdId][3] += popTotals[blkgrpid][1]/len(cdIds)
				for ii in range(0,9):
					if popTotals[blkgrpid][0]/polydata[0]<breakDensities[ii]:
						cds[cdId][4][ii][1]+=popTotals[blkgrpid][1]/len(cdIds)
						cds[cdId][4][ii][2]+=popTotals[blkgrpid][2]/len(cdIds)
						cds[cdId][4][ii][3]+=popTotals[blkgrpid][3]/len(cdIds)
						cds[cdId][4][ii][4]+=popTotals[blkgrpid][4]/len(cdIds)
						cds[cdId][4][ii][5]+=popTotals[blkgrpid][5]/len(cdIds)
						break
					if ii == 8:
						cds[cdId][4][9][1]+=popTotals[blkgrpid][1]/len(cdIds)
						cds[cdId][4][9][2]+=popTotals[blkgrpid][2]/len(cdIds)
						cds[cdId][4][9][3]+=popTotals[blkgrpid][3]/len(cdIds)
						cds[cdId][4][9][4]+=popTotals[blkgrpid][4]/len(cdIds)
						cds[cdId][4][9][5]+=popTotals[blkgrpid][5]/len(cdIds)
					
			blockGrps[blkgrpid] = [popTotals[blkgrpid][0],polydata[0],polydata[1],0,0]
		except:
			pass
	return cds


allData = {}
for stateRaw in range(1,57):
	
	if stateRaw not in [3,7,14,43,52]:
		stateRaw3 = '0'+str(stateRaw)
		stateId = stateRaw3[-2:]
		try:
			cds = densities(stateId)
		except:
			print('error',stateId)
		print(stateRaw)
		allData[stateId]={}
		resultFile = readcsv('electionResults/2008-2016-house-pres.csv')[1:]
		cdResults = {}
		for i in resultFile:
			if i[0][:2]==stateAbbrevs[stateId]:
				if i[0][3:]!='AL':
					cdResults[i[0][3:]]=[float(i[8])*100.0/(float(i[8])+float(i[9])),float(i[6])*100.0/(float(i[6])+float(i[7])),float(i[4])*100.0/(float(i[4])+float(i[5]))]
				else:
					cdResults['0']=[float(i[8])*100.0/(float(i[8])+float(i[9])),float(i[6])*100.0/(float(i[6])+float(i[7])),float(i[4])*100.0/(float(i[4])+float(i[5]))]
		if stateAbbrevs[stateId]=='DC':
			cdResults['0']=[.7,.75,.8]
		for cd in cds.keys():
			if cds[cd][2]>0 and cds[cd][1]>0:
				allData[stateId][cd]={'result':cdResults[cd],'density':cds[cd][1]/cds[cd][2],'data':[['Density','18-29','30-39','40-49','50-59','60+']]+cds[cd][4]}

with open('cdData.json', 'w') as outfile:
    json.dump(allData, outfile)
#for county in counties.keys():
#	if county == '491':
#		print(counties[county][4])
	#print(county,10000000*counties[county][0]/counties[county][1],10000000*counties[county][3]/counties[county][1])
#print(countryDensities)



	
