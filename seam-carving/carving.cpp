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
std::map<int,int> xCount;
std::map<int,int> yCount;

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
p.x = 124; p.y = 636; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 116; p.y = 568; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 681; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 561; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 130; p.y = 711; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 149; p.y = 722; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 631; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 150; p.y = 610; p.county = 1;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 278; p.y = 341; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 292; p.y = 338; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 279; p.y = 383; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 304; p.y = 368; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 290; p.y = 346; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 291; p.y = 342; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 299; p.y = 322; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 297; p.y = 285; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 248; p.y = 292; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 262; p.y = 267; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 295; p.y = 288; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 246; p.y = 306; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 293; p.y = 317; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 261; p.y = 311; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 320; p.y = 411; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 354; p.y = 363; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 230; p.y = 303; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 344; p.y = 340; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 224; p.y = 305; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 264; p.y = 361; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 269; p.y = 330; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 329; p.y = 320; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 282; p.y = 351; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 257; p.y = 290; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 255; p.y = 337; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 312; p.y = 339; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 236; p.y = 347; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 271; p.y = 321; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 233; p.y = 336; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 300; p.y = 296; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 221; p.y = 325; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 281; p.y = 302; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 294; p.y = 328; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 274; p.y = 314; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 286; p.y = 312; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 251; p.y = 276; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 287; p.y = 327; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 239; p.y = 332; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 234; p.y = 313; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 285; p.y = 307; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 272; p.y = 333; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 283; p.y = 316; p.county = 3;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 352; p.y = 219; p.county = 5;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 366; p.y = 198; p.county = 5;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 328; p.y = 232; p.county = 5;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 380; p.y = 220; p.county = 5;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 755; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 768; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 791; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 689; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 787; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 779; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 797; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 822; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 774; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 764; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 782; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 730; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 863; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 778; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 720; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 110; p.y = 733; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 770; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 747; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 734; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 777; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 796; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 745; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 843; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 838; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 775; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 806; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 801; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 789; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 769; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 761; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 753; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 748; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 750; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 762; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 737; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 760; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 767; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 757; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 766; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 739; p.county = 7;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 421; p.y = 240; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 448; p.y = 236; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 391; p.y = 255; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 485; p.y = 244; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 503; p.y = 235; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 443; p.y = 258; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 449; p.y = 264; p.county = 9;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 342; p.y = 263; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 337; p.y = 251; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 369; p.y = 269; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 356; p.y = 248; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 358; p.y = 283; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 331; p.y = 252; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 333; p.y = 271; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 316; p.y = 254; p.county = 11;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 602; p.y = 39; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 566; p.y = 37; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 586; p.y = 32; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 584; p.y = 43; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 590; p.y = 34; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 591; p.y = 36; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 553; p.y = 33; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 498; p.y = 31; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 607; p.y = 35; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 612; p.y = 45; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 600; p.y = 44; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 609; p.y = 49; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 576; p.y = 48; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 557; p.y = 53; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 560; p.y = 41; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 616; p.y = 27; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 629; p.y = 38; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 637; p.y = 30; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 604; p.y = 42; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 581; p.y = 9; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 573; p.y = 8; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 608; p.y = 7; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 601; p.y = 4; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 587; p.y = 21; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 571; p.y = 14; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 578; p.y = 20; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 580; p.y = 13; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 577; p.y = 11; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 568; p.y = 5; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 565; p.y = 3; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 575; p.y = 0; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 558; p.y = 1; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 537; p.y = 24; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 530; p.y = 18; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 507; p.y = 23; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 469; p.y = 25; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 474; p.y = 19; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 528; p.y = 10; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 535; p.y = 15; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 509; p.y = 12; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 494; p.y = 6; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 512; p.y = 29; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 522; p.y = 16; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 515; p.y = 17; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 488; p.y = 22; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 466; p.y = 26; p.county = 13;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 876; p.y = 247; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 790; p.y = 266; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 799; p.y = 259; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 820; p.y = 291; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 758; p.y = 212; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 853; p.y = 196; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 797; p.y = 246; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 738; p.y = 231; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 709; p.y = 224; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 736; p.y = 257; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 890; p.y = 261; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 658; p.y = 250; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 714; p.y = 241; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 836; p.y = 143; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 742; p.y = 223; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 745; p.y = 218; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 786; p.y = 154; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 748; p.y = 204; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 775; p.y = 253; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 771; p.y = 245; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 719; p.y = 226; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 686; p.y = 234; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 729; p.y = 225; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 732; p.y = 207; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 801; p.y = 203; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 746; p.y = 237; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 831; p.y = 126; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 827; p.y = 160; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 721; p.y = 214; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 798; p.y = 159; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 783; p.y = 242; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 773; p.y = 167; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 807; p.y = 174; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 768; p.y = 192; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 774; p.y = 181; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 741; p.y = 213; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 705; p.y = 215; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 772; p.y = 185; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 712; p.y = 233; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 703; p.y = 229; p.county = 15;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 589; p.y = 343; p.county = 17;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 605; p.y = 356; p.county = 17;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 518; p.y = 386; p.county = 17;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 621; p.y = 362; p.county = 17;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 499; p.y = 378; p.county = 17;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 570; p.y = 369; p.county = 17;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 892; p.y = 227; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 744; p.y = 175; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 847; p.y = 86; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 870; p.y = 112; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 849; p.y = 92; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 856; p.y = 118; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 840; p.y = 120; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 861; p.y = 69; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 909; p.y = 230; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 679; p.y = 58; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 747; p.y = 52; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 755; p.y = 172; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 700; p.y = 206; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 862; p.y = 99; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 656; p.y = 50; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 826; p.y = 79; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 816; p.y = 80; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 841; p.y = 62; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 825; p.y = 95; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 819; p.y = 90; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 817; p.y = 115; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 824; p.y = 87; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 811; p.y = 84; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 814; p.y = 96; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 808; p.y = 104; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 813; p.y = 102; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 805; p.y = 117; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 845; p.y = 89; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 834; p.y = 108; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 848; p.y = 81; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 843; p.y = 106; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 854; p.y = 107; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 863; p.y = 121; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 857; p.y = 122; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 842; p.y = 132; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 860; p.y = 131; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 864; p.y = 147; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 867; p.y = 134; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 881; p.y = 151; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 795; p.y = 60; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 829; p.y = 66; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 812; p.y = 64; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 810; p.y = 67; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 809; p.y = 70; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 720; p.y = 57; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 859; p.y = 142; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 877; p.y = 137; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 806; p.y = 65; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 787; p.y = 76; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 822; p.y = 68; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 821; p.y = 74; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 785; p.y = 72; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 733; p.y = 73; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 757; p.y = 61; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 651; p.y = 94; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 673; p.y = 63; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 669; p.y = 78; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 793; p.y = 85; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 777; p.y = 93; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 764; p.y = 98; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 759; p.y = 83; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 769; p.y = 103; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 761; p.y = 119; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 717; p.y = 105; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 802; p.y = 88; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 791; p.y = 91; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 781; p.y = 82; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 770; p.y = 110; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 800; p.y = 113; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 780; p.y = 109; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 767; p.y = 111; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 751; p.y = 97; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 753; p.y = 114; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 743; p.y = 116; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 739; p.y = 125; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 716; p.y = 128; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 782; p.y = 124; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 789; p.y = 130; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 803; p.y = 133; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 779; p.y = 150; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 778; p.y = 146; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 776; p.y = 140; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 750; p.y = 135; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 749; p.y = 153; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 765; p.y = 156; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 737; p.y = 169; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 804; p.y = 138; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 792; p.y = 141; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 762; p.y = 139; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 766; p.y = 152; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 754; p.y = 129; p.county = 19;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 317; p.y = 994; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 275; p.y = 999; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 323; p.y = 995; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 306; p.y = 987; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 267; p.y = 996; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 305; p.y = 988; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 298; p.y = 991; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 284; p.y = 975; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 307; p.y = 993; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 280; p.y = 989; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 296; p.y = 983; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 310; p.y = 998; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 313; p.y = 967; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 324; p.y = 968; p.county = 21;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 357; p.y = 830; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 490; p.y = 793; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 461; p.y = 879; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 504; p.y = 826; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 416; p.y = 792; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 452; p.y = 825; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 463; p.y = 784; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 505; p.y = 773; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 367; p.y = 824; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 386; p.y = 839; p.county = 23;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 655; p.y = 781; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 665; p.y = 812; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 846; p.y = 788; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 833; p.y = 845; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 837; p.y = 814; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 727; p.y = 844; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 784; p.y = 800; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 667; p.y = 740; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 674; p.y = 865; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 641; p.y = 850; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 752; p.y = 780; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 690; p.y = 851; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 734; p.y = 866; p.county = 25;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 823; p.y = 422; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 706; p.y = 350; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 663; p.y = 335; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 794; p.y = 431; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 687; p.y = 329; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 680; p.y = 375; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 662; p.y = 384; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 763; p.y = 415; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 644; p.y = 365; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 650; p.y = 318; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 653; p.y = 371; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 735; p.y = 370; p.county = 27;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 541; p.y = 179; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 639; p.y = 157; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 630; p.y = 55; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 610; p.y = 205; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 636; p.y = 77; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 638; p.y = 210; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 620; p.y = 188; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 572; p.y = 127; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 628; p.y = 163; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 563; p.y = 202; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 554; p.y = 238; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 550; p.y = 144; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 613; p.y = 162; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 596; p.y = 155; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 592; p.y = 191; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 603; p.y = 168; p.county = 29;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 788; p.y = 732; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 756; p.y = 691; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 711; p.y = 694; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 835; p.y = 683; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 844; p.y = 668; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 760; p.y = 703; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 740; p.y = 701; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 723; p.y = 716; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 815; p.y = 670; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 728; p.y = 592; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 725; p.y = 675; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 718; p.y = 727; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 872; p.y = 669; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 796; p.y = 690; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 832; p.y = 693; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 702; p.y = 705; p.county = 31;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 919; p.y = 726; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 916; p.y = 717; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 930; p.y = 713; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 942; p.y = 697; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 920; p.y = 715; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 928; p.y = 729; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 914; p.y = 754; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 908; p.y = 738; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 900; p.y = 692; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 917; p.y = 696; p.county = 33;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 631; p.y = 260; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 627; p.y = 239; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 599; p.y = 243; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 645; p.y = 249; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 675; p.y = 221; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 671; p.y = 178; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 684; p.y = 208; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 685; p.y = 189; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 648; p.y = 186; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 689; p.y = 201; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 654; p.y = 217; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 677; p.y = 145; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 683; p.y = 183; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 730; p.y = 158; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 693; p.y = 173; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 699; p.y = 176; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 668; p.y = 171; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 661; p.y = 193; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 660; p.y = 211; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 681; p.y = 177; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 698; p.y = 190; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 694; p.y = 216; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 726; p.y = 149; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 615; p.y = 256; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 688; p.y = 187; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 696; p.y = 199; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 724; p.y = 166; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 695; p.y = 194; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 672; p.y = 209; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 713; p.y = 195; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 722; p.y = 161; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 701; p.y = 184; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 692; p.y = 197; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 676; p.y = 228; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 704; p.y = 164; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 691; p.y = 222; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 708; p.y = 180; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 707; p.y = 182; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 710; p.y = 170; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 664; p.y = 200; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 731; p.y = 165; p.county = 35;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 229; p.y = 399; p.county = 37;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 258; p.y = 420; p.county = 37;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 215; p.y = 354; p.county = 37;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 265; p.y = 403; p.county = 37;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 209; p.y = 429; p.county = 37;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 249; p.y = 372; p.county = 37;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 345; p.y = 728; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 341; p.y = 756; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 437; p.y = 763; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 374; p.y = 680; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 383; p.y = 718; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 349; p.y = 706; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 493; p.y = 695; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 434; p.y = 708; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 414; p.y = 710; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 419; p.y = 736; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 523; p.y = 719; p.county = 39;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 869; p.y = 656; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 839; p.y = 623; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 894; p.y = 570; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 875; p.y = 625; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 883; p.y = 601; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 873; p.y = 491; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 865; p.y = 613; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 838; p.y = 608; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 850; p.y = 612; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 851; p.y = 544; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 888; p.y = 628; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 879; p.y = 611; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 874; p.y = 637; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 866; p.y = 622; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 878; p.y = 635; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 871; p.y = 602; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 887; p.y = 585; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 885; p.y = 417; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 893; p.y = 421; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 896; p.y = 659; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 899; p.y = 533; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 828; p.y = 460; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 868; p.y = 437; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 897; p.y = 498; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 903; p.y = 416; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 858; p.y = 470; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 884; p.y = 454; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 882; p.y = 577; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 818; p.y = 600; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 855; p.y = 638; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 830; p.y = 574; p.county = 41;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 898; p.y = 295; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 906; p.y = 286; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 913; p.y = 301; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 922; p.y = 275; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 925; p.y = 277; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 929; p.y = 358; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 963; p.y = 334; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 921; p.y = 389; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 952; p.y = 344; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 926; p.y = 274; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 927; p.y = 280; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 918; p.y = 268; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 911; p.y = 376; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 904; p.y = 273; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 915; p.y = 279; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 943; p.y = 299; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 935; p.y = 265; p.county = 43;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 115; p.y = 922; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 104; p.y = 918; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 135; p.y = 870; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 835; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 908; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 102; p.y = 902; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 101; p.y = 928; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 119; p.y = 899; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 103; p.y = 894; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 111; p.y = 900; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 108; p.y = 887; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 113; p.y = 884; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 112; p.y = 896; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 120; p.y = 885; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 125; p.y = 912; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 122; p.y = 962; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 137; p.y = 930; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 877; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 118; p.y = 910; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 126; p.y = 873; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 114; p.y = 847; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 172; p.y = 889; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 139; p.y = 936; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 127; p.y = 944; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 926; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 148; p.y = 923; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 131; p.y = 935; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 138; p.y = 943; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 164; p.y = 925; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 964; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 153; p.y = 904; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 997; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 142; p.y = 915; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 134; p.y = 772; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 940; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 179; p.y = 817; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 106; p.y = 934; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 121; p.y = 979; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 986; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 109; p.y = 945; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 920; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 171; p.y = 799; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 166; p.y = 819; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 168; p.y = 875; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 151; p.y = 898; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 117; p.y = 938; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 160; p.y = 852; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 175; p.y = 836; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 140; p.y = 950; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 154; p.y = 929; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 891; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 162; p.y = 903; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 159; p.y = 916; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 129; p.y = 971; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 158; p.y = 984; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 156; p.y = 842; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 146; p.y = 946; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 128; p.y = 914; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 169; p.y = 951; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 123; p.y = 933; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 132; p.y = 924; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 913; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 105; p.y = 862; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 157; p.y = 864; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 167; p.y = 965; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 170; p.y = 931; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 143; p.y = 856; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 165; p.y = 867; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 152; p.y = 956; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 136; p.y = 837; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 133; p.y = 848; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 181; p.y = 881; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 959; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 173; p.y = 958; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 107; p.y = 794; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 188; p.y = 861; p.county = 45;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 197; p.y = 626; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 195; p.y = 604; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 144; p.y = 699; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 191; p.y = 615; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 193; p.y = 630; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 176; p.y = 617; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 200; p.y = 679; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 187; p.y = 647; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 216; p.y = 609; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 198; p.y = 526; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 161; p.y = 712; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 163; p.y = 674; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 145; p.y = 520; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 202; p.y = 634; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 205; p.y = 621; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 201; p.y = 653; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 212; p.y = 660; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 226; p.y = 632; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 184; p.y = 616; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 177; p.y = 707; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 185; p.y = 640; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 174; p.y = 639; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 227; p.y = 599; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 194; p.y = 651; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 208; p.y = 665; p.county = 47;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 411; p.y = 148; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 432; p.y = 123; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 355; p.y = 56; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 404; p.y = 71; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 361; p.y = 59; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 429; p.y = 75; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 405; p.y = 100; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 471; p.y = 101; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 368; p.y = 136; p.county = 49;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 974; p.y = 512; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 936; p.y = 407; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 979; p.y = 489; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 944; p.y = 435; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 946; p.y = 412; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 960; p.y = 446; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 934; p.y = 511; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 940; p.y = 482; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 932; p.y = 538; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 931; p.y = 443; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 941; p.y = 428; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 993; p.y = 445; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 998; p.y = 433; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 956; p.y = 357; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 976; p.y = 405; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 999; p.y = 425; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 996; p.y = 434; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 969; p.y = 426; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 981; p.y = 382; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 966; p.y = 364; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 987; p.y = 397; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 989; p.y = 402; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 991; p.y = 465; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 978; p.y = 564; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 972; p.y = 398; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 949; p.y = 618; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 968; p.y = 391; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 958; p.y = 377; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 965; p.y = 349; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 959; p.y = 352; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 962; p.y = 359; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 964; p.y = 380; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 953; p.y = 374; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 984; p.y = 387; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 995; p.y = 430; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 951; p.y = 424; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 994; p.y = 409; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 986; p.y = 390; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 985; p.y = 395; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 939; p.y = 393; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 945; p.y = 481; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 947; p.y = 419; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 983; p.y = 453; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 961; p.y = 401; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 980; p.y = 379; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 977; p.y = 449; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 957; p.y = 654; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 975; p.y = 360; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 938; p.y = 580; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 948; p.y = 400; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 954; p.y = 414; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 973; p.y = 466; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 990; p.y = 404; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 997; p.y = 452; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 992; p.y = 440; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 967; p.y = 381; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 955; p.y = 348; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 982; p.y = 385; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 950; p.y = 367; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 970; p.y = 388; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 988; p.y = 410; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 971; p.y = 355; p.county = 51;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 445; p.y = 54; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 501; p.y = 46; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 439; p.y = 28; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 464; p.y = 2; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 390; p.y = 51; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 450; p.y = 40; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 430; p.y = 47; p.county = 53;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 625; p.y = 682; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 647; p.y = 725; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 622; p.y = 649; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 619; p.y = 664; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 640; p.y = 700; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 623; p.y = 658; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 559; p.y = 627; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 617; p.y = 672; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 595; p.y = 590; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 569; p.y = 606; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 635; p.y = 741; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 594; p.y = 655; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 574; p.y = 645; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 632; p.y = 688; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 614; p.y = 657; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 598; p.y = 714; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 624; p.y = 723; p.county = 55;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 606; p.y = 829; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 593; p.y = 855; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 544; p.y = 798; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 585; p.y = 834; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 618; p.y = 758; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 567; p.y = 810; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 548; p.y = 828; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 611; p.y = 853; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 583; p.y = 818; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 633; p.y = 795; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 526; p.y = 976; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 543; p.y = 854; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 588; p.y = 872; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 529; p.y = 966; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 556; p.y = 955; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 538; p.y = 932; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 555; p.y = 937; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 536; p.y = 948; p.county = 57;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 218; p.y = 746; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 220; p.y = 749; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 214; p.y = 743; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 228; p.y = 735; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 219; p.y = 765; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 211; p.y = 731; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 266; p.y = 721; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 225; p.y = 709; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 190; p.y = 809; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 203; p.y = 785; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 199; p.y = 840; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 223; p.y = 790; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 232; p.y = 677; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 182; p.y = 724; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 196; p.y = 702; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 155; p.y = 744; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 247; p.y = 742; p.county = 59;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 682; p.y = 687; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 670; p.y = 624; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 666; p.y = 662; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 697; p.y = 644; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 652; p.y = 620; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 715; p.y = 545; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 678; p.y = 598; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 649; p.y = 676; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 642; p.y = 584; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 659; p.y = 673; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 646; p.y = 569; p.county = 61;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 322; p.y = 451; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 348; p.y = 523; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 330; p.y = 447; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 353; p.y = 515; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 338; p.y = 531; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 347; p.y = 464; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 455; p.y = 396; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 340; p.y = 459; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 420; p.y = 394; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 428; p.y = 486; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 332; p.y = 457; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 392; p.y = 408; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 376; p.y = 456; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 395; p.y = 495; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 379; p.y = 427; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 436; p.y = 467; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 343; p.y = 603; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 423; p.y = 463; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 364; p.y = 475; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 399; p.y = 441; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 412; p.y = 455; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 418; p.y = 478; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 388; p.y = 551; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 339; p.y = 558; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 384; p.y = 505; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 371; p.y = 506; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 359; p.y = 494; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 409; p.y = 413; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 397; p.y = 418; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 401; p.y = 392; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 336; p.y = 588; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 413; p.y = 442; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 362; p.y = 436; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 360; p.y = 500; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 425; p.y = 497; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 403; p.y = 536; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 422; p.y = 496; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 394; p.y = 547; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 407; p.y = 525; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 400; p.y = 501; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 377; p.y = 548; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 363; p.y = 550; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 385; p.y = 487; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 389; p.y = 521; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 350; p.y = 563; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 381; p.y = 473; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 346; p.y = 508; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 373; p.y = 552; p.county = 63;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 514; p.county = 65;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 444; p.county = 65;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 141; p.y = 469; p.county = 65;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 147; p.y = 439; p.county = 65;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 178; p.y = 406; p.county = 65;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 192; p.y = 373; p.county = 65;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 907; p.y = 507; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 924; p.y = 562; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 912; p.y = 641; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 905; p.y = 594; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 910; p.y = 667; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 923; p.y = 643; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 933; p.y = 646; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 937; p.y = 661; p.county = 67;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 895; p.y = 841; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 889; p.y = 849; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 886; p.y = 759; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 852; p.y = 857; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 901; p.y = 776; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 880; p.y = 783; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 891; p.y = 807; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 902; p.y = 802; p.county = 69;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 315; p.y = 678; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 311; p.y = 666; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 318; p.y = 671; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 270; p.y = 686; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 309; p.y = 629; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 288; p.y = 704; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 321; p.y = 698; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 326; p.y = 576; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 334; p.y = 633; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 308; p.y = 684; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 335; p.y = 663; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 289; p.y = 650; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 327; p.y = 685; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 314; p.y = 751; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 325; p.y = 642; p.county = 71;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 771; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 752; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 831; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 859; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 804; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 786; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 815; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 893; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 805; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 942; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 816; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 860; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 833; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 821; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 808; p.county = 73;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 524; p.y = 308; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 534; p.y = 300; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 533; p.y = 310; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 545; p.y = 304; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 542; p.y = 293; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 510; p.y = 324; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 520; p.y = 315; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 511; p.y = 298; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 532; p.y = 319; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 525; p.y = 323; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 582; p.y = 287; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 564; p.y = 262; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 446; p.y = 278; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 495; p.y = 270; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 657; p.y = 282; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 551; p.y = 326; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 579; p.y = 309; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 552; p.y = 345; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 408; p.y = 331; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 431; p.y = 366; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 402; p.y = 294; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 626; p.y = 281; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 634; p.y = 297; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 643; p.y = 284; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 489; p.y = 353; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 516; p.y = 289; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 546; p.y = 272; p.county = 75;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 813; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 823; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 820; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 827; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 858; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 909; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 880; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 939; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 890; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 974; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 953; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 919; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 883; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 868; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 869; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 874; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 917; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 905; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 876; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 878; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 895; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 901; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 892; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 906; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 947; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 832; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 886; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 888; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 882; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 911; p.county = 77;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 442; p.y = 499; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 427; p.y = 518; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 473; p.y = 522; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 387; p.y = 559; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 547; p.y = 530; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 438; p.y = 493; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 460; p.y = 524; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 444; p.y = 513; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 447; p.y = 509; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 372; p.y = 597; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 370; p.y = 587; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 454; p.y = 483; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 477; p.y = 462; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 458; p.y = 502; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 456; p.y = 510; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 462; p.y = 504; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 497; p.y = 432; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 481; p.y = 471; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 441; p.y = 527; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 406; p.y = 557; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 426; p.y = 535; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 486; p.y = 476; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 440; p.y = 542; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 540; p.y = 448; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 433; p.y = 503; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 514; p.y = 472; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 398; p.y = 579; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 365; p.y = 572; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 375; p.y = 571; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 415; p.y = 537; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 487; p.y = 619; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 482; p.y = 652; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 457; p.y = 578; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 539; p.y = 593; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 506; p.y = 589; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 478; p.y = 529; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 424; p.y = 549; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 468; p.y = 546; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 451; p.y = 532; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 453; p.y = 543; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 561; p.y = 480; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 465; p.y = 516; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 378; p.y = 566; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 476; p.y = 474; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 459; p.y = 553; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 472; p.y = 554; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 527; p.y = 648; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 517; p.y = 614; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 479; p.y = 605; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 502; p.y = 468; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 562; p.y = 458; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 500; p.y = 581; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 393; p.y = 556; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 519; p.y = 596; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 483; p.y = 485; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 521; p.y = 479; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 508; p.y = 555; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 549; p.y = 586; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 513; p.y = 607; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 435; p.y = 540; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 382; p.y = 591; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 396; p.y = 565; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 417; p.y = 519; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 470; p.y = 528; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 467; p.y = 484; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 496; p.y = 567; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 351; p.y = 583; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 475; p.y = 539; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 484; p.y = 582; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 597; p.y = 450; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 410; p.y = 534; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 492; p.y = 541; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 480; p.y = 492; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 491; p.y = 595; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 531; p.y = 573; p.county = 79;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 303; p.y = 477; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 273; p.y = 575; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 319; p.y = 461; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 276; p.y = 488; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 240; p.y = 517; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 301; p.y = 560; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 302; p.y = 423; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 268; p.y = 490; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 277; p.y = 438; p.county = 81;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 222; p.y = 960; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 243; p.y = 907; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 259; p.y = 970; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 204; p.y = 871; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 256; p.y = 992; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 260; p.y = 897; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 253; p.y = 949; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 231; p.y = 980; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 250; p.y = 982; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 206; p.y = 973; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 180; p.y = 952; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 210; p.y = 985; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 186; p.y = 990; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 254; p.y = 972; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 235; p.y = 846; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 252; p.y = 811; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 245; p.y = 969; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 238; p.y = 803; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 189; p.y = 981; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 217; p.y = 921; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 244; p.y = 957; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 242; p.y = 963; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 237; p.y = 954; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 183; p.y = 941; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 207; p.y = 961; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 241; p.y = 977; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 263; p.y = 927; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
if (1==1){ Point p;
p.x = 213; p.y = 978; p.county = 83;
points[i]=p;xCount[p.x]++;yCount[p.y]++;i++;}
return points;}






