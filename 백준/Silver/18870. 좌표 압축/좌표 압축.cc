#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;
int arr[1000002];

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		vec.push_back(arr[i]);
	}
	
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

void solve() {
	for(int i=0; i<n; i++) {
		int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
		cout << idx << " ";
	}	
}

int main() {
	input();
	solve();
	
}