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
		pointsOut.push({"x":pointSplit[3],"y":pointSplit[4],"ox":pointSplit[0],"oy":pointSplit[1],"county":pointSplit[5],"val":pointSplit[2]});	
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
	int npix;
};

std::map<int,Point> scPoints(){
std::map<int,Point> points; int i=0;
if (1==1){ Point p;
p.x = 20; p.y = 31; p.county = 1; p.val = 817;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 34; p.county = 1; p.val = 625;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 35; p.county = 1; p.val = 580;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 32; p.county = 1; p.val = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 29; p.county = 1; p.val = 636;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 24; p.county = 1; p.val = 261;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 35; p.county = 1; p.val = 944;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 30; p.county = 1; p.val = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 26; p.county = 1; p.val = 312;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 28; p.county = 1; p.val = 813;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 25; p.county = 1; p.val = 423;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 27; p.county = 1; p.val = 609;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 32; p.county = 1; p.val = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 34; p.county = 1; p.val = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 32; p.county = 1; p.val = 490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 60; p.county = 3; p.val = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 52; p.county = 3; p.val = 1944;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 52; p.county = 3; p.val = 1994;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 53; p.county = 3; p.val = 1114;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 51; p.county = 3; p.val = 680;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 48; p.county = 3; p.val = 702;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 50; p.county = 3; p.val = 990;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 49; p.county = 3; p.val = 1052;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 54; p.county = 3; p.val = 2172;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 53; p.county = 3; p.val = 2397;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 54; p.county = 3; p.val = 1853;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 55; p.county = 3; p.val = 870;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 57; p.county = 3; p.val = 1763;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 47; p.county = 3; p.val = 516;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 56; p.county = 3; p.val = 830;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 55; p.county = 3; p.val = 888;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 60; p.county = 3; p.val = 878;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 51; p.county = 3; p.val = 402;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 54; p.county = 3; p.val = 3640;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 54; p.county = 3; p.val = 1133;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 44; p.county = 3; p.val = 634;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 49; p.county = 3; p.val = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 50; p.county = 3; p.val = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 52; p.county = 3; p.val = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 55; p.county = 3; p.val = 1496;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 53; p.county = 3; p.val = 2890;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 53; p.county = 3; p.val = 400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 50; p.county = 3; p.val = 875;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 47; p.county = 3; p.val = 760;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 53; p.county = 3; p.val = 1511;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 56; p.county = 3; p.val = 433;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 54; p.county = 3; p.val = 536;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 52; p.county = 3; p.val = 965;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 57; p.county = 3; p.val = 609;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 51; p.county = 3; p.val = 1264;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 53; p.county = 3; p.val = 1213;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 53; p.county = 3; p.val = 673;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 52; p.county = 3; p.val = 583;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 52; p.county = 3; p.val = 1674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 55; p.county = 3; p.val = 951;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 54; p.county = 3; p.val = 1688;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 58; p.county = 3; p.val = 946;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 53; p.county = 3; p.val = 1557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 56; p.county = 3; p.val = 902;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 56; p.county = 3; p.val = 1162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 54; p.county = 3; p.val = 805;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 55; p.county = 3; p.val = 3090;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 54; p.county = 3; p.val = 1006;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 55; p.county = 3; p.val = 500;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 58; p.county = 3; p.val = 516;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 56; p.county = 3; p.val = 490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 54; p.county = 3; p.val = 1374;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 55; p.county = 3; p.val = 935;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 70; p.county = 5; p.val = 492;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 71; p.county = 5; p.val = 471;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 71; p.county = 5; p.val = 295;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 75; p.county = 5; p.val = 552;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 68; p.county = 5; p.val = 267;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 71; p.county = 5; p.val = 453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 70; p.county = 5; p.val = 244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 68; p.county = 5; p.val = 123;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 21; p.county = 7; p.val = 2754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 24; p.county = 7; p.val = 234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 21; p.county = 7; p.val = 790;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 16; p.county = 7; p.val = 1099;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 18; p.county = 7; p.val = 978;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 23; p.county = 7; p.val = 331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 28; p.county = 7; p.val = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 28; p.county = 7; p.val = 393;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 18; p.county = 7; p.val = 509;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 17; p.county = 7; p.val = 407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 19; p.county = 7; p.val = 1170;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 23; p.county = 7; p.val = 906;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 17; p.county = 7; p.val = 1205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 18; p.county = 7; p.val = 1565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 16; p.county = 7; p.val = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 23; p.county = 7; p.val = 1256;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 20; p.county = 7; p.val = 1638;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 20; p.county = 7; p.val = 759;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 21; p.county = 7; p.val = 754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 28; p.county = 7; p.val = 320;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 19; p.county = 7; p.val = 1908;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 21; p.county = 7; p.val = 608;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 24; p.county = 7; p.val = 520;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 15; p.county = 7; p.val = 1369;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 13; p.county = 7; p.val = 1564;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 22; p.county = 7; p.val = 592;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 19; p.county = 7; p.val = 666;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 20; p.county = 7; p.val = 2313;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 25; p.county = 7; p.val = 627;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 23; p.county = 7; p.val = 276;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 24; p.county = 7; p.val = 769;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 26; p.county = 7; p.val = 609;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 22; p.county = 7; p.val = 848;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 24; p.county = 7; p.val = 502;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 23; p.county = 7; p.val = 644;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 21; p.county = 7; p.val = 1290;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 17; p.county = 7; p.val = 1146;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 24; p.county = 7; p.val = 688;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 22; p.county = 7; p.val = 434;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 25; p.county = 7; p.val = 433;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 15; p.county = 7; p.val = 1362;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 26; p.county = 7; p.val = 486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 15; p.county = 7; p.val = 1311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 20; p.county = 7; p.val = 244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 20; p.county = 7; p.val = 430;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 19; p.county = 7; p.val = 870;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 25; p.county = 7; p.val = 196;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 17; p.county = 7; p.val = 1565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 18; p.county = 7; p.val = 1111;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 18; p.county = 7; p.val = 1151;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 26; p.county = 7; p.val = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 20; p.county = 7; p.val = 1733;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 21; p.county = 7; p.val = 2645;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 22; p.county = 7; p.val = 1787;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 22; p.county = 7; p.val = 727;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 22; p.county = 7; p.val = 1088;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 21; p.county = 7; p.val = 1345;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 14; p.county = 7; p.val = 1313;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 21; p.county = 7; p.val = 904;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 12; p.county = 7; p.val = 1659;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 20; p.county = 7; p.val = 969;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 23; p.county = 7; p.val = 1262;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 13; p.county = 7; p.val = 2153;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 65; p.county = 9; p.val = 137;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 64; p.county = 9; p.val = 229;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 67; p.county = 9; p.val = 505;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 60; p.county = 9; p.val = 1064;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 63; p.county = 9; p.val = 99;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 61; p.county = 9; p.val = 55;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 9; p.val = 154;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 68; p.county = 9; p.val = 90;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 9; p.val = 103;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 9; p.val = 234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 9; p.val = 714;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 59; p.county = 9; p.val = 727;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 61; p.county = 9; p.val = 269;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 61; p.county = 11; p.val = 301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 61; p.county = 11; p.val = 722;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 63; p.county = 11; p.val = 799;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 64; p.county = 11; p.val = 615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 60; p.county = 11; p.val = 486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 60; p.county = 11; p.val = 308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 58; p.county = 11; p.val = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 64; p.county = 11; p.val = 327;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 66; p.county = 11; p.val = 301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 57; p.county = 11; p.val = 478;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 11; p.val = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 64; p.county = 11; p.val = 609;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 56; p.county = 11; p.val = 734;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 59; p.county = 11; p.val = 313;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 58; p.county = 11; p.val = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 63; p.county = 11; p.val = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 89; p.county = 13; p.val = 1761;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 90; p.county = 13; p.val = 937;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 89; p.county = 13; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 92; p.county = 13; p.val = 717;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 90; p.county = 13; p.val = 1076;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 88; p.county = 13; p.val = 773;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 91; p.county = 13; p.val = 1223;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 89; p.county = 13; p.val = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 90; p.county = 13; p.val = 1914;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 91; p.county = 13; p.val = 862;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 92; p.county = 13; p.val = 1071;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 92; p.county = 13; p.val = 805;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 89; p.county = 13; p.val = 1558;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 91; p.county = 13; p.val = 963;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 88; p.county = 13; p.val = 1586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 87; p.county = 13; p.val = 834;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 85; p.county = 13; p.val = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 88; p.county = 13; p.val = 512;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 86; p.county = 13; p.val = 528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 87; p.county = 13; p.val = 733;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 84; p.county = 13; p.val = 656;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 82; p.county = 13; p.val = 409;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 88; p.county = 13; p.val = 258;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 91; p.county = 13; p.val = 754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 94; p.county = 13; p.val = 835;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 89; p.county = 13; p.val = 1151;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 89; p.county = 13; p.val = 844;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 90; p.county = 13; p.val = 811;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 93; p.county = 13; p.val = 736;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 88; p.county = 13; p.val = 577;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 100; p.county = 13; p.val = 298;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 96; p.county = 13; p.val = 2064;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 98; p.county = 13; p.val = 1451;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 96; p.county = 13; p.val = 1259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 97; p.county = 13; p.val = 1018;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 96; p.county = 13; p.val = 701;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 98; p.county = 13; p.val = 1570;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 97; p.county = 13; p.val = 2048;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 94; p.county = 13; p.val = 753;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 95; p.county = 13; p.val = 1515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 94; p.county = 13; p.val = 583;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 95; p.county = 13; p.val = 652;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 98; p.county = 13; p.val = 1864;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 97; p.county = 13; p.val = 1155;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 99; p.county = 13; p.val = 1462;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 99; p.county = 13; p.val = 746;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 100; p.county = 13; p.val = 572;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 94; p.county = 13; p.val = 1353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 96; p.county = 13; p.val = 556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 95; p.county = 13; p.val = 2713;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 95; p.county = 13; p.val = 1910;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 94; p.county = 13; p.val = 1864;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 94; p.county = 13; p.val = 5005;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 95; p.county = 13; p.val = 2344;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 94; p.county = 13; p.val = 1580;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 96; p.county = 13; p.val = 891;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 97; p.county = 13; p.val = 798;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 95; p.county = 13; p.val = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 95; p.county = 13; p.val = 1290;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 97; p.county = 13; p.val = 1565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 94; p.county = 13; p.val = 532;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 93; p.county = 13; p.val = 589;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 60; p.county = 15; p.val = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 64; p.county = 15; p.val = 139;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 61; p.county = 15; p.val = 612;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 60; p.county = 15; p.val = 850;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 62; p.county = 15; p.val = 860;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 63; p.county = 15; p.val = 1270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 57; p.county = 15; p.val = 660;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 57; p.county = 15; p.val = 647;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 70; p.county = 15; p.val = 3401;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 71; p.county = 15; p.val = 3192;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 71; p.county = 15; p.val = 626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 57; p.county = 15; p.val = 357;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 64; p.county = 15; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 58; p.county = 15; p.val = 662;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 68; p.county = 15; p.val = 1165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 72; p.county = 15; p.val = 5053;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 70; p.county = 15; p.val = 4715;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 69; p.county = 15; p.val = 2486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 63; p.county = 15; p.val = 926;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 66; p.county = 15; p.val = 622;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 62; p.county = 15; p.val = 306;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 61; p.county = 15; p.val = 565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 64; p.county = 15; p.val = 753;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 66; p.county = 15; p.val = 390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 65; p.county = 15; p.val = 633;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 75; p.county = 15; p.val = 1258;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 75; p.county = 15; p.val = 947;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 70; p.county = 15; p.val = 3989;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 73; p.county = 15; p.val = 1355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 74; p.county = 15; p.val = 4005;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 71; p.county = 15; p.val = 3366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 68; p.county = 15; p.val = 691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 65; p.county = 15; p.val = 1626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 69; p.county = 15; p.val = 713;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 71; p.county = 15; p.val = 1065;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 68; p.county = 15; p.val = 1193;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 64; p.county = 15; p.val = 247;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 69; p.county = 15; p.val = 639;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 71; p.county = 15; p.val = 1259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 66; p.county = 15; p.val = 1234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 67; p.county = 15; p.val = 751;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 76; p.county = 15; p.val = 2214;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 76; p.county = 15; p.val = 2873;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 74; p.county = 15; p.val = 2743;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 73; p.county = 15; p.val = 1058;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 67; p.county = 15; p.val = 2675;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 68; p.county = 15; p.val = 2196;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 73; p.county = 15; p.val = 2749;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 58; p.county = 15; p.val = 652;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 65; p.county = 15; p.val = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 72; p.county = 15; p.val = 556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 69; p.county = 15; p.val = 817;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 72; p.county = 15; p.val = 709;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 69; p.county = 15; p.val = 1856;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 68; p.county = 15; p.val = 80;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 47; p.county = 17; p.val = 504;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 52; p.county = 17; p.val = 464;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 49; p.county = 17; p.val = 632;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 51; p.county = 17; p.val = 138;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 49; p.county = 17; p.val = 996;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 48; p.county = 17; p.val = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 47; p.county = 17; p.val = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 50; p.county = 17; p.val = 458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 54; p.county = 17; p.val = 215;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 49; p.county = 17; p.val = 271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 44; p.county = 17; p.val = 994;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 50; p.county = 17; p.val = 796;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 73; p.county = 19; p.val = 811;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 69; p.county = 19; p.val = 547;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 79; p.county = 19; p.val = 1999;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 72; p.county = 19; p.val = 3162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 82; p.county = 19; p.val = 728;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 78; p.county = 19; p.val = 1634;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 76; p.county = 19; p.val = 3542;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 77; p.county = 19; p.val = 1594;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 77; p.county = 19; p.val = 992;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 77; p.county = 19; p.val = 4758;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 77; p.county = 19; p.val = 1094;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 77; p.county = 19; p.val = 5297;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 68; p.county = 19; p.val = 1072;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 82; p.county = 19; p.val = 699;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 84; p.county = 19; p.val = 1224;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 85; p.county = 19; p.val = 985;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 85; p.county = 19; p.val = 1627;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 78; p.county = 19; p.val = 5697;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 83; p.county = 19; p.val = 754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 81; p.county = 19; p.val = 923;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 77; p.county = 19; p.val = 5874;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 78; p.county = 19; p.val = 1102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 76; p.county = 19; p.val = 1487;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 75; p.county = 19; p.val = 2547;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 75; p.county = 19; p.val = 3532;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 74; p.county = 19; p.val = 5946;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 75; p.county = 19; p.val = 2010;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 74; p.county = 19; p.val = 1755;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 81; p.county = 19; p.val = 1156;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 82; p.county = 19; p.val = 534;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 79; p.county = 19; p.val = 1616;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 80; p.county = 19; p.val = 448;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 80; p.county = 19; p.val = 3563;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 79; p.county = 19; p.val = 2589;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 79; p.county = 19; p.val = 5456;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 82; p.county = 19; p.val = 1034;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 75; p.county = 19; p.val = 812;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 80; p.county = 19; p.val = 973;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 78; p.county = 19; p.val = 5777;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 80; p.county = 19; p.val = 1948;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 79; p.county = 19; p.val = 754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 79; p.county = 19; p.val = 811;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 79; p.county = 19; p.val = 1941;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 82; p.county = 19; p.val = 626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 81; p.county = 19; p.val = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 77; p.county = 19; p.val = 498;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 80; p.county = 19; p.val = 782;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 80; p.county = 19; p.val = 1177;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 79; p.county = 19; p.val = 944;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 78; p.county = 19; p.val = 569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 77; p.county = 19; p.val = 1089;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 77; p.county = 19; p.val = 4720;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 77; p.county = 19; p.val = 5152;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 78; p.county = 19; p.val = 1604;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 76; p.county = 19; p.val = 2996;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 78; p.county = 19; p.val = 2121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 77; p.county = 19; p.val = 1089;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 77; p.county = 19; p.val = 1574;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 76; p.county = 19; p.val = 1452;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 76; p.county = 19; p.val = 2588;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 75; p.county = 19; p.val = 1625;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 76; p.county = 19; p.val = 1660;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 75; p.county = 19; p.val = 3654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 75; p.county = 19; p.val = 2234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 74; p.county = 19; p.val = 2352;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 74; p.county = 19; p.val = 2060;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 73; p.county = 19; p.val = 2689;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 5; p.county = 21; p.val = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 3; p.county = 21; p.val = 692;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 2; p.county = 21; p.val = 651;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 1; p.county = 21; p.val = 646;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 2; p.county = 21; p.val = 448;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 2; p.county = 21; p.val = 691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 4; p.county = 21; p.val = 772;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 3; p.county = 21; p.val = 1614;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 4; p.county = 21; p.val = 1297;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 2; p.county = 21; p.val = 728;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 4; p.county = 21; p.val = 550;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 3; p.county = 21; p.val = 1055;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 1; p.county = 21; p.val = 1160;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 5; p.county = 21; p.val = 612;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 1; p.county = 21; p.val = 623;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 9; p.county = 21; p.val = 221;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 3; p.county = 21; p.val = 771;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 0; p.county = 21; p.val = 649;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 3; p.county = 21; p.val = 467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 1; p.county = 21; p.val = 524;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 6; p.county = 21; p.val = 527;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 7; p.county = 21; p.val = 649;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 6; p.county = 21; p.val = 318;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 0; p.county = 21; p.val = 561;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 15; p.county = 23; p.val = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 14; p.county = 23; p.val = 366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 18; p.county = 23; p.val = 599;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 18; p.county = 23; p.val = 358;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 12; p.county = 23; p.val = 694;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 14; p.county = 23; p.val = 673;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 15; p.county = 23; p.val = 800;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 18; p.county = 23; p.val = 133;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 18; p.county = 23; p.val = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 12; p.county = 23; p.val = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 15; p.county = 23; p.val = 781;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 13; p.county = 23; p.val = 749;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 19; p.county = 23; p.val = 251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 13; p.county = 23; p.val = 342;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 20; p.county = 23; p.val = 521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 14; p.county = 23; p.val = 690;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 16; p.county = 23; p.val = 573;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 15; p.county = 23; p.val = 439;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 16; p.county = 23; p.val = 441;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 19; p.county = 25; p.val = 342;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 18; p.county = 25; p.val = 176;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 16; p.county = 25; p.val = 140;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 13; p.county = 25; p.val = 677;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 18; p.county = 25; p.val = 528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 13; p.county = 25; p.val = 427;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 14; p.county = 25; p.val = 653;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 15; p.county = 25; p.val = 436;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 16; p.county = 25; p.val = 730;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 16; p.county = 25; p.val = 592;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 15; p.county = 25; p.val = 829;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 12; p.county = 25; p.val = 388;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 17; p.county = 25; p.val = 552;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 16; p.county = 25; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 23; p.county = 25; p.val = 817;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 22; p.county = 25; p.val = 348;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 13; p.county = 25; p.val = 199;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 21; p.county = 25; p.val = 315;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 14; p.county = 25; p.val = 824;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 13; p.county = 25; p.val = 691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 19; p.county = 25; p.val = 326;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 25; p.val = 136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 14; p.county = 25; p.val = 461;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 16; p.county = 25; p.val = 315;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 13; p.county = 25; p.val = 237;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 45; p.county = 27; p.val = 534;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 43; p.county = 27; p.val = 316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 45; p.county = 27; p.val = 107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 52; p.county = 27; p.val = 232;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 49; p.county = 27; p.val = 370;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 53; p.county = 27; p.val = 1009;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 46; p.county = 27; p.val = 381;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 42; p.county = 27; p.val = 340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 46; p.county = 27; p.val = 239;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 53; p.county = 27; p.val = 1111;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 48; p.county = 27; p.val = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 49; p.county = 27; p.val = 1226;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 48; p.county = 27; p.val = 701;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 47; p.county = 27; p.val = 504;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 44; p.county = 27; p.val = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 47; p.county = 27; p.val = 599;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 50; p.county = 27; p.val = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 44; p.county = 27; p.val = 267;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 54; p.county = 27; p.val = 1094;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 52; p.county = 27; p.val = 202;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 50; p.county = 27; p.val = 537;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 41; p.county = 27; p.val = 649;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 50; p.county = 27; p.val = 641;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 47; p.county = 27; p.val = 205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 72; p.county = 29; p.val = 231;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 69; p.county = 29; p.val = 302;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 74; p.county = 29; p.val = 794;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 68; p.county = 29; p.val = 189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 83; p.county = 29; p.val = 533;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 79; p.county = 29; p.val = 557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 71; p.county = 29; p.val = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 73; p.county = 29; p.val = 318;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 78; p.county = 29; p.val = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 70; p.county = 29; p.val = 197;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 70; p.county = 29; p.val = 511;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 76; p.county = 29; p.val = 439;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 71; p.county = 29; p.val = 620;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 77; p.county = 29; p.val = 119;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 76; p.county = 29; p.val = 392;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 78; p.county = 29; p.val = 288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 73; p.county = 29; p.val = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 74; p.county = 29; p.val = 264;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 71; p.county = 29; p.val = 191;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 70; p.county = 29; p.val = 284;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 67; p.county = 29; p.val = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 72; p.county = 29; p.val = 388;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 74; p.county = 29; p.val = 261;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 75; p.county = 29; p.val = 542;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 73; p.county = 29; p.val = 1231;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 75; p.county = 29; p.val = 574;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 74; p.county = 29; p.val = 614;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 69; p.county = 29; p.val = 196;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 71; p.county = 29; p.val = 202;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 88; p.county = 29; p.val = 794;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 74; p.county = 29; p.val = 467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 31; p.val = 953;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 31; p.val = 399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 31; p.val = 400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 26; p.county = 31; p.val = 626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 31; p.val = 416;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 28; p.county = 31; p.val = 927;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 29; p.county = 31; p.val = 649;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 29; p.county = 31; p.val = 1343;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 25; p.county = 31; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 27; p.county = 31; p.val = 417;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 26; p.county = 31; p.val = 2079;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 31; p.val = 605;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 31; p.val = 521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 31; p.val = 1540;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 30; p.county = 31; p.val = 1315;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 29; p.county = 31; p.val = 339;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 32; p.county = 31; p.val = 731;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 33; p.county = 31; p.val = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 33; p.county = 31; p.val = 891;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 29; p.county = 31; p.val = 429;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 26; p.county = 31; p.val = 868;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 24; p.county = 31; p.val = 558;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 31; p.val = 591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 29; p.county = 31; p.val = 1052;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 23; p.county = 31; p.val = 504;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 28; p.county = 31; p.val = 521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 27; p.county = 31; p.val = 1272;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 31; p.val = 925;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 26; p.county = 31; p.val = 1159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 24; p.county = 33; p.val = 987;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 25; p.county = 33; p.val = 636;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 25; p.county = 33; p.val = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 27; p.county = 33; p.val = 1206;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 26; p.county = 33; p.val = 106;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 25; p.county = 33; p.val = 174;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 28; p.county = 33; p.val = 654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 28; p.county = 33; p.val = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 25; p.county = 33; p.val = 855;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 27; p.county = 33; p.val = 139;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 24; p.county = 33; p.val = 91;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 23; p.county = 33; p.val = 361;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 22; p.county = 33; p.val = 447;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 20; p.county = 33; p.val = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 23; p.county = 33; p.val = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 21; p.county = 33; p.val = 115;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 28; p.county = 33; p.val = 417;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 26; p.county = 33; p.val = 152;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 28; p.county = 33; p.val = 347;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 29; p.county = 33; p.val = 259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 62; p.county = 35; p.val = 698;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 65; p.county = 35; p.val = 363;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 66; p.county = 35; p.val = 530;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 67; p.county = 35; p.val = 460;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 65; p.county = 35; p.val = 545;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 65; p.county = 35; p.val = 343;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 64; p.county = 35; p.val = 597;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 67; p.county = 35; p.val = 576;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 70; p.county = 35; p.val = 3971;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 71; p.county = 35; p.val = 2904;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 72; p.county = 35; p.val = 1027;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 72; p.county = 35; p.val = 3866;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 70; p.county = 35; p.val = 3010;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 64; p.county = 35; p.val = 407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 71; p.county = 35; p.val = 5960;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 68; p.county = 35; p.val = 429;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 72; p.county = 35; p.val = 518;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 73; p.county = 35; p.val = 4689;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 70; p.county = 35; p.val = 597;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 74; p.county = 35; p.val = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 74; p.county = 35; p.val = 214;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 72; p.county = 35; p.val = 4770;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 73; p.county = 35; p.val = 880;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 73; p.county = 35; p.val = 736;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 71; p.county = 35; p.val = 1333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 70; p.county = 35; p.val = 931;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 63; p.county = 35; p.val = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 74; p.county = 35; p.val = 2440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 69; p.county = 35; p.val = 1190;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 69; p.county = 35; p.val = 1643;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 68; p.county = 35; p.val = 380;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 44; p.county = 37; p.val = 520;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 37; p.val = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 44; p.county = 37; p.val = 685;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 43; p.county = 37; p.val = 732;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 47; p.county = 37; p.val = 615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 52; p.county = 37; p.val = 1504;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 47; p.county = 37; p.val = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 45; p.county = 37; p.val = 527;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 41; p.county = 37; p.val = 299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 42; p.county = 37; p.val = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 50; p.county = 37; p.val = 1709;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 49; p.county = 37; p.val = 1021;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 20; p.county = 39; p.val = 40;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 24; p.county = 39; p.val = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 29; p.county = 39; p.val = 184;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 21; p.county = 39; p.val = 195;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 29; p.county = 39; p.val = 1020;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 21; p.county = 39; p.val = 47;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 30; p.county = 39; p.val = 390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 29; p.county = 39; p.val = 195;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 27; p.county = 39; p.val = 556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 25; p.county = 39; p.val = 452;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 22; p.county = 39; p.val = 503;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 26; p.county = 39; p.val = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 22; p.county = 39; p.val = 52;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 28; p.county = 39; p.val = 1219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 28; p.county = 39; p.val = 578;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 26; p.county = 39; p.val = 362;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 26; p.county = 39; p.val = 336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 26; p.county = 39; p.val = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 25; p.county = 39; p.val = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 23; p.county = 39; p.val = 178;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 22; p.county = 39; p.val = 89;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 25; p.county = 39; p.val = 919;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 29; p.county = 41; p.val = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 30; p.county = 41; p.val = 379;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 35; p.county = 41; p.val = 480;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 32; p.county = 41; p.val = 2080;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 44; p.county = 41; p.val = 935;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 35; p.county = 41; p.val = 1127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 36; p.county = 41; p.val = 623;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 32; p.county = 41; p.val = 2127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 33; p.county = 41; p.val = 2582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 39; p.county = 41; p.val = 453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 38; p.county = 41; p.val = 436;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 33; p.county = 41; p.val = 2148;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 32; p.county = 41; p.val = 2425;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 33; p.county = 41; p.val = 1414;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 41; p.county = 41; p.val = 279;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 32; p.county = 41; p.val = 750;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 36; p.county = 41; p.val = 405;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 36; p.county = 41; p.val = 914;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 31; p.county = 41; p.val = 2271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 32; p.county = 41; p.val = 926;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 31; p.county = 41; p.val = 1487;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 33; p.county = 41; p.val = 2179;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 39; p.county = 41; p.val = 301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 34; p.county = 41; p.val = 1041;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 41; p.county = 41; p.val = 409;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 43; p.county = 41; p.val = 1307;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 43; p.county = 41; p.val = 181;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 33; p.county = 41; p.val = 1147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 30; p.county = 41; p.val = 835;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 41; p.county = 41; p.val = 396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 37; p.county = 41; p.val = 354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 37; p.county = 41; p.val = 606;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 40; p.county = 41; p.val = 782;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 42; p.county = 41; p.val = 537;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 42; p.county = 41; p.val = 693;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 43; p.county = 41; p.val = 765;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 38; p.county = 41; p.val = 599;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 39; p.county = 41; p.val = 356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 43; p.county = 41; p.val = 196;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 30; p.county = 41; p.val = 564;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 39; p.county = 41; p.val = 296;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 34; p.county = 41; p.val = 1921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 41; p.county = 41; p.val = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 34; p.county = 41; p.val = 945;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 35; p.county = 41; p.val = 905;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 33; p.county = 41; p.val = 758;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 44; p.county = 41; p.val = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 31; p.county = 41; p.val = 1461;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 34; p.county = 41; p.val = 620;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 56; p.county = 43; p.val = 1397;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 57; p.county = 43; p.val = 491;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 56; p.county = 43; p.val = 827;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 55; p.county = 43; p.val = 1038;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 52; p.county = 43; p.val = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 59; p.county = 43; p.val = 986;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 58; p.county = 43; p.val = 1410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 55; p.county = 43; p.val = 1793;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 51; p.county = 43; p.val = 122;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 53; p.county = 43; p.val = 1451;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 53; p.county = 43; p.val = 930;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 60; p.county = 43; p.val = 297;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 47; p.county = 43; p.val = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 49; p.county = 43; p.val = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 52; p.county = 43; p.val = 3991;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 53; p.county = 43; p.val = 1288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 60; p.county = 43; p.val = 865;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 52; p.county = 43; p.val = 305;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 60; p.county = 43; p.val = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 55; p.county = 43; p.val = 407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 49; p.county = 43; p.val = 503;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 54; p.county = 43; p.val = 395;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 59; p.county = 43; p.val = 549;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 64; p.county = 43; p.val = 634;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 58; p.county = 43; p.val = 816;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 61; p.county = 43; p.val = 490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 55; p.county = 43; p.val = 1595;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 56; p.county = 43; p.val = 1599;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 61; p.county = 43; p.val = 1457;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 57; p.county = 43; p.val = 487;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 10; p.county = 45; p.val = 5815;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 9; p.county = 45; p.val = 4051;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 13; p.county = 45; p.val = 730;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 12; p.county = 45; p.val = 3116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 10; p.county = 45; p.val = 5011;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 15; p.county = 45; p.val = 1282;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 10; p.county = 45; p.val = 3288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 11; p.county = 45; p.val = 2943;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 11; p.county = 45; p.val = 5924;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 9; p.county = 45; p.val = 4756;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 11; p.county = 45; p.val = 3261;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 12; p.county = 45; p.val = 3142;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 13; p.county = 45; p.val = 2508;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 13; p.county = 45; p.val = 5119;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 9; p.county = 45; p.val = 5286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 10; p.county = 45; p.val = 3205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 7; p.county = 45; p.val = 821;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 7; p.county = 45; p.val = 1477;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 11; p.county = 45; p.val = 2790;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 9; p.county = 45; p.val = 6589;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 12; p.county = 45; p.val = 1747;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 11; p.county = 45; p.val = 4521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 14; p.county = 45; p.val = 509;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 8; p.county = 45; p.val = 2272;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 8; p.county = 45; p.val = 3128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 13; p.county = 45; p.val = 2689;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 12; p.county = 45; p.val = 5754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 9; p.county = 45; p.val = 4562;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 7; p.county = 45; p.val = 1212;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 11; p.county = 45; p.val = 1690;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 7; p.county = 45; p.val = 3177;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 2; p.county = 45; p.val = 1027;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 10; p.county = 45; p.val = 2240;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 20; p.county = 45; p.val = 1168;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 18; p.county = 45; p.val = 1080;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 15; p.county = 45; p.val = 1842;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 16; p.county = 45; p.val = 723;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 8; p.county = 45; p.val = 1635;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 1; p.county = 45; p.val = 1219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 5; p.county = 45; p.val = 1247;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 8; p.county = 45; p.val = 2542;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 3; p.county = 45; p.val = 1058;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 15; p.county = 45; p.val = 3983;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 17; p.county = 45; p.val = 632;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 16; p.county = 45; p.val = 1615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 16; p.county = 45; p.val = 1073;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 12; p.county = 45; p.val = 4964;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 13; p.county = 45; p.val = 1410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 14; p.county = 45; p.val = 2542;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 14; p.county = 45; p.val = 1873;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 15; p.county = 45; p.val = 2576;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 8; p.county = 45; p.val = 2201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 8; p.county = 45; p.val = 1147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 11; p.county = 45; p.val = 1056;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 1; p.county = 45; p.val = 1494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 9; p.county = 45; p.val = 841;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 6; p.county = 45; p.val = 1904;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 4; p.county = 45; p.val = 1407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 14; p.county = 45; p.val = 1499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 4; p.county = 45; p.val = 1449;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 7; p.county = 45; p.val = 3763;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 6; p.county = 45; p.val = 2217;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 10; p.county = 45; p.val = 829;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 15; p.county = 45; p.val = 1279;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 16; p.county = 45; p.val = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 6; p.county = 45; p.val = 1453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 12; p.county = 45; p.val = 2691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 15; p.county = 45; p.val = 1905;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 5; p.county = 45; p.val = 1615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 14; p.county = 45; p.val = 1426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 7; p.county = 45; p.val = 1440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 16; p.county = 45; p.val = 1280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 18; p.county = 45; p.val = 1085;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 13; p.county = 45; p.val = 2672;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 32; p.county = 47; p.val = 1597;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 31; p.county = 47; p.val = 2564;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 33; p.county = 47; p.val = 742;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 32; p.county = 47; p.val = 961;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 27; p.county = 47; p.val = 186;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 35; p.county = 47; p.val = 592;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 32; p.county = 47; p.val = 1223;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 32; p.county = 47; p.val = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 31; p.county = 47; p.val = 1524;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 29; p.county = 47; p.val = 707;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 34; p.county = 47; p.val = 663;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 32; p.county = 47; p.val = 483;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 33; p.county = 47; p.val = 420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 37; p.county = 47; p.val = 362;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 37; p.county = 47; p.val = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 35; p.county = 47; p.val = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 26; p.county = 47; p.val = 740;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 27; p.county = 47; p.val = 117;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 29; p.county = 47; p.val = 752;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 36; p.county = 47; p.val = 147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 37; p.county = 47; p.val = 102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 29; p.county = 47; p.val = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 31; p.county = 47; p.val = 917;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 30; p.county = 47; p.val = 1082;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 30; p.county = 47; p.val = 617;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 30; p.county = 47; p.val = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 31; p.county = 47; p.val = 751;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 33; p.county = 47; p.val = 412;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 31; p.county = 47; p.val = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 33; p.county = 47; p.val = 485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 31; p.county = 47; p.val = 446;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 33; p.county = 47; p.val = 749;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 30; p.county = 47; p.val = 500;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 73; p.county = 49; p.val = 332;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 74; p.county = 49; p.val = 464;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 75; p.county = 49; p.val = 682;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 76; p.county = 49; p.val = 993;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 80; p.county = 49; p.val = 224;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 83; p.county = 49; p.val = 116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 80; p.county = 49; p.val = 899;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 79; p.county = 49; p.val = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 81; p.county = 49; p.val = 235;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 82; p.county = 49; p.val = 215;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 81; p.county = 49; p.val = 648;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 79; p.county = 49; p.val = 64;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 71; p.county = 49; p.val = 48;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 77; p.county = 49; p.val = 155;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 73; p.county = 49; p.val = 285;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 77; p.county = 49; p.val = 435;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 76; p.county = 49; p.val = 144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 75; p.county = 49; p.val = 225;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 40; p.county = 51; p.val = 845;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 38; p.county = 51; p.val = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 45; p.county = 51; p.val = 1416;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 45; p.county = 51; p.val = 789;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 44; p.county = 51; p.val = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 39; p.county = 51; p.val = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 43; p.county = 51; p.val = 614;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 42; p.county = 51; p.val = 878;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 42; p.county = 51; p.val = 737;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 44; p.county = 51; p.val = 2080;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 49; p.county = 51; p.val = 3220;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 41; p.county = 51; p.val = 809;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 40; p.county = 51; p.val = 291;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 38; p.county = 51; p.val = 857;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 37; p.county = 51; p.val = 650;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 39; p.county = 51; p.val = 230;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 39; p.county = 51; p.val = 464;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 36; p.county = 51; p.val = 94;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 41; p.county = 51; p.val = 590;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 42; p.county = 51; p.val = 259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 37; p.county = 51; p.val = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 43; p.county = 51; p.val = 863;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 37; p.county = 51; p.val = 391;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 41; p.county = 51; p.val = 1676;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 42; p.county = 51; p.val = 898;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 42; p.county = 51; p.val = 2786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 51; p.county = 51; p.val = 5160;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 46; p.county = 51; p.val = 2481;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 45; p.county = 51; p.val = 983;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 44; p.county = 51; p.val = 965;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 43; p.county = 51; p.val = 1247;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 45; p.county = 51; p.val = 2047;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 45; p.county = 51; p.val = 1354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 43; p.county = 51; p.val = 724;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 48; p.county = 51; p.val = 199;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 48; p.county = 51; p.val = 1038;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 48; p.county = 51; p.val = 1110;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 50; p.county = 51; p.val = 2691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 43; p.county = 51; p.val = 720;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 46; p.county = 51; p.val = 2271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 46; p.county = 51; p.val = 1143;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 36; p.county = 51; p.val = 1296;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 40; p.county = 51; p.val = 1199;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 36; p.county = 51; p.val = 96;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 35; p.county = 51; p.val = 361;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 41; p.county = 51; p.val = 882;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 46; p.county = 51; p.val = 1060;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 34; p.county = 51; p.val = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 32; p.county = 51; p.val = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 47; p.county = 51; p.val = 1846;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 47; p.county = 51; p.val = 1637;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 46; p.county = 51; p.val = 2576;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 51; p.val = 3021;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 52; p.county = 51; p.val = 2506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 51; p.county = 51; p.val = 2078;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 46; p.county = 51; p.val = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 49; p.county = 51; p.val = 1710;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 37; p.county = 51; p.val = 394;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 48; p.county = 51; p.val = 870;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 47; p.county = 51; p.val = 1928;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 42; p.county = 51; p.val = 924;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 43; p.county = 51; p.val = 1420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 43; p.county = 51; p.val = 1414;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 44; p.county = 51; p.val = 1843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 47; p.county = 51; p.val = 886;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 46; p.county = 51; p.val = 2977;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 47; p.county = 51; p.val = 251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 35; p.county = 51; p.val = 129;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 39; p.county = 51; p.val = 405;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 49; p.county = 51; p.val = 386;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 43; p.county = 51; p.val = 578;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 41; p.county = 51; p.val = 497;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 45; p.county = 51; p.val = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 44; p.county = 51; p.val = 1149;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 49; p.county = 51; p.val = 668;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 41; p.county = 51; p.val = 699;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 48; p.county = 51; p.val = 3147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 30; p.county = 51; p.val = 201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 50; p.county = 51; p.val = 4085;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 38; p.county = 51; p.val = 536;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 34; p.county = 51; p.val = 164;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 44; p.county = 51; p.val = 830;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 46; p.county = 51; p.val = 767;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 43; p.county = 51; p.val = 912;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 44; p.county = 51; p.val = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 36; p.county = 51; p.val = 411;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 40; p.county = 51; p.val = 338;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 44; p.county = 51; p.val = 1396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 41; p.county = 51; p.val = 695;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 42; p.county = 51; p.val = 1043;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 49; p.county = 51; p.val = 603;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 50; p.county = 51; p.val = 948;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 48; p.county = 51; p.val = 718;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 51; p.val = 1634;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 44; p.county = 51; p.val = 1482;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 51; p.county = 51; p.val = 1880;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 84; p.county = 53; p.val = 281;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 84; p.county = 53; p.val = 345;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 89; p.county = 53; p.val = 635;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 87; p.county = 53; p.val = 1045;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 81; p.county = 53; p.val = 454;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 93; p.county = 53; p.val = 805;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 93; p.county = 53; p.val = 422;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 99; p.county = 53; p.val = 972;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 91; p.county = 53; p.val = 666;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 85; p.county = 53; p.val = 395;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 87; p.county = 53; p.val = 471;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 89; p.county = 53; p.val = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 89; p.county = 53; p.val = 374;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 86; p.county = 53; p.val = 386;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 93; p.county = 53; p.val = 1622;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 29; p.county = 55; p.val = 595;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 30; p.county = 55; p.val = 458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 24; p.county = 55; p.val = 744;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 20; p.county = 55; p.val = 549;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 31; p.county = 55; p.val = 799;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 30; p.county = 55; p.val = 1424;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 29; p.county = 55; p.val = 492;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 27; p.county = 55; p.val = 714;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 32; p.county = 55; p.val = 802;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 32; p.county = 55; p.val = 2029;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 32; p.county = 55; p.val = 750;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 29; p.county = 55; p.val = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 34; p.county = 55; p.val = 961;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 33; p.county = 55; p.val = 1335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 33; p.county = 55; p.val = 718;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 32; p.county = 55; p.val = 640;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 23; p.county = 55; p.val = 209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 23; p.county = 55; p.val = 364;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 30; p.county = 55; p.val = 588;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 31; p.county = 55; p.val = 931;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 31; p.county = 55; p.val = 936;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 32; p.county = 55; p.val = 792;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 28; p.county = 55; p.val = 782;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 28; p.county = 55; p.val = 1160;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 30; p.county = 55; p.val = 423;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 29; p.county = 55; p.val = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 25; p.county = 55; p.val = 507;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 28; p.county = 55; p.val = 951;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 24; p.county = 55; p.val = 838;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 30; p.county = 55; p.val = 858;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 15; p.county = 57; p.val = 482;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 8; p.county = 57; p.val = 3694;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 14; p.county = 57; p.val = 471;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 20; p.county = 57; p.val = 295;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 17; p.county = 57; p.val = 957;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 20; p.county = 57; p.val = 683;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 15; p.county = 57; p.val = 765;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 20; p.county = 57; p.val = 817;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 21; p.county = 57; p.val = 835;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 14; p.county = 57; p.val = 1099;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 16; p.county = 57; p.val = 1101;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 15; p.county = 57; p.val = 517;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 15; p.county = 57; p.val = 724;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 15; p.county = 57; p.val = 1377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 14; p.county = 57; p.val = 980;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 12; p.county = 57; p.val = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 16; p.county = 57; p.val = 848;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 14; p.county = 57; p.val = 654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 17; p.county = 57; p.val = 380;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 18; p.county = 57; p.val = 674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 57; p.val = 1732;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 16; p.county = 57; p.val = 566;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 14; p.county = 57; p.val = 440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 13; p.county = 57; p.val = 625;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 12; p.county = 57; p.val = 715;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 11; p.county = 57; p.val = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 6; p.county = 57; p.val = 3111;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 7; p.county = 57; p.val = 1100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 6; p.county = 57; p.val = 1839;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 9; p.county = 57; p.val = 666;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 4; p.county = 57; p.val = 1815;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 9; p.county = 57; p.val = 2038;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 7; p.county = 57; p.val = 1378;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 22; p.county = 59; p.val = 1233;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 22; p.county = 59; p.val = 1342;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 23; p.county = 59; p.val = 518;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 22; p.county = 59; p.val = 792;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 21; p.county = 59; p.val = 615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 20; p.county = 59; p.val = 494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 23; p.county = 59; p.val = 621;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 23; p.county = 59; p.val = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 25; p.county = 59; p.val = 853;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 23; p.county = 59; p.val = 540;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 26; p.county = 59; p.val = 343;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 25; p.county = 59; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 16; p.county = 59; p.val = 799;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 17; p.county = 59; p.val = 400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 19; p.county = 59; p.val = 684;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 19; p.county = 59; p.val = 913;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 15; p.county = 59; p.val = 1109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 16; p.county = 59; p.val = 578;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 18; p.county = 59; p.val = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 20; p.county = 59; p.val = 642;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 29; p.county = 59; p.val = 912;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 27; p.county = 59; p.val = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 24; p.county = 59; p.val = 361;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 25; p.county = 59; p.val = 290;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 27; p.county = 59; p.val = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 21; p.county = 59; p.val = 1171;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 22; p.county = 59; p.val = 145;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 23; p.county = 59; p.val = 262;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 22; p.county = 59; p.val = 579;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 21; p.county = 59; p.val = 651;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 61; p.val = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 35; p.county = 61; p.val = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 32; p.county = 61; p.val = 355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 31; p.county = 61; p.val = 386;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 30; p.county = 61; p.val = 507;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 30; p.county = 61; p.val = 180;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 31; p.county = 61; p.val = 277;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 35; p.county = 61; p.val = 298;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 32; p.county = 61; p.val = 188;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 31; p.county = 61; p.val = 311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 36; p.county = 61; p.val = 422;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 33; p.county = 61; p.val = 322;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 33; p.county = 61; p.val = 162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 33; p.county = 61; p.val = 205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 29; p.county = 61; p.val = 279;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 38; p.county = 61; p.val = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 34; p.county = 61; p.val = 387;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 36; p.county = 61; p.val = 494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 29; p.county = 61; p.val = 111;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 27; p.county = 61; p.val = 82;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 35; p.county = 61; p.val = 107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 31; p.county = 61; p.val = 437;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 41; p.county = 63; p.val = 1059;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 43; p.county = 63; p.val = 737;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 37; p.county = 63; p.val = 1330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 38; p.county = 63; p.val = 1286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 41; p.county = 63; p.val = 1320;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 39; p.county = 63; p.val = 2564;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 38; p.county = 63; p.val = 4486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 40; p.county = 63; p.val = 1905;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 37; p.county = 63; p.val = 1467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 42; p.county = 63; p.val = 1128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 63; p.val = 1740;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 48; p.county = 63; p.val = 430;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 46; p.county = 63; p.val = 535;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 38; p.county = 63; p.val = 4588;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 40; p.county = 63; p.val = 1116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 39; p.county = 63; p.val = 1347;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 47; p.county = 63; p.val = 691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 44; p.county = 63; p.val = 670;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 43; p.county = 63; p.val = 976;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 41; p.county = 63; p.val = 752;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 46; p.county = 63; p.val = 665;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 45; p.county = 63; p.val = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 36; p.county = 63; p.val = 5725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 41; p.county = 63; p.val = 1038;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 41; p.county = 63; p.val = 1581;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 38; p.county = 63; p.val = 1604;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 43; p.county = 63; p.val = 497;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 40; p.county = 63; p.val = 1601;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 45; p.county = 63; p.val = 652;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 33; p.county = 63; p.val = 1646;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 40; p.county = 63; p.val = 2048;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 38; p.county = 63; p.val = 3034;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 39; p.county = 63; p.val = 938;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 42; p.county = 63; p.val = 1459;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 42; p.county = 63; p.val = 1965;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 38; p.county = 63; p.val = 2834;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 41; p.county = 63; p.val = 1402;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 35; p.county = 63; p.val = 2017;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 40; p.county = 63; p.val = 2193;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 37; p.county = 63; p.val = 1565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 39; p.county = 63; p.val = 1586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 40; p.county = 63; p.val = 400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 44; p.county = 63; p.val = 729;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 43; p.county = 63; p.val = 661;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 43; p.county = 63; p.val = 784;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 47; p.county = 63; p.val = 693;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 46; p.county = 63; p.val = 705;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 34; p.county = 63; p.val = 1024;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 41; p.county = 63; p.val = 897;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 42; p.county = 63; p.val = 1714;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 42; p.county = 63; p.val = 1311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 39; p.county = 63; p.val = 2244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 37; p.county = 63; p.val = 3444;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 44; p.county = 63; p.val = 675;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 35; p.county = 63; p.val = 4050;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 39; p.county = 63; p.val = 800;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 36; p.county = 63; p.val = 2085;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 36; p.county = 63; p.val = 1443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 39; p.county = 63; p.val = 4101;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 40; p.county = 63; p.val = 1682;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 37; p.county = 63; p.val = 1528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 35; p.county = 63; p.val = 1375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 35; p.county = 63; p.val = 1777;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 37; p.county = 63; p.val = 808;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 38; p.county = 63; p.val = 1644;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 38; p.county = 65; p.val = 207;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 41; p.county = 65; p.val = 339;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 41; p.county = 65; p.val = 1114;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 38; p.county = 65; p.val = 124;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 39; p.county = 65; p.val = 606;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 40; p.county = 65; p.val = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 42; p.county = 65; p.val = 483;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 43; p.county = 65; p.val = 518;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 45; p.county = 65; p.val = 150;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 47; p.county = 65; p.val = 234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 49; p.county = 65; p.val = 375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 43; p.county = 67; p.val = 782;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 38; p.county = 67; p.val = 203;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 36; p.county = 67; p.val = 685;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 35; p.county = 67; p.val = 397;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 32; p.county = 67; p.val = 748;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 31; p.county = 67; p.val = 722;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 33; p.county = 67; p.val = 1209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 33; p.county = 67; p.val = 636;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 30; p.county = 67; p.val = 144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 29; p.county = 67; p.val = 511;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 30; p.county = 67; p.val = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 31; p.county = 67; p.val = 687;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 33; p.county = 67; p.val = 765;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 31; p.county = 67; p.val = 887;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 33; p.county = 67; p.val = 707;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 30; p.county = 67; p.val = 390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 32; p.county = 67; p.val = 603;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 15; p.county = 69; p.val = 285;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 22; p.county = 69; p.val = 192;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 14; p.county = 69; p.val = 447;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 25; p.county = 69; p.val = 208;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 21; p.county = 69; p.val = 563;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 17; p.county = 69; p.val = 249;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 13; p.county = 69; p.val = 759;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 15; p.county = 69; p.val = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 20; p.county = 69; p.val = 816;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 19; p.county = 69; p.val = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 19; p.county = 69; p.val = 650;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 18; p.county = 69; p.val = 336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 17; p.county = 69; p.val = 1108;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 16; p.county = 69; p.val = 403;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 17; p.county = 69; p.val = 580;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 29; p.county = 71; p.val = 1745;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 29; p.county = 71; p.val = 936;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 27; p.county = 71; p.val = 318;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 28; p.county = 71; p.val = 170;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 31; p.county = 71; p.val = 397;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 32; p.county = 71; p.val = 521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 26; p.county = 71; p.val = 266;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 30; p.county = 71; p.val = 277;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 27; p.county = 71; p.val = 623;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 27; p.county = 71; p.val = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 34; p.county = 71; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 34; p.county = 71; p.val = 1057;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 31; p.county = 71; p.val = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 23; p.county = 71; p.val = 51;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 28; p.county = 71; p.val = 321;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 31; p.county = 71; p.val = 92;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 30; p.county = 71; p.val = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 31; p.county = 71; p.val = 894;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 31; p.county = 71; p.val = 415;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 33; p.county = 71; p.val = 501;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 28; p.county = 71; p.val = 590;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 33; p.county = 71; p.val = 329;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 22; p.county = 71; p.val = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 24; p.county = 71; p.val = 434;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 15; p.county = 73; p.val = 136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 20; p.county = 73; p.val = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 15; p.county = 73; p.val = 1499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 22; p.county = 73; p.val = 637;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 18; p.county = 73; p.val = 1107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 15; p.county = 73; p.val = 240;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 12; p.county = 73; p.val = 1076;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 13; p.county = 73; p.val = 261;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 9; p.county = 73; p.val = 630;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 17; p.county = 73; p.val = 379;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 15; p.county = 73; p.val = 1008;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 19; p.county = 73; p.val = 776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 18; p.county = 73; p.val = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 16; p.county = 73; p.val = 666;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 7; p.county = 73; p.val = 1171;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 11; p.county = 73; p.val = 1437;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 13; p.county = 73; p.val = 1296;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 17; p.county = 73; p.val = 711;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 20; p.county = 73; p.val = 923;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 8; p.county = 73; p.val = 812;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 19; p.county = 73; p.val = 714;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 16; p.county = 73; p.val = 3190;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 12; p.county = 73; p.val = 1657;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 13; p.county = 73; p.val = 1122;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 18; p.county = 73; p.val = 1493;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 15; p.county = 73; p.val = 792;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 14; p.county = 73; p.val = 996;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 15; p.county = 73; p.val = 997;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 17; p.county = 73; p.val = 749;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 55; p.county = 75; p.val = 540;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 55; p.county = 75; p.val = 1277;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 54; p.county = 75; p.val = 1097;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 54; p.county = 75; p.val = 2711;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 56; p.county = 75; p.val = 677;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 56; p.county = 75; p.val = 228;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 55; p.county = 75; p.val = 410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 61; p.county = 75; p.val = 433;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 56; p.county = 75; p.val = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 53; p.county = 75; p.val = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 53; p.county = 75; p.val = 1407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 57; p.county = 75; p.val = 348;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 59; p.county = 75; p.val = 685;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 62; p.county = 75; p.val = 587;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 64; p.county = 75; p.val = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 58; p.county = 75; p.val = 383;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 56; p.county = 75; p.val = 789;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 59; p.county = 75; p.val = 569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 55; p.county = 75; p.val = 400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 57; p.county = 75; p.val = 819;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 61; p.county = 75; p.val = 895;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 59; p.county = 75; p.val = 1055;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 55; p.county = 75; p.val = 310;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 60; p.county = 75; p.val = 1025;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 52; p.county = 75; p.val = 935;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 53; p.county = 75; p.val = 1205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 53; p.county = 75; p.val = 556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 50; p.county = 75; p.val = 750;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 51; p.county = 75; p.val = 722;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 56; p.county = 75; p.val = 780;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 55; p.county = 75; p.val = 682;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 57; p.county = 75; p.val = 658;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 54; p.county = 75; p.val = 805;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 56; p.county = 75; p.val = 656;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 54; p.county = 75; p.val = 661;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 57; p.county = 75; p.val = 954;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 55; p.county = 75; p.val = 571;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 52; p.county = 75; p.val = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 53; p.county = 75; p.val = 614;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 57; p.county = 75; p.val = 704;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 53; p.county = 75; p.val = 507;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 59; p.county = 75; p.val = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 17; p.county = 77; p.val = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 16; p.county = 77; p.val = 376;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 16; p.county = 77; p.val = 1088;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 15; p.county = 77; p.val = 1543;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 16; p.county = 77; p.val = 1121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 15; p.county = 77; p.val = 844;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 14; p.county = 77; p.val = 592;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 13; p.county = 77; p.val = 752;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 13; p.county = 77; p.val = 648;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 10; p.county = 77; p.val = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 12; p.county = 77; p.val = 827;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 10; p.county = 77; p.val = 754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 9; p.county = 77; p.val = 720;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 10; p.county = 77; p.val = 689;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 11; p.county = 77; p.val = 833;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 11; p.county = 77; p.val = 494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 5; p.county = 77; p.val = 871;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 5; p.county = 77; p.val = 908;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 7; p.county = 77; p.val = 874;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 8; p.county = 77; p.val = 1336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 10; p.county = 77; p.val = 686;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 9; p.county = 77; p.val = 625;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 12; p.county = 77; p.val = 660;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 13; p.county = 77; p.val = 706;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 12; p.county = 77; p.val = 1126;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 14; p.county = 77; p.val = 708;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 12; p.county = 77; p.val = 1765;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 11; p.county = 77; p.val = 1894;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 12; p.county = 77; p.val = 3528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 10; p.county = 77; p.val = 1316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 10; p.county = 77; p.val = 1340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 11; p.county = 77; p.val = 1331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 11; p.county = 77; p.val = 639;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 12; p.county = 77; p.val = 1202;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 11; p.county = 77; p.val = 1193;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 10; p.county = 77; p.val = 1141;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 8; p.county = 77; p.val = 568;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 8; p.county = 77; p.val = 424;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 6; p.county = 77; p.val = 627;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 13; p.county = 77; p.val = 517;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 38; p.county = 79; p.val = 5874;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 37; p.county = 79; p.val = 4920;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 37; p.county = 79; p.val = 5544;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 37; p.county = 79; p.val = 5993;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 35; p.county = 79; p.val = 3777;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 37; p.county = 79; p.val = 716;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 36; p.county = 79; p.val = 2505;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 34; p.county = 79; p.val = 1822;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 33; p.county = 79; p.val = 1827;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 34; p.county = 79; p.val = 3068;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 39; p.county = 79; p.val = 726;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 39; p.county = 79; p.val = 5630;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 40; p.county = 79; p.val = 1077;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 38; p.county = 79; p.val = 6081;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 36; p.county = 79; p.val = 2191;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 42; p.county = 79; p.val = 750;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 39; p.county = 79; p.val = 4710;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 35; p.county = 79; p.val = 5274;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 35; p.county = 79; p.val = 734;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 36; p.county = 79; p.val = 1738;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 41; p.county = 79; p.val = 850;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 37; p.county = 79; p.val = 1982;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 39; p.county = 79; p.val = 3377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 34; p.county = 79; p.val = 4131;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 33; p.county = 79; p.val = 3068;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 44; p.county = 79; p.val = 844;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 36; p.county = 79; p.val = 2095;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 31; p.county = 79; p.val = 1168;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 32; p.county = 79; p.val = 2762;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 33; p.county = 79; p.val = 1004;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 31; p.county = 79; p.val = 1915;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 32; p.county = 79; p.val = 1494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 34; p.county = 79; p.val = 1504;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 44; p.county = 79; p.val = 747;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 34; p.county = 79; p.val = 3770;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 33; p.county = 79; p.val = 6637;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 36; p.county = 79; p.val = 2624;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 33; p.county = 79; p.val = 1527;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 38; p.county = 79; p.val = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 39; p.county = 79; p.val = 1146;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 33; p.county = 79; p.val = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 35; p.county = 79; p.val = 1765;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 40; p.county = 79; p.val = 284;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 31; p.county = 79; p.val = 1125;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 33; p.county = 79; p.val = 1275;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 32; p.county = 79; p.val = 1757;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 35; p.county = 79; p.val = 1101;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 33; p.county = 79; p.val = 6452;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 40; p.county = 79; p.val = 682;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 35; p.county = 79; p.val = 4279;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 40; p.county = 79; p.val = 466;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 34; p.county = 79; p.val = 2869;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 35; p.county = 79; p.val = 1338;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 34; p.county = 79; p.val = 988;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 32; p.county = 79; p.val = 1399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 34; p.county = 79; p.val = 1271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 41; p.county = 79; p.val = 614;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 38; p.county = 79; p.val = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 35; p.county = 81; p.val = 283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 39; p.county = 81; p.val = 163;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 38; p.county = 81; p.val = 259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 34; p.county = 81; p.val = 363;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 36; p.county = 81; p.val = 591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 40; p.county = 81; p.val = 536;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 36; p.county = 81; p.val = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 39; p.county = 81; p.val = 561;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 39; p.county = 81; p.val = 397;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 38; p.county = 81; p.val = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 42; p.county = 81; p.val = 124;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 35; p.county = 81; p.val = 768;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 41; p.county = 81; p.val = 322;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 43; p.county = 81; p.val = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 38; p.county = 81; p.val = 145;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 38; p.county = 81; p.val = 579;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 38; p.county = 81; p.val = 336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 42; p.county = 81; p.val = 238;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 13; p.county = 83; p.val = 503;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 7; p.county = 83; p.val = 1639;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 7; p.county = 83; p.val = 2360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 10; p.county = 83; p.val = 1626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 1; p.county = 83; p.val = 1119;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 6; p.county = 83; p.val = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 5; p.county = 83; p.val = 891;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 12; p.county = 83; p.val = 695;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 7; p.county = 83; p.val = 708;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 3; p.county = 83; p.val = 849;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 12; p.county = 83; p.val = 982;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 11; p.county = 83; p.val = 581;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 10; p.county = 83; p.val = 1160;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 8; p.county = 83; p.val = 1748;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 9; p.county = 83; p.val = 1123;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 4; p.county = 83; p.val = 2458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 3; p.county = 83; p.val = 3245;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 4; p.county = 83; p.val = 744;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 2; p.county = 83; p.val = 1371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 5; p.county = 83; p.val = 1400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 10; p.county = 83; p.val = 970;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 3; p.county = 83; p.val = 927;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 4; p.county = 83; p.val = 1491;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 0; p.county = 83; p.val = 1528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 3; p.county = 83; p.val = 637;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 5; p.county = 83; p.val = 2905;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 6; p.county = 83; p.val = 2176;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 5; p.county = 83; p.val = 530;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 14; p.county = 83; p.val = 488;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 8; p.county = 83; p.val = 1663;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 16; p.county = 83; p.val = 375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 1; p.county = 83; p.val = 1694;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 6; p.county = 83; p.val = 1099;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 17; p.county = 83; p.val = 654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 6; p.county = 83; p.val = 1106;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 4; p.county = 83; p.val = 1626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 7; p.county = 83; p.val = 2044;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 10; p.county = 83; p.val = 1467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 11; p.county = 83; p.val = 1815;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 7; p.county = 83; p.val = 3377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 8; p.county = 83; p.val = 2043;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 7; p.county = 83; p.val = 2204;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 8; p.county = 83; p.val = 457;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 8; p.county = 83; p.val = 821;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 13; p.county = 83; p.val = 1486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 7; p.county = 83; p.val = 1253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 5; p.county = 83; p.val = 766;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 9; p.county = 83; p.val = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 5; p.county = 83; p.val = 1282;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 3; p.county = 83; p.val = 1132;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 6; p.county = 83; p.val = 615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 8; p.county = 83; p.val = 1773;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 4; p.county = 83; p.val = 1047;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 11; p.county = 83; p.val = 1556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 9; p.county = 83; p.val = 2138;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 4; p.county = 83; p.val = 593;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 3; p.county = 83; p.val = 738;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 7; p.county = 83; p.val = 2877;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 9; p.county = 83; p.val = 1132;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 1; p.county = 83; p.val = 1326;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 9; p.county = 83; p.val = 2705;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 15; p.county = 83; p.val = 1123;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 9; p.county = 83; p.val = 1469;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 6; p.county = 83; p.val = 1109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 6; p.county = 83; p.val = 930;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 6; p.county = 83; p.val = 449;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 8; p.county = 83; p.val = 3122;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 8; p.county = 83; p.val = 1437;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 5; p.county = 83; p.val = 809;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 10; p.county = 83; p.val = 1627;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 35; p.county = 85; p.val = 1097;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 38; p.county = 85; p.val = 349;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 37; p.county = 85; p.val = 489;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 39; p.county = 85; p.val = 1153;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 38; p.county = 85; p.val = 1325;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 41; p.county = 85; p.val = 268;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 39; p.county = 85; p.val = 703;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 43; p.county = 85; p.val = 735;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 44; p.county = 85; p.val = 972;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 41; p.county = 85; p.val = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 40; p.county = 85; p.val = 1135;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 43; p.county = 85; p.val = 769;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 46; p.county = 85; p.val = 892;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 45; p.county = 85; p.val = 553;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 43; p.county = 85; p.val = 884;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 38; p.county = 85; p.val = 711;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 44; p.county = 85; p.val = 691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 42; p.county = 85; p.val = 1728;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 39; p.county = 85; p.val = 1031;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 36; p.county = 85; p.val = 537;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 38; p.county = 85; p.val = 710;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 41; p.county = 85; p.val = 2078;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 42; p.county = 85; p.val = 584;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 40; p.county = 85; p.val = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 41; p.county = 85; p.val = 2941;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 39; p.county = 85; p.val = 438;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 40; p.county = 85; p.val = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 40; p.county = 85; p.val = 3727;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 42; p.county = 85; p.val = 1314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 40; p.county = 85; p.val = 1005;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 41; p.county = 85; p.val = 1116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 42; p.county = 85; p.val = 459;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 40; p.county = 85; p.val = 1590;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 39; p.county = 85; p.val = 59;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 39; p.county = 85; p.val = 754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 14; p.county = 87; p.val = 393;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 20; p.county = 87; p.val = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 13; p.county = 87; p.val = 480;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 14; p.county = 87; p.val = 414;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 10; p.county = 87; p.val = 513;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 11; p.county = 87; p.val = 591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 11; p.county = 87; p.val = 523;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 13; p.county = 87; p.val = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 14; p.county = 87; p.val = 848;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 15; p.county = 87; p.val = 152;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 14; p.county = 87; p.val = 420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 14; p.county = 87; p.val = 927;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 15; p.county = 87; p.val = 892;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 20; p.county = 87; p.val = 287;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 18; p.county = 87; p.val = 477;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 17; p.county = 87; p.val = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 15; p.county = 87; p.val = 147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 17; p.county = 87; p.val = 679;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 13; p.county = 87; p.val = 215;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 46; p.county = 89; p.val = 192;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 52; p.county = 89; p.val = 457;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 89; p.val = 268;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 57; p.county = 89; p.val = 340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 55; p.county = 89; p.val = 205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 44; p.county = 89; p.val = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 47; p.county = 89; p.val = 737;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 49; p.county = 89; p.val = 187;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 51; p.county = 89; p.val = 466;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 52; p.county = 89; p.val = 683;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 46; p.county = 89; p.val = 842;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 48; p.county = 89; p.val = 316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 49; p.county = 89; p.val = 1341;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 49; p.county = 89; p.val = 310;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 47; p.county = 89; p.val = 864;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 50; p.county = 89; p.val = 547;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 54; p.county = 89; p.val = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 52; p.county = 89; p.val = 151;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 49; p.county = 89; p.val = 217;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 50; p.county = 89; p.val = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 43; p.county = 89; p.val = 137;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 53; p.county = 89; p.val = 238;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 52; p.county = 89; p.val = 591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 45; p.county = 89; p.val = 171;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 58; p.county = 89; p.val = 145;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 55; p.county = 89; p.val = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 46; p.county = 89; p.val = 503;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 46; p.county = 89; p.val = 209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 2; p.county = 91; p.val = 1092;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 1; p.county = 91; p.val = 1967;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 2; p.county = 91; p.val = 1983;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 4; p.county = 91; p.val = 359;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 4; p.county = 91; p.val = 4244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 2; p.county = 91; p.val = 1620;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 1; p.county = 91; p.val = 762;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 10; p.county = 91; p.val = 259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 7; p.county = 91; p.val = 586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 5; p.county = 91; p.val = 674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 8; p.county = 91; p.val = 847;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 10; p.county = 91; p.val = 877;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 10; p.county = 91; p.val = 1218;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 11; p.county = 91; p.val = 1465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 4; p.county = 91; p.val = 837;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 9; p.county = 91; p.val = 1112;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 10; p.county = 91; p.val = 1596;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 6; p.county = 91; p.val = 2054;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 7; p.county = 91; p.val = 742;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 6; p.county = 91; p.val = 1106;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 6; p.county = 91; p.val = 821;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 6; p.county = 91; p.val = 1201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 6; p.county = 91; p.val = 4525;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 3; p.county = 91; p.val = 1485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 5; p.county = 91; p.val = 895;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 7; p.county = 91; p.val = 5266;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 7; p.county = 91; p.val = 4200;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 6; p.county = 91; p.val = 1613;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 91; p.val = 1073;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 8; p.county = 91; p.val = 4424;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 9; p.county = 91; p.val = 1894;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 3; p.county = 91; p.val = 1251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 5; p.county = 91; p.val = 2538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 9; p.county = 91; p.val = 1422;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 8; p.county = 91; p.val = 1126;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 5; p.county = 91; p.val = 3004;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 9; p.county = 91; p.val = 1535;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 4; p.county = 91; p.val = 3619;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 3; p.county = 91; p.val = 2554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 5; p.county = 91; p.val = 1591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 7; p.county = 91; p.val = 1761;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 4; p.county = 91; p.val = 1201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 7; p.county = 91; p.val = 2162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 4; p.county = 91; p.val = 3863;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 6; p.county = 91; p.val = 1143;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 7; p.county = 91; p.val = 999;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 9; p.county = 91; p.val = 524;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 8; p.county = 91; p.val = 1000;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 1; p.county = 91; p.val = 659;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 8; p.county = 91; p.val = 1490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 2; p.county = 91; p.val = 756;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 2; p.county = 91; p.val = 677;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 3; p.county = 91; p.val = 870;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 4; p.county = 91; p.val = 1201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 5; p.county = 91; p.val = 1901;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 3; p.county = 91; p.val = 2212;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 13; p.county = 23; p.val = 601;
points[i]=p;i++;}
return points;}










