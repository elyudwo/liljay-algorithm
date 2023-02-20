#include <iostream>

using namespace std;

int n;
int arr[2200][2200];
int answer_m = 0; int answer_z = 0; int answer_p = 0;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool checkNumber(int m, int z, int p) {
	if(m && !z && !p) {
		answer_m += 1;
		return true;
	}
	else if(!m && z && !p) {
		answer_z += 1;
		return true;
	}
	else if(!m && !z && p) {
		answer_p += 1;
		return true;
	}
	
	return false;
}

void dfs(int num, int x1, int y1, int x2, int y2) {
	int m = 0; int z = 0; int p = 0;
	
	for(int i=x1; i<=x2; i++) {
		for(int j=y1; j<=y2; j++) {
			if(arr[i][j] == -1) { m += 1; }
			else if(arr[i][j] == 0) { z += 1; }
			else if(arr[i][j] == 1) { p += 1; }
		}
	}
	
	if(!checkNumber(m,z,p)) {
		for(int i=x1; i<=x2; i=i+num/3) {
			for(int j=y1; j<=y2; j=j+num/3) {
				dfs(num/3,i,j,i+num/3-1,j+num/3-1);
			}
		}
	}
}

void solve() {
	dfs(n,1,1,n,n);
	cout << answer_m << '\n' << answer_z << '\n' << answer_p;
}

int main() {
	input();
	solve();
	
}