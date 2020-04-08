#include <iostream>
#include <fstream>
using namespace std;

void summarizeData(int n){
	string fts_all="cat ", fts_any="cat ", index_all="cat ", index_any="cat ";
	ofstream output("summarizeData.sh");
	for(int i=1; i<=n; i++){
		fts_all += to_string(i)+"/fts_all.result ";
		fts_any += to_string(i)+"/fts_any.result ";
		index_all += to_string(i)+"/index_all.result ";
		index_any += to_string(i)+"/index_any.result ";
	}
	fts_all += "> fts_all.result";
	fts_any += "> fts_any.result";
	index_all += "> index_all.result";
	index_any += "> index_any.result";
	output<<fts_all<<endl;
	output<<fts_any<<endl;
	output<<index_all<<endl;
	output<<index_any<<endl;
	output<<endl;
	for(int i=1; i<=n; i++){
		output<<"rm "<<i<<"/fts_all.result"<<endl;
		output<<"rm "<<i<<"/fts_any.result"<<endl;
		output<<"rm "<<i<<"/index_all.result"<<endl;
		output<<"rm "<<i<<"/index_any.result"<<endl;
	}
}

void executeRC(int n){
	ofstream output("executeRC.sh");
	for(int i=1; i<=n; i++){
		output<<"cd "<<i<<"/"<<endl;
		output<<"../../../../../Eclipse/RelationalCondition/Debug/RelationalCondition queryAll TG.data fts"<<endl;
		output<<"../../../../../Eclipse/RelationalCondition/Debug/RelationalCondition queryAll TG.data index"<<endl;
		output<<"../../../../../Eclipse/RelationalCondition/Debug/RelationalCondition queryAny TG.data fts"<<endl;
		output<<"../../../../../Eclipse/RelationalCondition/Debug/RelationalCondition queryAny TG.data index"<<endl;
		output<<"cd .."<<endl<<endl;
	}
}

void createTestCases(int n){
	ofstream output("createTestCases.sh");
	for(int i=1; i<=n; i++){
		output<<"cd "<<i<<"/"<<endl;
		output<<"./../../DataGenerator "<<i<<".in"<<endl;
		output<<"cd .."<<endl<<endl;
	}
}

void createIndexes(int n){
	ofstream output("createIndexes.sh");
	for(int i=1; i<=n; i++){
		output<<"cd "<<i<<"/"<<endl;
		output<<"sh createIndexes.sh"<<endl;
		output<<"cd .."<<endl<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	createIndexes(n);
	createTestCases(n);
	executeRC(n);
	summarizeData(n);
	return 0;
}