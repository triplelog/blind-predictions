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
  	console.log(jsStr);
});

std::map<int,std::vector<double> > correlations;
std::map<int,std::vector<int> > correlationsInt;
std::vector<std::string> states;
std::vector<int> evs;
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

void makePrediction(int year) {
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
	int bidenWins = 0;
	std::map<int,int> evData;
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
	for (i=0;i<1000;i++){
		std::vector<int> elonew = elo;
		int bidenEV = 0;
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
				stateData[thisstate]++;
				
				
			}
			else {
				
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
			bidenWins++;
		}
		if (evData.find(bidenEV) == evData.end()){
			evData[bidenEV] = 1;
		}
		else {
			evData[bidenEV]++;
		}
		
		
	}
	console_log(bidenWins);
	for (i=0;i<51;i++){
		if (stateData[i] > 100 && stateData[i] < 900){
			//string_log(states[i].c_str());
			//console_log(stateData[i]);
			//console_log(statePairsMI[i]);
			//console_log(stateData[i]*stateData[22]/1000);
			double nullprob = stateData[22];
			nullprob /= 1000;
			int diff = statePairsMI[i] - stateData[i]*stateData[22]/1000;
			double stdev = stateData[i]*nullprob*(1-nullprob);
			double z = diff/stdev;
			int diffmax = stateData[i] - stateData[i]*stateData[22]/1000;
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
	seed = 7;
	durationRand = 0;
	predictions16 = createPredictions16();
	predictions20 = createPredictions20();
	

}

int main() {
	
	initialRun();
	durationRand = 0;
	auto a11 = std::chrono::high_resolution_clock::now();
	makePrediction(2016);
	console_log(durationRand/1000000);
	durationRand = 0;
	makePrediction(2020);
	auto a22 = std::chrono::high_resolution_clock::now();
	int durationTotal = duration_cast<std::chrono::milliseconds>(a22-a11).count();
	console_log(durationRand/1000000);
	console_log(durationTotal);
	
	return 1;
}
