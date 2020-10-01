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

extern "C" {


}

struct Point {
	int x;
	int y;
	int val;
	int county;
	int npix;
	std::map<std::string,int> data;
};

std::map<int,Point> points;


void scPoints0(){
points.clear();
if (1==1){ Point p;
p.x = 70; p.y = 77; p.county = 0; p.val = 6610; p.data["black"] = 810; p.data["white"] = 5620; p.data["r"] = 1482; p.data["d"] = 1168; p.data["d16"] = 1600; p.data["r16"] = 539;
points[0]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 9; p.county = 0; p.val = 1805; p.data["black"] = 75; p.data["white"] = 1720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 71; p.data["r16"] = 736;
points[1]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 36; p.county = 0; p.val = 7190; p.data["black"] = 6380; p.data["white"] = 580; p.data["r"] = 442; p.data["d"] = 11; p.data["d16"] = 1780; p.data["r16"] = 35;
points[2]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 36; p.county = 0; p.val = 7910; p.data["black"] = 5785; p.data["white"] = 1853; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1485; p.data["r16"] = 534;
points[3]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 35; p.county = 0; p.val = 6180; p.data["black"] = 3845; p.data["white"] = 1810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[4]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 54; p.county = 0; p.val = 3070; p.data["black"] = 2125; p.data["white"] = 865; p.data["r"] = 618; p.data["d"] = 282; p.data["d16"] = 1242; p.data["r16"] = 322;
points[5]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 36; p.county = 0; p.val = 9140; p.data["black"] = 4735; p.data["white"] = 3129; p.data["r"] = 1089; p.data["d"] = 160; p.data["d16"] = 1190; p.data["r16"] = 380;
points[6]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 36; p.county = 0; p.val = 1065; p.data["black"] = 510; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[7]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 34; p.county = 0; p.val = 6495; p.data["black"] = 3315; p.data["white"] = 2685; p.data["r"] = 990; p.data["d"] = 182; p.data["d16"] = 0; p.data["r16"] = 0;
points[8]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 38; p.county = 0; p.val = 1465; p.data["black"] = 1300; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[9]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 39; p.county = 0; p.val = 7335; p.data["black"] = 4790; p.data["white"] = 1840; p.data["r"] = 729; p.data["d"] = 63; p.data["d16"] = 766; p.data["r16"] = 77;
points[10]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 31; p.county = 0; p.val = 2030; p.data["black"] = 665; p.data["white"] = 1290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[11]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 31; p.county = 0; p.val = 1505; p.data["black"] = 1165; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[12]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 32; p.county = 0; p.val = 1615; p.data["black"] = 1435; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 280; p.data["r16"] = 642;
points[13]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 39; p.county = 0; p.val = 1705; p.data["black"] = 945; p.data["white"] = 660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[14]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 47; p.county = 0; p.val = 1095; p.data["black"] = 275; p.data["white"] = 790; p.data["r"] = 24; p.data["d"] = 126; p.data["d16"] = 0; p.data["r16"] = 0;
points[15]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 22; p.county = 0; p.val = 3755; p.data["black"] = 1915; p.data["white"] = 1655; p.data["r"] = 186; p.data["d"] = 34; p.data["d16"] = 274; p.data["r16"] = 39;
points[16]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 22; p.county = 0; p.val = 1245; p.data["black"] = 360; p.data["white"] = 875; p.data["r"] = 291; p.data["d"] = 501; p.data["d16"] = 0; p.data["r16"] = 0;
points[17]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 62; p.county = 0; p.val = 1190; p.data["black"] = 385; p.data["white"] = 775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[18]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 71; p.county = 0; p.val = 6235; p.data["black"] = 2075; p.data["white"] = 3335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[19]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 56; p.county = 0; p.val = 905; p.data["black"] = 905; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[20]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 70; p.county = 0; p.val = 4415; p.data["black"] = 1345; p.data["white"] = 2530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[21]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 69; p.county = 0; p.val = 5425; p.data["black"] = 1750; p.data["white"] = 3045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[22]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 65; p.county = 0; p.val = 3925; p.data["black"] = 570; p.data["white"] = 3025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 255; p.data["r16"] = 210;
points[23]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 65; p.county = 0; p.val = 2915; p.data["black"] = 1135; p.data["white"] = 1565; p.data["r"] = 604; p.data["d"] = 370; p.data["d16"] = 414; p.data["r16"] = 482;
points[24]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 14; p.county = 0; p.val = 1645; p.data["black"] = 120; p.data["white"] = 1445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 198; p.data["r16"] = 500;
points[25]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 13; p.county = 0; p.val = 1900; p.data["black"] = 25; p.data["white"] = 1815; p.data["r"] = 123; p.data["d"] = 525; p.data["d16"] = 0; p.data["r16"] = 0;
points[26]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 12; p.county = 0; p.val = 1475; p.data["black"] = 305; p.data["white"] = 1170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[27]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 14; p.county = 0; p.val = 1250; p.data["black"] = 65; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[28]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 12; p.county = 0; p.val = 1610; p.data["black"] = 4; p.data["white"] = 1570; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[29]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 8; p.county = 0; p.val = 1310; p.data["black"] = 0; p.data["white"] = 1255; p.data["r"] = 64; p.data["d"] = 360; p.data["d16"] = 109; p.data["r16"] = 772;
points[30]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 13; p.county = 0; p.val = 1225; p.data["black"] = 60; p.data["white"] = 1160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 477; p.data["r16"] = 2210;
points[31]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 17; p.county = 0; p.val = 4090; p.data["black"] = 545; p.data["white"] = 3215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[32]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 13; p.county = 0; p.val = 1775; p.data["black"] = 50; p.data["white"] = 1695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[33]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 12; p.county = 0; p.val = 6515; p.data["black"] = 669; p.data["white"] = 5625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 227; p.data["r16"] = 1061;
points[34]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 15; p.county = 0; p.val = 2505; p.data["black"] = 520; p.data["white"] = 1750; p.data["r"] = 179; p.data["d"] = 157; p.data["d16"] = 521; p.data["r16"] = 565;
points[35]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 5; p.county = 0; p.val = 1560; p.data["black"] = 20; p.data["white"] = 1485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 181; p.data["r16"] = 869;
points[36]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 10; p.county = 0; p.val = 1270; p.data["black"] = 245; p.data["white"] = 985; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[37]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 10; p.county = 0; p.val = 900; p.data["black"] = 50; p.data["white"] = 825; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[38]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 13; p.county = 0; p.val = 1680; p.data["black"] = 85; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[39]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 11; p.county = 0; p.val = 1600; p.data["black"] = 15; p.data["white"] = 1535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[40]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 48; p.county = 0; p.val = 890; p.data["black"] = 310; p.data["white"] = 580; p.data["r"] = 162; p.data["d"] = 154; p.data["d16"] = 0; p.data["r16"] = 0;
points[41]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 48; p.county = 0; p.val = 270; p.data["black"] = 205; p.data["white"] = 65; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[42]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 49; p.county = 0; p.val = 445; p.data["black"] = 225; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[43]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 35; p.county = 0; p.val = 3375; p.data["black"] = 3025; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[44]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 48; p.county = 0; p.val = 1685; p.data["black"] = 1040; p.data["white"] = 645; p.data["r"] = 268; p.data["d"] = 409; p.data["d16"] = 275; p.data["r16"] = 150;
points[45]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 47; p.county = 0; p.val = 355; p.data["black"] = 295; p.data["white"] = 30; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[46]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 11; p.county = 0; p.val = 3340; p.data["black"] = 520; p.data["white"] = 2705; p.data["r"] = 170; p.data["d"] = 412; p.data["d16"] = 145; p.data["r16"] = 487;
points[47]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 12; p.county = 0; p.val = 2800; p.data["black"] = 755; p.data["white"] = 1890; p.data["r"] = 479; p.data["d"] = 1180; p.data["d16"] = 0; p.data["r16"] = 0;
points[48]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 51; p.county = 0; p.val = 2825; p.data["black"] = 1290; p.data["white"] = 1365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[49]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 52; p.county = 0; p.val = 1555; p.data["black"] = 775; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[50]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 53; p.county = 0; p.val = 4830; p.data["black"] = 880; p.data["white"] = 3865; p.data["r"] = 624; p.data["d"] = 641; p.data["d16"] = 0; p.data["r16"] = 0;
points[51]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 54; p.county = 0; p.val = 3030; p.data["black"] = 360; p.data["white"] = 2265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 363; p.data["r16"] = 727;
points[52]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 6; p.county = 0; p.val = 2875; p.data["black"] = 195; p.data["white"] = 2375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[53]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 5; p.county = 0; p.val = 4230; p.data["black"] = 515; p.data["white"] = 3545; p.data["r"] = 509; p.data["d"] = 1082; p.data["d16"] = 0; p.data["r16"] = 0;
points[54]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 71; p.county = 0; p.val = 10890; p.data["black"] = 2760; p.data["white"] = 7065; p.data["r"] = 803; p.data["d"] = 410; p.data["d16"] = 1401; p.data["r16"] = 1390;
points[55]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 2; p.county = 0; p.val = 2075; p.data["black"] = 200; p.data["white"] = 1840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[56]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 5; p.county = 0; p.val = 3130; p.data["black"] = 245; p.data["white"] = 2715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[57]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 5; p.county = 0; p.val = 3840; p.data["black"] = 0; p.data["white"] = 3335; p.data["r"] = 478; p.data["d"] = 655; p.data["d16"] = 701; p.data["r16"] = 1094;
points[58]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 7; p.county = 0; p.val = 1585; p.data["black"] = 80; p.data["white"] = 1395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 666; p.data["r16"] = 1116;
points[59]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 7; p.county = 0; p.val = 1970; p.data["black"] = 95; p.data["white"] = 1775; p.data["r"] = 885; p.data["d"] = 1277; p.data["d16"] = 0; p.data["r16"] = 0;
points[60]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 5; p.county = 0; p.val = 5165; p.data["black"] = 895; p.data["white"] = 3940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 463; p.data["r16"] = 1069;
points[61]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 37; p.county = 0; p.val = 460; p.data["black"] = 0; p.data["white"] = 460; p.data["r"] = 39; p.data["d"] = 297; p.data["d16"] = 39; p.data["r16"] = 377;
points[62]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 42; p.county = 0; p.val = 500; p.data["black"] = 95; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[63]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 37; p.county = 0; p.val = 590; p.data["black"] = 90; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 148; p.data["r16"] = 491;
points[64]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 37; p.county = 0; p.val = 1270; p.data["black"] = 35; p.data["white"] = 1225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 70; p.data["r16"] = 438;
points[65]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 34; p.county = 0; p.val = 865; p.data["black"] = 260; p.data["white"] = 530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 212; p.data["r16"] = 217;
points[66]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 63; p.county = 0; p.val = 1660; p.data["black"] = 670; p.data["white"] = 950; p.data["r"] = 377; p.data["d"] = 238; p.data["d16"] = 0; p.data["r16"] = 0;
points[67]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 63; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[68]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 72; p.county = 0; p.val = 8635; p.data["black"] = 970; p.data["white"] = 6750; p.data["r"] = 509; p.data["d"] = 200; p.data["d16"] = 0; p.data["r16"] = 0;
points[69]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 67; p.county = 0; p.val = 2220; p.data["black"] = 330; p.data["white"] = 1550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 801; p.data["r16"] = 1557;
points[70]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 67; p.county = 0; p.val = 2985; p.data["black"] = 70; p.data["white"] = 2600; p.data["r"] = 312; p.data["d"] = 439; p.data["d16"] = 0; p.data["r16"] = 0;
points[71]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 71; p.county = 0; p.val = 14340; p.data["black"] = 4285; p.data["white"] = 8795; p.data["r"] = 629; p.data["d"] = 395; p.data["d16"] = 303; p.data["r16"] = 335;
points[72]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 64; p.county = 0; p.val = 1835; p.data["black"] = 815; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 499; p.data["r16"] = 426;
points[73]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 69; p.county = 0; p.val = 15915; p.data["black"] = 3260; p.data["white"] = 10800; p.data["r"] = 318; p.data["d"] = 321; p.data["d16"] = 0; p.data["r16"] = 0;
points[74]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 57; p.county = 0; p.val = 1000; p.data["black"] = 555; p.data["white"] = 430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[75]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 72; p.county = 0; p.val = 9095; p.data["black"] = 2135; p.data["white"] = 6015; p.data["r"] = 1487; p.data["d"] = 1335; p.data["d16"] = 1043; p.data["r16"] = 1113;
points[76]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 22; p.county = 0; p.val = 1560; p.data["black"] = 450; p.data["white"] = 1060; p.data["r"] = 306; p.data["d"] = 443; p.data["d16"] = 189; p.data["r16"] = 456;
points[77]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 26; p.county = 0; p.val = 740; p.data["black"] = 125; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[78]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 10; p.county = 0; p.val = 4365; p.data["black"] = 395; p.data["white"] = 3360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 249; p.data["r16"] = 556;
points[79]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 8; p.county = 0; p.val = 5950; p.data["black"] = 815; p.data["white"] = 4880; p.data["r"] = 275; p.data["d"] = 417; p.data["d16"] = 0; p.data["r16"] = 0;
points[80]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 10; p.county = 0; p.val = 3820; p.data["black"] = 785; p.data["white"] = 2875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[81]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 9; p.county = 0; p.val = 7480; p.data["black"] = 1120; p.data["white"] = 5745; p.data["r"] = 932; p.data["d"] = 811; p.data["d16"] = 0; p.data["r16"] = 0;
points[82]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 37; p.county = 0; p.val = 13130; p.data["black"] = 2240; p.data["white"] = 10465; p.data["r"] = 1086; p.data["d"] = 830; p.data["d16"] = 582; p.data["r16"] = 391;
points[83]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 38; p.county = 0; p.val = 20495; p.data["black"] = 3530; p.data["white"] = 15320; p.data["r"] = 476; p.data["d"] = 150; p.data["d16"] = 3040; p.data["r16"] = 871;
points[84]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 37; p.county = 0; p.val = 6785; p.data["black"] = 2285; p.data["white"] = 4120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 2233; p.data["r16"] = 285;
points[85]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 36; p.county = 0; p.val = 7990; p.data["black"] = 1685; p.data["white"] = 5685; p.data["r"] = 1768; p.data["d"] = 1343; p.data["d16"] = 1105; p.data["r16"] = 1272;
points[86]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 39; p.county = 0; p.val = 6075; p.data["black"] = 1170; p.data["white"] = 4510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[87]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 45; p.county = 0; p.val = 590; p.data["black"] = 295; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[88]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 49; p.county = 0; p.val = 720; p.data["black"] = 370; p.data["white"] = 345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[89]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 47; p.county = 0; p.val = 560; p.data["black"] = 510; p.data["white"] = 50; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[90]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 45; p.county = 0; p.val = 785; p.data["black"] = 380; p.data["white"] = 405; p.data["r"] = 185; p.data["d"] = 318; p.data["d16"] = 195; p.data["r16"] = 388;
points[91]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 53; p.county = 0; p.val = 590; p.data["black"] = 535; p.data["white"] = 35; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[92]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 45; p.county = 0; p.val = 540; p.data["black"] = 335; p.data["white"] = 190; p.data["r"] = 144; p.data["d"] = 27; p.data["d16"] = 0; p.data["r16"] = 0;
points[93]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 45; p.county = 0; p.val = 875; p.data["black"] = 380; p.data["white"] = 465; p.data["r"] = 15; p.data["d"] = 59; p.data["d16"] = 55; p.data["r16"] = 306;
points[94]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 43; p.county = 0; p.val = 760; p.data["black"] = 45; p.data["white"] = 690; p.data["r"] = 786; p.data["d"] = 116; p.data["d16"] = 0; p.data["r16"] = 0;
points[95]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 55; p.county = 0; p.val = 800; p.data["black"] = 470; p.data["white"] = 330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 488; p.data["r16"] = 61;
points[96]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 52; p.county = 0; p.val = 635; p.data["black"] = 470; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[97]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 49; p.county = 0; p.val = 750; p.data["black"] = 565; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 385; p.data["r16"] = 47;
points[98]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 56; p.county = 0; p.val = 590; p.data["black"] = 305; p.data["white"] = 245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[99]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 55; p.county = 0; p.val = 1200; p.data["black"] = 585; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[100]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 49; p.county = 0; p.val = 1330; p.data["black"] = 1170; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[101]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 52; p.county = 0; p.val = 505; p.data["black"] = 95; p.data["white"] = 400; p.data["r"] = 139; p.data["d"] = 12; p.data["d16"] = 10; p.data["r16"] = 262;
points[102]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 46; p.county = 0; p.val = 1035; p.data["black"] = 965; p.data["white"] = 70; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[103]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 47; p.county = 0; p.val = 1180; p.data["black"] = 1155; p.data["white"] = 15; p.data["r"] = 790; p.data["d"] = 74; p.data["d16"] = 1050; p.data["r16"] = 71;
points[104]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 45; p.county = 0; p.val = 505; p.data["black"] = 70; p.data["white"] = 435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[105]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 51; p.county = 0; p.val = 710; p.data["black"] = 430; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[106]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 50; p.county = 0; p.val = 430; p.data["black"] = 235; p.data["white"] = 130; p.data["r"] = 308; p.data["d"] = 158; p.data["d16"] = 0; p.data["r16"] = 0;
points[107]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 48; p.county = 0; p.val = 1840; p.data["black"] = 1695; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[108]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 47; p.county = 0; p.val = 1130; p.data["black"] = 525; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 71; p.data["r16"] = 186;
points[109]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 47; p.county = 0; p.val = 1080; p.data["black"] = 600; p.data["white"] = 445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[110]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 11; p.county = 0; p.val = 5090; p.data["black"] = 299; p.data["white"] = 4470; p.data["r"] = 911; p.data["d"] = 1954; p.data["d16"] = 557; p.data["r16"] = 1347;
points[111]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 12; p.county = 0; p.val = 8710; p.data["black"] = 575; p.data["white"] = 7265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[112]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 13; p.county = 0; p.val = 6585; p.data["black"] = 2000; p.data["white"] = 4095; p.data["r"] = 509; p.data["d"] = 535; p.data["d16"] = 458; p.data["r16"] = 741;
points[113]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 15; p.county = 0; p.val = 10035; p.data["black"] = 1725; p.data["white"] = 7405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[114]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 14; p.county = 0; p.val = 7510; p.data["black"] = 1395; p.data["white"] = 5650; p.data["r"] = 390; p.data["d"] = 514; p.data["d16"] = 530; p.data["r16"] = 1009;
points[115]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 15; p.county = 0; p.val = 5585; p.data["black"] = 880; p.data["white"] = 4460; p.data["r"] = 853; p.data["d"] = 1204; p.data["d16"] = 0; p.data["r16"] = 0;
points[116]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 13; p.county = 0; p.val = 7555; p.data["black"] = 5470; p.data["white"] = 1754; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[117]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 12; p.county = 0; p.val = 11665; p.data["black"] = 3155; p.data["white"] = 8190; p.data["r"] = 1209; p.data["d"] = 311; p.data["d16"] = 1983; p.data["r16"] = 231;
points[118]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 11; p.county = 0; p.val = 9900; p.data["black"] = 4725; p.data["white"] = 4600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[119]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 12; p.county = 0; p.val = 6970; p.data["black"] = 435; p.data["white"] = 6425; p.data["r"] = 561; p.data["d"] = 1668; p.data["d16"] = 0; p.data["r16"] = 0;
points[120]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 7; p.county = 0; p.val = 960; p.data["black"] = 0; p.data["white"] = 960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[121]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 8; p.county = 0; p.val = 800; p.data["black"] = 0; p.data["white"] = 775; p.data["r"] = 200; p.data["d"] = 1136; p.data["d16"] = 81; p.data["r16"] = 755;
points[122]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 11; p.county = 0; p.val = 1065; p.data["black"] = 0; p.data["white"] = 1010; p.data["r"] = 146; p.data["d"] = 543; p.data["d16"] = 40; p.data["r16"] = 557;
points[123]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 7; p.county = 0; p.val = 1180; p.data["black"] = 0; p.data["white"] = 1145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[124]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 12; p.county = 0; p.val = 5840; p.data["black"] = 2200; p.data["white"] = 3205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 658; p.data["r16"] = 590;
points[125]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 26; p.county = 0; p.val = 5235; p.data["black"] = 2305; p.data["white"] = 2805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 227; p.data["r16"] = 583;
points[126]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 4; p.county = 0; p.val = 2185; p.data["black"] = 250; p.data["white"] = 1830; p.data["r"] = 543; p.data["d"] = 823; p.data["d16"] = 1818; p.data["r16"] = 2751;
points[127]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 4; p.county = 0; p.val = 7135; p.data["black"] = 630; p.data["white"] = 6065; p.data["r"] = 1147; p.data["d"] = 1693; p.data["d16"] = 267; p.data["r16"] = 554;
points[128]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 6; p.county = 0; p.val = 2860; p.data["black"] = 305; p.data["white"] = 2140; p.data["r"] = 1287; p.data["d"] = 1270; p.data["d16"] = 1333; p.data["r16"] = 1607;
points[129]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 3; p.county = 0; p.val = 3035; p.data["black"] = 275; p.data["white"] = 2195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[130]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 45; p.county = 0; p.val = 4955; p.data["black"] = 365; p.data["white"] = 4175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 387; p.data["r16"] = 789;
points[131]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 42; p.county = 0; p.val = 1370; p.data["black"] = 95; p.data["white"] = 1265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[132]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 50; p.county = 0; p.val = 6650; p.data["black"] = 205; p.data["white"] = 5870; p.data["r"] = 446; p.data["d"] = 902; p.data["d16"] = 0; p.data["r16"] = 0;
points[133]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 51; p.county = 0; p.val = 8920; p.data["black"] = 170; p.data["white"] = 8470; p.data["r"] = 355; p.data["d"] = 613; p.data["d16"] = 424; p.data["r16"] = 1268;
points[134]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 46; p.county = 0; p.val = 6370; p.data["black"] = 329; p.data["white"] = 5675; p.data["r"] = 338; p.data["d"] = 805; p.data["d16"] = 0; p.data["r16"] = 0;
points[135]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 47; p.county = 0; p.val = 5040; p.data["black"] = 1164; p.data["white"] = 3500; p.data["r"] = 300; p.data["d"] = 586; p.data["d16"] = 0; p.data["r16"] = 0;
points[136]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 40; p.county = 0; p.val = 6585; p.data["black"] = 1955; p.data["white"] = 4380; p.data["r"] = 505; p.data["d"] = 1074; p.data["d16"] = 0; p.data["r16"] = 0;
points[137]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 41; p.county = 0; p.val = 6395; p.data["black"] = 3705; p.data["white"] = 2510; p.data["r"] = 341; p.data["d"] = 11; p.data["d16"] = 1312; p.data["r16"] = 292;
points[138]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 41; p.county = 0; p.val = 6015; p.data["black"] = 1895; p.data["white"] = 3730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 404; p.data["r16"] = 1153;
points[139]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 42; p.county = 0; p.val = 2825; p.data["black"] = 810; p.data["white"] = 1835; p.data["r"] = 448; p.data["d"] = 561; p.data["d16"] = 1083; p.data["r16"] = 1923;
points[140]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 76; p.county = 0; p.val = 8435; p.data["black"] = 2505; p.data["white"] = 5505; p.data["r"] = 603; p.data["d"] = 723; p.data["d16"] = 901; p.data["r16"] = 1292;
points[141]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 75; p.county = 0; p.val = 7595; p.data["black"] = 470; p.data["white"] = 6695; p.data["r"] = 343; p.data["d"] = 439; p.data["d16"] = 930; p.data["r16"] = 1034;
points[142]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 76; p.county = 0; p.val = 9870; p.data["black"] = 640; p.data["white"] = 8765; p.data["r"] = 213; p.data["d"] = 278; p.data["d16"] = 513; p.data["r16"] = 597;
points[143]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 75; p.county = 0; p.val = 1395; p.data["black"] = 695; p.data["white"] = 630; p.data["r"] = 1020; p.data["d"] = 990; p.data["d16"] = 273; p.data["r16"] = 647;
points[144]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 73; p.county = 0; p.val = 6050; p.data["black"] = 190; p.data["white"] = 5740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[145]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 72; p.county = 0; p.val = 795; p.data["black"] = 355; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[146]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 37; p.county = 0; p.val = 10460; p.data["black"] = 6010; p.data["white"] = 3979; p.data["r"] = 846; p.data["d"] = 158; p.data["d16"] = 1645; p.data["r16"] = 360;
points[147]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 35; p.county = 0; p.val = 7655; p.data["black"] = 2960; p.data["white"] = 3665; p.data["r"] = 1851; p.data["d"] = 1141; p.data["d16"] = 1131; p.data["r16"] = 467;
points[148]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 34; p.county = 0; p.val = 7185; p.data["black"] = 3340; p.data["white"] = 3395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 2095; p.data["r16"] = 1335;
points[149]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 33; p.county = 0; p.val = 6825; p.data["black"] = 4615; p.data["white"] = 1825; p.data["r"] = 2086; p.data["d"] = 279; p.data["d16"] = 1298; p.data["r16"] = 281;
points[150]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 34; p.county = 0; p.val = 7410; p.data["black"] = 1810; p.data["white"] = 5160; p.data["r"] = 840; p.data["d"] = 798; p.data["d16"] = 0; p.data["r16"] = 0;
points[151]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 34; p.county = 0; p.val = 5015; p.data["black"] = 3630; p.data["white"] = 1115; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[152]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 32; p.county = 0; p.val = 1635; p.data["black"] = 140; p.data["white"] = 1495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[153]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 35; p.county = 0; p.val = 4175; p.data["black"] = 3235; p.data["white"] = 760; p.data["r"] = 641; p.data["d"] = 42; p.data["d16"] = 2024; p.data["r16"] = 408;
points[154]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 36; p.county = 0; p.val = 5900; p.data["black"] = 3965; p.data["white"] = 1620; p.data["r"] = 363; p.data["d"] = 212; p.data["d16"] = 1325; p.data["r16"] = 58;
points[155]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 38; p.county = 0; p.val = 2730; p.data["black"] = 1540; p.data["white"] = 1130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[156]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 46; p.county = 0; p.val = 730; p.data["black"] = 0; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[157]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 37; p.county = 0; p.val = 13275; p.data["black"] = 9805; p.data["white"] = 2950; p.data["r"] = 1684; p.data["d"] = 61; p.data["d16"] = 1367; p.data["r16"] = 681;
points[158]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 41; p.county = 0; p.val = 1310; p.data["black"] = 1120; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 718; p.data["r16"] = 113;
points[159]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 30; p.county = 0; p.val = 2145; p.data["black"] = 535; p.data["white"] = 1525; p.data["r"] = 56; p.data["d"] = 128; p.data["d16"] = 78; p.data["r16"] = 183;
points[160]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 33; p.county = 0; p.val = 6475; p.data["black"] = 945; p.data["white"] = 5060; p.data["r"] = 638; p.data["d"] = 889; p.data["d16"] = 0; p.data["r16"] = 0;
points[161]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 39; p.county = 0; p.val = 625; p.data["black"] = 175; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[162]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 42; p.county = 0; p.val = 1260; p.data["black"] = 1060; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[163]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 37; p.county = 0; p.val = 12990; p.data["black"] = 3600; p.data["white"] = 6425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[164]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 31; p.county = 0; p.val = 1345; p.data["black"] = 195; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[165]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 38; p.county = 0; p.val = 1060; p.data["black"] = 360; p.data["white"] = 680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 371; p.data["r16"] = 221;
points[166]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 41; p.county = 0; p.val = 925; p.data["black"] = 225; p.data["white"] = 700; p.data["r"] = 168; p.data["d"] = 131; p.data["d16"] = 0; p.data["r16"] = 0;
points[167]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 38; p.county = 0; p.val = 1245; p.data["black"] = 25; p.data["white"] = 1120; p.data["r"] = 537; p.data["d"] = 1107; p.data["d16"] = 421; p.data["r16"] = 1488;
points[168]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 41; p.county = 0; p.val = 445; p.data["black"] = 235; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[169]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 38; p.county = 0; p.val = 12020; p.data["black"] = 1159; p.data["white"] = 10470; p.data["r"] = 1891; p.data["d"] = 1334; p.data["d16"] = 592; p.data["r16"] = 560;
points[170]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 52; p.county = 0; p.val = 4695; p.data["black"] = 1305; p.data["white"] = 3290; p.data["r"] = 1030; p.data["d"] = 155; p.data["d16"] = 339; p.data["r16"] = 46;
points[171]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 93; p.county = 0; p.val = 4810; p.data["black"] = 310; p.data["white"] = 4125; p.data["r"] = 164; p.data["d"] = 425; p.data["d16"] = 0; p.data["r16"] = 0;
points[172]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 94; p.county = 0; p.val = 605; p.data["black"] = 0; p.data["white"] = 545; p.data["r"] = 574; p.data["d"] = 852; p.data["d16"] = 581; p.data["r16"] = 950;
points[173]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 94; p.county = 0; p.val = 4350; p.data["black"] = 590; p.data["white"] = 2935; p.data["r"] = 418; p.data["d"] = 801; p.data["d16"] = 434; p.data["r16"] = 418;
points[174]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 49; p.county = 0; p.val = 1735; p.data["black"] = 555; p.data["white"] = 1180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[175]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 52; p.county = 0; p.val = 1010; p.data["black"] = 155; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 278; p.data["r16"] = 441;
points[176]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 54; p.county = 0; p.val = 1980; p.data["black"] = 175; p.data["white"] = 1575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[177]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 52; p.county = 0; p.val = 3740; p.data["black"] = 825; p.data["white"] = 2850; p.data["r"] = 180; p.data["d"] = 329; p.data["d16"] = 532; p.data["r16"] = 976;
points[178]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 48; p.county = 0; p.val = 1740; p.data["black"] = 795; p.data["white"] = 905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[179]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 87; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 203; p.data["d"] = 591; p.data["d16"] = 0; p.data["r16"] = 0;
points[180]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 40; p.county = 0; p.val = 2055; p.data["black"] = 185; p.data["white"] = 1670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[181]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 40; p.county = 0; p.val = 5595; p.data["black"] = 305; p.data["white"] = 5135; p.data["r"] = 434; p.data["d"] = 793; p.data["d16"] = 0; p.data["r16"] = 0;
points[182]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 36; p.county = 0; p.val = 915; p.data["black"] = 0; p.data["white"] = 910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[183]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 38; p.county = 0; p.val = 4570; p.data["black"] = 305; p.data["white"] = 4020; p.data["r"] = 280; p.data["d"] = 530; p.data["d16"] = 295; p.data["r16"] = 615;
points[184]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 45; p.county = 0; p.val = 1370; p.data["black"] = 290; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[185]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 38; p.county = 0; p.val = 10340; p.data["black"] = 2485; p.data["white"] = 7360; p.data["r"] = 625; p.data["d"] = 322; p.data["d16"] = 1091; p.data["r16"] = 336;
points[186]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 40; p.county = 0; p.val = 1155; p.data["black"] = 900; p.data["white"] = 235; p.data["r"] = 445; p.data["d"] = 169; p.data["d16"] = 0; p.data["r16"] = 0;
points[187]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 44; p.county = 0; p.val = 1130; p.data["black"] = 1130; p.data["white"] = 0; p.data["r"] = 792; p.data["d"] = 52; p.data["d16"] = 0; p.data["r16"] = 0;
points[188]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 24; p.county = 0; p.val = 800; p.data["black"] = 85; p.data["white"] = 695; p.data["r"] = 149; p.data["d"] = 285; p.data["d16"] = 183; p.data["r16"] = 399;
points[189]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 29; p.county = 0; p.val = 1190; p.data["black"] = 380; p.data["white"] = 790; p.data["r"] = 235; p.data["d"] = 355; p.data["d16"] = 267; p.data["r16"] = 521;
points[190]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 30; p.county = 0; p.val = 1140; p.data["black"] = 315; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[191]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 29; p.county = 0; p.val = 975; p.data["black"] = 245; p.data["white"] = 720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[192]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 22; p.county = 0; p.val = 1330; p.data["black"] = 310; p.data["white"] = 1005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 180; p.data["r16"] = 117;
points[193]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 30; p.county = 0; p.val = 465; p.data["black"] = 290; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 276; p.data["r16"] = 44;
points[194]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 26; p.county = 0; p.val = 650; p.data["black"] = 115; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[195]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 29; p.county = 0; p.val = 960; p.data["black"] = 255; p.data["white"] = 660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[196]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 51; p.county = 0; p.val = 1060; p.data["black"] = 505; p.data["white"] = 555; p.data["r"] = 205; p.data["d"] = 253; p.data["d16"] = 0; p.data["r16"] = 0;
points[197]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 51; p.county = 0; p.val = 2305; p.data["black"] = 1555; p.data["white"] = 660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[198]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 46; p.county = 0; p.val = 1055; p.data["black"] = 290; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[199]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 47; p.county = 0; p.val = 805; p.data["black"] = 615; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 124; p.data["r16"] = 90;
points[200]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 47; p.county = 0; p.val = 875; p.data["black"] = 460; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 178; p.data["r16"] = 208;
points[201]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 51; p.county = 0; p.val = 450; p.data["black"] = 170; p.data["white"] = 250; p.data["r"] = 251; p.data["d"] = 213; p.data["d16"] = 280; p.data["r16"] = 244;
points[202]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 44; p.county = 0; p.val = 1910; p.data["black"] = 115; p.data["white"] = 1725; p.data["r"] = 347; p.data["d"] = 647; p.data["d16"] = 0; p.data["r16"] = 0;
points[203]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 53; p.county = 0; p.val = 515; p.data["black"] = 300; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[204]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 48; p.county = 0; p.val = 1525; p.data["black"] = 660; p.data["white"] = 710; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 172; p.data["r16"] = 133;
points[205]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 48; p.county = 0; p.val = 500; p.data["black"] = 245; p.data["white"] = 250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[206]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 49; p.county = 0; p.val = 1360; p.data["black"] = 1120; p.data["white"] = 235; p.data["r"] = 772; p.data["d"] = 224; p.data["d16"] = 0; p.data["r16"] = 0;
points[207]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 50; p.county = 0; p.val = 1040; p.data["black"] = 170; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[208]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 49; p.county = 0; p.val = 570; p.data["black"] = 195; p.data["white"] = 355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[209]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 21; p.county = 0; p.val = 1545; p.data["black"] = 25; p.data["white"] = 1505; p.data["r"] = 103; p.data["d"] = 451; p.data["d16"] = 96; p.data["r16"] = 580;
points[210]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 14; p.county = 0; p.val = 1340; p.data["black"] = 345; p.data["white"] = 830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[211]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 19; p.county = 0; p.val = 1590; p.data["black"] = 35; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[212]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 21; p.county = 0; p.val = 535; p.data["black"] = 4; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[213]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 18; p.county = 0; p.val = 1995; p.data["black"] = 15; p.data["white"] = 1865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[214]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 16; p.county = 0; p.val = 1330; p.data["black"] = 40; p.data["white"] = 1255; p.data["r"] = 159; p.data["d"] = 507; p.data["d16"] = 143; p.data["r16"] = 649;
points[215]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 18; p.county = 0; p.val = 1240; p.data["black"] = 165; p.data["white"] = 1050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[216]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 17; p.county = 0; p.val = 835; p.data["black"] = 30; p.data["white"] = 805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[217]=p;}
if (1==1){ Point p;
p.x = 3; p.y = 16; p.county = 0; p.val = 960; p.data["black"] = 0; p.data["white"] = 960; p.data["r"] = 151; p.data["d"] = 641; p.data["d16"] = 0; p.data["r16"] = 0;
points[218]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 7; p.county = 0; p.val = 1260; p.data["black"] = 0; p.data["white"] = 1210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[219]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 16; p.county = 0; p.val = 2945; p.data["black"] = 455; p.data["white"] = 2410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 245; p.data["r16"] = 613;
points[220]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 8; p.county = 0; p.val = 4085; p.data["black"] = 810; p.data["white"] = 2860; p.data["r"] = 250; p.data["d"] = 207; p.data["d16"] = 310; p.data["r16"] = 316;
points[221]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 27; p.county = 0; p.val = 585; p.data["black"] = 270; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[222]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 38; p.county = 0; p.val = 5095; p.data["black"] = 1690; p.data["white"] = 2960; p.data["r"] = 310; p.data["d"] = 239; p.data["d16"] = 337; p.data["r16"] = 353;
points[223]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 40; p.county = 0; p.val = 6115; p.data["black"] = 4670; p.data["white"] = 1230; p.data["r"] = 801; p.data["d"] = 204; p.data["d16"] = 0; p.data["r16"] = 0;
points[224]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 8; p.county = 0; p.val = 2575; p.data["black"] = 705; p.data["white"] = 1565; p.data["r"] = 410; p.data["d"] = 267; p.data["d16"] = 405; p.data["r16"] = 429;
points[225]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 0; p.val = 8320; p.data["black"] = 1595; p.data["white"] = 6310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[226]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 6; p.county = 0; p.val = 3320; p.data["black"] = 480; p.data["white"] = 2575; p.data["r"] = 384; p.data["d"] = 517; p.data["d16"] = 375; p.data["r16"] = 742;
points[227]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 8; p.county = 0; p.val = 1970; p.data["black"] = 395; p.data["white"] = 1500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[228]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 51; p.county = 0; p.val = 1320; p.data["black"] = 890; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 641; p.data["r16"] = 95;
points[229]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 32; p.county = 0; p.val = 2260; p.data["black"] = 1835; p.data["white"] = 425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 400; p.data["r16"] = 492;
points[230]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 11; p.county = 0; p.val = 5720; p.data["black"] = 790; p.data["white"] = 4345; p.data["r"] = 290; p.data["d"] = 328; p.data["d16"] = 1234; p.data["r16"] = 1925;
points[231]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 10; p.county = 0; p.val = 10130; p.data["black"] = 2755; p.data["white"] = 6160; p.data["r"] = 738; p.data["d"] = 183; p.data["d16"] = 0; p.data["r16"] = 0;
points[232]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 11; p.county = 0; p.val = 1325; p.data["black"] = 190; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[233]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 12; p.county = 0; p.val = 3190; p.data["black"] = 340; p.data["white"] = 2770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 860; p.data["r16"] = 1340;
points[234]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 7; p.county = 0; p.val = 2555; p.data["black"] = 195; p.data["white"] = 2205; p.data["r"] = 333; p.data["d"] = 1144; p.data["d16"] = 286; p.data["r16"] = 1282;
points[235]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 8; p.county = 0; p.val = 3880; p.data["black"] = 160; p.data["white"] = 3435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[236]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 38; p.county = 0; p.val = 1945; p.data["black"] = 520; p.data["white"] = 1415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 99; p.data["r16"] = 80;
points[237]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 42; p.county = 0; p.val = 730; p.data["black"] = 525; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[238]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 40; p.county = 0; p.val = 545; p.data["black"] = 330; p.data["white"] = 220; p.data["r"] = 216; p.data["d"] = 64; p.data["d16"] = 0; p.data["r16"] = 0;
points[239]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 43; p.county = 0; p.val = 610; p.data["black"] = 365; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 23; p.data["r16"] = 146;
points[240]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 40; p.county = 0; p.val = 1235; p.data["black"] = 515; p.data["white"] = 680; p.data["r"] = 255; p.data["d"] = 859; p.data["d16"] = 292; p.data["r16"] = 1029;
points[241]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 41; p.county = 0; p.val = 580; p.data["black"] = 400; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[242]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 87; p.county = 0; p.val = 2785; p.data["black"] = 390; p.data["white"] = 1940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[243]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 88; p.county = 0; p.val = 2230; p.data["black"] = 455; p.data["white"] = 1610; p.data["r"] = 147; p.data["d"] = 111; p.data["d16"] = 0; p.data["r16"] = 0;
points[244]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 88; p.county = 0; p.val = 3825; p.data["black"] = 610; p.data["white"] = 2855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[245]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 85; p.county = 0; p.val = 1960; p.data["black"] = 1440; p.data["white"] = 475; p.data["r"] = 410; p.data["d"] = 208; p.data["d16"] = 0; p.data["r16"] = 0;
points[246]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 88; p.county = 0; p.val = 2130; p.data["black"] = 1345; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[247]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 88; p.county = 0; p.val = 680; p.data["black"] = 370; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[248]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 96; p.county = 0; p.val = 2630; p.data["black"] = 115; p.data["white"] = 2515; p.data["r"] = 372; p.data["d"] = 329; p.data["d16"] = 0; p.data["r16"] = 0;
points[249]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 96; p.county = 0; p.val = 2655; p.data["black"] = 10; p.data["white"] = 2420; p.data["r"] = 377; p.data["d"] = 309; p.data["d16"] = 0; p.data["r16"] = 0;
points[250]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 91; p.county = 0; p.val = 750; p.data["black"] = 10; p.data["white"] = 590; p.data["r"] = 1081; p.data["d"] = 1251; p.data["d16"] = 791; p.data["r16"] = 862;
points[251]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 91; p.county = 0; p.val = 1050; p.data["black"] = 450; p.data["white"] = 550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 620; p.data["r16"] = 135;
points[252]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 6; p.county = 0; p.val = 2895; p.data["black"] = 189; p.data["white"] = 2560; p.data["r"] = 624; p.data["d"] = 989; p.data["d16"] = 501; p.data["r16"] = 1110;
points[253]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 3; p.county = 0; p.val = 1330; p.data["black"] = 130; p.data["white"] = 1200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[254]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 3; p.county = 0; p.val = 575; p.data["black"] = 0; p.data["white"] = 540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 383; p.data["r16"] = 1142;
points[255]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 48; p.county = 0; p.val = 995; p.data["black"] = 255; p.data["white"] = 660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 334; p.data["r16"] = 552;
points[256]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 46; p.county = 0; p.val = 1225; p.data["black"] = 125; p.data["white"] = 965; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 455; p.data["r16"] = 850;
points[257]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 47; p.county = 0; p.val = 4205; p.data["black"] = 360; p.data["white"] = 3805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 597; p.data["r16"] = 1632;
points[258]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 48; p.county = 0; p.val = 6800; p.data["black"] = 380; p.data["white"] = 5780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[259]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 40; p.county = 0; p.val = 1610; p.data["black"] = 830; p.data["white"] = 745; p.data["r"] = 218; p.data["d"] = 98; p.data["d16"] = 626; p.data["r16"] = 379;
points[260]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 39; p.county = 0; p.val = 1695; p.data["black"] = 780; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[261]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 55; p.county = 0; p.val = 1295; p.data["black"] = 1175; p.data["white"] = 120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 861; p.data["r16"] = 35;
points[262]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 54; p.county = 0; p.val = 6410; p.data["black"] = 6045; p.data["white"] = 245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1106; p.data["r16"] = 24;
points[263]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 39; p.county = 0; p.val = 3345; p.data["black"] = 445; p.data["white"] = 2680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1398; p.data["r16"] = 560;
points[264]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 34; p.county = 0; p.val = 1650; p.data["black"] = 375; p.data["white"] = 1275; p.data["r"] = 579; p.data["d"] = 676; p.data["d16"] = 0; p.data["r16"] = 0;
points[265]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 32; p.county = 0; p.val = 705; p.data["black"] = 250; p.data["white"] = 430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 138; p.data["r16"] = 656;
points[266]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 33; p.county = 0; p.val = 2460; p.data["black"] = 1415; p.data["white"] = 1015; p.data["r"] = 218; p.data["d"] = 166; p.data["d16"] = 643; p.data["r16"] = 421;
points[267]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 34; p.county = 0; p.val = 560; p.data["black"] = 105; p.data["white"] = 455; p.data["r"] = 86; p.data["d"] = 265; p.data["d16"] = 0; p.data["r16"] = 0;
points[268]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 31; p.county = 0; p.val = 7470; p.data["black"] = 2620; p.data["white"] = 4465; p.data["r"] = 504; p.data["d"] = 569; p.data["d16"] = 0; p.data["r16"] = 0;
points[269]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 36; p.county = 0; p.val = 1425; p.data["black"] = 130; p.data["white"] = 1285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[270]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 32; p.county = 0; p.val = 1940; p.data["black"] = 350; p.data["white"] = 1505; p.data["r"] = 205; p.data["d"] = 274; p.data["d16"] = 0; p.data["r16"] = 0;
points[271]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 32; p.county = 0; p.val = 5735; p.data["black"] = 3300; p.data["white"] = 2355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 988; p.data["r16"] = 608;
points[272]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 30; p.county = 0; p.val = 3180; p.data["black"] = 990; p.data["white"] = 2040; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 147; p.data["r16"] = 502;
points[273]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 7; p.county = 0; p.val = 5610; p.data["black"] = 2915; p.data["white"] = 2230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 689; p.data["r16"] = 257;
points[274]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 8; p.county = 0; p.val = 10230; p.data["black"] = 6160; p.data["white"] = 3460; p.data["r"] = 225; p.data["d"] = 136; p.data["d16"] = 1191; p.data["r16"] = 555;
points[275]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 6; p.county = 0; p.val = 3020; p.data["black"] = 540; p.data["white"] = 2385; p.data["r"] = 391; p.data["d"] = 501; p.data["d16"] = 398; p.data["r16"] = 534;
points[276]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 5; p.county = 0; p.val = 1565; p.data["black"] = 100; p.data["white"] = 1365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[277]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 6; p.county = 0; p.val = 1130; p.data["black"] = 315; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 457; p.data["r16"] = 920;
points[278]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 7; p.county = 0; p.val = 6850; p.data["black"] = 1244; p.data["white"] = 5260; p.data["r"] = 1129; p.data["d"] = 292; p.data["d16"] = 185; p.data["r16"] = 209;
points[279]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 44; p.county = 0; p.val = 3495; p.data["black"] = 140; p.data["white"] = 3260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 625; p.data["r16"] = 1680;
points[280]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 0; p.val = 9215; p.data["black"] = 720; p.data["white"] = 7785; p.data["r"] = 534; p.data["d"] = 1100; p.data["d16"] = 857; p.data["r16"] = 1810;
points[281]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 73; p.county = 0; p.val = 8910; p.data["black"] = 3190; p.data["white"] = 5105; p.data["r"] = 417; p.data["d"] = 623; p.data["d16"] = 558; p.data["r16"] = 942;
points[282]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 74; p.county = 0; p.val = 9290; p.data["black"] = 6570; p.data["white"] = 2390; p.data["r"] = 702; p.data["d"] = 533; p.data["d16"] = 942; p.data["r16"] = 498;
points[283]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 31; p.county = 0; p.val = 5565; p.data["black"] = 5300; p.data["white"] = 200; p.data["r"] = 286; p.data["d"] = 3; p.data["d16"] = 904; p.data["r16"] = 8;
points[284]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 32; p.county = 0; p.val = 1215; p.data["black"] = 775; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[285]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 33; p.county = 0; p.val = 7250; p.data["black"] = 1720; p.data["white"] = 5065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 599; p.data["r16"] = 888;
points[286]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 14; p.county = 0; p.val = 2600; p.data["black"] = 725; p.data["white"] = 1730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[287]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 9; p.county = 0; p.val = 1105; p.data["black"] = 65; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 591; p.data["r16"] = 1487;
points[288]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 10; p.county = 0; p.val = 1805; p.data["black"] = 165; p.data["white"] = 1475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 470; p.data["r16"] = 1396;
points[289]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 15; p.county = 0; p.val = 2195; p.data["black"] = 635; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[290]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 2; p.county = 0; p.val = 1060; p.data["black"] = 95; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[291]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 4; p.county = 0; p.val = 1590; p.data["black"] = 0; p.data["white"] = 1510; p.data["r"] = 265; p.data["d"] = 1361; p.data["d16"] = 0; p.data["r16"] = 0;
points[292]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 4; p.county = 0; p.val = 4465; p.data["black"] = 400; p.data["white"] = 3900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[293]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 5; p.county = 0; p.val = 690; p.data["black"] = 140; p.data["white"] = 550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[294]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 10; p.county = 0; p.val = 1125; p.data["black"] = 160; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[295]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 3; p.county = 0; p.val = 1435; p.data["black"] = 0; p.data["white"] = 1375; p.data["r"] = 167; p.data["d"] = 760; p.data["d16"] = 0; p.data["r16"] = 0;
points[296]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 8; p.county = 0; p.val = 7660; p.data["black"] = 2095; p.data["white"] = 4805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 885; p.data["r16"] = 1647;
points[297]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 9; p.county = 0; p.val = 845; p.data["black"] = 85; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[298]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 14; p.county = 0; p.val = 700; p.data["black"] = 425; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[299]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 8; p.county = 0; p.val = 6730; p.data["black"] = 4070; p.data["white"] = 2360; p.data["r"] = 587; p.data["d"] = 271; p.data["d16"] = 630; p.data["r16"] = 318;
points[300]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 45; p.county = 0; p.val = 2545; p.data["black"] = 8; p.data["white"] = 2445; p.data["r"] = 218; p.data["d"] = 513; p.data["d16"] = 323; p.data["r16"] = 451;
points[301]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 15; p.county = 0; p.val = 1880; p.data["black"] = 625; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[302]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 16; p.county = 0; p.val = 1205; p.data["black"] = 670; p.data["white"] = 525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[303]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 16; p.county = 0; p.val = 3110; p.data["black"] = 1830; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 758; p.data["r16"] = 252;
points[304]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 13; p.county = 0; p.val = 1390; p.data["black"] = 245; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 136; p.data["r16"] = 436;
points[305]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 13; p.county = 0; p.val = 1420; p.data["black"] = 150; p.data["white"] = 1270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[306]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 32; p.county = 0; p.val = 5655; p.data["black"] = 2545; p.data["white"] = 2929; p.data["r"] = 677; p.data["d"] = 172; p.data["d16"] = 0; p.data["r16"] = 0;
points[307]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 47; p.county = 0; p.val = 1175; p.data["black"] = 190; p.data["white"] = 975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 775; p.data["r16"] = 1138;
points[308]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 9; p.county = 0; p.val = 3315; p.data["black"] = 1200; p.data["white"] = 1905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 662; p.data["r16"] = 662;
points[309]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 93; p.county = 0; p.val = 7680; p.data["black"] = 175; p.data["white"] = 7350; p.data["r"] = 628; p.data["d"] = 994; p.data["d16"] = 0; p.data["r16"] = 0;
points[310]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 93; p.county = 0; p.val = 1220; p.data["black"] = 130; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[311]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 92; p.county = 0; p.val = 4550; p.data["black"] = 140; p.data["white"] = 4310; p.data["r"] = 318; p.data["d"] = 348; p.data["d16"] = 0; p.data["r16"] = 0;
points[312]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 96; p.county = 0; p.val = 280; p.data["black"] = 0; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 238; p.data["r16"] = 420;
points[313]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 95; p.county = 0; p.val = 1580; p.data["black"] = 60; p.data["white"] = 1425; p.data["r"] = 516; p.data["d"] = 649; p.data["d16"] = 1321; p.data["r16"] = 2045;
points[314]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 3; p.county = 0; p.val = 995; p.data["black"] = 55; p.data["white"] = 865; p.data["r"] = 594; p.data["d"] = 869; p.data["d16"] = 0; p.data["r16"] = 0;
points[315]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 2; p.county = 0; p.val = 1360; p.data["black"] = 80; p.data["white"] = 1165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[316]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 1; p.county = 0; p.val = 2115; p.data["black"] = 145; p.data["white"] = 1895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[317]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 7; p.county = 0; p.val = 2155; p.data["black"] = 235; p.data["white"] = 1910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[318]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 6; p.county = 0; p.val = 2070; p.data["black"] = 1060; p.data["white"] = 1010; p.data["r"] = 450; p.data["d"] = 371; p.data["d16"] = 0; p.data["r16"] = 0;
points[319]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 5; p.county = 0; p.val = 2210; p.data["black"] = 40; p.data["white"] = 2150; p.data["r"] = 304; p.data["d"] = 641; p.data["d16"] = 0; p.data["r16"] = 0;
points[320]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 51; p.county = 0; p.val = 805; p.data["black"] = 0; p.data["white"] = 805; p.data["r"] = 215; p.data["d"] = 431; p.data["d16"] = 0; p.data["r16"] = 0;
points[321]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 36; p.county = 0; p.val = 13715; p.data["black"] = 7840; p.data["white"] = 5085; p.data["r"] = 362; p.data["d"] = 28; p.data["d16"] = 0; p.data["r16"] = 0;
points[322]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 43; p.county = 0; p.val = 600; p.data["black"] = 15; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[323]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 38; p.county = 0; p.val = 3440; p.data["black"] = 150; p.data["white"] = 3140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 314; p.data["r16"] = 801;
points[324]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 41; p.county = 0; p.val = 5170; p.data["black"] = 710; p.data["white"] = 3945; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 497; p.data["r16"] = 1474;
points[325]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 40; p.county = 0; p.val = 3520; p.data["black"] = 670; p.data["white"] = 2695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1511; p.data["r16"] = 748;
points[326]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 41; p.county = 0; p.val = 2205; p.data["black"] = 4; p.data["white"] = 2130; p.data["r"] = 407; p.data["d"] = 1461; p.data["d16"] = 0; p.data["r16"] = 0;
points[327]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 38; p.county = 0; p.val = 6775; p.data["black"] = 450; p.data["white"] = 5805; p.data["r"] = 1094; p.data["d"] = 1940; p.data["d16"] = 695; p.data["r16"] = 1861;
points[328]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 20; p.county = 0; p.val = 1055; p.data["black"] = 755; p.data["white"] = 220; p.data["r"] = 504; p.data["d"] = 146; p.data["d16"] = 0; p.data["r16"] = 0;
points[329]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 42; p.county = 0; p.val = 1445; p.data["black"] = 755; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[330]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 42; p.county = 0; p.val = 2405; p.data["black"] = 270; p.data["white"] = 2035; p.data["r"] = 591; p.data["d"] = 1374; p.data["d16"] = 457; p.data["r16"] = 886;
points[331]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 37; p.county = 0; p.val = 4830; p.data["black"] = 405; p.data["white"] = 4145; p.data["r"] = 550; p.data["d"] = 978; p.data["d16"] = 578; p.data["r16"] = 466;
points[332]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 45; p.county = 0; p.val = 1400; p.data["black"] = 335; p.data["white"] = 1055; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[333]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 39; p.county = 0; p.val = 1915; p.data["black"] = 15; p.data["white"] = 1810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 258; p.data["r16"] = 1300;
points[334]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 47; p.county = 0; p.val = 805; p.data["black"] = 305; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[335]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 44; p.county = 0; p.val = 1950; p.data["black"] = 210; p.data["white"] = 1640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[336]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 43; p.county = 0; p.val = 3875; p.data["black"] = 665; p.data["white"] = 3165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[337]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 45; p.county = 0; p.val = 890; p.data["black"] = 10; p.data["white"] = 865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 326; p.data["r16"] = 896;
points[338]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 46; p.county = 0; p.val = 1895; p.data["black"] = 50; p.data["white"] = 1640; p.data["r"] = 183; p.data["d"] = 522; p.data["d16"] = 0; p.data["r16"] = 0;
points[339]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 44; p.county = 0; p.val = 1950; p.data["black"] = 165; p.data["white"] = 1675; p.data["r"] = 145; p.data["d"] = 530; p.data["d16"] = 0; p.data["r16"] = 0;
points[340]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 42; p.county = 0; p.val = 1415; p.data["black"] = 185; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[341]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 39; p.county = 0; p.val = 6525; p.data["black"] = 815; p.data["white"] = 5270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[342]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 42; p.county = 0; p.val = 1790; p.data["black"] = 50; p.data["white"] = 1730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 327; p.data["r16"] = 784;
points[343]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 38; p.county = 0; p.val = 4640; p.data["black"] = 175; p.data["white"] = 4190; p.data["r"] = 471; p.data["d"] = 956; p.data["d16"] = 549; p.data["r16"] = 1556;
points[344]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 43; p.county = 0; p.val = 2800; p.data["black"] = 105; p.data["white"] = 2605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[345]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 42; p.county = 0; p.val = 4680; p.data["black"] = 1200; p.data["white"] = 3345; p.data["r"] = 1049; p.data["d"] = 1232; p.data["d16"] = 0; p.data["r16"] = 0;
points[346]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 42; p.county = 0; p.val = 1015; p.data["black"] = 135; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[347]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 37; p.county = 0; p.val = 930; p.data["black"] = 0; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[348]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 34; p.county = 0; p.val = 1470; p.data["black"] = 0; p.data["white"] = 1425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[349]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 0; p.val = 3415; p.data["black"] = 150; p.data["white"] = 3160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[350]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 41; p.county = 0; p.val = 925; p.data["black"] = 45; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[351]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 36; p.county = 0; p.val = 3785; p.data["black"] = 285; p.data["white"] = 3295; p.data["r"] = 516; p.data["d"] = 654; p.data["d16"] = 1479; p.data["r16"] = 2441;
points[352]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 38; p.county = 0; p.val = 1625; p.data["black"] = 0; p.data["white"] = 1605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[353]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 43; p.county = 0; p.val = 2645; p.data["black"] = 215; p.data["white"] = 2295; p.data["r"] = 226; p.data["d"] = 435; p.data["d16"] = 0; p.data["r16"] = 0;
points[354]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 41; p.county = 0; p.val = 1720; p.data["black"] = 65; p.data["white"] = 1580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[355]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 46; p.county = 0; p.val = 275; p.data["black"] = 105; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[356]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 46; p.county = 0; p.val = 1230; p.data["black"] = 360; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[357]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 41; p.county = 0; p.val = 3755; p.data["black"] = 455; p.data["white"] = 3170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 228; p.data["r16"] = 954;
points[358]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 33; p.county = 0; p.val = 1380; p.data["black"] = 0; p.data["white"] = 1330; p.data["r"] = 334; p.data["d"] = 1065; p.data["d16"] = 0; p.data["r16"] = 0;
points[359]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 41; p.county = 0; p.val = 1590; p.data["black"] = 1235; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[360]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 71; p.county = 0; p.val = 875; p.data["black"] = 285; p.data["white"] = 585; p.data["r"] = 26; p.data["d"] = 22; p.data["d16"] = 35; p.data["r16"] = 22;
points[361]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 47; p.county = 0; p.val = 4110; p.data["black"] = 870; p.data["white"] = 2940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 478; p.data["r16"] = 199;
points[362]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 2; p.county = 0; p.val = 545; p.data["black"] = 50; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 303; p.data["r16"] = 1353;
points[363]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 31; p.county = 0; p.val = 4575; p.data["black"] = 2005; p.data["white"] = 2295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 788; p.data["r16"] = 6;
points[364]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 32; p.county = 0; p.val = 7560; p.data["black"] = 2130; p.data["white"] = 5150; p.data["r"] = 615; p.data["d"] = 898; p.data["d16"] = 184; p.data["r16"] = 362;
points[365]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 7; p.county = 0; p.val = 6255; p.data["black"] = 1370; p.data["white"] = 4580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 628; p.data["r16"] = 716;
points[366]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 77; p.county = 0; p.val = 1555; p.data["black"] = 1220; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[367]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 72; p.county = 0; p.val = 590; p.data["black"] = 25; p.data["white"] = 565; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[368]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 78; p.county = 0; p.val = 830; p.data["black"] = 165; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[369]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 75; p.county = 0; p.val = 810; p.data["black"] = 515; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 49; p.data["r16"] = 124;
points[370]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 81; p.county = 0; p.val = 470; p.data["black"] = 360; p.data["white"] = 110; p.data["r"] = 862; p.data["d"] = 252; p.data["d16"] = 1210; p.data["r16"] = 276;
points[371]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 80; p.county = 0; p.val = 915; p.data["black"] = 505; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 137; p.data["r16"] = 116;
points[372]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 78; p.county = 0; p.val = 845; p.data["black"] = 560; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[373]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 76; p.county = 0; p.val = 425; p.data["black"] = 205; p.data["white"] = 220; p.data["r"] = 274; p.data["d"] = 161; p.data["d16"] = 0; p.data["r16"] = 0;
points[374]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 78; p.county = 0; p.val = 1915; p.data["black"] = 1385; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[375]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 44; p.county = 0; p.val = 1395; p.data["black"] = 520; p.data["white"] = 775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[376]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 75; p.county = 0; p.val = 1930; p.data["black"] = 1110; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[377]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 6; p.county = 0; p.val = 3150; p.data["black"] = 865; p.data["white"] = 2155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 913; p.data["r16"] = 1166;
points[378]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 6; p.county = 0; p.val = 5755; p.data["black"] = 2045; p.data["white"] = 3245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 540; p.data["r16"] = 280;
points[379]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 52; p.county = 0; p.val = 5500; p.data["black"] = 940; p.data["white"] = 4460; p.data["r"] = 620; p.data["d"] = 1419; p.data["d16"] = 422; p.data["r16"] = 1005;
points[380]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 50; p.county = 0; p.val = 1845; p.data["black"] = 985; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[381]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 53; p.county = 0; p.val = 835; p.data["black"] = 160; p.data["white"] = 655; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[382]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 47; p.county = 0; p.val = 1515; p.data["black"] = 620; p.data["white"] = 895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[383]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 49; p.county = 0; p.val = 990; p.data["black"] = 90; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[384]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 53; p.county = 0; p.val = 5000; p.data["black"] = 875; p.data["white"] = 3905; p.data["r"] = 289; p.data["d"] = 439; p.data["d16"] = 419; p.data["r16"] = 556;
points[385]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 53; p.county = 0; p.val = 3590; p.data["black"] = 500; p.data["white"] = 2855; p.data["r"] = 120; p.data["d"] = 225; p.data["d16"] = 213; p.data["r16"] = 468;
points[386]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 57; p.county = 0; p.val = 490; p.data["black"] = 270; p.data["white"] = 220; p.data["r"] = 284; p.data["d"] = 878; p.data["d16"] = 524; p.data["r16"] = 563;
points[387]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 49; p.county = 0; p.val = 1630; p.data["black"] = 145; p.data["white"] = 1415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 231; p.data["r16"] = 761;
points[388]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 49; p.county = 0; p.val = 705; p.data["black"] = 175; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 595; p.data["r16"] = 757;
points[389]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 50; p.county = 0; p.val = 1205; p.data["black"] = 1050; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[390]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 58; p.county = 0; p.val = 930; p.data["black"] = 140; p.data["white"] = 760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[391]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 56; p.county = 0; p.val = 855; p.data["black"] = 260; p.data["white"] = 525; p.data["r"] = 225; p.data["d"] = 208; p.data["d16"] = 257; p.data["r16"] = 309;
points[392]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 50; p.county = 0; p.val = 1050; p.data["black"] = 210; p.data["white"] = 840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 117; p.data["r16"] = 348;
points[393]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 54; p.county = 0; p.val = 5960; p.data["black"] = 445; p.data["white"] = 5245; p.data["r"] = 197; p.data["d"] = 270; p.data["d16"] = 483; p.data["r16"] = 1035;
points[394]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 67; p.county = 0; p.val = 1345; p.data["black"] = 710; p.data["white"] = 390; p.data["r"] = 206; p.data["d"] = 174; p.data["d16"] = 256; p.data["r16"] = 217;
points[395]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 52; p.county = 0; p.val = 6740; p.data["black"] = 1230; p.data["white"] = 5270; p.data["r"] = 178; p.data["d"] = 669; p.data["d16"] = 0; p.data["r16"] = 0;
points[396]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 53; p.county = 0; p.val = 5530; p.data["black"] = 1040; p.data["white"] = 4125; p.data["r"] = 317; p.data["d"] = 302; p.data["d16"] = 547; p.data["r16"] = 646;
points[397]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 57; p.county = 0; p.val = 1685; p.data["black"] = 910; p.data["white"] = 765; p.data["r"] = 457; p.data["d"] = 359; p.data["d16"] = 0; p.data["r16"] = 0;
points[398]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 57; p.county = 0; p.val = 2255; p.data["black"] = 800; p.data["white"] = 1325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 150; p.data["r16"] = 528;
points[399]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 58; p.county = 0; p.val = 3325; p.data["black"] = 2430; p.data["white"] = 855; p.data["r"] = 449; p.data["d"] = 64; p.data["d16"] = 623; p.data["r16"] = 10;
points[400]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 59; p.county = 0; p.val = 1280; p.data["black"] = 295; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[401]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 56; p.county = 0; p.val = 1700; p.data["black"] = 315; p.data["white"] = 1370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[402]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 60; p.county = 0; p.val = 1450; p.data["black"] = 325; p.data["white"] = 1060; p.data["r"] = 467; p.data["d"] = 668; p.data["d16"] = 111; p.data["r16"] = 226;
points[403]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 15; p.county = 0; p.val = 1905; p.data["black"] = 445; p.data["white"] = 1440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[404]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 14; p.county = 0; p.val = 1435; p.data["black"] = 575; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 86; p.data["r16"] = 409;
points[405]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 16; p.county = 0; p.val = 670; p.data["black"] = 220; p.data["white"] = 450; p.data["r"] = 162; p.data["d"] = 315; p.data["d16"] = 0; p.data["r16"] = 0;
points[406]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 12; p.county = 0; p.val = 1385; p.data["black"] = 215; p.data["white"] = 1150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[407]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 69; p.county = 0; p.val = 7875; p.data["black"] = 2115; p.data["white"] = 5170; p.data["r"] = 440; p.data["d"] = 377; p.data["d16"] = 0; p.data["r16"] = 0;
points[408]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 64; p.county = 0; p.val = 945; p.data["black"] = 420; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[409]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 61; p.county = 0; p.val = 460; p.data["black"] = 245; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[410]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 70; p.county = 0; p.val = 11325; p.data["black"] = 1835; p.data["white"] = 8860; p.data["r"] = 341; p.data["d"] = 477; p.data["d16"] = 1265; p.data["r16"] = 1089;
points[411]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 71; p.county = 0; p.val = 11070; p.data["black"] = 1290; p.data["white"] = 9115; p.data["r"] = 1066; p.data["d"] = 1887; p.data["d16"] = 1365; p.data["r16"] = 2677;
points[412]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 65; p.county = 0; p.val = 945; p.data["black"] = 615; p.data["white"] = 315; p.data["r"] = 128; p.data["d"] = 215; p.data["d16"] = 209; p.data["r16"] = 299;
points[413]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 67; p.county = 0; p.val = 1410; p.data["black"] = 610; p.data["white"] = 745; p.data["r"] = 59; p.data["d"] = 331; p.data["d16"] = 0; p.data["r16"] = 0;
points[414]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 62; p.county = 0; p.val = 1070; p.data["black"] = 475; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 443; p.data["r16"] = 510;
points[415]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 62; p.county = 0; p.val = 705; p.data["black"] = 520; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[416]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 63; p.county = 0; p.val = 1065; p.data["black"] = 295; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[417]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 66; p.county = 0; p.val = 1300; p.data["black"] = 525; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[418]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 35; p.county = 0; p.val = 855; p.data["black"] = 40; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[419]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 73; p.county = 0; p.val = 670; p.data["black"] = 335; p.data["white"] = 325; p.data["r"] = 525; p.data["d"] = 1091; p.data["d16"] = 579; p.data["r16"] = 639;
points[420]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 70; p.county = 0; p.val = 3085; p.data["black"] = 305; p.data["white"] = 2265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1063; p.data["r16"] = 1809;
points[421]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 68; p.county = 0; p.val = 2845; p.data["black"] = 615; p.data["white"] = 2005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[422]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 69; p.county = 0; p.val = 8270; p.data["black"] = 1695; p.data["white"] = 6080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[423]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 63; p.county = 0; p.val = 1520; p.data["black"] = 850; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[424]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 64; p.county = 0; p.val = 4270; p.data["black"] = 1335; p.data["white"] = 2770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[425]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 71; p.county = 0; p.val = 1315; p.data["black"] = 65; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[426]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 73; p.county = 0; p.val = 1735; p.data["black"] = 35; p.data["white"] = 1480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[427]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 66; p.county = 0; p.val = 1975; p.data["black"] = 1035; p.data["white"] = 760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[428]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 26; p.county = 0; p.val = 475; p.data["black"] = 135; p.data["white"] = 335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[429]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 31; p.county = 0; p.val = 1095; p.data["black"] = 170; p.data["white"] = 895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[430]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 32; p.county = 0; p.val = 500; p.data["black"] = 110; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[431]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 33; p.county = 0; p.val = 940; p.data["black"] = 170; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[432]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 35; p.county = 0; p.val = 1025; p.data["black"] = 0; p.data["white"] = 975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[433]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 31; p.county = 0; p.val = 1315; p.data["black"] = 440; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 305; p.data["r16"] = 406;
points[434]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 31; p.county = 0; p.val = 1345; p.data["black"] = 450; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 31; p.data["r16"] = 215;
points[435]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 27; p.county = 0; p.val = 1285; p.data["black"] = 725; p.data["white"] = 560; p.data["r"] = 353; p.data["d"] = 270; p.data["d16"] = 110; p.data["r16"] = 248;
points[436]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 30; p.county = 0; p.val = 1040; p.data["black"] = 525; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 129; p.data["r16"] = 253;
points[437]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 29; p.county = 0; p.val = 2525; p.data["black"] = 1370; p.data["white"] = 975; p.data["r"] = 851; p.data["d"] = 429; p.data["d16"] = 632; p.data["r16"] = 321;
points[438]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 95; p.county = 0; p.val = 1090; p.data["black"] = 120; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[439]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 90; p.county = 0; p.val = 4895; p.data["black"] = 690; p.data["white"] = 3150; p.data["r"] = 554; p.data["d"] = 787; p.data["d16"] = 254; p.data["r16"] = 510;
points[440]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 92; p.county = 0; p.val = 1845; p.data["black"] = 0; p.data["white"] = 1820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 397; p.data["r16"] = 721;
points[441]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 91; p.county = 0; p.val = 285; p.data["black"] = 0; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[442]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 93; p.county = 0; p.val = 2695; p.data["black"] = 30; p.data["white"] = 2395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[443]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 95; p.county = 0; p.val = 715; p.data["black"] = 25; p.data["white"] = 630; p.data["r"] = 387; p.data["d"] = 338; p.data["d16"] = 0; p.data["r16"] = 0;
points[444]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 98; p.county = 0; p.val = 375; p.data["black"] = 0; p.data["white"] = 375; p.data["r"] = 110; p.data["d"] = 188; p.data["d16"] = 0; p.data["r16"] = 0;
points[445]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 97; p.county = 0; p.val = 2835; p.data["black"] = 85; p.data["white"] = 2690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 602; p.data["r16"] = 618;
points[446]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 95; p.county = 0; p.val = 6655; p.data["black"] = 760; p.data["white"] = 5550; p.data["r"] = 296; p.data["d"] = 347; p.data["d16"] = 631; p.data["r16"] = 918;
points[447]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 94; p.county = 0; p.val = 3370; p.data["black"] = 400; p.data["white"] = 2775; p.data["r"] = 311; p.data["d"] = 442; p.data["d16"] = 0; p.data["r16"] = 0;
points[448]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 84; p.county = 0; p.val = 1210; p.data["black"] = 570; p.data["white"] = 610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[449]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 86; p.county = 0; p.val = 1220; p.data["black"] = 640; p.data["white"] = 530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[450]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 90; p.county = 0; p.val = 2435; p.data["black"] = 75; p.data["white"] = 2270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[451]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 86; p.county = 0; p.val = 1880; p.data["black"] = 210; p.data["white"] = 1550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[452]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 86; p.county = 0; p.val = 670; p.data["black"] = 80; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[453]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 88; p.county = 0; p.val = 3110; p.data["black"] = 1155; p.data["white"] = 1810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 195; p.data["r16"] = 386;
points[454]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 87; p.county = 0; p.val = 285; p.data["black"] = 150; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[455]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 89; p.county = 0; p.val = 7820; p.data["black"] = 1960; p.data["white"] = 5290; p.data["r"] = 328; p.data["d"] = 397; p.data["d16"] = 287; p.data["r16"] = 418;
points[456]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 33; p.county = 0; p.val = 1415; p.data["black"] = 1230; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[457]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 90; p.county = 0; p.val = 1620; p.data["black"] = 1415; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[458]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 89; p.county = 0; p.val = 3865; p.data["black"] = 1420; p.data["white"] = 2225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 512; p.data["r16"] = 129;
points[459]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 91; p.county = 0; p.val = 1040; p.data["black"] = 0; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[460]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 97; p.county = 0; p.val = 2255; p.data["black"] = 4; p.data["white"] = 2190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 801; p.data["r16"] = 1027;
points[461]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 42; p.county = 0; p.val = 3795; p.data["black"] = 2725; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[462]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 36; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[463]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 34; p.county = 0; p.val = 745; p.data["black"] = 520; p.data["white"] = 205; p.data["r"] = 314; p.data["d"] = 306; p.data["d16"] = 0; p.data["r16"] = 0;
points[464]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 41; p.county = 0; p.val = 925; p.data["black"] = 140; p.data["white"] = 765; p.data["r"] = 56; p.data["d"] = 353; p.data["d16"] = 0; p.data["r16"] = 0;
points[465]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 38; p.county = 0; p.val = 655; p.data["black"] = 105; p.data["white"] = 535; p.data["r"] = 147; p.data["d"] = 306; p.data["d16"] = 62; p.data["r16"] = 338;
points[466]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 35; p.county = 0; p.val = 830; p.data["black"] = 325; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[467]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 37; p.county = 0; p.val = 3080; p.data["black"] = 15; p.data["white"] = 2970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[468]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 37; p.county = 0; p.val = 1715; p.data["black"] = 0; p.data["white"] = 1630; p.data["r"] = 335; p.data["d"] = 995; p.data["d16"] = 253; p.data["r16"] = 1198;
points[469]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 35; p.county = 0; p.val = 2465; p.data["black"] = 10; p.data["white"] = 2375; p.data["r"] = 497; p.data["d"] = 1280; p.data["d16"] = 0; p.data["r16"] = 0;
points[470]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 35; p.county = 0; p.val = 3025; p.data["black"] = 0; p.data["white"] = 2970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[471]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 35; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 275; p.data["r16"] = 892;
points[472]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 36; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[473]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 26; p.county = 0; p.val = 1485; p.data["black"] = 720; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[474]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 28; p.county = 0; p.val = 2585; p.data["black"] = 1120; p.data["white"] = 1435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[475]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 37; p.county = 0; p.val = 1580; p.data["black"] = 480; p.data["white"] = 1030; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 61; p.data["r16"] = 112;
points[476]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 31; p.county = 0; p.val = 1260; p.data["black"] = 1005; p.data["white"] = 250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 286; p.data["r16"] = 207;
points[477]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 74; p.county = 0; p.val = 580; p.data["black"] = 75; p.data["white"] = 500; p.data["r"] = 171; p.data["d"] = 161; p.data["d16"] = 317; p.data["r16"] = 304;
points[478]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 75; p.county = 0; p.val = 675; p.data["black"] = 305; p.data["white"] = 370; p.data["r"] = 681; p.data["d"] = 312; p.data["d16"] = 0; p.data["r16"] = 0;
points[479]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 80; p.county = 0; p.val = 890; p.data["black"] = 675; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[480]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 48; p.county = 0; p.val = 3115; p.data["black"] = 635; p.data["white"] = 2230; p.data["r"] = 316; p.data["d"] = 302; p.data["d16"] = 0; p.data["r16"] = 0;
points[481]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 49; p.county = 0; p.val = 2065; p.data["black"] = 100; p.data["white"] = 1775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 799; p.data["r16"] = 1544;
points[482]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 49; p.county = 0; p.val = 4275; p.data["black"] = 365; p.data["white"] = 3570; p.data["r"] = 322; p.data["d"] = 551; p.data["d16"] = 0; p.data["r16"] = 0;
points[483]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 47; p.county = 0; p.val = 6235; p.data["black"] = 545; p.data["white"] = 5345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 678; p.data["r16"] = 1508;
points[484]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 53; p.county = 0; p.val = 1360; p.data["black"] = 370; p.data["white"] = 870; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[485]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 51; p.county = 0; p.val = 1630; p.data["black"] = 965; p.data["white"] = 660; p.data["r"] = 485; p.data["d"] = 779; p.data["d16"] = 0; p.data["r16"] = 0;
points[486]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 44; p.county = 0; p.val = 2020; p.data["black"] = 235; p.data["white"] = 1740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[487]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 33; p.county = 0; p.val = 3705; p.data["black"] = 1265; p.data["white"] = 2385; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[488]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 34; p.county = 0; p.val = 2025; p.data["black"] = 1055; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[489]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 34; p.county = 0; p.val = 2965; p.data["black"] = 1610; p.data["white"] = 1250; p.data["r"] = 755; p.data["d"] = 190; p.data["d16"] = 0; p.data["r16"] = 0;
points[490]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 33; p.county = 0; p.val = 1725; p.data["black"] = 805; p.data["white"] = 820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[491]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 31; p.county = 0; p.val = 5040; p.data["black"] = 740; p.data["white"] = 4020; p.data["r"] = 209; p.data["d"] = 406; p.data["d16"] = 495; p.data["r16"] = 628;
points[492]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 33; p.county = 0; p.val = 615; p.data["black"] = 310; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 292; p.data["r16"] = 239;
points[493]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 7; p.county = 0; p.val = 2555; p.data["black"] = 375; p.data["white"] = 2045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 540; p.data["r16"] = 1627;
points[494]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 8; p.county = 0; p.val = 3390; p.data["black"] = 1480; p.data["white"] = 1575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[495]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 15; p.county = 0; p.val = 340; p.data["black"] = 45; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[496]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 7; p.county = 0; p.val = 840; p.data["black"] = 4; p.data["white"] = 800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[497]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 2; p.county = 0; p.val = 1880; p.data["black"] = 35; p.data["white"] = 1800; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[498]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 1; p.county = 0; p.val = 1300; p.data["black"] = 15; p.data["white"] = 1250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[499]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 2; p.county = 0; p.val = 1090; p.data["black"] = 15; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[500]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 9; p.county = 0; p.val = 1455; p.data["black"] = 255; p.data["white"] = 1145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[501]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 5; p.county = 0; p.val = 2005; p.data["black"] = 275; p.data["white"] = 1590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 299; p.data["r16"] = 619;
points[502]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 6; p.county = 0; p.val = 3870; p.data["black"] = 1300; p.data["white"] = 2330; p.data["r"] = 318; p.data["d"] = 264; p.data["d16"] = 0; p.data["r16"] = 0;
points[503]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 7; p.county = 0; p.val = 2035; p.data["black"] = 230; p.data["white"] = 1235; p.data["r"] = 758; p.data["d"] = 881; p.data["d16"] = 0; p.data["r16"] = 0;
points[504]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 9; p.county = 0; p.val = 3850; p.data["black"] = 565; p.data["white"] = 2975; p.data["r"] = 881; p.data["d"] = 1257; p.data["d16"] = 0; p.data["r16"] = 0;
points[505]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 9; p.county = 0; p.val = 5820; p.data["black"] = 2560; p.data["white"] = 3025; p.data["r"] = 929; p.data["d"] = 972; p.data["d16"] = 0; p.data["r16"] = 0;
points[506]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 10; p.county = 0; p.val = 2010; p.data["black"] = 170; p.data["white"] = 1760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[507]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 42; p.county = 0; p.val = 3230; p.data["black"] = 915; p.data["white"] = 2225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 205; p.data["r16"] = 442;
points[508]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 29; p.county = 0; p.val = 1135; p.data["black"] = 345; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[509]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 0; p.val = 1250; p.data["black"] = 745; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[510]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 24; p.county = 0; p.val = 830; p.data["black"] = 460; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[511]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 29; p.county = 0; p.val = 1350; p.data["black"] = 875; p.data["white"] = 480; p.data["r"] = 463; p.data["d"] = 186; p.data["d16"] = 596; p.data["r16"] = 277;
points[512]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 31; p.county = 0; p.val = 970; p.data["black"] = 430; p.data["white"] = 540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 426; p.data["r16"] = 536;
points[513]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 0; p.val = 990; p.data["black"] = 210; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[514]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 26; p.county = 0; p.val = 520; p.data["black"] = 425; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[515]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 27; p.county = 0; p.val = 730; p.data["black"] = 255; p.data["white"] = 475; p.data["r"] = 566; p.data["d"] = 706; p.data["d16"] = 0; p.data["r16"] = 0;
points[516]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 24; p.county = 0; p.val = 740; p.data["black"] = 50; p.data["white"] = 675; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[517]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 26; p.county = 0; p.val = 1655; p.data["black"] = 200; p.data["white"] = 1435; p.data["r"] = 179; p.data["d"] = 447; p.data["d16"] = 0; p.data["r16"] = 0;
points[518]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 31; p.county = 0; p.val = 1335; p.data["black"] = 575; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[519]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 42; p.county = 0; p.val = 775; p.data["black"] = 665; p.data["white"] = 40; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[520]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 18; p.county = 0; p.val = 1610; p.data["black"] = 375; p.data["white"] = 1155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 290; p.data["r16"] = 848;
points[521]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 21; p.county = 0; p.val = 1125; p.data["black"] = 0; p.data["white"] = 1125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[522]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 20; p.county = 0; p.val = 3495; p.data["black"] = 540; p.data["white"] = 2885; p.data["r"] = 470; p.data["d"] = 952; p.data["d16"] = 0; p.data["r16"] = 0;
points[523]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 21; p.county = 0; p.val = 1885; p.data["black"] = 350; p.data["white"] = 1510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[524]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 53; p.county = 0; p.val = 1080; p.data["black"] = 85; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[525]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 53; p.county = 0; p.val = 1255; p.data["black"] = 620; p.data["white"] = 555; p.data["r"] = 255; p.data["d"] = 252; p.data["d16"] = 0; p.data["r16"] = 0;
points[526]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 57; p.county = 0; p.val = 690; p.data["black"] = 400; p.data["white"] = 245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 647; p.data["r16"] = 370;
points[527]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 57; p.county = 0; p.val = 610; p.data["black"] = 445; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[528]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 52; p.county = 0; p.val = 1305; p.data["black"] = 925; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[529]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 51; p.county = 0; p.val = 1390; p.data["black"] = 880; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[530]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 52; p.county = 0; p.val = 1650; p.data["black"] = 1490; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[531]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 56; p.county = 0; p.val = 1145; p.data["black"] = 300; p.data["white"] = 830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[532]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 32; p.county = 0; p.val = 8520; p.data["black"] = 4250; p.data["white"] = 3545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1020; p.data["r16"] = 860;
points[533]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 33; p.county = 0; p.val = 9525; p.data["black"] = 5995; p.data["white"] = 2600; p.data["r"] = 2312; p.data["d"] = 558; p.data["d16"] = 1060; p.data["r16"] = 296;
points[534]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 39; p.county = 0; p.val = 7215; p.data["black"] = 2010; p.data["white"] = 4960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 981; p.data["r16"] = 1032;
points[535]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 33; p.county = 0; p.val = 4285; p.data["black"] = 1635; p.data["white"] = 2480; p.data["r"] = 1210; p.data["d"] = 565; p.data["d16"] = 0; p.data["r16"] = 0;
points[536]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 32; p.county = 0; p.val = 6280; p.data["black"] = 2860; p.data["white"] = 3040; p.data["r"] = 1780; p.data["d"] = 1446; p.data["d16"] = 0; p.data["r16"] = 0;
points[537]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 34; p.county = 0; p.val = 2255; p.data["black"] = 895; p.data["white"] = 875; p.data["r"] = 564; p.data["d"] = 424; p.data["d16"] = 0; p.data["r16"] = 0;
points[538]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 33; p.county = 0; p.val = 1670; p.data["black"] = 45; p.data["white"] = 1580; p.data["r"] = 1029; p.data["d"] = 1273; p.data["d16"] = 0; p.data["r16"] = 0;
points[539]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 35; p.county = 0; p.val = 7005; p.data["black"] = 2945; p.data["white"] = 3445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[540]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 39; p.county = 0; p.val = 7925; p.data["black"] = 4095; p.data["white"] = 3410; p.data["r"] = 1896; p.data["d"] = 829; p.data["d16"] = 830; p.data["r16"] = 277;
points[541]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 40; p.county = 0; p.val = 2100; p.data["black"] = 1725; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[542]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 34; p.county = 0; p.val = 2705; p.data["black"] = 705; p.data["white"] = 1770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 839; p.data["r16"] = 637;
points[543]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 64; p.county = 0; p.val = 945; p.data["black"] = 475; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[544]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 21; p.county = 0; p.val = 5360; p.data["black"] = 945; p.data["white"] = 4250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 467; p.data["r16"] = 1110;
points[545]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 22; p.county = 0; p.val = 6135; p.data["black"] = 3080; p.data["white"] = 2775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[546]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 15; p.county = 0; p.val = 1730; p.data["black"] = 160; p.data["white"] = 1490; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 128; p.data["r16"] = 455;
points[547]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 70; p.county = 0; p.val = 1890; p.data["black"] = 750; p.data["white"] = 1085; p.data["r"] = 253; p.data["d"] = 344; p.data["d16"] = 0; p.data["r16"] = 0;
points[548]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 66; p.county = 0; p.val = 810; p.data["black"] = 245; p.data["white"] = 555; p.data["r"] = 265; p.data["d"] = 265; p.data["d16"] = 299; p.data["r16"] = 363;
points[549]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 64; p.county = 0; p.val = 1125; p.data["black"] = 520; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[550]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 15; p.county = 0; p.val = 4400; p.data["black"] = 2065; p.data["white"] = 2275; p.data["r"] = 311; p.data["d"] = 185; p.data["d16"] = 505; p.data["r16"] = 240;
points[551]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 25; p.county = 0; p.val = 2745; p.data["black"] = 1640; p.data["white"] = 1060; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[552]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 44; p.county = 0; p.val = 1440; p.data["black"] = 935; p.data["white"] = 480; p.data["r"] = 432; p.data["d"] = 253; p.data["d16"] = 0; p.data["r16"] = 0;
points[553]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 47; p.county = 0; p.val = 1445; p.data["black"] = 680; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[554]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 47; p.county = 0; p.val = 1200; p.data["black"] = 565; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[555]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 45; p.county = 0; p.val = 1025; p.data["black"] = 295; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[556]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 43; p.county = 0; p.val = 1080; p.data["black"] = 610; p.data["white"] = 470; p.data["r"] = 59; p.data["d"] = 65; p.data["d16"] = 528; p.data["r16"] = 393;
points[557]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 46; p.county = 0; p.val = 2530; p.data["black"] = 1335; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[558]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 44; p.county = 0; p.val = 905; p.data["black"] = 660; p.data["white"] = 245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 238; p.data["r16"] = 382;
points[559]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 45; p.county = 0; p.val = 1090; p.data["black"] = 330; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[560]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 10; p.county = 0; p.val = 960; p.data["black"] = 50; p.data["white"] = 905; p.data["r"] = 148; p.data["d"] = 365; p.data["d16"] = 0; p.data["r16"] = 0;
points[561]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 14; p.county = 0; p.val = 840; p.data["black"] = 45; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[562]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 12; p.county = 0; p.val = 700; p.data["black"] = 220; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[563]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 19; p.county = 0; p.val = 850; p.data["black"] = 290; p.data["white"] = 540; p.data["r"] = 144; p.data["d"] = 102; p.data["d16"] = 0; p.data["r16"] = 0;
points[564]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 11; p.county = 0; p.val = 780; p.data["black"] = 195; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[565]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 13; p.county = 0; p.val = 1120; p.data["black"] = 180; p.data["white"] = 905; p.data["r"] = 145; p.data["d"] = 490; p.data["d16"] = 78; p.data["r16"] = 443;
points[566]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 11; p.county = 0; p.val = 565; p.data["black"] = 250; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 279; p.data["r16"] = 505;
points[567]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 15; p.county = 0; p.val = 955; p.data["black"] = 295; p.data["white"] = 625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[568]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 20; p.county = 0; p.val = 575; p.data["black"] = 435; p.data["white"] = 125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[569]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 17; p.county = 0; p.val = 870; p.data["black"] = 490; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[570]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 14; p.county = 0; p.val = 605; p.data["black"] = 105; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[571]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 13; p.county = 0; p.val = 660; p.data["black"] = 50; p.data["white"] = 595; p.data["r"] = 77; p.data["d"] = 237; p.data["d16"] = 0; p.data["r16"] = 0;
points[572]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 60; p.county = 0; p.val = 2255; p.data["black"] = 55; p.data["white"] = 2140; p.data["r"] = 199; p.data["d"] = 651; p.data["d16"] = 215; p.data["r16"] = 819;
points[573]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 28; p.county = 0; p.val = 960; p.data["black"] = 210; p.data["white"] = 695; p.data["r"] = 154; p.data["d"] = 263; p.data["d16"] = 174; p.data["r16"] = 402;
points[574]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 29; p.county = 0; p.val = 435; p.data["black"] = 45; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[575]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 24; p.county = 0; p.val = 3010; p.data["black"] = 630; p.data["white"] = 2130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[576]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 26; p.county = 0; p.val = 750; p.data["black"] = 230; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[577]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 28; p.county = 0; p.val = 690; p.data["black"] = 195; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[578]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 27; p.county = 0; p.val = 805; p.data["black"] = 690; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 820; p.data["r16"] = 754;
points[579]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 65; p.county = 0; p.val = 1110; p.data["black"] = 240; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[580]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 70; p.county = 0; p.val = 7890; p.data["black"] = 2240; p.data["white"] = 4870; p.data["r"] = 1493; p.data["d"] = 1199; p.data["d16"] = 297; p.data["r16"] = 512;
points[581]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 26; p.county = 0; p.val = 315; p.data["black"] = 295; p.data["white"] = 20; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 82; p.data["r16"] = 134;
points[582]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 65; p.county = 0; p.val = 1890; p.data["black"] = 505; p.data["white"] = 1335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 262; p.data["r16"] = 470;
points[583]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 23; p.county = 0; p.val = 660; p.data["black"] = 420; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[584]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 28; p.county = 0; p.val = 1280; p.data["black"] = 1000; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[585]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 24; p.county = 0; p.val = 1325; p.data["black"] = 470; p.data["white"] = 825; p.data["r"] = 34; p.data["d"] = 57; p.data["d16"] = 45; p.data["r16"] = 98;
points[586]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 28; p.county = 0; p.val = 810; p.data["black"] = 170; p.data["white"] = 640; p.data["r"] = 136; p.data["d"] = 100; p.data["d16"] = 0; p.data["r16"] = 0;
points[587]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 28; p.county = 0; p.val = 855; p.data["black"] = 245; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 76; p.data["r16"] = 249;
points[588]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 20; p.county = 0; p.val = 650; p.data["black"] = 325; p.data["white"] = 205; p.data["r"] = 82; p.data["d"] = 39; p.data["d16"] = 124; p.data["r16"] = 60;
points[589]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 27; p.county = 0; p.val = 885; p.data["black"] = 80; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[590]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 22; p.county = 0; p.val = 1180; p.data["black"] = 715; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[591]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 26; p.county = 0; p.val = 465; p.data["black"] = 125; p.data["white"] = 295; p.data["r"] = 35; p.data["d"] = 71; p.data["d16"] = 52; p.data["r16"] = 112;
points[592]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 25; p.county = 0; p.val = 450; p.data["black"] = 15; p.data["white"] = 415; p.data["r"] = 485; p.data["d"] = 151; p.data["d16"] = 0; p.data["r16"] = 0;
points[593]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 24; p.county = 0; p.val = 515; p.data["black"] = 370; p.data["white"] = 10; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[594]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 25; p.county = 0; p.val = 1105; p.data["black"] = 950; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[595]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 23; p.county = 0; p.val = 1080; p.data["black"] = 390; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[596]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 26; p.county = 0; p.val = 1760; p.data["black"] = 1150; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[597]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 32; p.county = 0; p.val = 1760; p.data["black"] = 795; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[598]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 77; p.county = 0; p.val = 12595; p.data["black"] = 1195; p.data["white"] = 10695; p.data["r"] = 2646; p.data["d"] = 402; p.data["d16"] = 1353; p.data["r16"] = 319;
points[599]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 72; p.county = 0; p.val = 4155; p.data["black"] = 1880; p.data["white"] = 1685; p.data["r"] = 745; p.data["d"] = 705; p.data["d16"] = 461; p.data["r16"] = 1228;
points[600]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 29; p.county = 0; p.val = 585; p.data["black"] = 90; p.data["white"] = 465; p.data["r"] = 187; p.data["d"] = 565; p.data["d16"] = 0; p.data["r16"] = 0;
points[601]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 28; p.county = 0; p.val = 1850; p.data["black"] = 765; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 372; p.data["r16"] = 344;
points[602]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 27; p.county = 0; p.val = 1300; p.data["black"] = 175; p.data["white"] = 1015; p.data["r"] = 55; p.data["d"] = 131; p.data["d16"] = 61; p.data["r16"] = 181;
points[603]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 29; p.county = 0; p.val = 1260; p.data["black"] = 35; p.data["white"] = 1170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[604]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 32; p.county = 0; p.val = 2220; p.data["black"] = 250; p.data["white"] = 1930; p.data["r"] = 250; p.data["d"] = 619; p.data["d16"] = 219; p.data["r16"] = 724;
points[605]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 34; p.county = 0; p.val = 340; p.data["black"] = 65; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[606]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 44; p.county = 0; p.val = 1595; p.data["black"] = 140; p.data["white"] = 1410; p.data["r"] = 144; p.data["d"] = 645; p.data["d16"] = 0; p.data["r16"] = 0;
points[607]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 73; p.county = 0; p.val = 2980; p.data["black"] = 1465; p.data["white"] = 1150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 796; p.data["r16"] = 240;
points[608]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 72; p.county = 0; p.val = 10905; p.data["black"] = 5195; p.data["white"] = 4955; p.data["r"] = 657; p.data["d"] = 408; p.data["d16"] = 843; p.data["r16"] = 795;
points[609]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 16; p.county = 0; p.val = 3230; p.data["black"] = 920; p.data["white"] = 2065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[610]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 32; p.county = 0; p.val = 1920; p.data["black"] = 340; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[611]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 83; p.county = 0; p.val = 1155; p.data["black"] = 4; p.data["white"] = 1150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[612]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 75; p.county = 0; p.val = 13425; p.data["black"] = 4710; p.data["white"] = 8020; p.data["r"] = 225; p.data["d"] = 203; p.data["d16"] = 1018; p.data["r16"] = 396;
points[613]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 75; p.county = 0; p.val = 3325; p.data["black"] = 500; p.data["white"] = 2545; p.data["r"] = 880; p.data["d"] = 780; p.data["d16"] = 0; p.data["r16"] = 0;
points[614]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 74; p.county = 0; p.val = 5665; p.data["black"] = 1010; p.data["white"] = 4540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[615]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 6; p.county = 0; p.val = 3240; p.data["black"] = 940; p.data["white"] = 2160; p.data["r"] = 196; p.data["d"] = 478; p.data["d16"] = 547; p.data["r16"] = 1616;
points[616]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 41; p.county = 0; p.val = 1205; p.data["black"] = 50; p.data["white"] = 1140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[617]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 41; p.county = 0; p.val = 2140; p.data["black"] = 525; p.data["white"] = 1555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[618]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 43; p.county = 0; p.val = 1075; p.data["black"] = 865; p.data["white"] = 210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 357; p.data["r16"] = 1137;
points[619]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 51; p.county = 0; p.val = 8635; p.data["black"] = 250; p.data["white"] = 8205; p.data["r"] = 646; p.data["d"] = 1303; p.data["d16"] = 1134; p.data["r16"] = 2828;
points[620]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 42; p.county = 0; p.val = 2280; p.data["black"] = 605; p.data["white"] = 1640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 314; p.data["r16"] = 789;
points[621]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 36; p.county = 0; p.val = 470; p.data["black"] = 10; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[622]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 39; p.county = 0; p.val = 795; p.data["black"] = 105; p.data["white"] = 690; p.data["r"] = 93; p.data["d"] = 542; p.data["d16"] = 54; p.data["r16"] = 489;
points[623]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 37; p.county = 0; p.val = 1370; p.data["black"] = 70; p.data["white"] = 1295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[624]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 50; p.county = 0; p.val = 7305; p.data["black"] = 415; p.data["white"] = 6495; p.data["r"] = 343; p.data["d"] = 666; p.data["d16"] = 750; p.data["r16"] = 2086;
points[625]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 45; p.county = 0; p.val = 1695; p.data["black"] = 110; p.data["white"] = 1520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[626]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 9; p.county = 0; p.val = 7330; p.data["black"] = 5670; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[627]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 8; p.county = 0; p.val = 9910; p.data["black"] = 3610; p.data["white"] = 5610; p.data["r"] = 1949; p.data["d"] = 528; p.data["d16"] = 505; p.data["r16"] = 423;
points[628]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 70; p.county = 0; p.val = 6250; p.data["black"] = 1720; p.data["white"] = 4285; p.data["r"] = 1051; p.data["d"] = 1862; p.data["d16"] = 391; p.data["r16"] = 670;
points[629]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 8; p.county = 0; p.val = 6925; p.data["black"] = 3025; p.data["white"] = 3685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1962; p.data["r16"] = 237;
points[630]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 7; p.county = 0; p.val = 11715; p.data["black"] = 2335; p.data["white"] = 8720; p.data["r"] = 688; p.data["d"] = 886; p.data["d16"] = 772; p.data["r16"] = 618;
points[631]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 73; p.county = 0; p.val = 3945; p.data["black"] = 545; p.data["white"] = 3085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[632]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 31; p.county = 0; p.val = 1140; p.data["black"] = 460; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[633]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 52; p.county = 0; p.val = 690; p.data["black"] = 555; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[634]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 30; p.county = 0; p.val = 1925; p.data["black"] = 355; p.data["white"] = 1540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 771; p.data["r16"] = 533;
points[635]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 30; p.county = 0; p.val = 625; p.data["black"] = 50; p.data["white"] = 575; p.data["r"] = 241; p.data["d"] = 545; p.data["d16"] = 0; p.data["r16"] = 0;
points[636]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 32; p.county = 0; p.val = 1800; p.data["black"] = 195; p.data["white"] = 1590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 500; p.data["r16"] = 832;
points[637]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 26; p.county = 0; p.val = 1005; p.data["black"] = 275; p.data["white"] = 715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[638]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 29; p.county = 0; p.val = 1800; p.data["black"] = 190; p.data["white"] = 1475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 665; p.data["r16"] = 817;
points[639]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 19; p.county = 0; p.val = 300; p.data["black"] = 15; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[640]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 15; p.county = 0; p.val = 5065; p.data["black"] = 3585; p.data["white"] = 1455; p.data["r"] = 819; p.data["d"] = 310; p.data["d16"] = 445; p.data["r16"] = 135;
points[641]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 50; p.county = 0; p.val = 935; p.data["black"] = 255; p.data["white"] = 680; p.data["r"] = 117; p.data["d"] = 328; p.data["d16"] = 0; p.data["r16"] = 0;
points[642]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 16; p.county = 0; p.val = 1285; p.data["black"] = 470; p.data["white"] = 750; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[643]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 17; p.county = 0; p.val = 1105; p.data["black"] = 340; p.data["white"] = 750; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[644]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 19; p.county = 0; p.val = 885; p.data["black"] = 385; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 394; p.data["r16"] = 397;
points[645]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 20; p.county = 0; p.val = 775; p.data["black"] = 265; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 172; p.data["r16"] = 225;
points[646]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 18; p.county = 0; p.val = 610; p.data["black"] = 245; p.data["white"] = 365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 113; p.data["r16"] = 92;
points[647]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 15; p.county = 0; p.val = 960; p.data["black"] = 275; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 415; p.data["r16"] = 620;
points[648]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 96; p.county = 0; p.val = 765; p.data["black"] = 65; p.data["white"] = 675; p.data["r"] = 211; p.data["d"] = 385; p.data["d16"] = 228; p.data["r16"] = 436;
points[649]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 87; p.county = 0; p.val = 1085; p.data["black"] = 210; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[650]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 87; p.county = 0; p.val = 2420; p.data["black"] = 75; p.data["white"] = 2075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[651]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 94; p.county = 0; p.val = 3485; p.data["black"] = 20; p.data["white"] = 3410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[652]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 20; p.county = 0; p.val = 1725; p.data["black"] = 480; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[653]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 18; p.county = 0; p.val = 305; p.data["black"] = 15; p.data["white"] = 280; p.data["r"] = 202; p.data["d"] = 304; p.data["d16"] = 0; p.data["r16"] = 0;
points[654]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 17; p.county = 0; p.val = 1960; p.data["black"] = 350; p.data["white"] = 1515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[655]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 22; p.county = 0; p.val = 1195; p.data["black"] = 25; p.data["white"] = 1125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 248; p.data["r16"] = 1228;
points[656]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 29; p.county = 0; p.val = 1195; p.data["black"] = 320; p.data["white"] = 850; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[657]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 25; p.county = 0; p.val = 500; p.data["black"] = 0; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 68; p.data["r16"] = 433;
points[658]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 23; p.county = 0; p.val = 1180; p.data["black"] = 270; p.data["white"] = 910; p.data["r"] = 175; p.data["d"] = 446; p.data["d16"] = 214; p.data["r16"] = 565;
points[659]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 28; p.county = 0; p.val = 1095; p.data["black"] = 185; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[660]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 26; p.county = 0; p.val = 460; p.data["black"] = 0; p.data["white"] = 455; p.data["r"] = 73; p.data["d"] = 442; p.data["d16"] = 0; p.data["r16"] = 0;
points[661]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 22; p.county = 0; p.val = 1405; p.data["black"] = 290; p.data["white"] = 1075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[662]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 21; p.county = 0; p.val = 1020; p.data["black"] = 250; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[663]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 20; p.county = 0; p.val = 420; p.data["black"] = 140; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[664]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 17; p.county = 0; p.val = 1705; p.data["black"] = 475; p.data["white"] = 1140; p.data["r"] = 367; p.data["d"] = 465; p.data["d16"] = 462; p.data["r16"] = 629;
points[665]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 13; p.county = 0; p.val = 1045; p.data["black"] = 310; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[666]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 19; p.county = 0; p.val = 690; p.data["black"] = 75; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 167; p.data["r16"] = 246;
points[667]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 21; p.county = 0; p.val = 1215; p.data["black"] = 15; p.data["white"] = 1200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 66; p.data["r16"] = 395;
points[668]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 13; p.county = 0; p.val = 1110; p.data["black"] = 520; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[669]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 14; p.county = 0; p.val = 680; p.data["black"] = 385; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[670]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 14; p.county = 0; p.val = 1625; p.data["black"] = 850; p.data["white"] = 735; p.data["r"] = 241; p.data["d"] = 195; p.data["d16"] = 339; p.data["r16"] = 486;
points[671]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 20; p.county = 0; p.val = 915; p.data["black"] = 270; p.data["white"] = 645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[672]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 25; p.county = 0; p.val = 1195; p.data["black"] = 70; p.data["white"] = 1125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[673]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 17; p.county = 0; p.val = 2890; p.data["black"] = 70; p.data["white"] = 2795; p.data["r"] = 58; p.data["d"] = 269; p.data["d16"] = 0; p.data["r16"] = 0;
points[674]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 22; p.county = 0; p.val = 5860; p.data["black"] = 3295; p.data["white"] = 2300; p.data["r"] = 405; p.data["d"] = 133; p.data["d16"] = 366; p.data["r16"] = 40;
points[675]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 26; p.county = 0; p.val = 450; p.data["black"] = 95; p.data["white"] = 355; p.data["r"] = 87; p.data["d"] = 399; p.data["d16"] = 0; p.data["r16"] = 0;
points[676]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 24; p.county = 0; p.val = 1720; p.data["black"] = 15; p.data["white"] = 1660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[677]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 21; p.county = 0; p.val = 7270; p.data["black"] = 1060; p.data["white"] = 5880; p.data["r"] = 732; p.data["d"] = 1180; p.data["d16"] = 854; p.data["r16"] = 902;
points[678]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 14; p.county = 0; p.val = 1750; p.data["black"] = 10; p.data["white"] = 1715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[679]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 16; p.county = 0; p.val = 2175; p.data["black"] = 90; p.data["white"] = 2010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 184; p.data["r16"] = 983;
points[680]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 23; p.county = 0; p.val = 3360; p.data["black"] = 1390; p.data["white"] = 1860; p.data["r"] = 238; p.data["d"] = 102; p.data["d16"] = 276; p.data["r16"] = 143;
points[681]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 16; p.county = 0; p.val = 1875; p.data["black"] = 105; p.data["white"] = 1720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[682]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 24; p.county = 0; p.val = 1215; p.data["black"] = 10; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[683]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 22; p.county = 0; p.val = 2160; p.data["black"] = 1430; p.data["white"] = 690; p.data["r"] = 119; p.data["d"] = 315; p.data["d16"] = 0; p.data["r16"] = 0;
points[684]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 22; p.county = 0; p.val = 1180; p.data["black"] = 220; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[685]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 19; p.county = 0; p.val = 1045; p.data["black"] = 190; p.data["white"] = 825; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 418; p.data["r16"] = 1093;
points[686]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 24; p.county = 0; p.val = 1370; p.data["black"] = 145; p.data["white"] = 1195; p.data["r"] = 65; p.data["d"] = 131; p.data["d16"] = 150; p.data["r16"] = 619;
points[687]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 18; p.county = 0; p.val = 2050; p.data["black"] = 85; p.data["white"] = 1895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[688]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 16; p.county = 0; p.val = 1110; p.data["black"] = 75; p.data["white"] = 975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[689]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 14; p.county = 0; p.val = 4685; p.data["black"] = 25; p.data["white"] = 4615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 282; p.data["r16"] = 1400;
points[690]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 26; p.county = 0; p.val = 755; p.data["black"] = 4; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 167; p.data["r16"] = 627;
points[691]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 19; p.county = 0; p.val = 1125; p.data["black"] = 40; p.data["white"] = 1050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[692]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 24; p.county = 0; p.val = 1190; p.data["black"] = 105; p.data["white"] = 1075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[693]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 13; p.county = 0; p.val = 4655; p.data["black"] = 225; p.data["white"] = 4025; p.data["r"] = 893; p.data["d"] = 1401; p.data["d16"] = 572; p.data["r16"] = 355;
points[694]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 19; p.county = 0; p.val = 1640; p.data["black"] = 130; p.data["white"] = 1480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[695]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 23; p.county = 0; p.val = 985; p.data["black"] = 175; p.data["white"] = 810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[696]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 28; p.county = 0; p.val = 1390; p.data["black"] = 80; p.data["white"] = 1310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 192; p.data["r16"] = 818;
points[697]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 17; p.county = 0; p.val = 1000; p.data["black"] = 390; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[698]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 18; p.county = 0; p.val = 1335; p.data["black"] = 110; p.data["white"] = 1195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[699]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 18; p.county = 0; p.val = 1475; p.data["black"] = 25; p.data["white"] = 1425; p.data["r"] = 205; p.data["d"] = 946; p.data["d16"] = 273; p.data["r16"] = 1375;
points[700]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 14; p.county = 0; p.val = 1915; p.data["black"] = 15; p.data["white"] = 1900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[701]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 23; p.county = 0; p.val = 1030; p.data["black"] = 915; p.data["white"] = 100; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[702]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 38; p.county = 0; p.val = 770; p.data["black"] = 115; p.data["white"] = 660; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[703]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 39; p.county = 0; p.val = 4585; p.data["black"] = 2440; p.data["white"] = 1755; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 916; p.data["r16"] = 602;
points[704]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 42; p.county = 0; p.val = 1415; p.data["black"] = 605; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[705]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 35; p.county = 0; p.val = 1110; p.data["black"] = 905; p.data["white"] = 205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 343; p.data["r16"] = 137;
points[706]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 41; p.county = 0; p.val = 1425; p.data["black"] = 1125; p.data["white"] = 225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 799; p.data["r16"] = 169;
points[707]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 15; p.county = 0; p.val = 1350; p.data["black"] = 165; p.data["white"] = 1070; p.data["r"] = 302; p.data["d"] = 187; p.data["d16"] = 248; p.data["r16"] = 234;
points[708]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 29; p.county = 0; p.val = 680; p.data["black"] = 435; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[709]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 25; p.county = 0; p.val = 570; p.data["black"] = 55; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[710]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 30; p.county = 0; p.val = 1755; p.data["black"] = 650; p.data["white"] = 1060; p.data["r"] = 294; p.data["d"] = 85; p.data["d16"] = 392; p.data["r16"] = 105;
points[711]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 33; p.county = 0; p.val = 1050; p.data["black"] = 475; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[712]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 30; p.county = 0; p.val = 1055; p.data["black"] = 535; p.data["white"] = 500; p.data["r"] = 730; p.data["d"] = 585; p.data["d16"] = 804; p.data["r16"] = 770;
points[713]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 29; p.county = 0; p.val = 495; p.data["black"] = 360; p.data["white"] = 110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[714]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 24; p.county = 0; p.val = 1810; p.data["black"] = 615; p.data["white"] = 1185; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[715]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 29; p.county = 0; p.val = 2920; p.data["black"] = 2055; p.data["white"] = 805; p.data["r"] = 577; p.data["d"] = 475; p.data["d16"] = 0; p.data["r16"] = 0;
points[716]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 28; p.county = 0; p.val = 2960; p.data["black"] = 780; p.data["white"] = 2120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[717]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 0; p.val = 450; p.data["black"] = 370; p.data["white"] = 80; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 479; p.data["r16"] = 685;
points[718]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 23; p.county = 0; p.val = 1340; p.data["black"] = 60; p.data["white"] = 1205; p.data["r"] = 383; p.data["d"] = 570; p.data["d16"] = 537; p.data["r16"] = 696;
points[719]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 24; p.county = 0; p.val = 470; p.data["black"] = 255; p.data["white"] = 205; p.data["r"] = 538; p.data["d"] = 294; p.data["d16"] = 681; p.data["r16"] = 384;
points[720]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 28; p.county = 0; p.val = 705; p.data["black"] = 415; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[721]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 30; p.county = 0; p.val = 905; p.data["black"] = 285; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 282; p.data["r16"] = 474;
points[722]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 25; p.county = 0; p.val = 2065; p.data["black"] = 200; p.data["white"] = 1770; p.data["r"] = 253; p.data["d"] = 906; p.data["d16"] = 0; p.data["r16"] = 0;
points[723]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 22; p.county = 0; p.val = 565; p.data["black"] = 325; p.data["white"] = 225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[724]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 32; p.county = 0; p.val = 815; p.data["black"] = 355; p.data["white"] = 440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[725]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 33; p.county = 0; p.val = 1520; p.data["black"] = 1440; p.data["white"] = 75; p.data["r"] = 916; p.data["d"] = 293; p.data["d16"] = 1316; p.data["r16"] = 403;
points[726]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 31; p.county = 0; p.val = 465; p.data["black"] = 20; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[727]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 34; p.county = 0; p.val = 635; p.data["black"] = 235; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[728]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 31; p.county = 0; p.val = 930; p.data["black"] = 435; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 747; p.data["r16"] = 271;
points[729]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 30; p.county = 0; p.val = 765; p.data["black"] = 725; p.data["white"] = 30; p.data["r"] = 61; p.data["d"] = 198; p.data["d16"] = 0; p.data["r16"] = 0;
points[730]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 34; p.county = 0; p.val = 735; p.data["black"] = 325; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[731]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 35; p.county = 0; p.val = 1260; p.data["black"] = 615; p.data["white"] = 645; p.data["r"] = 290; p.data["d"] = 107; p.data["d16"] = 0; p.data["r16"] = 0;
points[732]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 32; p.county = 0; p.val = 430; p.data["black"] = 105; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[733]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 34; p.county = 0; p.val = 855; p.data["black"] = 0; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 19; p.data["r16"] = 207;
points[734]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 37; p.county = 0; p.val = 455; p.data["black"] = 260; p.data["white"] = 195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 195; p.data["r16"] = 69;
points[735]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 44; p.county = 0; p.val = 545; p.data["black"] = 305; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[736]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 37; p.county = 0; p.val = 605; p.data["black"] = 270; p.data["white"] = 325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[737]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 12; p.county = 0; p.val = 1460; p.data["black"] = 480; p.data["white"] = 950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 339; p.data["r16"] = 630;
points[738]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 0; p.val = 1140; p.data["black"] = 595; p.data["white"] = 525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[739]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 21; p.county = 0; p.val = 455; p.data["black"] = 175; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[740]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 13; p.county = 0; p.val = 490; p.data["black"] = 155; p.data["white"] = 295; p.data["r"] = 257; p.data["d"] = 403; p.data["d16"] = 67; p.data["r16"] = 178;
points[741]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 15; p.county = 0; p.val = 725; p.data["black"] = 185; p.data["white"] = 525; p.data["r"] = 290; p.data["d"] = 539; p.data["d16"] = 0; p.data["r16"] = 0;
points[742]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 18; p.county = 0; p.val = 785; p.data["black"] = 510; p.data["white"] = 275; p.data["r"] = 306; p.data["d"] = 222; p.data["d16"] = 0; p.data["r16"] = 0;
points[743]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 24; p.county = 0; p.val = 1535; p.data["black"] = 490; p.data["white"] = 965; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[744]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 18; p.county = 0; p.val = 1220; p.data["black"] = 0; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[745]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 14; p.county = 0; p.val = 1485; p.data["black"] = 400; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[746]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 0; p.val = 5660; p.data["black"] = 530; p.data["white"] = 4670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 883; p.data["r16"] = 1248;
points[747]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 7; p.county = 0; p.val = 3990; p.data["black"] = 120; p.data["white"] = 3365; p.data["r"] = 1911; p.data["d"] = 2883; p.data["d16"] = 0; p.data["r16"] = 0;
points[748]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 14; p.county = 0; p.val = 2040; p.data["black"] = 425; p.data["white"] = 1440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 104; p.data["r16"] = 514;
points[749]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 21; p.county = 0; p.val = 720; p.data["black"] = 10; p.data["white"] = 705; p.data["r"] = 188; p.data["d"] = 566; p.data["d16"] = 0; p.data["r16"] = 0;
points[750]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 27; p.county = 0; p.val = 1845; p.data["black"] = 260; p.data["white"] = 1580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[751]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 0; p.val = 1545; p.data["black"] = 385; p.data["white"] = 1120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 217; p.data["r16"] = 410;
points[752]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 47; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[753]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 17; p.county = 0; p.val = 1165; p.data["black"] = 80; p.data["white"] = 1055; p.data["r"] = 131; p.data["d"] = 276; p.data["d16"] = 0; p.data["r16"] = 0;
points[754]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 19; p.county = 0; p.val = 3285; p.data["black"] = 285; p.data["white"] = 2625; p.data["r"] = 247; p.data["d"] = 769; p.data["d16"] = 469; p.data["r16"] = 1505;
points[755]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 21; p.county = 0; p.val = 3445; p.data["black"] = 245; p.data["white"] = 3075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[756]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 22; p.county = 0; p.val = 2055; p.data["black"] = 300; p.data["white"] = 1645; p.data["r"] = 430; p.data["d"] = 658; p.data["d16"] = 331; p.data["r16"] = 1193;
points[757]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 22; p.county = 0; p.val = 1030; p.data["black"] = 0; p.data["white"] = 1005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 179; p.data["r16"] = 837;
points[758]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 20; p.county = 0; p.val = 1120; p.data["black"] = 20; p.data["white"] = 990; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[759]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 19; p.county = 0; p.val = 1405; p.data["black"] = 25; p.data["white"] = 1380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[760]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 22; p.county = 0; p.val = 800; p.data["black"] = 0; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[761]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 13; p.county = 0; p.val = 3115; p.data["black"] = 265; p.data["white"] = 2545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[762]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 21; p.county = 0; p.val = 970; p.data["black"] = 65; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[763]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 23; p.county = 0; p.val = 3045; p.data["black"] = 1105; p.data["white"] = 1815; p.data["r"] = 82; p.data["d"] = 98; p.data["d16"] = 117; p.data["r16"] = 139;
points[764]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 23; p.county = 0; p.val = 755; p.data["black"] = 365; p.data["white"] = 365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[765]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 36; p.county = 0; p.val = 855; p.data["black"] = 235; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[766]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 51; p.county = 0; p.val = 915; p.data["black"] = 585; p.data["white"] = 310; p.data["r"] = 26; p.data["d"] = 96; p.data["d16"] = 34; p.data["r16"] = 127;
points[767]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 59; p.county = 0; p.val = 705; p.data["black"] = 150; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[768]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 56; p.county = 0; p.val = 1970; p.data["black"] = 975; p.data["white"] = 970; p.data["r"] = 312; p.data["d"] = 210; p.data["d16"] = 789; p.data["r16"] = 269;
points[769]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 16; p.county = 0; p.val = 1315; p.data["black"] = 430; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[770]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 15; p.county = 0; p.val = 755; p.data["black"] = 25; p.data["white"] = 720; p.data["r"] = 291; p.data["d"] = 166; p.data["d16"] = 0; p.data["r16"] = 0;
points[771]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 33; p.county = 0; p.val = 520; p.data["black"] = 0; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[772]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 19; p.county = 0; p.val = 765; p.data["black"] = 0; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[773]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 18; p.county = 0; p.val = 2135; p.data["black"] = 465; p.data["white"] = 1640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[774]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 19; p.county = 0; p.val = 1785; p.data["black"] = 190; p.data["white"] = 1505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[775]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 17; p.county = 0; p.val = 935; p.data["black"] = 80; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[776]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 23; p.county = 0; p.val = 1440; p.data["black"] = 0; p.data["white"] = 1355; p.data["r"] = 340; p.data["d"] = 922; p.data["d16"] = 0; p.data["r16"] = 0;
points[777]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 25; p.county = 0; p.val = 785; p.data["black"] = 50; p.data["white"] = 715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 62; p.data["r16"] = 646;
points[778]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 0; p.county = 0; p.val = 730; p.data["black"] = 25; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[779]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 0; p.county = 0; p.val = 740; p.data["black"] = 15; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[780]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 5; p.county = 0; p.val = 3510; p.data["black"] = 420; p.data["white"] = 2785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[781]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 4; p.county = 0; p.val = 1445; p.data["black"] = 240; p.data["white"] = 1125; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[782]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 4; p.county = 0; p.val = 2865; p.data["black"] = 540; p.data["white"] = 2010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 549; p.data["r16"] = 1207;
points[783]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 8; p.county = 0; p.val = 1975; p.data["black"] = 260; p.data["white"] = 1590; p.data["r"] = 345; p.data["d"] = 657; p.data["d16"] = 0; p.data["r16"] = 0;
points[784]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 9; p.county = 0; p.val = 3165; p.data["black"] = 540; p.data["white"] = 2190; p.data["r"] = 594; p.data["d"] = 875; p.data["d16"] = 0; p.data["r16"] = 0;
points[785]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 52; p.county = 0; p.val = 790; p.data["black"] = 760; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[786]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 48; p.county = 0; p.val = 555; p.data["black"] = 205; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 195; p.data["r16"] = 97;
points[787]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 43; p.county = 0; p.val = 2825; p.data["black"] = 865; p.data["white"] = 1855; p.data["r"] = 439; p.data["d"] = 811; p.data["d16"] = 0; p.data["r16"] = 0;
points[788]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 39; p.county = 0; p.val = 1195; p.data["black"] = 40; p.data["white"] = 1145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[789]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 34; p.county = 0; p.val = 1450; p.data["black"] = 135; p.data["white"] = 1265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[790]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 39; p.county = 0; p.val = 2345; p.data["black"] = 95; p.data["white"] = 2170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 57; p.data["r16"] = 356;
points[791]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 43; p.county = 0; p.val = 3345; p.data["black"] = 320; p.data["white"] = 2955; p.data["r"] = 256; p.data["d"] = 709; p.data["d16"] = 280; p.data["r16"] = 777;
points[792]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 34; p.county = 0; p.val = 1075; p.data["black"] = 235; p.data["white"] = 840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[793]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 35; p.county = 0; p.val = 640; p.data["black"] = 130; p.data["white"] = 510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 404; p.data["r16"] = 610;
points[794]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 35; p.county = 0; p.val = 825; p.data["black"] = 300; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[795]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 42; p.county = 0; p.val = 965; p.data["black"] = 545; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 458; p.data["r16"] = 369;
points[796]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 30; p.county = 0; p.val = 1245; p.data["black"] = 905; p.data["white"] = 325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[797]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 30; p.county = 0; p.val = 1960; p.data["black"] = 735; p.data["white"] = 1220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[798]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 34; p.county = 0; p.val = 1000; p.data["black"] = 630; p.data["white"] = 360; p.data["r"] = 1065; p.data["d"] = 856; p.data["d16"] = 0; p.data["r16"] = 0;
points[799]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 70; p.county = 0; p.val = 825; p.data["black"] = 40; p.data["white"] = 775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 154; p.data["r16"] = 340;
points[800]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 69; p.county = 0; p.val = 910; p.data["black"] = 215; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[801]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 71; p.county = 0; p.val = 1655; p.data["black"] = 435; p.data["white"] = 1220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[802]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 74; p.county = 0; p.val = 1195; p.data["black"] = 625; p.data["white"] = 570; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[803]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 74; p.county = 0; p.val = 1130; p.data["black"] = 615; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 672; p.data["r16"] = 104;
points[804]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 76; p.county = 0; p.val = 18615; p.data["black"] = 7530; p.data["white"] = 10235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 748; p.data["r16"] = 29;
points[805]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 23; p.county = 0; p.val = 400; p.data["black"] = 20; p.data["white"] = 360; p.data["r"] = 144; p.data["d"] = 132; p.data["d16"] = 159; p.data["r16"] = 202;
points[806]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 24; p.county = 0; p.val = 535; p.data["black"] = 115; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[807]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 27; p.county = 0; p.val = 1660; p.data["black"] = 340; p.data["white"] = 1270; p.data["r"] = 144; p.data["d"] = 581; p.data["d16"] = 0; p.data["r16"] = 0;
points[808]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 25; p.county = 0; p.val = 860; p.data["black"] = 15; p.data["white"] = 830; p.data["r"] = 142; p.data["d"] = 467; p.data["d16"] = 201; p.data["r16"] = 645;
points[809]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 74; p.county = 0; p.val = 7200; p.data["black"] = 4005; p.data["white"] = 2455; p.data["r"] = 340; p.data["d"] = 93; p.data["d16"] = 279; p.data["r16"] = 45;
points[810]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 3; p.county = 0; p.val = 3215; p.data["black"] = 1645; p.data["white"] = 1465; p.data["r"] = 350; p.data["d"] = 219; p.data["d16"] = 310; p.data["r16"] = 115;
points[811]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 4; p.county = 0; p.val = 4565; p.data["black"] = 1624; p.data["white"] = 2645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 259; p.data["r16"] = 390;
points[812]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 77; p.county = 0; p.val = 1350; p.data["black"] = 110; p.data["white"] = 1240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[813]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 76; p.county = 0; p.val = 11920; p.data["black"] = 4070; p.data["white"] = 7450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[814]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 78; p.county = 0; p.val = 10845; p.data["black"] = 1070; p.data["white"] = 9340; p.data["r"] = 651; p.data["d"] = 542; p.data["d16"] = 1182; p.data["r16"] = 884;
points[815]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 79; p.county = 0; p.val = 2795; p.data["black"] = 610; p.data["white"] = 2135; p.data["r"] = 1093; p.data["d"] = 849; p.data["d16"] = 728; p.data["r16"] = 882;
points[816]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 76; p.county = 0; p.val = 6555; p.data["black"] = 1385; p.data["white"] = 4820; p.data["r"] = 509; p.data["d"] = 676; p.data["d16"] = 399; p.data["r16"] = 662;
points[817]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 67; p.county = 0; p.val = 1255; p.data["black"] = 705; p.data["white"] = 550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 847; p.data["r16"] = 357;
points[818]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 78; p.county = 0; p.val = 4840; p.data["black"] = 640; p.data["white"] = 3990; p.data["r"] = 1877; p.data["d"] = 1387; p.data["d16"] = 996; p.data["r16"] = 832;
points[819]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 65; p.county = 0; p.val = 960; p.data["black"] = 800; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[820]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 76; p.county = 0; p.val = 665; p.data["black"] = 130; p.data["white"] = 535; p.data["r"] = 309; p.data["d"] = 189; p.data["d16"] = 0; p.data["r16"] = 0;
points[821]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 78; p.county = 0; p.val = 530; p.data["black"] = 230; p.data["white"] = 305; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[822]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 79; p.county = 0; p.val = 2855; p.data["black"] = 680; p.data["white"] = 2105; p.data["r"] = 1654; p.data["d"] = 1202; p.data["d16"] = 1646; p.data["r16"] = 1766;
points[823]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 76; p.county = 0; p.val = 340; p.data["black"] = 0; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[824]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 80; p.county = 0; p.val = 1155; p.data["black"] = 775; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[825]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 75; p.county = 0; p.val = 5525; p.data["black"] = 3025; p.data["white"] = 2345; p.data["r"] = 1400; p.data["d"] = 205; p.data["d16"] = 296; p.data["r16"] = 122;
points[826]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 4; p.county = 0; p.val = 1445; p.data["black"] = 95; p.data["white"] = 1320; p.data["r"] = 184; p.data["d"] = 419; p.data["d16"] = 0; p.data["r16"] = 0;
points[827]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 3; p.county = 0; p.val = 3995; p.data["black"] = 1600; p.data["white"] = 2215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 328; p.data["r16"] = 120;
points[828]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 79; p.county = 0; p.val = 715; p.data["black"] = 375; p.data["white"] = 335; p.data["r"] = 725; p.data["d"] = 219; p.data["d16"] = 834; p.data["r16"] = 260;
points[829]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 76; p.county = 0; p.val = 1710; p.data["black"] = 370; p.data["white"] = 1325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[830]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 79; p.county = 0; p.val = 4040; p.data["black"] = 870; p.data["white"] = 3125; p.data["r"] = 334; p.data["d"] = 389; p.data["d16"] = 367; p.data["r16"] = 483;
points[831]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 81; p.county = 0; p.val = 1335; p.data["black"] = 685; p.data["white"] = 640; p.data["r"] = 411; p.data["d"] = 288; p.data["d16"] = 415; p.data["r16"] = 371;
points[832]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 76; p.county = 0; p.val = 6265; p.data["black"] = 380; p.data["white"] = 5530; p.data["r"] = 667; p.data["d"] = 834; p.data["d16"] = 470; p.data["r16"] = 604;
points[833]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 78; p.county = 0; p.val = 2690; p.data["black"] = 74; p.data["white"] = 2330; p.data["r"] = 299; p.data["d"] = 255; p.data["d16"] = 0; p.data["r16"] = 0;
points[834]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 80; p.county = 0; p.val = 1115; p.data["black"] = 340; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[835]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 73; p.county = 0; p.val = 9995; p.data["black"] = 595; p.data["white"] = 9095; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[836]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 80; p.county = 0; p.val = 1295; p.data["black"] = 730; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[837]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 71; p.county = 0; p.val = 3990; p.data["black"] = 1165; p.data["white"] = 2155; p.data["r"] = 343; p.data["d"] = 722; p.data["d16"] = 0; p.data["r16"] = 0;
points[838]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 73; p.county = 0; p.val = 5635; p.data["black"] = 1840; p.data["white"] = 3355; p.data["r"] = 824; p.data["d"] = 299; p.data["d16"] = 2128; p.data["r16"] = 783;
points[839]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 76; p.county = 0; p.val = 2675; p.data["black"] = 115; p.data["white"] = 2435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1014; p.data["r16"] = 970;
points[840]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 53; p.county = 0; p.val = 2635; p.data["black"] = 270; p.data["white"] = 2365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[841]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 77; p.county = 0; p.val = 1525; p.data["black"] = 70; p.data["white"] = 1425; p.data["r"] = 1513; p.data["d"] = 1712; p.data["d16"] = 441; p.data["r16"] = 475;
points[842]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 53; p.county = 0; p.val = 2795; p.data["black"] = 145; p.data["white"] = 2525; p.data["r"] = 220; p.data["d"] = 401; p.data["d16"] = 242; p.data["r16"] = 426;
points[843]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 52; p.county = 0; p.val = 3230; p.data["black"] = 725; p.data["white"] = 2325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 414; p.data["r16"] = 752;
points[844]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 55; p.county = 0; p.val = 2380; p.data["black"] = 100; p.data["white"] = 2175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[845]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 55; p.county = 0; p.val = 1475; p.data["black"] = 405; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 418; p.data["r16"] = 773;
points[846]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 54; p.county = 0; p.val = 1565; p.data["black"] = 115; p.data["white"] = 1420; p.data["r"] = 161; p.data["d"] = 425; p.data["d16"] = 148; p.data["r16"] = 558;
points[847]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 5; p.county = 0; p.val = 1770; p.data["black"] = 110; p.data["white"] = 1550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 112; p.data["r16"] = 675;
points[848]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 2; p.county = 0; p.val = 2145; p.data["black"] = 145; p.data["white"] = 1855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[849]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 9; p.county = 0; p.val = 525; p.data["black"] = 20; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[850]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 3; p.county = 0; p.val = 1285; p.data["black"] = 60; p.data["white"] = 1140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[851]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 1; p.county = 0; p.val = 2130; p.data["black"] = 155; p.data["white"] = 1950; p.data["r"] = 498; p.data["d"] = 1186; p.data["d16"] = 99; p.data["r16"] = 620;
points[852]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 1; p.county = 0; p.val = 1745; p.data["black"] = 235; p.data["white"] = 1475; p.data["r"] = 96; p.data["d"] = 553; p.data["d16"] = 101; p.data["r16"] = 715;
points[853]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 3; p.county = 0; p.val = 995; p.data["black"] = 25; p.data["white"] = 885; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[854]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 1; p.county = 0; p.val = 945; p.data["black"] = 90; p.data["white"] = 840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[855]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 7; p.county = 0; p.val = 2310; p.data["black"] = 240; p.data["white"] = 1960; p.data["r"] = 98; p.data["d"] = 551; p.data["d16"] = 0; p.data["r16"] = 0;
points[856]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 2; p.county = 0; p.val = 1370; p.data["black"] = 630; p.data["white"] = 600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 309; p.data["r16"] = 307;
points[857]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 2; p.county = 0; p.val = 1630; p.data["black"] = 115; p.data["white"] = 1355; p.data["r"] = 123; p.data["d"] = 568; p.data["d16"] = 173; p.data["r16"] = 446;
points[858]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 2; p.county = 0; p.val = 1470; p.data["black"] = 30; p.data["white"] = 1440; p.data["r"] = 81; p.data["d"] = 570; p.data["d16"] = 0; p.data["r16"] = 0;
points[859]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 4; p.county = 0; p.val = 550; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[860]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 7; p.county = 0; p.val = 765; p.data["black"] = 35; p.data["white"] = 710; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[861]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 3; p.county = 0; p.val = 805; p.data["black"] = 65; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[862]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 43; p.county = 0; p.val = 1620; p.data["black"] = 125; p.data["white"] = 1435; p.data["r"] = 179; p.data["d"] = 684; p.data["d16"] = 0; p.data["r16"] = 0;
points[863]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 78; p.county = 0; p.val = 4195; p.data["black"] = 1050; p.data["white"] = 3025; p.data["r"] = 447; p.data["d"] = 537; p.data["d16"] = 0; p.data["r16"] = 0;
points[864]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 80; p.county = 0; p.val = 1860; p.data["black"] = 590; p.data["white"] = 1070; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[865]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 7; p.county = 0; p.val = 2700; p.data["black"] = 425; p.data["white"] = 2245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[866]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 2; p.county = 0; p.val = 4530; p.data["black"] = 590; p.data["white"] = 3700; p.data["r"] = 667; p.data["d"] = 1300; p.data["d16"] = 597; p.data["r16"] = 1362;
points[867]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 3; p.county = 0; p.val = 6080; p.data["black"] = 285; p.data["white"] = 5425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[868]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 2; p.county = 0; p.val = 1845; p.data["black"] = 660; p.data["white"] = 1100; p.data["r"] = 247; p.data["d"] = 430; p.data["d16"] = 0; p.data["r16"] = 0;
points[869]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 9; p.county = 0; p.val = 1490; p.data["black"] = 55; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 71; p.data["r16"] = 129;
points[870]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 9; p.county = 0; p.val = 7005; p.data["black"] = 414; p.data["white"] = 5860; p.data["r"] = 350; p.data["d"] = 601; p.data["d16"] = 392; p.data["r16"] = 715;
points[871]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 10; p.county = 0; p.val = 16610; p.data["black"] = 1910; p.data["white"] = 13400; p.data["r"] = 1138; p.data["d"] = 1235; p.data["d16"] = 530; p.data["r16"] = 662;
points[872]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 10; p.county = 0; p.val = 11175; p.data["black"] = 775; p.data["white"] = 9460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[873]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 43; p.county = 0; p.val = 4320; p.data["black"] = 255; p.data["white"] = 3830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[874]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 9; p.county = 0; p.val = 7870; p.data["black"] = 1145; p.data["white"] = 6015; p.data["r"] = 998; p.data["d"] = 1488; p.data["d16"] = 652; p.data["r16"] = 867;
points[875]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 5; p.county = 0; p.val = 1025; p.data["black"] = 30; p.data["white"] = 955; p.data["r"] = 273; p.data["d"] = 1176; p.data["d16"] = 0; p.data["r16"] = 0;
points[876]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 10; p.county = 0; p.val = 9580; p.data["black"] = 1905; p.data["white"] = 7115; p.data["r"] = 902; p.data["d"] = 1322; p.data["d16"] = 2091; p.data["r16"] = 1653;
points[877]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 11; p.county = 0; p.val = 11725; p.data["black"] = 4645; p.data["white"] = 6630; p.data["r"] = 937; p.data["d"] = 897; p.data["d16"] = 976; p.data["r16"] = 1431;
points[878]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 43; p.county = 0; p.val = 595; p.data["black"] = 0; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[879]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 41; p.county = 0; p.val = 1230; p.data["black"] = 475; p.data["white"] = 750; p.data["r"] = 436; p.data["d"] = 446; p.data["d16"] = 339; p.data["r16"] = 740;
points[880]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 44; p.county = 0; p.val = 3715; p.data["black"] = 110; p.data["white"] = 3395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[881]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 36; p.county = 0; p.val = 1230; p.data["black"] = 145; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[882]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 38; p.county = 0; p.val = 750; p.data["black"] = 130; p.data["white"] = 610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[883]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 44; p.county = 0; p.val = 3900; p.data["black"] = 1450; p.data["white"] = 2300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[884]=p;}
if (1==1){ Point p;
p.x = 98; p.y = 42; p.county = 0; p.val = 4190; p.data["black"] = 870; p.data["white"] = 3125; p.data["r"] = 297; p.data["d"] = 627; p.data["d16"] = 0; p.data["r16"] = 0;
points[885]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 41; p.county = 0; p.val = 1205; p.data["black"] = 200; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 223; p.data["r16"] = 412;
points[886]=p;}
if (1==1){ Point p;
p.x = 99; p.y = 42; p.county = 0; p.val = 4390; p.data["black"] = 194; p.data["white"] = 3935; p.data["r"] = 378; p.data["d"] = 887; p.data["d16"] = 848; p.data["r16"] = 2127;
points[887]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 46; p.county = 0; p.val = 5345; p.data["black"] = 275; p.data["white"] = 4885; p.data["r"] = 1035; p.data["d"] = 1942; p.data["d16"] = 0; p.data["r16"] = 0;
points[888]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 46; p.county = 0; p.val = 1185; p.data["black"] = 4; p.data["white"] = 1075; p.data["r"] = 505; p.data["d"] = 845; p.data["d16"] = 330; p.data["r16"] = 702;
points[889]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 47; p.county = 0; p.val = 1210; p.data["black"] = 35; p.data["white"] = 1005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[890]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 41; p.county = 0; p.val = 1265; p.data["black"] = 155; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[891]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 43; p.county = 0; p.val = 4150; p.data["black"] = 2290; p.data["white"] = 1720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 723; p.data["r16"] = 53;
points[892]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 44; p.county = 0; p.val = 1880; p.data["black"] = 325; p.data["white"] = 1415; p.data["r"] = 1228; p.data["d"] = 852; p.data["d16"] = 0; p.data["r16"] = 0;
points[893]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 39; p.county = 0; p.val = 1115; p.data["black"] = 20; p.data["white"] = 1085; p.data["r"] = 356; p.data["d"] = 843; p.data["d16"] = 0; p.data["r16"] = 0;
points[894]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 42; p.county = 0; p.val = 2415; p.data["black"] = 720; p.data["white"] = 1695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[895]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 31; p.county = 0; p.val = 645; p.data["black"] = 110; p.data["white"] = 490; p.data["r"] = 44; p.data["d"] = 157; p.data["d16"] = 42; p.data["r16"] = 219;
points[896]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 46; p.county = 0; p.val = 9165; p.data["black"] = 1010; p.data["white"] = 7575; p.data["r"] = 376; p.data["d"] = 764; p.data["d16"] = 329; p.data["r16"] = 844;
points[897]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 46; p.county = 0; p.val = 1440; p.data["black"] = 230; p.data["white"] = 1155; p.data["r"] = 259; p.data["d"] = 508; p.data["d16"] = 115; p.data["r16"] = 150;
points[898]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 98; p.county = 0; p.val = 1150; p.data["black"] = 0; p.data["white"] = 1150; p.data["r"] = 904; p.data["d"] = 960; p.data["d16"] = 814; p.data["r16"] = 1093;
points[899]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 41; p.county = 0; p.val = 2170; p.data["black"] = 160; p.data["white"] = 1900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 243; p.data["r16"] = 665;
points[900]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 11; p.county = 0; p.val = 4650; p.data["black"] = 835; p.data["white"] = 3530; p.data["r"] = 998; p.data["d"] = 837; p.data["d16"] = 0; p.data["r16"] = 0;
points[901]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 93; p.county = 0; p.val = 2070; p.data["black"] = 60; p.data["white"] = 1955; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[902]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 89; p.county = 0; p.val = 2460; p.data["black"] = 2015; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[903]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 90; p.county = 0; p.val = 1330; p.data["black"] = 200; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 449; p.data["r16"] = 566;
points[904]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 85; p.county = 0; p.val = 1055; p.data["black"] = 510; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[905]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 88; p.county = 0; p.val = 2710; p.data["black"] = 335; p.data["white"] = 2330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[906]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 93; p.county = 0; p.val = 1635; p.data["black"] = 45; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[907]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 81; p.county = 0; p.val = 1060; p.data["black"] = 930; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[908]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 88; p.county = 0; p.val = 1060; p.data["black"] = 605; p.data["white"] = 365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 750; p.data["r16"] = 706;
points[909]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 84; p.county = 0; p.val = 1030; p.data["black"] = 665; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[910]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 58; p.county = 0; p.val = 880; p.data["black"] = 685; p.data["white"] = 195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[911]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 89; p.county = 0; p.val = 1625; p.data["black"] = 510; p.data["white"] = 1045; p.data["r"] = 697; p.data["d"] = 1163; p.data["d16"] = 0; p.data["r16"] = 0;
points[912]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 98; p.county = 0; p.val = 480; p.data["black"] = 10; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 249; p.data["r16"] = 440;
points[913]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 94; p.county = 0; p.val = 5600; p.data["black"] = 470; p.data["white"] = 4590; p.data["r"] = 634; p.data["d"] = 946; p.data["d16"] = 267; p.data["r16"] = 380;
points[914]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 70; p.county = 0; p.val = 6790; p.data["black"] = 1605; p.data["white"] = 4770; p.data["r"] = 552; p.data["d"] = 627; p.data["d16"] = 1039; p.data["r16"] = 1205;
points[915]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 68; p.county = 0; p.val = 1490; p.data["black"] = 385; p.data["white"] = 1030; p.data["r"] = 590; p.data["d"] = 493; p.data["d16"] = 0; p.data["r16"] = 0;
points[916]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 69; p.county = 0; p.val = 7985; p.data["black"] = 1415; p.data["white"] = 6240; p.data["r"] = 390; p.data["d"] = 472; p.data["d16"] = 356; p.data["r16"] = 582;
points[917]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 66; p.county = 0; p.val = 520; p.data["black"] = 140; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 89; p.data["r16"] = 85;
points[918]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 60; p.county = 0; p.val = 2145; p.data["black"] = 1945; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 938; p.data["r16"] = 183;
points[919]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 63; p.county = 0; p.val = 715; p.data["black"] = 150; p.data["white"] = 545; p.data["r"] = 74; p.data["d"] = 155; p.data["d16"] = 0; p.data["r16"] = 0;
points[920]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 61; p.county = 0; p.val = 550; p.data["black"] = 390; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[921]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 63; p.county = 0; p.val = 1790; p.data["black"] = 595; p.data["white"] = 1135; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 199; p.data["r16"] = 894;
points[922]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 43; p.county = 0; p.val = 500; p.data["black"] = 265; p.data["white"] = 235; p.data["r"] = 263; p.data["d"] = 209; p.data["d16"] = 0; p.data["r16"] = 0;
points[923]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 35; p.county = 0; p.val = 920; p.data["black"] = 95; p.data["white"] = 810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[924]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 37; p.county = 0; p.val = 1025; p.data["black"] = 290; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[925]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 37; p.county = 0; p.val = 1325; p.data["black"] = 0; p.data["white"] = 1310; p.data["r"] = 92; p.data["d"] = 499; p.data["d16"] = 0; p.data["r16"] = 0;
points[926]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 41; p.county = 0; p.val = 1260; p.data["black"] = 165; p.data["white"] = 1065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 91; p.data["r16"] = 359;
points[927]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 61; p.county = 0; p.val = 265; p.data["black"] = 265; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[928]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 61; p.county = 0; p.val = 445; p.data["black"] = 280; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 538; p.data["r16"] = 574;
points[929]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 59; p.county = 0; p.val = 770; p.data["black"] = 655; p.data["white"] = 115; p.data["r"] = 180; p.data["d"] = 203; p.data["d16"] = 0; p.data["r16"] = 0;
points[930]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 60; p.county = 0; p.val = 805; p.data["black"] = 205; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[931]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 60; p.county = 0; p.val = 725; p.data["black"] = 240; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[932]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 62; p.county = 0; p.val = 1050; p.data["black"] = 875; p.data["white"] = 170; p.data["r"] = 527; p.data["d"] = 187; p.data["d16"] = 0; p.data["r16"] = 0;
points[933]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 58; p.county = 0; p.val = 595; p.data["black"] = 175; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[934]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 60; p.county = 0; p.val = 690; p.data["black"] = 660; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[935]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 65; p.county = 0; p.val = 575; p.data["black"] = 155; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 119; p.data["r16"] = 151;
points[936]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 63; p.county = 0; p.val = 390; p.data["black"] = 125; p.data["white"] = 255; p.data["r"] = 70; p.data["d"] = 29; p.data["d16"] = 0; p.data["r16"] = 0;
points[937]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 66; p.county = 0; p.val = 565; p.data["black"] = 250; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 43; p.data["r16"] = 101;
points[938]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 30; p.county = 0; p.val = 935; p.data["black"] = 400; p.data["white"] = 530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 103; p.data["r16"] = 143;
points[939]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 0; p.val = 525; p.data["black"] = 70; p.data["white"] = 455; p.data["r"] = 55; p.data["d"] = 210; p.data["d16"] = 0; p.data["r16"] = 0;
points[940]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 31; p.county = 0; p.val = 550; p.data["black"] = 270; p.data["white"] = 285; p.data["r"] = 188; p.data["d"] = 89; p.data["d16"] = 217; p.data["r16"] = 108;
points[941]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 28; p.county = 0; p.val = 835; p.data["black"] = 275; p.data["white"] = 515; p.data["r"] = 38; p.data["d"] = 73; p.data["d16"] = 63; p.data["r16"] = 76;
points[942]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 30; p.county = 0; p.val = 1060; p.data["black"] = 800; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[943]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 34; p.county = 0; p.val = 765; p.data["black"] = 545; p.data["white"] = 135; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[944]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 31; p.county = 0; p.val = 540; p.data["black"] = 435; p.data["white"] = 105; p.data["r"] = 323; p.data["d"] = 63; p.data["d16"] = 392; p.data["r16"] = 66;
points[945]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 34; p.county = 0; p.val = 970; p.data["black"] = 515; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[946]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 32; p.county = 0; p.val = 825; p.data["black"] = 470; p.data["white"] = 325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[947]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 36; p.county = 0; p.val = 500; p.data["black"] = 435; p.data["white"] = 60; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[948]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 32; p.county = 0; p.val = 2150; p.data["black"] = 1630; p.data["white"] = 430; p.data["r"] = 134; p.data["d"] = 28; p.data["d16"] = 153; p.data["r16"] = 29;
points[949]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 16; p.county = 0; p.val = 1910; p.data["black"] = 405; p.data["white"] = 1395; p.data["r"] = 719; p.data["d"] = 896; p.data["d16"] = 0; p.data["r16"] = 0;
points[950]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 15; p.county = 0; p.val = 3925; p.data["black"] = 1340; p.data["white"] = 2155; p.data["r"] = 968; p.data["d"] = 937; p.data["d16"] = 875; p.data["r16"] = 1105;
points[951]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 33; p.county = 0; p.val = 915; p.data["black"] = 325; p.data["white"] = 550; p.data["r"] = 289; p.data["d"] = 156; p.data["d16"] = 0; p.data["r16"] = 0;
points[952]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 75; p.county = 0; p.val = 2530; p.data["black"] = 2110; p.data["white"] = 370; p.data["r"] = 439; p.data["d"] = 819; p.data["d16"] = 1382; p.data["r16"] = 968;
points[953]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 76; p.county = 0; p.val = 2425; p.data["black"] = 0; p.data["white"] = 2285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[954]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 16; p.county = 0; p.val = 2770; p.data["black"] = 165; p.data["white"] = 2435; p.data["r"] = 204; p.data["d"] = 172; p.data["d16"] = 0; p.data["r16"] = 0;
points[955]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 31; p.county = 0; p.val = 1050; p.data["black"] = 405; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 133; p.data["r16"] = 44;
points[956]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 14; p.county = 0; p.val = 785; p.data["black"] = 395; p.data["white"] = 305; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[957]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 39; p.county = 0; p.val = 6560; p.data["black"] = 1495; p.data["white"] = 4715; p.data["r"] = 409; p.data["d"] = 508; p.data["d16"] = 0; p.data["r16"] = 0;
points[958]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 77; p.county = 0; p.val = 1725; p.data["black"] = 4; p.data["white"] = 1710; p.data["r"] = 438; p.data["d"] = 488; p.data["d16"] = 0; p.data["r16"] = 0;
points[959]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 77; p.county = 0; p.val = 5475; p.data["black"] = 545; p.data["white"] = 4790; p.data["r"] = 734; p.data["d"] = 674; p.data["d16"] = 1416; p.data["r16"] = 1912;
points[960]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 15; p.county = 0; p.val = 2950; p.data["black"] = 1045; p.data["white"] = 1830; p.data["r"] = 710; p.data["d"] = 569; p.data["d16"] = 771; p.data["r16"] = 755;
points[961]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 9; p.county = 0; p.val = 4125; p.data["black"] = 960; p.data["white"] = 2995; p.data["r"] = 976; p.data["d"] = 1595; p.data["d16"] = 1427; p.data["r16"] = 2727;
points[962]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 81; p.county = 0; p.val = 925; p.data["black"] = 0; p.data["white"] = 890; p.data["r"] = 422; p.data["d"] = 332; p.data["d16"] = 0; p.data["r16"] = 0;
points[963]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 77; p.county = 0; p.val = 2285; p.data["black"] = 530; p.data["white"] = 1680; p.data["r"] = 634; p.data["d"] = 455; p.data["d16"] = 0; p.data["r16"] = 0;
points[964]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 81; p.county = 0; p.val = 1075; p.data["black"] = 255; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[965]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 77; p.county = 0; p.val = 3615; p.data["black"] = 470; p.data["white"] = 2730; p.data["r"] = 411; p.data["d"] = 131; p.data["d16"] = 1576; p.data["r16"] = 810;
points[966]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 74; p.county = 0; p.val = 4840; p.data["black"] = 1190; p.data["white"] = 3530; p.data["r"] = 988; p.data["d"] = 589; p.data["d16"] = 379; p.data["r16"] = 397;
points[967]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 82; p.county = 0; p.val = 995; p.data["black"] = 4; p.data["white"] = 970; p.data["r"] = 453; p.data["d"] = 81; p.data["d16"] = 0; p.data["r16"] = 0;
points[968]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 82; p.county = 0; p.val = 160; p.data["black"] = 15; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 599; p.data["r16"] = 555;
points[969]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 75; p.county = 0; p.val = 3415; p.data["black"] = 345; p.data["white"] = 2905; p.data["r"] = 496; p.data["d"] = 163; p.data["d16"] = 0; p.data["r16"] = 0;
points[970]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 74; p.county = 0; p.val = 4950; p.data["black"] = 825; p.data["white"] = 3905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 930; p.data["r16"] = 1720;
points[971]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 69; p.county = 0; p.val = 1255; p.data["black"] = 580; p.data["white"] = 630; p.data["r"] = 291; p.data["d"] = 256; p.data["d16"] = 350; p.data["r16"] = 280;
points[972]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 60; p.county = 0; p.val = 645; p.data["black"] = 270; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[973]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 37; p.county = 0; p.val = 1870; p.data["black"] = 1050; p.data["white"] = 610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[974]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 39; p.county = 0; p.val = 470; p.data["black"] = 230; p.data["white"] = 210; p.data["r"] = 368; p.data["d"] = 193; p.data["d16"] = 0; p.data["r16"] = 0;
points[975]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 39; p.county = 0; p.val = 710; p.data["black"] = 150; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[976]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 17; p.county = 0; p.val = 1745; p.data["black"] = 330; p.data["white"] = 1340; p.data["r"] = 268; p.data["d"] = 411; p.data["d16"] = 0; p.data["r16"] = 0;
points[977]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 13; p.county = 0; p.val = 645; p.data["black"] = 265; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 205; p.data["r16"] = 401;
points[978]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 2; p.county = 0; p.val = 1610; p.data["black"] = 125; p.data["white"] = 1405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[979]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 5; p.county = 0; p.val = 1515; p.data["black"] = 270; p.data["white"] = 1245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[980]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 5; p.county = 0; p.val = 370; p.data["black"] = 0; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 19; p.data["r16"] = 379;
points[981]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 5; p.county = 0; p.val = 1195; p.data["black"] = 270; p.data["white"] = 920; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[982]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 14; p.county = 0; p.val = 1295; p.data["black"] = 60; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[983]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 8; p.county = 0; p.val = 835; p.data["black"] = 0; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[984]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 10; p.county = 0; p.val = 1920; p.data["black"] = 65; p.data["white"] = 1680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 172; p.data["r16"] = 840;
points[985]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 9; p.county = 0; p.val = 1490; p.data["black"] = 10; p.data["white"] = 1480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[986]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 16; p.county = 0; p.val = 8560; p.data["black"] = 465; p.data["white"] = 7575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[987]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 10; p.county = 0; p.val = 1395; p.data["black"] = 20; p.data["white"] = 1375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 103; p.data["r16"] = 765;
points[988]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 12; p.county = 0; p.val = 2555; p.data["black"] = 4; p.data["white"] = 2435; p.data["r"] = 124; p.data["d"] = 536; p.data["d16"] = 108; p.data["r16"] = 709;
points[989]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 14; p.county = 0; p.val = 910; p.data["black"] = 4; p.data["white"] = 895; p.data["r"] = 127; p.data["d"] = 581; p.data["d16"] = 0; p.data["r16"] = 0;
points[990]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 29; p.county = 0; p.val = 695; p.data["black"] = 80; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[991]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 18; p.county = 0; p.val = 3040; p.data["black"] = 1905; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[992]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 26; p.county = 0; p.val = 685; p.data["black"] = 175; p.data["white"] = 510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[993]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 33; p.county = 0; p.val = 715; p.data["black"] = 230; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 463; p.data["r16"] = 539;
points[994]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 28; p.county = 0; p.val = 995; p.data["black"] = 315; p.data["white"] = 520; p.data["r"] = 350; p.data["d"] = 432; p.data["d16"] = 0; p.data["r16"] = 0;
points[995]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 20; p.county = 0; p.val = 1305; p.data["black"] = 115; p.data["white"] = 1180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[996]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 24; p.county = 0; p.val = 1120; p.data["black"] = 435; p.data["white"] = 650; p.data["r"] = 327; p.data["d"] = 417; p.data["d16"] = 406; p.data["r16"] = 528;
points[997]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 31; p.county = 0; p.val = 1550; p.data["black"] = 485; p.data["white"] = 1040; p.data["r"] = 132; p.data["d"] = 179; p.data["d16"] = 165; p.data["r16"] = 255;
points[998]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 23; p.county = 0; p.val = 505; p.data["black"] = 200; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[999]=p;}

}
void scPoints1(){

if (1==1){ Point p;
p.x = 58; p.y = 30; p.county = 0; p.val = 685; p.data["black"] = 210; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1000]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 23; p.county = 0; p.val = 865; p.data["black"] = 75; p.data["white"] = 775; p.data["r"] = 42; p.data["d"] = 167; p.data["d16"] = 0; p.data["r16"] = 0;
points[1001]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 24; p.county = 0; p.val = 645; p.data["black"] = 80; p.data["white"] = 565; p.data["r"] = 270; p.data["d"] = 568; p.data["d16"] = 322; p.data["r16"] = 757;
points[1002]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 19; p.county = 0; p.val = 760; p.data["black"] = 145; p.data["white"] = 555; p.data["r"] = 93; p.data["d"] = 205; p.data["d16"] = 120; p.data["r16"] = 228;
points[1003]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 28; p.county = 0; p.val = 1320; p.data["black"] = 330; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1004]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 29; p.county = 0; p.val = 2150; p.data["black"] = 540; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1005]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 27; p.county = 0; p.val = 1580; p.data["black"] = 280; p.data["white"] = 1260; p.data["r"] = 256; p.data["d"] = 458; p.data["d16"] = 0; p.data["r16"] = 0;
points[1006]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 42; p.county = 0; p.val = 760; p.data["black"] = 570; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1007]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 30; p.county = 0; p.val = 4475; p.data["black"] = 2335; p.data["white"] = 1995; p.data["r"] = 96; p.data["d"] = 80; p.data["d16"] = 83; p.data["r16"] = 104;
points[1008]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 14; p.county = 0; p.val = 745; p.data["black"] = 415; p.data["white"] = 330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1009]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 12; p.county = 0; p.val = 1495; p.data["black"] = 80; p.data["white"] = 1365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1010]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 14; p.county = 0; p.val = 1235; p.data["black"] = 235; p.data["white"] = 1000; p.data["r"] = 328; p.data["d"] = 472; p.data["d16"] = 0; p.data["r16"] = 0;
points[1011]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 13; p.county = 0; p.val = 1465; p.data["black"] = 415; p.data["white"] = 1050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1012]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 15; p.county = 0; p.val = 840; p.data["black"] = 290; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 108; p.data["r16"] = 377;
points[1013]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 18; p.county = 0; p.val = 665; p.data["black"] = 50; p.data["white"] = 615; p.data["r"] = 149; p.data["d"] = 209; p.data["d16"] = 0; p.data["r16"] = 0;
points[1014]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 15; p.county = 0; p.val = 965; p.data["black"] = 0; p.data["white"] = 945; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1015]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 13; p.county = 0; p.val = 755; p.data["black"] = 315; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1016]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 66; p.county = 0; p.val = 1535; p.data["black"] = 600; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1017]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 14; p.county = 0; p.val = 2545; p.data["black"] = 70; p.data["white"] = 2390; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1018]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 19; p.county = 0; p.val = 2050; p.data["black"] = 70; p.data["white"] = 1960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1019]=p;}
if (1==1){ Point p;
p.x = 3; p.y = 9; p.county = 0; p.val = 855; p.data["black"] = 0; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 160; p.data["r16"] = 565;
points[1020]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 15; p.county = 0; p.val = 1035; p.data["black"] = 85; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 321; p.data["r16"] = 248;
points[1021]=p;}
if (1==1){ Point p;
p.x = 2; p.y = 17; p.county = 0; p.val = 1375; p.data["black"] = 95; p.data["white"] = 1260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 49; p.data["r16"] = 423;
points[1022]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 17; p.county = 0; p.val = 1695; p.data["black"] = 130; p.data["white"] = 1455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1023]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 14; p.county = 0; p.val = 700; p.data["black"] = 60; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1024]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 17; p.county = 0; p.val = 565; p.data["black"] = 30; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1025]=p;}
if (1==1){ Point p;
p.x = 2; p.y = 13; p.county = 0; p.val = 1450; p.data["black"] = 0; p.data["white"] = 1430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1026]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 17; p.county = 0; p.val = 2465; p.data["black"] = 165; p.data["white"] = 2190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1027]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 16; p.county = 0; p.val = 2415; p.data["black"] = 525; p.data["white"] = 1875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 318; p.data["r16"] = 534;
points[1028]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 87; p.county = 0; p.val = 625; p.data["black"] = 470; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 279; p.data["r16"] = 173;
points[1029]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 94; p.county = 0; p.val = 1100; p.data["black"] = 405; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 354; p.data["r16"] = 578;
points[1030]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 81; p.county = 0; p.val = 1185; p.data["black"] = 340; p.data["white"] = 835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 160; p.data["r16"] = 407;
points[1031]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 90; p.county = 0; p.val = 1150; p.data["black"] = 535; p.data["white"] = 390; p.data["r"] = 266; p.data["d"] = 209; p.data["d16"] = 346; p.data["r16"] = 311;
points[1032]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 22; p.county = 0; p.val = 880; p.data["black"] = 620; p.data["white"] = 170; p.data["r"] = 75; p.data["d"] = 14; p.data["d16"] = 110; p.data["r16"] = 60;
points[1033]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 92; p.county = 0; p.val = 1100; p.data["black"] = 510; p.data["white"] = 555; p.data["r"] = 428; p.data["d"] = 377; p.data["d16"] = 0; p.data["r16"] = 0;
points[1034]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 97; p.county = 0; p.val = 1630; p.data["black"] = 965; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 826; p.data["r16"] = 430;
points[1035]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 83; p.county = 0; p.val = 535; p.data["black"] = 480; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 426; p.data["r16"] = 45;
points[1036]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 85; p.county = 0; p.val = 1155; p.data["black"] = 365; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1037]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 40; p.county = 0; p.val = 3695; p.data["black"] = 375; p.data["white"] = 3215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1038]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 47; p.county = 0; p.val = 1405; p.data["black"] = 220; p.data["white"] = 1160; p.data["r"] = 112; p.data["d"] = 318; p.data["d16"] = 0; p.data["r16"] = 0;
points[1039]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 38; p.county = 0; p.val = 7250; p.data["black"] = 900; p.data["white"] = 5880; p.data["r"] = 508; p.data["d"] = 644; p.data["d16"] = 755; p.data["r16"] = 1556;
points[1040]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 69; p.county = 0; p.val = 470; p.data["black"] = 300; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1041]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 25; p.county = 0; p.val = 1080; p.data["black"] = 90; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1042]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 26; p.county = 0; p.val = 780; p.data["black"] = 290; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1043]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 29; p.county = 0; p.val = 665; p.data["black"] = 555; p.data["white"] = 110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1044]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 27; p.county = 0; p.val = 1540; p.data["black"] = 740; p.data["white"] = 685; p.data["r"] = 380; p.data["d"] = 176; p.data["d16"] = 0; p.data["r16"] = 0;
points[1045]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 26; p.county = 0; p.val = 2375; p.data["black"] = 1450; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1046]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 29; p.county = 0; p.val = 1785; p.data["black"] = 795; p.data["white"] = 685; p.data["r"] = 345; p.data["d"] = 233; p.data["d16"] = 0; p.data["r16"] = 0;
points[1047]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 22; p.county = 0; p.val = 865; p.data["black"] = 745; p.data["white"] = 110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1048]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 25; p.county = 0; p.val = 1380; p.data["black"] = 945; p.data["white"] = 410; p.data["r"] = 564; p.data["d"] = 161; p.data["d16"] = 884; p.data["r16"] = 437;
points[1049]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 22; p.county = 0; p.val = 1045; p.data["black"] = 255; p.data["white"] = 785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 320; p.data["r16"] = 293;
points[1050]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 29; p.county = 0; p.val = 1385; p.data["black"] = 1065; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1051]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 25; p.county = 0; p.val = 490; p.data["black"] = 90; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1052]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 27; p.county = 0; p.val = 660; p.data["black"] = 525; p.data["white"] = 135; p.data["r"] = 252; p.data["d"] = 78; p.data["d16"] = 0; p.data["r16"] = 0;
points[1053]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 28; p.county = 0; p.val = 965; p.data["black"] = 440; p.data["white"] = 525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1054]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 9; p.county = 0; p.val = 870; p.data["black"] = 0; p.data["white"] = 835; p.data["r"] = 172; p.data["d"] = 640; p.data["d16"] = 0; p.data["r16"] = 0;
points[1055]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 46; p.county = 0; p.val = 655; p.data["black"] = 410; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1056]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 62; p.county = 0; p.val = 980; p.data["black"] = 0; p.data["white"] = 970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1057]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 17; p.county = 0; p.val = 810; p.data["black"] = 350; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1058]=p;}
if (1==1){ Point p;
p.x = 3; p.y = 19; p.county = 0; p.val = 710; p.data["black"] = 0; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 302; p.data["r16"] = 1529;
points[1059]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 23; p.county = 0; p.val = 2525; p.data["black"] = 240; p.data["white"] = 2220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1060]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 16; p.county = 0; p.val = 1760; p.data["black"] = 225; p.data["white"] = 1485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1061]=p;}
if (1==1){ Point p;
p.x = 11; p.y = 16; p.county = 0; p.val = 3560; p.data["black"] = 390; p.data["white"] = 2900; p.data["r"] = 307; p.data["d"] = 792; p.data["d16"] = 0; p.data["r16"] = 0;
points[1062]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 18; p.county = 0; p.val = 635; p.data["black"] = 125; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1063]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 20; p.county = 0; p.val = 955; p.data["black"] = 50; p.data["white"] = 890; p.data["r"] = 110; p.data["d"] = 320; p.data["d16"] = 0; p.data["r16"] = 0;
points[1064]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 21; p.county = 0; p.val = 3850; p.data["black"] = 460; p.data["white"] = 3215; p.data["r"] = 231; p.data["d"] = 377; p.data["d16"] = 270; p.data["r16"] = 496;
points[1065]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 29; p.county = 0; p.val = 1150; p.data["black"] = 110; p.data["white"] = 1040; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1066]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 25; p.county = 0; p.val = 800; p.data["black"] = 120; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1067]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 25; p.county = 0; p.val = 1365; p.data["black"] = 245; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1068]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 21; p.county = 0; p.val = 5085; p.data["black"] = 675; p.data["white"] = 4170; p.data["r"] = 142; p.data["d"] = 335; p.data["d16"] = 0; p.data["r16"] = 0;
points[1069]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 20; p.county = 0; p.val = 1120; p.data["black"] = 55; p.data["white"] = 1070; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1070]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 20; p.county = 0; p.val = 2325; p.data["black"] = 410; p.data["white"] = 1835; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 144; p.data["r16"] = 366;
points[1071]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 54; p.county = 0; p.val = 7685; p.data["black"] = 1630; p.data["white"] = 5510; p.data["r"] = 750; p.data["d"] = 1209; p.data["d16"] = 516; p.data["r16"] = 217;
points[1072]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 54; p.county = 0; p.val = 1620; p.data["black"] = 970; p.data["white"] = 600; p.data["r"] = 168; p.data["d"] = 498; p.data["d16"] = 0; p.data["r16"] = 0;
points[1073]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 53; p.county = 0; p.val = 1060; p.data["black"] = 115; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 506; p.data["r16"] = 912;
points[1074]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 80; p.county = 0; p.val = 5025; p.data["black"] = 1320; p.data["white"] = 3320; p.data["r"] = 1086; p.data["d"] = 492; p.data["d16"] = 1660; p.data["r16"] = 1235;
points[1075]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 78; p.county = 0; p.val = 2045; p.data["black"] = 50; p.data["white"] = 1995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 360; p.data["r16"] = 685;
points[1076]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 78; p.county = 0; p.val = 2095; p.data["black"] = 1690; p.data["white"] = 410; p.data["r"] = 193; p.data["d"] = 53; p.data["d16"] = 261; p.data["r16"] = 65;
points[1077]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 31; p.county = 0; p.val = 1290; p.data["black"] = 190; p.data["white"] = 1020; p.data["r"] = 211; p.data["d"] = 243; p.data["d16"] = 503; p.data["r16"] = 701;
points[1078]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 26; p.county = 0; p.val = 900; p.data["black"] = 385; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1079]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 29; p.county = 0; p.val = 930; p.data["black"] = 395; p.data["white"] = 530; p.data["r"] = 50; p.data["d"] = 120; p.data["d16"] = 0; p.data["r16"] = 0;
points[1080]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 70; p.county = 0; p.val = 655; p.data["black"] = 630; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1081]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 71; p.county = 0; p.val = 925; p.data["black"] = 760; p.data["white"] = 165; p.data["r"] = 201; p.data["d"] = 94; p.data["d16"] = 259; p.data["r16"] = 109;
points[1082]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 49; p.county = 0; p.val = 1190; p.data["black"] = 255; p.data["white"] = 920; p.data["r"] = 657; p.data["d"] = 364; p.data["d16"] = 0; p.data["r16"] = 0;
points[1083]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 50; p.county = 0; p.val = 760; p.data["black"] = 500; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1084]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 51; p.county = 0; p.val = 1185; p.data["black"] = 135; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1085]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 49; p.county = 0; p.val = 1760; p.data["black"] = 35; p.data["white"] = 1690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1086]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 0; p.val = 530; p.data["black"] = 220; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1087]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 50; p.county = 0; p.val = 475; p.data["black"] = 0; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 750; p.data["r16"] = 3021;
points[1088]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 95; p.county = 0; p.val = 2045; p.data["black"] = 300; p.data["white"] = 1505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1089]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 94; p.county = 0; p.val = 930; p.data["black"] = 0; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1090]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 42; p.county = 0; p.val = 1935; p.data["black"] = 705; p.data["white"] = 1170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1091]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 46; p.county = 0; p.val = 400; p.data["black"] = 195; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1092]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 37; p.county = 0; p.val = 1470; p.data["black"] = 805; p.data["white"] = 535; p.data["r"] = 302; p.data["d"] = 187; p.data["d16"] = 0; p.data["r16"] = 0;
points[1093]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 38; p.county = 0; p.val = 730; p.data["black"] = 255; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1094]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 41; p.county = 0; p.val = 1095; p.data["black"] = 555; p.data["white"] = 490; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1095]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 43; p.county = 0; p.val = 2240; p.data["black"] = 900; p.data["white"] = 1325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1096]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 40; p.county = 0; p.val = 755; p.data["black"] = 480; p.data["white"] = 265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1097]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 36; p.county = 0; p.val = 1365; p.data["black"] = 1090; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1098]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 38; p.county = 0; p.val = 1620; p.data["black"] = 515; p.data["white"] = 1040; p.data["r"] = 314; p.data["d"] = 396; p.data["d16"] = 0; p.data["r16"] = 0;
points[1099]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 39; p.county = 0; p.val = 845; p.data["black"] = 405; p.data["white"] = 440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 626; p.data["r16"] = 396;
points[1100]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 44; p.county = 0; p.val = 2205; p.data["black"] = 385; p.data["white"] = 1720; p.data["r"] = 516; p.data["d"] = 728; p.data["d16"] = 440; p.data["r16"] = 667;
points[1101]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 44; p.county = 0; p.val = 2055; p.data["black"] = 670; p.data["white"] = 1300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1102]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 37; p.county = 0; p.val = 815; p.data["black"] = 485; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1103]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 38; p.county = 0; p.val = 805; p.data["black"] = 460; p.data["white"] = 345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1104]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 75; p.county = 0; p.val = 1170; p.data["black"] = 485; p.data["white"] = 610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1105]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 42; p.county = 0; p.val = 705; p.data["black"] = 510; p.data["white"] = 190; p.data["r"] = 428; p.data["d"] = 31; p.data["d16"] = 0; p.data["r16"] = 0;
points[1106]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 36; p.county = 0; p.val = 1560; p.data["black"] = 1205; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 1105; p.data["r16"] = 180;
points[1107]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 41; p.county = 0; p.val = 3290; p.data["black"] = 2995; p.data["white"] = 185; p.data["r"] = 235; p.data["d"] = 36; p.data["d16"] = 0; p.data["r16"] = 0;
points[1108]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 12; p.county = 0; p.val = 1705; p.data["black"] = 50; p.data["white"] = 1595; p.data["r"] = 126; p.data["d"] = 701; p.data["d16"] = 119; p.data["r16"] = 840;
points[1109]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 11; p.county = 0; p.val = 780; p.data["black"] = 0; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1110]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 13; p.county = 0; p.val = 475; p.data["black"] = 0; p.data["white"] = 455; p.data["r"] = 308; p.data["d"] = 988; p.data["d16"] = 245; p.data["r16"] = 1060;
points[1111]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 17; p.county = 0; p.val = 1055; p.data["black"] = 175; p.data["white"] = 860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1112]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 15; p.county = 0; p.val = 905; p.data["black"] = 15; p.data["white"] = 865; p.data["r"] = 381; p.data["d"] = 616; p.data["d16"] = 0; p.data["r16"] = 0;
points[1113]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 39; p.county = 0; p.val = 600; p.data["black"] = 380; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1114]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 51; p.county = 0; p.val = 3050; p.data["black"] = 890; p.data["white"] = 2075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1115]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 40; p.county = 0; p.val = 810; p.data["black"] = 215; p.data["white"] = 595; p.data["r"] = 488; p.data["d"] = 337; p.data["d16"] = 0; p.data["r16"] = 0;
points[1116]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 15; p.county = 0; p.val = 3195; p.data["black"] = 2455; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 329; p.data["r16"] = 609;
points[1117]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 10; p.county = 0; p.val = 3745; p.data["black"] = 640; p.data["white"] = 2885; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1118]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 11; p.county = 0; p.val = 1190; p.data["black"] = 225; p.data["white"] = 925; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1119]=p;}
if (1==1){ Point p;
p.x = 0; p.y = 14; p.county = 0; p.val = 615; p.data["black"] = 10; p.data["white"] = 610; p.data["r"] = 88; p.data["d"] = 173; p.data["d16"] = 0; p.data["r16"] = 0;
points[1120]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 9; p.county = 0; p.val = 710; p.data["black"] = 4; p.data["white"] = 705; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1121]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 12; p.county = 0; p.val = 1355; p.data["black"] = 0; p.data["white"] = 1330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1122]=p;}
if (1==1){ Point p;
p.x = 4; p.y = 13; p.county = 0; p.val = 1875; p.data["black"] = 25; p.data["white"] = 1610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1123]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 15; p.county = 0; p.val = 1070; p.data["black"] = 30; p.data["white"] = 980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1124]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 8; p.county = 0; p.val = 5295; p.data["black"] = 810; p.data["white"] = 4110; p.data["r"] = 441; p.data["d"] = 677; p.data["d16"] = 0; p.data["r16"] = 0;
points[1125]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 13; p.county = 0; p.val = 6415; p.data["black"] = 2495; p.data["white"] = 3530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 903; p.data["r16"] = 687;
points[1126]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 14; p.county = 0; p.val = 1975; p.data["black"] = 345; p.data["white"] = 1435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 968; p.data["r16"] = 772;
points[1127]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 5; p.county = 0; p.val = 830; p.data["black"] = 0; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1128]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 5; p.county = 0; p.val = 1675; p.data["black"] = 65; p.data["white"] = 1575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1129]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 9; p.county = 0; p.val = 7565; p.data["black"] = 530; p.data["white"] = 6100; p.data["r"] = 603; p.data["d"] = 676; p.data["d16"] = 1204; p.data["r16"] = 2201;
points[1130]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 18; p.county = 0; p.val = 1020; p.data["black"] = 60; p.data["white"] = 950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1131]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 17; p.county = 0; p.val = 2925; p.data["black"] = 1120; p.data["white"] = 1680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1132]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 29; p.county = 0; p.val = 1205; p.data["black"] = 225; p.data["white"] = 940; p.data["r"] = 298; p.data["d"] = 240; p.data["d16"] = 0; p.data["r16"] = 0;
points[1133]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 30; p.county = 0; p.val = 795; p.data["black"] = 170; p.data["white"] = 620; p.data["r"] = 170; p.data["d"] = 413; p.data["d16"] = 285; p.data["r16"] = 301;
points[1134]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 30; p.county = 0; p.val = 430; p.data["black"] = 160; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1135]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 39; p.county = 0; p.val = 1980; p.data["black"] = 635; p.data["white"] = 1240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 356; p.data["r16"] = 417;
points[1136]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 43; p.county = 0; p.val = 695; p.data["black"] = 285; p.data["white"] = 330; p.data["r"] = 309; p.data["d"] = 426; p.data["d16"] = 0; p.data["r16"] = 0;
points[1137]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 46; p.county = 0; p.val = 1230; p.data["black"] = 440; p.data["white"] = 785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1138]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 39; p.county = 0; p.val = 450; p.data["black"] = 340; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1139]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 18; p.county = 0; p.val = 1720; p.data["black"] = 325; p.data["white"] = 1330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1140]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 15; p.county = 0; p.val = 1070; p.data["black"] = 250; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 90; p.data["r16"] = 149;
points[1141]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 16; p.county = 0; p.val = 845; p.data["black"] = 325; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1142]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 16; p.county = 0; p.val = 1760; p.data["black"] = 460; p.data["white"] = 1290; p.data["r"] = 35; p.data["d"] = 141; p.data["d16"] = 0; p.data["r16"] = 0;
points[1143]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 10; p.county = 0; p.val = 2385; p.data["black"] = 1265; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 849; p.data["r16"] = 898;
points[1144]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 6; p.county = 0; p.val = 2305; p.data["black"] = 75; p.data["white"] = 2105; p.data["r"] = 192; p.data["d"] = 703; p.data["d16"] = 0; p.data["r16"] = 0;
points[1145]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 6; p.county = 0; p.val = 1085; p.data["black"] = 145; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1146]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 8; p.county = 0; p.val = 4360; p.data["black"] = 150; p.data["white"] = 4170; p.data["r"] = 653; p.data["d"] = 1619; p.data["d16"] = 268; p.data["r16"] = 657;
points[1147]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 9; p.county = 0; p.val = 1955; p.data["black"] = 25; p.data["white"] = 1930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 97; p.data["r16"] = 744;
points[1148]=p;}
if (1==1){ Point p;
p.x = 12; p.y = 7; p.county = 0; p.val = 840; p.data["black"] = 0; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1149]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 9; p.county = 0; p.val = 1530; p.data["black"] = 45; p.data["white"] = 1465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1150]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 11; p.county = 0; p.val = 3765; p.data["black"] = 835; p.data["white"] = 2830; p.data["r"] = 340; p.data["d"] = 482; p.data["d16"] = 262; p.data["r16"] = 1045;
points[1151]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 30; p.county = 0; p.val = 660; p.data["black"] = 355; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1152]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 32; p.county = 0; p.val = 610; p.data["black"] = 415; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1153]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 40; p.county = 0; p.val = 1185; p.data["black"] = 650; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1154]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 30; p.county = 0; p.val = 965; p.data["black"] = 250; p.data["white"] = 670; p.data["r"] = 180; p.data["d"] = 210; p.data["d16"] = 0; p.data["r16"] = 0;
points[1155]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 74; p.county = 0; p.val = 5575; p.data["black"] = 855; p.data["white"] = 4525; p.data["r"] = 430; p.data["d"] = 678; p.data["d16"] = 534; p.data["r16"] = 1060;
points[1156]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 52; p.county = 0; p.val = 1850; p.data["black"] = 390; p.data["white"] = 1375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1157]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 55; p.county = 0; p.val = 1890; p.data["black"] = 120; p.data["white"] = 1640; p.data["r"] = 226; p.data["d"] = 725; p.data["d16"] = 254; p.data["r16"] = 724;
points[1158]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 83; p.county = 0; p.val = 140; p.data["black"] = 0; p.data["white"] = 135; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1159]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 12; p.county = 0; p.val = 8610; p.data["black"] = 1005; p.data["white"] = 6510; p.data["r"] = 754; p.data["d"] = 678; p.data["d16"] = 1194; p.data["r16"] = 1687;
points[1160]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 24; p.county = 0; p.val = 905; p.data["black"] = 315; p.data["white"] = 450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1161]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 30; p.county = 0; p.val = 1655; p.data["black"] = 525; p.data["white"] = 1105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1162]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 22; p.county = 0; p.val = 950; p.data["black"] = 230; p.data["white"] = 710; p.data["r"] = 403; p.data["d"] = 352; p.data["d16"] = 0; p.data["r16"] = 0;
points[1163]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 13; p.county = 0; p.val = 630; p.data["black"] = 100; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1164]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 18; p.county = 0; p.val = 2360; p.data["black"] = 1600; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1165]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 16; p.county = 0; p.val = 590; p.data["black"] = 110; p.data["white"] = 435; p.data["r"] = 112; p.data["d"] = 291; p.data["d16"] = 0; p.data["r16"] = 0;
points[1166]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 16; p.county = 0; p.val = 375; p.data["black"] = 135; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1167]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 19; p.county = 0; p.val = 980; p.data["black"] = 225; p.data["white"] = 670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 634; p.data["r16"] = 258;
points[1168]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 18; p.county = 0; p.val = 685; p.data["black"] = 150; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1169]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 14; p.county = 0; p.val = 875; p.data["black"] = 295; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1170]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 14; p.county = 0; p.val = 765; p.data["black"] = 330; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1171]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 19; p.county = 0; p.val = 660; p.data["black"] = 485; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1172]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 17; p.county = 0; p.val = 1035; p.data["black"] = 305; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1173]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 17; p.county = 0; p.val = 3500; p.data["black"] = 2475; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 661; p.data["r16"] = 544;
points[1174]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 17; p.county = 0; p.val = 855; p.data["black"] = 85; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1175]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 19; p.county = 0; p.val = 1285; p.data["black"] = 355; p.data["white"] = 910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1176]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 23; p.county = 0; p.val = 985; p.data["black"] = 145; p.data["white"] = 810; p.data["r"] = 28; p.data["d"] = 234; p.data["d16"] = 0; p.data["r16"] = 0;
points[1177]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 23; p.county = 0; p.val = 795; p.data["black"] = 325; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1178]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 26; p.county = 0; p.val = 700; p.data["black"] = 290; p.data["white"] = 415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1179]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 20; p.county = 0; p.val = 1170; p.data["black"] = 595; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 818; p.data["r16"] = 307;
points[1180]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 59; p.county = 0; p.val = 600; p.data["black"] = 25; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1181]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 14; p.county = 0; p.val = 625; p.data["black"] = 385; p.data["white"] = 220; p.data["r"] = 359; p.data["d"] = 195; p.data["d16"] = 311; p.data["r16"] = 243;
points[1182]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 16; p.county = 0; p.val = 1210; p.data["black"] = 500; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 165; p.data["r16"] = 153;
points[1183]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 14; p.county = 0; p.val = 2590; p.data["black"] = 160; p.data["white"] = 2250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 67; p.data["r16"] = 140;
points[1184]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 33; p.county = 0; p.val = 1090; p.data["black"] = 60; p.data["white"] = 1025; p.data["r"] = 69; p.data["d"] = 351; p.data["d16"] = 0; p.data["r16"] = 0;
points[1185]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 11; p.county = 0; p.val = 1550; p.data["black"] = 0; p.data["white"] = 1480; p.data["r"] = 415; p.data["d"] = 1242; p.data["d16"] = 413; p.data["r16"] = 1479;
points[1186]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 15; p.county = 0; p.val = 1515; p.data["black"] = 15; p.data["white"] = 1470; p.data["r"] = 280; p.data["d"] = 728; p.data["d16"] = 0; p.data["r16"] = 0;
points[1187]=p;}
if (1==1){ Point p;
p.x = 6; p.y = 14; p.county = 0; p.val = 850; p.data["black"] = 10; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1188]=p;}
if (1==1){ Point p;
p.x = 5; p.y = 13; p.county = 0; p.val = 705; p.data["black"] = 4; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1189]=p;}
if (1==1){ Point p;
p.x = 7; p.y = 10; p.county = 0; p.val = 760; p.data["black"] = 0; p.data["white"] = 760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1190]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 6; p.county = 0; p.val = 1435; p.data["black"] = 60; p.data["white"] = 1340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1191]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 57; p.county = 0; p.val = 1490; p.data["black"] = 280; p.data["white"] = 1165; p.data["r"] = 800; p.data["d"] = 963; p.data["d16"] = 0; p.data["r16"] = 0;
points[1192]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 75; p.county = 0; p.val = 4465; p.data["black"] = 350; p.data["white"] = 3915; p.data["r"] = 341; p.data["d"] = 426; p.data["d16"] = 76; p.data["r16"] = 124;
points[1193]=p;}
if (1==1){ Point p;
p.x = 8; p.y = 18; p.county = 0; p.val = 1260; p.data["black"] = 160; p.data["white"] = 940; p.data["r"] = 317; p.data["d"] = 790; p.data["d16"] = 0; p.data["r16"] = 0;
points[1194]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 11; p.county = 0; p.val = 1310; p.data["black"] = 95; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1195]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 1; p.county = 0; p.val = 1205; p.data["black"] = 245; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1196]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 9; p.county = 0; p.val = 1180; p.data["black"] = 70; p.data["white"] = 1110; p.data["r"] = 386; p.data["d"] = 746; p.data["d16"] = 0; p.data["r16"] = 0;
points[1197]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 8; p.county = 0; p.val = 760; p.data["black"] = 20; p.data["white"] = 720; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1198]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 5; p.county = 0; p.val = 1450; p.data["black"] = 85; p.data["white"] = 1355; p.data["r"] = 193; p.data["d"] = 337; p.data["d16"] = 0; p.data["r16"] = 0;
points[1199]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 3; p.county = 0; p.val = 1030; p.data["black"] = 145; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1200]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 9; p.county = 0; p.val = 2375; p.data["black"] = 555; p.data["white"] = 1640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1201]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 10; p.county = 0; p.val = 3105; p.data["black"] = 275; p.data["white"] = 2455; p.data["r"] = 621; p.data["d"] = 1006; p.data["d16"] = 0; p.data["r16"] = 0;
points[1202]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 7; p.county = 0; p.val = 1245; p.data["black"] = 90; p.data["white"] = 1120; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1203]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 6; p.county = 0; p.val = 3860; p.data["black"] = 270; p.data["white"] = 3395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1204]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 7; p.county = 0; p.val = 2195; p.data["black"] = 580; p.data["white"] = 1510; p.data["r"] = 609; p.data["d"] = 644; p.data["d16"] = 0; p.data["r16"] = 0;
points[1205]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 11; p.county = 0; p.val = 3810; p.data["black"] = 45; p.data["white"] = 3545; p.data["r"] = 537; p.data["d"] = 1278; p.data["d16"] = 0; p.data["r16"] = 0;
points[1206]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 52; p.county = 0; p.val = 1335; p.data["black"] = 680; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1207]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 11; p.county = 0; p.val = 2070; p.data["black"] = 545; p.data["white"] = 1515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1208]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 10; p.county = 0; p.val = 2005; p.data["black"] = 190; p.data["white"] = 1730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1209]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 11; p.county = 0; p.val = 2010; p.data["black"] = 310; p.data["white"] = 1645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 470; p.data["r16"] = 1428;
points[1210]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 55; p.county = 0; p.val = 1060; p.data["black"] = 490; p.data["white"] = 555; p.data["r"] = 406; p.data["d"] = 169; p.data["d16"] = 0; p.data["r16"] = 0;
points[1211]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 56; p.county = 0; p.val = 860; p.data["black"] = 460; p.data["white"] = 355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1212]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 55; p.county = 0; p.val = 3075; p.data["black"] = 390; p.data["white"] = 2550; p.data["r"] = 669; p.data["d"] = 1664; p.data["d16"] = 349; p.data["r16"] = 777;
points[1213]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 57; p.county = 0; p.val = 910; p.data["black"] = 295; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1214]=p;}
if (1==1){ Point p;
p.x = 32; p.y = 58; p.county = 0; p.val = 2005; p.data["black"] = 675; p.data["white"] = 1180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1215]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 60; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1216]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 3; p.county = 0; p.val = 1570; p.data["black"] = 25; p.data["white"] = 1440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 200; p.data["r16"] = 1189;
points[1217]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 14; p.county = 0; p.val = 1690; p.data["black"] = 180; p.data["white"] = 1455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1218]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 13; p.county = 0; p.val = 1015; p.data["black"] = 305; p.data["white"] = 695; p.data["r"] = 287; p.data["d"] = 404; p.data["d16"] = 0; p.data["r16"] = 0;
points[1219]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 53; p.county = 0; p.val = 1025; p.data["black"] = 0; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1220]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 55; p.county = 0; p.val = 1170; p.data["black"] = 215; p.data["white"] = 820; p.data["r"] = 195; p.data["d"] = 295; p.data["d16"] = 0; p.data["r16"] = 0;
points[1221]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 51; p.county = 0; p.val = 2065; p.data["black"] = 450; p.data["white"] = 1565; p.data["r"] = 359; p.data["d"] = 516; p.data["d16"] = 0; p.data["r16"] = 0;
points[1222]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 46; p.county = 0; p.val = 1770; p.data["black"] = 60; p.data["white"] = 1580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 146; p.data["r16"] = 534;
points[1223]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 8; p.county = 0; p.val = 4425; p.data["black"] = 750; p.data["white"] = 3265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 730; p.data["r16"] = 1253;
points[1224]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 9; p.county = 0; p.val = 1665; p.data["black"] = 165; p.data["white"] = 1365; p.data["r"] = 135; p.data["d"] = 430; p.data["d16"] = 125; p.data["r16"] = 477;
points[1225]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 6; p.county = 0; p.val = 2825; p.data["black"] = 195; p.data["white"] = 2380; p.data["r"] = 272; p.data["d"] = 400; p.data["d16"] = 0; p.data["r16"] = 0;
points[1226]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 11; p.county = 0; p.val = 1440; p.data["black"] = 595; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 698; p.data["r16"] = 715;
points[1227]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 9; p.county = 0; p.val = 2480; p.data["black"] = 240; p.data["white"] = 2170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 243; p.data["r16"] = 925;
points[1228]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 6; p.county = 0; p.val = 1450; p.data["black"] = 75; p.data["white"] = 1335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 212; p.data["r16"] = 884;
points[1229]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 11; p.county = 0; p.val = 950; p.data["black"] = 200; p.data["white"] = 740; p.data["r"] = 158; p.data["d"] = 396; p.data["d16"] = 198; p.data["r16"] = 528;
points[1230]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 10; p.county = 0; p.val = 1060; p.data["black"] = 95; p.data["white"] = 930; p.data["r"] = 47; p.data["d"] = 212; p.data["d16"] = 56; p.data["r16"] = 261;
points[1231]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 5; p.county = 0; p.val = 1705; p.data["black"] = 25; p.data["white"] = 1600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1232]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 12; p.county = 0; p.val = 5640; p.data["black"] = 440; p.data["white"] = 4435; p.data["r"] = 610; p.data["d"] = 773; p.data["d16"] = 0; p.data["r16"] = 0;
points[1233]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 7; p.county = 0; p.val = 2395; p.data["black"] = 110; p.data["white"] = 2245; p.data["r"] = 371; p.data["d"] = 776; p.data["d16"] = 363; p.data["r16"] = 959;
points[1234]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 34; p.county = 0; p.val = 695; p.data["black"] = 65; p.data["white"] = 630; p.data["r"] = 264; p.data["d"] = 793; p.data["d16"] = 0; p.data["r16"] = 0;
points[1235]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 28; p.county = 0; p.val = 1655; p.data["black"] = 480; p.data["white"] = 1145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1236]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 7; p.county = 0; p.val = 1715; p.data["black"] = 95; p.data["white"] = 1560; p.data["r"] = 445; p.data["d"] = 867; p.data["d16"] = 177; p.data["r16"] = 917;
points[1237]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 29; p.county = 0; p.val = 1075; p.data["black"] = 525; p.data["white"] = 460; p.data["r"] = 339; p.data["d"] = 172; p.data["d16"] = 0; p.data["r16"] = 0;
points[1238]=p;}
if (1==1){ Point p;
p.x = 35; p.y = 28; p.county = 0; p.val = 650; p.data["black"] = 425; p.data["white"] = 205; p.data["r"] = 259; p.data["d"] = 62; p.data["d16"] = 0; p.data["r16"] = 0;
points[1239]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 33; p.county = 0; p.val = 860; p.data["black"] = 235; p.data["white"] = 625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1240]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 80; p.county = 0; p.val = 820; p.data["black"] = 0; p.data["white"] = 820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1241]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 83; p.county = 0; p.val = 665; p.data["black"] = 0; p.data["white"] = 650; p.data["r"] = 485; p.data["d"] = 243; p.data["d16"] = 713; p.data["r16"] = 986;
points[1242]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 83; p.county = 0; p.val = 1345; p.data["black"] = 680; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1243]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 74; p.county = 0; p.val = 1305; p.data["black"] = 0; p.data["white"] = 1305; p.data["r"] = 379; p.data["d"] = 538; p.data["d16"] = 0; p.data["r16"] = 0;
points[1244]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 40; p.county = 0; p.val = 4075; p.data["black"] = 2360; p.data["white"] = 1575; p.data["r"] = 1042; p.data["d"] = 35; p.data["d16"] = 1046; p.data["r16"] = 216;
points[1245]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 15; p.county = 0; p.val = 4205; p.data["black"] = 1270; p.data["white"] = 2780; p.data["r"] = 943; p.data["d"] = 899; p.data["d16"] = 0; p.data["r16"] = 0;
points[1246]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 16; p.county = 0; p.val = 855; p.data["black"] = 35; p.data["white"] = 645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1247]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 35; p.county = 0; p.val = 4645; p.data["black"] = 1370; p.data["white"] = 3170; p.data["r"] = 1208; p.data["d"] = 498; p.data["d16"] = 1335; p.data["r16"] = 643;
points[1248]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 33; p.county = 0; p.val = 990; p.data["black"] = 630; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1249]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 33; p.county = 0; p.val = 1750; p.data["black"] = 690; p.data["white"] = 835; p.data["r"] = 1891; p.data["d"] = 878; p.data["d16"] = 2271; p.data["r16"] = 731;
points[1250]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 42; p.county = 0; p.val = 1175; p.data["black"] = 975; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1251]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 44; p.county = 0; p.val = 440; p.data["black"] = 285; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1252]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 32; p.county = 0; p.val = 5025; p.data["black"] = 2465; p.data["white"] = 2460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1253]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 40; p.county = 0; p.val = 755; p.data["black"] = 460; p.data["white"] = 295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1254]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 53; p.county = 0; p.val = 1380; p.data["black"] = 660; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1255]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 29; p.county = 0; p.val = 1325; p.data["black"] = 680; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1256]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 19; p.county = 0; p.val = 2245; p.data["black"] = 140; p.data["white"] = 2050; p.data["r"] = 198; p.data["d"] = 715; p.data["d16"] = 221; p.data["r16"] = 920;
points[1257]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 15; p.county = 0; p.val = 2015; p.data["black"] = 570; p.data["white"] = 1270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1258]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 19; p.county = 0; p.val = 610; p.data["black"] = 270; p.data["white"] = 330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1259]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 30; p.county = 0; p.val = 810; p.data["black"] = 15; p.data["white"] = 795; p.data["r"] = 152; p.data["d"] = 599; p.data["d16"] = 0; p.data["r16"] = 0;
points[1260]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 28; p.county = 0; p.val = 370; p.data["black"] = 165; p.data["white"] = 205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1261]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 24; p.county = 0; p.val = 1315; p.data["black"] = 355; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1262]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 26; p.county = 0; p.val = 530; p.data["black"] = 235; p.data["white"] = 290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1263]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 8; p.county = 0; p.val = 7960; p.data["black"] = 1335; p.data["white"] = 6085; p.data["r"] = 364; p.data["d"] = 652; p.data["d16"] = 377; p.data["r16"] = 843;
points[1264]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 13; p.county = 0; p.val = 7240; p.data["black"] = 910; p.data["white"] = 5845; p.data["r"] = 362; p.data["d"] = 698; p.data["d16"] = 1146; p.data["r16"] = 2498;
points[1265]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 14; p.county = 0; p.val = 1170; p.data["black"] = 475; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1266]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 27; p.county = 0; p.val = 980; p.data["black"] = 0; p.data["white"] = 980; p.data["r"] = 322; p.data["d"] = 567; p.data["d16"] = 0; p.data["r16"] = 0;
points[1267]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 24; p.county = 0; p.val = 530; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1268]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 23; p.county = 0; p.val = 1605; p.data["black"] = 895; p.data["white"] = 670; p.data["r"] = 355; p.data["d"] = 185; p.data["d16"] = 447; p.data["r16"] = 258;
points[1269]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 15; p.county = 0; p.val = 1900; p.data["black"] = 255; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1270]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 23; p.county = 0; p.val = 4575; p.data["black"] = 1150; p.data["white"] = 3190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1271]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 56; p.county = 0; p.val = 475; p.data["black"] = 405; p.data["white"] = 70; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1272]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 52; p.county = 0; p.val = 1575; p.data["black"] = 320; p.data["white"] = 1200; p.data["r"] = 219; p.data["d"] = 337; p.data["d16"] = 294; p.data["r16"] = 408;
points[1273]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 55; p.county = 0; p.val = 1410; p.data["black"] = 1085; p.data["white"] = 325; p.data["r"] = 209; p.data["d"] = 115; p.data["d16"] = 0; p.data["r16"] = 0;
points[1274]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 59; p.county = 0; p.val = 1495; p.data["black"] = 1000; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 867; p.data["r16"] = 210;
points[1275]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 57; p.county = 0; p.val = 1155; p.data["black"] = 790; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1276]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 58; p.county = 0; p.val = 360; p.data["black"] = 75; p.data["white"] = 270; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1277]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 57; p.county = 0; p.val = 800; p.data["black"] = 585; p.data["white"] = 215; p.data["r"] = 493; p.data["d"] = 165; p.data["d16"] = 629; p.data["r16"] = 223;
points[1278]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 60; p.county = 0; p.val = 1405; p.data["black"] = 665; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1279]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 54; p.county = 0; p.val = 470; p.data["black"] = 210; p.data["white"] = 260; p.data["r"] = 378; p.data["d"] = 283; p.data["d16"] = 0; p.data["r16"] = 0;
points[1280]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 57; p.county = 0; p.val = 1285; p.data["black"] = 1060; p.data["white"] = 225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1281]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 60; p.county = 0; p.val = 1040; p.data["black"] = 735; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1282]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 56; p.county = 0; p.val = 680; p.data["black"] = 95; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1283]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 60; p.county = 0; p.val = 960; p.data["black"] = 800; p.data["white"] = 155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1284]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 54; p.county = 0; p.val = 830; p.data["black"] = 525; p.data["white"] = 285; p.data["r"] = 319; p.data["d"] = 81; p.data["d16"] = 0; p.data["r16"] = 0;
points[1285]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 59; p.county = 0; p.val = 530; p.data["black"] = 415; p.data["white"] = 105; p.data["r"] = 493; p.data["d"] = 192; p.data["d16"] = 0; p.data["r16"] = 0;
points[1286]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 56; p.county = 0; p.val = 795; p.data["black"] = 465; p.data["white"] = 335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1287]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 59; p.county = 0; p.val = 880; p.data["black"] = 225; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 189; p.data["r16"] = 553;
points[1288]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 53; p.county = 0; p.val = 1100; p.data["black"] = 1015; p.data["white"] = 25; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1289]=p;}
if (1==1){ Point p;
p.x = 45; p.y = 55; p.county = 0; p.val = 1130; p.data["black"] = 835; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1290]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 53; p.county = 0; p.val = 4315; p.data["black"] = 3145; p.data["white"] = 935; p.data["r"] = 674; p.data["d"] = 24; p.data["d16"] = 0; p.data["r16"] = 0;
points[1291]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 55; p.county = 0; p.val = 1345; p.data["black"] = 1060; p.data["white"] = 265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 644; p.data["r16"] = 63;
points[1292]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 56; p.county = 0; p.val = 1290; p.data["black"] = 1115; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1293]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 58; p.county = 0; p.val = 720; p.data["black"] = 430; p.data["white"] = 170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1294]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 54; p.county = 0; p.val = 480; p.data["black"] = 150; p.data["white"] = 325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1295]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 63; p.county = 0; p.val = 625; p.data["black"] = 205; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1296]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 51; p.county = 0; p.val = 300; p.data["black"] = 30; p.data["white"] = 250; p.data["r"] = 435; p.data["d"] = 287; p.data["d16"] = 500; p.data["r16"] = 344;
points[1297]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 50; p.county = 0; p.val = 620; p.data["black"] = 290; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1298]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 53; p.county = 0; p.val = 655; p.data["black"] = 405; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1299]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 50; p.county = 0; p.val = 1440; p.data["black"] = 765; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1300]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 56; p.county = 0; p.val = 565; p.data["black"] = 215; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1301]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 55; p.county = 0; p.val = 2055; p.data["black"] = 725; p.data["white"] = 1310; p.data["r"] = 264; p.data["d"] = 146; p.data["d16"] = 369; p.data["r16"] = 228;
points[1302]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 53; p.county = 0; p.val = 4975; p.data["black"] = 2495; p.data["white"] = 2330; p.data["r"] = 301; p.data["d"] = 167; p.data["d16"] = 0; p.data["r16"] = 0;
points[1303]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 60; p.county = 0; p.val = 980; p.data["black"] = 395; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 375; p.data["r16"] = 239;
points[1304]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 58; p.county = 0; p.val = 915; p.data["black"] = 760; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1305]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 77; p.county = 0; p.val = 1420; p.data["black"] = 675; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 402; p.data["r16"] = 698;
points[1306]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 32; p.county = 0; p.val = 1265; p.data["black"] = 555; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1307]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 0; p.val = 1120; p.data["black"] = 205; p.data["white"] = 865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 167; p.data["r16"] = 337;
points[1308]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 26; p.county = 0; p.val = 575; p.data["black"] = 345; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1309]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 27; p.county = 0; p.val = 1425; p.data["black"] = 325; p.data["white"] = 1060; p.data["r"] = 459; p.data["d"] = 409; p.data["d16"] = 0; p.data["r16"] = 0;
points[1310]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 38; p.county = 0; p.val = 5705; p.data["black"] = 1080; p.data["white"] = 3650; p.data["r"] = 307; p.data["d"] = 525; p.data["d16"] = 0; p.data["r16"] = 0;
points[1311]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 36; p.county = 0; p.val = 215; p.data["black"] = 20; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1312]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 10; p.county = 0; p.val = 1535; p.data["black"] = 160; p.data["white"] = 1380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1313]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 34; p.county = 0; p.val = 1605; p.data["black"] = 605; p.data["white"] = 915; p.data["r"] = 473; p.data["d"] = 385; p.data["d16"] = 794; p.data["r16"] = 1059;
points[1314]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 36; p.county = 0; p.val = 925; p.data["black"] = 445; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1315]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 35; p.county = 0; p.val = 8545; p.data["black"] = 1975; p.data["white"] = 6010; p.data["r"] = 491; p.data["d"] = 300; p.data["d16"] = 1108; p.data["r16"] = 1171;
points[1316]=p;}
if (1==1){ Point p;
p.x = 82; p.y = 44; p.county = 0; p.val = 760; p.data["black"] = 125; p.data["white"] = 610; p.data["r"] = 294; p.data["d"] = 641; p.data["d16"] = 0; p.data["r16"] = 0;
points[1317]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 68; p.county = 0; p.val = 745; p.data["black"] = 400; p.data["white"] = 295; p.data["r"] = 7; p.data["d"] = 83; p.data["d16"] = 0; p.data["r16"] = 0;
points[1318]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 70; p.county = 0; p.val = 940; p.data["black"] = 865; p.data["white"] = 75; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1319]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 62; p.county = 0; p.val = 2720; p.data["black"] = 1195; p.data["white"] = 1435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 394; p.data["r16"] = 583;
points[1320]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 58; p.county = 0; p.val = 845; p.data["black"] = 110; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 127; p.data["r16"] = 267;
points[1321]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 34; p.county = 0; p.val = 5030; p.data["black"] = 275; p.data["white"] = 4480; p.data["r"] = 320; p.data["d"] = 758; p.data["d16"] = 355; p.data["r16"] = 634;
points[1322]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 24; p.county = 0; p.val = 735; p.data["black"] = 140; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 162; p.data["r16"] = 598;
points[1323]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 31; p.county = 0; p.val = 930; p.data["black"] = 390; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1324]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 25; p.county = 0; p.val = 920; p.data["black"] = 225; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1325]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 33; p.county = 0; p.val = 595; p.data["black"] = 300; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1326]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 26; p.county = 0; p.val = 730; p.data["black"] = 70; p.data["white"] = 620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1327]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 31; p.county = 0; p.val = 565; p.data["black"] = 15; p.data["white"] = 545; p.data["r"] = 126; p.data["d"] = 472; p.data["d16"] = 0; p.data["r16"] = 0;
points[1328]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 39; p.county = 0; p.val = 2275; p.data["black"] = 640; p.data["white"] = 1550; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1329]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 85; p.county = 0; p.val = 1120; p.data["black"] = 350; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1330]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 87; p.county = 0; p.val = 1750; p.data["black"] = 955; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1331]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 100; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 221; p.data["d"] = 351; p.data["d16"] = 0; p.data["r16"] = 0;
points[1332]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 30; p.county = 0; p.val = 1070; p.data["black"] = 125; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1333]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 32; p.county = 0; p.val = 1235; p.data["black"] = 610; p.data["white"] = 610; p.data["r"] = 128; p.data["d"] = 298; p.data["d16"] = 0; p.data["r16"] = 0;
points[1334]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 33; p.county = 0; p.val = 1135; p.data["black"] = 440; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1335]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 27; p.county = 0; p.val = 850; p.data["black"] = 110; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1336]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 31; p.county = 0; p.val = 1340; p.data["black"] = 175; p.data["white"] = 1125; p.data["r"] = 279; p.data["d"] = 538; p.data["d16"] = 0; p.data["r16"] = 0;
points[1337]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 33; p.county = 0; p.val = 1205; p.data["black"] = 515; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1338]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 35; p.county = 0; p.val = 685; p.data["black"] = 110; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1339]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 34; p.county = 0; p.val = 775; p.data["black"] = 105; p.data["white"] = 675; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1340]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 36; p.county = 0; p.val = 435; p.data["black"] = 395; p.data["white"] = 35; p.data["r"] = 573; p.data["d"] = 371; p.data["d16"] = 0; p.data["r16"] = 0;
points[1341]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 34; p.county = 0; p.val = 480; p.data["black"] = 225; p.data["white"] = 255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 328; p.data["r16"] = 362;
points[1342]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 29; p.county = 0; p.val = 920; p.data["black"] = 115; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1343]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 30; p.county = 0; p.val = 1310; p.data["black"] = 0; p.data["white"] = 1310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1344]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 40; p.county = 0; p.val = 1165; p.data["black"] = 505; p.data["white"] = 650; p.data["r"] = 21; p.data["d"] = 142; p.data["d16"] = 0; p.data["r16"] = 0;
points[1345]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 39; p.county = 0; p.val = 1260; p.data["black"] = 720; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1346]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 7; p.county = 0; p.val = 1245; p.data["black"] = 135; p.data["white"] = 955; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1347]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 10; p.county = 0; p.val = 790; p.data["black"] = 0; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1348]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 12; p.county = 0; p.val = 890; p.data["black"] = 110; p.data["white"] = 775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 126; p.data["r16"] = 678;
points[1349]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 3; p.county = 0; p.val = 1535; p.data["black"] = 30; p.data["white"] = 1350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1350]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 12; p.county = 0; p.val = 1275; p.data["black"] = 175; p.data["white"] = 1050; p.data["r"] = 135; p.data["d"] = 560; p.data["d16"] = 154; p.data["r16"] = 746;
points[1351]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 12; p.county = 0; p.val = 1200; p.data["black"] = 30; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1352]=p;}
if (1==1){ Point p;
p.x = 34; p.y = 6; p.county = 0; p.val = 640; p.data["black"] = 0; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1353]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 18; p.county = 0; p.val = 720; p.data["black"] = 140; p.data["white"] = 525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1354]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 27; p.county = 0; p.val = 1655; p.data["black"] = 305; p.data["white"] = 1260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1355]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 94; p.county = 0; p.val = 2590; p.data["black"] = 325; p.data["white"] = 1885; p.data["r"] = 418; p.data["d"] = 935; p.data["d16"] = 157; p.data["r16"] = 389;
points[1356]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 21; p.county = 0; p.val = 990; p.data["black"] = 165; p.data["white"] = 825; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1357]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 17; p.county = 0; p.val = 945; p.data["black"] = 200; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1358]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 13; p.county = 0; p.val = 645; p.data["black"] = 55; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1359]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 16; p.county = 0; p.val = 1775; p.data["black"] = 590; p.data["white"] = 1075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1360]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 20; p.county = 0; p.val = 2470; p.data["black"] = 60; p.data["white"] = 2345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 263; p.data["r16"] = 734;
points[1361]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 68; p.county = 0; p.val = 1135; p.data["black"] = 590; p.data["white"] = 425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1362]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 31; p.county = 0; p.val = 810; p.data["black"] = 435; p.data["white"] = 375; p.data["r"] = 250; p.data["d"] = 187; p.data["d16"] = 0; p.data["r16"] = 0;
points[1363]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 32; p.county = 0; p.val = 800; p.data["black"] = 660; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1364]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 33; p.county = 0; p.val = 1135; p.data["black"] = 700; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1365]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 36; p.county = 0; p.val = 1135; p.data["black"] = 765; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1366]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 37; p.county = 0; p.val = 510; p.data["black"] = 385; p.data["white"] = 90; p.data["r"] = 179; p.data["d"] = 57; p.data["d16"] = 0; p.data["r16"] = 0;
points[1367]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 4; p.county = 0; p.val = 1330; p.data["black"] = 375; p.data["white"] = 960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 226; p.data["r16"] = 770;
points[1368]=p;}
if (1==1){ Point p;
p.x = 39; p.y = 3; p.county = 0; p.val = 880; p.data["black"] = 235; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1369]=p;}
if (1==1){ Point p;
p.x = 36; p.y = 7; p.county = 0; p.val = 1380; p.data["black"] = 120; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1370]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 89; p.county = 0; p.val = 4050; p.data["black"] = 810; p.data["white"] = 3100; p.data["r"] = 246; p.data["d"] = 389; p.data["d16"] = 0; p.data["r16"] = 0;
points[1371]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 83; p.county = 0; p.val = 1125; p.data["black"] = 1040; p.data["white"] = 80; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1372]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 85; p.county = 0; p.val = 1835; p.data["black"] = 1245; p.data["white"] = 510; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1373]=p;}
if (1==1){ Point p;
p.x = 51; p.y = 86; p.county = 0; p.val = 1405; p.data["black"] = 845; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1374]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 11; p.county = 0; p.val = 1585; p.data["black"] = 0; p.data["white"] = 1585; p.data["r"] = 168; p.data["d"] = 556; p.data["d16"] = 0; p.data["r16"] = 0;
points[1375]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 33; p.county = 0; p.val = 1660; p.data["black"] = 930; p.data["white"] = 690; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 592; p.data["r16"] = 951;
points[1376]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 33; p.county = 0; p.val = 4810; p.data["black"] = 860; p.data["white"] = 3575; p.data["r"] = 365; p.data["d"] = 647; p.data["d16"] = 902; p.data["r16"] = 1541;
points[1377]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 34; p.county = 0; p.val = 1550; p.data["black"] = 1060; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1378]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 39; p.county = 0; p.val = 3815; p.data["black"] = 505; p.data["white"] = 3095; p.data["r"] = 348; p.data["d"] = 692; p.data["d16"] = 348; p.data["r16"] = 1004;
points[1379]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 15; p.county = 0; p.val = 485; p.data["black"] = 15; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1380]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 30; p.county = 0; p.val = 1810; p.data["black"] = 750; p.data["white"] = 965; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 464; p.data["r16"] = 167;
points[1381]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 61; p.county = 0; p.val = 915; p.data["black"] = 195; p.data["white"] = 675; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1382]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 60; p.county = 0; p.val = 1385; p.data["black"] = 290; p.data["white"] = 1095; p.data["r"] = 341; p.data["d"] = 185; p.data["d16"] = 448; p.data["r16"] = 246;
points[1383]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 66; p.county = 0; p.val = 2080; p.data["black"] = 455; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 586; p.data["r16"] = 764;
points[1384]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 59; p.county = 0; p.val = 1815; p.data["black"] = 825; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1385]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 6; p.county = 0; p.val = 1095; p.data["black"] = 55; p.data["white"] = 1020; p.data["r"] = 193; p.data["d"] = 678; p.data["d16"] = 0; p.data["r16"] = 0;
points[1386]=p;}
if (1==1){ Point p;
p.x = 15; p.y = 10; p.county = 0; p.val = 1540; p.data["black"] = 0; p.data["white"] = 1440; p.data["r"] = 166; p.data["d"] = 479; p.data["d16"] = 0; p.data["r16"] = 0;
points[1387]=p;}
if (1==1){ Point p;
p.x = 9; p.y = 10; p.county = 0; p.val = 1755; p.data["black"] = 35; p.data["white"] = 1685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1388]=p;}
if (1==1){ Point p;
p.x = 10; p.y = 14; p.county = 0; p.val = 1195; p.data["black"] = 40; p.data["white"] = 1105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1389]=p;}
if (1==1){ Point p;
p.x = 13; p.y = 11; p.county = 0; p.val = 1155; p.data["black"] = 0; p.data["white"] = 1135; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1390]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 19; p.county = 0; p.val = 1250; p.data["black"] = 225; p.data["white"] = 990; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1391]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 22; p.county = 0; p.val = 1190; p.data["black"] = 20; p.data["white"] = 1090; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1392]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 39; p.county = 0; p.val = 2780; p.data["black"] = 440; p.data["white"] = 2135; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 847; p.data["r16"] = 1976;
points[1393]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 42; p.county = 0; p.val = 1925; p.data["black"] = 365; p.data["white"] = 1525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 709; p.data["r16"] = 416;
points[1394]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 15; p.county = 0; p.val = 3565; p.data["black"] = 1110; p.data["white"] = 2225; p.data["r"] = 418; p.data["d"] = 301; p.data["d16"] = 0; p.data["r16"] = 0;
points[1395]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 16; p.county = 0; p.val = 1775; p.data["black"] = 560; p.data["white"] = 1215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 523; p.data["r16"] = 435;
points[1396]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 17; p.county = 0; p.val = 1950; p.data["black"] = 580; p.data["white"] = 1285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1397]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 40; p.county = 0; p.val = 390; p.data["black"] = 0; p.data["white"] = 390; p.data["r"] = 157; p.data["d"] = 243; p.data["d16"] = 0; p.data["r16"] = 0;
points[1398]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 16; p.county = 0; p.val = 2765; p.data["black"] = 350; p.data["white"] = 2185; p.data["r"] = 504; p.data["d"] = 776; p.data["d16"] = 503; p.data["r16"] = 908;
points[1399]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 14; p.county = 0; p.val = 3100; p.data["black"] = 190; p.data["white"] = 2865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1400]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 77; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 334; p.data["r16"] = 668;
points[1401]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 33; p.county = 0; p.val = 3015; p.data["black"] = 495; p.data["white"] = 2455; p.data["r"] = 516; p.data["d"] = 819; p.data["d16"] = 344; p.data["r16"] = 533;
points[1402]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 31; p.county = 0; p.val = 1700; p.data["black"] = 360; p.data["white"] = 1235; p.data["r"] = 347; p.data["d"] = 584; p.data["d16"] = 0; p.data["r16"] = 0;
points[1403]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 33; p.county = 0; p.val = 2200; p.data["black"] = 520; p.data["white"] = 1490; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1404]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 29; p.county = 0; p.val = 1320; p.data["black"] = 490; p.data["white"] = 825; p.data["r"] = 220; p.data["d"] = 114; p.data["d16"] = 0; p.data["r16"] = 0;
points[1405]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 28; p.county = 0; p.val = 2370; p.data["black"] = 360; p.data["white"] = 1895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1406]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 31; p.county = 0; p.val = 4960; p.data["black"] = 1355; p.data["white"] = 3275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1407]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 31; p.county = 0; p.val = 1790; p.data["black"] = 180; p.data["white"] = 1570; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1408]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 32; p.county = 0; p.val = 1195; p.data["black"] = 375; p.data["white"] = 775; p.data["r"] = 463; p.data["d"] = 537; p.data["d16"] = 0; p.data["r16"] = 0;
points[1409]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 32; p.county = 0; p.val = 1730; p.data["black"] = 280; p.data["white"] = 1355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 198; p.data["r16"] = 698;
points[1410]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 0; p.val = 570; p.data["black"] = 540; p.data["white"] = 30; p.data["r"] = 594; p.data["d"] = 11; p.data["d16"] = 436; p.data["r16"] = 157;
points[1411]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 68; p.county = 0; p.val = 3505; p.data["black"] = 710; p.data["white"] = 2465; p.data["r"] = 229; p.data["d"] = 936; p.data["d16"] = 0; p.data["r16"] = 0;
points[1412]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 58; p.county = 0; p.val = 1775; p.data["black"] = 860; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 67; p.data["r16"] = 119;
points[1413]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 41; p.county = 0; p.val = 2020; p.data["black"] = 935; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1414]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 8; p.county = 0; p.val = 3540; p.data["black"] = 605; p.data["white"] = 2895; p.data["r"] = 425; p.data["d"] = 717; p.data["d16"] = 0; p.data["r16"] = 0;
points[1415]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 5; p.county = 0; p.val = 1820; p.data["black"] = 0; p.data["white"] = 1755; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1416]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 7; p.county = 0; p.val = 4995; p.data["black"] = 495; p.data["white"] = 4380; p.data["r"] = 257; p.data["d"] = 746; p.data["d16"] = 789; p.data["r16"] = 1606;
points[1417]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 13; p.county = 0; p.val = 6005; p.data["black"] = 840; p.data["white"] = 4825; p.data["r"] = 992; p.data["d"] = 1680; p.data["d16"] = 0; p.data["r16"] = 0;
points[1418]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 6; p.county = 0; p.val = 1385; p.data["black"] = 275; p.data["white"] = 1110; p.data["r"] = 288; p.data["d"] = 1082; p.data["d16"] = 0; p.data["r16"] = 0;
points[1419]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 6; p.county = 0; p.val = 3710; p.data["black"] = 100; p.data["white"] = 3450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1420]=p;}
if (1==1){ Point p;
p.x = 37; p.y = 40; p.county = 0; p.val = 755; p.data["black"] = 185; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1421]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 21; p.county = 0; p.val = 2525; p.data["black"] = 585; p.data["white"] = 1850; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 299; p.data["r16"] = 866;
points[1422]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 52; p.county = 0; p.val = 1280; p.data["black"] = 195; p.data["white"] = 1065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1423]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 54; p.county = 0; p.val = 265; p.data["black"] = 70; p.data["white"] = 175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1424]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 54; p.county = 0; p.val = 190; p.data["black"] = 0; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1425]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 15; p.county = 0; p.val = 1250; p.data["black"] = 160; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1426]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 39; p.county = 0; p.val = 1135; p.data["black"] = 190; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1427]=p;}
if (1==1){ Point p;
p.x = 38; p.y = 41; p.county = 0; p.val = 1120; p.data["black"] = 245; p.data["white"] = 840; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 608; p.data["r16"] = 943;
points[1428]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 16; p.county = 0; p.val = 1530; p.data["black"] = 225; p.data["white"] = 1245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 217; p.data["r16"] = 684;
points[1429]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 2; p.county = 0; p.val = 1355; p.data["black"] = 25; p.data["white"] = 1315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 265; p.data["r16"] = 987;
points[1430]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 1; p.county = 0; p.val = 1600; p.data["black"] = 20; p.data["white"] = 1540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1431]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 9; p.county = 0; p.val = 2225; p.data["black"] = 430; p.data["white"] = 1695; p.data["r"] = 326; p.data["d"] = 515; p.data["d16"] = 447; p.data["r16"] = 464;
points[1432]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 25; p.county = 0; p.val = 370; p.data["black"] = 0; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1433]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 67; p.county = 0; p.val = 1665; p.data["black"] = 445; p.data["white"] = 1015; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1434]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 5; p.county = 0; p.val = 4655; p.data["black"] = 495; p.data["white"] = 3860; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 361; p.data["r16"] = 621;
points[1435]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 59; p.county = 0; p.val = 555; p.data["black"] = 310; p.data["white"] = 230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1436]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 58; p.county = 0; p.val = 655; p.data["black"] = 150; p.data["white"] = 495; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1437]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 58; p.county = 0; p.val = 690; p.data["black"] = 540; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 460; p.data["r16"] = 112;
points[1438]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 59; p.county = 0; p.val = 315; p.data["black"] = 235; p.data["white"] = 60; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 281; p.data["r16"] = 117;
points[1439]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 61; p.county = 0; p.val = 610; p.data["black"] = 210; p.data["white"] = 400; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1440]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 65; p.county = 0; p.val = 1490; p.data["black"] = 815; p.data["white"] = 655; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1441]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 57; p.county = 0; p.val = 380; p.data["black"] = 330; p.data["white"] = 45; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1442]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 57; p.county = 0; p.val = 810; p.data["black"] = 665; p.data["white"] = 125; p.data["r"] = 377; p.data["d"] = 101; p.data["d16"] = 0; p.data["r16"] = 0;
points[1443]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 63; p.county = 0; p.val = 730; p.data["black"] = 0; p.data["white"] = 730; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1444]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 0; p.val = 1195; p.data["black"] = 85; p.data["white"] = 1095; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 76; p.data["r16"] = 546;
points[1445]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 58; p.county = 0; p.val = 1350; p.data["black"] = 410; p.data["white"] = 845; p.data["r"] = 165; p.data["d"] = 185; p.data["d16"] = 0; p.data["r16"] = 0;
points[1446]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 55; p.county = 0; p.val = 1065; p.data["black"] = 760; p.data["white"] = 295; p.data["r"] = 480; p.data["d"] = 254; p.data["d16"] = 0; p.data["r16"] = 0;
points[1447]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 61; p.county = 0; p.val = 1220; p.data["black"] = 525; p.data["white"] = 670; p.data["r"] = 166; p.data["d"] = 135; p.data["d16"] = 0; p.data["r16"] = 0;
points[1448]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 54; p.county = 0; p.val = 3025; p.data["black"] = 150; p.data["white"] = 2830; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1449]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 53; p.county = 0; p.val = 1840; p.data["black"] = 15; p.data["white"] = 1810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1450]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 57; p.county = 0; p.val = 3010; p.data["black"] = 270; p.data["white"] = 2645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1451]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 56; p.county = 0; p.val = 2925; p.data["black"] = 340; p.data["white"] = 2545; p.data["r"] = 758; p.data["d"] = 841; p.data["d16"] = 0; p.data["r16"] = 0;
points[1452]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 18; p.county = 0; p.val = 1460; p.data["black"] = 310; p.data["white"] = 1150; p.data["r"] = 252; p.data["d"] = 422; p.data["d16"] = 0; p.data["r16"] = 0;
points[1453]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 16; p.county = 0; p.val = 705; p.data["black"] = 40; p.data["white"] = 665; p.data["r"] = 352; p.data["d"] = 496; p.data["d16"] = 0; p.data["r16"] = 0;
points[1454]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 20; p.county = 0; p.val = 2775; p.data["black"] = 690; p.data["white"] = 2015; p.data["r"] = 332; p.data["d"] = 485; p.data["d16"] = 447; p.data["r16"] = 654;
points[1455]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 16; p.county = 0; p.val = 1330; p.data["black"] = 235; p.data["white"] = 1095; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 123; p.data["r16"] = 673;
points[1456]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 16; p.county = 0; p.val = 990; p.data["black"] = 290; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1457]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 13; p.county = 0; p.val = 1055; p.data["black"] = 245; p.data["white"] = 805; p.data["r"] = 251; p.data["d"] = 189; p.data["d16"] = 0; p.data["r16"] = 0;
points[1458]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 16; p.county = 0; p.val = 2860; p.data["black"] = 905; p.data["white"] = 1420; p.data["r"] = 485; p.data["d"] = 616; p.data["d16"] = 0; p.data["r16"] = 0;
points[1459]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 16; p.county = 0; p.val = 1280; p.data["black"] = 75; p.data["white"] = 1140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1460]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 14; p.county = 0; p.val = 2015; p.data["black"] = 410; p.data["white"] = 1420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 345; p.data["r16"] = 603;
points[1461]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 19; p.county = 0; p.val = 1975; p.data["black"] = 1275; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1462]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 13; p.county = 0; p.val = 2035; p.data["black"] = 95; p.data["white"] = 1795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1463]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 41; p.county = 0; p.val = 1330; p.data["black"] = 905; p.data["white"] = 400; p.data["r"] = 225; p.data["d"] = 43; p.data["d16"] = 572; p.data["r16"] = 679;
points[1464]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 52; p.county = 0; p.val = 360; p.data["black"] = 0; p.data["white"] = 350; p.data["r"] = 309; p.data["d"] = 784; p.data["d16"] = 0; p.data["r16"] = 0;
points[1465]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 55; p.county = 0; p.val = 920; p.data["black"] = 75; p.data["white"] = 845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1466]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 53; p.county = 0; p.val = 1745; p.data["black"] = 275; p.data["white"] = 1450; p.data["r"] = 335; p.data["d"] = 776; p.data["d16"] = 379; p.data["r16"] = 825;
points[1467]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 46; p.county = 0; p.val = 755; p.data["black"] = 435; p.data["white"] = 280; p.data["r"] = 204; p.data["d"] = 177; p.data["d16"] = 286; p.data["r16"] = 265;
points[1468]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 18; p.county = 0; p.val = 1225; p.data["black"] = 225; p.data["white"] = 930; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1469]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 13; p.county = 0; p.val = 1510; p.data["black"] = 220; p.data["white"] = 1290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1470]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 9; p.county = 0; p.val = 10600; p.data["black"] = 605; p.data["white"] = 9765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1471]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 17; p.county = 0; p.val = 1470; p.data["black"] = 660; p.data["white"] = 810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1472]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 20; p.county = 0; p.val = 1180; p.data["black"] = 550; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1473]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 21; p.county = 0; p.val = 1170; p.data["black"] = 45; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1474]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 10; p.county = 0; p.val = 1105; p.data["black"] = 85; p.data["white"] = 955; p.data["r"] = 200; p.data["d"] = 355; p.data["d16"] = 0; p.data["r16"] = 0;
points[1475]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 2; p.county = 0; p.val = 1495; p.data["black"] = 50; p.data["white"] = 1390; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1476]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 32; p.county = 0; p.val = 4230; p.data["black"] = 645; p.data["white"] = 3345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 700; p.data["r16"] = 616;
points[1477]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 19; p.county = 0; p.val = 880; p.data["black"] = 395; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1478]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 17; p.county = 0; p.val = 375; p.data["black"] = 65; p.data["white"] = 315; p.data["r"] = 425; p.data["d"] = 532; p.data["d16"] = 0; p.data["r16"] = 0;
points[1479]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 1; p.county = 0; p.val = 1005; p.data["black"] = 210; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1480]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 13; p.county = 0; p.val = 1115; p.data["black"] = 35; p.data["white"] = 1075; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1481]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 2; p.county = 0; p.val = 965; p.data["black"] = 105; p.data["white"] = 865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1482]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 6; p.county = 0; p.val = 3585; p.data["black"] = 645; p.data["white"] = 2725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1483]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 13; p.county = 0; p.val = 1845; p.data["black"] = 220; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1484]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 17; p.county = 0; p.val = 2055; p.data["black"] = 165; p.data["white"] = 1820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 199; p.data["r16"] = 733;
points[1485]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 1; p.county = 0; p.val = 515; p.data["black"] = 0; p.data["white"] = 515; p.data["r"] = 299; p.data["d"] = 820; p.data["d16"] = 0; p.data["r16"] = 0;
points[1486]=p;}
if (1==1){ Point p;
p.x = 25; p.y = 5; p.county = 0; p.val = 3140; p.data["black"] = 330; p.data["white"] = 2760; p.data["r"] = 378; p.data["d"] = 1022; p.data["d16"] = 0; p.data["r16"] = 0;
points[1487]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 4; p.county = 0; p.val = 1455; p.data["black"] = 80; p.data["white"] = 1350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 218; p.data["r16"] = 748;
points[1488]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 3; p.county = 0; p.val = 2925; p.data["black"] = 55; p.data["white"] = 2845; p.data["r"] = 458; p.data["d"] = 1677; p.data["d16"] = 224; p.data["r16"] = 1105;
points[1489]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 34; p.county = 0; p.val = 685; p.data["black"] = 285; p.data["white"] = 375; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1490]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 3; p.county = 0; p.val = 725; p.data["black"] = 0; p.data["white"] = 725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 147; p.data["r16"] = 1013;
points[1491]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 64; p.county = 0; p.val = 1480; p.data["black"] = 670; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1492]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 5; p.county = 0; p.val = 640; p.data["black"] = 135; p.data["white"] = 460; p.data["r"] = 449; p.data["d"] = 833; p.data["d16"] = 587; p.data["r16"] = 1122;
points[1493]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 37; p.county = 0; p.val = 1165; p.data["black"] = 205; p.data["white"] = 950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1494]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 38; p.county = 0; p.val = 525; p.data["black"] = 275; p.data["white"] = 235; p.data["r"] = 256; p.data["d"] = 280; p.data["d16"] = 0; p.data["r16"] = 0;
points[1495]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 34; p.county = 0; p.val = 1075; p.data["black"] = 200; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1496]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 0; p.val = 3365; p.data["black"] = 205; p.data["white"] = 2980; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1497]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 55; p.county = 0; p.val = 2735; p.data["black"] = 360; p.data["white"] = 2255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 544; p.data["r16"] = 1265;
points[1498]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 55; p.county = 0; p.val = 780; p.data["black"] = 380; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1499]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 43; p.county = 0; p.val = 1220; p.data["black"] = 180; p.data["white"] = 1000; p.data["r"] = 149; p.data["d"] = 521; p.data["d16"] = 0; p.data["r16"] = 0;
points[1500]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 41; p.county = 0; p.val = 1995; p.data["black"] = 615; p.data["white"] = 1295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1501]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 4; p.county = 0; p.val = 1315; p.data["black"] = 80; p.data["white"] = 1220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1502]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 1; p.county = 0; p.val = 1325; p.data["black"] = 175; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1503]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 50; p.county = 0; p.val = 715; p.data["black"] = 15; p.data["white"] = 695; p.data["r"] = 383; p.data["d"] = 565; p.data["d16"] = 0; p.data["r16"] = 0;
points[1504]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 44; p.county = 0; p.val = 5930; p.data["black"] = 815; p.data["white"] = 4975; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1505]=p;}
if (1==1){ Point p;
p.x = 97; p.y = 43; p.county = 0; p.val = 2005; p.data["black"] = 40; p.data["white"] = 1910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1506]=p;}
if (1==1){ Point p;
p.x = 100; p.y = 42; p.county = 0; p.val = 1720; p.data["black"] = 155; p.data["white"] = 1530; p.data["r"] = 288; p.data["d"] = 610; p.data["d16"] = 0; p.data["r16"] = 0;
points[1507]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 9; p.county = 0; p.val = 1840; p.data["black"] = 570; p.data["white"] = 950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1508]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 40; p.county = 0; p.val = 920; p.data["black"] = 0; p.data["white"] = 885; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1509]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 36; p.county = 0; p.val = 1005; p.data["black"] = 480; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1510]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 33; p.county = 0; p.val = 980; p.data["black"] = 455; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1511]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 39; p.county = 0; p.val = 2130; p.data["black"] = 120; p.data["white"] = 1850; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1512]=p;}
if (1==1){ Point p;
p.x = 16; p.y = 12; p.county = 0; p.val = 3000; p.data["black"] = 195; p.data["white"] = 2735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 216; p.data["r16"] = 755;
points[1513]=p;}
if (1==1){ Point p;
p.x = 24; p.y = 7; p.county = 0; p.val = 2670; p.data["black"] = 165; p.data["white"] = 2300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 621; p.data["r16"] = 1863;
points[1514]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 14; p.county = 0; p.val = 2175; p.data["black"] = 725; p.data["white"] = 1420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1515]=p;}
if (1==1){ Point p;
p.x = 28; p.y = 3; p.county = 0; p.val = 1265; p.data["black"] = 150; p.data["white"] = 1120; p.data["r"] = 147; p.data["d"] = 591; p.data["d16"] = 0; p.data["r16"] = 0;
points[1516]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 38; p.county = 0; p.val = 910; p.data["black"] = 570; p.data["white"] = 330; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1517]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 32; p.county = 0; p.val = 3545; p.data["black"] = 405; p.data["white"] = 3060; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1518]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 32; p.county = 0; p.val = 2605; p.data["black"] = 1550; p.data["white"] = 1015; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 657; p.data["r16"] = 738;
points[1519]=p;}
if (1==1){ Point p;
p.x = 79; p.y = 36; p.county = 0; p.val = 810; p.data["black"] = 580; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 355; p.data["r16"] = 164;
points[1520]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 40; p.county = 0; p.val = 785; p.data["black"] = 0; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1521]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 43; p.county = 0; p.val = 1210; p.data["black"] = 815; p.data["white"] = 390; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1522]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 44; p.county = 0; p.val = 740; p.data["black"] = 195; p.data["white"] = 545; p.data["r"] = 101; p.data["d"] = 425; p.data["d16"] = 103; p.data["r16"] = 400;
points[1523]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 30; p.county = 0; p.val = 1245; p.data["black"] = 275; p.data["white"] = 925; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1524]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 39; p.county = 0; p.val = 545; p.data["black"] = 240; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1525]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 41; p.county = 0; p.val = 600; p.data["black"] = 180; p.data["white"] = 370; p.data["r"] = 121; p.data["d"] = 275; p.data["d16"] = 0; p.data["r16"] = 0;
points[1526]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 36; p.county = 0; p.val = 445; p.data["black"] = 4; p.data["white"] = 440; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 205; p.data["r16"] = 544;
points[1527]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 31; p.county = 0; p.val = 760; p.data["black"] = 655; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1528]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 41; p.county = 0; p.val = 1120; p.data["black"] = 370; p.data["white"] = 750; p.data["r"] = 73; p.data["d"] = 206; p.data["d16"] = 71; p.data["r16"] = 502;
points[1529]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 40; p.county = 0; p.val = 1025; p.data["black"] = 350; p.data["white"] = 670; p.data["r"] = 361; p.data["d"] = 421; p.data["d16"] = 0; p.data["r16"] = 0;
points[1530]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 32; p.county = 0; p.val = 1010; p.data["black"] = 410; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1531]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 40; p.county = 0; p.val = 2815; p.data["black"] = 655; p.data["white"] = 2070; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1532]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 33; p.county = 0; p.val = 1660; p.data["black"] = 85; p.data["white"] = 1470; p.data["r"] = 531; p.data["d"] = 1115; p.data["d16"] = 0; p.data["r16"] = 0;
points[1533]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 41; p.county = 0; p.val = 1180; p.data["black"] = 70; p.data["white"] = 1090; p.data["r"] = 75; p.data["d"] = 515; p.data["d16"] = 21; p.data["r16"] = 365;
points[1534]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 38; p.county = 0; p.val = 770; p.data["black"] = 165; p.data["white"] = 605; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1535]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 39; p.county = 0; p.val = 705; p.data["black"] = 0; p.data["white"] = 670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1536]=p;}
if (1==1){ Point p;
p.x = 88; p.y = 40; p.county = 0; p.val = 1130; p.data["black"] = 0; p.data["white"] = 1130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1537]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 37; p.county = 0; p.val = 1895; p.data["black"] = 310; p.data["white"] = 1460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1538]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 46; p.county = 0; p.val = 535; p.data["black"] = 20; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1539]=p;}
if (1==1){ Point p;
p.x = 95; p.y = 37; p.county = 0; p.val = 950; p.data["black"] = 555; p.data["white"] = 380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1540]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 40; p.county = 0; p.val = 1085; p.data["black"] = 190; p.data["white"] = 870; p.data["r"] = 45; p.data["d"] = 246; p.data["d16"] = 0; p.data["r16"] = 0;
points[1541]=p;}
if (1==1){ Point p;
p.x = 90; p.y = 36; p.county = 0; p.val = 575; p.data["black"] = 290; p.data["white"] = 255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 24; p.data["r16"] = 94;
points[1542]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 44; p.county = 0; p.val = 1825; p.data["black"] = 195; p.data["white"] = 1540; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1543]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 40; p.county = 0; p.val = 1610; p.data["black"] = 260; p.data["white"] = 1240; p.data["r"] = 234; p.data["d"] = 611; p.data["d16"] = 0; p.data["r16"] = 0;
points[1544]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 33; p.county = 0; p.val = 1635; p.data["black"] = 255; p.data["white"] = 1365; p.data["r"] = 115; p.data["d"] = 291; p.data["d16"] = 0; p.data["r16"] = 0;
points[1545]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 10; p.county = 0; p.val = 1590; p.data["black"] = 170; p.data["white"] = 1295; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1546]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 35; p.county = 0; p.val = 1375; p.data["black"] = 505; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1547]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 36; p.county = 0; p.val = 520; p.data["black"] = 0; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1548]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 45; p.county = 0; p.val = 730; p.data["black"] = 350; p.data["white"] = 300; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1549]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 37; p.county = 0; p.val = 2025; p.data["black"] = 0; p.data["white"] = 2005; p.data["r"] = 296; p.data["d"] = 1171; p.data["d16"] = 214; p.data["r16"] = 1327;
points[1550]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 37; p.county = 0; p.val = 830; p.data["black"] = 205; p.data["white"] = 625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1551]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 39; p.county = 0; p.val = 750; p.data["black"] = 190; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 250; p.data["r16"] = 606;
points[1552]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 44; p.county = 0; p.val = 1400; p.data["black"] = 460; p.data["white"] = 935; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1553]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 44; p.county = 0; p.val = 450; p.data["black"] = 0; p.data["white"] = 435; p.data["r"] = 550; p.data["d"] = 232; p.data["d16"] = 0; p.data["r16"] = 0;
points[1554]=p;}
if (1==1){ Point p;
p.x = 78; p.y = 43; p.county = 0; p.val = 610; p.data["black"] = 85; p.data["white"] = 510; p.data["r"] = 72; p.data["d"] = 109; p.data["d16"] = 0; p.data["r16"] = 0;
points[1555]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 42; p.county = 0; p.val = 1070; p.data["black"] = 555; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 683; p.data["r16"] = 414;
points[1556]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 38; p.county = 0; p.val = 1195; p.data["black"] = 150; p.data["white"] = 1025; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1557]=p;}
if (1==1){ Point p;
p.x = 73; p.y = 39; p.county = 0; p.val = 490; p.data["black"] = 55; p.data["white"] = 425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1558]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 37; p.county = 0; p.val = 1255; p.data["black"] = 280; p.data["white"] = 965; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1559]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 36; p.county = 0; p.val = 540; p.data["black"] = 60; p.data["white"] = 470; p.data["r"] = 253; p.data["d"] = 661; p.data["d16"] = 269; p.data["r16"] = 801;
points[1560]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 74; p.county = 0; p.val = 825; p.data["black"] = 0; p.data["white"] = 795; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1561]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 62; p.county = 0; p.val = 1670; p.data["black"] = 70; p.data["white"] = 1575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1562]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 4; p.county = 0; p.val = 1110; p.data["black"] = 0; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1563]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 1; p.county = 0; p.val = 1875; p.data["black"] = 315; p.data["white"] = 1515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1564]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 3; p.county = 0; p.val = 1715; p.data["black"] = 70; p.data["white"] = 1585; p.data["r"] = 138; p.data["d"] = 499; p.data["d16"] = 119; p.data["r16"] = 693;
points[1565]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 12; p.county = 0; p.val = 890; p.data["black"] = 75; p.data["white"] = 815; p.data["r"] = 184; p.data["d"] = 798; p.data["d16"] = 0; p.data["r16"] = 0;
points[1566]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 16; p.county = 0; p.val = 1385; p.data["black"] = 55; p.data["white"] = 1315; p.data["r"] = 92; p.data["d"] = 283; p.data["d16"] = 0; p.data["r16"] = 0;
points[1567]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 7; p.county = 0; p.val = 3905; p.data["black"] = 1205; p.data["white"] = 2415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1568]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 4; p.county = 0; p.val = 3290; p.data["black"] = 470; p.data["white"] = 2625; p.data["r"] = 1380; p.data["d"] = 1924; p.data["d16"] = 0; p.data["r16"] = 0;
points[1569]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 4; p.county = 0; p.val = 1825; p.data["black"] = 190; p.data["white"] = 1580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1570]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 17; p.county = 0; p.val = 395; p.data["black"] = 0; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 297; p.data["r16"] = 1086;
points[1571]=p;}
if (1==1){ Point p;
p.x = 92; p.y = 49; p.county = 0; p.val = 6115; p.data["black"] = 145; p.data["white"] = 5695; p.data["r"] = 270; p.data["d"] = 333; p.data["d16"] = 0; p.data["r16"] = 0;
points[1572]=p;}
if (1==1){ Point p;
p.x = 93; p.y = 36; p.county = 0; p.val = 1225; p.data["black"] = 560; p.data["white"] = 640; p.data["r"] = 294; p.data["d"] = 117; p.data["d16"] = 380; p.data["r16"] = 153;
points[1573]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 37; p.county = 0; p.val = 1375; p.data["black"] = 0; p.data["white"] = 1335; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1574]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 34; p.county = 0; p.val = 1410; p.data["black"] = 60; p.data["white"] = 1335; p.data["r"] = 396; p.data["d"] = 875; p.data["d16"] = 324; p.data["r16"] = 1008;
points[1575]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 57; p.county = 0; p.val = 1420; p.data["black"] = 895; p.data["white"] = 520; p.data["r"] = 815; p.data["d"] = 202; p.data["d16"] = 0; p.data["r16"] = 0;
points[1576]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 63; p.county = 0; p.val = 1255; p.data["black"] = 435; p.data["white"] = 745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1577]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 9; p.county = 0; p.val = 2100; p.data["black"] = 105; p.data["white"] = 1935; p.data["r"] = 663; p.data["d"] = 555; p.data["d16"] = 0; p.data["r16"] = 0;
points[1578]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 40; p.county = 0; p.val = 1735; p.data["black"] = 140; p.data["white"] = 1430; p.data["r"] = 150; p.data["d"] = 429; p.data["d16"] = 312; p.data["r16"] = 1305;
points[1579]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 6; p.county = 0; p.val = 2130; p.data["black"] = 200; p.data["white"] = 1895; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1580]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 14; p.county = 0; p.val = 1880; p.data["black"] = 695; p.data["white"] = 1065; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1581]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 4; p.county = 0; p.val = 1180; p.data["black"] = 0; p.data["white"] = 1150; p.data["r"] = 178; p.data["d"] = 1229; p.data["d16"] = 0; p.data["r16"] = 0;
points[1582]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 4; p.county = 0; p.val = 915; p.data["black"] = 10; p.data["white"] = 905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 201; p.data["r16"] = 1355;
points[1583]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 14; p.county = 0; p.val = 2475; p.data["black"] = 440; p.data["white"] = 1990; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1584]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 15; p.county = 0; p.val = 3175; p.data["black"] = 840; p.data["white"] = 2275; p.data["r"] = 496; p.data["d"] = 786; p.data["d16"] = 0; p.data["r16"] = 0;
points[1585]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 4; p.county = 0; p.val = 1450; p.data["black"] = 0; p.data["white"] = 1390; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1586]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 6; p.county = 0; p.val = 1935; p.data["black"] = 85; p.data["white"] = 1745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 365; p.data["r16"] = 1868;
points[1587]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 18; p.county = 0; p.val = 965; p.data["black"] = 140; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1588]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 7; p.county = 0; p.val = 1040; p.data["black"] = 0; p.data["white"] = 1015; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1589]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 18; p.county = 0; p.val = 1735; p.data["black"] = 70; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1590]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 16; p.county = 0; p.val = 1150; p.data["black"] = 610; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 587; p.data["r16"] = 654;
points[1591]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 20; p.county = 0; p.val = 1625; p.data["black"] = 0; p.data["white"] = 1605; p.data["r"] = 203; p.data["d"] = 965; p.data["d16"] = 212; p.data["r16"] = 1277;
points[1592]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 2; p.county = 0; p.val = 1260; p.data["black"] = 0; p.data["white"] = 1250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1593]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 4; p.county = 0; p.val = 3410; p.data["black"] = 215; p.data["white"] = 2960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1594]=p;}
if (1==1){ Point p;
p.x = 17; p.y = 4; p.county = 0; p.val = 945; p.data["black"] = 25; p.data["white"] = 915; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1595]=p;}
if (1==1){ Point p;
p.x = 18; p.y = 7; p.county = 0; p.val = 3500; p.data["black"] = 435; p.data["white"] = 2805; p.data["r"] = 586; p.data["d"] = 854; p.data["d16"] = 0; p.data["r16"] = 0;
points[1596]=p;}
if (1==1){ Point p;
p.x = 22; p.y = 17; p.county = 0; p.val = 2260; p.data["black"] = 305; p.data["white"] = 1865; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1597]=p;}
if (1==1){ Point p;
p.x = 21; p.y = 20; p.county = 0; p.val = 1005; p.data["black"] = 95; p.data["white"] = 900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1598]=p;}
if (1==1){ Point p;
p.x = 14; p.y = 3; p.county = 0; p.val = 770; p.data["black"] = 0; p.data["white"] = 760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 237; p.data["r16"] = 848;
points[1599]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 54; p.county = 0; p.val = 1220; p.data["black"] = 195; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1600]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 51; p.county = 0; p.val = 335; p.data["black"] = 100; p.data["white"] = 225; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1601]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 60; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 355; p.data["r16"] = 1051;
points[1602]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 53; p.county = 0; p.val = 1025; p.data["black"] = 195; p.data["white"] = 785; p.data["r"] = 179; p.data["d"] = 216; p.data["d16"] = 0; p.data["r16"] = 0;
points[1603]=p;}
if (1==1){ Point p;
p.x = 87; p.y = 59; p.county = 0; p.val = 690; p.data["black"] = 15; p.data["white"] = 595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1604]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 63; p.county = 0; p.val = 545; p.data["black"] = 335; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 661; p.data["r16"] = 136;
points[1605]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 55; p.county = 0; p.val = 660; p.data["black"] = 350; p.data["white"] = 280; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1606]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 40; p.county = 0; p.val = 760; p.data["black"] = 250; p.data["white"] = 480; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1607]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 33; p.county = 0; p.val = 1615; p.data["black"] = 815; p.data["white"] = 800; p.data["r"] = 452; p.data["d"] = 313; p.data["d16"] = 0; p.data["r16"] = 0;
points[1608]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 73; p.county = 0; p.val = 830; p.data["black"] = 330; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1609]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 46; p.county = 0; p.val = 1250; p.data["black"] = 745; p.data["white"] = 480; p.data["r"] = 306; p.data["d"] = 228; p.data["d16"] = 0; p.data["r16"] = 0;
points[1610]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 51; p.county = 0; p.val = 1095; p.data["black"] = 775; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1611]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 50; p.county = 0; p.val = 910; p.data["black"] = 340; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1612]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 49; p.county = 0; p.val = 975; p.data["black"] = 500; p.data["white"] = 475; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1613]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 52; p.county = 0; p.val = 945; p.data["black"] = 225; p.data["white"] = 685; p.data["r"] = 105; p.data["d"] = 127; p.data["d16"] = 0; p.data["r16"] = 0;
points[1614]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 50; p.county = 0; p.val = 1635; p.data["black"] = 1010; p.data["white"] = 545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1615]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 42; p.county = 0; p.val = 995; p.data["black"] = 235; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1616]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 50; p.county = 0; p.val = 865; p.data["black"] = 460; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1617]=p;}
if (1==1){ Point p;
p.x = 40; p.y = 71; p.county = 0; p.val = 620; p.data["black"] = 535; p.data["white"] = 85; p.data["r"] = 337; p.data["d"] = 116; p.data["d16"] = 0; p.data["r16"] = 0;
points[1618]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 25; p.county = 0; p.val = 1020; p.data["black"] = 105; p.data["white"] = 900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1619]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 22; p.county = 0; p.val = 970; p.data["black"] = 405; p.data["white"] = 570; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1620]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 23; p.county = 0; p.val = 1100; p.data["black"] = 360; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1621]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 25; p.county = 0; p.val = 480; p.data["black"] = 70; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1622]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 7; p.county = 0; p.val = 3790; p.data["black"] = 465; p.data["white"] = 3225; p.data["r"] = 1456; p.data["d"] = 1924; p.data["d16"] = 0; p.data["r16"] = 0;
points[1623]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 7; p.county = 0; p.val = 2190; p.data["black"] = 650; p.data["white"] = 1530; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 481; p.data["r16"] = 572;
points[1624]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 11; p.county = 0; p.val = 710; p.data["black"] = 40; p.data["white"] = 635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1625]=p;}
if (1==1){ Point p;
p.x = 23; p.y = 16; p.county = 0; p.val = 1625; p.data["black"] = 390; p.data["white"] = 1185; p.data["r"] = 321; p.data["d"] = 478; p.data["d16"] = 341; p.data["r16"] = 634;
points[1626]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 21; p.county = 0; p.val = 865; p.data["black"] = 355; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 223; p.data["r16"] = 565;
points[1627]=p;}
if (1==1){ Point p;
p.x = 30; p.y = 20; p.county = 0; p.val = 745; p.data["black"] = 95; p.data["white"] = 650; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 163; p.data["r16"] = 665;
points[1628]=p;}
if (1==1){ Point p;
p.x = 29; p.y = 22; p.county = 0; p.val = 815; p.data["black"] = 505; p.data["white"] = 310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 583; p.data["r16"] = 277;
points[1629]=p;}
if (1==1){ Point p;
p.x = 31; p.y = 24; p.county = 0; p.val = 585; p.data["black"] = 30; p.data["white"] = 555; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1630]=p;}
if (1==1){ Point p;
p.x = 33; p.y = 22; p.county = 0; p.val = 820; p.data["black"] = 85; p.data["white"] = 710; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 372; p.data["r16"] = 450;
points[1631]=p;}
if (1==1){ Point p;
p.x = 26; p.y = 20; p.county = 0; p.val = 1015; p.data["black"] = 295; p.data["white"] = 700; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1632]=p;}
if (1==1){ Point p;
p.x = 72; p.y = 72; p.county = 0; p.val = 1660; p.data["black"] = 670; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1633]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 70; p.county = 0; p.val = 1795; p.data["black"] = 145; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1634]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 68; p.county = 0; p.val = 1085; p.data["black"] = 55; p.data["white"] = 960; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1635]=p;}
if (1==1){ Point p;
p.x = 74; p.y = 69; p.county = 0; p.val = 2845; p.data["black"] = 1675; p.data["white"] = 1085; p.data["r"] = 456; p.data["d"] = 235; p.data["d16"] = 0; p.data["r16"] = 0;
points[1636]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 72; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1637]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 4; p.county = 0; p.val = 1505; p.data["black"] = 50; p.data["white"] = 1380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1638]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 4; p.county = 0; p.val = 425; p.data["black"] = 0; p.data["white"] = 415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1639]=p;}
if (1==1){ Point p;
p.x = 94; p.y = 45; p.county = 0; p.val = 3940; p.data["black"] = 125; p.data["white"] = 3610; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1640]=p;}
if (1==1){ Point p;
p.x = 91; p.y = 45; p.county = 0; p.val = 2135; p.data["black"] = 305; p.data["white"] = 1575; p.data["r"] = 242; p.data["d"] = 466; p.data["d16"] = 0; p.data["r16"] = 0;
points[1641]=p;}
if (1==1){ Point p;
p.x = 96; p.y = 39; p.county = 0; p.val = 1745; p.data["black"] = 585; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 507; p.data["r16"] = 478;
points[1642]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 50; p.county = 0; p.val = 650; p.data["black"] = 585; p.data["white"] = 45; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1643]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 0; p.val = 470; p.data["black"] = 295; p.data["white"] = 170; p.data["r"] = 168; p.data["d"] = 100; p.data["d16"] = 0; p.data["r16"] = 0;
points[1644]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 47; p.county = 0; p.val = 445; p.data["black"] = 370; p.data["white"] = 75; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1645]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 49; p.county = 0; p.val = 700; p.data["black"] = 450; p.data["white"] = 250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1646]=p;}
if (1==1){ Point p;
p.x = 27; p.y = 52; p.county = 0; p.val = 1790; p.data["black"] = 395; p.data["white"] = 1370; p.data["r"] = 343; p.data["d"] = 1161; p.data["d16"] = 0; p.data["r16"] = 0;
points[1647]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 9; p.county = 0; p.val = 2005; p.data["black"] = 20; p.data["white"] = 1625; p.data["r"] = 193; p.data["d"] = 627; p.data["d16"] = 162; p.data["r16"] = 673;
points[1648]=p;}
if (1==1){ Point p;
p.x = 48; p.y = 11; p.county = 0; p.val = 1710; p.data["black"] = 340; p.data["white"] = 1340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1649]=p;}
if (1==1){ Point p;
p.x = 42; p.y = 2; p.county = 0; p.val = 1860; p.data["black"] = 60; p.data["white"] = 1735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 426; p.data["r16"] = 542;
points[1650]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 97; p.county = 0; p.val = 195; p.data["black"] = 0; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1651]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 94; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 275; p.data["d"] = 461; p.data["d16"] = 0; p.data["r16"] = 0;
points[1652]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 87; p.county = 0; p.val = 530; p.data["black"] = 365; p.data["white"] = 105; p.data["r"] = 447; p.data["d"] = 286; p.data["d16"] = 524; p.data["r16"] = 373;
points[1653]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 3; p.county = 0; p.val = 2210; p.data["black"] = 360; p.data["white"] = 1645; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1654]=p;}
if (1==1){ Point p;
p.x = 89; p.y = 48; p.county = 0; p.val = 1960; p.data["black"] = 875; p.data["white"] = 1070; p.data["r"] = 87; p.data["d"] = 112; p.data["d16"] = 0; p.data["r16"] = 0;
points[1655]=p;}
if (1==1){ Point p;
p.x = 20; p.y = 32; p.county = 0; p.val = 1150; p.data["black"] = 890; p.data["white"] = 255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1656]=p;}
if (1==1){ Point p;
p.x = 85; p.y = 48; p.county = 0; p.val = 735; p.data["black"] = 310; p.data["white"] = 370; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1657]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 58; p.county = 0; p.val = 755; p.data["black"] = 615; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1658]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 55; p.county = 0; p.val = 1885; p.data["black"] = 1095; p.data["white"] = 705; p.data["r"] = 866; p.data["d"] = 172; p.data["d16"] = 0; p.data["r16"] = 0;
points[1659]=p;}
if (1==1){ Point p;
p.x = 86; p.y = 54; p.county = 0; p.val = 1050; p.data["black"] = 735; p.data["white"] = 315; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1660]=p;}
if (1==1){ Point p;
p.x = 80; p.y = 60; p.county = 0; p.val = 1355; p.data["black"] = 715; p.data["white"] = 635; p.data["r"] = 66; p.data["d"] = 231; p.data["d16"] = 0; p.data["r16"] = 0;
points[1661]=p;}
if (1==1){ Point p;
p.x = 83; p.y = 50; p.county = 0; p.val = 800; p.data["black"] = 405; p.data["white"] = 395; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 509; p.data["r16"] = 171;
points[1662]=p;}
if (1==1){ Point p;
p.x = 81; p.y = 57; p.county = 0; p.val = 1295; p.data["black"] = 65; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 82; p.data["r16"] = 647;
points[1663]=p;}
if (1==1){ Point p;
p.x = 84; p.y = 47; p.county = 0; p.val = 1150; p.data["black"] = 410; p.data["white"] = 735; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1664]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 55; p.county = 0; p.val = 1175; p.data["black"] = 1020; p.data["white"] = 85; p.data["r"] = 767; p.data["d"] = 12; p.data["d16"] = 394; p.data["r16"] = 9;
points[1665]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 54; p.county = 0; p.val = 855; p.data["black"] = 535; p.data["white"] = 310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1666]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 57; p.county = 0; p.val = 855; p.data["black"] = 165; p.data["white"] = 675; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1667]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 56; p.county = 0; p.val = 635; p.data["black"] = 100; p.data["white"] = 535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1668]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 49; p.county = 0; p.val = 750; p.data["black"] = 325; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1669]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 70; p.county = 0; p.val = 1575; p.data["black"] = 170; p.data["white"] = 1385; p.data["r"] = 129; p.data["d"] = 231; p.data["d16"] = 373; p.data["r16"] = 937;
points[1670]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 69; p.county = 0; p.val = 1115; p.data["black"] = 110; p.data["white"] = 985; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1671]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 68; p.county = 0; p.val = 2840; p.data["black"] = 385; p.data["white"] = 2290; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1672]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 69; p.county = 0; p.val = 8105; p.data["black"] = 1150; p.data["white"] = 6655; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 341; p.data["r16"] = 794;
points[1673]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 68; p.county = 0; p.val = 2130; p.data["black"] = 395; p.data["white"] = 1595; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1674]=p;}
if (1==1){ Point p;
p.x = 65; p.y = 71; p.county = 0; p.val = 2020; p.data["black"] = 465; p.data["white"] = 1450; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 224; p.data["r16"] = 295;
points[1675]=p;}
if (1==1){ Point p;
p.x = 67; p.y = 73; p.county = 0; p.val = 2505; p.data["black"] = 575; p.data["white"] = 1535; p.data["r"] = 980; p.data["d"] = 1086; p.data["d16"] = 629; p.data["r16"] = 640;
points[1676]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 63; p.county = 0; p.val = 1475; p.data["black"] = 755; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1677]=p;}
if (1==1){ Point p;
p.x = 19; p.y = 28; p.county = 0; p.val = 730; p.data["black"] = 155; p.data["white"] = 515; p.data["r"] = 310; p.data["d"] = 503; p.data["d16"] = 0; p.data["r16"] = 0;
points[1678]=p;}
if (1==1){ Point p;
p.x = 44; p.y = 70; p.county = 0; p.val = 675; p.data["black"] = 495; p.data["white"] = 180; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1679]=p;}
if (1==1){ Point p;
p.x = 41; p.y = 74; p.county = 0; p.val = 1330; p.data["black"] = 790; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 693; p.data["r16"] = 73;
points[1680]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 72; p.county = 0; p.val = 765; p.data["black"] = 60; p.data["white"] = 665; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 42; p.data["r16"] = 235;
points[1681]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 56; p.county = 0; p.val = 435; p.data["black"] = 85; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1682]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 60; p.county = 0; p.val = 1105; p.data["black"] = 470; p.data["white"] = 625; p.data["r"] = 655; p.data["d"] = 370; p.data["d16"] = 704; p.data["r16"] = 488;
points[1683]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 54; p.county = 0; p.val = 680; p.data["black"] = 440; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1684]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 52; p.county = 0; p.val = 560; p.data["black"] = 290; p.data["white"] = 150; p.data["r"] = 369; p.data["d"] = 157; p.data["d16"] = 0; p.data["r16"] = 0;
points[1685]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 73; p.county = 0; p.val = 1075; p.data["black"] = 285; p.data["white"] = 770; p.data["r"] = 276; p.data["d"] = 338; p.data["d16"] = 0; p.data["r16"] = 0;
points[1686]=p;}
if (1==1){ Point p;
p.x = 59; p.y = 71; p.county = 0; p.val = 1845; p.data["black"] = 395; p.data["white"] = 1420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1687]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 81; p.county = 0; p.val = 440; p.data["black"] = 275; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1688]=p;}
if (1==1){ Point p;
p.x = 53; p.y = 66; p.county = 0; p.val = 815; p.data["black"] = 580; p.data["white"] = 210; p.data["r"] = 418; p.data["d"] = 184; p.data["d16"] = 0; p.data["r16"] = 0;
points[1689]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 75; p.county = 0; p.val = 965; p.data["black"] = 465; p.data["white"] = 445; p.data["r"] = 455; p.data["d"] = 479; p.data["d16"] = 302; p.data["r16"] = 311;
points[1690]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 76; p.county = 0; p.val = 950; p.data["black"] = 530; p.data["white"] = 420; p.data["r"] = 264; p.data["d"] = 175; p.data["d16"] = 0; p.data["r16"] = 0;
points[1691]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 86; p.county = 0; p.val = 705; p.data["black"] = 4; p.data["white"] = 685; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1692]=p;}
if (1==1){ Point p;
p.x = 58; p.y = 82; p.county = 0; p.val = 630; p.data["black"] = 430; p.data["white"] = 200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 519; p.data["r16"] = 162;
points[1693]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 75; p.county = 0; p.val = 865; p.data["black"] = 335; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 68; p.data["r16"] = 103;
points[1694]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 70; p.county = 0; p.val = 1950; p.data["black"] = 730; p.data["white"] = 1170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1695]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 72; p.county = 0; p.val = 700; p.data["black"] = 195; p.data["white"] = 505; p.data["r"] = 95; p.data["d"] = 169; p.data["d16"] = 184; p.data["r16"] = 293;
points[1696]=p;}
if (1==1){ Point p;
p.x = 57; p.y = 71; p.county = 0; p.val = 2165; p.data["black"] = 515; p.data["white"] = 1485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1697]=p;}
if (1==1){ Point p;
p.x = 52; p.y = 68; p.county = 0; p.val = 450; p.data["black"] = 150; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1698]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 73; p.county = 0; p.val = 1115; p.data["black"] = 335; p.data["white"] = 525; p.data["r"] = 265; p.data["d"] = 529; p.data["d16"] = 289; p.data["r16"] = 677;
points[1699]=p;}
if (1==1){ Point p;
p.x = 49; p.y = 69; p.county = 0; p.val = 595; p.data["black"] = 240; p.data["white"] = 355; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1700]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 72; p.county = 0; p.val = 1100; p.data["black"] = 230; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1701]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 44; p.county = 0; p.val = 925; p.data["black"] = 495; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1702]=p;}
if (1==1){ Point p;
p.x = 55; p.y = 79; p.county = 0; p.val = 550; p.data["black"] = 360; p.data["white"] = 150; p.data["r"] = 373; p.data["d"] = 184; p.data["d16"] = 367; p.data["r16"] = 144;
points[1703]=p;}
if (1==1){ Point p;
p.x = 50; p.y = 26; p.county = 0; p.val = 660; p.data["black"] = 445; p.data["white"] = 220; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1704]=p;}
if (1==1){ Point p;
p.x = 47; p.y = 29; p.county = 0; p.val = 930; p.data["black"] = 465; p.data["white"] = 345; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 374; p.data["r16"] = 288;
points[1705]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 73; p.county = 0; p.val = 1115; p.data["black"] = 460; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1706]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 77; p.county = 0; p.val = 945; p.data["black"] = 425; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1707]=p;}
if (1==1){ Point p;
p.x = 54; p.y = 68; p.county = 0; p.val = 660; p.data["black"] = 185; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1708]=p;}
if (1==1){ Point p;
p.x = 56; p.y = 73; p.county = 0; p.val = 2490; p.data["black"] = 1595; p.data["white"] = 900; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 400; p.data["r16"] = 203;
points[1709]=p;}
if (1==1){ Point p;
p.x = 46; p.y = 18; p.county = 0; p.val = 655; p.data["black"] = 115; p.data["white"] = 500; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1710]=p;}
if (1==1){ Point p;
p.x = 43; p.y = 13; p.county = 0; p.val = 1035; p.data["black"] = 100; p.data["white"] = 890; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1711]=p;}
if (1==1){ Point p;
p.x = 63; p.y = 46; p.county = 0; p.val = 1505; p.data["black"] = 695; p.data["white"] = 785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1712]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 43; p.county = 0; p.val = 705; p.data["black"] = 145; p.data["white"] = 520; p.data["r"] = 329; p.data["d"] = 273; p.data["d16"] = 177; p.data["r16"] = 261;
points[1713]=p;}
if (1==1){ Point p;
p.x = 69; p.y = 45; p.county = 0; p.val = 720; p.data["black"] = 470; p.data["white"] = 225; p.data["r"] = 119; p.data["d"] = 86; p.data["d16"] = 0; p.data["r16"] = 0;
points[1714]=p;}
if (1==1){ Point p;
p.x = 64; p.y = 48; p.county = 0; p.val = 1090; p.data["black"] = 940; p.data["white"] = 80; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1715]=p;}
if (1==1){ Point p;
p.x = 62; p.y = 50; p.county = 0; p.val = 1110; p.data["black"] = 850; p.data["white"] = 240; p.data["r"] = 446; p.data["d"] = 91; p.data["d16"] = 175; p.data["r16"] = 48;
points[1716]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 42; p.county = 0; p.val = 635; p.data["black"] = 160; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 57; p.data["r16"] = 390;
points[1717]=p;}
if (1==1){ Point p;
p.x = 61; p.y = 52; p.county = 0; p.val = 475; p.data["black"] = 335; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1718]=p;}
if (1==1){ Point p;
p.x = 60; p.y = 49; p.county = 0; p.val = 390; p.data["black"] = 330; p.data["white"] = 60; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 416; p.data["r16"] = 81;
points[1719]=p;}
if (1==1){ Point p;
p.x = 70; p.y = 41; p.county = 0; p.val = 1110; p.data["black"] = 315; p.data["white"] = 780; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1720]=p;}
if (1==1){ Point p;
p.x = 75; p.y = 41; p.county = 0; p.val = 855; p.data["black"] = 545; p.data["white"] = 310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1721]=p;}
if (1==1){ Point p;
p.x = 76; p.y = 41; p.county = 0; p.val = 510; p.data["black"] = 235; p.data["white"] = 260; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1722]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 62; p.county = 0; p.val = 520; p.data["black"] = 80; p.data["white"] = 445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1723]=p;}
if (1==1){ Point p;
p.x = 71; p.y = 58; p.county = 0; p.val = 1610; p.data["black"] = 825; p.data["white"] = 785; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1724]=p;}
if (1==1){ Point p;
p.x = 77; p.y = 64; p.county = 0; p.val = 1450; p.data["black"] = 700; p.data["white"] = 680; p.data["r"] = 187; p.data["d"] = 119; p.data["d16"] = 17; p.data["r16"] = 164;
points[1725]=p;}
if (1==1){ Point p;
p.x = 66; p.y = 57; p.county = 0; p.val = 760; p.data["black"] = 450; p.data["white"] = 285; p.data["r"] = 525; p.data["d"] = 127; p.data["d16"] = 1040; p.data["r16"] = 282;
points[1726]=p;}
if (1==1){ Point p;
p.x = 68; p.y = 55; p.county = 0; p.val = 430; p.data["black"] = 290; p.data["white"] = 95; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[1727]=p;}
np = 1728;
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
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
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
				for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
					m.pixels[i][ii]=m.pixels[i][ii+1];
				}
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

	
	killCarveV = false;
	killCarveH = false;
	
	auto a11 = std::chrono::high_resolution_clock::now();
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();

	a11 = std::chrono::high_resolution_clock::now();
	
	np =0;//will get set to right value in scPoints()
	scPoints0();
	scPoints1();
	
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
	

	
	for(i=0;i<100;i++){
		for(ii=0;ii<100;ii++){
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
			
			minX = i-6;
			maxX = i+6;
			minY = ii-6;
			maxY = ii+6;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > 100){maxX = 100;}
			if (maxY > 100){maxY = 100;}
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
	for(i=0;i<100;i++){
		for(ii=0;ii<100;ii++){
			if (pixelMap[i][ii]>=0){
				pixels[i][ii].val += points[pixelMap[i][ii]].val*100/points[pixelMap[i][ii]].npix;
				for (iii=0;iii<nd;iii++){
					s = datas[iii];
					pixels[i][ii].data[s] += points[pixelMap[i][ii]].data[s]*100/points[pixelMap[i][ii]].npix;
				}
				pixels[i][ii].x = points[pixelMap[i][ii]].x;
				pixels[i][ii].y = points[pixelMap[i][ii]].y;
				pixels[i][ii].county = points[pixelMap[i][ii]].county;
				continue;
			}
			int minX = i-3;
			int maxX = i+3;
			int minY = ii-3;
			int maxY = ii+3;
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
				for (iii=0;iii<nd;iii++){
					s = datas[iii];
					pixels[i][ii].data[s] += points[minI].data[s]*100/points[minI].npix;
				}
				pixels[i][ii].x = points[minI].x;
				pixels[i][ii].y = points[minI].y;
				pixels[i][ii].county = points[minI].county;
				continue;
			}
			
			minX = i-6;
			maxX = i+6;
			minY = ii-6;
			maxY = ii+6;
			if (minX < 0){minX = 0;}
			if (minY < 0){minY = 0;}
			if (maxX > 100){maxX = 100;}
			if (maxY > 100){maxY = 100;}
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
				pixels[i][ii].x = points[minI].x;
				pixels[i][ii].y = points[minI].y;
				pixels[i][ii].county = points[minI].county;
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
