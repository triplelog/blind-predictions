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

print(len(shape))

precincts = {}
bounds = {'left':10000,'right':-10000,'bottom':10000,'top':-10000}
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
	if cent.x < bounds['left']:
		bounds['left'] = cent.x
	if cent.x > bounds['right']:
		bounds['right'] = cent.x
	if cent.y < bounds['bottom']:
		bounds['bottom'] = cent.y
	if cent.y > bounds['top']:
		bounds['top'] = cent.y
print(bounds)
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
	
	precincts[shape[i]['id']]={'x':(cent.x-bounds['left'])/(bounds['right']-bounds['left']),'y':(bounds['top']-cent.y)/(bounds['top']-bounds['bottom']),'name':shape[i]['properties']['NAME'],'d':shape[i]['properties']['G18GOVDSMI'],'r':shape[i]['properties']['G18GOVRMCM'],'county':shape[i]['properties']['COUNTYFP']}




file1 = open('scpre.txt', 'w')
file1.writelines(['std::map<int,Point> scPoints(){\n'])
file1.writelines(['std::map<int,Point> points; int i=0;\n'])
for precinct in precincts:

	file1.writelines(['if (1==1){ Point p;\n'])
	#line = str(precincts[precinct]['name'])+","+str(precincts[precinct]['x'])+","+str(precincts[precinct]['y'])+","+str(precincts[precinct]['d'])+","+str(precincts[precinct]['r'])+","+str(precincts[precinct]['county'])+"\n"
	line = "p.x = "+str(round(precincts[precinct]['x']*100))+"; p.y = "+str(round(precincts[precinct]['y']*100))+"; p.county = "+str(int(precincts[precinct]['county']))+"; p.val = "+str(int(precincts[precinct]['d'])+int(precincts[precinct]['r']))+";\n"
	
	file1.writelines([line])
	file1.writelines(['points[i]=p;i++;}\n'])
file1.writelines(['return points;}\n'])
file1.close()
