#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[4];
vector<int> yun;
int num[12];
int n;
int max_t = -2000000000;
int min_t = 2000000000;
int main(void)
{
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> num[i];
	}
	
	int cnt = 0;
	
	for(int i=0; i<4; i++) {
		cin >> v[i];
		for(int j=0; j<v[i]; j++) {
			yun.push_back(i);
		}
	}
	


	
	do {
		int tmp;
		
		for(int i=0; i<n-1; i++) {
			if(i == 0) {
				if(yun[i] == 0) {
					tmp = num[0] + num[1];
				}
				else if(yun[i] == 1) {
					tmp = num[0] - num[1];
				}
				else if(yun[i] == 2) {
					tmp = num[0] * num[1];
				}
				else if(yun[i] == 3) {
					tmp = num[0] / num[1];
				}
			}
			else {
				if(yun[i] == 0) {
					tmp = tmp + num[i+1];
				}
				else if(yun[i] == 1) {
					tmp = tmp - num[i+1];
				}
				else if(yun[i] == 2) {
					tmp = tmp * num[i+1];
				}
				else if(yun[i] == 3) {
					tmp = tmp / num[i+1];
				}
			}
			
		}
		
		if(max_t < tmp) {
			max_t = tmp;
		}
		if(min_t > tmp) {
			min_t = tmp;
		}
	} while(next_permutation(yun.begin(),yun.end()));
	
	cout << max_t << endl << min_t;
	
	return 0;
}
