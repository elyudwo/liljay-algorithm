#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, q;
long long arr[250001];
deque<int> dq;

int binarySearch(int x) {
	int left = 1;
	int right = n;
	int mid;
	int max_value = 0;
	
	while(left <= right) {
		mid = (left + right) / 2;
		
//		if(dq[mid] >= x && dq[mid-1] < x) { return mid; }
		
		if(dq[mid] >= x) { right = mid - 1; }
		else { left = mid + 1; max_value = max(max_value, mid); }
	}
	return max_value + 1;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> q;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		dq.push_back(arr[i]);
	}

	dq.push_front(0);
	sort(dq.begin(), dq.end());
	
	while(q--) {
		int x, y;
		cin >> x >> y;
		
		if(x > arr[y]) {
			cout << "0" << '\n';
			continue;
		}
		int idx = n - binarySearch(x);
		
		int side = arr[y] + 1 - x;
		int up = idx - y + 1;
		int answer = side + up;
		if(answer <= 0) {
			cout << "0" << '\n';
			continue;
		}
//		cout << "side : " << side << " " << "up : " << up << " idx : " << idx << '\n';
		cout << side + up << '\n'; 
	}
}