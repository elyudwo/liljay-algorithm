#include <iostream>
#include <stdio.h>
#include <vector> 
using namespace std;

int main() {
	int c;
	cin >> c;
	while(c--) {
		int n;
		int avg = 0;
		double person = 0;
		
		vector<int> vec;
		cin >> n;
		
		for(int i=0; i<n; i++) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
			avg += tmp;
		}
		
		avg = avg / n;
		
		for(int i=0; i<n; i++) {
			if(vec[i] > avg) {
				person++;
			}
		}
		
		person = person/n * 100;
		
		printf("%.3f%\n",person);
	}
	
	
}