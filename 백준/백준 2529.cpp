#include <iostream>
#include <algorithm> 
#include <cmath>
#include <string>
#include <vector> 
using namespace std;

string max_tmp="0000000000";
string min_tmp="0000000000";
int v[10];
int n;

int main(void)
{
	cin >> n;
	// < == 1 , > == 2
	
	for(int i=0; i<n; i++) {
		char c;
		cin >> c;
		if(c == '<') v[i] = 1;
		else v[i] = 2;
	}
	
	// 맨위에서 3개 맨아래에서 3개 
	int lt[10] = {0,1,2,3,4,5,6,7,8,9};
	int mt[10] = {9,8,7,6,5,4,3,2,1,0};
	
	vector<int> l;
	vector<int> m;
	
	for(int i=0; i<=n; i++) {
		l.push_back(lt[i]);
		m.push_back(mt[i]);
	}
	
	do {
		bool check = true;
		string tmp;
		for(int i=0; i<n; i++) {
			if(v[i] == 1) {
				if(m[i] > m[i+1]) {
					check = false;
					break;
				}
			}
			else if(v[i] == 2) {
				if(m[i] < m[i+1]) {
					check = false;
					break;
				}
			}
		}
		if(check) {
			for(int i=0; i<=n; i++) {
				tmp = tmp + to_string(m[i]);
			}
		}
		
		for(int i=0; i<=n; i++) {
			int a = tmp[i] - '0';
			int b = max_tmp[i] - '0';
			
			if(a > b) {
				max_tmp = tmp;
			}
			else if(a == b) {
				continue;
			}
			else {
				break;
			}
		}
	}while(next_permutation(m.begin(),m.end()));
	
	
	do {
		bool check = true;
		string tmp;
		for(int i=0; i<n; i++) {
			if(v[i] == 1) {
				if(l[i] > l[i+1]) {
					check = false;
					break;
				}
			}
			else if(v[i] == 2) {
				if(l[i] < l[i+1]) {
					check = false;
					break;
				}
			}
		}
		if(check) {
			for(int i=0; i<=n; i++) {
				tmp = tmp + to_string(l[i]);
			}
		}
		
		for(int i=0; i<=n; i++) {
			int a = tmp[i] - '0';
			int b = max_tmp[i] - '0';
			
			if(a < b) {
				min_tmp = tmp;
			}
			else if(a == b) {
				continue;
			}
			else {
				break;
			}
		}
	}while(next_permutation(m.begin(),m.end()));
	
	
	cout << max_tmp << endl << min_tmp;
	
	return 0;
}
