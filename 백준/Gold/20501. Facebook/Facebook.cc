#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n,q;
long long arr[2001][35];


void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int tmp;
			scanf("%1d",&tmp);
			if(tmp == 1) {
				arr[i][j/60] |= 1LL << (j%60);
			}
		}
	}
}

void solve() {
	cin >> q;
	
	for(int i=0; i<q; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		
		
		int answer = 0;
		
		for(int j=0; j<35; j++) {
			answer += __builtin_popcountll(arr[a][j] & arr[b][j]);
		}
		printf("%d\n",answer);
	}
}

int main() {
	input();
	solve();
	
}