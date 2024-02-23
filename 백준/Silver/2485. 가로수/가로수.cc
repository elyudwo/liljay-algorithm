#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int answer = 0;
vector<int> vec;
vector<int> mns;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	for(int i=0; i<n-1; i++) {
		mns.push_back(vec[i+1] - vec[i]);
	}
}

void solve() {
	int large = __gcd(mns[1], mns[0]);
	
	for(int i=2; i<mns.size(); i++) {
		large = __gcd(mns[i], large);
	}
	
	for(int i=0; i<mns.size(); i++) {
		answer += mns[i] / large - 1;
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}