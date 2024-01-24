#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> vec;

int n;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end(), cmp);
}

void solve() {
	long long big = vec[0];
	long long sum = 0;
	
	for(int i=1; i<n; i++) { sum += vec[i]; }
	
	
	if(sum > big) {
		if((sum + big) % 2 == 1) {
			cout << "1";
			return;
		} 
		cout << "0";
		return;
	}
	
	cout << big - sum;
}

int main() {
	input();
	solve();
}