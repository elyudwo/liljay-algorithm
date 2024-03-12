#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int n;
vector<pair<int,int> > vec;
long long sum[100002];
long long all_sum = 0;

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({a,b});
		all_sum += b;
	}
	
	sort(vec.begin(), vec.end());
}

void solve() {
	for(int i=1; i<=n; i++) {
		sum[i] = sum[i-1] + vec[i-1].second;
		if(sum[i] * 2 >= all_sum) {
			cout << vec[i-1].first;
			return;
		}
	}
}

int main() {
	input();
	solve();
	
}