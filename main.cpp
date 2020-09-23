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

std::map<int,std::vector<double> > correlations;
std::vector<std::string> states;
std::vector<int> evs;
std::vector<double> predictions16;
std::vector<double> predictions20;
int seed;

int predictionToElo(double prediction){
	double e = log(1/prediction-1)*-400/log(10.0);
	return 1500+round(e);
	
}
double predictionFromElo(int elo){
	double e = 1500-elo;
	return 1/(1+pow(10,e/400));
	
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
	for (i=0;i<1000;i++){
		std::vector<int> elonew = elo;
		int bidenEV = 0;
		std::map<int,bool> doneYet;
		for (ii=0;ii<51;ii++){
			int thisstate = rand() % 51;
			while (doneYet.find(thisstate) != doneYet.end()){
				thisstate = rand() % 51;
			}
			doneYet[thisstate]=true;
			double pred = predictionFromElo(elonew[thisstate]);
			//std::cout << "Biden prob for "+states[ii] + " is " << pred << " not " << predictionFromElo(elo[ii]) << "\n";
			int r = rand() % 1000;
			double rr = r;
			rr /= 1000;
			int elodiff = 0;
			int eloNum = 1;
			int eloDen = 10;
			if (rr < pred){ // Biden wins
				//elodiff = 2300 - elonew[thisstate];
				//elodiff *= eloNum;
				//elodiff /= eloDen;
				int pt = round((1-pred)*1000/pred);
				elodiff = (elonew[thisstate] - 700)*eloNum/eloDen*pt/1000;
				//std::cout << "Biden wins "+states[ii] << "\n";
				bidenEV += evs[thisstate];
			}
			else {
				elodiff = 700 - elonew[thisstate];
				elodiff *= eloNum;
				elodiff /= eloDen;
				//std::cout << "Biden loses "+states[ii] << "\n";
			}
			for (iii=0;iii<51;iii++){
				elonew[iii]=elonew[iii]+elodiff*correlations[thisstate][iii];
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
	for (i=0;i<539;i++){
		if (evData.find(i) != evData.end()){
			//std::cout << i << ", " << evData[i] << "\n";
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
