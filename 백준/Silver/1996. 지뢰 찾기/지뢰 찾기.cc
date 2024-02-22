#include <iostream>

using namespace std;

int n;
int mine[1002][1002];
int check[1002][1002];
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {-1,1,0,0,1,-1,1,-1};

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		
		for(int j=1; j<=n; j++) {
			if(str[j-1] == '.') {
				mine[i][j] = 0;
				continue;
			}
			check[i][j] = str[j-1] - '0';
			mine[i][j] = str[j-1] - '0';
		}
	}
}

void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(!check[i][j]) { continue; }
			
			for(int k=0; k<8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				mine[nx][ny] += check[i][j];
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(check[i][j]) {
				cout << "*";
				continue;
			}
			if(mine[i][j] >= 10) {
				cout << "M";
				continue;
			}
			
			cout << mine[i][j];
		}
		cout << '\n';
	}
}

int main() {
	input();
	solve();
	
}