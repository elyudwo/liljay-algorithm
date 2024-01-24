#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> vec;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(), vec.end(), cmp);
}

void solve() {
	long long big = vec[0];
	long long sum = 0;
	
	for(int i=1; i<vec.size(); i++) {
		sum += vec[i];
	}

	if(big > sum + 1) {
		cout << sum * 2 + 1;
		return;
	}

	cout << big + sum;
}

int main() {
	input();
	solve();
	
}