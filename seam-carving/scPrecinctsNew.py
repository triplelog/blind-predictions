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
from shapely.geometry import Point
from functools import partial

def readcsv(filen):
        allgamesa  =[]
        with open(filen, 'r', encoding='mac_roman') as csvfile:
                spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
                for row in spamreader:
                        allgamesa.append(row)
        return allgamesa
		
def readblockgroup(filen,state):
		allgamesa  ={}
		with open(filen, 'r', encoding='mac_roman') as csvfile:
			spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
			for row in spamreader:
				if row[2][7:9] == state:
					try:
						allgamesa[row[2][7:]][row[1]]=row[6]
					except:
						allgamesa[row[2][7:]]={}
						allgamesa[row[2][7:]][row[1]]=row[6]
		return allgamesa	   
		
        



counties = [19,13,15,29,35]
counties = []
for i in range(0,100):
	counties.append(i)
maindatas = {"val":'Total',"black":'Black or African American Alone',"white":'White Alone'}

extradatas = {"sc_2018/sc_2018.shp":{"r":'G18GOVDSMI',"d":'G18GOVRMCM'},"sc_2016/sc_2016.shp":{"d16":'G16PREDCLI',"r16":'G16PRERTRU'}}

bgdata = readblockgroup("demographics/CVAP_2013-2017_ACS_csv_files/BlockGr.csv","45")




pixelMap = {}

def addMain(extrafile):
	shape16 = fiona.open(extrafile)
	print(len(shape16))
	precincts16 = {}
	bounds16 = {'left':1000000000,'right':-1000000000,'bottom':1000000000,'top':-1000000000}
	for i in range(0,len(shape16)):

		if shape16[i]['geometry']['type'] == "Polygon":
			coords = shape16[i]['geometry']['coordinates'][0]
		else:
			maxPoly = 0
			for ii in range(0,len(shape16[i]['geometry']['coordinates'])):
				l = len(shape16[i]['geometry']['coordinates'][ii][0])
				if l>maxPoly:
					maxPoly = l
					coords = shape16[i]['geometry']['coordinates'][ii][0]
		try:
			poly = Polygon(coords)
		except:
			#print(coords)
			print(shape16[i]['geometry']['type'])
		cent = poly.centroid


		if int(shape16[i]['properties']['COUNTYFP']) not in counties:
			continue
		if cent.x < bounds16['left']:
			bounds16['left'] = cent.x
		if cent.x > bounds16['right']:
			bounds16['right'] = cent.x
		if cent.y < bounds16['bottom']:
			bounds16['bottom'] = cent.y
		if cent.y > bounds16['top']:
			bounds16['top'] = cent.y
	print(bounds16)



	for i in range(0,len(shape16)):

		if shape16[i]['geometry']['type'] == "Polygon":
			coords = shape16[i]['geometry']['coordinates'][0]
		else:
			maxPoly = 0
			for ii in range(0,len(shape16[i]['geometry']['coordinates'])):
				l = len(shape16[i]['geometry']['coordinates'][ii][0])
				if l>maxPoly:
					maxPoly = l
					coords = shape16[i]['geometry']['coordinates'][ii][0]
		try:
			poly = Polygon(coords)
		except:
			#print(coords)
			print(shape16[i]['geometry']['type'])
		cent = poly.centroid
		

		if int(shape16[i]['properties']['COUNTYFP']) not in counties:
			continue
		precincts16[shape16[i]['id']]={'x':(cent.x-bounds16['left'])/(bounds16['right']-bounds16['left']),'y':(bounds16['top']-cent.y)/(bounds16['top']-bounds16['bottom'])}
		for ii in maindatas.keys():
			precincts16[shape16[i]['id']][ii]=bgdata[shape16[i]['properties']['GEOID']][maindatas[ii]]
			

		
	missingP = 0
	for precinct in precincts16:

		roundedX = round(precincts16[precinct]['x']*100)
		roundedY = round(precincts16[precinct]['y']*100)
		try:
			for ii in maindatas.keys():
				pixelMap[roundedX*1000+roundedY][ii]+=int(precincts16[precinct][ii])
		except:
			pixelMap[roundedX*1000+roundedY]={}
			for ii in maindatas.keys():
				pixelMap[roundedX*1000+roundedY][ii]=int(precincts16[precinct][ii])
			pixelMap[roundedX*1000+roundedY]['x']=round(precincts16[precinct]['x']*100)
			pixelMap[roundedX*1000+roundedY]['y']=round(precincts16[precinct]['y']*100)
			pixelMap[roundedX*1000+roundedY]['county']=0
			for i in extradatas.keys():
				for ii in extradatas[i].keys():
					pixelMap[roundedX*1000+roundedY][ii]=0
					
