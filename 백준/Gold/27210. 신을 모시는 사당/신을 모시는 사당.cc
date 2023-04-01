#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> vec;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
}

void solve() {
	int left = 0;
	int right = 0;
	int answer = 0;
	
	for(int i=0; i<vec.size(); i++) {
		if(vec[i] == 1)  { left += 1; }
		else { right += 1; }
		
		if(left - right < 0) {
			left = 0;
			right = 0;
		}
		
		answer = max(answer, abs(left - right));
	}
	
	for(int i=0; i<vec.size(); i++) {
		if(vec[i] == 1)  { left += 1; }
		else { right += 1; }
		
		if(right - left < 0) {
			left = 0;
			right = 0;
		}
		
		answer = max(answer, abs(right - left));
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}