#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> vec; 
bool check[501];
int answer = 0;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}	
}

bool sosu(int x) {
	if(x < 2) { return false; } 
	int a = (int)sqrt(x);
	for(int i=2; i<=a; i++) {
		if(x%i == 0) { return false; }
	}
	
	return true;
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			if(sosu(j-i+1)) {
				int sum = 0;
				for(int k=i; k<=j; k++) {
					sum += vec[k];
				}
				if(sosu(sum)) {
					answer++;
				}
			}
		}
	}
	for(int i=0; i<n; i++) {
		if(check[i]) { answer++; }
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}