#include <iostream>
#include <vector>
#define INF 2e9

using namespace std;

int n, s;
long long arr[100002];

void input() {
	cin >> n >> s;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	
	for(int i=1; i<=n; i++) {
		arr[i] = arr[i] + arr[i-1];
 	}
}

void solve() {
	int left = 0;
	int right = 1;
	int answer = INF;
	
	while(left <= right) {
		if(right > n) { break; }
		if(arr[right] - arr[left] >= s) { 
			answer = min(answer, right - left);
			left++;
		}
		else {
			right++;
		}
		
		if(left == right) {
			right++;
		}
	}
	
	if(answer == INF) {
		cout << "0";
		return;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}