#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h> 
#include <ctype.h>
#include <cmath>
#include <map>
#include <numeric>
#include <chrono>
#include <vector>
#include <unistd.h>
#include <future>

#include "data.cpp"

#include <emscripten/emscripten.h>

EM_JS(void, console_log, (int x), {
  console.log(x);
});
EM_JS(void, string_log, (const char* x), {
  console.log(UTF8ToString(x));
});
EM_JS(void, send_map, (const char* x), {
	var statesOut = [];
	var statesStr = UTF8ToString(x);
	var jsStr = "";
	for (var i=0;i<51;i++){
		statesOut.push(statesStr[i]);
		jsStr += statesStr[i]+"\n";
		
	}
  	//console.log(jsStr);
});
EM_JS(void, send_results, (const char* x), {
	var xStr = UTF8ToString(x).split(",");
	var wins = {};
	wins["D"]=xStr[0];
	wins["R"]=xStr[1];
	wins["T"]=xStr[2];
	wins["DH"]=xStr[3];
	wins["RH"]=xStr[4];
	wins["TH"]=xStr[5];
	wins["DV"]=xStr[6];
	wins["RV"]=xStr[7];
	wins["TV"]=xStr[8];
	wins["ME"]=xStr[9];
	wins["MS"]=xStr[10];
	var hist = xStr[11].split("|");
	var minH = 51;
	var maxH = 0;
	for (var i=0;i<hist.length;i++){
		if (hist[i]>0 && i < minH){
			minH = i;
		}
		else if (hist[i]>0 && i > maxH){
			maxH = i;
		}
	}
	var histS = {};
	for (var i=minH;i<=maxH;i++){
		histS[i]=hist[i];
	}
	wins["HistogramS"]=histS;
	updateWins(wins);
});
EM_JS(void, send_ready, (), {
  cpp_ready();
});

std::map<int,std::vector<double> > correlations;
std::map<int,std::vector<int> > correlationsInt;
std::vector<std::string> states;
std::vector<int> evs;
std::vector<int> vepevs;
std::vector<double> predictions16;
std::vector<double> predictions20;
long long durationRand;
int seed;

int predictionToElo(double prediction, int counter){
	double e = log(1/prediction-1)*-1*(75-counter)/log(10.0);
	return round(e);
	
}
double predictionFromElo(int elo){
	double e = 0-elo;
	return 1.0/(1+pow(10.0,e/75));
	
}



