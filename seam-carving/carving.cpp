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
EM_JS(void, set_maxX, (int x), {
  maxX = x;
});
EM_JS(void, set_maxY, (int y), {
  maxY = y;
});
EM_JS(void, display_points, (), {
	jsPoints = pointsOut;
	displayNow();
});
EM_JS(void, add_point, (const char* x), {
	var pointSplit = UTF8ToString(x).split(",");
	points.push({"x":pointSplit[0],"y":pointSplit[1],"val":pointSplit[2]});	
});
EM_JS(void, add_pointOut, (const char* x), {
	var pointSplit = UTF8ToString(x).split(",");
	if (parseInt(pointSplit[2])*-1-1000000>=0){
		pointsOut.push({"x":pointSplit[3],"y":pointSplit[4],"ox":pointSplit[0],"oy":pointSplit[1]});	
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
bool killCarveV;
bool killCarveH;
int vertThreads;
int horzThreads;

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

Map splitHorizontal(Map m, int sz){
	int h = m.height;
	int ii;
	int i;
	for(ii=h*sz-sz;ii>=0;ii--){
		if (ii%sz == 0){
			for (i=0;i<m.width;i++){
				m.pointMap[i][ii]=m.pointMap[i][ii/sz];
			}
		}
		else {
			for (i=0;i<m.width;i++){
				Point p;
				p.x = i;
				p.y = ii;
				p.val = 1;
				m.pointMap[i][ii]=p;
			}
		}
	}
	m.height = m.height*sz-sz+1;
	return m;
}
Map splitVertical(Map m, int sz){
	int w = m.width;
	int ii;
	int i;
	for(i=w*sz-sz;i>=0;i--){
		if (i%sz == 0){
			for (ii=0;ii<m.height;ii++){
				m.pointMap[i][ii]=m.pointMap[i/sz][ii];
			}
		}
		else {
			for (ii=0;ii<m.height;ii++){
				Point p;
				p.x = i;
				p.y = ii;
				p.val = 1;
				m.pointMap[i][ii]=p;
			}
		}
	}
	m.width = m.width*sz-sz+1;
	return m;
}
Map horizontalSeam(Map m, int n, int l){
	int i;
	int ii;
	int iii;
	int iiii;
	std::map<int,int> oldMax;
	std::map<int,int> newMax;
	std::map<int,std::vector<int> > oldSeams;
	std::map<int,std::vector<int> > newSeams;
	for(ii=0;ii<m.height;ii++){
		oldMax[ii]=m.pointMap[0][ii].val;
		oldSeams[ii]={ii};
		if (l==0){
			if (m.pointMap[0][ii].val >= 0){
				oldMax[ii]=m.height;
			}
			else {
				oldMax[ii]=-10000000;
			}
			
		}
		else if (l < 0){
			if (m.pointMap[0][ii].val >= 0){
				oldMax[ii]=m.height;
			}
			else {
				oldMax[ii]=-1000000;
				oldSeams[ii]={m.height};
			}
			
		}
		
	}
	int h = m.height;
	int w = m.width;
	int modn = h / n;
	for(i=1;i<w;i++){
		for(ii=0;ii<h;ii++){
			int top = -10000000;
			if (ii%modn>0){top = oldMax[ii-1];}
			int maxv = top;
			int newI = ii-1;
			int mid = oldMax[ii];
			if (mid > maxv){
				maxv = mid;
				newI = ii;
			}
			int bottom = -10000000;
			if (ii+1<h && (ii+1)%modn>0){bottom = oldMax[ii+1];}
			if (bottom > maxv){
				maxv = bottom;
				newI = ii+1;
			}
			
			/*if (l == 2){
				top = -10000000;
				if (ii%modn>1){top = oldMax[ii-2];}
				if (top > maxv){
					maxv = top;
					newI = ii-2;
				}
				bottom = -10000000;
				if (ii+2<h && (ii+2) % modn>0){bottom = oldMax[ii+2];}
				if (bottom > maxv){
					maxv = bottom;
					newI = ii+2;
				}
			}*/
			bool skip = false;
			if (l == 0){
				if (maxv >= 0){
					if (newI == ii){
						maxv = h-1;//zig zag is good
					}
					else {
						maxv = h;
					}
				}
				else {
					for (iiii=2;iiii<h;iiii++){
						if (ii%modn>=iiii && oldMax[ii-iiii] >= 0){
							maxv = h-iiii;
							newI = ii-iiii;
							break;
						}
						if (ii+iiii<h && (ii+iiii) % modn>0 && oldMax[ii+iiii] >= 0){
							maxv = h-iiii;
							newI = ii+iiii;
							break;
						}
					}
				}
			}
			else if (l < 0){
				if (maxv >= 0){
					if (newI == ii){
						maxv = h-1;//zig zag is good
					}
					else {
						maxv = h;
					}
				}
				else {
					for (iiii=2;iiii<h;iiii++){
						if (i%modn>=iiii && oldMax[ii-iiii] >= 0){
							maxv = h-iiii;
							newI = ii-iiii;
							break;
						}
						if (i+iiii<h && (ii+iiii) % modn>0 && oldMax[ii+iiii] >= 0){
							maxv = h-iiii;
							newI = ii+iiii;
							break;
						}
					}
				}
				
				if (maxv >= 0){
				
				}
				else {
					maxv = -1000000;
					newI = ii;
					skip = true;
				}
			}
			
			
			newMax[ii] = maxv+m.pointMap[i][ii].val;

			
			newSeams[ii] = oldSeams[newI];
			if (skip){
				newSeams[ii].push_back(h);
			}
			else {
				newSeams[ii].push_back(ii);
			}
		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	for (iii=n-1;iii>=0;iii--){
		int maxSeam = 0;
		std::vector<int> removeSeam;
		int maxY = (iii+1)*modn;
		if (maxY > h){
			maxY = h;
		}
		for (ii=iii*modn;ii<maxY;ii++){
			if (oldMax[ii]>maxSeam){
				maxSeam = oldMax[ii];
				removeSeam = oldSeams[ii];
			}
		}
		
		if (l >= 0){
			if (maxSeam <=0 && n == 1){
				killCarveH = true;
				return m;
			}
			else if (maxSeam <= 0 && iii< n-1){
				horzThreads/=2;
				return horizontalSeam(m,horzThreads,l);
			}
			else if (maxSeam > 0){
				for(i=0;i<w;i++){
					for(ii=removeSeam[i];ii<m.height-1;ii++){
						m.pointMap[i][ii]=m.pointMap[i][ii+1];
					}
				}
				m.height--;
			}
		}
		else {
			if (maxSeam <=1000000*l){
				killCarveV = true;
				return m;
			}
			else {
				for(i=0;i<w;i++){
					if (removeSeam[i] == m.height){
					
					}
					else {
						for(ii=removeSeam[i];ii<m.height-1;ii++){
							m.pointMap[i][ii]=m.pointMap[i][ii+1];
						}
						m.pointMap[i][m.height-1].val=1;
					}
					
				}
			}
		}
	}
	
	
	return m;
}

Map verticalSeam(Map m, int n, int l){
	int i;
	int ii;
	int iii;
	int iiii;
	std::map<int,int> oldMax;
	std::map<int,int> newMax;
	std::map<int,std::vector<int> > oldSeams;
	std::map<int,std::vector<int> > newSeams;
	for(i=0;i<m.width;i++){
		oldMax[i]=m.pointMap[i][0].val;
		oldSeams[i]={i};
		if (l==0){
			if (m.pointMap[i][0].val >= 0){
				oldMax[i]=m.width;
			}
			else {
				oldMax[i]=-1000000;
			}
		}
		else if (l < 0){
			if (m.pointMap[i][0].val >= 0){
				oldMax[i]=m.width;
			}
			else {
				oldMax[i]=-1000000;
				oldSeams[i]={m.width};
			}
			
		}
		
	}
	int h = m.height;
	int w = m.width;
	int modn = w / n;
	for(ii=1;ii<h;ii++){
		for(i=0;i<w;i++){
			int mpv = m.pointMap[i][ii].val;
			if (l >= 0 && m.pointMap[i][ii].val<0){
				newMax[i] = mpv;
				newSeams[i] = oldSeams[i];
				newSeams[i].push_back(i);
				continue;
			}
			int left = -10000000;
			if (i%modn>0){left = oldMax[i-1];}
			int maxv = left;
			int newI = i-1;
			int mid = oldMax[i];
			if (mid > maxv){
				maxv = mid;
				newI = i;
			}
			int right = -10000000;
			if (i+1<w && (i+1) % modn>0){right = oldMax[i+1];}
			if (right > maxv){
				maxv = right;
				newI = i+1;
			}
			
			/*if (l == 2){
				left = -10000000;
				if (i%modn>1){left = oldMax[i-2];}
				if (left > maxv){
					maxv = left;
					newI = i-2;
				}
				right = -10000000;
				if (i+2<w && (i+2) % modn>0){right = oldMax[i+2];}
				if (right > maxv){
					maxv = right;
					newI = i+2;
				}
			}*/
			bool skip = false;
			if (l == 0){
				if (maxv >= 0){
					if (newI == i){
						maxv = w-1;//zig zag is good
					}
					else {
						maxv = w;
					}
				}
				else {
					for (iiii=2;iiii<w;iiii++){
						if (i%modn>=iiii && oldMax[i-iiii] >= 0){
							maxv = w-iiii;
							newI = i-iiii;
							break;
						}
						if (i+iiii<w && (i+iiii) % modn>0 && oldMax[i+iiii] >= 0){
							maxv = w-iiii;
							newI = i+iiii;
							break;
						}
					}
				}
			}
			else if (l < 0){
				if (maxv >= 0){
					if (newI == i){
						maxv = w-1;//zig zag is good
					}
					else {
						maxv = w;
					}
				}
				else {
					for (iiii=2;iiii<w;iiii++){
						if (i%modn>=iiii && oldMax[i-iiii] >= 0){
							maxv = w-iiii;
							newI = i-iiii;
							break;
						}
						if (i+iiii<w && (i+iiii) % modn>0 && oldMax[i+iiii] >= 0){
							maxv = w-iiii;
							newI = i+iiii;
							break;
						}
					}
				}
				
				if (maxv >= 0){
				
				}
				else {
					maxv = -1000000;
					newI = i;
					skip = true;
				}
			}
			
			newMax[i] = maxv+mpv;

			
			newSeams[i] = oldSeams[newI];
			if (skip){
				newSeams[i].push_back(w);
			}
			else {
				newSeams[i].push_back(i);
			}
		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	//std::vector<int> removeSeams;
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
		if (l >= 0){
			if (maxSeam <=0 && n == 1){
				killCarveV = true;
				return m;
			}
			else if (maxSeam <= 0 && iii< n-1){
				vertThreads/=2;
				return verticalSeam(m,vertThreads,l);
			}
			else if (maxSeam > 0){
				for(ii=0;ii<h;ii++){
					for(i=removeSeam[ii];i<m.width-1;i++){
					
						m.pointMap[i][ii]=m.pointMap[i+1][ii];
					}
				}
				m.width--;
			}
		}
		else {
			if (maxSeam <=1000000*l){
				killCarveV = true;
				return m;
			}
			else {
				for(ii=0;ii<h;ii++){
					if (removeSeam[ii] == m.width){
					
					}
					else {
						for(i=removeSeam[ii];i<m.width-1;i++){
					
							m.pointMap[i][ii]=m.pointMap[i+1][ii];
						}
						m.pointMap[m.width-1][ii].val=1;
					}
					
				}
			}
		}
	}

	
	return m;
}

Map fillBlanks(Map m) {
	int i;
	int ii;
	int ix;
	int iy;
	for(i=0;i<m.width;i++){
		if (m.pointMap.find(i) == m.pointMap.end()){
			std::map<int,Point> t;
			m.pointMap[i] = t;
		}
	}
	for(i=0;i<m.width;i++){
		for(ii=0;ii<m.height;ii++){
			if (m.pointMap[i].find(ii) == m.pointMap[i].end() || m.pointMap[i][ii].val>=0){
				Point t;
				t.x = i;
				t.y = ii;
				int minX = i-1;
				int minY = ii-1;
				int maxX = i+1;
				int maxY = ii+1;
				if (minX<0){minX =0;}
				if (minY<0){minY =0;}
				if (maxX>=m.width){maxX =m.width-1;}
				if (maxY>=m.height){maxY =m.height-1;}
				int maxD = 128;
				for (ix=minX;ix<=maxX;ix++){
					for (iy=minY;iy<=maxY;iy++){
						if (m.pointMap[ix].find(iy) != m.pointMap[ix].end()){
							if (m.pointMap[ix][iy].val<0){
								//int d = (i-ix)*(i-ix)+(ii-iy)*(ii-iy);
								//if (d < minD){
								//	minD = d;
								//}
								maxD /= 2;
							}
						}
					}
				}
				t.val = maxD;
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
	killCarveV = false;
	killCarveH = false;
	int np = 250;
	for(i=0;i<10000;i++){
		xCount[i]=0;
		yCount[i]=0;
	}
	for (i=0;i<np;i++){
		int x = rand() % 10000;
		int y = rand() % 10000;
		Point p;
		p.x = x;
		p.y = y;
		points[i]=p;
		xCount[x]++;
		yCount[y]++;
	}
	
	for(i=0;i<np;i++){
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
		//add_point(pointStr.c_str());
	}
	
	Map m;
	m.pointMap = pointMap;
	m.width = np;
	m.height = np;
	
	auto a11 = std::chrono::high_resolution_clock::now();
	m = fillBlanks(m);
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationTotal);
	
	a11 = std::chrono::high_resolution_clock::now();
	vertThreads = 28;
	horzThreads = 28;
	for (i=0;i<np;i++){
		if (vertThreads>3){
			vertThreads-=3;
		}
		else {
			vertThreads=3;
		}
		if (horzThreads>3){
			horzThreads-=3;
		}
		else {
			horzThreads=3;
		}
		
		if (!killCarveV){
			m = verticalSeam(m,vertThreads,1);
		}
		if (!killCarveH){
			m = horizontalSeam(m,horzThreads,1);
		}
		if (killCarveV && killCarveH){
			break;
		}
		console_log(m.width);
		console_log(m.height);
		if (i%3 == 2){
			m = fillBlanks(m);
		}
	}
	
	int oldArea = m.height*m.width+1;
	while (m.width*m.height<oldArea){
		oldArea = m.height*m.width;
		if (m.width > m.height){
			m = splitHorizontal(m,3);
			vertThreads = 5;
			killCarveV = false;
			m = verticalSeam(m,vertThreads,1);
		}
		else {
			m = splitVertical(m,3);
			horzThreads = 5;
			killCarveH = false;
			m = horizontalSeam(m,horzThreads,1);
		}
		m = fillBlanks(m);
		console_log(m.width);
		console_log(m.height);
		killCarveV = false;
		killCarveH = false;
		vertThreads=2;
		horzThreads=2;
		for (i=0;i<np;i++){
			if (!killCarveV){
				m = verticalSeam(m,1,0);
			}
			if (!killCarveH){
				m = horizontalSeam(m,1,0);
			}
		}
		console_log(m.width);
		console_log(m.height);
	}
		

	
	oldArea = m.height*m.width+1;
	while (m.width*m.height<oldArea){
		oldArea = m.height*m.width;
		if (m.width > m.height){
			m = splitHorizontal(m,2);
			vertThreads = 5;
			killCarveV = false;
			m = verticalSeam(m,vertThreads,1);
		}
		else {
			m = splitVertical(m,2);
			horzThreads = 5;
			killCarveH = false;
			m = horizontalSeam(m,horzThreads,1);
		}
		m = fillBlanks(m);
		console_log(m.width);
		console_log(m.height);
		killCarveV = false;
		killCarveH = false;
		vertThreads=2;
		horzThreads=2;
		for (i=0;i<np;i++){
			if (!killCarveV){
				m = verticalSeam(m,1,0);
			}
			if (!killCarveH){
				m = horizontalSeam(m,1,0);
			}
		}
		console_log(m.width);
		console_log(m.height);
	}
	

	
	killCarveV = false;
	killCarveH = false;
	vertThreads=2;
	horzThreads=2;
	for (i=0;i<np;i++){
		if (!killCarveV){
			m = verticalSeam(m,1,-1);
		}
		if (!killCarveH){
			m = horizontalSeam(m,1,-1);
		}
	}
	
	oldArea = m.height*m.width+1;
	while (m.width*m.height<oldArea){
		oldArea = m.height*m.width;

		m = splitHorizontal(m,1);
		m = splitVertical(m,1);
		m = fillBlanks(m);
		console_log(m.width);
		console_log(m.height);

		killCarveV = false;
		killCarveH = false;
		vertThreads=2;
		horzThreads=2;
		for (i=0;i<np;i++){
			if (!killCarveV){
				m = verticalSeam(m,vertThreads,1);
			}
			if (!killCarveH){
				m = horizontalSeam(m,horzThreads,1);
			}
		}
		console_log(m.width);
		console_log(m.height);
	}
	
	killCarveV = false;
	killCarveH = false;
	vertThreads=2;
	horzThreads=2;
	for (i=0;i<np;i++){
		if (!killCarveV){
			m = verticalSeam(m,1,-2);
		}
		if (!killCarveH){
			m = horizontalSeam(m,1,-2);
		}
	}
	
	oldArea = m.height*m.width+1;
	while (m.width*m.height<oldArea){
		oldArea = m.height*m.width;

		m = splitHorizontal(m,1);
		m = splitVertical(m,1);
		m = fillBlanks(m);
		console_log(m.width);
		console_log(m.height);

		killCarveV = false;
		killCarveH = false;
		vertThreads=2;
		horzThreads=2;
		for (i=0;i<np;i++){
			if (!killCarveV){
				m = verticalSeam(m,vertThreads,1);
			}
			if (!killCarveH){
				m = horizontalSeam(m,horzThreads,1);
			}
		}
		console_log(m.width);
		console_log(m.height);
	}
	
	killCarveV = false;
	killCarveH = false;
	vertThreads=2;
	horzThreads=2;
	for (i=0;i<np;i++){
		if (!killCarveV){
			m = verticalSeam(m,1,-2);
		}
		if (!killCarveH){
			m = horizontalSeam(m,1,-2);
		}
	}

	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(m.width);
	console_log(m.height);
	set_maxX(m.width);
	set_maxY(m.height);
	for(i=0;i<m.width;i++){
		for(ii=0;ii<m.height;ii++){
			Point p = m.pointMap[i][ii];
			std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii);
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
