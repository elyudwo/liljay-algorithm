#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

priority_queue<int, vector<int>, greater<int>> end_time;
int answer = 1;
priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> >> pq;

int n;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		pq.push({a,b});
	}	
}

void solve() {
	end_time.push(pq.top().second);
	pq.pop();
	
	for(int i=1; i<pq.size(); i++) {
		while(1) {
		    if(answer <= end_time.size()) {
		        answer = end_time.size();
		    }
			if(pq.empty()) {
				break;
			}
			if(end_time.empty()) {
				end_time.push(pq.top().second);
				pq.pop();
				break;
			}
			if(pq.top().first >= end_time.top()) {
				end_time.pop();
			}
			else {
				end_time.push(pq.top().second);
				pq.pop();
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
	
}