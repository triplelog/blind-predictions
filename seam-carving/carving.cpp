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
};

std::map<int,Point> scPoints(){
std::map<int,Point> points; int i=0;
if (1==1){ Point p;
p.x = 20; p.y = 31; p.county = 1; p.val = 817; p.d = 279; p.r = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 34; p.county = 1; p.val = 625; p.d = 402; p.r = 223;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 35; p.county = 1; p.val = 580; p.d = 302; p.r = 278;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 32; p.county = 1; p.val = 426; p.d = 128; p.r = 298;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 29; p.county = 1; p.val = 636; p.d = 154; p.r = 482;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 24; p.county = 1; p.val = 261; p.d = 77; p.r = 184;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 35; p.county = 1; p.val = 944; p.d = 573; p.r = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 30; p.county = 1; p.val = 560; p.d = 131; p.r = 429;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 26; p.county = 1; p.val = 312; p.d = 61; p.r = 251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 28; p.county = 1; p.val = 813; p.d = 310; p.r = 503;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 25; p.county = 1; p.val = 423; p.d = 148; p.r = 275;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 27; p.county = 1; p.val = 609; p.d = 140; p.r = 469;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 32; p.county = 1; p.val = 598; p.d = 126; p.r = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 34; p.county = 1; p.val = 470; p.d = 137; p.r = 333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 32; p.county = 1; p.val = 490; p.d = 145; p.r = 345;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 60; p.county = 3; p.val = 0; p.d = 0; p.r = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 52; p.county = 3; p.val = 1944; p.d = 745; p.r = 1199;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 52; p.county = 3; p.val = 1994; p.d = 1688; p.r = 306;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 53; p.county = 3; p.val = 1114; p.d = 615; p.r = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 51; p.county = 3; p.val = 680; p.d = 477; p.r = 203;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 48; p.county = 3; p.val = 702; p.d = 188; p.r = 514;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 50; p.county = 3; p.val = 990; p.d = 295; p.r = 695;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 49; p.county = 3; p.val = 1052; p.d = 473; p.r = 579;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 54; p.county = 3; p.val = 2172; p.d = 811; p.r = 1361;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 53; p.county = 3; p.val = 2397; p.d = 1051; p.r = 1346;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 54; p.county = 3; p.val = 1853; p.d = 637; p.r = 1216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 55; p.county = 3; p.val = 870; p.d = 311; p.r = 559;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 57; p.county = 3; p.val = 1763; p.d = 800; p.r = 963;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 47; p.county = 3; p.val = 516; p.d = 121; p.r = 395;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 56; p.county = 3; p.val = 830; p.d = 459; p.r = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 55; p.county = 3; p.val = 888; p.d = 546; p.r = 342;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 60; p.county = 3; p.val = 878; p.d = 195; p.r = 683;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 51; p.county = 3; p.val = 402; p.d = 136; p.r = 266;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 54; p.county = 3; p.val = 3640; p.d = 1476; p.r = 2164;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 54; p.county = 3; p.val = 1133; p.d = 309; p.r = 824;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 44; p.county = 3; p.val = 634; p.d = 294; p.r = 340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 49; p.county = 3; p.val = 445; p.d = 117; p.r = 328;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 50; p.county = 3; p.val = 465; p.d = 168; p.r = 297;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 52; p.county = 3; p.val = 389; p.d = 192; p.r = 197;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 55; p.county = 3; p.val = 1496; p.d = 581; p.r = 915;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 53; p.county = 3; p.val = 2890; p.d = 823; p.r = 2067;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 53; p.county = 3; p.val = 400; p.d = 224; p.r = 176;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 50; p.county = 3; p.val = 875; p.d = 359; p.r = 516;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 47; p.county = 3; p.val = 760; p.d = 332; p.r = 428;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 53; p.county = 3; p.val = 1511; p.d = 479; p.r = 1032;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 56; p.county = 3; p.val = 433; p.d = 225; p.r = 208;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 54; p.county = 3; p.val = 536; p.d = 205; p.r = 331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 52; p.county = 3; p.val = 965; p.d = 387; p.r = 578;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 57; p.county = 3; p.val = 609; p.d = 228; p.r = 381;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 51; p.county = 3; p.val = 1264; p.d = 485; p.r = 779;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 53; p.county = 3; p.val = 1213; p.d = 414; p.r = 799;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 53; p.county = 3; p.val = 673; p.d = 247; p.r = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 52; p.county = 3; p.val = 583; p.d = 194; p.r = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 52; p.county = 3; p.val = 1674; p.d = 420; p.r = 1254;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 55; p.county = 3; p.val = 951; p.d = 226; p.r = 725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 54; p.county = 3; p.val = 1688; p.d = 499; p.r = 1189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 58; p.county = 3; p.val = 946; p.d = 537; p.r = 409;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 53; p.county = 3; p.val = 1557; p.d = 530; p.r = 1027;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 56; p.county = 3; p.val = 902; p.d = 228; p.r = 674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 56; p.county = 3; p.val = 1162; p.d = 284; p.r = 878;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 54; p.county = 3; p.val = 805; p.d = 225; p.r = 580;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 55; p.county = 3; p.val = 3090; p.d = 879; p.r = 2211;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 54; p.county = 3; p.val = 1006; p.d = 319; p.r = 687;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 55; p.county = 3; p.val = 500; p.d = 171; p.r = 329;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 58; p.county = 3; p.val = 516; p.d = 181; p.r = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 56; p.county = 3; p.val = 490; p.d = 195; p.r = 295;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 54; p.county = 3; p.val = 1374; p.d = 464; p.r = 910;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 55; p.county = 3; p.val = 935; p.d = 309; p.r = 626;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 70; p.county = 5; p.val = 492; p.d = 405; p.r = 87;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 71; p.county = 5; p.val = 471; p.d = 459; p.r = 12;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 71; p.county = 5; p.val = 295; p.d = 201; p.r = 94;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 75; p.county = 5; p.val = 552; p.d = 495; p.r = 57;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 68; p.county = 5; p.val = 267; p.d = 238; p.r = 29;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 71; p.county = 5; p.val = 453; p.d = 337; p.r = 116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 70; p.county = 5; p.val = 244; p.d = 89; p.r = 155;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 68; p.county = 5; p.val = 123; p.d = 65; p.r = 58;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 21; p.county = 7; p.val = 2754; p.d = 1107; p.r = 1647;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 24; p.county = 7; p.val = 234; p.d = 31; p.r = 203;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 21; p.county = 7; p.val = 790; p.d = 227; p.r = 563;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 16; p.county = 7; p.val = 1099; p.d = 307; p.r = 792;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 18; p.county = 7; p.val = 978; p.d = 301; p.r = 677;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 23; p.county = 7; p.val = 331; p.d = 60; p.r = 271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 28; p.county = 7; p.val = 725; p.d = 144; p.r = 581;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 28; p.county = 7; p.val = 393; p.d = 76; p.r = 317;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 18; p.county = 7; p.val = 509; p.d = 173; p.r = 336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 17; p.county = 7; p.val = 407; p.d = 131; p.r = 276;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 19; p.county = 7; p.val = 1170; p.d = 384; p.r = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 23; p.county = 7; p.val = 906; p.d = 367; p.r = 539;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 17; p.county = 7; p.val = 1205; p.d = 213; p.r = 992;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 18; p.county = 7; p.val = 1565; p.d = 806; p.r = 759;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 16; p.county = 7; p.val = 443; p.d = 105; p.r = 338;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 23; p.county = 7; p.val = 1256; p.d = 655; p.r = 601;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 20; p.county = 7; p.val = 1638; p.d = 476; p.r = 1162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 20; p.county = 7; p.val = 759; p.d = 214; p.r = 545;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 21; p.county = 7; p.val = 754; p.d = 188; p.r = 566;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 28; p.county = 7; p.val = 320; p.d = 47; p.r = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 19; p.county = 7; p.val = 1908; p.d = 487; p.r = 1421;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 21; p.county = 7; p.val = 608; p.d = 231; p.r = 377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 24; p.county = 7; p.val = 520; p.d = 63; p.r = 457;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 15; p.county = 7; p.val = 1369; p.d = 291; p.r = 1078;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 13; p.county = 7; p.val = 1564; p.d = 436; p.r = 1128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 22; p.county = 7; p.val = 592; p.d = 115; p.r = 477;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 19; p.county = 7; p.val = 666; p.d = 135; p.r = 531;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 20; p.county = 7; p.val = 2313; p.d = 808; p.r = 1505;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 25; p.county = 7; p.val = 627; p.d = 131; p.r = 496;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 23; p.county = 7; p.val = 276; p.d = 144; p.r = 132;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 24; p.county = 7; p.val = 769; p.d = 169; p.r = 600;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 26; p.county = 7; p.val = 609; p.d = 142; p.r = 467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 22; p.county = 7; p.val = 848; p.d = 180; p.r = 668;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 24; p.county = 7; p.val = 502; p.d = 150; p.r = 352;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 23; p.county = 7; p.val = 644; p.d = 301; p.r = 343;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 21; p.county = 7; p.val = 1290; p.d = 350; p.r = 940;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 17; p.county = 7; p.val = 1146; p.d = 257; p.r = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 24; p.county = 7; p.val = 688; p.d = 140; p.r = 548;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 22; p.county = 7; p.val = 434; p.d = 119; p.r = 315;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 25; p.county = 7; p.val = 433; p.d = 88; p.r = 345;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 15; p.county = 7; p.val = 1362; p.d = 371; p.r = 991;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 26; p.county = 7; p.val = 486; p.d = 87; p.r = 399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 15; p.county = 7; p.val = 1311; p.d = 248; p.r = 1063;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 20; p.county = 7; p.val = 244; p.d = 28; p.r = 216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 20; p.county = 7; p.val = 430; p.d = 110; p.r = 320;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 19; p.county = 7; p.val = 870; p.d = 250; p.r = 620;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 25; p.county = 7; p.val = 196; p.d = 65; p.r = 131;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 17; p.county = 7; p.val = 1565; p.d = 369; p.r = 1196;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 18; p.county = 7; p.val = 1111; p.d = 327; p.r = 784;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 18; p.county = 7; p.val = 1151; p.d = 205; p.r = 946;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 26; p.county = 7; p.val = 445; p.d = 54; p.r = 391;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 20; p.county = 7; p.val = 1733; p.d = 574; p.r = 1159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 21; p.county = 7; p.val = 2645; p.d = 944; p.r = 1701;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 22; p.county = 7; p.val = 1787; p.d = 1327; p.r = 460;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 22; p.county = 7; p.val = 727; p.d = 568; p.r = 159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 22; p.county = 7; p.val = 1088; p.d = 430; p.r = 658;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 21; p.county = 7; p.val = 1345; p.d = 436; p.r = 909;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 14; p.county = 7; p.val = 1313; p.d = 291; p.r = 1022;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 21; p.county = 7; p.val = 904; p.d = 286; p.r = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 12; p.county = 7; p.val = 1659; p.d = 479; p.r = 1180;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 20; p.county = 7; p.val = 969; p.d = 297; p.r = 672;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 23; p.county = 7; p.val = 1262; p.d = 340; p.r = 922;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 13; p.county = 7; p.val = 2153; p.d = 551; p.r = 1602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 65; p.county = 9; p.val = 137; p.d = 56; p.r = 81;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 64; p.county = 9; p.val = 229; p.d = 74; p.r = 155;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 67; p.county = 9; p.val = 505; p.d = 230; p.r = 275;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 60; p.county = 9; p.val = 1064; p.d = 850; p.r = 214;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 63; p.county = 9; p.val = 99; p.d = 70; p.r = 29;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 61; p.county = 9; p.val = 55; p.d = 27; p.r = 28;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 65; p.county = 9; p.val = 154; p.d = 76; p.r = 78;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 68; p.county = 9; p.val = 90; p.d = 7; p.r = 83;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 67; p.county = 9; p.val = 103; p.d = 16; p.r = 87;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 66; p.county = 9; p.val = 234; p.d = 104; p.r = 130;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 63; p.county = 9; p.val = 714; p.d = 527; p.r = 187;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 59; p.county = 9; p.val = 727; p.d = 614; p.r = 113;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 61; p.county = 9; p.val = 269; p.d = 177; p.r = 92;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 61; p.county = 11; p.val = 301; p.d = 166; p.r = 135;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 61; p.county = 11; p.val = 722; p.d = 261; p.r = 461;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 63; p.county = 11; p.val = 799; p.d = 346; p.r = 453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 64; p.county = 11; p.val = 615; p.d = 377; p.r = 238;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 60; p.county = 11; p.val = 486; p.d = 352; p.r = 134;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 60; p.county = 11; p.val = 308; p.d = 208; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 58; p.county = 11; p.val = 350; p.d = 165; p.r = 185;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 64; p.county = 11; p.val = 327; p.d = 38; p.r = 289;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 66; p.county = 11; p.val = 301; p.d = 136; p.r = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 57; p.county = 11; p.val = 478; p.d = 377; p.r = 101;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 62; p.county = 11; p.val = 465; p.d = 54; p.r = 411;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 64; p.county = 11; p.val = 609; p.d = 278; p.r = 331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 56; p.county = 11; p.val = 734; p.d = 480; p.r = 254;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 59; p.county = 11; p.val = 313; p.d = 106; p.r = 207;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 58; p.county = 11; p.val = 475; p.d = 205; p.r = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 63; p.county = 11; p.val = 0; p.d = 0; p.r = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 89; p.county = 13; p.val = 1761; p.d = 954; p.r = 807;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 90; p.county = 13; p.val = 937; p.d = 418; p.r = 519;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 89; p.county = 13; p.val = 832; p.d = 499; p.r = 333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 92; p.county = 13; p.val = 717; p.d = 314; p.r = 403;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 90; p.county = 13; p.val = 1076; p.d = 382; p.r = 694;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 88; p.county = 13; p.val = 773; p.d = 321; p.r = 452;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 91; p.county = 13; p.val = 1223; p.d = 668; p.r = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 89; p.county = 13; p.val = 610; p.d = 495; p.r = 115;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 90; p.county = 13; p.val = 1914; p.d = 772; p.r = 1142;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 91; p.county = 13; p.val = 862; p.d = 428; p.r = 434;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 92; p.county = 13; p.val = 1071; p.d = 381; p.r = 690;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 92; p.county = 13; p.val = 805; p.d = 252; p.r = 553;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 89; p.county = 13; p.val = 1558; p.d = 605; p.r = 953;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 91; p.county = 13; p.val = 963; p.d = 425; p.r = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 88; p.county = 13; p.val = 1586; p.d = 590; p.r = 996;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 87; p.county = 13; p.val = 834; p.d = 332; p.r = 502;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 85; p.county = 13; p.val = 618; p.d = 410; p.r = 208;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 88; p.county = 13; p.val = 512; p.d = 276; p.r = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 86; p.county = 13; p.val = 528; p.d = 404; p.r = 124;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 87; p.county = 13; p.val = 733; p.d = 447; p.r = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 84; p.county = 13; p.val = 656; p.d = 356; p.r = 300;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 82; p.county = 13; p.val = 409; p.d = 358; p.r = 51;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 88; p.county = 13; p.val = 258; p.d = 147; p.r = 111;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 91; p.county = 13; p.val = 754; p.d = 624; p.r = 130;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 94; p.county = 13; p.val = 835; p.d = 670; p.r = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 89; p.county = 13; p.val = 1151; p.d = 472; p.r = 679;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 89; p.county = 13; p.val = 844; p.d = 526; p.r = 318;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 90; p.county = 13; p.val = 811; p.d = 646; p.r = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 93; p.county = 13; p.val = 736; p.d = 275; p.r = 461;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 88; p.county = 13; p.val = 577; p.d = 212; p.r = 365;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 100; p.county = 13; p.val = 298; p.d = 110; p.r = 188;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 96; p.county = 13; p.val = 2064; p.d = 937; p.r = 1127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 98; p.county = 13; p.val = 1451; p.d = 497; p.r = 954;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 96; p.county = 13; p.val = 1259; p.d = 649; p.r = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 97; p.county = 13; p.val = 1018; p.d = 408; p.r = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 96; p.county = 13; p.val = 701; p.d = 372; p.r = 329;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 98; p.county = 13; p.val = 1570; p.d = 624; p.r = 946;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 97; p.county = 13; p.val = 2048; p.d = 885; p.r = 1163;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 94; p.county = 13; p.val = 753; p.d = 311; p.r = 442;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 95; p.county = 13; p.val = 1515; p.d = 657; p.r = 858;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 94; p.county = 13; p.val = 583; p.d = 245; p.r = 338;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 95; p.county = 13; p.val = 652; p.d = 261; p.r = 391;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 98; p.county = 13; p.val = 1864; p.d = 904; p.r = 960;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 97; p.county = 13; p.val = 1155; p.d = 580; p.r = 575;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 99; p.county = 13; p.val = 1462; p.d = 616; p.r = 846;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 99; p.county = 13; p.val = 746; p.d = 363; p.r = 383;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 100; p.county = 13; p.val = 572; p.d = 221; p.r = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 94; p.county = 13; p.val = 1353; p.d = 418; p.r = 935;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 96; p.county = 13; p.val = 556; p.d = 219; p.r = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 95; p.county = 13; p.val = 2713; p.d = 1440; p.r = 1273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 95; p.county = 13; p.val = 1910; p.d = 770; p.r = 1140;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 94; p.county = 13; p.val = 1864; p.d = 699; p.r = 1165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 94; p.county = 13; p.val = 5005; p.d = 1929; p.r = 3076;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 95; p.county = 13; p.val = 2344; p.d = 948; p.r = 1396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 94; p.county = 13; p.val = 1580; p.d = 634; p.r = 946;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 96; p.county = 13; p.val = 891; p.d = 483; p.r = 408;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 97; p.county = 13; p.val = 798; p.d = 292; p.r = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 95; p.county = 13; p.val = 725; p.d = 387; p.r = 338;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 95; p.county = 13; p.val = 1290; p.d = 496; p.r = 794;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 97; p.county = 13; p.val = 1565; p.d = 644; p.r = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 94; p.county = 13; p.val = 532; p.d = 149; p.r = 383;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 93; p.county = 13; p.val = 589; p.d = 164; p.r = 425;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 60; p.county = 15; p.val = 526; p.d = 341; p.r = 185;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 64; p.county = 15; p.val = 139; p.d = 12; p.r = 127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 61; p.county = 15; p.val = 612; p.d = 259; p.r = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 60; p.county = 15; p.val = 850; p.d = 199; p.r = 651;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 62; p.county = 15; p.val = 860; p.d = 125; p.r = 735;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 63; p.county = 15; p.val = 1270; p.d = 511; p.r = 759;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 57; p.county = 15; p.val = 660; p.d = 532; p.r = 128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 57; p.county = 15; p.val = 647; p.d = 551; p.r = 96;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 70; p.county = 15; p.val = 3401; p.d = 1490; p.r = 1911;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 71; p.county = 15; p.val = 3192; p.d = 1687; p.r = 1505;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 71; p.county = 15; p.val = 626; p.d = 506; p.r = 120;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 57; p.county = 15; p.val = 357; p.d = 283; p.r = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 64; p.county = 15; p.val = 832; p.d = 267; p.r = 565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 58; p.county = 15; p.val = 662; p.d = 369; p.r = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 68; p.county = 15; p.val = 1165; p.d = 229; p.r = 936;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 72; p.county = 15; p.val = 5053; p.d = 2582; p.r = 2471;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 70; p.county = 15; p.val = 4715; p.d = 2404; p.r = 2311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 69; p.county = 15; p.val = 2486; p.d = 1088; p.r = 1398;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 63; p.county = 15; p.val = 926; p.d = 237; p.r = 689;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 66; p.county = 15; p.val = 622; p.d = 245; p.r = 377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 62; p.county = 15; p.val = 306; p.d = 187; p.r = 119;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 61; p.county = 15; p.val = 565; p.d = 279; p.r = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 64; p.county = 15; p.val = 753; p.d = 461; p.r = 292;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 66; p.county = 15; p.val = 390; p.d = 59; p.r = 331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 65; p.county = 15; p.val = 633; p.d = 319; p.r = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 75; p.county = 15; p.val = 1258; p.d = 439; p.r = 819;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 75; p.county = 15; p.val = 947; p.d = 471; p.r = 476;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 70; p.county = 15; p.val = 3989; p.d = 1856; p.r = 2133;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 73; p.county = 15; p.val = 1355; p.d = 831; p.r = 524;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 74; p.county = 15; p.val = 4005; p.d = 2496; p.r = 1509;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 71; p.county = 15; p.val = 3366; p.d = 1590; p.r = 1776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 68; p.county = 15; p.val = 691; p.d = 456; p.r = 235;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 65; p.county = 15; p.val = 1626; p.d = 939; p.r = 687;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 69; p.county = 15; p.val = 713; p.d = 147; p.r = 566;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 71; p.county = 15; p.val = 1065; p.d = 343; p.r = 722;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 68; p.county = 15; p.val = 1193; p.d = 484; p.r = 709;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 64; p.county = 15; p.val = 247; p.d = 113; p.r = 134;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 69; p.county = 15; p.val = 639; p.d = 318; p.r = 321;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 71; p.county = 15; p.val = 1259; p.d = 734; p.r = 525;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 66; p.county = 15; p.val = 1234; p.d = 676; p.r = 558;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 67; p.county = 15; p.val = 751; p.d = 312; p.r = 439;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 76; p.county = 15; p.val = 2214; p.d = 1632; p.r = 582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 76; p.county = 15; p.val = 2873; p.d = 1276; p.r = 1597;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 74; p.county = 15; p.val = 2743; p.d = 1018; p.r = 1725;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 73; p.county = 15; p.val = 1058; p.d = 532; p.r = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 67; p.county = 15; p.val = 2675; p.d = 1157; p.r = 1518;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 68; p.county = 15; p.val = 2196; p.d = 1107; p.r = 1089;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 73; p.county = 15; p.val = 2749; p.d = 1031; p.r = 1718;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 58; p.county = 15; p.val = 652; p.d = 525; p.r = 127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 65; p.county = 15; p.val = 506; p.d = 221; p.r = 285;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 72; p.county = 15; p.val = 556; p.d = 274; p.r = 282;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 69; p.county = 15; p.val = 817; p.d = 440; p.r = 377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 72; p.county = 15; p.val = 709; p.d = 509; p.r = 200;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 69; p.county = 15; p.val = 1856; p.d = 1115; p.r = 741;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 68; p.county = 15; p.val = 80; p.d = 28; p.r = 52;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 47; p.county = 17; p.val = 504; p.d = 171; p.r = 333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 52; p.county = 17; p.val = 464; p.d = 251; p.r = 213;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 49; p.county = 17; p.val = 632; p.d = 359; p.r = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 51; p.county = 17; p.val = 138; p.d = 60; p.r = 78;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 49; p.county = 17; p.val = 996; p.d = 772; p.r = 224;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 48; p.county = 17; p.val = 309; p.d = 148; p.r = 161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 47; p.county = 17; p.val = 165; p.d = 91; p.r = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 50; p.county = 17; p.val = 458; p.d = 205; p.r = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 54; p.county = 17; p.val = 215; p.d = 64; p.r = 151;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 49; p.county = 17; p.val = 271; p.d = 163; p.r = 108;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 44; p.county = 17; p.val = 994; p.d = 347; p.r = 647;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 50; p.county = 17; p.val = 796; p.d = 359; p.r = 437;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 73; p.county = 19; p.val = 811; p.d = 447; p.r = 364;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 69; p.county = 19; p.val = 547; p.d = 291; p.r = 256;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 79; p.county = 19; p.val = 1999; p.d = 964; p.r = 1035;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 72; p.county = 19; p.val = 3162; p.d = 2036; p.r = 1126;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 82; p.county = 19; p.val = 728; p.d = 485; p.r = 243;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 78; p.county = 19; p.val = 1634; p.d = 791; p.r = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 76; p.county = 19; p.val = 3542; p.d = 1858; p.r = 1684;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 77; p.county = 19; p.val = 1594; p.d = 750; p.r = 844;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 77; p.county = 19; p.val = 992; p.d = 414; p.r = 578;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 77; p.county = 19; p.val = 4758; p.d = 2402; p.r = 2356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 77; p.county = 19; p.val = 1094; p.d = 390; p.r = 704;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 77; p.county = 19; p.val = 5297; p.d = 2534; p.r = 2763;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 68; p.county = 19; p.val = 1072; p.d = 756; p.r = 316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 82; p.county = 19; p.val = 699; p.d = 411; p.r = 288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 84; p.county = 19; p.val = 1224; p.d = 436; p.r = 788;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 85; p.county = 19; p.val = 985; p.d = 523; p.r = 462;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 85; p.county = 19; p.val = 1627; p.d = 693; p.r = 934;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 78; p.county = 19; p.val = 5697; p.d = 3495; p.r = 2202;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 83; p.county = 19; p.val = 754; p.d = 422; p.r = 332;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 81; p.county = 19; p.val = 923; p.d = 471; p.r = 452;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 77; p.county = 19; p.val = 5874; p.d = 5082; p.r = 792;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 78; p.county = 19; p.val = 1102; p.d = 525; p.r = 577;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 76; p.county = 19; p.val = 1487; p.d = 796; p.r = 691;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 75; p.county = 19; p.val = 2547; p.d = 1064; p.r = 1483;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 75; p.county = 19; p.val = 3532; p.d = 1555; p.r = 1977;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 74; p.county = 19; p.val = 5946; p.d = 2250; p.r = 3696;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 75; p.county = 19; p.val = 2010; p.d = 1020; p.r = 990;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 74; p.county = 19; p.val = 1755; p.d = 666; p.r = 1089;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 81; p.county = 19; p.val = 1156; p.d = 732; p.r = 424;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 82; p.county = 19; p.val = 534; p.d = 453; p.r = 81;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 79; p.county = 19; p.val = 1616; p.d = 746; p.r = 870;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 80; p.county = 19; p.val = 448; p.d = 172; p.r = 276;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 80; p.county = 19; p.val = 3563; p.d = 2230; p.r = 1333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 79; p.county = 19; p.val = 2589; p.d = 1677; p.r = 912;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 79; p.county = 19; p.val = 5456; p.d = 2962; p.r = 2494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 82; p.county = 19; p.val = 1034; p.d = 538; p.r = 496;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 75; p.county = 19; p.val = 812; p.d = 315; p.r = 497;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 80; p.county = 19; p.val = 973; p.d = 640; p.r = 333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 78; p.county = 19; p.val = 5777; p.d = 3428; p.r = 2349;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 80; p.county = 19; p.val = 1948; p.d = 1037; p.r = 911;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 79; p.county = 19; p.val = 754; p.d = 334; p.r = 420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 79; p.county = 19; p.val = 811; p.d = 520; p.r = 291;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 79; p.county = 19; p.val = 1941; p.d = 1052; p.r = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 82; p.county = 19; p.val = 626; p.d = 394; p.r = 232;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 81; p.county = 19; p.val = 602; p.d = 460; p.r = 142;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 77; p.county = 19; p.val = 498; p.d = 309; p.r = 189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 80; p.county = 19; p.val = 782; p.d = 481; p.r = 301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 80; p.county = 19; p.val = 1177; p.d = 390; p.r = 787;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 79; p.county = 19; p.val = 944; p.d = 725; p.r = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 78; p.county = 19; p.val = 569; p.d = 282; p.r = 287;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 77; p.county = 19; p.val = 1089; p.d = 442; p.r = 647;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 77; p.county = 19; p.val = 4720; p.d = 3012; p.r = 1708;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 77; p.county = 19; p.val = 5152; p.d = 3558; p.r = 1594;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 78; p.county = 19; p.val = 1604; p.d = 776; p.r = 828;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 76; p.county = 19; p.val = 2996; p.d = 1503; p.r = 1493;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 78; p.county = 19; p.val = 2121; p.d = 1232; p.r = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 77; p.county = 19; p.val = 1089; p.d = 634; p.r = 455;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 77; p.county = 19; p.val = 1574; p.d = 880; p.r = 694;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 76; p.county = 19; p.val = 1452; p.d = 1078; p.r = 374;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 76; p.county = 19; p.val = 2588; p.d = 1098; p.r = 1490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 75; p.county = 19; p.val = 1625; p.d = 932; p.r = 693;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 76; p.county = 19; p.val = 1660; p.d = 880; p.r = 780;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 75; p.county = 19; p.val = 3654; p.d = 3105; p.r = 549;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 75; p.county = 19; p.val = 2234; p.d = 1635; p.r = 599;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 74; p.county = 19; p.val = 2352; p.d = 1389; p.r = 963;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 74; p.county = 19; p.val = 2060; p.d = 1661; p.r = 399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 73; p.county = 19; p.val = 2689; p.d = 1893; p.r = 796;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 5; p.county = 21; p.val = 468; p.d = 50; p.r = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 3; p.county = 21; p.val = 692; p.d = 370; p.r = 322;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 2; p.county = 21; p.val = 651; p.d = 81; p.r = 570;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 1; p.county = 21; p.val = 646; p.d = 82; p.r = 564;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 2; p.county = 21; p.val = 448; p.d = 140; p.r = 308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 2; p.county = 21; p.val = 691; p.d = 123; p.r = 568;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 4; p.county = 21; p.val = 772; p.d = 186; p.r = 586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 3; p.county = 21; p.val = 1614; p.d = 1212; p.r = 402;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 4; p.county = 21; p.val = 1297; p.d = 391; p.r = 906;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 2; p.county = 21; p.val = 728; p.d = 123; p.r = 605;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 4; p.county = 21; p.val = 550; p.d = 239; p.r = 311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 3; p.county = 21; p.val = 1055; p.d = 639; p.r = 416;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 1; p.county = 21; p.val = 1160; p.d = 223; p.r = 937;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 5; p.county = 21; p.val = 612; p.d = 104; p.r = 508;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 1; p.county = 21; p.val = 623; p.d = 97; p.r = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 9; p.county = 21; p.val = 221; p.d = 29; p.r = 192;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 3; p.county = 21; p.val = 771; p.d = 161; p.r = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 0; p.county = 21; p.val = 649; p.d = 96; p.r = 553;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 3; p.county = 21; p.val = 467; p.d = 54; p.r = 413;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 1; p.county = 21; p.val = 524; p.d = 275; p.r = 249;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 6; p.county = 21; p.val = 527; p.d = 76; p.r = 451;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 7; p.county = 21; p.val = 649; p.d = 98; p.r = 551;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 6; p.county = 21; p.val = 318; p.d = 22; p.r = 296;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 0; p.county = 21; p.val = 561; p.d = 93; p.r = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 15; p.county = 23; p.val = 889; p.d = 636; p.r = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 14; p.county = 23; p.val = 366; p.d = 92; p.r = 274;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 18; p.county = 23; p.val = 599; p.d = 291; p.r = 308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 18; p.county = 23; p.val = 358; p.d = 149; p.r = 209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 12; p.county = 23; p.val = 694; p.d = 227; p.r = 467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 14; p.county = 23; p.val = 673; p.d = 447; p.r = 226;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 15; p.county = 23; p.val = 800; p.d = 328; p.r = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 18; p.county = 23; p.val = 133; p.d = 71; p.r = 62;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 18; p.county = 23; p.val = 406; p.d = 134; p.r = 272;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 12; p.county = 23; p.val = 554; p.d = 158; p.r = 396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 15; p.county = 23; p.val = 781; p.d = 331; p.r = 450;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 13; p.county = 23; p.val = 749; p.d = 270; p.r = 479;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 19; p.county = 23; p.val = 251; p.d = 74; p.r = 177;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 13; p.county = 23; p.val = 342; p.d = 194; p.r = 148;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 20; p.county = 23; p.val = 521; p.d = 282; p.r = 239;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 14; p.county = 23; p.val = 690; p.d = 506; p.r = 184;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 16; p.county = 23; p.val = 573; p.d = 333; p.r = 240;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 15; p.county = 23; p.val = 439; p.d = 313; p.r = 126;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 16; p.county = 23; p.val = 441; p.d = 159; p.r = 282;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 19; p.county = 25; p.val = 342; p.d = 126; p.r = 216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 18; p.county = 25; p.val = 176; p.d = 35; p.r = 141;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 16; p.county = 25; p.val = 140; p.d = 47; p.r = 93;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 13; p.county = 25; p.val = 677; p.d = 413; p.r = 264;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 18; p.county = 25; p.val = 528; p.d = 306; p.r = 222;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 13; p.county = 25; p.val = 427; p.d = 239; p.r = 188;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 14; p.county = 25; p.val = 653; p.d = 286; p.r = 367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 15; p.county = 25; p.val = 436; p.d = 241; p.r = 195;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 16; p.county = 25; p.val = 730; p.d = 529; p.r = 201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 16; p.county = 25; p.val = 592; p.d = 353; p.r = 239;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 15; p.county = 25; p.val = 829; p.d = 290; p.r = 539;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 12; p.county = 25; p.val = 388; p.d = 93; p.r = 295;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 17; p.county = 25; p.val = 552; p.d = 206; p.r = 346;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 16; p.county = 25; p.val = 832; p.d = 367; p.r = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 23; p.county = 25; p.val = 817; p.d = 337; p.r = 480;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 22; p.county = 25; p.val = 348; p.d = 59; p.r = 289;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 13; p.county = 25; p.val = 199; p.d = 49; p.r = 150;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 21; p.county = 25; p.val = 315; p.d = 52; p.r = 263;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 14; p.county = 25; p.val = 824; p.d = 381; p.r = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 13; p.county = 25; p.val = 691; p.d = 287; p.r = 404;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 19; p.county = 25; p.val = 326; p.d = 143; p.r = 183;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 21; p.county = 25; p.val = 136; p.d = 26; p.r = 110;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 14; p.county = 25; p.val = 461; p.d = 208; p.r = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 16; p.county = 25; p.val = 315; p.d = 100; p.r = 215;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 13; p.county = 25; p.val = 237; p.d = 68; p.r = 169;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 45; p.county = 27; p.val = 534; p.d = 306; p.r = 228;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 43; p.county = 27; p.val = 316; p.d = 46; p.r = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 45; p.county = 27; p.val = 107; p.d = 38; p.r = 69;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 52; p.county = 27; p.val = 232; p.d = 105; p.r = 127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 49; p.county = 27; p.val = 370; p.d = 311; p.r = 59;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 53; p.county = 27; p.val = 1009; p.d = 481; p.r = 528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 46; p.county = 27; p.val = 381; p.d = 204; p.r = 177;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 42; p.county = 27; p.val = 340; p.d = 69; p.r = 271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 46; p.county = 27; p.val = 239; p.d = 65; p.r = 174;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 53; p.county = 27; p.val = 1111; p.d = 335; p.r = 776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 48; p.county = 27; p.val = 323; p.d = 207; p.r = 116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 49; p.county = 27; p.val = 1226; p.d = 590; p.r = 636;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 48; p.county = 27; p.val = 701; p.d = 594; p.r = 107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 47; p.county = 27; p.val = 504; p.d = 289; p.r = 215;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 44; p.county = 27; p.val = 335; p.d = 141; p.r = 194;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 47; p.county = 27; p.val = 599; p.d = 418; p.r = 181;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 50; p.county = 27; p.val = 165; p.d = 133; p.r = 32;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 44; p.county = 27; p.val = 267; p.d = 188; p.r = 79;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 54; p.county = 27; p.val = 1094; p.d = 483; p.r = 611;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 52; p.county = 27; p.val = 202; p.d = 162; p.r = 40;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 50; p.county = 27; p.val = 537; p.d = 446; p.r = 91;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 41; p.county = 27; p.val = 649; p.d = 214; p.r = 435;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 50; p.county = 27; p.val = 641; p.d = 421; p.r = 220;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 47; p.county = 27; p.val = 205; p.d = 119; p.r = 86;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 72; p.county = 29; p.val = 231; p.d = 101; p.r = 130;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 69; p.county = 29; p.val = 302; p.d = 140; p.r = 162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 74; p.county = 29; p.val = 794; p.d = 265; p.r = 529;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 68; p.county = 29; p.val = 189; p.d = 138; p.r = 51;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 83; p.county = 29; p.val = 533; p.d = 412; p.r = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 79; p.county = 29; p.val = 557; p.d = 373; p.r = 184;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 71; p.county = 29; p.val = 360; p.d = 124; p.r = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 73; p.county = 29; p.val = 318; p.d = 98; p.r = 220;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 78; p.county = 29; p.val = 246; p.d = 193; p.r = 53;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 70; p.county = 29; p.val = 197; p.d = 67; p.r = 130;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 70; p.county = 29; p.val = 511; p.d = 134; p.r = 377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 76; p.county = 29; p.val = 439; p.d = 264; p.r = 175;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 71; p.county = 29; p.val = 620; p.d = 279; p.r = 341;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 77; p.county = 29; p.val = 119; p.d = 57; p.r = 62;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 76; p.county = 29; p.val = 392; p.d = 175; p.r = 217;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 78; p.county = 29; p.val = 288; p.d = 224; p.r = 64;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 73; p.county = 29; p.val = 506; p.d = 208; p.r = 298;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 74; p.county = 29; p.val = 264; p.d = 95; p.r = 169;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 71; p.county = 29; p.val = 191; p.d = 91; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 70; p.county = 29; p.val = 284; p.d = 71; p.r = 213;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 67; p.county = 29; p.val = 602; p.d = 418; p.r = 184;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 72; p.county = 29; p.val = 388; p.d = 98; p.r = 290;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 74; p.county = 29; p.val = 261; p.d = 82; p.r = 179;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 75; p.county = 29; p.val = 542; p.d = 280; p.r = 262;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 73; p.county = 29; p.val = 1231; p.d = 574; p.r = 657;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 75; p.county = 29; p.val = 574; p.d = 486; p.r = 88;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 74; p.county = 29; p.val = 614; p.d = 276; p.r = 338;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 69; p.county = 29; p.val = 196; p.d = 91; p.r = 105;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 71; p.county = 29; p.val = 202; p.d = 35; p.r = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 88; p.county = 29; p.val = 794; p.d = 203; p.r = 591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 74; p.county = 29; p.val = 467; p.d = 269; p.r = 198;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 23; p.county = 31; p.val = 953; p.d = 383; p.r = 570;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 26; p.county = 31; p.val = 399; p.d = 318; p.r = 81;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 28; p.county = 31; p.val = 400; p.d = 213; p.r = 187;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 26; p.county = 31; p.val = 626; p.d = 179; p.r = 447;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 28; p.county = 31; p.val = 416; p.d = 146; p.r = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 28; p.county = 31; p.val = 927; p.d = 495; p.r = 432;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 29; p.county = 31; p.val = 649; p.d = 463; p.r = 186;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 29; p.county = 31; p.val = 1343; p.d = 1091; p.r = 252;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 25; p.county = 31; p.val = 832; p.d = 538; p.r = 294;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 27; p.county = 31; p.val = 417; p.d = 281; p.r = 136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 26; p.county = 31; p.val = 2079; p.d = 846; p.r = 1233;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 27; p.county = 31; p.val = 605; p.d = 594; p.r = 11;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 26; p.county = 31; p.val = 521; p.d = 234; p.r = 287;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 25; p.county = 31; p.val = 1540; p.d = 370; p.r = 1170;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 30; p.county = 31; p.val = 1315; p.d = 730; p.r = 585;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 29; p.county = 31; p.val = 339; p.d = 109; p.r = 230;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 32; p.county = 31; p.val = 731; p.d = 355; p.r = 376;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 33; p.county = 31; p.val = 445; p.d = 289; p.r = 156;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 33; p.county = 31; p.val = 891; p.d = 363; p.r = 528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 29; p.county = 31; p.val = 429; p.d = 306; p.r = 123;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 26; p.county = 31; p.val = 868; p.d = 459; p.r = 409;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 24; p.county = 31; p.val = 558; p.d = 85; p.r = 473;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 30; p.county = 31; p.val = 591; p.d = 237; p.r = 354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 29; p.county = 31; p.val = 1052; p.d = 577; p.r = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 23; p.county = 31; p.val = 504; p.d = 363; p.r = 141;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 28; p.county = 31; p.val = 521; p.d = 187; p.r = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 27; p.county = 31; p.val = 1272; p.d = 566; p.r = 706;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 25; p.county = 31; p.val = 925; p.d = 406; p.r = 519;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 26; p.county = 31; p.val = 1159; p.d = 253; p.r = 906;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 24; p.county = 33; p.val = 987; p.d = 201; p.r = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 25; p.county = 33; p.val = 636; p.d = 485; p.r = 151;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 25; p.county = 33; p.val = 555; p.d = 457; p.r = 98;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 27; p.county = 33; p.val = 1206; p.d = 604; p.r = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 26; p.county = 33; p.val = 106; p.d = 35; p.r = 71;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 25; p.county = 33; p.val = 174; p.d = 55; p.r = 119;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 28; p.county = 33; p.val = 654; p.d = 288; p.r = 366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 28; p.county = 33; p.val = 236; p.d = 136; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 25; p.county = 33; p.val = 855; p.d = 598; p.r = 257;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 27; p.county = 33; p.val = 139; p.d = 55; p.r = 84;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 24; p.county = 33; p.val = 91; p.d = 34; p.r = 57;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 23; p.county = 33; p.val = 361; p.d = 151; p.r = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 22; p.county = 33; p.val = 447; p.d = 280; p.r = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 20; p.county = 33; p.val = 121; p.d = 82; p.r = 39;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 23; p.county = 33; p.val = 335; p.d = 236; p.r = 99;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 21; p.county = 33; p.val = 115; p.d = 68; p.r = 47;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 28; p.county = 33; p.val = 417; p.d = 154; p.r = 263;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 26; p.county = 33; p.val = 152; p.d = 69; p.r = 83;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 28; p.county = 33; p.val = 347; p.d = 92; p.r = 255;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 29; p.county = 33; p.val = 259; p.d = 61; p.r = 198;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 62; p.county = 35; p.val = 698; p.d = 358; p.r = 340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 65; p.county = 35; p.val = 363; p.d = 158; p.r = 205;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 66; p.county = 35; p.val = 530; p.d = 265; p.r = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 67; p.county = 35; p.val = 460; p.d = 231; p.r = 229;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 65; p.county = 35; p.val = 545; p.d = 284; p.r = 261;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 65; p.county = 35; p.val = 343; p.d = 128; p.r = 215;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 64; p.county = 35; p.val = 597; p.d = 260; p.r = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 67; p.county = 35; p.val = 576; p.d = 230; p.r = 346;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 70; p.county = 35; p.val = 3971; p.d = 1480; p.r = 2491;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 71; p.county = 35; p.val = 2904; p.d = 1173; p.r = 1731;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 72; p.county = 35; p.val = 1027; p.d = 427; p.r = 600;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 72; p.county = 35; p.val = 3866; p.d = 1585; p.r = 2281;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 70; p.county = 35; p.val = 3010; p.d = 1530; p.r = 1480;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 64; p.county = 35; p.val = 407; p.d = 222; p.r = 185;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 71; p.county = 35; p.val = 5960; p.d = 2303; p.r = 3657;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 68; p.county = 35; p.val = 429; p.d = 206; p.r = 223;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 72; p.county = 35; p.val = 518; p.d = 167; p.r = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 73; p.county = 35; p.val = 4689; p.d = 2456; p.r = 2233;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 70; p.county = 35; p.val = 597; p.d = 253; p.r = 344;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 74; p.county = 35; p.val = 470; p.d = 353; p.r = 117;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 74; p.county = 35; p.val = 214; p.d = 59; p.r = 155;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 72; p.county = 35; p.val = 4770; p.d = 2602; p.r = 2168;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 73; p.county = 35; p.val = 880; p.d = 296; p.r = 584;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 73; p.county = 35; p.val = 736; p.d = 229; p.r = 507;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 71; p.county = 35; p.val = 1333; p.d = 520; p.r = 813;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 70; p.county = 35; p.val = 931; p.d = 350; p.r = 581;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 63; p.county = 35; p.val = 265; p.d = 178; p.r = 87;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 74; p.county = 35; p.val = 2440; p.d = 1194; p.r = 1246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 69; p.county = 35; p.val = 1190; p.d = 531; p.r = 659;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 69; p.county = 35; p.val = 1643; p.d = 723; p.r = 920;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 68; p.county = 35; p.val = 380; p.d = 206; p.r = 174;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 44; p.county = 37; p.val = 520; p.d = 198; p.r = 322;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 46; p.county = 37; p.val = 843; p.d = 398; p.r = 445;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 44; p.county = 37; p.val = 685; p.d = 432; p.r = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 43; p.county = 37; p.val = 732; p.d = 418; p.r = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 47; p.county = 37; p.val = 615; p.d = 303; p.r = 312;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 52; p.county = 37; p.val = 1504; p.d = 343; p.r = 1161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 47; p.county = 37; p.val = 598; p.d = 46; p.r = 552;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 45; p.county = 37; p.val = 527; p.d = 152; p.r = 375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 41; p.county = 37; p.val = 299; p.d = 168; p.r = 131;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 42; p.county = 37; p.val = 330; p.d = 212; p.r = 118;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 50; p.county = 37; p.val = 1709; p.d = 420; p.r = 1289;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 49; p.county = 37; p.val = 1021; p.d = 657; p.r = 364;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 20; p.county = 39; p.val = 40; p.d = 34; p.r = 6;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 24; p.county = 39; p.val = 286; p.d = 243; p.r = 43;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 29; p.county = 39; p.val = 184; p.d = 56; p.r = 128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 21; p.county = 39; p.val = 195; p.d = 137; p.r = 58;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 29; p.county = 39; p.val = 1020; p.d = 720; p.r = 300;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 21; p.county = 39; p.val = 47; p.d = 19; p.r = 28;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 30; p.county = 39; p.val = 390; p.d = 332; p.r = 58;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 29; p.county = 39; p.val = 195; p.d = 172; p.r = 23;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 27; p.county = 39; p.val = 556; p.d = 380; p.r = 176;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 25; p.county = 39; p.val = 452; p.d = 218; p.r = 234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 22; p.county = 39; p.val = 503; p.d = 264; p.r = 239;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 26; p.county = 39; p.val = 330; p.d = 252; p.r = 78;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 22; p.county = 39; p.val = 52; p.d = 20; p.r = 32;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 28; p.county = 39; p.val = 1219; p.d = 807; p.r = 412;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 28; p.county = 39; p.val = 578; p.d = 345; p.r = 233;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 26; p.county = 39; p.val = 362; p.d = 292; p.r = 70;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 26; p.county = 39; p.val = 336; p.d = 181; p.r = 155;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 26; p.county = 39; p.val = 725; p.d = 564; p.r = 161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 25; p.county = 39; p.val = 618; p.d = 365; p.r = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 23; p.county = 39; p.val = 178; p.d = 134; p.r = 44;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 22; p.county = 39; p.val = 89; p.d = 75; p.r = 14;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 25; p.county = 39; p.val = 919; p.d = 255; p.r = 664;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 29; p.county = 41; p.val = 280; p.d = 97; p.r = 183;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 30; p.county = 41; p.val = 379; p.d = 294; p.r = 85;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 35; p.county = 41; p.val = 480; p.d = 204; p.r = 276;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 32; p.county = 41; p.val = 2080; p.d = 681; p.r = 1399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 44; p.county = 41; p.val = 935; p.d = 294; p.r = 641;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 35; p.county = 41; p.val = 1127; p.d = 424; p.r = 703;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 36; p.county = 41; p.val = 623; p.d = 188; p.r = 435;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 32; p.county = 41; p.val = 2127; p.d = 1132; p.r = 995;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 33; p.county = 41; p.val = 2582; p.d = 1216; p.r = 1366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 39; p.county = 41; p.val = 453; p.d = 147; p.r = 306;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 38; p.county = 41; p.val = 436; p.d = 119; p.r = 317;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 33; p.county = 41; p.val = 2148; p.d = 952; p.r = 1196;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 32; p.county = 41; p.val = 2425; p.d = 1098; p.r = 1327;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 33; p.county = 41; p.val = 1414; p.d = 622; p.r = 792;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 41; p.county = 41; p.val = 279; p.d = 73; p.r = 206;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 32; p.county = 41; p.val = 750; p.d = 236; p.r = 514;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 36; p.county = 41; p.val = 405; p.d = 97; p.r = 308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 36; p.county = 41; p.val = 914; p.d = 253; p.r = 661;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 31; p.county = 41; p.val = 2271; p.d = 2216; p.r = 55;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 32; p.county = 41; p.val = 926; p.d = 804; p.r = 122;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 31; p.county = 41; p.val = 1487; p.d = 918; p.r = 569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 33; p.county = 41; p.val = 2179; p.d = 736; p.r = 1443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 39; p.county = 41; p.val = 301; p.d = 44; p.r = 257;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 34; p.county = 41; p.val = 1041; p.d = 569; p.r = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 41; p.county = 41; p.val = 409; p.d = 56; p.r = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 43; p.county = 41; p.val = 1307; p.d = 796; p.r = 511;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 43; p.county = 41; p.val = 181; p.d = 72; p.r = 109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 33; p.county = 41; p.val = 1147; p.d = 585; p.r = 562;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 30; p.county = 41; p.val = 835; p.d = 313; p.r = 522;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 41; p.county = 41; p.val = 396; p.d = 121; p.r = 275;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 37; p.county = 41; p.val = 354; p.d = 245; p.r = 109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 37; p.county = 41; p.val = 606; p.d = 104; p.r = 502;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 40; p.county = 41; p.val = 782; p.d = 361; p.r = 421;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 42; p.county = 41; p.val = 537; p.d = 317; p.r = 220;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 42; p.county = 41; p.val = 693; p.d = 445; p.r = 248;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 43; p.county = 41; p.val = 765; p.d = 725; p.r = 40;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 38; p.county = 41; p.val = 599; p.d = 185; p.r = 414;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 39; p.county = 41; p.val = 356; p.d = 261; p.r = 95;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 43; p.county = 41; p.val = 196; p.d = 17; p.r = 179;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 30; p.county = 41; p.val = 564; p.d = 434; p.r = 130;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 39; p.county = 41; p.val = 296; p.d = 38; p.r = 258;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 34; p.county = 41; p.val = 1921; p.d = 1065; p.r = 856;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 41; p.county = 41; p.val = 475; p.d = 210; p.r = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 34; p.county = 41; p.val = 945; p.d = 755; p.r = 190;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 35; p.county = 41; p.val = 905; p.d = 424; p.r = 481;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 33; p.county = 41; p.val = 758; p.d = 622; p.r = 136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 44; p.county = 41; p.val = 330; p.d = 84; p.r = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 31; p.county = 41; p.val = 1461; p.d = 570; p.r = 891;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 34; p.county = 41; p.val = 620; p.d = 314; p.r = 306;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 56; p.county = 43; p.val = 1397; p.d = 926; p.r = 471;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 57; p.county = 43; p.val = 491; p.d = 64; p.r = 427;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 56; p.county = 43; p.val = 827; p.d = 244; p.r = 583;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 55; p.county = 43; p.val = 1038; p.d = 866; p.r = 172;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 52; p.county = 43; p.val = 526; p.d = 405; p.r = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 59; p.county = 43; p.val = 986; p.d = 684; p.r = 302;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 58; p.county = 43; p.val = 1410; p.d = 746; p.r = 664;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 55; p.county = 43; p.val = 1793; p.d = 649; p.r = 1144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 51; p.county = 43; p.val = 122; p.d = 26; p.r = 96;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 53; p.county = 43; p.val = 1451; p.d = 531; p.r = 920;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 53; p.county = 43; p.val = 930; p.d = 228; p.r = 702;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 60; p.county = 43; p.val = 297; p.d = 66; p.r = 231;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 47; p.county = 43; p.val = 526; p.d = 135; p.r = 391;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 49; p.county = 43; p.val = 350; p.d = 275; p.r = 75;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 52; p.county = 43; p.val = 3991; p.d = 1237; p.r = 2754;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 53; p.county = 43; p.val = 1288; p.d = 422; p.r = 866;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 60; p.county = 43; p.val = 865; p.d = 363; p.r = 502;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 52; p.county = 43; p.val = 305; p.d = 277; p.r = 28;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 60; p.county = 43; p.val = 270; p.d = 104; p.r = 166;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 55; p.county = 43; p.val = 407; p.d = 307; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 49; p.county = 43; p.val = 503; p.d = 198; p.r = 305;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 54; p.county = 43; p.val = 395; p.d = 179; p.r = 216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 59; p.county = 43; p.val = 549; p.d = 456; p.r = 93;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 64; p.county = 43; p.val = 634; p.d = 538; p.r = 96;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 58; p.county = 43; p.val = 816; p.d = 457; p.r = 359;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 61; p.county = 43; p.val = 490; p.d = 156; p.r = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 55; p.county = 43; p.val = 1595; p.d = 487; p.r = 1108;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 56; p.county = 43; p.val = 1599; p.d = 758; p.r = 841;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 61; p.county = 43; p.val = 1457; p.d = 446; p.r = 1011;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 57; p.county = 43; p.val = 487; p.d = 147; p.r = 340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 10; p.county = 45; p.val = 5815; p.d = 3425; p.r = 2390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 9; p.county = 45; p.val = 4051; p.d = 1800; p.r = 2251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 13; p.county = 45; p.val = 730; p.d = 457; p.r = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 12; p.county = 45; p.val = 3116; p.d = 1617; p.r = 1499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 10; p.county = 45; p.val = 5011; p.d = 1951; p.r = 3060;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 15; p.county = 45; p.val = 1282; p.d = 496; p.r = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 10; p.county = 45; p.val = 3288; p.d = 1993; p.r = 1295;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 11; p.county = 45; p.val = 2943; p.d = 1943; p.r = 1000;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 11; p.county = 45; p.val = 5924; p.d = 3428; p.r = 2496;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 9; p.county = 45; p.val = 4756; p.d = 2155; p.r = 2601;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 11; p.county = 45; p.val = 3261; p.d = 1614; p.r = 1647;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 12; p.county = 45; p.val = 3142; p.d = 2359; p.r = 783;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 13; p.county = 45; p.val = 2508; p.d = 1457; p.r = 1051;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 13; p.county = 45; p.val = 5119; p.d = 1879; p.r = 3240;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 9; p.county = 45; p.val = 5286; p.d = 1937; p.r = 3349;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 10; p.county = 45; p.val = 3205; p.d = 1593; p.r = 1612;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 7; p.county = 45; p.val = 821; p.d = 236; p.r = 585;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 7; p.county = 45; p.val = 1477; p.d = 333; p.r = 1144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 11; p.county = 45; p.val = 2790; p.d = 1207; p.r = 1583;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 9; p.county = 45; p.val = 6589; p.d = 2458; p.r = 4131;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 12; p.county = 45; p.val = 1747; p.d = 1145; p.r = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 11; p.county = 45; p.val = 4521; p.d = 1475; p.r = 3046;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 14; p.county = 45; p.val = 509; p.d = 393; p.r = 116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 8; p.county = 45; p.val = 2272; p.d = 653; p.r = 1619;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 8; p.county = 45; p.val = 3128; p.d = 1061; p.r = 2067;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 13; p.county = 45; p.val = 2689; p.d = 1249; p.r = 1440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 12; p.county = 45; p.val = 5754; p.d = 2757; p.r = 2997;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 9; p.county = 45; p.val = 4562; p.d = 1860; p.r = 2702;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 7; p.county = 45; p.val = 1212; p.d = 275; p.r = 937;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 11; p.county = 45; p.val = 1690; p.d = 602; p.r = 1088;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 7; p.county = 45; p.val = 3177; p.d = 854; p.r = 2323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 2; p.county = 45; p.val = 1027; p.d = 284; p.r = 743;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 10; p.county = 45; p.val = 2240; p.d = 829; p.r = 1411;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 20; p.county = 45; p.val = 1168; p.d = 203; p.r = 965;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 18; p.county = 45; p.val = 1080; p.d = 197; p.r = 883;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 15; p.county = 45; p.val = 1842; p.d = 943; p.r = 899;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 16; p.county = 45; p.val = 723; p.d = 280; p.r = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 8; p.county = 45; p.val = 1635; p.d = 653; p.r = 982;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 1; p.county = 45; p.val = 1219; p.d = 288; p.r = 931;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 5; p.county = 45; p.val = 1247; p.d = 194; p.r = 1053;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 8; p.county = 45; p.val = 2542; p.d = 981; p.r = 1561;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 3; p.county = 45; p.val = 1058; p.d = 257; p.r = 801;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 15; p.county = 45; p.val = 3983; p.d = 1643; p.r = 2340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 17; p.county = 45; p.val = 632; p.d = 137; p.r = 495;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 16; p.county = 45; p.val = 1615; p.d = 719; p.r = 896;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 16; p.county = 45; p.val = 1073; p.d = 542; p.r = 531;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 12; p.county = 45; p.val = 4964; p.d = 1775; p.r = 3189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 13; p.county = 45; p.val = 1410; p.d = 1183; p.r = 227;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 14; p.county = 45; p.val = 2542; p.d = 941; p.r = 1601;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 14; p.county = 45; p.val = 1873; p.d = 796; p.r = 1077;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 15; p.county = 45; p.val = 2576; p.d = 1275; p.r = 1301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 8; p.county = 45; p.val = 2201; p.d = 959; p.r = 1242;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 8; p.county = 45; p.val = 1147; p.d = 371; p.r = 776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 11; p.county = 45; p.val = 1056; p.d = 577; p.r = 479;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 1; p.county = 45; p.val = 1494; p.d = 360; p.r = 1134;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 9; p.county = 45; p.val = 841; p.d = 326; p.r = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 6; p.county = 45; p.val = 1904; p.d = 470; p.r = 1434;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 4; p.county = 45; p.val = 1407; p.d = 178; p.r = 1229;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 14; p.county = 45; p.val = 1499; p.d = 466; p.r = 1033;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 4; p.county = 45; p.val = 1449; p.d = 273; p.r = 1176;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 7; p.county = 45; p.val = 3763; p.d = 1319; p.r = 2444;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 6; p.county = 45; p.val = 2217; p.d = 554; p.r = 1663;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 10; p.county = 45; p.val = 829; p.d = 335; p.r = 494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 15; p.county = 45; p.val = 1279; p.d = 710; p.r = 569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 16; p.county = 45; p.val = 725; p.d = 224; p.r = 501;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 6; p.county = 45; p.val = 1453; p.d = 370; p.r = 1083;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 12; p.county = 45; p.val = 2691; p.d = 1135; p.r = 1556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 15; p.county = 45; p.val = 1905; p.d = 968; p.r = 937;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 5; p.county = 45; p.val = 1615; p.d = 387; p.r = 1228;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 14; p.county = 45; p.val = 1426; p.d = 877; p.r = 549;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 7; p.county = 45; p.val = 1440; p.d = 586; p.r = 854;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 16; p.county = 45; p.val = 1280; p.d = 504; p.r = 776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 18; p.county = 45; p.val = 1085; p.d = 284; p.r = 801;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 13; p.county = 45; p.val = 2672; p.d = 992; p.r = 1680;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 32; p.county = 47; p.val = 1597; p.d = 1280; p.r = 317;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 31; p.county = 47; p.val = 2564; p.d = 1221; p.r = 1343;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 33; p.county = 47; p.val = 742; p.d = 432; p.r = 310;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 32; p.county = 47; p.val = 961; p.d = 396; p.r = 565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 27; p.county = 47; p.val = 186; p.d = 55; p.r = 131;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 35; p.county = 47; p.val = 592; p.d = 317; p.r = 275;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 32; p.county = 47; p.val = 1223; p.d = 350; p.r = 873;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 32; p.county = 47; p.val = 443; p.d = 97; p.r = 346;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 31; p.county = 47; p.val = 1524; p.d = 536; p.r = 988;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 29; p.county = 47; p.val = 707; p.d = 151; p.r = 556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 34; p.county = 47; p.val = 663; p.d = 262; p.r = 401;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 32; p.county = 47; p.val = 483; p.d = 202; p.r = 281;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 33; p.county = 47; p.val = 420; p.d = 69; p.r = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 37; p.county = 47; p.val = 362; p.d = 66; p.r = 296;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 37; p.county = 47; p.val = 499; p.d = 133; p.r = 366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 35; p.county = 47; p.val = 351; p.d = 86; p.r = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 26; p.county = 47; p.val = 740; p.d = 302; p.r = 438;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 27; p.county = 47; p.val = 117; p.d = 43; p.r = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 29; p.county = 47; p.val = 752; p.d = 187; p.r = 565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 36; p.county = 47; p.val = 147; p.d = 56; p.r = 91;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 37; p.county = 47; p.val = 102; p.d = 31; p.r = 71;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 29; p.county = 47; p.val = 538; p.d = 298; p.r = 240;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 31; p.county = 47; p.val = 917; p.d = 601; p.r = 316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 30; p.county = 47; p.val = 1082; p.d = 382; p.r = 700;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 30; p.county = 47; p.val = 617; p.d = 176; p.r = 441;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 30; p.county = 47; p.val = 598; p.d = 135; p.r = 463;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 31; p.county = 47; p.val = 751; p.d = 152; p.r = 599;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 33; p.county = 47; p.val = 412; p.d = 208; p.r = 204;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 31; p.county = 47; p.val = 843; p.d = 144; p.r = 699;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 33; p.county = 47; p.val = 485; p.d = 140; p.r = 345;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 31; p.county = 47; p.val = 446; p.d = 285; p.r = 161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 33; p.county = 47; p.val = 749; p.d = 211; p.r = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 30; p.county = 47; p.val = 500; p.d = 136; p.r = 364;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 73; p.county = 49; p.val = 332; p.d = 171; p.r = 161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 74; p.county = 49; p.val = 464; p.d = 258; p.r = 206;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 75; p.county = 49; p.val = 682; p.d = 354; p.r = 328;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 76; p.county = 49; p.val = 993; p.d = 681; p.r = 312;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 80; p.county = 49; p.val = 224; p.d = 130; p.r = 94;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 83; p.county = 49; p.val = 116; p.d = 103; p.r = 13;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 80; p.county = 49; p.val = 899; p.d = 668; p.r = 231;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 79; p.county = 49; p.val = 445; p.d = 161; p.r = 284;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 81; p.county = 49; p.val = 235; p.d = 160; p.r = 75;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 82; p.county = 49; p.val = 215; p.d = 194; p.r = 21;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 81; p.county = 49; p.val = 648; p.d = 453; p.r = 195;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 79; p.county = 49; p.val = 64; p.d = 10; p.r = 54;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 71; p.county = 49; p.val = 48; p.d = 26; p.r = 22;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 77; p.county = 49; p.val = 155; p.d = 32; p.r = 123;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 73; p.county = 49; p.val = 285; p.d = 126; p.r = 159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 77; p.county = 49; p.val = 435; p.d = 274; p.r = 161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 76; p.county = 49; p.val = 144; p.d = 47; p.r = 97;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 75; p.county = 49; p.val = 225; p.d = 203; p.r = 22;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 40; p.county = 51; p.val = 845; p.d = 234; p.r = 611;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 38; p.county = 51; p.val = 350; p.d = 61; p.r = 289;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 45; p.county = 51; p.val = 1416; p.d = 529; p.r = 887;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 45; p.county = 51; p.val = 789; p.d = 144; p.r = 645;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 44; p.county = 51; p.val = 418; p.d = 71; p.r = 347;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 39; p.county = 51; p.val = 618; p.d = 128; p.r = 490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 43; p.county = 51; p.val = 614; p.d = 206; p.r = 408;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 42; p.county = 51; p.val = 878; p.d = 291; p.r = 587;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 42; p.county = 51; p.val = 737; p.d = 266; p.r = 471;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 44; p.county = 51; p.val = 2080; p.d = 1228; p.r = 852;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 49; p.county = 51; p.val = 3220; p.d = 1271; p.r = 1949;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 41; p.county = 51; p.val = 809; p.d = 234; p.r = 575;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 40; p.county = 51; p.val = 291; p.d = 45; p.r = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 38; p.county = 51; p.val = 857; p.d = 173; p.r = 684;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 37; p.county = 51; p.val = 650; p.d = 243; p.r = 407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 39; p.county = 51; p.val = 230; p.d = 48; p.r = 182;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 39; p.county = 51; p.val = 464; p.d = 65; p.r = 399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 36; p.county = 51; p.val = 94; p.d = 27; p.r = 67;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 41; p.county = 51; p.val = 590; p.d = 75; p.r = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 42; p.county = 51; p.val = 259; p.d = 25; p.r = 234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 37; p.county = 51; p.val = 219; p.d = 27; p.r = 192;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 43; p.county = 51; p.val = 863; p.d = 179; p.r = 684;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 37; p.county = 51; p.val = 391; p.d = 28; p.r = 363;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 41; p.county = 51; p.val = 1676; p.d = 621; p.r = 1055;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 42; p.county = 51; p.val = 898; p.d = 288; p.r = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 42; p.county = 51; p.val = 2786; p.d = 827; p.r = 1959;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 51; p.county = 51; p.val = 5160; p.d = 1793; p.r = 3367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 46; p.county = 51; p.val = 2481; p.d = 889; p.r = 1592;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 45; p.county = 51; p.val = 983; p.d = 374; p.r = 609;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 44; p.county = 51; p.val = 965; p.d = 256; p.r = 709;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 43; p.county = 51; p.val = 1247; p.d = 393; p.r = 854;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 45; p.county = 51; p.val = 2047; p.d = 662; p.r = 1385;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 45; p.county = 51; p.val = 1354; p.d = 535; p.r = 819;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 43; p.county = 51; p.val = 724; p.d = 165; p.r = 559;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 48; p.county = 51; p.val = 199; p.d = 87; p.r = 112;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 48; p.county = 51; p.val = 1038; p.d = 623; p.r = 415;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 48; p.county = 51; p.val = 1110; p.d = 656; p.r = 454;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 50; p.county = 51; p.val = 2691; p.d = 855; p.r = 1836;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 43; p.county = 51; p.val = 720; p.d = 331; p.r = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 46; p.county = 51; p.val = 2271; p.d = 761; p.r = 1510;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 46; p.county = 51; p.val = 1143; p.d = 338; p.r = 805;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 36; p.county = 51; p.val = 1296; p.d = 472; p.r = 824;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 40; p.county = 51; p.val = 1199; p.d = 356; p.r = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 36; p.county = 51; p.val = 96; p.d = 17; p.r = 79;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 35; p.county = 51; p.val = 361; p.d = 57; p.r = 304;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 41; p.county = 51; p.val = 882; p.d = 436; p.r = 446;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 46; p.county = 51; p.val = 1060; p.d = 455; p.r = 605;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 34; p.county = 51; p.val = 465; p.d = 131; p.r = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 32; p.county = 51; p.val = 406; p.d = 115; p.r = 291;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 47; p.county = 51; p.val = 1846; p.d = 744; p.r = 1102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 47; p.county = 51; p.val = 1637; p.d = 586; p.r = 1051;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 46; p.county = 51; p.val = 2576; p.d = 965; p.r = 1611;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 49; p.county = 51; p.val = 3021; p.d = 1073; p.r = 1948;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 52; p.county = 51; p.val = 2506; p.d = 705; p.r = 1801;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 51; p.county = 51; p.val = 2078; p.d = 726; p.r = 1352;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 46; p.county = 51; p.val = 309; p.d = 95; p.r = 214;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 49; p.county = 51; p.val = 1710; p.d = 644; p.r = 1066;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 37; p.county = 51; p.val = 394; p.d = 147; p.r = 247;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 48; p.county = 51; p.val = 870; p.d = 336; p.r = 534;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 47; p.county = 51; p.val = 1928; p.d = 676; p.r = 1252;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 42; p.county = 51; p.val = 924; p.d = 297; p.r = 627;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 43; p.county = 51; p.val = 1420; p.d = 596; p.r = 824;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 43; p.county = 51; p.val = 1414; p.d = 588; p.r = 826;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 98; p.y = 44; p.county = 51; p.val = 1843; p.d = 469; p.r = 1374;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 95; p.y = 47; p.county = 51; p.val = 886; p.d = 300; p.r = 586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 46; p.county = 51; p.val = 2977; p.d = 1035; p.r = 1942;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 47; p.county = 51; p.val = 251; p.d = 35; p.r = 216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 35; p.county = 51; p.val = 129; p.d = 22; p.r = 107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 39; p.county = 51; p.val = 405; p.d = 45; p.r = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 49; p.county = 51; p.val = 386; p.d = 358; p.r = 28;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 43; p.county = 51; p.val = 578; p.d = 326; p.r = 252;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 41; p.county = 51; p.val = 497; p.d = 224; p.r = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 45; p.county = 51; p.val = 426; p.d = 125; p.r = 301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 44; p.county = 51; p.val = 1149; p.d = 296; p.r = 853;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 49; p.county = 51; p.val = 668; p.d = 278; p.r = 390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 41; p.county = 51; p.val = 699; p.d = 145; p.r = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 48; p.county = 51; p.val = 3147; p.d = 1160; p.r = 1987;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 30; p.county = 51; p.val = 201; p.d = 44; p.r = 157;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 50; p.county = 51; p.val = 4085; p.d = 1366; p.r = 2719;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 38; p.county = 51; p.val = 536; p.d = 256; p.r = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 88; p.y = 34; p.county = 51; p.val = 164; p.d = 12; p.r = 152;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 94; p.y = 44; p.county = 51; p.val = 830; p.d = 229; p.r = 601;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 46; p.county = 51; p.val = 767; p.d = 259; p.r = 508;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 43; p.county = 51; p.val = 912; p.d = 593; p.r = 319;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 44; p.county = 51; p.val = 350; p.d = 185; p.r = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 93; p.y = 36; p.county = 51; p.val = 411; p.d = 294; p.r = 117;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 40; p.county = 51; p.val = 338; p.d = 50; p.r = 288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 44; p.county = 51; p.val = 1396; p.d = 498; p.r = 898;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 99; p.y = 41; p.county = 51; p.val = 695; p.d = 251; p.r = 444;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 97; p.y = 42; p.county = 51; p.val = 1043; p.d = 392; p.r = 651;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 49; p.county = 51; p.val = 603; p.d = 270; p.r = 333;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 50; p.county = 51; p.val = 948; p.d = 383; p.r = 565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 90; p.y = 48; p.county = 51; p.val = 718; p.d = 195; p.r = 523;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 91; p.y = 48; p.county = 51; p.val = 1634; p.d = 534; p.r = 1100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 96; p.y = 44; p.county = 51; p.val = 1482; p.d = 415; p.r = 1067;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 92; p.y = 51; p.county = 51; p.val = 1880; p.d = 644; p.r = 1236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 84; p.county = 53; p.val = 281; p.d = 205; p.r = 76;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 84; p.county = 53; p.val = 345; p.d = 202; p.r = 143;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 89; p.county = 53; p.val = 635; p.d = 246; p.r = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 87; p.county = 53; p.val = 1045; p.d = 714; p.r = 331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 81; p.county = 53; p.val = 454; p.d = 133; p.r = 321;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 93; p.county = 53; p.val = 805; p.d = 428; p.r = 377;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 93; p.county = 53; p.val = 422; p.d = 284; p.r = 138;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 99; p.county = 53; p.val = 972; p.d = 673; p.r = 299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 91; p.county = 53; p.val = 666; p.d = 318; p.r = 348;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 85; p.county = 53; p.val = 395; p.d = 358; p.r = 37;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 87; p.county = 53; p.val = 471; p.d = 170; p.r = 301;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 89; p.county = 53; p.val = 475; p.d = 266; p.r = 209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 89; p.county = 53; p.val = 374; p.d = 238; p.r = 136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 86; p.county = 53; p.val = 386; p.d = 139; p.r = 247;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 93; p.county = 53; p.val = 1622; p.d = 628; p.r = 994;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 29; p.county = 55; p.val = 595; p.d = 206; p.r = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 30; p.county = 55; p.val = 458; p.d = 170; p.r = 288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 24; p.county = 55; p.val = 744; p.d = 327; p.r = 417;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 20; p.county = 55; p.val = 549; p.d = 120; p.r = 429;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 31; p.county = 55; p.val = 799; p.d = 469; p.r = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 30; p.county = 55; p.val = 1424; p.d = 705; p.r = 719;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 29; p.county = 55; p.val = 492; p.d = 216; p.r = 276;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 27; p.county = 55; p.val = 714; p.d = 256; p.r = 458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 32; p.county = 55; p.val = 802; p.d = 396; p.r = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 32; p.county = 55; p.val = 2029; p.d = 914; p.r = 1115;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 32; p.county = 55; p.val = 750; p.d = 286; p.r = 464;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 29; p.county = 55; p.val = 334; p.d = 220; p.r = 114;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 34; p.county = 55; p.val = 961; p.d = 350; p.r = 611;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 33; p.county = 55; p.val = 1335; p.d = 516; p.r = 819;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 33; p.county = 55; p.val = 718; p.d = 334; p.r = 384;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 32; p.county = 55; p.val = 640; p.d = 338; p.r = 302;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 23; p.county = 55; p.val = 209; p.d = 42; p.r = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 23; p.county = 55; p.val = 364; p.d = 99; p.r = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 30; p.county = 55; p.val = 588; p.d = 229; p.r = 359;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 31; p.county = 55; p.val = 931; p.d = 347; p.r = 584;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 31; p.county = 55; p.val = 936; p.d = 275; p.r = 661;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 32; p.county = 55; p.val = 792; p.d = 241; p.r = 551;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 28; p.county = 55; p.val = 782; p.d = 350; p.r = 432;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 28; p.county = 55; p.val = 1160; p.d = 288; p.r = 872;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 30; p.county = 55; p.val = 423; p.d = 361; p.r = 62;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 29; p.county = 55; p.val = 786; p.d = 241; p.r = 545;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 25; p.county = 55; p.val = 507; p.d = 227; p.r = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 28; p.county = 55; p.val = 951; p.d = 464; p.r = 487;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 24; p.county = 55; p.val = 838; p.d = 270; p.r = 568;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 30; p.county = 55; p.val = 858; p.d = 331; p.r = 527;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 15; p.county = 57; p.val = 482; p.d = 132; p.r = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 8; p.county = 57; p.val = 3694; p.d = 1412; p.r = 2282;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 14; p.county = 57; p.val = 471; p.d = 104; p.r = 367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 20; p.county = 57; p.val = 295; p.d = 134; p.r = 161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 17; p.county = 57; p.val = 957; p.d = 425; p.r = 532;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 20; p.county = 57; p.val = 683; p.d = 255; p.r = 428;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 15; p.county = 57; p.val = 765; p.d = 312; p.r = 453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 20; p.county = 57; p.val = 817; p.d = 332; p.r = 485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 21; p.county = 57; p.val = 835; p.d = 200; p.r = 635;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 14; p.county = 57; p.val = 1099; p.d = 480; p.r = 619;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 16; p.county = 57; p.val = 1101; p.d = 485; p.r = 616;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 15; p.county = 57; p.val = 517; p.d = 442; p.r = 75;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 15; p.county = 57; p.val = 724; p.d = 401; p.r = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 15; p.county = 57; p.val = 1377; p.d = 691; p.r = 686;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 14; p.county = 57; p.val = 980; p.d = 220; p.r = 760;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 12; p.county = 57; p.val = 538; p.d = 203; p.r = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 16; p.county = 57; p.val = 848; p.d = 352; p.r = 496;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 14; p.county = 57; p.val = 654; p.d = 422; p.r = 232;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 17; p.county = 57; p.val = 380; p.d = 68; p.r = 312;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 18; p.county = 57; p.val = 674; p.d = 252; p.r = 422;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 5; p.county = 57; p.val = 1732; p.d = 813; p.r = 919;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 16; p.county = 57; p.val = 566; p.d = 122; p.r = 444;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 14; p.county = 57; p.val = 440; p.d = 251; p.r = 189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 13; p.county = 57; p.val = 625; p.d = 141; p.r = 484;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 12; p.county = 57; p.val = 715; p.d = 207; p.r = 508;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 11; p.county = 57; p.val = 555; p.d = 200; p.r = 355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 6; p.county = 57; p.val = 3111; p.d = 1146; p.r = 1965;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 7; p.county = 57; p.val = 1100; p.d = 499; p.r = 601;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 6; p.county = 57; p.val = 1839; p.d = 775; p.r = 1064;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 9; p.county = 57; p.val = 666; p.d = 226; p.r = 440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 4; p.county = 57; p.val = 1815; p.d = 754; p.r = 1061;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 9; p.county = 57; p.val = 2038; p.d = 890; p.r = 1148;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 7; p.county = 57; p.val = 1378; p.d = 487; p.r = 891;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 22; p.county = 59; p.val = 1233; p.d = 908; p.r = 325;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 22; p.county = 59; p.val = 1342; p.d = 517; p.r = 825;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 23; p.county = 59; p.val = 518; p.d = 210; p.r = 308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 22; p.county = 59; p.val = 792; p.d = 291; p.r = 501;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 21; p.county = 59; p.val = 615; p.d = 186; p.r = 429;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 20; p.county = 59; p.val = 494; p.d = 171; p.r = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 23; p.county = 59; p.val = 621; p.d = 175; p.r = 446;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 23; p.county = 59; p.val = 725; p.d = 330; p.r = 395;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 25; p.county = 59; p.val = 853; p.d = 243; p.r = 610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 23; p.county = 59; p.val = 540; p.d = 355; p.r = 185;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 26; p.county = 59; p.val = 343; p.d = 125; p.r = 218;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 25; p.county = 59; p.val = 832; p.d = 250; p.r = 582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 16; p.county = 59; p.val = 799; p.d = 321; p.r = 478;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 17; p.county = 59; p.val = 400; p.d = 138; p.r = 262;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 19; p.county = 59; p.val = 684; p.d = 291; p.r = 393;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 19; p.county = 59; p.val = 913; p.d = 198; p.r = 715;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 15; p.county = 59; p.val = 1109; p.d = 402; p.r = 707;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 16; p.county = 59; p.val = 578; p.d = 116; p.r = 462;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 18; p.county = 59; p.val = 506; p.d = 202; p.r = 304;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 20; p.county = 59; p.val = 642; p.d = 130; p.r = 512;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 29; p.county = 59; p.val = 912; p.d = 360; p.r = 552;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 27; p.county = 59; p.val = 889; p.d = 322; p.r = 567;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 24; p.county = 59; p.val = 361; p.d = 68; p.r = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 25; p.county = 59; p.val = 290; p.d = 62; p.r = 228;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 27; p.county = 59; p.val = 515; p.d = 73; p.r = 442;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 21; p.county = 59; p.val = 1171; p.d = 223; p.r = 948;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 22; p.county = 59; p.val = 145; p.d = 14; p.r = 131;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 23; p.county = 59; p.val = 262; p.d = 28; p.r = 234;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 22; p.county = 59; p.val = 579; p.d = 412; p.r = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 21; p.county = 59; p.val = 651; p.d = 294; p.r = 357;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 28; p.county = 61; p.val = 265; p.d = 55; p.r = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 35; p.county = 61; p.val = 353; p.d = 112; p.r = 241;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 32; p.county = 61; p.val = 355; p.d = 305; p.r = 50;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 31; p.county = 61; p.val = 386; p.d = 323; p.r = 63;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 30; p.county = 61; p.val = 507; p.d = 417; p.r = 90;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 30; p.county = 61; p.val = 180; p.d = 78; p.r = 102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 31; p.county = 61; p.val = 277; p.d = 188; p.r = 89;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 35; p.county = 61; p.val = 298; p.d = 269; p.r = 29;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 32; p.county = 61; p.val = 188; p.d = 96; p.r = 92;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 31; p.county = 61; p.val = 311; p.d = 132; p.r = 179;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 36; p.county = 61; p.val = 422; p.d = 356; p.r = 66;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 33; p.county = 61; p.val = 322; p.d = 245; p.r = 77;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 33; p.county = 61; p.val = 162; p.d = 134; p.r = 28;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 33; p.county = 61; p.val = 205; p.d = 105; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 29; p.county = 61; p.val = 279; p.d = 152; p.r = 127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 38; p.county = 61; p.val = 236; p.d = 179; p.r = 57;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 34; p.county = 61; p.val = 387; p.d = 279; p.r = 108;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 36; p.county = 61; p.val = 494; p.d = 352; p.r = 142;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 29; p.county = 61; p.val = 111; p.d = 38; p.r = 73;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 27; p.county = 61; p.val = 82; p.d = 39; p.r = 43;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 35; p.county = 61; p.val = 107; p.d = 86; p.r = 21;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 31; p.county = 61; p.val = 437; p.d = 250; p.r = 187;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 41; p.county = 63; p.val = 1059; p.d = 549; p.r = 510;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 43; p.county = 63; p.val = 737; p.d = 177; p.r = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 37; p.county = 63; p.val = 1330; p.d = 335; p.r = 995;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 38; p.county = 63; p.val = 1286; p.d = 260; p.r = 1026;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 41; p.county = 63; p.val = 1320; p.d = 513; p.r = 807;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 39; p.county = 63; p.val = 2564; p.d = 1265; p.r = 1299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 38; p.county = 63; p.val = 4486; p.d = 1457; p.r = 3029;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 40; p.county = 63; p.val = 1905; p.d = 694; p.r = 1211;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 37; p.county = 63; p.val = 1467; p.d = 296; p.r = 1171;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 42; p.county = 63; p.val = 1128; p.d = 270; p.r = 858;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 63; p.val = 1740; p.d = 612; p.r = 1128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 48; p.county = 63; p.val = 430; p.d = 112; p.r = 318;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 46; p.county = 63; p.val = 535; p.d = 200; p.r = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 38; p.county = 63; p.val = 4588; p.d = 1978; p.r = 2610;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 40; p.county = 63; p.val = 1116; p.d = 219; p.r = 897;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 39; p.county = 63; p.val = 1347; p.d = 299; p.r = 1048;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 47; p.county = 63; p.val = 691; p.d = 337; p.r = 354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 44; p.county = 63; p.val = 670; p.d = 149; p.r = 521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 43; p.county = 63; p.val = 976; p.d = 185; p.r = 791;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 41; p.county = 63; p.val = 752; p.d = 188; p.r = 564;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 46; p.county = 63; p.val = 665; p.d = 166; p.r = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 45; p.county = 63; p.val = 843; p.d = 280; p.r = 563;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 36; p.county = 63; p.val = 5725; p.d = 2958; p.r = 2767;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 41; p.county = 63; p.val = 1038; p.d = 290; p.r = 748;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 41; p.county = 63; p.val = 1581; p.d = 511; p.r = 1070;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 38; p.county = 63; p.val = 1604; p.d = 603; p.r = 1001;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 43; p.county = 63; p.val = 497; p.d = 162; p.r = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 40; p.county = 63; p.val = 1601; p.d = 1173; p.r = 428;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 45; p.county = 63; p.val = 652; p.d = 122; p.r = 530;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 33; p.county = 63; p.val = 1646; p.d = 531; p.r = 1115;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 40; p.county = 63; p.val = 2048; p.d = 867; p.r = 1181;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 38; p.county = 63; p.val = 3034; p.d = 1094; p.r = 1940;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 39; p.county = 63; p.val = 938; p.d = 422; p.r = 516;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 42; p.county = 63; p.val = 1459; p.d = 1128; p.r = 331;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 42; p.county = 63; p.val = 1965; p.d = 591; p.r = 1374;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 38; p.county = 63; p.val = 2834; p.d = 1826; p.r = 1008;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 41; p.county = 63; p.val = 1402; p.d = 462; p.r = 940;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 35; p.county = 63; p.val = 2017; p.d = 512; p.r = 1505;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 40; p.county = 63; p.val = 2193; p.d = 818; p.r = 1375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 37; p.county = 63; p.val = 1565; p.d = 395; p.r = 1170;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 39; p.county = 63; p.val = 1586; p.d = 641; p.r = 945;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 40; p.county = 63; p.val = 400; p.d = 157; p.r = 243;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 44; p.county = 63; p.val = 729; p.d = 259; p.r = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 43; p.county = 63; p.val = 661; p.d = 226; p.r = 435;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 43; p.county = 63; p.val = 784; p.d = 169; p.r = 615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 47; p.county = 63; p.val = 693; p.d = 287; p.r = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 46; p.county = 63; p.val = 705; p.d = 183; p.r = 522;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 34; p.county = 63; p.val = 1024; p.d = 180; p.r = 844;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 41; p.county = 63; p.val = 897; p.d = 301; p.r = 596;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 42; p.county = 63; p.val = 1714; p.d = 572; p.r = 1142;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 42; p.county = 63; p.val = 1311; p.d = 688; p.r = 623;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 39; p.county = 63; p.val = 2244; p.d = 778; p.r = 1466;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 37; p.county = 63; p.val = 3444; p.d = 2305; p.r = 1139;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 44; p.county = 63; p.val = 675; p.d = 145; p.r = 530;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 35; p.county = 63; p.val = 4050; p.d = 2190; p.r = 1860;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 39; p.county = 63; p.val = 800; p.d = 239; p.r = 561;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 36; p.county = 63; p.val = 2085; p.d = 958; p.r = 1127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 36; p.county = 63; p.val = 1443; p.d = 430; p.r = 1013;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 39; p.county = 63; p.val = 4101; p.d = 1472; p.r = 2629;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 40; p.county = 63; p.val = 1682; p.d = 547; p.r = 1135;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 37; p.county = 63; p.val = 1528; p.d = 550; p.r = 978;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 35; p.county = 63; p.val = 1375; p.d = 342; p.r = 1033;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 35; p.county = 63; p.val = 1777; p.d = 497; p.r = 1280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 37; p.county = 63; p.val = 808; p.d = 236; p.r = 572;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 38; p.county = 63; p.val = 1644; p.d = 537; p.r = 1107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 38; p.county = 65; p.val = 207; p.d = 174; p.r = 33;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 41; p.county = 65; p.val = 339; p.d = 95; p.r = 244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 41; p.county = 65; p.val = 1114; p.d = 255; p.r = 859;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 38; p.county = 65; p.val = 124; p.d = 66; p.r = 58;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 39; p.county = 65; p.val = 606; p.d = 400; p.r = 206;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 40; p.county = 65; p.val = 280; p.d = 216; p.r = 64;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 42; p.county = 65; p.val = 483; p.d = 347; p.r = 136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 43; p.county = 65; p.val = 518; p.d = 306; p.r = 212;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 45; p.county = 65; p.val = 150; p.d = 24; p.r = 126;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 47; p.county = 65; p.val = 234; p.d = 24; p.r = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 49; p.county = 65; p.val = 375; p.d = 196; p.r = 179;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 43; p.county = 67; p.val = 782; p.d = 550; p.r = 232;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 38; p.county = 67; p.val = 203; p.d = 155; p.r = 48;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 36; p.county = 67; p.val = 685; p.d = 476; p.r = 209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 35; p.county = 67; p.val = 397; p.d = 290; p.r = 107;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 32; p.county = 67; p.val = 748; p.d = 367; p.r = 381;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 31; p.county = 67; p.val = 722; p.d = 388; p.r = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 33; p.county = 67; p.val = 1209; p.d = 916; p.r = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 33; p.county = 67; p.val = 636; p.d = 299; p.r = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 30; p.county = 67; p.val = 144; p.d = 118; p.r = 26;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 29; p.county = 67; p.val = 511; p.d = 339; p.r = 172;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 84; p.y = 30; p.county = 67; p.val = 337; p.d = 226; p.r = 111;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 31; p.county = 67; p.val = 687; p.d = 489; p.r = 198;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 33; p.county = 67; p.val = 765; p.d = 452; p.r = 313;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 31; p.county = 67; p.val = 887; p.d = 555; p.r = 332;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 86; p.y = 33; p.county = 67; p.val = 707; p.d = 214; p.r = 493;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 87; p.y = 30; p.county = 67; p.val = 390; p.d = 180; p.r = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 32; p.county = 67; p.val = 603; p.d = 436; p.r = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 15; p.county = 69; p.val = 285; p.d = 152; p.r = 133;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 22; p.county = 69; p.val = 192; p.d = 98; p.r = 94;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 14; p.county = 69; p.val = 447; p.d = 256; p.r = 191;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 25; p.county = 69; p.val = 208; p.d = 90; p.r = 118;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 21; p.county = 69; p.val = 563; p.d = 305; p.r = 258;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 17; p.county = 69; p.val = 249; p.d = 148; p.r = 101;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 13; p.county = 69; p.val = 759; p.d = 393; p.r = 366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 15; p.county = 69; p.val = 554; p.d = 359; p.r = 195;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 20; p.county = 69; p.val = 816; p.d = 569; p.r = 247;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 19; p.county = 69; p.val = 610; p.d = 412; p.r = 198;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 19; p.county = 69; p.val = 650; p.d = 504; p.r = 146;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 18; p.county = 69; p.val = 336; p.d = 311; p.r = 25;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 17; p.county = 69; p.val = 1108; p.d = 614; p.r = 494;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 16; p.county = 69; p.val = 403; p.d = 112; p.r = 291;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 17; p.county = 69; p.val = 580; p.d = 271; p.r = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 29; p.county = 71; p.val = 1745; p.d = 1190; p.r = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 29; p.county = 71; p.val = 936; p.d = 499; p.r = 437;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 27; p.county = 71; p.val = 318; p.d = 118; p.r = 200;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 28; p.county = 71; p.val = 170; p.d = 50; p.r = 120;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 31; p.county = 71; p.val = 397; p.d = 146; p.r = 251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 32; p.county = 71; p.val = 521; p.d = 202; p.r = 319;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 26; p.county = 71; p.val = 266; p.d = 78; p.r = 188;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 30; p.county = 71; p.val = 277; p.d = 99; p.r = 178;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 27; p.county = 71; p.val = 623; p.d = 353; p.r = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 27; p.county = 71; p.val = 610; p.d = 220; p.r = 390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 34; p.county = 71; p.val = 832; p.d = 200; p.r = 632;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 34; p.county = 71; p.val = 1057; p.d = 264; p.r = 793;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 31; p.county = 71; p.val = 843; p.d = 251; p.r = 592;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 23; p.county = 71; p.val = 51; p.d = 38; p.r = 13;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 28; p.county = 71; p.val = 321; p.d = 259; p.r = 62;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 31; p.county = 71; p.val = 92; p.d = 35; p.r = 57;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 30; p.county = 71; p.val = 351; p.d = 112; p.r = 239;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 31; p.county = 71; p.val = 894; p.d = 402; p.r = 492;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 31; p.county = 71; p.val = 415; p.d = 166; p.r = 249;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 33; p.county = 71; p.val = 501; p.d = 100; p.r = 401;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 28; p.county = 71; p.val = 590; p.d = 235; p.r = 355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 33; p.county = 71; p.val = 329; p.d = 59; p.r = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 22; p.county = 71; p.val = 445; p.d = 149; p.r = 296;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 24; p.county = 71; p.val = 434; p.d = 149; p.r = 285;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 15; p.county = 73; p.val = 136; p.d = 49; p.r = 87;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 20; p.county = 73; p.val = 554; p.d = 103; p.r = 451;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 15; p.county = 73; p.val = 1499; p.d = 662; p.r = 837;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 22; p.county = 73; p.val = 637; p.d = 109; p.r = 528;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 18; p.county = 73; p.val = 1107; p.d = 317; p.r = 790;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 15; p.county = 73; p.val = 240; p.d = 21; p.r = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 12; p.county = 73; p.val = 1076; p.d = 236; p.r = 840;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 13; p.county = 73; p.val = 261; p.d = 88; p.r = 173;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 9; p.county = 73; p.val = 630; p.d = 152; p.r = 478;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 17; p.county = 73; p.val = 379; p.d = 56; p.r = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 15; p.county = 73; p.val = 1008; p.d = 280; p.r = 728;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 19; p.county = 73; p.val = 776; p.d = 168; p.r = 608;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 18; p.county = 73; p.val = 515; p.d = 92; p.r = 423;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 16; p.county = 73; p.val = 666; p.d = 159; p.r = 507;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 7; p.county = 73; p.val = 1171; p.d = 239; p.r = 932;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 11; p.county = 73; p.val = 1437; p.d = 457; p.r = 980;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 13; p.county = 73; p.val = 1296; p.d = 308; p.r = 988;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 17; p.county = 73; p.val = 711; p.d = 313; p.r = 398;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 20; p.county = 73; p.val = 923; p.d = 247; p.r = 676;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 8; p.county = 73; p.val = 812; p.d = 172; p.r = 640;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 19; p.county = 73; p.val = 714; p.d = 165; p.r = 549;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 16; p.county = 73; p.val = 3190; p.d = 1536; p.r = 1654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 12; p.county = 73; p.val = 1657; p.d = 415; p.r = 1242;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 13; p.county = 73; p.val = 1122; p.d = 285; p.r = 837;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 18; p.county = 73; p.val = 1493; p.d = 307; p.r = 1186;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 15; p.county = 73; p.val = 792; p.d = 151; p.r = 641;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 14; p.county = 73; p.val = 996; p.d = 237; p.r = 759;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 15; p.county = 73; p.val = 997; p.d = 381; p.r = 616;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 17; p.county = 73; p.val = 749; p.d = 240; p.r = 509;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 55; p.county = 75; p.val = 540; p.d = 415; p.r = 125;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 55; p.county = 75; p.val = 1277; p.d = 1241; p.r = 36;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 54; p.county = 75; p.val = 1097; p.d = 1072; p.r = 25;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 54; p.county = 75; p.val = 2711; p.d = 1816; p.r = 895;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 56; p.county = 75; p.val = 677; p.d = 630; p.r = 47;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 56; p.county = 75; p.val = 228; p.d = 161; p.r = 67;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 55; p.county = 75; p.val = 410; p.d = 264; p.r = 146;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 61; p.county = 75; p.val = 433; p.d = 255; p.r = 178;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 56; p.county = 75; p.val = 602; p.d = 493; p.r = 109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 53; p.county = 75; p.val = 468; p.d = 301; p.r = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 53; p.county = 75; p.val = 1407; p.d = 1268; p.r = 139;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 57; p.county = 75; p.val = 348; p.d = 253; p.r = 95;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 59; p.county = 75; p.val = 685; p.d = 493; p.r = 192;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 62; p.county = 75; p.val = 587; p.d = 292; p.r = 295;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 64; p.county = 75; p.val = 286; p.d = 123; p.r = 163;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 58; p.county = 75; p.val = 383; p.d = 180; p.r = 203;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 56; p.county = 75; p.val = 789; p.d = 418; p.r = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 59; p.county = 75; p.val = 569; p.d = 163; p.r = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 55; p.county = 75; p.val = 400; p.d = 319; p.r = 81;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 57; p.county = 75; p.val = 819; p.d = 409; p.r = 410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 61; p.county = 75; p.val = 895; p.d = 768; p.r = 127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 59; p.county = 75; p.val = 1055; p.d = 887; p.r = 168;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 55; p.county = 75; p.val = 310; p.d = 88; p.r = 222;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 60; p.county = 75; p.val = 1025; p.d = 655; p.r = 370;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 52; p.county = 75; p.val = 935; p.d = 696; p.r = 239;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 53; p.county = 75; p.val = 1205; p.d = 941; p.r = 264;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 53; p.county = 75; p.val = 556; p.d = 219; p.r = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 50; p.county = 75; p.val = 750; p.d = 395; p.r = 355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 51; p.county = 75; p.val = 722; p.d = 435; p.r = 287;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 56; p.county = 75; p.val = 780; p.d = 562; p.r = 218;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 55; p.county = 75; p.val = 682; p.d = 376; p.r = 306;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 57; p.county = 75; p.val = 658; p.d = 493; p.r = 165;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 54; p.county = 75; p.val = 805; p.d = 374; p.r = 431;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 56; p.county = 75; p.val = 656; p.d = 624; p.r = 32;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 54; p.county = 75; p.val = 661; p.d = 378; p.r = 283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 57; p.county = 75; p.val = 954; p.d = 743; p.r = 211;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 55; p.county = 75; p.val = 571; p.d = 521; p.r = 50;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 52; p.county = 75; p.val = 526; p.d = 369; p.r = 157;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 53; p.county = 75; p.val = 614; p.d = 393; p.r = 221;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 57; p.county = 75; p.val = 704; p.d = 454; p.r = 250;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 53; p.county = 75; p.val = 507; p.d = 255; p.r = 252;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 59; p.county = 75; p.val = 337; p.d = 210; p.r = 127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 17; p.county = 77; p.val = 725; p.d = 421; p.r = 304;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 16; p.county = 77; p.val = 376; p.d = 204; p.r = 172;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 16; p.county = 77; p.val = 1088; p.d = 659; p.r = 429;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 15; p.county = 77; p.val = 1543; p.d = 836; p.r = 707;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 16; p.county = 77; p.val = 1121; p.d = 569; p.r = 552;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 15; p.county = 77; p.val = 844; p.d = 431; p.r = 413;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 14; p.county = 77; p.val = 592; p.d = 188; p.r = 404;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 13; p.county = 77; p.val = 752; p.d = 237; p.r = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 13; p.county = 77; p.val = 648; p.d = 123; p.r = 525;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 10; p.county = 77; p.val = 541; p.d = 166; p.r = 375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 12; p.county = 77; p.val = 827; p.d = 126; p.r = 701;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 10; p.county = 77; p.val = 754; p.d = 157; p.r = 597;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 9; p.county = 77; p.val = 720; p.d = 107; p.r = 613;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 10; p.county = 77; p.val = 689; p.d = 146; p.r = 543;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 11; p.county = 77; p.val = 833; p.d = 185; p.r = 648;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 11; p.county = 77; p.val = 494; p.d = 53; p.r = 441;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 5; p.county = 77; p.val = 871; p.d = 193; p.r = 678;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 5; p.county = 77; p.val = 908; p.d = 215; p.r = 693;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 7; p.county = 77; p.val = 874; p.d = 156; p.r = 718;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 8; p.county = 77; p.val = 1336; p.d = 200; p.r = 1136;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 10; p.county = 77; p.val = 686; p.d = 86; p.r = 600;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 9; p.county = 77; p.val = 625; p.d = 74; p.r = 551;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 12; p.county = 77; p.val = 660; p.d = 124; p.r = 536;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 13; p.county = 77; p.val = 706; p.d = 124; p.r = 582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 12; p.county = 77; p.val = 1126; p.d = 217; p.r = 909;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 14; p.county = 77; p.val = 708; p.d = 127; p.r = 581;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 12; p.county = 77; p.val = 1765; p.d = 487; p.r = 1278;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 11; p.county = 77; p.val = 1894; p.d = 595; p.r = 1299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 12; p.county = 77; p.val = 3528; p.d = 896; p.r = 2632;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 10; p.county = 77; p.val = 1316; p.d = 227; p.r = 1089;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 10; p.county = 77; p.val = 1340; p.d = 325; p.r = 1015;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 11; p.county = 77; p.val = 1331; p.d = 330; p.r = 1001;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 11; p.county = 77; p.val = 639; p.d = 83; p.r = 556;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 12; p.county = 77; p.val = 1202; p.d = 313; p.r = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 11; p.county = 77; p.val = 1193; p.d = 361; p.r = 832;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 10; p.county = 77; p.val = 1141; p.d = 298; p.r = 843;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 8; p.county = 77; p.val = 568; p.d = 111; p.r = 457;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 8; p.county = 77; p.val = 424; p.d = 64; p.r = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 6; p.county = 77; p.val = 627; p.d = 94; p.r = 533;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 13; p.county = 77; p.val = 517; p.d = 85; p.r = 432;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 38; p.county = 79; p.val = 5874; p.d = 4513; p.r = 1361;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 37; p.county = 79; p.val = 4920; p.d = 4177; p.r = 743;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 37; p.county = 79; p.val = 5544; p.d = 4931; p.r = 613;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 37; p.county = 79; p.val = 5993; p.d = 3447; p.r = 2546;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 35; p.county = 79; p.val = 3777; p.d = 2535; p.r = 1242;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 37; p.county = 79; p.val = 716; p.d = 533; p.r = 183;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 36; p.county = 79; p.val = 2505; p.d = 2057; p.r = 448;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 34; p.county = 79; p.val = 1822; p.d = 1076; p.r = 746;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 33; p.county = 79; p.val = 1827; p.d = 790; p.r = 1037;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 34; p.county = 79; p.val = 3068; p.d = 1040; p.r = 2028;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 39; p.county = 79; p.val = 726; p.d = 582; p.r = 144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 39; p.county = 79; p.val = 5630; p.d = 3600; p.r = 2030;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 40; p.county = 79; p.val = 1077; p.d = 1042; p.r = 35;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 38; p.county = 79; p.val = 6081; p.d = 3223; p.r = 2858;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 36; p.county = 79; p.val = 2191; p.d = 2118; p.r = 73;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 42; p.county = 79; p.val = 750; p.d = 682; p.r = 68;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 39; p.county = 79; p.val = 4710; p.d = 3483; p.r = 1227;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 35; p.county = 79; p.val = 5274; p.d = 4067; p.r = 1207;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 35; p.county = 79; p.val = 734; p.d = 536; p.r = 198;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 36; p.county = 79; p.val = 1738; p.d = 1561; p.r = 177;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 41; p.county = 79; p.val = 850; p.d = 744; p.r = 106;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 37; p.county = 79; p.val = 1982; p.d = 1229; p.r = 753;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 39; p.county = 79; p.val = 3377; p.d = 2910; p.r = 467;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 34; p.county = 79; p.val = 4131; p.d = 2181; p.r = 1950;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 33; p.county = 79; p.val = 3068; p.d = 2022; p.r = 1046;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 44; p.county = 79; p.val = 844; p.d = 792; p.r = 52;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 36; p.county = 79; p.val = 2095; p.d = 1690; p.r = 405;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 31; p.county = 79; p.val = 1168; p.d = 473; p.r = 695;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 32; p.county = 79; p.val = 2762; p.d = 1474; p.r = 1288;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 33; p.county = 79; p.val = 1004; p.d = 603; p.r = 401;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 31; p.county = 79; p.val = 1915; p.d = 1107; p.r = 808;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 32; p.county = 79; p.val = 1494; p.d = 933; p.r = 561;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 34; p.county = 79; p.val = 1504; p.d = 1277; p.r = 227;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 44; p.county = 79; p.val = 747; p.d = 689; p.r = 58;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 34; p.county = 79; p.val = 3770; p.d = 2399; p.r = 1371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 33; p.county = 79; p.val = 6637; p.d = 5406; p.r = 1231;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 36; p.county = 79; p.val = 2624; p.d = 2187; p.r = 437;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 33; p.county = 79; p.val = 1527; p.d = 638; p.r = 889;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 38; p.county = 79; p.val = 499; p.d = 351; p.r = 148;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 39; p.county = 79; p.val = 1146; p.d = 688; p.r = 458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 33; p.county = 79; p.val = 475; p.d = 239; p.r = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 35; p.county = 79; p.val = 1765; p.d = 1691; p.r = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 40; p.county = 79; p.val = 284; p.d = 170; p.r = 114;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 31; p.county = 79; p.val = 1125; p.d = 733; p.r = 392;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 33; p.county = 79; p.val = 1275; p.d = 958; p.r = 317;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 32; p.county = 79; p.val = 1757; p.d = 1139; p.r = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 35; p.county = 79; p.val = 1101; p.d = 1080; p.r = 21;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 33; p.county = 79; p.val = 6452; p.d = 5578; p.r = 874;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 40; p.county = 79; p.val = 682; p.d = 548; p.r = 134;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 35; p.county = 79; p.val = 4279; p.d = 2831; p.r = 1448;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 40; p.county = 79; p.val = 466; p.d = 303; p.r = 163;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 34; p.county = 79; p.val = 2869; p.d = 2510; p.r = 359;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 35; p.county = 79; p.val = 1338; p.d = 823; p.r = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 34; p.county = 79; p.val = 988; p.d = 564; p.r = 424;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 32; p.county = 79; p.val = 1399; p.d = 334; p.r = 1065;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 34; p.county = 79; p.val = 1271; p.d = 396; p.r = 875;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 41; p.county = 79; p.val = 614; p.d = 445; p.r = 169;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 38; p.county = 79; p.val = 832; p.d = 307; p.r = 525;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 35; p.county = 81; p.val = 283; p.d = 66; p.r = 217;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 39; p.county = 81; p.val = 163; p.d = 21; p.r = 142;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 38; p.county = 81; p.val = 259; p.d = 46; p.r = 213;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 34; p.county = 81; p.val = 363; p.d = 172; p.r = 191;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 36; p.county = 81; p.val = 591; p.d = 92; p.r = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 40; p.county = 81; p.val = 536; p.d = 202; p.r = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 36; p.county = 81; p.val = 465; p.d = 107; p.r = 358;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 39; p.county = 81; p.val = 561; p.d = 368; p.r = 193;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 39; p.county = 81; p.val = 397; p.d = 244; p.r = 153;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 38; p.county = 81; p.val = 270; p.d = 83; p.r = 187;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 42; p.county = 81; p.val = 124; p.d = 59; p.r = 65;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 35; p.county = 81; p.val = 768; p.d = 132; p.r = 636;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 41; p.county = 81; p.val = 322; p.d = 71; p.r = 251;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 43; p.county = 81; p.val = 472; p.d = 263; p.r = 209;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 38; p.county = 81; p.val = 145; p.d = 41; p.r = 104;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 38; p.county = 81; p.val = 579; p.d = 225; p.r = 354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 38; p.county = 81; p.val = 336; p.d = 39; p.r = 297;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 42; p.county = 81; p.val = 238; p.d = 125; p.r = 113;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 13; p.county = 83; p.val = 503; p.d = 145; p.r = 358;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 7; p.county = 83; p.val = 1639; p.d = 758; p.r = 881;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 7; p.county = 83; p.val = 2360; p.d = 1094; p.r = 1266;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 10; p.county = 83; p.val = 1626; p.d = 499; p.r = 1127;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 1; p.county = 83; p.val = 1119; p.d = 299; p.r = 820;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 6; p.county = 83; p.val = 445; p.d = 162; p.r = 283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 5; p.county = 83; p.val = 891; p.d = 217; p.r = 674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 12; p.county = 83; p.val = 695; p.d = 135; p.r = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 7; p.county = 83; p.val = 708; p.d = 149; p.r = 559;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 3; p.county = 83; p.val = 849; p.d = 112; p.r = 737;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 12; p.county = 83; p.val = 982; p.d = 184; p.r = 798;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 11; p.county = 83; p.val = 581; p.d = 116; p.r = 465;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 10; p.county = 83; p.val = 1160; p.d = 452; p.r = 708;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 8; p.county = 83; p.val = 1748; p.d = 772; p.r = 976;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 9; p.county = 83; p.val = 1123; p.d = 624; p.r = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 4; p.county = 83; p.val = 2458; p.d = 909; p.r = 1549;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 3; p.county = 83; p.val = 3245; p.d = 709; p.r = 2536;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 4; p.county = 83; p.val = 744; p.d = 173; p.r = 571;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 2; p.county = 83; p.val = 1371; p.d = 316; p.r = 1055;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 5; p.county = 83; p.val = 1400; p.d = 378; p.r = 1022;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 10; p.county = 83; p.val = 970; p.d = 246; p.r = 724;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 3; p.county = 83; p.val = 927; p.d = 167; p.r = 760;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 4; p.county = 83; p.val = 1491; p.d = 565; p.r = 926;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 0; p.county = 83; p.val = 1528; p.d = 456; p.r = 1072;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 3; p.county = 83; p.val = 637; p.d = 138; p.r = 499;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 5; p.county = 83; p.val = 2905; p.d = 1150; p.r = 1755;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 6; p.county = 83; p.val = 2176; p.d = 839; p.r = 1337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 5; p.county = 83; p.val = 530; p.d = 193; p.r = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 14; p.county = 83; p.val = 488; p.d = 88; p.r = 400;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 8; p.county = 83; p.val = 1663; p.d = 804; p.r = 859;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 16; p.county = 83; p.val = 375; p.d = 92; p.r = 283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 1; p.county = 83; p.val = 1694; p.d = 345; p.r = 1349;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 6; p.county = 83; p.val = 1099; p.d = 588; p.r = 511;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 17; p.county = 83; p.val = 654; p.d = 159; p.r = 495;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 6; p.county = 83; p.val = 1106; p.d = 703; p.r = 403;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 4; p.county = 83; p.val = 1626; p.d = 265; p.r = 1361;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 7; p.county = 83; p.val = 2044; p.d = 670; p.r = 1374;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 10; p.county = 83; p.val = 1467; p.d = 470; p.r = 997;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 11; p.county = 83; p.val = 1815; p.d = 537; p.r = 1278;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 7; p.county = 83; p.val = 3377; p.d = 1848; p.r = 1529;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 8; p.county = 83; p.val = 2043; p.d = 1377; p.r = 666;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 7; p.county = 83; p.val = 2204; p.d = 1858; p.r = 346;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 8; p.county = 83; p.val = 457; p.d = 250; p.r = 207;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 8; p.county = 83; p.val = 821; p.d = 363; p.r = 458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 13; p.county = 83; p.val = 1486; p.d = 229; p.r = 1257;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 7; p.county = 83; p.val = 1253; p.d = 609; p.r = 644;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 5; p.county = 83; p.val = 766; p.d = 312; p.r = 454;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 31; p.y = 9; p.county = 83; p.val = 468; p.d = 195; p.r = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 5; p.county = 83; p.val = 1282; p.d = 449; p.r = 833;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 3; p.county = 83; p.val = 1132; p.d = 209; p.r = 923;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 6; p.county = 83; p.val = 615; p.d = 234; p.r = 381;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 8; p.county = 83; p.val = 1773; p.d = 710; p.r = 1063;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 4; p.county = 83; p.val = 1047; p.d = 337; p.r = 710;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 11; p.county = 83; p.val = 1556; p.d = 520; p.r = 1036;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 9; p.county = 83; p.val = 2138; p.d = 881; p.r = 1257;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 4; p.county = 83; p.val = 593; p.d = 125; p.r = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 3; p.county = 83; p.val = 738; p.d = 147; p.r = 591;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 7; p.county = 83; p.val = 2877; p.d = 1377; p.r = 1500;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 9; p.county = 83; p.val = 1132; p.d = 386; p.r = 746;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 1; p.county = 83; p.val = 1326; p.d = 380; p.r = 946;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 9; p.county = 83; p.val = 2705; p.d = 1336; p.r = 1369;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 15; p.county = 83; p.val = 1123; p.d = 447; p.r = 676;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 9; p.county = 83; p.val = 1469; p.d = 594; p.r = 875;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 6; p.county = 83; p.val = 1109; p.d = 283; p.r = 826;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 6; p.county = 83; p.val = 930; p.d = 229; p.r = 701;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 6; p.county = 83; p.val = 449; p.d = 249; p.r = 200;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 8; p.county = 83; p.val = 3122; p.d = 1553; p.r = 1569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 8; p.county = 83; p.val = 1437; p.d = 1148; p.r = 289;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 5; p.county = 83; p.val = 809; p.d = 330; p.r = 479;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 10; p.county = 83; p.val = 1627; p.d = 621; p.r = 1006;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 35; p.county = 85; p.val = 1097; p.d = 938; p.r = 159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 38; p.county = 85; p.val = 349; p.d = 300; p.r = 49;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 37; p.county = 85; p.val = 489; p.d = 302; p.r = 187;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 39; p.county = 85; p.val = 1153; p.d = 555; p.r = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 38; p.county = 85; p.val = 1325; p.d = 710; p.r = 615;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 41; p.county = 85; p.val = 268; p.d = 225; p.r = 43;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 39; p.county = 85; p.val = 703; p.d = 423; p.r = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 43; p.county = 85; p.val = 735; p.d = 309; p.r = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 44; p.county = 85; p.val = 972; p.d = 407; p.r = 565;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 41; p.county = 85; p.val = 786; p.d = 633; p.r = 153;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 40; p.county = 85; p.val = 1135; p.d = 727; p.r = 408;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 43; p.county = 85; p.val = 769; p.d = 373; p.r = 396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 46; p.county = 85; p.val = 892; p.d = 525; p.r = 367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 45; p.county = 85; p.val = 553; p.d = 307; p.r = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 43; p.county = 85; p.val = 884; p.d = 321; p.r = 563;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 38; p.county = 85; p.val = 711; p.d = 418; p.r = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 44; p.county = 85; p.val = 691; p.d = 209; p.r = 482;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 42; p.county = 85; p.val = 1728; p.d = 776; p.r = 952;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 39; p.county = 85; p.val = 1031; p.d = 577; p.r = 454;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 36; p.county = 85; p.val = 537; p.d = 399; p.r = 138;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 38; p.county = 85; p.val = 710; p.d = 314; p.r = 396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 41; p.county = 85; p.val = 2078; p.d = 917; p.r = 1161;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 42; p.county = 85; p.val = 584; p.d = 329; p.r = 255;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 40; p.county = 85; p.val = 360; p.d = 279; p.r = 81;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 41; p.county = 85; p.val = 2941; p.d = 2155; p.r = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 39; p.county = 85; p.val = 438; p.d = 320; p.r = 118;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 40; p.county = 85; p.val = 465; p.d = 209; p.r = 256;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 40; p.county = 85; p.val = 3727; p.d = 1957; p.r = 1770;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 42; p.county = 85; p.val = 1314; p.d = 891; p.r = 423;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 40; p.county = 85; p.val = 1005; p.d = 801; p.r = 204;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 41; p.county = 85; p.val = 1116; p.d = 998; p.r = 118;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 42; p.county = 85; p.val = 459; p.d = 428; p.r = 31;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 40; p.county = 85; p.val = 1590; p.d = 366; p.r = 1224;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 39; p.county = 85; p.val = 59; p.d = 27; p.r = 32;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 39; p.county = 85; p.val = 754; p.d = 405; p.r = 349;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 14; p.county = 87; p.val = 393; p.d = 63; p.r = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 20; p.county = 87; p.val = 246; p.d = 144; p.r = 102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 13; p.county = 87; p.val = 480; p.d = 173; p.r = 307;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 14; p.county = 87; p.val = 414; p.d = 105; p.r = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 10; p.county = 87; p.val = 513; p.d = 148; p.r = 365;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 11; p.county = 87; p.val = 591; p.d = 224; p.r = 367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 11; p.county = 87; p.val = 523; p.d = 189; p.r = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 13; p.county = 87; p.val = 314; p.d = 77; p.r = 237;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 14; p.county = 87; p.val = 848; p.d = 294; p.r = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 36; p.y = 15; p.county = 87; p.val = 152; p.d = 52; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 14; p.county = 87; p.val = 420; p.d = 77; p.r = 343;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 14; p.county = 87; p.val = 927; p.d = 493; p.r = 434;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 15; p.county = 87; p.val = 892; p.d = 590; p.r = 302;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 38; p.y = 20; p.county = 87; p.val = 287; p.d = 251; p.r = 36;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 18; p.county = 87; p.val = 477; p.d = 162; p.r = 315;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 37; p.y = 17; p.county = 87; p.val = 418; p.d = 249; p.r = 169;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 15; p.county = 87; p.val = 147; p.d = 101; p.r = 46;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 17; p.county = 87; p.val = 679; p.d = 268; p.r = 411;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 13; p.county = 87; p.val = 215; p.d = 68; p.r = 147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 46; p.county = 89; p.val = 192; p.d = 116; p.r = 76;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 52; p.county = 89; p.val = 457; p.d = 308; p.r = 149;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 89; p.val = 268; p.d = 168; p.r = 100;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 57; p.county = 89; p.val = 340; p.d = 95; p.r = 245;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 55; p.county = 89; p.val = 205; p.d = 62; p.r = 143;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 44; p.county = 89; p.val = 74; p.d = 15; p.r = 59;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 79; p.y = 47; p.county = 89; p.val = 737; p.d = 619; p.r = 118;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 49; p.county = 89; p.val = 187; p.d = 91; p.r = 96;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 51; p.county = 89; p.val = 466; p.d = 308; p.r = 158;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 52; p.county = 89; p.val = 683; p.d = 562; p.r = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 46; p.county = 89; p.val = 842; p.d = 538; p.r = 304;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 48; p.county = 89; p.val = 316; p.d = 162; p.r = 154;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 49; p.county = 89; p.val = 1341; p.d = 702; p.r = 639;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 49; p.county = 89; p.val = 310; p.d = 298; p.r = 12;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 47; p.county = 89; p.val = 864; p.d = 790; p.r = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 50; p.county = 89; p.val = 547; p.d = 423; p.r = 124;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 54; p.county = 89; p.val = 506; p.d = 471; p.r = 35;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 81; p.y = 52; p.county = 89; p.val = 151; p.d = 139; p.r = 12;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 49; p.county = 89; p.val = 217; p.d = 133; p.r = 84;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 50; p.county = 89; p.val = 371; p.d = 321; p.r = 50;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 43; p.county = 89; p.val = 137; p.d = 61; p.r = 76;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 53; p.county = 89; p.val = 238; p.d = 10; p.r = 228;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 52; p.county = 89; p.val = 591; p.d = 507; p.r = 84;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 45; p.county = 89; p.val = 171; p.d = 144; p.r = 27;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 58; p.county = 89; p.val = 145; p.d = 48; p.r = 97;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 55; p.county = 89; p.val = 475; p.d = 423; p.r = 52;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 46; p.county = 89; p.val = 503; p.d = 185; p.r = 318;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 46; p.county = 89; p.val = 209; p.d = 70; p.r = 139;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 2; p.county = 91; p.val = 1092; p.d = 171; p.r = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 1; p.county = 91; p.val = 1967; p.d = 667; p.r = 1300;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 2; p.county = 91; p.val = 1983; p.d = 627; p.r = 1356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 4; p.county = 91; p.val = 359; p.d = 36; p.r = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 4; p.county = 91; p.val = 4244; p.d = 1721; p.r = 2523;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 2; p.county = 91; p.val = 1620; p.d = 534; p.r = 1086;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 1; p.county = 91; p.val = 762; p.d = 151; p.r = 611;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 10; p.county = 91; p.val = 259; p.d = 47; p.r = 212;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 7; p.county = 91; p.val = 586; p.d = 156; p.r = 430;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 5; p.county = 91; p.val = 674; p.d = 196; p.r = 478;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 8; p.county = 91; p.val = 847; p.d = 180; p.r = 667;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 10; p.county = 91; p.val = 877; p.d = 237; p.r = 640;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 10; p.county = 91; p.val = 1218; p.d = 663; p.r = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 11; p.county = 91; p.val = 1465; p.d = 411; p.r = 1054;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 4; p.county = 91; p.val = 837; p.d = 157; p.r = 680;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 9; p.county = 91; p.val = 1112; p.d = 305; p.r = 807;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 10; p.county = 91; p.val = 1596; p.d = 810; p.r = 786;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 6; p.county = 91; p.val = 2054; p.d = 818; p.r = 1236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 41; p.y = 7; p.county = 91; p.val = 742; p.d = 220; p.r = 522;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 6; p.county = 91; p.val = 1106; p.d = 261; p.r = 845;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 6; p.county = 91; p.val = 821; p.d = 450; p.r = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 6; p.county = 91; p.val = 1201; p.d = 546; p.r = 655;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 6; p.county = 91; p.val = 4525; p.d = 1953; p.r = 2572;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 3; p.county = 91; p.val = 1485; p.d = 386; p.r = 1099;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 5; p.county = 91; p.val = 895; p.d = 192; p.r = 703;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 7; p.county = 91; p.val = 5266; p.d = 2356; p.r = 2910;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 7; p.county = 91; p.val = 4200; p.d = 1996; p.r = 2204;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 6; p.county = 91; p.val = 1613; p.d = 624; p.r = 989;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 6; p.county = 91; p.val = 1073; p.d = 530; p.r = 543;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 8; p.county = 91; p.val = 4424; p.d = 3277; p.r = 1147;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 9; p.county = 91; p.val = 1894; p.d = 1712; p.r = 182;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 3; p.county = 91; p.val = 1251; p.d = 491; p.r = 760;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 5; p.county = 91; p.val = 2538; p.d = 900; p.r = 1638;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 9; p.county = 91; p.val = 1422; p.d = 450; p.r = 972;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 8; p.county = 91; p.val = 1126; p.d = 1032; p.r = 94;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 5; p.county = 91; p.val = 3004; p.d = 1248; p.r = 1756;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 9; p.county = 91; p.val = 1535; p.d = 342; p.r = 1193;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 4; p.county = 91; p.val = 3619; p.d = 1449; p.r = 2170;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 3; p.county = 91; p.val = 2554; p.d = 1050; p.r = 1504;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 5; p.county = 91; p.val = 1591; p.d = 509; p.r = 1082;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 7; p.county = 91; p.val = 1761; p.d = 997; p.r = 764;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 4; p.county = 91; p.val = 1201; p.d = 325; p.r = 876;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 7; p.county = 91; p.val = 2162; p.d = 885; p.r = 1277;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 4; p.county = 91; p.val = 3863; p.d = 1672; p.r = 2191;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 6; p.county = 91; p.val = 1143; p.d = 397; p.r = 746;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 7; p.county = 91; p.val = 999; p.d = 383; p.r = 616;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 9; p.county = 91; p.val = 524; p.d = 144; p.r = 380;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 8; p.county = 91; p.val = 1000; p.d = 365; p.r = 635;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 1; p.county = 91; p.val = 659; p.d = 187; p.r = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 8; p.county = 91; p.val = 1490; p.d = 826; p.r = 664;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 2; p.county = 91; p.val = 756; p.d = 337; p.r = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 2; p.county = 91; p.val = 677; p.d = 247; p.r = 430;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 3; p.county = 91; p.val = 870; p.d = 221; p.r = 649;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 4; p.county = 91; p.val = 1201; p.d = 394; p.r = 807;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 5; p.county = 91; p.val = 1901; p.d = 815; p.r = 1086;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 3; p.county = 91; p.val = 2212; p.d = 979; p.r = 1233;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 13; p.county = 23; p.val = 601; p.d = 200; p.r = 401;
points[i]=p;i++;}
return points;}