struct Map {
	std::map<int,std::map<int,Point> > pointMap;
	int width;
	int height;
};


Map fillBlanks(Map m) {
	int i;
	int ii;
	int ix;
	int iy;
	int count = 0;
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
			else {
				count++;
			}
		}
	}
	console_log(count);
	return m;
}


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
				oldMax[ii]=-1000000;
			}
			
		}
		else if (l < 0){
			if (m.pointMap[0][ii].val >= 0){
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
			int mpv = m.pointMap[i][ii].val;
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
						m.pointMap[i][ii]=m.pointMap[i][ii+1];
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
					if (removeSeam[i] == m.height || m.pointMap[i][removeSeam[i]].val < 0){
					}
					else {
						for(ii=removeSeam[i];ii<m.height-1;ii++){
							m.pointMap[i][ii]=m.pointMap[i][ii+1];
						}
						Point p;
						p.x = i;
						p.y = m.height-1;
						p.val = 1;
						m.pointMap[i][m.height-1]=p;
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
				oldSeams[i][0]=m.width;
			}
			
		}
		
	}
	int h = m.height;
	int w = m.width;
	int modn = w / n;
	for(ii=1;ii<h;ii++){
		for(i=0;i<w;i++){
			int mpv = m.pointMap[i][ii].val;
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
					if (removeSeam[ii] == m.width || m.pointMap[removeSeam[ii]][ii].val < 0){
						
					}
					else {
						
						
						for(i=removeSeam[ii];i<m.width-1;i++){
							m.pointMap[i][ii]=m.pointMap[i+1][ii];
						}
						Point p;
						p.x = m.width-1;
						p.y = ii;
						p.val = 1;
						m.pointMap[m.width-1][ii]=p;
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
	std::map<int,std::map<int,Point>> pointMap;
	
	killCarveV = false;
	killCarveH = false;
	int np = 1000;
	for(i=0;i<10000;i++){
		xCount[i]=0;
		yCount[i]=0;
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
		p.val = -1000000;
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
	vertThreads = 80;
	horzThreads = 80;
	for (i=0;i<np;i++){
		if (vertThreads>6){
			vertThreads-=6;
		}
		else {
			vertThreads=6;
		}
		if (horzThreads>6){
			horzThreads-=6;
		}
		else {
			horzThreads=6;
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
	


	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(m.width);
	console_log(m.height);
	set_maxX(m.width);
	set_maxY(m.height);
	for(i=0;i<m.width;i++){
		for(ii=0;ii<m.height;ii++){
			Point p = m.pointMap[i][ii];
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
