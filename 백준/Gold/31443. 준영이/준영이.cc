#include <iostream>
#include <deque>

using namespace std;

int n, m;
long long answer = 1;
deque<int> dq;

void input() {
	cin >> n >> m;
}

void solve() {
	n = n * m;
	
	int div = n / 3;
	int other = n % 3;
	
	for(int i=0; i<div; i++) {
		dq.push_back(3);
	}	
	if(other == 1) {
		if(dq.empty()) {
			dq.push_back(1);
		}
		else {
			dq.pop_back();
			dq.push_back(2);
			dq.push_back(2);
		}
	}
	else if(other == 2) {
		dq.push_back(2);
	}
	
	for(int i=0; i<dq.size(); i++) {
		answer = (answer * dq[i]) % 1000000007;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}