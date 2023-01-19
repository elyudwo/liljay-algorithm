#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <vector> 

using namespace std;

deque<int> dq;
int t;

void solve(int n) {
	vector<int> vec;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(),vec.end());
	
	for(int i=0; i<n; i++) {
		if(i%2 == 0) { dq.push_back(vec[i]); }
		else { dq.push_front(vec[i]); }
	}
	
	int result = -1;
	
	for(int i=0; i<n-1; i++) {
		int tmp;
		if(i == 0) {
			tmp = fabs(dq[0] - dq[n-1]);
			result = max(result,tmp);
			tmp = fabs(dq[0] - dq[1]);
			result = max(result,tmp);
		}
		else {
			int tmp = fabs(dq[i] - dq[i+1]);
			result = max(result,tmp);
		}
	}
	
	cout << result << '\n';
	
}

void input() {
	cin >> t;
	for(int i=0; i<t; i++) {
		int tmp;
		cin >> tmp;
		solve(tmp);
		dq.clear();
	}
}

int main() {
	input();
	
}
