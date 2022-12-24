#include <iostream>
#include <cmath>
using namespace std;

int n,l;
int road[101][101];
bool rCheck[101][101];
bool remrCheck[101][101];

void input() {
	cin >> n >> l;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> road[i][j];
		}
	}
}

bool checkRoad(char c,int k) {
	int cnt = 1;
	
	bool result = true;
	
	if(c == 'g') {
		int rem = road[k][1];
		for(int i=2; i<=n; i++) {
			if(rem > road[k][i]) {
				if(fabs(rem - road[k][i]) > 1) { return false; }
				
				for(int j=i; j<i+l; j++) {
					if(road[k][i] != road[k][j] || j > n) {
						return false;
					}
				}
				
				for(int j=i; j<i+l; j++) {
					rCheck[k][j] = true;
				}	
				rem = road[k][i];
				
			}		
			else if(rem < road[k][i]) {
				if(fabs(rem - road[k][i]) > 1 || cnt < l) { return false; }
				if(cnt >= l) {
					for(int j=i-l; j<i; j++) {
						// 같은 곳에 경사로를 놓을 수 없다. 
						if(rCheck[k][j]) { return false; }
						rCheck[k][j] = true;
					}
					cnt = 0;
					rem = road[k][i];
				}
			}
			else {
				cnt++;
			}
		}
	}
	else {
		int rem = road[1][k];
		for(int i=2; i<=n; i++) {
			if(rem > road[i][k]) {
				if(fabs(rem - road[i][k]) > 1) { return false; }
				
				int a = road[i][k];
				for(int j=i; j<i+l; j++) {
					if(a != road[j][k] || j > n) {
						return false;
					}
				}
				rem = road[i][k];
			}
			else if(rem < road[i][k]) {
				if(fabs(rem - road[i][k]) > 1 || cnt < l) { return false; }
				if(cnt >= l) {
					for(int j=i-l; j<i; j++) {
						// 같은 곳에 경사로를 놓을 수 없다. 
						if(rCheck[j][k]) { return false; }
						rCheck[j][k] = true;
					}
					cnt = 0;
					rem = road[i][k];
				}
			}
			else {
				cnt++;
			}
		}
	}
	
	return true;
} 

void copy() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			remrCheck[i][j] = rCheck[i][j];
		}
	}
}

void copy2() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			rCheck[i][j] = remrCheck[i][j];
		}
	}
}

void solve() {
	int result = 0;
	//가로  
	for(int i=1; i<=n; i++) {
		if(checkRoad('g',i)) {
		 	result++; 
			cout << i << "g" <<endl;
			copy();
		}
		else {
			copy2();
		}
	}
	
	//세로 
	for(int i=1; i<=n; i++) {
		if(checkRoad('s',i)) {
			result++;
			cout << i << "s" << endl; 
		}
		else {
			copy2();
		}
	}
	
	cout << result;
}

int main() {
	input();
	solve();
	
}
