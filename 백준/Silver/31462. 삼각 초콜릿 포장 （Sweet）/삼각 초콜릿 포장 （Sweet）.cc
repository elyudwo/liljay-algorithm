#include <iostream>

using namespace std;

char chr[5002][5002];
bool check[5002][5002];
int n;

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		
		for(int j=1; j<=str.size(); j++) {
			chr[i][j] = str[j-1];
		}
	}
}

void solve() {
	for(int i=n; i>=1; i--) {
		for(int j=1; j<=i; j++) {
			if(check[i][j]) continue;
			if(chr[i][j] == 'B') {
				if(check[i-1][j] || check[i-1][j-1] || chr[i-1][j] != 'B' || chr[i-1][j-1] != 'B') {
					cout << "0";
					return;
				}
				check[i-1][j] = true;
				check[i-1][j-1] = true;
				continue;
			}
			
			if(check[i-1][j] || check[i][j+1] || chr[i-1][j] != 'R' || chr[i][j+1] != 'R') { cout << "0"; return; }
			
			check[i-1][j] = true;
			check[i][j+1] = true;
		}
	}
	
	cout << "1";
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	
}