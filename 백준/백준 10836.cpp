#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int arr[701][701];
int dx[] = {0,-1,-1};
int dy[] = {-1,-1,0};
int v[1500];

void input() {
	cin >> m >> n;
	
	for(int i=0; i<=700; i++) {
		for(int j=0; j<=700; j++) {
			arr[i][j] = 1;
		}
	}
		
	while(n--) {
		int a,b,c;
		cin >> a >> b >> c;
		int cnt = 0;
		for(int i=0; i<a; i++) {
			v[cnt] = v[cnt] + 0;
			cnt++;
		}
		
		for(int i=0; i<b; i++) {
			v[cnt] = v[cnt] + 1;
			cnt++;
		}
		
		for(int i=0; i<c; i++) {
			v[cnt] = v[cnt] + 2;
			cnt++;
		}
	}
}

void solve() {
	int tmp = 0;
	for(int i=m-1; i>=0; i--) {
		arr[i][0] = 1 + v[tmp++];
	}
	for(int i=1; i<m; i++) {
		arr[0][i] = 1 + v[tmp++];
	}
	
	for(int i=1; i<m; i++) {
		for(int j=1; j<m; j++) {
			int max_tmp = 0;
			for(int k=0; k<3; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				max_tmp = max(max_tmp,arr[nx][ny]);
			}
			arr[i][j] = max_tmp;
		}
	}
	
}

void print() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	input();
	solve();
	print();
	
}