extern "C" {

void updateProbability(int state, double p, int year) {
	if (year == 2016){
		predictions16[state] = p;
	}
	else if (year == 2020){
		predictions20[state] = p;
	}
	
}

void makePrediction(int year, int n) {
	std::vector<double> predictions;
	int i; int ii; int iii;
	if (year == 2016){
		for (i = 0;i<51;i++){
			predictions.push_back(predictions16[i]);
		}
	}
	else if (year == 2020){
		for (i = 0;i<51;i++){
			predictions.push_back(predictions20[i]);
		}
	}
	srand(seed);
	std::vector<int> elo;
	
	for (i = 0;i<predictions.size();i++){
		elo.push_back(predictionToElo(predictions[i],0));
	}
	//predict one state at a time
	int dWins[4] = {0,0,0,0};
	int rWins[4] = {0,0,0,0};
	int ties[4] = {0,0,0,0};
	std::map<int,int> evData;
	std::map<int,int> senateData;
	std::map<int,int> stateData;
	std::map<int,int> stateMax;
	std::map<int,int> statePairsMI;
	std::string statesOut = "";
	for (ii=0;ii<51;ii++){
		stateData[ii]=0;
		stateMax[ii]=-2000;
		statePairsMI[ii]=0;
		int x = round(elo[ii]*1.0/20)+5;
		if (x < 1){
			x = 1;
		}
		if (x > 9){
			x = 9;
		}
		statesOut += std::to_string(x);
	}
	send_map(statesOut.c_str());
	for (i=0;i<n;i++){
		std::vector<int> elonew = elo;
		int bidenEV = 0;
		int dHEV = 0;
		int dVEPEV = 0;
		int dSen = 0;
		std::map<int,bool> doneYet;
		for (ii=0;ii<51;ii++){
			doneYet[ii]=false;
		}
		for (ii=0;ii<51;ii++){
			//auto a1 = std::chrono::high_resolution_clock::now();
			int thisstate = rand() % 51;
			while (doneYet[thisstate]){
				thisstate = rand() % 51;
			}
			//auto a2 = std::chrono::high_resolution_clock::now();
			//durationRand += duration_cast<std::chrono::nanoseconds>(a2-a1).count();
			doneYet[thisstate]=true;
			if (elonew[thisstate]>stateMax[thisstate]){
				stateMax[thisstate]=elonew[thisstate];
			}
			
			
			int r = rand() % 1000;
			double rr = r;
			rr /= 1000;
			//convert rr to vote percentage
			int eloR = predictionToElo(rr,ii);
			
			
			if (elonew[thisstate]+eloR > 0){ // Biden wins
				
				bidenEV += evs[thisstate];
				dHEV += evs[thisstate]-2;
				dVEPEV += vepevs[thisstate];
				stateData[thisstate]++;
				dSen++;
				
				
			}
			if (thisstate == 21){//Maine
				if (elonew[thisstate]+eloR > -100){ //Biden wins 1st
					bidenEV++; dHEV++; dVEPEV+=10;
				}
				if (elonew[thisstate]+eloR > 100){ //Biden wins 2nd
					bidenEV++; dHEV++; dVEPEV+=10;
				}
			}
			if (thisstate == 29){//Nebraska
				if (elonew[thisstate]+eloR > -60){ //Biden wins 1st
					bidenEV++; dHEV++; dVEPEV+=9;
				}
				if (elonew[thisstate]+eloR > -200){ //Biden wins 2nd
					bidenEV++; dHEV++; dVEPEV+=9;
				}
				if (elonew[thisstate]+eloR > 300){ //Biden wins 3rd
					bidenEV++; dHEV++; dVEPEV+=9;
				}
			}
			
			if (eloR < 0){
				eloR = -1*round(pow(-1*eloR,.8-ii/150));
			}
			else {
				eloR = round(pow(eloR,.8-ii/150));
			}
			
			auto a1 = std::chrono::high_resolution_clock::now();
			iii = 0;
			for (std::map<int,bool>::iterator it = doneYet.begin() ; it != doneYet.end(); ++it){
  
				//int elodiff = eloR*correlationsInt[thisstate][iii]/1000;
				if (it->second){
					iii++; continue;
				}
				int c = correlationsInt[thisstate][iii];
				if (eloR <= -10 || eloR >= 10 || c >= 10 ){
					elonew[iii]+=eloR*c/100;
				}
				iii++;
			}
			auto a2 = std::chrono::high_resolution_clock::now();
			durationRand += duration_cast<std::chrono::nanoseconds>(a2-a1).count();
		}
		if (bidenEV >= 270){
			dWins[0]++;
		}
		else if (bidenEV <= 268){
			rWins[0]++;
		}
		else {
			ties[0]++;
		}
		if (dHEV >= 219){
			dWins[1]++;
		}
		else if (dHEV <= 217){
			rWins[1]++;
		}
		else {
			ties[1]++;
		}
		if (dVEPEV >= 2182){
			dWins[2]++;
		}
		else if (dVEPEV <= 2181){
			rWins[2]++;
		}
		else {
			ties[2]++;
		}
		if (evData.find(bidenEV) == evData.end()){
			evData[bidenEV] = 1;
		}
		else {
			evData[bidenEV]++;
		}
		if (senateData.find(dSen) == senateData.end()){
			senateData[dSen] = 1;
		}
		else {
			senateData[dSen]++;
		}
		
		if (i % 100 == 99){
			std::string resultStr = "";
			resultStr += std::to_string(dWins[0])+",";
			resultStr += std::to_string(rWins[0])+",";
			resultStr += std::to_string(ties[0])+",";
			
			resultStr += std::to_string(dWins[1])+",";
			resultStr += std::to_string(rWins[1])+",";
			resultStr += std::to_string(ties[1])+",";
			
			resultStr += std::to_string(dWins[2])+",";
			resultStr += std::to_string(rWins[2])+",";
			resultStr += std::to_string(ties[2])+",";
			int medEV = 0;
			int count = 0;
			for (ii=0;ii<539;ii++){
				if (evData.find(ii) != evData.end()){
					count+= evData[ii];
				}
				if (count >= i/2){
					medEV = ii;
					break;
				}
			}
			resultStr += std::to_string(medEV)+",";
			medEV = 0;
			count = 0;
			for (ii=0;ii<51;ii++){
				if (senateData.find(ii) != senateData.end()){
					count+= senateData[ii];
				}
				if (count >= i/2){
					medEV = ii;
					break;
				}
			}
			resultStr += std::to_string(medEV)+",";
			for (ii=0;ii<51;ii++){
				if (senateData.find(ii) != senateData.end()){
					resultStr += std::to_string(senateData[ii])+"|";
				}
				else {
					resultStr += "0|";
				}
			}
			resultStr += "0";
			send_results(resultStr.c_str());
		}
		
	}
	//console_log(dWins[0]);
	
	for (i=0;i<51;i++){
		if (stateData[i] > n/10 && stateData[i] < n*9/10){
			//string_log(states[i].c_str());
			//console_log(stateData[i]);
			//console_log(statePairsMI[i]);
			//console_log(stateData[i]*stateData[22]/1000);
			double nullprob = stateData[22];
			nullprob /= n;
			int diff = statePairsMI[i] - stateData[i]*stateData[22]/n;
			double stdev = stateData[i]*nullprob*(1-nullprob);
			double z = diff/stdev;
			int diffmax = stateData[i] - stateData[i]*stateData[22]/n;
			double zmax = diffmax/stdev;
			//console_log(round(z*1000/zmax));
			//console_log(round(correlationsInt[22][i]));
		}
		
	}
	for (i=0;i<539;i++){
		if (evData.find(i) != evData.end()){
			//std::cout << i << ", " << evData[i] << "\n";
			//console_log(i);
			//console_log(evData[i]);
		}
	}
}

}

void initialRun(){
	correlations = createCorrelations();
	int i; int ii;
	for (i=0;i<51;i++){
		std::vector<int> v;
		v.resize(51);
		correlationsInt[i] = v;
		for (ii=0;ii<51;ii++){
			correlationsInt[i][ii] = round(pow(correlations[i][ii],5)*220);
		}
	}
	states = createStates();
	evs = createEV();
	vepevs = createVEPEV();
	evs[21]=2;
	evs[29]=2;
	vepevs[21]=0;
	vepevs[29]=0;
	seed = 7;
	durationRand = 0;
	predictions16 = createPredictions16();
	predictions20 = createPredictions20();
	

}

int main() {
	
	initialRun();
	durationRand = 0;
	auto a11 = std::chrono::high_resolution_clock::now();
	//makePrediction(2016,100);
	//console_log(durationRand/1000000);
	durationRand = 0;
	//makePrediction(2020,100);
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	//console_log(durationRand/1000000);
	//console_log(durationTotal);
	send_ready();
	
	return 1;
}
