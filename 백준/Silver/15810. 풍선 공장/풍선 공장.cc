#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, m;
vector<int> vec;

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);		
	}
	
	sort(vec.begin(), vec.end());
}

void solve() {
	ll left = 0;
	ll right = 2000000000001;
	ll answer = 0;
	
	ll mid;
	
	while(left <= right) {
		mid = (left + right) / 2;
//		cout << mid << " "; 
		ll cnt = 0;
		
		for(int i=0; i<n; i++) { cnt += mid / vec[i]; }
		
//		if(cnt == m) {
//			cout << mid;
//			return;
//		}
		
		if(cnt >= m) {
			right = mid - 1;
			answer = mid;
			continue;
		}
		left = mid + 1;
	}
	
	cout << answer;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	
}