addMain("demographics/tl_2019_45_bg/tl_2019_45_bg.shp")



def addExtra(extrafile,idx):
	shape16 = fiona.open(extrafile)
	print(len(shape16))
	precincts16 = {}
	bounds16 = {'left':1000000000,'right':-1000000000,'bottom':1000000000,'top':-1000000000}
	for i in range(0,len(shape16)):

		if shape16[i]['geometry']['type'] == "Polygon":
			coords = shape16[i]['geometry']['coordinates'][0]
		else:
			maxPoly = 0
			for ii in range(0,len(shape16[i]['geometry']['coordinates'])):
				l = len(shape16[i]['geometry']['coordinates'][ii][0])
				if l>maxPoly:
					maxPoly = l
					coords = shape16[i]['geometry']['coordinates'][ii][0]
		try:
			poly = Polygon(coords)
		except:
			#print(coords)
			print(shape16[i]['geometry']['type'])
		cent = poly.centroid

		if idx == 0 and int(shape16[i]['properties']['COUNTYFP']) not in counties:
			continue
		if idx == 1 and int(shape16[i]['properties']['COUNTY']) not in counties:
			continue
		if cent.x < bounds16['left']:
			bounds16['left'] = cent.x
		if cent.x > bounds16['right']:
			bounds16['right'] = cent.x
		if cent.y < bounds16['bottom']:
			bounds16['bottom'] = cent.y
		if cent.y > bounds16['top']:
			bounds16['top'] = cent.y
	print(bounds16)



	for i in range(0,len(shape16)):
		
		if shape16[i]['geometry']['type'] == "Polygon":
			coords = shape16[i]['geometry']['coordinates'][0]
		else:
			maxPoly = 0
			for ii in range(0,len(shape16[i]['geometry']['coordinates'])):
				l = len(shape16[i]['geometry']['coordinates'][ii][0])
				if l>maxPoly:
					maxPoly = l
					coords = shape16[i]['geometry']['coordinates'][ii][0]
		try:
			poly = Polygon(coords)
		except:
			#print(coords)
			print(shape16[i]['geometry']['type'])
		cent = poly.centroid
		
		if idx == 0 and int(shape16[i]['properties']['COUNTYFP']) not in counties:
			continue
		if idx == 1 and int(shape16[i]['properties']['COUNTY']) not in counties:
			continue
		precincts16[shape16[i]['id']]={'x':(cent.x-bounds16['left'])/(bounds16['right']-bounds16['left']),'y':(bounds16['top']-cent.y)/(bounds16['top']-bounds16['bottom'])}
		if i%3 > 0 and idx == 1:
			precincts16[shape16[i]['id']]['county']=1
		else:
			precincts16[shape16[i]['id']]['county']=0
		for ii in extradatas[extrafile].keys():
			precincts16[shape16[i]['id']][ii]=shape16[i]['properties'][extradatas[extrafile][ii]]
			

		
	missingP = 0
	for precinct in precincts16:

		roundedX = round(precincts16[precinct]['x']*100)
		roundedY = round(precincts16[precinct]['y']*100)
		try:
			for i in extradatas[extrafile].keys():
				pixelMap[roundedX*1000+roundedY][i]+=int(precincts16[precinct][i])
			if pixelMap[roundedX*1000+roundedY]['county']<precincts16[precinct]['county']:
				pixelMap[roundedX*1000+roundedY]['county']=precincts16[precinct]['county']
		except:
			try:
				for i in extradatas[extrafile].keys():
					pixelMap[roundedX*1000+roundedY][i]=int(precincts16[precinct][i])
				if pixelMap[roundedX*1000+roundedY]['county']<precincts16[precinct]['county']:
					pixelMap[roundedX*1000+roundedY]['county']=precincts16[precinct]['county']
			except:
			
				rXY = -1
				minD = 100000
				for i in range(-2,3):
					if roundedX+i<0 or roundedX+i>100:
						continue
					for ii in range(-2,3):
						if roundedY+i<0 or roundedY+ii>100:
							continue
						try:
							p = pixelMap[(roundedX+i)*1000+roundedY+ii]
						except:
							continue
						if i*i+ii*ii < minD:
							minD = i*i+ii*ii
							rXY = (roundedX+i)*1000+roundedY+ii
				if rXY <0:
					missingP+=1
					rXY = roundedX*1000+roundedY
					pixelMap[rXY]={}
					pixelMap[rXY]['d']=0
					pixelMap[rXY]['r']=0
					pixelMap[rXY]['x']=round(precincts16[precinct]['x']*100)
					pixelMap[rXY]['y']=round(precincts16[precinct]['y']*100)
					for ii in maindatas.keys():
						pixelMap[rXY][ii]=0
					for i in extradatas.keys():
						for ii in extradatas[i].keys():
							pixelMap[rXY][ii]=0
					pixelMap[rXY]['county']=precincts16[precinct]['county']
			
				try:
					for i in extradatas[extrafile].keys():
						pixelMap[rXY][i]+=int(precincts16[precinct][i])
					if pixelMap[rXY]['county']<precincts16[precinct]['county']:
						pixelMap[rXY]['county']=precincts16[precinct]['county']
				except:
					for i in extradatas[extrafile].keys():
						pixelMap[rXY][i]=int(precincts16[precinct][i])
					if pixelMap[rXY]['county']<precincts16[precinct]['county']:
						pixelMap[rXY]['county']=precincts16[precinct]['county']
					
	print(missingP)

