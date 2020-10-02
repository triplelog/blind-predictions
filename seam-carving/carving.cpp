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
		var myObj = {"x":pointSplit[3],"y":pointSplit[4],"ox":pointSplit[0],"oy":pointSplit[1],"county":pointSplit[5],"val":pointSplit[2]};
		myObj["d"] = pointSplit[6];
		myObj["r"] = pointSplit[7];
		myObj["d16"] = pointSplit[8];
		myObj["r16"] = pointSplit[9];
		myObj["white"] = pointSplit[10];
		myObj["black"] = pointSplit[11];
		pointsOut.push(myObj);	
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
int np;
int nd;
std::vector<std::string> datas;
bool computeVal;
extern "C" {


}

struct Point {
	int x;
	int y;
	int val;
	int county;
	int npix;
	std::map<std::string,int> data;
	void computeVal() {
		val = data["d16"]*9/8-data["r16"];
		if (val < 0){ val *= -1;}
	}
};

std::map<int,Point> points;


void scPoints0(){
points.clear();
if (1==1){ Point p;
p.x = 140; p.y = 153; p.county = 0; p.val = 1795; p.data["black"] = 375; p.data["white"] = 1410; p.data["r"] = 357; p.data["d"] = 337; p.data["d16"] = 356; p.data["r16"] = 353;
points[0]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 153; p.county = 0; p.val = 1910; p.data["black"] = 800; p.data["white"] = 995; p.data["r"] = 929; p.data["d"] = 586; p.data["d16"] = 1570; p.data["r16"] = 942;
points[1]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 18; p.county = 0; p.val = 1025; p.data["black"] = 10; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 72; p.county = 0; p.val = 2405; p.data["black"] = 2330; p.data["white"] = 55; p.data["r"] = 1398; p.data["d"] = 28; p.data["d16"] = 2279; p.data["r16"] = 97;
points[3]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 73; p.county = 0; p.val = 3175; p.data["black"] = 2545; p.data["white"] = 460; p.data["r"] = 1356; p.data["d"] = 49; p.data["d16"] = 1600; p.data["r16"] = 40;
points[4]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 73; p.county = 0; p.val = 4770; p.data["black"] = 3900; p.data["white"] = 775; p.data["r"] = 777; p.data["d"] = 277; p.data["d16"] = 1117; p.data["r16"] = 639;
points[5]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 70; p.county = 0; p.val = 3535; p.data["black"] = 2540; p.data["white"] = 810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[6]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 108; p.county = 0; p.val = 555; p.data["black"] = 245; p.data["white"] = 275; p.data["r"] = 695; p.data["d"] = 395; p.data["d16"] = 1453; p.data["r16"] = 666;
points[7]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 71; p.county = 0; p.val = 1240; p.data["black"] = 940; p.data["white"] = 184; p.data["r"] = 793; p.data["d"] = 91; p.data["d16"] = 865; p.data["r16"] = 116;
points[8]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 72; p.county = 0; p.val = 5080; p.data["black"] = 2960; p.data["white"] = 1235; p.data["r"] = 1089; p.data["d"] = 160; p.data["d16"] = 0; p.data["r16"] = 0;
points[9]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 72; p.county = 0; p.val = 835; p.data["black"] = 485; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[10]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 69; p.county = 0; p.val = 3495; p.data["black"] = 2095; p.data["white"] = 1160; p.data["r"] = 2242; p.data["d"] = 810; p.data["d16"] = 933; p.data["r16"] = 652;
points[11]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 70; p.county = 0; p.val = 980; p.data["black"] = 445; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[12]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 71; p.county = 0; p.val = 1065; p.data["black"] = 510; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1131; p.data["r16"] = 467;
points[13]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 77; p.county = 0; p.val = 4240; p.data["black"] = 3365; p.data["white"] = 460; p.data["r"] = 729; p.data["d"] = 63; p.data["d16"] = 0; p.data["r16"] = 0;
points[14]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 62; p.county = 0; p.val = 670; p.data["black"] = 105; p.data["white"] = 545; p.data["r"] = 388; p.data["d"] = 334; p.data["d16"] = 506; p.data["r16"] = 484;
points[15]=p;}
if (1==1){ Point p;
p.x = 172; p.y = 62; p.county = 0; p.val = 520; p.data["black"] = 405; p.data["white"] = 110; p.data["r"] = 555; p.data["d"] = 332; p.data["d16"] = 0; p.data["r16"] = 0;
points[16]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 65; p.county = 0; p.val = 1615; p.data["black"] = 1435; p.data["white"] = 180; p.data["r"] = 214; p.data["d"] = 493; p.data["d16"] = 280; p.data["r16"] = 642;
points[17]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 78; p.county = 0; p.val = 1705; p.data["black"] = 945; p.data["white"] = 660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[18]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 94; p.county = 0; p.val = 1095; p.data["black"] = 275; p.data["white"] = 790; p.data["r"] = 24; p.data["d"] = 210; p.data["d16"] = 25; p.data["r16"] = 253;
points[19]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 45; p.county = 0; p.val = 950; p.data["black"] = 690; p.data["white"] = 255; p.data["r"] = 320; p.data["d"] = 64; p.data["d16"] = 672; p.data["r16"] = 476;
points[20]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 43; p.county = 0; p.val = 1245; p.data["black"] = 360; p.data["white"] = 875; p.data["r"] = 291; p.data["d"] = 501; p.data["d16"] = 327; p.data["r16"] = 556;
points[21]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 44; p.county = 0; p.val = 1540; p.data["black"] = 715; p.data["white"] = 770; p.data["r"] = 227; p.data["d"] = 93; p.data["d16"] = 0; p.data["r16"] = 0;
points[22]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 124; p.county = 0; p.val = 1190; p.data["black"] = 385; p.data["white"] = 775; p.data["r"] = 279; p.data["d"] = 286; p.data["d16"] = 286; p.data["r16"] = 360;
points[23]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 142; p.county = 0; p.val = 6205; p.data["black"] = 2085; p.data["white"] = 3365; p.data["r"] = 629; p.data["d"] = 395; p.data["d16"] = 958; p.data["r16"] = 858;
points[24]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 111; p.county = 0; p.val = 905; p.data["black"] = 905; p.data["white"] = 0; p.data["r"] = 471; p.data["d"] = 35; p.data["d16"] = 584; p.data["r16"] = 52;
points[25]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 140; p.county = 0; p.val = 4415; p.data["black"] = 1345; p.data["white"] = 2530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[26]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 138; p.county = 0; p.val = 6980; p.data["black"] = 2325; p.data["white"] = 3890; p.data["r"] = 1705; p.data["d"] = 1234; p.data["d16"] = 1040; p.data["r16"] = 973;
points[27]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 131; p.county = 0; p.val = 3925; p.data["black"] = 570; p.data["white"] = 3025; p.data["r"] = 319; p.data["d"] = 314; p.data["d16"] = 255; p.data["r16"] = 210;
points[28]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 129; p.county = 0; p.val = 2915; p.data["black"] = 1135; p.data["white"] = 1565; p.data["r"] = 939; p.data["d"] = 687; p.data["d16"] = 994; p.data["r16"] = 1039;
points[29]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 27; p.county = 0; p.val = 985; p.data["black"] = 70; p.data["white"] = 900; p.data["r"] = 188; p.data["d"] = 404; p.data["d16"] = 198; p.data["r16"] = 500;
points[30]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 25; p.county = 0; p.val = 1900; p.data["black"] = 25; p.data["white"] = 1815; p.data["r"] = 126; p.data["d"] = 701; p.data["d16"] = 228; p.data["r16"] = 606;
points[31]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 25; p.county = 0; p.val = 1475; p.data["black"] = 305; p.data["white"] = 1170; p.data["r"] = 114; p.data["d"] = 475; p.data["d16"] = 80; p.data["r16"] = 592;
points[32]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 28; p.county = 0; p.val = 1250; p.data["black"] = 65; p.data["white"] = 1175; p.data["r"] = 127; p.data["d"] = 581; p.data["d16"] = 0; p.data["r16"] = 0;
points[33]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 24; p.county = 0; p.val = 1610; p.data["black"] = 4; p.data["white"] = 1570; p.data["r"] = 308; p.data["d"] = 1173; p.data["d16"] = 123; p.data["r16"] = 676;
points[34]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 16; p.county = 0; p.val = 1310; p.data["black"] = 0; p.data["white"] = 1255; p.data["r"] = 175; p.data["d"] = 817; p.data["d16"] = 226; p.data["r16"] = 1446;
points[35]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 26; p.county = 0; p.val = 1225; p.data["black"] = 60; p.data["white"] = 1160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 477; p.data["r16"] = 2210;
points[36]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 34; p.county = 0; p.val = 3270; p.data["black"] = 375; p.data["white"] = 2665; p.data["r"] = 421; p.data["d"] = 304; p.data["d16"] = 0; p.data["r16"] = 0;
points[37]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 26; p.county = 0; p.val = 760; p.data["black"] = 15; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 245; p.data["r16"] = 1351;
points[38]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 27; p.county = 0; p.val = 1015; p.data["black"] = 35; p.data["white"] = 965; p.data["r"] = 85; p.data["d"] = 432; p.data["d16"] = 0; p.data["r16"] = 0;
points[39]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 25; p.county = 0; p.val = 2605; p.data["black"] = 185; p.data["white"] = 2275; p.data["r"] = 118; p.data["d"] = 477; p.data["d16"] = 108; p.data["r16"] = 568;
points[40]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 30; p.county = 0; p.val = 815; p.data["black"] = 80; p.data["white"] = 715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 323; p.data["r16"] = 989;
points[41]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 10; p.county = 0; p.val = 1560; p.data["black"] = 20; p.data["white"] = 1485; p.data["r"] = 215; p.data["d"] = 693; p.data["d16"] = 181; p.data["r16"] = 869;
points[42]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 20; p.county = 0; p.val = 825; p.data["black"] = 75; p.data["white"] = 750; p.data["r"] = 146; p.data["d"] = 543; p.data["d16"] = 142; p.data["r16"] = 777;
points[43]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 19; p.county = 0; p.val = 900; p.data["black"] = 50; p.data["white"] = 825; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[44]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 26; p.county = 0; p.val = 1680; p.data["black"] = 85; p.data["white"] = 1545; p.data["r"] = 124; p.data["d"] = 582; p.data["d16"] = 99; p.data["r16"] = 739;
points[45]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 22; p.county = 0; p.val = 1600; p.data["black"] = 15; p.data["white"] = 1535; p.data["r"] = 124; p.data["d"] = 536; p.data["d16"] = 108; p.data["r16"] = 709;
points[46]=p;}
if (1==1){ Point p;
p.x = 164; p.y = 95; p.county = 0; p.val = 890; p.data["black"] = 310; p.data["white"] = 580; p.data["r"] = 162; p.data["d"] = 154; p.data["d16"] = 211; p.data["r16"] = 210;
points[47]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 95; p.county = 0; p.val = 270; p.data["black"] = 205; p.data["white"] = 65; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[48]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 98; p.county = 0; p.val = 445; p.data["black"] = 225; p.data["white"] = 220; p.data["r"] = 421; p.data["d"] = 220; p.data["d16"] = 561; p.data["r16"] = 311;
points[49]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 71; p.county = 0; p.val = 495; p.data["black"] = 475; p.data["white"] = 20; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[50]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 95; p.county = 0; p.val = 1125; p.data["black"] = 1000; p.data["white"] = 100; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[51]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 23; p.county = 0; p.val = 1615; p.data["black"] = 115; p.data["white"] = 1485; p.data["r"] = 525; p.data["d"] = 1489; p.data["d16"] = 350; p.data["r16"] = 1197;
points[52]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 23; p.county = 0; p.val = 1270; p.data["black"] = 180; p.data["white"] = 1050; p.data["r"] = 162; p.data["d"] = 445; p.data["d16"] = 716; p.data["r16"] = 640;
points[53]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 103; p.county = 0; p.val = 3180; p.data["black"] = 2170; p.data["white"] = 965; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[54]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 104; p.county = 0; p.val = 435; p.data["black"] = 0; p.data["white"] = 425; p.data["r"] = 194; p.data["d"] = 389; p.data["d16"] = 0; p.data["r16"] = 0;
points[55]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 107; p.county = 0; p.val = 1535; p.data["black"] = 215; p.data["white"] = 1295; p.data["r"] = 561; p.data["d"] = 649; p.data["d16"] = 250; p.data["r16"] = 363;
points[56]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 108; p.county = 0; p.val = 590; p.data["black"] = 15; p.data["white"] = 555; p.data["r"] = 290; p.data["d"] = 614; p.data["d16"] = 0; p.data["r16"] = 0;
points[57]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 12; p.county = 0; p.val = 2875; p.data["black"] = 195; p.data["white"] = 2375; p.data["r"] = 536; p.data["d"] = 1084; p.data["d16"] = 501; p.data["r16"] = 1110;
points[58]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 9; p.county = 0; p.val = 1820; p.data["black"] = 245; p.data["white"] = 1445; p.data["r"] = 325; p.data["d"] = 876; p.data["d16"] = 917; p.data["r16"] = 2446;
points[59]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 142; p.county = 0; p.val = 955; p.data["black"] = 55; p.data["white"] = 815; p.data["r"] = 1205; p.data["d"] = 1141; p.data["d16"] = 1177; p.data["r16"] = 1535;
points[60]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 4; p.county = 0; p.val = 2075; p.data["black"] = 200; p.data["white"] = 1840; p.data["r"] = 1016; p.data["d"] = 2116; p.data["d16"] = 345; p.data["r16"] = 687;
points[61]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 10; p.county = 0; p.val = 3130; p.data["black"] = 245; p.data["white"] = 2715; p.data["r"] = 304; p.data["d"] = 641; p.data["d16"] = 665; p.data["r16"] = 1430;
points[62]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 10; p.county = 0; p.val = 3840; p.data["black"] = 0; p.data["white"] = 3335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 401; p.data["r16"] = 690;
points[63]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 14; p.county = 0; p.val = 1585; p.data["black"] = 80; p.data["white"] = 1395; p.data["r"] = 629; p.data["d"] = 965; p.data["d16"] = 1106; p.data["r16"] = 2046;
points[64]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 14; p.county = 0; p.val = 1970; p.data["black"] = 95; p.data["white"] = 1775; p.data["r"] = 1023; p.data["d"] = 1535; p.data["d16"] = 654; p.data["r16"] = 1490;
points[65]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 9; p.county = 0; p.val = 3290; p.data["black"] = 340; p.data["white"] = 2670; p.data["r"] = 1170; p.data["d"] = 1912; p.data["d16"] = 878; p.data["r16"] = 1367;
points[66]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 75; p.county = 0; p.val = 460; p.data["black"] = 0; p.data["white"] = 460; p.data["r"] = 39; p.data["d"] = 297; p.data["d16"] = 39; p.data["r16"] = 377;
points[67]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 83; p.county = 0; p.val = 500; p.data["black"] = 95; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[68]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 74; p.county = 0; p.val = 590; p.data["black"] = 90; p.data["white"] = 465; p.data["r"] = 83; p.data["d"] = 187; p.data["d16"] = 78; p.data["r16"] = 227;
points[69]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 74; p.county = 0; p.val = 1270; p.data["black"] = 35; p.data["white"] = 1225; p.data["r"] = 107; p.data["d"] = 358; p.data["d16"] = 108; p.data["r16"] = 689;
points[70]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 68; p.county = 0; p.val = 865; p.data["black"] = 260; p.data["white"] = 530; p.data["r"] = 238; p.data["d"] = 408; p.data["d16"] = 212; p.data["r16"] = 217;
points[71]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 126; p.county = 0; p.val = 1660; p.data["black"] = 670; p.data["white"] = 950; p.data["r"] = 278; p.data["d"] = 331; p.data["d16"] = 904; p.data["r16"] = 758;
points[72]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 125; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[73]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 143; p.county = 0; p.val = 4180; p.data["black"] = 500; p.data["white"] = 3265; p.data["r"] = 388; p.data["d"] = 325; p.data["d16"] = 1522; p.data["r16"] = 1356;
points[74]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 135; p.county = 0; p.val = 2220; p.data["black"] = 330; p.data["white"] = 1550; p.data["r"] = 28; p.data["d"] = 52; p.data["d16"] = 0; p.data["r16"] = 0;
points[75]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 134; p.county = 0; p.val = 1370; p.data["black"] = 55; p.data["white"] = 1095; p.data["r"] = 312; p.data["d"] = 439; p.data["d16"] = 207; p.data["r16"] = 631;
points[76]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 129; p.county = 0; p.val = 1300; p.data["black"] = 480; p.data["white"] = 770; p.data["r"] = 461; p.data["d"] = 292; p.data["d16"] = 499; p.data["r16"] = 426;
points[77]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 137; p.county = 0; p.val = 2285; p.data["black"] = 205; p.data["white"] = 1800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[78]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 114; p.county = 0; p.val = 1000; p.data["black"] = 555; p.data["white"] = 430; p.data["r"] = 551; p.data["d"] = 96; p.data["d16"] = 736; p.data["r16"] = 129;
points[79]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 144; p.county = 0; p.val = 1060; p.data["black"] = 175; p.data["white"] = 870; p.data["r"] = 2358; p.data["d"] = 2452; p.data["d16"] = 2298; p.data["r16"] = 3253;
points[80]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 43; p.county = 0; p.val = 465; p.data["black"] = 80; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 463; p.data["r16"] = 495;
points[81]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 52; p.county = 0; p.val = 740; p.data["black"] = 125; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[82]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 20; p.county = 0; p.val = 2395; p.data["black"] = 290; p.data["white"] = 1795; p.data["r"] = 248; p.data["d"] = 455; p.data["d16"] = 689; p.data["r16"] = 1450;
points[83]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 16; p.county = 0; p.val = 2230; p.data["black"] = 105; p.data["white"] = 2075; p.data["r"] = 390; p.data["d"] = 842; p.data["d16"] = 805; p.data["r16"] = 2075;
points[84]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 17; p.county = 0; p.val = 2705; p.data["black"] = 335; p.data["white"] = 2250; p.data["r"] = 275; p.data["d"] = 417; p.data["d16"] = 750; p.data["r16"] = 1555;
points[85]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 20; p.county = 0; p.val = 1785; p.data["black"] = 285; p.data["white"] = 1455; p.data["r"] = 326; p.data["d"] = 515; p.data["d16"] = 345; p.data["r16"] = 667;
points[86]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 20; p.county = 0; p.val = 2025; p.data["black"] = 455; p.data["white"] = 1470; p.data["r"] = 390; p.data["d"] = 515; p.data["d16"] = 519; p.data["r16"] = 754;
points[87]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 18; p.county = 0; p.val = 1600; p.data["black"] = 315; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[88]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 74; p.county = 0; p.val = 3195; p.data["black"] = 1830; p.data["white"] = 1290; p.data["r"] = 1332; p.data["d"] = 341; p.data["d16"] = 579; p.data["r16"] = 375;
points[89]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 76; p.county = 0; p.val = 9125; p.data["black"] = 920; p.data["white"] = 7225; p.data["r"] = 1167; p.data["d"] = 208; p.data["d16"] = 2723; p.data["r16"] = 717;
points[90]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 74; p.county = 0; p.val = 1145; p.data["black"] = 430; p.data["white"] = 690; p.data["r"] = 462; p.data["d"] = 298; p.data["d16"] = 1037; p.data["r16"] = 113;
points[91]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 73; p.county = 0; p.val = 1390; p.data["black"] = 415; p.data["white"] = 895; p.data["r"] = 547; p.data["d"] = 343; p.data["d16"] = 614; p.data["r16"] = 825;
points[92]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 77; p.county = 0; p.val = 1675; p.data["black"] = 185; p.data["white"] = 1380; p.data["r"] = 609; p.data["d"] = 917; p.data["d16"] = 454; p.data["r16"] = 1124;
points[93]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 89; p.county = 0; p.val = 590; p.data["black"] = 295; p.data["white"] = 290; p.data["r"] = 70; p.data["d"] = 139; p.data["d16"] = 71; p.data["r16"] = 186;
points[94]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 97; p.county = 0; p.val = 365; p.data["black"] = 170; p.data["white"] = 195; p.data["r"] = 702; p.data["d"] = 639; p.data["d16"] = 863; p.data["r16"] = 833;
points[95]=p;}
if (1==1){ Point p;
p.x = 157; p.y = 93; p.county = 0; p.val = 560; p.data["black"] = 510; p.data["white"] = 50; p.data["r"] = 619; p.data["d"] = 118; p.data["d16"] = 807; p.data["r16"] = 140;
points[96]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 90; p.county = 0; p.val = 785; p.data["black"] = 380; p.data["white"] = 405; p.data["r"] = 185; p.data["d"] = 318; p.data["d16"] = 195; p.data["r16"] = 388;
points[97]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 106; p.county = 0; p.val = 590; p.data["black"] = 535; p.data["white"] = 35; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[98]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 90; p.county = 0; p.val = 540; p.data["black"] = 335; p.data["white"] = 190; p.data["r"] = 228; p.data["d"] = 273; p.data["d16"] = 255; p.data["r16"] = 432;
points[99]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 91; p.county = 0; p.val = 875; p.data["black"] = 380; p.data["white"] = 465; p.data["r"] = 116; p.data["d"] = 76; p.data["d16"] = 131; p.data["r16"] = 94;
points[100]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 86; p.county = 0; p.val = 760; p.data["black"] = 45; p.data["white"] = 690; p.data["r"] = 76; p.data["d"] = 135; p.data["d16"] = 1342; p.data["r16"] = 433;
points[101]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 111; p.county = 0; p.val = 800; p.data["black"] = 470; p.data["white"] = 330; p.data["r"] = 423; p.data["d"] = 52; p.data["d16"] = 488; p.data["r16"] = 61;
points[102]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 105; p.county = 0; p.val = 635; p.data["black"] = 470; p.data["white"] = 150; p.data["r"] = 562; p.data["d"] = 121; p.data["d16"] = 735; p.data["r16"] = 169;
points[103]=p;}
if (1==1){ Point p;
p.x = 160; p.y = 98; p.county = 0; p.val = 750; p.data["black"] = 565; p.data["white"] = 150; p.data["r"] = 321; p.data["d"] = 50; p.data["d16"] = 385; p.data["r16"] = 47;
points[104]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 112; p.county = 0; p.val = 590; p.data["black"] = 305; p.data["white"] = 245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[105]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 111; p.county = 0; p.val = 1200; p.data["black"] = 585; p.data["white"] = 605; p.data["r"] = 157; p.data["d"] = 388; p.data["d16"] = 178; p.data["r16"] = 481;
points[106]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 97; p.county = 0; p.val = 1330; p.data["black"] = 1170; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[107]=p;}
if (1==1){ Point p;
p.x = 161; p.y = 104; p.county = 0; p.val = 505; p.data["black"] = 95; p.data["white"] = 400; p.data["r"] = 139; p.data["d"] = 12; p.data["d16"] = 178; p.data["r16"] = 7;
points[108]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 91; p.county = 0; p.val = 1035; p.data["black"] = 965; p.data["white"] = 70; p.data["r"] = 538; p.data["d"] = 304; p.data["d16"] = 680; p.data["r16"] = 355;
points[109]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 94; p.county = 0; p.val = 1180; p.data["black"] = 1155; p.data["white"] = 15; p.data["r"] = 790; p.data["d"] = 74; p.data["d16"] = 1050; p.data["r16"] = 71;
points[110]=p;}
if (1==1){ Point p;
p.x = 164; p.y = 91; p.county = 0; p.val = 505; p.data["black"] = 70; p.data["white"] = 435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[111]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 102; p.county = 0; p.val = 710; p.data["black"] = 430; p.data["white"] = 280; p.data["r"] = 308; p.data["d"] = 149; p.data["d16"] = 458; p.data["r16"] = 186;
points[112]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 100; p.county = 0; p.val = 430; p.data["black"] = 235; p.data["white"] = 130; p.data["r"] = 731; p.data["d"] = 282; p.data["d16"] = 997; p.data["r16"] = 336;
points[113]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 69; p.county = 0; p.val = 475; p.data["black"] = 60; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[114]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 96; p.county = 0; p.val = 1840; p.data["black"] = 1695; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[115]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 94; p.county = 0; p.val = 1130; p.data["black"] = 525; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[116]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 94; p.county = 0; p.val = 1080; p.data["black"] = 600; p.data["white"] = 445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[117]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 97; p.county = 0; p.val = 355; p.data["black"] = 200; p.data["white"] = 150; p.data["r"] = 298; p.data["d"] = 12; p.data["d16"] = 440; p.data["r16"] = 13;
points[118]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 22; p.county = 0; p.val = 1500; p.data["black"] = 30; p.data["white"] = 1345; p.data["r"] = 564; p.data["d"] = 1092; p.data["d16"] = 557; p.data["r16"] = 1347;
points[119]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 23; p.county = 0; p.val = 1460; p.data["black"] = 160; p.data["white"] = 1220; p.data["r"] = 967; p.data["d"] = 1904; p.data["d16"] = 950; p.data["r16"] = 2324;
points[120]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 24; p.county = 0; p.val = 2060; p.data["black"] = 75; p.data["white"] = 1780; p.data["r"] = 542; p.data["d"] = 1037; p.data["d16"] = 523; p.data["r16"] = 1290;
points[121]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 26; p.county = 0; p.val = 2695; p.data["black"] = 720; p.data["white"] = 1880; p.data["r"] = 801; p.data["d"] = 498; p.data["d16"] = 903; p.data["r16"] = 687;
points[122]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 25; p.county = 0; p.val = 2045; p.data["black"] = 1005; p.data["white"] = 910; p.data["r"] = 530; p.data["d"] = 530; p.data["d16"] = 0; p.data["r16"] = 0;
points[123]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 26; p.county = 0; p.val = 1535; p.data["black"] = 320; p.data["white"] = 1075; p.data["r"] = 1102; p.data["d"] = 1603; p.data["d16"] = 1088; p.data["r16"] = 1942;
points[124]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 30; p.county = 0; p.val = 965; p.data["black"] = 140; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[125]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 29; p.county = 0; p.val = 970; p.data["black"] = 345; p.data["white"] = 615; p.data["r"] = 449; p.data["d"] = 509; p.data["d16"] = 491; p.data["r16"] = 728;
points[126]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 30; p.county = 0; p.val = 5630; p.data["black"] = 1095; p.data["white"] = 4055; p.data["r"] = 644; p.data["d"] = 809; p.data["d16"] = 648; p.data["r16"] = 1076;
points[127]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 26; p.county = 0; p.val = 2520; p.data["black"] = 2050; p.data["white"] = 395; p.data["r"] = 612; p.data["d"] = 80; p.data["d16"] = 0; p.data["r16"] = 0;
points[128]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 25; p.county = 0; p.val = 2315; p.data["black"] = 1955; p.data["white"] = 329; p.data["r"] = 571; p.data["d"] = 147; p.data["d16"] = 1766; p.data["r16"] = 223;
points[129]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 22; p.county = 0; p.val = 3600; p.data["black"] = 1980; p.data["white"] = 1420; p.data["r"] = 518; p.data["d"] = 366; p.data["d16"] = 689; p.data["r16"] = 472;
points[130]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 24; p.county = 0; p.val = 695; p.data["black"] = 25; p.data["white"] = 630; p.data["r"] = 257; p.data["d"] = 658; p.data["d16"] = 241; p.data["r16"] = 849;
points[131]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 13; p.county = 0; p.val = 960; p.data["black"] = 0; p.data["white"] = 960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 109; p.data["r16"] = 940;
points[132]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 23; p.county = 0; p.val = 730; p.data["black"] = 4; p.data["white"] = 730; p.data["r"] = 91; p.data["d"] = 301; p.data["d16"] = 111; p.data["r16"] = 512;
points[133]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 16; p.county = 0; p.val = 800; p.data["black"] = 0; p.data["white"] = 775; p.data["r"] = 113; p.data["d"] = 574; p.data["d16"] = 81; p.data["r16"] = 755;
points[134]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 22; p.county = 0; p.val = 2095; p.data["black"] = 325; p.data["white"] = 1660; p.data["r"] = 338; p.data["d"] = 968; p.data["d16"] = 316; p.data["r16"] = 1055;
points[135]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 23; p.county = 0; p.val = 1065; p.data["black"] = 0; p.data["white"] = 1010; p.data["r"] = 53; p.data["d"] = 441; p.data["d16"] = 197; p.data["r16"] = 1384;
points[136]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 20; p.county = 0; p.val = 445; p.data["black"] = 170; p.data["white"] = 235; p.data["r"] = 166; p.data["d"] = 375; p.data["d16"] = 177; p.data["r16"] = 512;
points[137]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 29; p.county = 0; p.val = 660; p.data["black"] = 50; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 291; p.data["r16"] = 363;
points[138]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 14; p.county = 0; p.val = 1180; p.data["black"] = 0; p.data["white"] = 1145; p.data["r"] = 94; p.data["d"] = 533; p.data["d16"] = 91; p.data["r16"] = 815;
points[139]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 23; p.county = 0; p.val = 3200; p.data["black"] = 1035; p.data["white"] = 1995; p.data["r"] = 465; p.data["d"] = 355; p.data["d16"] = 514; p.data["r16"] = 485;
points[140]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 24; p.county = 0; p.val = 1130; p.data["black"] = 360; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[141]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 23; p.county = 0; p.val = 2530; p.data["black"] = 440; p.data["white"] = 1985; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 386; p.data["r16"] = 664;
points[142]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 53; p.county = 0; p.val = 885; p.data["black"] = 310; p.data["white"] = 570; p.data["r"] = 594; p.data["d"] = 11; p.data["d16"] = 920; p.data["r16"] = 14;
points[143]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 9; p.county = 0; p.val = 2185; p.data["black"] = 250; p.data["white"] = 1830; p.data["r"] = 2062; p.data["d"] = 2989; p.data["d16"] = 1850; p.data["r16"] = 2842;
points[144]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 9; p.county = 0; p.val = 3890; p.data["black"] = 440; p.data["white"] = 3200; p.data["r"] = 339; p.data["d"] = 464; p.data["d16"] = 905; p.data["r16"] = 1118;
points[145]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 13; p.county = 0; p.val = 1505; p.data["black"] = 0; p.data["white"] = 1170; p.data["r"] = 425; p.data["d"] = 590; p.data["d16"] = 1524; p.data["r16"] = 1666;
points[146]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 7; p.county = 0; p.val = 3035; p.data["black"] = 275; p.data["white"] = 2195; p.data["r"] = 1806; p.data["d"] = 2571; p.data["d16"] = 1592; p.data["r16"] = 2530;
points[147]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 90; p.county = 0; p.val = 4955; p.data["black"] = 365; p.data["white"] = 4175; p.data["r"] = 374; p.data["d"] = 609; p.data["d16"] = 1358; p.data["r16"] = 2900;
points[148]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 85; p.county = 0; p.val = 1370; p.data["black"] = 95; p.data["white"] = 1265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 157; p.data["r16"] = 782;
points[149]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 100; p.county = 0; p.val = 880; p.data["black"] = 15; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 426; p.data["r16"] = 1076;
points[150]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 102; p.county = 0; p.val = 2350; p.data["black"] = 100; p.data["white"] = 2090; p.data["r"] = 726; p.data["d"] = 1352; p.data["d16"] = 0; p.data["r16"] = 0;
points[151]=p;}
if (1==1){ Point p;
p.x = 190; p.y = 92; p.county = 0; p.val = 3060; p.data["black"] = 290; p.data["white"] = 2560; p.data["r"] = 514; p.data["d"] = 1280; p.data["d16"] = 0; p.data["r16"] = 0;
points[152]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 95; p.county = 0; p.val = 3050; p.data["black"] = 1565; p.data["white"] = 1315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[153]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 80; p.county = 0; p.val = 1805; p.data["black"] = 255; p.data["white"] = 1475; p.data["r"] = 355; p.data["d"] = 237; p.data["d16"] = 367; p.data["r16"] = 307;
points[154]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 81; p.county = 0; p.val = 1575; p.data["black"] = 690; p.data["white"] = 860; p.data["r"] = 453; p.data["d"] = 690; p.data["d16"] = 470; p.data["r16"] = 706;
points[155]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 81; p.county = 0; p.val = 1425; p.data["black"] = 495; p.data["white"] = 895; p.data["r"] = 239; p.data["d"] = 716; p.data["d16"] = 412; p.data["r16"] = 1208;
points[156]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 83; p.county = 0; p.val = 1630; p.data["black"] = 380; p.data["white"] = 1140; p.data["r"] = 825; p.data["d"] = 984; p.data["d16"] = 759; p.data["r16"] = 1042;
points[157]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 82; p.county = 0; p.val = 775; p.data["black"] = 215; p.data["white"] = 480; p.data["r"] = 216; p.data["d"] = 282; p.data["d16"] = 206; p.data["r16"] = 230;
points[158]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 83; p.county = 0; p.val = 870; p.data["black"] = 370; p.data["white"] = 445; p.data["r"] = 460; p.data["d"] = 579; p.data["d16"] = 605; p.data["r16"] = 752;
points[159]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 152; p.county = 0; p.val = 2245; p.data["black"] = 650; p.data["white"] = 1450; p.data["r"] = 282; p.data["d"] = 258; p.data["d16"] = 278; p.data["r16"] = 313;
points[160]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 151; p.county = 0; p.val = 3510; p.data["black"] = 630; p.data["white"] = 2765; p.data["r"] = 952; p.data["d"] = 713; p.data["d16"] = 221; p.data["r16"] = 213;
points[161]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 151; p.county = 0; p.val = 1460; p.data["black"] = 130; p.data["white"] = 1260; p.data["r"] = 320; p.data["d"] = 7; p.data["d16"] = 324; p.data["r16"] = 14;
points[162]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 152; p.county = 0; p.val = 5180; p.data["black"] = 385; p.data["white"] = 4510; p.data["r"] = 1034; p.data["d"] = 1067; p.data["d16"] = 962; p.data["r16"] = 1467;
points[163]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 149; p.county = 0; p.val = 615; p.data["black"] = 475; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1077; p.data["r16"] = 1071;
points[164]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 145; p.county = 0; p.val = 655; p.data["black"] = 110; p.data["white"] = 435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[165]=p;}
if (1==1){ Point p;
p.x = 155; p.y = 144; p.county = 0; p.val = 795; p.data["black"] = 355; p.data["white"] = 405; p.data["r"] = 447; p.data["d"] = 364; p.data["d16"] = 496; p.data["r16"] = 404;
points[166]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 74; p.county = 0; p.val = 3075; p.data["black"] = 1950; p.data["white"] = 959; p.data["r"] = 1350; p.data["d"] = 226; p.data["d16"] = 2400; p.data["r16"] = 247;
points[167]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 70; p.county = 0; p.val = 3785; p.data["black"] = 1755; p.data["white"] = 1460; p.data["r"] = 1025; p.data["d"] = 410; p.data["d16"] = 0; p.data["r16"] = 0;
points[168]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 69; p.county = 0; p.val = 2465; p.data["black"] = 970; p.data["white"] = 1275; p.data["r"] = 805; p.data["d"] = 565; p.data["d16"] = 0; p.data["r16"] = 0;
points[169]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 66; p.county = 0; p.val = 4195; p.data["black"] = 3125; p.data["white"] = 795; p.data["r"] = 4785; p.data["d"] = 769; p.data["d16"] = 4635; p.data["r16"] = 1167;
points[170]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 67; p.county = 0; p.val = 2710; p.data["black"] = 715; p.data["white"] = 1895; p.data["r"] = 239; p.data["d"] = 236; p.data["d16"] = 224; p.data["r16"] = 328;
points[171]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 67; p.county = 0; p.val = 1285; p.data["black"] = 930; p.data["white"] = 360; p.data["r"] = 958; p.data["d"] = 317; p.data["d16"] = 1815; p.data["r16"] = 618;
points[172]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 63; p.county = 0; p.val = 1635; p.data["black"] = 140; p.data["white"] = 1495; p.data["r"] = 334; p.data["d"] = 1065; p.data["d16"] = 0; p.data["r16"] = 0;
points[173]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 70; p.county = 0; p.val = 575; p.data["black"] = 510; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[174]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 69; p.county = 0; p.val = 535; p.data["black"] = 485; p.data["white"] = 50; p.data["r"] = 1277; p.data["d"] = 227; p.data["d16"] = 1366; p.data["r16"] = 293;
points[175]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 73; p.county = 0; p.val = 3555; p.data["black"] = 2630; p.data["white"] = 800; p.data["r"] = 364; p.data["d"] = 10; p.data["d16"] = 845; p.data["r16"] = 44;
points[176]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 68; p.county = 0; p.val = 4075; p.data["black"] = 2025; p.data["white"] = 1700; p.data["r"] = 990; p.data["d"] = 182; p.data["d16"] = 981; p.data["r16"] = 640;
points[177]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 77; p.county = 0; p.val = 2730; p.data["black"] = 1540; p.data["white"] = 1130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[178]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 93; p.county = 0; p.val = 730; p.data["black"] = 0; p.data["white"] = 700; p.data["r"] = 46; p.data["d"] = 552; p.data["d16"] = 60; p.data["r16"] = 623;
points[179]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 75; p.county = 0; p.val = 4870; p.data["black"] = 2074; p.data["white"] = 2735; p.data["r"] = 1408; p.data["d"] = 592; p.data["d16"] = 1015; p.data["r16"] = 975;
points[180]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 71; p.county = 0; p.val = 620; p.data["black"] = 220; p.data["white"] = 345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[181]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 82; p.county = 0; p.val = 1310; p.data["black"] = 1120; p.data["white"] = 190; p.data["r"] = 744; p.data["d"] = 106; p.data["d16"] = 1016; p.data["r16"] = 337;
points[182]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 61; p.county = 0; p.val = 2145; p.data["black"] = 535; p.data["white"] = 1525; p.data["r"] = 1840; p.data["d"] = 1200; p.data["d16"] = 1478; p.data["r16"] = 1415;
points[183]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 67; p.county = 0; p.val = 3270; p.data["black"] = 440; p.data["white"] = 2540; p.data["r"] = 516; p.data["d"] = 581; p.data["d16"] = 936; p.data["r16"] = 1851;
points[184]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 78; p.county = 0; p.val = 625; p.data["black"] = 175; p.data["white"] = 450; p.data["r"] = 688; p.data["d"] = 458; p.data["d16"] = 797; p.data["r16"] = 615;
points[185]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 72; p.county = 0; p.val = 2030; p.data["black"] = 1840; p.data["white"] = 130; p.data["r"] = 688; p.data["d"] = 26; p.data["d16"] = 956; p.data["r16"] = 27;
points[186]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 84; p.county = 0; p.val = 1260; p.data["black"] = 1060; p.data["white"] = 200; p.data["r"] = 682; p.data["d"] = 68; p.data["d16"] = 718; p.data["r16"] = 79;
points[187]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 73; p.county = 0; p.val = 2500; p.data["black"] = 90; p.data["white"] = 2275; p.data["r"] = 897; p.data["d"] = 708; p.data["d16"] = 582; p.data["r16"] = 391;
points[188]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 62; p.county = 0; p.val = 1345; p.data["black"] = 195; p.data["white"] = 1110; p.data["r"] = 473; p.data["d"] = 695; p.data["d16"] = 363; p.data["r16"] = 807;
points[189]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 75; p.county = 0; p.val = 1060; p.data["black"] = 360; p.data["white"] = 680; p.data["r"] = 351; p.data["d"] = 148; p.data["d16"] = 371; p.data["r16"] = 221;
points[190]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 82; p.county = 0; p.val = 925; p.data["black"] = 225; p.data["white"] = 700; p.data["r"] = 168; p.data["d"] = 131; p.data["d16"] = 206; p.data["r16"] = 150;
points[191]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 76; p.county = 0; p.val = 1245; p.data["black"] = 25; p.data["white"] = 1120; p.data["r"] = 299; p.data["d"] = 1048; p.data["d16"] = 421; p.data["r16"] = 1488;
points[192]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 81; p.county = 0; p.val = 445; p.data["black"] = 235; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 150; p.data["r16"] = 184;
points[193]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 76; p.county = 0; p.val = 2920; p.data["black"] = 215; p.data["white"] = 2575; p.data["r"] = 1431; p.data["d"] = 1525; p.data["d16"] = 431; p.data["r16"] = 807;
points[194]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 105; p.county = 0; p.val = 2305; p.data["black"] = 325; p.data["white"] = 1920; p.data["r"] = 261; p.data["d"] = 37; p.data["d16"] = 0; p.data["r16"] = 0;
points[195]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 70; p.county = 0; p.val = 1435; p.data["black"] = 1395; p.data["white"] = 40; p.data["r"] = 1080; p.data["d"] = 21; p.data["d16"] = 1394; p.data["r16"] = 29;
points[196]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 71; p.county = 0; p.val = 1900; p.data["black"] = 1300; p.data["white"] = 415; p.data["r"] = 2012; p.data["d"] = 613; p.data["d16"] = 2289; p.data["r16"] = 738;
points[197]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 186; p.county = 0; p.val = 2065; p.data["black"] = 140; p.data["white"] = 1690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[198]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 186; p.county = 0; p.val = 1400; p.data["black"] = 75; p.data["white"] = 1295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[199]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 186; p.county = 0; p.val = 2100; p.data["black"] = 225; p.data["white"] = 1745; p.data["r"] = 416; p.data["d"] = 978; p.data["d16"] = 156; p.data["r16"] = 386;
points[200]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 187; p.county = 0; p.val = 605; p.data["black"] = 0; p.data["white"] = 545; p.data["r"] = 1289; p.data["d"] = 2074; p.data["d16"] = 1489; p.data["r16"] = 2522;
points[201]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 187; p.county = 0; p.val = 2005; p.data["black"] = 250; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[202]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 98; p.county = 0; p.val = 1735; p.data["black"] = 555; p.data["white"] = 1180; p.data["r"] = 295; p.data["d"] = 695; p.data["d16"] = 302; p.data["r16"] = 877;
points[203]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 104; p.county = 0; p.val = 1010; p.data["black"] = 155; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 278; p.data["r16"] = 441;
points[204]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 108; p.county = 0; p.val = 665; p.data["black"] = 75; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 157; p.data["r16"] = 462;
points[205]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 105; p.county = 0; p.val = 1135; p.data["black"] = 140; p.data["white"] = 975; p.data["r"] = 765; p.data["d"] = 1236; p.data["d16"] = 501; p.data["r16"] = 981;
points[206]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 104; p.county = 0; p.val = 950; p.data["black"] = 110; p.data["white"] = 835; p.data["r"] = 304; p.data["d"] = 396; p.data["d16"] = 535; p.data["r16"] = 157;
points[207]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 96; p.county = 0; p.val = 1740; p.data["black"] = 795; p.data["white"] = 905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[208]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 174; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 203; p.data["d"] = 591; p.data["d16"] = 219; p.data["r16"] = 635;
points[209]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 81; p.county = 0; p.val = 2055; p.data["black"] = 185; p.data["white"] = 1670; p.data["r"] = 801; p.data["d"] = 1818; p.data["d16"] = 278; p.data["r16"] = 1077;
points[210]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 81; p.county = 0; p.val = 2130; p.data["black"] = 75; p.data["white"] = 1965; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 351; p.data["r16"] = 1077;
points[211]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 72; p.county = 0; p.val = 745; p.data["black"] = 225; p.data["white"] = 470; p.data["r"] = 574; p.data["d"] = 346; p.data["d16"] = 583; p.data["r16"] = 444;
points[212]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 72; p.county = 0; p.val = 915; p.data["black"] = 0; p.data["white"] = 910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[213]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 76; p.county = 0; p.val = 1230; p.data["black"] = 75; p.data["white"] = 1095; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[214]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 89; p.county = 0; p.val = 1370; p.data["black"] = 290; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[215]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 76; p.county = 0; p.val = 1950; p.data["black"] = 1070; p.data["white"] = 680; p.data["r"] = 511; p.data["d"] = 499; p.data["d16"] = 419; p.data["r16"] = 176;
points[216]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 80; p.county = 0; p.val = 1155; p.data["black"] = 900; p.data["white"] = 235; p.data["r"] = 445; p.data["d"] = 169; p.data["d16"] = 524; p.data["r16"] = 218;
points[217]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 73; p.county = 0; p.val = 4695; p.data["black"] = 3260; p.data["white"] = 1155; p.data["r"] = 1327; p.data["d"] = 193; p.data["d16"] = 1672; p.data["r16"] = 226;
points[218]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 74; p.county = 0; p.val = 3535; p.data["black"] = 595; p.data["white"] = 2800; p.data["r"] = 833; p.data["d"] = 996; p.data["d16"] = 777; p.data["r16"] = 1048;
points[219]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 88; p.county = 0; p.val = 1130; p.data["black"] = 1130; p.data["white"] = 0; p.data["r"] = 792; p.data["d"] = 52; p.data["d16"] = 864; p.data["r16"] = 54;
points[220]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 48; p.county = 0; p.val = 800; p.data["black"] = 85; p.data["white"] = 695; p.data["r"] = 149; p.data["d"] = 285; p.data["d16"] = 183; p.data["r16"] = 399;
points[221]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 57; p.county = 0; p.val = 1190; p.data["black"] = 380; p.data["white"] = 790; p.data["r"] = 235; p.data["d"] = 355; p.data["d16"] = 267; p.data["r16"] = 521;
points[222]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 60; p.county = 0; p.val = 1140; p.data["black"] = 315; p.data["white"] = 800; p.data["r"] = 146; p.data["d"] = 251; p.data["d16"] = 159; p.data["r16"] = 334;
points[223]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 57; p.county = 0; p.val = 975; p.data["black"] = 245; p.data["white"] = 720; p.data["r"] = 112; p.data["d"] = 239; p.data["d16"] = 0; p.data["r16"] = 0;
points[224]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 43; p.county = 0; p.val = 765; p.data["black"] = 90; p.data["white"] = 670; p.data["r"] = 293; p.data["d"] = 398; p.data["d16"] = 180; p.data["r16"] = 117;
points[225]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 59; p.county = 0; p.val = 465; p.data["black"] = 290; p.data["white"] = 160; p.data["r"] = 461; p.data["d"] = 201; p.data["d16"] = 293; p.data["r16"] = 236;
points[226]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 52; p.county = 0; p.val = 650; p.data["black"] = 115; p.data["white"] = 535; p.data["r"] = 220; p.data["d"] = 390; p.data["d16"] = 236; p.data["r16"] = 586;
points[227]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 58; p.county = 0; p.val = 960; p.data["black"] = 255; p.data["white"] = 660; p.data["r"] = 99; p.data["d"] = 178; p.data["d16"] = 0; p.data["r16"] = 0;
points[228]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 102; p.county = 0; p.val = 1060; p.data["black"] = 505; p.data["white"] = 555; p.data["r"] = 265; p.data["d"] = 331; p.data["d16"] = 323; p.data["r16"] = 362;
points[229]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 104; p.county = 0; p.val = 480; p.data["black"] = 0; p.data["white"] = 480; p.data["r"] = 397; p.data["d"] = 114; p.data["d16"] = 745; p.data["r16"] = 136;
points[230]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 104; p.county = 0; p.val = 435; p.data["black"] = 260; p.data["white"] = 130; p.data["r"] = 553; p.data["d"] = 86; p.data["d16"] = 234; p.data["r16"] = 499;
points[231]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 102; p.county = 0; p.val = 1265; p.data["black"] = 815; p.data["white"] = 360; p.data["r"] = 477; p.data["d"] = 203; p.data["d16"] = 0; p.data["r16"] = 0;
points[232]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 92; p.county = 0; p.val = 1055; p.data["black"] = 290; p.data["white"] = 765; p.data["r"] = 171; p.data["d"] = 333; p.data["d16"] = 189; p.data["r16"] = 457;
points[233]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 95; p.county = 0; p.val = 805; p.data["black"] = 615; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[234]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 94; p.county = 0; p.val = 875; p.data["black"] = 460; p.data["white"] = 405; p.data["r"] = 148; p.data["d"] = 161; p.data["d16"] = 178; p.data["r16"] = 208;
points[235]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 103; p.county = 0; p.val = 450; p.data["black"] = 170; p.data["white"] = 250; p.data["r"] = 251; p.data["d"] = 213; p.data["d16"] = 348; p.data["r16"] = 338;
points[236]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 88; p.county = 0; p.val = 1910; p.data["black"] = 115; p.data["white"] = 1725; p.data["r"] = 347; p.data["d"] = 647; p.data["d16"] = 336; p.data["r16"] = 888;
points[237]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 106; p.county = 0; p.val = 515; p.data["black"] = 300; p.data["white"] = 215; p.data["r"] = 64; p.data["d"] = 151; p.data["d16"] = 68; p.data["r16"] = 190;
points[238]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 97; p.county = 0; p.val = 1525; p.data["black"] = 660; p.data["white"] = 710; p.data["r"] = 522; p.data["d"] = 381; p.data["d16"] = 623; p.data["r16"] = 473;
points[239]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 96; p.county = 0; p.val = 500; p.data["black"] = 245; p.data["white"] = 250; p.data["r"] = 91; p.data["d"] = 74; p.data["d16"] = 124; p.data["r16"] = 90;
points[240]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 98; p.county = 0; p.val = 1360; p.data["black"] = 1120; p.data["white"] = 235; p.data["r"] = 772; p.data["d"] = 224; p.data["d16"] = 941; p.data["r16"] = 265;
points[241]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 100; p.county = 0; p.val = 1040; p.data["black"] = 170; p.data["white"] = 835; p.data["r"] = 359; p.data["d"] = 437; p.data["d16"] = 443; p.data["r16"] = 516;
points[242]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 97; p.county = 0; p.val = 570; p.data["black"] = 195; p.data["white"] = 355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[243]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 42; p.county = 0; p.val = 1545; p.data["black"] = 25; p.data["white"] = 1505; p.data["r"] = 109; p.data["d"] = 528; p.data["d16"] = 188; p.data["r16"] = 1208;
points[244]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 27; p.county = 0; p.val = 1340; p.data["black"] = 345; p.data["white"] = 830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 244; p.data["r16"] = 930;
points[245]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 39; p.county = 0; p.val = 1590; p.data["black"] = 35; p.data["white"] = 1545; p.data["r"] = 247; p.data["d"] = 676; p.data["d16"] = 211; p.data["r16"] = 861;
points[246]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 43; p.county = 0; p.val = 535; p.data["black"] = 4; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[247]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 37; p.county = 0; p.val = 1995; p.data["black"] = 15; p.data["white"] = 1865; p.data["r"] = 168; p.data["d"] = 608; p.data["d16"] = 152; p.data["r16"] = 839;
points[248]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 32; p.county = 0; p.val = 720; p.data["black"] = 40; p.data["white"] = 645; p.data["r"] = 159; p.data["d"] = 507; p.data["d16"] = 0; p.data["r16"] = 0;
points[249]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 36; p.county = 0; p.val = 1240; p.data["black"] = 165; p.data["white"] = 1050; p.data["r"] = 307; p.data["d"] = 1186; p.data["d16"] = 0; p.data["r16"] = 0;
points[250]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 34; p.county = 0; p.val = 835; p.data["black"] = 30; p.data["white"] = 805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[251]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 32; p.county = 0; p.val = 960; p.data["black"] = 0; p.data["white"] = 960; p.data["r"] = 21; p.data["d"] = 219; p.data["d16"] = 0; p.data["r16"] = 0;
points[252]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 14; p.county = 0; p.val = 1260; p.data["black"] = 0; p.data["white"] = 1210; p.data["r"] = 239; p.data["d"] = 932; p.data["d16"] = 203; p.data["r16"] = 1154;
points[253]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 31; p.county = 0; p.val = 2240; p.data["black"] = 180; p.data["white"] = 2000; p.data["r"] = 742; p.data["d"] = 778; p.data["d16"] = 245; p.data["r16"] = 613;
points[254]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 17; p.county = 0; p.val = 1515; p.data["black"] = 175; p.data["white"] = 1025; p.data["r"] = 594; p.data["d"] = 875; p.data["d16"] = 510; p.data["r16"] = 932;
points[255]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 53; p.county = 0; p.val = 585; p.data["black"] = 270; p.data["white"] = 315; p.data["r"] = 181; p.data["d"] = 155; p.data["d16"] = 267; p.data["r16"] = 200;
points[256]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 77; p.county = 0; p.val = 990; p.data["black"] = 305; p.data["white"] = 565; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[257]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 80; p.county = 0; p.val = 2065; p.data["black"] = 1405; p.data["white"] = 505; p.data["r"] = 209; p.data["d"] = 256; p.data["d16"] = 252; p.data["r16"] = 338;
points[258]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 15; p.county = 0; p.val = 1690; p.data["black"] = 595; p.data["white"] = 845; p.data["r"] = 528; p.data["d"] = 585; p.data["d16"] = 0; p.data["r16"] = 0;
points[259]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 11; p.county = 0; p.val = 5315; p.data["black"] = 590; p.data["white"] = 4490; p.data["r"] = 478; p.data["d"] = 655; p.data["d16"] = 0; p.data["r16"] = 0;
points[260]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 12; p.county = 0; p.val = 2080; p.data["black"] = 435; p.data["white"] = 1380; p.data["r"] = 1771; p.data["d"] = 2852; p.data["d16"] = 1395; p.data["r16"] = 2357;
points[261]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 11; p.county = 0; p.val = 2410; p.data["black"] = 270; p.data["white"] = 2100; p.data["r"] = 125; p.data["d"] = 346; p.data["d16"] = 162; p.data["r16"] = 421;
points[262]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 16; p.county = 0; p.val = 1970; p.data["black"] = 395; p.data["white"] = 1500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[263]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 102; p.county = 0; p.val = 1320; p.data["black"] = 890; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[264]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 64; p.county = 0; p.val = 880; p.data["black"] = 690; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[265]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 20; p.county = 0; p.val = 1970; p.data["black"] = 105; p.data["white"] = 1565; p.data["r"] = 581; p.data["d"] = 956; p.data["d16"] = 0; p.data["r16"] = 0;
points[266]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 22; p.county = 0; p.val = 1095; p.data["black"] = 10; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1245; p.data["r16"] = 1628;
points[267]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 21; p.county = 0; p.val = 1125; p.data["black"] = 0; p.data["white"] = 1085; p.data["r"] = 451; p.data["d"] = 681; p.data["d16"] = 405; p.data["r16"] = 797;
points[268]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 21; p.county = 0; p.val = 1585; p.data["black"] = 415; p.data["white"] = 920; p.data["r"] = 629; p.data["d"] = 1039; p.data["d16"] = 624; p.data["r16"] = 1226;
points[269]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 21; p.county = 0; p.val = 1085; p.data["black"] = 480; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 297; p.data["r16"] = 210;
points[270]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 22; p.county = 0; p.val = 1325; p.data["black"] = 190; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[271]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 23; p.county = 0; p.val = 720; p.data["black"] = 0; p.data["white"] = 720; p.data["r"] = 447; p.data["d"] = 797; p.data["d16"] = 373; p.data["r16"] = 958;
points[272]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 24; p.county = 0; p.val = 2890; p.data["black"] = 460; p.data["white"] = 2335; p.data["r"] = 640; p.data["d"] = 172; p.data["d16"] = 799; p.data["r16"] = 209;
points[273]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 25; p.county = 0; p.val = 1570; p.data["black"] = 1290; p.data["white"] = 195; p.data["r"] = 1107; p.data["d"] = 166; p.data["d16"] = 1173; p.data["r16"] = 278;
points[274]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 18; p.county = 0; p.val = 3395; p.data["black"] = 425; p.data["white"] = 2725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 643; p.data["r16"] = 759;
points[275]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 15; p.county = 0; p.val = 1530; p.data["black"] = 75; p.data["white"] = 1350; p.data["r"] = 441; p.data["d"] = 677; p.data["d16"] = 501; p.data["r16"] = 882;
points[276]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 28; p.county = 0; p.val = 2765; p.data["black"] = 545; p.data["white"] = 1970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 454; p.data["r16"] = 731;
points[277]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 17; p.county = 0; p.val = 510; p.data["black"] = 0; p.data["white"] = 495; p.data["r"] = 555; p.data["d"] = 877; p.data["d16"] = 505; p.data["r16"] = 1012;
points[278]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 77; p.county = 0; p.val = 1945; p.data["black"] = 520; p.data["white"] = 1415; p.data["r"] = 240; p.data["d"] = 91; p.data["d16"] = 99; p.data["r16"] = 80;
points[279]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 84; p.county = 0; p.val = 730; p.data["black"] = 525; p.data["white"] = 200; p.data["r"] = 442; p.data["d"] = 380; p.data["d16"] = 429; p.data["r16"] = 190;
points[280]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 81; p.county = 0; p.val = 545; p.data["black"] = 330; p.data["white"] = 220; p.data["r"] = 216; p.data["d"] = 64; p.data["d16"] = 267; p.data["r16"] = 93;
points[281]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 87; p.county = 0; p.val = 610; p.data["black"] = 365; p.data["white"] = 235; p.data["r"] = 306; p.data["d"] = 212; p.data["d16"] = 352; p.data["r16"] = 309;
points[282]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 80; p.county = 0; p.val = 1235; p.data["black"] = 515; p.data["white"] = 680; p.data["r"] = 400; p.data["d"] = 206; p.data["d16"] = 510; p.data["r16"] = 296;
points[283]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 81; p.county = 0; p.val = 580; p.data["black"] = 400; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[284]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 174; p.county = 0; p.val = 2005; p.data["black"] = 260; p.data["white"] = 1385; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 524; p.data["r16"] = 373;
points[285]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 176; p.county = 0; p.val = 2230; p.data["black"] = 455; p.data["white"] = 1610; p.data["r"] = 922; p.data["d"] = 680; p.data["d16"] = 944; p.data["r16"] = 918;
points[286]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 173; p.county = 0; p.val = 2000; p.data["black"] = 770; p.data["white"] = 1085; p.data["r"] = 404; p.data["d"] = 124; p.data["d16"] = 431; p.data["r16"] = 159;
points[287]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 175; p.county = 0; p.val = 2670; p.data["black"] = 390; p.data["white"] = 1935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[288]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 170; p.county = 0; p.val = 1960; p.data["black"] = 1440; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[289]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 175; p.county = 0; p.val = 2130; p.data["black"] = 1345; p.data["white"] = 585; p.data["r"] = 447; p.data["d"] = 286; p.data["d16"] = 0; p.data["r16"] = 0;
points[290]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 176; p.county = 0; p.val = 680; p.data["black"] = 370; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[291]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 193; p.county = 0; p.val = 3425; p.data["black"] = 25; p.data["white"] = 3395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[292]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 193; p.county = 0; p.val = 815; p.data["black"] = 10; p.data["white"] = 645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[293]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 183; p.county = 0; p.val = 750; p.data["black"] = 10; p.data["white"] = 590; p.data["r"] = 656; p.data["d"] = 713; p.data["d16"] = 638; p.data["r16"] = 926;
points[294]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 183; p.county = 0; p.val = 1050; p.data["black"] = 450; p.data["white"] = 550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[295]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 12; p.county = 0; p.val = 1695; p.data["black"] = 150; p.data["white"] = 1455; p.data["r"] = 530; p.data["d"] = 543; p.data["d16"] = 0; p.data["r16"] = 0;
points[296]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 5; p.county = 0; p.val = 1330; p.data["black"] = 130; p.data["white"] = 1200; p.data["r"] = 187; p.data["d"] = 462; p.data["d16"] = 440; p.data["r16"] = 1392;
points[297]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 7; p.county = 0; p.val = 575; p.data["black"] = 0; p.data["white"] = 540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[298]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 96; p.county = 0; p.val = 995; p.data["black"] = 255; p.data["white"] = 660; p.data["r"] = 623; p.data["d"] = 415; p.data["d16"] = 842; p.data["r16"] = 622;
points[299]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 93; p.county = 0; p.val = 1225; p.data["black"] = 125; p.data["white"] = 965; p.data["r"] = 455; p.data["d"] = 605; p.data["d16"] = 600; p.data["r16"] = 1334;
points[300]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 94; p.county = 0; p.val = 4205; p.data["black"] = 360; p.data["white"] = 3805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 597; p.data["r16"] = 1632;
points[301]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 96; p.county = 0; p.val = 1220; p.data["black"] = 50; p.data["white"] = 1130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[302]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 82; p.county = 0; p.val = 1575; p.data["black"] = 945; p.data["white"] = 610; p.data["r"] = 368; p.data["d"] = 197; p.data["d16"] = 235; p.data["r16"] = 55;
points[303]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 83; p.county = 0; p.val = 880; p.data["black"] = 380; p.data["white"] = 455; p.data["r"] = 1292; p.data["d"] = 566; p.data["d16"] = 1528; p.data["r16"] = 230;
points[304]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 80; p.county = 0; p.val = 1610; p.data["black"] = 830; p.data["white"] = 745; p.data["r"] = 509; p.data["d"] = 310; p.data["d16"] = 626; p.data["r16"] = 379;
points[305]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 79; p.county = 0; p.val = 775; p.data["black"] = 595; p.data["white"] = 180; p.data["r"] = 218; p.data["d"] = 98; p.data["d16"] = 300; p.data["r16"] = 170;
points[306]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 80; p.county = 0; p.val = 2240; p.data["black"] = 1165; p.data["white"] = 1025; p.data["r"] = 917; p.data["d"] = 177; p.data["d16"] = 712; p.data["r16"] = 176;
points[307]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 77; p.county = 0; p.val = 3655; p.data["black"] = 1285; p.data["white"] = 2250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[308]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 76; p.county = 0; p.val = 2535; p.data["black"] = 495; p.data["white"] = 1885; p.data["r"] = 353; p.data["d"] = 129; p.data["d16"] = 392; p.data["r16"] = 81;
points[309]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 74; p.county = 0; p.val = 2725; p.data["black"] = 2010; p.data["white"] = 620; p.data["r"] = 1435; p.data["d"] = 45; p.data["d16"] = 1111; p.data["r16"] = 20;
points[310]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 75; p.county = 0; p.val = 1270; p.data["black"] = 225; p.data["white"] = 955; p.data["r"] = 1423; p.data["d"] = 375; p.data["d16"] = 708; p.data["r16"] = 251;
points[311]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 75; p.county = 0; p.val = 3500; p.data["black"] = 2160; p.data["white"] = 1110; p.data["r"] = 611; p.data["d"] = 19; p.data["d16"] = 2588; p.data["r16"] = 420;
points[312]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 73; p.county = 0; p.val = 2710; p.data["black"] = 1795; p.data["white"] = 785; p.data["r"] = 776; p.data["d"] = 34; p.data["d16"] = 480; p.data["r16"] = 14;
points[313]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 110; p.county = 0; p.val = 1295; p.data["black"] = 1175; p.data["white"] = 120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[314]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 107; p.county = 0; p.val = 1860; p.data["black"] = 1115; p.data["white"] = 650; p.data["r"] = 594; p.data["d"] = 115; p.data["d16"] = 742; p.data["r16"] = 134;
points[315]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 107; p.county = 0; p.val = 1755; p.data["black"] = 1740; p.data["white"] = 0; p.data["r"] = 591; p.data["d"] = 1; p.data["d16"] = 719; p.data["r16"] = 17;
points[316]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 77; p.county = 0; p.val = 3930; p.data["black"] = 350; p.data["white"] = 3385; p.data["r"] = 751; p.data["d"] = 230; p.data["d16"] = 1400; p.data["r16"] = 664;
points[317]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 76; p.county = 0; p.val = 4385; p.data["black"] = 330; p.data["white"] = 3925; p.data["r"] = 1340; p.data["d"] = 734; p.data["d16"] = 796; p.data["r16"] = 960;
points[318]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 68; p.county = 0; p.val = 1650; p.data["black"] = 375; p.data["white"] = 1275; p.data["r"] = 262; p.data["d"] = 401; p.data["d16"] = 303; p.data["r16"] = 607;
points[319]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 64; p.county = 0; p.val = 705; p.data["black"] = 250; p.data["white"] = 430; p.data["r"] = 354; p.data["d"] = 880; p.data["d16"] = 387; p.data["r16"] = 976;
points[320]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 66; p.county = 0; p.val = 1505; p.data["black"] = 905; p.data["white"] = 570; p.data["r"] = 214; p.data["d"] = 144; p.data["d16"] = 0; p.data["r16"] = 0;
points[321]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 67; p.county = 0; p.val = 560; p.data["black"] = 105; p.data["white"] = 455; p.data["r"] = 86; p.data["d"] = 265; p.data["d16"] = 84; p.data["r16"] = 398;
points[322]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 0; p.val = 2330; p.data["black"] = 450; p.data["white"] = 1785; p.data["r"] = 316; p.data["d"] = 269; p.data["d16"] = 396; p.data["r16"] = 349;
points[323]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 72; p.county = 0; p.val = 1425; p.data["black"] = 130; p.data["white"] = 1285; p.data["r"] = 66; p.data["d"] = 296; p.data["d16"] = 73; p.data["r16"] = 422;
points[324]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 64; p.county = 0; p.val = 925; p.data["black"] = 265; p.data["white"] = 575; p.data["r"] = 205; p.data["d"] = 274; p.data["d16"] = 258; p.data["r16"] = 364;
points[325]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 0; p.val = 1740; p.data["black"] = 1220; p.data["white"] = 505; p.data["r"] = 682; p.data["d"] = 178; p.data["d16"] = 518; p.data["r16"] = 27;
points[326]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 60; p.county = 0; p.val = 1285; p.data["black"] = 495; p.data["white"] = 745; p.data["r"] = 176; p.data["d"] = 441; p.data["d16"] = 147; p.data["r16"] = 502;
points[327]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 14; p.county = 0; p.val = 3410; p.data["black"] = 1455; p.data["white"] = 1625; p.data["r"] = 407; p.data["d"] = 49; p.data["d16"] = 667; p.data["r16"] = 95;
points[328]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 15; p.county = 0; p.val = 1615; p.data["black"] = 1360; p.data["white"] = 255; p.data["r"] = 1420; p.data["d"] = 200; p.data["d16"] = 1169; p.data["r16"] = 189;
points[329]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 15; p.county = 0; p.val = 2260; p.data["black"] = 1595; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1328; p.data["r16"] = 174;
points[330]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 12; p.county = 0; p.val = 780; p.data["black"] = 120; p.data["white"] = 645; p.data["r"] = 162; p.data["d"] = 283; p.data["d16"] = 170; p.data["r16"] = 385;
points[331]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 13; p.county = 0; p.val = 1490; p.data["black"] = 210; p.data["white"] = 1225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[332]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 10; p.county = 0; p.val = 890; p.data["black"] = 60; p.data["white"] = 785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[333]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 12; p.county = 0; p.val = 695; p.data["black"] = 275; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 287; p.data["r16"] = 535;
points[334]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 11; p.county = 0; p.val = 435; p.data["black"] = 40; p.data["white"] = 380; p.data["r"] = 234; p.data["d"] = 381; p.data["d16"] = 0; p.data["r16"] = 0;
points[335]=p;}
if (1==1){ Point p;
p.x = 195; p.y = 87; p.county = 0; p.val = 1735; p.data["black"] = 140; p.data["white"] = 1590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[336]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 97; p.county = 0; p.val = 3320; p.data["black"] = 90; p.data["white"] = 2995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 598; p.data["r16"] = 1531;
points[337]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 147; p.county = 0; p.val = 2505; p.data["black"] = 1860; p.data["white"] = 335; p.data["r"] = 224; p.data["d"] = 459; p.data["d16"] = 519; p.data["r16"] = 586;
points[338]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 62; p.county = 0; p.val = 1305; p.data["black"] = 1130; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[339]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 65; p.county = 0; p.val = 620; p.data["black"] = 310; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[340]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 65; p.county = 0; p.val = 640; p.data["black"] = 110; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[341]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 66; p.county = 0; p.val = 1215; p.data["black"] = 440; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[342]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 28; p.county = 0; p.val = 2600; p.data["black"] = 725; p.data["white"] = 1730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[343]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 17; p.county = 0; p.val = 1105; p.data["black"] = 65; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[344]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 20; p.county = 0; p.val = 1805; p.data["black"] = 165; p.data["white"] = 1475; p.data["r"] = 499; p.data["d"] = 1127; p.data["d16"] = 0; p.data["r16"] = 0;
points[345]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 31; p.county = 0; p.val = 1385; p.data["black"] = 185; p.data["white"] = 1200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[346]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 4; p.county = 0; p.val = 1060; p.data["black"] = 95; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[347]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 9; p.county = 0; p.val = 2280; p.data["black"] = 140; p.data["white"] = 2060; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[348]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 8; p.county = 0; p.val = 2665; p.data["black"] = 140; p.data["white"] = 2450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[349]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 19; p.county = 0; p.val = 1125; p.data["black"] = 160; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[350]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 7; p.county = 0; p.val = 1435; p.data["black"] = 0; p.data["white"] = 1375; p.data["r"] = 167; p.data["d"] = 760; p.data["d16"] = 139; p.data["r16"] = 976;
points[351]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 17; p.county = 0; p.val = 920; p.data["black"] = 410; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 398; p.data["r16"] = 456;
points[352]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 18; p.county = 0; p.val = 845; p.data["black"] = 85; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[353]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 28; p.county = 0; p.val = 700; p.data["black"] = 425; p.data["white"] = 230; p.data["r"] = 239; p.data["d"] = 188; p.data["d16"] = 354; p.data["r16"] = 259;
points[354]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 15; p.county = 0; p.val = 1675; p.data["black"] = 249; p.data["white"] = 1375; p.data["r"] = 567; p.data["d"] = 83; p.data["d16"] = 0; p.data["r16"] = 0;
points[355]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 16; p.county = 0; p.val = 2710; p.data["black"] = 1840; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 785; p.data["r16"] = 26;
points[356]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 16; p.county = 0; p.val = 2560; p.data["black"] = 1850; p.data["white"] = 680; p.data["r"] = 1148; p.data["d"] = 289; p.data["d16"] = 630; p.data["r16"] = 318;
points[357]=p;}
if (1==1){ Point p;
p.x = 191; p.y = 90; p.county = 0; p.val = 765; p.data["black"] = 4; p.data["white"] = 750; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[358]=p;}
if (1==1){ Point p;
p.x = 189; p.y = 93; p.county = 0; p.val = 1900; p.data["black"] = 19; p.data["white"] = 1725; p.data["r"] = 616; p.data["d"] = 778; p.data["d16"] = 0; p.data["r16"] = 0;
points[359]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 96; p.county = 0; p.val = 4805; p.data["black"] = 540; p.data["white"] = 3850; p.data["r"] = 462; p.data["d"] = 887; p.data["d16"] = 0; p.data["r16"] = 0;
points[360]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 30; p.county = 0; p.val = 860; p.data["black"] = 335; p.data["white"] = 520; p.data["r"] = 527; p.data["d"] = 562; p.data["d16"] = 644; p.data["r16"] = 770;
points[361]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 32; p.county = 0; p.val = 1205; p.data["black"] = 670; p.data["white"] = 525; p.data["r"] = 206; p.data["d"] = 346; p.data["d16"] = 447; p.data["r16"] = 344;
points[362]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 31; p.county = 0; p.val = 1135; p.data["black"] = 800; p.data["white"] = 335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[363]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 25; p.county = 0; p.val = 1390; p.data["black"] = 245; p.data["white"] = 1000; p.data["r"] = 93; p.data["d"] = 295; p.data["d16"] = 136; p.data["r16"] = 436;
points[364]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 26; p.county = 0; p.val = 1420; p.data["black"] = 150; p.data["white"] = 1270; p.data["r"] = 68; p.data["d"] = 169; p.data["d16"] = 70; p.data["r16"] = 247;
points[365]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 64; p.county = 0; p.val = 2135; p.data["black"] = 1230; p.data["white"] = 840; p.data["r"] = 497; p.data["d"] = 22; p.data["d16"] = 0; p.data["r16"] = 0;
points[366]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 62; p.county = 0; p.val = 1735; p.data["black"] = 1735; p.data["white"] = 0; p.data["r"] = 598; p.data["d"] = 23; p.data["d16"] = 0; p.data["r16"] = 0;
points[367]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 94; p.county = 0; p.val = 1175; p.data["black"] = 190; p.data["white"] = 975; p.data["r"] = 287; p.data["d"] = 406; p.data["d16"] = 378; p.data["r16"] = 615;
points[368]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 17; p.county = 0; p.val = 2005; p.data["black"] = 1205; p.data["white"] = 665; p.data["r"] = 624; p.data["d"] = 499; p.data["d16"] = 662; p.data["r16"] = 662;
points[369]=p;}
if (1==1){ Point p;
p.x = 188; p.y = 93; p.county = 0; p.val = 1465; p.data["black"] = 70; p.data["white"] = 1325; p.data["r"] = 460; p.data["d"] = 766; p.data["d16"] = 0; p.data["r16"] = 0;
points[370]=p;}
if (1==1){ Point p;
p.x = 189; p.y = 94; p.county = 0; p.val = 680; p.data["black"] = 4; p.data["white"] = 665; p.data["r"] = 636; p.data["d"] = 1120; p.data["d16"] = 920; p.data["r16"] = 1919;
points[371]=p;}
if (1==1){ Point p;
p.x = 188; p.y = 94; p.county = 0; p.val = 1360; p.data["black"] = 90; p.data["white"] = 1030; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[372]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 185; p.county = 0; p.val = 7680; p.data["black"] = 175; p.data["white"] = 7350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 589; p.data["r16"] = 970;
points[373]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 186; p.county = 0; p.val = 465; p.data["black"] = 0; p.data["white"] = 390; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[374]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 185; p.county = 0; p.val = 4550; p.data["black"] = 140; p.data["white"] = 4310; p.data["r"] = 946; p.data["d"] = 1342; p.data["d16"] = 724; p.data["r16"] = 1010;
points[375]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 192; p.county = 0; p.val = 280; p.data["black"] = 0; p.data["white"] = 275; p.data["r"] = 1473; p.data["d"] = 1602; p.data["d16"] = 1306; p.data["r16"] = 1870;
points[376]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 190; p.county = 0; p.val = 1580; p.data["black"] = 60; p.data["white"] = 1425; p.data["r"] = 2046; p.data["d"] = 3079; p.data["d16"] = 2075; p.data["r16"] = 3702;
points[377]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 7; p.county = 0; p.val = 995; p.data["black"] = 55; p.data["white"] = 865; p.data["r"] = 1078; p.data["d"] = 1467; p.data["d16"] = 689; p.data["r16"] = 1052;
points[378]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 8; p.county = 0; p.val = 3245; p.data["black"] = 190; p.data["white"] = 2865; p.data["r"] = 2603; p.data["d"] = 3491; p.data["d16"] = 2732; p.data["r16"] = 4455;
points[379]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 5; p.county = 0; p.val = 1360; p.data["black"] = 80; p.data["white"] = 1165; p.data["r"] = 420; p.data["d"] = 1286; p.data["d16"] = 638; p.data["r16"] = 1956;
points[380]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 3; p.county = 0; p.val = 2115; p.data["black"] = 145; p.data["white"] = 1895; p.data["r"] = 151; p.data["d"] = 611; p.data["d16"] = 393; p.data["r16"] = 1403;
points[381]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 11; p.county = 0; p.val = 1240; p.data["black"] = 45; p.data["white"] = 1195; p.data["r"] = 656; p.data["d"] = 1103; p.data["d16"] = 697; p.data["r16"] = 1413;
points[382]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 13; p.county = 0; p.val = 2155; p.data["black"] = 235; p.data["white"] = 1910; p.data["r"] = 261; p.data["d"] = 845; p.data["d16"] = 295; p.data["r16"] = 1051;
points[383]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 12; p.county = 0; p.val = 1300; p.data["black"] = 870; p.data["white"] = 430; p.data["r"] = 450; p.data["d"] = 371; p.data["d16"] = 570; p.data["r16"] = 404;
points[384]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 10; p.county = 0; p.val = 2210; p.data["black"] = 40; p.data["white"] = 2150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[385]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 101; p.county = 0; p.val = 560; p.data["black"] = 0; p.data["white"] = 540; p.data["r"] = 409; p.data["d"] = 934; p.data["d16"] = 206; p.data["r16"] = 543;
points[386]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 101; p.county = 0; p.val = 2050; p.data["black"] = 10; p.data["white"] = 1970; p.data["r"] = 349; p.data["d"] = 908; p.data["d16"] = 0; p.data["r16"] = 0;
points[387]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 102; p.county = 0; p.val = 1205; p.data["black"] = 10; p.data["white"] = 1195; p.data["r"] = 644; p.data["d"] = 1236; p.data["d16"] = 412; p.data["r16"] = 999;
points[388]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 72; p.county = 0; p.val = 2895; p.data["black"] = 415; p.data["white"] = 2340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 963; p.data["r16"] = 111;
points[389]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 86; p.county = 0; p.val = 600; p.data["black"] = 15; p.data["white"] = 585; p.data["r"] = 177; p.data["d"] = 560; p.data["d16"] = 189; p.data["r16"] = 732;
points[390]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 76; p.county = 0; p.val = 3440; p.data["black"] = 150; p.data["white"] = 3140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[391]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 82; p.county = 0; p.val = 5170; p.data["black"] = 710; p.data["white"] = 3945; p.data["r"] = 361; p.data["d"] = 609; p.data["d16"] = 824; p.data["r16"] = 2258;
points[392]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 81; p.county = 0; p.val = 825; p.data["black"] = 75; p.data["white"] = 680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 666; p.data["r16"] = 425;
points[393]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 82; p.county = 0; p.val = 2205; p.data["black"] = 4; p.data["white"] = 2130; p.data["r"] = 188; p.data["d"] = 564; p.data["d16"] = 189; p.data["r16"] = 1163;
points[394]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 77; p.county = 0; p.val = 2130; p.data["black"] = 180; p.data["white"] = 1810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 447; p.data["r16"] = 1192;
points[395]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 40; p.county = 0; p.val = 1055; p.data["black"] = 755; p.data["white"] = 220; p.data["r"] = 504; p.data["d"] = 146; p.data["d16"] = 950; p.data["r16"] = 601;
points[396]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 65; p.county = 0; p.val = 1585; p.data["black"] = 825; p.data["white"] = 750; p.data["r"] = 382; p.data["d"] = 212; p.data["d16"] = 571; p.data["r16"] = 301;
points[397]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 15; p.county = 0; p.val = 1500; p.data["black"] = 780; p.data["white"] = 660; p.data["r"] = 623; p.data["d"] = 151; p.data["d16"] = 820; p.data["r16"] = 243;
points[398]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 85; p.county = 0; p.val = 1445; p.data["black"] = 755; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[399]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 83; p.county = 0; p.val = 1165; p.data["black"] = 230; p.data["white"] = 855; p.data["r"] = 390; p.data["d"] = 668; p.data["d16"] = 0; p.data["r16"] = 0;
points[400]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 74; p.county = 0; p.val = 4830; p.data["black"] = 405; p.data["white"] = 4145; p.data["r"] = 550; p.data["d"] = 978; p.data["d16"] = 0; p.data["r16"] = 0;
points[401]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 76; p.county = 0; p.val = 2230; p.data["black"] = 160; p.data["white"] = 1820; p.data["r"] = 808; p.data["d"] = 1494; p.data["d16"] = 282; p.data["r16"] = 580;
points[402]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 90; p.county = 0; p.val = 1400; p.data["black"] = 335; p.data["white"] = 1055; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[403]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 75; p.county = 0; p.val = 2905; p.data["black"] = 70; p.data["white"] = 2695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 433; p.data["r16"] = 1108;
points[404]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 78; p.county = 0; p.val = 2380; p.data["black"] = 785; p.data["white"] = 1465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 586; p.data["r16"] = 1323;
points[405]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 79; p.county = 0; p.val = 1915; p.data["black"] = 15; p.data["white"] = 1810; p.data["r"] = 612; p.data["d"] = 1128; p.data["d16"] = 519; p.data["r16"] = 1663;
points[406]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 94; p.county = 0; p.val = 805; p.data["black"] = 305; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[407]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 88; p.county = 0; p.val = 1950; p.data["black"] = 210; p.data["white"] = 1640; p.data["r"] = 226; p.data["d"] = 435; p.data["d16"] = 316; p.data["r16"] = 747;
points[408]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 87; p.county = 0; p.val = 1520; p.data["black"] = 245; p.data["white"] = 1230; p.data["r"] = 259; p.data["d"] = 470; p.data["d16"] = 147; p.data["r16"] = 712;
points[409]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 91; p.county = 0; p.val = 890; p.data["black"] = 10; p.data["white"] = 865; p.data["r"] = 280; p.data["d"] = 563; p.data["d16"] = 326; p.data["r16"] = 896;
points[410]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 92; p.county = 0; p.val = 1895; p.data["black"] = 50; p.data["white"] = 1640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 187; p.data["r16"] = 800;
points[411]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 88; p.county = 0; p.val = 1950; p.data["black"] = 165; p.data["white"] = 1675; p.data["r"] = 267; p.data["d"] = 1060; p.data["d16"] = 123; p.data["r16"] = 762;
points[412]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 84; p.county = 0; p.val = 1415; p.data["black"] = 185; p.data["white"] = 1175; p.data["r"] = 185; p.data["d"] = 791; p.data["d16"] = 205; p.data["r16"] = 1097;
points[413]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 16; p.county = 0; p.val = 1995; p.data["black"] = 900; p.data["white"] = 1005; p.data["r"] = 526; p.data["d"] = 405; p.data["d16"] = 653; p.data["r16"] = 456;
points[414]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 79; p.county = 0; p.val = 1370; p.data["black"] = 200; p.data["white"] = 1130; p.data["r"] = 534; p.data["d"] = 1007; p.data["d16"] = 356; p.data["r16"] = 647;
points[415]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 85; p.county = 0; p.val = 1790; p.data["black"] = 50; p.data["white"] = 1730; p.data["r"] = 270; p.data["d"] = 858; p.data["d16"] = 345; p.data["r16"] = 1837;
points[416]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 77; p.county = 0; p.val = 2460; p.data["black"] = 240; p.data["white"] = 2060; p.data["r"] = 422; p.data["d"] = 516; p.data["d16"] = 351; p.data["r16"] = 667;
points[417]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 75; p.county = 0; p.val = 3290; p.data["black"] = 125; p.data["white"] = 2980; p.data["r"] = 471; p.data["d"] = 956; p.data["d16"] = 413; p.data["r16"] = 1281;
points[418]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 85; p.county = 0; p.val = 1180; p.data["black"] = 25; p.data["white"] = 1125; p.data["r"] = 211; p.data["d"] = 533; p.data["d16"] = 198; p.data["r16"] = 716;
points[419]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 83; p.county = 0; p.val = 4680; p.data["black"] = 1200; p.data["white"] = 3345; p.data["r"] = 688; p.data["d"] = 623; p.data["d16"] = 942; p.data["r16"] = 1681;
points[420]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 84; p.county = 0; p.val = 1015; p.data["black"] = 135; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[421]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 68; p.county = 0; p.val = 1470; p.data["black"] = 0; p.data["white"] = 1425; p.data["r"] = 180; p.data["d"] = 844; p.data["d16"] = 155; p.data["r16"] = 1029;
points[422]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 79; p.county = 0; p.val = 3415; p.data["black"] = 150; p.data["white"] = 3160; p.data["r"] = 547; p.data["d"] = 1135; p.data["d16"] = 407; p.data["r16"] = 1359;
points[423]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 81; p.county = 0; p.val = 925; p.data["black"] = 45; p.data["white"] = 845; p.data["r"] = 219; p.data["d"] = 897; p.data["d16"] = 0; p.data["r16"] = 0;
points[424]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 72; p.county = 0; p.val = 1955; p.data["black"] = 150; p.data["white"] = 1730; p.data["r"] = 442; p.data["d"] = 473; p.data["d16"] = 963; p.data["r16"] = 1351;
points[425]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 76; p.county = 0; p.val = 1625; p.data["black"] = 0; p.data["white"] = 1605; p.data["r"] = 260; p.data["d"] = 1026; p.data["d16"] = 258; p.data["r16"] = 1300;
points[426]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 86; p.county = 0; p.val = 2645; p.data["black"] = 215; p.data["white"] = 2295; p.data["r"] = 162; p.data["d"] = 335; p.data["d16"] = 502; p.data["r16"] = 1160;
points[427]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 82; p.county = 0; p.val = 1720; p.data["black"] = 65; p.data["white"] = 1580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 220; p.data["r16"] = 597;
points[428]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 92; p.county = 0; p.val = 275; p.data["black"] = 105; p.data["white"] = 155; p.data["r"] = 337; p.data["d"] = 354; p.data["d16"] = 397; p.data["r16"] = 523;
points[429]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 92; p.county = 0; p.val = 1230; p.data["black"] = 360; p.data["white"] = 860; p.data["r"] = 200; p.data["d"] = 335; p.data["d16"] = 200; p.data["r16"] = 446;
points[430]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 83; p.county = 0; p.val = 2555; p.data["black"] = 295; p.data["white"] = 2220; p.data["r"] = 301; p.data["d"] = 596; p.data["d16"] = 228; p.data["r16"] = 954;
points[431]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 65; p.county = 0; p.val = 1380; p.data["black"] = 0; p.data["white"] = 1330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 300; p.data["r16"] = 1251;
points[432]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 82; p.county = 0; p.val = 1590; p.data["black"] = 1235; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[433]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 143; p.county = 0; p.val = 875; p.data["black"] = 285; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 35; p.data["r16"] = 22;
points[434]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 93; p.county = 0; p.val = 4445; p.data["black"] = 295; p.data["white"] = 3800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 328; p.data["r16"] = 843;
points[435]=p;}
if (1==1){ Point p;
p.x = 192; p.y = 90; p.county = 0; p.val = 855; p.data["black"] = 4; p.data["white"] = 825; p.data["r"] = 884; p.data["d"] = 1947; p.data["d16"] = 238; p.data["r16"] = 432;
points[436]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 5; p.county = 0; p.val = 545; p.data["black"] = 50; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[437]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 63; p.county = 0; p.val = 1800; p.data["black"] = 1165; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[438]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 62; p.county = 0; p.val = 930; p.data["black"] = 900; p.data["white"] = 25; p.data["r"] = 896; p.data["d"] = 7; p.data["d16"] = 1953; p.data["r16"] = 54;
points[439]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 64; p.county = 0; p.val = 3355; p.data["black"] = 240; p.data["white"] = 3035; p.data["r"] = 400; p.data["d"] = 407; p.data["d16"] = 838; p.data["r16"] = 218;
points[440]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 16; p.county = 0; p.val = 940; p.data["black"] = 40; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[441]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 14; p.county = 0; p.val = 755; p.data["black"] = 130; p.data["white"] = 615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 628; p.data["r16"] = 716;
points[442]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 13; p.county = 0; p.val = 1860; p.data["black"] = 665; p.data["white"] = 1045; p.data["r"] = 811; p.data["d"] = 800; p.data["d16"] = 1108; p.data["r16"] = 1394;
points[443]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 15; p.county = 0; p.val = 2860; p.data["black"] = 120; p.data["white"] = 2705; p.data["r"] = 326; p.data["d"] = 540; p.data["d16"] = 315; p.data["r16"] = 525;
points[444]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 14; p.county = 0; p.val = 2315; p.data["black"] = 450; p.data["white"] = 1730; p.data["r"] = 957; p.data["d"] = 1201; p.data["d16"] = 0; p.data["r16"] = 0;
points[445]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 154; p.county = 0; p.val = 1555; p.data["black"] = 1220; p.data["white"] = 275; p.data["r"] = 47; p.data["d"] = 97; p.data["d16"] = 49; p.data["r16"] = 124;
points[446]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 144; p.county = 0; p.val = 590; p.data["black"] = 25; p.data["white"] = 565; p.data["r"] = 26; p.data["d"] = 22; p.data["d16"] = 0; p.data["r16"] = 0;
points[447]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 155; p.county = 0; p.val = 830; p.data["black"] = 165; p.data["white"] = 665; p.data["r"] = 42; p.data["d"] = 177; p.data["d16"] = 46; p.data["r16"] = 247;
points[448]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 149; p.county = 0; p.val = 810; p.data["black"] = 515; p.data["white"] = 275; p.data["r"] = 203; p.data["d"] = 22; p.data["d16"] = 0; p.data["r16"] = 0;
points[449]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 163; p.county = 0; p.val = 470; p.data["black"] = 360; p.data["white"] = 110; p.data["r"] = 194; p.data["d"] = 21; p.data["d16"] = 266; p.data["r16"] = 27;
points[450]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 159; p.county = 0; p.val = 915; p.data["black"] = 505; p.data["white"] = 360; p.data["r"] = 583; p.data["d"] = 289; p.data["d16"] = 650; p.data["r16"] = 372;
points[451]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 157; p.county = 0; p.val = 845; p.data["black"] = 560; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[452]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 152; p.county = 0; p.val = 425; p.data["black"] = 205; p.data["white"] = 220; p.data["r"] = 274; p.data["d"] = 161; p.data["d16"] = 325; p.data["r16"] = 253;
points[453]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 155; p.county = 0; p.val = 1915; p.data["black"] = 1385; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[454]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 88; p.county = 0; p.val = 1395; p.data["black"] = 520; p.data["white"] = 775; p.data["r"] = 294; p.data["d"] = 340; p.data["d16"] = 406; p.data["r16"] = 424;
points[455]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 149; p.county = 0; p.val = 1930; p.data["black"] = 1110; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[456]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 14; p.county = 0; p.val = 1440; p.data["black"] = 515; p.data["white"] = 785; p.data["r"] = 449; p.data["d"] = 133; p.data["d16"] = 0; p.data["r16"] = 0;
points[457]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 11; p.county = 0; p.val = 1950; p.data["black"] = 440; p.data["white"] = 1415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[458]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 12; p.county = 0; p.val = 2000; p.data["black"] = 930; p.data["white"] = 950; p.data["r"] = 429; p.data["d"] = 174; p.data["d16"] = 540; p.data["r16"] = 280;
points[459]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 13; p.county = 0; p.val = 765; p.data["black"] = 390; p.data["white"] = 310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[460]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 11; p.county = 0; p.val = 980; p.data["black"] = 100; p.data["white"] = 795; p.data["r"] = 330; p.data["d"] = 479; p.data["d16"] = 361; p.data["r16"] = 621;
points[461]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 94; p.county = 0; p.val = 1465; p.data["black"] = 680; p.data["white"] = 685; p.data["r"] = 307; p.data["d"] = 704; p.data["d16"] = 0; p.data["r16"] = 0;
points[462]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 103; p.county = 0; p.val = 3255; p.data["black"] = 340; p.data["white"] = 2850; p.data["r"] = 235; p.data["d"] = 403; p.data["d16"] = 553; p.data["r16"] = 1455;
points[463]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 100; p.county = 0; p.val = 1845; p.data["black"] = 985; p.data["white"] = 860; p.data["r"] = 359; p.data["d"] = 516; p.data["d16"] = 0; p.data["r16"] = 0;
points[464]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 106; p.county = 0; p.val = 835; p.data["black"] = 160; p.data["white"] = 655; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[465]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 94; p.county = 0; p.val = 1515; p.data["black"] = 620; p.data["white"] = 895; p.data["r"] = 332; p.data["d"] = 428; p.data["d16"] = 396; p.data["r16"] = 607;
points[466]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 99; p.county = 0; p.val = 990; p.data["black"] = 90; p.data["white"] = 855; p.data["r"] = 168; p.data["d"] = 297; p.data["d16"] = 194; p.data["r16"] = 433;
points[467]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 108; p.county = 0; p.val = 430; p.data["black"] = 25; p.data["white"] = 405; p.data["r"] = 282; p.data["d"] = 779; p.data["d16"] = 190; p.data["r16"] = 588;
points[468]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 107; p.county = 0; p.val = 2150; p.data["black"] = 290; p.data["white"] = 1755; p.data["r"] = 966; p.data["d"] = 1542; p.data["d16"] = 849; p.data["r16"] = 1430;
points[469]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 105; p.county = 0; p.val = 835; p.data["black"] = 30; p.data["white"] = 805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 339; p.data["r16"] = 46;
points[470]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 107; p.county = 0; p.val = 1415; p.data["black"] = 60; p.data["white"] = 1280; p.data["r"] = 319; p.data["d"] = 687; p.data["d16"] = 346; p.data["r16"] = 941;
points[471]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 113; p.county = 0; p.val = 490; p.data["black"] = 270; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[472]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 98; p.county = 0; p.val = 1630; p.data["black"] = 145; p.data["white"] = 1415; p.data["r"] = 188; p.data["d"] = 514; p.data["d16"] = 231; p.data["r16"] = 761;
points[473]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 99; p.county = 0; p.val = 705; p.data["black"] = 175; p.data["white"] = 480; p.data["r"] = 473; p.data["d"] = 579; p.data["d16"] = 595; p.data["r16"] = 757;
points[474]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 101; p.county = 0; p.val = 1205; p.data["black"] = 1050; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[475]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 116; p.county = 0; p.val = 930; p.data["black"] = 140; p.data["white"] = 760; p.data["r"] = 181; p.data["d"] = 335; p.data["d16"] = 237; p.data["r16"] = 463;
points[476]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 111; p.county = 0; p.val = 855; p.data["black"] = 260; p.data["white"] = 525; p.data["r"] = 225; p.data["d"] = 208; p.data["d16"] = 257; p.data["r16"] = 309;
points[477]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 100; p.county = 0; p.val = 1050; p.data["black"] = 210; p.data["white"] = 840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[478]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 106; p.county = 0; p.val = 1805; p.data["black"] = 260; p.data["white"] = 1485; p.data["r"] = 289; p.data["d"] = 439; p.data["d16"] = 365; p.data["r16"] = 276;
points[479]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 106; p.county = 0; p.val = 1045; p.data["black"] = 325; p.data["white"] = 665; p.data["r"] = 377; p.data["d"] = 215; p.data["d16"] = 0; p.data["r16"] = 0;
points[480]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 107; p.county = 0; p.val = 2335; p.data["black"] = 145; p.data["white"] = 2190; p.data["r"] = 499; p.data["d"] = 1189; p.data["d16"] = 1203; p.data["r16"] = 2910;
points[481]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 106; p.county = 0; p.val = 1780; p.data["black"] = 375; p.data["white"] = 1405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 297; p.data["r16"] = 540;
points[482]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 102; p.county = 0; p.val = 1720; p.data["black"] = 655; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[483]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 134; p.county = 0; p.val = 1345; p.data["black"] = 710; p.data["white"] = 390; p.data["r"] = 206; p.data["d"] = 223; p.data["d16"] = 271; p.data["r16"] = 303;
points[484]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 103; p.county = 0; p.val = 3120; p.data["black"] = 335; p.data["white"] = 2715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 414; p.data["r16"] = 752;
points[485]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 106; p.county = 0; p.val = 1200; p.data["black"] = 105; p.data["white"] = 1090; p.data["r"] = 317; p.data["d"] = 302; p.data["d16"] = 132; p.data["r16"] = 296;
points[486]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 107; p.county = 0; p.val = 3985; p.data["black"] = 1025; p.data["white"] = 2740; p.data["r"] = 563; p.data["d"] = 1173; p.data["d16"] = 867; p.data["r16"] = 1196;
points[487]=p;}
if (1==1){ Point p;
p.x = 168; p.y = 114; p.county = 0; p.val = 1300; p.data["black"] = 770; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[488]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 114; p.county = 0; p.val = 585; p.data["black"] = 400; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[489]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 115; p.county = 0; p.val = 865; p.data["black"] = 685; p.data["white"] = 175; p.data["r"] = 184; p.data["d"] = 434; p.data["d16"] = 150; p.data["r16"] = 528;
points[490]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 118; p.county = 0; p.val = 1280; p.data["black"] = 295; p.data["white"] = 940; p.data["r"] = 586; p.data["d"] = 792; p.data["d16"] = 377; p.data["r16"] = 618;
points[491]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 111; p.county = 0; p.val = 1700; p.data["black"] = 315; p.data["white"] = 1370; p.data["r"] = 307; p.data["d"] = 100; p.data["d16"] = 201; p.data["r16"] = 802;
points[492]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 113; p.county = 0; p.val = 360; p.data["black"] = 130; p.data["white"] = 210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[493]=p;}
if (1==1){ Point p;
p.x = 168; p.y = 120; p.county = 0; p.val = 1450; p.data["black"] = 325; p.data["white"] = 1060; p.data["r"] = 104; p.data["d"] = 166; p.data["d16"] = 111; p.data["r16"] = 226;
points[494]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 30; p.county = 0; p.val = 575; p.data["black"] = 80; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[495]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 28; p.county = 0; p.val = 1435; p.data["black"] = 575; p.data["white"] = 835; p.data["r"] = 203; p.data["d"] = 716; p.data["d16"] = 86; p.data["r16"] = 409;
points[496]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 32; p.county = 0; p.val = 670; p.data["black"] = 220; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[497]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 23; p.county = 0; p.val = 1385; p.data["black"] = 215; p.data["white"] = 1150; p.data["r"] = 189; p.data["d"] = 334; p.data["d16"] = 236; p.data["r16"] = 460;
points[498]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 138; p.county = 0; p.val = 2990; p.data["black"] = 590; p.data["white"] = 2185; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[499]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 128; p.county = 0; p.val = 945; p.data["black"] = 420; p.data["white"] = 505; p.data["r"] = 380; p.data["d"] = 390; p.data["d16"] = 486; p.data["r16"] = 533;
points[500]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 122; p.county = 0; p.val = 460; p.data["black"] = 245; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[501]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 140; p.county = 0; p.val = 3065; p.data["black"] = 805; p.data["white"] = 2095; p.data["r"] = 219; p.data["d"] = 339; p.data["d16"] = 204; p.data["r16"] = 351;
points[502]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 142; p.county = 0; p.val = 6590; p.data["black"] = 590; p.data["white"] = 5600; p.data["r"] = 1693; p.data["d"] = 2577; p.data["d16"] = 1681; p.data["r16"] = 3411;
points[503]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 131; p.county = 0; p.val = 945; p.data["black"] = 615; p.data["white"] = 315; p.data["r"] = 265; p.data["d"] = 265; p.data["d16"] = 299; p.data["r16"] = 363;
points[504]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 141; p.county = 0; p.val = 2030; p.data["black"] = 245; p.data["white"] = 1690; p.data["r"] = 986; p.data["d"] = 1720; p.data["d16"] = 935; p.data["r16"] = 2101;
points[505]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 135; p.county = 0; p.val = 1410; p.data["black"] = 610; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 256; p.data["r16"] = 217;
points[506]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 124; p.county = 0; p.val = 1070; p.data["black"] = 475; p.data["white"] = 590; p.data["r"] = 358; p.data["d"] = 340; p.data["d16"] = 443; p.data["r16"] = 510;
points[507]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 125; p.county = 0; p.val = 705; p.data["black"] = 520; p.data["white"] = 145; p.data["r"] = 178; p.data["d"] = 87; p.data["d16"] = 237; p.data["r16"] = 122;
points[508]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 127; p.county = 0; p.val = 1065; p.data["black"] = 295; p.data["white"] = 705; p.data["r"] = 260; p.data["d"] = 337; p.data["d16"] = 336; p.data["r16"] = 426;
points[509]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 133; p.county = 0; p.val = 1300; p.data["black"] = 525; p.data["white"] = 765; p.data["r"] = 230; p.data["d"] = 346; p.data["d16"] = 293; p.data["r16"] = 450;
points[510]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 70; p.county = 0; p.val = 855; p.data["black"] = 40; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 420; p.data["r16"] = 1717;
points[511]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 139; p.county = 0; p.val = 2885; p.data["black"] = 295; p.data["white"] = 2480; p.data["r"] = 493; p.data["d"] = 180; p.data["d16"] = 514; p.data["r16"] = 171;
points[512]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 147; p.county = 0; p.val = 670; p.data["black"] = 335; p.data["white"] = 325; p.data["r"] = 649; p.data["d"] = 701; p.data["d16"] = 652; p.data["r16"] = 791;
points[513]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 139; p.county = 0; p.val = 3845; p.data["black"] = 520; p.data["white"] = 2680; p.data["r"] = 808; p.data["d"] = 778; p.data["d16"] = 1284; p.data["r16"] = 1563;
points[514]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 135; p.county = 0; p.val = 2845; p.data["black"] = 615; p.data["white"] = 2005; p.data["r"] = 484; p.data["d"] = 709; p.data["d16"] = 522; p.data["r16"] = 993;
points[515]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 138; p.county = 0; p.val = 4320; p.data["black"] = 465; p.data["white"] = 3395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[516]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 126; p.county = 0; p.val = 1520; p.data["black"] = 850; p.data["white"] = 650; p.data["r"] = 201; p.data["d"] = 310; p.data["d16"] = 210; p.data["r16"] = 389;
points[517]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 128; p.county = 0; p.val = 1370; p.data["black"] = 580; p.data["white"] = 695; p.data["r"] = 267; p.data["d"] = 565; p.data["d16"] = 293; p.data["r16"] = 921;
points[518]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 142; p.county = 0; p.val = 1635; p.data["black"] = 120; p.data["white"] = 1155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[519]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 146; p.county = 0; p.val = 1735; p.data["black"] = 35; p.data["white"] = 1480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 434; p.data["r16"] = 1011;
points[520]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 132; p.county = 0; p.val = 1975; p.data["black"] = 1035; p.data["white"] = 760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[521]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 52; p.county = 0; p.val = 475; p.data["black"] = 135; p.data["white"] = 335; p.data["r"] = 78; p.data["d"] = 188; p.data["d16"] = 108; p.data["r16"] = 258;
points[522]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 62; p.county = 0; p.val = 1095; p.data["black"] = 170; p.data["white"] = 895; p.data["r"] = 35; p.data["d"] = 57; p.data["d16"] = 372; p.data["r16"] = 1019;
points[523]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 64; p.county = 0; p.val = 500; p.data["black"] = 110; p.data["white"] = 395; p.data["r"] = 310; p.data["d"] = 862; p.data["d16"] = 89; p.data["r16"] = 530;
points[524]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 67; p.county = 0; p.val = 940; p.data["black"] = 170; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[525]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 69; p.county = 0; p.val = 1025; p.data["black"] = 0; p.data["white"] = 975; p.data["r"] = 200; p.data["d"] = 632; p.data["d16"] = 191; p.data["r16"] = 791;
points[526]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 63; p.county = 0; p.val = 1315; p.data["black"] = 440; p.data["white"] = 795; p.data["r"] = 202; p.data["d"] = 319; p.data["d16"] = 305; p.data["r16"] = 406;
points[527]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 61; p.county = 0; p.val = 1345; p.data["black"] = 450; p.data["white"] = 875; p.data["r"] = 191; p.data["d"] = 249; p.data["d16"] = 0; p.data["r16"] = 0;
points[528]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 55; p.county = 0; p.val = 1285; p.data["black"] = 725; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 110; p.data["r16"] = 248;
points[529]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 59; p.county = 0; p.val = 1040; p.data["black"] = 525; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 129; p.data["r16"] = 253;
points[530]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 58; p.county = 0; p.val = 1090; p.data["black"] = 880; p.data["white"] = 170; p.data["r"] = 718; p.data["d"] = 196; p.data["d16"] = 1456; p.data["r16"] = 667;
points[531]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 189; p.county = 0; p.val = 1090; p.data["black"] = 120; p.data["white"] = 915; p.data["r"] = 645; p.data["d"] = 1177; p.data["d16"] = 684; p.data["r16"] = 1164;
points[532]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 181; p.county = 0; p.val = 3290; p.data["black"] = 285; p.data["white"] = 2155; p.data["r"] = 1029; p.data["d"] = 1130; p.data["d16"] = 1101; p.data["r16"] = 1280;
points[533]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 184; p.county = 0; p.val = 1845; p.data["black"] = 0; p.data["white"] = 1820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[534]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 182; p.county = 0; p.val = 285; p.data["black"] = 0; p.data["white"] = 285; p.data["r"] = 381; p.data["d"] = 690; p.data["d16"] = 397; p.data["r16"] = 721;
points[535]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 186; p.county = 0; p.val = 2215; p.data["black"] = 30; p.data["white"] = 1990; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[536]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 190; p.county = 0; p.val = 715; p.data["black"] = 25; p.data["white"] = 630; p.data["r"] = 606; p.data["d"] = 675; p.data["d16"] = 672; p.data["r16"] = 838;
points[537]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 196; p.county = 0; p.val = 375; p.data["black"] = 0; p.data["white"] = 375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[538]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 194; p.county = 0; p.val = 1300; p.data["black"] = 74; p.data["white"] = 1140; p.data["r"] = 580; p.data["d"] = 575; p.data["d16"] = 602; p.data["r16"] = 618;
points[539]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 189; p.county = 0; p.val = 465; p.data["black"] = 0; p.data["white"] = 460; p.data["r"] = 556; p.data["d"] = 780; p.data["d16"] = 351; p.data["r16"] = 509;
points[540]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 188; p.county = 0; p.val = 2630; p.data["black"] = 95; p.data["white"] = 2525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[541]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 188; p.county = 0; p.val = 740; p.data["black"] = 305; p.data["white"] = 250; p.data["r"] = 670; p.data["d"] = 165; p.data["d16"] = 686; p.data["r16"] = 183;
points[542]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 167; p.county = 0; p.val = 1210; p.data["black"] = 570; p.data["white"] = 610; p.data["r"] = 714; p.data["d"] = 351; p.data["d16"] = 927; p.data["r16"] = 357;
points[543]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 181; p.county = 0; p.val = 2435; p.data["black"] = 75; p.data["white"] = 2270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[544]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 172; p.county = 0; p.val = 1880; p.data["black"] = 210; p.data["white"] = 1550; p.data["r"] = 410; p.data["d"] = 208; p.data["d16"] = 495; p.data["r16"] = 236;
points[545]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 173; p.county = 0; p.val = 670; p.data["black"] = 80; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[546]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 176; p.county = 0; p.val = 1510; p.data["black"] = 595; p.data["white"] = 840; p.data["r"] = 96; p.data["d"] = 88; p.data["d16"] = 191; p.data["r16"] = 113;
points[547]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 173; p.county = 0; p.val = 285; p.data["black"] = 150; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[548]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 179; p.county = 0; p.val = 3540; p.data["black"] = 705; p.data["white"] = 2455; p.data["r"] = 822; p.data["d"] = 1192; p.data["d16"] = 788; p.data["r16"] = 1336;
points[549]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 177; p.county = 0; p.val = 1105; p.data["black"] = 140; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[550]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 66; p.county = 0; p.val = 960; p.data["black"] = 835; p.data["white"] = 115; p.data["r"] = 622; p.data["d"] = 136; p.data["d16"] = 862; p.data["r16"] = 196;
points[551]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 180; p.county = 0; p.val = 1620; p.data["black"] = 1415; p.data["white"] = 200; p.data["r"] = 1096; p.data["d"] = 809; p.data["d16"] = 1005; p.data["r16"] = 793;
points[552]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 177; p.county = 0; p.val = 2990; p.data["black"] = 1025; p.data["white"] = 1770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[553]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 183; p.county = 0; p.val = 1040; p.data["black"] = 0; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[554]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 189; p.county = 0; p.val = 395; p.data["black"] = 0; p.data["white"] = 395; p.data["r"] = 1094; p.data["d"] = 1000; p.data["d16"] = 1049; p.data["r16"] = 1256;
points[555]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 65; p.county = 0; p.val = 1960; p.data["black"] = 100; p.data["white"] = 1760; p.data["r"] = 311; p.data["d"] = 772; p.data["d16"] = 478; p.data["r16"] = 876;
points[556]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 65; p.county = 0; p.val = 1010; p.data["black"] = 310; p.data["white"] = 660; p.data["r"] = 144; p.data["d"] = 51; p.data["d16"] = 0; p.data["r16"] = 0;
points[557]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 66; p.county = 0; p.val = 3830; p.data["black"] = 1000; p.data["white"] = 2580; p.data["r"] = 948; p.data["d"] = 1229; p.data["d16"] = 558; p.data["r16"] = 646;
points[558]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 84; p.county = 0; p.val = 585; p.data["black"] = 155; p.data["white"] = 430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[559]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 84; p.county = 0; p.val = 2240; p.data["black"] = 1630; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[560]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 72; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[561]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 67; p.county = 0; p.val = 455; p.data["black"] = 395; p.data["white"] = 60; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[562]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 68; p.county = 0; p.val = 745; p.data["black"] = 520; p.data["white"] = 205; p.data["r"] = 314; p.data["d"] = 306; p.data["d16"] = 378; p.data["r16"] = 425;
points[563]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 81; p.county = 0; p.val = 925; p.data["black"] = 140; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 71; p.data["r16"] = 502;
points[564]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 76; p.county = 0; p.val = 655; p.data["black"] = 105; p.data["white"] = 535; p.data["r"] = 191; p.data["d"] = 563; p.data["d16"] = 220; p.data["r16"] = 850;
points[565]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 70; p.county = 0; p.val = 830; p.data["black"] = 325; p.data["white"] = 460; p.data["r"] = 204; p.data["d"] = 276; p.data["d16"] = 270; p.data["r16"] = 366;
points[566]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 73; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[567]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 73; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 253; p.data["r16"] = 1198;
points[568]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 64; p.county = 0; p.val = 2245; p.data["black"] = 1720; p.data["white"] = 495; p.data["r"] = 442; p.data["d"] = 337; p.data["d16"] = 245; p.data["r16"] = 335;
points[569]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 69; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[570]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 70; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 512; p.data["d"] = 1505; p.data["d16"] = 376; p.data["r16"] = 1575;
points[571]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 70; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 342; p.data["d"] = 1033; p.data["d16"] = 228; p.data["r16"] = 1186;
points[572]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 71; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 430; p.data["d"] = 1013; p.data["d16"] = 865; p.data["r16"] = 1978;
points[573]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 72; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[574]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 51; p.county = 0; p.val = 1485; p.data["black"] = 720; p.data["white"] = 725; p.data["r"] = 302; p.data["d"] = 438; p.data["d16"] = 397; p.data["r16"] = 580;
points[575]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 61; p.county = 0; p.val = 2170; p.data["black"] = 530; p.data["white"] = 1520; p.data["r"] = 532; p.data["d"] = 509; p.data["d16"] = 441; p.data["r16"] = 284;
points[576]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 55; p.county = 0; p.val = 585; p.data["black"] = 160; p.data["white"] = 425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[577]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 73; p.county = 0; p.val = 1580; p.data["black"] = 480; p.data["white"] = 1030; p.data["r"] = 56; p.data["d"] = 91; p.data["d16"] = 61; p.data["r16"] = 112;
points[578]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 62; p.county = 0; p.val = 1260; p.data["black"] = 1005; p.data["white"] = 250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 286; p.data["r16"] = 207;
points[579]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 0; p.val = 1015; p.data["black"] = 85; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[580]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 147; p.county = 0; p.val = 580; p.data["black"] = 75; p.data["white"] = 500; p.data["r"] = 171; p.data["d"] = 161; p.data["d16"] = 202; p.data["r16"] = 253;
points[581]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 151; p.county = 0; p.val = 675; p.data["black"] = 305; p.data["white"] = 370; p.data["r"] = 681; p.data["d"] = 312; p.data["d16"] = 799; p.data["r16"] = 438;
points[582]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 159; p.county = 0; p.val = 890; p.data["black"] = 675; p.data["white"] = 200; p.data["r"] = 161; p.data["d"] = 284; p.data["d16"] = 190; p.data["r16"] = 412;
points[583]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 98; p.county = 0; p.val = 1185; p.data["black"] = 20; p.data["white"] = 1030; p.data["r"] = 359; p.data["d"] = 539; p.data["d16"] = 799; p.data["r16"] = 1544;
points[584]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 99; p.county = 0; p.val = 2650; p.data["black"] = 350; p.data["white"] = 2040; p.data["r"] = 674; p.data["d"] = 1145; p.data["d16"] = 634; p.data["r16"] = 1419;
points[585]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 94; p.county = 0; p.val = 2895; p.data["black"] = 255; p.data["white"] = 2400; p.data["r"] = 744; p.data["d"] = 1102; p.data["d16"] = 478; p.data["r16"] = 199;
points[586]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 106; p.county = 0; p.val = 1360; p.data["black"] = 370; p.data["white"] = 870; p.data["r"] = 414; p.data["d"] = 799; p.data["d16"] = 392; p.data["r16"] = 944;
points[587]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 102; p.county = 0; p.val = 1630; p.data["black"] = 965; p.data["white"] = 660; p.data["r"] = 387; p.data["d"] = 578; p.data["d16"] = 519; p.data["r16"] = 1038;
points[588]=p;}
if (1==1){ Point p;
p.x = 194; p.y = 88; p.county = 0; p.val = 2020; p.data["black"] = 235; p.data["white"] = 1740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[589]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 66; p.county = 0; p.val = 1580; p.data["black"] = 150; p.data["white"] = 1410; p.data["r"] = 339; p.data["d"] = 772; p.data["d16"] = 299; p.data["r16"] = 914;
points[590]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 67; p.county = 0; p.val = 2025; p.data["black"] = 1055; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1080; p.data["r16"] = 1062;
points[591]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 68; p.county = 0; p.val = 1835; p.data["black"] = 815; p.data["white"] = 935; p.data["r"] = 755; p.data["d"] = 190; p.data["d16"] = 873; p.data["r16"] = 205;
points[592]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 67; p.county = 0; p.val = 1130; p.data["black"] = 795; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[593]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 67; p.county = 0; p.val = 1725; p.data["black"] = 805; p.data["white"] = 820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[594]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 62; p.county = 0; p.val = 1385; p.data["black"] = 365; p.data["white"] = 990; p.data["r"] = 740; p.data["d"] = 1173; p.data["d16"] = 424; p.data["r16"] = 788;
points[595]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 66; p.county = 0; p.val = 615; p.data["black"] = 310; p.data["white"] = 260; p.data["r"] = 208; p.data["d"] = 204; p.data["d16"] = 292; p.data["r16"] = 239;
points[596]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 15; p.county = 0; p.val = 1075; p.data["black"] = 95; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[597]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 16; p.county = 0; p.val = 1190; p.data["black"] = 280; p.data["white"] = 780; p.data["r"] = 250; p.data["d"] = 207; p.data["d16"] = 310; p.data["r16"] = 316;
points[598]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 15; p.county = 0; p.val = 2225; p.data["black"] = 245; p.data["white"] = 1930; p.data["r"] = 522; p.data["d"] = 93; p.data["d16"] = 694; p.data["r16"] = 122;
points[599]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 16; p.county = 0; p.val = 2405; p.data["black"] = 1305; p.data["white"] = 850; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[600]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 30; p.county = 0; p.val = 340; p.data["black"] = 45; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[601]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 19; p.county = 0; p.val = 835; p.data["black"] = 280; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[602]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 14; p.county = 0; p.val = 840; p.data["black"] = 4; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[603]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 5; p.county = 0; p.val = 955; p.data["black"] = 0; p.data["white"] = 955; p.data["r"] = 458; p.data["d"] = 1677; p.data["d16"] = 385; p.data["r16"] = 2159;
points[604]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 3; p.county = 0; p.val = 925; p.data["black"] = 35; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[605]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 2; p.county = 0; p.val = 1300; p.data["black"] = 15; p.data["white"] = 1250; p.data["r"] = 316; p.data["d"] = 1055; p.data["d16"] = 303; p.data["r16"] = 1353;
points[606]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 4; p.county = 0; p.val = 1090; p.data["black"] = 15; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[607]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 17; p.county = 0; p.val = 1455; p.data["black"] = 255; p.data["white"] = 1145; p.data["r"] = 386; p.data["d"] = 746; p.data["d16"] = 448; p.data["r16"] = 1104;
points[608]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 10; p.county = 0; p.val = 1440; p.data["black"] = 190; p.data["white"] = 1125; p.data["r"] = 312; p.data["d"] = 454; p.data["d16"] = 299; p.data["r16"] = 619;
points[609]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 13; p.county = 0; p.val = 1260; p.data["black"] = 460; p.data["white"] = 750; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[610]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 14; p.county = 0; p.val = 1360; p.data["black"] = 455; p.data["white"] = 815; p.data["r"] = 393; p.data["d"] = 697; p.data["d16"] = 439; p.data["r16"] = 600;
points[611]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 13; p.county = 0; p.val = 1260; p.data["black"] = 320; p.data["white"] = 830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[612]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 13; p.county = 0; p.val = 595; p.data["black"] = 0; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 298; p.data["r16"] = 262;
points[613]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 18; p.county = 0; p.val = 2340; p.data["black"] = 905; p.data["white"] = 1295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[614]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 19; p.county = 0; p.val = 1660; p.data["black"] = 1015; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 794; p.data["r16"] = 826;
points[615]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 18; p.county = 0; p.val = 960; p.data["black"] = 185; p.data["white"] = 755; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[616]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 19; p.county = 0; p.val = 1365; p.data["black"] = 170; p.data["white"] = 1115; p.data["r"] = 207; p.data["d"] = 349; p.data["d16"] = 229; p.data["r16"] = 499;
points[617]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 84; p.county = 0; p.val = 1320; p.data["black"] = 210; p.data["white"] = 1070; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[618]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 58; p.county = 0; p.val = 1135; p.data["black"] = 345; p.data["white"] = 745; p.data["r"] = 109; p.data["d"] = 230; p.data["d16"] = 740; p.data["r16"] = 575;
points[619]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 52; p.county = 0; p.val = 1250; p.data["black"] = 745; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 411; p.data["r16"] = 98;
points[620]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 48; p.county = 0; p.val = 830; p.data["black"] = 460; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[621]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 58; p.county = 0; p.val = 920; p.data["black"] = 500; p.data["white"] = 425; p.data["r"] = 688; p.data["d"] = 47; p.data["d16"] = 850; p.data["r16"] = 50;
points[622]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 61; p.county = 0; p.val = 970; p.data["black"] = 430; p.data["white"] = 540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[623]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 50; p.county = 0; p.val = 990; p.data["black"] = 210; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[624]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 53; p.county = 0; p.val = 520; p.data["black"] = 425; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[625]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 53; p.county = 0; p.val = 730; p.data["black"] = 255; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[626]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 49; p.county = 0; p.val = 740; p.data["black"] = 50; p.data["white"] = 675; p.data["r"] = 383; p.data["d"] = 570; p.data["d16"] = 0; p.data["r16"] = 0;
points[627]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 52; p.county = 0; p.val = 1655; p.data["black"] = 200; p.data["white"] = 1435; p.data["r"] = 179; p.data["d"] = 447; p.data["d16"] = 231; p.data["r16"] = 672;
points[628]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 63; p.county = 0; p.val = 1335; p.data["black"] = 575; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[629]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 21; p.county = 0; p.val = 2875; p.data["black"] = 705; p.data["white"] = 1985; p.data["r"] = 1015; p.data["d"] = 340; p.data["d16"] = 777; p.data["r16"] = 109;
points[630]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 20; p.county = 0; p.val = 1900; p.data["black"] = 345; p.data["white"] = 1470; p.data["r"] = 179; p.data["d"] = 36; p.data["d16"] = 216; p.data["r16"] = 57;
points[631]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 19; p.county = 0; p.val = 1685; p.data["black"] = 145; p.data["white"] = 1110; p.data["r"] = 1027; p.data["d"] = 883; p.data["d16"] = 495; p.data["r16"] = 514;
points[632]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 20; p.county = 0; p.val = 2625; p.data["black"] = 1310; p.data["white"] = 1035; p.data["r"] = 1009; p.data["d"] = 456; p.data["d16"] = 954; p.data["r16"] = 559;
points[633]=p;}
if (1==1){ Point p;
p.x = 191; p.y = 91; p.county = 0; p.val = 1140; p.data["black"] = 4; p.data["white"] = 1065; p.data["r"] = 338; p.data["d"] = 805; p.data["d16"] = 787; p.data["r16"] = 2144;
points[634]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 84; p.county = 0; p.val = 775; p.data["black"] = 665; p.data["white"] = 40; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[635]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 36; p.county = 0; p.val = 520; p.data["black"] = 0; p.data["white"] = 520; p.data["r"] = 806; p.data["d"] = 759; p.data["d16"] = 0; p.data["r16"] = 0;
points[636]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 42; p.county = 0; p.val = 1125; p.data["black"] = 0; p.data["white"] = 1125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 338; p.data["r16"] = 1257;
points[637]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 40; p.county = 0; p.val = 2260; p.data["black"] = 280; p.data["white"] = 1910; p.data["r"] = 338; p.data["d"] = 553; p.data["d16"] = 429; p.data["r16"] = 705;
points[638]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 42; p.county = 0; p.val = 720; p.data["black"] = 60; p.data["white"] = 660; p.data["r"] = 231; p.data["d"] = 377; p.data["d16"] = 270; p.data["r16"] = 496;
points[639]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 107; p.county = 0; p.val = 1080; p.data["black"] = 85; p.data["white"] = 995; p.data["r"] = 374; p.data["d"] = 431; p.data["d16"] = 385; p.data["r16"] = 527;
points[640]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 106; p.county = 0; p.val = 1255; p.data["black"] = 620; p.data["white"] = 555; p.data["r"] = 255; p.data["d"] = 252; p.data["d16"] = 0; p.data["r16"] = 0;
points[641]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 113; p.county = 0; p.val = 690; p.data["black"] = 400; p.data["white"] = 245; p.data["r"] = 454; p.data["d"] = 250; p.data["d16"] = 891; p.data["r16"] = 448;
points[642]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 115; p.county = 0; p.val = 610; p.data["black"] = 445; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[643]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 103; p.county = 0; p.val = 1305; p.data["black"] = 925; p.data["white"] = 350; p.data["r"] = 696; p.data["d"] = 239; p.data["d16"] = 0; p.data["r16"] = 0;
points[644]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 102; p.county = 0; p.val = 1390; p.data["black"] = 880; p.data["white"] = 505; p.data["r"] = 369; p.data["d"] = 157; p.data["d16"] = 0; p.data["r16"] = 0;
points[645]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 105; p.county = 0; p.val = 1650; p.data["black"] = 1490; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 809; p.data["r16"] = 273;
points[646]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 112; p.county = 0; p.val = 1145; p.data["black"] = 300; p.data["white"] = 830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[647]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 108; p.county = 0; p.val = 3195; p.data["black"] = 2935; p.data["white"] = 200; p.data["r"] = 259; p.data["d"] = 53; p.data["d16"] = 835; p.data["r16"] = 5;
points[648]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 65; p.county = 0; p.val = 8520; p.data["black"] = 4250; p.data["white"] = 3545; p.data["r"] = 3453; p.data["d"] = 1203; p.data["d16"] = 1357; p.data["r16"] = 1505;
points[649]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 75; p.county = 0; p.val = 1575; p.data["black"] = 95; p.data["white"] = 1375; p.data["r"] = 647; p.data["d"] = 387; p.data["d16"] = 759; p.data["r16"] = 473;
points[650]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 66; p.county = 0; p.val = 4820; p.data["black"] = 2335; p.data["white"] = 2055; p.data["r"] = 2022; p.data["d"] = 1046; p.data["d16"] = 1114; p.data["r16"] = 695;
points[651]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 67; p.county = 0; p.val = 4925; p.data["black"] = 3035; p.data["white"] = 1705; p.data["r"] = 2573; p.data["d"] = 683; p.data["d16"] = 2074; p.data["r16"] = 494;
points[652]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 67; p.county = 0; p.val = 2290; p.data["black"] = 1315; p.data["white"] = 865; p.data["r"] = 793; p.data["d"] = 105; p.data["d16"] = 1298; p.data["r16"] = 281;
points[653]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 64; p.county = 0; p.val = 6280; p.data["black"] = 2860; p.data["white"] = 3040; p.data["r"] = 1474; p.data["d"] = 1288; p.data["d16"] = 368; p.data["r16"] = 173;
points[654]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 69; p.county = 0; p.val = 2255; p.data["black"] = 895; p.data["white"] = 875; p.data["r"] = 564; p.data["d"] = 424; p.data["d16"] = 425; p.data["r16"] = 470;
points[655]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 66; p.county = 0; p.val = 1670; p.data["black"] = 45; p.data["white"] = 1580; p.data["r"] = 326; p.data["d"] = 446; p.data["d16"] = 249; p.data["r16"] = 545;
points[656]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 68; p.county = 0; p.val = 1505; p.data["black"] = 445; p.data["white"] = 1040; p.data["r"] = 925; p.data["d"] = 884; p.data["d16"] = 456; p.data["r16"] = 507;
points[657]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 69; p.county = 0; p.val = 2395; p.data["black"] = 790; p.data["white"] = 1475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[658]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 79; p.county = 0; p.val = 2685; p.data["black"] = 1505; p.data["white"] = 940; p.data["r"] = 1872; p.data["d"] = 585; p.data["d16"] = 1986; p.data["r16"] = 725;
points[659]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 80; p.county = 0; p.val = 2100; p.data["black"] = 1725; p.data["white"] = 260; p.data["r"] = 1042; p.data["d"] = 35; p.data["d16"] = 0; p.data["r16"] = 0;
points[660]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 69; p.county = 0; p.val = 2705; p.data["black"] = 705; p.data["white"] = 1770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[661]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 66; p.county = 0; p.val = 3205; p.data["black"] = 505; p.data["white"] = 2520; p.data["r"] = 1385; p.data["d"] = 1730; p.data["d16"] = 233; p.data["r16"] = 623;
points[662]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 70; p.county = 0; p.val = 1840; p.data["black"] = 785; p.data["white"] = 780; p.data["r"] = 826; p.data["d"] = 731; p.data["d16"] = 779; p.data["r16"] = 760;
points[663]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 78; p.county = 0; p.val = 1695; p.data["black"] = 1110; p.data["white"] = 505; p.data["r"] = 827; p.data["d"] = 193; p.data["d16"] = 813; p.data["r16"] = 350;
points[664]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 128; p.county = 0; p.val = 945; p.data["black"] = 475; p.data["white"] = 455; p.data["r"] = 128; p.data["d"] = 215; p.data["d16"] = 209; p.data["r16"] = 299;
points[665]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 43; p.county = 0; p.val = 1875; p.data["black"] = 560; p.data["white"] = 1210; p.data["r"] = 131; p.data["d"] = 135; p.data["d16"] = 0; p.data["r16"] = 0;
points[666]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 44; p.county = 0; p.val = 1025; p.data["black"] = 360; p.data["white"] = 655; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[667]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 30; p.county = 0; p.val = 1730; p.data["black"] = 160; p.data["white"] = 1490; p.data["r"] = 291; p.data["d"] = 1078; p.data["d16"] = 273; p.data["r16"] = 1362;
points[668]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 140; p.county = 0; p.val = 1890; p.data["black"] = 750; p.data["white"] = 1085; p.data["r"] = 253; p.data["d"] = 344; p.data["d16"] = 248; p.data["r16"] = 387;
points[669]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 133; p.county = 0; p.val = 810; p.data["black"] = 245; p.data["white"] = 555; p.data["r"] = 231; p.data["d"] = 229; p.data["d16"] = 273; p.data["r16"] = 323;
points[670]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 137; p.county = 0; p.val = 1395; p.data["black"] = 785; p.data["white"] = 550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[671]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 128; p.county = 0; p.val = 1125; p.data["black"] = 520; p.data["white"] = 605; p.data["r"] = 284; p.data["d"] = 261; p.data["d16"] = 354; p.data["r16"] = 360;
points[672]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 29; p.county = 0; p.val = 1010; p.data["black"] = 350; p.data["white"] = 655; p.data["r"] = 154; p.data["d"] = 168; p.data["d16"] = 345; p.data["r16"] = 799;
points[673]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 49; p.county = 0; p.val = 350; p.data["black"] = 340; p.data["white"] = 15; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[674]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 88; p.county = 0; p.val = 1060; p.data["black"] = 765; p.data["white"] = 295; p.data["r"] = 432; p.data["d"] = 253; p.data["d16"] = 644; p.data["r16"] = 321;
points[675]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 95; p.county = 0; p.val = 1445; p.data["black"] = 680; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[676]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 95; p.county = 0; p.val = 1200; p.data["black"] = 565; p.data["white"] = 635; p.data["r"] = 303; p.data["d"] = 312; p.data["d16"] = 376; p.data["r16"] = 398;
points[677]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 72; p.county = 0; p.val = 2705; p.data["black"] = 2020; p.data["white"] = 535; p.data["r"] = 771; p.data["d"] = 273; p.data["d16"] = 468; p.data["r16"] = 280;
points[678]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 89; p.county = 0; p.val = 1025; p.data["black"] = 295; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[679]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 85; p.county = 0; p.val = 1080; p.data["black"] = 610; p.data["white"] = 470; p.data["r"] = 477; p.data["d"] = 379; p.data["d16"] = 758; p.data["r16"] = 626;
points[680]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 92; p.county = 0; p.val = 2530; p.data["black"] = 1335; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[681]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 87; p.county = 0; p.val = 380; p.data["black"] = 170; p.data["white"] = 185; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[682]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 88; p.county = 0; p.val = 905; p.data["black"] = 660; p.data["white"] = 245; p.data["r"] = 198; p.data["d"] = 322; p.data["d16"] = 238; p.data["r16"] = 382;
points[683]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 90; p.county = 0; p.val = 1090; p.data["black"] = 330; p.data["white"] = 740; p.data["r"] = 152; p.data["d"] = 375; p.data["d16"] = 160; p.data["r16"] = 465;
points[684]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 71; p.county = 0; p.val = 870; p.data["black"] = 645; p.data["white"] = 45; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[685]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 71; p.county = 0; p.val = 1430; p.data["black"] = 1290; p.data["white"] = 114; p.data["r"] = 641; p.data["d"] = 42; p.data["d16"] = 739; p.data["r16"] = 74;
points[686]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 71; p.county = 0; p.val = 1370; p.data["black"] = 1335; p.data["white"] = 0; p.data["r"] = 1050; p.data["d"] = 32; p.data["d16"] = 1227; p.data["r16"] = 24;
points[687]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 20; p.county = 0; p.val = 960; p.data["black"] = 50; p.data["white"] = 905; p.data["r"] = 148; p.data["d"] = 365; p.data["d16"] = 177; p.data["r16"] = 570;
points[688]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 28; p.county = 0; p.val = 840; p.data["black"] = 45; p.data["white"] = 795; p.data["r"] = 105; p.data["d"] = 309; p.data["d16"] = 292; p.data["r16"] = 766;
points[689]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 0; p.val = 700; p.data["black"] = 220; p.data["white"] = 460; p.data["r"] = 173; p.data["d"] = 307; p.data["d16"] = 205; p.data["r16"] = 401;
points[690]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 39; p.county = 0; p.val = 850; p.data["black"] = 290; p.data["white"] = 540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[691]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 0; p.val = 780; p.data["black"] = 195; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[692]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 31; p.county = 0; p.val = 180; p.data["black"] = 15; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[693]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 27; p.county = 0; p.val = 1120; p.data["black"] = 180; p.data["white"] = 905; p.data["r"] = 77; p.data["d"] = 343; p.data["d16"] = 78; p.data["r16"] = 443;
points[694]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 30; p.county = 0; p.val = 2235; p.data["black"] = 1020; p.data["white"] = 1155; p.data["r"] = 380; p.data["d"] = 163; p.data["d16"] = 415; p.data["r16"] = 166;
points[695]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 22; p.county = 0; p.val = 565; p.data["black"] = 250; p.data["white"] = 315; p.data["r"] = 224; p.data["d"] = 367; p.data["d16"] = 279; p.data["r16"] = 505;
points[696]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 31; p.county = 0; p.val = 610; p.data["black"] = 255; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 74; p.data["r16"] = 156;
points[697]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 30; p.county = 0; p.val = 1180; p.data["black"] = 465; p.data["white"] = 720; p.data["r"] = 363; p.data["d"] = 285; p.data["d16"] = 374; p.data["r16"] = 190;
points[698]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 31; p.county = 0; p.val = 955; p.data["black"] = 295; p.data["white"] = 625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 149; p.data["r16"] = 62;
points[699]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 40; p.county = 0; p.val = 575; p.data["black"] = 435; p.data["white"] = 125; p.data["r"] = 251; p.data["d"] = 36; p.data["d16"] = 335; p.data["r16"] = 38;
points[700]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 35; p.county = 0; p.val = 870; p.data["black"] = 490; p.data["white"] = 380; p.data["r"] = 249; p.data["d"] = 169; p.data["d16"] = 341; p.data["r16"] = 217;
points[701]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 28; p.county = 0; p.val = 605; p.data["black"] = 105; p.data["white"] = 500; p.data["r"] = 493; p.data["d"] = 434; p.data["d16"] = 443; p.data["r16"] = 236;
points[702]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 26; p.county = 0; p.val = 660; p.data["black"] = 50; p.data["white"] = 595; p.data["r"] = 77; p.data["d"] = 237; p.data["d16"] = 90; p.data["r16"] = 388;
points[703]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 120; p.county = 0; p.val = 2255; p.data["black"] = 55; p.data["white"] = 2140; p.data["r"] = 199; p.data["d"] = 651; p.data["d16"] = 215; p.data["r16"] = 819;
points[704]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 72; p.county = 0; p.val = 2275; p.data["black"] = 1750; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[705]=p;}
if (1==1){ Point p;
p.x = 159; p.y = 56; p.county = 0; p.val = 960; p.data["black"] = 210; p.data["white"] = 695; p.data["r"] = 154; p.data["d"] = 263; p.data["d16"] = 174; p.data["r16"] = 402;
points[706]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 57; p.county = 0; p.val = 435; p.data["black"] = 45; p.data["white"] = 360; p.data["r"] = 61; p.data["d"] = 198; p.data["d16"] = 76; p.data["r16"] = 249;
points[707]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 49; p.county = 0; p.val = 2210; p.data["black"] = 1005; p.data["white"] = 1140; p.data["r"] = 658; p.data["d"] = 884; p.data["d16"] = 838; p.data["r16"] = 416;
points[708]=p;}
if (1==1){ Point p;
p.x = 175; p.y = 53; p.county = 0; p.val = 750; p.data["black"] = 230; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 362; p.data["r16"] = 490;
points[709]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 56; p.county = 0; p.val = 690; p.data["black"] = 195; p.data["white"] = 495; p.data["r"] = 288; p.data["d"] = 366; p.data["d16"] = 0; p.data["r16"] = 0;
points[710]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 54; p.county = 0; p.val = 805; p.data["black"] = 690; p.data["white"] = 105; p.data["r"] = 604; p.data["d"] = 602; p.data["d16"] = 820; p.data["r16"] = 754;
points[711]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 131; p.county = 0; p.val = 1110; p.data["black"] = 240; p.data["white"] = 855; p.data["r"] = 221; p.data["d"] = 285; p.data["d16"] = 171; p.data["r16"] = 274;
points[712]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 139; p.county = 0; p.val = 4900; p.data["black"] = 1010; p.data["white"] = 3390; p.data["r"] = 217; p.data["d"] = 278; p.data["d16"] = 227; p.data["r16"] = 401;
points[713]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 146; p.county = 0; p.val = 2475; p.data["black"] = 1020; p.data["white"] = 1120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[714]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 51; p.county = 0; p.val = 315; p.data["black"] = 295; p.data["white"] = 20; p.data["r"] = 69; p.data["d"] = 83; p.data["d16"] = 82; p.data["r16"] = 134;
points[715]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 145; p.county = 0; p.val = 3240; p.data["black"] = 1010; p.data["white"] = 2005; p.data["r"] = 403; p.data["d"] = 511; p.data["d16"] = 558; p.data["r16"] = 942;
points[716]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 129; p.county = 0; p.val = 1890; p.data["black"] = 505; p.data["white"] = 1335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[717]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 45; p.county = 0; p.val = 660; p.data["black"] = 420; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[718]=p;}
if (1==1){ Point p;
p.x = 164; p.y = 56; p.county = 0; p.val = 1280; p.data["black"] = 1000; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[719]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 47; p.county = 0; p.val = 1325; p.data["black"] = 470; p.data["white"] = 825; p.data["r"] = 34; p.data["d"] = 57; p.data["d16"] = 45; p.data["r16"] = 98;
points[720]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 56; p.county = 0; p.val = 810; p.data["black"] = 170; p.data["white"] = 640; p.data["r"] = 136; p.data["d"] = 100; p.data["d16"] = 180; p.data["r16"] = 146;
points[721]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 55; p.county = 0; p.val = 855; p.data["black"] = 245; p.data["white"] = 590; p.data["r"] = 92; p.data["d"] = 255; p.data["d16"] = 102; p.data["r16"] = 346;
points[722]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 51; p.county = 0; p.val = 1530; p.data["black"] = 1105; p.data["white"] = 420; p.data["r"] = 598; p.data["d"] = 257; p.data["d16"] = 0; p.data["r16"] = 0;
points[723]=p;}
if (1==1){ Point p;
p.x = 164; p.y = 41; p.county = 0; p.val = 650; p.data["black"] = 325; p.data["white"] = 205; p.data["r"] = 150; p.data["d"] = 86; p.data["d16"] = 124; p.data["r16"] = 60;
points[724]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 53; p.county = 0; p.val = 885; p.data["black"] = 80; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[725]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 43; p.county = 0; p.val = 1180; p.data["black"] = 715; p.data["white"] = 420; p.data["r"] = 431; p.data["d"] = 377; p.data["d16"] = 600; p.data["r16"] = 560;
points[726]=p;}
if (1==1){ Point p;
p.x = 172; p.y = 52; p.county = 0; p.val = 465; p.data["black"] = 125; p.data["white"] = 295; p.data["r"] = 90; p.data["d"] = 155; p.data["d16"] = 0; p.data["r16"] = 0;
points[727]=p;}
if (1==1){ Point p;
p.x = 161; p.y = 51; p.county = 0; p.val = 450; p.data["black"] = 15; p.data["white"] = 415; p.data["r"] = 55; p.data["d"] = 119; p.data["d16"] = 88; p.data["r16"] = 177;
points[728]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 47; p.county = 0; p.val = 515; p.data["black"] = 370; p.data["white"] = 10; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 226; p.data["r16"] = 979;
points[729]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 49; p.county = 0; p.val = 1205; p.data["black"] = 280; p.data["white"] = 720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 52; p.data["r16"] = 112;
points[730]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 50; p.county = 0; p.val = 670; p.data["black"] = 375; p.data["white"] = 265; p.data["r"] = 485; p.data["d"] = 151; p.data["d16"] = 1597; p.data["r16"] = 362;
points[731]=p;}
if (1==1){ Point p;
p.x = 168; p.y = 48; p.county = 0; p.val = 895; p.data["black"] = 115; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[732]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 47; p.county = 0; p.val = 1080; p.data["black"] = 390; p.data["white"] = 505; p.data["r"] = 236; p.data["d"] = 99; p.data["d16"] = 315; p.data["r16"] = 173;
points[733]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 52; p.county = 0; p.val = 1760; p.data["black"] = 1150; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 73; p.data["r16"] = 124;
points[734]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 63; p.county = 0; p.val = 1760; p.data["black"] = 795; p.data["white"] = 915; p.data["r"] = 285; p.data["d"] = 161; p.data["d16"] = 0; p.data["r16"] = 0;
points[735]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 154; p.county = 0; p.val = 2475; p.data["black"] = 0; p.data["white"] = 2435; p.data["r"] = 1256; p.data["d"] = 257; p.data["d16"] = 696; p.data["r16"] = 223;
points[736]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 153; p.county = 0; p.val = 1520; p.data["black"] = 470; p.data["white"] = 1025; p.data["r"] = 674; p.data["d"] = 386; p.data["d16"] = 295; p.data["r16"] = 339;
points[737]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 144; p.county = 0; p.val = 2520; p.data["black"] = 1350; p.data["white"] = 915; p.data["r"] = 427; p.data["d"] = 823; p.data["d16"] = 364; p.data["r16"] = 1087;
points[738]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 57; p.county = 0; p.val = 585; p.data["black"] = 90; p.data["white"] = 465; p.data["r"] = 187; p.data["d"] = 565; p.data["d16"] = 229; p.data["r16"] = 697;
points[739]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 55; p.county = 0; p.val = 1850; p.data["black"] = 765; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[740]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 54; p.county = 0; p.val = 1300; p.data["black"] = 175; p.data["white"] = 1015; p.data["r"] = 98; p.data["d"] = 205; p.data["d16"] = 118; p.data["r16"] = 280;
points[741]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 59; p.county = 0; p.val = 1260; p.data["black"] = 35; p.data["white"] = 1170; p.data["r"] = 136; p.data["d"] = 364; p.data["d16"] = 0; p.data["r16"] = 0;
points[742]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 65; p.county = 0; p.val = 1540; p.data["black"] = 225; p.data["white"] = 1290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 337; p.data["r16"] = 187;
points[743]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 67; p.county = 0; p.val = 340; p.data["black"] = 65; p.data["white"] = 275; p.data["r"] = 140; p.data["d"] = 345; p.data["d16"] = 168; p.data["r16"] = 395;
points[744]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 59; p.county = 0; p.val = 1895; p.data["black"] = 495; p.data["white"] = 1295; p.data["r"] = 151; p.data["d"] = 556; p.data["d16"] = 167; p.data["r16"] = 785;
points[745]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 62; p.county = 0; p.val = 2150; p.data["black"] = 110; p.data["white"] = 2040; p.data["r"] = 144; p.data["d"] = 699; p.data["d16"] = 415; p.data["r16"] = 1286;
points[746]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 88; p.county = 0; p.val = 1595; p.data["black"] = 140; p.data["white"] = 1410; p.data["r"] = 71; p.data["d"] = 347; p.data["d16"] = 227; p.data["r16"] = 1319;
points[747]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 145; p.county = 0; p.val = 915; p.data["black"] = 650; p.data["white"] = 190; p.data["r"] = 497; p.data["d"] = 242; p.data["d16"] = 582; p.data["r16"] = 497;
points[748]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 144; p.county = 0; p.val = 1650; p.data["black"] = 1000; p.data["white"] = 515; p.data["r"] = 1308; p.data["d"] = 841; p.data["d16"] = 1876; p.data["r16"] = 1584;
points[749]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 145; p.county = 0; p.val = 2445; p.data["black"] = 1450; p.data["white"] = 775; p.data["r"] = 728; p.data["d"] = 266; p.data["d16"] = 0; p.data["r16"] = 0;
points[750]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 33; p.county = 0; p.val = 580; p.data["black"] = 110; p.data["white"] = 440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[751]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 63; p.county = 0; p.val = 3045; p.data["black"] = 695; p.data["white"] = 1955; p.data["r"] = 306; p.data["d"] = 313; p.data["d16"] = 687; p.data["r16"] = 594;
points[752]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 65; p.county = 0; p.val = 1920; p.data["black"] = 340; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[753]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 165; p.county = 0; p.val = 145; p.data["black"] = 0; p.data["white"] = 145; p.data["r"] = 485; p.data["d"] = 243; p.data["d16"] = 531; p.data["r16"] = 265;
points[754]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 147; p.county = 0; p.val = 4865; p.data["black"] = 1775; p.data["white"] = 2850; p.data["r"] = 211; p.data["d"] = 584; p.data["d16"] = 404; p.data["r16"] = 438;
points[755]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 150; p.county = 0; p.val = 4115; p.data["black"] = 2585; p.data["white"] = 1255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[756]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 155; p.county = 0; p.val = 1815; p.data["black"] = 360; p.data["white"] = 1330; p.data["r"] = 2768; p.data["d"] = 577; p.data["d16"] = 2092; p.data["r16"] = 525;
points[757]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 150; p.county = 0; p.val = 3325; p.data["black"] = 500; p.data["white"] = 2545; p.data["r"] = 880; p.data["d"] = 780; p.data["d16"] = 907; p.data["r16"] = 1201;
points[758]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 152; p.county = 0; p.val = 4095; p.data["black"] = 2130; p.data["white"] = 1705; p.data["r"] = 161; p.data["d"] = 13; p.data["d16"] = 0; p.data["r16"] = 0;
points[759]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 149; p.county = 0; p.val = 575; p.data["black"] = 440; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[760]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 11; p.county = 0; p.val = 535; p.data["black"] = 120; p.data["white"] = 395; p.data["r"] = 196; p.data["d"] = 478; p.data["d16"] = 252; p.data["r16"] = 565;
points[761]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 12; p.county = 0; p.val = 1285; p.data["black"] = 210; p.data["white"] = 1060; p.data["r"] = 546; p.data["d"] = 655; p.data["d16"] = 0; p.data["r16"] = 0;
points[762]=p;}
if (1==1){ Point p;
p.x = 200; p.y = 83; p.county = 0; p.val = 1205; p.data["black"] = 50; p.data["white"] = 1140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[763]=p;}
if (1==1){ Point p;
p.x = 197; p.y = 81; p.county = 0; p.val = 2140; p.data["black"] = 525; p.data["white"] = 1555; p.data["r"] = 251; p.data["d"] = 444; p.data["d16"] = 752; p.data["r16"] = 1604;
points[764]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 99; p.county = 0; p.val = 1690; p.data["black"] = 35; p.data["white"] = 1500; p.data["r"] = 912; p.data["d"] = 1410; p.data["d16"] = 0; p.data["r16"] = 0;
points[765]=p;}
if (1==1){ Point p;
p.x = 192; p.y = 86; p.county = 0; p.val = 1075; p.data["black"] = 865; p.data["white"] = 210; p.data["r"] = 593; p.data["d"] = 319; p.data["d16"] = 709; p.data["r16"] = 416;
points[766]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 102; p.county = 0; p.val = 3895; p.data["black"] = 135; p.data["white"] = 3625; p.data["r"] = 1347; p.data["d"] = 2493; p.data["d16"] = 581; p.data["r16"] = 1373;
points[767]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 84; p.county = 0; p.val = 2280; p.data["black"] = 605; p.data["white"] = 1640; p.data["r"] = 470; p.data["d"] = 1271; p.data["d16"] = 314; p.data["r16"] = 789;
points[768]=p;}
if (1==1){ Point p;
p.x = 175; p.y = 71; p.county = 0; p.val = 470; p.data["black"] = 10; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 23; p.data["r16"] = 504;
points[769]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 101; p.county = 0; p.val = 7080; p.data["black"] = 160; p.data["white"] = 6860; p.data["r"] = 789; p.data["d"] = 1540; p.data["d16"] = 1245; p.data["r16"] = 3072;
points[770]=p;}
if (1==1){ Point p;
p.x = 175; p.y = 77; p.county = 0; p.val = 795; p.data["black"] = 105; p.data["white"] = 690; p.data["r"] = 48; p.data["d"] = 182; p.data["d16"] = 58; p.data["r16"] = 224;
points[771]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 74; p.county = 0; p.val = 1370; p.data["black"] = 70; p.data["white"] = 1295; p.data["r"] = 55; p.data["d"] = 555; p.data["d16"] = 44; p.data["r16"] = 261;
points[772]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 100; p.county = 0; p.val = 2720; p.data["black"] = 330; p.data["white"] = 2265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 317; p.data["r16"] = 875;
points[773]=p;}
if (1==1){ Point p;
p.x = 176; p.y = 90; p.county = 0; p.val = 1695; p.data["black"] = 110; p.data["white"] = 1520; p.data["r"] = 144; p.data["d"] = 645; p.data["d16"] = 246; p.data["r16"] = 595;
points[774]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 17; p.county = 0; p.val = 1915; p.data["black"] = 1465; p.data["white"] = 400; p.data["r"] = 1326; p.data["d"] = 152; p.data["d16"] = 633; p.data["r16"] = 154;
points[775]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 16; p.county = 0; p.val = 1245; p.data["black"] = 15; p.data["white"] = 1210; p.data["r"] = 1240; p.data["d"] = 903; p.data["d16"] = 865; p.data["r16"] = 754;
points[776]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 16; p.county = 0; p.val = 5290; p.data["black"] = 2125; p.data["white"] = 2865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 842; p.data["r16"] = 619;
points[777]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 17; p.county = 0; p.val = 3085; p.data["black"] = 1315; p.data["white"] = 1650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[778]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 18; p.county = 0; p.val = 2400; p.data["black"] = 1915; p.data["white"] = 460; p.data["r"] = 519; p.data["d"] = 42; p.data["d16"] = 547; p.data["r16"] = 54;
points[779]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 139; p.county = 0; p.val = 4775; p.data["black"] = 870; p.data["white"] = 3785; p.data["r"] = 221; p.data["d"] = 557; p.data["d16"] = 175; p.data["r16"] = 577;
points[780]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 18; p.county = 0; p.val = 1275; p.data["black"] = 905; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1174; p.data["r16"] = 163;
points[781]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 17; p.county = 0; p.val = 1885; p.data["black"] = 1500; p.data["white"] = 230; p.data["r"] = 1193; p.data["d"] = 140; p.data["d16"] = 734; p.data["r16"] = 14;
points[782]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 15; p.county = 0; p.val = 3385; p.data["black"] = 670; p.data["white"] = 2465; p.data["r"] = 483; p.data["d"] = 388; p.data["d16"] = 300; p.data["r16"] = 429;
points[783]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 140; p.county = 0; p.val = 1510; p.data["black"] = 410; p.data["white"] = 950; p.data["r"] = 429; p.data["d"] = 629; p.data["d16"] = 391; p.data["r16"] = 670;
points[784]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 139; p.county = 0; p.val = 1440; p.data["black"] = 200; p.data["white"] = 1185; p.data["r"] = 543; p.data["d"] = 815; p.data["d16"] = 462; p.data["r16"] = 1145;
points[785]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 138; p.county = 0; p.val = 1105; p.data["black"] = 570; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[786]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 145; p.county = 0; p.val = 3945; p.data["black"] = 545; p.data["white"] = 3085; p.data["r"] = 968; p.data["d"] = 1787; p.data["d16"] = 892; p.data["r16"] = 2081;
points[787]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 62; p.county = 0; p.val = 1140; p.data["black"] = 460; p.data["white"] = 560; p.data["r"] = 581; p.data["d"] = 480; p.data["d16"] = 0; p.data["r16"] = 0;
points[788]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 142; p.county = 0; p.val = 6475; p.data["black"] = 1835; p.data["white"] = 3755; p.data["r"] = 1230; p.data["d"] = 988; p.data["d16"] = 1401; p.data["r16"] = 1390;
points[789]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 141; p.county = 0; p.val = 2710; p.data["black"] = 755; p.data["white"] = 1875; p.data["r"] = 457; p.data["d"] = 517; p.data["d16"] = 450; p.data["r16"] = 663;
points[790]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 104; p.county = 0; p.val = 690; p.data["black"] = 555; p.data["white"] = 105; p.data["r"] = 224; p.data["d"] = 176; p.data["d16"] = 293; p.data["r16"] = 215;
points[791]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 61; p.county = 0; p.val = 1155; p.data["black"] = 205; p.data["white"] = 935; p.data["r"] = 229; p.data["d"] = 359; p.data["d16"] = 270; p.data["r16"] = 458;
points[792]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 59; p.county = 0; p.val = 770; p.data["black"] = 150; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[793]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 60; p.county = 0; p.val = 625; p.data["black"] = 50; p.data["white"] = 575; p.data["r"] = 241; p.data["d"] = 545; p.data["d16"] = 275; p.data["r16"] = 693;
points[794]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 63; p.county = 0; p.val = 1800; p.data["black"] = 195; p.data["white"] = 1590; p.data["r"] = 737; p.data["d"] = 1042; p.data["d16"] = 500; p.data["r16"] = 832;
points[795]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 52; p.county = 0; p.val = 1005; p.data["black"] = 275; p.data["white"] = 715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[796]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 57; p.county = 0; p.val = 820; p.data["black"] = 165; p.data["white"] = 635; p.data["r"] = 464; p.data["d"] = 487; p.data["d16"] = 665; p.data["r16"] = 817;
points[797]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 37; p.county = 0; p.val = 300; p.data["black"] = 15; p.data["white"] = 275; p.data["r"] = 291; p.data["d"] = 393; p.data["d16"] = 0; p.data["r16"] = 0;
points[798]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 30; p.county = 0; p.val = 840; p.data["black"] = 585; p.data["white"] = 245; p.data["r"] = 313; p.data["d"] = 126; p.data["d16"] = 445; p.data["r16"] = 135;
points[799]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 99; p.county = 0; p.val = 935; p.data["black"] = 255; p.data["white"] = 680; p.data["r"] = 117; p.data["d"] = 328; p.data["d16"] = 118; p.data["r16"] = 435;
points[800]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 140; p.county = 0; p.val = 1725; p.data["black"] = 260; p.data["white"] = 1285; p.data["r"] = 281; p.data["d"] = 369; p.data["d16"] = 297; p.data["r16"] = 512;
points[801]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 144; p.county = 0; p.val = 3575; p.data["black"] = 1685; p.data["white"] = 1625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[802]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 31; p.county = 0; p.val = 620; p.data["black"] = 190; p.data["white"] = 385; p.data["r"] = 159; p.data["d"] = 282; p.data["d16"] = 179; p.data["r16"] = 242;
points[803]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 35; p.county = 0; p.val = 1105; p.data["black"] = 340; p.data["white"] = 750; p.data["r"] = 291; p.data["d"] = 308; p.data["d16"] = 425; p.data["r16"] = 389;
points[804]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 39; p.county = 0; p.val = 885; p.data["black"] = 385; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[805]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 40; p.county = 0; p.val = 385; p.data["black"] = 145; p.data["white"] = 240; p.data["r"] = 282; p.data["d"] = 239; p.data["d16"] = 394; p.data["r16"] = 397;
points[806]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 36; p.county = 0; p.val = 610; p.data["black"] = 245; p.data["white"] = 365; p.data["r"] = 71; p.data["d"] = 62; p.data["d16"] = 0; p.data["r16"] = 0;
points[807]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 30; p.county = 0; p.val = 960; p.data["black"] = 275; p.data["white"] = 635; p.data["r"] = 331; p.data["d"] = 450; p.data["d16"] = 415; p.data["r16"] = 620;
points[808]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 39; p.county = 0; p.val = 390; p.data["black"] = 120; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 172; p.data["r16"] = 225;
points[809]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 192; p.county = 0; p.val = 125; p.data["black"] = 0; p.data["white"] = 125; p.data["r"] = 408; p.data["d"] = 610; p.data["d16"] = 377; p.data["r16"] = 646;
points[810]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 194; p.county = 0; p.val = 655; p.data["black"] = 0; p.data["white"] = 635; p.data["r"] = 885; p.data["d"] = 1163; p.data["d16"] = 871; p.data["r16"] = 1355;
points[811]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 175; p.county = 0; p.val = 1085; p.data["black"] = 210; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[812]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 174; p.county = 0; p.val = 2420; p.data["black"] = 75; p.data["white"] = 2075; p.data["r"] = 332; p.data["d"] = 502; p.data["d16"] = 272; p.data["r16"] = 506;
points[813]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 193; p.county = 0; p.val = 670; p.data["black"] = 0; p.data["white"] = 615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[814]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 188; p.county = 0; p.val = 1705; p.data["black"] = 10; p.data["white"] = 1680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[815]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 40; p.county = 0; p.val = 1725; p.data["black"] = 480; p.data["white"] = 1205; p.data["r"] = 171; p.data["d"] = 323; p.data["d16"] = 185; p.data["r16"] = 389;
points[816]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 37; p.county = 0; p.val = 305; p.data["black"] = 15; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 211; p.data["r16"] = 413;
points[817]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 35; p.county = 0; p.val = 490; p.data["black"] = 45; p.data["white"] = 410; p.data["r"] = 459; p.data["d"] = 740; p.data["d16"] = 513; p.data["r16"] = 1013;
points[818]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 43; p.county = 0; p.val = 1195; p.data["black"] = 25; p.data["white"] = 1125; p.data["r"] = 223; p.data["d"] = 948; p.data["d16"] = 248; p.data["r16"] = 1228;
points[819]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 57; p.county = 0; p.val = 1195; p.data["black"] = 320; p.data["white"] = 850; p.data["r"] = 360; p.data["d"] = 552; p.data["d16"] = 447; p.data["r16"] = 676;
points[820]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 49; p.county = 0; p.val = 500; p.data["black"] = 0; p.data["white"] = 475; p.data["r"] = 68; p.data["d"] = 293; p.data["d16"] = 68; p.data["r16"] = 433;
points[821]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 47; p.county = 0; p.val = 1180; p.data["black"] = 270; p.data["white"] = 910; p.data["r"] = 175; p.data["d"] = 446; p.data["d16"] = 214; p.data["r16"] = 565;
points[822]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 56; p.county = 0; p.val = 1095; p.data["black"] = 185; p.data["white"] = 915; p.data["r"] = 322; p.data["d"] = 567; p.data["d16"] = 0; p.data["r16"] = 0;
points[823]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 52; p.county = 0; p.val = 460; p.data["black"] = 0; p.data["white"] = 455; p.data["r"] = 73; p.data["d"] = 442; p.data["d16"] = 98; p.data["r16"] = 610;
points[824]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 44; p.county = 0; p.val = 845; p.data["black"] = 180; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[825]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 42; p.county = 0; p.val = 325; p.data["black"] = 65; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[826]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 40; p.county = 0; p.val = 420; p.data["black"] = 140; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[827]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 34; p.county = 0; p.val = 1705; p.data["black"] = 475; p.data["white"] = 1140; p.data["r"] = 367; p.data["d"] = 465; p.data["d16"] = 462; p.data["r16"] = 629;
points[828]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 31; p.county = 0; p.val = 640; p.data["black"] = 255; p.data["white"] = 320; p.data["r"] = 353; p.data["d"] = 239; p.data["d16"] = 0; p.data["r16"] = 0;
points[829]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 27; p.county = 0; p.val = 1045; p.data["black"] = 310; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 546; p.data["r16"] = 362;
points[830]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 38; p.county = 0; p.val = 690; p.data["black"] = 75; p.data["white"] = 605; p.data["r"] = 143; p.data["d"] = 183; p.data["d16"] = 167; p.data["r16"] = 246;
points[831]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 42; p.county = 0; p.val = 1215; p.data["black"] = 15; p.data["white"] = 1200; p.data["r"] = 59; p.data["d"] = 289; p.data["d16"] = 66; p.data["r16"] = 395;
points[832]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 32; p.county = 0; p.val = 740; p.data["black"] = 355; p.data["white"] = 375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 758; p.data["r16"] = 252;
points[833]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 26; p.county = 0; p.val = 1110; p.data["black"] = 520; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 426; p.data["r16"] = 550;
points[834]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 32; p.county = 0; p.val = 595; p.data["black"] = 420; p.data["white"] = 145; p.data["r"] = 529; p.data["d"] = 201; p.data["d16"] = 0; p.data["r16"] = 0;
points[835]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 29; p.county = 0; p.val = 680; p.data["black"] = 385; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[836]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 28; p.county = 0; p.val = 1625; p.data["black"] = 850; p.data["white"] = 735; p.data["r"] = 413; p.data["d"] = 264; p.data["d16"] = 0; p.data["r16"] = 0;
points[837]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 41; p.county = 0; p.val = 915; p.data["black"] = 270; p.data["white"] = 645; p.data["r"] = 26; p.data["d"] = 110; p.data["d16"] = 37; p.data["r16"] = 161;
points[838]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 49; p.county = 0; p.val = 1195; p.data["black"] = 70; p.data["white"] = 1125; p.data["r"] = 88; p.data["d"] = 345; p.data["d16"] = 109; p.data["r16"] = 452;
points[839]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 34; p.county = 0; p.val = 695; p.data["black"] = 20; p.data["white"] = 675; p.data["r"] = 155; p.data["d"] = 723; p.data["d16"] = 67; p.data["r16"] = 447;
points[840]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 45; p.county = 0; p.val = 1590; p.data["black"] = 940; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[841]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 52; p.county = 0; p.val = 450; p.data["black"] = 95; p.data["white"] = 355; p.data["r"] = 87; p.data["d"] = 399; p.data["d16"] = 87; p.data["r16"] = 536;
points[842]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 49; p.county = 0; p.val = 635; p.data["black"] = 15; p.data["white"] = 585; p.data["r"] = 31; p.data["d"] = 203; p.data["d16"] = 31; p.data["r16"] = 263;
points[843]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 42; p.county = 0; p.val = 2245; p.data["black"] = 245; p.data["white"] = 1875; p.data["r"] = 357; p.data["d"] = 514; p.data["d16"] = 777; p.data["r16"] = 1170;
points[844]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 43; p.county = 0; p.val = 855; p.data["black"] = 260; p.data["white"] = 575; p.data["r"] = 119; p.data["d"] = 315; p.data["d16"] = 132; p.data["r16"] = 418;
points[845]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 28; p.county = 0; p.val = 1750; p.data["black"] = 10; p.data["white"] = 1715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[846]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 31; p.county = 0; p.val = 2175; p.data["black"] = 90; p.data["white"] = 2010; p.data["r"] = 105; p.data["d"] = 338; p.data["d16"] = 128; p.data["r16"] = 455;
points[847]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 46; p.county = 0; p.val = 1220; p.data["black"] = 655; p.data["white"] = 525; p.data["r"] = 238; p.data["d"] = 102; p.data["d16"] = 0; p.data["r16"] = 0;
points[848]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 31; p.county = 0; p.val = 1875; p.data["black"] = 105; p.data["white"] = 1720; p.data["r"] = 307; p.data["d"] = 792; p.data["d16"] = 0; p.data["r16"] = 0;
points[849]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 48; p.county = 0; p.val = 1215; p.data["black"] = 10; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[850]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 44; p.county = 0; p.val = 1065; p.data["black"] = 595; p.data["white"] = 450; p.data["r"] = 367; p.data["d"] = 539; p.data["d16"] = 378; p.data["r16"] = 718;
points[851]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 45; p.county = 0; p.val = 1180; p.data["black"] = 220; p.data["white"] = 930; p.data["r"] = 115; p.data["d"] = 477; p.data["d16"] = 127; p.data["r16"] = 681;
points[852]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 39; p.county = 0; p.val = 1045; p.data["black"] = 190; p.data["white"] = 825; p.data["r"] = 384; p.data["d"] = 786; p.data["d16"] = 418; p.data["r16"] = 1093;
points[853]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 49; p.county = 0; p.val = 1370; p.data["black"] = 145; p.data["white"] = 1195; p.data["r"] = 205; p.data["d"] = 679; p.data["d16"] = 66; p.data["r16"] = 164;
points[854]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 35; p.county = 0; p.val = 2050; p.data["black"] = 85; p.data["white"] = 1895; p.data["r"] = 257; p.data["d"] = 889; p.data["d16"] = 226; p.data["r16"] = 1118;
points[855]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 31; p.county = 0; p.val = 1110; p.data["black"] = 75; p.data["white"] = 975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[856]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 29; p.county = 0; p.val = 1740; p.data["black"] = 0; p.data["white"] = 1725; p.data["r"] = 371; p.data["d"] = 991; p.data["d16"] = 319; p.data["r16"] = 1401;
points[857]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 52; p.county = 0; p.val = 755; p.data["black"] = 4; p.data["white"] = 735; p.data["r"] = 54; p.data["d"] = 391; p.data["d16"] = 70; p.data["r16"] = 504;
points[858]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 37; p.county = 0; p.val = 1125; p.data["black"] = 40; p.data["white"] = 1050; p.data["r"] = 173; p.data["d"] = 336; p.data["d16"] = 0; p.data["r16"] = 0;
points[859]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 48; p.county = 0; p.val = 1190; p.data["black"] = 105; p.data["white"] = 1075; p.data["r"] = 150; p.data["d"] = 352; p.data["d16"] = 183; p.data["r16"] = 534;
points[860]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 34; p.county = 0; p.val = 1070; p.data["black"] = 20; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[861]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 44; p.county = 0; p.val = 1945; p.data["black"] = 1445; p.data["white"] = 440; p.data["r"] = 445; p.data["d"] = 66; p.data["d16"] = 366; p.data["r16"] = 40;
points[862]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 27; p.county = 0; p.val = 1920; p.data["black"] = 120; p.data["white"] = 1665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[863]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 39; p.county = 0; p.val = 1640; p.data["black"] = 130; p.data["white"] = 1480; p.data["r"] = 214; p.data["d"] = 545; p.data["d16"] = 197; p.data["r16"] = 690;
points[864]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 46; p.county = 0; p.val = 985; p.data["black"] = 175; p.data["white"] = 810; p.data["r"] = 60; p.data["d"] = 271; p.data["d16"] = 216; p.data["r16"] = 567;
points[865]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 56; p.county = 0; p.val = 1390; p.data["black"] = 80; p.data["white"] = 1310; p.data["r"] = 123; p.data["d"] = 590; p.data["d16"] = 126; p.data["r16"] = 793;
points[866]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 35; p.county = 0; p.val = 340; p.data["black"] = 200; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[867]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 36; p.county = 0; p.val = 1335; p.data["black"] = 110; p.data["white"] = 1195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[868]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 37; p.county = 0; p.val = 1475; p.data["black"] = 25; p.data["white"] = 1425; p.data["r"] = 205; p.data["d"] = 946; p.data["d16"] = 441; p.data["r16"] = 2093;
points[869]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 28; p.county = 0; p.val = 1915; p.data["black"] = 15; p.data["white"] = 1900; p.data["r"] = 248; p.data["d"] = 1063; p.data["d16"] = 234; p.data["r16"] = 1395;
points[870]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 46; p.county = 0; p.val = 1030; p.data["black"] = 915; p.data["white"] = 100; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[871]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 76; p.county = 0; p.val = 770; p.data["black"] = 115; p.data["white"] = 660; p.data["r"] = 314; p.data["d"] = 396; p.data["d16"] = 0; p.data["r16"] = 0;
points[872]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 77; p.county = 0; p.val = 1015; p.data["black"] = 570; p.data["white"] = 445; p.data["r"] = 823; p.data["d"] = 642; p.data["d16"] = 0; p.data["r16"] = 0;
points[873]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 83; p.county = 0; p.val = 1415; p.data["black"] = 605; p.data["white"] = 795; p.data["r"] = 329; p.data["d"] = 255; p.data["d16"] = 430; p.data["r16"] = 389;
points[874]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 69; p.county = 0; p.val = 1110; p.data["black"] = 905; p.data["white"] = 205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[875]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 81; p.county = 0; p.val = 1425; p.data["black"] = 1125; p.data["white"] = 225; p.data["r"] = 633; p.data["d"] = 153; p.data["d16"] = 799; p.data["r16"] = 169;
points[876]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 31; p.county = 0; p.val = 1350; p.data["black"] = 165; p.data["white"] = 1070; p.data["r"] = 569; p.data["d"] = 552; p.data["d16"] = 521; p.data["r16"] = 565;
points[877]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 58; p.county = 0; p.val = 680; p.data["black"] = 435; p.data["white"] = 230; p.data["r"] = 577; p.data["d"] = 475; p.data["d16"] = 0; p.data["r16"] = 0;
points[878]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 50; p.county = 0; p.val = 570; p.data["black"] = 55; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[879]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 51; p.county = 0; p.val = 650; p.data["black"] = 0; p.data["white"] = 600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 227; p.data["r16"] = 583;
points[880]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 61; p.county = 0; p.val = 1755; p.data["black"] = 650; p.data["white"] = 1060; p.data["r"] = 570; p.data["d"] = 891; p.data["d16"] = 677; p.data["r16"] = 1150;
points[881]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 66; p.county = 0; p.val = 1050; p.data["black"] = 475; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[882]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 60; p.county = 0; p.val = 1055; p.data["black"] = 535; p.data["white"] = 500; p.data["r"] = 730; p.data["d"] = 585; p.data["d16"] = 804; p.data["r16"] = 770;
points[883]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 57; p.county = 0; p.val = 495; p.data["black"] = 360; p.data["white"] = 110; p.data["r"] = 306; p.data["d"] = 123; p.data["d16"] = 633; p.data["r16"] = 441;
points[884]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 49; p.county = 0; p.val = 1810; p.data["black"] = 615; p.data["white"] = 1185; p.data["r"] = 491; p.data["d"] = 992; p.data["d16"] = 479; p.data["r16"] = 685;
points[885]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 59; p.county = 0; p.val = 750; p.data["black"] = 440; p.data["white"] = 250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[886]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 56; p.county = 0; p.val = 1000; p.data["black"] = 205; p.data["white"] = 760; p.data["r"] = 842; p.data["d"] = 547; p.data["d16"] = 581; p.data["r16"] = 576;
points[887]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 50; p.county = 0; p.val = 450; p.data["black"] = 370; p.data["white"] = 80; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 331; p.data["r16"] = 360;
points[888]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 47; p.county = 0; p.val = 1340; p.data["black"] = 60; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 537; p.data["r16"] = 696;
points[889]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 49; p.county = 0; p.val = 470; p.data["black"] = 255; p.data["white"] = 205; p.data["r"] = 538; p.data["d"] = 294; p.data["d16"] = 681; p.data["r16"] = 384;
points[890]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 55; p.county = 0; p.val = 705; p.data["black"] = 415; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[891]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 60; p.county = 0; p.val = 905; p.data["black"] = 285; p.data["white"] = 620; p.data["r"] = 237; p.data["d"] = 354; p.data["d16"] = 282; p.data["r16"] = 474;
points[892]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 58; p.county = 0; p.val = 1045; p.data["black"] = 520; p.data["white"] = 525; p.data["r"] = 403; p.data["d"] = 205; p.data["d16"] = 660; p.data["r16"] = 563;
points[893]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 50; p.county = 0; p.val = 2065; p.data["black"] = 200; p.data["white"] = 1770; p.data["r"] = 370; p.data["d"] = 1170; p.data["d16"] = 524; p.data["r16"] = 2069;
points[894]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 43; p.county = 0; p.val = 565; p.data["black"] = 325; p.data["white"] = 225; p.data["r"] = 363; p.data["d"] = 141; p.data["d16"] = 461; p.data["r16"] = 204;
points[895]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 65; p.county = 0; p.val = 815; p.data["black"] = 355; p.data["white"] = 440; p.data["r"] = 363; p.data["d"] = 528; p.data["d16"] = 447; p.data["r16"] = 724;
points[896]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 65; p.county = 0; p.val = 605; p.data["black"] = 535; p.data["white"] = 60; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[897]=p;}
if (1==1){ Point p;
p.x = 173; p.y = 63; p.county = 0; p.val = 465; p.data["black"] = 20; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[898]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 68; p.county = 0; p.val = 635; p.data["black"] = 235; p.data["white"] = 405; p.data["r"] = 916; p.data["d"] = 293; p.data["d16"] = 0; p.data["r16"] = 0;
points[899]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 61; p.county = 0; p.val = 300; p.data["black"] = 160; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[900]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 60; p.county = 0; p.val = 765; p.data["black"] = 725; p.data["white"] = 30; p.data["r"] = 226; p.data["d"] = 111; p.data["d16"] = 249; p.data["r16"] = 151;
points[901]=p;}
if (1==1){ Point p;
p.x = 172; p.y = 61; p.county = 0; p.val = 685; p.data["black"] = 460; p.data["white"] = 205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 797; p.data["r16"] = 422;
points[902]=p;}
if (1==1){ Point p;
p.x = 162; p.y = 68; p.county = 0; p.val = 735; p.data["black"] = 325; p.data["white"] = 405; p.data["r"] = 299; p.data["d"] = 337; p.data["d16"] = 349; p.data["r16"] = 516;
points[903]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 69; p.county = 0; p.val = 1260; p.data["black"] = 615; p.data["white"] = 645; p.data["r"] = 290; p.data["d"] = 107; p.data["d16"] = 404; p.data["r16"] = 172;
points[904]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 64; p.county = 0; p.val = 430; p.data["black"] = 105; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[905]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 62; p.county = 0; p.val = 300; p.data["black"] = 300; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[906]=p;}
if (1==1){ Point p;
p.x = 172; p.y = 68; p.county = 0; p.val = 855; p.data["black"] = 0; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[907]=p;}
if (1==1){ Point p;
p.x = 164; p.y = 74; p.county = 0; p.val = 455; p.data["black"] = 260; p.data["white"] = 195; p.data["r"] = 155; p.data["d"] = 48; p.data["d16"] = 815; p.data["r16"] = 349;
points[908]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 88; p.county = 0; p.val = 545; p.data["black"] = 305; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[909]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 63; p.county = 0; p.val = 630; p.data["black"] = 275; p.data["white"] = 340; p.data["r"] = 489; p.data["d"] = 198; p.data["d16"] = 747; p.data["r16"] = 271;
points[910]=p;}
if (1==1){ Point p;
p.x = 168; p.y = 74; p.county = 0; p.val = 605; p.data["black"] = 270; p.data["white"] = 325; p.data["r"] = 476; p.data["d"] = 209; p.data["d16"] = 0; p.data["r16"] = 0;
points[911]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 25; p.county = 0; p.val = 1460; p.data["black"] = 480; p.data["white"] = 950; p.data["r"] = 203; p.data["d"] = 335; p.data["d16"] = 218; p.data["r16"] = 662;
points[912]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 79; p.county = 0; p.val = 1540; p.data["black"] = 1250; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 878; p.data["r16"] = 153;
points[913]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 52; p.county = 0; p.val = 1060; p.data["black"] = 145; p.data["white"] = 905; p.data["r"] = 313; p.data["d"] = 504; p.data["d16"] = 0; p.data["r16"] = 0;
points[914]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 52; p.county = 0; p.val = 1890; p.data["black"] = 1145; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[915]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 51; p.county = 0; p.val = 1140; p.data["black"] = 595; p.data["white"] = 525; p.data["r"] = 234; p.data["d"] = 287; p.data["d16"] = 0; p.data["r16"] = 0;
points[916]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 42; p.county = 0; p.val = 455; p.data["black"] = 175; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[917]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 26; p.county = 0; p.val = 490; p.data["black"] = 155; p.data["white"] = 295; p.data["r"] = 257; p.data["d"] = 403; p.data["d16"] = 328; p.data["r16"] = 566;
points[918]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 30; p.county = 0; p.val = 725; p.data["black"] = 185; p.data["white"] = 525; p.data["r"] = 290; p.data["d"] = 539; p.data["d16"] = 355; p.data["r16"] = 713;
points[919]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 37; p.county = 0; p.val = 785; p.data["black"] = 510; p.data["white"] = 275; p.data["r"] = 306; p.data["d"] = 222; p.data["d16"] = 384; p.data["r16"] = 303;
points[920]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 47; p.county = 0; p.val = 1535; p.data["black"] = 490; p.data["white"] = 965; p.data["r"] = 337; p.data["d"] = 480; p.data["d16"] = 419; p.data["r16"] = 678;
points[921]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 107; p.county = 0; p.val = 1010; p.data["black"] = 0; p.data["white"] = 945; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[922]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 35; p.county = 0; p.val = 1220; p.data["black"] = 0; p.data["white"] = 1175; p.data["r"] = 68; p.data["d"] = 312; p.data["d16"] = 63; p.data["r16"] = 458;
points[923]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 28; p.county = 0; p.val = 1485; p.data["black"] = 400; p.data["white"] = 1080; p.data["r"] = 422; p.data["d"] = 232; p.data["d16"] = 555; p.data["r16"] = 270;
points[924]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 10; p.county = 0; p.val = 5660; p.data["black"] = 530; p.data["white"] = 4670; p.data["r"] = 813; p.data["d"] = 919; p.data["d16"] = 883; p.data["r16"] = 1248;
points[925]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 13; p.county = 0; p.val = 3990; p.data["black"] = 120; p.data["white"] = 3365; p.data["r"] = 1884; p.data["d"] = 2546; p.data["d16"] = 1240; p.data["r16"] = 2064;
points[926]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 28; p.county = 0; p.val = 2040; p.data["black"] = 425; p.data["white"] = 1440; p.data["r"] = 104; p.data["d"] = 367; p.data["d16"] = 104; p.data["r16"] = 514;
points[927]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 42; p.county = 0; p.val = 720; p.data["black"] = 10; p.data["white"] = 705; p.data["r"] = 188; p.data["d"] = 566; p.data["d16"] = 0; p.data["r16"] = 0;
points[928]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 53; p.county = 0; p.val = 1845; p.data["black"] = 260; p.data["white"] = 1580; p.data["r"] = 786; p.data["d"] = 1635; p.data["d16"] = 834; p.data["r16"] = 1827;
points[929]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 56; p.county = 0; p.val = 1545; p.data["black"] = 385; p.data["white"] = 1120; p.data["r"] = 400; p.data["d"] = 521; p.data["d16"] = 217; p.data["r16"] = 410;
points[930]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 155; p.county = 0; p.val = 2170; p.data["black"] = 300; p.data["white"] = 1820; p.data["r"] = 1077; p.data["d"] = 328; p.data["d16"] = 2248; p.data["r16"] = 486;
points[931]=p;}
if (1==1){ Point p;
p.x = 193; p.y = 93; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[932]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 34; p.county = 0; p.val = 1165; p.data["black"] = 80; p.data["white"] = 1055; p.data["r"] = 131; p.data["d"] = 276; p.data["d16"] = 127; p.data["r16"] = 348;
points[933]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 38; p.county = 0; p.val = 3285; p.data["black"] = 285; p.data["white"] = 2625; p.data["r"] = 497; p.data["d"] = 1389; p.data["d16"] = 665; p.data["r16"] = 2183;
points[934]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 42; p.county = 0; p.val = 1045; p.data["black"] = 0; p.data["white"] = 995; p.data["r"] = 350; p.data["d"] = 940; p.data["d16"] = 0; p.data["r16"] = 0;
points[935]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 47; p.county = 0; p.val = 2120; p.data["black"] = 525; p.data["white"] = 1550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[936]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 45; p.county = 0; p.val = 2055; p.data["black"] = 300; p.data["white"] = 1645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[937]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 44; p.county = 0; p.val = 1030; p.data["black"] = 0; p.data["white"] = 1005; p.data["r"] = 180; p.data["d"] = 668; p.data["d16"] = 179; p.data["r16"] = 837;
points[938]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 42; p.county = 0; p.val = 1660; p.data["black"] = 295; p.data["white"] = 1335; p.data["r"] = 436; p.data["d"] = 909; p.data["d16"] = 467; p.data["r16"] = 1110;
points[939]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 39; p.county = 0; p.val = 1120; p.data["black"] = 20; p.data["white"] = 990; p.data["r"] = 647; p.data["d"] = 1531; p.data["d16"] = 409; p.data["r16"] = 1364;
points[940]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 38; p.county = 0; p.val = 1405; p.data["black"] = 25; p.data["white"] = 1380; p.data["r"] = 69; p.data["d"] = 283; p.data["d16"] = 0; p.data["r16"] = 0;
points[941]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 44; p.county = 0; p.val = 800; p.data["black"] = 0; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[942]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 25; p.county = 0; p.val = 3115; p.data["black"] = 265; p.data["white"] = 2545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[943]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 26; p.county = 0; p.val = 2735; p.data["black"] = 105; p.data["white"] = 2360; p.data["r"] = 436; p.data["d"] = 1128; p.data["d16"] = 422; p.data["r16"] = 1518;
points[944]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 42; p.county = 0; p.val = 970; p.data["black"] = 65; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[945]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 45; p.county = 0; p.val = 755; p.data["black"] = 365; p.data["white"] = 365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 268; p.data["r16"] = 380;
points[946]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 72; p.county = 0; p.val = 855; p.data["black"] = 235; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[947]=p;}
if (1==1){ Point p;
p.x = 173; p.y = 101; p.county = 0; p.val = 915; p.data["black"] = 585; p.data["white"] = 310; p.data["r"] = 303; p.data["d"] = 124; p.data["d16"] = 401; p.data["r16"] = 162;
points[948]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 117; p.county = 0; p.val = 705; p.data["black"] = 150; p.data["white"] = 515; p.data["r"] = 1023; p.data["d"] = 242; p.data["d16"] = 833; p.data["r16"] = 307;
points[949]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 112; p.county = 0; p.val = 1325; p.data["black"] = 750; p.data["white"] = 570; p.data["r"] = 926; p.data["d"] = 471; p.data["d16"] = 1280; p.data["r16"] = 681;
points[950]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 114; p.county = 0; p.val = 1310; p.data["black"] = 270; p.data["white"] = 1020; p.data["r"] = 244; p.data["d"] = 583; p.data["d16"] = 0; p.data["r16"] = 0;
points[951]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 32; p.county = 0; p.val = 1315; p.data["black"] = 430; p.data["white"] = 880; p.data["r"] = 328; p.data["d"] = 472; p.data["d16"] = 475; p.data["r16"] = 663;
points[952]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 30; p.county = 0; p.val = 755; p.data["black"] = 25; p.data["white"] = 720; p.data["r"] = 291; p.data["d"] = 166; p.data["d16"] = 832; p.data["r16"] = 320;
points[953]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 64; p.county = 0; p.val = 680; p.data["black"] = 25; p.data["white"] = 640; p.data["r"] = 294; p.data["d"] = 946; p.data["d16"] = 447; p.data["r16"] = 1513;
points[954]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 65; p.county = 0; p.val = 520; p.data["black"] = 0; p.data["white"] = 485; p.data["r"] = 211; p.data["d"] = 538; p.data["d16"] = 0; p.data["r16"] = 0;
points[955]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 37; p.county = 0; p.val = 1305; p.data["black"] = 255; p.data["white"] = 1035; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[956]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 35; p.county = 0; p.val = 630; p.data["black"] = 185; p.data["white"] = 435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[957]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 38; p.county = 0; p.val = 1785; p.data["black"] = 190; p.data["white"] = 1505; p.data["r"] = 301; p.data["d"] = 677; p.data["d16"] = 290; p.data["r16"] = 848;
points[958]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 33; p.county = 0; p.val = 660; p.data["black"] = 190; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 874; p.data["r16"] = 833;
points[959]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 36; p.county = 0; p.val = 965; p.data["black"] = 25; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[960]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 35; p.county = 0; p.val = 935; p.data["black"] = 80; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[961]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 36; p.county = 0; p.val = 1090; p.data["black"] = 375; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 164; p.data["r16"] = 453;
points[962]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 46; p.county = 0; p.val = 1440; p.data["black"] = 0; p.data["white"] = 1355; p.data["r"] = 340; p.data["d"] = 922; p.data["d16"] = 481; p.data["r16"] = 1812;
points[963]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 49; p.county = 0; p.val = 785; p.data["black"] = 50; p.data["white"] = 715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[964]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 47; p.county = 0; p.val = 770; p.data["black"] = 75; p.data["white"] = 650; p.data["r"] = 82; p.data["d"] = 98; p.data["d16"] = 0; p.data["r16"] = 0;
points[965]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 0; p.county = 0; p.val = 730; p.data["black"] = 25; p.data["white"] = 620; p.data["r"] = 456; p.data["d"] = 1072; p.data["d16"] = 451; p.data["r16"] = 1476;
points[966]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 1; p.county = 0; p.val = 740; p.data["black"] = 15; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[967]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 9; p.county = 0; p.val = 1770; p.data["black"] = 190; p.data["white"] = 1380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[968]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 8; p.county = 0; p.val = 1445; p.data["black"] = 240; p.data["white"] = 1125; p.data["r"] = 337; p.data["d"] = 710; p.data["d16"] = 399; p.data["r16"] = 1057;
points[969]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 9; p.county = 0; p.val = 1690; p.data["black"] = 345; p.data["white"] = 1175; p.data["r"] = 449; p.data["d"] = 833; p.data["d16"] = 587; p.data["r16"] = 1122;
points[970]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 16; p.county = 0; p.val = 930; p.data["black"] = 150; p.data["white"] = 755; p.data["r"] = 345; p.data["d"] = 657; p.data["d16"] = 409; p.data["r16"] = 924;
points[971]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 17; p.county = 0; p.val = 805; p.data["black"] = 285; p.data["white"] = 440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 834; p.data["r16"] = 1024;
points[972]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 103; p.county = 0; p.val = 790; p.data["black"] = 760; p.data["white"] = 25; p.data["r"] = 507; p.data["d"] = 84; p.data["d16"] = 641; p.data["r16"] = 95;
points[973]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 97; p.county = 0; p.val = 555; p.data["black"] = 205; p.data["white"] = 300; p.data["r"] = 133; p.data["d"] = 84; p.data["d16"] = 195; p.data["r16"] = 97;
points[974]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 86; p.county = 0; p.val = 1385; p.data["black"] = 805; p.data["white"] = 500; p.data["r"] = 439; p.data["d"] = 811; p.data["d16"] = 179; p.data["r16"] = 202;
points[975]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 78; p.county = 0; p.val = 1195; p.data["black"] = 40; p.data["white"] = 1145; p.data["r"] = 65; p.data["d"] = 399; p.data["d16"] = 79; p.data["r16"] = 559;
points[976]=p;}
if (1==1){ Point p;
p.x = 186; p.y = 67; p.county = 0; p.val = 1450; p.data["black"] = 135; p.data["white"] = 1265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[977]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 77; p.county = 0; p.val = 2345; p.data["black"] = 95; p.data["white"] = 2170; p.data["r"] = 128; p.data["d"] = 490; p.data["d16"] = 226; p.data["r16"] = 990;
points[978]=p;}
if (1==1){ Point p;
p.x = 197; p.y = 87; p.county = 0; p.val = 750; p.data["black"] = 10; p.data["white"] = 700; p.data["r"] = 469; p.data["d"] = 1374; p.data["d16"] = 454; p.data["r16"] = 1536;
points[979]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 61; p.county = 0; p.val = 2465; p.data["black"] = 530; p.data["white"] = 1710; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 720; p.data["r16"] = 663;
points[980]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 63; p.county = 0; p.val = 1035; p.data["black"] = 815; p.data["white"] = 170; p.data["r"] = 732; p.data["d"] = 6; p.data["d16"] = 725; p.data["r16"] = 14;
points[981]=p;}
if (1==1){ Point p;
p.x = 157; p.y = 68; p.county = 0; p.val = 1075; p.data["black"] = 235; p.data["white"] = 840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[982]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 70; p.county = 0; p.val = 640; p.data["black"] = 130; p.data["white"] = 510; p.data["r"] = 424; p.data["d"] = 481; p.data["d16"] = 404; p.data["r16"] = 610;
points[983]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 71; p.county = 0; p.val = 825; p.data["black"] = 300; p.data["white"] = 520; p.data["r"] = 253; p.data["d"] = 661; p.data["d16"] = 269; p.data["r16"] = 801;
points[984]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 84; p.county = 0; p.val = 965; p.data["black"] = 545; p.data["white"] = 400; p.data["r"] = 317; p.data["d"] = 220; p.data["d16"] = 458; p.data["r16"] = 369;
points[985]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 61; p.county = 0; p.val = 1245; p.data["black"] = 905; p.data["white"] = 325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[986]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 60; p.county = 0; p.val = 1960; p.data["black"] = 735; p.data["white"] = 1220; p.data["r"] = 313; p.data["d"] = 522; p.data["d16"] = 344; p.data["r16"] = 645;
points[987]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 68; p.county = 0; p.val = 1000; p.data["black"] = 630; p.data["white"] = 360; p.data["r"] = 1065; p.data["d"] = 856; p.data["d16"] = 0; p.data["r16"] = 0;
points[988]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 141; p.county = 0; p.val = 825; p.data["black"] = 40; p.data["white"] = 775; p.data["r"] = 124; p.data["d"] = 236; p.data["d16"] = 154; p.data["r16"] = 340;
points[989]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 137; p.county = 0; p.val = 910; p.data["black"] = 215; p.data["white"] = 695; p.data["r"] = 140; p.data["d"] = 162; p.data["d16"] = 165; p.data["r16"] = 210;
points[990]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 142; p.county = 0; p.val = 1655; p.data["black"] = 435; p.data["white"] = 1220; p.data["r"] = 91; p.data["d"] = 100; p.data["d16"] = 96; p.data["r16"] = 109;
points[991]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 147; p.county = 0; p.val = 1195; p.data["black"] = 625; p.data["white"] = 570; p.data["r"] = 477; p.data["d"] = 496; p.data["d16"] = 230; p.data["r16"] = 407;
points[992]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 147; p.county = 0; p.val = 1130; p.data["black"] = 615; p.data["white"] = 465; p.data["r"] = 486; p.data["d"] = 88; p.data["d16"] = 980; p.data["r16"] = 386;
points[993]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 153; p.county = 0; p.val = 5145; p.data["black"] = 1000; p.data["white"] = 3845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[994]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 77; p.county = 0; p.val = 1630; p.data["black"] = 905; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[995]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 47; p.county = 0; p.val = 400; p.data["black"] = 20; p.data["white"] = 360; p.data["r"] = 313; p.data["d"] = 732; p.data["d16"] = 189; p.data["r16"] = 771;
points[996]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 48; p.county = 0; p.val = 535; p.data["black"] = 115; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 95; p.data["r16"] = 274;
points[997]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 53; p.county = 0; p.val = 1660; p.data["black"] = 340; p.data["white"] = 1270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[998]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 50; p.county = 0; p.val = 860; p.data["black"] = 15; p.data["white"] = 830; p.data["r"] = 142; p.data["d"] = 467; p.data["d16"] = 201; p.data["r16"] = 645;
points[999]=p;}

}
void scPoints1(){

if (1==1){ Point p;
p.x = 26; p.y = 46; p.county = 0; p.val = 1430; p.data["black"] = 830; p.data["white"] = 530; p.data["r"] = 219; p.data["d"] = 245; p.data["d16"] = 117; p.data["r16"] = 139;
points[1000]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 68; p.county = 0; p.val = 2145; p.data["black"] = 1040; p.data["white"] = 1005; p.data["r"] = 1078; p.data["d"] = 526; p.data["d16"] = 0; p.data["r16"] = 0;
points[1001]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 149; p.county = 0; p.val = 2325; p.data["black"] = 1085; p.data["white"] = 1155; p.data["r"] = 484; p.data["d"] = 70; p.data["d16"] = 386; p.data["r16"] = 37;
points[1002]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 148; p.county = 0; p.val = 2340; p.data["black"] = 1335; p.data["white"] = 710; p.data["r"] = 913; p.data["d"] = 185; p.data["d16"] = 383; p.data["r16"] = 49;
points[1003]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 6; p.county = 0; p.val = 1405; p.data["black"] = 855; p.data["white"] = 545; p.data["r"] = 350; p.data["d"] = 219; p.data["d16"] = 529; p.data["r16"] = 341;
points[1004]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 7; p.county = 0; p.val = 1390; p.data["black"] = 655; p.data["white"] = 665; p.data["r"] = 436; p.data["d"] = 79; p.data["d16"] = 497; p.data["r16"] = 87;
points[1005]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 8; p.county = 0; p.val = 1950; p.data["black"] = 1070; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1006]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 155; p.county = 0; p.val = 1350; p.data["black"] = 110; p.data["white"] = 1240; p.data["r"] = 2505; p.data["d"] = 1888; p.data["d16"] = 2003; p.data["r16"] = 1975;
points[1007]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 152; p.county = 0; p.val = 4620; p.data["black"] = 2025; p.data["white"] = 2520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 225; p.data["r16"] = 12;
points[1008]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 152; p.county = 0; p.val = 6410; p.data["black"] = 3625; p.data["white"] = 2605; p.data["r"] = 362; p.data["d"] = 19; p.data["d16"] = 525; p.data["r16"] = 20;
points[1009]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 156; p.county = 0; p.val = 2015; p.data["black"] = 155; p.data["white"] = 1740; p.data["r"] = 654; p.data["d"] = 580; p.data["d16"] = 525; p.data["r16"] = 763;
points[1010]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 158; p.county = 0; p.val = 2195; p.data["black"] = 190; p.data["white"] = 1955; p.data["r"] = 2680; p.data["d"] = 2458; p.data["d16"] = 1833; p.data["r16"] = 2023;
points[1011]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 151; p.county = 0; p.val = 3235; p.data["black"] = 365; p.data["white"] = 2780; p.data["r"] = 624; p.data["d"] = 57; p.data["d16"] = 960; p.data["r16"] = 57;
points[1012]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 152; p.county = 0; p.val = 4900; p.data["black"] = 1340; p.data["white"] = 3305; p.data["r"] = 618; p.data["d"] = 658; p.data["d16"] = 464; p.data["r16"] = 768;
points[1013]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 134; p.county = 0; p.val = 1255; p.data["black"] = 705; p.data["white"] = 550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1014]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 155; p.county = 0; p.val = 1775; p.data["black"] = 185; p.data["white"] = 1500; p.data["r"] = 778; p.data["d"] = 238; p.data["d16"] = 930; p.data["r16"] = 305;
points[1015]=p;}
if (1==1){ Point p;
p.x = 162; p.y = 130; p.county = 0; p.val = 960; p.data["black"] = 800; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1016]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 151; p.county = 0; p.val = 395; p.data["black"] = 390; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1017]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 153; p.county = 0; p.val = 665; p.data["black"] = 130; p.data["white"] = 535; p.data["r"] = 309; p.data["d"] = 189; p.data["d16"] = 397; p.data["r16"] = 243;
points[1018]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 155; p.county = 0; p.val = 530; p.data["black"] = 230; p.data["white"] = 305; p.data["r"] = 282; p.data["d"] = 287; p.data["d16"] = 342; p.data["r16"] = 337;
points[1019]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 157; p.county = 0; p.val = 2855; p.data["black"] = 680; p.data["white"] = 2105; p.data["r"] = 1052; p.data["d"] = 889; p.data["d16"] = 1096; p.data["r16"] = 1307;
points[1020]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 152; p.county = 0; p.val = 340; p.data["black"] = 0; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1021]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 160; p.county = 0; p.val = 1155; p.data["black"] = 775; p.data["white"] = 370; p.data["r"] = 334; p.data["d"] = 420; p.data["d16"] = 0; p.data["r16"] = 0;
points[1022]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 149; p.county = 0; p.val = 3375; p.data["black"] = 2820; p.data["white"] = 490; p.data["r"] = 880; p.data["d"] = 462; p.data["d16"] = 1142; p.data["r16"] = 512;
points[1023]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 7; p.county = 0; p.val = 1365; p.data["black"] = 440; p.data["white"] = 795; p.data["r"] = 423; p.data["d"] = 730; p.data["d16"] = 461; p.data["r16"] = 917;
points[1024]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 7; p.county = 0; p.val = 1765; p.data["black"] = 1010; p.data["white"] = 620; p.data["r"] = 571; p.data["d"] = 797; p.data["d16"] = 773; p.data["r16"] = 494;
points[1025]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 6; p.county = 0; p.val = 925; p.data["black"] = 445; p.data["white"] = 435; p.data["r"] = 701; p.data["d"] = 210; p.data["d16"] = 546; p.data["r16"] = 125;
points[1026]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 139; p.county = 0; p.val = 3210; p.data["black"] = 975; p.data["white"] = 1840; p.data["r"] = 440; p.data["d"] = 377; p.data["d16"] = 421; p.data["r16"] = 521;
points[1027]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 151; p.county = 0; p.val = 1765; p.data["black"] = 500; p.data["white"] = 1210; p.data["r"] = 986; p.data["d"] = 67; p.data["d16"] = 780; p.data["r16"] = 31;
points[1028]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 158; p.county = 0; p.val = 715; p.data["black"] = 375; p.data["white"] = 335; p.data["r"] = 725; p.data["d"] = 219; p.data["d16"] = 834; p.data["r16"] = 260;
points[1029]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 152; p.county = 0; p.val = 1710; p.data["black"] = 370; p.data["white"] = 1325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1030]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 157; p.county = 0; p.val = 1320; p.data["black"] = 0; p.data["white"] = 1320; p.data["r"] = 412; p.data["d"] = 481; p.data["d16"] = 1123; p.data["r16"] = 1404;
points[1031]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 163; p.county = 0; p.val = 1335; p.data["black"] = 685; p.data["white"] = 640; p.data["r"] = 411; p.data["d"] = 288; p.data["d16"] = 415; p.data["r16"] = 371;
points[1032]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 151; p.county = 0; p.val = 4105; p.data["black"] = 270; p.data["white"] = 3555; p.data["r"] = 721; p.data["d"] = 1044; p.data["d16"] = 606; p.data["r16"] = 1020;
points[1033]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 155; p.county = 0; p.val = 2850; p.data["black"] = 4; p.data["white"] = 2725; p.data["r"] = 1241; p.data["d"] = 577; p.data["d16"] = 1672; p.data["r16"] = 960;
points[1034]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 153; p.county = 0; p.val = 2775; p.data["black"] = 510; p.data["white"] = 2110; p.data["r"] = 1527; p.data["d"] = 741; p.data["d16"] = 2473; p.data["r16"] = 1761;
points[1035]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 160; p.county = 0; p.val = 1115; p.data["black"] = 340; p.data["white"] = 765; p.data["r"] = 941; p.data["d"] = 443; p.data["d16"] = 1162; p.data["r16"] = 534;
points[1036]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 156; p.county = 0; p.val = 1410; p.data["black"] = 155; p.data["white"] = 1180; p.data["r"] = 2605; p.data["d"] = 2015; p.data["d16"] = 1613; p.data["r16"] = 1966;
points[1037]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 147; p.county = 0; p.val = 3565; p.data["black"] = 395; p.data["white"] = 3020; p.data["r"] = 833; p.data["d"] = 1638; p.data["d16"] = 716; p.data["r16"] = 1643;
points[1038]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 154; p.county = 0; p.val = 2400; p.data["black"] = 165; p.data["white"] = 2115; p.data["r"] = 1103; p.data["d"] = 100; p.data["d16"] = 2621; p.data["r16"] = 337;
points[1039]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 7; p.county = 0; p.val = 420; p.data["black"] = 4; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1040]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 159; p.county = 0; p.val = 1295; p.data["black"] = 730; p.data["white"] = 560; p.data["r"] = 390; p.data["d"] = 787; p.data["d16"] = 429; p.data["r16"] = 921;
points[1041]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 150; p.county = 0; p.val = 3560; p.data["black"] = 620; p.data["white"] = 2790; p.data["r"] = 594; p.data["d"] = 159; p.data["d16"] = 1296; p.data["r16"] = 282;
points[1042]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 154; p.county = 0; p.val = 2160; p.data["black"] = 30; p.data["white"] = 2020; p.data["r"] = 706; p.data["d"] = 567; p.data["d16"] = 1130; p.data["r16"] = 1072;
points[1043]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 142; p.county = 0; p.val = 1515; p.data["black"] = 715; p.data["white"] = 730; p.data["r"] = 718; p.data["d"] = 1219; p.data["d16"] = 698; p.data["r16"] = 1419;
points[1044]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 147; p.county = 0; p.val = 2240; p.data["black"] = 815; p.data["white"] = 1315; p.data["r"] = 340; p.data["d"] = 93; p.data["d16"] = 469; p.data["r16"] = 164;
points[1045]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 152; p.county = 0; p.val = 2675; p.data["black"] = 115; p.data["white"] = 2435; p.data["r"] = 573; p.data["d"] = 443; p.data["d16"] = 557; p.data["r16"] = 487;
points[1046]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 154; p.county = 0; p.val = 2845; p.data["black"] = 265; p.data["white"] = 2520; p.data["r"] = 516; p.data["d"] = 404; p.data["d16"] = 1093; p.data["r16"] = 528;
points[1047]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 106; p.county = 0; p.val = 925; p.data["black"] = 70; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 254; p.data["r16"] = 890;
points[1048]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 105; p.county = 0; p.val = 1430; p.data["black"] = 0; p.data["white"] = 1305; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 218; p.data["r16"] = 507;
points[1049]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 104; p.county = 0; p.val = 2950; p.data["black"] = 585; p.data["white"] = 2195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1050]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 110; p.county = 0; p.val = 2380; p.data["black"] = 100; p.data["white"] = 2175; p.data["r"] = 171; p.data["d"] = 329; p.data["d16"] = 229; p.data["r16"] = 395;
points[1051]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 110; p.county = 0; p.val = 1475; p.data["black"] = 405; p.data["white"] = 980; p.data["r"] = 190; p.data["d"] = 205; p.data["d16"] = 0; p.data["r16"] = 0;
points[1052]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 107; p.county = 0; p.val = 1565; p.data["black"] = 115; p.data["white"] = 1420; p.data["r"] = 148; p.data["d"] = 399; p.data["d16"] = 0; p.data["r16"] = 0;
points[1053]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 9; p.county = 0; p.val = 1770; p.data["black"] = 110; p.data["white"] = 1550; p.data["r"] = 104; p.data["d"] = 508; p.data["d16"] = 112; p.data["r16"] = 675;
points[1054]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 153; p.county = 0; p.val = 7690; p.data["black"] = 2260; p.data["white"] = 5055; p.data["r"] = 471; p.data["d"] = 33; p.data["d16"] = 748; p.data["r16"] = 29;
points[1055]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 4; p.county = 0; p.val = 2145; p.data["black"] = 145; p.data["white"] = 1855; p.data["r"] = 123; p.data["d"] = 605; p.data["d16"] = 164; p.data["r16"] = 801;
points[1056]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 18; p.county = 0; p.val = 525; p.data["black"] = 20; p.data["white"] = 505; p.data["r"] = 29; p.data["d"] = 192; p.data["d16"] = 30; p.data["r16"] = 250;
points[1057]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 6; p.county = 0; p.val = 1285; p.data["black"] = 60; p.data["white"] = 1140; p.data["r"] = 54; p.data["d"] = 413; p.data["d16"] = 60; p.data["r16"] = 544;
points[1058]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 2; p.county = 0; p.val = 2130; p.data["black"] = 155; p.data["white"] = 1950; p.data["r"] = 175; p.data["d"] = 1032; p.data["d16"] = 399; p.data["r16"] = 1742;
points[1059]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 2; p.county = 0; p.val = 1745; p.data["black"] = 235; p.data["white"] = 1475; p.data["r"] = 96; p.data["d"] = 553; p.data["d16"] = 182; p.data["r16"] = 1427;
points[1060]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 6; p.county = 0; p.val = 995; p.data["black"] = 25; p.data["white"] = 885; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1061]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 2; p.county = 0; p.val = 945; p.data["black"] = 90; p.data["white"] = 840; p.data["r"] = 140; p.data["d"] = 308; p.data["d16"] = 173; p.data["r16"] = 446;
points[1062]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 15; p.county = 0; p.val = 2310; p.data["black"] = 240; p.data["white"] = 1960; p.data["r"] = 98; p.data["d"] = 551; p.data["d16"] = 169; p.data["r16"] = 724;
points[1063]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 3; p.county = 0; p.val = 1370; p.data["black"] = 630; p.data["white"] = 600; p.data["r"] = 498; p.data["d"] = 1186; p.data["d16"] = 309; p.data["r16"] = 307;
points[1064]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 8; p.county = 0; p.val = 800; p.data["black"] = 10; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1065]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 3; p.county = 0; p.val = 1630; p.data["black"] = 115; p.data["white"] = 1355; p.data["r"] = 220; p.data["d"] = 1094; p.data["d16"] = 254; p.data["r16"] = 1424;
points[1066]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 4; p.county = 0; p.val = 1470; p.data["black"] = 30; p.data["white"] = 1440; p.data["r"] = 81; p.data["d"] = 570; p.data["d16"] = 103; p.data["r16"] = 759;
points[1067]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 9; p.county = 0; p.val = 1055; p.data["black"] = 50; p.data["white"] = 1005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1068]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 6; p.county = 0; p.val = 840; p.data["black"] = 280; p.data["white"] = 515; p.data["r"] = 370; p.data["d"] = 322; p.data["d16"] = 543; p.data["r16"] = 419;
points[1069]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 8; p.county = 0; p.val = 550; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1070]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 13; p.county = 0; p.val = 765; p.data["black"] = 35; p.data["white"] = 710; p.data["r"] = 22; p.data["d"] = 296; p.data["d16"] = 19; p.data["r16"] = 379;
points[1071]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 7; p.county = 0; p.val = 805; p.data["black"] = 65; p.data["white"] = 745; p.data["r"] = 161; p.data["d"] = 610; p.data["d16"] = 169; p.data["r16"] = 768;
points[1072]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 152; p.county = 0; p.val = 390; p.data["black"] = 130; p.data["white"] = 235; p.data["r"] = 470; p.data["d"] = 489; p.data["d16"] = 470; p.data["r16"] = 604;
points[1073]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 85; p.county = 0; p.val = 1620; p.data["black"] = 125; p.data["white"] = 1435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 196; p.data["r16"] = 890;
points[1074]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 157; p.county = 0; p.val = 1550; p.data["black"] = 130; p.data["white"] = 1420; p.data["r"] = 591; p.data["d"] = 430; p.data["d16"] = 554; p.data["r16"] = 466;
points[1075]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 158; p.county = 0; p.val = 600; p.data["black"] = 420; p.data["white"] = 180; p.data["r"] = 2168; p.data["d"] = 1295; p.data["d16"] = 2749; p.data["r16"] = 2408;
points[1076]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 156; p.county = 0; p.val = 4195; p.data["black"] = 1050; p.data["white"] = 3025; p.data["r"] = 1732; p.data["d"] = 1208; p.data["d16"] = 1026; p.data["r16"] = 987;
points[1077]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 159; p.county = 0; p.val = 1860; p.data["black"] = 590; p.data["white"] = 1070; p.data["r"] = 1037; p.data["d"] = 911; p.data["d16"] = 734; p.data["r16"] = 1040;
points[1078]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 150; p.county = 0; p.val = 530; p.data["black"] = 25; p.data["white"] = 470; p.data["r"] = 759; p.data["d"] = 149; p.data["d16"] = 454; p.data["r16"] = 105;
points[1079]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 75; p.county = 0; p.val = 2730; p.data["black"] = 125; p.data["white"] = 2520; p.data["r"] = 1018; p.data["d"] = 811; p.data["d16"] = 303; p.data["r16"] = 493;
points[1080]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 72; p.county = 0; p.val = 1950; p.data["black"] = 340; p.data["white"] = 1495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1299; p.data["r16"] = 233;
points[1081]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 73; p.county = 0; p.val = 1345; p.data["black"] = 645; p.data["white"] = 560; p.data["r"] = 968; p.data["d"] = 288; p.data["d16"] = 1190; p.data["r16"] = 380;
points[1082]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 74; p.county = 0; p.val = 9305; p.data["black"] = 2795; p.data["white"] = 4160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1083]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 13; p.county = 0; p.val = 1390; p.data["black"] = 335; p.data["white"] = 955; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 627; p.data["r16"] = 787;
points[1084]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 4; p.county = 0; p.val = 4530; p.data["black"] = 590; p.data["white"] = 3700; p.data["r"] = 999; p.data["d"] = 2098; p.data["d16"] = 597; p.data["r16"] = 1362;
points[1085]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 5; p.county = 0; p.val = 2960; p.data["black"] = 55; p.data["white"] = 2780; p.data["r"] = 491; p.data["d"] = 760; p.data["d16"] = 1025; p.data["r16"] = 2037;
points[1086]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 4; p.county = 0; p.val = 660; p.data["black"] = 440; p.data["white"] = 200; p.data["r"] = 337; p.data["d"] = 419; p.data["d16"] = 426; p.data["r16"] = 542;
points[1087]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 4; p.county = 0; p.val = 1185; p.data["black"] = 220; p.data["white"] = 900; p.data["r"] = 247; p.data["d"] = 430; p.data["d16"] = 248; p.data["r16"] = 532;
points[1088]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 18; p.county = 0; p.val = 1490; p.data["black"] = 55; p.data["white"] = 930; p.data["r"] = 370; p.data["d"] = 820; p.data["d16"] = 71; p.data["r16"] = 129;
points[1089]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 45; p.county = 0; p.val = 1095; p.data["black"] = 370; p.data["white"] = 680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1090]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 24; p.county = 0; p.val = 2840; p.data["black"] = 1115; p.data["white"] = 1665; p.data["r"] = 892; p.data["d"] = 185; p.data["d16"] = 961; p.data["r16"] = 179;
points[1091]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 18; p.county = 0; p.val = 3580; p.data["black"] = 79; p.data["white"] = 3035; p.data["r"] = 386; p.data["d"] = 551; p.data["d16"] = 392; p.data["r16"] = 715;
points[1092]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 19; p.county = 0; p.val = 1895; p.data["black"] = 205; p.data["white"] = 1510; p.data["r"] = 919; p.data["d"] = 1472; p.data["d16"] = 270; p.data["r16"] = 730;
points[1093]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 19; p.county = 0; p.val = 1365; p.data["black"] = 60; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 604; p.data["r16"] = 1578;
points[1094]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 20; p.county = 0; p.val = 5790; p.data["black"] = 315; p.data["white"] = 4825; p.data["r"] = 477; p.data["d"] = 557; p.data["d16"] = 427; p.data["r16"] = 756;
points[1095]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 18; p.county = 0; p.val = 3405; p.data["black"] = 285; p.data["white"] = 2800; p.data["r"] = 760; p.data["d"] = 1410; p.data["d16"] = 702; p.data["r16"] = 1635;
points[1096]=p;}
if (1==1){ Point p;
p.x = 196; p.y = 85; p.county = 0; p.val = 1475; p.data["black"] = 155; p.data["white"] = 1125; p.data["r"] = 297; p.data["d"] = 627; p.data["d16"] = 666; p.data["r16"] = 998;
points[1097]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 19; p.county = 0; p.val = 2100; p.data["black"] = 40; p.data["white"] = 1920; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 652; p.data["r16"] = 867;
points[1098]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 19; p.county = 0; p.val = 3190; p.data["black"] = 580; p.data["white"] = 2325; p.data["r"] = 1055; p.data["d"] = 1488; p.data["d16"] = 457; p.data["r16"] = 975;
points[1099]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 20; p.county = 0; p.val = 5310; p.data["black"] = 195; p.data["white"] = 4780; p.data["r"] = 996; p.data["d"] = 931; p.data["d16"] = 1153; p.data["r16"] = 1534;
points[1100]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 11; p.county = 0; p.val = 1025; p.data["black"] = 30; p.data["white"] = 955; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1101]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 21; p.county = 0; p.val = 3525; p.data["black"] = 765; p.data["white"] = 2530; p.data["r"] = 830; p.data["d"] = 495; p.data["d16"] = 1652; p.data["r16"] = 581;
points[1102]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 22; p.county = 0; p.val = 3190; p.data["black"] = 1280; p.data["white"] = 1790; p.data["r"] = 1620; p.data["d"] = 938; p.data["d16"] = 824; p.data["r16"] = 1100;
points[1103]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 96; p.county = 0; p.val = 125; p.data["black"] = 0; p.data["white"] = 120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1104]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 86; p.county = 0; p.val = 595; p.data["black"] = 0; p.data["white"] = 585; p.data["r"] = 165; p.data["d"] = 559; p.data["d16"] = 265; p.data["r16"] = 993;
points[1105]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 22; p.county = 0; p.val = 2955; p.data["black"] = 1185; p.data["white"] = 1630; p.data["r"] = 1503; p.data["d"] = 809; p.data["d16"] = 507; p.data["r16"] = 698;
points[1106]=p;}
if (1==1){ Point p;
p.x = 192; p.y = 81; p.county = 0; p.val = 1230; p.data["black"] = 475; p.data["white"] = 750; p.data["r"] = 436; p.data["d"] = 446; p.data["d16"] = 507; p.data["r16"] = 478;
points[1107]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 19; p.county = 0; p.val = 1250; p.data["black"] = 345; p.data["white"] = 840; p.data["r"] = 1284; p.data["d"] = 1254; p.data["d16"] = 1245; p.data["r16"] = 1459;
points[1108]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 20; p.county = 0; p.val = 3115; p.data["black"] = 725; p.data["white"] = 2320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 681; p.data["r16"] = 360;
points[1109]=p;}
if (1==1){ Point p;
p.x = 189; p.y = 88; p.county = 0; p.val = 3715; p.data["black"] = 110; p.data["white"] = 3395; p.data["r"] = 229; p.data["d"] = 601; p.data["d16"] = 199; p.data["r16"] = 685;
points[1110]=p;}
if (1==1){ Point p;
p.x = 188; p.y = 72; p.county = 0; p.val = 1230; p.data["black"] = 145; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 556; p.data["r16"] = 1076;
points[1111]=p;}
if (1==1){ Point p;
p.x = 178; p.y = 77; p.county = 0; p.val = 750; p.data["black"] = 130; p.data["white"] = 610; p.data["r"] = 45; p.data["d"] = 360; p.data["d16"] = 54; p.data["r16"] = 489;
points[1112]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 89; p.county = 0; p.val = 2620; p.data["black"] = 685; p.data["white"] = 1785; p.data["r"] = 125; p.data["d"] = 301; p.data["d16"] = 174; p.data["r16"] = 492;
points[1113]=p;}
if (1==1){ Point p;
p.x = 196; p.y = 84; p.county = 0; p.val = 2700; p.data["black"] = 705; p.data["white"] = 1885; p.data["r"] = 1013; p.data["d"] = 1706; p.data["d16"] = 0; p.data["r16"] = 0;
points[1114]=p;}
if (1==1){ Point p;
p.x = 198; p.y = 82; p.county = 0; p.val = 1205; p.data["black"] = 200; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 252; p.data["r16"] = 756;
points[1115]=p;}
if (1==1){ Point p;
p.x = 197; p.y = 83; p.county = 0; p.val = 1905; p.data["black"] = 90; p.data["white"] = 1680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 834; p.data["r16"] = 2216;
points[1116]=p;}
if (1==1){ Point p;
p.x = 198; p.y = 86; p.county = 0; p.val = 1765; p.data["black"] = 310; p.data["white"] = 1425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1117]=p;}
if (1==1){ Point p;
p.x = 196; p.y = 86; p.county = 0; p.val = 1160; p.data["black"] = 80; p.data["white"] = 1080; p.data["r"] = 596; p.data["d"] = 824; p.data["d16"] = 0; p.data["r16"] = 0;
points[1118]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 92; p.county = 0; p.val = 3570; p.data["black"] = 125; p.data["white"] = 3425; p.data["r"] = 594; p.data["d"] = 1212; p.data["d16"] = 557; p.data["r16"] = 1431;
points[1119]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 20; p.county = 0; p.val = 3520; p.data["black"] = 245; p.data["white"] = 2955; p.data["r"] = 1029; p.data["d"] = 1023; p.data["d16"] = 834; p.data["r16"] = 810;
points[1120]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 21; p.county = 0; p.val = 4045; p.data["black"] = 1010; p.data["white"] = 2715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1121]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 95; p.county = 0; p.val = 2300; p.data["black"] = 125; p.data["white"] = 1945; p.data["r"] = 195; p.data["d"] = 523; p.data["d16"] = 211; p.data["r16"] = 798;
points[1122]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 85; p.county = 0; p.val = 1440; p.data["black"] = 60; p.data["white"] = 1355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 416; p.data["r16"] = 930;
points[1123]=p;}
if (1==1){ Point p;
p.x = 178; p.y = 82; p.county = 0; p.val = 1265; p.data["black"] = 155; p.data["white"] = 1110; p.data["r"] = 266; p.data["d"] = 471; p.data["d16"] = 288; p.data["r16"] = 619;
points[1124]=p;}
if (1==1){ Point p;
p.x = 178; p.y = 85; p.county = 0; p.val = 1555; p.data["black"] = 305; p.data["white"] = 1185; p.data["r"] = 326; p.data["d"] = 252; p.data["d16"] = 347; p.data["r16"] = 310;
points[1125]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 88; p.county = 0; p.val = 1880; p.data["black"] = 325; p.data["white"] = 1415; p.data["r"] = 699; p.data["d"] = 782; p.data["d16"] = 663; p.data["r16"] = 999;
points[1126]=p;}
if (1==1){ Point p;
p.x = 195; p.y = 78; p.county = 0; p.val = 1115; p.data["black"] = 20; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 335; p.data["r16"] = 953;
points[1127]=p;}
if (1==1){ Point p;
p.x = 189; p.y = 84; p.county = 0; p.val = 2415; p.data["black"] = 720; p.data["white"] = 1695; p.data["r"] = 555; p.data["d"] = 662; p.data["d16"] = 352; p.data["r16"] = 481;
points[1128]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 61; p.county = 0; p.val = 645; p.data["black"] = 110; p.data["white"] = 490; p.data["r"] = 44; p.data["d"] = 157; p.data["d16"] = 42; p.data["r16"] = 219;
points[1129]=p;}
if (1==1){ Point p;
p.x = 186; p.y = 92; p.county = 0; p.val = 6345; p.data["black"] = 770; p.data["white"] = 5190; p.data["r"] = 1394; p.data["d"] = 2437; p.data["d16"] = 990; p.data["r16"] = 2192;
points[1130]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 93; p.county = 0; p.val = 1440; p.data["black"] = 230; p.data["white"] = 1155; p.data["r"] = 381; p.data["d"] = 836; p.data["d16"] = 178; p.data["r16"] = 482;
points[1131]=p;}
if (1==1){ Point p;
p.x = 186; p.y = 95; p.county = 0; p.val = 1020; p.data["black"] = 135; p.data["white"] = 840; p.data["r"] = 340; p.data["d"] = 152; p.data["d16"] = 499; p.data["r16"] = 437;
points[1132]=p;}
if (1==1){ Point p;
p.x = 186; p.y = 96; p.county = 0; p.val = 1475; p.data["black"] = 70; p.data["white"] = 1275; p.data["r"] = 316; p.data["d"] = 302; p.data["d16"] = 0; p.data["r16"] = 0;
points[1133]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 94; p.county = 0; p.val = 3340; p.data["black"] = 290; p.data["white"] = 2945; p.data["r"] = 586; p.data["d"] = 1051; p.data["d16"] = 678; p.data["r16"] = 1508;
points[1134]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 195; p.county = 0; p.val = 1050; p.data["black"] = 0; p.data["white"] = 1045; p.data["r"] = 292; p.data["d"] = 506; p.data["d16"] = 330; p.data["r16"] = 629;
points[1135]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 83; p.county = 0; p.val = 2170; p.data["black"] = 160; p.data["white"] = 1900; p.data["r"] = 234; p.data["d"] = 575; p.data["d16"] = 243; p.data["r16"] = 665;
points[1136]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 22; p.county = 0; p.val = 3025; p.data["black"] = 1415; p.data["white"] = 1515; p.data["r"] = 616; p.data["d"] = 810; p.data["d16"] = 567; p.data["r16"] = 967;
points[1137]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 140; p.county = 0; p.val = 2575; p.data["black"] = 515; p.data["white"] = 1905; p.data["r"] = 490; p.data["d"] = 415; p.data["d16"] = 534; p.data["r16"] = 525;
points[1138]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 186; p.county = 0; p.val = 2070; p.data["black"] = 60; p.data["white"] = 1955; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1139]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 177; p.county = 0; p.val = 1315; p.data["black"] = 165; p.data["white"] = 1065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1140]=p;}
if (1==1){ Point p;
p.x = 118; p.y = 179; p.county = 0; p.val = 2460; p.data["black"] = 2015; p.data["white"] = 420; p.data["r"] = 1172; p.data["d"] = 483; p.data["d16"] = 1182; p.data["r16"] = 506;
points[1141]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 192; p.county = 0; p.val = 740; p.data["black"] = 0; p.data["white"] = 735; p.data["r"] = 377; p.data["d"] = 309; p.data["d16"] = 423; p.data["r16"] = 417;
points[1142]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 191; p.county = 0; p.val = 895; p.data["black"] = 195; p.data["white"] = 680; p.data["r"] = 557; p.data["d"] = 738; p.data["d16"] = 515; p.data["r16"] = 910;
points[1143]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 175; p.county = 0; p.val = 985; p.data["black"] = 165; p.data["white"] = 820; p.data["r"] = 225; p.data["d"] = 364; p.data["d16"] = 195; p.data["r16"] = 386;
points[1144]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 180; p.county = 0; p.val = 1330; p.data["black"] = 200; p.data["white"] = 1085; p.data["r"] = 1228; p.data["d"] = 1647; p.data["d16"] = 1205; p.data["r16"] = 1907;
points[1145]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 170; p.county = 0; p.val = 1055; p.data["black"] = 510; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1146]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 175; p.county = 0; p.val = 1165; p.data["black"] = 30; p.data["white"] = 1130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1147]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 186; p.county = 0; p.val = 1635; p.data["black"] = 45; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1148]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 187; p.county = 0; p.val = 1780; p.data["black"] = 10; p.data["white"] = 1730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1149]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 192; p.county = 0; p.val = 470; p.data["black"] = 0; p.data["white"] = 455; p.data["r"] = 265; p.data["d"] = 379; p.data["d16"] = 273; p.data["r16"] = 461;
points[1150]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 191; p.county = 0; p.val = 2505; p.data["black"] = 165; p.data["white"] = 2165; p.data["r"] = 656; p.data["d"] = 950; p.data["d16"] = 1044; p.data["r16"] = 1528;
points[1151]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 162; p.county = 0; p.val = 1060; p.data["black"] = 930; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1152]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 176; p.county = 0; p.val = 1060; p.data["black"] = 605; p.data["white"] = 365; p.data["r"] = 212; p.data["d"] = 365; p.data["d16"] = 231; p.data["r16"] = 397;
points[1153]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 178; p.county = 0; p.val = 1930; p.data["black"] = 585; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1154]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 176; p.county = 0; p.val = 1220; p.data["black"] = 355; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1155]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 168; p.county = 0; p.val = 1030; p.data["black"] = 665; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1156]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 175; p.county = 0; p.val = 1545; p.data["black"] = 305; p.data["white"] = 1200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1157]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 190; p.county = 0; p.val = 640; p.data["black"] = 0; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1158]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 176; p.county = 0; p.val = 550; p.data["black"] = 260; p.data["white"] = 270; p.data["r"] = 590; p.data["d"] = 996; p.data["d16"] = 488; p.data["r16"] = 1169;
points[1159]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 195; p.county = 0; p.val = 825; p.data["black"] = 0; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1160]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 116; p.county = 0; p.val = 880; p.data["black"] = 685; p.data["white"] = 195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1161]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 178; p.county = 0; p.val = 875; p.data["black"] = 395; p.data["white"] = 455; p.data["r"] = 495; p.data["d"] = 115; p.data["d16"] = 512; p.data["r16"] = 129;
points[1162]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 178; p.county = 0; p.val = 1535; p.data["black"] = 770; p.data["white"] = 685; p.data["r"] = 626; p.data["d"] = 410; p.data["d16"] = 657; p.data["r16"] = 463;
points[1163]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 179; p.county = 0; p.val = 1625; p.data["black"] = 510; p.data["white"] = 1045; p.data["r"] = 605; p.data["d"] = 953; p.data["d16"] = 579; p.data["r16"] = 1033;
points[1164]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 196; p.county = 0; p.val = 480; p.data["black"] = 10; p.data["white"] = 460; p.data["r"] = 1159; p.data["d"] = 1399; p.data["d16"] = 1484; p.data["r16"] = 2129;
points[1165]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 187; p.county = 0; p.val = 2685; p.data["black"] = 245; p.data["white"] = 2155; p.data["r"] = 600; p.data["d"] = 885; p.data["d16"] = 240; p.data["r16"] = 420;
points[1166]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 140; p.county = 0; p.val = 2755; p.data["black"] = 745; p.data["white"] = 1825; p.data["r"] = 552; p.data["d"] = 627; p.data["d16"] = 625; p.data["r16"] = 830;
points[1167]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 135; p.county = 0; p.val = 1490; p.data["black"] = 385; p.data["white"] = 1030; p.data["r"] = 517; p.data["d"] = 596; p.data["d16"] = 446; p.data["r16"] = 719;
points[1168]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 138; p.county = 0; p.val = 1600; p.data["black"] = 385; p.data["white"] = 1170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1169]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 139; p.county = 0; p.val = 2225; p.data["black"] = 530; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1170]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 138; p.county = 0; p.val = 1485; p.data["black"] = 90; p.data["white"] = 1330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1171]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 141; p.county = 0; p.val = 2250; p.data["black"] = 595; p.data["white"] = 1405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1172]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 132; p.county = 0; p.val = 520; p.data["black"] = 140; p.data["white"] = 380; p.data["r"] = 76; p.data["d"] = 78; p.data["d16"] = 89; p.data["r16"] = 85;
points[1173]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 120; p.county = 0; p.val = 1475; p.data["black"] = 1290; p.data["white"] = 145; p.data["r"] = 850; p.data["d"] = 214; p.data["d16"] = 0; p.data["r16"] = 0;
points[1174]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 127; p.county = 0; p.val = 715; p.data["black"] = 150; p.data["white"] = 545; p.data["r"] = 74; p.data["d"] = 155; p.data["d16"] = 75; p.data["r16"] = 164;
points[1175]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 121; p.county = 0; p.val = 550; p.data["black"] = 390; p.data["white"] = 160; p.data["r"] = 177; p.data["d"] = 92; p.data["d16"] = 538; p.data["r16"] = 574;
points[1176]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 145; p.county = 0; p.val = 2560; p.data["black"] = 215; p.data["white"] = 2250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 446; p.data["r16"] = 598;
points[1177]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 126; p.county = 0; p.val = 1790; p.data["black"] = 595; p.data["white"] = 1135; p.data["r"] = 237; p.data["d"] = 689; p.data["d16"] = 199; p.data["r16"] = 894;
points[1178]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 86; p.county = 0; p.val = 500; p.data["black"] = 265; p.data["white"] = 235; p.data["r"] = 263; p.data["d"] = 209; p.data["d16"] = 315; p.data["r16"] = 253;
points[1179]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 69; p.county = 0; p.val = 920; p.data["black"] = 95; p.data["white"] = 810; p.data["r"] = 132; p.data["d"] = 636; p.data["d16"] = 107; p.data["r16"] = 771;
points[1180]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 73; p.county = 0; p.val = 1025; p.data["black"] = 290; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1181]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 74; p.county = 0; p.val = 1325; p.data["black"] = 0; p.data["white"] = 1310; p.data["r"] = 138; p.data["d"] = 712; p.data["d16"] = 82; p.data["r16"] = 591;
points[1182]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 82; p.county = 0; p.val = 1260; p.data["black"] = 165; p.data["white"] = 1065; p.data["r"] = 196; p.data["d"] = 364; p.data["d16"] = 91; p.data["r16"] = 359;
points[1183]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 146; p.county = 0; p.val = 930; p.data["black"] = 125; p.data["white"] = 615; p.data["r"] = 261; p.data["d"] = 32; p.data["d16"] = 669; p.data["r16"] = 248;
points[1184]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 146; p.county = 0; p.val = 275; p.data["black"] = 150; p.data["white"] = 125; p.data["r"] = 720; p.data["d"] = 1010; p.data["d16"] = 345; p.data["r16"] = 481;
points[1185]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 123; p.county = 0; p.val = 265; p.data["black"] = 265; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1186]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 122; p.county = 0; p.val = 445; p.data["black"] = 280; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1187]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 119; p.county = 0; p.val = 770; p.data["black"] = 655; p.data["white"] = 115; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1188]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 119; p.county = 0; p.val = 670; p.data["black"] = 655; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 761; p.data["r16"] = 108;
points[1189]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 121; p.county = 0; p.val = 805; p.data["black"] = 205; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1190]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 119; p.county = 0; p.val = 725; p.data["black"] = 240; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1191]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 125; p.county = 0; p.val = 1050; p.data["black"] = 875; p.data["white"] = 170; p.data["r"] = 527; p.data["d"] = 187; p.data["d16"] = 960; p.data["r16"] = 282;
points[1192]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 117; p.county = 0; p.val = 595; p.data["black"] = 175; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1193]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 121; p.county = 0; p.val = 690; p.data["black"] = 660; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 938; p.data["r16"] = 183;
points[1194]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 131; p.county = 0; p.val = 575; p.data["black"] = 155; p.data["white"] = 400; p.data["r"] = 104; p.data["d"] = 130; p.data["d16"] = 162; p.data["r16"] = 252;
points[1195]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 126; p.county = 0; p.val = 390; p.data["black"] = 125; p.data["white"] = 255; p.data["r"] = 70; p.data["d"] = 29; p.data["d16"] = 77; p.data["r16"] = 41;
points[1196]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 133; p.county = 0; p.val = 565; p.data["black"] = 250; p.data["white"] = 300; p.data["r"] = 286; p.data["d"] = 356; p.data["d16"] = 243; p.data["r16"] = 302;
points[1197]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 59; p.county = 0; p.val = 935; p.data["black"] = 400; p.data["white"] = 530; p.data["r"] = 152; p.data["d"] = 127; p.data["d16"] = 269; p.data["r16"] = 333;
points[1198]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 57; p.county = 0; p.val = 525; p.data["black"] = 70; p.data["white"] = 455; p.data["r"] = 55; p.data["d"] = 210; p.data["d16"] = 270; p.data["r16"] = 608;
points[1199]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 62; p.county = 0; p.val = 550; p.data["black"] = 270; p.data["white"] = 285; p.data["r"] = 188; p.data["d"] = 89; p.data["d16"] = 217; p.data["r16"] = 108;
points[1200]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 57; p.county = 0; p.val = 835; p.data["black"] = 275; p.data["white"] = 515; p.data["r"] = 77; p.data["d"] = 116; p.data["d16"] = 114; p.data["r16"] = 177;
points[1201]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 61; p.county = 0; p.val = 1060; p.data["black"] = 800; p.data["white"] = 260; p.data["r"] = 417; p.data["d"] = 90; p.data["d16"] = 516; p.data["r16"] = 121;
points[1202]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 68; p.county = 0; p.val = 765; p.data["black"] = 545; p.data["white"] = 135; p.data["r"] = 269; p.data["d"] = 29; p.data["d16"] = 505; p.data["r16"] = 56;
points[1203]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 63; p.county = 0; p.val = 540; p.data["black"] = 435; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1204]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 69; p.county = 0; p.val = 970; p.data["black"] = 515; p.data["white"] = 455; p.data["r"] = 198; p.data["d"] = 262; p.data["d16"] = 146; p.data["r16"] = 300;
points[1205]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 63; p.county = 0; p.val = 825; p.data["black"] = 470; p.data["white"] = 325; p.data["r"] = 228; p.data["d"] = 271; p.data["d16"] = 303; p.data["r16"] = 377;
points[1206]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 72; p.county = 0; p.val = 500; p.data["black"] = 435; p.data["white"] = 60; p.data["r"] = 356; p.data["d"] = 66; p.data["d16"] = 484; p.data["r16"] = 70;
points[1207]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 64; p.county = 0; p.val = 2150; p.data["black"] = 1630; p.data["white"] = 430; p.data["r"] = 439; p.data["d"] = 78; p.data["d16"] = 321; p.data["r16"] = 67;
points[1208]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 44; p.county = 0; p.val = 1000; p.data["black"] = 290; p.data["white"] = 605; p.data["r"] = 517; p.data["d"] = 825; p.data["d16"] = 635; p.data["r16"] = 640;
points[1209]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 29; p.county = 0; p.val = 1165; p.data["black"] = 30; p.data["white"] = 1095; p.data["r"] = 411; p.data["d"] = 795; p.data["d16"] = 597; p.data["r16"] = 644;
points[1210]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 30; p.county = 0; p.val = 1280; p.data["black"] = 350; p.data["white"] = 865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 286; p.data["r16"] = 682;
points[1211]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 31; p.county = 0; p.val = 1910; p.data["black"] = 405; p.data["white"] = 1395; p.data["r"] = 719; p.data["d"] = 896; p.data["d16"] = 677; p.data["r16"] = 1152;
points[1212]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 30; p.county = 0; p.val = 855; p.data["black"] = 490; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1213]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 66; p.county = 0; p.val = 915; p.data["black"] = 325; p.data["white"] = 550; p.data["r"] = 289; p.data["d"] = 156; p.data["d16"] = 372; p.data["r16"] = 218;
points[1214]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 31; p.county = 0; p.val = 860; p.data["black"] = 460; p.data["white"] = 400; p.data["r"] = 678; p.data["d"] = 327; p.data["d16"] = 391; p.data["r16"] = 275;
points[1215]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 31; p.county = 0; p.val = 1170; p.data["black"] = 675; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1216]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 71; p.county = 0; p.val = 4445; p.data["black"] = 2795; p.data["white"] = 1330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1217]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 140; p.county = 0; p.val = 2150; p.data["black"] = 980; p.data["white"] = 990; p.data["r"] = 1203; p.data["d"] = 1167; p.data["d16"] = 760; p.data["r16"] = 1166;
points[1218]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 151; p.county = 0; p.val = 1050; p.data["black"] = 0; p.data["white"] = 935; p.data["r"] = 1020; p.data["d"] = 990; p.data["d16"] = 0; p.data["r16"] = 0;
points[1219]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 32; p.county = 0; p.val = 4265; p.data["black"] = 180; p.data["white"] = 3775; p.data["r"] = 204; p.data["d"] = 172; p.data["d16"] = 616; p.data["r16"] = 544;
points[1220]=p;}
if (1==1){ Point p;
p.x = 162; p.y = 61; p.county = 0; p.val = 1050; p.data["black"] = 405; p.data["white"] = 640; p.data["r"] = 118; p.data["d"] = 26; p.data["d16"] = 133; p.data["r16"] = 44;
points[1221]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 30; p.county = 0; p.val = 410; p.data["black"] = 385; p.data["white"] = 20; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1222]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 56; p.county = 0; p.val = 775; p.data["black"] = 85; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1223]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 30; p.county = 0; p.val = 1445; p.data["black"] = 960; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1224]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 55; p.county = 0; p.val = 1065; p.data["black"] = 300; p.data["white"] = 740; p.data["r"] = 566; p.data["d"] = 706; p.data["d16"] = 581; p.data["r16"] = 871;
points[1225]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 28; p.county = 0; p.val = 785; p.data["black"] = 395; p.data["white"] = 305; p.data["r"] = 1270; p.data["d"] = 665; p.data["d16"] = 1398; p.data["r16"] = 917;
points[1226]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 21; p.county = 0; p.val = 2780; p.data["black"] = 1790; p.data["white"] = 825; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 986; p.data["r16"] = 301;
points[1227]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 30; p.county = 0; p.val = 625; p.data["black"] = 155; p.data["white"] = 465; p.data["r"] = 252; p.data["d"] = 256; p.data["d16"] = 0; p.data["r16"] = 0;
points[1228]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 78; p.county = 0; p.val = 1685; p.data["black"] = 660; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1229]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 73; p.county = 0; p.val = 1755; p.data["black"] = 220; p.data["white"] = 1340; p.data["r"] = 1287; p.data["d"] = 1102; p.data["d16"] = 723; p.data["r16"] = 455;
points[1230]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 77; p.county = 0; p.val = 2605; p.data["black"] = 285; p.data["white"] = 2140; p.data["r"] = 828; p.data["d"] = 459; p.data["d16"] = 870; p.data["r16"] = 464;
points[1231]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 153; p.county = 0; p.val = 1665; p.data["black"] = 0; p.data["white"] = 1645; p.data["r"] = 852; p.data["d"] = 1066; p.data["d16"] = 711; p.data["r16"] = 1066;
points[1232]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 154; p.county = 0; p.val = 700; p.data["black"] = 85; p.data["white"] = 615; p.data["r"] = 1222; p.data["d"] = 1332; p.data["d16"] = 1204; p.data["r16"] = 1541;
points[1233]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 146; p.county = 0; p.val = 3495; p.data["black"] = 1425; p.data["white"] = 1855; p.data["r"] = 1091; p.data["d"] = 404; p.data["d16"] = 957; p.data["r16"] = 397;
points[1234]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 31; p.county = 0; p.val = 1260; p.data["black"] = 480; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1235]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 18; p.county = 0; p.val = 1675; p.data["black"] = 70; p.data["white"] = 1505; p.data["r"] = 393; p.data["d"] = 698; p.data["d16"] = 414; p.data["r16"] = 851;
points[1236]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 152; p.county = 0; p.val = 4225; p.data["black"] = 600; p.data["white"] = 3255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 417; p.data["r16"] = 51;
points[1237]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 148; p.county = 0; p.val = 1770; p.data["black"] = 1355; p.data["white"] = 360; p.data["r"] = 369; p.data["d"] = 323; p.data["d16"] = 994; p.data["r16"] = 397;
points[1238]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 153; p.county = 0; p.val = 3005; p.data["black"] = 240; p.data["white"] = 2675; p.data["r"] = 1075; p.data["d"] = 1159; p.data["d16"] = 772; p.data["r16"] = 884;
points[1239]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 19; p.county = 0; p.val = 2075; p.data["black"] = 270; p.data["white"] = 1555; p.data["r"] = 927; p.data["d"] = 313; p.data["d16"] = 980; p.data["r16"] = 409;
points[1240]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 143; p.county = 0; p.val = 3965; p.data["black"] = 975; p.data["white"] = 2545; p.data["r"] = 340; p.data["d"] = 220; p.data["d16"] = 372; p.data["r16"] = 354;
points[1241]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 151; p.county = 0; p.val = 780; p.data["black"] = 220; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1242]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 162; p.county = 0; p.val = 925; p.data["black"] = 0; p.data["white"] = 890; p.data["r"] = 453; p.data["d"] = 81; p.data["d16"] = 400; p.data["r16"] = 79;
points[1243]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 166; p.county = 0; p.val = 1010; p.data["black"] = 4; p.data["white"] = 1005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1244]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 155; p.county = 0; p.val = 2285; p.data["black"] = 530; p.data["white"] = 1680; p.data["r"] = 634; p.data["d"] = 455; p.data["d16"] = 699; p.data["r16"] = 724;
points[1245]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 162; p.county = 0; p.val = 1075; p.data["black"] = 255; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1246]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 154; p.county = 0; p.val = 1490; p.data["black"] = 170; p.data["white"] = 1050; p.data["r"] = 2249; p.data["d"] = 714; p.data["d16"] = 878; p.data["r16"] = 322;
points[1247]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 143; p.county = 0; p.val = 4960; p.data["black"] = 1235; p.data["white"] = 3340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1248]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 149; p.county = 0; p.val = 1970; p.data["black"] = 235; p.data["white"] = 1715; p.data["r"] = 436; p.data["d"] = 530; p.data["d16"] = 423; p.data["r16"] = 726;
points[1249]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 164; p.county = 0; p.val = 995; p.data["black"] = 4; p.data["white"] = 970; p.data["r"] = 394; p.data["d"] = 232; p.data["d16"] = 389; p.data["r16"] = 311;
points[1250]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 165; p.county = 0; p.val = 160; p.data["black"] = 15; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1251]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 149; p.county = 0; p.val = 1230; p.data["black"] = 115; p.data["white"] = 980; p.data["r"] = 496; p.data["d"] = 163; p.data["d16"] = 634; p.data["r16"] = 220;
points[1252]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 152; p.county = 0; p.val = 1655; p.data["black"] = 45; p.data["white"] = 1515; p.data["r"] = 589; p.data["d"] = 814; p.data["d16"] = 0; p.data["r16"] = 0;
points[1253]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 147; p.county = 0; p.val = 5395; p.data["black"] = 80; p.data["white"] = 5305; p.data["r"] = 1704; p.data["d"] = 2609; p.data["d16"] = 1439; p.data["r16"] = 2746;
points[1254]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 149; p.county = 0; p.val = 4950; p.data["black"] = 825; p.data["white"] = 3905; p.data["r"] = 315; p.data["d"] = 497; p.data["d16"] = 760; p.data["r16"] = 1274;
points[1255]=p;}
if (1==1){ Point p;
p.x = 155; p.y = 137; p.county = 0; p.val = 1255; p.data["black"] = 580; p.data["white"] = 630; p.data["r"] = 291; p.data["d"] = 256; p.data["d16"] = 350; p.data["r16"] = 280;
points[1256]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 120; p.county = 0; p.val = 645; p.data["black"] = 270; p.data["white"] = 360; p.data["r"] = 195; p.data["d"] = 683; p.data["d16"] = 210; p.data["r16"] = 865;
points[1257]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 143; p.county = 0; p.val = 750; p.data["black"] = 135; p.data["white"] = 530; p.data["r"] = 657; p.data["d"] = 408; p.data["d16"] = 722; p.data["r16"] = 687;
points[1258]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 144; p.county = 0; p.val = 4410; p.data["black"] = 1415; p.data["white"] = 2605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1259]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 145; p.county = 0; p.val = 830; p.data["black"] = 170; p.data["white"] = 660; p.data["r"] = 747; p.data["d"] = 220; p.data["d16"] = 867; p.data["r16"] = 299;
points[1260]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 74; p.county = 0; p.val = 1870; p.data["black"] = 1050; p.data["white"] = 610; p.data["r"] = 41; p.data["d"] = 104; p.data["d16"] = 39; p.data["r16"] = 134;
points[1261]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 77; p.county = 0; p.val = 470; p.data["black"] = 230; p.data["white"] = 210; p.data["r"] = 593; p.data["d"] = 547; p.data["d16"] = 845; p.data["r16"] = 660;
points[1262]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 79; p.county = 0; p.val = 710; p.data["black"] = 150; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1263]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 33; p.county = 0; p.val = 1745; p.data["black"] = 330; p.data["white"] = 1340; p.data["r"] = 268; p.data["d"] = 411; p.data["d16"] = 365; p.data["r16"] = 539;
points[1264]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 25; p.county = 0; p.val = 645; p.data["black"] = 265; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1265]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 4; p.county = 0; p.val = 1610; p.data["black"] = 125; p.data["white"] = 1405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1266]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 10; p.county = 0; p.val = 1515; p.data["black"] = 270; p.data["white"] = 1245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1267]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 9; p.county = 0; p.val = 370; p.data["black"] = 0; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1268]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 10; p.county = 0; p.val = 1195; p.data["black"] = 270; p.data["white"] = 920; p.data["r"] = 50; p.data["d"] = 418; p.data["d16"] = 69; p.data["r16"] = 618;
points[1269]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 13; p.county = 0; p.val = 4485; p.data["black"] = 1405; p.data["white"] = 2815; p.data["r"] = 696; p.data["d"] = 556; p.data["d16"] = 0; p.data["r16"] = 0;
points[1270]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 28; p.county = 0; p.val = 1295; p.data["black"] = 60; p.data["white"] = 1175; p.data["r"] = 237; p.data["d"] = 515; p.data["d16"] = 0; p.data["r16"] = 0;
points[1271]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 17; p.county = 0; p.val = 835; p.data["black"] = 0; p.data["white"] = 835; p.data["r"] = 87; p.data["d"] = 562; p.data["d16"] = 92; p.data["r16"] = 684;
points[1272]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 21; p.county = 0; p.val = 985; p.data["black"] = 50; p.data["white"] = 850; p.data["r"] = 143; p.data["d"] = 613; p.data["d16"] = 172; p.data["r16"] = 840;
points[1273]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 18; p.county = 0; p.val = 1490; p.data["black"] = 10; p.data["white"] = 1480; p.data["r"] = 84; p.data["d"] = 476; p.data["d16"] = 98; p.data["r16"] = 646;
points[1274]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 24; p.county = 0; p.val = 885; p.data["black"] = 75; p.data["white"] = 780; p.data["r"] = 100; p.data["d"] = 313; p.data["d16"] = 119; p.data["r16"] = 493;
points[1275]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 32; p.county = 0; p.val = 3070; p.data["black"] = 285; p.data["white"] = 2605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1276]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 33; p.county = 0; p.val = 1620; p.data["black"] = 195; p.data["white"] = 1325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1277]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 20; p.county = 0; p.val = 1395; p.data["black"] = 20; p.data["white"] = 1375; p.data["r"] = 325; p.data["d"] = 1015; p.data["d16"] = 322; p.data["r16"] = 1330;
points[1278]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 24; p.county = 0; p.val = 2555; p.data["black"] = 4; p.data["white"] = 2435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1279]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 29; p.county = 0; p.val = 910; p.data["black"] = 4; p.data["white"] = 895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1280]=p;}
if (1==1){ Point p;
p.x = 118; p.y = 58; p.county = 0; p.val = 695; p.data["black"] = 80; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1281]=p;}
if (1==1){ Point p;
p.x = 154; p.y = 37; p.county = 0; p.val = 640; p.data["black"] = 280; p.data["white"] = 285; p.data["r"] = 412; p.data["d"] = 198; p.data["d16"] = 634; p.data["r16"] = 258;
points[1282]=p;}
if (1==1){ Point p;
p.x = 154; p.y = 36; p.county = 0; p.val = 760; p.data["black"] = 220; p.data["white"] = 540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1283]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 51; p.county = 0; p.val = 685; p.data["black"] = 175; p.data["white"] = 510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1284]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 66; p.county = 0; p.val = 715; p.data["black"] = 230; p.data["white"] = 465; p.data["r"] = 396; p.data["d"] = 406; p.data["d16"] = 463; p.data["r16"] = 539;
points[1285]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 56; p.county = 0; p.val = 995; p.data["black"] = 315; p.data["white"] = 520; p.data["r"] = 350; p.data["d"] = 432; p.data["d16"] = 0; p.data["r16"] = 0;
points[1286]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 41; p.county = 0; p.val = 1305; p.data["black"] = 115; p.data["white"] = 1180; p.data["r"] = 120; p.data["d"] = 429; p.data["d16"] = 149; p.data["r16"] = 571;
points[1287]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 59; p.county = 0; p.val = 1630; p.data["black"] = 290; p.data["white"] = 1205; p.data["r"] = 216; p.data["d"] = 276; p.data["d16"] = 742; p.data["r16"] = 745;
points[1288]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 48; p.county = 0; p.val = 1120; p.data["black"] = 435; p.data["white"] = 650; p.data["r"] = 327; p.data["d"] = 417; p.data["d16"] = 406; p.data["r16"] = 528;
points[1289]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 62; p.county = 0; p.val = 1550; p.data["black"] = 485; p.data["white"] = 1040; p.data["r"] = 170; p.data["d"] = 288; p.data["d16"] = 179; p.data["r16"] = 417;
points[1290]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 47; p.county = 0; p.val = 505; p.data["black"] = 200; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1291]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 60; p.county = 0; p.val = 685; p.data["black"] = 210; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 405; p.data["r16"] = 709;
points[1292]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 46; p.county = 0; p.val = 865; p.data["black"] = 75; p.data["white"] = 775; p.data["r"] = 42; p.data["d"] = 167; p.data["d16"] = 34; p.data["r16"] = 200;
points[1293]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 47; p.county = 0; p.val = 645; p.data["black"] = 80; p.data["white"] = 565; p.data["r"] = 270; p.data["d"] = 568; p.data["d16"] = 322; p.data["r16"] = 757;
points[1294]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 38; p.county = 0; p.val = 760; p.data["black"] = 145; p.data["white"] = 555; p.data["r"] = 74; p.data["d"] = 177; p.data["d16"] = 120; p.data["r16"] = 228;
points[1295]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 56; p.county = 0; p.val = 805; p.data["black"] = 185; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1296]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 57; p.county = 0; p.val = 515; p.data["black"] = 145; p.data["white"] = 375; p.data["r"] = 206; p.data["d"] = 389; p.data["d16"] = 449; p.data["r16"] = 467;
points[1297]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 58; p.county = 0; p.val = 520; p.data["black"] = 125; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1298]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 59; p.county = 0; p.val = 2060; p.data["black"] = 450; p.data["white"] = 1460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 187; p.data["r16"] = 426;
points[1299]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 59; p.county = 0; p.val = 655; p.data["black"] = 250; p.data["white"] = 405; p.data["r"] = 331; p.data["d"] = 527; p.data["d16"] = 0; p.data["r16"] = 0;
points[1300]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 55; p.county = 0; p.val = 1580; p.data["black"] = 280; p.data["white"] = 1260; p.data["r"] = 256; p.data["d"] = 458; p.data["d16"] = 311; p.data["r16"] = 658;
points[1301]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 84; p.county = 0; p.val = 760; p.data["black"] = 570; p.data["white"] = 190; p.data["r"] = 212; p.data["d"] = 118; p.data["d16"] = 262; p.data["r16"] = 143;
points[1302]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 59; p.county = 0; p.val = 1970; p.data["black"] = 720; p.data["white"] = 1245; p.data["r"] = 717; p.data["d"] = 603; p.data["d16"] = 0; p.data["r16"] = 0;
points[1303]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 60; p.county = 0; p.val = 885; p.data["black"] = 415; p.data["white"] = 415; p.data["r"] = 96; p.data["d"] = 80; p.data["d16"] = 107; p.data["r16"] = 147;
points[1304]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 29; p.county = 0; p.val = 745; p.data["black"] = 415; p.data["white"] = 330; p.data["r"] = 194; p.data["d"] = 148; p.data["d16"] = 242; p.data["r16"] = 178;
points[1305]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 25; p.county = 0; p.val = 1495; p.data["black"] = 80; p.data["white"] = 1365; p.data["r"] = 227; p.data["d"] = 467; p.data["d16"] = 494; p.data["r16"] = 1118;
points[1306]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 27; p.county = 0; p.val = 1235; p.data["black"] = 235; p.data["white"] = 1000; p.data["r"] = 200; p.data["d"] = 401; p.data["d16"] = 0; p.data["r16"] = 0;
points[1307]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 27; p.county = 0; p.val = 1465; p.data["black"] = 415; p.data["white"] = 1050; p.data["r"] = 270; p.data["d"] = 479; p.data["d16"] = 268; p.data["r16"] = 529;
points[1308]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 29; p.county = 0; p.val = 840; p.data["black"] = 290; p.data["white"] = 535; p.data["r"] = 92; p.data["d"] = 274; p.data["d16"] = 108; p.data["r16"] = 377;
points[1309]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 37; p.county = 0; p.val = 665; p.data["black"] = 50; p.data["white"] = 615; p.data["r"] = 149; p.data["d"] = 209; p.data["d16"] = 190; p.data["r16"] = 257;
points[1310]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 29; p.county = 0; p.val = 965; p.data["black"] = 0; p.data["white"] = 945; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 179; p.data["r16"] = 922;
points[1311]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 26; p.county = 0; p.val = 755; p.data["black"] = 315; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1312]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 29; p.county = 0; p.val = 1005; p.data["black"] = 800; p.data["white"] = 205; p.data["r"] = 953; p.data["d"] = 410; p.data["d16"] = 1132; p.data["r16"] = 528;
points[1313]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 132; p.county = 0; p.val = 1535; p.data["black"] = 600; p.data["white"] = 915; p.data["r"] = 59; p.data["d"] = 331; p.data["d16"] = 92; p.data["r16"] = 440;
points[1314]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 145; p.county = 0; p.val = 1570; p.data["black"] = 285; p.data["white"] = 965; p.data["r"] = 274; p.data["d"] = 282; p.data["d16"] = 0; p.data["r16"] = 0;
points[1315]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 27; p.county = 0; p.val = 2545; p.data["black"] = 70; p.data["white"] = 2390; p.data["r"] = 308; p.data["d"] = 988; p.data["d16"] = 245; p.data["r16"] = 1060;
points[1316]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 39; p.county = 0; p.val = 2050; p.data["black"] = 70; p.data["white"] = 1960; p.data["r"] = 268; p.data["d"] = 1000; p.data["d16"] = 154; p.data["r16"] = 762;
points[1317]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 18; p.county = 0; p.val = 855; p.data["black"] = 0; p.data["white"] = 855; p.data["r"] = 152; p.data["d"] = 478; p.data["d16"] = 160; p.data["r16"] = 565;
points[1318]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 31; p.county = 0; p.val = 1035; p.data["black"] = 85; p.data["white"] = 880; p.data["r"] = 662; p.data["d"] = 837; p.data["d16"] = 639; p.data["r16"] = 1058;
points[1319]=p;}
if (1==1){ Point p;
p.x = 3; p.y = 34; p.county = 0; p.val = 1375; p.data["black"] = 95; p.data["white"] = 1260; p.data["r"] = 56; p.data["d"] = 323; p.data["d16"] = 49; p.data["r16"] = 423;
points[1320]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 32; p.county = 0; p.val = 705; p.data["black"] = 275; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1321]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 33; p.county = 0; p.val = 1695; p.data["black"] = 130; p.data["white"] = 1455; p.data["r"] = 332; p.data["d"] = 932; p.data["d16"] = 78; p.data["r16"] = 511;
points[1322]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 27; p.county = 0; p.val = 700; p.data["black"] = 60; p.data["white"] = 515; p.data["r"] = 285; p.data["d"] = 837; p.data["d16"] = 0; p.data["r16"] = 0;
points[1323]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 34; p.county = 0; p.val = 565; p.data["black"] = 30; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 302; p.data["r16"] = 1529;
points[1324]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 26; p.county = 0; p.val = 1450; p.data["black"] = 0; p.data["white"] = 1430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 319; p.data["r16"] = 1143;
points[1325]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 33; p.county = 0; p.val = 2465; p.data["black"] = 165; p.data["white"] = 2190; p.data["r"] = 313; p.data["d"] = 398; p.data["d16"] = 318; p.data["r16"] = 534;
points[1326]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 33; p.county = 0; p.val = 1015; p.data["black"] = 115; p.data["white"] = 895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1327]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 173; p.county = 0; p.val = 625; p.data["black"] = 470; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1328]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 187; p.county = 0; p.val = 1100; p.data["black"] = 405; p.data["white"] = 585; p.data["r"] = 712; p.data["d"] = 515; p.data["d16"] = 909; p.data["r16"] = 608;
points[1329]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 162; p.county = 0; p.val = 1185; p.data["black"] = 340; p.data["white"] = 835; p.data["r"] = 133; p.data["d"] = 321; p.data["d16"] = 160; p.data["r16"] = 407;
points[1330]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 180; p.county = 0; p.val = 1150; p.data["black"] = 535; p.data["white"] = 390; p.data["r"] = 238; p.data["d"] = 136; p.data["d16"] = 279; p.data["r16"] = 173;
points[1331]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 44; p.county = 0; p.val = 880; p.data["black"] = 620; p.data["white"] = 170; p.data["r"] = 209; p.data["d"] = 58; p.data["d16"] = 240; p.data["r16"] = 80;
points[1332]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 184; p.county = 0; p.val = 1100; p.data["black"] = 510; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1333]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 194; p.county = 0; p.val = 1630; p.data["black"] = 965; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1334]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 167; p.county = 0; p.val = 535; p.data["black"] = 480; p.data["white"] = 25; p.data["r"] = 358; p.data["d"] = 37; p.data["d16"] = 426; p.data["r16"] = 45;
points[1335]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 170; p.county = 0; p.val = 1155; p.data["black"] = 365; p.data["white"] = 790; p.data["r"] = 202; p.data["d"] = 143; p.data["d16"] = 252; p.data["r16"] = 207;
points[1336]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 108; p.county = 0; p.val = 2440; p.data["black"] = 345; p.data["white"] = 1710; p.data["r"] = 347; p.data["d"] = 602; p.data["d16"] = 363; p.data["r16"] = 727;
points[1337]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 80; p.county = 0; p.val = 1790; p.data["black"] = 120; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 155; p.data["r16"] = 333;
points[1338]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 94; p.county = 0; p.val = 1405; p.data["black"] = 220; p.data["white"] = 1160; p.data["r"] = 183; p.data["d"] = 522; p.data["d16"] = 0; p.data["r16"] = 0;
points[1339]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 75; p.county = 0; p.val = 1700; p.data["black"] = 295; p.data["white"] = 1325; p.data["r"] = 508; p.data["d"] = 644; p.data["d16"] = 0; p.data["r16"] = 0;
points[1340]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 138; p.county = 0; p.val = 470; p.data["black"] = 300; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1341]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 50; p.county = 0; p.val = 1080; p.data["black"] = 90; p.data["white"] = 980; p.data["r"] = 255; p.data["d"] = 664; p.data["d16"] = 250; p.data["r16"] = 727;
points[1342]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 53; p.county = 0; p.val = 780; p.data["black"] = 290; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1343]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 59; p.county = 0; p.val = 665; p.data["black"] = 555; p.data["white"] = 110; p.data["r"] = 504; p.data["d"] = 81; p.data["d16"] = 630; p.data["r16"] = 115;
points[1344]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 54; p.county = 0; p.val = 1540; p.data["black"] = 740; p.data["white"] = 685; p.data["r"] = 380; p.data["d"] = 176; p.data["d16"] = 434; p.data["r16"] = 210;
points[1345]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 52; p.county = 0; p.val = 1605; p.data["black"] = 990; p.data["white"] = 430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1003; p.data["r16"] = 270;
points[1346]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 58; p.county = 0; p.val = 1785; p.data["black"] = 795; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1347]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 45; p.county = 0; p.val = 865; p.data["black"] = 745; p.data["white"] = 110; p.data["r"] = 137; p.data["d"] = 58; p.data["d16"] = 176; p.data["r16"] = 80;
points[1348]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 49; p.county = 0; p.val = 1380; p.data["black"] = 945; p.data["white"] = 410; p.data["r"] = 218; p.data["d"] = 234; p.data["d16"] = 261; p.data["r16"] = 249;
points[1349]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 44; p.county = 0; p.val = 1045; p.data["black"] = 255; p.data["white"] = 785; p.data["r"] = 264; p.data["d"] = 239; p.data["d16"] = 320; p.data["r16"] = 293;
points[1350]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 59; p.county = 0; p.val = 1385; p.data["black"] = 1065; p.data["white"] = 320; p.data["r"] = 720; p.data["d"] = 300; p.data["d16"] = 849; p.data["r16"] = 346;
points[1351]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 51; p.county = 0; p.val = 490; p.data["black"] = 90; p.data["white"] = 400; p.data["r"] = 657; p.data["d"] = 323; p.data["d16"] = 0; p.data["r16"] = 0;
points[1352]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 53; p.county = 0; p.val = 660; p.data["black"] = 525; p.data["white"] = 135; p.data["r"] = 252; p.data["d"] = 78; p.data["d16"] = 341; p.data["r16"] = 99;
points[1353]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 56; p.county = 0; p.val = 965; p.data["black"] = 440; p.data["white"] = 525; p.data["r"] = 56; p.data["d"] = 128; p.data["d16"] = 78; p.data["r16"] = 183;
points[1354]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 19; p.county = 0; p.val = 870; p.data["black"] = 0; p.data["white"] = 835; p.data["r"] = 172; p.data["d"] = 640; p.data["d16"] = 0; p.data["r16"] = 0;
points[1355]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 91; p.county = 0; p.val = 655; p.data["black"] = 410; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1356]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 123; p.county = 0; p.val = 980; p.data["black"] = 0; p.data["white"] = 970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1357]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 33; p.county = 0; p.val = 715; p.data["black"] = 155; p.data["white"] = 380; p.data["r"] = 634; p.data["d"] = 707; p.data["d16"] = 0; p.data["r16"] = 0;
points[1358]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 31; p.county = 0; p.val = 1400; p.data["black"] = 410; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 214; p.data["r16"] = 244;
points[1359]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 34; p.county = 0; p.val = 810; p.data["black"] = 350; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1360]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 37; p.county = 0; p.val = 710; p.data["black"] = 0; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1361]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 31; p.county = 0; p.val = 610; p.data["black"] = 0; p.data["white"] = 610; p.data["r"] = 151; p.data["d"] = 641; p.data["d16"] = 0; p.data["r16"] = 0;
points[1362]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 46; p.county = 0; p.val = 2525; p.data["black"] = 240; p.data["white"] = 2220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 62; p.data["r16"] = 646;
points[1363]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 75; p.county = 0; p.val = 3220; p.data["black"] = 800; p.data["white"] = 2270; p.data["r"] = 421; p.data["d"] = 117; p.data["d16"] = 800; p.data["r16"] = 288;
points[1364]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 72; p.county = 0; p.val = 2830; p.data["black"] = 1885; p.data["white"] = 750; p.data["r"] = 791; p.data["d"] = 88; p.data["d16"] = 562; p.data["r16"] = 81;
points[1365]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 33; p.county = 0; p.val = 1760; p.data["black"] = 225; p.data["white"] = 1485; p.data["r"] = 369; p.data["d"] = 1196; p.data["d16"] = 508; p.data["r16"] = 2637;
points[1366]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 33; p.county = 0; p.val = 1035; p.data["black"] = 190; p.data["white"] = 825; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1367]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 36; p.county = 0; p.val = 635; p.data["black"] = 125; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1368]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 40; p.county = 0; p.val = 955; p.data["black"] = 50; p.data["white"] = 890; p.data["r"] = 110; p.data["d"] = 320; p.data["d16"] = 283; p.data["r16"] = 1092;
points[1369]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 43; p.county = 0; p.val = 1755; p.data["black"] = 215; p.data["white"] = 1505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1370]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 41; p.county = 0; p.val = 3850; p.data["black"] = 460; p.data["white"] = 3215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1371]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 47; p.county = 0; p.val = 1085; p.data["black"] = 0; p.data["white"] = 1075; p.data["r"] = 63; p.data["d"] = 457; p.data["d16"] = 0; p.data["r16"] = 0;
points[1372]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 58; p.county = 0; p.val = 1150; p.data["black"] = 110; p.data["white"] = 1040; p.data["r"] = 144; p.data["d"] = 581; p.data["d16"] = 192; p.data["r16"] = 818;
points[1373]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 49; p.county = 0; p.val = 800; p.data["black"] = 120; p.data["white"] = 665; p.data["r"] = 131; p.data["d"] = 496; p.data["d16"] = 186; p.data["r16"] = 692;
points[1374]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 50; p.county = 0; p.val = 1365; p.data["black"] = 245; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1375]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 42; p.county = 0; p.val = 1705; p.data["black"] = 55; p.data["white"] = 1615; p.data["r"] = 258; p.data["d"] = 440; p.data["d16"] = 507; p.data["r16"] = 833;
points[1376]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 44; p.county = 0; p.val = 1095; p.data["black"] = 835; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1377]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 43; p.county = 0; p.val = 3555; p.data["black"] = 745; p.data["white"] = 2600; p.data["r"] = 186; p.data["d"] = 107; p.data["d16"] = 1543; p.data["r16"] = 581;
points[1378]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 42; p.county = 0; p.val = 3625; p.data["black"] = 565; p.data["white"] = 2890; p.data["r"] = 802; p.data["d"] = 1366; p.data["d16"] = 0; p.data["r16"] = 0;
points[1379]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 43; p.county = 0; p.val = 1360; p.data["black"] = 455; p.data["white"] = 770; p.data["r"] = 696; p.data["d"] = 287; p.data["d16"] = 0; p.data["r16"] = 0;
points[1380]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 19; p.county = 0; p.val = 780; p.data["black"] = 65; p.data["white"] = 710; p.data["r"] = 86; p.data["d"] = 600; p.data["d16"] = 71; p.data["r16"] = 736;
points[1381]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 45; p.county = 0; p.val = 1180; p.data["black"] = 595; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1382]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 44; p.county = 0; p.val = 1345; p.data["black"] = 905; p.data["white"] = 330; p.data["r"] = 378; p.data["d"] = 87; p.data["d16"] = 526; p.data["r16"] = 111;
points[1383]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 42; p.county = 0; p.val = 460; p.data["black"] = 125; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 217; p.data["r16"] = 194;
points[1384]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 40; p.county = 0; p.val = 1120; p.data["black"] = 55; p.data["white"] = 1070; p.data["r"] = 135; p.data["d"] = 531; p.data["d16"] = 0; p.data["r16"] = 0;
points[1385]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 43; p.county = 0; p.val = 2950; p.data["black"] = 1260; p.data["white"] = 1560; p.data["r"] = 307; p.data["d"] = 99; p.data["d16"] = 276; p.data["r16"] = 94;
points[1386]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 41; p.county = 0; p.val = 2415; p.data["black"] = 570; p.data["white"] = 1805; p.data["r"] = 274; p.data["d"] = 371; p.data["d16"] = 217; p.data["r16"] = 577;
points[1387]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 40; p.county = 0; p.val = 1275; p.data["black"] = 255; p.data["white"] = 940; p.data["r"] = 597; p.data["d"] = 1460; p.data["d16"] = 877; p.data["r16"] = 2105;
points[1388]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 107; p.county = 0; p.val = 1690; p.data["black"] = 730; p.data["white"] = 640; p.data["r"] = 296; p.data["d"] = 412; p.data["d16"] = 0; p.data["r16"] = 0;
points[1389]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 108; p.county = 0; p.val = 330; p.data["black"] = 165; p.data["white"] = 120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 180; p.data["r16"] = 678;
points[1390]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 108; p.county = 0; p.val = 760; p.data["black"] = 90; p.data["white"] = 605; p.data["r"] = 720; p.data["d"] = 856; p.data["d16"] = 414; p.data["r16"] = 337;
points[1391]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 109; p.county = 0; p.val = 365; p.data["black"] = 90; p.data["white"] = 275; p.data["r"] = 491; p.data["d"] = 854; p.data["d16"] = 516; p.data["r16"] = 217;
points[1392]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 106; p.county = 0; p.val = 1060; p.data["black"] = 115; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 721; p.data["r16"] = 1462;
points[1393]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 34; p.county = 0; p.val = 570; p.data["black"] = 15; p.data["white"] = 550; p.data["r"] = 58; p.data["d"] = 269; p.data["d16"] = 0; p.data["r16"] = 0;
points[1394]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 149; p.county = 0; p.val = 2925; p.data["black"] = 2375; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1395]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 150; p.county = 0; p.val = 1020; p.data["black"] = 850; p.data["white"] = 145; p.data["r"] = 322; p.data["d"] = 138; p.data["d16"] = 1686; p.data["r16"] = 371;
points[1396]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 151; p.county = 0; p.val = 2165; p.data["black"] = 335; p.data["white"] = 1730; p.data["r"] = 609; p.data["d"] = 763; p.data["d16"] = 575; p.data["r16"] = 865;
points[1397]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 153; p.county = 0; p.val = 1320; p.data["black"] = 210; p.data["white"] = 1105; p.data["r"] = 677; p.data["d"] = 753; p.data["d16"] = 664; p.data["r16"] = 750;
points[1398]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 154; p.county = 0; p.val = 1185; p.data["black"] = 0; p.data["white"] = 1100; p.data["r"] = 591; p.data["d"] = 498; p.data["d16"] = 496; p.data["r16"] = 695;
points[1399]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 160; p.county = 0; p.val = 5025; p.data["black"] = 1320; p.data["white"] = 3320; p.data["r"] = 2516; p.data["d"] = 1335; p.data["d16"] = 1798; p.data["r16"] = 1250;
points[1400]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 156; p.county = 0; p.val = 1525; p.data["black"] = 70; p.data["white"] = 1225; p.data["r"] = 525; p.data["d"] = 577; p.data["d16"] = 501; p.data["r16"] = 546;
points[1401]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 156; p.county = 0; p.val = 2045; p.data["black"] = 50; p.data["white"] = 1995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 360; p.data["r16"] = 685;
points[1402]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 157; p.county = 0; p.val = 2095; p.data["black"] = 1690; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1403]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 62; p.county = 0; p.val = 1290; p.data["black"] = 190; p.data["white"] = 1020; p.data["r"] = 211; p.data["d"] = 243; p.data["d16"] = 503; p.data["r16"] = 701;
points[1404]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 53; p.county = 0; p.val = 900; p.data["black"] = 385; p.data["white"] = 485; p.data["r"] = 471; p.data["d"] = 470; p.data["d16"] = 0; p.data["r16"] = 0;
points[1405]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 44; p.county = 0; p.val = 565; p.data["black"] = 220; p.data["white"] = 335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 171; p.data["r16"] = 388;
points[1406]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 58; p.county = 0; p.val = 930; p.data["black"] = 395; p.data["white"] = 530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1407]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 147; p.county = 0; p.val = 565; p.data["black"] = 105; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1408]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 148; p.county = 0; p.val = 1645; p.data["black"] = 1495; p.data["white"] = 115; p.data["r"] = 535; p.data["d"] = 202; p.data["d16"] = 583; p.data["r16"] = 330;
points[1409]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 57; p.county = 0; p.val = 2205; p.data["black"] = 1810; p.data["white"] = 365; p.data["r"] = 116; p.data["d"] = 71; p.data["d16"] = 0; p.data["r16"] = 0;
points[1410]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 56; p.county = 0; p.val = 895; p.data["black"] = 275; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1411]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 139; p.county = 0; p.val = 655; p.data["black"] = 630; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1412]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 142; p.county = 0; p.val = 925; p.data["black"] = 760; p.data["white"] = 165; p.data["r"] = 201; p.data["d"] = 94; p.data["d16"] = 259; p.data["r16"] = 109;
points[1413]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 97; p.county = 0; p.val = 1190; p.data["black"] = 255; p.data["white"] = 920; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1414]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 100; p.county = 0; p.val = 760; p.data["black"] = 500; p.data["white"] = 215; p.data["r"] = 657; p.data["d"] = 364; p.data["d16"] = 720; p.data["r16"] = 452;
points[1415]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 101; p.county = 0; p.val = 1185; p.data["black"] = 135; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1416]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 98; p.county = 0; p.val = 1760; p.data["black"] = 35; p.data["white"] = 1690; p.data["r"] = 420; p.data["d"] = 1289; p.data["d16"] = 408; p.data["r16"] = 1608;
points[1417]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 91; p.county = 0; p.val = 530; p.data["black"] = 220; p.data["white"] = 295; p.data["r"] = 398; p.data["d"] = 445; p.data["d16"] = 547; p.data["r16"] = 494;
points[1418]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 101; p.county = 0; p.val = 475; p.data["black"] = 0; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 342; p.data["r16"] = 1413;
points[1419]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 57; p.county = 0; p.val = 575; p.data["black"] = 535; p.data["white"] = 40; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 504; p.data["r16"] = 230;
points[1420]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 191; p.county = 0; p.val = 945; p.data["black"] = 105; p.data["white"] = 845; p.data["r"] = 372; p.data["d"] = 329; p.data["d16"] = 414; p.data["r16"] = 350;
points[1421]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 190; p.county = 0; p.val = 1135; p.data["black"] = 190; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1422]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 189; p.county = 0; p.val = 930; p.data["black"] = 0; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1423]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 190; p.county = 0; p.val = 650; p.data["black"] = 30; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1424]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 191; p.county = 0; p.val = 430; p.data["black"] = 145; p.data["white"] = 275; p.data["r"] = 649; p.data["d"] = 610; p.data["d16"] = 568; p.data["r16"] = 273;
points[1425]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 85; p.county = 0; p.val = 1935; p.data["black"] = 705; p.data["white"] = 1170; p.data["r"] = 373; p.data["d"] = 396; p.data["d16"] = 494; p.data["r16"] = 525;
points[1426]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 92; p.county = 0; p.val = 400; p.data["black"] = 195; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1427]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 74; p.county = 0; p.val = 1470; p.data["black"] = 805; p.data["white"] = 535; p.data["r"] = 302; p.data["d"] = 187; p.data["d16"] = 0; p.data["r16"] = 0;
points[1428]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 83; p.county = 0; p.val = 1095; p.data["black"] = 555; p.data["white"] = 490; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1429]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 86; p.county = 0; p.val = 2240; p.data["black"] = 900; p.data["white"] = 1325; p.data["r"] = 407; p.data["d"] = 565; p.data["d16"] = 440; p.data["r16"] = 667;
points[1430]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 79; p.county = 0; p.val = 755; p.data["black"] = 480; p.data["white"] = 265; p.data["r"] = 225; p.data["d"] = 43; p.data["d16"] = 292; p.data["r16"] = 53;
points[1431]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 72; p.county = 0; p.val = 1365; p.data["black"] = 1090; p.data["white"] = 180; p.data["r"] = 399; p.data["d"] = 138; p.data["d16"] = 462; p.data["r16"] = 180;
points[1432]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 75; p.county = 0; p.val = 1620; p.data["black"] = 515; p.data["white"] = 1040; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 499; p.data["r16"] = 387;
points[1433]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 78; p.county = 0; p.val = 845; p.data["black"] = 405; p.data["white"] = 440; p.data["r"] = 423; p.data["d"] = 280; p.data["d16"] = 626; p.data["r16"] = 396;
points[1434]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 88; p.county = 0; p.val = 2205; p.data["black"] = 385; p.data["white"] = 1720; p.data["r"] = 209; p.data["d"] = 482; p.data["d16"] = 225; p.data["r16"] = 790;
points[1435]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 89; p.county = 0; p.val = 2055; p.data["black"] = 670; p.data["white"] = 1300; p.data["r"] = 307; p.data["d"] = 246; p.data["d16"] = 442; p.data["r16"] = 364;
points[1436]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 73; p.county = 0; p.val = 815; p.data["black"] = 485; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 294; p.data["r16"] = 491;
points[1437]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 75; p.county = 0; p.val = 3460; p.data["black"] = 1350; p.data["white"] = 1805; p.data["r"] = 310; p.data["d"] = 239; p.data["d16"] = 337; p.data["r16"] = 353;
points[1438]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 76; p.county = 0; p.val = 805; p.data["black"] = 460; p.data["white"] = 345; p.data["r"] = 300; p.data["d"] = 49; p.data["d16"] = 651; p.data["r16"] = 319;
points[1439]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 149; p.county = 0; p.val = 1170; p.data["black"] = 485; p.data["white"] = 610; p.data["r"] = 612; p.data["d"] = 534; p.data["d16"] = 753; p.data["r16"] = 744;
points[1440]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 83; p.county = 0; p.val = 1555; p.data["black"] = 1360; p.data["white"] = 190; p.data["r"] = 1492; p.data["d"] = 81; p.data["d16"] = 1640; p.data["r16"] = 81;
points[1441]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 71; p.county = 0; p.val = 1560; p.data["black"] = 1205; p.data["white"] = 350; p.data["r"] = 938; p.data["d"] = 159; p.data["d16"] = 1105; p.data["r16"] = 180;
points[1442]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 83; p.county = 0; p.val = 590; p.data["black"] = 550; p.data["white"] = 15; p.data["r"] = 489; p.data["d"] = 80; p.data["d16"] = 719; p.data["r16"] = 112;
points[1443]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 81; p.county = 0; p.val = 2030; p.data["black"] = 740; p.data["white"] = 1250; p.data["r"] = 324; p.data["d"] = 456; p.data["d16"] = 0; p.data["r16"] = 0;
points[1444]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 23; p.county = 0; p.val = 1705; p.data["black"] = 50; p.data["white"] = 1595; p.data["r"] = 457; p.data["d"] = 980; p.data["d16"] = 365; p.data["r16"] = 944;
points[1445]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 23; p.county = 0; p.val = 780; p.data["black"] = 0; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 119; p.data["r16"] = 840;
points[1446]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 26; p.county = 0; p.val = 475; p.data["black"] = 0; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1447]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 35; p.county = 0; p.val = 1055; p.data["black"] = 175; p.data["white"] = 860; p.data["r"] = 317; p.data["d"] = 790; p.data["d16"] = 0; p.data["r16"] = 0;
points[1448]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 30; p.county = 0; p.val = 905; p.data["black"] = 15; p.data["white"] = 865; p.data["r"] = 381; p.data["d"] = 616; p.data["d16"] = 441; p.data["r16"] = 795;
points[1449]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 79; p.county = 0; p.val = 600; p.data["black"] = 380; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1450]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 103; p.county = 0; p.val = 2545; p.data["black"] = 750; p.data["white"] = 1705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 652; p.data["r16"] = 62;
points[1451]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 102; p.county = 0; p.val = 1625; p.data["black"] = 400; p.data["white"] = 1195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 619; p.data["r16"] = 270;
points[1452]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 104; p.county = 0; p.val = 1655; p.data["black"] = 575; p.data["white"] = 1040; p.data["r"] = 180; p.data["d"] = 329; p.data["d16"] = 314; p.data["r16"] = 469;
points[1453]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 106; p.county = 0; p.val = 2010; p.data["black"] = 520; p.data["white"] = 1200; p.data["r"] = 530; p.data["d"] = 1027; p.data["d16"] = 210; p.data["r16"] = 570;
points[1454]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 80; p.county = 0; p.val = 810; p.data["black"] = 215; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1455]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 30; p.county = 0; p.val = 490; p.data["black"] = 120; p.data["white"] = 365; p.data["r"] = 312; p.data["d"] = 453; p.data["d16"] = 329; p.data["r16"] = 609;
points[1456]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 20; p.county = 0; p.val = 1595; p.data["black"] = 425; p.data["white"] = 1090; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 328; p.data["r16"] = 1172;
points[1457]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 22; p.county = 0; p.val = 1190; p.data["black"] = 225; p.data["white"] = 925; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 212; p.data["r16"] = 399;
points[1458]=p;}
if (1==1){ Point p;
p.x = 0; p.y = 29; p.county = 0; p.val = 615; p.data["black"] = 10; p.data["white"] = 610; p.data["r"] = 88; p.data["d"] = 173; p.data["d16"] = 0; p.data["r16"] = 0;
points[1459]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 19; p.county = 0; p.val = 710; p.data["black"] = 4; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1460]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 24; p.county = 0; p.val = 1355; p.data["black"] = 0; p.data["white"] = 1330; p.data["r"] = 236; p.data["d"] = 840; p.data["d16"] = 207; p.data["r16"] = 912;
points[1461]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 27; p.county = 0; p.val = 540; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1462]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 30; p.county = 0; p.val = 1070; p.data["black"] = 30; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 143; p.data["r16"] = 649;
points[1463]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 82; p.county = 0; p.val = 1285; p.data["black"] = 1040; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1464]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 16; p.county = 0; p.val = 1715; p.data["black"] = 470; p.data["white"] = 1160; p.data["r"] = 396; p.data["d"] = 808; p.data["d16"] = 0; p.data["r16"] = 0;
points[1465]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 15; p.county = 0; p.val = 1975; p.data["black"] = 365; p.data["white"] = 1495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1466]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 25; p.county = 0; p.val = 2340; p.data["black"] = 1270; p.data["white"] = 1015; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 560; p.data["r16"] = 714;
points[1467]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 27; p.county = 0; p.val = 1975; p.data["black"] = 345; p.data["white"] = 1435; p.data["r"] = 656; p.data["d"] = 553; p.data["d16"] = 0; p.data["r16"] = 0;
points[1468]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 10; p.county = 0; p.val = 830; p.data["black"] = 0; p.data["white"] = 790; p.data["r"] = 470; p.data["d"] = 1434; p.data["d16"] = 365; p.data["r16"] = 1868;
points[1469]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 9; p.county = 0; p.val = 1675; p.data["black"] = 65; p.data["white"] = 1575; p.data["r"] = 194; p.data["d"] = 1053; p.data["d16"] = 201; p.data["r16"] = 1355;
points[1470]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 19; p.county = 0; p.val = 4425; p.data["black"] = 370; p.data["white"] = 3435; p.data["r"] = 624; p.data["d"] = 1090; p.data["d16"] = 0; p.data["r16"] = 0;
points[1471]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 25; p.county = 0; p.val = 2045; p.data["black"] = 100; p.data["white"] = 1815; p.data["r"] = 927; p.data["d"] = 1593; p.data["d16"] = 565; p.data["r16"] = 1360;
points[1472]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 27; p.county = 0; p.val = 1965; p.data["black"] = 695; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 458; p.data["r16"] = 741;
points[1473]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 36; p.county = 0; p.val = 1020; p.data["black"] = 60; p.data["white"] = 950; p.data["r"] = 197; p.data["d"] = 883; p.data["d16"] = 214; p.data["r16"] = 1110;
points[1474]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 34; p.county = 0; p.val = 2925; p.data["black"] = 1120; p.data["white"] = 1680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1475]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 18; p.county = 0; p.val = 3110; p.data["black"] = 255; p.data["white"] = 2545; p.data["r"] = 1108; p.data["d"] = 1795; p.data["d16"] = 1070; p.data["r16"] = 2358;
points[1476]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 19; p.county = 0; p.val = 880; p.data["black"] = 255; p.data["white"] = 595; p.data["r"] = 314; p.data["d"] = 332; p.data["d16"] = 447; p.data["r16"] = 464;
points[1477]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 64; p.county = 0; p.val = 955; p.data["black"] = 240; p.data["white"] = 685; p.data["r"] = 336; p.data["d"] = 320; p.data["d16"] = 604; p.data["r16"] = 127;
points[1478]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 58; p.county = 0; p.val = 1205; p.data["black"] = 225; p.data["white"] = 940; p.data["r"] = 298; p.data["d"] = 240; p.data["d16"] = 372; p.data["r16"] = 344;
points[1479]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 61; p.county = 0; p.val = 795; p.data["black"] = 170; p.data["white"] = 620; p.data["r"] = 197; p.data["d"] = 320; p.data["d16"] = 493; p.data["r16"] = 678;
points[1480]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 60; p.county = 0; p.val = 430; p.data["black"] = 160; p.data["white"] = 240; p.data["r"] = 170; p.data["d"] = 413; p.data["d16"] = 144; p.data["r16"] = 481;
points[1481]=p;}
if (1==1){ Point p;
p.x = 118; p.y = 78; p.county = 0; p.val = 1980; p.data["black"] = 635; p.data["white"] = 1240; p.data["r"] = 582; p.data["d"] = 630; p.data["d16"] = 672; p.data["r16"] = 895;
points[1482]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 86; p.county = 0; p.val = 695; p.data["black"] = 285; p.data["white"] = 330; p.data["r"] = 309; p.data["d"] = 426; p.data["d16"] = 414; p.data["r16"] = 541;
points[1483]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 91; p.county = 0; p.val = 1230; p.data["black"] = 440; p.data["white"] = 785; p.data["r"] = 525; p.data["d"] = 367; p.data["d16"] = 642; p.data["r16"] = 580;
points[1484]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 85; p.county = 0; p.val = 1955; p.data["black"] = 440; p.data["white"] = 1390; p.data["r"] = 321; p.data["d"] = 563; p.data["d16"] = 707; p.data["r16"] = 1469;
points[1485]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 78; p.county = 0; p.val = 450; p.data["black"] = 340; p.data["white"] = 105; p.data["r"] = 279; p.data["d"] = 81; p.data["d16"] = 421; p.data["r16"] = 86;
points[1486]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 35; p.county = 0; p.val = 1720; p.data["black"] = 325; p.data["white"] = 1330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1487]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 30; p.county = 0; p.val = 1070; p.data["black"] = 250; p.data["white"] = 740; p.data["r"] = 47; p.data["d"] = 93; p.data["d16"] = 90; p.data["r16"] = 149;
points[1488]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 32; p.county = 0; p.val = 845; p.data["black"] = 325; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 259; p.data["r16"] = 491;
points[1489]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 32; p.county = 0; p.val = 1760; p.data["black"] = 460; p.data["white"] = 1290; p.data["r"] = 100; p.data["d"] = 215; p.data["d16"] = 142; p.data["r16"] = 277;
points[1490]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 20; p.county = 0; p.val = 2385; p.data["black"] = 1265; p.data["white"] = 1000; p.data["r"] = 810; p.data["d"] = 786; p.data["d16"] = 849; p.data["r16"] = 898;
points[1491]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 11; p.county = 0; p.val = 2305; p.data["black"] = 75; p.data["white"] = 2105; p.data["r"] = 192; p.data["d"] = 703; p.data["d16"] = 212; p.data["r16"] = 884;
points[1492]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 12; p.county = 0; p.val = 1085; p.data["black"] = 145; p.data["white"] = 935; p.data["r"] = 156; p.data["d"] = 430; p.data["d16"] = 181; p.data["r16"] = 567;
points[1493]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 23; p.county = 0; p.val = 2515; p.data["black"] = 765; p.data["white"] = 1570; p.data["r"] = 577; p.data["d"] = 479; p.data["d16"] = 0; p.data["r16"] = 0;
points[1494]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 18; p.county = 0; p.val = 1745; p.data["black"] = 555; p.data["white"] = 1140; p.data["r"] = 474; p.data["d"] = 634; p.data["d16"] = 556; p.data["r16"] = 783;
points[1495]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 17; p.county = 0; p.val = 1710; p.data["black"] = 110; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1496]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 18; p.county = 0; p.val = 1955; p.data["black"] = 25; p.data["white"] = 1930; p.data["r"] = 107; p.data["d"] = 613; p.data["d16"] = 97; p.data["r16"] = 744;
points[1497]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 14; p.county = 0; p.val = 840; p.data["black"] = 0; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1498]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 17; p.county = 0; p.val = 1530; p.data["black"] = 45; p.data["white"] = 1465; p.data["r"] = 230; p.data["d"] = 1269; p.data["d16"] = 75; p.data["r16"] = 738;
points[1499]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 107; p.county = 0; p.val = 1170; p.data["black"] = 35; p.data["white"] = 1100; p.data["r"] = 225; p.data["d"] = 580; p.data["d16"] = 364; p.data["r16"] = 1583;
points[1500]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 22; p.county = 0; p.val = 790; p.data["black"] = 10; p.data["white"] = 750; p.data["r"] = 351; p.data["d"] = 584; p.data["d16"] = 421; p.data["r16"] = 865;
points[1501]=p;}
if (1==1){ Point p;
p.x = 176; p.y = 60; p.county = 0; p.val = 660; p.data["black"] = 355; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1502]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 65; p.county = 0; p.val = 610; p.data["black"] = 415; p.data["white"] = 175; p.data["r"] = 452; p.data["d"] = 313; p.data["d16"] = 612; p.data["r16"] = 372;
points[1503]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 81; p.county = 0; p.val = 1185; p.data["black"] = 650; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1504]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 60; p.county = 0; p.val = 965; p.data["black"] = 250; p.data["white"] = 670; p.data["r"] = 180; p.data["d"] = 210; p.data["d16"] = 209; p.data["r16"] = 304;
points[1505]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 108; p.county = 0; p.val = 2015; p.data["black"] = 515; p.data["white"] = 1450; p.data["r"] = 456; p.data["d"] = 1001; p.data["d16"] = 1434; p.data["r16"] = 2996;
points[1506]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 149; p.county = 0; p.val = 3300; p.data["black"] = 245; p.data["white"] = 2940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1507]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 105; p.county = 0; p.val = 1850; p.data["black"] = 390; p.data["white"] = 1375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1508]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 106; p.county = 0; p.val = 1710; p.data["black"] = 200; p.data["white"] = 1510; p.data["r"] = 259; p.data["d"] = 631; p.data["d16"] = 218; p.data["r16"] = 482;
points[1509]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 110; p.county = 0; p.val = 1890; p.data["black"] = 120; p.data["white"] = 1640; p.data["r"] = 226; p.data["d"] = 725; p.data["d16"] = 536; p.data["r16"] = 2010;
points[1510]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 145; p.county = 0; p.val = 6430; p.data["black"] = 200; p.data["white"] = 6075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1511]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 143; p.county = 0; p.val = 2875; p.data["black"] = 905; p.data["white"] = 1630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 470; p.data["r16"] = 263;
points[1512]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 165; p.county = 0; p.val = 140; p.data["black"] = 0; p.data["white"] = 135; p.data["r"] = 538; p.data["d"] = 496; p.data["d16"] = 599; p.data["r16"] = 555;
points[1513]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 146; p.county = 0; p.val = 1215; p.data["black"] = 745; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 194; p.data["r16"] = 651;
points[1514]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 150; p.county = 0; p.val = 2185; p.data["black"] = 230; p.data["white"] = 1925; p.data["r"] = 412; p.data["d"] = 167; p.data["d16"] = 521; p.data["r16"] = 206;
points[1515]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 150; p.county = 0; p.val = 595; p.data["black"] = 595; p.data["white"] = 0; p.data["r"] = 471; p.data["d"] = 476; p.data["d16"] = 459; p.data["r16"] = 558;
points[1516]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 22; p.county = 0; p.val = 2690; p.data["black"] = 635; p.data["white"] = 2015; p.data["r"] = 153; p.data["d"] = 414; p.data["d16"] = 329; p.data["r16"] = 1090;
points[1517]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 23; p.county = 0; p.val = 1110; p.data["black"] = 230; p.data["white"] = 855; p.data["r"] = 151; p.data["d"] = 321; p.data["d16"] = 144; p.data["r16"] = 443;
points[1518]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 24; p.county = 0; p.val = 3675; p.data["black"] = 400; p.data["white"] = 2850; p.data["r"] = 908; p.data["d"] = 1072; p.data["d16"] = 0; p.data["r16"] = 0;
points[1519]=p;}
if (1==1){ Point p;
p.x = 155; p.y = 48; p.county = 0; p.val = 905; p.data["black"] = 315; p.data["white"] = 450; p.data["r"] = 90; p.data["d"] = 118; p.data["d16"] = 101; p.data["r16"] = 198;
points[1520]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 25; p.county = 0; p.val = 690; p.data["black"] = 365; p.data["white"] = 315; p.data["r"] = 617; p.data["d"] = 658; p.data["d16"] = 629; p.data["r16"] = 848;
points[1521]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 60; p.county = 0; p.val = 1655; p.data["black"] = 525; p.data["white"] = 1105; p.data["r"] = 135; p.data["d"] = 463; p.data["d16"] = 243; p.data["r16"] = 844;
points[1522]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 61; p.county = 0; p.val = 575; p.data["black"] = 35; p.data["white"] = 535; p.data["r"] = 212; p.data["d"] = 287; p.data["d16"] = 423; p.data["r16"] = 675;
points[1523]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 63; p.county = 0; p.val = 1020; p.data["black"] = 980; p.data["white"] = 25; p.data["r"] = 267; p.data["d"] = 63; p.data["d16"] = 317; p.data["r16"] = 73;
points[1524]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 44; p.county = 0; p.val = 950; p.data["black"] = 230; p.data["white"] = 710; p.data["r"] = 305; p.data["d"] = 258; p.data["d16"] = 0; p.data["r16"] = 0;
points[1525]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 27; p.county = 0; p.val = 630; p.data["black"] = 100; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1526]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 35; p.county = 0; p.val = 1520; p.data["black"] = 850; p.data["white"] = 610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1527]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 32; p.county = 0; p.val = 590; p.data["black"] = 110; p.data["white"] = 435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 557; p.data["r16"] = 862;
points[1528]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 33; p.county = 0; p.val = 375; p.data["black"] = 135; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1529]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 39; p.county = 0; p.val = 980; p.data["black"] = 225; p.data["white"] = 670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1530]=p;}
if (1==1){ Point p;
p.x = 161; p.y = 35; p.county = 0; p.val = 685; p.data["black"] = 150; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1531]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 28; p.county = 0; p.val = 875; p.data["black"] = 295; p.data["white"] = 535; p.data["r"] = 256; p.data["d"] = 191; p.data["d16"] = 461; p.data["r16"] = 390;
points[1532]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 28; p.county = 0; p.val = 765; p.data["black"] = 330; p.data["white"] = 370; p.data["r"] = 393; p.data["d"] = 366; p.data["d16"] = 529; p.data["r16"] = 511;
points[1533]=p;}
if (1==1){ Point p;
p.x = 160; p.y = 37; p.county = 0; p.val = 660; p.data["black"] = 485; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1534]=p;}
if (1==1){ Point p;
p.x = 160; p.y = 33; p.county = 0; p.val = 1035; p.data["black"] = 305; p.data["white"] = 590; p.data["r"] = 383; p.data["d"] = 600; p.data["d16"] = 0; p.data["r16"] = 0;
points[1535]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 36; p.county = 0; p.val = 470; p.data["black"] = 310; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1536]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 33; p.county = 0; p.val = 3500; p.data["black"] = 2475; p.data["white"] = 735; p.data["r"] = 614; p.data["d"] = 494; p.data["d16"] = 661; p.data["r16"] = 544;
points[1537]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 34; p.county = 0; p.val = 855; p.data["black"] = 85; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1538]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 38; p.county = 0; p.val = 1285; p.data["black"] = 355; p.data["white"] = 910; p.data["r"] = 202; p.data["d"] = 304; p.data["d16"] = 0; p.data["r16"] = 0;
points[1539]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 33; p.county = 0; p.val = 1470; p.data["black"] = 305; p.data["white"] = 1105; p.data["r"] = 116; p.data["d"] = 462; p.data["d16"] = 127; p.data["r16"] = 674;
points[1540]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 46; p.county = 0; p.val = 985; p.data["black"] = 145; p.data["white"] = 810; p.data["r"] = 42; p.data["d"] = 365; p.data["d16"] = 63; p.data["r16"] = 479;
points[1541]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 47; p.county = 0; p.val = 475; p.data["black"] = 255; p.data["white"] = 210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1542]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 52; p.county = 0; p.val = 700; p.data["black"] = 290; p.data["white"] = 415; p.data["r"] = 125; p.data["d"] = 218; p.data["d16"] = 182; p.data["r16"] = 288;
points[1543]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 41; p.county = 0; p.val = 1170; p.data["black"] = 595; p.data["white"] = 480; p.data["r"] = 569; p.data["d"] = 247; p.data["d16"] = 818; p.data["r16"] = 307;
points[1544]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 104; p.county = 0; p.val = 1855; p.data["black"] = 375; p.data["white"] = 1390; p.data["r"] = 242; p.data["d"] = 585; p.data["d16"] = 238; p.data["r16"] = 784;
points[1545]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 105; p.county = 0; p.val = 475; p.data["black"] = 185; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1546]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 118; p.county = 0; p.val = 600; p.data["black"] = 25; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1547]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 103; p.county = 0; p.val = 645; p.data["black"] = 515; p.data["white"] = 110; p.data["r"] = 477; p.data["d"] = 69; p.data["d16"] = 0; p.data["r16"] = 0;
points[1548]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 150; p.county = 0; p.val = 4200; p.data["black"] = 280; p.data["white"] = 3675; p.data["r"] = 644; p.data["d"] = 881; p.data["d16"] = 612; p.data["r16"] = 1015;
points[1549]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 152; p.county = 0; p.val = 565; p.data["black"] = 0; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1550]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 152; p.county = 0; p.val = 2350; p.data["black"] = 30; p.data["white"] = 2225; p.data["r"] = 667; p.data["d"] = 834; p.data["d16"] = 571; p.data["r16"] = 999;
points[1551]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 28; p.county = 0; p.val = 625; p.data["black"] = 385; p.data["white"] = 220; p.data["r"] = 359; p.data["d"] = 195; p.data["d16"] = 404; p.data["r16"] = 270;
points[1552]=p;}
if (1==1){ Point p;
p.x = 155; p.y = 36; p.county = 0; p.val = 550; p.data["black"] = 475; p.data["white"] = 75; p.data["r"] = 148; p.data["d"] = 101; p.data["d16"] = 165; p.data["r16"] = 153;
points[1553]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 37; p.county = 0; p.val = 620; p.data["black"] = 620; p.data["white"] = 0; p.data["r"] = 311; p.data["d"] = 25; p.data["d16"] = 0; p.data["r16"] = 0;
points[1554]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 31; p.county = 0; p.val = 1210; p.data["black"] = 500; p.data["white"] = 620; p.data["r"] = 152; p.data["d"] = 133; p.data["d16"] = 0; p.data["r16"] = 0;
points[1555]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 28; p.county = 0; p.val = 2590; p.data["black"] = 160; p.data["white"] = 2250; p.data["r"] = 49; p.data["d"] = 87; p.data["d16"] = 67; p.data["r16"] = 140;
points[1556]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 24; p.county = 0; p.val = 2650; p.data["black"] = 395; p.data["white"] = 1945; p.data["r"] = 754; p.data["d"] = 678; p.data["d16"] = 0; p.data["r16"] = 0;
points[1557]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 27; p.county = 0; p.val = 1730; p.data["black"] = 120; p.data["white"] = 1420; p.data["r"] = 1039; p.data["d"] = 1341; p.data["d16"] = 530; p.data["r16"] = 1009;
points[1558]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 23; p.county = 0; p.val = 1915; p.data["black"] = 365; p.data["white"] = 1255; p.data["r"] = 533; p.data["d"] = 943; p.data["d16"] = 517; p.data["r16"] = 1195;
points[1559]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 66; p.county = 0; p.val = 1090; p.data["black"] = 60; p.data["white"] = 1025; p.data["r"] = 69; p.data["d"] = 351; p.data["d16"] = 73; p.data["r16"] = 443;
points[1560]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 26; p.county = 0; p.val = 1335; p.data["black"] = 25; p.data["white"] = 1095; p.data["r"] = 415; p.data["d"] = 1242; p.data["d16"] = 0; p.data["r16"] = 0;
points[1561]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 22; p.county = 0; p.val = 1550; p.data["black"] = 0; p.data["white"] = 1480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 413; p.data["r16"] = 1479;
points[1562]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 30; p.county = 0; p.val = 1515; p.data["black"] = 15; p.data["white"] = 1470; p.data["r"] = 280; p.data["d"] = 728; p.data["d16"] = 1050; p.data["r16"] = 1655;
points[1563]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 28; p.county = 0; p.val = 850; p.data["black"] = 10; p.data["white"] = 735; p.data["r"] = 237; p.data["d"] = 759; p.data["d16"] = 0; p.data["r16"] = 0;
points[1564]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 26; p.county = 0; p.val = 705; p.data["black"] = 4; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1565]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 20; p.county = 0; p.val = 760; p.data["black"] = 0; p.data["white"] = 760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1566]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 12; p.county = 0; p.val = 1435; p.data["black"] = 60; p.data["white"] = 1340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1567]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 32; p.county = 0; p.val = 1380; p.data["black"] = 415; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 779; p.data["r16"] = 864;
points[1568]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 108; p.county = 0; p.val = 495; p.data["black"] = 415; p.data["white"] = 80; p.data["r"] = 308; p.data["d"] = 671; p.data["d16"] = 196; p.data["r16"] = 222;
points[1569]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 114; p.county = 0; p.val = 200; p.data["black"] = 30; p.data["white"] = 170; p.data["r"] = 800; p.data["d"] = 963; p.data["d16"] = 0; p.data["r16"] = 0;
points[1570]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 153; p.county = 0; p.val = 900; p.data["black"] = 0; p.data["white"] = 900; p.data["r"] = 186; p.data["d"] = 324; p.data["d16"] = 166; p.data["r16"] = 286;
points[1571]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 155; p.county = 0; p.val = 700; p.data["black"] = 10; p.data["white"] = 670; p.data["r"] = 1640; p.data["d"] = 1706; p.data["d16"] = 1046; p.data["r16"] = 1448;
points[1572]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 32; p.county = 0; p.val = 555; p.data["black"] = 240; p.data["white"] = 305; p.data["r"] = 160; p.data["d"] = 169; p.data["d16"] = 0; p.data["r16"] = 0;
points[1573]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 36; p.county = 0; p.val = 1260; p.data["black"] = 160; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 340; p.data["r16"] = 1034;
points[1574]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 24; p.county = 0; p.val = 3145; p.data["black"] = 240; p.data["white"] = 2450; p.data["r"] = 478; p.data["d"] = 589; p.data["d16"] = 467; p.data["r16"] = 767;
points[1575]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 25; p.county = 0; p.val = 2285; p.data["black"] = 210; p.data["white"] = 1715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 276; p.data["r16"] = 641;
points[1576]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 20; p.county = 0; p.val = 1465; p.data["black"] = 285; p.data["white"] = 1115; p.data["r"] = 999; p.data["d"] = 1468; p.data["d16"] = 828; p.data["r16"] = 2002;
points[1577]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 20; p.county = 0; p.val = 645; p.data["black"] = 0; p.data["white"] = 645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 470; p.data["r16"] = 1396;
points[1578]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 22; p.county = 0; p.val = 1310; p.data["black"] = 95; p.data["white"] = 1205; p.data["r"] = 184; p.data["d"] = 798; p.data["d16"] = 0; p.data["r16"] = 0;
points[1579]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 19; p.county = 0; p.val = 2210; p.data["black"] = 205; p.data["white"] = 1815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1580]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 2; p.county = 0; p.val = 1205; p.data["black"] = 245; p.data["white"] = 880; p.data["r"] = 380; p.data["d"] = 946; p.data["d16"] = 468; p.data["r16"] = 1343;
points[1581]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 17; p.county = 0; p.val = 1220; p.data["black"] = 610; p.data["white"] = 610; p.data["r"] = 225; p.data["d"] = 136; p.data["d16"] = 291; p.data["r16"] = 203;
points[1582]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 19; p.county = 0; p.val = 1180; p.data["black"] = 70; p.data["white"] = 1110; p.data["r"] = 195; p.data["d"] = 273; p.data["d16"] = 0; p.data["r16"] = 0;
points[1583]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 13; p.county = 0; p.val = 875; p.data["black"] = 245; p.data["white"] = 585; p.data["r"] = 147; p.data["d"] = 147; p.data["d16"] = 185; p.data["r16"] = 209;
points[1584]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 15; p.county = 0; p.val = 760; p.data["black"] = 20; p.data["white"] = 720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 171; p.data["r16"] = 814;
points[1585]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 9; p.county = 0; p.val = 925; p.data["black"] = 85; p.data["white"] = 830; p.data["r"] = 193; p.data["d"] = 337; p.data["d16"] = 228; p.data["r16"] = 446;
points[1586]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 6; p.county = 0; p.val = 1030; p.data["black"] = 145; p.data["white"] = 845; p.data["r"] = 209; p.data["d"] = 923; p.data["d16"] = 208; p.data["r16"] = 1099;
points[1587]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 17; p.county = 0; p.val = 3665; p.data["black"] = 590; p.data["white"] = 2680; p.data["r"] = 881; p.data["d"] = 1257; p.data["d16"] = 966; p.data["r16"] = 1407;
points[1588]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 17; p.county = 0; p.val = 1790; p.data["black"] = 525; p.data["white"] = 1130; p.data["r"] = 804; p.data["d"] = 859; p.data["d16"] = 0; p.data["r16"] = 0;
points[1589]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 19; p.county = 0; p.val = 2665; p.data["black"] = 515; p.data["white"] = 1825; p.data["r"] = 621; p.data["d"] = 1006; p.data["d16"] = 0; p.data["r16"] = 0;
points[1590]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 20; p.county = 0; p.val = 3105; p.data["black"] = 275; p.data["white"] = 2455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 591; p.data["r16"] = 1487;
points[1591]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 14; p.county = 0; p.val = 1245; p.data["black"] = 90; p.data["white"] = 1120; p.data["r"] = 149; p.data["d"] = 559; p.data["d16"] = 0; p.data["r16"] = 0;
points[1592]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 11; p.county = 0; p.val = 2060; p.data["black"] = 230; p.data["white"] = 1760; p.data["r"] = 283; p.data["d"] = 826; p.data["d16"] = 546; p.data["r16"] = 2095;
points[1593]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 12; p.county = 0; p.val = 1800; p.data["black"] = 40; p.data["white"] = 1635; p.data["r"] = 801; p.data["d"] = 1874; p.data["d16"] = 540; p.data["r16"] = 1627;
points[1594]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 13; p.county = 0; p.val = 990; p.data["black"] = 175; p.data["white"] = 810; p.data["r"] = 609; p.data["d"] = 644; p.data["d16"] = 619; p.data["r16"] = 828;
points[1595]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 16; p.county = 0; p.val = 455; p.data["black"] = 95; p.data["white"] = 340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1596]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 21; p.county = 0; p.val = 1740; p.data["black"] = 15; p.data["white"] = 1610; p.data["r"] = 452; p.data["d"] = 708; p.data["d16"] = 0; p.data["r16"] = 0;
points[1597]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 104; p.county = 0; p.val = 1335; p.data["black"] = 680; p.data["white"] = 605; p.data["r"] = 383; p.data["d"] = 692; p.data["d16"] = 117; p.data["r16"] = 348;
points[1598]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 105; p.county = 0; p.val = 2045; p.data["black"] = 660; p.data["white"] = 1295; p.data["r"] = 178; p.data["d"] = 669; p.data["d16"] = 213; p.data["r16"] = 468;
points[1599]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 141; p.county = 0; p.val = 6110; p.data["black"] = 2070; p.data["white"] = 3400; p.data["r"] = 1067; p.data["d"] = 1330; p.data["d16"] = 1138; p.data["r16"] = 1757;
points[1600]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 23; p.county = 0; p.val = 2070; p.data["black"] = 545; p.data["white"] = 1515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1601]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 19; p.county = 0; p.val = 2005; p.data["black"] = 190; p.data["white"] = 1730; p.data["r"] = 470; p.data["d"] = 997; p.data["d16"] = 440; p.data["r16"] = 1197;
points[1602]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 22; p.county = 0; p.val = 2010; p.data["black"] = 310; p.data["white"] = 1645; p.data["r"] = 537; p.data["d"] = 1278; p.data["d16"] = 497; p.data["r16"] = 1605;
points[1603]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 109; p.county = 0; p.val = 1975; p.data["black"] = 345; p.data["white"] = 1505; p.data["r"] = 667; p.data["d"] = 1473; p.data["d16"] = 349; p.data["r16"] = 777;
points[1604]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 105; p.county = 0; p.val = 1185; p.data["black"] = 0; p.data["white"] = 1165; p.data["r"] = 333; p.data["d"] = 960; p.data["d16"] = 210; p.data["r16"] = 837;
points[1605]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 108; p.county = 0; p.val = 795; p.data["black"] = 390; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1606]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 110; p.county = 0; p.val = 1060; p.data["black"] = 490; p.data["white"] = 555; p.data["r"] = 406; p.data["d"] = 169; p.data["d16"] = 261; p.data["r16"] = 311;
points[1607]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 113; p.county = 0; p.val = 860; p.data["black"] = 460; p.data["white"] = 355; p.data["r"] = 228; p.data["d"] = 674; p.data["d16"] = 0; p.data["r16"] = 0;
points[1608]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 113; p.county = 0; p.val = 1290; p.data["black"] = 250; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1124; p.data["r16"] = 1866;
points[1609]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 111; p.county = 0; p.val = 3075; p.data["black"] = 390; p.data["white"] = 2550; p.data["r"] = 595; p.data["d"] = 1695; p.data["d16"] = 254; p.data["r16"] = 724;
points[1610]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 113; p.county = 0; p.val = 910; p.data["black"] = 295; p.data["white"] = 560; p.data["r"] = 687; p.data["d"] = 752; p.data["d16"] = 831; p.data["r16"] = 1008;
points[1611]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 107; p.county = 0; p.val = 885; p.data["black"] = 75; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 148; p.data["r16"] = 558;
points[1612]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 117; p.county = 0; p.val = 1465; p.data["black"] = 435; p.data["white"] = 920; p.data["r"] = 537; p.data["d"] = 409; p.data["d16"] = 631; p.data["r16"] = 503;
points[1613]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 119; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1614]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 109; p.county = 0; p.val = 3015; p.data["black"] = 100; p.data["white"] = 2770; p.data["r"] = 210; p.data["d"] = 547; p.data["d16"] = 551; p.data["r16"] = 1450;
points[1615]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 115; p.county = 0; p.val = 540; p.data["black"] = 240; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1616]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 6; p.county = 0; p.val = 1570; p.data["black"] = 25; p.data["white"] = 1440; p.data["r"] = 36; p.data["d"] = 323; p.data["d16"] = 63; p.data["r16"] = 422;
points[1617]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 29; p.county = 0; p.val = 1690; p.data["black"] = 180; p.data["white"] = 1455; p.data["r"] = 381; p.data["d"] = 443; p.data["d16"] = 495; p.data["r16"] = 565;
points[1618]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 25; p.county = 0; p.val = 1015; p.data["black"] = 305; p.data["white"] = 695; p.data["r"] = 287; p.data["d"] = 404; p.data["d16"] = 0; p.data["r16"] = 0;
points[1619]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 21; p.county = 0; p.val = 2385; p.data["black"] = 30; p.data["white"] = 2260; p.data["r"] = 557; p.data["d"] = 907; p.data["d16"] = 0; p.data["r16"] = 0;
points[1620]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 22; p.county = 0; p.val = 1545; p.data["black"] = 425; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1621]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 22; p.county = 0; p.val = 1810; p.data["black"] = 285; p.data["white"] = 1395; p.data["r"] = 998; p.data["d"] = 837; p.data["d16"] = 909; p.data["r16"] = 944;
points[1622]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 31; p.county = 0; p.val = 1020; p.data["black"] = 290; p.data["white"] = 710; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1623]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 107; p.county = 0; p.val = 1025; p.data["black"] = 0; p.data["white"] = 1025; p.data["r"] = 205; p.data["d"] = 331; p.data["d16"] = 238; p.data["r16"] = 455;
points[1624]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 111; p.county = 0; p.val = 1170; p.data["black"] = 215; p.data["white"] = 820; p.data["r"] = 195; p.data["d"] = 295; p.data["d16"] = 274; p.data["r16"] = 482;
points[1625]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 102; p.county = 0; p.val = 2065; p.data["black"] = 450; p.data["white"] = 1565; p.data["r"] = 485; p.data["d"] = 779; p.data["d16"] = 353; p.data["r16"] = 643;
points[1626]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 93; p.county = 0; p.val = 1770; p.data["black"] = 60; p.data["white"] = 1580; p.data["r"] = 121; p.data["d"] = 395; p.data["d16"] = 146; p.data["r16"] = 534;
points[1627]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 16; p.county = 0; p.val = 4425; p.data["black"] = 750; p.data["white"] = 3265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 369; p.data["r16"] = 770;
points[1628]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 19; p.county = 0; p.val = 1665; p.data["black"] = 165; p.data["white"] = 1365; p.data["r"] = 305; p.data["d"] = 807; p.data["d16"] = 348; p.data["r16"] = 1266;
points[1629]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 13; p.county = 0; p.val = 2825; p.data["black"] = 195; p.data["white"] = 2380; p.data["r"] = 742; p.data["d"] = 871; p.data["d16"] = 649; p.data["r16"] = 1254;
points[1630]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 22; p.county = 0; p.val = 1440; p.data["black"] = 595; p.data["white"] = 780; p.data["r"] = 663; p.data["d"] = 555; p.data["d16"] = 698; p.data["r16"] = 715;
points[1631]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 18; p.county = 0; p.val = 2480; p.data["black"] = 240; p.data["white"] = 2170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1632]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 12; p.county = 0; p.val = 1450; p.data["black"] = 75; p.data["white"] = 1335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1633]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 21; p.county = 0; p.val = 950; p.data["black"] = 200; p.data["white"] = 740; p.data["r"] = 237; p.data["d"] = 640; p.data["d16"] = 298; p.data["r16"] = 754;
points[1634]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 15; p.county = 0; p.val = 2035; p.data["black"] = 280; p.data["white"] = 1725; p.data["r"] = 180; p.data["d"] = 667; p.data["d16"] = 243; p.data["r16"] = 925;
points[1635]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 19; p.county = 0; p.val = 1060; p.data["black"] = 95; p.data["white"] = 930; p.data["r"] = 47; p.data["d"] = 212; p.data["d16"] = 56; p.data["r16"] = 261;
points[1636]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 11; p.county = 0; p.val = 2195; p.data["black"] = 559; p.data["white"] = 1575; p.data["r"] = 624; p.data["d"] = 989; p.data["d16"] = 695; p.data["r16"] = 1276;
points[1637]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 10; p.county = 0; p.val = 685; p.data["black"] = 10; p.data["white"] = 610; p.data["r"] = 273; p.data["d"] = 1176; p.data["d16"] = 278; p.data["r16"] = 1599;
points[1638]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 24; p.county = 0; p.val = 3380; p.data["black"] = 200; p.data["white"] = 2690; p.data["r"] = 610; p.data["d"] = 773; p.data["d16"] = 0; p.data["r16"] = 0;
points[1639]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 14; p.county = 0; p.val = 1305; p.data["black"] = 30; p.data["white"] = 1250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1640]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 14; p.county = 0; p.val = 1090; p.data["black"] = 80; p.data["white"] = 995; p.data["r"] = 275; p.data["d"] = 937; p.data["d16"] = 258; p.data["r16"] = 1241;
points[1641]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 68; p.county = 0; p.val = 695; p.data["black"] = 65; p.data["white"] = 630; p.data["r"] = 264; p.data["d"] = 793; p.data["d16"] = 209; p.data["r16"] = 916;
points[1642]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 56; p.county = 0; p.val = 640; p.data["black"] = 330; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 413; p.data["r16"] = 332;
points[1643]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 148; p.county = 0; p.val = 1810; p.data["black"] = 905; p.data["white"] = 805; p.data["r"] = 868; p.data["d"] = 222; p.data["d16"] = 977; p.data["r16"] = 356;
points[1644]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 151; p.county = 0; p.val = 2960; p.data["black"] = 1030; p.data["white"] = 1840; p.data["r"] = 518; p.data["d"] = 54; p.data["d16"] = 897; p.data["r16"] = 562;
points[1645]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 156; p.county = 0; p.val = 2240; p.data["black"] = 75; p.data["white"] = 2075; p.data["r"] = 438; p.data["d"] = 373; p.data["d16"] = 860; p.data["r16"] = 816;
points[1646]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 21; p.county = 0; p.val = 2010; p.data["black"] = 645; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1647]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 22; p.county = 0; p.val = 1555; p.data["black"] = 4; p.data["white"] = 1510; p.data["r"] = 466; p.data["d"] = 574; p.data["d16"] = 0; p.data["r16"] = 0;
points[1648]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 25; p.county = 0; p.val = 755; p.data["black"] = 470; p.data["white"] = 270; p.data["r"] = 457; p.data["d"] = 273; p.data["d16"] = 572; p.data["r16"] = 355;
points[1649]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 14; p.county = 0; p.val = 1715; p.data["black"] = 95; p.data["white"] = 1560; p.data["r"] = 445; p.data["d"] = 867; p.data["d16"] = 435; p.data["r16"] = 1080;
points[1650]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 65; p.county = 0; p.val = 1445; p.data["black"] = 1370; p.data["white"] = 80; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1316; p.data["r16"] = 403;
points[1651]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 59; p.county = 0; p.val = 1075; p.data["black"] = 525; p.data["white"] = 460; p.data["r"] = 339; p.data["d"] = 172; p.data["d16"] = 464; p.data["r16"] = 250;
points[1652]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 57; p.county = 0; p.val = 455; p.data["black"] = 155; p.data["white"] = 235; p.data["r"] = 259; p.data["d"] = 62; p.data["d16"] = 339; p.data["r16"] = 85;
points[1653]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 56; p.county = 0; p.val = 650; p.data["black"] = 425; p.data["white"] = 205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1654]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 66; p.county = 0; p.val = 860; p.data["black"] = 235; p.data["white"] = 625; p.data["r"] = 100; p.data["d"] = 401; p.data["d16"] = 88; p.data["r16"] = 506;
points[1655]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 57; p.county = 0; p.val = 1015; p.data["black"] = 150; p.data["white"] = 860; p.data["r"] = 243; p.data["d"] = 324; p.data["d16"] = 0; p.data["r16"] = 0;
points[1656]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 151; p.county = 0; p.val = 1425; p.data["black"] = 0; p.data["white"] = 1340; p.data["r"] = 67; p.data["d"] = 129; p.data["d16"] = 76; p.data["r16"] = 124;
points[1657]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 159; p.county = 0; p.val = 2720; p.data["black"] = 870; p.data["white"] = 1805; p.data["r"] = 172; p.data["d"] = 276; p.data["d16"] = 159; p.data["r16"] = 305;
points[1658]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 160; p.county = 0; p.val = 820; p.data["black"] = 0; p.data["white"] = 820; p.data["r"] = 471; p.data["d"] = 452; p.data["d16"] = 460; p.data["r16"] = 517;
points[1659]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 167; p.county = 0; p.val = 665; p.data["black"] = 0; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1660]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 154; p.county = 0; p.val = 870; p.data["black"] = 4; p.data["white"] = 855; p.data["r"] = 540; p.data["d"] = 677; p.data["d16"] = 1083; p.data["r16"] = 1548;
points[1661]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 166; p.county = 0; p.val = 1345; p.data["black"] = 680; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1662]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 148; p.county = 0; p.val = 2275; p.data["black"] = 610; p.data["white"] = 1585; p.data["r"] = 1359; p.data["d"] = 2151; p.data["d16"] = 1204; p.data["r16"] = 2079;
points[1663]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 149; p.county = 0; p.val = 1305; p.data["black"] = 0; p.data["white"] = 1305; p.data["r"] = 379; p.data["d"] = 538; p.data["d16"] = 0; p.data["r16"] = 0;
points[1664]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 148; p.county = 0; p.val = 1200; p.data["black"] = 195; p.data["white"] = 980; p.data["r"] = 2056; p.data["d"] = 1640; p.data["d16"] = 1437; p.data["r16"] = 1320;
points[1665]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 151; p.county = 0; p.val = 2675; p.data["black"] = 200; p.data["white"] = 2285; p.data["r"] = 509; p.data["d"] = 676; p.data["d16"] = 862; p.data["r16"] = 1443;
points[1666]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 79; p.county = 0; p.val = 795; p.data["black"] = 770; p.data["white"] = 20; p.data["r"] = 809; p.data["d"] = 134; p.data["d16"] = 1046; p.data["r16"] = 216;
points[1667]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 79; p.county = 0; p.val = 380; p.data["black"] = 165; p.data["white"] = 210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 845; p.data["r16"] = 323;
points[1668]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 30; p.county = 0; p.val = 4205; p.data["black"] = 1270; p.data["white"] = 2780; p.data["r"] = 943; p.data["d"] = 899; p.data["d16"] = 947; p.data["r16"] = 1136;
points[1669]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 28; p.county = 0; p.val = 920; p.data["black"] = 235; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1670]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 33; p.county = 0; p.val = 855; p.data["black"] = 35; p.data["white"] = 645; p.data["r"] = 224; p.data["d"] = 501; p.data["d16"] = 0; p.data["r16"] = 0;
points[1671]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 70; p.county = 0; p.val = 3535; p.data["black"] = 1180; p.data["white"] = 2305; p.data["r"] = 340; p.data["d"] = 244; p.data["d16"] = 0; p.data["r16"] = 0;
points[1672]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 66; p.county = 0; p.val = 990; p.data["black"] = 630; p.data["white"] = 285; p.data["r"] = 603; p.data["d"] = 401; p.data["d16"] = 757; p.data["r16"] = 471;
points[1673]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 67; p.county = 0; p.val = 1750; p.data["black"] = 690; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 805; p.data["r16"] = 731;
points[1674]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 74; p.county = 0; p.val = 865; p.data["black"] = 40; p.data["white"] = 780; p.data["r"] = 396; p.data["d"] = 400; p.data["d16"] = 0; p.data["r16"] = 0;
points[1675]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 84; p.county = 0; p.val = 1175; p.data["black"] = 975; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1676]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 73; p.county = 0; p.val = 1455; p.data["black"] = 125; p.data["white"] = 1200; p.data["r"] = 358; p.data["d"] = 261; p.data["d16"] = 340; p.data["r16"] = 447;
points[1677]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 68; p.county = 0; p.val = 3730; p.data["black"] = 2700; p.data["white"] = 755; p.data["r"] = 1520; p.data["d"] = 177; p.data["d16"] = 4402; p.data["r16"] = 1158;
points[1678]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 151; p.county = 0; p.val = 2025; p.data["black"] = 350; p.data["white"] = 1620; p.data["r"] = 503; p.data["d"] = 541; p.data["d16"] = 215; p.data["r16"] = 277;
points[1679]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 74; p.county = 0; p.val = 1035; p.data["black"] = 645; p.data["white"] = 365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 891; p.data["r16"] = 167;
points[1680]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 78; p.county = 0; p.val = 3355; p.data["black"] = 1570; p.data["white"] = 1575; p.data["r"] = 1308; p.data["d"] = 300; p.data["d16"] = 1361; p.data["r16"] = 130;
points[1681]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 88; p.county = 0; p.val = 440; p.data["black"] = 285; p.data["white"] = 155; p.data["r"] = 689; p.data["d"] = 58; p.data["d16"] = 833; p.data["r16"] = 57;
points[1682]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 64; p.county = 0; p.val = 5025; p.data["black"] = 2465; p.data["white"] = 2460; p.data["r"] = 933; p.data["d"] = 561; p.data["d16"] = 1199; p.data["r16"] = 1503;
points[1683]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 80; p.county = 0; p.val = 755; p.data["black"] = 460; p.data["white"] = 295; p.data["r"] = 303; p.data["d"] = 163; p.data["d16"] = 0; p.data["r16"] = 0;
points[1684]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 106; p.county = 0; p.val = 1380; p.data["black"] = 660; p.data["white"] = 690; p.data["r"] = 393; p.data["d"] = 221; p.data["d16"] = 1558; p.data["r16"] = 619;
points[1685]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 58; p.county = 0; p.val = 2305; p.data["black"] = 1015; p.data["white"] = 1220; p.data["r"] = 267; p.data["d"] = 271; p.data["d16"] = 314; p.data["r16"] = 304;
points[1686]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 142; p.county = 0; p.val = 2915; p.data["black"] = 595; p.data["white"] = 1850; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1687]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 37; p.county = 0; p.val = 2245; p.data["black"] = 140; p.data["white"] = 2050; p.data["r"] = 198; p.data["d"] = 715; p.data["d16"] = 221; p.data["r16"] = 920;
points[1688]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 31; p.county = 0; p.val = 2015; p.data["black"] = 570; p.data["white"] = 1270; p.data["r"] = 402; p.data["d"] = 707; p.data["d16"] = 452; p.data["r16"] = 995;
points[1689]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 37; p.county = 0; p.val = 610; p.data["black"] = 270; p.data["white"] = 330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 340; p.data["r16"] = 485;
points[1690]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 60; p.county = 0; p.val = 810; p.data["black"] = 15; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1691]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 55; p.county = 0; p.val = 370; p.data["black"] = 165; p.data["white"] = 205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1692]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 48; p.county = 0; p.val = 1315; p.data["black"] = 355; p.data["white"] = 880; p.data["r"] = 210; p.data["d"] = 308; p.data["d16"] = 0; p.data["r16"] = 0;
points[1693]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 53; p.county = 0; p.val = 530; p.data["black"] = 235; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1694]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 17; p.county = 0; p.val = 2575; p.data["black"] = 440; p.data["white"] = 1790; p.data["r"] = 603; p.data["d"] = 676; p.data["d16"] = 583; p.data["r16"] = 900;
points[1695]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 16; p.county = 0; p.val = 665; p.data["black"] = 60; p.data["white"] = 605; p.data["r"] = 364; p.data["d"] = 652; p.data["d16"] = 377; p.data["r16"] = 843;
points[1696]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 26; p.county = 0; p.val = 2270; p.data["black"] = 0; p.data["white"] = 2155; p.data["r"] = 318; p.data["d"] = 632; p.data["d16"] = 314; p.data["r16"] = 785;
points[1697]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 24; p.county = 0; p.val = 2260; p.data["black"] = 240; p.data["white"] = 1745; p.data["r"] = 525; p.data["d"] = 783; p.data["d16"] = 1078; p.data["r16"] = 2019;
points[1698]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 21; p.county = 0; p.val = 820; p.data["black"] = 170; p.data["white"] = 595; p.data["r"] = 335; p.data["d"] = 494; p.data["d16"] = 405; p.data["r16"] = 676;
points[1699]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 28; p.county = 0; p.val = 1170; p.data["black"] = 475; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1700]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 139; p.county = 0; p.val = 315; p.data["black"] = 105; p.data["white"] = 210; p.data["r"] = 642; p.data["d"] = 719; p.data["d16"] = 657; p.data["r16"] = 1107;
points[1701]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 55; p.county = 0; p.val = 980; p.data["black"] = 0; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 369; p.data["r16"] = 678;
points[1702]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 49; p.county = 0; p.val = 530; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 62; p.data["d"] = 228; p.data["d16"] = 62; p.data["r16"] = 330;
points[1703]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 47; p.county = 0; p.val = 1065; p.data["black"] = 515; p.data["white"] = 510; p.data["r"] = 355; p.data["d"] = 185; p.data["d16"] = 447; p.data["r16"] = 258;
points[1704]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 30; p.county = 0; p.val = 1900; p.data["black"] = 255; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1705]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 47; p.county = 0; p.val = 410; p.data["black"] = 115; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1706]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 47; p.county = 0; p.val = 2505; p.data["black"] = 390; p.data["white"] = 1990; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1707]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 109; p.county = 0; p.val = 460; p.data["black"] = 450; p.data["white"] = 0; p.data["r"] = 324; p.data["d"] = 3; p.data["d16"] = 394; p.data["r16"] = 9;
points[1708]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 111; p.county = 0; p.val = 475; p.data["black"] = 405; p.data["white"] = 70; p.data["r"] = 624; p.data["d"] = 32; p.data["d16"] = 0; p.data["r16"] = 0;
points[1709]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 108; p.county = 0; p.val = 1175; p.data["black"] = 1130; p.data["white"] = 30; p.data["r"] = 272; p.data["d"] = 12; p.data["d16"] = 0; p.data["r16"] = 0;
points[1710]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 107; p.county = 0; p.val = 715; p.data["black"] = 490; p.data["white"] = 225; p.data["r"] = 627; p.data["d"] = 299; p.data["d16"] = 325; p.data["r16"] = 211;
points[1711]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 104; p.county = 0; p.val = 850; p.data["black"] = 235; p.data["white"] = 600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1712]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 110; p.county = 0; p.val = 825; p.data["black"] = 690; p.data["white"] = 135; p.data["r"] = 680; p.data["d"] = 34; p.data["d16"] = 947; p.data["r16"] = 42;
points[1713]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 117; p.county = 0; p.val = 1495; p.data["black"] = 1000; p.data["white"] = 395; p.data["r"] = 887; p.data["d"] = 168; p.data["d16"] = 867; p.data["r16"] = 210;
points[1714]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 114; p.county = 0; p.val = 1155; p.data["black"] = 790; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1715]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 117; p.county = 0; p.val = 360; p.data["black"] = 75; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 709; p.data["r16"] = 246;
points[1716]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 113; p.county = 0; p.val = 800; p.data["black"] = 585; p.data["white"] = 215; p.data["r"] = 493; p.data["d"] = 165; p.data["d16"] = 1490; p.data["r16"] = 258;
points[1717]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 121; p.county = 0; p.val = 1405; p.data["black"] = 665; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1718]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 108; p.county = 0; p.val = 470; p.data["black"] = 210; p.data["white"] = 260; p.data["r"] = 378; p.data["d"] = 283; p.data["d16"] = 467; p.data["r16"] = 356;
points[1719]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 114; p.county = 0; p.val = 1285; p.data["black"] = 1060; p.data["white"] = 225; p.data["r"] = 409; p.data["d"] = 410; p.data["d16"] = 457; p.data["r16"] = 550;
points[1720]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 120; p.county = 0; p.val = 1040; p.data["black"] = 735; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1721]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 113; p.county = 0; p.val = 680; p.data["black"] = 95; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1722]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 31; p.county = 0; p.val = 515; p.data["black"] = 325; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1723]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 120; p.county = 0; p.val = 960; p.data["black"] = 800; p.data["white"] = 155; p.data["r"] = 768; p.data["d"] = 127; p.data["d16"] = 1052; p.data["r16"] = 171;
points[1724]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 108; p.county = 0; p.val = 830; p.data["black"] = 525; p.data["white"] = 285; p.data["r"] = 319; p.data["d"] = 81; p.data["d16"] = 749; p.data["r16"] = 399;
points[1725]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 117; p.county = 0; p.val = 530; p.data["black"] = 415; p.data["white"] = 105; p.data["r"] = 493; p.data["d"] = 192; p.data["d16"] = 0; p.data["r16"] = 0;
points[1726]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 111; p.county = 0; p.val = 795; p.data["black"] = 465; p.data["white"] = 335; p.data["r"] = 161; p.data["d"] = 67; p.data["d16"] = 802; p.data["r16"] = 72;
points[1727]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 108; p.county = 0; p.val = 975; p.data["black"] = 975; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1728]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 188; p.county = 0; p.val = 2915; p.data["black"] = 225; p.data["white"] = 2435; p.data["r"] = 1045; p.data["d"] = 1685; p.data["d16"] = 656; p.data["r16"] = 1301;
points[1729]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 118; p.county = 0; p.val = 880; p.data["black"] = 225; p.data["white"] = 640; p.data["r"] = 163; p.data["d"] = 406; p.data["d16"] = 189; p.data["r16"] = 553;
points[1730]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 107; p.county = 0; p.val = 1100; p.data["black"] = 1015; p.data["white"] = 25; p.data["r"] = 674; p.data["d"] = 24; p.data["d16"] = 0; p.data["r16"] = 0;
points[1731]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 110; p.county = 0; p.val = 1130; p.data["black"] = 835; p.data["white"] = 285; p.data["r"] = 562; p.data["d"] = 218; p.data["d16"] = 0; p.data["r16"] = 0;
points[1732]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 105; p.county = 0; p.val = 1715; p.data["black"] = 835; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1733]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 110; p.county = 0; p.val = 1345; p.data["black"] = 1060; p.data["white"] = 265; p.data["r"] = 630; p.data["d"] = 47; p.data["d16"] = 644; p.data["r16"] = 63;
points[1734]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 112; p.county = 0; p.val = 1290; p.data["black"] = 1115; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1735]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 116; p.county = 0; p.val = 720; p.data["black"] = 430; p.data["white"] = 170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1736]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 108; p.county = 0; p.val = 480; p.data["black"] = 150; p.data["white"] = 325; p.data["r"] = 88; p.data["d"] = 222; p.data["d16"] = 156; p.data["r16"] = 286;
points[1737]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 125; p.county = 0; p.val = 625; p.data["black"] = 205; p.data["white"] = 410; p.data["r"] = 415; p.data["d"] = 458; p.data["d16"] = 466; p.data["r16"] = 638;
points[1738]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 102; p.county = 0; p.val = 300; p.data["black"] = 30; p.data["white"] = 250; p.data["r"] = 435; p.data["d"] = 287; p.data["d16"] = 500; p.data["r16"] = 344;
points[1739]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 99; p.county = 0; p.val = 620; p.data["black"] = 290; p.data["white"] = 275; p.data["r"] = 395; p.data["d"] = 355; p.data["d16"] = 436; p.data["r16"] = 431;
points[1740]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 106; p.county = 0; p.val = 655; p.data["black"] = 405; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1741]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 100; p.county = 0; p.val = 1440; p.data["black"] = 765; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1742]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 112; p.county = 0; p.val = 565; p.data["black"] = 215; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1743]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 110; p.county = 0; p.val = 2055; p.data["black"] = 725; p.data["white"] = 1310; p.data["r"] = 376; p.data["d"] = 306; p.data["d16"] = 452; p.data["r16"] = 454;
points[1744]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 107; p.county = 0; p.val = 1305; p.data["black"] = 650; p.data["white"] = 630; p.data["r"] = 466; p.data["d"] = 373; p.data["d16"] = 0; p.data["r16"] = 0;
points[1745]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 120; p.county = 0; p.val = 980; p.data["black"] = 395; p.data["white"] = 545; p.data["r"] = 255; p.data["d"] = 178; p.data["d16"] = 375; p.data["r16"] = 239;
points[1746]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 105; p.county = 0; p.val = 725; p.data["black"] = 85; p.data["white"] = 600; p.data["r"] = 219; p.data["d"] = 337; p.data["d16"] = 294; p.data["r16"] = 408;
points[1747]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 115; p.county = 0; p.val = 915; p.data["black"] = 760; p.data["white"] = 160; p.data["r"] = 743; p.data["d"] = 211; p.data["d16"] = 709; p.data["r16"] = 204;
points[1748]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 108; p.county = 0; p.val = 385; p.data["black"] = 215; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 685; p.data["r16"] = 611;
points[1749]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 69; p.county = 0; p.val = 2030; p.data["black"] = 420; p.data["white"] = 1425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 817; p.data["r16"] = 680;
points[1750]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 154; p.county = 0; p.val = 1420; p.data["black"] = 675; p.data["white"] = 690; p.data["r"] = 442; p.data["d"] = 647; p.data["d16"] = 402; p.data["r16"] = 698;
points[1751]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 64; p.county = 0; p.val = 1265; p.data["black"] = 555; p.data["white"] = 690; p.data["r"] = 355; p.data["d"] = 376; p.data["d16"] = 426; p.data["r16"] = 536;
points[1752]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 55; p.county = 0; p.val = 1120; p.data["black"] = 205; p.data["white"] = 865; p.data["r"] = 146; p.data["d"] = 270; p.data["d16"] = 0; p.data["r16"] = 0;
points[1753]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 52; p.county = 0; p.val = 575; p.data["black"] = 345; p.data["white"] = 230; p.data["r"] = 318; p.data["d"] = 81; p.data["d16"] = 0; p.data["r16"] = 0;
points[1754]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 54; p.county = 0; p.val = 1425; p.data["black"] = 325; p.data["white"] = 1060; p.data["r"] = 459; p.data["d"] = 409; p.data["d16"] = 552; p.data["r16"] = 465;
points[1755]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 78; p.county = 0; p.val = 2560; p.data["black"] = 620; p.data["white"] = 1855; p.data["r"] = 1985; p.data["d"] = 1192; p.data["d16"] = 1199; p.data["r16"] = 1467;
points[1756]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 66; p.county = 0; p.val = 2875; p.data["black"] = 1330; p.data["white"] = 1375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1757]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 76; p.county = 0; p.val = 1175; p.data["black"] = 285; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1758]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 73; p.county = 0; p.val = 215; p.data["black"] = 20; p.data["white"] = 190; p.data["r"] = 533; p.data["d"] = 183; p.data["d16"] = 660; p.data["r16"] = 304;
points[1759]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 67; p.county = 0; p.val = 3195; p.data["black"] = 650; p.data["white"] = 2225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1760]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 80; p.county = 0; p.val = 3280; p.data["black"] = 1590; p.data["white"] = 1555; p.data["r"] = 629; p.data["d"] = 173; p.data["d16"] = 1253; p.data["r16"] = 41;
points[1761]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 19; p.county = 0; p.val = 520; p.data["black"] = 35; p.data["white"] = 490; p.data["r"] = 246; p.data["d"] = 724; p.data["d16"] = 176; p.data["r16"] = 831;
points[1762]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 78; p.county = 0; p.val = 1850; p.data["black"] = 205; p.data["white"] = 1470; p.data["r"] = 582; p.data["d"] = 144; p.data["d16"] = 2014; p.data["r16"] = 771;
points[1763]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 71; p.county = 0; p.val = 1635; p.data["black"] = 785; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1764]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 69; p.county = 0; p.val = 3290; p.data["black"] = 975; p.data["white"] = 2110; p.data["r"] = 2507; p.data["d"] = 1518; p.data["d16"] = 2490; p.data["r16"] = 2060;
points[1765]=p;}
if (1==1){ Point p;
p.x = 154; p.y = 72; p.county = 0; p.val = 925; p.data["black"] = 445; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1766]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 88; p.county = 0; p.val = 760; p.data["black"] = 125; p.data["white"] = 610; p.data["r"] = 294; p.data["d"] = 641; p.data["d16"] = 504; p.data["r16"] = 1126;
points[1767]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 66; p.county = 0; p.val = 1955; p.data["black"] = 505; p.data["white"] = 1260; p.data["r"] = 633; p.data["d"] = 784; p.data["d16"] = 599; p.data["r16"] = 888;
points[1768]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 63; p.county = 0; p.val = 1730; p.data["black"] = 1675; p.data["white"] = 4; p.data["r"] = 600; p.data["d"] = 23; p.data["d16"] = 1015; p.data["r16"] = 151;
points[1769]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 15; p.county = 0; p.val = 770; p.data["black"] = 175; p.data["white"] = 565; p.data["r"] = 425; p.data["d"] = 717; p.data["d16"] = 267; p.data["r16"] = 571;
points[1770]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 136; p.county = 0; p.val = 745; p.data["black"] = 400; p.data["white"] = 295; p.data["r"] = 65; p.data["d"] = 58; p.data["d16"] = 83; p.data["r16"] = 93;
points[1771]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 140; p.county = 0; p.val = 450; p.data["black"] = 425; p.data["white"] = 20; p.data["r"] = 459; p.data["d"] = 12; p.data["d16"] = 0; p.data["r16"] = 0;
points[1772]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 125; p.county = 0; p.val = 710; p.data["black"] = 555; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1773]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 115; p.county = 0; p.val = 845; p.data["black"] = 110; p.data["white"] = 665; p.data["r"] = 205; p.data["d"] = 270; p.data["d16"] = 226; p.data["r16"] = 359;
points[1774]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 69; p.county = 0; p.val = 1345; p.data["black"] = 260; p.data["white"] = 1035; p.data["r"] = 603; p.data["d"] = 361; p.data["d16"] = 914; p.data["r16"] = 934;
points[1775]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 68; p.county = 0; p.val = 3030; p.data["black"] = 220; p.data["white"] = 2630; p.data["r"] = 719; p.data["d"] = 1675; p.data["d16"] = 355; p.data["r16"] = 634;
points[1776]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 69; p.county = 0; p.val = 2000; p.data["black"] = 55; p.data["white"] = 1850; p.data["r"] = 717; p.data["d"] = 1228; p.data["d16"] = 930; p.data["r16"] = 1400;
points[1777]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 51; p.county = 0; p.val = 770; p.data["black"] = 460; p.data["white"] = 305; p.data["r"] = 564; p.data["d"] = 161; p.data["d16"] = 390; p.data["r16"] = 312;
points[1778]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 48; p.county = 0; p.val = 735; p.data["black"] = 140; p.data["white"] = 580; p.data["r"] = 77; p.data["d"] = 184; p.data["d16"] = 0; p.data["r16"] = 0;
points[1779]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 62; p.county = 0; p.val = 930; p.data["black"] = 390; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 375; p.data["r16"] = 778;
points[1780]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 50; p.county = 0; p.val = 920; p.data["black"] = 225; p.data["white"] = 685; p.data["r"] = 148; p.data["d"] = 275; p.data["d16"] = 208; p.data["r16"] = 325;
points[1781]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 65; p.county = 0; p.val = 595; p.data["black"] = 300; p.data["white"] = 285; p.data["r"] = 402; p.data["d"] = 223; p.data["d16"] = 0; p.data["r16"] = 0;
points[1782]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 51; p.county = 0; p.val = 730; p.data["black"] = 70; p.data["white"] = 620; p.data["r"] = 61; p.data["d"] = 251; p.data["d16"] = 67; p.data["r16"] = 324;
points[1783]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 62; p.county = 0; p.val = 565; p.data["black"] = 15; p.data["white"] = 545; p.data["r"] = 126; p.data["d"] = 472; p.data["d16"] = 124; p.data["r16"] = 616;
points[1784]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 78; p.county = 0; p.val = 835; p.data["black"] = 790; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1785]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 106; p.county = 0; p.val = 2770; p.data["black"] = 2150; p.data["white"] = 530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1786]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 79; p.county = 0; p.val = 2045; p.data["black"] = 1640; p.data["white"] = 355; p.data["r"] = 320; p.data["d"] = 118; p.data["d16"] = 443; p.data["r16"] = 152;
points[1787]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 79; p.county = 0; p.val = 2735; p.data["black"] = 1080; p.data["white"] = 1285; p.data["r"] = 483; p.data["d"] = 85; p.data["d16"] = 0; p.data["r16"] = 0;
points[1788]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 81; p.county = 0; p.val = 730; p.data["black"] = 595; p.data["white"] = 130; p.data["r"] = 546; p.data["d"] = 105; p.data["d16"] = 0; p.data["r16"] = 0;
points[1789]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 81; p.county = 0; p.val = 1665; p.data["black"] = 1010; p.data["white"] = 600; p.data["r"] = 210; p.data["d"] = 206; p.data["d16"] = 491; p.data["r16"] = 76;
points[1790]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 77; p.county = 0; p.val = 920; p.data["black"] = 185; p.data["white"] = 565; p.data["r"] = 577; p.data["d"] = 454; p.data["d16"] = 529; p.data["r16"] = 548;
points[1791]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 79; p.county = 0; p.val = 2275; p.data["black"] = 640; p.data["white"] = 1550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1792]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 171; p.county = 0; p.val = 1120; p.data["black"] = 350; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1793]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 175; p.county = 0; p.val = 720; p.data["black"] = 485; p.data["white"] = 235; p.data["r"] = 405; p.data["d"] = 456; p.data["d16"] = 541; p.data["r16"] = 743;
points[1794]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 173; p.county = 0; p.val = 1030; p.data["black"] = 470; p.data["white"] = 490; p.data["r"] = 170; p.data["d"] = 301; p.data["d16"] = 853; p.data["r16"] = 382;
points[1795]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 200; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 331; p.data["d"] = 539; p.data["d16"] = 267; p.data["r16"] = 453;
points[1796]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 60; p.county = 0; p.val = 1070; p.data["black"] = 125; p.data["white"] = 930; p.data["r"] = 131; p.data["d"] = 429; p.data["d16"] = 135; p.data["r16"] = 505;
points[1797]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 64; p.county = 0; p.val = 1235; p.data["black"] = 610; p.data["white"] = 610; p.data["r"] = 128; p.data["d"] = 298; p.data["d16"] = 201; p.data["r16"] = 356;
points[1798]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 66; p.county = 0; p.val = 1135; p.data["black"] = 440; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1799]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 54; p.county = 0; p.val = 850; p.data["black"] = 110; p.data["white"] = 630; p.data["r"] = 140; p.data["d"] = 469; p.data["d16"] = 167; p.data["r16"] = 627;
points[1800]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 63; p.county = 0; p.val = 1340; p.data["black"] = 175; p.data["white"] = 1125; p.data["r"] = 279; p.data["d"] = 538; p.data["d16"] = 0; p.data["r16"] = 0;
points[1801]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 66; p.county = 0; p.val = 1205; p.data["black"] = 515; p.data["white"] = 690; p.data["r"] = 145; p.data["d"] = 345; p.data["d16"] = 571; p.data["r16"] = 387;
points[1802]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 70; p.county = 0; p.val = 685; p.data["black"] = 110; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1803]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 68; p.county = 0; p.val = 775; p.data["black"] = 105; p.data["white"] = 675; p.data["r"] = 137; p.data["d"] = 333; p.data["d16"] = 164; p.data["r16"] = 394;
points[1804]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 72; p.county = 0; p.val = 435; p.data["black"] = 395; p.data["white"] = 35; p.data["r"] = 573; p.data["d"] = 371; p.data["d16"] = 0; p.data["r16"] = 0;
points[1805]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 69; p.county = 0; p.val = 480; p.data["black"] = 225; p.data["white"] = 255; p.data["r"] = 302; p.data["d"] = 278; p.data["d16"] = 328; p.data["r16"] = 362;
points[1806]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 57; p.county = 0; p.val = 920; p.data["black"] = 115; p.data["white"] = 770; p.data["r"] = 154; p.data["d"] = 482; p.data["d16"] = 161; p.data["r16"] = 633;
points[1807]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 60; p.county = 0; p.val = 1310; p.data["black"] = 0; p.data["white"] = 1310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1808]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 80; p.county = 0; p.val = 1165; p.data["black"] = 505; p.data["white"] = 650; p.data["r"] = 223; p.data["d"] = 476; p.data["d16"] = 257; p.data["r16"] = 401;
points[1809]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 79; p.county = 0; p.val = 1260; p.data["black"] = 720; p.data["white"] = 515; p.data["r"] = 244; p.data["d"] = 153; p.data["d16"] = 318; p.data["r16"] = 179;
points[1810]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 14; p.county = 0; p.val = 1245; p.data["black"] = 135; p.data["white"] = 955; p.data["r"] = 527; p.data["d"] = 715; p.data["d16"] = 630; p.data["r16"] = 973;
points[1811]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 21; p.county = 0; p.val = 790; p.data["black"] = 0; p.data["white"] = 780; p.data["r"] = 116; p.data["d"] = 465; p.data["d16"] = 126; p.data["r16"] = 678;
points[1812]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 24; p.county = 0; p.val = 890; p.data["black"] = 110; p.data["white"] = 775; p.data["r"] = 68; p.data["d"] = 147; p.data["d16"] = 77; p.data["r16"] = 179;
points[1813]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 6; p.county = 0; p.val = 1535; p.data["black"] = 30; p.data["white"] = 1350; p.data["r"] = 565; p.data["d"] = 926; p.data["d16"] = 549; p.data["r16"] = 1207;
points[1814]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 23; p.county = 0; p.val = 1275; p.data["black"] = 175; p.data["white"] = 1050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1815]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 14; p.county = 0; p.val = 1140; p.data["black"] = 280; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1816]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 25; p.county = 0; p.val = 1200; p.data["black"] = 30; p.data["white"] = 1110; p.data["r"] = 229; p.data["d"] = 1257; p.data["d16"] = 229; p.data["r16"] = 1642;
points[1817]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 13; p.county = 0; p.val = 640; p.data["black"] = 0; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 74; p.data["r16"] = 572;
points[1818]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 18; p.county = 0; p.val = 1690; p.data["black"] = 455; p.data["white"] = 1190; p.data["r"] = 722; p.data["d"] = 623; p.data["d16"] = 0; p.data["r16"] = 0;
points[1819]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 19; p.county = 0; p.val = 1040; p.data["black"] = 380; p.data["white"] = 600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1820]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 35; p.county = 0; p.val = 720; p.data["black"] = 140; p.data["white"] = 525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1821]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 55; p.county = 0; p.val = 1655; p.data["black"] = 305; p.data["white"] = 1260; p.data["r"] = 310; p.data["d"] = 503; p.data["d16"] = 357; p.data["r16"] = 663;
points[1822]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 188; p.county = 0; p.val = 3280; p.data["black"] = 565; p.data["white"] = 1785; p.data["r"] = 418; p.data["d"] = 935; p.data["d16"] = 446; p.data["r16"] = 993;
points[1823]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 188; p.county = 0; p.val = 1260; p.data["black"] = 100; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1824]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 42; p.county = 0; p.val = 990; p.data["black"] = 165; p.data["white"] = 825; p.data["r"] = 52; p.data["d"] = 263; p.data["d16"] = 71; p.data["r16"] = 425;
points[1825]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 35; p.county = 0; p.val = 945; p.data["black"] = 200; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1826]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 27; p.county = 0; p.val = 645; p.data["black"] = 55; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1827]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 32; p.county = 0; p.val = 1775; p.data["black"] = 590; p.data["white"] = 1075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1828]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 41; p.county = 0; p.val = 1065; p.data["black"] = 0; p.data["white"] = 1065; p.data["r"] = 386; p.data["d"] = 866; p.data["d16"] = 523; p.data["r16"] = 1096;
points[1829]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 135; p.county = 0; p.val = 1135; p.data["black"] = 590; p.data["white"] = 425; p.data["r"] = 238; p.data["d"] = 29; p.data["d16"] = 0; p.data["r16"] = 0;
points[1830]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 62; p.county = 0; p.val = 810; p.data["black"] = 435; p.data["white"] = 375; p.data["r"] = 328; p.data["d"] = 289; p.data["d16"] = 290; p.data["r16"] = 210;
points[1831]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 65; p.county = 0; p.val = 800; p.data["black"] = 660; p.data["white"] = 140; p.data["r"] = 245; p.data["d"] = 77; p.data["d16"] = 322; p.data["r16"] = 115;
points[1832]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 67; p.county = 0; p.val = 1135; p.data["black"] = 700; p.data["white"] = 420; p.data["r"] = 384; p.data["d"] = 208; p.data["d16"] = 588; p.data["r16"] = 317;
points[1833]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 71; p.county = 0; p.val = 1135; p.data["black"] = 765; p.data["white"] = 320; p.data["r"] = 352; p.data["d"] = 142; p.data["d16"] = 406; p.data["r16"] = 155;
points[1834]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 75; p.county = 0; p.val = 510; p.data["black"] = 385; p.data["white"] = 90; p.data["r"] = 179; p.data["d"] = 57; p.data["d16"] = 223; p.data["r16"] = 60;
points[1835]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 63; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 323; p.data["d"] = 63; p.data["d16"] = 392; p.data["r16"] = 66;
points[1836]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 8; p.county = 0; p.val = 700; p.data["black"] = 345; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1837]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 7; p.county = 0; p.val = 880; p.data["black"] = 235; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1838]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 7; p.county = 0; p.val = 1305; p.data["black"] = 145; p.data["white"] = 1160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 231; p.data["r16"] = 578;
points[1839]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 8; p.county = 0; p.val = 630; p.data["black"] = 30; p.data["white"] = 600; p.data["r"] = 186; p.data["d"] = 586; p.data["d16"] = 226; p.data["r16"] = 770;
points[1840]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 14; p.county = 0; p.val = 1380; p.data["black"] = 120; p.data["white"] = 1205; p.data["r"] = 76; p.data["d"] = 451; p.data["d16"] = 0; p.data["r16"] = 0;
points[1841]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 62; p.county = 0; p.val = 1360; p.data["black"] = 560; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1842]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 178; p.county = 0; p.val = 4050; p.data["black"] = 810; p.data["white"] = 3100; p.data["r"] = 246; p.data["d"] = 389; p.data["d16"] = 287; p.data["r16"] = 436;
points[1843]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 166; p.county = 0; p.val = 1125; p.data["black"] = 1040; p.data["white"] = 80; p.data["r"] = 205; p.data["d"] = 76; p.data["d16"] = 266; p.data["r16"] = 95;
points[1844]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 171; p.county = 0; p.val = 1835; p.data["black"] = 1245; p.data["white"] = 510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1845]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 172; p.county = 0; p.val = 1405; p.data["black"] = 845; p.data["white"] = 560; p.data["r"] = 714; p.data["d"] = 331; p.data["d16"] = 0; p.data["r16"] = 0;
points[1846]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 22; p.county = 0; p.val = 1585; p.data["black"] = 0; p.data["white"] = 1585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 259; p.data["r16"] = 890;
points[1847]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 66; p.county = 0; p.val = 405; p.data["black"] = 225; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1848]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 65; p.county = 0; p.val = 6335; p.data["black"] = 1690; p.data["white"] = 4265; p.data["r"] = 613; p.data["d"] = 424; p.data["d16"] = 0; p.data["r16"] = 0;
points[1849]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 68; p.county = 0; p.val = 1550; p.data["black"] = 1060; p.data["white"] = 480; p.data["r"] = 569; p.data["d"] = 472; p.data["d16"] = 528; p.data["r16"] = 602;
points[1850]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 85; p.county = 0; p.val = 2355; p.data["black"] = 420; p.data["white"] = 1935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 457; p.data["r16"] = 886;
points[1851]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 77; p.county = 0; p.val = 2050; p.data["black"] = 295; p.data["white"] = 1695; p.data["r"] = 719; p.data["d"] = 521; p.data["d16"] = 397; p.data["r16"] = 519;
points[1852]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 74; p.county = 0; p.val = 1505; p.data["black"] = 65; p.data["white"] = 1365; p.data["r"] = 546; p.data["d"] = 396; p.data["d16"] = 1573; p.data["r16"] = 1576;
points[1853]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 76; p.county = 0; p.val = 2945; p.data["black"] = 300; p.data["white"] = 2465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 335; p.data["r16"] = 799;
points[1854]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 78; p.county = 0; p.val = 1250; p.data["black"] = 25; p.data["white"] = 1175; p.data["r"] = 430; p.data["d"] = 774; p.data["d16"] = 0; p.data["r16"] = 0;
points[1855]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 29; p.county = 0; p.val = 485; p.data["black"] = 15; p.data["white"] = 475; p.data["r"] = 132; p.data["d"] = 350; p.data["d16"] = 199; p.data["r16"] = 1061;
points[1856]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 59; p.county = 0; p.val = 830; p.data["black"] = 105; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1857]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 123; p.county = 0; p.val = 915; p.data["black"] = 195; p.data["white"] = 675; p.data["r"] = 259; p.data["d"] = 353; p.data["d16"] = 295; p.data["r16"] = 472;
points[1858]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 119; p.county = 0; p.val = 1385; p.data["black"] = 290; p.data["white"] = 1095; p.data["r"] = 341; p.data["d"] = 185; p.data["d16"] = 448; p.data["r16"] = 246;
points[1859]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 131; p.county = 0; p.val = 560; p.data["black"] = 205; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1860]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 119; p.county = 0; p.val = 1815; p.data["black"] = 825; p.data["white"] = 935; p.data["r"] = 525; p.data["d"] = 127; p.data["d16"] = 685; p.data["r16"] = 157;
points[1861]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 12; p.county = 0; p.val = 1095; p.data["black"] = 55; p.data["white"] = 1020; p.data["r"] = 193; p.data["d"] = 678; p.data["d16"] = 161; p.data["r16"] = 788;
points[1862]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 31; p.county = 0; p.val = 1595; p.data["black"] = 0; p.data["white"] = 1455; p.data["r"] = 302; p.data["d"] = 187; p.data["d16"] = 671; p.data["r16"] = 593;
points[1863]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 20; p.county = 0; p.val = 935; p.data["black"] = 15; p.data["white"] = 830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1864]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 20; p.county = 0; p.val = 1540; p.data["black"] = 0; p.data["white"] = 1440; p.data["r"] = 298; p.data["d"] = 843; p.data["d16"] = 316; p.data["r16"] = 1151;
points[1865]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 25; p.county = 0; p.val = 1590; p.data["black"] = 80; p.data["white"] = 1495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1866]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 20; p.county = 0; p.val = 1755; p.data["black"] = 35; p.data["white"] = 1685; p.data["r"] = 157; p.data["d"] = 597; p.data["d16"] = 147; p.data["r16"] = 699;
points[1867]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 29; p.county = 0; p.val = 1195; p.data["black"] = 40; p.data["white"] = 1105; p.data["r"] = 256; p.data["d"] = 322; p.data["d16"] = 496; p.data["r16"] = 612;
points[1868]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 22; p.county = 0; p.val = 1155; p.data["black"] = 0; p.data["white"] = 1135; p.data["r"] = 186; p.data["d"] = 990; p.data["d16"] = 203; p.data["r16"] = 1286;
points[1869]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 23; p.county = 0; p.val = 1070; p.data["black"] = 310; p.data["white"] = 730; p.data["r"] = 269; p.data["d"] = 488; p.data["d16"] = 289; p.data["r16"] = 617;
points[1870]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 16; p.county = 0; p.val = 1445; p.data["black"] = 640; p.data["white"] = 670; p.data["r"] = 618; p.data["d"] = 296; p.data["d16"] = 739; p.data["r16"] = 381;
points[1871]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 14; p.county = 0; p.val = 1440; p.data["black"] = 230; p.data["white"] = 680; p.data["r"] = 231; p.data["d"] = 166; p.data["d16"] = 689; p.data["r16"] = 257;
points[1872]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 187; p.county = 0; p.val = 480; p.data["black"] = 0; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1873]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 78; p.county = 0; p.val = 3005; p.data["black"] = 390; p.data["white"] = 2365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1874]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 40; p.county = 0; p.val = 1405; p.data["black"] = 60; p.data["white"] = 1280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1875]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 35; p.county = 0; p.val = 555; p.data["black"] = 15; p.data["white"] = 525; p.data["r"] = 327; p.data["d"] = 784; p.data["d16"] = 312; p.data["r16"] = 1099;
points[1876]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 42; p.county = 0; p.val = 645; p.data["black"] = 30; p.data["white"] = 575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1877]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 39; p.county = 0; p.val = 1250; p.data["black"] = 225; p.data["white"] = 990; p.data["r"] = 28; p.data["d"] = 216; p.data["d16"] = 53; p.data["r16"] = 307;
points[1878]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 43; p.county = 0; p.val = 1190; p.data["black"] = 20; p.data["white"] = 1090; p.data["r"] = 286; p.data["d"] = 618; p.data["d16"] = 0; p.data["r16"] = 0;
points[1879]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 78; p.county = 0; p.val = 2780; p.data["black"] = 440; p.data["white"] = 2135; p.data["r"] = 641; p.data["d"] = 945; p.data["d16"] = 0; p.data["r16"] = 0;
points[1880]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 80; p.county = 0; p.val = 1560; p.data["black"] = 190; p.data["white"] = 1355; p.data["r"] = 434; p.data["d"] = 793; p.data["d16"] = 364; p.data["r16"] = 1090;
points[1881]=p;}
if (1==1){ Point p;
p.x = 194; p.y = 83; p.county = 0; p.val = 1925; p.data["black"] = 365; p.data["white"] = 1525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 339; p.data["r16"] = 740;
points[1882]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 31; p.county = 0; p.val = 660; p.data["black"] = 250; p.data["white"] = 320; p.data["r"] = 418; p.data["d"] = 301; p.data["d16"] = 523; p.data["r16"] = 435;
points[1883]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 31; p.county = 0; p.val = 1250; p.data["black"] = 505; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1884]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 33; p.county = 0; p.val = 1405; p.data["black"] = 460; p.data["white"] = 860; p.data["r"] = 485; p.data["d"] = 616; p.data["d16"] = 513; p.data["r16"] = 855;
points[1885]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 29; p.county = 0; p.val = 1040; p.data["black"] = 980; p.data["white"] = 55; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1886]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 79; p.county = 0; p.val = 860; p.data["black"] = 190; p.data["white"] = 550; p.data["r"] = 300; p.data["d"] = 403; p.data["d16"] = 312; p.data["r16"] = 558;
points[1887]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 79; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1888]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 74; p.county = 0; p.val = 1060; p.data["black"] = 0; p.data["white"] = 1060; p.data["r"] = 236; p.data["d"] = 572; p.data["d16"] = 193; p.data["r16"] = 665;
points[1889]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 80; p.county = 0; p.val = 390; p.data["black"] = 0; p.data["white"] = 390; p.data["r"] = 157; p.data["d"] = 243; p.data["d16"] = 0; p.data["r16"] = 0;
points[1890]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 71; p.county = 0; p.val = 2345; p.data["black"] = 515; p.data["white"] = 1580; p.data["r"] = 888; p.data["d"] = 800; p.data["d16"] = 1335; p.data["r16"] = 643;
points[1891]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 71; p.county = 0; p.val = 2010; p.data["black"] = 910; p.data["white"] = 900; p.data["r"] = 868; p.data["d"] = 254; p.data["d16"] = 545; p.data["r16"] = 323;
points[1892]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 32; p.county = 0; p.val = 2765; p.data["black"] = 350; p.data["white"] = 2185; p.data["r"] = 504; p.data["d"] = 776; p.data["d16"] = 503; p.data["r16"] = 908;
points[1893]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 28; p.county = 0; p.val = 3100; p.data["black"] = 190; p.data["white"] = 2865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1894]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 77; p.county = 0; p.val = 3370; p.data["black"] = 490; p.data["white"] = 2710; p.data["r"] = 2517; p.data["d"] = 915; p.data["d16"] = 2416; p.data["r16"] = 1428;
points[1895]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 153; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 390; p.data["d"] = 704; p.data["d16"] = 334; p.data["r16"] = 668;
points[1896]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 66; p.county = 0; p.val = 3015; p.data["black"] = 495; p.data["white"] = 2455; p.data["r"] = 516; p.data["d"] = 819; p.data["d16"] = 816; p.data["r16"] = 1567;
points[1897]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 62; p.county = 0; p.val = 1700; p.data["black"] = 360; p.data["white"] = 1235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 501; p.data["r16"] = 75;
points[1898]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 67; p.county = 0; p.val = 2200; p.data["black"] = 520; p.data["white"] = 1490; p.data["r"] = 350; p.data["d"] = 611; p.data["d16"] = 457; p.data["r16"] = 826;
points[1899]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 56; p.county = 0; p.val = 2370; p.data["black"] = 360; p.data["white"] = 1895; p.data["r"] = 288; p.data["d"] = 872; p.data["d16"] = 287; p.data["r16"] = 971;
points[1900]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 62; p.county = 0; p.val = 1240; p.data["black"] = 160; p.data["white"] = 1065; p.data["r"] = 516; p.data["d"] = 1212; p.data["d16"] = 270; p.data["r16"] = 730;
points[1901]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 63; p.county = 0; p.val = 3720; p.data["black"] = 1195; p.data["white"] = 2210; p.data["r"] = 801; p.data["d"] = 839; p.data["d16"] = 383; p.data["r16"] = 420;
points[1902]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 62; p.county = 0; p.val = 955; p.data["black"] = 75; p.data["white"] = 865; p.data["r"] = 347; p.data["d"] = 584; p.data["d16"] = 307; p.data["r16"] = 801;
points[1903]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 63; p.county = 0; p.val = 1195; p.data["black"] = 375; p.data["white"] = 775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 386; p.data["r16"] = 682;
points[1904]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 30; p.county = 0; p.val = 1665; p.data["black"] = 1355; p.data["white"] = 265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1905]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 30; p.county = 0; p.val = 900; p.data["black"] = 380; p.data["white"] = 485; p.data["r"] = 442; p.data["d"] = 75; p.data["d16"] = 518; p.data["r16"] = 102;
points[1906]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 30; p.county = 0; p.val = 1810; p.data["black"] = 390; p.data["white"] = 1320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1907]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 65; p.county = 0; p.val = 1730; p.data["black"] = 280; p.data["white"] = 1355; p.data["r"] = 334; p.data["d"] = 384; p.data["d16"] = 198; p.data["r16"] = 698;
points[1908]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 63; p.county = 0; p.val = 835; p.data["black"] = 105; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1909]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 54; p.county = 0; p.val = 570; p.data["black"] = 540; p.data["white"] = 30; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1910]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 136; p.county = 0; p.val = 1255; p.data["black"] = 375; p.data["white"] = 750; p.data["r"] = 229; p.data["d"] = 936; p.data["d16"] = 218; p.data["r16"] = 1330;
points[1911]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 137; p.county = 0; p.val = 3100; p.data["black"] = 700; p.data["white"] = 2125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1912]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 144; p.county = 0; p.val = 690; p.data["black"] = 235; p.data["white"] = 420; p.data["r"] = 1122; p.data["d"] = 892; p.data["d16"] = 97; p.data["r16"] = 141;
points[1913]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 116; p.county = 0; p.val = 1775; p.data["black"] = 860; p.data["white"] = 875; p.data["r"] = 369; p.data["d"] = 293; p.data["d16"] = 429; p.data["r16"] = 410;
points[1914]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 24; p.county = 0; p.val = 1185; p.data["black"] = 175; p.data["white"] = 985; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1915]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 30; p.county = 0; p.val = 1065; p.data["black"] = 285; p.data["white"] = 570; p.data["r"] = 179; p.data["d"] = 157; p.data["d16"] = 224; p.data["r16"] = 231;
points[1916]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 31; p.county = 0; p.val = 650; p.data["black"] = 80; p.data["white"] = 560; p.data["r"] = 566; p.data["d"] = 331; p.data["d16"] = 330; p.data["r16"] = 206;
points[1917]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 81; p.county = 0; p.val = 1145; p.data["black"] = 455; p.data["white"] = 625; p.data["r"] = 549; p.data["d"] = 510; p.data["d16"] = 770; p.data["r16"] = 626;
points[1918]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 83; p.county = 0; p.val = 755; p.data["black"] = 395; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1919]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 31; p.county = 0; p.val = 2525; p.data["black"] = 200; p.data["white"] = 2075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1920]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 17; p.county = 0; p.val = 1280; p.data["black"] = 945; p.data["white"] = 245; p.data["r"] = 407; p.data["d"] = 397; p.data["d16"] = 0; p.data["r16"] = 0;
points[1921]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 16; p.county = 0; p.val = 1310; p.data["black"] = 25; p.data["white"] = 1270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1922]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 15; p.county = 0; p.val = 1840; p.data["black"] = 35; p.data["white"] = 1805; p.data["r"] = 653; p.data["d"] = 1619; p.data["d16"] = 564; p.data["r16"] = 1886;
points[1923]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 11; p.county = 0; p.val = 1820; p.data["black"] = 0; p.data["white"] = 1755; p.data["r"] = 387; p.data["d"] = 1228; p.data["d16"] = 314; p.data["r16"] = 1553;
points[1924]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 14; p.county = 0; p.val = 1390; p.data["black"] = 25; p.data["white"] = 1315; p.data["r"] = 448; p.data["d"] = 1445; p.data["d16"] = 404; p.data["r16"] = 1791;
points[1925]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 23; p.county = 0; p.val = 2470; p.data["black"] = 340; p.data["white"] = 2050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 860; p.data["r16"] = 1340;
points[1926]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 27; p.county = 0; p.val = 2270; p.data["black"] = 365; p.data["white"] = 1875; p.data["r"] = 992; p.data["d"] = 1680; p.data["d16"] = 0; p.data["r16"] = 0;
points[1927]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 25; p.county = 0; p.val = 1005; p.data["black"] = 710; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1928]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 18; p.county = 0; p.val = 2870; p.data["black"] = 530; p.data["white"] = 2130; p.data["r"] = 458; p.data["d"] = 809; p.data["d16"] = 394; p.data["r16"] = 995;
points[1929]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 21; p.county = 0; p.val = 2035; p.data["black"] = 265; p.data["white"] = 1615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1930]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 29; p.county = 0; p.val = 3070; p.data["black"] = 850; p.data["white"] = 1805; p.data["r"] = 968; p.data["d"] = 937; p.data["d16"] = 875; p.data["r16"] = 1105;
points[1931]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 23; p.county = 0; p.val = 2485; p.data["black"] = 50; p.data["white"] = 2375; p.data["r"] = 795; p.data["d"] = 965; p.data["d16"] = 336; p.data["r16"] = 515;
points[1932]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 12; p.county = 0; p.val = 1385; p.data["black"] = 275; p.data["white"] = 1110; p.data["r"] = 288; p.data["d"] = 1082; p.data["d16"] = 502; p.data["r16"] = 1066;
points[1933]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 27; p.county = 0; p.val = 2025; p.data["black"] = 960; p.data["white"] = 975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1934]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 25; p.county = 0; p.val = 3735; p.data["black"] = 475; p.data["white"] = 2950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1935]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 13; p.county = 0; p.val = 1135; p.data["black"] = 55; p.data["white"] = 1040; p.data["r"] = 264; p.data["d"] = 833; p.data["d16"] = 248; p.data["r16"] = 1074;
points[1936]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 42; p.county = 0; p.val = 1135; p.data["black"] = 95; p.data["white"] = 1015; p.data["r"] = 227; p.data["d"] = 563; p.data["d16"] = 265; p.data["r16"] = 787;
points[1937]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 41; p.county = 0; p.val = 1235; p.data["black"] = 260; p.data["white"] = 975; p.data["r"] = 470; p.data["d"] = 952; p.data["d16"] = 430; p.data["r16"] = 1246;
points[1938]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 42; p.county = 0; p.val = 445; p.data["black"] = 55; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 299; p.data["r16"] = 866;
points[1939]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 70; p.county = 0; p.val = 1585; p.data["black"] = 815; p.data["white"] = 640; p.data["r"] = 536; p.data["d"] = 198; p.data["d16"] = 0; p.data["r16"] = 0;
points[1940]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 27; p.county = 0; p.val = 2945; p.data["black"] = 25; p.data["white"] = 2890; p.data["r"] = 842; p.data["d"] = 2624; p.data["d16"] = 282; p.data["r16"] = 1400;
points[1941]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 103; p.county = 0; p.val = 1280; p.data["black"] = 195; p.data["white"] = 1065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1942]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 108; p.county = 0; p.val = 265; p.data["black"] = 70; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 534; p.data["r16"] = 606;
points[1943]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 78; p.county = 0; p.val = 1725; p.data["black"] = 565; p.data["white"] = 1050; p.data["r"] = 231; p.data["d"] = 250; p.data["d16"] = 673; p.data["r16"] = 716;
points[1944]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 108; p.county = 0; p.val = 190; p.data["black"] = 0; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1945]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 30; p.county = 0; p.val = 1250; p.data["black"] = 160; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1946]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 156; p.county = 0; p.val = 915; p.data["black"] = 110; p.data["white"] = 725; p.data["r"] = 1075; p.data["d"] = 739; p.data["d16"] = 1161; p.data["r16"] = 796;
points[1947]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 157; p.county = 0; p.val = 2440; p.data["black"] = 600; p.data["white"] = 1760; p.data["r"] = 214; p.data["d"] = 341; p.data["d16"] = 617; p.data["r16"] = 475;
points[1948]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 72; p.county = 0; p.val = 2955; p.data["black"] = 215; p.data["white"] = 2530; p.data["r"] = 1056; p.data["d"] = 1342; p.data["d16"] = 977; p.data["r16"] = 1315;
points[1949]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 79; p.county = 0; p.val = 645; p.data["black"] = 140; p.data["white"] = 495; p.data["r"] = 345; p.data["d"] = 470; p.data["d16"] = 348; p.data["r16"] = 1004;
points[1950]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 70; p.county = 0; p.val = 2370; p.data["black"] = 890; p.data["white"] = 1360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 314; p.data["r16"] = 258;
points[1951]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 71; p.county = 0; p.val = 1690; p.data["black"] = 295; p.data["white"] = 1300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 617; p.data["r16"] = 779;
points[1952]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 78; p.county = 0; p.val = 1135; p.data["black"] = 190; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 202; p.data["r16"] = 1229;
points[1953]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 81; p.county = 0; p.val = 1120; p.data["black"] = 245; p.data["white"] = 840; p.data["r"] = 513; p.data["d"] = 807; p.data["d16"] = 189; p.data["r16"] = 755;
points[1954]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 82; p.county = 0; p.val = 875; p.data["black"] = 270; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 608; p.data["r16"] = 943;
points[1955]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 32; p.county = 0; p.val = 1530; p.data["black"] = 225; p.data["white"] = 1245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 217; p.data["r16"] = 684;
points[1956]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 3; p.county = 0; p.val = 1355; p.data["black"] = 25; p.data["white"] = 1315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1957]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 2; p.county = 0; p.val = 1600; p.data["black"] = 20; p.data["white"] = 1540; p.data["r"] = 288; p.data["d"] = 931; p.data["d16"] = 222; p.data["r16"] = 1105;
points[1958]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 11; p.county = 0; p.val = 1020; p.data["black"] = 15; p.data["white"] = 990; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 527; p.data["r16"] = 2089;
points[1959]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 17; p.county = 0; p.val = 2225; p.data["black"] = 430; p.data["white"] = 1695; p.data["r"] = 1039; p.data["d"] = 1689; p.data["d16"] = 954; p.data["r16"] = 2069;
points[1960]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 61; p.county = 0; p.val = 1205; p.data["black"] = 1140; p.data["white"] = 65; p.data["r"] = 361; p.data["d"] = 62; p.data["d16"] = 610; p.data["r16"] = 564;
points[1961]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 49; p.county = 0; p.val = 370; p.data["black"] = 0; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1962]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 135; p.county = 0; p.val = 1665; p.data["black"] = 445; p.data["white"] = 1015; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1963]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 132; p.county = 0; p.val = 1520; p.data["black"] = 250; p.data["white"] = 1235; p.data["r"] = 676; p.data["d"] = 558; p.data["d16"] = 586; p.data["r16"] = 764;
points[1964]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 149; p.county = 0; p.val = 4535; p.data["black"] = 100; p.data["white"] = 4355; p.data["r"] = 439; p.data["d"] = 819; p.data["d16"] = 304; p.data["r16"] = 699;
points[1965]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 141; p.county = 0; p.val = 250; p.data["black"] = 15; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1966]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 141; p.county = 0; p.val = 285; p.data["black"] = 45; p.data["white"] = 175; p.data["r"] = 734; p.data["d"] = 525; p.data["d16"] = 703; p.data["r16"] = 708;
points[1967]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 8; p.county = 0; p.val = 1800; p.data["black"] = 260; p.data["white"] = 1450; p.data["r"] = 672; p.data["d"] = 1069; p.data["d16"] = 686; p.data["r16"] = 1586;
points[1968]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 10; p.county = 0; p.val = 2805; p.data["black"] = 340; p.data["white"] = 2250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1969]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 12; p.county = 0; p.val = 750; p.data["black"] = 210; p.data["white"] = 515; p.data["r"] = 265; p.data["d"] = 440; p.data["d16"] = 0; p.data["r16"] = 0;
points[1970]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 11; p.county = 0; p.val = 525; p.data["black"] = 0; p.data["white"] = 525; p.data["r"] = 183; p.data["d"] = 396; p.data["d16"] = 246; p.data["r16"] = 552;
points[1971]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 12; p.county = 0; p.val = 615; p.data["black"] = 60; p.data["white"] = 525; p.data["r"] = 318; p.data["d"] = 264; p.data["d16"] = 435; p.data["r16"] = 390;
points[1972]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 119; p.county = 0; p.val = 555; p.data["black"] = 310; p.data["white"] = 230; p.data["r"] = 352; p.data["d"] = 134; p.data["d16"] = 439; p.data["r16"] = 178;
points[1973]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 43; p.county = 0; p.val = 1825; p.data["black"] = 90; p.data["white"] = 1705; p.data["r"] = 430; p.data["d"] = 658; p.data["d16"] = 566; p.data["r16"] = 842;
points[1974]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 46; p.county = 0; p.val = 865; p.data["black"] = 410; p.data["white"] = 420; p.data["r"] = 417; p.data["d"] = 499; p.data["d16"] = 885; p.data["r16"] = 888;
points[1975]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 41; p.county = 0; p.val = 1255; p.data["black"] = 465; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1976]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 124; p.county = 0; p.val = 430; p.data["black"] = 120; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1977]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 125; p.county = 0; p.val = 425; p.data["black"] = 235; p.data["white"] = 195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 394; p.data["r16"] = 583;
points[1978]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 117; p.county = 0; p.val = 655; p.data["black"] = 150; p.data["white"] = 495; p.data["r"] = 106; p.data["d"] = 207; p.data["d16"] = 330; p.data["r16"] = 481;
points[1979]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 116; p.county = 0; p.val = 690; p.data["black"] = 540; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1980]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 118; p.county = 0; p.val = 315; p.data["black"] = 235; p.data["white"] = 60; p.data["r"] = 822; p.data["d"] = 213; p.data["d16"] = 281; p.data["r16"] = 117;
points[1981]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 122; p.county = 0; p.val = 610; p.data["black"] = 210; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1982]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 130; p.county = 0; p.val = 1490; p.data["black"] = 815; p.data["white"] = 655; p.data["r"] = 513; p.data["d"] = 403; p.data["d16"] = 163; p.data["r16"] = 242;
points[1983]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 125; p.county = 0; p.val = 1155; p.data["black"] = 285; p.data["white"] = 790; p.data["r"] = 346; p.data["d"] = 453; p.data["d16"] = 0; p.data["r16"] = 0;
points[1984]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 113; p.county = 0; p.val = 380; p.data["black"] = 330; p.data["white"] = 45; p.data["r"] = 480; p.data["d"] = 254; p.data["d16"] = 579; p.data["r16"] = 327;
points[1985]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 113; p.county = 0; p.val = 810; p.data["black"] = 665; p.data["white"] = 125; p.data["r"] = 377; p.data["d"] = 101; p.data["d16"] = 460; p.data["r16"] = 112;
points[1986]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 126; p.county = 0; p.val = 730; p.data["black"] = 0; p.data["white"] = 730; p.data["r"] = 38; p.data["d"] = 289; p.data["d16"] = 30; p.data["r16"] = 443;
points[1987]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 123; p.county = 0; p.val = 1195; p.data["black"] = 85; p.data["white"] = 1095; p.data["r"] = 81; p.data["d"] = 439; p.data["d16"] = 119; p.data["r16"] = 577;
points[1988]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 115; p.county = 0; p.val = 1350; p.data["black"] = 410; p.data["white"] = 845; p.data["r"] = 165; p.data["d"] = 185; p.data["d16"] = 0; p.data["r16"] = 0;
points[1989]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 111; p.county = 0; p.val = 1065; p.data["black"] = 760; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1990]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 122; p.county = 0; p.val = 1220; p.data["black"] = 525; p.data["white"] = 670; p.data["r"] = 427; p.data["d"] = 596; p.data["d16"] = 518; p.data["r16"] = 743;
points[1991]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 108; p.county = 0; p.val = 2230; p.data["black"] = 150; p.data["white"] = 2050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1992]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 109; p.county = 0; p.val = 795; p.data["black"] = 0; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 544; p.data["r16"] = 1265;
points[1993]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 106; p.county = 0; p.val = 1840; p.data["black"] = 15; p.data["white"] = 1810; p.data["r"] = 953; p.data["d"] = 1786; p.data["d16"] = 0; p.data["r16"] = 0;
points[1994]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 111; p.county = 0; p.val = 645; p.data["black"] = 225; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1995]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 113; p.county = 0; p.val = 3010; p.data["black"] = 270; p.data["white"] = 2645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1996]=p;}
if (1==1){ Point p;
p.x = 176; p.y = 113; p.county = 0; p.val = 1315; p.data["black"] = 105; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1997]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 36; p.county = 0; p.val = 1460; p.data["black"] = 310; p.data["white"] = 1150; p.data["r"] = 252; p.data["d"] = 422; p.data["d16"] = 285; p.data["r16"] = 572;
points[1998]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 32; p.county = 0; p.val = 705; p.data["black"] = 40; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1999]=p;}

}
void scPoints2(){

if (1==1){ Point p;
p.x = 113; p.y = 40; p.county = 0; p.val = 1320; p.data["black"] = 355; p.data["white"] = 915; p.data["r"] = 332; p.data["d"] = 485; p.data["d16"] = 447; p.data["r16"] = 654;
points[2000]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 31; p.county = 0; p.val = 1330; p.data["black"] = 235; p.data["white"] = 1095; p.data["r"] = 122; p.data["d"] = 444; p.data["d16"] = 235; p.data["r16"] = 1150;
points[2001]=p;}
if (1==1){ Point p;
p.x = 105; p.y = 31; p.county = 0; p.val = 990; p.data["black"] = 290; p.data["white"] = 700; p.data["r"] = 401; p.data["d"] = 323; p.data["d16"] = 457; p.data["r16"] = 439;
points[2002]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 27; p.county = 0; p.val = 1055; p.data["black"] = 245; p.data["white"] = 805; p.data["r"] = 251; p.data["d"] = 189; p.data["d16"] = 365; p.data["r16"] = 373;
points[2003]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 32; p.county = 0; p.val = 2860; p.data["black"] = 905; p.data["white"] = 1420; p.data["r"] = 352; p.data["d"] = 496; p.data["d16"] = 352; p.data["r16"] = 620;
points[2004]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 31; p.county = 0; p.val = 1280; p.data["black"] = 75; p.data["white"] = 1140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2005]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 28; p.county = 0; p.val = 595; p.data["black"] = 85; p.data["white"] = 465; p.data["r"] = 513; p.data["d"] = 547; p.data["d16"] = 632; p.data["r16"] = 813;
points[2006]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 33; p.county = 0; p.val = 545; p.data["black"] = 120; p.data["white"] = 425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2007]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 38; p.county = 0; p.val = 1375; p.data["black"] = 995; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2008]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 39; p.county = 0; p.val = 600; p.data["black"] = 280; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2009]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 26; p.county = 0; p.val = 2035; p.data["black"] = 95; p.data["white"] = 1795; p.data["r"] = 141; p.data["d"] = 484; p.data["d16"] = 149; p.data["r16"] = 674;
points[2010]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 83; p.county = 0; p.val = 1330; p.data["black"] = 905; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2011]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 112; p.county = 0; p.val = 660; p.data["black"] = 30; p.data["white"] = 595; p.data["r"] = 905; p.data["d"] = 1181; p.data["d16"] = 428; p.data["r16"] = 1055;
points[2012]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 116; p.county = 0; p.val = 1520; p.data["black"] = 1500; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 761; p.data["r16"] = 274;
points[2013]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 104; p.county = 0; p.val = 1020; p.data["black"] = 0; p.data["white"] = 980; p.data["r"] = 389; p.data["d"] = 1316; p.data["d16"] = 202; p.data["r16"] = 947;
points[2014]=p;}
if (1==1){ Point p;
p.x = 176; p.y = 110; p.county = 0; p.val = 920; p.data["black"] = 75; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 443; p.data["r16"] = 1176;
points[2015]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 96; p.county = 0; p.val = 915; p.data["black"] = 335; p.data["white"] = 575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2016]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 106; p.county = 0; p.val = 1745; p.data["black"] = 275; p.data["white"] = 1450; p.data["r"] = 816; p.data["d"] = 1304; p.data["d16"] = 379; p.data["r16"] = 825;
points[2017]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 91; p.county = 0; p.val = 755; p.data["black"] = 435; p.data["white"] = 280; p.data["r"] = 204; p.data["d"] = 177; p.data["d16"] = 286; p.data["r16"] = 265;
points[2018]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 35; p.county = 0; p.val = 1225; p.data["black"] = 225; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2019]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 26; p.county = 0; p.val = 1510; p.data["black"] = 220; p.data["white"] = 1290; p.data["r"] = 427; p.data["d"] = 1268; p.data["d16"] = 0; p.data["r16"] = 0;
points[2020]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 41; p.county = 0; p.val = 1455; p.data["black"] = 335; p.data["white"] = 1100; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2021]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 17; p.county = 0; p.val = 10600; p.data["black"] = 605; p.data["white"] = 9765; p.data["r"] = 2160; p.data["d"] = 3356; p.data["d16"] = 1969; p.data["r16"] = 3378;
points[2022]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 32; p.county = 0; p.val = 720; p.data["black"] = 145; p.data["white"] = 575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2023]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 34; p.county = 0; p.val = 1470; p.data["black"] = 660; p.data["white"] = 810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2024]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 41; p.county = 0; p.val = 1180; p.data["black"] = 550; p.data["white"] = 590; p.data["r"] = 134; p.data["d"] = 161; p.data["d16"] = 0; p.data["r16"] = 0;
points[2025]=p;}
if (1==1){ Point p;
p.x = 115; p.y = 43; p.county = 0; p.val = 1170; p.data["black"] = 45; p.data["white"] = 1080; p.data["r"] = 200; p.data["d"] = 635; p.data["d16"] = 209; p.data["r16"] = 836;
points[2026]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 21; p.county = 0; p.val = 1105; p.data["black"] = 85; p.data["white"] = 955; p.data["r"] = 200; p.data["d"] = 355; p.data["d16"] = 0; p.data["r16"] = 0;
points[2027]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 27; p.county = 0; p.val = 1420; p.data["black"] = 325; p.data["white"] = 955; p.data["r"] = 240; p.data["d"] = 457; p.data["d16"] = 339; p.data["r16"] = 630;
points[2028]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 4; p.county = 0; p.val = 1495; p.data["black"] = 50; p.data["white"] = 1390; p.data["r"] = 147; p.data["d"] = 591; p.data["d16"] = 108; p.data["r16"] = 716;
points[2029]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 62; p.county = 0; p.val = 810; p.data["black"] = 310; p.data["white"] = 460; p.data["r"] = 622; p.data["d"] = 723; p.data["d16"] = 1225; p.data["r16"] = 195;
points[2030]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 64; p.county = 0; p.val = 1170; p.data["black"] = 160; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2031]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 74; p.county = 0; p.val = 1940; p.data["black"] = 520; p.data["white"] = 1345; p.data["r"] = 846; p.data["d"] = 158; p.data["d16"] = 1446; p.data["r16"] = 26;
points[2032]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 79; p.county = 0; p.val = 1905; p.data["black"] = 40; p.data["white"] = 1815; p.data["r"] = 384; p.data["d"] = 582; p.data["d16"] = 339; p.data["r16"] = 718;
points[2033]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 38; p.county = 0; p.val = 880; p.data["black"] = 395; p.data["white"] = 480; p.data["r"] = 255; p.data["d"] = 428; p.data["d16"] = 306; p.data["r16"] = 541;
points[2034]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 35; p.county = 0; p.val = 375; p.data["black"] = 65; p.data["white"] = 315; p.data["r"] = 425; p.data["d"] = 532; p.data["d16"] = 483; p.data["r16"] = 595;
points[2035]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 76; p.county = 0; p.val = 1550; p.data["black"] = 310; p.data["white"] = 1180; p.data["r"] = 419; p.data["d"] = 681; p.data["d16"] = 509; p.data["r16"] = 569;
points[2036]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 76; p.county = 0; p.val = 1440; p.data["black"] = 240; p.data["white"] = 1025; p.data["r"] = 297; p.data["d"] = 457; p.data["d16"] = 295; p.data["r16"] = 615;
points[2037]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 1; p.county = 0; p.val = 1005; p.data["black"] = 210; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2038]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 10; p.county = 0; p.val = 675; p.data["black"] = 40; p.data["white"] = 580; p.data["r"] = 217; p.data["d"] = 674; p.data["d16"] = 236; p.data["r16"] = 932;
points[2039]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 27; p.county = 0; p.val = 1115; p.data["black"] = 35; p.data["white"] = 1075; p.data["r"] = 88; p.data["d"] = 400; p.data["d16"] = 118; p.data["r16"] = 601;
points[2040]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 4; p.county = 0; p.val = 965; p.data["black"] = 105; p.data["white"] = 865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2041]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 12; p.county = 0; p.val = 1790; p.data["black"] = 90; p.data["white"] = 1510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2042]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 26; p.county = 0; p.val = 1845; p.data["black"] = 220; p.data["white"] = 1545; p.data["r"] = 135; p.data["d"] = 560; p.data["d16"] = 154; p.data["r16"] = 746;
points[2043]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 34; p.county = 0; p.val = 2055; p.data["black"] = 165; p.data["white"] = 1820; p.data["r"] = 251; p.data["d"] = 778; p.data["d16"] = 328; p.data["r16"] = 1191;
points[2044]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 10; p.county = 0; p.val = 1740; p.data["black"] = 230; p.data["white"] = 1405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2045]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 1; p.county = 0; p.val = 515; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 299; p.data["d"] = 820; p.data["d16"] = 346; p.data["r16"] = 1195;
points[2046]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 16; p.county = 0; p.val = 1740; p.data["black"] = 410; p.data["white"] = 1195; p.data["r"] = 515; p.data["d"] = 550; p.data["d16"] = 0; p.data["r16"] = 0;
points[2047]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 10; p.county = 0; p.val = 1290; p.data["black"] = 20; p.data["white"] = 1235; p.data["r"] = 378; p.data["d"] = 1022; p.data["d16"] = 399; p.data["r16"] = 1184;
points[2048]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 8; p.county = 0; p.val = 1455; p.data["black"] = 80; p.data["white"] = 1350; p.data["r"] = 173; p.data["d"] = 571; p.data["d16"] = 218; p.data["r16"] = 748;
points[2049]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 5; p.county = 0; p.val = 1400; p.data["black"] = 15; p.data["white"] = 1360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2050]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 69; p.county = 0; p.val = 685; p.data["black"] = 285; p.data["white"] = 375; p.data["r"] = 424; p.data["d"] = 703; p.data["d16"] = 366; p.data["r16"] = 850;
points[2051]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 15; p.county = 0; p.val = 1045; p.data["black"] = 110; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2052]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 6; p.county = 0; p.val = 725; p.data["black"] = 0; p.data["white"] = 725; p.data["r"] = 112; p.data["d"] = 737; p.data["d16"] = 147; p.data["r16"] = 1013;
points[2053]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 77; p.county = 0; p.val = 1875; p.data["black"] = 295; p.data["white"] = 1570; p.data["r"] = 348; p.data["d"] = 692; p.data["d16"] = 577; p.data["r16"] = 1230;
points[2054]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 75; p.county = 0; p.val = 1800; p.data["black"] = 90; p.data["white"] = 1665; p.data["r"] = 492; p.data["d"] = 140; p.data["d16"] = 1750; p.data["r16"] = 543;
points[2055]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 137; p.county = 0; p.val = 2935; p.data["black"] = 570; p.data["white"] = 2265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 276; p.data["r16"] = 438;
points[2056]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 138; p.county = 0; p.val = 2955; p.data["black"] = 745; p.data["white"] = 1985; p.data["r"] = 390; p.data["d"] = 472; p.data["d16"] = 0; p.data["r16"] = 0;
points[2057]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 128; p.county = 0; p.val = 1480; p.data["black"] = 670; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2058]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 12; p.county = 0; p.val = 1200; p.data["black"] = 425; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2059]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 11; p.county = 0; p.val = 1795; p.data["black"] = 555; p.data["white"] = 1215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2060]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 11; p.county = 0; p.val = 640; p.data["black"] = 135; p.data["white"] = 460; p.data["r"] = 249; p.data["d"] = 200; p.data["d16"] = 913; p.data["r16"] = 1166;
points[2061]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 10; p.county = 0; p.val = 1850; p.data["black"] = 310; p.data["white"] = 1525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2062]=p;}
if (1==1){ Point p;
p.x = 173; p.y = 75; p.county = 0; p.val = 1165; p.data["black"] = 205; p.data["white"] = 950; p.data["r"] = 200; p.data["d"] = 751; p.data["d16"] = 165; p.data["r16"] = 816;
points[2063]=p;}
if (1==1){ Point p;
p.x = 191; p.y = 76; p.county = 0; p.val = 525; p.data["black"] = 275; p.data["white"] = 235; p.data["r"] = 256; p.data["d"] = 280; p.data["d16"] = 0; p.data["r16"] = 0;
points[2064]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 69; p.county = 0; p.val = 1075; p.data["black"] = 200; p.data["white"] = 875; p.data["r"] = 131; p.data["d"] = 334; p.data["d16"] = 268; p.data["r16"] = 767;
points[2065]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 98; p.county = 0; p.val = 3365; p.data["black"] = 205; p.data["white"] = 2980; p.data["r"] = 656; p.data["d"] = 1173; p.data["d16"] = 452; p.data["r16"] = 1165;
points[2066]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 73; p.county = 0; p.val = 3385; p.data["black"] = 1555; p.data["white"] = 1725; p.data["r"] = 1022; p.data["d"] = 107; p.data["d16"] = 561; p.data["r16"] = 59;
points[2067]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 78; p.county = 0; p.val = 565; p.data["black"] = 55; p.data["white"] = 485; p.data["r"] = 368; p.data["d"] = 474; p.data["d16"] = 398; p.data["r16"] = 636;
points[2068]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 77; p.county = 0; p.val = 1335; p.data["black"] = 300; p.data["white"] = 935; p.data["r"] = 459; p.data["d"] = 543; p.data["d16"] = 383; p.data["r16"] = 85;
points[2069]=p;}
if (1==1){ Point p;
p.x = 178; p.y = 111; p.county = 0; p.val = 415; p.data["black"] = 0; p.data["white"] = 415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2070]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 104; p.county = 0; p.val = 1585; p.data["black"] = 600; p.data["white"] = 980; p.data["r"] = 1237; p.data["d"] = 2754; p.data["d16"] = 1243; p.data["r16"] = 3148;
points[2071]=p;}
if (1==1){ Point p;
p.x = 176; p.y = 111; p.county = 0; p.val = 950; p.data["black"] = 205; p.data["white"] = 745; p.data["r"] = 487; p.data["d"] = 1108; p.data["d16"] = 0; p.data["r16"] = 0;
points[2072]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 111; p.county = 0; p.val = 525; p.data["black"] = 225; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 815; p.data["r16"] = 1034;
points[2073]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 110; p.county = 0; p.val = 780; p.data["black"] = 380; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2074]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 77; p.county = 0; p.val = 1090; p.data["black"] = 110; p.data["white"] = 935; p.data["r"] = 295; p.data["d"] = 285; p.data["d16"] = 524; p.data["r16"] = 747;
points[2075]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 79; p.county = 0; p.val = 2630; p.data["black"] = 480; p.data["white"] = 2070; p.data["r"] = 544; p.data["d"] = 255; p.data["d16"] = 0; p.data["r16"] = 0;
points[2076]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 78; p.county = 0; p.val = 2150; p.data["black"] = 225; p.data["white"] = 1775; p.data["r"] = 357; p.data["d"] = 622; p.data["d16"] = 0; p.data["r16"] = 0;
points[2077]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 87; p.county = 0; p.val = 1220; p.data["black"] = 180; p.data["white"] = 1000; p.data["r"] = 149; p.data["d"] = 521; p.data["d16"] = 0; p.data["r16"] = 0;
points[2078]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 75; p.county = 0; p.val = 2020; p.data["black"] = 15; p.data["white"] = 1910; p.data["r"] = 388; p.data["d"] = 953; p.data["d16"] = 0; p.data["r16"] = 0;
points[2079]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 83; p.county = 0; p.val = 635; p.data["black"] = 435; p.data["white"] = 200; p.data["r"] = 1128; p.data["d"] = 331; p.data["d16"] = 1386; p.data["r16"] = 416;
points[2080]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 133; p.county = 0; p.val = 1615; p.data["black"] = 15; p.data["white"] = 1505; p.data["r"] = 1157; p.data["d"] = 1518; p.data["d16"] = 801; p.data["r16"] = 1557;
points[2081]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 142; p.county = 0; p.val = 775; p.data["black"] = 180; p.data["white"] = 485; p.data["r"] = 572; p.data["d"] = 787; p.data["d16"] = 274; p.data["r16"] = 674;
points[2082]=p;}
if (1==1){ Point p;
p.x = 136; p.y = 138; p.county = 0; p.val = 1355; p.data["black"] = 335; p.data["white"] = 975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2083]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 8; p.county = 0; p.val = 1315; p.data["black"] = 80; p.data["white"] = 1220; p.data["r"] = 125; p.data["d"] = 468; p.data["d16"] = 121; p.data["r16"] = 547;
points[2084]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 8; p.county = 0; p.val = 1175; p.data["black"] = 195; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2085]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 19; p.county = 0; p.val = 585; p.data["black"] = 30; p.data["white"] = 510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2086]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 17; p.county = 0; p.val = 865; p.data["black"] = 355; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2087]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 2; p.county = 0; p.val = 705; p.data["black"] = 160; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2088]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 60; p.county = 0; p.val = 570; p.data["black"] = 305; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2089]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 82; p.county = 0; p.val = 1200; p.data["black"] = 160; p.data["white"] = 950; p.data["r"] = 210; p.data["d"] = 418; p.data["d16"] = 210; p.data["r16"] = 548;
points[2090]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 99; p.county = 0; p.val = 715; p.data["black"] = 15; p.data["white"] = 695; p.data["r"] = 1158; p.data["d"] = 1368; p.data["d16"] = 312; p.data["r16"] = 709;
points[2091]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 87; p.county = 0; p.val = 1875; p.data["black"] = 225; p.data["white"] = 1565; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2092]=p;}
if (1==1){ Point p;
p.x = 194; p.y = 87; p.county = 0; p.val = 2005; p.data["black"] = 40; p.data["white"] = 1910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2093]=p;}
if (1==1){ Point p;
p.x = 197; p.y = 84; p.county = 0; p.val = 1490; p.data["black"] = 165; p.data["white"] = 1240; p.data["r"] = 378; p.data["d"] = 887; p.data["d16"] = 303; p.data["r16"] = 787;
points[2094]=p;}
if (1==1){ Point p;
p.x = 198; p.y = 84; p.county = 0; p.val = 2485; p.data["black"] = 104; p.data["white"] = 2255; p.data["r"] = 449; p.data["d"] = 1072; p.data["d16"] = 0; p.data["r16"] = 0;
points[2095]=p;}
if (1==1){ Point p;
p.x = 199; p.y = 84; p.county = 0; p.val = 850; p.data["black"] = 20; p.data["white"] = 805; p.data["r"] = 681; p.data["d"] = 1464; p.data["d16"] = 372; p.data["r16"] = 925;
points[2096]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 83; p.county = 0; p.val = 1240; p.data["black"] = 40; p.data["white"] = 1180; p.data["r"] = 201; p.data["d"] = 706; p.data["d16"] = 0; p.data["r16"] = 0;
points[2097]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 11; p.county = 0; p.val = 565; p.data["black"] = 85; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2098]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 18; p.county = 0; p.val = 660; p.data["black"] = 125; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 245; p.data["r16"] = 376;
points[2099]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 17; p.county = 0; p.val = 1180; p.data["black"] = 445; p.data["white"] = 630; p.data["r"] = 347; p.data["d"] = 259; p.data["d16"] = 450; p.data["r16"] = 347;
points[2100]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 15; p.county = 0; p.val = 925; p.data["black"] = 35; p.data["white"] = 850; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2101]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 16; p.county = 0; p.val = 1130; p.data["black"] = 550; p.data["white"] = 565; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 414; p.data["r16"] = 752;
points[2102]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 81; p.county = 0; p.val = 920; p.data["black"] = 0; p.data["white"] = 885; p.data["r"] = 145; p.data["d"] = 554; p.data["d16"] = 103; p.data["r16"] = 642;
points[2103]=p;}
if (1==1){ Point p;
p.x = 190; p.y = 72; p.county = 0; p.val = 1005; p.data["black"] = 480; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2104]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 82; p.county = 0; p.val = 1360; p.data["black"] = 180; p.data["white"] = 1095; p.data["r"] = 252; p.data["d"] = 522; p.data["d16"] = 0; p.data["r16"] = 0;
points[2105]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 77; p.county = 0; p.val = 2080; p.data["black"] = 115; p.data["white"] = 1790; p.data["r"] = 861; p.data["d"] = 1530; p.data["d16"] = 260; p.data["r16"] = 656;
points[2106]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 66; p.county = 0; p.val = 980; p.data["black"] = 455; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2107]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 79; p.county = 0; p.val = 565; p.data["black"] = 65; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 852; p.data["r16"] = 2187;
points[2108]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 78; p.county = 0; p.val = 2130; p.data["black"] = 120; p.data["white"] = 1850; p.data["r"] = 239; p.data["d"] = 561; p.data["d16"] = 215; p.data["r16"] = 725;
points[2109]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 25; p.county = 0; p.val = 1725; p.data["black"] = 270; p.data["white"] = 1435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2110]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 24; p.county = 0; p.val = 3000; p.data["black"] = 195; p.data["white"] = 2735; p.data["r"] = 597; p.data["d"] = 1426; p.data["d16"] = 427; p.data["r16"] = 1529;
points[2111]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 139; p.county = 0; p.val = 2410; p.data["black"] = 200; p.data["white"] = 2100; p.data["r"] = 612; p.data["d"] = 1001; p.data["d16"] = 629; p.data["r16"] = 1326;
points[2112]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 15; p.county = 0; p.val = 1205; p.data["black"] = 405; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2113]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 14; p.county = 0; p.val = 1560; p.data["black"] = 40; p.data["white"] = 1315; p.data["r"] = 670; p.data["d"] = 1374; p.data["d16"] = 621; p.data["r16"] = 1863;
points[2114]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 21; p.county = 0; p.val = 1015; p.data["black"] = 125; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2115]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 28; p.county = 0; p.val = 1145; p.data["black"] = 475; p.data["white"] = 670; p.data["r"] = 145; p.data["d"] = 358; p.data["d16"] = 202; p.data["r16"] = 558;
points[2116]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 7; p.county = 0; p.val = 1265; p.data["black"] = 150; p.data["white"] = 1120; p.data["r"] = 237; p.data["d"] = 480; p.data["d16"] = 193; p.data["r16"] = 621;
points[2117]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 100; p.county = 0; p.val = 5635; p.data["black"] = 215; p.data["white"] = 4990; p.data["r"] = 446; p.data["d"] = 902; p.data["d16"] = 393; p.data["r16"] = 1167;
points[2118]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 101; p.county = 0; p.val = 2835; p.data["black"] = 30; p.data["white"] = 2615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 750; p.data["r16"] = 1632;
points[2119]=p;}
if (1==1){ Point p;
p.x = 159; p.y = 77; p.county = 0; p.val = 910; p.data["black"] = 570; p.data["white"] = 330; p.data["r"] = 261; p.data["d"] = 95; p.data["d16"] = 407; p.data["r16"] = 139;
points[2120]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 65; p.county = 0; p.val = 1140; p.data["black"] = 105; p.data["white"] = 1010; p.data["r"] = 236; p.data["d"] = 514; p.data["d16"] = 949; p.data["r16"] = 1208;
points[2121]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 65; p.county = 0; p.val = 2605; p.data["black"] = 1550; p.data["white"] = 1015; p.data["r"] = 585; p.data["d"] = 562; p.data["d16"] = 657; p.data["r16"] = 738;
points[2122]=p;}
if (1==1){ Point p;
p.x = 159; p.y = 73; p.county = 0; p.val = 810; p.data["black"] = 580; p.data["white"] = 220; p.data["r"] = 245; p.data["d"] = 109; p.data["d16"] = 355; p.data["r16"] = 164;
points[2123]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 79; p.county = 0; p.val = 785; p.data["black"] = 0; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2124]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 86; p.county = 0; p.val = 1210; p.data["black"] = 815; p.data["white"] = 390; p.data["r"] = 796; p.data["d"] = 511; p.data["d16"] = 1099; p.data["r16"] = 805;
points[2125]=p;}
if (1==1){ Point p;
p.x = 159; p.y = 87; p.county = 0; p.val = 740; p.data["black"] = 195; p.data["white"] = 545; p.data["r"] = 17; p.data["d"] = 179; p.data["d16"] = 18; p.data["r16"] = 287;
points[2126]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 59; p.county = 0; p.val = 1245; p.data["black"] = 275; p.data["white"] = 925; p.data["r"] = 97; p.data["d"] = 183; p.data["d16"] = 106; p.data["r16"] = 262;
points[2127]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 78; p.county = 0; p.val = 545; p.data["black"] = 240; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2128]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 82; p.county = 0; p.val = 600; p.data["black"] = 180; p.data["white"] = 370; p.data["r"] = 121; p.data["d"] = 275; p.data["d16"] = 184; p.data["r16"] = 384;
points[2129]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 71; p.county = 0; p.val = 445; p.data["black"] = 4; p.data["white"] = 440; p.data["r"] = 188; p.data["d"] = 435; p.data["d16"] = 0; p.data["r16"] = 0;
points[2130]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 63; p.county = 0; p.val = 760; p.data["black"] = 655; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2131]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 83; p.county = 0; p.val = 1120; p.data["black"] = 370; p.data["white"] = 750; p.data["r"] = 73; p.data["d"] = 206; p.data["d16"] = 90; p.data["r16"] = 311;
points[2132]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 81; p.county = 0; p.val = 1025; p.data["black"] = 350; p.data["white"] = 670; p.data["r"] = 361; p.data["d"] = 421; p.data["d16"] = 490; p.data["r16"] = 583;
points[2133]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 65; p.county = 0; p.val = 1010; p.data["black"] = 410; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2134]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 81; p.county = 0; p.val = 2815; p.data["black"] = 655; p.data["white"] = 2070; p.data["r"] = 234; p.data["d"] = 611; p.data["d16"] = 0; p.data["r16"] = 0;
points[2135]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 76; p.county = 0; p.val = 1350; p.data["black"] = 50; p.data["white"] = 1210; p.data["r"] = 598; p.data["d"] = 1120; p.data["d16"] = 863; p.data["r16"] = 2357;
points[2136]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 66; p.county = 0; p.val = 1660; p.data["black"] = 85; p.data["white"] = 1470; p.data["r"] = 531; p.data["d"] = 1115; p.data["d16"] = 526; p.data["r16"] = 1475;
points[2137]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 80; p.county = 0; p.val = 770; p.data["black"] = 170; p.data["white"] = 560; p.data["r"] = 567; p.data["d"] = 778; p.data["d16"] = 536; p.data["r16"] = 967;
points[2138]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 69; p.county = 0; p.val = 3025; p.data["black"] = 0; p.data["white"] = 2970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 227; p.data["r16"] = 897;
points[2139]=p;}
if (1==1){ Point p;
p.x = 173; p.y = 82; p.county = 0; p.val = 1180; p.data["black"] = 70; p.data["white"] = 1090; p.data["r"] = 25; p.data["d"] = 234; p.data["d16"] = 21; p.data["r16"] = 365;
points[2140]=p;}
if (1==1){ Point p;
p.x = 197; p.y = 86; p.county = 0; p.val = 1685; p.data["black"] = 20; p.data["white"] = 1625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2141]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 85; p.county = 0; p.val = 1910; p.data["black"] = 705; p.data["white"] = 1155; p.data["r"] = 355; p.data["d"] = 423; p.data["d16"] = 387; p.data["r16"] = 438;
points[2142]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 76; p.county = 0; p.val = 770; p.data["black"] = 165; p.data["white"] = 605; p.data["r"] = 61; p.data["d"] = 289; p.data["d16"] = 0; p.data["r16"] = 0;
points[2143]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 87; p.county = 0; p.val = 1280; p.data["black"] = 765; p.data["white"] = 515; p.data["r"] = 185; p.data["d"] = 165; p.data["d16"] = 0; p.data["r16"] = 0;
points[2144]=p;}
if (1==1){ Point p;
p.x = 200; p.y = 85; p.county = 0; p.val = 870; p.data["black"] = 135; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2145]=p;}
if (1==1){ Point p;
p.x = 180; p.y = 78; p.county = 0; p.val = 705; p.data["black"] = 0; p.data["white"] = 670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 257; p.data["r16"] = 911;
points[2146]=p;}
if (1==1){ Point p;
p.x = 193; p.y = 89; p.county = 0; p.val = 925; p.data["black"] = 0; p.data["white"] = 870; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 588; p.data["r16"] = 1708;
points[2147]=p;}
if (1==1){ Point p;
p.x = 175; p.y = 80; p.county = 0; p.val = 1130; p.data["black"] = 0; p.data["white"] = 1130; p.data["r"] = 75; p.data["d"] = 515; p.data["d16"] = 88; p.data["r16"] = 647;
points[2148]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 86; p.county = 0; p.val = 2595; p.data["black"] = 1985; p.data["white"] = 535; p.data["r"] = 529; p.data["d"] = 70; p.data["d16"] = 723; p.data["r16"] = 53;
points[2149]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 73; p.county = 0; p.val = 1895; p.data["black"] = 310; p.data["white"] = 1460; p.data["r"] = 147; p.data["d"] = 247; p.data["d16"] = 242; p.data["r16"] = 679;
points[2150]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 91; p.county = 0; p.val = 535; p.data["black"] = 20; p.data["white"] = 485; p.data["r"] = 95; p.data["d"] = 214; p.data["d16"] = 87; p.data["r16"] = 234;
points[2151]=p;}
if (1==1){ Point p;
p.x = 189; p.y = 74; p.county = 0; p.val = 950; p.data["black"] = 555; p.data["white"] = 380; p.data["r"] = 472; p.data["d"] = 824; p.data["d16"] = 328; p.data["r16"] = 326;
points[2152]=p;}
if (1==1){ Point p;
p.x = 188; p.y = 80; p.county = 0; p.val = 1085; p.data["black"] = 190; p.data["white"] = 870; p.data["r"] = 45; p.data["d"] = 246; p.data["d16"] = 286; p.data["r16"] = 358;
points[2153]=p;}
if (1==1){ Point p;
p.x = 181; p.y = 73; p.county = 0; p.val = 575; p.data["black"] = 290; p.data["white"] = 255; p.data["r"] = 260; p.data["d"] = 486; p.data["d16"] = 302; p.data["r16"] = 674;
points[2154]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 89; p.county = 0; p.val = 4055; p.data["black"] = 590; p.data["white"] = 3410; p.data["r"] = 498; p.data["d"] = 898; p.data["d16"] = 376; p.data["r16"] = 507;
points[2155]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 88; p.county = 0; p.val = 1825; p.data["black"] = 195; p.data["white"] = 1540; p.data["r"] = 296; p.data["d"] = 853; p.data["d16"] = 482; p.data["r16"] = 1209;
points[2156]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 80; p.county = 0; p.val = 1610; p.data["black"] = 260; p.data["white"] = 1240; p.data["r"] = 50; p.data["d"] = 288; p.data["d16"] = 47; p.data["r16"] = 378;
points[2157]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 67; p.county = 0; p.val = 1635; p.data["black"] = 255; p.data["white"] = 1365; p.data["r"] = 12; p.data["d"] = 152; p.data["d16"] = 19; p.data["r16"] = 207;
points[2158]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 10; p.county = 0; p.val = 1410; p.data["black"] = 100; p.data["white"] = 1240; p.data["r"] = 1150; p.data["d"] = 1755; p.data["d16"] = 587; p.data["r16"] = 1426;
points[2159]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 14; p.county = 0; p.val = 1110; p.data["black"] = 125; p.data["white"] = 985; p.data["r"] = 365; p.data["d"] = 406; p.data["d16"] = 465; p.data["r16"] = 585;
points[2160]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 20; p.county = 0; p.val = 1590; p.data["black"] = 170; p.data["white"] = 1295; p.data["r"] = 520; p.data["d"] = 1036; p.data["d16"] = 470; p.data["r16"] = 1428;
points[2161]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 97; p.county = 0; p.val = 1625; p.data["black"] = 15; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2162]=p;}
if (1==1){ Point p;
p.x = 195; p.y = 88; p.county = 0; p.val = 1760; p.data["black"] = 0; p.data["white"] = 1670; p.data["r"] = 722; p.data["d"] = 1392; p.data["d16"] = 710; p.data["r16"] = 1699;
points[2163]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 103; p.county = 0; p.val = 1415; p.data["black"] = 0; p.data["white"] = 1380; p.data["r"] = 309; p.data["d"] = 784; p.data["d16"] = 502; p.data["r16"] = 1784;
points[2164]=p;}
if (1==1){ Point p;
p.x = 185; p.y = 95; p.county = 0; p.val = 995; p.data["black"] = 75; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2165]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 75; p.county = 0; p.val = 2125; p.data["black"] = 765; p.data["white"] = 895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2166]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 63; p.county = 0; p.val = 595; p.data["black"] = 465; p.data["white"] = 80; p.data["r"] = 804; p.data["d"] = 122; p.data["d16"] = 0; p.data["r16"] = 0;
points[2167]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 71; p.county = 0; p.val = 1375; p.data["black"] = 505; p.data["white"] = 855; p.data["r"] = 97; p.data["d"] = 308; p.data["d16"] = 308; p.data["r16"] = 951;
points[2168]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 72; p.county = 0; p.val = 520; p.data["black"] = 0; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2169]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 64; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2170]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 90; p.county = 0; p.val = 730; p.data["black"] = 350; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2171]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 87; p.county = 0; p.val = 1620; p.data["black"] = 80; p.data["white"] = 1480; p.data["r"] = 169; p.data["d"] = 615; p.data["d16"] = 150; p.data["r16"] = 895;
points[2172]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 70; p.county = 0; p.val = 1755; p.data["black"] = 160; p.data["white"] = 1425; p.data["r"] = 1699; p.data["d"] = 1560; p.data["d16"] = 600; p.data["r16"] = 683;
points[2173]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 74; p.county = 0; p.val = 2025; p.data["black"] = 0; p.data["white"] = 2005; p.data["r"] = 296; p.data["d"] = 1171; p.data["d16"] = 214; p.data["r16"] = 1327;
points[2174]=p;}
if (1==1){ Point p;
p.x = 155; p.y = 75; p.county = 0; p.val = 830; p.data["black"] = 205; p.data["white"] = 625; p.data["r"] = 185; p.data["d"] = 414; p.data["d16"] = 250; p.data["r16"] = 606;
points[2175]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 78; p.county = 0; p.val = 750; p.data["black"] = 190; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2176]=p;}
if (1==1){ Point p;
p.x = 162; p.y = 88; p.county = 0; p.val = 1400; p.data["black"] = 460; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2177]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 87; p.county = 0; p.val = 450; p.data["black"] = 0; p.data["white"] = 435; p.data["r"] = 550; p.data["d"] = 232; p.data["d16"] = 764; p.data["r16"] = 337;
points[2178]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 85; p.county = 0; p.val = 610; p.data["black"] = 85; p.data["white"] = 510; p.data["r"] = 128; p.data["d"] = 462; p.data["d16"] = 105; p.data["r16"] = 165;
points[2179]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 84; p.county = 0; p.val = 1070; p.data["black"] = 555; p.data["white"] = 515; p.data["r"] = 445; p.data["d"] = 248; p.data["d16"] = 683; p.data["r16"] = 414;
points[2180]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 77; p.county = 0; p.val = 1195; p.data["black"] = 150; p.data["white"] = 1025; p.data["r"] = 119; p.data["d"] = 317; p.data["d16"] = 182; p.data["r16"] = 442;
points[2181]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 78; p.county = 0; p.val = 490; p.data["black"] = 55; p.data["white"] = 425; p.data["r"] = 38; p.data["d"] = 258; p.data["d16"] = 38; p.data["r16"] = 356;
points[2182]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 74; p.county = 0; p.val = 1255; p.data["black"] = 280; p.data["white"] = 965; p.data["r"] = 104; p.data["d"] = 502; p.data["d16"] = 147; p.data["r16"] = 673;
points[2183]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 71; p.county = 0; p.val = 540; p.data["black"] = 60; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2184]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 129; p.county = 0; p.val = 535; p.data["black"] = 335; p.data["white"] = 170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2185]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 147; p.county = 0; p.val = 825; p.data["black"] = 0; p.data["white"] = 795; p.data["r"] = 532; p.data["d"] = 526; p.data["d16"] = 483; p.data["r16"] = 560;
points[2186]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 124; p.county = 0; p.val = 1670; p.data["black"] = 70; p.data["white"] = 1575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2187]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 12; p.county = 0; p.val = 1120; p.data["black"] = 535; p.data["white"] = 470; p.data["r"] = 270; p.data["d"] = 247; p.data["d16"] = 348; p.data["r16"] = 352;
points[2188]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 12; p.county = 0; p.val = 2450; p.data["black"] = 680; p.data["white"] = 1560; p.data["r"] = 274; p.data["d"] = 229; p.data["d16"] = 453; p.data["r16"] = 345;
points[2189]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 15; p.county = 0; p.val = 1335; p.data["black"] = 685; p.data["white"] = 570; p.data["r"] = 420; p.data["d"] = 723; p.data["d16"] = 885; p.data["r16"] = 1647;
points[2190]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 8; p.county = 0; p.val = 1110; p.data["black"] = 0; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2191]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 2; p.county = 0; p.val = 1875; p.data["black"] = 315; p.data["white"] = 1515; p.data["r"] = 345; p.data["d"] = 1349; p.data["d16"] = 322; p.data["r16"] = 1565;
points[2192]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 7; p.county = 0; p.val = 1525; p.data["black"] = 40; p.data["white"] = 1485; p.data["r"] = 251; p.data["d"] = 859; p.data["d16"] = 224; p.data["r16"] = 1105;
points[2193]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 7; p.county = 0; p.val = 1715; p.data["black"] = 70; p.data["white"] = 1585; p.data["r"] = 403; p.data["d"] = 1860; p.data["d16"] = 391; p.data["r16"] = 2462;
points[2194]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 24; p.county = 0; p.val = 890; p.data["black"] = 75; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 182; p.data["r16"] = 1004;
points[2195]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 31; p.county = 0; p.val = 1385; p.data["black"] = 55; p.data["white"] = 1315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2196]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 12; p.county = 0; p.val = 1355; p.data["black"] = 305; p.data["white"] = 970; p.data["r"] = 862; p.data["d"] = 680; p.data["d16"] = 626; p.data["r16"] = 753;
points[2197]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 14; p.county = 0; p.val = 2795; p.data["black"] = 765; p.data["white"] = 1795; p.data["r"] = 267; p.data["d"] = 353; p.data["d16"] = 1125; p.data["r16"] = 874;
points[2198]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 9; p.county = 0; p.val = 460; p.data["black"] = 45; p.data["white"] = 405; p.data["r"] = 493; p.data["d"] = 441; p.data["d16"] = 463; p.data["r16"] = 1069;
points[2199]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 8; p.county = 0; p.val = 1825; p.data["black"] = 190; p.data["white"] = 1580; p.data["r"] = 157; p.data["d"] = 680; p.data["d16"] = 186; p.data["r16"] = 863;
points[2200]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 35; p.county = 0; p.val = 395; p.data["black"] = 0; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 297; p.data["r16"] = 1086;
points[2201]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 98; p.county = 0; p.val = 1670; p.data["black"] = 0; p.data["white"] = 1655; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2202]=p;}
if (1==1){ Point p;
p.x = 186; p.y = 97; p.county = 0; p.val = 880; p.data["black"] = 80; p.data["white"] = 745; p.data["r"] = 278; p.data["d"] = 390; p.data["d16"] = 335; p.data["r16"] = 645;
points[2203]=p;}
if (1==1){ Point p;
p.x = 189; p.y = 92; p.county = 0; p.val = 1455; p.data["black"] = 20; p.data["white"] = 1400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 613; p.data["r16"] = 1058;
points[2204]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 66; p.county = 0; p.val = 4105; p.data["black"] = 2435; p.data["white"] = 1225; p.data["r"] = 1035; p.data["d"] = 243; p.data["d16"] = 3116; p.data["r16"] = 1309;
points[2205]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 63; p.county = 0; p.val = 1770; p.data["black"] = 415; p.data["white"] = 1335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2206]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 64; p.county = 0; p.val = 2405; p.data["black"] = 300; p.data["white"] = 2050; p.data["r"] = 681; p.data["d"] = 1399; p.data["d16"] = 0; p.data["r16"] = 0;
points[2207]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 65; p.county = 0; p.val = 1255; p.data["black"] = 705; p.data["white"] = 510; p.data["r"] = 622; p.data["d"] = 792; p.data["d16"] = 1295; p.data["r16"] = 2687;
points[2208]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 64; p.county = 0; p.val = 2250; p.data["black"] = 1110; p.data["white"] = 1045; p.data["r"] = 169; p.data["d"] = 271; p.data["d16"] = 832; p.data["r16"] = 1411;
points[2209]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 72; p.county = 0; p.val = 1225; p.data["black"] = 560; p.data["white"] = 640; p.data["r"] = 351; p.data["d"] = 421; p.data["d16"] = 380; p.data["r16"] = 153;
points[2210]=p;}
if (1==1){ Point p;
p.x = 199; p.y = 86; p.county = 0; p.val = 830; p.data["black"] = 0; p.data["white"] = 830; p.data["r"] = 256; p.data["d"] = 709; p.data["d16"] = 280; p.data["r16"] = 777;
points[2211]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 75; p.county = 0; p.val = 1375; p.data["black"] = 0; p.data["white"] = 1335; p.data["r"] = 537; p.data["d"] = 1107; p.data["d16"] = 282; p.data["r16"] = 1082;
points[2212]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 74; p.county = 0; p.val = 1715; p.data["black"] = 0; p.data["white"] = 1630; p.data["r"] = 730; p.data["d"] = 2165; p.data["d16"] = 296; p.data["r16"] = 1315;
points[2213]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 70; p.county = 0; p.val = 890; p.data["black"] = 65; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 508; p.data["r16"] = 488;
points[2214]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 69; p.county = 0; p.val = 2465; p.data["black"] = 10; p.data["white"] = 2375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2215]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 68; p.county = 0; p.val = 1410; p.data["black"] = 60; p.data["white"] = 1335; p.data["r"] = 497; p.data["d"] = 1280; p.data["d16"] = 324; p.data["r16"] = 1008;
points[2216]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 115; p.county = 0; p.val = 1420; p.data["black"] = 895; p.data["white"] = 520; p.data["r"] = 815; p.data["d"] = 202; p.data["d16"] = 971; p.data["r16"] = 246;
points[2217]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 127; p.county = 0; p.val = 1255; p.data["black"] = 435; p.data["white"] = 745; p.data["r"] = 310; p.data["d"] = 449; p.data["d16"] = 363; p.data["r16"] = 557;
points[2218]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 137; p.county = 0; p.val = 4110; p.data["black"] = 785; p.data["white"] = 2885; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2219]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 3; p.county = 0; p.val = 620; p.data["black"] = 15; p.data["white"] = 575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2220]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 29; p.county = 0; p.val = 1030; p.data["black"] = 250; p.data["white"] = 750; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2221]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 14; p.county = 0; p.val = 3170; p.data["black"] = 460; p.data["white"] = 2450; p.data["r"] = 705; p.data["d"] = 538; p.data["d16"] = 772; p.data["r16"] = 618;
points[2222]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 15; p.county = 0; p.val = 1585; p.data["black"] = 130; p.data["white"] = 1360; p.data["r"] = 843; p.data["d"] = 1551; p.data["d16"] = 1396; p.data["r16"] = 2097;
points[2223]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 18; p.county = 0; p.val = 2100; p.data["black"] = 105; p.data["white"] = 1935; p.data["r"] = 450; p.data["d"] = 972; p.data["d16"] = 474; p.data["r16"] = 1148;
points[2224]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 95; p.county = 0; p.val = 1890; p.data["black"] = 145; p.data["white"] = 1495; p.data["r"] = 1232; p.data["d"] = 2200; p.data["d16"] = 461; p.data["r16"] = 1127;
points[2225]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 97; p.county = 0; p.val = 3525; p.data["black"] = 145; p.data["white"] = 3120; p.data["r"] = 914; p.data["d"] = 1399; p.data["d16"] = 857; p.data["r16"] = 1810;
points[2226]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 76; p.county = 0; p.val = 1375; p.data["black"] = 290; p.data["white"] = 1000; p.data["r"] = 400; p.data["d"] = 376; p.data["d16"] = 397; p.data["r16"] = 507;
points[2227]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 80; p.county = 0; p.val = 1735; p.data["black"] = 140; p.data["white"] = 1430; p.data["r"] = 216; p.data["d"] = 795; p.data["d16"] = 312; p.data["r16"] = 1305;
points[2228]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 82; p.county = 0; p.val = 1250; p.data["black"] = 1245; p.data["white"] = 0; p.data["r"] = 254; p.data["d"] = 4; p.data["d16"] = 373; p.data["r16"] = 1;
points[2229]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 61; p.county = 0; p.val = 370; p.data["black"] = 265; p.data["white"] = 100; p.data["r"] = 294; p.data["d"] = 85; p.data["d16"] = 0; p.data["r16"] = 0;
points[2230]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 61; p.county = 0; p.val = 410; p.data["black"] = 340; p.data["white"] = 60; p.data["r"] = 434; p.data["d"] = 130; p.data["d16"] = 464; p.data["r16"] = 167;
points[2231]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 24; p.county = 0; p.val = 1805; p.data["black"] = 20; p.data["white"] = 1760; p.data["r"] = 349; p.data["d"] = 1227; p.data["d16"] = 360; p.data["r16"] = 1390;
points[2232]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 12; p.county = 0; p.val = 2130; p.data["black"] = 200; p.data["white"] = 1895; p.data["r"] = 218; p.data["d"] = 757; p.data["d16"] = 198; p.data["r16"] = 952;
points[2233]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 26; p.county = 0; p.val = 1310; p.data["black"] = 620; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 690; p.data["r16"] = 748;
points[2234]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 27; p.county = 0; p.val = 1305; p.data["black"] = 445; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2235]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 8; p.county = 0; p.val = 1180; p.data["black"] = 0; p.data["white"] = 1150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2236]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 8; p.county = 0; p.val = 915; p.data["black"] = 10; p.data["white"] = 905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2237]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 28; p.county = 0; p.val = 2855; p.data["black"] = 270; p.data["white"] = 2425; p.data["r"] = 796; p.data["d"] = 1077; p.data["d16"] = 405; p.data["r16"] = 657;
points[2238]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 27; p.county = 0; p.val = 2575; p.data["black"] = 495; p.data["white"] = 1825; p.data["r"] = 577; p.data["d"] = 865; p.data["d16"] = 937; p.data["r16"] = 2194;
points[2239]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 28; p.county = 0; p.val = 2475; p.data["black"] = 440; p.data["white"] = 1990; p.data["r"] = 466; p.data["d"] = 1033; p.data["d16"] = 430; p.data["r16"] = 1126;
points[2240]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 29; p.county = 0; p.val = 1200; p.data["black"] = 20; p.data["white"] = 1185; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 521; p.data["r16"] = 1069;
points[2241]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 31; p.county = 0; p.val = 1975; p.data["black"] = 820; p.data["white"] = 1090; p.data["r"] = 496; p.data["d"] = 786; p.data["d16"] = 0; p.data["r16"] = 0;
points[2242]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 8; p.county = 0; p.val = 1450; p.data["black"] = 0; p.data["white"] = 1390; p.data["r"] = 178; p.data["d"] = 1229; p.data["d16"] = 158; p.data["r16"] = 1520;
points[2243]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 11; p.county = 0; p.val = 2575; p.data["black"] = 45; p.data["white"] = 2410; p.data["r"] = 370; p.data["d"] = 1083; p.data["d16"] = 317; p.data["r16"] = 1394;
points[2244]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 12; p.county = 0; p.val = 1935; p.data["black"] = 85; p.data["white"] = 1745; p.data["r"] = 333; p.data["d"] = 1144; p.data["d16"] = 286; p.data["r16"] = 1282;
points[2245]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 36; p.county = 0; p.val = 965; p.data["black"] = 140; p.data["white"] = 815; p.data["r"] = 284; p.data["d"] = 801; p.data["d16"] = 0; p.data["r16"] = 0;
points[2246]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 14; p.county = 0; p.val = 1040; p.data["black"] = 0; p.data["white"] = 1015; p.data["r"] = 236; p.data["d"] = 585; p.data["d16"] = 225; p.data["r16"] = 668;
points[2247]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 14; p.county = 0; p.val = 1025; p.data["black"] = 120; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2248]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 22; p.county = 0; p.val = 2070; p.data["black"] = 30; p.data["white"] = 1935; p.data["r"] = 602; p.data["d"] = 1088; p.data["d16"] = 540; p.data["r16"] = 1239;
points[2249]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 29; p.county = 0; p.val = 3215; p.data["black"] = 585; p.data["white"] = 2265; p.data["r"] = 631; p.data["d"] = 492; p.data["d16"] = 0; p.data["r16"] = 0;
points[2250]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 36; p.county = 0; p.val = 1735; p.data["black"] = 70; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2251]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 32; p.county = 0; p.val = 1150; p.data["black"] = 610; p.data["white"] = 520; p.data["r"] = 542; p.data["d"] = 531; p.data["d16"] = 587; p.data["r16"] = 654;
points[2252]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 14; p.county = 0; p.val = 1160; p.data["black"] = 90; p.data["white"] = 1035; p.data["r"] = 320; p.data["d"] = 362; p.data["d16"] = 333; p.data["r16"] = 515;
points[2253]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 40; p.county = 0; p.val = 1625; p.data["black"] = 0; p.data["white"] = 1605; p.data["r"] = 203; p.data["d"] = 965; p.data["d16"] = 212; p.data["r16"] = 1277;
points[2254]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 26; p.county = 0; p.val = 2395; p.data["black"] = 415; p.data["white"] = 1865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 868; p.data["r16"] = 2091;
points[2255]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 17; p.county = 0; p.val = 1025; p.data["black"] = 460; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1125; p.data["r16"] = 102;
points[2256]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 24; p.county = 0; p.val = 1520; p.data["black"] = 365; p.data["white"] = 1135; p.data["r"] = 641; p.data["d"] = 470; p.data["d16"] = 658; p.data["r16"] = 590;
points[2257]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 16; p.county = 0; p.val = 1485; p.data["black"] = 20; p.data["white"] = 1430; p.data["r"] = 502; p.data["d"] = 961; p.data["d16"] = 457; p.data["r16"] = 1255;
points[2258]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 5; p.county = 0; p.val = 1260; p.data["black"] = 0; p.data["white"] = 1250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2259]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 7; p.county = 0; p.val = 3410; p.data["black"] = 215; p.data["white"] = 2960; p.data["r"] = 257; p.data["d"] = 801; p.data["d16"] = 265; p.data["r16"] = 987;
points[2260]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 8; p.county = 0; p.val = 945; p.data["black"] = 25; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2261]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 15; p.county = 0; p.val = 1770; p.data["black"] = 295; p.data["white"] = 1320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 581; p.data["r16"] = 1151;
points[2262]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 33; p.county = 0; p.val = 2260; p.data["black"] = 305; p.data["white"] = 1865; p.data["r"] = 137; p.data["d"] = 495; p.data["d16"] = 128; p.data["r16"] = 641;
points[2263]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 30; p.county = 0; p.val = 3365; p.data["black"] = 405; p.data["white"] = 2795; p.data["r"] = 1194; p.data["d"] = 1831; p.data["d16"] = 805; p.data["r16"] = 1538;
points[2264]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 0; p.val = 1005; p.data["black"] = 95; p.data["white"] = 900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2265]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 6; p.county = 0; p.val = 770; p.data["black"] = 0; p.data["white"] = 760; p.data["r"] = 284; p.data["d"] = 743; p.data["d16"] = 0; p.data["r16"] = 0;
points[2266]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 108; p.county = 0; p.val = 1220; p.data["black"] = 195; p.data["white"] = 995; p.data["r"] = 483; p.data["d"] = 611; p.data["d16"] = 518; p.data["r16"] = 680;
points[2267]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 70; p.county = 0; p.val = 960; p.data["black"] = 585; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2268]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 102; p.county = 0; p.val = 335; p.data["black"] = 100; p.data["white"] = 225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2269]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 72; p.county = 0; p.val = 1630; p.data["black"] = 1395; p.data["white"] = 134; p.data["r"] = 916; p.data["d"] = 78; p.data["d16"] = 0; p.data["r16"] = 0;
points[2270]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 120; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2271]=p;}
if (1==1){ Point p;
p.x = 177; p.y = 110; p.county = 0; p.val = 1795; p.data["black"] = 135; p.data["white"] = 1565; p.data["r"] = 649; p.data["d"] = 1144; p.data["d16"] = 0; p.data["r16"] = 0;
points[2272]=p;}
if (1==1){ Point p;
p.x = 163; p.y = 107; p.county = 0; p.val = 1025; p.data["black"] = 195; p.data["white"] = 785; p.data["r"] = 179; p.data["d"] = 216; p.data["d16"] = 229; p.data["r16"] = 326;
points[2273]=p;}
if (1==1){ Point p;
p.x = 174; p.y = 119; p.county = 0; p.val = 690; p.data["black"] = 15; p.data["white"] = 595; p.data["r"] = 446; p.data["d"] = 1011; p.data["d16"] = 355; p.data["r16"] = 1051;
points[2274]=p;}
if (1==1){ Point p;
p.x = 169; p.y = 126; p.county = 0; p.val = 545; p.data["black"] = 335; p.data["white"] = 215; p.data["r"] = 538; p.data["d"] = 96; p.data["d16"] = 661; p.data["r16"] = 136;
points[2275]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 116; p.county = 0; p.val = 940; p.data["black"] = 245; p.data["white"] = 680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2276]=p;}
if (1==1){ Point p;
p.x = 160; p.y = 110; p.county = 0; p.val = 660; p.data["black"] = 350; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2277]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 193; p.county = 0; p.val = 695; p.data["black"] = 0; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2278]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 64; p.county = 0; p.val = 850; p.data["black"] = 680; p.data["white"] = 170; p.data["r"] = 803; p.data["d"] = 548; p.data["d16"] = 924; p.data["r16"] = 727;
points[2279]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 79; p.county = 0; p.val = 760; p.data["black"] = 250; p.data["white"] = 480; p.data["r"] = 1013; p.data["d"] = 240; p.data["d16"] = 0; p.data["r16"] = 0;
points[2280]=p;}
if (1==1){ Point p;
p.x = 168; p.y = 66; p.county = 0; p.val = 1615; p.data["black"] = 815; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2281]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 146; p.county = 0; p.val = 830; p.data["black"] = 330; p.data["white"] = 500; p.data["r"] = 126; p.data["d"] = 159; p.data["d16"] = 149; p.data["r16"] = 207;
points[2282]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 93; p.county = 0; p.val = 1250; p.data["black"] = 745; p.data["white"] = 480; p.data["r"] = 289; p.data["d"] = 215; p.data["d16"] = 388; p.data["r16"] = 290;
points[2283]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 103; p.county = 0; p.val = 1095; p.data["black"] = 775; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2284]=p;}
if (1==1){ Point p;
p.x = 129; p.y = 99; p.county = 0; p.val = 910; p.data["black"] = 340; p.data["white"] = 560; p.data["r"] = 268; p.data["d"] = 409; p.data["d16"] = 284; p.data["r16"] = 497;
points[2285]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 98; p.county = 0; p.val = 975; p.data["black"] = 500; p.data["white"] = 475; p.data["r"] = 529; p.data["d"] = 343; p.data["d16"] = 630; p.data["r16"] = 383;
points[2286]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 105; p.county = 0; p.val = 945; p.data["black"] = 225; p.data["white"] = 685; p.data["r"] = 105; p.data["d"] = 127; p.data["d16"] = 131; p.data["r16"] = 231;
points[2287]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 100; p.county = 0; p.val = 1635; p.data["black"] = 1010; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2288]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 84; p.county = 0; p.val = 995; p.data["black"] = 235; p.data["white"] = 735; p.data["r"] = 69; p.data["d"] = 271; p.data["d16"] = 96; p.data["r16"] = 444;
points[2289]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 99; p.county = 0; p.val = 865; p.data["black"] = 460; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2290]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 143; p.county = 0; p.val = 620; p.data["black"] = 535; p.data["white"] = 85; p.data["r"] = 337; p.data["d"] = 116; p.data["d16"] = 378; p.data["r16"] = 166;
points[2291]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 43; p.county = 0; p.val = 585; p.data["black"] = 290; p.data["white"] = 280; p.data["r"] = 186; p.data["d"] = 34; p.data["d16"] = 264; p.data["r16"] = 209;
points[2292]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 42; p.county = 0; p.val = 695; p.data["black"] = 185; p.data["white"] = 475; p.data["r"] = 186; p.data["d"] = 429; p.data["d16"] = 0; p.data["r16"] = 0;
points[2293]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 43; p.county = 0; p.val = 560; p.data["black"] = 110; p.data["white"] = 455; p.data["r"] = 175; p.data["d"] = 134; p.data["d16"] = 0; p.data["r16"] = 0;
points[2294]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 50; p.county = 0; p.val = 1020; p.data["black"] = 105; p.data["white"] = 900; p.data["r"] = 250; p.data["d"] = 582; p.data["d16"] = 281; p.data["r16"] = 720;
points[2295]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 44; p.county = 0; p.val = 970; p.data["black"] = 405; p.data["white"] = 570; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2296]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 46; p.county = 0; p.val = 1100; p.data["black"] = 360; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2297]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 45; p.county = 0; p.val = 370; p.data["black"] = 55; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2298]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 45; p.county = 0; p.val = 1650; p.data["black"] = 1075; p.data["white"] = 570; p.data["r"] = 412; p.data["d"] = 167; p.data["d16"] = 583; p.data["r16"] = 277;
points[2299]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 46; p.county = 0; p.val = 540; p.data["black"] = 380; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 375; p.data["r16"] = 420;
points[2300]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 77; p.county = 0; p.val = 1580; p.data["black"] = 480; p.data["white"] = 1065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2301]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 46; p.county = 0; p.val = 455; p.data["black"] = 20; p.data["white"] = 425; p.data["r"] = 330; p.data["d"] = 395; p.data["d16"] = 0; p.data["r16"] = 0;
points[2302]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 49; p.county = 0; p.val = 480; p.data["black"] = 70; p.data["white"] = 410; p.data["r"] = 243; p.data["d"] = 610; p.data["d16"] = 284; p.data["r16"] = 909;
points[2303]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 81; p.county = 0; p.val = 695; p.data["black"] = 50; p.data["white"] = 640; p.data["r"] = 349; p.data["d"] = 741; p.data["d16"] = 0; p.data["r16"] = 0;
points[2304]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 14; p.county = 0; p.val = 3790; p.data["black"] = 465; p.data["white"] = 3225; p.data["r"] = 779; p.data["d"] = 1090; p.data["d16"] = 578; p.data["r16"] = 644;
points[2305]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 15; p.county = 0; p.val = 1345; p.data["black"] = 190; p.data["white"] = 1050; p.data["r"] = 359; p.data["d"] = 247; p.data["d16"] = 0; p.data["r16"] = 0;
points[2306]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 14; p.county = 0; p.val = 1775; p.data["black"] = 730; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2307]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 14; p.county = 0; p.val = 2190; p.data["black"] = 650; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 714; p.data["r16"] = 1163;
points[2308]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 15; p.county = 0; p.val = 3020; p.data["black"] = 1355; p.data["white"] = 1565; p.data["r"] = 695; p.data["d"] = 121; p.data["d16"] = 1342; p.data["r16"] = 558;
points[2309]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 11; p.county = 0; p.val = 880; p.data["black"] = 35; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2310]=p;}
if (1==1){ Point p;
p.x = 146; p.y = 150; p.county = 0; p.val = 1750; p.data["black"] = 20; p.data["white"] = 1615; p.data["r"] = 343; p.data["d"] = 439; p.data["d16"] = 295; p.data["r16"] = 500;
points[2311]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 21; p.county = 0; p.val = 2150; p.data["black"] = 215; p.data["white"] = 1795; p.data["r"] = 411; p.data["d"] = 1054; p.data["d16"] = 0; p.data["r16"] = 0;
points[2312]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 19; p.county = 0; p.val = 945; p.data["black"] = 815; p.data["white"] = 120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 125; p.data["r16"] = 477;
points[2313]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 22; p.county = 0; p.val = 710; p.data["black"] = 40; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 420; p.data["r16"] = 1196;
points[2314]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 11; p.county = 0; p.val = 770; p.data["black"] = 190; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2315]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 31; p.county = 0; p.val = 1625; p.data["black"] = 390; p.data["white"] = 1185; p.data["r"] = 280; p.data["d"] = 443; p.data["d16"] = 265; p.data["r16"] = 625;
points[2316]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 30; p.county = 0; p.val = 1690; p.data["black"] = 565; p.data["white"] = 1050; p.data["r"] = 710; p.data["d"] = 569; p.data["d16"] = 771; p.data["r16"] = 755;
points[2317]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 24; p.county = 0; p.val = 510; p.data["black"] = 170; p.data["white"] = 145; p.data["r"] = 504; p.data["d"] = 132; p.data["d16"] = 608; p.data["r16"] = 190;
points[2318]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 15; p.county = 0; p.val = 2840; p.data["black"] = 565; p.data["white"] = 2175; p.data["r"] = 478; p.data["d"] = 503; p.data["d16"] = 562; p.data["r16"] = 732;
points[2319]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 15; p.county = 0; p.val = 1380; p.data["black"] = 45; p.data["white"] = 1275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2320]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 17; p.county = 0; p.val = 1715; p.data["black"] = 80; p.data["white"] = 1540; p.data["r"] = 363; p.data["d"] = 458; p.data["d16"] = 462; p.data["r16"] = 707;
points[2321]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 16; p.county = 0; p.val = 1645; p.data["black"] = 335; p.data["white"] = 1210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2322]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 17; p.county = 0; p.val = 3065; p.data["black"] = 560; p.data["white"] = 2200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2323]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 16; p.county = 0; p.val = 2235; p.data["black"] = 150; p.data["white"] = 1905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2324]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 16; p.county = 0; p.val = 1135; p.data["black"] = 10; p.data["white"] = 1035; p.data["r"] = 653; p.data["d"] = 982; p.data["d16"] = 0; p.data["r16"] = 0;
points[2325]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 14; p.county = 0; p.val = 1730; p.data["black"] = 140; p.data["white"] = 1485; p.data["r"] = 852; p.data["d"] = 1435; p.data["d16"] = 0; p.data["r16"] = 0;
points[2326]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 16; p.county = 0; p.val = 1020; p.data["black"] = 125; p.data["white"] = 865; p.data["r"] = 1135; p.data["d"] = 1474; p.data["d16"] = 1193; p.data["r16"] = 1915;
points[2327]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 42; p.county = 0; p.val = 865; p.data["black"] = 355; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 223; p.data["r16"] = 565;
points[2328]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 41; p.county = 0; p.val = 745; p.data["black"] = 95; p.data["white"] = 650; p.data["r"] = 130; p.data["d"] = 512; p.data["d16"] = 163; p.data["r16"] = 665;
points[2329]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 48; p.county = 0; p.val = 585; p.data["black"] = 30; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2330]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 43; p.county = 0; p.val = 820; p.data["black"] = 85; p.data["white"] = 710; p.data["r"] = 294; p.data["d"] = 357; p.data["d16"] = 372; p.data["r16"] = 450;
points[2331]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 41; p.county = 0; p.val = 1015; p.data["black"] = 295; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2332]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 144; p.county = 0; p.val = 1660; p.data["black"] = 670; p.data["white"] = 890; p.data["r"] = 506; p.data["d"] = 120; p.data["d16"] = 580; p.data["r16"] = 116;
points[2333]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 140; p.county = 0; p.val = 1795; p.data["black"] = 145; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2334]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 136; p.county = 0; p.val = 1085; p.data["black"] = 55; p.data["white"] = 960; p.data["r"] = 147; p.data["d"] = 566; p.data["d16"] = 560; p.data["r16"] = 1283;
points[2335]=p;}
if (1==1){ Point p;
p.x = 147; p.y = 139; p.county = 0; p.val = 2845; p.data["black"] = 1675; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2336]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 143; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 243; p.data["r16"] = 309;
points[2337]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 7; p.county = 0; p.val = 1505; p.data["black"] = 50; p.data["white"] = 1380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 333; p.data["r16"] = 901;
points[2338]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 7; p.county = 0; p.val = 3120; p.data["black"] = 230; p.data["white"] = 2645; p.data["r"] = 394; p.data["d"] = 807; p.data["d16"] = 0; p.data["r16"] = 0;
points[2339]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 9; p.county = 0; p.val = 425; p.data["black"] = 0; p.data["white"] = 415; p.data["r"] = 509; p.data["d"] = 1082; p.data["d16"] = 537; p.data["r16"] = 914;
points[2340]=p;}
if (1==1){ Point p;
p.x = 183; p.y = 99; p.county = 0; p.val = 920; p.data["black"] = 0; p.data["white"] = 920; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 432; p.data["r16"] = 1192;
points[2341]=p;}
if (1==1){ Point p;
p.x = 187; p.y = 90; p.county = 0; p.val = 3940; p.data["black"] = 125; p.data["white"] = 3610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 770; p.data["r16"] = 1961;
points[2342]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 90; p.county = 0; p.val = 2135; p.data["black"] = 305; p.data["white"] = 1575; p.data["r"] = 293; p.data["d"] = 353; p.data["d16"] = 777; p.data["r16"] = 1531;
points[2343]=p;}
if (1==1){ Point p;
p.x = 182; p.y = 91; p.county = 0; p.val = 1775; p.data["black"] = 150; p.data["white"] = 1460; p.data["r"] = 683; p.data["d"] = 1196; p.data["d16"] = 0; p.data["r16"] = 0;
points[2344]=p;}
if (1==1){ Point p;
p.x = 193; p.y = 79; p.county = 0; p.val = 1745; p.data["black"] = 585; p.data["white"] = 1085; p.data["r"] = 356; p.data["d"] = 843; p.data["d16"] = 0; p.data["r16"] = 0;
points[2345]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 82; p.county = 0; p.val = 530; p.data["black"] = 525; p.data["white"] = 10; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 365; p.data["r16"] = 54;
points[2346]=p;}
if (1==1){ Point p;
p.x = 122; p.y = 82; p.county = 0; p.val = 2355; p.data["black"] = 775; p.data["white"] = 1340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 512; p.data["r16"] = 876;
points[2347]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 80; p.county = 0; p.val = 520; p.data["black"] = 255; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1369; p.data["r16"] = 156;
points[2348]=p;}
if (1==1){ Point p;
p.x = 123; p.y = 79; p.county = 0; p.val = 580; p.data["black"] = 65; p.data["white"] = 495; p.data["r"] = 150; p.data["d"] = 429; p.data["d16"] = 473; p.data["r16"] = 450;
points[2349]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 77; p.county = 0; p.val = 4930; p.data["black"] = 630; p.data["white"] = 3945; p.data["r"] = 307; p.data["d"] = 525; p.data["d16"] = 215; p.data["r16"] = 652;
points[2350]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 101; p.county = 0; p.val = 650; p.data["black"] = 585; p.data["white"] = 45; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2351]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 90; p.county = 0; p.val = 470; p.data["black"] = 295; p.data["white"] = 170; p.data["r"] = 168; p.data["d"] = 100; p.data["d16"] = 203; p.data["r16"] = 123;
points[2352]=p;}
if (1==1){ Point p;
p.x = 161; p.y = 94; p.county = 0; p.val = 445; p.data["black"] = 370; p.data["white"] = 75; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2353]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 99; p.county = 0; p.val = 700; p.data["black"] = 450; p.data["white"] = 250; p.data["r"] = 91; p.data["d"] = 96; p.data["d16"] = 109; p.data["r16"] = 105;
points[2354]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 150; p.county = 0; p.val = 1200; p.data["black"] = 40; p.data["white"] = 1100; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2355]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 76; p.county = 0; p.val = 1250; p.data["black"] = 335; p.data["white"] = 565; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2356]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 53; p.county = 0; p.val = 750; p.data["black"] = 705; p.data["white"] = 25; p.data["r"] = 281; p.data["d"] = 136; p.data["d16"] = 436; p.data["r16"] = 157;
points[2357]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 103; p.county = 0; p.val = 1790; p.data["black"] = 395; p.data["white"] = 1370; p.data["r"] = 343; p.data["d"] = 1161; p.data["d16"] = 0; p.data["r16"] = 0;
points[2358]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 14; p.county = 0; p.val = 2400; p.data["black"] = 420; p.data["white"] = 1955; p.data["r"] = 983; p.data["d"] = 841; p.data["d16"] = 269; p.data["r16"] = 443;
points[2359]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 17; p.county = 0; p.val = 2005; p.data["black"] = 20; p.data["white"] = 1625; p.data["r"] = 342; p.data["d"] = 1193; p.data["d16"] = 0; p.data["r16"] = 0;
points[2360]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 21; p.county = 0; p.val = 1710; p.data["black"] = 340; p.data["white"] = 1340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2361]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 12; p.county = 0; p.val = 695; p.data["black"] = 420; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2362]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 4; p.county = 0; p.val = 1860; p.data["black"] = 60; p.data["white"] = 1735; p.data["r"] = 171; p.data["d"] = 921; p.data["d16"] = 200; p.data["r16"] = 1189;
points[2363]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 188; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2364]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 189; p.county = 0; p.val = 1420; p.data["black"] = 140; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 194; p.data["r16"] = 358;
points[2365]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 189; p.county = 0; p.val = 1160; p.data["black"] = 260; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2366]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 175; p.county = 0; p.val = 530; p.data["black"] = 365; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2367]=p;}
if (1==1){ Point p;
p.x = 107; p.y = 195; p.county = 0; p.val = 170; p.data["black"] = 0; p.data["white"] = 170; p.data["r"] = 858; p.data["d"] = 1361; p.data["d16"] = 474; p.data["r16"] = 1061;
points[2368]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 8; p.county = 0; p.val = 2830; p.data["black"] = 425; p.data["white"] = 2220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2369]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 16; p.county = 0; p.val = 650; p.data["black"] = 320; p.data["white"] = 220; p.data["r"] = 1032; p.data["d"] = 94; p.data["d16"] = 0; p.data["r16"] = 0;
points[2370]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 6; p.county = 0; p.val = 2210; p.data["black"] = 360; p.data["white"] = 1645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2371]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 105; p.county = 0; p.val = 1905; p.data["black"] = 880; p.data["white"] = 925; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2372]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 29; p.county = 0; p.val = 810; p.data["black"] = 450; p.data["white"] = 330; p.data["r"] = 447; p.data["d"] = 676; p.data["d16"] = 514; p.data["r16"] = 931;
points[2373]=p;}
if (1==1){ Point p;
p.x = 184; p.y = 97; p.county = 0; p.val = 2695; p.data["black"] = 110; p.data["white"] = 2265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2374]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 95; p.county = 0; p.val = 1960; p.data["black"] = 875; p.data["white"] = 1070; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 499; p.data["r16"] = 34;
points[2375]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 32; p.county = 0; p.val = 950; p.data["black"] = 60; p.data["white"] = 840; p.data["r"] = 371; p.data["d"] = 296; p.data["d16"] = 0; p.data["r16"] = 0;
points[2376]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 64; p.county = 0; p.val = 1150; p.data["black"] = 890; p.data["white"] = 255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2377]=p;}
if (1==1){ Point p;
p.x = 171; p.y = 96; p.county = 0; p.val = 735; p.data["black"] = 310; p.data["white"] = 370; p.data["r"] = 275; p.data["d"] = 75; p.data["d16"] = 371; p.data["r16"] = 72;
points[2378]=p;}
if (1==1){ Point p;
p.x = 168; p.y = 115; p.county = 0; p.val = 385; p.data["black"] = 140; p.data["white"] = 245; p.data["r"] = 457; p.data["d"] = 359; p.data["d16"] = 562; p.data["r16"] = 511;
points[2379]=p;}
if (1==1){ Point p;
p.x = 162; p.y = 117; p.county = 0; p.val = 755; p.data["black"] = 615; p.data["white"] = 140; p.data["r"] = 456; p.data["d"] = 93; p.data["d16"] = 603; p.data["r16"] = 127;
points[2380]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 109; p.county = 0; p.val = 1885; p.data["black"] = 1095; p.data["white"] = 705; p.data["r"] = 866; p.data["d"] = 172; p.data["d16"] = 1042; p.data["r16"] = 227;
points[2381]=p;}
if (1==1){ Point p;
p.x = 172; p.y = 108; p.county = 0; p.val = 1050; p.data["black"] = 735; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 434; p.data["r16"] = 123;
points[2382]=p;}
if (1==1){ Point p;
p.x = 160; p.y = 120; p.county = 0; p.val = 1355; p.data["black"] = 715; p.data["white"] = 635; p.data["r"] = 66; p.data["d"] = 231; p.data["d16"] = 81; p.data["r16"] = 374;
points[2383]=p;}
if (1==1){ Point p;
p.x = 166; p.y = 99; p.county = 0; p.val = 800; p.data["black"] = 405; p.data["white"] = 395; p.data["r"] = 198; p.data["d"] = 305; p.data["d16"] = 252; p.data["r16"] = 448;
points[2384]=p;}
if (1==1){ Point p;
p.x = 162; p.y = 114; p.county = 0; p.val = 1295; p.data["black"] = 65; p.data["white"] = 1230; p.data["r"] = 64; p.data["d"] = 427; p.data["d16"] = 82; p.data["r16"] = 647;
points[2385]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 94; p.county = 0; p.val = 1150; p.data["black"] = 410; p.data["white"] = 735; p.data["r"] = 135; p.data["d"] = 391; p.data["d16"] = 195; p.data["r16"] = 548;
points[2386]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 109; p.county = 0; p.val = 1175; p.data["black"] = 1020; p.data["white"] = 85; p.data["r"] = 931; p.data["d"] = 78; p.data["d16"] = 1609; p.data["r16"] = 37;
points[2387]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 108; p.county = 0; p.val = 855; p.data["black"] = 535; p.data["white"] = 310; p.data["r"] = 264; p.data["d"] = 146; p.data["d16"] = 369; p.data["r16"] = 228;
points[2388]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 114; p.county = 0; p.val = 855; p.data["black"] = 165; p.data["white"] = 675; p.data["r"] = 598; p.data["d"] = 574; p.data["d16"] = 747; p.data["r16"] = 772;
points[2389]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 113; p.county = 0; p.val = 635; p.data["black"] = 100; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2390]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 99; p.county = 0; p.val = 750; p.data["black"] = 325; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2391]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 140; p.county = 0; p.val = 1575; p.data["black"] = 170; p.data["white"] = 1385; p.data["r"] = 472; p.data["d"] = 873; p.data["d16"] = 494; p.data["r16"] = 1101;
points[2392]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 139; p.county = 0; p.val = 1115; p.data["black"] = 110; p.data["white"] = 985; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2393]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 137; p.county = 0; p.val = 2840; p.data["black"] = 385; p.data["white"] = 2290; p.data["r"] = 737; p.data["d"] = 833; p.data["d16"] = 518; p.data["r16"] = 890;
points[2394]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 137; p.county = 0; p.val = 2760; p.data["black"] = 300; p.data["white"] = 2320; p.data["r"] = 309; p.data["d"] = 336; p.data["d16"] = 285; p.data["r16"] = 538;
points[2395]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 136; p.county = 0; p.val = 2130; p.data["black"] = 395; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2396]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 139; p.county = 0; p.val = 1440; p.data["black"] = 115; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2397]=p;}
if (1==1){ Point p;
p.x = 130; p.y = 141; p.county = 0; p.val = 2020; p.data["black"] = 465; p.data["white"] = 1450; p.data["r"] = 1580; p.data["d"] = 2123; p.data["d16"] = 1976; p.data["r16"] = 3279;
points[2398]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 146; p.county = 0; p.val = 4075; p.data["black"] = 935; p.data["white"] = 2555; p.data["r"] = 1325; p.data["d"] = 1078; p.data["d16"] = 2063; p.data["r16"] = 2058;
points[2399]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 141; p.county = 0; p.val = 3990; p.data["black"] = 655; p.data["white"] = 3125; p.data["r"] = 608; p.data["d"] = 414; p.data["d16"] = 591; p.data["r16"] = 512;
points[2400]=p;}
if (1==1){ Point p;
p.x = 134; p.y = 145; p.county = 0; p.val = 2555; p.data["black"] = 485; p.data["white"] = 1855; p.data["r"] = 1980; p.data["d"] = 2001; p.data["d16"] = 1931; p.data["r16"] = 2506;
points[2401]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 138; p.county = 0; p.val = 1810; p.data["black"] = 310; p.data["white"] = 1355; p.data["r"] = 481; p.data["d"] = 648; p.data["d16"] = 412; p.data["r16"] = 685;
points[2402]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 127; p.county = 0; p.val = 1475; p.data["black"] = 755; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2403]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 57; p.county = 0; p.val = 730; p.data["black"] = 155; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2404]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 140; p.county = 0; p.val = 675; p.data["black"] = 495; p.data["white"] = 180; p.data["r"] = 89; p.data["d"] = 155; p.data["d16"] = 88; p.data["r16"] = 205;
points[2405]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 139; p.county = 0; p.val = 490; p.data["black"] = 440; p.data["white"] = 55; p.data["r"] = 405; p.data["d"] = 87; p.data["d16"] = 1003; p.data["r16"] = 100;
points[2406]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 148; p.county = 0; p.val = 1330; p.data["black"] = 790; p.data["white"] = 500; p.data["r"] = 495; p.data["d"] = 57; p.data["d16"] = 693; p.data["r16"] = 73;
points[2407]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 144; p.county = 0; p.val = 765; p.data["black"] = 60; p.data["white"] = 665; p.data["r"] = 35; p.data["d"] = 167; p.data["d16"] = 42; p.data["r16"] = 235;
points[2408]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 110; p.county = 0; p.val = 585; p.data["black"] = 395; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2409]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 111; p.county = 0; p.val = 435; p.data["black"] = 85; p.data["white"] = 350; p.data["r"] = 493; p.data["d"] = 109; p.data["d16"] = 674; p.data["r16"] = 128;
points[2410]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 120; p.county = 0; p.val = 1105; p.data["black"] = 470; p.data["white"] = 625; p.data["r"] = 655; p.data["d"] = 370; p.data["d16"] = 704; p.data["r16"] = 488;
points[2411]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 109; p.county = 0; p.val = 680; p.data["black"] = 440; p.data["white"] = 235; p.data["r"] = 521; p.data["d"] = 50; p.data["d16"] = 0; p.data["r16"] = 0;
points[2412]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 105; p.county = 0; p.val = 560; p.data["black"] = 290; p.data["white"] = 150; p.data["r"] = 941; p.data["d"] = 264; p.data["d16"] = 418; p.data["r16"] = 225;
points[2413]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 78; p.county = 0; p.val = 1185; p.data["black"] = 95; p.data["white"] = 1035; p.data["r"] = 1126; p.data["d"] = 934; p.data["d16"] = 1363; p.data["r16"] = 755;
points[2414]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 145; p.county = 0; p.val = 1075; p.data["black"] = 285; p.data["white"] = 770; p.data["r"] = 255; p.data["d"] = 508; p.data["d16"] = 201; p.data["r16"] = 462;
points[2415]=p;}
if (1==1){ Point p;
p.x = 118; p.y = 143; p.county = 0; p.val = 1845; p.data["black"] = 395; p.data["white"] = 1420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2416]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 161; p.county = 0; p.val = 440; p.data["black"] = 275; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2417]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 131; p.county = 0; p.val = 815; p.data["black"] = 580; p.data["white"] = 210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2418]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 149; p.county = 0; p.val = 965; p.data["black"] = 465; p.data["white"] = 445; p.data["r"] = 455; p.data["d"] = 479; p.data["d16"] = 541; p.data["r16"] = 597;
points[2419]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 152; p.county = 0; p.val = 950; p.data["black"] = 530; p.data["white"] = 420; p.data["r"] = 264; p.data["d"] = 175; p.data["d16"] = 302; p.data["r16"] = 219;
points[2420]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 172; p.county = 0; p.val = 705; p.data["black"] = 4; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2421]=p;}
if (1==1){ Point p;
p.x = 116; p.y = 163; p.county = 0; p.val = 630; p.data["black"] = 430; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2422]=p;}
if (1==1){ Point p;
p.x = 152; p.y = 37; p.county = 0; p.val = 840; p.data["black"] = 750; p.data["white"] = 75; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 567; p.data["r16"] = 39;
points[2423]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 141; p.county = 0; p.val = 2125; p.data["black"] = 390; p.data["white"] = 1640; p.data["r"] = 616; p.data["d"] = 1065; p.data["d16"] = 322; p.data["r16"] = 748;
points[2424]=p;}
if (1==1){ Point p;
p.x = 133; p.y = 140; p.county = 0; p.val = 1650; p.data["black"] = 420; p.data["white"] = 1140; p.data["r"] = 309; p.data["d"] = 368; p.data["d16"] = 361; p.data["r16"] = 443;
points[2425]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 150; p.county = 0; p.val = 865; p.data["black"] = 335; p.data["white"] = 485; p.data["r"] = 82; p.data["d"] = 179; p.data["d16"] = 121; p.data["r16"] = 314;
points[2426]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 140; p.county = 0; p.val = 1950; p.data["black"] = 730; p.data["white"] = 1170; p.data["r"] = 134; p.data["d"] = 377; p.data["d16"] = 123; p.data["r16"] = 520;
points[2427]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 145; p.county = 0; p.val = 700; p.data["black"] = 195; p.data["white"] = 505; p.data["r"] = 95; p.data["d"] = 169; p.data["d16"] = 184; p.data["r16"] = 293;
points[2428]=p;}
if (1==1){ Point p;
p.x = 114; p.y = 142; p.county = 0; p.val = 2165; p.data["black"] = 515; p.data["white"] = 1485; p.data["r"] = 279; p.data["d"] = 341; p.data["d16"] = 300; p.data["r16"] = 406;
points[2429]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 136; p.county = 0; p.val = 450; p.data["black"] = 150; p.data["white"] = 260; p.data["r"] = 418; p.data["d"] = 184; p.data["d16"] = 485; p.data["r16"] = 278;
points[2430]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 147; p.county = 0; p.val = 1115; p.data["black"] = 335; p.data["white"] = 525; p.data["r"] = 265; p.data["d"] = 529; p.data["d16"] = 289; p.data["r16"] = 677;
points[2431]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 138; p.county = 0; p.val = 595; p.data["black"] = 240; p.data["white"] = 355; p.data["r"] = 67; p.data["d"] = 130; p.data["d16"] = 97; p.data["r16"] = 293;
points[2432]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 143; p.county = 0; p.val = 1100; p.data["black"] = 230; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2433]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 89; p.county = 0; p.val = 925; p.data["black"] = 495; p.data["white"] = 420; p.data["r"] = 306; p.data["d"] = 228; p.data["d16"] = 361; p.data["r16"] = 281;
points[2434]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 157; p.county = 0; p.val = 550; p.data["black"] = 360; p.data["white"] = 150; p.data["r"] = 373; p.data["d"] = 184; p.data["d16"] = 480; p.data["r16"] = 253;
points[2435]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 53; p.county = 0; p.val = 660; p.data["black"] = 445; p.data["white"] = 220; p.data["r"] = 807; p.data["d"] = 412; p.data["d16"] = 0; p.data["r16"] = 0;
points[2436]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 58; p.county = 0; p.val = 930; p.data["black"] = 465; p.data["white"] = 345; p.data["r"] = 345; p.data["d"] = 233; p.data["d16"] = 374; p.data["r16"] = 288;
points[2437]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 146; p.county = 0; p.val = 1115; p.data["black"] = 460; p.data["white"] = 580; p.data["r"] = 196; p.data["d"] = 510; p.data["d16"] = 249; p.data["r16"] = 687;
points[2438]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 154; p.county = 0; p.val = 945; p.data["black"] = 425; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2439]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 137; p.county = 0; p.val = 660; p.data["black"] = 185; p.data["white"] = 470; p.data["r"] = 138; p.data["d"] = 51; p.data["d16"] = 184; p.data["r16"] = 89;
points[2440]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 145; p.county = 0; p.val = 755; p.data["black"] = 515; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2441]=p;}
if (1==1){ Point p;
p.x = 112; p.y = 146; p.county = 0; p.val = 1175; p.data["black"] = 875; p.data["white"] = 305; p.data["r"] = 319; p.data["d"] = 149; p.data["d16"] = 400; p.data["r16"] = 203;
points[2442]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 146; p.county = 0; p.val = 560; p.data["black"] = 205; p.data["white"] = 355; p.data["r"] = 276; p.data["d"] = 338; p.data["d16"] = 274; p.data["r16"] = 432;
points[2443]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 37; p.county = 0; p.val = 655; p.data["black"] = 115; p.data["white"] = 500; p.data["r"] = 134; p.data["d"] = 272; p.data["d16"] = 158; p.data["r16"] = 389;
points[2444]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 26; p.county = 0; p.val = 1035; p.data["black"] = 100; p.data["white"] = 890; p.data["r"] = 158; p.data["d"] = 396; p.data["d16"] = 198; p.data["r16"] = 528;
points[2445]=p;}
if (1==1){ Point p;
p.x = 125; p.y = 92; p.county = 0; p.val = 1505; p.data["black"] = 695; p.data["white"] = 785; p.data["r"] = 483; p.data["d"] = 355; p.data["d16"] = 565; p.data["r16"] = 546;
points[2446]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 87; p.county = 0; p.val = 705; p.data["black"] = 145; p.data["white"] = 520; p.data["r"] = 141; p.data["d"] = 194; p.data["d16"] = 177; p.data["r16"] = 261;
points[2447]=p;}
if (1==1){ Point p;
p.x = 138; p.y = 89; p.county = 0; p.val = 720; p.data["black"] = 470; p.data["white"] = 225; p.data["r"] = 226; p.data["d"] = 148; p.data["d16"] = 51; p.data["r16"] = 105;
points[2448]=p;}
if (1==1){ Point p;
p.x = 128; p.y = 96; p.county = 0; p.val = 1090; p.data["black"] = 940; p.data["white"] = 80; p.data["r"] = 594; p.data["d"] = 107; p.data["d16"] = 598; p.data["r16"] = 101;
points[2449]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 99; p.county = 0; p.val = 1110; p.data["black"] = 850; p.data["white"] = 240; p.data["r"] = 446; p.data["d"] = 91; p.data["d16"] = 620; p.data["r16"] = 121;
points[2450]=p;}
if (1==1){ Point p;
p.x = 143; p.y = 85; p.county = 0; p.val = 635; p.data["black"] = 160; p.data["white"] = 470; p.data["r"] = 46; p.data["d"] = 270; p.data["d16"] = 57; p.data["r16"] = 390;
points[2451]=p;}
if (1==1){ Point p;
p.x = 121; p.y = 103; p.county = 0; p.val = 475; p.data["black"] = 335; p.data["white"] = 140; p.data["r"] = 162; p.data["d"] = 40; p.data["d16"] = 180; p.data["r16"] = 54;
points[2452]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 19; p.county = 0; p.val = 1415; p.data["black"] = 0; p.data["white"] = 1380; p.data["r"] = 464; p.data["d"] = 1002; p.data["d16"] = 1280; p.data["r16"] = 2511;
points[2453]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 99; p.county = 0; p.val = 390; p.data["black"] = 330; p.data["white"] = 60; p.data["r"] = 444; p.data["d"] = 91; p.data["d16"] = 591; p.data["r16"] = 129;
points[2454]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 82; p.county = 0; p.val = 1110; p.data["black"] = 315; p.data["white"] = 780; p.data["r"] = 214; p.data["d"] = 435; p.data["d16"] = 280; p.data["r16"] = 626;
points[2455]=p;}
if (1==1){ Point p;
p.x = 148; p.y = 65; p.county = 0; p.val = 1965; p.data["black"] = 485; p.data["white"] = 1380; p.data["r"] = 766; p.data["d"] = 1437; p.data["d16"] = 726; p.data["r16"] = 1617;
points[2456]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 81; p.county = 0; p.val = 855; p.data["black"] = 545; p.data["white"] = 310; p.data["r"] = 210; p.data["d"] = 265; p.data["d16"] = 291; p.data["r16"] = 394;
points[2457]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 81; p.county = 0; p.val = 510; p.data["black"] = 235; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2458]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 85; p.county = 0; p.val = 970; p.data["black"] = 940; p.data["white"] = 25; p.data["r"] = 725; p.data["d"] = 40; p.data["d16"] = 0; p.data["r16"] = 0;
points[2459]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 124; p.county = 0; p.val = 520; p.data["black"] = 80; p.data["white"] = 445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2460]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 117; p.county = 0; p.val = 1610; p.data["black"] = 825; p.data["white"] = 785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2461]=p;}
if (1==1){ Point p;
p.x = 154; p.y = 127; p.county = 0; p.val = 1450; p.data["black"] = 700; p.data["white"] = 680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2462]=p;}
if (1==1){ Point p;
p.x = 140; p.y = 127; p.county = 0; p.val = 1075; p.data["black"] = 160; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2463]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 114; p.county = 0; p.val = 760; p.data["black"] = 450; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2464]=p;}
if (1==1){ Point p;
p.x = 141; p.y = 127; p.county = 0; p.val = 1825; p.data["black"] = 595; p.data["white"] = 1195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2465]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 110; p.county = 0; p.val = 430; p.data["black"] = 290; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[2466]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 103; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 192; p.data["d"] = 197; p.data["d16"] = 227; p.data["r16"] = 258;
points[2467]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 135; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 7; p.data["d"] = 83; p.data["d16"] = 4; p.data["r16"] = 89;
points[2468]=p;}
if (1==1){ Point p;
p.x = 101; p.y = 135; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 16; p.data["d"] = 87; p.data["d16"] = 8; p.data["r16"] = 93;
points[2469]=p;}
if (1==1){ Point p;
p.x = 120; p.y = 186; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 275; p.data["d"] = 461; p.data["d16"] = 275; p.data["r16"] = 541;
points[2470]=p;}
if (1==1){ Point p;
p.x = 111; p.y = 196; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 624; p.data["d"] = 946; p.data["d16"] = 318; p.data["r16"] = 513;
points[2471]=p;}
if (1==1){ Point p;
p.x = 108; p.y = 199; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 363; p.data["d"] = 383; p.data["d16"] = 691; p.data["r16"] = 1010;
points[2472]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 129; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 12; p.data["d"] = 127; p.data["d16"] = 17; p.data["r16"] = 164;
points[2473]=p;}
if (1==1){ Point p;
p.x = 145; p.y = 124; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 125; p.data["d"] = 735; p.data["d16"] = 114; p.data["r16"] = 1102;
points[2474]=p;}
if (1==1){ Point p;
p.x = 144; p.y = 132; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 245; p.data["d"] = 377; p.data["d16"] = 262; p.data["r16"] = 470;
points[2475]=p;}
if (1==1){ Point p;
p.x = 153; p.y = 124; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 187; p.data["d"] = 119; p.data["d16"] = 247; p.data["r16"] = 156;
points[2476]=p;}
if (1==1){ Point p;
p.x = 150; p.y = 135; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 456; p.data["d"] = 235; p.data["d16"] = 526; p.data["r16"] = 271;
points[2477]=p;}
if (1==1){ Point p;
p.x = 158; p.y = 129; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 113; p.data["d"] = 134; p.data["d16"] = 130; p.data["r16"] = 157;
points[2478]=p;}
if (1==1){ Point p;
p.x = 149; p.y = 157; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 964; p.data["d"] = 1035; p.data["d16"] = 931; p.data["r16"] = 1141;
points[2479]=p;}
if (1==1){ Point p;
p.x = 165; p.y = 137; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 756; p.data["d"] = 316; p.data["d16"] = 847; p.data["r16"] = 357;
points[2480]=p;}
if (1==1){ Point p;
p.x = 137; p.y = 169; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 436; p.data["d"] = 788; p.data["d16"] = 429; p.data["r16"] = 822;
points[2481]=p;}
if (1==1){ Point p;
p.x = 127; p.y = 169; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 523; p.data["d"] = 462; p.data["d16"] = 550; p.data["r16"] = 569;
points[2482]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 171; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 693; p.data["d"] = 934; p.data["d16"] = 713; p.data["r16"] = 986;
points[2483]=p;}
if (1==1){ Point p;
p.x = 142; p.y = 166; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 422; p.data["d"] = 332; p.data["d16"] = 363; p.data["r16"] = 410;
points[2484]=p;}
if (1==1){ Point p;
p.x = 126; p.y = 38; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 126; p.data["d"] = 216; p.data["d16"] = 163; p.data["r16"] = 287;
points[2485]=p;}
if (1==1){ Point p;
p.x = 132; p.y = 36; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 35; p.data["d"] = 141; p.data["d16"] = 39; p.data["r16"] = 207;
points[2486]=p;}
if (1==1){ Point p;
p.x = 139; p.y = 93; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 119; p.data["d"] = 86; p.data["d16"] = 163; p.data["r16"] = 129;
points[2487]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 144; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 101; p.data["d"] = 130; p.data["d16"] = 85; p.data["r16"] = 146;
points[2488]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 167; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 412; p.data["d"] = 121; p.data["d16"] = 519; p.data["r16"] = 162;
points[2489]=p;}
if (1==1){ Point p;
p.x = 119; p.y = 157; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 193; p.data["d"] = 53; p.data["d16"] = 261; p.data["r16"] = 65;
points[2490]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 154; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 57; p.data["d"] = 62; p.data["d16"] = 68; p.data["r16"] = 103;
points[2491]=p;}
if (1==1){ Point p;
p.x = 113; p.y = 155; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 224; p.data["d"] = 64; p.data["d16"] = 367; p.data["r16"] = 144;
points[2492]=p;}
if (1==1){ Point p;
p.x = 117; p.y = 140; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 71; p.data["d"] = 213; p.data["d16"] = 93; p.data["r16"] = 305;
points[2493]=p;}
if (1==1){ Point p;
p.x = 103; p.y = 139; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 91; p.data["d"] = 105; p.data["d16"] = 118; p.data["r16"] = 121;
points[2494]=p;}
if (1==1){ Point p;
p.x = 124; p.y = 143; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 167; p.data["d"] = 351; p.data["d16"] = 227; p.data["r16"] = 415;
points[2495]=p;}
if (1==1){ Point p;
p.x = 131; p.y = 149; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 59; p.data["d"] = 155; p.data["d16"] = 69; p.data["r16"] = 189;
points[2496]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 40; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 34; p.data["d"] = 6; p.data["d16"] = 43; p.data["r16"] = 11;
points[2497]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 48; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 243; p.data["d"] = 43; p.data["d16"] = 349; p.data["r16"] = 50;
points[2498]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 42; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 19; p.data["d"] = 28; p.data["d16"] = 17; p.data["r16"] = 39;
points[2499]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 43; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 20; p.data["d"] = 32; p.data["d16"] = 17; p.data["r16"] = 36;
points[2500]=p;}
if (1==1){ Point p;
p.x = 167; p.y = 104; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 405; p.data["d"] = 121; p.data["d16"] = 509; p.data["r16"] = 171;
points[2501]=p;}
if (1==1){ Point p;
p.x = 170; p.y = 123; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 156; p.data["d"] = 334; p.data["d16"] = 145; p.data["r16"] = 405;
points[2502]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 3; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 360; p.data["d"] = 1134; p.data["d16"] = 284; p.data["r16"] = 1335;
points[2503]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 69; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 317; p.data["d"] = 275; p.data["d16"] = 400; p.data["r16"] = 482;
points[2504]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 74; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 133; p.data["d"] = 366; p.data["d16"] = 157; p.data["r16"] = 507;
points[2505]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 75; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 31; p.data["d"] = 71; p.data["d16"] = 34; p.data["r16"] = 79;
points[2506]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 167; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 103; p.data["d"] = 13; p.data["d16"] = 120; p.data["r16"] = 15;
points[2507]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 160; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 668; p.data["d"] = 231; p.data["d16"] = 1090; p.data["r16"] = 261;
points[2508]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 162; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 160; p.data["d"] = 75; p.data["d16"] = 214; p.data["r16"] = 93;
points[2509]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 64; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 115; p.data["d"] = 291; p.data["d16"] = 161; p.data["r16"] = 428;
points[2510]=p;}
if (1==1){ Point p;
p.x = 179; p.y = 70; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 22; p.data["d"] = 107; p.data["d16"] = 31; p.data["r16"] = 141;
points[2511]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 198; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 673; p.data["d"] = 299; p.data["d16"] = 826; p.data["r16"] = 430;
points[2512]=p;}
if (1==1){ Point p;
p.x = 106; p.y = 46; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 99; p.data["d"] = 265; p.data["d16"] = 101; p.data["r16"] = 275;
points[2513]=p;}
if (1==1){ Point p;
p.x = 110; p.y = 51; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 227; p.data["d"] = 280; p.data["d16"] = 213; p.data["r16"] = 324;
points[2514]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 97; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 112; p.data["d"] = 318; p.data["d16"] = 116; p.data["r16"] = 454;
points[2515]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 92; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 166; p.data["d"] = 499; p.data["d16"] = 211; p.data["r16"] = 781;
points[2516]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 83; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 255; p.data["d"] = 859; p.data["d16"] = 292; p.data["r16"] = 1029;
points[2517]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 90; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 24; p.data["d"] = 126; p.data["d16"] = 23; p.data["r16"] = 146;
points[2518]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 99; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 196; p.data["d"] = 179; p.data["d16"] = 283; p.data["r16"] = 224;
points[2519]=p;}
if (1==1){ Point p;
p.x = 156; p.y = 44; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 98; p.data["d"] = 94; p.data["d16"] = 107; p.data["r16"] = 134;
points[2520]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 57; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 50; p.data["d"] = 120; p.data["d16"] = 62; p.data["r16"] = 178;
points[2521]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 47; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 38; p.data["d"] = 13; p.data["d16"] = 47; p.data["r16"] = 17;
points[2522]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 61; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 166; p.data["d"] = 249; p.data["d16"] = 173; p.data["r16"] = 342;
points[2523]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 114; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 253; p.data["d"] = 95; p.data["d16"] = 322; p.data["r16"] = 146;
points[2524]=p;}
if (1==1){ Point p;
p.x = 104; p.y = 118; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 210; p.data["d"] = 127; p.data["d16"] = 292; p.data["r16"] = 167;
points[2525]=p;}
if (1==1){ Point p;
p.x = 109; p.y = 71; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 823; p.data["d"] = 515; p.data["d16"] = 839; p.data["r16"] = 637;
points[2526]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 35; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 162; p.data["d"] = 315; p.data["d16"] = 188; p.data["r16"] = 420;
points[2527]=p;}
if (1==1){ Point p;
p.x = 160; p.y = 107; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 10; p.data["d"] = 228; p.data["d16"] = 10; p.data["r16"] = 262;
points[2528]=p;}
if (1==1){ Point p;
p.x = 151; p.y = 116; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 48; p.data["d"] = 97; p.data["d16"] = 67; p.data["r16"] = 119;
points[2529]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 15; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 220; p.data["d"] = 522; p.data["d16"] = 284; p.data["r16"] = 656;
points[2530]=p;}
if (1==1){ Point p;
p.x = 172; p.y = 72; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 23; p.data["r16"] = 114;
points[2531]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 75; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 199; p.data["r16"] = 32;
points[2532]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 136; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 231; p.data["r16"] = 43;
points[2533]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 150; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 282; p.data["r16"] = 20;
points[2534]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 69; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 788; p.data["r16"] = 519;
points[2535]=p;}
if (1==1){ Point p;
p.x = 135; p.y = 88; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 282; p.data["r16"] = 111;
points[2536]=p;}
if (1==1){ Point p;
p.x = 161; p.y = 43; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 80; p.data["r16"] = 55;
points[2537]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 56; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 906; p.data["r16"] = 439;
points[2538]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 3; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 237; p.data["r16"] = 848;
points[2539]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 113; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 626; p.data["r16"] = 296;
points[2540]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 70; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 70; p.data["r16"] = 264;
points[2541]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 78; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 22; p.data["r16"] = 171;
points[2542]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 173; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 175; p.data["r16"] = 314;
points[2543]=p;}
if (1==1){ Point p;
p.x = 102; p.y = 199; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 115; p.data["r16"] = 185;
points[2544]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 36; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 113; p.data["r16"] = 92;
points[2545]=p;}
if (1==1){ Point p;
p.x = 0; p.y = 26; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 90; p.data["r16"] = 224;
points[2546]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 16; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 176; p.data["r16"] = 856;
points[2547]=p;}
if (1==1){ Point p;
p.x = 3; p.y = 29; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 27; p.data["r16"] = 270;
points[2548]=p;}
np = 2549;
}






























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
	std::string s;
	int r;
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
				
				int v = m.pixels[i][removeSeam[i]].val+m.pixels[i][removeSeam[i]-1].val+m.pixels[i][removeSeam[i]+1].val;
				
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
				
				for (ii=0;ii<nd;ii++){
					s = datas[ii];
					r = m.pixels[i][removeSeam[i]].data[s]+m.pixels[i][removeSeam[i]-1].data[s]+m.pixels[i][removeSeam[i]+1].data[s];
					m.pixels[i][removeSeam[i]-1].data[s] = r/4;
					m.pixels[i][removeSeam[i]].data[s] = r - r/4 - r/4 - r/4;
					m.pixels[i][removeSeam[i]+1].data[s] = r/4;
					m.pixels[i][removeSeam[i]+2].data[s] = r/4;
				}
				m.pixels[i][removeSeam[i]-1].x = xx;
				m.pixels[i][removeSeam[i]].x = xx;
				m.pixels[i][removeSeam[i]+1].x = xx;
				m.pixels[i][removeSeam[i]+2].x = xx;
				
				m.pixels[i][removeSeam[i]-1].y = yy;
				m.pixels[i][removeSeam[i]].y = yy;
				m.pixels[i][removeSeam[i]+1].y = yy;
				m.pixels[i][removeSeam[i]+2].y = yy;
				int county = m.pixels[i][removeSeam[i]].county;
				if (county < m.pixels[i][removeSeam[i]+1].county){county = m.pixels[i][removeSeam[i]+1].county;}
				if (county < m.pixels[i][removeSeam[i]-1].county){county = m.pixels[i][removeSeam[i]-1].county;}
				m.pixels[i][removeSeam[i]-1].county = county;
				m.pixels[i][removeSeam[i]].county = county;
				m.pixels[i][removeSeam[i]+1].county = county;
				m.pixels[i][removeSeam[i]+2].county = county;
				
				if (computeVal){m.pixels[i][removeSeam[i]].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]-1].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]+1].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]+2].computeVal();}
			}
			else if (removeSeam[i]+1<m.height){
				for(ii=m.height;ii>removeSeam[i]+2;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val+m.pixels[i][removeSeam[i]+1].val;
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
				
				for (ii=0;ii<nd;ii++){
					s = datas[ii];
					r = m.pixels[i][removeSeam[i]].data[s]+m.pixels[i][removeSeam[i]+1].data[s];
					m.pixels[i][removeSeam[i]].data[s] = r - r/3 - r/3;
					m.pixels[i][removeSeam[i]+1].data[s] = r/3;
					m.pixels[i][removeSeam[i]+2].data[s] = r/3;
				}
				
				m.pixels[i][removeSeam[i]].x = xx;
				m.pixels[i][removeSeam[i]+1].x = xx;
				m.pixels[i][removeSeam[i]+2].x = xx;
				
				m.pixels[i][removeSeam[i]].y = yy;
				m.pixels[i][removeSeam[i]+1].y = yy;
				m.pixels[i][removeSeam[i]+2].y = yy;
				
				int county = m.pixels[i][removeSeam[i]].county;
				if (county < m.pixels[i][removeSeam[i]+1].county){county = m.pixels[i][removeSeam[i]+1].county;}
				m.pixels[i][removeSeam[i]].county = county;
				m.pixels[i][removeSeam[i]+1].county = county;
				m.pixels[i][removeSeam[i]+2].county = county;
				
				if (computeVal){m.pixels[i][removeSeam[i]].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]+1].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]+2].computeVal();}
			}
			else {
				for(ii=m.height;ii>removeSeam[i]+1;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val;
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
				
				for (ii=0;ii<nd;ii++){
					s = datas[ii];
					r = m.pixels[i][removeSeam[i]].data[s];
					m.pixels[i][removeSeam[i]].data[s] = r/2;
					m.pixels[i][removeSeam[i]+1].data[s] = r - r/2;
				}
				
				
				m.pixels[i][removeSeam[i]].x = xx;
				m.pixels[i][removeSeam[i]+1].x = xx;
				
				m.pixels[i][removeSeam[i]].y = yy;
				m.pixels[i][removeSeam[i]+1].y = yy;
				
				if (computeVal){m.pixels[i][removeSeam[i]].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]+1].computeVal();}
				
				int county = m.pixels[i][removeSeam[i]].county;
				m.pixels[i][removeSeam[i]].county = county;
				m.pixels[i][removeSeam[i]+1].county = county;
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
	std::string s;
	int r;
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
				
				for (i=0;i<nd;i++){
					s = datas[i];
					r = m.pixels[removeSeam[ii]][ii].data[s]+m.pixels[removeSeam[ii]-1][ii].data[s]+m.pixels[removeSeam[ii]+1][ii].data[s];
					m.pixels[removeSeam[ii]-1][ii].data[s]=r/4;
					m.pixels[removeSeam[ii]][ii].data[s]=r - r/4 - r/4 - r/4;
					m.pixels[removeSeam[ii]+1][ii].data[s]=r/4;
					m.pixels[removeSeam[ii]+2][ii].data[s]= r/4;
				}
				
				m.pixels[removeSeam[ii]-1][ii].x=xx;
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]+1][ii].x=xx;
				m.pixels[removeSeam[ii]+2][ii].x= xx;
				
				m.pixels[removeSeam[ii]-1][ii].y=yy;
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]+1][ii].y=yy;
				m.pixels[removeSeam[ii]+2][ii].y= yy;
				
				if (computeVal){m.pixels[removeSeam[ii]][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]-1][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]+1][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]+2][ii].computeVal();}
				
				int county = m.pixels[removeSeam[ii]][ii].county;
				if (county < m.pixels[removeSeam[ii]+1][ii].county){county = m.pixels[removeSeam[ii]+1][ii].county;}
				if (county < m.pixels[removeSeam[ii]-1][ii].county){county = m.pixels[removeSeam[ii]-1][ii].county;}
				m.pixels[removeSeam[ii]][ii].county = county;
				m.pixels[removeSeam[ii]+1][ii].county = county;
				m.pixels[removeSeam[ii]+2][ii].county = county;
				m.pixels[removeSeam[ii]-1][ii].county = county;
			}
			else if (removeSeam[ii]+1<m.width){
				for(i=m.width;i>removeSeam[ii]+2;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
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
				
				for (i=0;i<nd;i++){
					s = datas[i];
					r = m.pixels[removeSeam[ii]][ii].data[s]+m.pixels[removeSeam[ii]+1][ii].data[s];
					m.pixels[removeSeam[ii]][ii].data[s]=r - r/3 - r/3;
					m.pixels[removeSeam[ii]+1][ii].data[s]=r/3;
					m.pixels[removeSeam[ii]+2][ii].data[s]= r/3;
				}
				
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]+1][ii].x=xx;
				m.pixels[removeSeam[ii]+2][ii].x= xx;
				
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]+1][ii].y=yy;
				m.pixels[removeSeam[ii]+2][ii].y= yy;
				
				if (computeVal){m.pixels[removeSeam[ii]][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]+1][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]+2][ii].computeVal();}
				
				int county = m.pixels[removeSeam[ii]][ii].county;
				if (county < m.pixels[removeSeam[ii]+1][ii].county){county = m.pixels[removeSeam[ii]+1][ii].county;}
				m.pixels[removeSeam[ii]][ii].county = county;
				m.pixels[removeSeam[ii]+1][ii].county = county;
				m.pixels[removeSeam[ii]+2][ii].county = county;
			}
			else {
				for(i=m.width;i>removeSeam[ii]+1;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val;
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
				
				for (i=0;i<nd;i++){
					s = datas[i];
					r = m.pixels[removeSeam[ii]][ii].data[s];
					m.pixels[removeSeam[ii]][ii].data[s]=r/2;
					m.pixels[removeSeam[ii]+1][ii].data[s]= r - r/2;
				}
				
				
				m.pixels[removeSeam[ii]][ii].x=xx;
				m.pixels[removeSeam[ii]+1][ii].x= xx;
				
				m.pixels[removeSeam[ii]][ii].y=yy;
				m.pixels[removeSeam[ii]+1][ii].y= yy;
				
				if (computeVal){m.pixels[removeSeam[ii]][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]+1][ii].computeVal();}
				
				int county = m.pixels[removeSeam[ii]][ii].county;
				m.pixels[removeSeam[ii]][ii].county = county;
				m.pixels[removeSeam[ii]+1][ii].county = county;
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
	std::string s;
	int r;
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
				
				for (ii=0;ii<nd;ii++){
					s = datas[ii];
					r = m.pixels[i][removeSeam[i]].data[s]+m.pixels[i][removeSeam[i]-1].data[s]+m.pixels[i][removeSeam[i]+1].data[s];
					m.pixels[i][removeSeam[i]].data[s]=r - r/2;
					m.pixels[i][removeSeam[i]-1].data[s]= r/2;
				}
				
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
				
				if (computeVal){m.pixels[i][removeSeam[i]].computeVal();}
				if (computeVal){m.pixels[i][removeSeam[i]-1].computeVal();}
				
				for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
					m.pixels[i][ii]=m.pixels[i][ii+1];
				}
				
				int county = m.pixels[i][removeSeam[i]].county;
				if (county < m.pixels[i][removeSeam[i]+1].county){county = m.pixels[i][removeSeam[i]+1].county;}
				if (county < m.pixels[i][removeSeam[i]-1].county){county = m.pixels[i][removeSeam[i]-1].county;}
				m.pixels[i][removeSeam[i]-1].county = county;
				m.pixels[i][removeSeam[i]].county = county;
			}
			else if (removeSeam[i]+1 < m.height){
				int v = m.pixels[i][removeSeam[i]].val +m.pixels[i][removeSeam[i]+1].val;
				
				for (ii=0;ii<nd;ii++){
					s = datas[ii];
					m.pixels[i][removeSeam[i]].data[s] +=m.pixels[i][removeSeam[i]+1].data[s];
				}
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
				
				if (computeVal){m.pixels[i][removeSeam[i]].computeVal();}
				
				int county = m.pixels[i][removeSeam[i]].county;
				if (county < m.pixels[i][removeSeam[i]+1].county){county = m.pixels[i][removeSeam[i]+1].county;}
				m.pixels[i][removeSeam[i]].county = county;
				
				for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
					m.pixels[i][ii]=m.pixels[i][ii+1];
				}
			}
			else {
				int v = m.pixels[i][removeSeam[i]].val +m.pixels[i][removeSeam[i]-1].val;
				
				for (ii=0;ii<nd;ii++){
					s = datas[ii];
					m.pixels[i][removeSeam[i]-1].data[s] +=m.pixels[i][removeSeam[i]].data[s];
				}
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
				
				if (computeVal){m.pixels[i][removeSeam[i]-1].computeVal();}
				
				int county = m.pixels[i][removeSeam[i]].county;
				if (county < m.pixels[i][removeSeam[i]-1].county){county = m.pixels[i][removeSeam[i]-1].county;}
				m.pixels[i][removeSeam[i]-1].county = county;
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
	std::string s;
	int r;
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
				
				for (i=0;i<nd;i++){
					s = datas[i];
					r = m.pixels[removeSeam[ii]][ii].data[s]+m.pixels[removeSeam[ii]-1][ii].data[s]+m.pixels[removeSeam[ii]+1][ii].data[s];
					m.pixels[removeSeam[ii]][ii].data[s]=r - r/2;
					m.pixels[removeSeam[ii]-1][ii].data[s]= r/2;
				}
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
				
				if (computeVal){m.pixels[removeSeam[ii]][ii].computeVal();}
				if (computeVal){m.pixels[removeSeam[ii]-1][ii].computeVal();}
				
				int county = m.pixels[removeSeam[ii]][ii].county;
				if (county < m.pixels[removeSeam[ii]+1][ii].county){county = m.pixels[removeSeam[ii]+1][ii].county;}
				if (county < m.pixels[removeSeam[ii]-1][ii].county){county = m.pixels[removeSeam[ii]-1][ii].county;}
				m.pixels[removeSeam[ii]][ii].county = county;
				m.pixels[removeSeam[ii]-1][ii].county = county;
				
				for(i=removeSeam[ii]+1;i<m.width-1;i++){
			
					m.pixels[i][ii]=m.pixels[i+1][ii];
				}
			}
			else if (removeSeam[ii]+1 < m.width){
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
				
				for (i=0;i<nd;i++){
					s = datas[i];
					m.pixels[removeSeam[ii]][ii].data[s]+=m.pixels[removeSeam[ii]+1][ii].data[s];
				}
				
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
				
				if (computeVal){m.pixels[removeSeam[ii]][ii].computeVal();}
				
				int county = m.pixels[removeSeam[ii]][ii].county;
				if (county < m.pixels[removeSeam[ii]+1][ii].county){county = m.pixels[removeSeam[ii]+1][ii].county;}
				m.pixels[removeSeam[ii]][ii].county = county;
				
				for(i=removeSeam[ii]+1;i<m.width-1;i++){
			
					m.pixels[i][ii]=m.pixels[i+1][ii];
				}
			}
			else {
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]-1][ii].val;
				
				for (i=0;i<nd;i++){
					s = datas[i];
					m.pixels[removeSeam[ii]-1][ii].data[s]+=m.pixels[removeSeam[ii]][ii].data[s];
				}
				
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
				if (computeVal){m.pixels[removeSeam[ii]-1][ii].computeVal();}
				
				int county = m.pixels[removeSeam[ii]][ii].county;
				if (county < m.pixels[removeSeam[ii]-1][ii].county){county = m.pixels[removeSeam[ii]-1][ii].county;}
				m.pixels[removeSeam[ii]-1][ii].county = county;
				
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
	int iiii;
	int npixels = 200;
	
	killCarveV = false;
	killCarveH = false;
	
	computeVal = false;
	
	auto a11 = std::chrono::high_resolution_clock::now();
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();

	a11 = std::chrono::high_resolution_clock::now();
	
	np =0;//will get set to right value in scPoints()
	scPoints0();
	scPoints1();
	scPoints2();
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationTotal);
	a11 = std::chrono::high_resolution_clock::now();
	
	
	nd = 0;
	datas.resize(0);
	//for (std::map<std::string,int>::iterator iter = points[0].data.begin(); iter != points[0].data.end(); ++iter){
	//	datas.push_back(iter->first);
	//	nd++;
	//}
	datas.push_back("d");
	datas.push_back("r");
	datas.push_back("d16");
	datas.push_back("r16");
	datas.push_back("white");
	datas.push_back("black");
	nd = 6;
	
	std::map<int,std::map<int,Point>> pixels;
	std::map<int,std::map<int,int>> pixelMap;

	for(i=0;i<npixels;i++){
		std::map<int,Point> v;
		pixels[i] = v;
		std::map<int,int> vv;
		pixelMap[i]=vv;
		for(ii=0;ii<npixels;ii++){
			Point p;
			p.x = i;
			p.y = ii;
			p.val = 0;
			p.county = 0;
			for (iii=0;iii<nd;iii++){
				p.data[datas[iii]] = 0;
			}
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
	
	
	for(i=0;i<np;i++){
		points[i].npix = 0;
		pixelMap[points[i].x][points[i].y]=i;
	}
	

	
	for(i=0;i<npixels;i++){
		for(ii=0;ii<npixels;ii++){
			if (pixelMap[i][ii]>=0){
				points[pixelMap[i][ii]].npix++;
				continue;
			}
			int minX = i-3;
			int maxX = i+3;
			int minY = ii-3;
			int maxY = ii+3;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > npixels){maxX = npixels;}
			if (maxY > npixels){maxY = npixels;}
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
			
			minX = i-6;
			maxX = i+6;
			minY = ii-6;
			maxY = ii+6;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > npixels){maxX = npixels;}
			if (maxY > npixels){maxY = npixels;}
			minP = 1000000000;
			minI = 0;
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
			/*
			for (iii=0;iii<np;iii++){
				d = (points[iii].x-i)*(points[iii].x-i)+(points[iii].y-ii)*(points[iii].y-ii);
				if (d < minP){
					minP = d;
					minI = iii;
				}
			}
			points[minI].npix++;*/
		}
	}
	

	std::string s;
	for(i=0;i<npixels;i++){
		for(ii=0;ii<npixels;ii++){
			if (pixelMap[i][ii]>=0){
				pixels[i][ii].val += points[pixelMap[i][ii]].val*100/points[pixelMap[i][ii]].npix;
				for (iii=0;iii<nd;iii++){
					s = datas[iii];
					pixels[i][ii].data[s] += points[pixelMap[i][ii]].data[s]*100/points[pixelMap[i][ii]].npix;
				}
				if (computeVal){pixels[i][ii].computeVal();}
				pixels[i][ii].x = points[pixelMap[i][ii]].x;
				pixels[i][ii].y = points[pixelMap[i][ii]].y;
				if (pixels[i][ii].county < points[pixelMap[i][ii]].county){
					pixels[i][ii].county = points[pixelMap[i][ii]].county;
				}
				continue;
			}
			int minX = i-3;
			int maxX = i+3;
			int minY = ii-3;
			int maxY = ii+3;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > npixels){maxX = npixels;}
			if (maxY > npixels){maxY = npixels;}
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
				for (iii=0;iii<nd;iii++){
					s = datas[iii];
					pixels[i][ii].data[s] += points[minI].data[s]*100/points[minI].npix;
				}
				if (computeVal){pixels[i][ii].computeVal();}
				pixels[i][ii].x = points[minI].x;
				pixels[i][ii].y = points[minI].y;
				if (pixels[i][ii].county < points[minI].county){
					pixels[i][ii].county = points[minI].county;
				}
				continue;
			}
			
			minX = i-6;
			maxX = i+6;
			minY = ii-6;
			maxY = ii+6;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > npixels){maxX = npixels;}
			if (maxY > npixels){maxY = npixels;}
			minP = 1000000000;
			minI = 0;
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
				for (iii=0;iii<nd;iii++){
					s = datas[iii];
					pixels[i][ii].data[s] += points[minI].data[s]*100/points[minI].npix;
				}
				if (computeVal){pixels[i][ii].computeVal();}
				pixels[i][ii].x = points[minI].x;
				pixels[i][ii].y = points[minI].y;
				if (pixels[i][ii].county < points[minI].county){
					pixels[i][ii].county = points[minI].county;
				}
				continue;
			}
			/*
			for (iii=0;iii<np;iii++){
				d = (points[iii].x-i)*(points[iii].x-i)+(points[iii].y-ii)*(points[iii].y-ii);
				if (d < minP){
					minP = d;
					minI = iii;
				}
			}
			pixels[i][ii].val += points[minI].val*100/points[minI].npix;
			for (iii=0;iii<nd;iii++){
				s = datas[iii];
				pixels[i][ii].data[s] += points[minI].data[s]*100/points[minI].npix;
			}
			pixels[i][ii].x = points[minI].x;
			pixels[i][ii].y = points[minI].y;
			pixels[i][ii].county = points[minI].county;*/
		}
	}
	
	
	
	

	
	Map m;
	m.pixels = pixels;
	m.width = npixels;
	m.height = npixels;
	
	
	
	a22 = std::chrono::high_resolution_clock::now();
	durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationTotal);
	
	a11 = std::chrono::high_resolution_clock::now();
	
	set_maxX(m.width);
	set_maxY(m.height);
	for (iii=0;iii<101;iii++){
		vertThreads = 1 + (rand() % (25-iii/5));
		horzThreads = 1 + (rand() % (25-iii/5));
		if (iii%5 == 0){
			for(i=0;i<m.width;i++){
				for(ii=0;ii<m.height;ii++){
					Point p = m.pixels[i][ii];
					std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county);
					for (iiii=0;iiii<nd;iiii++){
						s = datas[iiii];
						pointStr += ","+std::to_string(p.data[s]);
					}
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
			std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county);
			for (iiii=0;iiii<nd;iiii++){
				s = datas[iiii];
				pointStr += ","+std::to_string(p.data[s]);
			}
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
