#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,arrive;
int result = 999999;
vector<int> v[11];
vector<int> start;
bool check[11];

void dfs(int x, int time) {
	check[x] = true;
	for(int i=0; i<v[x].size(); i++) {
		if(v[x][i] == arrive) {
			result = min(result,time);
			check[x] = false;
			return;
		}
		
		for(int j=0; j<n; j++) {
			if(j == x) { continue; }
			for(int k=0; k<v[j].size(); j++) {
				if(!check[j] && v[j][k] == v[x][i]) {
					dfs(j,time+1);
				}
			}
		}
	}
	check[x] = false;
}

void input() {
	cin >> n;
	int tmp,train;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		for(int j=0; j<tmp; j++) {
			cin >> train;
			v[i].push_back(train);
			if(train == 0) {
				start.push_back(i);
			}
		}
	}
	cin >> arrive;
}


int main() {
	input();
	for(int i=0; i<start.size(); i++) {
		dfs(start[i],0);
	}
	
	if(result == 999999) {
		cout << "-1";
	}
	else {
		cout << result;
	}
}
