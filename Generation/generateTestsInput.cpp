#include <iostream>
#include <string>
#include <fstream>
#define FLOAT 1
#define STRING 2
using namespace std;
// Global vars
int nrT2;
int nrT1;
double correlation;
int nrGroups;
string overlapGroups;
string distShared;
string distGet;
string distInitial;
int nrReqAtts;
double reqAtts[20];

void printValues(string directory){
	ofstream output(directory);
	output<<nrT2<<endl;
	output<<nrT1<<endl;
	output<<correlation<<endl;
	output<<nrGroups<<endl;
	output<<overlapGroups<<endl;
	output<<distShared<<endl;
	output<<distGet<<endl;
	output<<distInitial<<endl;
}

void printQuery(string directory, string quantifier){
	ofstream output(directory);
	output<<"T1.data;T2.data;"<<nrReqAtts<<";"<<quantifier<<endl;
}

void reinitValues(){
	nrT2 = 5;
	nrT1 = 1000;
	correlation = 0.5;
	nrGroups = 10;
	overlapGroups = "outlier false";
	distShared = "EXPONENCIAL";
	distGet = "UNIFORM";
	distInitial = "UNIFORM";	
	nrReqAtts = 1;
	reqAtts[0] = FLOAT;
}

void generateVarDivisor(int begin, int end, int nrBins){
	string basePath = "VarDivisor/";
	string fullPath = "";
	string fileName = "";
	string fileExt = ".in";
	int binSize = (end-begin)/(nrBins-1);
	int i = 1;
	for(nrT2=begin; nrT2<=end; nrT2+=binSize){
		fileName = to_string(i);
		fullPath = basePath + fileName + "/";
		system(("mkdir -p "+fullPath).c_str());
		printValues(fullPath+fileName+".in");
		printQuery(fullPath+"query","all");
		i++;
	}
}

void generateVarDividend(int begin, int end, int nrBins){
	string basePath = "VarDividend/";
	string fullPath = "";
	string fileName = "";
	string fileExt = ".in";
	int binSize = (end-begin)/(nrBins-1);
	int i = 1;
	for(nrT1=begin; nrT1<=end; nrT1+=binSize){
		fileName = to_string(i);
		fullPath = basePath + fileName + "/";
		system(("mkdir -p "+fullPath).c_str());
		printValues(fullPath+fileName+".in");
		i++;
	}
}

int main(){
	reinitValues();
	generateVarDividend(100,10000,100);
	reinitValues();
	generateVarDivisor(1,100,100);
	return 0;
}
