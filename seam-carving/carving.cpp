#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <string.h> 
#include <ctype.h>
#include <cmath>
#include <variant>
#include <map>
#include <numeric>
#include <chrono>
#include <thread>
#include <array>
#include <vector>
#include <unistd.h>
#include <thread>
#include <future>


#include <emscripten/emscripten.h>

EM_JS(void, console_log, (int x), {
  console.log(x);
});
EM_JS(void, string_log, (const char* x), {
  console.log(UTF8ToString(x));
});
EM_JS(void, display_points, (), {
	console.log(points);
	console.log(pointsOut);
});
EM_JS(void, add_point, (const char* x), {
	var pointSplit = UTF8ToString(x).split(",");
	points.push({"x":pointSplit[0],"y":pointSplit[1],"val":pointSplit[2]});	
});
EM_JS(void, add_pointOut, (const char* x), {
	var pointSplit = UTF8ToString(x).split(",");
	if (parseInt(pointSplit[2])*-1-1000000>=0){
		pointsOut.push({"x":pointSplit[0],"y":pointSplit[1],"val":parseInt(pointSplit[2])*-1-1000000});	
	}
	
});
EM_JS(void, send_results, (const char* x), {
	var xStr = UTF8ToString(x).split(",");

});
EM_JS(void, send_ready, (), {
  cpp_ready();
});


long long durationRand;
int seed;
bool killCarve;



extern "C" {


}

struct Point {
	int x;
	int y;
	int val;
};

struct Map {
	std::map<int,std::map<int,Point> > pointMap;
	int width;
	int height;
};

