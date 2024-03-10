#include <iostream>
#include <deque>
#define INF 2e9
using namespace std;

int n,m;
int arr[302];
int answer = INF;
deque<int> dq;

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
}

bool check(int mid) {
	int cnt = 1;
	int tmp = 0;
	
	for(int i=1; i<=n; i++) {
		if(arr[i] > mid) return false;
		if(tmp + arr[i] > mid) {
			cnt++;
			tmp = arr[i];
			continue;
		}
		tmp += arr[i];
	}
	
	if(cnt <= m) {
		return true;
	}
	return false;
}

void solve() {
	int low = 0;
	int high = 30002;
	
	while(low <= high) {
		int mid = (low + high) / 2;
//		cout << mid << "\n";
		if(check(mid)) {
			high = mid - 1;
			answer = min(answer, mid);
		}
		else {
			low = mid + 1;
		}
	}
	
	
	cout << answer << '\n';
	
	int cnt = 0;
	int sum = 0; 
	
	for(int i=0; i<n; i++) {
		sum += arr[i+1];
		if(sum > answer) {
			sum = arr[i+1];
			m--;
			cout << cnt << " ";
			cnt = 0;
		}
		cnt++;
		
		if(n - i == m) {
			break;
		}
	}
	
	while(m--) {
		cout << cnt << " ";
		cnt = 1;
	}
}

int main() {
	input();
	solve();
	
}