struct Map {
	std::map<int,std::map<int,Point> > pixels;
	int width;
	int height;
};

int sum(Map m){
	int i; int ii; int sum = 0;
	for (i=0;i<m.width;i++){
		for (ii=0;ii<m.height;ii++){
			sum += m.pixels[i][ii].val;
		}
	}
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
			}
			else if (removeSeam[i]+1<m.height){
				for(ii=m.height;ii>removeSeam[i]+2;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val+m.pixels[i][removeSeam[i]+1].val;
				int r = m.pixels[i][removeSeam[i]].r+m.pixels[i][removeSeam[i]+1].r;
				int d = m.pixels[i][removeSeam[i]].d+m.pixels[i][removeSeam[i]+1].d;
				m.pixels[i][removeSeam[i]].val = v - v/3 - v/3;
				m.pixels[i][removeSeam[i]+1].val = v/3;
				m.pixels[i][removeSeam[i]+2].val = v/3;
				
				m.pixels[i][removeSeam[i]].r = r - r/3 - r/3;
				m.pixels[i][removeSeam[i]+1].r = r/3;
				m.pixels[i][removeSeam[i]+2].r = r/3;
				
				m.pixels[i][removeSeam[i]].d = d - d/3 - d/3;
				m.pixels[i][removeSeam[i]+1].d = d/3;
				m.pixels[i][removeSeam[i]+2].d = d/3;
			}
			else {
				for(ii=m.height;ii>removeSeam[i]+1;ii--){
					m.pixels[i][ii]=m.pixels[i][ii-1];
				}
				m.pixels[i][removeSeam[i]+1].county =m.pixels[i][removeSeam[i]].county;
				int v = m.pixels[i][removeSeam[i]].val;
				int r = m.pixels[i][removeSeam[i]].r;
				int d = m.pixels[i][removeSeam[i]].d;
				m.pixels[i][removeSeam[i]].val = v/2;
				m.pixels[i][removeSeam[i]+1].val = v - v/2;
				
				m.pixels[i][removeSeam[i]].r = r/2;
				m.pixels[i][removeSeam[i]+1].r = r - r/2;
				
				m.pixels[i][removeSeam[i]].d = d/2;
				m.pixels[i][removeSeam[i]+1].d = d - d/2;
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
			}
			else if (removeSeam[ii]+1<m.width){
				for(i=m.width;i>removeSeam[ii]+2;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val+m.pixels[removeSeam[ii]+1][ii].val;
				int r = m.pixels[removeSeam[ii]][ii].r+m.pixels[removeSeam[ii]+1][ii].r;
				int d = m.pixels[removeSeam[ii]][ii].d+m.pixels[removeSeam[ii]+1][ii].d;
				m.pixels[removeSeam[ii]][ii].val=v - v/3 - v/3;
				m.pixels[removeSeam[ii]+1][ii].val=v/3;
				m.pixels[removeSeam[ii]+2][ii].val= v/3;
				
				m.pixels[removeSeam[ii]][ii].r=r - r/3 - r/3;
				m.pixels[removeSeam[ii]+1][ii].r=r/3;
				m.pixels[removeSeam[ii]+2][ii].r= r/3;
				
				m.pixels[removeSeam[ii]][ii].d=d - d/3 - d/3;
				m.pixels[removeSeam[ii]+1][ii].d=d/3;
				m.pixels[removeSeam[ii]+2][ii].d= d/3;
			}
			else {
				for(i=m.width;i>removeSeam[ii]+1;i--){
			
					m.pixels[i][ii]=m.pixels[i-1][ii];
				}
				m.pixels[removeSeam[ii]+1][ii].county=m.pixels[removeSeam[ii]][ii].county;
				int v = m.pixels[removeSeam[ii]][ii].val;
				int r = m.pixels[removeSeam[ii]][ii].r;
				int d = m.pixels[removeSeam[ii]][ii].d;
				m.pixels[removeSeam[ii]][ii].val=v/2;
				m.pixels[removeSeam[ii]+1][ii].val= v - v/2;
				
				m.pixels[removeSeam[ii]][ii].r=r/2;
				m.pixels[removeSeam[ii]+1][ii].r= r - r/2;
				
				m.pixels[removeSeam[ii]][ii].d=d/2;
				m.pixels[removeSeam[ii]+1][ii].d= d - d/2;
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
			if (removeSeam[i]+1 < m.height){
				m.pixels[i][removeSeam[i]].val +=m.pixels[i][removeSeam[i]+1].val;
				m.pixels[i][removeSeam[i]].r +=m.pixels[i][removeSeam[i]+1].r;
				m.pixels[i][removeSeam[i]].d +=m.pixels[i][removeSeam[i]+1].d;
				for(ii=removeSeam[i]+1;ii<m.height-1;ii++){
					m.pixels[i][ii]=m.pixels[i][ii+1];
				}
			}
			else {
				m.pixels[i][removeSeam[i]-1].val +=m.pixels[i][removeSeam[i]].val;
				m.pixels[i][removeSeam[i]-1].r +=m.pixels[i][removeSeam[i]].r;
				m.pixels[i][removeSeam[i]-1].d +=m.pixels[i][removeSeam[i]].d;
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
				if (removeSeam[ii]+1 < m.width){
					m.pixels[removeSeam[ii]][ii].val+=m.pixels[removeSeam[ii]+1][ii].val;
					m.pixels[removeSeam[ii]][ii].r+=m.pixels[removeSeam[ii]+1][ii].r;
					m.pixels[removeSeam[ii]][ii].d+=m.pixels[removeSeam[ii]+1][ii].d;
					for(i=removeSeam[ii]+1;i<m.width-1;i++){
				
						m.pixels[i][ii]=m.pixels[i+1][ii];
					}
				}
				else {
					m.pixels[removeSeam[ii]-1][ii].val+=m.pixels[removeSeam[ii]][ii].val;
					m.pixels[removeSeam[ii]-1][ii].r+=m.pixels[removeSeam[ii]][ii].r;
					m.pixels[removeSeam[ii]-1][ii].d+=m.pixels[removeSeam[ii]][ii].d;
				}
			}
			m.width--;
		}
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
				pixels[i][ii].d += points[pixelMap[i][ii]].d*100/points[pixelMap[i][ii]].npix;
				pixels[i][ii].r += points[pixelMap[i][ii]].r*100/points[pixelMap[i][ii]].npix;
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
	for (iii=0;iii<101;iii++){
		vertThreads = 1 + (rand() % 25);
		horzThreads = 1 + (rand() % 25);
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
	console_log(m.width);
	console_log(m.height);
	
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
