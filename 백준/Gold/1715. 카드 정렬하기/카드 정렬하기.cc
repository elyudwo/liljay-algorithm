#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int answer = 0 ;
priority_queue<int, vector<int>, greater<int> > pq;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
}

void solve() {
	int cnt = n-1;
	
	while(cnt--) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		answer += (a+b);
		pq.push(a+b);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}