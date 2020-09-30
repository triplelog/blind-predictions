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
	if (parseInt(pointSplit[2])>0){
		pointsOut.push({"x":pointSplit[3],"y":pointSplit[4],"ox":pointSplit[0],"oy":pointSplit[1],"county":pointSplit[5]});	
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
	int county;
};

std::map<int,Point> scPoints(){
std::map<int,Point> points; int i=0;
if (1==1){ Point p;
p.x = 20; p.y = 69; p.county = 1; p.val = 817;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 66; p.county = 1; p.val = 625;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 65; p.county = 1; p.val = 580;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 68; p.county = 1; p.val = 426;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 71; p.county = 1; p.val = 636;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 76; p.county = 1; p.val = 261;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 65; p.county = 1; p.val = 944;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 70; p.county = 1; p.val = 560;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 74; p.county = 1; p.val = 312;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 72; p.county = 1; p.val = 813;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 75; p.county = 1; p.val = 423;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 73; p.county = 1; p.val = 609;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 68; p.county = 1; p.val = 598;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 66; p.county = 1; p.val = 470;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 68; p.county = 1; p.val = 490;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 40; p.county = 3; p.val = 0;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 48; p.county = 3; p.val = 735;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 48; p.county = 3; p.val = 511;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 47; p.county = 3; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 49; p.county = 3; p.val = 680;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 52; p.county = 3; p.val = 702;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 48; p.county = 3; p.val = 509;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 50; p.county = 3; p.val = 990;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 51; p.county = 3; p.val = 1052;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 48; p.county = 3; p.val = 639;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 46; p.county = 3; p.val = 997;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 48; p.county = 3; p.val = 298;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 47; p.county = 3; p.val = 728;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 46; p.county = 3; p.val = 949;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 45; p.county = 3; p.val = 395;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 43; p.county = 3; p.val = 853;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 53; p.county = 3; p.val = 516;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 44; p.county = 3; p.val = 830;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 45; p.county = 3; p.val = 575;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 40; p.county = 3; p.val = 878;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 49; p.county = 3; p.val = 402;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 43; p.county = 3; p.val = 910;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 3; p.val = 758;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 45; p.county = 3; p.val = 313;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 3; p.val = 488;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 46; p.county = 3; p.val = 904;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 46; p.county = 3; p.val = 547;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 46; p.county = 3; p.val = 586;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 45; p.county = 3; p.val = 475;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 56; p.county = 3; p.val = 634;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 51; p.county = 3; p.val = 445;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 50; p.county = 3; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 48; p.county = 3; p.val = 389;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 45; p.county = 3; p.val = 755;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 47; p.county = 3; p.val = 978;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 47; p.county = 3; p.val = 400;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 3; p.val = 716;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 45; p.county = 3; p.val = 741;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 48; p.county = 3; p.val = 700;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 50; p.county = 3; p.val = 875;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 53; p.county = 3; p.val = 760;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 47; p.county = 3; p.val = 890;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 44; p.county = 3; p.val = 433;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 46; p.county = 3; p.val = 536;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 48; p.county = 3; p.val = 965;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 48; p.county = 3; p.val = 546;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 47; p.county = 3; p.val = 645;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 43; p.county = 3; p.val = 609;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 49; p.county = 3; p.val = 1264;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 47; p.county = 3; p.val = 1213;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 47; p.county = 3; p.val = 688;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 47; p.county = 3; p.val = 673;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 48; p.county = 3; p.val = 583;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 48; p.county = 3; p.val = 827;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 45; p.county = 3; p.val = 951;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 46; p.county = 3; p.val = 765;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 42; p.county = 3; p.val = 946;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 47; p.county = 3; p.val = 619;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 47; p.county = 3; p.val = 538;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 44; p.county = 3; p.val = 902;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 44; p.county = 3; p.val = 1162;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 46; p.county = 3; p.val = 805;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 47; p.county = 3; p.val = 1293;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 45; p.county = 3; p.val = 1128;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 46; p.county = 3; p.val = 1006;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 47; p.county = 3; p.val = 522;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 48; p.county = 3; p.val = 847;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 46; p.county = 3; p.val = 923;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 45; p.county = 3; p.val = 500;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 46; p.county = 3; p.val = 467;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 3; p.val = 506;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 42; p.county = 3; p.val = 516;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 44; p.county = 3; p.val = 490;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 47; p.county = 3; p.val = 336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 47; p.county = 3; p.val = 674;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 47; p.county = 3; p.val = 345;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 46; p.county = 3; p.val = 708;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 3; p.val = 582;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 46; p.county = 3; p.val = 666;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 45; p.county = 3; p.val = 757;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 3; p.val = 590;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 47; p.county = 3; p.val = 621;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 45; p.county = 3; p.val = 935;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 46; p.county = 3; p.val = 708;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 45; p.county = 3; p.val = 1205;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 30; p.county = 5; p.val = 492;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 29; p.county = 5; p.val = 471;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 29; p.county = 5; p.val = 295;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 25; p.county = 5; p.val = 552;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 32; p.county = 5; p.val = 267;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 29; p.county = 5; p.val = 453;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 30; p.county = 5; p.val = 244;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 32; p.county = 5; p.val = 123;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 79; p.county = 7; p.val = 266;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 76; p.county = 7; p.val = 234;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 79; p.county = 7; p.val = 790;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 84; p.county = 7; p.val = 1099;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 82; p.county = 7; p.val = 978;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 77; p.county = 7; p.val = 331;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 72; p.county = 7; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 72; p.county = 7; p.val = 393;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 82; p.county = 7; p.val = 509;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 83; p.county = 7; p.val = 407;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 81; p.county = 7; p.val = 1170;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 77; p.county = 7; p.val = 906;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 83; p.county = 7; p.val = 327;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 82; p.county = 7; p.val = 1565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 84; p.county = 7; p.val = 443;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 77; p.county = 7; p.val = 340;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 80; p.county = 7; p.val = 352;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 80; p.county = 7; p.val = 759;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 79; p.county = 7; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 72; p.county = 7; p.val = 320;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 81; p.county = 7; p.val = 892;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 79; p.county = 7; p.val = 608;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 76; p.county = 7; p.val = 520;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 85; p.county = 7; p.val = 1369;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 87; p.county = 7; p.val = 1564;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 78; p.county = 7; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 81; p.county = 7; p.val = 666;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 80; p.county = 7; p.val = 1422;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 75; p.county = 7; p.val = 627;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 77; p.county = 7; p.val = 916;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 77; p.county = 7; p.val = 276;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 76; p.county = 7; p.val = 769;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 80; p.county = 7; p.val = 891;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 74; p.county = 7; p.val = 609;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 78; p.county = 7; p.val = 848;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 76; p.county = 7; p.val = 502;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 77; p.county = 7; p.val = 180;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 79; p.county = 7; p.val = 1290;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 80; p.county = 7; p.val = 1286;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 81; p.county = 7; p.val = 1016;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 83; p.county = 7; p.val = 1146;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 76; p.county = 7; p.val = 688;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 78; p.county = 7; p.val = 434;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 75; p.county = 7; p.val = 433;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 85; p.county = 7; p.val = 1362;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 74; p.county = 7; p.val = 486;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 85; p.county = 7; p.val = 1311;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 80; p.county = 7; p.val = 244;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 80; p.county = 7; p.val = 430;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 81; p.county = 7; p.val = 870;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 83; p.county = 7; p.val = 878;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 75; p.county = 7; p.val = 196;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 83; p.county = 7; p.val = 1565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 82; p.county = 7; p.val = 1111;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 82; p.county = 7; p.val = 1151;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 74; p.county = 7; p.val = 445;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 80; p.county = 7; p.val = 645;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 79; p.county = 7; p.val = 775;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 79; p.county = 7; p.val = 698;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 79; p.county = 7; p.val = 1146;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 78; p.county = 7; p.val = 293;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 78; p.county = 7; p.val = 983;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 78; p.county = 7; p.val = 266;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 78; p.county = 7; p.val = 245;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 78; p.county = 7; p.val = 262;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 78; p.county = 7; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 79; p.county = 7; p.val = 871;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 79; p.county = 7; p.val = 144;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 77; p.county = 7; p.val = 464;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 78; p.county = 7; p.val = 1088;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 79; p.county = 7; p.val = 1345;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 80; p.county = 7; p.val = 1088;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 79; p.county = 7; p.val = 477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 86; p.county = 7; p.val = 1313;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 79; p.county = 7; p.val = 904;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 88; p.county = 7; p.val = 1659;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 79; p.county = 7; p.val = 1022;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 80; p.county = 7; p.val = 969;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 77; p.county = 7; p.val = 1262;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 87; p.county = 7; p.val = 2153;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 35; p.county = 9; p.val = 137;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 36; p.county = 9; p.val = 229;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 33; p.county = 9; p.val = 505;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 40; p.county = 9; p.val = 1064;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 37; p.county = 9; p.val = 99;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 39; p.county = 9; p.val = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 35; p.county = 9; p.val = 154;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 32; p.county = 9; p.val = 90;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 33; p.county = 9; p.val = 103;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 34; p.county = 9; p.val = 234;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 37; p.county = 9; p.val = 714;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 41; p.county = 9; p.val = 727;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 39; p.county = 9; p.val = 269;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 39; p.county = 11; p.val = 301;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 39; p.county = 11; p.val = 722;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 37; p.county = 11; p.val = 799;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 36; p.county = 11; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 11; p.val = 486;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 40; p.county = 11; p.val = 308;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 42; p.county = 11; p.val = 350;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 36; p.county = 11; p.val = 327;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 34; p.county = 11; p.val = 301;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 43; p.county = 11; p.val = 478;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 38; p.county = 11; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 36; p.county = 11; p.val = 609;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 44; p.county = 11; p.val = 734;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 41; p.county = 11; p.val = 313;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 42; p.county = 11; p.val = 475;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 37; p.county = 11; p.val = 0;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 11; p.county = 13; p.val = 431;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 11; p.county = 13; p.val = 605;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 11; p.county = 13; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 10; p.county = 13; p.val = 937;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 11; p.county = 13; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 8; p.county = 13; p.val = 717;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 10; p.county = 13; p.val = 1076;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 12; p.county = 13; p.val = 184;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 9; p.county = 13; p.val = 652;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 9; p.county = 13; p.val = 571;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 11; p.county = 13; p.val = 610;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 10; p.county = 13; p.val = 716;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 9; p.county = 13; p.val = 862;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 8; p.county = 13; p.val = 1071;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 10; p.county = 13; p.val = 625;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 8; p.county = 13; p.val = 805;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 11; p.county = 13; p.val = 849;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 9; p.county = 13; p.val = 963;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 12; p.county = 13; p.val = 1005;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 13; p.county = 13; p.val = 834;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 11; p.county = 13; p.val = 709;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 12; p.county = 13; p.val = 589;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 10; p.county = 13; p.val = 573;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 15; p.county = 13; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 12; p.county = 13; p.val = 512;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 14; p.county = 13; p.val = 528;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 13; p.county = 13; p.val = 733;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 16; p.county = 13; p.val = 656;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 18; p.county = 13; p.val = 409;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 12; p.county = 13; p.val = 258;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 9; p.county = 13; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 6; p.county = 13; p.val = 835;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 11; p.county = 13; p.val = 1151;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 11; p.county = 13; p.val = 844;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 10; p.county = 13; p.val = 811;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 7; p.county = 13; p.val = 736;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 12; p.county = 13; p.val = 577;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 12; p.county = 13; p.val = 581;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 0; p.county = 13; p.val = 298;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 4; p.county = 13; p.val = 644;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 2; p.county = 13; p.val = 553;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 4; p.county = 13; p.val = 686;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 4; p.county = 13; p.val = 663;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 3; p.county = 13; p.val = 1018;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 4; p.county = 13; p.val = 701;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 2; p.county = 13; p.val = 789;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 3; p.county = 13; p.val = 835;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 6; p.county = 13; p.val = 753;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 3; p.county = 13; p.val = 1213;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 5; p.county = 13; p.val = 872;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 4; p.county = 13; p.val = 596;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 6; p.county = 13; p.val = 583;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 2; p.county = 13; p.val = 781;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 5; p.county = 13; p.val = 643;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 5; p.county = 13; p.val = 652;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 4; p.county = 13; p.val = 734;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 2; p.county = 13; p.val = 1096;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 2; p.county = 13; p.val = 898;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 3; p.county = 13; p.val = 1155;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 2; p.county = 13; p.val = 768;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 1; p.county = 13; p.val = 486;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 1; p.county = 13; p.val = 746;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 0; p.county = 13; p.val = 572;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 1; p.county = 13; p.val = 355;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 1; p.county = 13; p.val = 621;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 6; p.county = 13; p.val = 1353;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 4; p.county = 13; p.val = 556;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 13; p.val = 569;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 5; p.county = 13; p.val = 1165;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 6; p.county = 13; p.val = 645;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 13; p.val = 901;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 13; p.val = 655;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 13; p.val = 871;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 5; p.county = 13; p.val = 825;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 6; p.county = 13; p.val = 714;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 4; p.county = 13; p.val = 891;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 3; p.county = 13; p.val = 798;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 5; p.county = 13; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 5; p.county = 13; p.val = 1290;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 13; p.val = 619;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 13; p.val = 771;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 3; p.county = 13; p.val = 1565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 6; p.county = 13; p.val = 532;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 7; p.county = 13; p.val = 589;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 5; p.county = 13; p.val = 1519;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 13; p.val = 740;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 6; p.county = 13; p.val = 1219;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 13; p.val = 785;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 13; p.val = 1010;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 6; p.county = 13; p.val = 866;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 5; p.county = 13; p.val = 745;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 13; p.val = 797;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 40; p.county = 15; p.val = 526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 36; p.county = 15; p.val = 139;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 39; p.county = 15; p.val = 612;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 40; p.county = 15; p.val = 850;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 38; p.county = 15; p.val = 860;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 37; p.county = 15; p.val = 511;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 43; p.county = 15; p.val = 660;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 43; p.county = 15; p.val = 647;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 15; p.val = 569;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 15; p.val = 1179;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 29; p.county = 15; p.val = 974;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 29; p.county = 15; p.val = 626;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 43; p.county = 15; p.val = 357;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 36; p.county = 15; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 42; p.county = 15; p.val = 662;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 32; p.county = 15; p.val = 1165;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 15; p.val = 1250;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 30; p.county = 15; p.val = 696;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 31; p.county = 15; p.val = 862;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 37; p.county = 15; p.val = 926;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 34; p.county = 15; p.val = 622;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 38; p.county = 15; p.val = 306;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 39; p.county = 15; p.val = 565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 36; p.county = 15; p.val = 753;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 34; p.county = 15; p.val = 390;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 35; p.county = 15; p.val = 633;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 15; p.val = 808;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 25; p.county = 15; p.val = 1258;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 25; p.county = 15; p.val = 947;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 30; p.county = 15; p.val = 947;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 30; p.county = 15; p.val = 665;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 30; p.county = 15; p.val = 805;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 27; p.county = 15; p.val = 690;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 15; p.val = 692;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 15; p.val = 683;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 29; p.county = 15; p.val = 983;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 32; p.county = 15; p.val = 691;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 37; p.county = 15; p.val = 759;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 35; p.county = 15; p.val = 652;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 35; p.county = 15; p.val = 974;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 31; p.county = 15; p.val = 713;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 31; p.county = 15; p.val = 495;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 29; p.county = 15; p.val = 1065;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 32; p.county = 15; p.val = 1193;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 36; p.county = 15; p.val = 247;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 31; p.county = 15; p.val = 639;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 29; p.county = 15; p.val = 812;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 30; p.county = 15; p.val = 872;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 29; p.county = 15; p.val = 1024;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 29; p.county = 15; p.val = 1259;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 34; p.county = 15; p.val = 1234;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 33; p.county = 15; p.val = 751;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 24; p.county = 15; p.val = 959;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 24; p.county = 15; p.val = 1372;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 26; p.county = 15; p.val = 1108;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 27; p.county = 15; p.val = 1058;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 33; p.county = 15; p.val = 2675;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 30; p.county = 15; p.val = 1005;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 32; p.county = 15; p.val = 1113;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 27; p.county = 15; p.val = 795;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 42; p.county = 15; p.val = 652;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 35; p.county = 15; p.val = 506;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 30; p.county = 15; p.val = 622;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 27; p.county = 15; p.val = 1040;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 27; p.county = 15; p.val = 914;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 28; p.county = 15; p.val = 556;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 31; p.county = 15; p.val = 817;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 29; p.county = 15; p.val = 547;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 30; p.county = 15; p.val = 650;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 28; p.county = 15; p.val = 709;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 31; p.county = 15; p.val = 1856;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 30; p.county = 15; p.val = 743;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 32; p.county = 15; p.val = 1083;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 30; p.county = 15; p.val = 677;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 15; p.val = 568;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 15; p.val = 713;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 15; p.val = 845;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 32; p.county = 15; p.val = 80;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 15; p.val = 737;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 31; p.county = 15; p.val = 1129;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 53; p.county = 17; p.val = 504;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 48; p.county = 17; p.val = 464;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 51; p.county = 17; p.val = 632;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 49; p.county = 17; p.val = 138;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 51; p.county = 17; p.val = 996;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 52; p.county = 17; p.val = 309;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 53; p.county = 17; p.val = 165;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 50; p.county = 17; p.val = 458;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 46; p.county = 17; p.val = 215;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 51; p.county = 17; p.val = 271;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 56; p.county = 17; p.val = 994;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 50; p.county = 17; p.val = 796;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 27; p.county = 19; p.val = 811;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 31; p.county = 19; p.val = 547;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 21; p.county = 19; p.val = 718;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 28; p.county = 19; p.val = 994;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 18; p.county = 19; p.val = 728;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 22; p.county = 19; p.val = 497;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 24; p.county = 19; p.val = 733;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 23; p.county = 19; p.val = 926;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 23; p.county = 19; p.val = 992;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 23; p.county = 19; p.val = 667;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 23; p.county = 19; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 24; p.county = 19; p.val = 1139;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 23; p.county = 19; p.val = 1094;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 24; p.county = 19; p.val = 1501;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 24; p.county = 19; p.val = 852;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 21; p.county = 19; p.val = 1281;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 19; p.val = 926;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 32; p.county = 19; p.val = 1072;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 28; p.county = 19; p.val = 1103;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 18; p.county = 19; p.val = 699;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 19; p.val = 523;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 16; p.county = 19; p.val = 1224;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 28; p.county = 19; p.val = 1065;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 19; p.val = 739;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 19; p.val = 523;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 30; p.county = 19; p.val = 1022;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 23; p.county = 19; p.val = 549;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 23; p.county = 19; p.val = 668;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 29; p.county = 19; p.val = 1213;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 15; p.county = 19; p.val = 985;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 15; p.county = 19; p.val = 1627;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 570;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 733;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 530;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 17; p.county = 19; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 19; p.county = 19; p.val = 923;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 555;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 553;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 551;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 24; p.county = 19; p.val = 504;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 664;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 623;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 303;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 19; p.val = 691;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 672;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 720;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 731;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 878;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 635;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 740;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 19; p.val = 463;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 24; p.county = 19; p.val = 370;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 22; p.county = 19; p.val = 1102;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 22; p.county = 19; p.val = 554;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 19; p.val = 642;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 19; p.val = 920;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 19; p.val = 869;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 22; p.county = 19; p.val = 583;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 23; p.county = 19; p.val = 1045;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 23; p.county = 19; p.val = 759;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 19; p.val = 510;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 23; p.county = 19; p.val = 1089;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 19; p.val = 1430;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 24; p.county = 19; p.val = 1016;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 24; p.county = 19; p.val = 471;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 24; p.county = 19; p.val = 491;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 24; p.county = 19; p.val = 327;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 25; p.county = 19; p.val = 1765;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 25; p.county = 19; p.val = 782;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 25; p.county = 19; p.val = 196;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 26; p.county = 19; p.val = 2471;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 26; p.county = 19; p.val = 917;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 26; p.county = 19; p.val = 2558;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 25; p.county = 19; p.val = 1044;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 25; p.county = 19; p.val = 2010;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 26; p.county = 19; p.val = 1755;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 19; p.county = 19; p.val = 1156;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 18; p.county = 19; p.val = 534;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 21; p.county = 19; p.val = 893;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 20; p.county = 19; p.val = 448;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 20; p.county = 19; p.val = 997;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 20; p.county = 19; p.val = 1141;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 21; p.county = 19; p.val = 687;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 19; p.val = 921;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 19; p.val = 698;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 19; p.val = 1017;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 19; p.val = 1021;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 18; p.county = 19; p.val = 1034;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 25; p.county = 19; p.val = 1525;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 25; p.county = 19; p.val = 767;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 26; p.county = 19; p.val = 1635;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 25; p.county = 19; p.val = 812;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 20; p.county = 19; p.val = 581;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 20; p.county = 19; p.val = 844;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 20; p.county = 19; p.val = 973;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 966;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 20; p.county = 19; p.val = 1948;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 19; p.val = 965;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 21; p.county = 19; p.val = 723;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 19; p.val = 834;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 21; p.county = 19; p.val = 987;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 21; p.county = 19; p.val = 915;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 21; p.county = 19; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 21; p.county = 19; p.val = 811;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 21; p.county = 19; p.val = 1941;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 18; p.county = 19; p.val = 626;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 19; p.county = 19; p.val = 602;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 23; p.county = 19; p.val = 498;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 20; p.county = 19; p.val = 782;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 20; p.county = 19; p.val = 1177;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 21; p.county = 19; p.val = 944;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 22; p.county = 19; p.val = 569;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 23; p.county = 19; p.val = 1089;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 661;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 753;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 636;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 609;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 525;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 22; p.county = 19; p.val = 620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 22; p.county = 19; p.val = 984;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 877;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 169;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 483;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 24; p.county = 19; p.val = 540;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 22; p.county = 19; p.val = 2121;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 23; p.county = 19; p.val = 1089;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 23; p.county = 19; p.val = 1574;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 285;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 811;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 744;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 1088;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 826;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 22; p.county = 19; p.val = 387;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 1032;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 664;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 690;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 24; p.county = 19; p.val = 694;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 19; p.val = 894;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 24; p.county = 19; p.val = 417;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 549;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 542;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 698;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 19; p.val = 760;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 24; p.county = 19; p.val = 563;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 24; p.county = 19; p.val = 713;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 24; p.county = 19; p.val = 369;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 24; p.county = 19; p.val = 1185;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 24; p.county = 19; p.val = 1034;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 19; p.val = 966;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 24; p.county = 19; p.val = 1660;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 24; p.county = 19; p.val = 381;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 24; p.county = 19; p.val = 174;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 24; p.county = 19; p.val = 763;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 681;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 24; p.county = 19; p.val = 584;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 469;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 19; p.val = 737;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 19; p.val = 561;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 19; p.val = 543;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 19; p.val = 313;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 406;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 241;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 19; p.val = 474;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 19; p.val = 579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 26; p.county = 19; p.val = 983;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 19; p.val = 1090;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 19; p.val = 334;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 19; p.val = 433;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 27; p.county = 19; p.val = 293;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 19; p.val = 967;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 572;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 460;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 19; p.val = 476;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 323;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 25; p.county = 19; p.val = 502;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 19; p.val = 753;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 19; p.val = 659;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 19; p.val = 203;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 27; p.county = 19; p.val = 372;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 19; p.val = 428;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 95; p.county = 21; p.val = 468;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 97; p.county = 21; p.val = 692;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 98; p.county = 21; p.val = 651;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 99; p.county = 21; p.val = 646;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 98; p.county = 21; p.val = 448;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 98; p.county = 21; p.val = 691;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 96; p.county = 21; p.val = 772;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 97; p.county = 21; p.val = 515;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 96; p.county = 21; p.val = 603;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 98; p.county = 21; p.val = 728;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 96; p.county = 21; p.val = 550;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 97; p.county = 21; p.val = 254;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 97; p.county = 21; p.val = 530;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 97; p.county = 21; p.val = 674;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 99; p.county = 21; p.val = 1160;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 95; p.county = 21; p.val = 612;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 99; p.county = 21; p.val = 623;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 97; p.county = 21; p.val = 315;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 91; p.county = 21; p.val = 221;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 97; p.county = 21; p.val = 771;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 100; p.county = 21; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 96; p.county = 21; p.val = 694;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 97; p.county = 21; p.val = 467;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 99; p.county = 21; p.val = 524;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 97; p.county = 21; p.val = 381;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 94; p.county = 21; p.val = 527;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 93; p.county = 21; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 94; p.county = 21; p.val = 318;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 100; p.county = 21; p.val = 561;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 85; p.county = 23; p.val = 457;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 86; p.county = 23; p.val = 366;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 82; p.county = 23; p.val = 599;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 82; p.county = 23; p.val = 358;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 88; p.county = 23; p.val = 694;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 86; p.county = 23; p.val = 673;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 85; p.county = 23; p.val = 800;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 82; p.county = 23; p.val = 133;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 82; p.county = 23; p.val = 406;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 88; p.county = 23; p.val = 554;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 85; p.county = 23; p.val = 781;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 87; p.county = 23; p.val = 749;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 81; p.county = 23; p.val = 251;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 87; p.county = 23; p.val = 342;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 80; p.county = 23; p.val = 521;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 86; p.county = 23; p.val = 690;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 85; p.county = 23; p.val = 432;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 84; p.county = 23; p.val = 573;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 85; p.county = 23; p.val = 439;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 84; p.county = 23; p.val = 441;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 81; p.county = 25; p.val = 342;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 82; p.county = 25; p.val = 176;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 84; p.county = 25; p.val = 140;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 87; p.county = 25; p.val = 677;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 82; p.county = 25; p.val = 528;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 87; p.county = 25; p.val = 427;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 86; p.county = 25; p.val = 653;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 85; p.county = 25; p.val = 436;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 84; p.county = 25; p.val = 730;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 84; p.county = 25; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 85; p.county = 25; p.val = 829;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 88; p.county = 25; p.val = 388;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 83; p.county = 25; p.val = 552;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 84; p.county = 25; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 77; p.county = 25; p.val = 817;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 78; p.county = 25; p.val = 348;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 87; p.county = 25; p.val = 199;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 79; p.county = 25; p.val = 315;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 86; p.county = 25; p.val = 824;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 87; p.county = 25; p.val = 691;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 81; p.county = 25; p.val = 326;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 79; p.county = 25; p.val = 136;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 86; p.county = 25; p.val = 461;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 84; p.county = 25; p.val = 315;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 87; p.county = 25; p.val = 237;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 55; p.county = 27; p.val = 534;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 57; p.county = 27; p.val = 316;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 55; p.county = 27; p.val = 107;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 48; p.county = 27; p.val = 232;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 51; p.county = 27; p.val = 370;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 47; p.county = 27; p.val = 1009;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 54; p.county = 27; p.val = 381;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 58; p.county = 27; p.val = 340;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 54; p.county = 27; p.val = 239;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 47; p.county = 27; p.val = 1111;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 52; p.county = 27; p.val = 323;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 51; p.county = 27; p.val = 549;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 51; p.county = 27; p.val = 677;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 52; p.county = 27; p.val = 701;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 53; p.county = 27; p.val = 504;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 56; p.county = 27; p.val = 335;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 53; p.county = 27; p.val = 599;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 50; p.county = 27; p.val = 165;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 56; p.county = 27; p.val = 267;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 46; p.county = 27; p.val = 1094;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 48; p.county = 27; p.val = 202;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 50; p.county = 27; p.val = 537;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 59; p.county = 27; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 50; p.county = 27; p.val = 641;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 53; p.county = 27; p.val = 205;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 28; p.county = 29; p.val = 231;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 31; p.county = 29; p.val = 302;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 26; p.county = 29; p.val = 794;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 32; p.county = 29; p.val = 189;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 17; p.county = 29; p.val = 533;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 21; p.county = 29; p.val = 557;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 29; p.county = 29; p.val = 360;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 27; p.county = 29; p.val = 318;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 22; p.county = 29; p.val = 246;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 30; p.county = 29; p.val = 197;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 30; p.county = 29; p.val = 511;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 24; p.county = 29; p.val = 439;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 29; p.county = 29; p.val = 620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 23; p.county = 29; p.val = 119;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 24; p.county = 29; p.val = 392;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 22; p.county = 29; p.val = 288;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 27; p.county = 29; p.val = 506;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 26; p.county = 29; p.val = 264;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 29; p.county = 29; p.val = 191;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 30; p.county = 29; p.val = 284;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 33; p.county = 29; p.val = 602;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 28; p.county = 29; p.val = 388;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 26; p.county = 29; p.val = 261;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 25; p.county = 29; p.val = 542;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 27; p.county = 29; p.val = 468;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 25; p.county = 29; p.val = 574;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 26; p.county = 29; p.val = 614;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 31; p.county = 29; p.val = 196;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 29; p.county = 29; p.val = 202;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 12; p.county = 29; p.val = 794;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 27; p.county = 29; p.val = 763;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 26; p.county = 29; p.val = 467;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 77; p.county = 31; p.val = 953;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 74; p.county = 31; p.val = 399;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 72; p.county = 31; p.val = 400;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 74; p.county = 31; p.val = 626;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 72; p.county = 31; p.val = 416;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 72; p.county = 31; p.val = 187;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 71; p.county = 31; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 71; p.county = 31; p.val = 608;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 71; p.county = 31; p.val = 735;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 75; p.county = 31; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 73; p.county = 31; p.val = 417;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 74; p.county = 31; p.val = 1262;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 73; p.county = 31; p.val = 605;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 74; p.county = 31; p.val = 521;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 75; p.county = 31; p.val = 1540;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 70; p.county = 31; p.val = 1315;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 71; p.county = 31; p.val = 339;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 68; p.county = 31; p.val = 731;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 67; p.county = 31; p.val = 445;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 67; p.county = 31; p.val = 891;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 71; p.county = 31; p.val = 429;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 74; p.county = 31; p.val = 868;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 76; p.county = 31; p.val = 558;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 70; p.county = 31; p.val = 591;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 71; p.county = 31; p.val = 1052;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 77; p.county = 31; p.val = 504;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 72; p.county = 31; p.val = 521;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 73; p.county = 31; p.val = 1272;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 72; p.county = 31; p.val = 740;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 75; p.county = 31; p.val = 925;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 74; p.county = 31; p.val = 1159;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 74; p.county = 31; p.val = 817;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 76; p.county = 33; p.val = 987;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 75; p.county = 33; p.val = 636;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 75; p.county = 33; p.val = 555;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 73; p.county = 33; p.val = 1206;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 74; p.county = 33; p.val = 106;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 75; p.county = 33; p.val = 174;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 72; p.county = 33; p.val = 654;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 72; p.county = 33; p.val = 236;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 75; p.county = 33; p.val = 855;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 73; p.county = 33; p.val = 139;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 76; p.county = 33; p.val = 91;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 77; p.county = 33; p.val = 361;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 78; p.county = 33; p.val = 447;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 80; p.county = 33; p.val = 121;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 77; p.county = 33; p.val = 335;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 79; p.county = 33; p.val = 115;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 72; p.county = 33; p.val = 417;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 74; p.county = 33; p.val = 152;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 72; p.county = 33; p.val = 347;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 71; p.county = 33; p.val = 259;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 38; p.county = 35; p.val = 698;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 35; p.county = 35; p.val = 363;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 34; p.county = 35; p.val = 530;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 33; p.county = 35; p.val = 460;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 35; p.county = 35; p.val = 545;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 35; p.county = 35; p.val = 343;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 36; p.county = 35; p.val = 597;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 33; p.county = 35; p.val = 576;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 30; p.county = 35; p.val = 778;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 29; p.county = 35; p.val = 746;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 28; p.county = 35; p.val = 1027;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 562;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 30; p.county = 35; p.val = 614;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 36; p.county = 35; p.val = 407;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 341;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 32; p.county = 35; p.val = 429;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 28; p.county = 35; p.val = 518;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 30; p.county = 35; p.val = 703;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 807;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 35; p.val = 1048;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 30; p.county = 35; p.val = 597;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 26; p.county = 35; p.val = 470;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 26; p.county = 35; p.val = 214;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 30; p.county = 35; p.val = 558;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 491;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 35; p.val = 544;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 35; p.val = 658;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 544;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 264;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 27; p.county = 35; p.val = 880;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 305;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 29; p.county = 35; p.val = 377;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 27; p.county = 35; p.val = 736;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 29; p.county = 35; p.val = 774;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 35; p.val = 1380;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 30; p.county = 35; p.val = 571;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 811;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 728;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 29; p.county = 35; p.val = 446;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 377;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 422;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 30; p.county = 35; p.val = 905;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 622;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 26; p.county = 35; p.val = 594;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 26; p.county = 35; p.val = 775;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 37; p.county = 35; p.val = 265;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 30; p.county = 35; p.val = 260;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 370;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 35; p.val = 1228;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 543;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 26; p.county = 35; p.val = 1344;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 35; p.val = 599;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 35; p.val = 357;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 583;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 30; p.county = 35; p.val = 1058;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 30; p.county = 35; p.val = 763;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 31; p.county = 35; p.val = 1190;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 29; p.county = 35; p.val = 1005;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 26; p.county = 35; p.val = 1096;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 35; p.val = 708;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 31; p.county = 35; p.val = 998;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 35; p.val = 882;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 204;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 483;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 30; p.county = 35; p.val = 669;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 31; p.county = 35; p.val = 645;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 29; p.county = 35; p.val = 601;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 35; p.val = 970;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 35; p.val = 397;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 30; p.county = 35; p.val = 673;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 32; p.county = 35; p.val = 380;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 35; p.val = 729;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 29; p.county = 35; p.val = 417;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 35; p.val = 560;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 29; p.county = 35; p.val = 317;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 35; p.val = 735;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 30; p.county = 35; p.val = 360;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 29; p.county = 35; p.val = 559;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 35; p.val = 675;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 35; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 56; p.county = 37; p.val = 520;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 54; p.county = 37; p.val = 843;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 56; p.county = 37; p.val = 685;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 57; p.county = 37; p.val = 732;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 53; p.county = 37; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 48; p.county = 37; p.val = 1504;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 53; p.county = 37; p.val = 598;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 55; p.county = 37; p.val = 527;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 59; p.county = 37; p.val = 299;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 58; p.county = 37; p.val = 330;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 50; p.county = 37; p.val = 1709;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 51; p.county = 37; p.val = 1021;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 80; p.county = 39; p.val = 40;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 76; p.county = 39; p.val = 286;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 71; p.county = 39; p.val = 184;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 79; p.county = 39; p.val = 195;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 71; p.county = 39; p.val = 1020;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 79; p.county = 39; p.val = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 70; p.county = 39; p.val = 390;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 71; p.county = 39; p.val = 195;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 73; p.county = 39; p.val = 556;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 75; p.county = 39; p.val = 452;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 78; p.county = 39; p.val = 503;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 74; p.county = 39; p.val = 330;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 78; p.county = 39; p.val = 52;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 72; p.county = 39; p.val = 1219;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 72; p.county = 39; p.val = 578;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 74; p.county = 39; p.val = 362;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 74; p.county = 39; p.val = 336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 74; p.county = 39; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 75; p.county = 39; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 77; p.county = 39; p.val = 178;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 78; p.county = 39; p.val = 89;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 75; p.county = 39; p.val = 919;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 71; p.county = 41; p.val = 280;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 70; p.county = 41; p.val = 379;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 65; p.county = 41; p.val = 480;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 68; p.county = 41; p.val = 2080;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 56; p.county = 41; p.val = 935;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 65; p.county = 41; p.val = 1127;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 64; p.county = 41; p.val = 623;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 68; p.county = 41; p.val = 330;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 68; p.county = 41; p.val = 1083;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 67; p.county = 41; p.val = 1417;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 61; p.county = 41; p.val = 453;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 62; p.county = 41; p.val = 436;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 67; p.county = 41; p.val = 1037;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 68; p.county = 41; p.val = 1036;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 67; p.county = 41; p.val = 1111;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 67; p.county = 41; p.val = 1414;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 59; p.county = 41; p.val = 279;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 68; p.county = 41; p.val = 750;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 64; p.county = 41; p.val = 405;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 64; p.county = 41; p.val = 914;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 69; p.county = 41; p.val = 623;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 68; p.county = 41; p.val = 926;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 68; p.county = 41; p.val = 519;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 68; p.county = 41; p.val = 195;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 69; p.county = 41; p.val = 614;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 69; p.county = 41; p.val = 289;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 68; p.county = 41; p.val = 472;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 68; p.county = 41; p.val = 440;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 68; p.county = 41; p.val = 477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 69; p.county = 41; p.val = 738;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 67; p.county = 41; p.val = 1167;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 67; p.county = 41; p.val = 1012;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 61; p.county = 41; p.val = 301;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 66; p.county = 41; p.val = 1041;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 59; p.county = 41; p.val = 409;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 57; p.county = 41; p.val = 692;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 57; p.county = 41; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 57; p.county = 41; p.val = 181;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 67; p.county = 41; p.val = 1147;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 70; p.county = 41; p.val = 835;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 59; p.county = 41; p.val = 396;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 63; p.county = 41; p.val = 354;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 63; p.county = 41; p.val = 606;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 60; p.county = 41; p.val = 782;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 58; p.county = 41; p.val = 537;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 58; p.county = 41; p.val = 693;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 57; p.county = 41; p.val = 765;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 62; p.county = 41; p.val = 599;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 61; p.county = 41; p.val = 356;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 57; p.county = 41; p.val = 196;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 70; p.county = 41; p.val = 564;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 61; p.county = 41; p.val = 296;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 66; p.county = 41; p.val = 1921;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 59; p.county = 41; p.val = 475;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 67; p.county = 41; p.val = 1165;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 66; p.county = 41; p.val = 945;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 65; p.county = 41; p.val = 905;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 67; p.county = 41; p.val = 758;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 56; p.county = 41; p.val = 330;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 69; p.county = 41; p.val = 1461;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 69; p.county = 41; p.val = 873;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 66; p.county = 41; p.val = 620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 69; p.county = 41; p.val = 621;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 44; p.county = 43; p.val = 875;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 44; p.county = 43; p.val = 522;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 43; p.county = 43; p.val = 491;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 44; p.county = 43; p.val = 827;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 45; p.county = 43; p.val = 1038;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 48; p.county = 43; p.val = 526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 41; p.county = 43; p.val = 473;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 42; p.county = 43; p.val = 513;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 42; p.county = 43; p.val = 279;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 45; p.county = 43; p.val = 1793;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 49; p.county = 43; p.val = 122;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 47; p.county = 43; p.val = 1451;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 47; p.county = 43; p.val = 930;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 40; p.county = 43; p.val = 297;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 53; p.county = 43; p.val = 526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 51; p.county = 43; p.val = 350;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 48; p.county = 43; p.val = 2039;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 47; p.county = 43; p.val = 1288;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 41; p.county = 43; p.val = 513;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 40; p.county = 43; p.val = 865;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 42; p.county = 43; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 48; p.county = 43; p.val = 305;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 40; p.county = 43; p.val = 270;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 45; p.county = 43; p.val = 407;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 51; p.county = 43; p.val = 503;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 46; p.county = 43; p.val = 395;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 41; p.county = 43; p.val = 549;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 36; p.county = 43; p.val = 634;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 42; p.county = 43; p.val = 816;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 39; p.county = 43; p.val = 490;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 45; p.county = 43; p.val = 1595;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 44; p.county = 43; p.val = 1599;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 39; p.county = 43; p.val = 1457;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 43; p.county = 43; p.val = 487;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 45; p.val = 1058;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 91; p.county = 45; p.val = 1480;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 45; p.val = 1240;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 87; p.county = 45; p.val = 730;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 88; p.county = 45; p.val = 1060;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 90; p.county = 45; p.val = 1034;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 85; p.county = 45; p.val = 1282;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 45; p.val = 1465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 90; p.county = 45; p.val = 215;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 90; p.county = 45; p.val = 921;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 89; p.county = 45; p.val = 1239;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 89; p.county = 45; p.val = 1325;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 91; p.county = 45; p.val = 1097;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 89; p.county = 45; p.val = 724;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 89; p.county = 45; p.val = 1426;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 89; p.county = 45; p.val = 1835;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 89; p.county = 45; p.val = 1073;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 90; p.county = 45; p.val = 434;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 89; p.county = 45; p.val = 1018;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 45; p.val = 886;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 89; p.county = 45; p.val = 968;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 88; p.county = 45; p.val = 1077;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 88; p.county = 45; p.val = 792;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 87; p.county = 45; p.val = 1209;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 89; p.county = 45; p.val = 816;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 87; p.county = 45; p.val = 1667;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 88; p.county = 45; p.val = 1244;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 91; p.county = 45; p.val = 1219;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 90; p.county = 45; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 93; p.county = 45; p.val = 821;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 93; p.county = 45; p.val = 1477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 89; p.county = 45; p.val = 1132;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 45; p.val = 1223;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 45; p.val = 670;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 88; p.county = 45; p.val = 636;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 90; p.county = 45; p.val = 1464;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 45; p.val = 496;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 89; p.county = 45; p.val = 1656;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 88; p.county = 45; p.val = 812;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 88; p.county = 45; p.val = 443;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 86; p.county = 45; p.val = 509;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 87; p.county = 45; p.val = 1299;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 89; p.county = 45; p.val = 1815;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 89; p.county = 45; p.val = 820;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 45; p.val = 947;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 92; p.county = 45; p.val = 1396;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 92; p.county = 45; p.val = 1232;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 88; p.county = 45; p.val = 830;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 91; p.county = 45; p.val = 646;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 87; p.county = 45; p.val = 1645;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 90; p.county = 45; p.val = 1324;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 88; p.county = 45; p.val = 1432;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 45; p.val = 937;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 88; p.county = 45; p.val = 1980;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 92; p.county = 45; p.val = 692;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 92; p.county = 45; p.val = 1204;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 91; p.county = 45; p.val = 1714;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 91; p.county = 45; p.val = 1267;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 93; p.county = 45; p.val = 1212;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 89; p.county = 45; p.val = 1690;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 89; p.county = 45; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 93; p.county = 45; p.val = 975;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 98; p.county = 45; p.val = 1027;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 93; p.county = 45; p.val = 1312;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 90; p.county = 45; p.val = 1189;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 90; p.county = 45; p.val = 703;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 80; p.county = 45; p.val = 1168;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 82; p.county = 45; p.val = 1080;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 91; p.county = 45; p.val = 1581;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 85; p.county = 45; p.val = 1842;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 84; p.county = 45; p.val = 723;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 92; p.county = 45; p.val = 1635;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 91; p.county = 45; p.val = 1108;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 99; p.county = 45; p.val = 1219;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 95; p.county = 45; p.val = 1247;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 92; p.county = 45; p.val = 1016;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 97; p.county = 45; p.val = 1058;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 88; p.county = 45; p.val = 1275;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 92; p.county = 45; p.val = 876;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 88; p.county = 45; p.val = 1067;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 90; p.county = 45; p.val = 813;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 85; p.county = 45; p.val = 2057;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 83; p.county = 45; p.val = 632;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 91; p.county = 45; p.val = 1432;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 84; p.county = 45; p.val = 1615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 84; p.county = 45; p.val = 1073;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 88; p.county = 45; p.val = 1579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 90; p.county = 45; p.val = 1278;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 89; p.county = 45; p.val = 1040;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 87; p.county = 45; p.val = 692;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 91; p.county = 45; p.val = 1463;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 91; p.county = 45; p.val = 1334;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 86; p.county = 45; p.val = 1336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 86; p.county = 45; p.val = 904;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 85; p.county = 45; p.val = 1123;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 88; p.county = 45; p.val = 1111;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 92; p.county = 45; p.val = 1118;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 92; p.county = 45; p.val = 1526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 91; p.county = 45; p.val = 1466;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 92; p.county = 45; p.val = 1147;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 89; p.county = 45; p.val = 1056;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 99; p.county = 45; p.val = 1494;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 89; p.county = 45; p.val = 1050;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 88; p.county = 45; p.val = 1056;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 90; p.county = 45; p.val = 1537;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 91; p.county = 45; p.val = 841;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 94; p.county = 45; p.val = 1904;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 86; p.county = 45; p.val = 1206;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 96; p.county = 45; p.val = 1407;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 86; p.county = 45; p.val = 1499;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 85; p.county = 45; p.val = 958;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 96; p.county = 45; p.val = 1449;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 92; p.county = 45; p.val = 1083;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 85; p.county = 45; p.val = 1453;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 90; p.county = 45; p.val = 1095;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 45; p.val = 1440;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 93; p.county = 45; p.val = 981;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 94; p.county = 45; p.val = 1370;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 45; p.val = 1091;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 89; p.county = 45; p.val = 884;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 45; p.val = 951;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 90; p.county = 45; p.val = 829;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 90; p.county = 45; p.val = 905;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 85; p.county = 45; p.val = 1279;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 87; p.county = 45; p.val = 718;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 84; p.county = 45; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 87; p.county = 45; p.val = 1060;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 94; p.county = 45; p.val = 1453;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 93; p.county = 45; p.val = 1097;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 93; p.county = 45; p.val = 1003;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 91; p.county = 45; p.val = 1569;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 87; p.county = 45; p.val = 950;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 87; p.county = 45; p.val = 1044;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 87; p.county = 45; p.val = 1442;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 88; p.county = 45; p.val = 853;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 88; p.county = 45; p.val = 1383;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 93; p.county = 45; p.val = 890;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 85; p.county = 45; p.val = 968;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 85; p.county = 45; p.val = 1905;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 95; p.county = 45; p.val = 1615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 86; p.county = 45; p.val = 1426;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 91; p.county = 45; p.val = 1279;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 88; p.county = 45; p.val = 1308;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 86; p.county = 45; p.val = 969;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 93; p.county = 45; p.val = 1440;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 94; p.county = 45; p.val = 847;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 93; p.county = 45; p.val = 682;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 84; p.county = 45; p.val = 1280;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 82; p.county = 45; p.val = 1085;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 88; p.county = 45; p.val = 1476;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 87; p.county = 45; p.val = 2672;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 68; p.county = 47; p.val = 297;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 68; p.county = 47; p.val = 426;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 69; p.county = 47; p.val = 619;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 67; p.county = 47; p.val = 358;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 68; p.county = 47; p.val = 482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 73; p.county = 47; p.val = 186;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 69; p.county = 47; p.val = 585;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 68; p.county = 47; p.val = 230;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 65; p.county = 47; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 68; p.county = 47; p.val = 434;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 68; p.county = 47; p.val = 331;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 68; p.county = 47; p.val = 443;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 69; p.county = 47; p.val = 392;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 71; p.county = 47; p.val = 707;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 66; p.county = 47; p.val = 663;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 69; p.county = 47; p.val = 517;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 68; p.county = 47; p.val = 483;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 67; p.county = 47; p.val = 420;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 63; p.county = 47; p.val = 362;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 63; p.county = 47; p.val = 499;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 65; p.county = 47; p.val = 351;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 74; p.county = 47; p.val = 300;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 73; p.county = 47; p.val = 117;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 71; p.county = 47; p.val = 752;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 64; p.county = 47; p.val = 147;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 63; p.county = 47; p.val = 102;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 71; p.county = 47; p.val = 538;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 69; p.county = 47; p.val = 330;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 70; p.county = 47; p.val = 499;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 68; p.county = 47; p.val = 479;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 70; p.county = 47; p.val = 617;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 69; p.county = 47; p.val = 587;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 68; p.county = 47; p.val = 426;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 70; p.county = 47; p.val = 598;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 69; p.county = 47; p.val = 416;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 69; p.county = 47; p.val = 751;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 69; p.county = 47; p.val = 490;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 68; p.county = 47; p.val = 466;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 70; p.county = 47; p.val = 583;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 74; p.county = 47; p.val = 440;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 67; p.county = 47; p.val = 412;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 69; p.county = 47; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 68; p.county = 47; p.val = 210;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 69; p.county = 47; p.val = 843;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 67; p.county = 47; p.val = 384;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 67; p.county = 47; p.val = 485;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 69; p.county = 47; p.val = 446;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 69; p.county = 47; p.val = 454;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 67; p.county = 47; p.val = 749;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 70; p.county = 47; p.val = 500;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 27; p.county = 49; p.val = 332;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 26; p.county = 49; p.val = 464;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 25; p.county = 49; p.val = 682;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 24; p.county = 49; p.val = 993;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 20; p.county = 49; p.val = 224;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 17; p.county = 49; p.val = 116;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 20; p.county = 49; p.val = 899;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 21; p.county = 49; p.val = 445;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 19; p.county = 49; p.val = 235;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 18; p.county = 49; p.val = 215;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 19; p.county = 49; p.val = 648;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 21; p.county = 49; p.val = 64;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 29; p.county = 49; p.val = 48;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 23; p.county = 49; p.val = 155;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 27; p.county = 49; p.val = 285;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 23; p.county = 49; p.val = 435;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 24; p.county = 49; p.val = 144;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 25; p.county = 49; p.val = 225;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 60; p.county = 51; p.val = 845;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 62; p.county = 51; p.val = 350;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 55; p.county = 51; p.val = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 55; p.county = 51; p.val = 789;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 56; p.county = 51; p.val = 418;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 61; p.county = 51; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 57; p.county = 51; p.val = 614;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 58; p.county = 51; p.val = 878;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 58; p.county = 51; p.val = 737;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 56; p.county = 51; p.val = 1481;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 51; p.county = 51; p.val = 898;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 59; p.county = 51; p.val = 809;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 60; p.county = 51; p.val = 291;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 62; p.county = 51; p.val = 857;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 63; p.county = 51; p.val = 650;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 61; p.county = 51; p.val = 230;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 61; p.county = 51; p.val = 464;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 64; p.county = 51; p.val = 94;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 59; p.county = 51; p.val = 590;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 58; p.county = 51; p.val = 259;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 63; p.county = 51; p.val = 219;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 57; p.county = 51; p.val = 863;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 63; p.county = 51; p.val = 391;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 59; p.county = 51; p.val = 1676;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 58; p.county = 51; p.val = 898;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 58; p.county = 51; p.val = 1521;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 51; p.val = 1320;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 51; p.val = 1949;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 54; p.county = 51; p.val = 1341;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 55; p.county = 51; p.val = 983;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 56; p.county = 51; p.val = 965;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 57; p.county = 51; p.val = 1247;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 55; p.county = 51; p.val = 860;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 58; p.county = 51; p.val = 1265;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 55; p.county = 51; p.val = 646;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 57; p.county = 51; p.val = 724;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 52; p.county = 51; p.val = 199;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 52; p.county = 51; p.val = 430;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 52; p.county = 51; p.val = 492;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 50; p.county = 51; p.val = 1348;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 57; p.county = 51; p.val = 720;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 54; p.county = 51; p.val = 1794;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 54; p.county = 51; p.val = 1143;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 55; p.county = 51; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 64; p.county = 51; p.val = 1296;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 60; p.county = 51; p.val = 1199;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 64; p.county = 51; p.val = 96;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 65; p.county = 51; p.val = 361;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 59; p.county = 51; p.val = 882;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 54; p.county = 51; p.val = 1060;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 66; p.county = 51; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 68; p.county = 51; p.val = 406;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 53; p.county = 51; p.val = 1846;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 53; p.county = 51; p.val = 1637;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 54; p.county = 51; p.val = 1350;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 51; p.county = 51; p.val = 1829;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 51; p.county = 51; p.val = 2322;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 51; p.val = 1093;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 51; p.val = 775;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 51; p.val = 638;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 49; p.county = 51; p.val = 968;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 49; p.county = 51; p.val = 1110;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 54; p.county = 51; p.val = 309;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 51; p.county = 51; p.val = 873;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 63; p.county = 51; p.val = 394;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 51; p.county = 51; p.val = 1192;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 55; p.county = 51; p.val = 708;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 52; p.county = 51; p.val = 870;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 53; p.county = 51; p.val = 1011;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 58; p.county = 51; p.val = 924;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 57; p.county = 51; p.val = 1420;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 57; p.county = 51; p.val = 778;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 57; p.county = 51; p.val = 636;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 55; p.county = 51; p.val = 1187;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 56; p.county = 51; p.val = 1843;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 53; p.county = 51; p.val = 886;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 53; p.county = 51; p.val = 917;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 54; p.county = 51; p.val = 477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 54; p.county = 51; p.val = 1806;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 53; p.county = 51; p.val = 251;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 65; p.county = 51; p.val = 129;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 61; p.county = 51; p.val = 405;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 51; p.county = 51; p.val = 386;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 57; p.county = 51; p.val = 578;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 56; p.county = 51; p.val = 599;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 59; p.county = 51; p.val = 497;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 55; p.county = 51; p.val = 426;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 54; p.county = 51; p.val = 1171;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 56; p.county = 51; p.val = 1149;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 51; p.county = 51; p.val = 668;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 52; p.county = 51; p.val = 618;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 59; p.county = 51; p.val = 699;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 52; p.county = 51; p.val = 1349;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 70; p.county = 51; p.val = 201;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 50; p.county = 51; p.val = 1257;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 50; p.county = 51; p.val = 1343;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 62; p.county = 51; p.val = 536;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 66; p.county = 51; p.val = 164;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 56; p.county = 51; p.val = 830;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 54; p.county = 51; p.val = 767;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 57; p.county = 51; p.val = 912;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 56; p.county = 51; p.val = 350;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 64; p.county = 51; p.val = 411;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 60; p.county = 51; p.val = 338;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 56; p.county = 51; p.val = 1396;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 55; p.county = 51; p.val = 731;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 51; p.val = 1891;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 59; p.county = 51; p.val = 695;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 54; p.county = 51; p.val = 1140;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 58; p.county = 51; p.val = 1043;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 54; p.county = 51; p.val = 1226;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 51; p.county = 51; p.val = 603;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 51; p.county = 51; p.val = 837;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 48; p.county = 51; p.val = 1952;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 50; p.county = 51; p.val = 1009;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 52; p.county = 51; p.val = 608;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 50; p.county = 51; p.val = 1819;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 50; p.county = 51; p.val = 948;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 52; p.county = 51; p.val = 718;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 52; p.county = 51; p.val = 1798;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 52; p.county = 51; p.val = 1634;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 56; p.county = 51; p.val = 1482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 49; p.county = 51; p.val = 1234;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 49; p.county = 51; p.val = 646;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 16; p.county = 53; p.val = 281;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 16; p.county = 53; p.val = 345;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 11; p.county = 53; p.val = 635;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 13; p.county = 53; p.val = 1045;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 19; p.county = 53; p.val = 454;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 7; p.county = 53; p.val = 805;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 7; p.county = 53; p.val = 422;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 1; p.county = 53; p.val = 972;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 9; p.county = 53; p.val = 666;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 15; p.county = 53; p.val = 395;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 13; p.county = 53; p.val = 471;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 11; p.county = 53; p.val = 475;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 11; p.county = 53; p.val = 374;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 14; p.county = 53; p.val = 386;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 7; p.county = 53; p.val = 1622;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 71; p.county = 55; p.val = 595;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 70; p.county = 55; p.val = 458;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 76; p.county = 55; p.val = 744;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 80; p.county = 55; p.val = 549;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 69; p.county = 55; p.val = 799;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 70; p.county = 55; p.val = 176;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 70; p.county = 55; p.val = 736;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 71; p.county = 55; p.val = 492;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 73; p.county = 55; p.val = 714;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 68; p.county = 55; p.val = 802;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 70; p.county = 55; p.val = 262;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 68; p.county = 55; p.val = 1000;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 68; p.county = 55; p.val = 1029;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 68; p.county = 55; p.val = 750;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 71; p.county = 55; p.val = 334;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 70; p.county = 55; p.val = 250;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 66; p.county = 55; p.val = 961;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 67; p.county = 55; p.val = 1335;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 67; p.county = 55; p.val = 718;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 68; p.county = 55; p.val = 640;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 77; p.county = 55; p.val = 209;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 77; p.county = 55; p.val = 364;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 70; p.county = 55; p.val = 588;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 69; p.county = 55; p.val = 931;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 69; p.county = 55; p.val = 936;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 68; p.county = 55; p.val = 792;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 72; p.county = 55; p.val = 782;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 72; p.county = 55; p.val = 1160;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 70; p.county = 55; p.val = 423;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 71; p.county = 55; p.val = 786;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 75; p.county = 55; p.val = 507;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 72; p.county = 55; p.val = 951;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 76; p.county = 55; p.val = 838;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 70; p.county = 55; p.val = 858;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 85; p.county = 57; p.val = 482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 92; p.county = 57; p.val = 1594;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 86; p.county = 57; p.val = 471;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 80; p.county = 57; p.val = 295;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 83; p.county = 57; p.val = 957;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 80; p.county = 57; p.val = 683;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 85; p.county = 57; p.val = 765;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 80; p.county = 57; p.val = 817;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 79; p.county = 57; p.val = 835;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 86; p.county = 57; p.val = 402;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 84; p.county = 57; p.val = 1101;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 85; p.county = 57; p.val = 517;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 85; p.county = 57; p.val = 724;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 85; p.county = 57; p.val = 719;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 86; p.county = 57; p.val = 980;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 88; p.county = 57; p.val = 538;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 84; p.county = 57; p.val = 848;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 86; p.county = 57; p.val = 654;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 83; p.county = 57; p.val = 380;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 82; p.county = 57; p.val = 674;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 95; p.county = 57; p.val = 1732;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 84; p.county = 57; p.val = 566;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 86; p.county = 57; p.val = 440;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 87; p.county = 57; p.val = 625;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 88; p.county = 57; p.val = 715;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 89; p.county = 57; p.val = 555;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 94; p.county = 57; p.val = 1491;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 85; p.county = 57; p.val = 658;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 93; p.county = 57; p.val = 1100;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 94; p.county = 57; p.val = 1839;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 91; p.county = 57; p.val = 666;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 96; p.county = 57; p.val = 1815;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 91; p.county = 57; p.val = 2038;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 93; p.county = 57; p.val = 1378;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 92; p.county = 57; p.val = 2100;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 86; p.county = 57; p.val = 697;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 78; p.county = 59; p.val = 320;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 78; p.county = 59; p.val = 220;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 78; p.county = 59; p.val = 309;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 78; p.county = 59; p.val = 384;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 78; p.county = 59; p.val = 749;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 78; p.county = 59; p.val = 593;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 77; p.county = 59; p.val = 518;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 78; p.county = 59; p.val = 792;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 79; p.county = 59; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 80; p.county = 59; p.val = 494;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 77; p.county = 59; p.val = 621;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 77; p.county = 59; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 75; p.county = 59; p.val = 853;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 77; p.county = 59; p.val = 540;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 74; p.county = 59; p.val = 343;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 75; p.county = 59; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 84; p.county = 59; p.val = 799;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 83; p.county = 59; p.val = 400;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 81; p.county = 59; p.val = 684;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 81; p.county = 59; p.val = 913;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 85; p.county = 59; p.val = 1109;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 84; p.county = 59; p.val = 578;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 82; p.county = 59; p.val = 506;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 80; p.county = 59; p.val = 642;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 71; p.county = 59; p.val = 912;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 73; p.county = 59; p.val = 889;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 76; p.county = 59; p.val = 361;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 75; p.county = 59; p.val = 290;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 73; p.county = 59; p.val = 515;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 79; p.county = 59; p.val = 1171;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 78; p.county = 59; p.val = 145;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 77; p.county = 59; p.val = 262;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 78; p.county = 59; p.val = 579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 79; p.county = 59; p.val = 651;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 72; p.county = 61; p.val = 265;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 65; p.county = 61; p.val = 353;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 68; p.county = 61; p.val = 355;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 69; p.county = 61; p.val = 386;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 70; p.county = 61; p.val = 507;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 70; p.county = 61; p.val = 180;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 69; p.county = 61; p.val = 277;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 65; p.county = 61; p.val = 298;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 68; p.county = 61; p.val = 188;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 69; p.county = 61; p.val = 311;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 64; p.county = 61; p.val = 422;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 67; p.county = 61; p.val = 322;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 67; p.county = 61; p.val = 162;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 67; p.county = 61; p.val = 205;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 71; p.county = 61; p.val = 279;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 62; p.county = 61; p.val = 236;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 66; p.county = 61; p.val = 387;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 64; p.county = 61; p.val = 494;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 71; p.county = 61; p.val = 111;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 73; p.county = 61; p.val = 82;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 65; p.county = 61; p.val = 107;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 69; p.county = 61; p.val = 437;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 59; p.county = 63; p.val = 1059;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 57; p.county = 63; p.val = 737;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 63; p.county = 63; p.val = 1330;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 62; p.county = 63; p.val = 1286;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 59; p.county = 63; p.val = 1320;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 61; p.county = 63; p.val = 481;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 63; p.val = 1341;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 60; p.county = 63; p.val = 815;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 63; p.county = 63; p.val = 1467;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 58; p.county = 63; p.val = 1128;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 60; p.county = 63; p.val = 1740;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 52; p.county = 63; p.val = 430;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 54; p.county = 63; p.val = 535;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 62; p.county = 63; p.val = 1100;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 60; p.county = 63; p.val = 1116;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 61; p.county = 63; p.val = 1347;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 53; p.county = 63; p.val = 691;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 56; p.county = 63; p.val = 670;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 61; p.county = 63; p.val = 805;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 57; p.county = 63; p.val = 976;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 59; p.county = 63; p.val = 752;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 54; p.county = 63; p.val = 665;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 55; p.county = 63; p.val = 843;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 64; p.county = 63; p.val = 890;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 59; p.county = 63; p.val = 1038;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 59; p.county = 63; p.val = 1581;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 62; p.county = 63; p.val = 810;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 60; p.county = 63; p.val = 1090;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 57; p.county = 63; p.val = 497;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 62; p.county = 63; p.val = 1152;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 60; p.county = 63; p.val = 799;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 55; p.county = 63; p.val = 652;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 67; p.county = 63; p.val = 1646;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 62; p.county = 63; p.val = 580;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 60; p.county = 63; p.val = 1345;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 62; p.county = 63; p.val = 1526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 61; p.county = 63; p.val = 938;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 58; p.county = 63; p.val = 1459;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 58; p.county = 63; p.val = 907;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 62; p.county = 63; p.val = 1010;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 59; p.county = 63; p.val = 774;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 61; p.county = 63; p.val = 436;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 61; p.county = 63; p.val = 842;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 64; p.county = 63; p.val = 1386;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 64; p.county = 63; p.val = 1301;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 60; p.county = 63; p.val = 703;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 65; p.county = 63; p.val = 2017;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 60; p.county = 63; p.val = 1227;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 62; p.county = 63; p.val = 794;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 63; p.county = 63; p.val = 1565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 63; p.val = 1427;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 61; p.county = 63; p.val = 1586;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 63; p.val = 1055;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 60; p.county = 63; p.val = 400;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 56; p.county = 63; p.val = 729;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 59; p.county = 63; p.val = 628;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 57; p.county = 63; p.val = 661;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 57; p.county = 63; p.val = 784;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 53; p.county = 63; p.val = 693;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 54; p.county = 63; p.val = 705;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 66; p.county = 63; p.val = 1024;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 60; p.county = 63; p.val = 966;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 58; p.county = 63; p.val = 1058;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 59; p.county = 63; p.val = 897;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 58; p.county = 63; p.val = 744;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 58; p.county = 63; p.val = 1311;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 63; p.val = 663;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 62; p.county = 63; p.val = 1002;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 62; p.county = 63; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 61; p.county = 63; p.val = 1204;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 63; p.county = 63; p.val = 1003;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 56; p.county = 63; p.val = 675;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 62; p.county = 63; p.val = 339;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 65; p.county = 63; p.val = 1158;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 64; p.county = 63; p.val = 920;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 63; p.county = 63; p.val = 942;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 63; p.county = 63; p.val = 760;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 61; p.county = 63; p.val = 1040;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 62; p.county = 63; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 61; p.county = 63; p.val = 800;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 64; p.county = 63; p.val = 1170;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 64; p.county = 63; p.val = 1228;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 64; p.county = 63; p.val = 1443;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 62; p.county = 63; p.val = 1508;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 61; p.county = 63; p.val = 1581;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 60; p.county = 63; p.val = 1682;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 63; p.county = 63; p.val = 1528;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 64; p.county = 63; p.val = 915;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 65; p.county = 63; p.val = 1375;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 65; p.county = 63; p.val = 1777;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 61; p.county = 63; p.val = 979;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 63; p.county = 63; p.val = 808;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 62; p.county = 63; p.val = 1644;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 61; p.county = 63; p.val = 1541;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 65; p.county = 63; p.val = 1257;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 58; p.county = 63; p.val = 970;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 62; p.county = 65; p.val = 207;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 59; p.county = 65; p.val = 339;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 59; p.county = 65; p.val = 1114;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 62; p.county = 65; p.val = 124;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 61; p.county = 65; p.val = 606;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 60; p.county = 65; p.val = 280;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 58; p.county = 65; p.val = 483;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 57; p.county = 65; p.val = 518;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 55; p.county = 65; p.val = 150;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 53; p.county = 65; p.val = 234;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 51; p.county = 65; p.val = 375;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 57; p.county = 67; p.val = 782;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 62; p.county = 67; p.val = 203;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 64; p.county = 67; p.val = 685;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 65; p.county = 67; p.val = 397;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 68; p.county = 67; p.val = 748;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 69; p.county = 67; p.val = 722;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 67; p.county = 67; p.val = 1209;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 67; p.county = 67; p.val = 636;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 70; p.county = 67; p.val = 144;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 71; p.county = 67; p.val = 511;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 70; p.county = 67; p.val = 337;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 69; p.county = 67; p.val = 687;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 67; p.county = 67; p.val = 765;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 69; p.county = 67; p.val = 887;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 67; p.county = 67; p.val = 707;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 70; p.county = 67; p.val = 390;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 68; p.county = 67; p.val = 603;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 85; p.county = 69; p.val = 285;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 78; p.county = 69; p.val = 192;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 86; p.county = 69; p.val = 447;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 75; p.county = 69; p.val = 208;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 79; p.county = 69; p.val = 563;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 83; p.county = 69; p.val = 249;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 87; p.county = 69; p.val = 759;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 85; p.county = 69; p.val = 554;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 80; p.county = 69; p.val = 816;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 81; p.county = 69; p.val = 610;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 81; p.county = 69; p.val = 650;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 82; p.county = 69; p.val = 336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 83; p.county = 69; p.val = 1108;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 84; p.county = 69; p.val = 403;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 83; p.county = 69; p.val = 580;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 71; p.county = 71; p.val = 201;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 71; p.county = 71; p.val = 567;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 71; p.county = 71; p.val = 398;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 71; p.county = 71; p.val = 264;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 71; p.county = 71; p.val = 263;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 71; p.county = 71; p.val = 538;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 73; p.county = 71; p.val = 318;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 72; p.county = 71; p.val = 170;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 69; p.county = 71; p.val = 397;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 68; p.county = 71; p.val = 521;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 71; p.county = 71; p.val = 450;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 74; p.county = 71; p.val = 266;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 70; p.county = 71; p.val = 277;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 73; p.county = 71; p.val = 623;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 73; p.county = 71; p.val = 610;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 66; p.county = 71; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 66; p.county = 71; p.val = 1057;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 69; p.county = 71; p.val = 843;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 77; p.county = 71; p.val = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 72; p.county = 71; p.val = 321;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 69; p.county = 71; p.val = 92;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 70; p.county = 71; p.val = 351;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 69; p.county = 71; p.val = 454;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 69; p.county = 71; p.val = 415;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 67; p.county = 71; p.val = 501;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 72; p.county = 71; p.val = 590;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 67; p.county = 71; p.val = 329;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 78; p.county = 71; p.val = 445;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 76; p.county = 71; p.val = 434;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 69; p.county = 71; p.val = 440;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 85; p.county = 73; p.val = 136;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 80; p.county = 73; p.val = 554;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 85; p.county = 73; p.val = 1499;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 78; p.county = 73; p.val = 637;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 82; p.county = 73; p.val = 1107;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 85; p.county = 73; p.val = 240;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 88; p.county = 73; p.val = 1076;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 87; p.county = 73; p.val = 261;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 91; p.county = 73; p.val = 630;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 83; p.county = 73; p.val = 379;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 85; p.county = 73; p.val = 1008;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 81; p.county = 73; p.val = 776;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 82; p.county = 73; p.val = 515;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 84; p.county = 73; p.val = 666;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 93; p.county = 73; p.val = 1171;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 89; p.county = 73; p.val = 1437;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 87; p.county = 73; p.val = 1296;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 83; p.county = 73; p.val = 711;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 80; p.county = 73; p.val = 923;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 92; p.county = 73; p.val = 812;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 81; p.county = 73; p.val = 714;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 84; p.county = 73; p.val = 329;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 88; p.county = 73; p.val = 1657;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 87; p.county = 73; p.val = 1122;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 82; p.county = 73; p.val = 1493;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 85; p.county = 73; p.val = 792;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 86; p.county = 73; p.val = 996;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 84; p.county = 73; p.val = 1520;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 85; p.county = 73; p.val = 997;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 83; p.county = 73; p.val = 749;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 84; p.county = 73; p.val = 1341;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 45; p.county = 75; p.val = 324;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 45; p.county = 75; p.val = 216;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 45; p.county = 75; p.val = 498;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 45; p.county = 75; p.val = 452;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 46; p.county = 75; p.val = 221;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 46; p.county = 75; p.val = 336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 45; p.county = 75; p.val = 327;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 44; p.county = 75; p.val = 677;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 44; p.county = 75; p.val = 228;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 45; p.county = 75; p.val = 410;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 46; p.county = 75; p.val = 839;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 39; p.county = 75; p.val = 433;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 46; p.county = 75; p.val = 442;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 46; p.county = 75; p.val = 324;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 44; p.county = 75; p.val = 602;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 47; p.county = 75; p.val = 468;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 46; p.county = 75; p.val = 312;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 46; p.county = 75; p.val = 284;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 46; p.county = 75; p.val = 458;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 47; p.county = 75; p.val = 709;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 43; p.county = 75; p.val = 348;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 41; p.county = 75; p.val = 685;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 38; p.county = 75; p.val = 587;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 36; p.county = 75; p.val = 286;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 42; p.county = 75; p.val = 383;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 44; p.county = 75; p.val = 789;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 41; p.county = 75; p.val = 569;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 45; p.county = 75; p.val = 400;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 43; p.county = 75; p.val = 819;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 39; p.county = 75; p.val = 895;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 47; p.county = 75; p.val = 698;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 41; p.county = 75; p.val = 1055;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 45; p.county = 75; p.val = 310;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 40; p.county = 75; p.val = 1025;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 48; p.county = 75; p.val = 935;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 47; p.county = 75; p.val = 1205;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 47; p.county = 75; p.val = 556;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 46; p.county = 75; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 50; p.county = 75; p.val = 750;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 49; p.county = 75; p.val = 722;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 44; p.county = 75; p.val = 780;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 45; p.county = 75; p.val = 682;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 43; p.county = 75; p.val = 658;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 46; p.county = 75; p.val = 805;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 44; p.county = 75; p.val = 656;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 46; p.county = 75; p.val = 661;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 43; p.county = 75; p.val = 954;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 45; p.county = 75; p.val = 571;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 48; p.county = 75; p.val = 526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 47; p.county = 75; p.val = 614;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 43; p.county = 75; p.val = 704;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 47; p.county = 75; p.val = 507;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 41; p.county = 75; p.val = 337;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 83; p.county = 77; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 84; p.county = 77; p.val = 376;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 84; p.county = 77; p.val = 667;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 84; p.county = 77; p.val = 421;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 85; p.county = 77; p.val = 489;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 84; p.county = 77; p.val = 1121;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 85; p.county = 77; p.val = 476;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 85; p.county = 77; p.val = 336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 86; p.county = 77; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 87; p.county = 77; p.val = 752;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 87; p.county = 77; p.val = 648;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 90; p.county = 77; p.val = 541;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 85; p.county = 77; p.val = 578;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 88; p.county = 77; p.val = 827;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 90; p.county = 77; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 91; p.county = 77; p.val = 720;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 90; p.county = 77; p.val = 689;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 89; p.county = 77; p.val = 833;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 89; p.county = 77; p.val = 494;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 95; p.county = 77; p.val = 871;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 95; p.county = 77; p.val = 908;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 93; p.county = 77; p.val = 874;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 92; p.county = 77; p.val = 687;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 90; p.county = 77; p.val = 686;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 91; p.county = 77; p.val = 625;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 88; p.county = 77; p.val = 660;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 87; p.county = 77; p.val = 706;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 88; p.county = 77; p.val = 589;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 86; p.county = 77; p.val = 708;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 88; p.county = 77; p.val = 595;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 89; p.county = 77; p.val = 505;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 88; p.county = 77; p.val = 915;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 90; p.county = 77; p.val = 560;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 90; p.county = 77; p.val = 693;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 89; p.county = 77; p.val = 724;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 90; p.county = 77; p.val = 756;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 89; p.county = 77; p.val = 639;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 88; p.county = 77; p.val = 738;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 88; p.county = 77; p.val = 838;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 88; p.county = 77; p.val = 413;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 89; p.county = 77; p.val = 430;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 89; p.county = 77; p.val = 567;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 88; p.county = 77; p.val = 757;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 89; p.county = 77; p.val = 582;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 89; p.county = 77; p.val = 611;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 89; p.county = 77; p.val = 607;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 90; p.county = 77; p.val = 645;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 90; p.county = 77; p.val = 647;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 92; p.county = 77; p.val = 568;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 92; p.county = 77; p.val = 424;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 94; p.county = 77; p.val = 627;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 85; p.county = 77; p.val = 508;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 92; p.county = 77; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 88; p.county = 77; p.val = 537;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 87; p.county = 77; p.val = 517;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 89; p.county = 77; p.val = 392;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 88; p.county = 77; p.val = 827;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 88; p.county = 77; p.val = 364;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 88; p.county = 77; p.val = 576;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 90; p.county = 77; p.val = 496;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 88; p.county = 77; p.val = 472;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 626;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 319;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 898;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 755;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 819;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 789;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 65; p.county = 79; p.val = 584;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 900;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 63; p.county = 79; p.val = 716;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 64; p.county = 79; p.val = 1249;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 328;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 906;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 490;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 302;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 66; p.county = 79; p.val = 858;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 430;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 491;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 67; p.county = 79; p.val = 1097;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 981;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 66; p.county = 79; p.val = 867;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 67; p.county = 79; p.val = 730;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 61; p.county = 79; p.val = 726;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 61; p.county = 79; p.val = 1373;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 60; p.county = 79; p.val = 1077;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 937;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 62; p.county = 79; p.val = 1122;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 79; p.val = 686;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 60; p.county = 79; p.val = 802;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 62; p.county = 79; p.val = 963;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 64; p.county = 79; p.val = 714;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 58; p.county = 79; p.val = 750;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 62; p.county = 79; p.val = 1140;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 61; p.county = 79; p.val = 943;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 617;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 79; p.val = 1338;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 65; p.county = 79; p.val = 734;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 1004;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 810;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 293;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 61; p.county = 79; p.val = 1020;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 62; p.county = 79; p.val = 665;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 64; p.county = 79; p.val = 650;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 64; p.county = 79; p.val = 390;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 59; p.county = 79; p.val = 850;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 62; p.county = 79; p.val = 1151;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 62; p.county = 79; p.val = 482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 63; p.county = 79; p.val = 948;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 61; p.county = 79; p.val = 1050;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 425;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 79; p.val = 865;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 697;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 66; p.county = 79; p.val = 1078;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 67; p.county = 79; p.val = 1293;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 66; p.county = 79; p.val = 964;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 56; p.county = 79; p.val = 844;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 64; p.county = 79; p.val = 1520;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 69; p.county = 79; p.val = 1168;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 68; p.county = 79; p.val = 2762;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 67; p.county = 79; p.val = 1004;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 69; p.county = 79; p.val = 1451;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 68; p.county = 79; p.val = 1494;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 66; p.county = 79; p.val = 1504;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 79; p.val = 684;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 67; p.county = 79; p.val = 1775;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 56; p.county = 79; p.val = 747;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 66; p.county = 79; p.val = 796;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 67; p.county = 79; p.val = 1278;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 796;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 79; p.val = 884;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 64; p.county = 79; p.val = 575;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 61; p.county = 79; p.val = 888;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 64; p.county = 79; p.val = 994;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 67; p.county = 79; p.val = 1527;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 79; p.val = 767;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 64; p.county = 79; p.val = 973;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 64; p.county = 79; p.val = 453;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 62; p.county = 79; p.val = 499;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 61; p.county = 79; p.val = 1146;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 67; p.county = 79; p.val = 475;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 62; p.county = 79; p.val = 1040;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 65; p.county = 79; p.val = 844;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 65; p.county = 79; p.val = 791;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 63; p.county = 79; p.val = 1034;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 61; p.county = 79; p.val = 1080;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 65; p.county = 79; p.val = 1122;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 65; p.county = 79; p.val = 1082;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 60; p.county = 79; p.val = 284;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 65; p.county = 79; p.val = 683;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 1054;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 69; p.county = 79; p.val = 1125;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 67; p.county = 79; p.val = 1275;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 68; p.county = 79; p.val = 1757;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 65; p.county = 79; p.val = 1101;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 79; p.val = 1025;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 61; p.county = 79; p.val = 1042;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 60; p.county = 79; p.val = 682;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 65; p.county = 79; p.val = 1435;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 60; p.county = 79; p.val = 466;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 66; p.county = 79; p.val = 1604;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 66; p.county = 79; p.val = 1172;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 619;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 65; p.county = 79; p.val = 387;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 79; p.val = 1340;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 67; p.county = 79; p.val = 1354;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 67; p.county = 79; p.val = 1106;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 61; p.county = 79; p.val = 980;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 64; p.county = 79; p.val = 879;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 61; p.county = 79; p.val = 566;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 61; p.county = 79; p.val = 792;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 65; p.county = 79; p.val = 1287;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 65; p.county = 79; p.val = 1338;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 66; p.county = 79; p.val = 988;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 79; p.val = 1480;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 67; p.county = 79; p.val = 1307;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 67; p.county = 79; p.val = 1592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 64; p.county = 79; p.val = 374;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 539;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 79; p.val = 772;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 79; p.val = 944;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 65; p.county = 79; p.val = 1684;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 69; p.county = 79; p.val = 464;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 632;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 79; p.val = 1709;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 79; p.val = 1010;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 62; p.county = 79; p.val = 538;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 61; p.county = 79; p.val = 711;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 68; p.county = 79; p.val = 1399;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 79; p.val = 1559;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 79; p.val = 1493;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 66; p.county = 79; p.val = 1271;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 66; p.county = 79; p.val = 1123;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 64; p.county = 79; p.val = 657;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 61; p.county = 79; p.val = 725;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 66; p.county = 79; p.val = 1697;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 64; p.county = 79; p.val = 469;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 59; p.county = 79; p.val = 614;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 79; p.val = 744;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 63; p.county = 79; p.val = 739;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 65; p.county = 79; p.val = 1557;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 64; p.county = 79; p.val = 1256;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 61; p.county = 79; p.val = 1578;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 62; p.county = 79; p.val = 832;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 61; p.county = 79; p.val = 969;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 79; p.val = 898;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 79; p.val = 866;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 66; p.county = 79; p.val = 1370;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 65; p.county = 81; p.val = 283;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 61; p.county = 81; p.val = 163;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 62; p.county = 81; p.val = 259;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 66; p.county = 81; p.val = 363;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 64; p.county = 81; p.val = 591;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 60; p.county = 81; p.val = 536;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 64; p.county = 81; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 61; p.county = 81; p.val = 561;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 61; p.county = 81; p.val = 397;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 62; p.county = 81; p.val = 270;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 58; p.county = 81; p.val = 124;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 65; p.county = 81; p.val = 768;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 59; p.county = 81; p.val = 322;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 57; p.county = 81; p.val = 472;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 62; p.county = 81; p.val = 145;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 62; p.county = 81; p.val = 579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 62; p.county = 81; p.val = 336;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 58; p.county = 81; p.val = 238;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 87; p.county = 83; p.val = 503;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 93; p.county = 83; p.val = 397;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 93; p.county = 83; p.val = 1745;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 90; p.county = 83; p.val = 1626;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 99; p.county = 83; p.val = 1119;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 94; p.county = 83; p.val = 445;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 95; p.county = 83; p.val = 891;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 88; p.county = 83; p.val = 695;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 93; p.county = 83; p.val = 708;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 97; p.county = 83; p.val = 849;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 88; p.county = 83; p.val = 982;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 89; p.county = 83; p.val = 581;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 90; p.county = 83; p.val = 1160;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 92; p.county = 83; p.val = 1142;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 91; p.county = 83; p.val = 1123;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 96; p.county = 83; p.val = 1741;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 97; p.county = 83; p.val = 2135;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 96; p.county = 83; p.val = 744;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 98; p.county = 83; p.val = 1371;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 95; p.county = 83; p.val = 1400;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 90; p.county = 83; p.val = 970;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 93; p.county = 83; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 97; p.county = 83; p.val = 927;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 96; p.county = 83; p.val = 1491;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 100; p.county = 83; p.val = 1528;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 97; p.county = 83; p.val = 637;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 95; p.county = 83; p.val = 1103;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 94; p.county = 83; p.val = 579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 95; p.county = 83; p.val = 530;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 86; p.county = 83; p.val = 488;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 92; p.county = 83; p.val = 1663;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 84; p.county = 83; p.val = 375;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 99; p.county = 83; p.val = 1694;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 94; p.county = 83; p.val = 517;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 93; p.county = 83; p.val = 1242;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 83; p.county = 83; p.val = 654;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 94; p.county = 83; p.val = 503;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 96; p.county = 83; p.val = 1626;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 93; p.county = 83; p.val = 2044;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 90; p.county = 83; p.val = 1467;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 89; p.county = 83; p.val = 1815;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 93; p.county = 83; p.val = 1090;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 92; p.county = 83; p.val = 931;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 93; p.county = 83; p.val = 294;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 93; p.county = 83; p.val = 456;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 93; p.county = 83; p.val = 392;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 92; p.county = 83; p.val = 457;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 92; p.county = 83; p.val = 821;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 87; p.county = 83; p.val = 1486;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 93; p.county = 83; p.val = 1253;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 92; p.county = 83; p.val = 606;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 95; p.county = 83; p.val = 766;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 92; p.county = 83; p.val = 361;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 91; p.county = 83; p.val = 468;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 97; p.county = 83; p.val = 1110;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 95; p.county = 83; p.val = 1282;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 97; p.county = 83; p.val = 1132;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 94; p.county = 83; p.val = 615;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 92; p.county = 83; p.val = 1002;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 96; p.county = 83; p.val = 1047;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 89; p.county = 83; p.val = 1556;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 91; p.county = 83; p.val = 1071;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 95; p.county = 83; p.val = 1802;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 96; p.county = 83; p.val = 593;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 97; p.county = 83; p.val = 738;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 96; p.county = 83; p.val = 717;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 93; p.county = 83; p.val = 835;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 91; p.county = 83; p.val = 1132;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 99; p.county = 83; p.val = 1326;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 92; p.county = 83; p.val = 751;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 91; p.county = 83; p.val = 556;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 85; p.county = 83; p.val = 1123;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 92; p.county = 83; p.val = 771;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 91; p.county = 83; p.val = 1469;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 94; p.county = 83; p.val = 1109;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 94; p.county = 83; p.val = 930;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 91; p.county = 83; p.val = 1067;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 94; p.county = 83; p.val = 449;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 92; p.county = 83; p.val = 1143;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 91; p.county = 83; p.val = 1345;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 91; p.county = 83; p.val = 804;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 93; p.county = 83; p.val = 719;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 93; p.county = 83; p.val = 650;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 92; p.county = 83; p.val = 914;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 92; p.county = 83; p.val = 579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 93; p.county = 83; p.val = 477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 93; p.county = 83; p.val = 866;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 93; p.county = 83; p.val = 1323;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 92; p.county = 83; p.val = 858;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 92; p.county = 83; p.val = 1065;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 94; p.county = 83; p.val = 603;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 94; p.county = 83; p.val = 892;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 93; p.county = 83; p.val = 774;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 94; p.county = 83; p.val = 705;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 94; p.county = 83; p.val = 582;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 95; p.county = 83; p.val = 809;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 93; p.county = 83; p.val = 582;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 90; p.county = 83; p.val = 1627;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 65; p.county = 85; p.val = 1097;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 62; p.county = 85; p.val = 349;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 63; p.county = 85; p.val = 489;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 61; p.county = 85; p.val = 653;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 62; p.county = 85; p.val = 776;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 59; p.county = 85; p.val = 268;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 61; p.county = 85; p.val = 500;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 61; p.county = 85; p.val = 703;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 57; p.county = 85; p.val = 735;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 56; p.county = 85; p.val = 972;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 59; p.county = 85; p.val = 786;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 60; p.county = 85; p.val = 316;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 57; p.county = 85; p.val = 769;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 54; p.county = 85; p.val = 892;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 55; p.county = 85; p.val = 553;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 57; p.county = 85; p.val = 884;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 62; p.county = 85; p.val = 711;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 56; p.county = 85; p.val = 691;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 60; p.county = 85; p.val = 819;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 58; p.county = 85; p.val = 719;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 62; p.county = 85; p.val = 549;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 61; p.county = 85; p.val = 1031;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 64; p.county = 85; p.val = 537;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 62; p.county = 85; p.val = 710;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 59; p.county = 85; p.val = 800;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 58; p.county = 85; p.val = 584;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 60; p.county = 85; p.val = 360;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 320;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 61; p.county = 85; p.val = 438;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 60; p.county = 85; p.val = 465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 482;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 85; p.val = 568;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 85; p.val = 955;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 85; p.val = 592;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 85; p.val = 519;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 85; p.val = 624;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 58; p.county = 85; p.val = 486;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 85; p.val = 469;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 60; p.county = 85; p.val = 625;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 416;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 548;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 60; p.county = 85; p.val = 380;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 59; p.county = 85; p.val = 569;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 216;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 59; p.county = 85; p.val = 271;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 258;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 59; p.county = 85; p.val = 276;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 58; p.county = 85; p.val = 459;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 349;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 58; p.county = 85; p.val = 828;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 59; p.county = 85; p.val = 352;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 60; p.county = 85; p.val = 1011;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 59; p.county = 85; p.val = 780;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 58; p.county = 85; p.val = 1009;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 61; p.county = 85; p.val = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 61; p.county = 85; p.val = 754;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 60; p.county = 85; p.val = 579;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 59; p.county = 85; p.val = 498;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 86; p.county = 87; p.val = 393;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 80; p.county = 87; p.val = 246;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 87; p.county = 87; p.val = 480;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 86; p.county = 87; p.val = 414;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 90; p.county = 87; p.val = 513;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 89; p.county = 87; p.val = 591;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 89; p.county = 87; p.val = 523;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 87; p.county = 87; p.val = 314;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 86; p.county = 87; p.val = 526;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 85; p.county = 87; p.val = 152;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 86; p.county = 87; p.val = 420;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 86; p.county = 87; p.val = 322;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 86; p.county = 87; p.val = 540;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 85; p.county = 87; p.val = 496;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 85; p.county = 87; p.val = 277;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 80; p.county = 87; p.val = 287;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 82; p.county = 87; p.val = 477;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 83; p.county = 87; p.val = 418;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 85; p.county = 87; p.val = 147;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 83; p.county = 87; p.val = 679;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 86; p.county = 87; p.val = 387;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 85; p.county = 87; p.val = 119;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 87; p.county = 87; p.val = 215;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 54; p.county = 89; p.val = 192;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 48; p.county = 89; p.val = 457;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 55; p.county = 89; p.val = 268;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 43; p.county = 89; p.val = 340;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 45; p.county = 89; p.val = 205;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 56; p.county = 89; p.val = 74;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 53; p.county = 89; p.val = 737;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 51; p.county = 89; p.val = 187;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 49; p.county = 89; p.val = 466;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 48; p.county = 89; p.val = 683;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 54; p.county = 89; p.val = 842;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 52; p.county = 89; p.val = 316;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 51; p.county = 89; p.val = 1341;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 51; p.county = 89; p.val = 310;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 53; p.county = 89; p.val = 864;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 50; p.county = 89; p.val = 547;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 46; p.county = 89; p.val = 506;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 48; p.county = 89; p.val = 151;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 51; p.county = 89; p.val = 217;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 50; p.county = 89; p.val = 371;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 57; p.county = 89; p.val = 137;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 47; p.county = 89; p.val = 238;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 48; p.county = 89; p.val = 591;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 55; p.county = 89; p.val = 171;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 42; p.county = 89; p.val = 145;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 89; p.val = 475;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 54; p.county = 89; p.val = 503;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 54; p.county = 89; p.val = 209;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 98; p.county = 91; p.val = 1092;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 99; p.county = 91; p.val = 853;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 98; p.county = 91; p.val = 1310;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 96; p.county = 91; p.val = 359;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 96; p.county = 91; p.val = 1366;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 98; p.county = 91; p.val = 1620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 99; p.county = 91; p.val = 762;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 90; p.county = 91; p.val = 259;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 96; p.county = 91; p.val = 1149;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 93; p.county = 91; p.val = 586;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 95; p.county = 91; p.val = 674;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 92; p.county = 91; p.val = 847;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 90; p.county = 91; p.val = 877;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 90; p.county = 91; p.val = 1218;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 89; p.county = 91; p.val = 1465;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 96; p.county = 91; p.val = 837;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 91; p.county = 91; p.val = 565;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 90; p.county = 91; p.val = 1596;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 94; p.county = 91; p.val = 1153;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 94; p.county = 91; p.val = 901;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 93; p.county = 91; p.val = 742;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 94; p.county = 91; p.val = 1106;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 94; p.county = 91; p.val = 821;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 94; p.county = 91; p.val = 1201;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 94; p.county = 91; p.val = 973;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 94; p.county = 91; p.val = 1542;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 97; p.county = 91; p.val = 836;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 97; p.county = 91; p.val = 649;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 95; p.county = 91; p.val = 895;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 93; p.county = 91; p.val = 825;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 93; p.county = 91; p.val = 763;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 94; p.county = 91; p.val = 1613;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 94; p.county = 91; p.val = 1073;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 91; p.val = 653;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 94; p.county = 91; p.val = 1015;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 91; p.county = 91; p.val = 561;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 97; p.county = 91; p.val = 1251;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 95; p.county = 91; p.val = 945;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 91; p.val = 606;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 91; p.county = 91; p.val = 1422;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 91; p.val = 790;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 92; p.county = 91; p.val = 1126;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 93; p.county = 91; p.val = 1061;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 91; p.val = 871;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 91; p.val = 688;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 93; p.county = 91; p.val = 1243;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 93; p.county = 91; p.val = 1395;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 91; p.county = 91; p.val = 1333;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 95; p.county = 91; p.val = 934;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 91; p.county = 91; p.val = 820;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 96; p.county = 91; p.val = 1409;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 97; p.county = 91; p.val = 1091;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 95; p.county = 91; p.val = 1591;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 93; p.county = 91; p.val = 509;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 96; p.county = 91; p.val = 1201;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 93; p.county = 91; p.val = 2162;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 94; p.county = 91; p.val = 1620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 95; p.county = 91; p.val = 803;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 96; p.county = 91; p.val = 1265;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 95; p.county = 91; p.val = 786;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 94; p.county = 91; p.val = 995;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 97; p.county = 91; p.val = 1463;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 95; p.county = 91; p.val = 807;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 94; p.county = 91; p.val = 471;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 93; p.county = 91; p.val = 941;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 93; p.county = 91; p.val = 999;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 96; p.county = 91; p.val = 721;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 91; p.val = 816;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 91; p.county = 91; p.val = 524;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 92; p.county = 91; p.val = 396;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 93; p.county = 91; p.val = 1044;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 92; p.county = 91; p.val = 604;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 99; p.county = 91; p.val = 659;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 96; p.county = 91; p.val = 1489;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 91; p.county = 91; p.val = 547;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 91; p.county = 91; p.val = 715;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 92; p.county = 91; p.val = 677;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 98; p.county = 91; p.val = 673;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 98; p.county = 91; p.val = 756;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 98; p.county = 91; p.val = 677;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 97; p.county = 91; p.val = 870;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 96; p.county = 91; p.val = 1201;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 95; p.county = 91; p.val = 1133;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 93; p.county = 91; p.val = 1252;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 96; p.county = 91; p.val = 1729;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 93; p.county = 91; p.val = 1574;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 92; p.county = 91; p.val = 813;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 93; p.county = 91; p.val = 620;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 94; p.county = 91; p.val = 672;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 97; p.county = 91; p.val = 1454;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 97; p.county = 91; p.val = 758;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 96; p.county = 91; p.val = 1575;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 95; p.county = 91; p.val = 1267;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 96; p.county = 91; p.val = 1023;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 99; p.county = 91; p.val = 1114;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 95; p.county = 91; p.val = 768;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 87; p.county = 23; p.val = 601;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
return points;}







struct Map {
	std::map<int,std::map<int,Point> > pixels;
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
				m.pixels[i][ii]=m.pixels[i][ii/sz];
			}
		}
		else {
			for (i=0;i<m.width;i++){
				Point p;
				p.x = i;
				p.y = ii;
				p.val = 1;
				m.pixels[i][ii]=p;
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
				m.pixels[i][ii]=m.pixels[i/sz][ii];
			}
		}
		else {
			for (ii=0;ii<m.height;ii++){
				Point p;
				p.x = i;
				p.y = ii;
				p.val = 1;
				m.pixels[i][ii]=p;
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
		oldMax[ii]=m.pixels[0][ii].val;
		oldSeams[ii]={ii};
		if (l==0){
			if (m.pixels[0][ii].val >= 0){
				oldMax[ii]=m.height;
			}
			else {
				oldMax[ii]=-1000000;
			}
			
		}
		else if (l < 0){
			if (m.pixels[0][ii].val >= 0){
				oldMax[ii]=m.height;
			}
			else {
				oldMax[ii]=-1000000;
				oldSeams[ii][0]=m.height;
			}
			
		}
		
	}
	int h = m.height;
	int w = m.width;
	int modn = h / n;
	for(i=1;i<w;i++){
		for(ii=0;ii<h;ii++){
			int mpv = m.pixels[i][ii].val;
			if (l >= 0 && mpv<0){
				newMax[ii] = mpv;
				newSeams[ii] = oldSeams[ii];
				newSeams[ii].push_back(ii);
				continue;
			}
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
						mpv = h-1;//zig zag is good
					}
					else {
						mpv = h;
					}
				}
				else {
					for (iiii=2;iiii<h;iiii++){
						if (ii%modn>=iiii && oldMax[ii-iiii] >= 0){
							maxv = oldMax[ii-iiii];
							mpv = h-iiii;
							newI = ii-iiii;
							break;
						}
						if (ii+iiii<h && (ii+iiii) % modn>0 && oldMax[ii+iiii] >= 0){
							maxv = oldMax[ii+iiii];
							mpv = h-iiii;
							newI = ii+iiii;
							break;
						}
					}
				}
			}
			else if (l < 0){
				if (maxv >= 0){
					if (newI == ii){
						mpv = h-1;//zig zag is good
					}
					else {
						mpv = h;
					}
				}
				else {
					for (iiii=2;iiii<h;iiii++){
						if (ii%modn>=iiii && oldMax[ii-iiii] >= 0){
							maxv = oldMax[ii-iiii];
							mpv = h-iiii;
							newI = ii-iiii;
							break;
						}
						if (ii+iiii<h && (ii+iiii) % modn>0 && oldMax[ii+iiii] >= 0){
							maxv = oldMax[ii+iiii];
							mpv = h-iiii;
							newI = ii+iiii;
							break;
						}
					}
				}
				
				if (maxv >= 0){
				
				}
				else {
					mpv = -1000000;
					maxv = oldMax[ii];
					newI = ii;
					skip = true;
				}
			}
			
			
			newMax[ii] = maxv+mpv;

			
			newSeams[ii] = oldSeams[newI];
			if (skip){
				//newSeams[ii][newSeams[ii].size()-1]=h;
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
		if (l<0){
			maxSeam =1000000*l;
		}
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
						m.pixels[i][ii]=m.pixels[i][ii+1];
					}
				}
				m.height--;
			}
		}
		else {
			if (maxSeam <=1000000*l){
				killCarveH = true;
				return m;
			}
			else {
				for(i=0;i<w;i++){
					if (removeSeam[i] == m.height || m.pixels[i][removeSeam[i]].val < 0){
					}
					else {
						for(ii=removeSeam[i];ii<m.height-1;ii++){
							m.pixels[i][ii]=m.pixels[i][ii+1];
						}
						Point p;
						p.x = i;
						p.y = m.height-1;
						p.val = 1;
						m.pixels[i][m.height-1]=p;
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
		oldMax[i]=m.pixels[i][0].val;
		oldSeams[i]={i};
		if (l==0){
			if (m.pixels[i][0].val >= 0){
				oldMax[i]=m.width;
			}
			else {
				oldMax[i]=-1000000;
			}
		}
		else if (l < 0){
			if (m.pixels[i][0].val >= 0){
				oldMax[i]=m.width;
			}
			else {
				oldMax[i]=-1000000;
				oldSeams[i][0]=m.width;
			}
			
		}
		
	}
	int h = m.height;
	int w = m.width;
	int modn = w / n;
	for(ii=1;ii<h;ii++){
		for(i=0;i<w;i++){
			int mpv = m.pixels[i][ii].val;
			if (l >= 0 && mpv<0){
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
						mpv = w-1;//zig zag is good
					}
					else {
						mpv = w;
					}
				}
				else {
					for (iiii=2;iiii<w;iiii++){
						if (i%modn>=iiii && oldMax[i-iiii] >= 0){
							maxv = oldMax[i-iiii];
							mpv = w-iiii;
							newI = i-iiii;
							break;
						}
						if (i+iiii<w && (i+iiii) % modn>0 && oldMax[i+iiii] >= 0){
							maxv = oldMax[i+iiii];
							mpv = w-iiii;
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
		if (l<0){
			maxSeam =1000000*l;
		}
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
					
						m.pixels[i][ii]=m.pixels[i+1][ii];
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
					if (removeSeam[ii] == m.width || m.pixels[removeSeam[ii]][ii].val < 0){
						
					}
					else {
						
						
						for(i=removeSeam[ii];i<m.width-1;i++){
							m.pixels[i][ii]=m.pixels[i+1][ii];
						}
						Point p;
						p.x = m.width-1;
						p.y = ii;
						p.val = 1;
						m.pixels[m.width-1][ii]=p;
					}
					
				}
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
	
	killCarveV = false;
	killCarveH = false;
	
	std::map<int,std::map<int,Point>> pixels;
	for(i=0;i<100;i++){
		std::map<int,Point> v
		pixels[i] = v;
		for(ii=0;ii<100;ii++){
			Point p;
			p.x = i;
			p.y = ii;
			p.val = 0;
			pixels[i][ii] = p;
		}
	}

	
	/*for (i=0;i<np;i++){
		int x = rand() % 10000;
		int y = rand() % 10000;
		Point p;
		p.x = x;
		p.y = y;
		points[i]=p;
		xCount[x]++;
		yCount[y]++;
	}*/
	points = scPoints();
	
	int np = points.size();
	
	
	for(i=0;i<np;i++){
		Point p = points[i];
		pixels[p.x][p.y].val += p.val;
		pixels[p.x][p.y].county += p.county;
	}
	
	Map m;
	m.pixels = pixels;
	m.width = 100;
	m.height = 100;
	
	auto a11 = std::chrono::high_resolution_clock::now();
	
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationTotal);
	
	a11 = std::chrono::high_resolution_clock::now();
	vertThreads = 5;
	horzThreads = 5;
	/*for (i=0;i<np;i++){

		
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
	}*/
	
	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(m.width);
	console_log(m.height);
	set_maxX(m.width);
	set_maxY(m.height);
	for(i=0;i<m.width;i++){
		for(ii=0;ii<m.height;ii++){
			Point p = m.pixels[i][ii];
			std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county);
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
