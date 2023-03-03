#include <iostream>
#include <vector>
using namespace std;

long long n,k;
vector<long long> vec;
long long sum = 0;

void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		vec.push_back(tmp);
	}
}

void solve() {
	while(1) {
		for(int i=0; i<vec.size(); i++) {
			k = k - vec[i];
			if(k < 0) {
				cout << i+1;
				return;
			}
		}
		
		for(int i=vec.size()-1; i>=0; i--) {
			k = k - vec[i];
			if(k < 0) {
				cout << i+1;
				return;
			}
		}
	}
}

int main() {
	input();
	solve();
	
}