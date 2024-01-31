#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int n;

void input() {
	cin >> n;
		 
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int tmp; 
			cin >> tmp;
			pq.push(tmp);
			if(pq.size() > n) {
				pq.pop();
			}
		}
	}
}

void solve() {
	cout << pq.top();
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	solve();
}