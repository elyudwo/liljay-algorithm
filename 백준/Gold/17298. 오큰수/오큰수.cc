#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
int arr[1000001];
vector<pair<int,int> > vec;

struct num {
	int num;
	int index;
};

stack<num> stk;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back({tmp,i});
	}
	
	for(int i=n-1; i>=0; i--) {
		stk.push({vec[i].first,vec[i].second});
	}
}

void solve() {
	if(n == 1) {
		cout << "-1";
		return;
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({stk.top().num,stk.top().index});
	stk.pop();
	
	for(int i=0; i<n-1; i++) {
		while(!pq.empty()) {
			if(stk.top().num > pq.top().first) {
				arr[pq.top().second] = stk.top().num;
				pq.pop();
			}
			else { break; }
		}
		pq.push({stk.top().num,stk.top().index});
		stk.pop();
	}
	
	for(int i=0; i<n; i++) {
	    if(arr[i] == 0) {
	        cout << "-1" << " ";
	    }
	    else {
	        cout << arr[i] << " ";
	    }
	}
}

int main() {
	input();
	solve();
	
	
}