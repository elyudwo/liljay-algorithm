#include <iostream>

using namespace std;

int n,m;
long long arr[1000001] = {0,};
long long sum[1000001] = {0,};
long long cnt[1001] = {0,};

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}
}

void solve() {
	long long answer = 0;
	
	for(int i=1; i<=n; i++) {
		sum[i] = sum[i] % m;
		if(!sum[i]) { answer += 1; cnt[0]++; }
		else { cnt[sum[i]]++; }
	}
	
	for(int i=0; i<m; i++) {
		if(cnt[i] >= 2) {
			answer += (cnt[i] * (cnt[i]-1)) / 2;
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}