struct Map {
	std::map<int,std::map<int,Point> > pixels;
	int width;
	int height;
};




Map horizontalStitch(Map m, int n, int l){
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
		
	}
	int h = m.height;
	int w = m.width;
	int modn = h / n;
	for(i=1;i<w;i++){
		for(ii=0;ii<h;ii++){
			int mpv = m.pixels[i][ii].val;

			int top = -1000000000;
			if (ii%modn>0){top = oldMax[ii-1];}
			int maxv = top;
			int newI = ii-1;
			int mid = oldMax[ii];
			if (mid > maxv){
				maxv = mid;
				newI = ii;
			}
			int bottom = -1000000000;
			if (ii+1<h && (ii+1)%modn>0){bottom = oldMax[ii+1];}
			if (bottom > maxv){
				maxv = bottom;
				newI = ii+1;
			}
			
			
			
			newMax[ii] = maxv+mpv;

			
			newSeams[ii] = oldSeams[newI];
			newSeams[ii].push_back(ii);
		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	for (iii=n-1;iii>=0;iii--){
		int maxSeam = -1000000000;
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

		for(i=0;i<w;i++){
			
			for(ii=m.height;ii>removeSeam[i];ii--){
				m.pixels[i][ii]=m.pixels[i][ii-1];
			}
			m.pixels[i][removeSeam[i]].county =m.pixels[i][removeSeam[i]+1].county;
			int v = m.pixels[i][removeSeam[i]+1].val;
			m.pixels[i][removeSeam[i]].val = v/2;
			m.pixels[i][removeSeam[i]+1].val = v - v/2;
		}
		m.height++;
		
	}
	
	
	return m;
}

Map verticalStitch(Map m, int n, int l){
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
		
	}
	int h = m.height;
	int w = m.width;
	int modn = w / n;
	for(ii=1;ii<h;ii++){
		for(i=0;i<w;i++){
			int mpv = m.pixels[i][ii].val;

			int left = -1000000000;
			if (i%modn>0){left = oldMax[i-1];}
			int maxv = left;
			int newI = i-1;
			int mid = oldMax[i];
			if (mid > maxv){
				maxv = mid;
				newI = i;
			}
			int right = -1000000000;
			if (i+1<w && (i+1) % modn>0){right = oldMax[i+1];}
			if (right> maxv){
				maxv = right;
				newI = i+1;
			}
			
			
			newMax[i] = maxv+mpv;

			newSeams[i] = oldSeams[newI];
			newSeams[i].push_back(i);

		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	//std::vector<int> removeSeams;
	for (iii=n-1;iii>=0;iii--){
		int maxSeam = -1000000000;

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
		for(ii=0;ii<h;ii++){
			
			for(i=m.width;i>removeSeam[ii];i--){
			
				m.pixels[i][ii]=m.pixels[i-1][ii];
			}
			m.pixels[removeSeam[ii]][ii].county=m.pixels[removeSeam[ii]+1][ii].county;
			int v = m.pixels[removeSeam[ii]+1][ii].val;
			m.pixels[removeSeam[ii]][ii].val=v/2;
			m.pixels[removeSeam[ii]+1][ii].val= v - v/2;
		}
		m.width++;
	}

	
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
		
	}
	int h = m.height;
	int w = m.width;
	int modn = h / n;
	for(i=1;i<w;i++){
		for(ii=0;ii<h;ii++){
			int mpv = m.pixels[i][ii].val;

			int top = 1000000000;
			if (ii%modn>0){top = oldMax[ii-1];}
			int maxv = top;
			int newI = ii-1;
			int mid = oldMax[ii];
			if (mid < maxv){
				maxv = mid;
				newI = ii;
			}
			int bottom = 1000000000;
			if (ii+1<h && (ii+1)%modn>0){bottom = oldMax[ii+1];}
			if (bottom < maxv){
				maxv = bottom;
				newI = ii+1;
			}
			
			
			
			newMax[ii] = maxv+mpv;

			
			newSeams[ii] = oldSeams[newI];
			newSeams[ii].push_back(ii);
		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	for (iii=n-1;iii>=0;iii--){
		int minSeam = 1000000000;
		std::vector<int> removeSeam;
		int maxY = (iii+1)*modn;
		if (maxY > h){
			maxY = h;
		}
		for (ii=iii*modn;ii<maxY;ii++){
			if (oldMax[ii]<minSeam){
				minSeam = oldMax[ii];
				removeSeam = oldSeams[ii];
			}
		}

		for(i=0;i<w;i++){
			m.pixels[i][removeSeam[i]].val +=m.pixels[i][removeSeam[i]+1].val;
			for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
				m.pixels[i][ii]=m.pixels[i][ii+1];
			}
		}
		m.height--;
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
		
	}
	int h = m.height;
	int w = m.width;
	int modn = w / n;
	for(ii=1;ii<h;ii++){
		for(i=0;i<w;i++){
			int mpv = m.pixels[i][ii].val;

			int left = 1000000000;
			if (i%modn>0){left = oldMax[i-1];}
			int maxv = left;
			int newI = i-1;
			int mid = oldMax[i];
			if (mid < maxv){
				maxv = mid;
				newI = i;
			}
			int right = 1000000000;
			if (i+1<w && (i+1) % modn>0){right = oldMax[i+1];}
			if (right< maxv){
				maxv = right;
				newI = i+1;
			}
			
			
			newMax[i] = maxv+mpv;

			newSeams[i] = oldSeams[newI];
			newSeams[i].push_back(i);

		}
		oldSeams = newSeams;
		oldMax = newMax;
	}
	//std::vector<int> removeSeams;
	for (iii=n-1;iii>=0;iii--){
		int minSeam = 1000000000;

		std::vector<int> removeSeam;
		int maxX = (iii+1)*modn;
		if (maxX > w){
			maxX = w;
		}
		for (i=iii*modn;i<maxX;i++){
			if (oldMax[i]<minSeam){
				minSeam = oldMax[i];
				removeSeam = oldSeams[i];
			}
		}
		if (l >= 0){
			for(ii=0;ii<h;ii++){
				m.pixels[removeSeam[ii]][ii].val+=m.pixels[removeSeam[ii]+1][ii].val;
				for(i=removeSeam[ii]+1;i<m.width-1;i++){
				
					m.pixels[i][ii]=m.pixels[i+1][ii];
				}
			}
			
			m.width--;
			console_log(sum(m));
		}
	}

	
	return m;
}

int sum(Map m){
	int i; int ii; int sum = 0;
	for (i=0;i<m.width;i++){
		for (ii=0;ii<m.height;ii++){
			sum += m.pixels[i][ii].val;
		}
	}
	return sum;
}
void initialRun(){
	seed = 7;
	srand(seed);
	int i;
	int ii;
	int iii;
	std::map<int,Point> points;
	
	killCarveV = false;
	killCarveH = false;
	
	auto a11 = std::chrono::high_resolution_clock::now();
	
	std::map<int,std::map<int,Point>> pixels;
	std::map<int,std::map<int,int>> pixelMap;
	for(i=0;i<100;i++){
		std::map<int,Point> v;
		pixels[i] = v;
		std::map<int,int> vv;
		pixelMap[i]=vv;
		for(ii=0;ii<100;ii++){
			Point p;
			p.x = i;
			p.y = ii;
			p.val = 0;
			pixels[i][ii] = p;
			pixelMap[i][ii] = -1;
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
	int np = 1559;
	for(i=0;i<np;i++){
		points[i].npix = 0;
		pixelMap[points[i].x][points[i].y]=i;
	}
	
	for(i=0;i<100;i++){
		for(ii=0;ii<100;ii++){
			if (pixelMap[i][ii]>=0){
				points[pixelMap[i][ii]].npix++;
				continue;
			}
			int minX = i-4;
			int maxX = i+4;
			int minY = ii-4;
			int maxY = ii+4;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > 100){maxX = 100;}
			if (maxY > 100){maxY = 100;}
			int iiii;
			int minP = 1000000000;
			int d;
			int minI = 0;
			for (iii=minX;iii<maxX+1;iii++){
				for (iiii=minY;iiii<maxY+1;iiii++){
					if (pixelMap[iii][iiii]>=0){
						d = (iii-i)*(iii-i)+(iiii-ii)*(iiii-ii);
						if (d < minP){
							minP = d;
							minI = pixelMap[iii][iiii];
						}
					}
				}
			}
			if (minP < 1000000000){
				points[minI].npix++;
				continue;
			}
			
			for (iii=0;iii<np;iii++){
				d = (points[iii].x-i)*(points[iii].x-i)+(points[iii].y-ii)*(points[iii].y-ii);
				if (d < minP){
					minP = d;
					minI = iii;
				}
			}
			points[minI].npix++;
		}
	}
	
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationTotal);
	
	for(i=0;i<100;i++){
		for(ii=0;ii<100;ii++){
			if (pixelMap[i][ii]>=0){
				pixels[i][ii].val += points[pixelMap[i][ii]].val*100/points[pixelMap[i][ii]].npix;
				pixels[i][ii].county = points[pixelMap[i][ii]].county;
				continue;
			}
			int minX = i-4;
			int maxX = i+4;
			int minY = ii-4;
			int maxY = ii+4;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > 100){maxX = 100;}
			if (maxY > 100){maxY = 100;}
			int iiii;
			int minP = 1000000000;
			int d;
			int minI = 0;
			for (iii=minX;iii<maxX+1;iii++){
				for (iiii=minY;iiii<maxY+1;iiii++){
					if (pixelMap[iii][iiii]>=0){
						d = (iii-i)*(iii-i)+(iiii-ii)*(iiii-ii);
						if (d < minP){
							minP = d;
							minI = pixelMap[iii][iiii];
						}
					}
				}
			}
			if (minP < 1000000000){
				pixels[i][ii].val += points[minI].val*100/points[minI].npix;
				pixels[i][ii].county = points[minI].county;
				continue;
			}
			
			for (iii=0;iii<np;iii++){
				d = (points[iii].x-i)*(points[iii].x-i)+(points[iii].y-ii)*(points[iii].y-ii);
				if (d < minP){
					minP = d;
					minI = iii;
				}
			}
			pixels[i][ii].val += points[minI].val*100/points[minI].npix;
			pixels[i][ii].county = points[minI].county;
		}
	}
	
	
	a11 = std::chrono::high_resolution_clock::now();
	

	
	Map m;
	m.pixels = pixels;
	m.width = 100;
	m.height = 100;
	
	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationTotal);
	
	a11 = std::chrono::high_resolution_clock::now();
	
	set_maxX(m.width);
	set_maxY(m.height);
	for (iii=0;iii<1;iii++){
		vertThreads = 1 + (rand() % 20);
		horzThreads = 1 + (rand() % 20);
		if (iii%5 == 0){
			for(i=0;i<m.width;i++){
				for(ii=0;ii<m.height;ii++){
					Point p = m.pixels[i][ii];
					std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county);
					add_pointOut(pointStr.c_str());
				}
			}
			display_points();
		}
		console_log(sum(m));
		m = verticalSeam(m,vertThreads,1);
		console_log(sum(m));
		m = horizontalSeam(m,horzThreads,1);
		console_log(sum(m));
		m = verticalStitch(m,vertThreads,1);
		console_log(sum(m));
		m = horizontalStitch(m,horzThreads,1);
		console_log(sum(m));

	}
	
	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(m.width);
	console_log(m.height);
	
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