ii = 0
for i in extradatas.keys():
	addExtra(i,ii)
	ii+=1



file1 = open('scpre.txt', 'w')
file1.writelines(['void scPoints0(){\n'])
file1.writelines(['points.clear();\n'])
pixels = 0
for pixel in pixelMap.keys():
	
	file1.writelines(['if (1==1){ Point p;\n'])
	#line = str(precincts[precinct]['name'])+","+str(precincts[precinct]['x'])+","+str(precincts[precinct]['y'])+","+str(precincts[precinct]['d'])+","+str(precincts[precinct]['r'])+","+str(precincts[precinct]['county'])+"\n"
	line = "p.x = "+str(pixelMap[pixel]['x'])+"; p.y = "+str(pixelMap[pixel]['y'])+"; p.county = "+str(pixelMap[pixel]['county'])+"; p.val = "+str(pixelMap[pixel]['val'])
	for ii in maindatas.keys():
		if ii == "val":
			continue
		line +="; p.data[\""+ii+"\"] = "+str(pixelMap[pixel][ii])
	for i in extradatas.keys():
		for ii in extradatas[i].keys():
			line +="; p.data[\""+ii+"\"] = "+str(pixelMap[pixel][ii])
	line +=";\n"
	
	file1.writelines([line])
	file1.writelines(['points['+str(pixels)+']=p;}\n'])
	pixels+=1
	if pixels == 1000:
		file1.writelines(['\n}\n'])
		file1.writelines(['void scPoints1(){\n'])
		file1.writelines(['\n'])
print(pixels)
file1.writelines(['np = '+str(pixels)+';\n}\n'])
file1.close()
