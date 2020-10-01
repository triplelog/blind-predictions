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

std::map<int,Point> scPoints(){
std::map<int,Point> points; int i=0;
if (1==1){ Point p;
p.x = 63; p.y = 50; p.county = 0; p.val = 850; p.data["black"] = 375; p.data["white"] = 485; p.data["r"] = 619; p.data["d"] = 347; p.data["d16"] = 550; p.data["r16"] = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 50; p.county = 0; p.val = 1910; p.data["black"] = 800; p.data["white"] = 995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 17; p.county = 0; p.val = 1190; p.data["black"] = 385; p.data["white"] = 775; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 37; p.county = 0; p.val = 3565; p.data["black"] = 1405; p.data["white"] = 1785; p.data["r"] = 820; p.data["d"] = 1134; p.data["d16"] = 558; p.data["r16"] = 942;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 1; p.county = 0; p.val = 905; p.data["black"] = 905; p.data["white"] = 0; p.data["r"] = 551; p.data["d"] = 96; p.data["d16"] = 736; p.data["r16"] = 129;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 35; p.county = 0; p.val = 3125; p.data["black"] = 810; p.data["white"] = 2085; p.data["r"] = 613; p.data["d"] = 692; p.data["d16"] = 498; p.data["r16"] = 664;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 33; p.county = 0; p.val = 5425; p.data["black"] = 1750; p.data["white"] = 3045; p.data["r"] = 734; p.data["d"] = 525; p.data["d16"] = 703; p.data["r16"] = 708;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 24; p.county = 0; p.val = 3925; p.data["black"] = 570; p.data["white"] = 3025; p.data["r"] = 1157; p.data["d"] = 1518; p.data["d16"] = 801; p.data["r16"] = 1557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 22; p.county = 0; p.val = 2915; p.data["black"] = 1135; p.data["white"] = 1565; p.data["r"] = 676; p.data["d"] = 558; p.data["d16"] = 586; p.data["r16"] = 764;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 37; p.county = 0; p.val = 465; p.data["black"] = 10; p.data["white"] = 425; p.data["r"] = 354; p.data["d"] = 321; p.data["d16"] = 350; p.data["r16"] = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 39; p.county = 0; p.val = 4180; p.data["black"] = 500; p.data["white"] = 3265; p.data["r"] = 224; p.data["d"] = 459; p.data["d16"] = 240; p.data["r16"] = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 29; p.county = 0; p.val = 2220; p.data["black"] = 330; p.data["white"] = 1550; p.data["r"] = 1192; p.data["d"] = 1495; p.data["d16"] = 768; p.data["r16"] = 1267;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 28; p.county = 0; p.val = 1370; p.data["black"] = 55; p.data["white"] = 1095; p.data["r"] = 229; p.data["d"] = 936; p.data["d16"] = 218; p.data["r16"] = 1330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 37; p.county = 0; p.val = 2640; p.data["black"] = 680; p.data["white"] = 1580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 22; p.county = 0; p.val = 1300; p.data["black"] = 480; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 32; p.county = 0; p.val = 2580; p.data["black"] = 480; p.data["white"] = 1820; p.data["r"] = 375; p.data["d"] = 497; p.data["d16"] = 398; p.data["r16"] = 612;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 4; p.county = 0; p.val = 1000; p.data["black"] = 555; p.data["white"] = 430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 39; p.county = 0; p.val = 1060; p.data["black"] = 175; p.data["white"] = 870; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 49; p.county = 0; p.val = 2245; p.data["black"] = 650; p.data["white"] = 1450; p.data["r"] = 447; p.data["d"] = 537; p.data["d16"] = 438; p.data["r16"] = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 48; p.county = 0; p.val = 2630; p.data["black"] = 335; p.data["white"] = 2195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 411; p.data["r16"] = 328;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 47; p.county = 0; p.val = 3210; p.data["black"] = 150; p.data["white"] = 2875; p.data["r"] = 1286; p.data["d"] = 1304; p.data["d16"] = 315; p.data["r16"] = 401;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 48; p.county = 0; p.val = 1845; p.data["black"] = 150; p.data["white"] = 1590; p.data["r"] = 540; p.data["d"] = 677; p.data["d16"] = 218; p.data["r16"] = 399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 45; p.county = 0; p.val = 615; p.data["black"] = 475; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 41; p.county = 0; p.val = 655; p.data["black"] = 110; p.data["white"] = 435; p.data["r"] = 666; p.data["d"] = 1089; p.data["d16"] = 509; p.data["r16"] = 1026;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 39; p.county = 0; p.val = 795; p.data["black"] = 355; p.data["white"] = 405; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 89; p.county = 0; p.val = 2065; p.data["black"] = 140; p.data["white"] = 1690; p.data["r"] = 473; p.data["d"] = 267; p.data["d16"] = 473; p.data["r16"] = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 88; p.county = 0; p.val = 1400; p.data["black"] = 75; p.data["white"] = 1295; p.data["r"] = 335; p.data["d"] = 450; p.data["d16"] = 286; p.data["r16"] = 574;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 88; p.county = 0; p.val = 1345; p.data["black"] = 95; p.data["white"] = 1140; p.data["r"] = 627; p.data["d"] = 637; p.data["d16"] = 589; p.data["r16"] = 770;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 90; p.county = 0; p.val = 605; p.data["black"] = 0; p.data["white"] = 545; p.data["r"] = 623; p.data["d"] = 896; p.data["d16"] = 519; p.data["r16"] = 1021;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 90; p.county = 0; p.val = 2005; p.data["black"] = 250; p.data["white"] = 1530; p.data["r"] = 483; p.data["d"] = 408; p.data["d16"] = 475; p.data["r16"] = 473;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 74; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 75; p.county = 0; p.val = 930; p.data["black"] = 145; p.data["white"] = 595; p.data["r"] = 499; p.data["d"] = 333; p.data["d16"] = 481; p.data["r16"] = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 77; p.county = 0; p.val = 2230; p.data["black"] = 455; p.data["white"] = 1610; p.data["r"] = 418; p.data["d"] = 519; p.data["d16"] = 376; p.data["r16"] = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 74; p.county = 0; p.val = 780; p.data["black"] = 130; p.data["white"] = 555; p.data["r"] = 495; p.data["d"] = 115; p.data["d16"] = 512; p.data["r16"] = 129;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 74; p.county = 0; p.val = 1075; p.data["black"] = 115; p.data["white"] = 790; p.data["r"] = 147; p.data["d"] = 111; p.data["d16"] = 151; p.data["r16"] = 211;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 76; p.county = 0; p.val = 2670; p.data["black"] = 390; p.data["white"] = 1935; p.data["r"] = 225; p.data["d"] = 484; p.data["d16"] = 223; p.data["r16"] = 485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 70; p.county = 0; p.val = 1960; p.data["black"] = 1440; p.data["white"] = 475; p.data["r"] = 404; p.data["d"] = 124; p.data["d16"] = 431; p.data["r16"] = 159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 76; p.county = 0; p.val = 2130; p.data["black"] = 1345; p.data["white"] = 585; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 76; p.county = 0; p.val = 680; p.data["black"] = 370; p.data["white"] = 285; p.data["r"] = 646; p.data["d"] = 165; p.data["d16"] = 663; p.data["r16"] = 197;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 96; p.county = 0; p.val = 1685; p.data["black"] = 10; p.data["white"] = 1670; p.data["r"] = 361; p.data["d"] = 407; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 96; p.county = 0; p.val = 485; p.data["black"] = 0; p.data["white"] = 410; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 85; p.county = 0; p.val = 750; p.data["black"] = 10; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 84; p.county = 0; p.val = 1050; p.data["black"] = 450; p.data["white"] = 550; p.data["r"] = 670; p.data["d"] = 165; p.data["d16"] = 686; p.data["r16"] = 183;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 43; p.county = 0; p.val = 1255; p.data["black"] = 1010; p.data["white"] = 210; p.data["r"] = 679; p.data["d"] = 67; p.data["d16"] = 567; p.data["r16"] = 73;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 87; p.county = 0; p.val = 7680; p.data["black"] = 175; p.data["white"] = 7350; p.data["r"] = 1942; p.data["d"] = 3117; p.data["d16"] = 1531; p.data["r16"] = 2523;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 88; p.county = 0; p.val = 465; p.data["black"] = 0; p.data["white"] = 390; p.data["r"] = 516; p.data["d"] = 649; p.data["d16"] = 480; p.data["r16"] = 634;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 87; p.county = 0; p.val = 4550; p.data["black"] = 140; p.data["white"] = 4310; p.data["r"] = 600; p.data["d"] = 885; p.data["d16"] = 755; p.data["r16"] = 1390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 88; p.county = 0; p.val = 755; p.data["black"] = 130; p.data["white"] = 605; p.data["r"] = 600; p.data["d"] = 1011; p.data["d16"] = 519; p.data["r16"] = 1076;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 95; p.county = 0; p.val = 280; p.data["black"] = 0; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 93; p.county = 0; p.val = 1580; p.data["black"] = 60; p.data["white"] = 1425; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 28; p.county = 0; p.val = 1345; p.data["black"] = 710; p.data["white"] = 390; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 33; p.county = 0; p.val = 1410; p.data["black"] = 250; p.data["white"] = 965; p.data["r"] = 294; p.data["d"] = 517; p.data["d16"] = 264; p.data["r16"] = 594;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 21; p.county = 0; p.val = 945; p.data["black"] = 420; p.data["white"] = 505; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 13; p.county = 0; p.val = 460; p.data["black"] = 245; p.data["white"] = 215; p.data["r"] = 358; p.data["d"] = 340; p.data["d16"] = 443; p.data["r16"] = 510;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 34; p.county = 0; p.val = 2825; p.data["black"] = 295; p.data["white"] = 2240; p.data["r"] = 430; p.data["d"] = 917; p.data["d16"] = 461; p.data["r16"] = 1062;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 37; p.county = 0; p.val = 4035; p.data["black"] = 420; p.data["white"] = 3415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 24; p.county = 0; p.val = 945; p.data["black"] = 615; p.data["white"] = 315; p.data["r"] = 265; p.data["d"] = 265; p.data["d16"] = 299; p.data["r16"] = 363;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 35; p.county = 0; p.val = 2030; p.data["black"] = 245; p.data["white"] = 1690; p.data["r"] = 233; p.data["d"] = 495; p.data["d16"] = 197; p.data["r16"] = 585;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 29; p.county = 0; p.val = 1410; p.data["black"] = 610; p.data["white"] = 745; p.data["r"] = 414; p.data["d"] = 584; p.data["d16"] = 859; p.data["r16"] = 1684;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 16; p.county = 0; p.val = 1070; p.data["black"] = 475; p.data["white"] = 590; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 17; p.county = 0; p.val = 705; p.data["black"] = 520; p.data["white"] = 145; p.data["r"] = 178; p.data["d"] = 87; p.data["d16"] = 237; p.data["r16"] = 122;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 19; p.county = 0; p.val = 1065; p.data["black"] = 295; p.data["white"] = 705; p.data["r"] = 260; p.data["d"] = 337; p.data["d16"] = 336; p.data["r16"] = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 26; p.county = 0; p.val = 1300; p.data["black"] = 525; p.data["white"] = 765; p.data["r"] = 230; p.data["d"] = 346; p.data["d16"] = 293; p.data["r16"] = 450;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 33; p.county = 0; p.val = 715; p.data["black"] = 85; p.data["white"] = 610; p.data["r"] = 196; p.data["d"] = 426; p.data["d16"] = 191; p.data["r16"] = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 43; p.county = 0; p.val = 670; p.data["black"] = 335; p.data["white"] = 325; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 34; p.county = 0; p.val = 3085; p.data["black"] = 305; p.data["white"] = 2265; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 843; p.data["r16"] = 795;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 29; p.county = 0; p.val = 2845; p.data["black"] = 615; p.data["white"] = 2005; p.data["r"] = 933; p.data["d"] = 557; p.data["d16"] = 935; p.data["r16"] = 692;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 33; p.county = 0; p.val = 2130; p.data["black"] = 190; p.data["white"] = 1820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 35; p.county = 0; p.val = 1725; p.data["black"] = 575; p.data["white"] = 830; p.data["r"] = 509; p.data["d"] = 200; p.data["d16"] = 704; p.data["r16"] = 336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 18; p.county = 0; p.val = 1520; p.data["black"] = 850; p.data["white"] = 650; p.data["r"] = 267; p.data["d"] = 565; p.data["d16"] = 293; p.data["r16"] = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 21; p.county = 0; p.val = 1370; p.data["black"] = 580; p.data["white"] = 695; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 37; p.county = 0; p.val = 1315; p.data["black"] = 65; p.data["white"] = 940; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 41; p.county = 0; p.val = 1735; p.data["black"] = 35; p.data["white"] = 1480; p.data["r"] = 1361; p.data["d"] = 2164; p.data["d16"] = 968; p.data["r16"] = 2071;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 26; p.county = 0; p.val = 1975; p.data["black"] = 1035; p.data["white"] = 760; p.data["r"] = 206; p.data["d"] = 174; p.data["d16"] = 256; p.data["r16"] = 217;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 92; p.county = 0; p.val = 1090; p.data["black"] = 120; p.data["white"] = 915; p.data["r"] = 292; p.data["d"] = 506; p.data["d16"] = 330; p.data["r16"] = 629;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 82; p.county = 0; p.val = 3290; p.data["black"] = 285; p.data["white"] = 2155; p.data["r"] = 314; p.data["d"] = 403; p.data["d16"] = 313; p.data["r16"] = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 86; p.county = 0; p.val = 1845; p.data["black"] = 0; p.data["white"] = 1820; p.data["r"] = 1286; p.data["d"] = 2444; p.data["d16"] = 545; p.data["r16"] = 1307;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 84; p.county = 0; p.val = 285; p.data["black"] = 0; p.data["white"] = 285; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 88; p.county = 0; p.val = 2215; p.data["black"] = 30; p.data["white"] = 1990; p.data["r"] = 496; p.data["d"] = 794; p.data["d16"] = 1263; p.data["r16"] = 2116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 93; p.county = 0; p.val = 715; p.data["black"] = 25; p.data["white"] = 630; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 100; p.county = 0; p.val = 375; p.data["black"] = 0; p.data["white"] = 375; p.data["r"] = 110; p.data["d"] = 188; p.data["d16"] = 115; p.data["r16"] = 185;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 98; p.county = 0; p.val = 1470; p.data["black"] = 74; p.data["white"] = 1310; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 92; p.county = 0; p.val = 465; p.data["black"] = 0; p.data["white"] = 460; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 91; p.county = 0; p.val = 2630; p.data["black"] = 95; p.data["white"] = 2525; p.data["r"] = 211; p.data["d"] = 385; p.data["d16"] = 228; p.data["r16"] = 436;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 0; p.val = 740; p.data["black"] = 305; p.data["white"] = 250; p.data["r"] = 438; p.data["d"] = 225; p.data["d16"] = 568; p.data["r16"] = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 66; p.county = 0; p.val = 1210; p.data["black"] = 570; p.data["white"] = 610; p.data["r"] = 356; p.data["d"] = 300; p.data["d16"] = 443; p.data["r16"] = 304;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 73; p.county = 0; p.val = 1220; p.data["black"] = 640; p.data["white"] = 530; p.data["r"] = 276; p.data["d"] = 236; p.data["d16"] = 312; p.data["r16"] = 354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 82; p.county = 0; p.val = 2435; p.data["black"] = 75; p.data["white"] = 2270; p.data["r"] = 381; p.data["d"] = 690; p.data["d16"] = 397; p.data["r16"] = 721;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 72; p.county = 0; p.val = 1880; p.data["black"] = 210; p.data["white"] = 1550; p.data["r"] = 796; p.data["d"] = 1208; p.data["d16"] = 662; p.data["r16"] = 1288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 73; p.county = 0; p.val = 670; p.data["black"] = 80; p.data["white"] = 370; p.data["r"] = 96; p.data["d"] = 88; p.data["d16"] = 191; p.data["r16"] = 113;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 77; p.county = 0; p.val = 1510; p.data["black"] = 595; p.data["white"] = 840; p.data["r"] = 658; p.data["d"] = 1134; p.data["d16"] = 634; p.data["r16"] = 1253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 73; p.county = 0; p.val = 285; p.data["black"] = 150; p.data["white"] = 140; p.data["r"] = 738; p.data["d"] = 683; p.data["d16"] = 750; p.data["r16"] = 706;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 80; p.county = 0; p.val = 820; p.data["black"] = 65; p.data["white"] = 740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 78; p.county = 0; p.val = 1105; p.data["black"] = 140; p.data["white"] = 875; p.data["r"] = 604; p.data["d"] = 592; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 81; p.county = 0; p.val = 1620; p.data["black"] = 1415; p.data["white"] = 200; p.data["r"] = 624; p.data["d"] = 130; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 78; p.county = 0; p.val = 2990; p.data["black"] = 1025; p.data["white"] = 1770; p.data["r"] = 428; p.data["d"] = 434; p.data["d16"] = 449; p.data["r16"] = 566;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 84; p.county = 0; p.val = 1040; p.data["black"] = 0; p.data["white"] = 1000; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 91; p.county = 0; p.val = 395; p.data["black"] = 0; p.data["white"] = 395; p.data["r"] = 644; p.data["d"] = 921; p.data["d16"] = 509; p.data["r16"] = 1007;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 21; p.county = 0; p.val = 945; p.data["black"] = 475; p.data["white"] = 455; p.data["r"] = 128; p.data["d"] = 215; p.data["d16"] = 209; p.data["r16"] = 299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 35; p.county = 0; p.val = 1890; p.data["black"] = 750; p.data["white"] = 1085; p.data["r"] = 167; p.data["d"] = 351; p.data["d16"] = 227; p.data["r16"] = 415;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 26; p.county = 0; p.val = 810; p.data["black"] = 245; p.data["white"] = 555; p.data["r"] = 231; p.data["d"] = 229; p.data["d16"] = 273; p.data["r16"] = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 32; p.county = 0; p.val = 1395; p.data["black"] = 785; p.data["white"] = 550; p.data["r"] = 1098; p.data["d"] = 829; p.data["d16"] = 1125; p.data["r16"] = 1037;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 20; p.county = 0; p.val = 1125; p.data["black"] = 520; p.data["white"] = 605; p.data["r"] = 284; p.data["d"] = 261; p.data["d16"] = 354; p.data["r16"] = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 12; p.county = 0; p.val = 2255; p.data["black"] = 55; p.data["white"] = 2140; p.data["r"] = 201; p.data["d"] = 310; p.data["d16"] = 210; p.data["r16"] = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 24; p.county = 0; p.val = 1110; p.data["black"] = 240; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 34; p.county = 0; p.val = 2955; p.data["black"] = 1005; p.data["white"] = 1745; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 41; p.county = 0; p.val = 1655; p.data["black"] = 165; p.data["white"] = 1365; p.data["r"] = 638; p.data["d"] = 381; p.data["d16"] = 1154; p.data["r16"] = 620;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 41; p.county = 0; p.val = 2430; p.data["black"] = 345; p.data["white"] = 1930; p.data["r"] = 270; p.data["d"] = 43; p.data["d16"] = 383; p.data["r16"] = 49;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 22; p.county = 0; p.val = 1890; p.data["black"] = 505; p.data["white"] = 1335; p.data["r"] = 245; p.data["d"] = 377; p.data["d16"] = 262; p.data["r16"] = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 51; p.county = 0; p.val = 1420; p.data["black"] = 0; p.data["white"] = 1395; p.data["r"] = 591; p.data["d"] = 430; p.data["d16"] = 617; p.data["r16"] = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 50; p.county = 0; p.val = 2465; p.data["black"] = 470; p.data["white"] = 1950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 40; p.county = 0; p.val = 1265; p.data["black"] = 560; p.data["white"] = 555; p.data["r"] = 168; p.data["d"] = 35; p.data["d16"] = 279; p.data["r16"] = 45;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 39; p.county = 0; p.val = 1255; p.data["black"] = 790; p.data["white"] = 360; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 41; p.county = 0; p.val = 915; p.data["black"] = 650; p.data["white"] = 190; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 39; p.county = 0; p.val = 1650; p.data["black"] = 1000; p.data["white"] = 515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 40; p.county = 0; p.val = 2445; p.data["black"] = 1450; p.data["white"] = 775; p.data["r"] = 868; p.data["d"] = 222; p.data["d16"] = 977; p.data["r16"] = 356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 64; p.county = 0; p.val = 145; p.data["black"] = 0; p.data["white"] = 145; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 43; p.county = 0; p.val = 2585; p.data["black"] = 1295; p.data["white"] = 1165; p.data["r"] = 950; p.data["d"] = 137; p.data["d16"] = 960; p.data["r16"] = 57;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 46; p.county = 0; p.val = 4115; p.data["black"] = 2585; p.data["white"] = 1255; p.data["r"] = 1301; p.data["d"] = 763; p.data["d16"] = 1570; p.data["r16"] = 942;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 52; p.county = 0; p.val = 1815; p.data["black"] = 360; p.data["white"] = 1330; p.data["r"] = 1427; p.data["d"] = 1132; p.data["d16"] = 1383; p.data["r16"] = 1516;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 47; p.county = 0; p.val = 3325; p.data["black"] = 500; p.data["white"] = 2545; p.data["r"] = 634; p.data["d"] = 455; p.data["d16"] = 699; p.data["r16"] = 724;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 49; p.county = 0; p.val = 2150; p.data["black"] = 1205; p.data["white"] = 815; p.data["r"] = 329; p.data["d"] = 291; p.data["d16"] = 255; p.data["r16"] = 384;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 45; p.county = 0; p.val = 575; p.data["black"] = 440; p.data["white"] = 130; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 525; p.data["r16"] = 20;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 34; p.county = 0; p.val = 1620; p.data["black"] = 485; p.data["white"] = 1120; p.data["r"] = 195; p.data["d"] = 251; p.data["d16"] = 271; p.data["r16"] = 352;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 35; p.county = 0; p.val = 1510; p.data["black"] = 410; p.data["white"] = 950; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 34; p.county = 0; p.val = 1440; p.data["black"] = 200; p.data["white"] = 1185; p.data["r"] = 402; p.data["d"] = 516; p.data["d16"] = 118; p.data["r16"] = 243;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 32; p.county = 0; p.val = 1105; p.data["black"] = 570; p.data["white"] = 515; p.data["r"] = 616; p.data["d"] = 1065; p.data["d16"] = 482; p.data["r16"] = 1154;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 41; p.county = 0; p.val = 3945; p.data["black"] = 545; p.data["white"] = 3085; p.data["r"] = 59; p.data["d"] = 155; p.data["d16"] = 69; p.data["r16"] = 189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 37; p.county = 0; p.val = 6475; p.data["black"] = 1835; p.data["white"] = 3755; p.data["r"] = 934; p.data["d"] = 1029; p.data["d16"] = 347; p.data["r16"] = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 36; p.county = 0; p.val = 2710; p.data["black"] = 755; p.data["white"] = 1875; p.data["r"] = 853; p.data["d"] = 832; p.data["d16"] = 774; p.data["r16"] = 1016;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 35; p.county = 0; p.val = 1725; p.data["black"] = 260; p.data["white"] = 1285; p.data["r"] = 743; p.data["d"] = 546; p.data["d16"] = 752; p.data["r16"] = 773;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 39; p.county = 0; p.val = 2635; p.data["black"] = 1290; p.data["white"] = 1160; p.data["r"] = 511; p.data["d"] = 147; p.data["d16"] = 636; p.data["r16"] = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 95; p.county = 0; p.val = 125; p.data["black"] = 0; p.data["white"] = 125; p.data["r"] = 315; p.data["d"] = 474; p.data["d16"] = 318; p.data["r16"] = 513;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 97; p.county = 0; p.val = 1195; p.data["black"] = 0; p.data["white"] = 1175; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 75; p.county = 0; p.val = 1085; p.data["black"] = 210; p.data["white"] = 790; p.data["r"] = 639; p.data["d"] = 517; p.data["d16"] = 637; p.data["r16"] = 587;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 74; p.county = 0; p.val = 2420; p.data["black"] = 75; p.data["white"] = 2075; p.data["r"] = 731; p.data["d"] = 1123; p.data["d16"] = 649; p.data["r16"] = 1321;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 96; p.county = 0; p.val = 670; p.data["black"] = 0; p.data["white"] = 615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 330; p.data["r16"] = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 91; p.county = 0; p.val = 1705; p.data["black"] = 10; p.data["white"] = 1680; p.data["r"] = 642; p.data["d"] = 688; p.data["d16"] = 696; p.data["r16"] = 878;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 52; p.county = 0; p.val = 515; p.data["black"] = 0; p.data["white"] = 510; p.data["r"] = 602; p.data["d"] = 313; p.data["d16"] = 550; p.data["r16"] = 459;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 36; p.county = 0; p.val = 825; p.data["black"] = 40; p.data["white"] = 775; p.data["r"] = 290; p.data["d"] = 675; p.data["d16"] = 243; p.data["r16"] = 697;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 31; p.county = 0; p.val = 910; p.data["black"] = 215; p.data["white"] = 695; p.data["r"] = 264; p.data["d"] = 398; p.data["d16"] = 319; p.data["r16"] = 550;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 37; p.county = 0; p.val = 1655; p.data["black"] = 435; p.data["white"] = 1220; p.data["r"] = 98; p.data["d"] = 220; p.data["d16"] = 129; p.data["r16"] = 283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 43; p.county = 0; p.val = 1195; p.data["black"] = 625; p.data["white"] = 570; p.data["r"] = 264; p.data["d"] = 175; p.data["d16"] = 302; p.data["r16"] = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 43; p.county = 0; p.val = 1130; p.data["black"] = 615; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 49; p.county = 0; p.val = 1785; p.data["black"] = 1185; p.data["white"] = 560; p.data["r"] = 1060; p.data["d"] = 907; p.data["d16"] = 1536; p.data["r16"] = 1173;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 45; p.county = 0; p.val = 3985; p.data["black"] = 1975; p.data["white"] = 1760; p.data["r"] = 282; p.data["d"] = 258; p.data["d16"] = 936; p.data["r16"] = 937;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 52; p.county = 0; p.val = 1350; p.data["black"] = 110; p.data["white"] = 1240; p.data["r"] = 520; p.data["d"] = 291; p.data["d16"] = 588; p.data["r16"] = 385;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 49; p.county = 0; p.val = 3315; p.data["black"] = 1330; p.data["white"] = 1910; p.data["r"] = 933; p.data["d"] = 481; p.data["d16"] = 767; p.data["r16"] = 899;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 48; p.county = 0; p.val = 1450; p.data["black"] = 500; p.data["white"] = 900; p.data["r"] = 1126; p.data["d"] = 240; p.data["d16"] = 693; p.data["r16"] = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 54; p.county = 0; p.val = 2015; p.data["black"] = 155; p.data["white"] = 1740; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 55; p.county = 0; p.val = 2195; p.data["black"] = 190; p.data["white"] = 1955; p.data["r"] = 732; p.data["d"] = 424; p.data["d16"] = 722; p.data["r16"] = 594;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 43; p.county = 0; p.val = 1250; p.data["black"] = 850; p.data["white"] = 125; p.data["r"] = 404; p.data["d"] = 70; p.data["d16"] = 499; p.data["r16"] = 99;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 48; p.county = 0; p.val = 3675; p.data["black"] = 765; p.data["white"] = 2835; p.data["r"] = 920; p.data["d"] = 103; p.data["d16"] = 1756; p.data["r16"] = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 49; p.county = 0; p.val = 4900; p.data["black"] = 1340; p.data["white"] = 3305; p.data["r"] = 1232; p.data["d"] = 889; p.data["d16"] = 1125; p.data["r16"] = 1024;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 28; p.county = 0; p.val = 1255; p.data["black"] = 705; p.data["white"] = 550; p.data["r"] = 756; p.data["d"] = 316; p.data["d16"] = 847; p.data["r16"] = 357;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 52; p.county = 0; p.val = 3430; p.data["black"] = 485; p.data["white"] = 2810; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 455; p.data["r16"] = 278;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 24; p.county = 0; p.val = 960; p.data["black"] = 800; p.data["white"] = 160; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 48; p.county = 0; p.val = 395; p.data["black"] = 390; p.data["white"] = 0; p.data["r"] = 1305; p.data["d"] = 348; p.data["d16"] = 1950; p.data["r16"] = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 49; p.county = 0; p.val = 665; p.data["black"] = 130; p.data["white"] = 535; p.data["r"] = 309; p.data["d"] = 189; p.data["d16"] = 397; p.data["r16"] = 243;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 53; p.county = 0; p.val = 530; p.data["black"] = 230; p.data["white"] = 305; p.data["r"] = 725; p.data["d"] = 219; p.data["d16"] = 834; p.data["r16"] = 260;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 55; p.county = 0; p.val = 2855; p.data["black"] = 680; p.data["white"] = 2105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 49; p.county = 0; p.val = 340; p.data["black"] = 0; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 58; p.county = 0; p.val = 1155; p.data["black"] = 775; p.data["white"] = 370; p.data["r"] = 485; p.data["d"] = 243; p.data["d16"] = 531; p.data["r16"] = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 46; p.county = 0; p.val = 200; p.data["black"] = 200; p.data["white"] = 0; p.data["r"] = 357; p.data["d"] = 337; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 34; p.county = 0; p.val = 3210; p.data["black"] = 975; p.data["white"] = 1840; p.data["r"] = 178; p.data["d"] = 199; p.data["d16"] = 180; p.data["r16"] = 241;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 48; p.county = 0; p.val = 1075; p.data["black"] = 50; p.data["white"] = 990; p.data["r"] = 193; p.data["d"] = 92; p.data["d16"] = 749; p.data["r16"] = 367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 55; p.county = 0; p.val = 715; p.data["black"] = 375; p.data["white"] = 335; p.data["r"] = 390; p.data["d"] = 787; p.data["d16"] = 429; p.data["r16"] = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 49; p.county = 0; p.val = 2600; p.data["black"] = 1250; p.data["white"] = 1255; p.data["r"] = 912; p.data["d"] = 1002; p.data["d16"] = 484; p.data["r16"] = 603;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 48; p.county = 0; p.val = 1710; p.data["black"] = 370; p.data["white"] = 1325; p.data["r"] = 442; p.data["d"] = 647; p.data["d16"] = 402; p.data["r16"] = 698;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 55; p.county = 0; p.val = 1320; p.data["black"] = 0; p.data["white"] = 1320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 61; p.county = 0; p.val = 1335; p.data["black"] = 685; p.data["white"] = 640; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 48; p.county = 0; p.val = 2515; p.data["black"] = 45; p.data["white"] = 2275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 53; p.county = 0; p.val = 1165; p.data["black"] = 4; p.data["white"] = 1105; p.data["r"] = 172; p.data["d"] = 276; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 49; p.county = 0; p.val = 650; p.data["black"] = 210; p.data["white"] = 430; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 58; p.county = 0; p.val = 1115; p.data["black"] = 340; p.data["white"] = 765; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 53; p.county = 0; p.val = 1410; p.data["black"] = 155; p.data["white"] = 1180; p.data["r"] = 1095; p.data["d"] = 565; p.data["d16"] = 660; p.data["r16"] = 574;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 42; p.county = 0; p.val = 3565; p.data["black"] = 395; p.data["white"] = 3020; p.data["r"] = 1052; p.data["d"] = 1436; p.data["d16"] = 1325; p.data["r16"] = 2098;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 42; p.county = 0; p.val = 1260; p.data["black"] = 845; p.data["white"] = 335; p.data["r"] = 214; p.data["d"] = 27; p.data["d16"] = 386; p.data["r16"] = 37;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 51; p.county = 0; p.val = 3525; p.data["black"] = 410; p.data["white"] = 3015; p.data["r"] = 1289; p.data["d"] = 1233; p.data["d16"] = 1252; p.data["r16"] = 1543;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 57; p.county = 0; p.val = 1295; p.data["black"] = 730; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 47; p.county = 0; p.val = 1370; p.data["black"] = 420; p.data["white"] = 910; p.data["r"] = 411; p.data["d"] = 131; p.data["d16"] = 411; p.data["r16"] = 235;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 51; p.county = 0; p.val = 1085; p.data["black"] = 20; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 37; p.county = 0; p.val = 1515; p.data["black"] = 715; p.data["white"] = 730; p.data["r"] = 1069; p.data["d"] = 497; p.data["d16"] = 807; p.data["r16"] = 989;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 42; p.county = 0; p.val = 570; p.data["black"] = 55; p.data["white"] = 480; p.data["r"] = 496; p.data["d"] = 163; p.data["d16"] = 634; p.data["r16"] = 220;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 42; p.county = 0; p.val = 1070; p.data["black"] = 250; p.data["white"] = 690; p.data["r"] = 242; p.data["d"] = 81; p.data["d16"] = 750; p.data["r16"] = 227;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 49; p.county = 0; p.val = 2675; p.data["black"] = 115; p.data["white"] = 2435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 51; p.county = 0; p.val = 1720; p.data["black"] = 20; p.data["white"] = 1620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 50; p.county = 0; p.val = 7005; p.data["black"] = 1790; p.data["white"] = 4845; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 50; p.county = 0; p.val = 4390; p.data["black"] = 525; p.data["white"] = 3580; p.data["r"] = 214; p.data["d"] = 341; p.data["d16"] = 229; p.data["r16"] = 398;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 50; p.county = 0; p.val = 685; p.data["black"] = 470; p.data["white"] = 210; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 48; p.county = 0; p.val = 1545; p.data["black"] = 895; p.data["white"] = 595; p.data["r"] = 1892; p.data["d"] = 285; p.data["d16"] = 1859; p.data["r16"] = 310;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 49; p.county = 0; p.val = 2475; p.data["black"] = 1440; p.data["white"] = 940; p.data["r"] = 1162; p.data["d"] = 610; p.data["d16"] = 953; p.data["r16"] = 486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 49; p.county = 0; p.val = 4525; p.data["black"] = 810; p.data["white"] = 3365; p.data["r"] = 438; p.data["d"] = 373; p.data["d16"] = 417; p.data["r16"] = 477;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 55; p.county = 0; p.val = 2150; p.data["black"] = 550; p.data["white"] = 1600; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 53; p.county = 0; p.val = 1685; p.data["black"] = 0; p.data["white"] = 1620; p.data["r"] = 573; p.data["d"] = 424; p.data["d16"] = 542; p.data["r16"] = 484;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 53; p.county = 0; p.val = 4195; p.data["black"] = 1050; p.data["white"] = 3025; p.data["r"] = 1037; p.data["d"] = 911; p.data["d16"] = 734; p.data["r16"] = 1040;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 57; p.county = 0; p.val = 1860; p.data["black"] = 590; p.data["white"] = 1070; p.data["r"] = 394; p.data["d"] = 232; p.data["d16"] = 389; p.data["r16"] = 311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 47; p.county = 0; p.val = 530; p.data["black"] = 25; p.data["white"] = 470; p.data["r"] = 706; p.data["d"] = 567; p.data["d16"] = 1130; p.data["r16"] = 1072;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 48; p.county = 0; p.val = 740; p.data["black"] = 55; p.data["white"] = 635; p.data["r"] = 598; p.data["d"] = 146; p.data["d16"] = 710; p.data["r16"] = 141;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 99; p.county = 0; p.val = 855; p.data["black"] = 0; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 35; p.county = 0; p.val = 1680; p.data["black"] = 625; p.data["white"] = 1030; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 35; p.county = 0; p.val = 1915; p.data["black"] = 515; p.data["white"] = 1245; p.data["r"] = 1361; p.data["d"] = 1224; p.data["d16"] = 1570; p.data["r16"] = 2048;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 98; p.county = 0; p.val = 155; p.data["black"] = 0; p.data["white"] = 150; p.data["r"] = 363; p.data["d"] = 383; p.data["d16"] = 347; p.data["r16"] = 462;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 88; p.county = 0; p.val = 2070; p.data["black"] = 60; p.data["white"] = 1955; p.data["r"] = 149; p.data["d"] = 383; p.data["d16"] = 157; p.data["r16"] = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 78; p.county = 0; p.val = 1800; p.data["black"] = 300; p.data["white"] = 1415; p.data["r"] = 425; p.data["d"] = 538; p.data["d16"] = 1101; p.data["r16"] = 1280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 80; p.county = 0; p.val = 2460; p.data["black"] = 2015; p.data["white"] = 420; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 96; p.county = 0; p.val = 740; p.data["black"] = 0; p.data["white"] = 735; p.data["r"] = 497; p.data["d"] = 954; p.data["d16"] = 474; p.data["r16"] = 1061;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 94; p.county = 0; p.val = 465; p.data["black"] = 195; p.data["white"] = 255; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 76; p.county = 0; p.val = 1155; p.data["black"] = 220; p.data["white"] = 920; p.data["r"] = 315; p.data["d"] = 290; p.data["d16"] = 307; p.data["r16"] = 294;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 81; p.county = 0; p.val = 1330; p.data["black"] = 200; p.data["white"] = 1085; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 70; p.county = 0; p.val = 1055; p.data["black"] = 510; p.data["white"] = 545; p.data["r"] = 447; p.data["d"] = 286; p.data["d16"] = 524; p.data["r16"] = 373;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 76; p.county = 0; p.val = 1165; p.data["black"] = 30; p.data["white"] = 1130; p.data["r"] = 472; p.data["d"] = 679; p.data["d16"] = 385; p.data["r16"] = 658;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 88; p.county = 0; p.val = 1635; p.data["black"] = 45; p.data["white"] = 1595; p.data["r"] = 556; p.data["d"] = 780; p.data["d16"] = 832; p.data["r16"] = 1341;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 90; p.county = 0; p.val = 1780; p.data["black"] = 10; p.data["white"] = 1730; p.data["r"] = 1213; p.data["d"] = 1688; p.data["d16"] = 1044; p.data["r16"] = 1528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 97; p.county = 0; p.val = 1420; p.data["black"] = 15; p.data["white"] = 1405; p.data["r"] = 208; p.data["d"] = 278; p.data["d16"] = 253; p.data["r16"] = 320;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 95; p.county = 0; p.val = 900; p.data["black"] = 0; p.data["white"] = 880; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 94; p.county = 0; p.val = 2505; p.data["black"] = 165; p.data["white"] = 2165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 61; p.county = 0; p.val = 1060; p.data["black"] = 930; p.data["white"] = 95; p.data["r"] = 358; p.data["d"] = 51; p.data["d16"] = 484; p.data["r16"] = 53;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 77; p.county = 0; p.val = 1060; p.data["black"] = 605; p.data["white"] = 365; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 620; p.data["r16"] = 135;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 79; p.county = 0; p.val = 1930; p.data["black"] = 585; p.data["white"] = 1205; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 76; p.county = 0; p.val = 1600; p.data["black"] = 560; p.data["white"] = 970; p.data["r"] = 218; p.data["d"] = 355; p.data["d16"] = 247; p.data["r16"] = 408;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 68; p.county = 0; p.val = 1030; p.data["black"] = 665; p.data["white"] = 315; p.data["r"] = 410; p.data["d"] = 208; p.data["d16"] = 495; p.data["r16"] = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 76; p.county = 0; p.val = 1545; p.data["black"] = 305; p.data["white"] = 1200; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 93; p.county = 0; p.val = 640; p.data["black"] = 0; p.data["white"] = 640; p.data["r"] = 580; p.data["d"] = 575; p.data["d16"] = 602; p.data["r16"] = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 80; p.county = 0; p.val = 2720; p.data["black"] = 640; p.data["white"] = 1715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 99; p.county = 0; p.val = 825; p.data["black"] = 0; p.data["white"] = 815; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 79; p.county = 0; p.val = 875; p.data["black"] = 395; p.data["white"] = 455; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 79; p.county = 0; p.val = 1050; p.data["black"] = 635; p.data["white"] = 335; p.data["r"] = 342; p.data["d"] = 310; p.data["d16"] = 325; p.data["r16"] = 366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 80; p.county = 0; p.val = 1625; p.data["black"] = 510; p.data["white"] = 1045; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 100; p.county = 0; p.val = 480; p.data["black"] = 10; p.data["white"] = 460; p.data["r"] = 221; p.data["d"] = 351; p.data["d16"] = 267; p.data["r16"] = 453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 90; p.county = 0; p.val = 2685; p.data["black"] = 245; p.data["white"] = 2155; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 34; p.county = 0; p.val = 2205; p.data["black"] = 655; p.data["white"] = 1380; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 29; p.county = 0; p.val = 1490; p.data["black"] = 385; p.data["white"] = 1030; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 32; p.county = 0; p.val = 1600; p.data["black"] = 385; p.data["white"] = 1170; p.data["r"] = 552; p.data["d"] = 627; p.data["d16"] = 625; p.data["r16"] = 830;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 33; p.county = 0; p.val = 1360; p.data["black"] = 360; p.data["white"] = 870; p.data["r"] = 916; p.data["d"] = 920; p.data["d16"] = 929; p.data["r16"] = 1197;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 32; p.county = 0; p.val = 2945; p.data["black"] = 465; p.data["white"] = 2365; p.data["r"] = 309; p.data["d"] = 368; p.data["d16"] = 361; p.data["r16"] = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 36; p.county = 0; p.val = 1815; p.data["black"] = 555; p.data["white"] = 1020; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 19; p.county = 0; p.val = 1790; p.data["black"] = 595; p.data["white"] = 1135; p.data["r"] = 319; p.data["d"] = 314; p.data["d16"] = 255; p.data["r16"] = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 42; p.county = 0; p.val = 930; p.data["black"] = 125; p.data["white"] = 615; p.data["r"] = 594; p.data["d"] = 159; p.data["d16"] = 1018; p.data["r16"] = 396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 42; p.county = 0; p.val = 2145; p.data["black"] = 855; p.data["white"] = 1125; p.data["r"] = 793; p.data["d"] = 614; p.data["d16"] = 1362; p.data["r16"] = 866;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 47; p.county = 0; p.val = 690; p.data["black"] = 450; p.data["white"] = 220; p.data["r"] = 715; p.data["d"] = 163; p.data["d16"] = 696; p.data["r16"] = 223;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 48; p.county = 0; p.val = 1050; p.data["black"] = 0; p.data["white"] = 935; p.data["r"] = 390; p.data["d"] = 704; p.data["d16"] = 334; p.data["r16"] = 668;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 50; p.county = 0; p.val = 855; p.data["black"] = 0; p.data["white"] = 855; p.data["r"] = 284; p.data["d"] = 434; p.data["d16"] = 290; p.data["r16"] = 500;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 51; p.county = 0; p.val = 700; p.data["black"] = 85; p.data["white"] = 615; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 42; p.county = 0; p.val = 3495; p.data["black"] = 1425; p.data["white"] = 1855; p.data["r"] = 436; p.data["d"] = 530; p.data["d16"] = 423; p.data["r16"] = 726;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 41; p.county = 0; p.val = 1135; p.data["black"] = 690; p.data["white"] = 345; p.data["r"] = 285; p.data["d"] = 49; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 44; p.county = 0; p.val = 770; p.data["black"] = 500; p.data["white"] = 235; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 225; p.data["r16"] = 12;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 43; p.county = 0; p.val = 1340; p.data["black"] = 420; p.data["white"] = 800; p.data["r"] = 859; p.data["d"] = 112; p.data["d16"] = 783; p.data["r16"] = 63;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 50; p.county = 0; p.val = 955; p.data["black"] = 0; p.data["white"] = 905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 37; p.county = 0; p.val = 3045; p.data["black"] = 215; p.data["white"] = 2575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 39; p.county = 0; p.val = 2725; p.data["black"] = 815; p.data["white"] = 1535; p.data["r"] = 527; p.data["d"] = 569; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 38; p.county = 0; p.val = 1240; p.data["black"] = 160; p.data["white"] = 1010; p.data["r"] = 453; p.data["d"] = 517; p.data["d16"] = 447; p.data["r16"] = 639;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 47; p.county = 0; p.val = 780; p.data["black"] = 220; p.data["white"] = 500; p.data["r"] = 414; p.data["d"] = 578; p.data["d16"] = 367; p.data["r16"] = 695;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 61; p.county = 0; p.val = 925; p.data["black"] = 0; p.data["white"] = 890; p.data["r"] = 422; p.data["d"] = 332; p.data["d16"] = 363; p.data["r16"] = 410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 65; p.county = 0; p.val = 1010; p.data["black"] = 4; p.data["white"] = 1005; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 52; p.county = 0; p.val = 2285; p.data["black"] = 530; p.data["white"] = 1680; p.data["r"] = 334; p.data["d"] = 420; p.data["d16"] = 360; p.data["r16"] = 685;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 61; p.county = 0; p.val = 1075; p.data["black"] = 255; p.data["white"] = 780; p.data["r"] = 538; p.data["d"] = 496; p.data["d16"] = 599; p.data["r16"] = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 47; p.county = 0; p.val = 3645; p.data["black"] = 380; p.data["white"] = 2990; p.data["r"] = 1273; p.data["d"] = 999; p.data["d16"] = 878; p.data["r16"] = 951;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 51; p.county = 0; p.val = 1490; p.data["black"] = 170; p.data["white"] = 1050; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 38; p.county = 0; p.val = 3230; p.data["black"] = 1220; p.data["white"] = 1800; p.data["r"] = 261; p.data["d"] = 32; p.data["d16"] = 342; p.data["r16"] = 172;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 45; p.county = 0; p.val = 1970; p.data["black"] = 235; p.data["white"] = 1715; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 62; p.county = 0; p.val = 995; p.data["black"] = 4; p.data["white"] = 970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 64; p.county = 0; p.val = 160; p.data["black"] = 15; p.data["white"] = 145; p.data["r"] = 436; p.data["d"] = 788; p.data["d16"] = 429; p.data["r16"] = 822;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 45; p.county = 0; p.val = 1230; p.data["black"] = 115; p.data["white"] = 980; p.data["r"] = 338; p.data["d"] = 375; p.data["d16"] = 464; p.data["r16"] = 768;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 49; p.county = 0; p.val = 1655; p.data["black"] = 45; p.data["white"] = 1515; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 42; p.county = 0; p.val = 5395; p.data["black"] = 80; p.data["white"] = 5305; p.data["r"] = 818; p.data["d"] = 1038; p.data["d16"] = 760; p.data["r16"] = 1274;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 45; p.county = 0; p.val = 4950; p.data["black"] = 825; p.data["white"] = 3905; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 344; p.data["r16"] = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 31; p.county = 0; p.val = 1255; p.data["black"] = 580; p.data["white"] = 630; p.data["r"] = 291; p.data["d"] = 256; p.data["d16"] = 350; p.data["r16"] = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 39; p.county = 0; p.val = 940; p.data["black"] = 395; p.data["white"] = 465; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 38; p.county = 0; p.val = 750; p.data["black"] = 135; p.data["white"] = 530; p.data["r"] = 789; p.data["d"] = 384; p.data["d16"] = 946; p.data["r16"] = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 39; p.county = 0; p.val = 2755; p.data["black"] = 660; p.data["white"] = 1755; p.data["r"] = 593; p.data["d"] = 455; p.data["d16"] = 1092; p.data["r16"] = 1314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 40; p.county = 0; p.val = 830; p.data["black"] = 170; p.data["white"] = 660; p.data["r"] = 644; p.data["d"] = 339; p.data["d16"] = 1031; p.data["r16"] = 835;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 50; p.county = 0; p.val = 810; p.data["black"] = 0; p.data["white"] = 790; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 26; p.county = 0; p.val = 1535; p.data["black"] = 600; p.data["white"] = 915; p.data["r"] = 484; p.data["d"] = 709; p.data["d16"] = 522; p.data["r16"] = 993;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 40; p.county = 0; p.val = 1570; p.data["black"] = 285; p.data["white"] = 965; p.data["r"] = 746; p.data["d"] = 786; p.data["d16"] = 583; p.data["r16"] = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 15; p.county = 0; p.val = 980; p.data["black"] = 0; p.data["white"] = 970; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 96; p.county = 0; p.val = 330; p.data["black"] = 10; p.data["white"] = 235; p.data["r"] = 309; p.data["d"] = 472; p.data["d16"] = 344; p.data["r16"] = 548;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 46; p.county = 0; p.val = 1410; p.data["black"] = 1220; p.data["white"] = 165; p.data["r"] = 345; p.data["d"] = 345; p.data["d16"] = 295; p.data["r16"] = 339;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 45; p.county = 0; p.val = 1125; p.data["black"] = 840; p.data["white"] = 250; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 45; p.county = 0; p.val = 555; p.data["black"] = 470; p.data["white"] = 55; p.data["r"] = 691; p.data["d"] = 60; p.data["d16"] = 417; p.data["r16"] = 51;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 46; p.county = 0; p.val = 1245; p.data["black"] = 1065; p.data["white"] = 150; p.data["r"] = 471; p.data["d"] = 33; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 48; p.county = 0; p.val = 2165; p.data["black"] = 335; p.data["white"] = 1730; p.data["r"] = 835; p.data["d"] = 727; p.data["d16"] = 691; p.data["r16"] = 772;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 50; p.county = 0; p.val = 2160; p.data["black"] = 390; p.data["white"] = 1760; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 51; p.county = 0; p.val = 1185; p.data["black"] = 0; p.data["white"] = 1100; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 58; p.county = 0; p.val = 5025; p.data["black"] = 1320; p.data["white"] = 3320; p.data["r"] = 453; p.data["d"] = 81; p.data["d16"] = 400; p.data["r16"] = 79;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 53; p.county = 0; p.val = 1525; p.data["black"] = 70; p.data["white"] = 1225; p.data["r"] = 412; p.data["d"] = 481; p.data["d16"] = 526; p.data["r16"] = 788;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 54; p.county = 0; p.val = 2045; p.data["black"] = 50; p.data["white"] = 1995; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 54; p.county = 0; p.val = 2095; p.data["black"] = 1690; p.data["white"] = 410; p.data["r"] = 460; p.data["d"] = 142; p.data["d16"] = 585; p.data["r16"] = 178;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 51; p.county = 0; p.val = 1055; p.data["black"] = 0; p.data["white"] = 1040; p.data["r"] = 620; p.data["d"] = 367; p.data["d16"] = 554; p.data["r16"] = 466;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 45; p.county = 0; p.val = 2600; p.data["black"] = 2310; p.data["white"] = 245; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 356; p.data["r16"] = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 44; p.county = 0; p.val = 1645; p.data["black"] = 1495; p.data["white"] = 115; p.data["r"] = 560; p.data["d"] = 24; p.data["d16"] = 780; p.data["r16"] = 31;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 45; p.county = 0; p.val = 1185; p.data["black"] = 795; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 97; p.county = 0; p.val = 320; p.data["black"] = 0; p.data["white"] = 320; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 249; p.data["r16"] = 440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 95; p.county = 0; p.val = 945; p.data["black"] = 105; p.data["white"] = 845; p.data["r"] = 543; p.data["d"] = 553; p.data["d16"] = 467; p.data["r16"] = 631;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 93; p.county = 0; p.val = 810; p.data["black"] = 160; p.data["white"] = 415; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 91; p.county = 0; p.val = 930; p.data["black"] = 0; p.data["white"] = 890; p.data["r"] = 408; p.data["d"] = 610; p.data["d16"] = 377; p.data["r16"] = 646;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 93; p.county = 0; p.val = 975; p.data["black"] = 60; p.data["white"] = 910; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 94; p.county = 0; p.val = 430; p.data["black"] = 145; p.data["white"] = 275; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 45; p.county = 0; p.val = 3300; p.data["black"] = 245; p.data["white"] = 2940; p.data["r"] = 1664; p.data["d"] = 1594; p.data["d16"] = 1838; p.data["r16"] = 2308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 41; p.county = 0; p.val = 6430; p.data["black"] = 200; p.data["white"] = 6075; p.data["r"] = 2250; p.data["d"] = 3696; p.data["d16"] = 1974; p.data["r16"] = 3923;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 50; p.county = 0; p.val = 2125; p.data["black"] = 300; p.data["white"] = 1680; p.data["r"] = 1052; p.data["d"] = 889; p.data["d16"] = 1096; p.data["r16"] = 1307;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 39; p.county = 0; p.val = 945; p.data["black"] = 295; p.data["white"] = 350; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 64; p.county = 0; p.val = 140; p.data["black"] = 0; p.data["white"] = 135; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 46; p.county = 0; p.val = 2185; p.data["black"] = 230; p.data["white"] = 1925; p.data["r"] = 426; p.data["d"] = 506; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 47; p.county = 0; p.val = 595; p.data["black"] = 595; p.data["white"] = 0; p.data["r"] = 1103; p.data["d"] = 100; p.data["d16"] = 1946; p.data["r16"] = 244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 48; p.county = 0; p.val = 1440; p.data["black"] = 60; p.data["white"] = 1235; p.data["r"] = 350; p.data["d"] = 317; p.data["d16"] = 574; p.data["r16"] = 714;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 46; p.county = 0; p.val = 1060; p.data["black"] = 0; p.data["white"] = 995; p.data["r"] = 380; p.data["d"] = 353; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 49; p.county = 0; p.val = 565; p.data["black"] = 0; p.data["white"] = 560; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 48; p.county = 0; p.val = 1590; p.data["black"] = 225; p.data["white"] = 1280; p.data["r"] = 1024; p.data["d"] = 1072; p.data["d16"] = 244; p.data["r16"] = 316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 49; p.county = 0; p.val = 685; p.data["black"] = 0; p.data["white"] = 625; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 501; p.data["r16"] = 546;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 49; p.county = 0; p.val = 3560; p.data["black"] = 205; p.data["white"] = 3285; p.data["r"] = 266; p.data["d"] = 317; p.data["d16"] = 228; p.data["r16"] = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 46; p.county = 0; p.val = 1015; p.data["black"] = 0; p.data["white"] = 955; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 457; p.data["r16"] = 483;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 50; p.county = 0; p.val = 900; p.data["black"] = 0; p.data["white"] = 900; p.data["r"] = 525; p.data["d"] = 577; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 52; p.county = 0; p.val = 700; p.data["black"] = 10; p.data["white"] = 670; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 35; p.county = 0; p.val = 2515; p.data["black"] = 635; p.data["white"] = 1715; p.data["r"] = 1024; p.data["d"] = 602; p.data["d16"] = 470; p.data["r16"] = 263;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 44; p.county = 0; p.val = 680; p.data["black"] = 445; p.data["white"] = 105; p.data["r"] = 548; p.data["d"] = 643; p.data["d16"] = 330; p.data["r16"] = 489;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 46; p.county = 0; p.val = 2100; p.data["black"] = 315; p.data["white"] = 1745; p.data["r"] = 744; p.data["d"] = 433; p.data["d16"] = 510; p.data["r16"] = 446;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 43; p.county = 0; p.val = 1670; p.data["black"] = 760; p.data["white"] = 835; p.data["r"] = 855; p.data["d"] = 758; p.data["d16"] = 920; p.data["r16"] = 868;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 44; p.county = 0; p.val = 1810; p.data["black"] = 905; p.data["white"] = 805; p.data["r"] = 509; p.data["d"] = 676; p.data["d16"] = 463; p.data["r16"] = 781;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 48; p.county = 0; p.val = 760; p.data["black"] = 105; p.data["white"] = 615; p.data["r"] = 1120; p.data["d"] = 282; p.data["d16"] = 483; p.data["r16"] = 128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 54; p.county = 0; p.val = 2240; p.data["black"] = 75; p.data["white"] = 2075; p.data["r"] = 513; p.data["d"] = 68; p.data["d16"] = 476; p.data["r16"] = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 47; p.county = 0; p.val = 1425; p.data["black"] = 0; p.data["white"] = 1340; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 57; p.county = 0; p.val = 2720; p.data["black"] = 870; p.data["white"] = 1805; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 58; p.county = 0; p.val = 820; p.data["black"] = 0; p.data["white"] = 820; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 66; p.county = 0; p.val = 665; p.data["black"] = 0; p.data["white"] = 650; p.data["r"] = 693; p.data["d"] = 934; p.data["d16"] = 713; p.data["r16"] = 986;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 51; p.county = 0; p.val = 870; p.data["black"] = 4; p.data["white"] = 855; p.data["r"] = 680; p.data["d"] = 601; p.data["d16"] = 641; p.data["r16"] = 641;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 66; p.county = 0; p.val = 1345; p.data["black"] = 680; p.data["white"] = 650; p.data["r"] = 523; p.data["d"] = 462; p.data["d16"] = 550; p.data["r16"] = 569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 45; p.county = 0; p.val = 2275; p.data["black"] = 610; p.data["white"] = 1585; p.data["r"] = 1034; p.data["d"] = 1067; p.data["d16"] = 898; p.data["r16"] = 1199;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 0; p.val = 1305; p.data["black"] = 0; p.data["white"] = 1305; p.data["r"] = 1011; p.data["d"] = 931; p.data["d16"] = 557; p.data["r16"] = 487;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 47; p.county = 0; p.val = 2125; p.data["black"] = 280; p.data["white"] = 1725; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 534; p.data["r16"] = 710;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 44; p.county = 0; p.val = 1200; p.data["black"] = 195; p.data["white"] = 980; p.data["r"] = 880; p.data["d"] = 780; p.data["d16"] = 907; p.data["r16"] = 1201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 47; p.county = 0; p.val = 2025; p.data["black"] = 350; p.data["white"] = 1620; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 331; p.data["r16"] = 439;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 36; p.county = 0; p.val = 720; p.data["black"] = 175; p.data["white"] = 345; p.data["r"] = 1012; p.data["d"] = 505; p.data["d16"] = 1033; p.data["r16"] = 789;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 37; p.county = 0; p.val = 4035; p.data["black"] = 1580; p.data["white"] = 2110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 38; p.county = 0; p.val = 1930; p.data["black"] = 610; p.data["white"] = 1280; p.data["r"] = 267; p.data["d"] = 105; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 37; p.county = 0; p.val = 1755; p.data["black"] = 275; p.data["white"] = 1080; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 867; p.data["r16"] = 299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 33; p.county = 0; p.val = 315; p.data["black"] = 105; p.data["white"] = 210; p.data["r"] = 1230; p.data["d"] = 988; p.data["d16"] = 436; p.data["r16"] = 726;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 90; p.county = 0; p.val = 2915; p.data["black"] = 225; p.data["white"] = 2435; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 50; p.county = 0; p.val = 1210; p.data["black"] = 60; p.data["white"] = 1115; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 51; p.county = 0; p.val = 1420; p.data["black"] = 675; p.data["white"] = 690; p.data["r"] = 282; p.data["d"] = 287; p.data["d16"] = 342; p.data["r16"] = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 90; p.county = 0; p.val = 1950; p.data["black"] = 340; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 91; p.county = 0; p.val = 1260; p.data["black"] = 100; p.data["white"] = 1110; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 90; p.county = 0; p.val = 1330; p.data["black"] = 225; p.data["white"] = 775; p.data["r"] = 219; p.data["d"] = 337; p.data["d16"] = 238; p.data["r16"] = 420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 15; p.county = 0; p.val = 915; p.data["black"] = 195; p.data["white"] = 675; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 11; p.county = 0; p.val = 1385; p.data["black"] = 290; p.data["white"] = 1095; p.data["r"] = 125; p.data["d"] = 735; p.data["d16"] = 114; p.data["r16"] = 1102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 24; p.county = 0; p.val = 560; p.data["black"] = 205; p.data["white"] = 360; p.data["r"] = 312; p.data["d"] = 439; p.data["d16"] = 207; p.data["r16"] = 631;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 10; p.county = 0; p.val = 1815; p.data["black"] = 825; p.data["white"] = 935; p.data["r"] = 279; p.data["d"] = 286; p.data["d16"] = 286; p.data["r16"] = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 89; p.county = 0; p.val = 480; p.data["black"] = 0; p.data["white"] = 405; p.data["r"] = 387; p.data["d"] = 338; p.data["d16"] = 434; p.data["r16"] = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 50; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 30; p.county = 0; p.val = 1255; p.data["black"] = 375; p.data["white"] = 750; p.data["r"] = 1519; p.data["d"] = 1494; p.data["d16"] = 1655; p.data["r16"] = 2190;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 31; p.county = 0; p.val = 1190; p.data["black"] = 275; p.data["white"] = 760; p.data["r"] = 564; p.data["d"] = 441; p.data["d16"] = 481; p.data["r16"] = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 38; p.county = 0; p.val = 1730; p.data["black"] = 15; p.data["white"] = 1540; p.data["r"] = 303; p.data["d"] = 387; p.data["d16"] = 672; p.data["r16"] = 557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 39; p.county = 0; p.val = 690; p.data["black"] = 235; p.data["white"] = 420; p.data["r"] = 340; p.data["d"] = 93; p.data["d16"] = 469; p.data["r16"] = 164;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 31; p.county = 0; p.val = 1060; p.data["black"] = 60; p.data["white"] = 955; p.data["r"] = 280; p.data["d"] = 463; p.data["d16"] = 279; p.data["r16"] = 625;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 7; p.county = 0; p.val = 1775; p.data["black"] = 860; p.data["white"] = 875; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 51; p.county = 0; p.val = 1075; p.data["black"] = 10; p.data["white"] = 1010; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 47; p.county = 0; p.val = 1670; p.data["black"] = 840; p.data["white"] = 780; p.data["r"] = 645; p.data["d"] = 418; p.data["d16"] = 148; p.data["r16"] = 19;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 53; p.county = 0; p.val = 915; p.data["black"] = 110; p.data["white"] = 725; p.data["r"] = 502; p.data["d"] = 419; p.data["d16"] = 496; p.data["r16"] = 498;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 54; p.county = 0; p.val = 2440; p.data["black"] = 600; p.data["white"] = 1760; p.data["r"] = 631; p.data["d"] = 510; p.data["d16"] = 600; p.data["r16"] = 582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 29; p.county = 0; p.val = 1665; p.data["black"] = 445; p.data["white"] = 1015; p.data["r"] = 1115; p.data["d"] = 741; p.data["d16"] = 1040; p.data["r16"] = 973;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 26; p.county = 0; p.val = 1520; p.data["black"] = 250; p.data["white"] = 1235; p.data["r"] = 1107; p.data["d"] = 1089; p.data["d16"] = 446; p.data["r16"] = 719;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 45; p.county = 0; p.val = 4535; p.data["black"] = 100; p.data["white"] = 4355; p.data["r"] = 470; p.data["d"] = 489; p.data["d16"] = 1218; p.data["r16"] = 633;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 37; p.county = 0; p.val = 320; p.data["black"] = 55; p.data["white"] = 215; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 194; p.data["r16"] = 651;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 37; p.county = 0; p.val = 250; p.data["black"] = 15; p.data["white"] = 140; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 446; p.data["r16"] = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 36; p.county = 0; p.val = 285; p.data["black"] = 45; p.data["white"] = 175; p.data["r"] = 274; p.data["d"] = 282; p.data["d16"] = 243; p.data["r16"] = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 32; p.county = 0; p.val = 1340; p.data["black"] = 225; p.data["white"] = 1070; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 965; p.data["r16"] = 664;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 32; p.county = 0; p.val = 1615; p.data["black"] = 520; p.data["white"] = 915; p.data["r"] = 457; p.data["d"] = 517; p.data["d16"] = 450; p.data["r16"] = 663;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 21; p.county = 0; p.val = 790; p.data["black"] = 395; p.data["white"] = 385; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 27; p.county = 0; p.val = 1615; p.data["black"] = 15; p.data["white"] = 1505; p.data["r"] = 28; p.data["d"] = 52; p.data["d16"] = 276; p.data["r16"] = 438;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 37; p.county = 0; p.val = 775; p.data["black"] = 180; p.data["white"] = 485; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 33; p.county = 0; p.val = 2190; p.data["black"] = 275; p.data["white"] = 1575; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 31; p.county = 0; p.val = 3385; p.data["black"] = 620; p.data["white"] = 2595; p.data["r"] = 819; p.data["d"] = 991; p.data["d16"] = 825; p.data["r16"] = 1438;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 34; p.county = 0; p.val = 1845; p.data["black"] = 200; p.data["white"] = 1545; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 34; p.county = 0; p.val = 865; p.data["black"] = 170; p.data["white"] = 675; p.data["r"] = 673; p.data["d"] = 587; p.data["d16"] = 720; p.data["r16"] = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 32; p.county = 0; p.val = 1555; p.data["black"] = 575; p.data["white"] = 845; p.data["r"] = 331; p.data["d"] = 238; p.data["d16"] = 414; p.data["r16"] = 375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 35; p.county = 0; p.val = 550; p.data["black"] = 90; p.data["white"] = 445; p.data["r"] = 924; p.data["d"] = 1065; p.data["d16"] = 946; p.data["r16"] = 1584;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 33; p.county = 0; p.val = 1325; p.data["black"] = 215; p.data["white"] = 970; p.data["r"] = 657; p.data["d"] = 408; p.data["d16"] = 722; p.data["r16"] = 687;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 33; p.county = 0; p.val = 4095; p.data["black"] = 985; p.data["white"] = 2635; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 22; p.county = 0; p.val = 535; p.data["black"] = 335; p.data["white"] = 170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 43; p.county = 0; p.val = 825; p.data["black"] = 0; p.data["white"] = 795; p.data["r"] = 1769; p.data["d"] = 2626; p.data["d16"] = 1181; p.data["r16"] = 1885;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 20; p.county = 0; p.val = 690; p.data["black"] = 275; p.data["white"] = 405; p.data["r"] = 335; p.data["d"] = 317; p.data["d16"] = 414; p.data["r16"] = 482;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 16; p.county = 0; p.val = 1670; p.data["black"] = 70; p.data["white"] = 1575; p.data["r"] = 310; p.data["d"] = 449; p.data["d16"] = 363; p.data["r16"] = 557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 6; p.county = 0; p.val = 1420; p.data["black"] = 895; p.data["white"] = 520; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 19; p.county = 0; p.val = 1255; p.data["black"] = 435; p.data["white"] = 745; p.data["r"] = 604; p.data["d"] = 370; p.data["d16"] = 580; p.data["r16"] = 557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 32; p.county = 0; p.val = 4110; p.data["black"] = 785; p.data["white"] = 2885; p.data["r"] = 1339; p.data["d"] = 2362; p.data["d16"] = 1282; p.data["r16"] = 2888;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 40; p.county = 0; p.val = 1660; p.data["black"] = 670; p.data["white"] = 890; p.data["r"] = 532; p.data["d"] = 526; p.data["d16"] = 787; p.data["r16"] = 1259;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 34; p.county = 0; p.val = 1795; p.data["black"] = 145; p.data["white"] = 1230; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 30; p.county = 0; p.val = 1085; p.data["black"] = 55; p.data["white"] = 960; p.data["r"] = 147; p.data["d"] = 566; p.data["d16"] = 560; p.data["r16"] = 1283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 33; p.county = 0; p.val = 2845; p.data["black"] = 1675; p.data["white"] = 1085; p.data["r"] = 506; p.data["d"] = 120; p.data["d16"] = 580; p.data["r16"] = 116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 39; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 47; p.county = 0; p.val = 1200; p.data["black"] = 40; p.data["white"] = 1100; p.data["r"] = 1408; p.data["d"] = 1656; p.data["d16"] = 1866; p.data["r16"] = 2522;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 98; p.county = 0; p.val = 195; p.data["black"] = 0; p.data["white"] = 190; p.data["r"] = 408; p.data["d"] = 568; p.data["d16"] = 185; p.data["r16"] = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 90; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 92; p.county = 0; p.val = 1420; p.data["black"] = 140; p.data["white"] = 1230; p.data["r"] = 885; p.data["d"] = 1163; p.data["d16"] = 871; p.data["r16"] = 1355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 92; p.county = 0; p.val = 1160; p.data["black"] = 260; p.data["white"] = 800; p.data["r"] = 372; p.data["d"] = 329; p.data["d16"] = 414; p.data["r16"] = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 76; p.county = 0; p.val = 530; p.data["black"] = 365; p.data["white"] = 105; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 35; p.county = 0; p.val = 1575; p.data["black"] = 170; p.data["white"] = 1385; p.data["r"] = 251; p.data["d"] = 523; p.data["d16"] = 252; p.data["r16"] = 586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 33; p.county = 0; p.val = 1115; p.data["black"] = 110; p.data["white"] = 985; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 262; p.data["r16"] = 459;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 31; p.county = 0; p.val = 2840; p.data["black"] = 385; p.data["white"] = 2290; p.data["r"] = 1150; p.data["d"] = 1530; p.data["d16"] = 363; p.data["r16"] = 866;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 31; p.county = 0; p.val = 2760; p.data["black"] = 300; p.data["white"] = 2320; p.data["r"] = 930; p.data["d"] = 1669; p.data["d16"] = 821; p.data["r16"] = 1801;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 30; p.county = 0; p.val = 2130; p.data["black"] = 395; p.data["white"] = 1595; p.data["r"] = 528; p.data["d"] = 675; p.data["d16"] = 489; p.data["r16"] = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 32; p.county = 0; p.val = 2190; p.data["black"] = 465; p.data["white"] = 1670; p.data["r"] = 702; p.data["d"] = 1047; p.data["d16"] = 755; p.data["r16"] = 1410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 36; p.county = 0; p.val = 2020; p.data["black"] = 465; p.data["white"] = 1450; p.data["r"] = 952; p.data["d"] = 1691; p.data["d16"] = 869; p.data["r16"] = 1986;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 41; p.county = 0; p.val = 2505; p.data["black"] = 575; p.data["white"] = 1535; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 40; p.county = 0; p.val = 1655; p.data["black"] = 755; p.data["white"] = 850; p.data["r"] = 745; p.data["d"] = 624; p.data["d16"] = 406; p.data["r16"] = 485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 36; p.county = 0; p.val = 3990; p.data["black"] = 655; p.data["white"] = 3125; p.data["r"] = 79; p.data["d"] = 185; p.data["d16"] = 99; p.data["r16"] = 216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 40; p.county = 0; p.val = 2555; p.data["black"] = 485; p.data["white"] = 1855; p.data["r"] = 667; p.data["d"] = 677; p.data["d16"] = 676; p.data["r16"] = 803;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 42; p.county = 0; p.val = 1570; p.data["black"] = 360; p.data["white"] = 1020; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 33; p.county = 0; p.val = 1810; p.data["black"] = 310; p.data["white"] = 1355; p.data["r"] = 460; p.data["d"] = 566; p.data["d16"] = 462; p.data["r16"] = 776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 19; p.county = 0; p.val = 1475; p.data["black"] = 755; p.data["white"] = 665; p.data["r"] = 380; p.data["d"] = 390; p.data["d16"] = 486; p.data["r16"] = 533;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 33; p.county = 0; p.val = 3155; p.data["black"] = 385; p.data["white"] = 2665; p.data["r"] = 190; p.data["d"] = 227; p.data["d16"] = 589; p.data["r16"] = 793;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 40; p.county = 0; p.val = 765; p.data["black"] = 60; p.data["white"] = 665; p.data["r"] = 276; p.data["d"] = 338; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 41; p.county = 0; p.val = 1075; p.data["black"] = 285; p.data["white"] = 770; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 274; p.data["r16"] = 432;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 38; p.county = 0; p.val = 1845; p.data["black"] = 395; p.data["white"] = 1420; p.data["r"] = 208; p.data["d"] = 298; p.data["d16"] = 230; p.data["r16"] = 407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 59; p.county = 0; p.val = 440; p.data["black"] = 275; p.data["white"] = 165; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 25; p.county = 0; p.val = 815; p.data["black"] = 580; p.data["white"] = 210; p.data["r"] = 418; p.data["d"] = 184; p.data["d16"] = 485; p.data["r16"] = 278;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 46; p.county = 0; p.val = 965; p.data["black"] = 465; p.data["white"] = 445; p.data["r"] = 175; p.data["d"] = 217; p.data["d16"] = 239; p.data["r16"] = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 48; p.county = 0; p.val = 950; p.data["black"] = 530; p.data["white"] = 420; p.data["r"] = 224; p.data["d"] = 64; p.data["d16"] = 367; p.data["r16"] = 144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 72; p.county = 0; p.val = 705; p.data["black"] = 4; p.data["white"] = 685; p.data["r"] = 203; p.data["d"] = 591; p.data["d16"] = 219; p.data["r16"] = 635;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 62; p.county = 0; p.val = 630; p.data["black"] = 430; p.data["white"] = 200; p.data["r"] = 412; p.data["d"] = 121; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 35; p.county = 0; p.val = 660; p.data["black"] = 0; p.data["white"] = 660; p.data["r"] = 416; p.data["d"] = 432; p.data["d16"] = 277; p.data["r16"] = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 36; p.county = 0; p.val = 2125; p.data["black"] = 390; p.data["white"] = 1640; p.data["r"] = 148; p.data["d"] = 414; p.data["d16"] = 120; p.data["r16"] = 495;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 34; p.county = 0; p.val = 1560; p.data["black"] = 85; p.data["white"] = 1420; p.data["r"] = 268; p.data["d"] = 443; p.data["d16"] = 205; p.data["r16"] = 654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 34; p.county = 0; p.val = 1650; p.data["black"] = 420; p.data["white"] = 1140; p.data["r"] = 423; p.data["d"] = 582; p.data["d16"] = 423; p.data["r16"] = 801;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 46; p.county = 0; p.val = 865; p.data["black"] = 335; p.data["white"] = 485; p.data["r"] = 57; p.data["d"] = 62; p.data["d16"] = 68; p.data["r16"] = 103;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 35; p.county = 0; p.val = 1950; p.data["black"] = 730; p.data["white"] = 1170; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 41; p.county = 0; p.val = 700; p.data["black"] = 195; p.data["white"] = 505; p.data["r"] = 95; p.data["d"] = 169; p.data["d16"] = 184; p.data["r16"] = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 38; p.county = 0; p.val = 2165; p.data["black"] = 515; p.data["white"] = 1485; p.data["r"] = 588; p.data["d"] = 347; p.data["d16"] = 708; p.data["r16"] = 485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 30; p.county = 0; p.val = 450; p.data["black"] = 150; p.data["white"] = 260; p.data["r"] = 182; p.data["d"] = 205; p.data["d16"] = 118; p.data["r16"] = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 43; p.county = 0; p.val = 1115; p.data["black"] = 335; p.data["white"] = 525; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 33; p.county = 0; p.val = 595; p.data["black"] = 240; p.data["white"] = 355; p.data["r"] = 67; p.data["d"] = 130; p.data["d16"] = 97; p.data["r16"] = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 39; p.county = 0; p.val = 1100; p.data["black"] = 230; p.data["white"] = 855; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 55; p.county = 0; p.val = 550; p.data["black"] = 360; p.data["white"] = 150; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 41; p.county = 0; p.val = 1115; p.data["black"] = 460; p.data["white"] = 580; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 51; p.county = 0; p.val = 945; p.data["black"] = 425; p.data["white"] = 520; p.data["r"] = 373; p.data["d"] = 184; p.data["d16"] = 480; p.data["r16"] = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 31; p.county = 0; p.val = 660; p.data["black"] = 185; p.data["white"] = 470; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 41; p.county = 0; p.val = 755; p.data["black"] = 515; p.data["white"] = 240; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 41; p.county = 0; p.val = 325; p.data["black"] = 245; p.data["white"] = 80; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 42; p.county = 0; p.val = 850; p.data["black"] = 630; p.data["white"] = 225; p.data["r"] = 486; p.data["d"] = 88; p.data["d16"] = 672; p.data["r16"] = 104;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 42; p.county = 0; p.val = 560; p.data["black"] = 205; p.data["white"] = 355; p.data["r"] = 280; p.data["d"] = 262; p.data["d16"] = 302; p.data["r16"] = 311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 17; p.county = 0; p.val = 520; p.data["black"] = 80; p.data["white"] = 445; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 40; p.county = 0; p.val = 1575; p.data["black"] = 155; p.data["white"] = 1355; p.data["r"] = 829; p.data["d"] = 424; p.data["d16"] = 1090; p.data["r16"] = 605;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 8; p.county = 0; p.val = 1610; p.data["black"] = 825; p.data["white"] = 785; p.data["r"] = 458; p.data["d"] = 1004; p.data["d16"] = 510; p.data["r16"] = 1291;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 20; p.county = 0; p.val = 1450; p.data["black"] = 700; p.data["white"] = 680; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 20; p.county = 0; p.val = 1075; p.data["black"] = 160; p.data["white"] = 880; p.data["r"] = 221; p.data["d"] = 285; p.data["d16"] = 171; p.data["r16"] = 274;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 4; p.county = 0; p.val = 760; p.data["black"] = 450; p.data["white"] = 285; p.data["r"] = 525; p.data["d"] = 127; p.data["d16"] = 685; p.data["r16"] = 157;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 20; p.county = 0; p.val = 1825; p.data["black"] = 595; p.data["white"] = 1195; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 0; p.county = 0; p.val = 430; p.data["black"] = 290; p.data["white"] = 95; p.data["r"] = 283; p.data["d"] = 74; p.data["d16"] = 355; p.data["r16"] = 125;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 83; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 252; p.data["d"] = 553; p.data["d16"] = 331; p.data["r16"] = 633;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 84; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 275; p.data["d"] = 461; p.data["d16"] = 275; p.data["r16"] = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 7; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 341; p.data["d"] = 185; p.data["d16"] = 448; p.data["r16"] = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 18; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 12; p.data["d"] = 127; p.data["d16"] = 17; p.data["r16"] = 164;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 2; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 532; p.data["d"] = 128; p.data["d16"] = 616; p.data["r16"] = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 4; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 369; p.data["d"] = 293; p.data["d16"] = 429; p.data["r16"] = 410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 15; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 237; p.data["d"] = 689; p.data["d16"] = 199; p.data["r16"] = 894;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 12; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 187; p.data["d"] = 119; p.data["d16"] = 247; p.data["r16"] = 156;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 17; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 461; p.data["d"] = 292; p.data["d16"] = 499; p.data["r16"] = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 21; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 59; p.data["d"] = 331; p.data["d16"] = 92; p.data["r16"] = 440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 26; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 456; p.data["d"] = 235; p.data["d16"] = 526; p.data["r16"] = 271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 18; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 113; p.data["d"] = 134; p.data["d16"] = 130; p.data["r16"] = 157;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 37; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 447; p.data["d"] = 364; p.data["d16"] = 496; p.data["r16"] = 404;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 58; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 411; p.data["d"] = 288; p.data["d16"] = 415; p.data["r16"] = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 56; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 471; p.data["d"] = 452; p.data["d16"] = 460; p.data["r16"] = 517;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 43; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 1020; p.data["d"] = 990; p.data["d16"] = 1077; p.data["r16"] = 1071;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 53; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 481; p.data["d"] = 301; p.data["d16"] = 577; p.data["r16"] = 356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 35; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 101; p.data["d"] = 130; p.data["d16"] = 85; p.data["r16"] = 146;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 39; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 265; p.data["d"] = 529; p.data["d16"] = 289; p.data["r16"] = 677;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 26; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 138; p.data["d"] = 51; p.data["d16"] = 184; p.data["r16"] = 89;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 50; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 193; p.data["d"] = 53; p.data["d16"] = 261; p.data["r16"] = 65;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 32; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 134; p.data["d"] = 377; p.data["d16"] = 123; p.data["r16"] = 520;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 34; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 279; p.data["d"] = 341; p.data["d16"] = 300; p.data["r16"] = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 31; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 71; p.data["d"] = 213; p.data["d16"] = 93; p.data["r16"] = 305;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 35; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 98; p.data["d"] = 290; p.data["d16"] = 120; p.data["r16"] = 404;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 41; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 82; p.data["d"] = 179; p.data["d16"] = 121; p.data["r16"] = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 25; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 206; p.data["d"] = 223; p.data["d16"] = 271; p.data["r16"] = 303;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 31; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 253; p.data["d"] = 344; p.data["d16"] = 248; p.data["r16"] = 387;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 353; p.data["d"] = 117; p.data["d16"] = 379; p.data["r16"] = 85;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 33; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 96; p.data["r16"] = 109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 62; p.county = 0; p.val = 0; p.data["black"] = 0; p.data["white"] = 0; p.data["r"] = 0; p.data["d"] = 0; p.data["d16"] = 519; p.data["r16"] = 162;
points[i]=p;i++;}
np = 479;
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
	std::map<int,Point> points;
	
	killCarveV = false;
	killCarveH = false;
	
	auto a11 = std::chrono::high_resolution_clock::now();
	
	np =0;//will get set to right value in scPoints()
	points = scPoints();
	
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
			for (iii=0;iii>nd;iii++){
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
				for (iii=0;iii<nd;iii++){
					s = datas[iii];
					pixels[i][ii].data[s] += points[minI].data[s]*100/points[minI].npix;
				}
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
			for (iii=0;iii<nd;iii++){
				s = datas[iii];
				pixels[i][ii].data[s] += points[minI].data[s]*100/points[minI].npix;
			}
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
	for (iii=0;iii<11;iii++){
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
