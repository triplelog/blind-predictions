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
        
        
shape = fiona.open("sc_2018/sc_2018.shp")

shape16 = fiona.open("sc_2016/sc_2016.shp")

print(len(shape))
print(len(shape16))

counties = [19,13,15,29,35]

precincts = {}

bounds = {'left':1000000000,'right':-1000000000,'bottom':1000000000,'top':-1000000000}
for i in range(0,len(shape)):

	if shape[i]['geometry']['type'] == "Polygon":
		coords = shape[i]['geometry']['coordinates'][0]
	else:
		maxPoly = 0
		for ii in range(0,len(shape[i]['geometry']['coordinates'])):
			l = len(shape[i]['geometry']['coordinates'][ii][0])
			if l>maxPoly:
				maxPoly = l
				coords = shape[i]['geometry']['coordinates'][ii][0]
	try:
		poly = Polygon(coords)
	except:
		#print(coords)
		print(shape[i]['geometry']['type'])
	cent = poly.centroid
	if int(shape[i]['properties']['COUNTYFP']) not in counties:
		continue
	if cent.x < bounds['left']:
		bounds['left'] = cent.x
	if cent.x > bounds['right']:
		bounds['right'] = cent.x
	if cent.y < bounds['bottom']:
		bounds['bottom'] = cent.y
	if cent.y > bounds['top']:
		bounds['top'] = cent.y
print(bounds)
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
	if int(shape16[i]['properties']['COUNTY']) not in counties:
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


for i in range(0,len(shape)):

	if shape[i]['geometry']['type'] == "Polygon":
		coords = shape[i]['geometry']['coordinates'][0]
	else:
		maxPoly = 0
		for ii in range(0,len(shape[i]['geometry']['coordinates'])):
			l = len(shape[i]['geometry']['coordinates'][ii][0])
			if l>maxPoly:
				maxPoly = l
				coords = shape[i]['geometry']['coordinates'][ii][0]
	try:
		poly = Polygon(coords)
	except:
		#print(coords)
		print(shape[i]['geometry']['type'])
	cent = poly.centroid
	if int(shape[i]['properties']['COUNTYFP']) not in counties:
		continue
	precincts[shape[i]['id']]={'x':(cent.x-bounds['left'])/(bounds['right']-bounds['left']),'y':(bounds['top']-cent.y)/(bounds['top']-bounds['bottom']),'name':shape[i]['properties']['NAME'],'d':shape[i]['properties']['G18GOVDSMI'],'r':shape[i]['properties']['G18GOVRMCM'],'county':shape[i]['properties']['COUNTYFP']}




precincts16 = {}

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
	
	if int(shape16[i]['properties']['COUNTY']) not in counties:
		continue
	precincts16[shape16[i]['id']]={'x':(cent.x-bounds16['left'])/(bounds16['right']-bounds16['left']),'y':(bounds16['top']-cent.y)/(bounds16['top']-bounds16['bottom']),'name':shape16[i]['properties']['PNAME'],'d16':shape16[i]['properties']['G16PREDCLI'],'r16':shape16[i]['properties']['G16PRERTRU'],'county':shape16[i]['properties']['COUNTY']}




file1 = open('scpre.txt', 'w')
file1.writelines(['std::map<int,Point> scPoints(){\n'])
file1.writelines(['std::map<int,Point> points; int i=0;\n'])

pixelMap = {}
for precinct in precincts:

	roundedX = round(precincts[precinct]['x']*100)
	roundedY = round(precincts[precinct]['y']*100)
	try:
		pixelMap[roundedX*1000+roundedY]['d']+=int(precincts[precinct]['d'])
		pixelMap[roundedX*1000+roundedY]['r']+=int(precincts[precinct]['r'])
	except:
		pixelMap[roundedX*1000+roundedY]={}
		pixelMap[roundedX*1000+roundedY]['d']=int(precincts[precinct]['d'])
		pixelMap[roundedX*1000+roundedY]['r']=int(precincts[precinct]['r'])
		pixelMap[roundedX*1000+roundedY]['x']=round(precincts[precinct]['x']*100)
		pixelMap[roundedX*1000+roundedY]['y']=round(precincts[precinct]['y']*100)
		pixelMap[roundedX*1000+roundedY]['county']=int(precincts[precinct]['county'])
		pixelMap[roundedX*1000+roundedY]['d16']=0
		pixelMap[roundedX*1000+roundedY]['r16']=0

		
missingP = 0
for precinct in precincts16:

	roundedX = round(precincts16[precinct]['x']*100)
	roundedY = round(precincts16[precinct]['y']*100)
	try:
		pixelMap[roundedX*1000+roundedY]['d16']+=int(precincts16[precinct]['d16'])
		pixelMap[roundedX*1000+roundedY]['r16']+=int(precincts16[precinct]['r16'])
	except:
		try:
			pixelMap[roundedX*1000+roundedY]['d16']=int(precincts16[precinct]['d16'])
			pixelMap[roundedX*1000+roundedY]['r16']=int(precincts16[precinct]['r16'])
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
				pixelMap[rXY]['x']=round(precincts[precinct]['x']*100)
				pixelMap[rXY]['y']=round(precincts[precinct]['y']*100)
				pixelMap[rXY]['county']=int(precincts[precinct]['county'])
			
			try:
				pixelMap[rXY]['d16']+=int(precincts16[precinct]['d16'])
				pixelMap[rXY]['r16']+=int(precincts16[precinct]['r16'])
			except:
				pixelMap[rXY]['d16']=int(precincts16[precinct]['d16'])
				pixelMap[rXY]['r16']=int(precincts16[precinct]['r16'])
					
print(missingP)
pixels = 0
for pixel in pixelMap.keys():
	pixels+=1
	file1.writelines(['if (1==1){ Point p;\n'])
	#line = str(precincts[precinct]['name'])+","+str(precincts[precinct]['x'])+","+str(precincts[precinct]['y'])+","+str(precincts[precinct]['d'])+","+str(precincts[precinct]['r'])+","+str(precincts[precinct]['county'])+"\n"
	line = "p.x = "+str(pixelMap[pixel]['x'])+"; p.y = "+str(pixelMap[pixel]['y'])+"; p.county = "+str(pixelMap[pixel]['county'])+"; p.val = "+str(pixelMap[pixel]['d']+pixelMap[pixel]['r'])+"; p.d = "+str(pixelMap[pixel]['d'])+"; p.r = "+str(pixelMap[pixel]['r'])+"; p.d16 = "+str(pixelMap[pixel]['d16'])+"; p.r16 = "+str(pixelMap[pixel]['r16'])+";\n"
	
	file1.writelines([line])
	file1.writelines(['points[i]=p;i++;}\n'])
print(pixels)
file1.writelines(['np = '+str(pixels)+';\nreturn points;}\n'])
file1.close()
