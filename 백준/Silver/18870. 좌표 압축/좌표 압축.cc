#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
vector<int> vec;
vector<int> v;

void input() {
	cin >> n;

	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
		v.push_back(tmp);
	}	
	sort(v.begin(), v.end());
	
	v.erase(unique(v.begin(), v.end()), v.end());
}

void solve() {
	for(int i=0; i<n; i++) {
		cout << lower_bound(v.begin(), v.end(), vec[i]) - v.begin() << " ";	
	}
}

int main() {
	input();
	solve();
	
}