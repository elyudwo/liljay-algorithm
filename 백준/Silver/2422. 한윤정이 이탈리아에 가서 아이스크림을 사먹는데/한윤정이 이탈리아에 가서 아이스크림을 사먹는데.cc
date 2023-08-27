#include <iostream>

using namespace std;

bool check[201][201];
int n,m;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		check[a][b] = true;
		check[b][a] = true;
	}
}

void solve() {
	int answer = 0;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			for(int k=j+1; k<=n; k++) {
				if(!check[i][j] && !check[i][k] && !check[j][k]) {
					answer += 1;
				}
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}