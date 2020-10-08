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
	var statesStr = UTF8ToString(x).split(",");
	var jsStr = "";
	for (var i=0;i<51;i++){
		statesOut.push(statesStr[i]);
		
	}
  	updateMap(statesOut);
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
	wins["DP"]=xStr[9];
	wins["RP"]=xStr[10];
	wins["TP"]=xStr[11];
	wins["ME"]=xStr[12];
	wins["MHE"]=xStr[13];
	wins["MVE"]=xStr[14];
	wins["MPE"]=xStr[15];
	wins["MS"]=xStr[16];
	var hist = xStr[17].split("|");
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
std::vector<double> results20;
std::vector<double> predictions20Sen;
long long durationRand;
int seed;
int randomness;
int correlationDivisor;
double correlationPower;

int predictionToElo(double prediction, int counter){
	if (prediction <= .00001){prediction = .00001;}
	if (prediction >= .99999){prediction = .99999;}
	double e = log(1/prediction-1)*-1*(randomness+1-counter)/log(10.0);
	return round(e);
	
}
double predictionFromElo(int elo, int counter){
	double e = 0-elo;
	return 1.0/(1+pow(10.0,e/(randomness+1-counter)));
	
}



extern "C" {

void updateProbability(int state, double p, int year) {
	if (state == 51){
		randomness = round(p);
	}
	else if (state == 52){
		correlationDivisor = round(p);
	}
	else if (state == 53){
		correlationPower = p;
	}
	else if (state == 54){
		seed = year;
	}
	else {
		if (year == 2016){
			predictions16[state] = p;
		}
		else if (year == 2020){
		
			predictions20[state] = p;
		}
	}
	
}

void makePrediction(int year, int n) {
	std::vector<double> predictions;
	std::vector<double> results;
	int i; int ii; int iii;
	if (year == 2016){
		for (i = 0;i<51;i++){
			predictions.push_back(predictions16[i]);
		}
		for (i = 0;i<102;i++){
			results.push_back(results20[i]);
		}
	}
	else if (year == 2020){
		for (i = 0;i<51;i++){
			predictions.push_back(predictions20[i]);
		}
		for (i = 0;i<102;i++){
			results.push_back(results20[i]);
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
	std::map<int,int> hevData;
	std::map<int,int> vevData;
	std::map<int,int> pevData;
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
		int dPEV = 0;
		int dSen = 0;
		std::map<int,int> doneYet;
		int unknownStates = 51;
		for (ii=0;ii<51;ii++){
			doneYet[ii]=0;
		}
		for (ii=0;ii<51;ii++){
			int thisstate = rand() % 51;
			while (doneYet[thisstate]!=0){
				thisstate = rand() % 51;
			}
			doneYet[thisstate]=-1;
			if (results[thisstate*2]>=-1000 || results[thisstate*2+1]<=1000){
				doneYet[thisstate]=1;
				unknownStates--;
				
				int minElo = results[thisstate*2] - elonew[thisstate];
				int maxElo = results[thisstate*2+1] - elonew[thisstate];
				
				int r = rand() % 1024;
				double rr = r;
				rr /= 1024;
				double minP = predictionFromElo(minElo,randomness-unknownStates);
				double maxP = predictionFromElo(maxElo,randomness-unknownStates);
				rr = minP + rr*(maxP-minP);
				//convert rr to vote percentage
				int eloState = predictionToElo(rr,randomness-unknownStates);
				int eloPres = eloState;
				if (elonew[thisstate]+eloPres > 0){ // Biden wins
				
					bidenEV += evs[thisstate];
					dHEV += evs[thisstate]-2;
					dVEPEV += vepevs[thisstate];
					stateData[thisstate]++;
					dSen++;
				
				
				}
				if (thisstate == 21){//Maine
					if (elonew[thisstate]+eloPres > -100){ //Biden wins 1st
						bidenEV++; dHEV++; dVEPEV+=10;
					}
					if (elonew[thisstate]+eloPres > 100){ //Biden wins 2nd
						bidenEV++; dHEV++; dVEPEV+=10;
					}
				}
				if (thisstate == 29){//Nebraska
					if (elonew[thisstate]+eloPres > -60){ //Biden wins 1st
						bidenEV++; dHEV++; dVEPEV+=9;
					}
					if (elonew[thisstate]+eloPres > -200){ //Biden wins 2nd
						bidenEV++; dHEV++; dVEPEV+=9;
					}
					if (elonew[thisstate]+eloPres > 300){ //Biden wins 3rd
						bidenEV++; dHEV++; dVEPEV+=9;
					}
				}
				
				int evBreak = round(2000.0/evs[thisstate]);
				if (evs[thisstate] % 2 == 0){
					int minEV = -1000 + evBreak/2;
					for (iii=0;iii<evs[thisstate];iii++){
						if (elonew[thisstate]+eloPres > minEV){
							dPEV++;
						}
						minEV += evBreak;
					}
				}
				else {
					int minEV = -1000 + evBreak;
					for (iii=0;iii<evs[thisstate];iii++){
						if (elonew[thisstate]+eloPres > minEV){
							dPEV++;
						}
						minEV += evBreak;
					}
				}
			
				if (eloState < 0){
					eloState = -1*round(pow(-1*eloState,1-(51-unknownStates)/51));
				}
				else {
					eloState = round(pow(eloState,1-(51-unknownStates)/51));
				}
			
				auto a1 = std::chrono::high_resolution_clock::now();
				iii = 0;
				for (std::map<int,int>::iterator it = doneYet.begin() ; it != doneYet.end(); ++it){
  
					//int elodiff = eloR*correlationsInt[thisstate][iii]/1000;
					if (it->second>0){
						iii++; continue;
					}
					int c = correlationsInt[thisstate][iii];
					if (eloState <= -10 || eloState >= 10 || c >= 10 ){
						elonew[iii]+=eloState*c/correlationDivisor;
					}
					iii++;
				}
				auto a2 = std::chrono::high_resolution_clock::now();
				durationRand += duration_cast<std::chrono::nanoseconds>(a2-a1).count();
			}
		}
		for (ii=0;ii<unknownStates;ii++){
			//auto a1 = std::chrono::high_resolution_clock::now();
			int usedStates = ii+51-unknownStates;
			int thisstate = rand() % 51;
			while (doneYet[thisstate]> 0){
				thisstate = rand() % 51;
			}
			//auto a2 = std::chrono::high_resolution_clock::now();
			//durationRand += duration_cast<std::chrono::nanoseconds>(a2-a1).count();
			doneYet[thisstate]=1;
			if (elonew[thisstate]>stateMax[thisstate]){
				stateMax[thisstate]=elonew[thisstate];
			}
			
			
			int r = rand() % 1024;
			double rr = r;
			rr /= 1024;
			//convert rr to vote percentage
			int eloState = predictionToElo(rr,usedStates*randomness/51);
			
			int rPres = rand() % 1024;
			double rrPres = rPres;
			rrPres /= 1024;
			//convert rr to vote percentage
			int eloPres = eloState+0;//predictionToElo(rrPres,51);
			
			
			if (elonew[thisstate]+eloPres > 0){ // Biden wins
				
				bidenEV += evs[thisstate];
				dHEV += evs[thisstate]-2;
				dVEPEV += vepevs[thisstate];
				stateData[thisstate]++;
				dSen++;
				
				
			}
			if (thisstate == 21){//Maine
				if (elonew[thisstate]+eloPres > -100){ //Biden wins 1st
					bidenEV++; dHEV++; dVEPEV+=10;
				}
				if (elonew[thisstate]+eloPres > 100){ //Biden wins 2nd
					bidenEV++; dHEV++; dVEPEV+=10;
				}
			}
			if (thisstate == 29){//Nebraska
				if (elonew[thisstate]+eloPres > -60){ //Biden wins 1st
					bidenEV++; dHEV++; dVEPEV+=9;
				}
				if (elonew[thisstate]+eloPres > -200){ //Biden wins 2nd
					bidenEV++; dHEV++; dVEPEV+=9;
				}
				if (elonew[thisstate]+eloPres > 300){ //Biden wins 3rd
					bidenEV++; dHEV++; dVEPEV+=9;
				}
			}
			
			if (n == 1){
				stateData[thisstate] = elonew[thisstate]+eloPres;
			}
			
			int evBreak = round(2000.0/(evs[thisstate]+1));
			if (evs[thisstate] % 2 == 0){
				int minEV = -1000 + evBreak/2;
				for (iii=0;iii<evs[thisstate];iii++){
					if (elonew[thisstate]+eloPres > minEV){
						dPEV++;
					}
					minEV += evBreak;
				}
			}
			else {
				int minEV = -1000 + evBreak;
				for (iii=0;iii<evs[thisstate];iii++){
					if (elonew[thisstate]+eloPres > minEV){
						dPEV++;
					}
					minEV += evBreak;
				}
			}
			
			if (eloState < 0){
				eloState = -1*round(pow(-1*eloState,1-(usedStates)/51));
			}
			else {
				eloState = round(pow(eloState,1-(usedStates)/51));
			}
			
			auto a1 = std::chrono::high_resolution_clock::now();
			iii = 0;
			for (std::map<int,int>::iterator it = doneYet.begin() ; it != doneYet.end(); ++it){
  
				//int elodiff = eloR*correlationsInt[thisstate][iii]/1000;
				if (it->second > 0){
					iii++; continue;
				}
				int c = correlationsInt[thisstate][iii];
				if (eloState <= -10 || eloState >= 10 || c >= 10 ){
					elonew[iii]+=eloState*c/correlationDivisor;
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
		if (dPEV >= 270){
			dWins[3]++;
		}
		else if (dPEV <= 268){
			rWins[3]++;
		}
		else {
			ties[3]++;
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
		if (hevData.find(dHEV) == hevData.end()){
			hevData[dHEV] = 1;
		}
		else {
			hevData[dHEV]++;
		}
		if (vevData.find(dVEPEV) == vevData.end()){
			vevData[dVEPEV] = 1;
		}
		else {
			vevData[dVEPEV]++;
		}
		if (pevData.find(dPEV) == pevData.end()){
			pevData[dPEV] = 1;
		}
		else {
			pevData[dPEV]++;
		}
		if (senateData.find(dSen) == senateData.end()){
			senateData[dSen] = 1;
		}
		else {
			senateData[dSen]++;
		}
		
		if (n == 1){
			std::string statesOut = "";
			for (ii=0;ii<51;ii++){
				statesOut += std::to_string(stateData[ii])+",";
			}
			send_map(statesOut.c_str());
		}
		else if (i % 100 == 99){
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
			
			resultStr += std::to_string(dWins[3])+",";
			resultStr += std::to_string(rWins[3])+",";
			resultStr += std::to_string(ties[3])+",";
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
			
			int medHEV = 0;
			count = 0;
			for (ii=0;ii<436;ii++){
				if (hevData.find(ii) != hevData.end()){
					count+= hevData[ii];
				}
				if (count >= i/2){
					medHEV = ii;
					break;
				}
			}
			resultStr += std::to_string((medHEV*538+218)/436)+",";
			
			int medVEV = 0;
			count = 0;
			for (ii=0;ii<4363;ii++){
				if (vevData.find(ii) != vevData.end()){
					count+= vevData[ii];
				}
				if (count >= i/2){
					medVEV = ii;
					break;
				}
			}
			resultStr += std::to_string((medVEV*538+2181)/4363)+",";
			
			int medPEV = 0;
			count = 0;
			for (ii=0;ii<538;ii++){
				if (pevData.find(ii) != pevData.end()){
					count+= pevData[ii];
				}
				if (count >= i/2){
					medPEV = ii;
					break;
				}
			}
			resultStr += std::to_string(medPEV)+",";
			
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
			
			std::string statesOut = "";
			for (ii=0;ii<51;ii++){
				double sdi = stateData[ii];
				int x = predictionToElo(sdi/i,51-unknownStates);
				statesOut += std::to_string(x)+",";
			}
			send_map(statesOut.c_str());
		}
		
	}

	
	for (i=0;i<539;i++){
		if (evData.find(i) != evData.end()){
			console_log(i);
			console_log(evData[i]);
		}
	}
}

}

void initialRun(){
	correlations = createCorrelations();
	int i; int ii;
	long long csum = 0;
	for (i=0;i<51;i++){
		std::vector<int> v;
		v.resize(51);
		correlationsInt[i] = v;
		for (ii=0;ii<51;ii++){
			correlationsInt[i][ii] = round(pow(correlations[i][ii],correlationPower)*100);
			csum += correlationsInt[i][ii];
		}
	}
	for (i=0;i<51;i++){
		for (ii=0;ii<51;ii++){
			correlationsInt[i][ii] *= 75000;
			correlationsInt[i][ii] /= csum;
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
	results20 = addResults20();
	//predictions20Sen = createPredictions20Sen();
	

}

int main() {
	correlationDivisor = 333;
	correlationPower = 3;
	randomness = 75;
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
