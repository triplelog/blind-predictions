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
		pointsOut.push({"x":pointSplit[3],"y":pointSplit[4],"ox":pointSplit[0],"oy":pointSplit[1],"county":pointSplit[5],"val":pointSplit[2],"d":pointSplit[6],"r":pointSplit[7]});	
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
	int d;
	int r;
	int d16;
	int r16;
};

std::map<int,Point> scPoints(){
std::map<int,Point> points; int i=0;
if (1==1){ Point p;
p.x = 65; p.y = 49; p.county = 3; p.val = 613; p.d = 250; p.r = 363; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 48; p.county = 3; p.val = 783; p.d = 314; p.r = 469; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 51; p.county = 3; p.val = 619; p.d = 157; p.r = 462; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 52; p.county = 3; p.val = 1143; p.d = 611; p.r = 532; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 50; p.county = 3; p.val = 544; p.d = 130; p.r = 414; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 47; p.county = 3; p.val = 889; p.d = 619; p.r = 270; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 50; p.county = 3; p.val = 362; p.d = 169; p.r = 193; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 51; p.county = 3; p.val = 794; p.d = 251; p.r = 543; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 49; p.county = 3; p.val = 1047; p.d = 210; p.r = 837; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 50; p.county = 3; p.val = 1287; p.d = 346; p.r = 941; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 49; p.county = 3; p.val = 681; p.d = 213; p.r = 468; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 48; p.county = 3; p.val = 1022; p.d = 238; p.r = 784; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 48; p.county = 3; p.val = 1166; p.d = 414; p.r = 752; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 56; p.county = 3; p.val = 1075; p.d = 210; p.r = 865; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 54; p.county = 3; p.val = 1134; p.d = 631; p.r = 503; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 52; p.county = 3; p.val = 566; p.d = 257; p.r = 309; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 49; p.county = 3; p.val = 508; p.d = 293; p.r = 215; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 47; p.county = 3; p.val = 627; p.d = 194; p.r = 433; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 45; p.county = 3; p.val = 1352; p.d = 595; p.r = 757; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 48; p.county = 3; p.val = 485; p.d = 227; p.r = 258; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 45; p.county = 3; p.val = 553; p.d = 118; p.r = 435; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 43; p.county = 3; p.val = 680; p.d = 146; p.r = 534; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 41; p.county = 3; p.val = 830; p.d = 406; p.r = 424; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 50; p.county = 3; p.val = 693; p.d = 238; p.r = 455; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 48; p.county = 3; p.val = 465; p.d = 117; p.r = 348; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 46; p.county = 3; p.val = 1179; p.d = 302; p.r = 877; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 43; p.county = 3; p.val = 1003; p.d = 396; p.r = 607; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 45; p.county = 3; p.val = 992; p.d = 231; p.r = 761; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 47; p.county = 3; p.val = 996; p.d = 353; p.r = 643; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 48; p.county = 3; p.val = 719; p.d = 278; p.r = 441; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 49; p.county = 3; p.val = 1144; p.d = 254; p.r = 890; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 50; p.county = 3; p.val = 833; p.d = 204; p.r = 629; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 49; p.county = 3; p.val = 837; p.d = 297; p.r = 540; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 51; p.county = 3; p.val = 756; p.d = 213; p.r = 543; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 52; p.county = 3; p.val = 825; p.d = 196; p.r = 629; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 53; p.county = 3; p.val = 1087; p.d = 524; p.r = 563; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 51; p.county = 3; p.val = 1222; p.d = 246; p.r = 976; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 52; p.county = 3; p.val = 1324; p.d = 290; p.r = 1034; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 50; p.county = 3; p.val = 1090; p.d = 363; p.r = 727; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 51; p.county = 3; p.val = 624; p.d = 229; p.r = 395; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 52; p.county = 3; p.val = 756; p.d = 274; p.r = 482; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 54; p.county = 3; p.val = 700; p.d = 237; p.r = 463; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 53; p.county = 3; p.val = 696; p.d = 220; p.r = 476; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 35; p.county = 79; p.val = 903; p.d = 519; p.r = 384; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 35; p.county = 63; p.val = 910; p.d = 295; p.r = 615; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 36; p.county = 79; p.val = 1563; p.d = 671; p.r = 892; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 34; p.county = 79; p.val = 954; p.d = 579; p.r = 375; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 34; p.county = 63; p.val = 1178; p.d = 723; p.r = 455; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 34; p.county = 79; p.val = 1570; p.d = 1190; p.r = 380; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 37; p.county = 79; p.val = 1262; p.d = 1046; p.r = 216; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 41; p.county = 79; p.val = 890; p.d = 833; p.r = 57; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 36; p.county = 79; p.val = 592; p.d = 371; p.r = 221; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 33; p.county = 79; p.val = 813; p.d = 739; p.r = 74; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 35; p.county = 79; p.val = 1232; p.d = 759; p.r = 473; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 36; p.county = 79; p.val = 1412; p.d = 797; p.r = 615; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 37; p.county = 79; p.val = 1031; p.d = 878; p.r = 153; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 36; p.county = 79; p.val = 867; p.d = 215; p.r = 652; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 38; p.county = 79; p.val = 831; p.d = 718; p.r = 113; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 37; p.county = 63; p.val = 1091; p.d = 666; p.r = 425; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 38; p.county = 79; p.val = 742; p.d = 524; p.r = 218; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 30; p.county = 79; p.val = 1551; p.d = 300; p.r = 1251; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 32; p.county = 63; p.val = 1414; p.d = 228; p.r = 1186; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 30; p.county = 79; p.val = 856; p.d = 233; p.r = 623; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 31; p.county = 79; p.val = 1522; p.d = 463; p.r = 1059; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 31; p.county = 79; p.val = 552; p.d = 224; p.r = 328; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 32; p.county = 79; p.val = 775; p.d = 414; p.r = 361; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 33; p.county = 63; p.val = 1354; p.d = 506; p.r = 848; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 33; p.county = 79; p.val = 748; p.d = 468; p.r = 280; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 41; p.county = 79; p.val = 918; p.d = 864; p.r = 54; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 39; p.county = 79; p.val = 797; p.d = 718; p.r = 79; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 34; p.county = 79; p.val = 964; p.d = 660; p.r = 304; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 29; p.county = 79; p.val = 541; p.d = 368; p.r = 173; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 28; p.county = 79; p.val = 1599; p.d = 752; p.r = 847; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 30; p.county = 79; p.val = 1213; p.d = 1069; p.r = 144; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 29; p.county = 79; p.val = 1170; p.d = 363; p.r = 807; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 30; p.county = 79; p.val = 1536; p.d = 805; p.r = 731; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 31; p.county = 79; p.val = 1343; p.d = 905; p.r = 438; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 31; p.county = 79; p.val = 1712; p.d = 1366; p.r = 346; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 31; p.county = 55; p.val = 1506; p.d = 472; p.r = 1034; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 32; p.county = 79; p.val = 1497; p.d = 817; p.r = 680; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 32; p.county = 79; p.val = 1368; p.d = 1102; p.r = 266; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 33; p.county = 79; p.val = 1459; p.d = 1078; p.r = 381; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 32; p.county = 79; p.val = 1659; p.d = 1366; p.r = 293; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 31; p.county = 79; p.val = 1228; p.d = 757; p.r = 471; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 33; p.county = 79; p.val = 1476; p.d = 839; p.r = 637; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 64; p.county = 15; p.val = 2013; p.d = 1040; p.r = 973; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 59; p.county = 15; p.val = 925; p.d = 499; p.r = 426; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 61; p.county = 15; p.val = 532; p.d = 92; p.r = 440; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 63; p.county = 15; p.val = 1515; p.d = 522; p.r = 993; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 61; p.county = 15; p.val = 465; p.d = 255; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 63; p.county = 15; p.val = 714; p.d = 276; p.r = 438; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 65; p.county = 19; p.val = 1103; p.d = 591; p.r = 512; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 66; p.county = 15; p.val = 696; p.d = 580; p.r = 116; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 57; p.county = 15; p.val = 646; p.d = 286; p.r = 360; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 58; p.county = 15; p.val = 1093; p.d = 199; p.r = 894; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 59; p.county = 15; p.val = 920; p.d = 363; p.r = 557; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 60; p.county = 15; p.val = 1214; p.d = 293; p.r = 921; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 61; p.county = 15; p.val = 1350; p.d = 586; p.r = 764; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 58; p.county = 15; p.val = 599; p.d = 210; p.r = 389; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 53; p.county = 15; p.val = 480; p.d = 355; p.r = 125; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 53; p.county = 15; p.val = 737; p.d = 616; p.r = 121; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 52; p.county = 15; p.val = 865; p.d = 736; p.r = 129; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 56; p.county = 15; p.val = 1034; p.d = 215; p.r = 819; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 56; p.county = 15; p.val = 767; p.d = 295; p.r = 472; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 54; p.county = 15; p.val = 839; p.d = 429; p.r = 410; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 55; p.county = 15; p.val = 694; p.d = 448; p.r = 246; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 57; p.county = 15; p.val = 1216; p.d = 114; p.r = 1102; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 57; p.county = 15; p.val = 403; p.d = 247; p.r = 156; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 60; p.county = 15; p.val = 181; p.d = 17; p.r = 164; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 59; p.county = 15; p.val = 287; p.d = 130; p.r = 157; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 63; p.county = 15; p.val = 797; p.d = 526; p.r = 271; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 61; p.county = 15; p.val = 732; p.d = 262; p.r = 470; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 64; p.county = 15; p.val = 1097; p.d = 412; p.r = 685; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 65; p.county = 15; p.val = 998; p.d = 371; p.r = 627; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 66; p.county = 19; p.val = 733; p.d = 470; p.r = 263; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 67; p.county = 15; p.val = 552; p.d = 243; p.r = 309; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 67; p.county = 19; p.val = 1079; p.d = 582; p.r = 497; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 68; p.county = 19; p.val = 633; p.d = 469; p.r = 164; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 64; p.county = 15; p.val = 1843; p.d = 560; p.r = 1283; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 65; p.county = 15; p.val = 1411; p.d = 703; p.r = 708; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 68; p.county = 15; p.val = 845; p.d = 194; p.r = 651; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 62; p.county = 15; p.val = 838; p.d = 207; p.r = 631; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 70; p.county = 19; p.val = 846; p.d = 783; p.r = 63; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 69; p.county = 19; p.val = 501; p.d = 295; p.r = 206; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 54; p.county = 15; p.val = 842; p.d = 685; p.r = 157; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 63; p.county = 15; p.val = 1165; p.d = 446; p.r = 719; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 62; p.county = 15; p.val = 2358; p.d = 801; p.r = 1557; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 68; p.county = 19; p.val = 2359; p.d = 716; p.r = 1643; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 64; p.county = 35; p.val = 685; p.d = 514; p.r = 171; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 82; p.county = 29; p.val = 854; p.d = 219; p.r = 635; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 73; p.county = 29; p.val = 326; p.d = 261; p.r = 65; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 65; p.county = 29; p.val = 390; p.d = 97; p.r = 293; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 68; p.county = 29; p.val = 412; p.d = 129; p.r = 283; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 71; p.county = 29; p.val = 171; p.d = 68; p.r = 103; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 67; p.county = 29; p.val = 231; p.d = 85; p.r = 146; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 64; p.county = 29; p.val = 375; p.d = 165; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 68; p.county = 29; p.val = 966; p.d = 289; p.r = 677; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 70; p.county = 29; p.val = 525; p.d = 239; p.r = 286; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 67; p.county = 29; p.val = 524; p.d = 120; p.r = 404; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 70; p.county = 29; p.val = 613; p.d = 302; p.r = 311; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 63; p.county = 29; p.val = 273; p.d = 184; p.r = 89; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 68; p.county = 29; p.val = 637; p.d = 230; p.r = 407; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 72; p.county = 29; p.val = 511; p.d = 367; p.r = 144; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 68; p.county = 29; p.val = 603; p.d = 400; p.r = 203; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 69; p.county = 29; p.val = 776; p.d = 672; p.r = 104; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 68; p.county = 29; p.val = 477; p.d = 184; p.r = 293; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 64; p.county = 29; p.val = 239; p.d = 118; p.r = 121; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 66; p.county = 29; p.val = 205; p.d = 96; p.r = 109; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 66; p.county = 29; p.val = 277; p.d = 42; p.r = 235; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 65; p.county = 29; p.val = 398; p.d = 93; p.r = 305; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 69; p.county = 29; p.val = 435; p.d = 121; p.r = 314; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 77; p.county = 29; p.val = 681; p.d = 519; p.r = 162; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 73; p.county = 29; p.val = 733; p.d = 480; p.r = 253; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 70; p.county = 29; p.val = 521; p.d = 302; p.r = 219; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 62; p.county = 29; p.val = 763; p.d = 485; p.r = 278; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 65; p.county = 29; p.val = 643; p.d = 123; p.r = 520; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 65; p.county = 29; p.val = 494; p.d = 154; p.r = 340; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 66; p.county = 29; p.val = 706; p.d = 300; p.r = 406; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 67; p.county = 29; p.val = 663; p.d = 201; p.r = 462; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 37; p.county = 51; p.val = 1168; p.d = 257; p.r = 911; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 35; p.county = 51; p.val = 464; p.d = 86; p.r = 378; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 41; p.county = 51; p.val = 1302; p.d = 351; p.r = 951; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 35; p.county = 51; p.val = 981; p.d = 165; p.r = 816; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 34; p.county = 51; p.val = 858; p.d = 278; p.r = 580; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 37; p.county = 51; p.val = 635; p.d = 223; p.r = 412; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 41; p.county = 51; p.val = 996; p.d = 150; p.r = 846; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 40; p.county = 51; p.val = 550; p.d = 77; p.r = 473; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 40; p.county = 51; p.val = 1057; p.d = 280; p.r = 777; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 44; p.county = 51; p.val = 1117; p.d = 364; p.r = 753; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 36; p.county = 51; p.val = 543; p.d = 54; p.r = 489; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 35; p.county = 51; p.val = 803; p.d = 169; p.r = 634; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 36; p.county = 51; p.val = 638; p.d = 79; p.r = 559; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 39; p.county = 51; p.val = 699; p.d = 211; p.r = 488; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 33; p.county = 51; p.val = 1632; p.d = 556; p.r = 1076; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 36; p.county = 51; p.val = 1288; p.d = 335; p.r = 953; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 39; p.county = 51; p.val = 1086; p.d = 196; p.r = 890; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 33; p.county = 51; p.val = 137; p.d = 23; p.r = 114; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 48; p.county = 51; p.val = 1372; p.d = 330; p.r = 1042; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 48; p.county = 43; p.val = 2377; p.d = 654; p.r = 1723; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 31; p.county = 51; p.val = 565; p.d = 182; p.r = 383; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 39; p.county = 51; p.val = 939; p.d = 157; p.r = 782; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 33; p.county = 51; p.val = 118; p.d = 24; p.r = 94; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 38; p.county = 51; p.val = 908; p.d = 243; p.r = 665; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 37; p.county = 51; p.val = 735; p.d = 88; p.r = 647; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 44; p.county = 51; p.val = 265; p.d = 115; p.r = 150; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 41; p.county = 51; p.val = 1662; p.d = 663; p.r = 999; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 32; p.county = 51; p.val = 470; p.d = 86; p.r = 384; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 38; p.county = 51; p.val = 386; p.d = 21; p.r = 365; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 34; p.county = 51; p.val = 527; p.d = 23; p.r = 504; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 37; p.county = 51; p.val = 985; p.d = 507; p.r = 478; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 38; p.county = 51; p.val = 1008; p.d = 252; p.r = 756; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 33; p.county = 51; p.val = 533; p.d = 380; p.r = 153; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 29; p.county = 51; p.val = 589; p.d = 161; p.r = 428; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 36; p.county = 51; p.val = 413; p.d = 57; p.r = 356; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 38; p.county = 51; p.val = 1721; p.d = 529; p.r = 1192; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 40; p.county = 51; p.val = 1990; p.d = 454; p.r = 1536; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 43; p.county = 51; p.val = 1171; p.d = 328; p.r = 843; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 43; p.county = 51; p.val = 395; p.d = 63; p.r = 332; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 45; p.county = 51; p.val = 533; p.d = 499; p.r = 34; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 40; p.county = 51; p.val = 776; p.d = 723; p.r = 53; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 37; p.county = 51; p.val = 644; p.d = 286; p.r = 358; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 40; p.county = 51; p.val = 1258; p.d = 265; p.r = 993; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 45; p.county = 51; p.val = 886; p.d = 334; p.r = 552; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 44; p.county = 51; p.val = 1588; p.d = 461; p.r = 1127; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 38; p.county = 51; p.val = 745; p.d = 103; p.r = 642; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 28; p.county = 51; p.val = 261; p.d = 42; p.r = 219; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 47; p.county = 51; p.val = 749; p.d = 206; p.r = 543; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 46; p.county = 51; p.val = 1624; p.d = 432; p.r = 1192; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 35; p.county = 51; p.val = 654; p.d = 328; p.r = 326; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 31; p.county = 51; p.val = 226; p.d = 19; p.r = 207; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 42; p.county = 51; p.val = 841; p.d = 246; p.r = 595; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 40; p.county = 51; p.val = 381; p.d = 179; p.r = 202; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 36; p.county = 51; p.val = 425; p.d = 47; p.r = 378; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 45; p.county = 51; p.val = 1617; p.d = 452; p.r = 1165; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 47; p.county = 51; p.val = 2161; p.d = 598; p.r = 1563; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 46; p.county = 51; p.val = 1192; p.d = 317; p.r = 875; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 39; p.county = 51; p.val = 1297; p.d = 372; p.r = 925; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 39; p.county = 51; p.val = 1090; p.d = 303; p.r = 787; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 42; p.county = 51; p.val = 1776; p.d = 478; p.r = 1298; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 39; p.county = 51; p.val = 833; p.d = 352; p.r = 481; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 42; p.county = 51; p.val = 1430; p.d = 494; p.r = 936; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 44; p.county = 51; p.val = 2229; p.d = 597; p.r = 1632; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 41; p.county = 51; p.val = 1691; p.d = 482; p.r = 1209; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 43; p.county = 51; p.val = 2009; p.d = 661; p.r = 1348; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 45; p.county = 51; p.val = 2667; p.d = 857; p.r = 1810; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 43; p.county = 51; p.val = 1988; p.d = 557; p.r = 1431; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 42; p.county = 51; p.val = 1305; p.d = 455; p.r = 850; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 41; p.county = 51; p.val = 1494; p.d = 357; p.r = 1137; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 40; p.county = 51; p.val = 884; p.d = 199; p.r = 685; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 41; p.county = 51; p.val = 1176; p.d = 387; p.r = 789; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 42; p.county = 51; p.val = 1466; p.d = 438; p.r = 1028; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 39; p.county = 51; p.val = 1125; p.d = 709; p.r = 416; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 32; p.county = 51; p.val = 172; p.d = 31; p.r = 141; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 20; p.county = 59; p.val = 822; p.d = 372; p.r = 450; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 21; p.county = 59; p.val = 860; p.d = 583; p.r = 277; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 23; p.county = 59; p.val = 1193; p.d = 284; p.r = 909; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 22; p.county = 59; p.val = 705; p.d = 447; p.r = 258; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 24; p.county = 59; p.val = 470; p.d = 182; p.r = 288; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 23; p.county = 59; p.val = 1001; p.d = 281; p.r = 720; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 15; p.county = 45; p.val = 890; p.d = 265; p.r = 625; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 16; p.county = 59; p.val = 551; p.d = 172; p.r = 379; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 17; p.county = 59; p.val = 825; p.d = 340; p.r = 485; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 17; p.county = 59; p.val = 1141; p.d = 221; p.r = 920; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 14; p.county = 45; p.val = 2083; p.d = 947; p.r = 1136; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 15; p.county = 59; p.val = 801; p.d = 127; p.r = 674; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 19; p.county = 59; p.val = 828; p.d = 163; p.r = 665; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 27; p.county = 59; p.val = 1123; p.d = 447; p.r = 676; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 25; p.county = 59; p.val = 1047; p.d = 369; p.r = 678; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 23; p.county = 59; p.val = 501; p.d = 68; p.r = 433; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 23; p.county = 59; p.val = 392; p.d = 62; p.r = 330; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 25; p.county = 59; p.val = 708; p.d = 98; p.r = 610; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 20; p.county = 59; p.val = 1476; p.d = 248; p.r = 1228; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 20; p.county = 59; p.val = 192; p.d = 22; p.r = 170; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 21; p.county = 59; p.val = 350; p.d = 41; p.r = 309; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 17; p.county = 59; p.val = 624; p.d = 211; p.r = 413; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 18; p.county = 59; p.val = 574; p.d = 185; p.r = 389; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 19; p.county = 59; p.val = 788; p.d = 223; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 20; p.county = 59; p.val = 883; p.d = 327; p.r = 556; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 22; p.county = 59; p.val = 779; p.d = 214; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 21; p.county = 59; p.val = 501; p.d = 422; p.r = 79; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 20; p.county = 59; p.val = 313; p.d = 274; p.r = 39; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 0; p.county = 83; p.val = 1927; p.d = 451; p.r = 1476; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 1; p.county = 83; p.val = 1656; p.d = 303; p.r = 1353; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 1; p.county = 83; p.val = 1887; p.d = 322; p.r = 1565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 4; p.county = 83; p.val = 1456; p.d = 399; p.r = 1057; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 3; p.county = 83; p.val = 812; p.d = 119; p.r = 693; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 3; p.county = 83; p.val = 1756; p.d = 549; p.r = 1207; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 4; p.county = 83; p.val = 2041; p.d = 272; p.r = 1769; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 2; p.county = 83; p.val = 2544; p.d = 385; p.r = 2159; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 1; p.county = 83; p.val = 1541; p.d = 346; p.r = 1195; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 3; p.county = 83; p.val = 1160; p.d = 147; p.r = 1013; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 3; p.county = 83; p.val = 814; p.d = 193; p.r = 621; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 3; p.county = 83; p.val = 668; p.d = 121; p.r = 547; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 4; p.county = 83; p.val = 966; p.d = 218; p.r = 748; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 5; p.county = 83; p.val = 2641; p.d = 546; p.r = 2095; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 5; p.county = 83; p.val = 1583; p.d = 399; p.r = 1184; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 4; p.county = 83; p.val = 2272; p.d = 686; p.r = 1586; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 5; p.county = 83; p.val = 982; p.d = 361; p.r = 621; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 4; p.county = 83; p.val = 1168; p.d = 236; p.r = 932; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 5; p.county = 83; p.val = 798; p.d = 246; p.r = 552; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 7; p.county = 83; p.val = 1166; p.d = 414; p.r = 752; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 9; p.county = 83; p.val = 621; p.d = 245; p.r = 376; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 10; p.county = 83; p.val = 804; p.d = 126; p.r = 678; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 12; p.county = 83; p.val = 1871; p.d = 229; p.r = 1642; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 15; p.county = 83; p.val = 932; p.d = 199; p.r = 733; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 13; p.county = 83; p.val = 719; p.d = 118; p.r = 601; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 12; p.county = 83; p.val = 760; p.d = 202; p.r = 558; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 12; p.county = 83; p.val = 900; p.d = 154; p.r = 746; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 11; p.county = 83; p.val = 1186; p.d = 182; p.r = 1004; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 10; p.county = 83; p.val = 1898; p.d = 470; p.r = 1428; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 9; p.county = 83; p.val = 1007; p.d = 176; p.r = 831; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 9; p.county = 83; p.val = 2078; p.d = 591; p.r = 1487; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 8; p.county = 83; p.val = 1169; p.d = 462; p.r = 707; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 7; p.county = 83; p.val = 816; p.d = 694; p.r = 122; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 6; p.county = 83; p.val = 1447; p.d = 619; p.r = 828; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 8; p.county = 83; p.val = 1442; p.d = 510; p.r = 932; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 7; p.county = 83; p.val = 626; p.d = 310; p.r = 316; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 9; p.county = 83; p.val = 1620; p.d = 794; p.r = 826; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 5; p.county = 83; p.val = 798; p.d = 453; p.r = 345; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 6; p.county = 83; p.val = 946; p.d = 689; p.r = 257; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 7; p.county = 83; p.val = 1063; p.d = 820; p.r = 243; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 8; p.county = 83; p.val = 854; p.d = 398; p.r = 456; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 9; p.county = 83; p.val = 728; p.d = 229; p.r = 499; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 8; p.county = 83; p.val = 797; p.d = 450; p.r = 347; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 8; p.county = 83; p.val = 811; p.d = 785; p.r = 26; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 7; p.county = 83; p.val = 1001; p.d = 841; p.r = 160; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 6; p.county = 83; p.val = 1344; p.d = 628; p.r = 716; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 6; p.county = 83; p.val = 555; p.d = 170; p.r = 385; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 8; p.county = 83; p.val = 1552; p.d = 448; p.r = 1104; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 1; p.county = 83; p.val = 1811; p.d = 468; p.r = 1343; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 6; p.county = 45; p.val = 848; p.d = 333; p.r = 515; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 14; p.county = 83; p.val = 1445; p.d = 514; p.r = 931; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 35; p.county = 65; p.val = 231; p.d = 199; p.r = 32; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 35; p.county = 65; p.val = 179; p.d = 99; p.r = 80; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 46; p.county = 65; p.val = 507; p.d = 283; p.r = 224; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 43; p.county = 65; p.val = 278; p.d = 25; p.r = 253; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 42; p.county = 65; p.val = 169; p.d = 23; p.r = 146; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 37; p.county = 65; p.val = 360; p.d = 267; p.r = 93; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 36; p.county = 65; p.val = 806; p.d = 510; p.r = 296; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 38; p.county = 65; p.val = 1004; p.d = 211; p.r = 793; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 40; p.county = 65; p.val = 661; p.d = 352; p.r = 309; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 39; p.county = 65; p.val = 619; p.d = 429; p.r = 190; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 38; p.county = 65; p.val = 317; p.d = 81; p.r = 236; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 65; p.county = 5; p.val = 557; p.d = 544; p.r = 13; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 66; p.county = 5; p.val = 368; p.d = 259; p.r = 109; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 65; p.county = 5; p.val = 293; p.d = 88; p.r = 205; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 63; p.county = 5; p.val = 176; p.d = 83; p.r = 93; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 70; p.county = 5; p.val = 766; p.d = 693; p.r = 73; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 63; p.county = 5; p.val = 274; p.d = 231; p.r = 43; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 66; p.county = 5; p.val = 544; p.d = 378; p.r = 166; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 0; p.county = 21; p.val = 816; p.d = 101; p.r = 715; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 2; p.county = 21; p.val = 965; p.d = 164; p.r = 801; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 1; p.county = 21; p.val = 793; p.d = 81; p.r = 712; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 0; p.county = 21; p.val = 719; p.d = 99; p.r = 620; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 3; p.county = 21; p.val = 937; p.d = 169; p.r = 768; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 1; p.county = 21; p.val = 616; p.d = 309; p.r = 307; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 1; p.county = 21; p.val = 803; p.d = 93; p.r = 710; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 2; p.county = 21; p.val = 619; p.d = 173; p.r = 446; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 2; p.county = 21; p.val = 875; p.d = 161; p.r = 714; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 3; p.county = 21; p.val = 604; p.d = 60; p.r = 544; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 6; p.county = 21; p.val = 398; p.d = 19; p.r = 379; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 8; p.county = 21; p.val = 280; p.d = 30; p.r = 250; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 7; p.county = 21; p.val = 893; p.d = 169; p.r = 724; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 5; p.county = 21; p.val = 787; p.d = 112; p.r = 675; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 6; p.county = 21; p.val = 646; p.d = 74; p.r = 572; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 5; p.county = 21; p.val = 687; p.d = 69; p.r = 618; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 4; p.county = 21; p.val = 996; p.d = 226; p.r = 770; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 4; p.county = 21; p.val = 809; p.d = 231; p.r = 578; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 3; p.county = 21; p.val = 584; p.d = 497; p.r = 87; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 68; p.county = 49; p.val = 455; p.d = 202; p.r = 253; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 69; p.county = 49; p.val = 621; p.d = 317; p.r = 304; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 70; p.county = 49; p.val = 876; p.d = 436; p.r = 440; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 70; p.county = 49; p.val = 1237; p.d = 799; p.r = 438; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 66; p.county = 49; p.val = 57; p.d = 35; p.r = 22; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 68; p.county = 49; p.val = 356; p.d = 149; p.r = 207; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 72; p.county = 49; p.val = 578; p.d = 325; p.r = 253; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 74; p.county = 49; p.val = 253; p.d = 137; p.r = 116; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 75; p.county = 49; p.val = 769; p.d = 513; p.r = 256; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 70; p.county = 49; p.val = 302; p.d = 282; p.r = 20; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 70; p.county = 49; p.val = 173; p.d = 49; p.r = 124; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 72; p.county = 49; p.val = 218; p.d = 43; p.r = 175; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 73; p.county = 49; p.val = 602; p.d = 190; p.r = 412; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 74; p.county = 49; p.val = 1351; p.d = 1090; p.r = 261; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 75; p.county = 49; p.val = 307; p.d = 214; p.r = 93; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 77; p.county = 49; p.val = 135; p.d = 120; p.r = 15; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 76; p.county = 49; p.val = 293; p.d = 266; p.r = 27; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 5; p.county = 77; p.val = 949; p.d = 161; p.r = 788; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 4; p.county = 77; p.val = 1050; p.d = 181; p.r = 869; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 6; p.county = 77; p.val = 906; p.d = 91; p.r = 815; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 7; p.county = 77; p.val = 791; p.d = 117; p.r = 674; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 8; p.county = 77; p.val = 881; p.d = 109; p.r = 772; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 8; p.county = 77; p.val = 813; p.d = 75; p.r = 738; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 7; p.county = 77; p.val = 1049; p.d = 109; p.r = 940; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 7; p.county = 77; p.val = 836; p.d = 81; p.r = 755; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 9; p.county = 77; p.val = 689; p.d = 177; p.r = 512; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 8; p.county = 77; p.val = 841; p.d = 97; p.r = 744; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 9; p.county = 77; p.val = 846; p.d = 147; p.r = 699; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 9; p.county = 77; p.val = 718; p.d = 166; p.r = 552; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 10; p.county = 77; p.val = 735; p.d = 178; p.r = 557; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 11; p.county = 77; p.val = 915; p.d = 205; p.r = 710; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 11; p.county = 77; p.val = 959; p.d = 119; p.r = 840; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 12; p.county = 77; p.val = 834; p.d = 228; p.r = 606; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 13; p.county = 77; p.val = 626; p.d = 248; p.r = 378; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 14; p.county = 77; p.val = 455; p.d = 224; p.r = 231; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 15; p.county = 77; p.val = 764; p.d = 426; p.r = 338; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 14; p.county = 7; p.val = 1312; p.d = 323; p.r = 989; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 13; p.county = 77; p.val = 835; p.d = 123; p.r = 712; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 12; p.county = 77; p.val = 672; p.d = 80; p.r = 592; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 11; p.county = 77; p.val = 587; p.d = 144; p.r = 443; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 10; p.county = 77; p.val = 984; p.d = 157; p.r = 827; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 10; p.county = 77; p.val = 597; p.d = 40; p.r = 557; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 12; p.county = 77; p.val = 838; p.d = 99; p.r = 739; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 11; p.county = 77; p.val = 817; p.d = 108; p.r = 709; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 10; p.county = 77; p.val = 784; p.d = 219; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 9; p.county = 77; p.val = 868; p.d = 103; p.r = 765; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 8; p.county = 77; p.val = 776; p.d = 92; p.r = 684; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 41; p.county = 89; p.val = 361; p.d = 55; p.r = 306; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 40; p.county = 89; p.val = 166; p.d = 70; p.r = 96; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 43; p.county = 89; p.val = 225; p.d = 131; p.r = 94; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 42; p.county = 89; p.val = 257; p.d = 71; p.r = 186; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 42; p.county = 89; p.val = 326; p.d = 203; p.r = 123; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 42; p.county = 89; p.val = 184; p.d = 152; p.r = 32; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 45; p.county = 89; p.val = 292; p.d = 195; p.r = 97; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 45; p.county = 89; p.val = 453; p.d = 440; p.r = 13; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 44; p.county = 89; p.val = 1121; p.d = 1050; p.r = 71; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 46; p.county = 89; p.val = 715; p.d = 582; p.r = 133; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 43; p.county = 89; p.val = 1035; p.d = 680; p.r = 355; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 42; p.county = 89; p.val = 583; p.d = 195; p.r = 388; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 45; p.county = 89; p.val = 421; p.d = 211; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 44; p.county = 89; p.val = 947; p.d = 807; p.r = 140; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 46; p.county = 89; p.val = 432; p.d = 385; p.r = 47; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 45; p.county = 89; p.val = 214; p.d = 109; p.r = 105; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 48; p.county = 89; p.val = 185; p.d = 178; p.r = 7; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 89; p.val = 272; p.d = 10; p.r = 262; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 48; p.county = 89; p.val = 644; p.d = 458; p.r = 186; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 50; p.county = 89; p.val = 240; p.d = 73; p.r = 167; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 51; p.county = 89; p.val = 549; p.d = 488; p.r = 61; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 52; p.county = 89; p.val = 419; p.d = 105; p.r = 314; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 47; p.county = 89; p.val = 618; p.d = 415; p.r = 203; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 48; p.county = 89; p.val = 736; p.d = 641; p.r = 95; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 48; p.county = 89; p.val = 904; p.d = 735; p.r = 169; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 50; p.county = 89; p.val = 636; p.d = 584; p.r = 52; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 54; p.county = 89; p.val = 186; p.d = 67; p.r = 119; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 29; p.county = 1; p.val = 1153; p.d = 375; p.r = 778; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 31; p.county = 1; p.val = 958; p.d = 571; p.r = 387; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 32; p.county = 1; p.val = 690; p.d = 328; p.r = 362; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 29; p.county = 1; p.val = 557; p.d = 201; p.r = 356; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 26; p.county = 1; p.val = 794; p.d = 161; p.r = 633; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 22; p.county = 7; p.val = 960; p.d = 189; p.r = 771; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 32; p.county = 1; p.val = 1307; p.d = 788; p.r = 519; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 28; p.county = 1; p.val = 640; p.d = 135; p.r = 505; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 24; p.county = 1; p.val = 391; p.d = 67; p.r = 324; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 26; p.county = 1; p.val = 1020; p.d = 357; p.r = 663; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 23; p.county = 1; p.val = 533; p.d = 208; p.r = 325; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 25; p.county = 1; p.val = 794; p.d = 167; p.r = 627; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 29; p.county = 1; p.val = 740; p.d = 124; p.r = 616; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 31; p.county = 1; p.val = 558; p.d = 164; p.r = 394; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 61; p.county = 9; p.val = 144; p.d = 43; p.r = 101; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 60; p.county = 9; p.val = 174; p.d = 89; p.r = 85; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 62; p.county = 9; p.val = 545; p.d = 243; p.r = 302; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 56; p.county = 9; p.val = 1121; p.d = 938; p.r = 183; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 59; p.county = 9; p.val = 118; p.d = 77; p.r = 41; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 57; p.county = 9; p.val = 74; p.d = 43; p.r = 31; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 63; p.county = 9; p.val = 93; p.d = 4; p.r = 89; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 63; p.county = 9; p.val = 101; p.d = 8; p.r = 93; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 61; p.county = 9; p.val = 270; p.d = 119; p.r = 151; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 58; p.county = 9; p.val = 1242; p.d = 960; p.r = 282; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 55; p.county = 9; p.val = 869; p.d = 761; p.r = 108; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 56; p.county = 9; p.val = 1112; p.d = 538; p.r = 574; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 57; p.county = 11; p.val = 378; p.d = 200; p.r = 178; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 57; p.county = 11; p.val = 883; p.d = 318; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 59; p.county = 11; p.val = 825; p.d = 517; p.r = 308; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 56; p.county = 11; p.val = 617; p.d = 439; p.r = 178; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 55; p.county = 11; p.val = 398; p.d = 281; p.r = 117; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 54; p.county = 11; p.val = 417; p.d = 203; p.r = 214; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 61; p.county = 11; p.val = 405; p.d = 163; p.r = 242; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 53; p.county = 11; p.val = 572; p.d = 460; p.r = 112; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 59; p.county = 11; p.val = 837; p.d = 387; p.r = 450; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 52; p.county = 11; p.val = 906; p.d = 579; p.r = 327; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 55; p.county = 11; p.val = 394; p.d = 127; p.r = 267; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 54; p.county = 11; p.val = 585; p.d = 226; p.r = 359; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 59; p.county = 11; p.val = 0; p.d = 0; p.r = 0; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 58; p.county = 11; p.val = 622; p.d = 76; p.r = 546; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 59; p.county = 11; p.val = 473; p.d = 30; p.r = 443; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 47; p.county = 17; p.val = 162; p.d = 68; p.r = 94; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 44; p.county = 17; p.val = 386; p.d = 178; p.r = 208; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 47; p.county = 17; p.val = 685; p.d = 323; p.r = 362; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 43; p.county = 17; p.val = 646; p.d = 189; p.r = 457; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 44; p.county = 17; p.val = 214; p.d = 124; p.r = 90; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 41; p.county = 17; p.val = 1224; p.d = 336; p.r = 888; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 45; p.county = 17; p.val = 791; p.d = 451; p.r = 340; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 45; p.county = 17; p.val = 305; p.d = 172; p.r = 133; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 17; p.val = 1206; p.d = 941; p.r = 265; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 46; p.county = 17; p.val = 959; p.d = 443; p.r = 516; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 49; p.county = 17; p.val = 524; p.d = 280; p.r = 244; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 50; p.county = 17; p.val = 258; p.d = 68; p.r = 190; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 67; p.county = 19; p.val = 900; p.d = 496; p.r = 404; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 64; p.county = 19; p.val = 630; p.d = 350; p.r = 280; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 72; p.county = 19; p.val = 1047; p.d = 501; p.r = 546; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 72; p.county = 19; p.val = 768; p.d = 675; p.r = 93; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 69; p.county = 19; p.val = 854; p.d = 634; p.r = 220; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 67; p.county = 35; p.val = 820; p.d = 350; p.r = 470; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 66; p.county = 35; p.val = 726; p.d = 372; p.r = 354; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 72; p.county = 19; p.val = 741; p.d = 512; p.r = 229; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 71; p.county = 19; p.val = 605; p.d = 531; p.r = 74; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 70; p.county = 19; p.val = 434; p.d = 221; p.r = 213; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 74; p.county = 19; p.val = 1234; p.d = 660; p.r = 574; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 73; p.county = 19; p.val = 1092; p.d = 617; p.r = 475; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 73; p.county = 19; p.val = 2403; p.d = 1096; p.r = 1307; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 79; p.county = 19; p.val = 1119; p.d = 550; p.r = 569; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 76; p.county = 19; p.val = 796; p.d = 531; p.r = 265; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 78; p.county = 19; p.val = 1251; p.d = 429; p.r = 822; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 79; p.county = 19; p.val = 1699; p.d = 713; p.r = 986; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 75; p.county = 19; p.val = 763; p.d = 585; p.r = 178; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 63; p.county = 19; p.val = 1204; p.d = 847; p.r = 357; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 71; p.county = 19; p.val = 956; p.d = 510; p.r = 446; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 73; p.county = 19; p.val = 973; p.d = 588; p.r = 385; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 72; p.county = 19; p.val = 640; p.d = 397; p.r = 243; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 70; p.county = 19; p.val = 495; p.d = 170; p.r = 325; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 71; p.county = 19; p.val = 1244; p.d = 534; p.r = 710; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 74; p.county = 19; p.val = 1774; p.d = 734; p.r = 1040; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 70; p.county = 19; p.val = 2108; p.d = 907; p.r = 1201; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 69; p.county = 35; p.val = 776; p.d = 379; p.r = 397; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 72; p.county = 19; p.val = 1100; p.d = 402; p.r = 698; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 74; p.county = 19; p.val = 933; p.d = 577; p.r = 356; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 74; p.county = 19; p.val = 1350; p.d = 429; p.r = 921; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 71; p.county = 19; p.val = 449; p.d = 171; p.r = 278; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 76; p.county = 19; p.val = 1154; p.d = 599; p.r = 555; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 76; p.county = 19; p.val = 700; p.d = 389; p.r = 311; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 69; p.county = 19; p.val = 888; p.d = 328; p.r = 560; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 69; p.county = 19; p.val = 920; p.d = 273; p.r = 647; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 68; p.county = 19; p.val = 1535; p.d = 509; p.r = 1026; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 70; p.county = 19; p.val = 1114; p.d = 487; p.r = 627; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 73; p.county = 19; p.val = 790; p.d = 290; p.r = 500; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 72; p.county = 19; p.val = 1002; p.d = 334; p.r = 668; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 70; p.county = 19; p.val = 2148; p.d = 1077; p.r = 1071; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 73; p.county = 19; p.val = 1282; p.d = 641; p.r = 641; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 72; p.county = 19; p.val = 2149; p.d = 1125; p.r = 1024; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 76; p.county = 19; p.val = 479; p.d = 400; p.r = 79; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 75; p.county = 19; p.val = 1316; p.d = 722; p.r = 594; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 77; p.county = 19; p.val = 773; p.d = 363; p.r = 410; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 71; p.county = 19; p.val = 715; p.d = 344; p.r = 371; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 75; p.county = 19; p.val = 977; p.d = 460; p.r = 517; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 73; p.county = 19; p.val = 1094; p.d = 834; p.r = 260; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 12; p.county = 25; p.val = 613; p.d = 354; p.r = 259; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 18; p.county = 25; p.val = 450; p.d = 163; p.r = 287; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 12; p.county = 25; p.val = 245; p.d = 67; p.r = 178; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 13; p.county = 25; p.val = 649; p.d = 261; p.r = 388; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 12; p.county = 25; p.val = 317; p.d = 70; p.r = 247; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 13; p.county = 25; p.val = 825; p.d = 339; p.r = 486; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 14; p.county = 25; p.val = 589; p.d = 305; p.r = 284; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 15; p.county = 25; p.val = 1010; p.d = 758; p.r = 252; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 17; p.county = 25; p.val = 246; p.d = 39; p.r = 207; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 20; p.county = 25; p.val = 496; p.d = 71; p.r = 425; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 15; p.county = 25; p.val = 239; p.d = 90; p.r = 149; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 15; p.county = 25; p.val = 419; p.d = 142; p.r = 277; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 13; p.county = 25; p.val = 908; p.d = 546; p.r = 362; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 18; p.county = 25; p.val = 413; p.d = 167; p.r = 246; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 19; p.county = 25; p.val = 198; p.d = 37; p.r = 161; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 17; p.county = 25; p.val = 687; p.d = 384; p.r = 303; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 12; p.county = 25; p.val = 572; p.d = 136; p.r = 436; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 12; p.county = 25; p.val = 976; p.d = 426; p.r = 550; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 13; p.county = 25; p.val = 1060; p.d = 495; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 15; p.county = 25; p.val = 1091; p.d = 462; p.r = 629; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 14; p.county = 25; p.val = 1068; p.d = 355; p.r = 713; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 16; p.county = 25; p.val = 750; p.d = 259; p.r = 491; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 20; p.county = 25; p.val = 461; p.d = 66; p.r = 395; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 21; p.county = 25; p.val = 1097; p.d = 419; p.r = 678; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 42; p.county = 27; p.val = 642; p.d = 361; p.r = 281; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 40; p.county = 27; p.val = 447; p.d = 57; p.r = 390; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 41; p.county = 27; p.val = 156; p.d = 51; p.r = 105; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 48; p.county = 27; p.val = 362; p.d = 131; p.r = 231; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 43; p.county = 27; p.val = 551; p.d = 286; p.r = 265; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 39; p.county = 27; p.val = 540; p.d = 96; p.r = 444; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 43; p.county = 27; p.val = 313; p.d = 57; p.r = 256; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 45; p.county = 27; p.val = 425; p.d = 275; p.r = 150; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 46; p.county = 27; p.val = 781; p.d = 284; p.r = 497; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 44; p.county = 27; p.val = 678; p.d = 388; p.r = 290; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 40; p.county = 27; p.val = 438; p.d = 177; p.r = 261; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 41; p.county = 27; p.val = 393; p.d = 282; p.r = 111; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 48; p.county = 27; p.val = 234; p.d = 180; p.r = 54; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 38; p.county = 27; p.val = 906; p.d = 280; p.r = 626; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 46; p.county = 27; p.val = 872; p.d = 561; p.r = 311; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 43; p.county = 27; p.val = 292; p.d = 163; p.r = 129; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 46; p.county = 27; p.val = 741; p.d = 620; p.r = 121; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 45; p.county = 27; p.val = 699; p.d = 598; p.r = 101; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 46; p.county = 27; p.val = 497; p.d = 416; p.r = 81; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 44; p.county = 27; p.val = 798; p.d = 508; p.r = 290; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 49; p.county = 27; p.val = 1204; p.d = 379; p.r = 825; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 49; p.county = 27; p.val = 1140; p.d = 534; p.r = 606; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 50; p.county = 27; p.val = 1198; p.d = 518; p.r = 680; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 22; p.county = 31; p.val = 1233; p.d = 537; p.r = 696; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 24; p.county = 31; p.val = 691; p.d = 331; p.r = 360; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 26; p.county = 31; p.val = 198; p.d = 109; p.r = 89; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 27; p.county = 31; p.val = 442; p.d = 144; p.r = 298; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 27; p.county = 31; p.val = 900; p.d = 850; p.r = 50; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 23; p.county = 31; p.val = 1065; p.d = 681; p.r = 384; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 25; p.county = 31; p.val = 934; p.d = 920; p.r = 14; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 23; p.county = 31; p.val = 1164; p.d = 479; p.r = 685; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 28; p.county = 31; p.val = 1574; p.d = 804; p.r = 770; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 25; p.county = 31; p.val = 1267; p.d = 249; p.r = 1018; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 30; p.county = 31; p.val = 1171; p.d = 447; p.r = 724; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 27; p.county = 31; p.val = 551; p.d = 383; p.r = 168; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 25; p.county = 31; p.val = 1017; p.d = 552; p.r = 465; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 28; p.county = 31; p.val = 756; p.d = 282; p.r = 474; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 27; p.county = 31; p.val = 1223; p.d = 660; p.r = 563; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 21; p.county = 31; p.val = 665; p.d = 461; p.r = 204; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 26; p.county = 31; p.val = 523; p.d = 250; p.r = 273; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 25; p.county = 31; p.val = 1452; p.d = 581; p.r = 871; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 26; p.county = 31; p.val = 959; p.d = 472; p.r = 487; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 31; p.county = 31; p.val = 590; p.d = 372; p.r = 218; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 26; p.county = 31; p.val = 504; p.d = 167; p.r = 337; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 25; p.county = 31; p.val = 593; p.d = 436; p.r = 157; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 22; p.county = 31; p.val = 771; p.d = 107; p.r = 664; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 24; p.county = 31; p.val = 903; p.d = 231; p.r = 672; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 24; p.county = 31; p.val = 810; p.d = 227; p.r = 583; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 22; p.county = 33; p.val = 1205; p.d = 226; p.r = 979; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 25; p.county = 33; p.val = 1574; p.d = 820; p.r = 754; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 23; p.county = 33; p.val = 265; p.d = 88; p.r = 177; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 25; p.county = 33; p.val = 852; p.d = 362; p.r = 490; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 23; p.county = 33; p.val = 164; p.d = 52; p.r = 112; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 23; p.county = 33; p.val = 1254; p.d = 838; p.r = 416; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 25; p.county = 33; p.val = 197; p.d = 73; p.r = 124; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 22; p.county = 33; p.val = 143; p.d = 45; p.r = 98; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 21; p.county = 33; p.val = 539; p.d = 224; p.r = 315; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 20; p.county = 33; p.val = 621; p.d = 376; p.r = 245; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 18; p.county = 33; p.val = 184; p.d = 124; p.r = 60; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 21; p.county = 33; p.val = 488; p.d = 315; p.r = 173; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 20; p.county = 33; p.val = 135; p.d = 80; p.r = 55; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 26; p.county = 33; p.val = 576; p.d = 174; p.r = 402; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 25; p.county = 33; p.val = 448; p.d = 102; p.r = 346; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 23; p.county = 33; p.val = 924; p.d = 762; p.r = 162; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 26; p.county = 33; p.val = 325; p.d = 76; p.r = 249; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 26; p.county = 33; p.val = 326; p.d = 180; p.r = 146; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 24; p.county = 33; p.val = 216; p.d = 82; p.r = 134; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 19; p.county = 39; p.val = 54; p.d = 43; p.r = 11; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 22; p.county = 39; p.val = 399; p.d = 349; p.r = 50; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 27; p.county = 55; p.val = 968; p.d = 275; p.r = 693; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 20; p.county = 39; p.val = 256; p.d = 176; p.r = 80; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 27; p.county = 39; p.val = 1195; p.d = 849; p.r = 346; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 20; p.county = 39; p.val = 56; p.d = 17; p.r = 39; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 27; p.county = 39; p.val = 262; p.d = 219; p.r = 43; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 25; p.county = 39; p.val = 644; p.d = 434; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 39; p.val = 510; p.d = 261; p.r = 249; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 20; p.county = 39; p.val = 53; p.d = 17; p.r = 36; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 26; p.county = 39; p.val = 1345; p.d = 906; p.r = 439; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 26; p.county = 39; p.val = 662; p.d = 374; p.r = 288; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 24; p.county = 39; p.val = 462; p.d = 380; p.r = 82; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 25; p.county = 39; p.val = 467; p.d = 267; p.r = 200; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 24; p.county = 39; p.val = 811; p.d = 623; p.r = 188; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 23; p.county = 39; p.val = 702; p.d = 390; p.r = 312; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 21; p.county = 39; p.val = 206; p.d = 147; p.r = 59; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 20; p.county = 39; p.val = 114; p.d = 93; p.r = 21; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 24; p.county = 39; p.val = 440; p.d = 341; p.r = 99; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 28; p.county = 39; p.val = 483; p.d = 411; p.r = 72; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 21; p.county = 39; p.val = 613; p.d = 320; p.r = 293; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 23; p.county = 39; p.val = 977; p.d = 250; p.r = 727; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 27; p.county = 41; p.val = 368; p.d = 106; p.r = 262; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 28; p.county = 41; p.val = 631; p.d = 464; p.r = 167; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 33; p.county = 41; p.val = 636; p.d = 270; p.r = 366; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 32; p.county = 41; p.val = 1216; p.d = 366; p.r = 850; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 31; p.county = 41; p.val = 1204; p.d = 558; p.r = 646; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 36; p.county = 41; p.val = 624; p.d = 182; p.r = 442; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 30; p.county = 41; p.val = 1239; p.d = 344; p.r = 895; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 30; p.county = 41; p.val = 1543; p.d = 592; p.r = 951; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 33; p.county = 41; p.val = 510; p.d = 103; p.r = 407; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 33; p.county = 41; p.val = 749; p.d = 205; p.r = 544; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 29; p.county = 41; p.val = 727; p.d = 692; p.r = 35; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 30; p.county = 41; p.val = 264; p.d = 214; p.r = 50; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 29; p.county = 41; p.val = 886; p.d = 328; p.r = 558; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 36; p.county = 41; p.val = 400; p.d = 62; p.r = 338; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 38; p.county = 41; p.val = 573; p.d = 71; p.r = 502; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 38; p.county = 41; p.val = 401; p.d = 90; p.r = 311; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 41; p.county = 41; p.val = 1630; p.d = 504; p.r = 1126; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 39; p.county = 41; p.val = 827; p.d = 458; p.r = 369; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 40; p.county = 41; p.val = 1248; p.d = 1217; p.r = 31; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 39; p.county = 41; p.val = 1097; p.d = 683; p.r = 414; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 40; p.county = 41; p.val = 270; p.d = 105; p.r = 165; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 30; p.county = 41; p.val = 1395; p.d = 657; p.r = 738; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 28; p.county = 41; p.val = 989; p.d = 344; p.r = 645; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 38; p.county = 41; p.val = 568; p.d = 184; p.r = 384; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 34; p.county = 41; p.val = 519; p.d = 355; p.r = 164; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 35; p.county = 41; p.val = 820; p.d = 147; p.r = 673; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 37; p.county = 41; p.val = 1073; p.d = 490; p.r = 583; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 35; p.county = 41; p.val = 856; p.d = 250; p.r = 606; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 36; p.county = 41; p.val = 546; p.d = 407; p.r = 139; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 40; p.county = 41; p.val = 305; p.d = 18; p.r = 287; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 36; p.county = 41; p.val = 394; p.d = 38; p.r = 356; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 38; p.county = 41; p.val = 685; p.d = 291; p.r = 394; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 32; p.county = 41; p.val = 1078; p.d = 873; p.r = 205; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 32; p.county = 41; p.val = 1014; p.d = 404; p.r = 610; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 31; p.county = 41; p.val = 1058; p.d = 862; p.r = 196; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 32; p.county = 41; p.val = 803; p.d = 378; p.r = 425; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 41; p.county = 41; p.val = 503; p.d = 103; p.r = 400; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 33; p.county = 41; p.val = 1070; p.d = 269; p.r = 801; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 31; p.county = 41; p.val = 2142; p.d = 1080; p.r = 1062; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 57; p.county = 43; p.val = 550; p.d = 145; p.r = 405; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 55; p.county = 43; p.val = 337; p.d = 111; p.r = 226; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 55; p.county = 43; p.val = 995; p.d = 377; p.r = 618; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 54; p.county = 43; p.val = 317; p.d = 122; p.r = 195; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 53; p.county = 43; p.val = 1073; p.d = 562; p.r = 511; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 54; p.county = 43; p.val = 730; p.d = 603; p.r = 127; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 53; p.county = 43; p.val = 729; p.d = 82; p.r = 647; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 53; p.county = 43; p.val = 678; p.d = 150; p.r = 528; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 52; p.county = 43; p.val = 1003; p.d = 201; p.r = 802; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 51; p.county = 43; p.val = 1269; p.d = 1042; p.r = 227; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 52; p.county = 43; p.val = 903; p.d = 491; p.r = 412; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 50; p.county = 43; p.val = 555; p.d = 229; p.r = 326; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 59; p.county = 43; p.val = 797; p.d = 661; p.r = 136; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 56; p.county = 43; p.val = 455; p.d = 81; p.r = 374; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 51; p.county = 43; p.val = 557; p.d = 434; p.r = 123; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 43; p.val = 680; p.d = 509; p.r = 171; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 45; p.county = 43; p.val = 700; p.d = 252; p.r = 448; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 51; p.county = 43; p.val = 1809; p.d = 544; p.r = 1265; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 56; p.county = 43; p.val = 1406; p.d = 355; p.r = 1051; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 52; p.county = 43; p.val = 1483; p.d = 428; p.r = 1055; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 49; p.county = 43; p.val = 587; p.d = 167; p.r = 420; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 49; p.county = 43; p.val = 1427; p.d = 422; p.r = 1005; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 48; p.county = 43; p.val = 402; p.d = 367; p.r = 35; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 47; p.county = 43; p.val = 161; p.d = 34; p.r = 127; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 45; p.county = 43; p.val = 443; p.d = 371; p.r = 72; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 44; p.county = 43; p.val = 743; p.d = 195; p.r = 548; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 18; p.county = 45; p.val = 1489; p.d = 212; p.r = 1277; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 17; p.county = 45; p.val = 1324; p.d = 214; p.r = 1110; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 16; p.county = 45; p.val = 769; p.d = 128; p.r = 641; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 16; p.county = 45; p.val = 1383; p.d = 297; p.r = 1086; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 15; p.county = 45; p.val = 1411; p.d = 503; p.r = 908; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 14; p.county = 45; p.val = 968; p.d = 286; p.r = 682; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 15; p.county = 45; p.val = 1241; p.d = 587; p.r = 654; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 14; p.county = 45; p.val = 1526; p.d = 771; p.r = 755; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 13; p.county = 45; p.val = 1185; p.d = 454; p.r = 731; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 14; p.county = 7; p.val = 583; p.d = 128; p.r = 455; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 13; p.county = 45; p.val = 1412; p.d = 356; p.r = 1056; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 13; p.county = 45; p.val = 1740; p.d = 968; p.r = 772; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 12; p.county = 45; p.val = 917; p.d = 276; p.r = 641; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 12; p.county = 45; p.val = 879; p.d = 785; p.r = 94; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 12; p.county = 7; p.val = 1940; p.d = 422; p.r = 1518; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 11; p.county = 45; p.val = 1331; p.d = 373; p.r = 958; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 12; p.county = 45; p.val = 1925; p.d = 565; p.r = 1360; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 11; p.county = 45; p.val = 2079; p.d = 553; p.r = 1526; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 11; p.county = 7; p.val = 1956; p.d = 427; p.r = 1529; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 11; p.county = 45; p.val = 1512; p.d = 513; p.r = 999; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 10; p.county = 45; p.val = 1319; p.d = 790; p.r = 529; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 10; p.county = 45; p.val = 1081; p.d = 405; p.r = 676; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 10; p.county = 45; p.val = 1202; p.d = 405; p.r = 797; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 9; p.county = 45; p.val = 1457; p.d = 485; p.r = 972; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 9; p.county = 45; p.val = 1922; p.d = 621; p.r = 1301; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 9; p.county = 45; p.val = 1012; p.d = 345; p.r = 667; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 8; p.county = 45; p.val = 1483; p.d = 583; p.r = 900; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 8; p.county = 45; p.val = 1712; p.d = 457; p.r = 1255; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 8; p.county = 45; p.val = 1322; p.d = 363; p.r = 959; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 7; p.county = 45; p.val = 1731; p.d = 584; p.r = 1147; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 7; p.county = 45; p.val = 893; p.d = 225; p.r = 668; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 7; p.county = 45; p.val = 1732; p.d = 581; p.r = 1151; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 6; p.county = 45; p.val = 1101; p.d = 227; p.r = 874; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 6; p.county = 45; p.val = 1568; p.d = 286; p.r = 1282; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 6; p.county = 45; p.val = 1073; p.d = 263; p.r = 810; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 5; p.county = 45; p.val = 2233; p.d = 365; p.r = 1868; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 5; p.county = 45; p.val = 1543; p.d = 264; p.r = 1279; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 5; p.county = 45; p.val = 1711; p.d = 317; p.r = 1394; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 4; p.county = 45; p.val = 1556; p.d = 201; p.r = 1355; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 4; p.county = 45; p.val = 1877; p.d = 278; p.r = 1599; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 3; p.county = 45; p.val = 1678; p.d = 158; p.r = 1520; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 3; p.county = 45; p.val = 1252; p.d = 265; p.r = 987; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 1; p.county = 45; p.val = 1327; p.d = 222; p.r = 1105; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 1; p.county = 45; p.val = 1619; p.d = 284; p.r = 1335; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 2; p.county = 45; p.val = 1085; p.d = 237; p.r = 848; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 15; p.county = 7; p.val = 1167; p.d = 184; p.r = 983; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 32; p.county = 61; p.val = 446; p.d = 146; p.r = 300; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 30; p.county = 61; p.val = 388; p.d = 321; p.r = 67; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 29; p.county = 61; p.val = 325; p.d = 217; p.r = 108; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 29; p.county = 61; p.val = 500; p.d = 290; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 28; p.county = 61; p.val = 246; p.d = 103; p.r = 143; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 32; p.county = 61; p.val = 379; p.d = 352; p.r = 27; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 30; p.county = 61; p.val = 301; p.d = 150; p.r = 151; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 29; p.county = 61; p.val = 420; p.d = 165; p.r = 255; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 33; p.county = 61; p.val = 554; p.d = 484; p.r = 70; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 30; p.county = 61; p.val = 437; p.d = 322; p.r = 115; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 31; p.county = 61; p.val = 182; p.d = 153; p.r = 29; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 35; p.county = 61; p.val = 283; p.d = 223; p.r = 60; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 31; p.county = 61; p.val = 480; p.d = 343; p.r = 137; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 33; p.county = 61; p.val = 561; p.d = 406; p.r = 155; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 27; p.county = 61; p.val = 152; p.d = 51; p.r = 101; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 25; p.county = 61; p.val = 139; p.d = 63; p.r = 76; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 32; p.county = 61; p.val = 124; p.d = 95; p.r = 29; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 27; p.county = 61; p.val = 356; p.d = 166; p.r = 190; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 26; p.county = 61; p.val = 374; p.d = 103; p.r = 271; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 39; p.county = 67; p.val = 1101; p.d = 764; p.r = 337; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 35; p.county = 67; p.val = 264; p.d = 195; p.r = 69; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 32; p.county = 67; p.val = 576; p.d = 404; p.r = 172; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 30; p.county = 67; p.val = 892; p.d = 400; p.r = 492; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 29; p.county = 67; p.val = 990; p.d = 506; p.r = 484; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 31; p.county = 67; p.val = 865; p.d = 349; p.r = 516; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 27; p.county = 67; p.val = 177; p.d = 133; p.r = 44; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 27; p.county = 67; p.val = 714; p.d = 464; p.r = 250; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 27; p.county = 67; p.val = 400; p.d = 249; p.r = 151; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 29; p.county = 67; p.val = 1018; p.d = 747; p.r = 271; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 30; p.county = 67; p.val = 984; p.d = 612; p.r = 372; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 28; p.county = 67; p.val = 513; p.d = 209; p.r = 304; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 30; p.county = 67; p.val = 922; p.d = 280; p.r = 642; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 33; p.county = 67; p.val = 900; p.d = 620; p.r = 280; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 31; p.county = 67; p.val = 1719; p.d = 1316; p.r = 403; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 13; p.county = 69; p.val = 297; p.d = 150; p.r = 147; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 20; p.county = 69; p.val = 241; p.d = 107; p.r = 134; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 13; p.county = 69; p.val = 554; p.d = 311; p.r = 243; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 23; p.county = 69; p.val = 299; p.d = 101; p.r = 198; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 20; p.county = 69; p.val = 757; p.d = 369; p.r = 388; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 16; p.county = 69; p.val = 318; p.d = 165; p.r = 153; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 12; p.county = 69; p.val = 1040; p.d = 529; p.r = 511; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 14; p.county = 69; p.val = 674; p.d = 404; p.r = 270; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 18; p.county = 69; p.val = 1125; p.d = 818; p.r = 307; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 15; p.county = 69; p.val = 625; p.d = 157; p.r = 468; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 17; p.county = 69; p.val = 606; p.d = 567; p.r = 39; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 17; p.county = 69; p.val = 794; p.d = 581; p.r = 213; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 15; p.county = 69; p.val = 1205; p.d = 661; p.r = 544; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 27; p.county = 71; p.val = 529; p.d = 293; p.r = 236; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 25; p.county = 71; p.val = 358; p.d = 110; p.r = 248; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 26; p.county = 71; p.val = 240; p.d = 62; p.r = 178; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 29; p.county = 71; p.val = 493; p.d = 159; p.r = 334; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 29; p.county = 71; p.val = 711; p.d = 305; p.r = 406; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 25; p.county = 71; p.val = 366; p.d = 108; p.r = 258; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 71; p.val = 382; p.d = 129; p.r = 253; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 29; p.county = 71; p.val = 786; p.d = 219; p.r = 567; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 22; p.county = 71; p.val = 64; p.d = 47; p.r = 17; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 29; p.county = 71; p.val = 246; p.d = 31; p.r = 215; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 25; p.county = 71; p.val = 745; p.d = 413; p.r = 332; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 71; p.val = 822; p.d = 236; p.r = 586; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 71; p.val = 498; p.d = 127; p.r = 371; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 29; p.county = 71; p.val = 1204; p.d = 503; p.r = 701; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 28; p.county = 71; p.val = 515; p.d = 173; p.r = 342; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 31; p.county = 71; p.val = 594; p.d = 88; p.r = 506; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 71; p.val = 788; p.d = 267; p.r = 521; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 31; p.county = 71; p.val = 373; p.d = 58; p.r = 315; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 20; p.county = 71; p.val = 559; p.d = 171; p.r = 388; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 22; p.county = 71; p.val = 582; p.d = 183; p.r = 399; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 32; p.county = 71; p.val = 982; p.d = 191; p.r = 791; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 32; p.county = 71; p.val = 1125; p.d = 209; p.r = 916; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 51; p.county = 75; p.val = 597; p.d = 369; p.r = 228; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 51; p.county = 75; p.val = 946; p.d = 936; p.r = 10; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 50; p.county = 75; p.val = 394; p.d = 387; p.r = 7; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 50; p.county = 75; p.val = 837; p.d = 409; p.r = 428; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 52; p.county = 75; p.val = 874; p.d = 802; p.r = 72; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 52; p.county = 75; p.val = 1015; p.d = 503; p.r = 512; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 49; p.county = 75; p.val = 536; p.d = 325; p.r = 211; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 53; p.county = 75; p.val = 468; p.d = 322; p.r = 146; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 54; p.county = 75; p.val = 955; p.d = 709; p.r = 246; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 56; p.county = 75; p.val = 614; p.d = 375; p.r = 239; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 57; p.county = 75; p.val = 745; p.d = 336; p.r = 409; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 59; p.county = 75; p.val = 359; p.d = 130; p.r = 229; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 54; p.county = 75; p.val = 504; p.d = 244; p.r = 260; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 55; p.county = 75; p.val = 742; p.d = 189; p.r = 553; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 51; p.county = 75; p.val = 530; p.d = 430; p.r = 100; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 53; p.county = 75; p.val = 1007; p.d = 457; p.r = 550; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 55; p.county = 75; p.val = 1077; p.d = 867; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 51; p.county = 75; p.val = 442; p.d = 156; p.r = 286; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 56; p.county = 75; p.val = 1223; p.d = 1052; p.r = 171; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 55; p.county = 75; p.val = 1192; p.d = 704; p.r = 488; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 48; p.county = 75; p.val = 1082; p.d = 809; p.r = 273; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 49; p.county = 75; p.val = 1394; p.d = 1062; p.r = 332; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 49; p.county = 75; p.val = 702; p.d = 294; p.r = 408; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 46; p.county = 75; p.val = 867; p.d = 436; p.r = 431; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 47; p.county = 75; p.val = 844; p.d = 500; p.r = 344; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 52; p.county = 75; p.val = 922; p.d = 626; p.r = 296; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 51; p.county = 75; p.val = 906; p.d = 452; p.r = 454; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 53; p.county = 75; p.val = 852; p.d = 629; p.r = 223; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 55; p.county = 75; p.val = 459; p.d = 292; p.r = 167; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 50; p.county = 75; p.val = 912; p.d = 385; p.r = 527; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 52; p.county = 75; p.val = 896; p.d = 861; p.r = 35; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 50; p.county = 75; p.val = 823; p.d = 467; p.r = 356; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 53; p.county = 75; p.val = 913; p.d = 709; p.r = 204; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 48; p.county = 75; p.val = 643; p.d = 418; p.r = 225; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 50; p.county = 75; p.val = 783; p.d = 496; p.r = 287; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 53; p.county = 75; p.val = 1017; p.d = 647; p.r = 370; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 49; p.county = 75; p.val = 618; p.d = 319; p.r = 299; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 32; p.county = 81; p.val = 334; p.d = 70; p.r = 264; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 35; p.county = 81; p.val = 289; p.d = 38; p.r = 251; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 36; p.county = 81; p.val = 708; p.d = 299; p.r = 409; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 32; p.county = 81; p.val = 429; p.d = 212; p.r = 217; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 34; p.county = 81; p.val = 673; p.d = 82; p.r = 591; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 33; p.county = 81; p.val = 878; p.d = 107; p.r = 771; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 35; p.county = 81; p.val = 305; p.d = 78; p.r = 227; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 35; p.county = 81; p.val = 173; p.d = 39; p.r = 134; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 39; p.county = 81; p.val = 158; p.d = 75; p.r = 83; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 34; p.county = 81; p.val = 508; p.d = 70; p.r = 438; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 36; p.county = 81; p.val = 797; p.d = 546; p.r = 251; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 35; p.county = 81; p.val = 416; p.d = 39; p.r = 377; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 39; p.county = 81; p.val = 305; p.d = 155; p.r = 150; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 36; p.county = 81; p.val = 193; p.d = 22; p.r = 171; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 38; p.county = 81; p.val = 450; p.d = 91; p.r = 359; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 37; p.county = 81; p.val = 658; p.d = 257; p.r = 401; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 40; p.county = 81; p.val = 568; p.d = 315; p.r = 253; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 33; p.county = 85; p.val = 1285; p.d = 1105; p.r = 180; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 36; p.county = 85; p.val = 642; p.d = 259; p.r = 383; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 35; p.county = 85; p.val = 690; p.d = 337; p.r = 353; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 35; p.county = 85; p.val = 785; p.d = 294; p.r = 491; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 37; p.county = 85; p.val = 507; p.d = 421; p.r = 86; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 38; p.county = 85; p.val = 345; p.d = 292; p.r = 53; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 38; p.county = 85; p.val = 858; p.d = 310; p.r = 548; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 36; p.county = 85; p.val = 1022; p.d = 626; p.r = 396; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 40; p.county = 85; p.val = 955; p.d = 414; p.r = 541; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 39; p.county = 85; p.val = 819; p.d = 430; p.r = 389; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 37; p.county = 85; p.val = 569; p.d = 121; p.r = 448; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 37; p.county = 85; p.val = 590; p.d = 252; p.r = 338; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 38; p.county = 85; p.val = 530; p.d = 202; p.r = 328; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 38; p.county = 85; p.val = 419; p.d = 365; p.r = 54; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 39; p.county = 85; p.val = 830; p.d = 376; p.r = 454; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 40; p.county = 85; p.val = 1118; p.d = 308; p.r = 810; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 39; p.county = 85; p.val = 1058; p.d = 399; p.r = 659; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 38; p.county = 85; p.val = 968; p.d = 799; p.r = 169; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 40; p.county = 85; p.val = 1019; p.d = 494; p.r = 525; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 42; p.county = 85; p.val = 806; p.d = 442; p.r = 364; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 34; p.county = 85; p.val = 642; p.d = 462; p.r = 180; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 35; p.county = 85; p.val = 886; p.d = 499; p.r = 387; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 43; p.county = 85; p.val = 1222; p.d = 642; p.r = 580; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 36; p.county = 85; p.val = 923; p.d = 473; p.r = 450; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 37; p.county = 85; p.val = 1005; p.d = 626; p.r = 379; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 41; p.county = 85; p.val = 1015; p.d = 225; p.r = 790; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 36; p.county = 85; p.val = 1077; p.d = 529; p.r = 548; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 13; p.county = 87; p.val = 457; p.d = 154; p.r = 303; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 14; p.county = 87; p.val = 181; p.d = 131; p.r = 50; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 16; p.county = 87; p.val = 904; p.d = 365; p.r = 539; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 12; p.county = 87; p.val = 606; p.d = 205; p.r = 401; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 13; p.county = 87; p.val = 495; p.d = 86; p.r = 409; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 13; p.county = 87; p.val = 521; p.d = 78; p.r = 443; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 12; p.county = 87; p.val = 256; p.d = 77; p.r = 179; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 16; p.county = 87; p.val = 608; p.d = 188; p.r = 420; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 19; p.county = 87; p.val = 297; p.d = 180; p.r = 117; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 18; p.county = 87; p.val = 373; p.d = 335; p.r = 38; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 16; p.county = 87; p.val = 558; p.d = 341; p.r = 217; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 10; p.county = 87; p.val = 696; p.d = 236; p.r = 460; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 12; p.county = 87; p.val = 478; p.d = 90; p.r = 388; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 11; p.county = 87; p.val = 784; p.d = 279; p.r = 505; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 9; p.county = 87; p.val = 747; p.d = 177; p.r = 570; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 14; p.county = 87; p.val = 230; p.d = 74; p.r = 156; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 75; p.county = 53; p.val = 567; p.d = 160; p.r = 407; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 78; p.county = 53; p.val = 361; p.d = 266; p.r = 95; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 78; p.county = 53; p.val = 459; p.d = 252; p.r = 207; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 78; p.county = 53; p.val = 471; p.d = 426; p.r = 45; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 80; p.county = 53; p.val = 489; p.d = 175; p.r = 314; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 80; p.county = 53; p.val = 627; p.d = 195; p.r = 432; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 82; p.county = 53; p.val = 657; p.d = 346; p.r = 311; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 80; p.county = 53; p.val = 1235; p.d = 853; p.r = 382; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 83; p.county = 53; p.val = 723; p.d = 287; p.r = 436; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 82; p.county = 53; p.val = 452; p.d = 279; p.r = 173; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 86; p.county = 53; p.val = 612; p.d = 429; p.r = 183; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 87; p.county = 13; p.val = 871; p.d = 341; p.r = 530; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 92; p.county = 53; p.val = 1256; p.d = 826; p.r = 430; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 86; p.county = 13; p.val = 964; p.d = 331; p.r = 633; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 85; p.county = 53; p.val = 770; p.d = 393; p.r = 377; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 20; p.county = 7; p.val = 1016; p.d = 179; p.r = 837; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 18; p.county = 7; p.val = 503; p.d = 87; p.r = 416; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 19; p.county = 7; p.val = 872; p.d = 196; p.r = 676; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 18; p.county = 7; p.val = 1511; p.d = 418; p.r = 1093; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 16; p.county = 7; p.val = 1707; p.d = 874; p.r = 833; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 22; p.county = 7; p.val = 769; p.d = 150; p.r = 619; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 23; p.county = 7; p.val = 230; p.d = 66; p.r = 164; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 26; p.county = 7; p.val = 430; p.d = 53; p.r = 377; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 26; p.county = 7; p.val = 1010; p.d = 192; p.r = 818; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 25; p.county = 7; p.val = 489; p.d = 73; p.r = 416; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 24; p.county = 7; p.val = 623; p.d = 87; p.r = 536; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 24; p.county = 7; p.val = 846; p.d = 201; p.r = 645; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 23; p.county = 7; p.val = 878; p.d = 186; p.r = 692; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 22; p.county = 7; p.val = 717; p.d = 183; p.r = 534; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 21; p.county = 7; p.val = 1524; p.d = 331; p.r = 1193; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 19; p.county = 7; p.val = 1134; p.d = 429; p.r = 705; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 20; p.county = 7; p.val = 411; p.d = 217; p.r = 194; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 21; p.county = 7; p.val = 1354; p.d = 609; p.r = 745; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 18; p.county = 7; p.val = 887; p.d = 197; p.r = 690; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 17; p.county = 7; p.val = 1138; p.d = 290; p.r = 848; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 15; p.county = 7; p.val = 475; p.d = 127; p.r = 348; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 13; p.county = 7; p.val = 1629; p.d = 234; p.r = 1395; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 12; p.county = 7; p.val = 2687; p.d = 477; p.r = 2210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 13; p.county = 7; p.val = 1682; p.d = 282; p.r = 1400; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 14; p.county = 7; p.val = 1635; p.d = 273; p.r = 1362; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 13; p.county = 7; p.val = 1720; p.d = 319; p.r = 1401; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 15; p.county = 7; p.val = 1978; p.d = 324; p.r = 1654; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 16; p.county = 7; p.val = 1344; p.d = 226; p.r = 1118; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 16; p.county = 7; p.val = 1411; p.d = 312; p.r = 1099; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 17; p.county = 7; p.val = 1648; p.d = 273; p.r = 1375; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 18; p.county = 7; p.val = 360; p.d = 53; p.r = 307; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 20; p.county = 7; p.val = 1165; p.d = 299; p.r = 866; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 20; p.county = 7; p.val = 808; p.d = 127; p.r = 681; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 21; p.county = 7; p.val = 422; p.d = 57; p.r = 365; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 22; p.county = 7; p.val = 708; p.d = 62; p.r = 646; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 24; p.county = 7; p.val = 574; p.d = 70; p.r = 504; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 23; p.county = 7; p.val = 561; p.d = 109; p.r = 452; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 17; p.county = 7; p.val = 974; p.d = 226; p.r = 748; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 18; p.county = 7; p.val = 874; p.d = 196; p.r = 678; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 18; p.county = 7; p.val = 425; p.d = 71; p.r = 354; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 19; p.county = 7; p.val = 1052; p.d = 265; p.r = 787; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 20; p.county = 7; p.val = 550; p.d = 132; p.r = 418; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 21; p.county = 7; p.val = 1096; p.d = 378; p.r = 718; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 20; p.county = 7; p.val = 220; p.d = 195; p.r = 25; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 19; p.county = 7; p.val = 1109; p.d = 379; p.r = 730; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 88; p.county = 13; p.val = 1540; p.d = 519; p.r = 1021; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 87; p.county = 13; p.val = 647; p.d = 267; p.r = 380; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 82; p.county = 13; p.val = 591; p.d = 195; p.r = 396; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 83; p.county = 13; p.val = 655; p.d = 247; p.r = 408; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 87; p.county = 13; p.val = 1439; p.d = 446; p.r = 993; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 89; p.county = 13; p.val = 658; p.d = 238; p.r = 420; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 90; p.county = 13; p.val = 959; p.d = 330; p.r = 629; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 88; p.county = 13; p.val = 845; p.d = 275; p.r = 570; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 90; p.county = 13; p.val = 1516; p.d = 509; p.r = 1007; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 88; p.county = 13; p.val = 852; p.d = 434; p.r = 418; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 87; p.county = 13; p.val = 546; p.d = 157; p.r = 389; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 83; p.county = 13; p.val = 1123; p.d = 380; p.r = 743; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 82; p.county = 13; p.val = 666; p.d = 312; p.r = 354; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 86; p.county = 13; p.val = 873; p.d = 313; p.r = 560; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 84; p.county = 13; p.val = 684; p.d = 360; p.r = 324; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 85; p.county = 13; p.val = 1118; p.d = 397; p.r = 721; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 79; p.county = 13; p.val = 731; p.d = 495; p.r = 236; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 92; p.county = 13; p.val = 689; p.d = 249; p.r = 440; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 90; p.county = 13; p.val = 1229; p.d = 388; p.r = 841; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 91; p.county = 13; p.val = 930; p.d = 217; p.r = 713; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 92; p.county = 13; p.val = 809; p.d = 347; p.r = 462; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 93; p.county = 13; p.val = 720; p.d = 267; p.r = 453; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 89; p.county = 13; p.val = 734; p.d = 273; p.r = 461; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 89; p.county = 13; p.val = 841; p.d = 568; p.r = 273; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 88; p.county = 13; p.val = 761; p.d = 287; p.r = 474; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 90; p.county = 13; p.val = 1023; p.d = 377; p.r = 646; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 91; p.county = 13; p.val = 831; p.d = 318; p.r = 513; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 91; p.county = 13; p.val = 1098; p.d = 467; p.r = 631; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 84; p.county = 13; p.val = 691; p.d = 325; p.r = 366; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 81; p.county = 13; p.val = 581; p.d = 195; p.r = 386; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 80; p.county = 13; p.val = 590; p.d = 431; p.r = 159; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 81; p.county = 13; p.val = 897; p.d = 524; p.r = 373; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 78; p.county = 13; p.val = 747; p.d = 443; p.r = 304; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 76; p.county = 13; p.val = 537; p.d = 484; p.r = 53; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 84; p.county = 13; p.val = 755; p.d = 620; p.r = 135; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 87; p.county = 13; p.val = 869; p.d = 686; p.r = 183; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 83; p.county = 13; p.val = 828; p.d = 519; p.r = 309; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 83; p.county = 13; p.val = 860; p.d = 663; p.r = 197; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 86; p.county = 13; p.val = 816; p.d = 275; p.r = 541; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 82; p.county = 13; p.val = 362; p.d = 151; p.r = 211; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 81; p.county = 13; p.val = 628; p.d = 231; p.r = 397; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 34; p.county = 47; p.val = 495; p.d = 73; p.r = 422; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 24; p.county = 47; p.val = 569; p.d = 206; p.r = 363; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 25; p.county = 47; p.val = 156; p.d = 57; p.r = 99; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 27; p.county = 47; p.val = 926; p.d = 229; p.r = 697; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 26; p.county = 47; p.val = 716; p.d = 372; p.r = 344; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 27; p.county = 47; p.val = 952; p.d = 167; p.r = 785; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 28; p.county = 47; p.val = 725; p.d = 441; p.r = 284; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 28; p.county = 47; p.val = 504; p.d = 194; p.r = 310; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 29; p.county = 47; p.val = 545; p.d = 518; p.r = 27; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 29; p.county = 47; p.val = 924; p.d = 138; p.r = 786; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 30; p.county = 47; p.val = 332; p.d = 265; p.r = 67; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 35; p.county = 47; p.val = 113; p.d = 34; p.r = 79; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 34; p.county = 47; p.val = 664; p.d = 157; p.r = 507; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 31; p.county = 47; p.val = 531; p.d = 292; p.r = 239; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 30; p.county = 47; p.val = 516; p.d = 73; p.r = 443; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 32; p.county = 47; p.val = 482; p.d = 84; p.r = 398; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 31; p.county = 47; p.val = 910; p.d = 303; p.r = 607; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 31; p.county = 47; p.val = 563; p.d = 168; p.r = 395; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 30; p.county = 47; p.val = 622; p.d = 258; p.r = 364; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 29; p.county = 47; p.val = 493; p.d = 286; p.r = 207; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 29; p.county = 47; p.val = 794; p.d = 138; p.r = 656; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 32; p.county = 47; p.val = 882; p.d = 400; p.r = 482; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 34; p.county = 47; p.val = 173; p.d = 61; p.r = 112; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 38; p.county = 63; p.val = 1396; p.d = 770; p.r = 626; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 40; p.county = 63; p.val = 921; p.d = 189; p.r = 732; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 35; p.county = 63; p.val = 648; p.d = 181; p.r = 467; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 37; p.county = 63; p.val = 1057; p.d = 339; p.r = 718; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 34; p.county = 63; p.val = 1541; p.d = 214; p.r = 1327; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 37; p.county = 63; p.val = 2182; p.d = 519; p.r = 1663; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 40; p.county = 63; p.val = 1302; p.d = 205; p.r = 1097; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 34; p.county = 63; p.val = 858; p.d = 193; p.r = 665; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 35; p.county = 63; p.val = 1431; p.d = 202; p.r = 1229; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 38; p.county = 63; p.val = 1551; p.d = 608; p.r = 943; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 38; p.county = 63; p.val = 1056; p.d = 292; p.r = 764; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 36; p.county = 63; p.val = 1558; p.d = 258; p.r = 1300; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 39; p.county = 63; p.val = 1567; p.d = 650; p.r = 917; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 40; p.county = 63; p.val = 989; p.d = 310; p.r = 679; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 38; p.county = 63; p.val = 1971; p.d = 497; p.r = 1474; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 43; p.county = 63; p.val = 992; p.d = 211; p.r = 781; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 42; p.county = 63; p.val = 885; p.d = 123; p.r = 762; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 45; p.county = 63; p.val = 570; p.d = 116; p.r = 454; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 43; p.county = 63; p.val = 993; p.d = 378; p.r = 615; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 43; p.county = 63; p.val = 646; p.d = 200; p.r = 446; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 41; p.county = 63; p.val = 1063; p.d = 316; p.r = 747; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 42; p.county = 63; p.val = 1222; p.d = 326; p.r = 896; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 63; p.val = 2001; p.d = 526; p.r = 1475; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 36; p.county = 63; p.val = 1171; p.d = 312; p.r = 859; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 37; p.county = 63; p.val = 488; p.d = 155; p.r = 333; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 36; p.county = 63; p.val = 1639; p.d = 447; p.r = 1192; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 36; p.county = 63; p.val = 1115; p.d = 314; p.r = 801; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 39; p.county = 63; p.val = 1343; p.d = 457; p.r = 886; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 39; p.county = 63; p.val = 1182; p.d = 228; p.r = 954; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 38; p.county = 63; p.val = 817; p.d = 220; p.r = 597; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 33; p.county = 63; p.val = 1489; p.d = 359; p.r = 1130; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 35; p.county = 63; p.val = 862; p.d = 282; p.r = 580; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 34; p.county = 63; p.val = 1611; p.d = 296; p.r = 1315; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 41; p.county = 63; p.val = 847; p.d = 134; p.r = 713; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 35; p.county = 63; p.val = 1909; p.d = 421; p.r = 1488; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 40; p.county = 63; p.val = 1045; p.d = 150; p.r = 895; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 43; p.county = 63; p.val = 987; p.d = 187; p.r = 800; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 32; p.county = 63; p.val = 1951; p.d = 376; p.r = 1575; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 37; p.county = 63; p.val = 1766; p.d = 407; p.r = 1359; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 33; p.county = 63; p.val = 2137; p.d = 420; p.r = 1717; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 31; p.county = 63; p.val = 1184; p.d = 155; p.r = 1029; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 60; p.county = 35; p.val = 714; p.d = 354; p.r = 360; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 58; p.county = 35; p.val = 359; p.d = 237; p.r = 122; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 58; p.county = 35; p.val = 953; p.d = 443; p.r = 510; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 59; p.county = 35; p.val = 562; p.d = 297; p.r = 265; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 60; p.county = 35; p.val = 457; p.d = 189; p.r = 268; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 61; p.county = 35; p.val = 662; p.d = 299; p.r = 363; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 62; p.county = 35; p.val = 596; p.d = 273; p.r = 323; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 59; p.county = 35; p.val = 762; p.d = 336; p.r = 426; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 60; p.county = 35; p.val = 508; p.d = 209; p.r = 299; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 62; p.county = 35; p.val = 743; p.d = 293; p.r = 450; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 63; p.county = 35; p.val = 574; p.d = 271; p.r = 303; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 63; p.county = 35; p.val = 473; p.d = 256; p.r = 217; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 65; p.county = 35; p.val = 472; p.d = 121; p.r = 351; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 66; p.county = 35; p.val = 642; p.d = 227; p.r = 415; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 69; p.county = 35; p.val = 464; p.d = 379; p.r = 85; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 69; p.county = 35; p.val = 258; p.d = 69; p.r = 189; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 68; p.county = 35; p.val = 979; p.d = 273; p.r = 706; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 67; p.county = 35; p.val = 782; p.d = 197; p.r = 585; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 64; p.county = 35; p.val = 1408; p.d = 518; p.r = 890; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 66; p.county = 35; p.val = 721; p.d = 262; p.r = 459; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 66; p.county = 35; p.val = 361; p.d = 118; p.r = 243; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 65; p.county = 35; p.val = 811; p.d = 226; p.r = 585; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 68; p.county = 35; p.val = 855; p.d = 636; p.r = 219; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 38; p.county = 37; p.val = 356; p.d = 206; p.r = 150; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 39; p.county = 37; p.val = 405; p.d = 262; p.r = 143; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 40; p.county = 37; p.val = 921; p.d = 528; p.r = 393; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 41; p.county = 37; p.val = 965; p.d = 644; p.r = 321; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 42; p.county = 37; p.val = 625; p.d = 160; p.r = 465; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 41; p.county = 37; p.val = 620; p.d = 238; p.r = 382; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 43; p.county = 37; p.val = 683; p.d = 60; p.r = 623; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 43; p.county = 37; p.val = 1041; p.d = 547; p.r = 494; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 48; p.county = 37; p.val = 1755; p.d = 342; p.r = 1413; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 46; p.county = 37; p.val = 1172; p.d = 720; p.r = 452; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 44; p.county = 37; p.val = 774; p.d = 376; p.r = 398; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 46; p.county = 37; p.val = 2016; p.d = 408; p.r = 1608; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 56; p.county = 3; p.val = 0; p.d = 0; p.r = 0; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 14; p.county = 23; p.val = 642; p.d = 407; p.r = 235; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 13; p.county = 23; p.val = 420; p.d = 242; p.r = 178; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 15; p.county = 23; p.val = 666; p.d = 391; p.r = 275; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 13; p.county = 23; p.val = 875; p.d = 566; p.r = 309; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 14; p.county = 23; p.val = 580; p.d = 445; p.r = 135; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 11; p.county = 23; p.val = 726; p.d = 198; p.r = 528; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 12; p.county = 23; p.val = 797; p.d = 268; p.r = 529; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 11; p.county = 23; p.val = 859; p.d = 258; p.r = 601; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 14; p.county = 23; p.val = 1035; p.d = 415; p.r = 620; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 14; p.county = 23; p.val = 1138; p.d = 475; p.r = 663; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 17; p.county = 23; p.val = 814; p.d = 425; p.r = 389; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 18; p.county = 23; p.val = 348; p.d = 120; p.r = 228; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 17; p.county = 23; p.val = 547; p.d = 158; p.r = 389; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 17; p.county = 23; p.val = 447; p.d = 190; p.r = 257; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 17; p.county = 23; p.val = 205; p.d = 113; p.r = 92; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 15; p.county = 23; p.val = 421; p.d = 179; p.r = 242; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 18; p.county = 23; p.val = 791; p.d = 394; p.r = 397; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 12; p.county = 23; p.val = 753; p.d = 236; p.r = 517; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 19; p.county = 55; p.val = 720; p.d = 149; p.r = 571; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 23; p.county = 55; p.val = 934; p.d = 406; p.r = 528; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 25; p.county = 55; p.val = 969; p.d = 311; p.r = 658; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 28; p.county = 55; p.val = 596; p.d = 179; p.r = 417; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 28; p.county = 55; p.val = 940; p.d = 414; p.r = 526; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 27; p.county = 55; p.val = 613; p.d = 187; p.r = 426; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 29; p.county = 55; p.val = 855; p.d = 492; p.r = 363; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 27; p.county = 55; p.val = 360; p.d = 245; p.r = 115; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 28; p.county = 55; p.val = 1114; p.d = 405; p.r = 709; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 30; p.county = 55; p.val = 1002; p.d = 463; p.r = 539; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 31; p.county = 55; p.val = 1283; p.d = 457; p.r = 826; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 30; p.county = 55; p.val = 803; p.d = 383; p.r = 420; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 29; p.county = 55; p.val = 896; p.d = 198; p.r = 698; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 30; p.county = 55; p.val = 982; p.d = 337; p.r = 645; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 21; p.county = 55; p.val = 234; p.d = 34; p.r = 200; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 28; p.county = 55; p.val = 728; p.d = 270; p.r = 458; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 29; p.county = 55; p.val = 1108; p.d = 307; p.r = 801; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 21; p.county = 55; p.val = 376; p.d = 101; p.r = 275; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 24; p.county = 55; p.val = 537; p.d = 213; p.r = 324; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 23; p.county = 55; p.val = 1079; p.d = 322; p.r = 757; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 26; p.county = 55; p.val = 1258; p.d = 287; p.r = 971; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 26; p.county = 55; p.val = 916; p.d = 449; p.r = 467; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 26; p.county = 55; p.val = 978; p.d = 478; p.r = 500; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 6; p.county = 91; p.val = 1611; p.d = 501; p.r = 1110; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 11; p.county = 57; p.val = 611; p.d = 212; p.r = 399; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 13; p.county = 57; p.val = 497; p.d = 287; p.r = 210; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 12; p.county = 57; p.val = 880; p.d = 218; p.r = 662; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 13; p.county = 57; p.val = 823; p.d = 149; p.r = 674; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 13; p.county = 57; p.val = 618; p.d = 104; p.r = 514; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 13; p.county = 57; p.val = 1260; p.d = 199; p.r = 1061; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 14; p.county = 57; p.val = 589; p.d = 112; p.r = 477; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 14; p.county = 57; p.val = 620; p.d = 518; p.r = 102; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 15; p.county = 57; p.val = 1368; p.d = 513; p.r = 855; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 14; p.county = 57; p.val = 896; p.d = 457; p.r = 439; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 16; p.county = 57; p.val = 1078; p.d = 483; p.r = 595; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 19; p.county = 57; p.val = 397; p.d = 172; p.r = 225; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 16; p.county = 57; p.val = 857; p.d = 285; p.r = 572; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 15; p.county = 57; p.val = 796; p.d = 123; p.r = 673; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 16; p.county = 57; p.val = 521; p.d = 63; p.r = 458; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 18; p.county = 57; p.val = 1101; p.d = 447; p.r = 654; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 20; p.county = 57; p.val = 1045; p.d = 209; p.r = 836; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 7; p.county = 57; p.val = 1370; p.d = 440; p.r = 930; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 8; p.county = 57; p.val = 1902; p.d = 708; p.r = 1194; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 9; p.county = 57; p.val = 200; p.d = 71; p.r = 129; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 4; p.county = 91; p.val = 821; p.d = 267; p.r = 554; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 5; p.county = 91; p.val = 931; p.d = 340; p.r = 591; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 6; p.county = 57; p.val = 1893; p.d = 688; p.r = 1205; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 12; p.county = 73; p.val = 314; p.d = 90; p.r = 224; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 8; p.county = 73; p.val = 725; p.d = 160; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 7; p.county = 73; p.val = 1357; p.d = 203; p.r = 1154; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 15; p.county = 73; p.val = 472; p.d = 49; p.r = 423; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 13; p.county = 73; p.val = 1101; p.d = 179; p.r = 922; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 10; p.county = 73; p.val = 1309; p.d = 365; p.r = 944; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 12; p.county = 73; p.val = 1305; p.d = 245; p.r = 1060; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 12; p.county = 73; p.val = 1174; p.d = 244; p.r = 930; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 13; p.county = 73; p.val = 1044; p.d = 268; p.r = 776; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 14; p.county = 73; p.val = 1661; p.d = 782; p.r = 879; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 16; p.county = 73; p.val = 589; p.d = 78; p.r = 511; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 16; p.county = 73; p.val = 1374; p.d = 340; p.r = 1034; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 15; p.county = 73; p.val = 1643; p.d = 779; p.r = 864; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 14; p.county = 73; p.val = 1236; p.d = 441; p.r = 795; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 13; p.county = 73; p.val = 207; p.d = 67; p.r = 140; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 18; p.county = 73; p.val = 1072; p.d = 211; p.r = 861; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 20; p.county = 73; p.val = 720; p.d = 92; p.r = 628; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 18; p.county = 73; p.val = 676; p.d = 96; p.r = 580; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 17; p.county = 73; p.val = 991; p.d = 152; p.r = 839; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 17; p.county = 73; p.val = 916; p.d = 154; p.r = 762; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 16; p.county = 73; p.val = 1831; p.d = 302; p.r = 1529; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 12; p.county = 73; p.val = 1462; p.d = 319; p.r = 1143; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 11; p.county = 73; p.val = 1892; p.d = 413; p.r = 1479; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 15; p.county = 73; p.val = 858; p.d = 245; p.r = 613; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 11; p.county = 73; p.val = 1119; p.d = 207; p.r = 912; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 2; p.county = 91; p.val = 1389; p.d = 200; p.r = 1189; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 1; p.county = 91; p.val = 996; p.d = 188; p.r = 808; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 4; p.county = 91; p.val = 485; p.d = 63; p.r = 422; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 5; p.county = 91; p.val = 974; p.d = 570; p.r = 404; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 4; p.county = 91; p.val = 1049; p.d = 186; p.r = 863; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 6; p.county = 91; p.val = 748; p.d = 181; p.r = 567; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 9; p.county = 91; p.val = 317; p.d = 56; p.r = 261; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 7; p.county = 91; p.val = 940; p.d = 284; p.r = 656; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 9; p.county = 91; p.val = 1052; p.d = 298; p.r = 754; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 7; p.county = 91; p.val = 1168; p.d = 243; p.r = 925; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 6; p.county = 91; p.val = 1346; p.d = 295; p.r = 1051; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 5; p.county = 91; p.val = 817; p.d = 252; p.r = 565; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 1; p.county = 91; p.val = 1186; p.d = 361; p.r = 825; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 2; p.county = 91; p.val = 773; p.d = 236; p.r = 537; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 2; p.county = 91; p.val = 1518; p.d = 529; p.r = 989; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 4; p.county = 91; p.val = 1876; p.d = 506; p.r = 1370; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 7; p.county = 91; p.val = 1083; p.d = 645; p.r = 438; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 8; p.county = 91; p.val = 1227; p.d = 1125; p.r = 102; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 10; p.county = 91; p.val = 1413; p.d = 698; p.r = 715; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 10; p.county = 91; p.val = 1747; p.d = 849; p.r = 898; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 9; p.county = 91; p.val = 964; p.d = 169; p.r = 795; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 8; p.county = 91; p.val = 650; p.d = 179; p.r = 471; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 9; p.county = 91; p.val = 602; p.d = 125; p.r = 477; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 8; p.county = 91; p.val = 751; p.d = 443; p.r = 308; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 7; p.county = 91; p.val = 599; p.d = 204; p.r = 395; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 6; p.county = 91; p.val = 1192; p.d = 457; p.r = 735; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 3; p.county = 91; p.val = 1741; p.d = 689; p.r = 1052; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 3; p.county = 91; p.val = 1577; p.d = 588; p.r = 989; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 4; p.county = 91; p.val = 864; p.d = 361; p.r = 503; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 5; p.county = 91; p.val = 1091; p.d = 401; p.r = 690; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 7; p.county = 91; p.val = 710; p.d = 399; p.r = 311; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 6; p.county = 91; p.val = 583; p.d = 162; p.r = 421; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 2; p.county = 91; p.val = 780; p.d = 248; p.r = 532; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 3; p.county = 91; p.val = 1069; p.d = 255; p.r = 814; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 4; p.county = 91; p.val = 1487; p.d = 411; p.r = 1076; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 2; p.county = 91; p.val = 968; p.d = 426; p.r = 542; p.d16 = 0; p.r16 = 0;
points[i]=p;i++;}
return points;}












