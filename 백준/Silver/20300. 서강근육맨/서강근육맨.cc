#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<ll> vec;

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		ll tmp;
		cin >> tmp;
		vec.push_back(tmp); 
	}
	
	sort(vec.begin(), vec.end());
}

void solve() {
	ll answer = 0;
	if(vec.size() % 2 == 1) {
		answer = vec[n - 1];
		vec.pop_back();
	}
	
	for(int i=0; i<vec.size() / 2; i++) {
		answer = max(answer, vec[i] + vec[vec.size() - i - 1]);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}