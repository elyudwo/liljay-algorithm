#include <iostream>

using namespace std;

int lamp[52][52];
int n,m,k;
int answer = 0;

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		for(int j=0; j<str.size(); j++) {
			lamp[i][j+1] = str[j] - '0';
		}
	}
	
	cin >> k;
}

void solve() {
	for(int i=1; i<=n; i++) {
		int cnt = 0;
		int rem[52][52];
		
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=m; k++) {
				rem[j][k] = lamp[j][k];
			}
		}
		
		for(int j=1; j<=m; j++) {
			if(rem[i][j] == 0) { 
				cnt++;	
				for(int k=1; k<=n; k++) {
					rem[k][j] = !rem[k][j];
				}
			}
		}
		
		if(cnt > k || (k - cnt) % 2 == 1) { continue; }
		
		int line = 0;
		
		for(int j=1; j<=n; j++) {
			bool check = true;
			for(int k=1; k<=m; k++) {
				if(!rem[j][k]) {
					check = false;
					break;
				}
			}
			if(check) {
				line++;
			}
		}
		

		answer = max(answer, line);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}