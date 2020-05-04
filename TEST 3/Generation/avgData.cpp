#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int main(){
	int i=0;
	double nr, sum = 0, avg, minV, maxV;
	while(cin>>nr){
		i++;
		sum += nr;
		minV = min(minV, nr);
		maxV = max(maxV, nr);
		if(i==1){
			minV = nr;
			maxV = nr;
		}
		else if(i==10){
			avg = (sum-maxV-minV)/8.0;
			printf("%.6lf\n",avg);
			i = 0;
			sum = 0;
		}
	}
	return 0;
}