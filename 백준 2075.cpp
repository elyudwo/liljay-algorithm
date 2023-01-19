#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;
int n,tmp;

int main() {
	cin >> n;
	
	bool check = true;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> tmp;
			pq.push(tmp);
			if(pq.size() > 5) {
				pq.pop();
			}
		}
	}
	
	cout << pq.top();
}