struct Map {
	std::map<int,std::map<int,Point> > pixels;
	int width;
	int height;
};

int sum(Map m){
	int i; int ii; int sum = 0;
	int sumX = 0;
	int sumY = 0;
	for (i=0;i<m.width;i++){
		for (ii=0;ii<m.height;ii++){
			sum += m.pixels[i][ii].val;
			sumX += m.pixels[i][ii].x;
			sumY += m.pixels[i][ii].y;
		}
	}
	console_log(sumX);
	console_log(sumY);
	return sum;
}


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
			if (removeSeam[i]+1<m.height && removeSeam[i]>0){
				for(ii=m.height;ii>removeSeam[i]+2;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val+m.pixels[i][removeSeam[i]-1].val+m.pixels[i][removeSeam[i]+1].val;
				int r = m.pixels[i][removeSeam[i]].r+m.pixels[i][removeSeam[i]-1].r+m.pixels[i][removeSeam[i]+1].r;
				int d = m.pixels[i][removeSeam[i]].d+m.pixels[i][removeSeam[i]-1].d+m.pixels[i][removeSeam[i]+1].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				else {
					xx = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].x;
					xx += m.pixels[i][removeSeam[i]-1].val*m.pixels[i][removeSeam[i]-1].x;
					xx += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].y;
					yy += m.pixels[i][removeSeam[i]-1].val*m.pixels[i][removeSeam[i]-1].y;
					yy += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[i][removeSeam[i]-1].val = v/4;
				m.pixels[i][removeSeam[i]].val = v - v/4 - v/4 - v/4;
				m.pixels[i][removeSeam[i]+1].val = v/4;
				m.pixels[i][removeSeam[i]+2].val = v/4;
				
				m.pixels[i][removeSeam[i]-1].r = r/4;
				m.pixels[i][removeSeam[i]].r = r - r/4 - r/4 - r/4;
				m.pixels[i][removeSeam[i]+1].r = r/4;
				m.pixels[i][removeSeam[i]+2].r = r/4;
				
				m.pixels[i][removeSeam[i]-1].d = d/4;
				m.pixels[i][removeSeam[i]].d = d - d/4 - d/4 - d/4;
				m.pixels[i][removeSeam[i]+1].d = d/4;
				m.pixels[i][removeSeam[i]+2].d = d/4;
				
				m.pixels[i][removeSeam[i]-1].x = xx;
				m.pixels[i][removeSeam[i]].x = xx;
				m.pixels[i][removeSeam[i]+1].x = xx;
				m.pixels[i][removeSeam[i]+2].x = xx;
				
				m.pixels[i][removeSeam[i]-1].y = yy;
				m.pixels[i][removeSeam[i]].y = yy;
				m.pixels[i][removeSeam[i]+1].y = yy;
				m.pixels[i][removeSeam[i]+2].y = yy;
			}
			else if (removeSeam[i]+1<m.height){
				for(ii=m.height;ii>removeSeam[i]+2;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val+m.pixels[i][removeSeam[i]+1].val;
				int r = m.pixels[i][removeSeam[i]].r+m.pixels[i][removeSeam[i]+1].r;
				int d = m.pixels[i][removeSeam[i]].d+m.pixels[i][removeSeam[i]+1].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				else {
					xx = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].x;
					xx += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].y;
					yy += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].y;
					yy += v/2;
					yy = yy/v;
				}
				
				m.pixels[i][removeSeam[i]].val = v - v/3 - v/3;
				m.pixels[i][removeSeam[i]+1].val = v/3;
				m.pixels[i][removeSeam[i]+2].val = v/3;
				
				m.pixels[i][removeSeam[i]].r = r - r/3 - r/3;
				m.pixels[i][removeSeam[i]+1].r = r/3;
				m.pixels[i][removeSeam[i]+2].r = r/3;
				
				m.pixels[i][removeSeam[i]].d = d - d/3 - d/3;
				m.pixels[i][removeSeam[i]+1].d = d/3;
				m.pixels[i][removeSeam[i]+2].d = d/3;
				
				m.pixels[i][removeSeam[i]].x = xx;
				m.pixels[i][removeSeam[i]+1].x = xx;
				m.pixels[i][removeSeam[i]+2].x = xx;
				
				m.pixels[i][removeSeam[i]].y = yy;
				m.pixels[i][removeSeam[i]+1].y = yy;
				m.pixels[i][removeSeam[i]+2].y = yy;
			}
			else {
				for(ii=m.height;ii>removeSeam[i]+1;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val;
				int r = m.pixels[i][removeSeam[i]].r;
				int d = m.pixels[i][removeSeam[i]].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				else {
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				m.pixels[i][removeSeam[i]].val = v/2;
				m.pixels[i][removeSeam[i]+1].val = v - v/2;
				
				m.pixels[i][removeSeam[i]].r = r/2;
				m.pixels[i][removeSeam[i]+1].r = r - r/2;
				
				m.pixels[i][removeSeam[i]].d = d/2;
				m.pixels[i][removeSeam[i]+1].d = d - d/2;
				
				m.pixels[i][removeSeam[i]].x = xx;
				m.pixels[i][removeSeam[i]+1].x = xx;
				
				m.pixels[i][removeSeam[i]].y = yy;
				m.pixels[i][removeSeam[i]+1].y = yy;
			}
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
			if (removeSeam[ii]+1<m.width && removeSeam[ii]>0){
				for(i=m.width;i>removeSeam[ii]+2;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]-1][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
				int r = m.pixels[removeSeam[ii]][ii].r+m.pixels[removeSeam[ii]-1][ii].r+m.pixels[removeSeam[ii]+1][ii].r;
				int d = m.pixels[removeSeam[ii]][ii].d+m.pixels[removeSeam[ii]-1][ii].d+m.pixels[removeSeam[ii]+1][ii].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				else{
					xx = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].x;
					xx += m.pixels[removeSeam[ii]-1][ii].val*m.pixels[removeSeam[ii]-1][ii].x;
					xx += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].y;
					yy += m.pixels[removeSeam[ii]-1][ii].val*m.pixels[removeSeam[ii]-1][ii].y;
					yy += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[removeSeam[ii]-1][ii].val=v/4;
				m.pixels[removeSeam[ii]][ii].val=v - v/4 - v/4 - v/4;
				m.pixels[removeSeam[ii]+1][ii].val=v/4;
				m.pixels[removeSeam[ii]+2][ii].val= v/4;
				
				m.pixels[removeSeam[ii]-1][ii].r=r/4;
				m.pixels[removeSeam[ii]][ii].r=r - r/4 - r/4 - r/4;
				m.pixels[removeSeam[ii]+1][ii].r=r/4;
				m.pixels[removeSeam[ii]+2][ii].r= r/4;
				
				m.pixels[removeSeam[ii]-1][ii].d=d/4;
				m.pixels[removeSeam[ii]][ii].d=d - d/4 - d/4 - d/4;
				m.pixels[removeSeam[ii]+1][ii].d=d/4;
				m.pixels[removeSeam[ii]+2][ii].d= d/4;
				
				m.pixels[removeSeam[ii]-1][ii].x=xx;
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]+1][ii].x=xx;
				m.pixels[removeSeam[ii]+2][ii].x= xx;
				
				m.pixels[removeSeam[ii]-1][ii].y=yy;
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]+1][ii].y=yy;
				m.pixels[removeSeam[ii]+2][ii].y= yy;
			}
			else if (removeSeam[ii]+1<m.width){
				for(i=m.width;i>removeSeam[ii]+2;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
				int r = m.pixels[removeSeam[ii]][ii].r+m.pixels[removeSeam[ii]+1][ii].r;
				int d = m.pixels[removeSeam[ii]][ii].d+m.pixels[removeSeam[ii]+1][ii].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				else{
					xx = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].x;
					xx += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].y;
					yy += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[removeSeam[ii]][ii].val=v - v/3 - v/3;
				m.pixels[removeSeam[ii]+1][ii].val=v/3;
				m.pixels[removeSeam[ii]+2][ii].val= v/3;
				
				m.pixels[removeSeam[ii]][ii].r=r - r/3 - r/3;
				m.pixels[removeSeam[ii]+1][ii].r=r/3;
				m.pixels[removeSeam[ii]+2][ii].r= r/3;
				
				m.pixels[removeSeam[ii]][ii].d=d - d/3 - d/3;
				m.pixels[removeSeam[ii]+1][ii].d=d/3;
				m.pixels[removeSeam[ii]+2][ii].d= d/3;
				
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]+1][ii].x=xx;
				m.pixels[removeSeam[ii]+2][ii].x= xx;
				
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]+1][ii].y=yy;
				m.pixels[removeSeam[ii]+2][ii].y= yy;
			}
			else {
				for(i=m.width;i>removeSeam[ii]+1;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val;
				int r = m.pixels[removeSeam[ii]][ii].r;
				int d = m.pixels[removeSeam[ii]][ii].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				else{
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				m.pixels[removeSeam[ii]][ii].val=v/2;
				m.pixels[removeSeam[ii]+1][ii].val= v - v/2;
				
				m.pixels[removeSeam[ii]][ii].r=r/2;
				m.pixels[removeSeam[ii]+1][ii].r= r - r/2;
				
				m.pixels[removeSeam[ii]][ii].d=d/2;
				m.pixels[removeSeam[ii]+1][ii].d= d - d/2;
				
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]+1][ii].x= xx;
				
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]+1][ii].y= yy;
			}
			
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
			if (removeSeam[i]+1 < m.height && removeSeam[i] > 0){
				int v = m.pixels[i][removeSeam[i]].val+m.pixels[i][removeSeam[i]-1].val+m.pixels[i][removeSeam[i]+1].val;
				
				int r = m.pixels[i][removeSeam[i]].r+m.pixels[i][removeSeam[i]-1].r+m.pixels[i][removeSeam[i]+1].r;
				m.pixels[i][removeSeam[i]].r=r - r/2;
				m.pixels[i][removeSeam[i]-1].r= r/2;
				int d = m.pixels[i][removeSeam[i]].d+m.pixels[i][removeSeam[i]-1].d+m.pixels[i][removeSeam[i]+1].d;
				m.pixels[i][removeSeam[i]].d=d - d/2;
				m.pixels[i][removeSeam[i]-1].d= d/2;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				else{
					xx = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].x;
					xx += m.pixels[i][removeSeam[i]-1].val*m.pixels[i][removeSeam[i]-1].x;
					xx += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].y;
					yy += m.pixels[i][removeSeam[i]-1].val*m.pixels[i][removeSeam[i]-1].y;
					yy += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[i][removeSeam[i]].val=v - v/2;
				m.pixels[i][removeSeam[i]-1].val= v/2;
				m.pixels[i][removeSeam[i]].x=xx;
				m.pixels[i][removeSeam[i]-1].x= xx;
				m.pixels[i][removeSeam[i]].y=yy;
				m.pixels[i][removeSeam[i]-1].y= yy;
				for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
					m.pixels[i][ii]=m.pixels[i][ii+1];
				}
			}
			else if (removeSeam[i]+1 < m.height){
				int v = m.pixels[i][removeSeam[i]].val +m.pixels[i][removeSeam[i]+1].val;
				
				m.pixels[i][removeSeam[i]].r +=m.pixels[i][removeSeam[i]+1].r;
				m.pixels[i][removeSeam[i]].d +=m.pixels[i][removeSeam[i]+1].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				else {
					xx = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].x;
					xx += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].y;
					yy += m.pixels[i][removeSeam[i]+1].val*m.pixels[i][removeSeam[i]+1].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[i][removeSeam[i]].val = v;
				m.pixels[i][removeSeam[i]].x=xx;
				m.pixels[i][removeSeam[i]].y=yy;
				for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
					m.pixels[i][ii]=m.pixels[i][ii+1];
				}
			}
			else {
				int v = m.pixels[i][removeSeam[i]].val +m.pixels[i][removeSeam[i]-1].val;
				
				m.pixels[i][removeSeam[i]-1].r +=m.pixels[i][removeSeam[i]].r;
				m.pixels[i][removeSeam[i]-1].d +=m.pixels[i][removeSeam[i]].d;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[i][removeSeam[i]].x;
					yy = m.pixels[i][removeSeam[i]].y;
				}
				else {
					xx = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].x;
					xx += m.pixels[i][removeSeam[i]-1].val*m.pixels[i][removeSeam[i]-1].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[i][removeSeam[i]].val*m.pixels[i][removeSeam[i]].y;
					yy += m.pixels[i][removeSeam[i]-1].val*m.pixels[i][removeSeam[i]-1].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[i][removeSeam[i]-1].val = v;
				m.pixels[i][removeSeam[i]-1].x =xx;
				m.pixels[i][removeSeam[i]-1].y =yy;
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
		for(ii=0;ii<h;ii++){
			if (removeSeam[ii]+1 < m.width && removeSeam[ii] > 0){
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]-1][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
				
				int r = m.pixels[removeSeam[ii]][ii].r+m.pixels[removeSeam[ii]-1][ii].r+m.pixels[removeSeam[ii]+1][ii].r;
				m.pixels[removeSeam[ii]][ii].r=r - r/2;
				m.pixels[removeSeam[ii]-1][ii].r= r/2;
				int d = m.pixels[removeSeam[ii]][ii].d+m.pixels[removeSeam[ii]-1][ii].d+m.pixels[removeSeam[ii]+1][ii].d;
				m.pixels[removeSeam[ii]][ii].d=d - d/2;
				m.pixels[removeSeam[ii]-1][ii].d= d/2;
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				else{
					xx = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].x;
					xx += m.pixels[removeSeam[ii]-1][ii].val*m.pixels[removeSeam[ii]-1][ii].x;
					xx += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].y;
					yy += m.pixels[removeSeam[ii]-1][ii].val*m.pixels[removeSeam[ii]-1][ii].y;
					yy += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[removeSeam[ii]][ii].val=v - v/2;
				m.pixels[removeSeam[ii]-1][ii].val= v/2;
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]-1][ii].x= xx;
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]-1][ii].y= yy;
				for(i=removeSeam[ii]+1;i<m.width-1;i++){
			
					m.pixels[i][ii]=m.pixels[i+1][ii];
				}
			}
			else if (removeSeam[ii]+1 < m.width){
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
				
				m.pixels[removeSeam[ii]][ii].r+=m.pixels[removeSeam[ii]+1][ii].r;
				m.pixels[removeSeam[ii]][ii].d+=m.pixels[removeSeam[ii]+1][ii].d;
				
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				else{
					xx = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].x;
					xx += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].y;
					yy += m.pixels[removeSeam[ii]+1][ii].val*m.pixels[removeSeam[ii]+1][ii].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[removeSeam[ii]][ii].val+=m.pixels[removeSeam[ii]+1][ii].val;
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]][ii].y=yy;
				for(i=removeSeam[ii]+1;i<m.width-1;i++){
			
					m.pixels[i][ii]=m.pixels[i+1][ii];
				}
			}
			else {
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]-1][ii].val;
				
				m.pixels[removeSeam[ii]-1][ii].r+=m.pixels[removeSeam[ii]][ii].r;
				m.pixels[removeSeam[ii]-1][ii].d+=m.pixels[removeSeam[ii]][ii].d;
				
				int xx; int yy;
				if (v <= 0){
					xx = m.pixels[removeSeam[ii]][ii].x;
					yy = m.pixels[removeSeam[ii]][ii].y;
				}
				else{
					xx = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].x;
					xx += m.pixels[removeSeam[ii]-1][ii].val*m.pixels[removeSeam[ii]-1][ii].x;
					xx += v/2;
					xx = xx/v;
					yy = m.pixels[removeSeam[ii]][ii].val*m.pixels[removeSeam[ii]][ii].y;
					yy += m.pixels[removeSeam[ii]-1][ii].val*m.pixels[removeSeam[ii]-1][ii].y;
					yy += v/2;
					yy = yy/v;
				}
				m.pixels[removeSeam[ii]-1][ii].val+=m.pixels[removeSeam[ii]][ii].val;
				m.pixels[removeSeam[ii]-1][ii].x=xx;
				m.pixels[removeSeam[ii]-1][ii].y=yy;
			}
		}
		m.width--;
	}

	
	return m;
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
			p.r = 0;
			p.d = 0;
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
	int np = 1241;
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
				pixels[i][ii].d += points[pixelMap[i][ii]].d*100/points[pixelMap[i][ii]].npix;
				pixels[i][ii].r += points[pixelMap[i][ii]].r*100/points[pixelMap[i][ii]].npix;
				pixels[i][ii].x = points[pixelMap[i][ii]].x;
				pixels[i][ii].y = points[pixelMap[i][ii]].y;
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
				pixels[i][ii].d += points[minI].d*100/points[minI].npix;
				pixels[i][ii].r += points[minI].r*100/points[minI].npix;
				pixels[i][ii].x = points[minI].x;
				pixels[i][ii].y = points[minI].y;
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
			pixels[i][ii].d += points[minI].d*100/points[minI].npix;
			pixels[i][ii].r += points[minI].r*100/points[minI].npix;
			pixels[i][ii].x = points[minI].x;
			pixels[i][ii].y = points[minI].y;
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
	for (iii=0;iii<61;iii++){
		vertThreads = 1 + (rand() % (30-iii/4));
		horzThreads = 1 + (rand() % (30-iii/4));
		if (iii%5 == 0){
			for(i=0;i<m.width;i++){
				for(ii=0;ii<m.height;ii++){
					Point p = m.pixels[i][ii];
					std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county)+","+std::to_string(p.d)+","+std::to_string(p.r);
					add_pointOut(pointStr.c_str());
				}
			}
			display_points();
		}
		m = verticalSeam(m,vertThreads,1);
		m = horizontalSeam(m,horzThreads,1);
		m = verticalStitch(m,vertThreads,1);
		m = horizontalStitch(m,horzThreads,1);
	}
	
	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();

	
	for(i=0;i<m.width;i++){
		for(ii=0;ii<m.height;ii++){
			Point p = m.pixels[i][ii];
			std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county)+","+std::to_string(p.d)+","+std::to_string(p.r);
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
