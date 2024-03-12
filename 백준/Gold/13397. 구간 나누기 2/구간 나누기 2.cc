#include <iostream>
#define INF 2e9
using namespace std;

int n,m;
int arr[5002];
int answer = INF;
int check_tmp;

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
}

bool possibleCheck(int mid) {
	int low = INF, high = 0;
	int cnt = 0;
	
	for(int i=1; i<=n; i++) {
		low = min(low, arr[i]);
		high = max(high, arr[i]);
		
		if(high - low > mid) {
			cnt++;
			low = arr[i];
			high = arr[i];
		}
	}
	
	cnt++;
	
	if(cnt <= m) {
		check_tmp = cnt;
		return true;
	}
	return false;
}

void solve() {
	int left = 0;
	int right = 50000001;
	
	while(left <= right) {
		int mid = (left + right) / 2;
		
		if(possibleCheck(mid)) {
			right = mid - 1;
			answer = min(answer, mid);

			continue;
		}
		left = mid + 1;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}