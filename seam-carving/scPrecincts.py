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
xList = []
yList = []
precincts = {}
for i in range(0,len(shape)):
	if i%2 > 0 or i>=2000:
		continue
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
	xList.append(cent.x)
	yList.append(cent.y)
	precincts[shape[i]['id']]={'x':cent.x,'y':cent.y,'name':shape[i]['properties']['NAME'],'d':shape[i]['properties']['G18GOVDSMI'],'r':shape[i]['properties']['G18GOVRMCM'],'county':shape[i]['properties']['COUNTYFP']}

xList.sort()
yList.sort()



file1 = open('scpre.txt', 'w')
file1.writelines(['std::map<int,Point> scPoints(){\n'])
file1.writelines(['std::map<int,Point> points; int i=0;\n'])
for precinct in precincts:
	for i in range(0,len(xList)):
		if xList[i] == precincts[precinct]['x']:
			precincts[precinct]['x'] = i
			break
	for i in range(0,len(yList)):
		if yList[i] == precincts[precinct]['y']:
			precincts[precinct]['y'] = i
			break
	file1.writelines(['if (1==1){ Point p;\n'])
	#line = str(precincts[precinct]['name'])+","+str(precincts[precinct]['x'])+","+str(precincts[precinct]['y'])+","+str(precincts[precinct]['d'])+","+str(precincts[precinct]['r'])+","+str(precincts[precinct]['county'])+"\n"
	line = "p.x = "+str(precincts[precinct]['x'])+"; p.y = "+str(precincts[precinct]['y'])+"; p.county = "+str(int(precincts[precinct]['county']))+";\n"
	
	file1.writelines([line])
	file1.writelines(['points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}\n'])
file1.writelines(['return points;}\n'])
file1.close()
