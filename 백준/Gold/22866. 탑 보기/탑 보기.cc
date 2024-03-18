#include <iostream>
#include <stack>
#include <cmath>
#define INF 2e9
using namespace std;

int n;
int arr[100002];
int sum[100002];
int building_num[100002];
int building_dist[100002];

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		building_num[i] = INF;
		building_dist[i] = INF;
	}
}

void solve() {
	stack<pair<int,int> > stk;
	
	stk.push({arr[n], n});
	
	for(int i=n-1; i>=1; i--) {
		while(!stk.empty()) {
			if(stk.top().first <= arr[i]) {
				stk.pop();
				continue;
			}
			break;
		}
		sum[i] += stk.size();
		
		if(!stk.empty() && building_dist[i] >= abs(i - stk.top().second)) {
			building_dist[i] = abs(i - stk.top().second);
			building_num[i] = min(building_num[i], stk.top().second);
		}
		
		stk.push({arr[i], i});
	}
	
	while(!stk.empty()) { stk.pop(); }
	
	stk.push({arr[1], 1});
	
	for(int i=2; i<=n; i++) {
		while(!stk.empty()) {
			if(stk.top().first <= arr[i]) {
				stk.pop();
				continue;
			}
			break;
		}
		sum[i] += stk.size();
		
		if(!stk.empty() && building_dist[i] >= abs(i - stk.top().second)) {
			building_dist[i] = abs(i - stk.top().second);
			building_num[i] = min(building_num[i], stk.top().second);
		}
		
		stk.push({arr[i], i});
	}
	
	
	for(int i=1; i<=n; i++) {
		if(sum[i] == 0) {
			cout << "0\n";
			continue;
		} 
		cout << sum[i] << " " << building_num[i] << '\n';
	}
}

int main() {
	input();
	solve();
	
}