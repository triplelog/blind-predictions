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

#include "data.cpp"

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
};

void initialRun(){
	seed = 7;
	srand(seed);
	int i;
	int ii;
	std::map<int,Point> points;
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
		points[i] = p;
	}

}

int main() {
	
	initialRun();
	
	return 1;
}
