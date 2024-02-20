#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, k;
vector<int> vec;

void input() {
	cin >> n >> k;
}

void solve() {
	if(k > n) { cout << "0"; return; }
	if(k == n) { cout << "0"; return; }
	
	int rem = n;
	
	while(rem > 0) {
		int cnt = 0;
		
		while(1) {
			int tmp = 1 << cnt;
			if(tmp > rem) {
				cnt--;
				break;
			}
			cnt++;
		}
		vec.push_back(cnt);
		rem -= (1 << cnt);
	}
	
	
	if(vec.size() <= k) {
		cout << "0";
		return;
	}
	
	
	int other = 0;
	for(int i=k; i<vec.size(); i++) {
		other += 1 << vec[i];
	}
	
	cout << (1 << vec[k-1]) - other;
	
}

int main() {
	input();
	solve();
	
}