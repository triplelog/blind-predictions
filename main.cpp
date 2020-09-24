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

std::map<int,std::vector<double> > correlations;
std::vector<std::string> states;
std::vector<int> evs;
std::vector<double> predictions16;
std::vector<double> predictions20;
int seed;

int predictionToElo(double prediction){
	double e = log(1/prediction-1)*-75/log(10.0);
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
		//std::cout << predictionToElo(predictions[i]) << "\n";
		elo.push_back(predictionToElo(predictions[i]));
	}
	//predict one state at a time
	int bidenWins = 0;
	std::map<int,int> evData;
	std::map<int,int> stateData;
	std::map<int,int> stateMax;
	std::map<int,int> statePairsMI;
	for (ii=0;ii<51;ii++){
		stateData[ii]=0;
		stateMax[ii]=-2000;
		statePairsMI[ii]=0;
	}
	for (i=0;i<1000;i++){
		std::vector<int> elonew = elo;
		int bidenEV = 0;
		std::map<int,bool> doneYet;
		for (ii=0;ii<51;ii++){
			int thisstate = rand() % 51;
			while (doneYet.find(thisstate) != doneYet.end()){
				thisstate = rand() % 51;
			}
			doneYet[thisstate]=false;
			if (elonew[thisstate]>stateMax[thisstate]){
				stateMax[thisstate]=elonew[thisstate];
			}
			
			
			int r = rand() % 1000;
			double rr = r;
			rr /= 1000;
			//convert rr to vote percentage
			int eloR = predictionToElo(rr);
			
			
			if (elonew[thisstate]+eloR > 0){ // Biden wins
				
				bidenEV += evs[thisstate];
				stateData[thisstate]++;
				doneYet[thisstate]=true;
				
				if (thisstate == 22){
					for (iii=0;iii<51;iii++){
						if (doneYet.find(iii) != doneYet.end()){
							if (doneYet[iii]){
								statePairsMI[iii]++;
							}
						}
					}
				}
				else if (doneYet.find(22) != doneYet.end()){
					if (doneYet[22]){
						statePairsMI[thisstate]++;
					}
				}
			}
			else {
				
			}
			
			for (iii=0;iii<51;iii++){
				int elodiff = round(eloR*pow(correlations[thisstate][iii],5)*1);
				elonew[iii]=elonew[iii]+elodiff;
			}
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
			string_log(states[i].c_str());
			console_log(stateData[i]);
			//console_log(statePairsMI[i]);
			//console_log(stateData[i]*stateData[22]/1000);
			double nullprob = stateData[22];
			nullprob /= 1000;
			int diff = statePairsMI[i] - stateData[i]*stateData[22]/1000;
			double stdev = stateData[i]*nullprob*(1-nullprob);
			double z = diff/stdev;
			console_log(round(z*1000));
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
	states = createStates();
	evs = createEV();
	seed = 7;
	predictions16 = createPredictions16();
	predictions20 = createPredictions20();
	

}

int main() {
	
	initialRun();
	makePrediction(2016);
	makePrediction(2020);
	return 1;
}
