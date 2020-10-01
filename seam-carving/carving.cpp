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
		pointsOut.push({"x":pointSplit[3],"y":pointSplit[4],"ox":pointSplit[0],"oy":pointSplit[1],"county":pointSplit[5],"val":pointSplit[2],"d":pointSplit[6],"r":pointSplit[7],"d16":pointSplit[8],"r16":pointSplit[9]});	
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

extern "C" {


}

struct Point {
	int x;
	int y;
	int val;
	int county;
	int npix;
	std::map<std::string,int> data;
	int d;
	int r;
	int d16;
};

std::map<int,Point> scPoints(){
std::map<int,Point> points; int i=0;
if (1==1){ Point p;
p.x = 19; p.y = 74; p.county = 13; p.val = 431; p.d = 311; p.r = 120; p.d16 = 350; p.data["r16"] = 169;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 74; p.county = 13; p.val = 605; p.d = 315; p.r = 290; p.d16 = 307; p.data["r16"] = 294;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 75; p.county = 13; p.val = 725; p.d = 328; p.r = 397; p.d16 = 287; p.data["r16"] = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 77; p.county = 13; p.val = 937; p.d = 418; p.r = 519; p.d16 = 376; p.data["r16"] = 598;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 75; p.county = 13; p.val = 832; p.d = 499; p.r = 333; p.d16 = 481; p.data["r16"] = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 82; p.county = 13; p.val = 717; p.d = 314; p.r = 403; p.d16 = 313; p.data["r16"] = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 77; p.county = 13; p.val = 1076; p.d = 382; p.r = 694; p.d16 = 380; p.data["r16"] = 743;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 72; p.county = 13; p.val = 184; p.d = 96; p.r = 88; p.d16 = 191; p.data["r16"] = 113;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 79; p.county = 13; p.val = 652; p.d = 342; p.r = 310; p.d16 = 325; p.data["r16"] = 366;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 78; p.county = 13; p.val = 1196; p.d = 604; p.r = 592; p.d16 = 670; p.data["r16"] = 742;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 74; p.county = 13; p.val = 610; p.d = 495; p.r = 115; p.d16 = 512; p.data["r16"] = 129;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 77; p.county = 13; p.val = 716; p.d = 276; p.r = 440; p.d16 = 254; p.data["r16"] = 510;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 78; p.county = 13; p.val = 862; p.d = 428; p.r = 434; p.d16 = 449; p.data["r16"] = 566;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 81; p.county = 13; p.val = 1071; p.d = 381; p.r = 690; p.d16 = 397; p.data["r16"] = 721;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 83; p.county = 13; p.val = 805; p.d = 252; p.r = 553; p.d16 = 331; p.data["r16"] = 633;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 74; p.county = 13; p.val = 849; p.d = 380; p.r = 469; p.d16 = 356; p.data["r16"] = 548;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 78; p.county = 13; p.val = 963; p.d = 425; p.r = 538; p.d16 = 431; p.data["r16"] = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 73; p.county = 13; p.val = 1005; p.d = 351; p.r = 654; p.d16 = 293; p.data["r16"] = 773;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 71; p.county = 13; p.val = 834; p.d = 332; p.r = 502; p.d16 = 272; p.data["r16"] = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 75; p.county = 13; p.val = 709; p.d = 225; p.r = 484; p.d16 = 223; p.data["r16"] = 485;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 72; p.county = 13; p.val = 589; p.d = 225; p.r = 364; p.d16 = 195; p.data["r16"] = 386;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 77; p.county = 13; p.val = 573; p.d = 218; p.r = 355; p.d16 = 247; p.data["r16"] = 408;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 66; p.county = 13; p.val = 618; p.d = 410; p.r = 208; p.d16 = 495; p.data["r16"] = 236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 72; p.county = 13; p.val = 512; p.d = 276; p.r = 236; p.d16 = 312; p.data["r16"] = 354;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 68; p.county = 13; p.val = 528; p.d = 404; p.r = 124; p.d16 = 431; p.data["r16"] = 159;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 70; p.county = 13; p.val = 733; p.d = 447; p.r = 286; p.d16 = 524; p.data["r16"] = 373;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 64; p.county = 13; p.val = 656; p.d = 356; p.r = 300; p.d16 = 443; p.data["r16"] = 304;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 59; p.county = 13; p.val = 409; p.d = 358; p.r = 51; p.d16 = 484; p.data["r16"] = 53;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 73; p.county = 13; p.val = 258; p.d = 147; p.r = 111; p.d16 = 151; p.data["r16"] = 211;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 79; p.county = 13; p.val = 754; p.d = 624; p.r = 130; p.d16 = 620; p.data["r16"] = 135;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 85; p.county = 13; p.val = 835; p.d = 670; p.r = 165; p.d16 = 686; p.data["r16"] = 183;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 75; p.county = 13; p.val = 1151; p.d = 472; p.r = 679; p.d16 = 385; p.data["r16"] = 658;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 75; p.county = 13; p.val = 844; p.d = 526; p.r = 318; p.d16 = 519; p.data["r16"] = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 32; p.y = 77; p.county = 13; p.val = 811; p.d = 646; p.r = 165; p.d16 = 663; p.data["r16"] = 197;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 84; p.county = 13; p.val = 736; p.d = 275; p.r = 461; p.d16 = 275; p.data["r16"] = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 72; p.county = 13; p.val = 577; p.d = 212; p.r = 365; p.d16 = 231; p.data["r16"] = 397;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 73; p.county = 13; p.val = 581; p.d = 239; p.r = 342; p.d16 = 195; p.data["r16"] = 396;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 99; p.county = 13; p.val = 298; p.d = 110; p.r = 188; p.d16 = 115; p.data["r16"] = 185;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 91; p.county = 13; p.val = 644; p.d = 265; p.r = 379; p.d16 = 273; p.data["r16"] = 461;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 96; p.county = 13; p.val = 553; p.d = 258; p.r = 295; p.d16 = 257; p.data["r16"] = 348;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 91; p.county = 13; p.val = 686; p.d = 377; p.r = 309; p.d16 = 423; p.data["r16"] = 417;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 90; p.county = 13; p.val = 663; p.d = 438; p.r = 225; p.d16 = 568; p.data["r16"] = 273;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 92; p.county = 13; p.val = 1018; p.d = 408; p.r = 610; p.d16 = 377; p.data["r16"] = 646;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 91; p.county = 13; p.val = 701; p.d = 372; p.r = 329; p.d16 = 414; p.data["r16"] = 350;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 95; p.county = 13; p.val = 789; p.d = 315; p.r = 474; p.d16 = 318; p.data["r16"] = 513;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 93; p.county = 13; p.val = 2048; p.d = 885; p.r = 1163; p.d16 = 871; p.data["r16"] = 1355;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 87; p.county = 13; p.val = 753; p.d = 311; p.r = 442; p.d16 = 351; p.data["r16"] = 509;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 89; p.county = 13; p.val = 872; p.d = 361; p.r = 511; p.d16 = 353; p.data["r16"] = 566;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 90; p.county = 13; p.val = 596; p.d = 211; p.r = 385; p.d16 = 228; p.data["r16"] = 436;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 87; p.county = 13; p.val = 583; p.d = 245; p.r = 338; p.d16 = 194; p.data["r16"] = 358;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 18; p.y = 96; p.county = 13; p.val = 781; p.d = 309; p.r = 472; p.d16 = 344; p.data["r16"] = 548;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 89; p.county = 13; p.val = 1295; p.d = 557; p.r = 738; p.d16 = 631; p.data["r16"] = 918;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 90; p.county = 13; p.val = 734; p.d = 295; p.r = 439; p.d16 = 347; p.data["r16"] = 518;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 95; p.county = 13; p.val = 1096; p.d = 543; p.r = 553; p.d16 = 467; p.data["r16"] = 631;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 15; p.y = 95; p.county = 13; p.val = 898; p.d = 239; p.r = 659; p.d16 = 217; p.data["r16"] = 713;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 14; p.y = 93; p.county = 13; p.val = 1155; p.d = 580; p.r = 575; p.d16 = 602; p.data["r16"] = 618;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 96; p.county = 13; p.val = 768; p.d = 361; p.r = 407; p.d16 = 330; p.data["r16"] = 468;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 97; p.county = 13; p.val = 486; p.d = 208; p.r = 278; p.d16 = 253; p.data["r16"] = 320;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 99; p.county = 13; p.val = 746; p.d = 363; p.r = 383; p.d16 = 347; p.data["r16"] = 462;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 100; p.county = 13; p.val = 572; p.d = 221; p.r = 351; p.d16 = 267; p.data["r16"] = 453;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 98; p.county = 13; p.val = 355; p.d = 174; p.r = 181; p.d16 = 185; p.data["r16"] = 270;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 97; p.county = 13; p.val = 621; p.d = 234; p.r = 387; p.d16 = 249; p.data["r16"] = 440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 86; p.county = 13; p.val = 1353; p.d = 418; p.r = 935; p.d16 = 446; p.data["r16"] = 993;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 90; p.county = 13; p.val = 556; p.d = 219; p.r = 337; p.d16 = 238; p.data["r16"] = 420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 87; p.county = 13; p.val = 569; p.d = 286; p.r = 283; p.d16 = 290; p.data["r16"] = 348;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 3; p.y = 89; p.county = 13; p.val = 1165; p.d = 516; p.r = 649; p.d16 = 480; p.data["r16"] = 634;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 87; p.county = 13; p.val = 645; p.d = 281; p.r = 364; p.d16 = 267; p.data["r16"] = 380;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 86; p.county = 13; p.val = 901; p.d = 311; p.r = 590; p.d16 = 299; p.data["r16"] = 589;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 86; p.county = 13; p.val = 655; p.d = 262; p.r = 393; p.d16 = 238; p.data["r16"] = 356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 0; p.y = 87; p.county = 13; p.val = 1881; p.d = 700; p.r = 1181; p.d16 = 653; p.data["r16"] = 1048;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 87; p.county = 13; p.val = 825; p.d = 325; p.r = 500; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 86; p.county = 13; p.val = 714; p.d = 288; p.r = 426; p.d16 = 240; p.data["r16"] = 420;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 90; p.county = 13; p.val = 891; p.d = 483; p.r = 408; p.d16 = 475; p.data["r16"] = 473;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 93; p.county = 13; p.val = 798; p.d = 292; p.r = 506; p.d16 = 330; p.data["r16"] = 629;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 8; p.y = 89; p.county = 13; p.val = 725; p.d = 387; p.r = 338; p.d16 = 434; p.data["r16"] = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 89; p.county = 13; p.val = 1290; p.d = 496; p.r = 794; p.d16 = 527; p.data["r16"] = 775;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 5; p.y = 89; p.county = 13; p.val = 619; p.d = 346; p.r = 273; p.d16 = 322; p.data["r16"] = 390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 2; p.y = 87; p.county = 13; p.val = 771; p.d = 312; p.r = 459; p.d16 = 515; p.data["r16"] = 970;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 93; p.county = 13; p.val = 1565; p.d = 644; p.r = 921; p.d16 = 509; p.data["r16"] = 1007;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 87; p.county = 13; p.val = 532; p.d = 149; p.r = 383; p.d16 = 157; p.data["r16"] = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 84; p.county = 13; p.val = 589; p.d = 164; p.r = 425; p.d16 = 156; p.data["r16"] = 386;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 89; p.county = 13; p.val = 1519; p.d = 623; p.r = 896; p.d16 = 519; p.data["r16"] = 1021;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 89; p.county = 13; p.val = 740; p.d = 473; p.r = 267; p.d16 = 473; p.data["r16"] = 334;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 7; p.y = 86; p.county = 13; p.val = 1219; p.d = 418; p.r = 801; p.d16 = 389; p.data["r16"] = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 6; p.y = 88; p.county = 13; p.val = 785; p.d = 335; p.r = 450; p.d16 = 286; p.data["r16"] = 574;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 87; p.county = 13; p.val = 866; p.d = 346; p.r = 520; p.d16 = 244; p.data["r16"] = 506;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 89; p.county = 13; p.val = 745; p.d = 254; p.r = 491; p.d16 = 275; p.data["r16"] = 570;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 85; p.county = 13; p.val = 797; p.d = 344; p.r = 453; p.d16 = 341; p.data["r16"] = 530;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 7; p.county = 15; p.val = 526; p.d = 341; p.r = 185; p.d16 = 448; p.data["r16"] = 246;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 18; p.county = 15; p.val = 139; p.d = 12; p.r = 127; p.d16 = 17; p.data["r16"] = 164;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 9; p.county = 15; p.val = 612; p.d = 259; p.r = 353; p.d16 = 295; p.data["r16"] = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 9; p.county = 15; p.val = 850; p.d = 199; p.r = 651; p.d16 = 215; p.data["r16"] = 819;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 13; p.county = 15; p.val = 860; p.d = 125; p.r = 735; p.d16 = 114; p.data["r16"] = 1102;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 14; p.county = 15; p.val = 511; p.d = 201; p.r = 310; p.d16 = 210; p.data["r16"] = 389;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 2; p.county = 15; p.val = 660; p.d = 532; p.r = 128; p.d16 = 616; p.data["r16"] = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 0; p.county = 15; p.val = 647; p.d = 551; p.r = 96; p.d16 = 736; p.data["r16"] = 129;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 32; p.county = 15; p.val = 569; p.d = 331; p.r = 238; p.d16 = 414; p.data["r16"] = 375;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 31; p.county = 15; p.val = 1179; p.d = 552; p.r = 627; p.d16 = 625; p.data["r16"] = 830;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 32; p.county = 15; p.val = 974; p.d = 457; p.r = 517; p.d16 = 450; p.data["r16"] = 663;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 33; p.county = 15; p.val = 626; p.d = 506; p.r = 120; p.d16 = 580; p.data["r16"] = 116;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 1; p.county = 15; p.val = 357; p.d = 283; p.r = 74; p.d16 = 355; p.data["r16"] = 125;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 18; p.county = 15; p.val = 832; p.d = 267; p.r = 565; p.d16 = 293; p.data["r16"] = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 4; p.county = 15; p.val = 662; p.d = 369; p.r = 293; p.d16 = 429; p.data["r16"] = 410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 27; p.county = 15; p.val = 1165; p.d = 229; p.r = 936; p.d16 = 218; p.data["r16"] = 1330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 36; p.county = 15; p.val = 1989; p.d = 924; p.r = 1065; p.d16 = 946; p.data["r16"] = 1584;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 30; p.county = 15; p.val = 696; p.d = 321; p.r = 375; p.d16 = 356; p.data["r16"] = 582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 28; p.county = 15; p.val = 862; p.d = 390; p.r = 472; p.d16 = 276; p.data["r16"] = 438;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 15; p.county = 15; p.val = 926; p.d = 237; p.r = 689; p.d16 = 199; p.data["r16"] = 894;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 22; p.county = 15; p.val = 622; p.d = 245; p.r = 377; p.d16 = 262; p.data["r16"] = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 83; p.y = 12; p.county = 15; p.val = 306; p.d = 187; p.r = 119; p.d16 = 247; p.data["r16"] = 156;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 10; p.county = 15; p.val = 565; p.d = 279; p.r = 286; p.d16 = 286; p.data["r16"] = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 17; p.county = 15; p.val = 753; p.d = 461; p.r = 292; p.d16 = 499; p.data["r16"] = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 21; p.county = 15; p.val = 390; p.d = 59; p.r = 331; p.d16 = 92; p.data["r16"] = 440;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 20; p.county = 15; p.val = 633; p.d = 319; p.r = 314; p.d16 = 255; p.data["r16"] = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 31; p.county = 15; p.val = 808; p.d = 260; p.r = 548; p.d16 = 258; p.data["r16"] = 699;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 42; p.county = 15; p.val = 1258; p.d = 439; p.r = 819; p.d16 = 304; p.data["r16"] = 699;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 42; p.county = 15; p.val = 947; p.d = 471; p.r = 476; p.d16 = 459; p.data["r16"] = 558;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 30; p.county = 15; p.val = 1752; p.d = 842; p.r = 910; p.d16 = 881; p.data["r16"] = 1367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 30; p.county = 15; p.val = 1160; p.d = 538; p.r = 622; p.d16 = 528; p.data["r16"] = 926;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 38; p.county = 15; p.val = 690; p.d = 303; p.r = 387; p.d16 = 672; p.data["r16"] = 557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 40; p.county = 15; p.val = 692; p.d = 369; p.r = 323; p.d16 = 1090; p.data["r16"] = 605;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 39; p.county = 15; p.val = 683; p.d = 224; p.r = 459; p.d16 = 240; p.data["r16"] = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 32; p.county = 15; p.val = 1828; p.d = 736; p.r = 1092; p.d16 = 724; p.data["r16"] = 1382;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 26; p.county = 15; p.val = 691; p.d = 456; p.r = 235; p.d16 = 526; p.data["r16"] = 271;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 16; p.county = 15; p.val = 759; p.d = 310; p.r = 449; p.d16 = 363; p.data["r16"] = 557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 19; p.county = 15; p.val = 652; p.d = 335; p.r = 317; p.d16 = 994; p.data["r16"] = 1039;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 19; p.county = 15; p.val = 974; p.d = 604; p.r = 370; p.d16 = 171; p.data["r16"] = 274;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 28; p.county = 15; p.val = 713; p.d = 147; p.r = 566; p.d16 = 560; p.data["r16"] = 1283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 32; p.county = 15; p.val = 1065; p.d = 343; p.r = 722; p.d16 = 300; p.data["r16"] = 807;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 25; p.county = 15; p.val = 1193; p.d = 484; p.r = 709; p.d16 = 522; p.data["r16"] = 993;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 18; p.county = 15; p.val = 247; p.d = 113; p.r = 134; p.d16 = 130; p.data["r16"] = 157;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 30; p.county = 15; p.val = 1261; p.d = 677; p.r = 584; p.d16 = 774; p.data["r16"] = 823;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 33; p.county = 15; p.val = 812; p.d = 287; p.r = 525; p.d16 = 274; p.data["r16"] = 674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 32; p.county = 15; p.val = 872; p.d = 375; p.r = 497; p.d16 = 398; p.data["r16"] = 612;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 33; p.county = 15; p.val = 1024; p.d = 629; p.r = 395; p.d16 = 655; p.data["r16"] = 523;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 32; p.county = 15; p.val = 1259; p.d = 734; p.r = 525; p.d16 = 703; p.data["r16"] = 708;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 22; p.county = 15; p.val = 1234; p.d = 676; p.r = 558; p.d16 = 586; p.data["r16"] = 764;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 24; p.county = 15; p.val = 751; p.d = 312; p.r = 439; p.d16 = 207; p.data["r16"] = 631;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 45; p.county = 15; p.val = 959; p.d = 470; p.r = 489; p.d16 = 1218; p.data["r16"] = 633;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 44; p.county = 15; p.val = 1372; p.d = 609; p.r = 763; p.d16 = 575; p.data["r16"] = 865;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 40; p.county = 15; p.val = 1108; p.d = 430; p.r = 678; p.d16 = 434; p.data["r16"] = 1011;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 39; p.county = 15; p.val = 1058; p.d = 532; p.r = 526; p.d16 = 483; p.data["r16"] = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 24; p.county = 15; p.val = 2675; p.d = 1157; p.r = 1518; p.d16 = 801; p.data["r16"] = 1557;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 31; p.county = 15; p.val = 1005; p.d = 564; p.r = 441; p.d16 = 481; p.data["r16"] = 541;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 25; p.county = 15; p.val = 1113; p.d = 517; p.r = 596; p.d16 = 446; p.data["r16"] = 719;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 39; p.county = 15; p.val = 795; p.d = 211; p.r = 584; p.d16 = 194; p.data["r16"] = 651;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 4; p.county = 15; p.val = 652; p.d = 525; p.r = 127; p.d16 = 685; p.data["r16"] = 157;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 20; p.county = 15; p.val = 506; p.d = 221; p.r = 285; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 37; p.county = 15; p.val = 1954; p.d = 820; p.r = 1134; p.d16 = 1004; p.data["r16"] = 1540;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 36; p.county = 15; p.val = 556; p.d = 274; p.r = 282; p.d16 = 243; p.data["r16"] = 309;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 29; p.county = 15; p.val = 817; p.d = 440; p.r = 377; p.d16 = 421; p.data["r16"] = 521;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 34; p.county = 15; p.val = 547; p.d = 285; p.r = 262; p.d16 = 303; p.data["r16"] = 335;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 31; p.county = 15; p.val = 650; p.d = 281; p.r = 369; p.d16 = 297; p.data["r16"] = 512;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 35; p.county = 15; p.val = 709; p.d = 509; p.r = 200; p.d16 = 704; p.data["r16"] = 336;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 30; p.county = 15; p.val = 1856; p.d = 1115; p.r = 741; p.d16 = 1040; p.data["r16"] = 973;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 31; p.county = 15; p.val = 743; p.d = 280; p.r = 463; p.d16 = 279; p.data["r16"] = 625;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 27; p.county = 15; p.val = 1083; p.d = 590; p.r = 493; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 31; p.county = 15; p.val = 677; p.d = 309; p.r = 368; p.d16 = 361; p.data["r16"] = 443;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 35; p.county = 15; p.val = 1305; p.d = 613; p.r = 692; p.d16 = 498; p.data["r16"] = 664;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 34; p.county = 15; p.val = 713; p.d = 388; p.r = 325; p.d16 = 417; p.data["r16"] = 497;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 26; p.county = 15; p.val = 80; p.d = 28; p.r = 52; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 28; p.county = 15; p.val = 1129; p.d = 481; p.r = 648; p.d16 = 412; p.data["r16"] = 685;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 89; p.y = 37; p.county = 19; p.val = 811; p.d = 447; p.r = 364; p.d16 = 496; p.data["r16"] = 404;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 85; p.y = 29; p.county = 19; p.val = 547; p.d = 291; p.r = 256; p.d16 = 350; p.data["r16"] = 280;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 51; p.county = 19; p.val = 718; p.d = 284; p.r = 434; p.d16 = 290; p.data["r16"] = 500;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 36; p.county = 19; p.val = 994; p.d = 728; p.r = 266; p.d16 = 1574; p.data["r16"] = 1236;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 59; p.county = 19; p.val = 728; p.d = 485; p.r = 243; p.d16 = 531; p.data["r16"] = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 48; p.county = 19; p.val = 2096; p.d = 1024; p.r = 1072; p.d16 = 244; p.data["r16"] = 316;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 46; p.county = 19; p.val = 733; p.d = 380; p.r = 353; p.d16 = 457; p.data["r16"] = 483;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 46; p.county = 19; p.val = 926; p.d = 438; p.r = 488; p.d16 = 344; p.data["r16"] = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 77; p.y = 48; p.county = 19; p.val = 992; p.d = 414; p.r = 578; p.d16 = 367; p.data["r16"] = 695;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 48; p.county = 19; p.val = 667; p.d = 350; p.r = 317; p.d16 = 574; p.data["r16"] = 714;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 46; p.county = 19; p.val = 1501; p.d = 695; p.r = 806; p.d16 = 315; p.data["r16"] = 401;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 45; p.county = 19; p.val = 1630; p.d = 811; p.r = 819; p.d16 = 513; p.data["r16"] = 597;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 80; p.y = 48; p.county = 19; p.val = 1094; p.d = 390; p.r = 704; p.d16 = 334; p.data["r16"] = 668;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 45; p.county = 19; p.val = 1501; p.d = 667; p.r = 834; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 52; p.county = 19; p.val = 1281; p.d = 680; p.r = 601; p.d16 = 641; p.data["r16"] = 641;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 47; p.county = 19; p.val = 1795; p.d = 836; p.r = 959; p.d16 = 460; p.data["r16"] = 531;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 100; p.y = 27; p.county = 19; p.val = 1072; p.d = 756; p.r = 316; p.d16 = 847; p.data["r16"] = 357;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 35; p.county = 19; p.val = 1626; p.d = 1024; p.r = 602; p.d16 = 470; p.data["r16"] = 263;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 58; p.county = 19; p.val = 699; p.d = 411; p.r = 288; p.d16 = 415; p.data["r16"] = 371;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 64; p.county = 19; p.val = 1224; p.d = 436; p.r = 788; p.d16 = 429; p.data["r16"] = 822;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 34; p.county = 19; p.val = 1065; p.d = 657; p.r = 408; p.d16 = 722; p.data["r16"] = 687;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 36; p.county = 19; p.val = 523; p.d = 284; p.r = 239; p.d16 = 302; p.data["r16"] = 348;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 32; p.county = 19; p.val = 1022; p.d = 608; p.r = 414; p.d16 = 591; p.data["r16"] = 512;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 48; p.county = 19; p.val = 549; p.d = 228; p.r = 321; p.d16 = 218; p.data["r16"] = 399;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 48; p.county = 19; p.val = 668; p.d = 312; p.r = 356; p.d16 = 331; p.data["r16"] = 439;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 33; p.county = 19; p.val = 2218; p.d = 1230; p.r = 988; p.d16 = 1401; p.data["r16"] = 1390;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 65; p.county = 19; p.val = 985; p.d = 523; p.r = 462; p.d16 = 550; p.data["r16"] = 569;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 66; p.county = 19; p.val = 1627; p.d = 693; p.r = 934; p.d16 = 713; p.data["r16"] = 986;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 49; p.county = 19; p.val = 1967; p.d = 1060; p.r = 907; p.d16 = 1536; p.data["r16"] = 1173;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 49; p.county = 19; p.val = 1772; p.d = 1162; p.r = 610; p.d16 = 953; p.data["r16"] = 486;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 61; p.county = 19; p.val = 754; p.d = 422; p.r = 332; p.d16 = 363; p.data["r16"] = 410;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 56; p.county = 19; p.val = 923; p.d = 471; p.r = 452; p.d16 = 460; p.data["r16"] = 517;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 50; p.county = 19; p.val = 555; p.d = 214; p.r = 341; p.d16 = 229; p.data["r16"] = 398;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 48; p.county = 19; p.val = 1653; p.d = 1305; p.r = 348; p.d16 = 1950; p.data["r16"] = 526;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 48; p.county = 19; p.val = 2177; p.d = 1892; p.r = 285; p.d16 = 1859; p.data["r16"] = 310;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 46; p.county = 19; p.val = 504; p.d = 471; p.r = 33; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 48; p.county = 19; p.val = 1366; p.d = 1126; p.r = 240; p.d16 = 693; p.data["r16"] = 167;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 47; p.county = 19; p.val = 878; p.d = 715; p.r = 163; p.d16 = 696; p.data["r16"] = 223;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 47; p.county = 19; p.val = 1203; p.d = 1103; p.r = 100; p.d16 = 1946; p.data["r16"] = 244;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 45; p.county = 19; p.val = 751; p.d = 691; p.r = 60; p.d16 = 942; p.data["r16"] = 71;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 70; p.y = 50; p.county = 19; p.val = 1102; p.d = 525; p.r = 577; p.d16 = 501; p.data["r16"] = 546;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 48; p.county = 19; p.val = 642; p.d = 319; p.r = 323; p.d16 = 250; p.data["r16"] = 297;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 47; p.county = 19; p.val = 920; p.d = 516; p.r = 404; p.d16 = 441; p.data["r16"] = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 49; p.county = 19; p.val = 583; p.d = 266; p.r = 317; p.d16 = 228; p.data["r16"] = 418;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 47; p.county = 19; p.val = 759; p.d = 386; p.r = 373; p.d16 = 1240; p.data["r16"] = 1705;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 46; p.county = 19; p.val = 510; p.d = 186; p.r = 324; p.d16 = 166; p.data["r16"] = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 47; p.county = 19; p.val = 1089; p.d = 591; p.r = 498; p.d16 = 534; p.data["r16"] = 710;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 46; p.county = 19; p.val = 1430; p.d = 677; p.r = 753; p.d16 = 664; p.data["r16"] = 750;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 45; p.county = 19; p.val = 1016; p.d = 573; p.r = 443; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 44; p.county = 19; p.val = 471; p.d = 223; p.r = 248; p.d16 = 772; p.data["r16"] = 764;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 44; p.county = 19; p.val = 327; p.d = 320; p.r = 7; p.d16 = 773; p.data["r16"] = 884;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 71; p.y = 43; p.county = 19; p.val = 1765; p.d = 721; p.r = 1044; p.d16 = 1177; p.data["r16"] = 2019;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 72; p.y = 43; p.county = 19; p.val = 782; p.d = 343; p.r = 439; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 43; p.county = 19; p.val = 196; p.d = 67; p.r = 129; p.d16 = 76; p.data["r16"] = 124;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 39; p.county = 19; p.val = 2471; p.d = 833; p.r = 1638; p.d16 = 716; p.data["r16"] = 1643;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 41; p.county = 19; p.val = 917; p.d = 379; p.r = 538; p.d16 = 328; p.data["r16"] = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 41; p.county = 19; p.val = 2558; p.d = 1038; p.r = 1520; p.d16 = 930; p.data["r16"] = 1720;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 76; p.y = 43; p.county = 19; p.val = 1044; p.d = 503; p.r = 541; p.d16 = 487; p.data["r16"] = 627;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 82; p.y = 43; p.county = 19; p.val = 2010; p.d = 1020; p.r = 990; p.d16 = 1077; p.data["r16"] = 1071;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 40; p.county = 19; p.val = 1755; p.d = 666; p.r = 1089; p.d16 = 509; p.data["r16"] = 1026;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 55; p.county = 19; p.val = 1156; p.d = 732; p.r = 424; p.d16 = 722; p.data["r16"] = 594;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 57; p.county = 19; p.val = 534; p.d = 453; p.r = 81; p.d16 = 400; p.data["r16"] = 79;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 69; p.y = 52; p.county = 19; p.val = 893; p.d = 412; p.r = 481; p.d16 = 367; p.data["r16"] = 483;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 53; p.county = 19; p.val = 448; p.d = 172; p.r = 276; p.d16 = 159; p.data["r16"] = 305;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 53; p.county = 19; p.val = 997; p.d = 573; p.r = 424; p.d16 = 542; p.data["r16"] = 484;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 54; p.county = 19; p.val = 1141; p.d = 631; p.r = 510; p.d16 = 600; p.data["r16"] = 582;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 53; p.county = 19; p.val = 687; p.d = 455; p.r = 232; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 53; p.county = 19; p.val = 921; p.d = 502; p.r = 419; p.d16 = 496; p.data["r16"] = 498;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 66; p.y = 52; p.county = 19; p.val = 698; p.d = 316; p.r = 382; p.d16 = 299; p.data["r16"] = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 52; p.county = 19; p.val = 1017; p.d = 598; p.r = 419; p.d16 = 563; p.data["r16"] = 585;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 51; p.county = 19; p.val = 1021; p.d = 591; p.r = 430; p.d16 = 617; p.data["r16"] = 475;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 59; p.county = 19; p.val = 1034; p.d = 538; p.r = 496; p.d16 = 599; p.data["r16"] = 555;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 75; p.y = 43; p.county = 19; p.val = 1525; p.d = 644; p.r = 881; p.d16 = 612; p.data["r16"] = 1015;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 74; p.y = 42; p.county = 19; p.val = 767; p.d = 341; p.r = 426; p.d16 = 637; p.data["r16"] = 959;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 73; p.y = 40; p.county = 19; p.val = 1635; p.d = 588; p.r = 1047; p.d16 = 534; p.data["r16"] = 1060;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 78; p.y = 42; p.county = 19; p.val = 812; p.d = 315; p.r = 497; p.d16 = 273; p.data["r16"] = 647;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 54; p.county = 19; p.val = 581; p.d = 513; p.r = 68; p.d16 = 476; p.data["r16"] = 74;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 53; p.county = 19; p.val = 844; p.d = 513; p.r = 331; p.d16 = 521; p.data["r16"] = 512;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 53; p.county = 19; p.val = 973; p.d = 640; p.r = 333; p.d16 = 660; p.data["r16"] = 574;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 50; p.county = 19; p.val = 966; p.d = 619; p.r = 347; p.d16 = 550; p.data["r16"] = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 53; p.county = 19; p.val = 1948; p.d = 1037; p.r = 911; p.d16 = 734; p.data["r16"] = 1040;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 52; p.county = 19; p.val = 965; p.d = 537; p.r = 428; p.d16 = 496; p.data["r16"] = 622;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 68; p.y = 51; p.county = 19; p.val = 723; p.d = 334; p.r = 389; p.d16 = 327; p.data["r16"] = 458;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 67; p.y = 51; p.county = 19; p.val = 834; p.d = 418; p.r = 416; p.d16 = 429; p.data["r16"] = 463;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 51; p.county = 19; p.val = 987; p.d = 620; p.r = 367; p.d16 = 554; p.data["r16"] = 466;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 52; p.county = 19; p.val = 915; p.d = 602; p.r = 313; p.d16 = 1005; p.data["r16"] = 737;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 52; p.county = 19; p.val = 754; p.d = 334; p.r = 420; p.d16 = 360; p.data["r16"] = 685;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 51; p.county = 19; p.val = 811; p.d = 520; p.r = 291; p.d16 = 588; p.data["r16"] = 385;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 51; p.county = 19; p.val = 1941; p.d = 1052; p.r = 889; p.d16 = 1096; p.data["r16"] = 1307;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 57; p.county = 19; p.val = 626; p.d = 394; p.r = 232; p.d16 = 389; p.data["r16"] = 311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 56; p.county = 19; p.val = 602; p.d = 460; p.r = 142; p.d16 = 585; p.data["r16"] = 178;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 48; p.county = 19; p.val = 498; p.d = 309; p.r = 189; p.d16 = 397; p.data["r16"] = 243;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 53; p.county = 19; p.val = 782; p.d = 481; p.r = 301; p.d16 = 577; p.data["r16"] = 356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 55; p.county = 19; p.val = 1177; p.d = 390; p.r = 787; p.d16 = 429; p.data["r16"] = 921;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 52; p.county = 19; p.val = 944; p.d = 725; p.r = 219; p.d16 = 834; p.data["r16"] = 260;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 50; p.county = 19; p.val = 569; p.d = 282; p.r = 287; p.d16 = 342; p.data["r16"] = 337;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 47; p.county = 19; p.val = 1089; p.d = 442; p.r = 647; p.d16 = 402; p.data["r16"] = 698;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 49; p.county = 19; p.val = 661; p.d = 479; p.r = 182; p.d16 = 324; p.data["r16"] = 560;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 49; p.county = 19; p.val = 753; p.d = 454; p.r = 299; p.d16 = 443; p.data["r16"] = 339;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 48; p.county = 19; p.val = 1023; p.d = 920; p.r = 103; p.d16 = 1756; p.data["r16"] = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 47; p.county = 19; p.val = 1273; p.d = 706; p.r = 567; p.d16 = 1130; p.data["r16"] = 1072;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 48; p.county = 19; p.val = 1402; p.d = 1120; p.r = 282; p.d16 = 483; p.data["r16"] = 128;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 49; p.county = 19; p.val = 620; p.d = 329; p.r = 291; p.d16 = 255; p.data["r16"] = 384;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 49; p.county = 19; p.val = 984; p.d = 447; p.r = 537; p.d16 = 438; p.data["r16"] = 602;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 47; p.county = 19; p.val = 169; p.d = 146; p.r = 23; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 46; p.county = 19; p.val = 483; p.d = 277; p.r = 206; p.d16 = 1118; p.data["r16"] = 739;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 45; p.county = 19; p.val = 540; p.d = 282; p.r = 258; p.d16 = 936; p.data["r16"] = 937;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 48; p.county = 19; p.val = 2121; p.d = 1232; p.r = 889; p.d16 = 1125; p.data["r16"] = 1024;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 47; p.county = 19; p.val = 1089; p.d = 634; p.r = 455; p.d16 = 699; p.data["r16"] = 724;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 47; p.county = 19; p.val = 1574; p.d = 880; p.r = 694; p.d16 = 878; p.data["r16"] = 951;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 48; p.county = 19; p.val = 285; p.d = 193; p.r = 92; p.d16 = 749; p.data["r16"] = 367;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 65; p.y = 49; p.county = 19; p.val = 811; p.d = 438; p.r = 373; p.d16 = 417; p.data["r16"] = 477;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 48; p.county = 19; p.val = 744; p.d = 598; p.r = 146; p.d16 = 710; p.data["r16"] = 141;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 49; p.county = 19; p.val = 1914; p.d = 912; p.r = 1002; p.d16 = 484; p.data["r16"] = 603;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 46; p.county = 19; p.val = 1581; p.d = 1024; p.r = 557; p.d16 = 452; p.data["r16"] = 203;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 46; p.county = 19; p.val = 690; p.d = 345; p.r = 345; p.d16 = 295; p.data["r16"] = 339;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 46; p.county = 19; p.val = 694; p.d = 357; p.r = 337; p.d16 = 356; p.data["r16"] = 353;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 47; p.county = 19; p.val = 894; p.d = 499; p.r = 395; p.d16 = 148; p.data["r16"] = 19;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 46; p.county = 19; p.val = 1177; p.d = 744; p.r = 433; p.d16 = 510; p.data["r16"] = 446;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 47; p.county = 19; p.val = 542; p.d = 411; p.r = 131; p.d16 = 411; p.data["r16"] = 235;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 48; p.county = 19; p.val = 698; p.d = 393; p.r = 305; p.d16 = 411; p.data["r16"] = 328;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 46; p.county = 19; p.val = 563; p.d = 280; p.r = 283; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 45; p.county = 19; p.val = 713; p.d = 338; p.r = 375; p.d16 = 293; p.data["r16"] = 490;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 46; p.county = 19; p.val = 369; p.d = 146; p.r = 223; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 44; p.county = 19; p.val = 1185; p.d = 509; p.r = 676; p.d16 = 463; p.data["r16"] = 781;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 44; p.county = 19; p.val = 1034; p.d = 443; p.r = 591; p.d16 = 570; p.data["r16"] = 940;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 42; p.county = 19; p.val = 966; p.d = 436; p.r = 530; p.d16 = 423; p.data["r16"] = 726;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 44; p.county = 19; p.val = 1660; p.d = 880; p.r = 780; p.d16 = 907; p.data["r16"] = 1201;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 44; p.county = 19; p.val = 174; p.d = 161; p.r = 13; p.d16 = 225; p.data["r16"] = 12;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 44; p.county = 19; p.val = 763; p.d = 323; p.r = 440; p.d16 = 330; p.data["r16"] = 489;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 43; p.county = 19; p.val = 1087; p.d = 950; p.r = 137; p.d16 = 960; p.data["r16"] = 57;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 44; p.county = 19; p.val = 584; p.d = 560; p.r = 24; p.d16 = 780; p.data["r16"] = 31;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 43; p.county = 19; p.val = 971; p.d = 859; p.r = 112; p.d16 = 783; p.data["r16"] = 63;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 40; p.county = 19; p.val = 737; p.d = 535; p.r = 202; p.d16 = 583; p.data["r16"] = 330;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 40; p.county = 19; p.val = 561; p.d = 460; p.r = 101; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 41; p.county = 19; p.val = 1019; p.d = 638; p.r = 381; p.d16 = 1154; p.data["r16"] = 620;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 41; p.county = 19; p.val = 313; p.d = 270; p.r = 43; p.d16 = 383; p.data["r16"] = 49;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 42; p.county = 19; p.val = 241; p.d = 214; p.r = 27; p.d16 = 386; p.data["r16"] = 37;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 43; p.county = 19; p.val = 474; p.d = 404; p.r = 70; p.d16 = 499; p.data["r16"] = 99;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 43; p.county = 19; p.val = 579; p.d = 412; p.r = 167; p.d16 = 742; p.data["r16"] = 419;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 41; p.county = 19; p.val = 983; p.d = 644; p.r = 339; p.d16 = 652; p.data["r16"] = 438;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 40; p.county = 19; p.val = 1090; p.d = 868; p.r = 222; p.d16 = 977; p.data["r16"] = 356;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 41; p.county = 19; p.val = 334; p.d = 285; p.r = 49; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 39; p.county = 19; p.val = 433; p.d = 340; p.r = 93; p.d16 = 469; p.data["r16"] = 164;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 38; p.county = 19; p.val = 293; p.d = 261; p.r = 32; p.d16 = 342; p.data["r16"] = 172;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 37; p.county = 19; p.val = 967; p.d = 747; p.r = 220; p.d16 = 867; p.data["r16"] = 299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 62; p.y = 43; p.county = 19; p.val = 572; p.d = 518; p.r = 54; p.d16 = 567; p.data["r16"] = 73;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 64; p.y = 42; p.county = 19; p.val = 460; p.d = 322; p.r = 138; p.d16 = 903; p.data["r16"] = 308;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 63; p.y = 42; p.county = 19; p.val = 323; p.d = 242; p.r = 81; p.d16 = 750; p.data["r16"] = 227;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 42; p.county = 19; p.val = 753; p.d = 594; p.r = 159; p.d16 = 797; p.data["r16"] = 183;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 58; p.y = 42; p.county = 19; p.val = 659; p.d = 496; p.r = 163; p.d16 = 634; p.data["r16"] = 220;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 61; p.y = 40; p.county = 19; p.val = 203; p.d = 168; p.r = 35; p.d16 = 279; p.data["r16"] = 45;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 59; p.y = 38; p.county = 19; p.val = 372; p.d = 267; p.r = 105; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 60; p.y = 44; p.county = 19; p.val = 428; p.d = 225; p.r = 203; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 35; p.county = 29; p.val = 231; p.d = 101; p.r = 130; p.d16 = 85; p.data["r16"] = 146;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 29; p.county = 29; p.val = 302; p.d = 140; p.r = 162; p.d16 = 165; p.data["r16"] = 210;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 39; p.county = 29; p.val = 794; p.d = 265; p.r = 529; p.d16 = 289; p.data["r16"] = 677;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 17; p.y = 26; p.county = 29; p.val = 189; p.d = 138; p.r = 51; p.d16 = 184; p.data["r16"] = 89;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 62; p.county = 29; p.val = 533; p.d = 412; p.r = 121; p.d16 = 519; p.data["r16"] = 162;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 52; p.county = 29; p.val = 557; p.d = 373; p.r = 184; p.d16 = 480; p.data["r16"] = 253;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 32; p.county = 29; p.val = 360; p.d = 124; p.r = 236; p.d16 = 154; p.data["r16"] = 340;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 13; p.y = 39; p.county = 29; p.val = 318; p.d = 98; p.r = 220; p.d16 = 129; p.data["r16"] = 283;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 33; p.y = 50; p.county = 29; p.val = 246; p.d = 193; p.r = 53; p.d16 = 261; p.data["r16"] = 65;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 1; p.y = 31; p.county = 29; p.val = 197; p.d = 67; p.r = 130; p.d16 = 97; p.data["r16"] = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 32; p.county = 29; p.val = 511; p.d = 134; p.r = 377; p.d16 = 123; p.data["r16"] = 520;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 27; p.y = 45; p.county = 29; p.val = 439; p.d = 264; p.r = 175; p.d16 = 302; p.data["r16"] = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 34; p.county = 29; p.val = 620; p.d = 279; p.r = 341; p.d16 = 300; p.data["r16"] = 406;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 47; p.county = 29; p.val = 119; p.d = 57; p.r = 62; p.d16 = 68; p.data["r16"] = 103;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 44; p.county = 29; p.val = 392; p.d = 175; p.r = 217; p.d16 = 239; p.data["r16"] = 286;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 48; p.county = 29; p.val = 288; p.d = 224; p.r = 64; p.d16 = 367; p.data["r16"] = 144;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 38; p.county = 29; p.val = 506; p.d = 208; p.r = 298; p.d16 = 230; p.data["r16"] = 407;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 4; p.y = 39; p.county = 29; p.val = 264; p.d = 95; p.r = 169; p.d16 = 184; p.data["r16"] = 293;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 12; p.y = 32; p.county = 29; p.val = 191; p.d = 91; p.r = 100; p.d16 = 96; p.data["r16"] = 109;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 29; p.y = 31; p.county = 29; p.val = 284; p.d = 71; p.r = 213; p.d16 = 93; p.data["r16"] = 305;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 11; p.y = 24; p.county = 29; p.val = 602; p.d = 418; p.r = 184; p.d16 = 485; p.data["r16"] = 278;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 16; p.y = 35; p.county = 29; p.val = 388; p.d = 98; p.r = 290; p.d16 = 120; p.data["r16"] = 404;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 10; p.y = 41; p.county = 29; p.val = 261; p.d = 82; p.r = 179; p.d16 = 121; p.data["r16"] = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 20; p.y = 43; p.county = 29; p.val = 542; p.d = 280; p.r = 262; p.d16 = 302; p.data["r16"] = 311;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 38; p.county = 29; p.val = 468; p.d = 319; p.r = 149; p.d16 = 400; p.data["r16"] = 203;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 22; p.y = 42; p.county = 29; p.val = 574; p.d = 486; p.r = 88; p.d16 = 672; p.data["r16"] = 104;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 39; p.county = 29; p.val = 614; p.d = 276; p.r = 338; p.d16 = 274; p.data["r16"] = 432;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 9; p.y = 29; p.county = 29; p.val = 196; p.d = 91; p.r = 105; p.d16 = 118; p.data["r16"] = 121;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 34; p.county = 29; p.val = 202; p.d = 35; p.r = 167; p.d16 = 42; p.data["r16"] = 235;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 43; p.y = 72; p.county = 29; p.val = 794; p.d = 203; p.r = 591; p.d16 = 219; p.data["r16"] = 635;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 21; p.y = 37; p.county = 29; p.val = 763; p.d = 255; p.r = 508; p.d16 = 201; p.data["r16"] = 462;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 24; p.y = 40; p.county = 29; p.val = 467; p.d = 269; p.r = 198; p.d16 = 308; p.data["r16"] = 282;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 30; p.y = 13; p.county = 35; p.val = 698; p.d = 358; p.r = 340; p.d16 = 443; p.data["r16"] = 510;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 26; p.y = 18; p.county = 35; p.val = 363; p.d = 158; p.r = 205; p.d16 = 189; p.data["r16"] = 268;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 22; p.county = 35; p.val = 530; p.d = 265; p.r = 265; p.d16 = 299; p.data["r16"] = 363;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 25; p.y = 25; p.county = 35; p.val = 460; p.d = 231; p.r = 229; p.d16 = 273; p.data["r16"] = 323;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 19; p.y = 19; p.county = 35; p.val = 545; p.d = 284; p.r = 261; p.d16 = 354; p.data["r16"] = 360;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 34; p.y = 19; p.county = 35; p.val = 343; p.d = 128; p.r = 215; p.d16 = 209; p.data["r16"] = 299;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 39; p.y = 17; p.county = 35; p.val = 597; p.d = 260; p.r = 337; p.d16 = 336; p.data["r16"] = 426;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 35; p.y = 24; p.county = 35; p.val = 576; p.d = 230; p.r = 346; p.d16 = 293; p.data["r16"] = 450;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 30; p.county = 35; p.val = 778; p.d = 221; p.r = 557; p.d16 = 175; p.data["r16"] = 577;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 34; p.county = 35; p.val = 1347; p.d = 430; p.r = 917; p.d16 = 461; p.data["r16"] = 1062;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 36; p.county = 35; p.val = 1027; p.d = 427; p.r = 600; p.d16 = 396; p.data["r16"] = 726;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 36; p.county = 35; p.val = 562; p.d = 148; p.r = 414; p.d16 = 120; p.data["r16"] = 495;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 32; p.county = 35; p.val = 1681; p.d = 616; p.r = 1065; p.d16 = 482; p.data["r16"] = 1154;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 28; p.y = 17; p.county = 35; p.val = 407; p.d = 222; p.r = 185; p.d16 = 297; p.data["r16"] = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 34; p.county = 35; p.val = 711; p.d = 268; p.r = 443; p.d16 = 205; p.data["r16"] = 654;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 25; p.county = 35; p.val = 429; p.d = 206; p.r = 223; p.d16 = 271; p.data["r16"] = 303;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 40; p.y = 34; p.county = 35; p.val = 518; p.d = 167; p.r = 351; p.d16 = 227; p.data["r16"] = 415;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 32; p.county = 35; p.val = 703; p.d = 263; p.r = 440; p.d16 = 274; p.data["r16"] = 532;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 38; p.county = 35; p.val = 1048; p.d = 593; p.r = 455; p.d16 = 629; p.data["r16"] = 640;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 31; p.county = 35; p.val = 597; p.d = 253; p.r = 344; p.d16 = 248; p.data["r16"] = 387;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 42; p.y = 40; p.county = 35; p.val = 470; p.d = 353; p.r = 117; p.d16 = 379; p.data["r16"] = 85;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 41; p.county = 35; p.val = 214; p.d = 59; p.r = 155; p.d16 = 69; p.data["r16"] = 189;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 31; p.county = 35; p.val = 558; p.d = 219; p.r = 339; p.d16 = 204; p.data["r16"] = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 35; p.county = 35; p.val = 848; p.d = 416; p.r = 432; p.d16 = 277; p.data["r16"] = 314;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 35; p.county = 35; p.val = 1426; p.d = 761; p.r = 665; p.d16 = 757; p.data["r16"] = 905;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 39; p.county = 35; p.val = 658; p.d = 511; p.r = 147; p.d16 = 636; p.data["r16"] = 219;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 35; p.county = 35; p.val = 1159; p.d = 600; p.r = 559; p.d16 = 813; p.data["r16"] = 1143;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 36; p.county = 35; p.val = 264; p.d = 79; p.r = 185; p.d16 = 99; p.data["r16"] = 216;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 38; p.county = 35; p.val = 880; p.d = 296; p.r = 584; p.d16 = 273; p.data["r16"] = 706;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 36; p.county = 35; p.val = 305; p.d = 109; p.r = 196; p.d16 = 103; p.data["r16"] = 257;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 32; p.county = 35; p.val = 1046; p.d = 439; p.r = 607; p.d16 = 481; p.data["r16"] = 878;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 37; p.county = 35; p.val = 736; p.d = 229; p.r = 507; p.d16 = 200; p.data["r16"] = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 34; p.county = 35; p.val = 774; p.d = 251; p.r = 523; p.d16 = 252; p.data["r16"] = 586;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 36; p.county = 35; p.val = 1380; p.d = 744; p.r = 636; p.d16 = 671; p.data["r16"] = 759;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 32; p.county = 35; p.val = 571; p.d = 221; p.r = 350; p.d16 = 242; p.data["r16"] = 515;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 33; p.county = 35; p.val = 811; p.d = 294; p.r = 517; p.d16 = 264; p.data["r16"] = 594;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 50; p.y = 36; p.county = 35; p.val = 728; p.d = 233; p.r = 495; p.d16 = 197; p.data["r16"] = 585;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 34; p.county = 35; p.val = 446; p.d = 195; p.r = 251; p.d16 = 271; p.data["r16"] = 352;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 34; p.county = 35; p.val = 377; p.d = 178; p.r = 199; p.d16 = 180; p.data["r16"] = 241;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 34; p.county = 35; p.val = 1005; p.d = 423; p.r = 582; p.d16 = 423; p.data["r16"] = 801;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 31; p.county = 35; p.val = 905; p.d = 490; p.r = 415; p.d16 = 534; p.data["r16"] = 525;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 33; p.county = 35; p.val = 622; p.d = 196; p.r = 426; p.d16 = 191; p.data["r16"] = 472;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 40; p.county = 35; p.val = 1369; p.d = 745; p.r = 624; p.d16 = 785; p.data["r16"] = 882;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 23; p.y = 15; p.county = 35; p.val = 265; p.d = 178; p.r = 87; p.d16 = 237; p.data["r16"] = 122;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 37; p.county = 35; p.val = 1228; p.d = 620; p.r = 608; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 52; p.y = 33; p.county = 35; p.val = 1026; p.d = 460; p.r = 566; p.d16 = 462; p.data["r16"] = 776;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 55; p.y = 40; p.county = 35; p.val = 1344; p.d = 667; p.r = 677; p.d16 = 676; p.data["r16"] = 803;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 37; p.county = 35; p.val = 599; p.d = 322; p.r = 277; p.d16 = 807; p.data["r16"] = 989;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 31; p.county = 35; p.val = 1058; p.d = 429; p.r = 629; p.d16 = 391; p.data["r16"] = 670;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 32; p.county = 35; p.val = 763; p.d = 280; p.r = 483; p.d16 = 255; p.data["r16"] = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 45; p.y = 29; p.county = 35; p.val = 1190; p.d = 531; p.r = 659; p.d16 = 518; p.data["r16"] = 890;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 39; p.county = 35; p.val = 1096; p.d = 527; p.r = 569; p.d16 = 463; p.data["r16"] = 674;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 56; p.y = 38; p.county = 35; p.val = 708; p.d = 476; p.r = 232; p.d16 = 625; p.data["r16"] = 265;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 29; p.county = 35; p.val = 998; p.d = 414; p.r = 584; p.d16 = 341; p.data["r16"] = 794;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 49; p.y = 28; p.county = 35; p.val = 645; p.d = 309; p.r = 336; p.d16 = 285; p.data["r16"] = 538;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 47; p.y = 33; p.county = 35; p.val = 601; p.d = 269; p.r = 332; p.d16 = 0; p.data["r16"] = 0;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 38; p.county = 35; p.val = 970; p.d = 453; p.r = 517; p.d16 = 447; p.data["r16"] = 639;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 51; p.y = 30; p.county = 35; p.val = 673; p.d = 493; p.r = 180; p.d16 = 514; p.data["r16"] = 171;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 44; p.y = 26; p.county = 35; p.val = 380; p.d = 206; p.r = 174; p.d16 = 256; p.data["r16"] = 217;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 35; p.county = 35; p.val = 1289; p.d = 743; p.r = 546; p.d16 = 752; p.data["r16"] = 773;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 33; p.county = 35; p.val = 417; p.d = 190; p.r = 227; p.d16 = 589; p.data["r16"] = 793;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 48; p.y = 34; p.county = 35; p.val = 317; p.d = 133; p.r = 184; p.d16 = 118; p.data["r16"] = 243;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 54; p.y = 37; p.county = 35; p.val = 735; p.d = 314; p.r = 421; p.d16 = 347; p.data["r16"] = 554;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 30; p.county = 35; p.val = 360; p.d = 129; p.r = 231; p.d16 = 121; p.data["r16"] = 351;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 46; p.y = 32; p.county = 35; p.val = 559; p.d = 269; p.r = 290; p.d16 = 262; p.data["r16"] = 459;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 53; p.y = 37; p.county = 35; p.val = 675; p.d = 354; p.r = 321; p.d16 = 350; p.data["r16"] = 470;
points[i]=p;i++;}
if (1==1){ Point p;
p.x = 57; p.y = 38; p.county = 35; p.val = 465; p.d = 313; p.r = 152; p.d16 = 321; p.data["r16"] = 178;
points[i]=p;i++;}
np = 415;
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
				int r16 = m.pixels[i][removeSeam[i]].data["r16"]+m.pixels[i][removeSeam[i]-1].data["r16"]+m.pixels[i][removeSeam[i]+1].data["r16"];
				int d16 = m.pixels[i][removeSeam[i]].d16+m.pixels[i][removeSeam[i]-1].d16+m.pixels[i][removeSeam[i]+1].d16;
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
				
				m.pixels[i][removeSeam[i]-1].data["r16"] = r16/4;
				m.pixels[i][removeSeam[i]].data["r16"] = r16 - r16/4 - r16/4 - r16/4;
				m.pixels[i][removeSeam[i]+1].data["r16"] = r16/4;
				m.pixels[i][removeSeam[i]+2].data["r16"] = r16/4;
				
				m.pixels[i][removeSeam[i]-1].d16 = d16/4;
				m.pixels[i][removeSeam[i]].d16 = d16 - d16/4 - d16/4 - d16/4;
				m.pixels[i][removeSeam[i]+1].d16 = d16/4;
				m.pixels[i][removeSeam[i]+2].d16 = d16/4;
				
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
				int r16 = m.pixels[i][removeSeam[i]].data["r16"]+m.pixels[i][removeSeam[i]+1].data["r16"];
				int d16 = m.pixels[i][removeSeam[i]].d16+m.pixels[i][removeSeam[i]+1].d16;
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
				
				m.pixels[i][removeSeam[i]].data["r16"] = r16 - r16/3 - r16/3;
				m.pixels[i][removeSeam[i]+1].data["r16"] = r16/3;
				m.pixels[i][removeSeam[i]+2].data["r16"] = r16/3;
				
				m.pixels[i][removeSeam[i]].d16 = d16 - d16/3 - d16/3;
				m.pixels[i][removeSeam[i]+1].d16 = d16/3;
				m.pixels[i][removeSeam[i]+2].d16 = d16/3;
				
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
				int r16 = m.pixels[i][removeSeam[i]].data["r16"];
				int d16 = m.pixels[i][removeSeam[i]].d16;
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
				
				m.pixels[i][removeSeam[i]].data["r16"] = r16/2;
				m.pixels[i][removeSeam[i]+1].data["r16"] = r16 - r16/2;
				
				m.pixels[i][removeSeam[i]].d16 = d16/2;
				m.pixels[i][removeSeam[i]+1].d16 = d16 - d16/2;
				
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
				int r16 = m.pixels[removeSeam[ii]][ii].data["r16"]+m.pixels[removeSeam[ii]-1][ii].data["r16"]+m.pixels[removeSeam[ii]+1][ii].data["r16"];
				int d16 = m.pixels[removeSeam[ii]][ii].d16+m.pixels[removeSeam[ii]-1][ii].d16+m.pixels[removeSeam[ii]+1][ii].d16;
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
				
				m.pixels[removeSeam[ii]-1][ii].data["r16"]=r16/4;
				m.pixels[removeSeam[ii]][ii].data["r16"]=r16 - r16/4 - r16/4 - r16/4;
				m.pixels[removeSeam[ii]+1][ii].data["r16"]=r16/4;
				m.pixels[removeSeam[ii]+2][ii].data["r16"]= r16/4;
				
				m.pixels[removeSeam[ii]-1][ii].d16=d16/4;
				m.pixels[removeSeam[ii]][ii].d16=d16 - d16/4 - d16/4 - d16/4;
				m.pixels[removeSeam[ii]+1][ii].d16=d16/4;
				m.pixels[removeSeam[ii]+2][ii].d16= d16/4;
				
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
				int r16 = m.pixels[removeSeam[ii]][ii].data["r16"]+m.pixels[removeSeam[ii]+1][ii].data["r16"];
				int d16 = m.pixels[removeSeam[ii]][ii].d16+m.pixels[removeSeam[ii]+1][ii].d16;
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
				
				m.pixels[removeSeam[ii]][ii].data["r16"]=r16 - r16/3 - r16/3;
				m.pixels[removeSeam[ii]+1][ii].data["r16"]=r16/3;
				m.pixels[removeSeam[ii]+2][ii].data["r16"]= r16/3;
				
				m.pixels[removeSeam[ii]][ii].d16=d16 - d16/3 - d16/3;
				m.pixels[removeSeam[ii]+1][ii].d16=d16/3;
				m.pixels[removeSeam[ii]+2][ii].d16= d16/3;
				
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
				int r16 = m.pixels[removeSeam[ii]][ii].data["r16"];
				int d16 = m.pixels[removeSeam[ii]][ii].d16;
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
				
				m.pixels[removeSeam[ii]][ii].data["r16"]=r16/2;
				m.pixels[removeSeam[ii]+1][ii].data["r16"]= r16 - r16/2;
				
				m.pixels[removeSeam[ii]][ii].d16=d16/2;
				m.pixels[removeSeam[ii]+1][ii].d16= d16 - d16/2;
				
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
				int r16 = m.pixels[i][removeSeam[i]].data["r16"]+m.pixels[i][removeSeam[i]-1].data["r16"]+m.pixels[i][removeSeam[i]+1].data["r16"];
				m.pixels[i][removeSeam[i]].data["r16"]=r16 - r16/2;
				m.pixels[i][removeSeam[i]-1].data["r16"]= r16/2;
				int d16 = m.pixels[i][removeSeam[i]].d16+m.pixels[i][removeSeam[i]-1].d16+m.pixels[i][removeSeam[i]+1].d16;
				m.pixels[i][removeSeam[i]].d16=d16 - d16/2;
				m.pixels[i][removeSeam[i]-1].d16= d16/2;
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
				m.pixels[i][removeSeam[i]].data["r16"] +=m.pixels[i][removeSeam[i]+1].data["r16"];
				m.pixels[i][removeSeam[i]].d16 +=m.pixels[i][removeSeam[i]+1].d16;
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
				m.pixels[i][removeSeam[i]-1].data["r16"] +=m.pixels[i][removeSeam[i]].data["r16"];
				m.pixels[i][removeSeam[i]-1].d16 +=m.pixels[i][removeSeam[i]].d16;
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
				int r16 = m.pixels[removeSeam[ii]][ii].data["r16"]+m.pixels[removeSeam[ii]-1][ii].data["r16"]+m.pixels[removeSeam[ii]+1][ii].data["r16"];
				m.pixels[removeSeam[ii]][ii].data["r16"]=r16 - r16/2;
				m.pixels[removeSeam[ii]-1][ii].data["r16"]= r16/2;
				int d16 = m.pixels[removeSeam[ii]][ii].d16+m.pixels[removeSeam[ii]-1][ii].d16+m.pixels[removeSeam[ii]+1][ii].d16;
				m.pixels[removeSeam[ii]][ii].d16=d16 - d16/2;
				m.pixels[removeSeam[ii]-1][ii].d16= d16/2;
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
				m.pixels[removeSeam[ii]][ii].data["r16"]+=m.pixels[removeSeam[ii]+1][ii].data["r16"];
				m.pixels[removeSeam[ii]][ii].d16+=m.pixels[removeSeam[ii]+1][ii].d16;
				
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
				m.pixels[removeSeam[ii]-1][ii].data["r16"]+=m.pixels[removeSeam[ii]][ii].data["r16"];
				m.pixels[removeSeam[ii]-1][ii].d16+=m.pixels[removeSeam[ii]][ii].d16;
				
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
			p.data["r16"] = 0;
			p.d16 = 0;
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
	np =0;//will get set to right value in scPoints()
	points = scPoints();
	
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
				pixels[i][ii].d16 += points[pixelMap[i][ii]].d16*100/points[pixelMap[i][ii]].npix;
				pixels[i][ii].data["r16"] += points[pixelMap[i][ii]].data["r16"]*100/points[pixelMap[i][ii]].npix;
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
				pixels[i][ii].d16 += points[minI].d16*100/points[minI].npix;
				pixels[i][ii].data["r16"] += points[minI].data["r16"]*100/points[minI].npix;
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
			pixels[i][ii].d16 += points[minI].d16*100/points[minI].npix;
			pixels[i][ii].data["r16"] += points[minI].data["r16"]*100/points[minI].npix;
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
					std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county)+","+std::to_string(p.d)+","+std::to_string(p.r)+","+std::to_string(p.d16)+","+std::to_string(p.data["r16"]);
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
			std::string pointStr = std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.val)+","+std::to_string(i)+","+std::to_string(ii)+","+std::to_string(p.county)+","+std::to_string(p.d)+","+std::to_string(p.r)+","+std::to_string(p.d16)+","+std::to_string(p.data["r16"]);
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
