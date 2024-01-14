#include <iostream>
#include <deque>
#include <vector> 
#include <algorithm>

using namespace std;

int n,m;
vector<int> crain;
deque<int> dq;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		crain.push_back(tmp);
	}
	
	sort(crain.begin(), crain.end(), cmp);
	
	cin >> m;
	
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		dq.push_back(tmp);
	}
	sort(dq.begin(), dq.end(), cmp);
}

void solve() {
	int cnt = 0;
	
	if(dq[0] > crain[0]) {
		cout << "-1";
		return;
	}
	
	while(!dq.empty()) {
		cnt++;
		int idx = 0;
		bool check[10001] = {false,};
		
		deque<int> rem;
		
		for(int i=0; i<dq.size(); i++) {
			if(crain[idx] >= dq[i]) {
				check[i] = true;
				idx++;
			}
			if(idx == crain.size()) { break; }
		}
		
		for(int i=0; i<dq.size(); i++) {
			if(!check[i]) { rem.push_back(dq[i]); }
		}
		
		dq = rem;	
	}
	
	cout << cnt;
}

int main() {
	input();
	solve();
	
}