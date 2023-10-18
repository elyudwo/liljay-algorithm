#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n,m;
int cost[101];
bool parking[101];
int weight[2001];
map<int,int> ma;
queue<int> waiting;

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> cost[i];
	}
	for(int i=1; i<=m; i++) {
		cin >> weight[i];
	}
	
}

void solve() {
	int num = 2*m;
	long long answer = 0;
	
	while(num--) {
		int move; 
		cin >> move;
		
		if(move > 0) {
			bool check = false;
			for(int i=0; i<n; i++) {
				if(!parking[i]) {
					answer += cost[i] * weight[move]; 
					ma[move] = i;
					parking[i] = true;
					check = true;
					break;
				}
			}
			if(!check) { waiting.push(move); }
		} 
		else {
			if(!waiting.empty()) {
				int car = waiting.front();
				answer += cost[ma[-move]] * weight[car];
				ma[car] = ma[-move];
				waiting.pop();
			}
			else {
				parking[ma[-move]] = false;
			}
			
		}
		
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}