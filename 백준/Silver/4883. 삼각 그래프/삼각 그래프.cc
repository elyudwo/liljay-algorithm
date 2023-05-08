#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long arr[100001][3];
long long answer[100001][3];
int k = 1;
int n;

void solve() {
	answer[0][1] = arr[0][1];
	answer[0][2] = arr[0][1] + arr[0][2];
	answer[0][0] = 100000000;
	
	for(int i=1; i<n; i++) {
		answer[i][0] = min(answer[i-1][0], answer[i-1][1]) + arr[i][0];
		answer[i][1] = min({answer[i-1][0], answer[i-1][1], answer[i-1][2], answer[i][0]}) + arr[i][1];
		answer[i][2] = min({answer[i-1][1],answer[i-1][2], answer[i][1]}) + arr[i][2];
	}
	
	cout << k << ". " << answer[n-1][1];
	
	k += 1;
}

int main() {
	
	while(1) {
		cin >> n;
		
		if(n == 0) { break; }
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<3; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
		cout << '\n';
	}
}