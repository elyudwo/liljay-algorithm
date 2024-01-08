#include <iostream>

using namespace std;

int n,m;
long long arr[1001][1001];
long long sum[1001][1001];
long long answer = 0;

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
}

void calculate() {
	for(int i=0; i<n; i++) {
		for(int j=1; j<n; j++) {
			sum[i][j] += sum[i][j-1];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=1; j<n; j++) {
			sum[j][i] += sum[j-1][i];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			arr[i][j] += sum[i][j];
		}
	}
}

/*
void print() {
	cout << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
}
*/

void solve() {
	for(int i=0; i<m; i++) {
		long long num,a,b,c,d,e;
		cin >> num;
		if(num == 1) {
			cin >> a >> b >> c >> d >> e;
			sum[a][b] += e;
			sum[c+1][d+1] += e;
			sum[a][d+1] -= e;
			sum[c+1][b] -= e;
		}
		else {
			calculate();
			 
			cin >> a >> b >> c >> d;
			for(int i=a; i<=c; i++) {
				for(int j=b; j<=d; j++) {
					answer += arr[i][j];
				}
			}
			
			cout << answer;
		}
	}
}

int main() {
	input();
	solve();
	
}