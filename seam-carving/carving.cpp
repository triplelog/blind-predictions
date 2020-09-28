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
EM_JS(void, send_map, (const char* x), {
	var statesOut = [];
	var statesStr = UTF8ToString(x);
	var jsStr = "";
	for (var i=0;i<51;i++){
		statesOut.push(statesStr[i]);
		jsStr += statesStr[i]+"\n";
		
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


Map verticalSeam(Map m){
	int i;
	int ii;
	std::map<int,int> oldMax;
	std::map<int,int> newMax;
	std::map<int,std::vector<int> > oldSeams;
	std::map<int,std::vector<int> > newSeams;
	for(i=0;i<m.width;i++){
		oldMax[i]=m.pointMap[i][0].val;
		oldSeams[i]={i};
	}
	for(ii=1;ii<m.height;ii++){
		for(i=0;i<m.width;i++){
			int left = -10000000;
			if (i>0){left = oldMax[i-1];}
			int mid = oldMax[i];
			int right = -10000000;
			if (i+1<m.width){right = oldMax[i+1];}
			if (left>mid){
				if (left>right){
					newMax[i] = left+m.pointMap[i][ii].val;
					newSeams[i]=oldSeams[i-1].push(i);
				}
				else {
					newMax[i] = right+m.pointMap[i][ii].val;
					newSeams[i]=oldSeams[i+1].push(i);
				}
			}
			else {
				if (mid>right){
					newMax[i] = mid+m.pointMap[i][ii].val;
					newSeams[i]=oldSeams[i].push(i);
				}
				else {
					newMax[i] = right+m.pointMap[i][ii].val;
					newSeams[i]=oldSeams[i+1].push(i);
				}
			}
		}
		oldSeams = newSeams;
		oldMax = newMax;
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
				t.val = 1;
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
		p.val = -1000000;
		pointMap[p.x][p.y] = p;
	}
	
	Map m;
	m.pointMap = pointMap;
	m.width = 100;
	m.height = 100;
	
	m = fillBlanks(m);
	m = verticalSeam(m);
	console_log(m.width);
	console_log(m.height);
}

int main() {
	
	initialRun();
	
	return 1;
}
