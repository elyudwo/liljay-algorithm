#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<long long> vec;

void input() {
	cin >> n;
}

void solve() {
	queue<long long> q;
	if(n <= 9) {
		cout << n;
		return;
	}	
	
	for(int i=0; i<=9; i++) {
		q.push(i);
		vec.push_back(i);
	}
	
	while(!q.empty()) {
		long long x = q.front();
		int last = x % 10;
		q.pop();
		
		for(int i=0; i<last; i++) {
			q.push(x * 10 + i);
			vec.push_back(x * 10 + i);
		}
	}
	if(n >= vec.size()) {
		cout << "-1";
		return;
	} 
	cout << vec[n];
	
}

int main() {
	input();
	solve();
	
}