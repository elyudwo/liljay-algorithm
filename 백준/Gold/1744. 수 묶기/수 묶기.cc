#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, zero = 0;
vector<int> pos;
vector<int> neg;

long long answer = 0;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;

	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		if(tmp == 0) { zero++; }
		else if(tmp < 0) { neg.push_back(tmp); }
		else { pos.push_back(tmp); }
	}
}

void solve() {
	sort(pos.begin(), pos.end(), cmp);
	sort(neg.begin(), neg.end());
	
	if(pos.size() % 2 == 1) {
		answer += pos[(int)pos.size() - 1];
		pos.pop_back();
	}
	
	for(int i=0; i<(int)pos.size() - 1; i = i + 2) {
		if(pos[i] == 1 || pos[i+1] == 1) {
			answer += pos[i] + pos[i+1];
			continue;
		}
		answer += pos[i] * pos[i+1];
	}
	
	for(int i=0; i<(int)neg.size() - 1; i = i + 2) {
		answer += neg[i] * neg[i+1];
	}
	
	if(neg.size() % 2 == 1 && zero == 0) {
		answer += neg[(int)neg.size() - 1];
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}