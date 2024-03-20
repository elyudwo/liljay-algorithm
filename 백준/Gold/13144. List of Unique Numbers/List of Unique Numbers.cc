#include <iostream>

using namespace std;

int n;
int arr[100002];
bool check[100002];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	long long answer = 0;
	
	int end = 1;
	
	for(int i=1; i<=n; i++) {
		while(end <= n) {
			if(check[arr[end]]) { break; }
			check[arr[end]] = true;
			end++;
		}
//		cout << end << endl;
		check[arr[i]] = false;
		answer += end - i;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}