Map horizontalSeam(Map m){
	int i;
	int ii;
	int iii;
	std::map<int,int> oldMax;
	std::map<int,int> newMax;
	std::map<int,std::vector<int> > oldSeams;
	std::map<int,std::vector<int> > newSeams;
	for(ii=0;ii<m.height;ii++){
		oldMax[ii]=m.pointMap[0][ii].val;
		oldSeams[ii]={ii};
	}
	int h = m.height;
	int w = m.width;
	for(i=1;i<w;i++){
		for(ii=0;ii<h;ii++){
			int top = -10000000;
			if (ii>0){top = oldMax[ii-1];}
			int mid = oldMax[ii];
			int bottom = -10000000;
			int newI = ii;
			if (ii+1<h){bottom = oldMax[ii+1];}
			if (top>mid){
				if (top>bottom){
					newMax[ii] = top+m.pointMap[i][ii].val;
					newI = ii-1;
				}
				else {
					newMax[ii] = bottom+m.pointMap[i][ii].val;
					newI = ii+1;
				}
			}
			else {
				if (mid>bottom){
					newMax[ii] = mid+m.pointMap[i][ii].val;
					newI = ii;
				}
				else {
					newMax[ii] = bottom+m.pointMap[i][ii].val;
					newI = ii+1;
				}
			}
			
			newSeams[ii] = oldSeams[newI];
			newSeams[ii].push_back(ii);
		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	
	int maxSeam = 0;
	std::vector<int> removeSeam;
	for (ii=0;ii<h;ii++){
		if (oldMax[ii]>maxSeam){
			maxSeam = oldMax[ii];
			removeSeam = oldSeams[ii];
		}
	}
	if (maxSeam <=0){
		killCarve = true;
		return m;
	}
	for(i=0;i<w;i++){
		for(ii=removeSeam[i];ii<h-1;ii++){
			m.pointMap[i][ii]=m.pointMap[i][ii+1];
		}
	}
	m.height--;
	return m;
}

Map verticalSeam(Map m, int n){
	int i;
	int ii;
	int iii;
	std::map<int,int> oldMax;
	std::map<int,int> newMax;
	std::map<int,std::vector<int> > oldSeams;
	std::map<int,std::vector<int> > newSeams;
	for(i=0;i<m.width;i++){
		oldMax[i]=m.pointMap[i][0].val;
		oldSeams[i]={i};
	}
	int h = m.height;
	int w = m.width;
	int modn = w / n;
	for(ii=1;ii<h;ii++){
		for(i=0;i<w;i++){
			int left = -10000000;
			if (i%modn>0){left = oldMax[i-1];}
			int mid = oldMax[i];
			int right = -10000000;
			int newI = i;
			if (i+1<w && i+1 % modn>0){right = oldMax[i+1];}
			if (left>mid){
				if (left>right){
					newMax[i] = left+m.pointMap[i][ii].val;
					newI = i-1;
				}
				else {
					newMax[i] = right+m.pointMap[i][ii].val;
					newI = i+1;
				}
			}
			else {
				if (mid>right){
					newMax[i] = mid+m.pointMap[i][ii].val;
					newI = i;
				}
				else {
					newMax[i] = right+m.pointMap[i][ii].val;
					newI = i+1;
				}
			}
			
			newSeams[i] = oldSeams[newI];
			newSeams[i].push_back(i);
		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	for (iii=n-1;iii>=0;iii--){
		int maxSeam = 0;
		std::vector<int> removeSeam;
		int maxX = (iii+1)*modn;
		if (maxX > w){
			maxX = w;
		}
		for (i=iii*modn;i<maxX;i++){
			if (oldMax[i]>maxSeam){
				maxSeam = oldMax[i];
				removeSeam = oldSeams[i];
			}
		}
		if (maxSeam <=0 && n == 1){
			killCarve = true;
			return m;
		}
		else if (maxSeam <= 0 && iii< n-1){
			return verticalSeam(m,n-1);
		}
		else if (maxSeam > 0){
			for(ii=0;ii<h;ii++){
				if (m.pointMap[removeSeam[ii]][ii].val<0){
					console_log(h);
					console_log(w);
					console_log(n);
					console_log(iii);
					console_log(diff);
					console_log(removeSeam[ii]);
				}
				for(i=removeSeam[ii];i<m.width-1;i++){
					
					m.pointMap[i][ii]=m.pointMap[i+1][ii];
				}
			}
			m.width--;
		}
	}

	
	return m;
}

Map fillBlanks(Map m) {
	int i;
	int ii;
	for(i=0;i<m.width;i++){
		if (m.pointMap.find(i) == m.pointMap.end()){
			std::map<int,Point> t;
			m.pointMap[i] = t;
		}
		for(ii=0;ii<m.height;ii++){
			if (m.pointMap[i].find(ii) == m.pointMap[i].end()){
				Point t;
				t.x = i;
				t.y = ii;
				t.val = rand() % 100;
				m.pointMap[i][ii] = t;
			}
		}
	}
	return m;
}

void initialRun(){
	seed = 7;
	srand(seed);
	int i;
	int ii;
	std::map<int,Point> points;
	std::map<int,std::map<int,Point>> pointMap;
	std::map<int,int> xCount;
	std::map<int,int> yCount;
	killCarve = false;
	for(i=0;i<1000;i++){
		xCount[i]=0;
		yCount[i]=0;
	}
	for (i=0;i<100;i++){
		int x = rand() % 1000;
		int y = rand() % 1000;
		Point p;
		p.x = x;
		p.y = y;
		points[i]=p;
		xCount[x]++;
		yCount[y]++;
	}
	
	for(i=0;i<100;i++){
		Point p = points[i];
		int newX = 0;
		for (ii=0;ii<p.x;ii++){
			newX+=xCount[ii];
		}
		int newY = 0;
		for (ii=0;ii<p.y;ii++){
			newY+=yCount[ii];
		}
		p.x = newX;
		p.y = newY;
		p.val = -1000000-i;
		pointMap[p.x][p.y] = p;
		std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val);
		add_point(pointStr.c_str());
	}
	
	Map m;
	m.pointMap = pointMap;
	m.width = 100;
	m.height = 100;
	
	m = fillBlanks(m);
	
	auto a11 = std::chrono::high_resolution_clock::now();
	for (i=0;i<100;i++){
		if (!killCarve){
			m = verticalSeam(m,2);
		}
		if (!killCarve){
			m = horizontalSeam(m);
		}
		if (!killCarve){
			m = horizontalSeam(m);
		}
	}
	
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(m.width);
	console_log(m.height);
	for(i=0;i<m.width;i++){
		for(ii=0;ii<m.height;ii++){
			Point p = m.pointMap[i][ii];
			std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val);
			add_pointOut(pointStr.c_str());
		}
	}
	
	console_log(durationTotal);
	display_points();
}

int main() {
	
	initialRun();
	
	return 1;
}
