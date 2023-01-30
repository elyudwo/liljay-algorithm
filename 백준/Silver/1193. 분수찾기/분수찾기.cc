#include <iostream>

using namespace std;

int x;
int up[10000001];
int down[10000001];


void input() {
	cin >> x;
}

void solve() {
	int cnt = 0;
	int rem = 1;
	bool check = false;
	
	while(1) {
		bool c = false;
		if(check) {
			 for(int i=1; i<=rem; i++) {
				cnt++;
				up[cnt] = i;
				if(cnt == x) {
					c = true;
					break;
				}
			}
			check = false;
		}
		else {
			for(int i=rem; i>=1; i--) {
				cnt++;
				up[cnt] = i;
				if(cnt == x) {
					c = true;
					break;
				}
			}
			
			check = true;
		}
		
		rem++;
		if(c) {
			break;
		}
	}
	
	cnt = 0;
	rem = 1;
	check = true;
	
	while(1) {
		bool c = false;
		if(check) {
			 for(int i=1; i<=rem; i++) {
				cnt++;
				down[cnt] = i;
				if(cnt == x) {
					c = true;
					break;
				}
			}
			check = false;
		}
		else {
			for(int i=rem; i>=1; i--) {
				cnt++;
				down[cnt] = i;
				if(cnt == x) {
					c = true;
					break;
				}
			}
			
			check = true;
		}
		
		rem++;
		if(c) { break; }
	}
	
	cout << up[x] << "/" << down[x];
}

int main() {
	input();
	solve();
}