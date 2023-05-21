#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> vec;
vector<int> m;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	if(n == 1) {
		m.push_back(vec[0]);
	}
	else {
		for(int i=1; i<n; i++) {
			m.push_back(vec[i] - vec[i-1]);
		}
	}
	
	sort(m.begin(), m.end(), cmp);
}

void solve() {
	int sum = 0;
	
	if(k == 1) {
		if(n != 1) {
			for(int i=0; i<m.size(); i++) {
				sum += m[i];
			}
		}
	}
	else {
		for(int i=k-1; i<m.size(); i++) {
			sum += m[i];
		}
	}
	
	cout << sum;
}

int main() {
	input();
	solve();
	
}