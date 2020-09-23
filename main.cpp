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
std::vector<double> predictions;
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

void updateProbability(int state, double p) {
	predictions[state] = p;
	console_log(1);
}

void makePrediction() {
	srand(seed);
	std::vector<int> elo;
	int i; int ii; int iii;
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
			int eloDen = 5;
			if (rr < pred){ // Biden wins
				elodiff = 2300 - elonew[thisstate];
				elodiff *= eloNum;
				elodiff /= eloDen;
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
	predictions = createPredictions();
	

}

int main() {
	
	initialRun();
	makePrediction();
	return 1;
}
