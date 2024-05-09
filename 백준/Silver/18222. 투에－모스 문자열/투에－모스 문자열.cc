// 1 2 4 8 16 32 64 128 ...
/*

0110 1001 1001 0110
*/


#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll k;
ll answer = -1;

void input() {
	cin >> k;
}

void divide(ll tmp, bool check) {
//	cout << tmp << " " << check << endl;
	if(tmp == 1) {
		if(check) {
			answer = 0;
			return;
		}
		answer = 1;
		return;
	}
	
	if(tmp == 2) {
		if(check) {
			answer = 1;
			return;
		}
		answer = 0;
		return;
	}
	
	
	
	ll cnt = 0;
	ll minus;
	while(1) {
		if(pow(2, cnt) >= tmp) {
			cnt--;
			minus = pow(2, cnt);
			break;
		}
		cnt++;
	}
	
	divide(tmp - minus, !check);
}

void solve() {
	divide(k, true);
	cout << answer; 
}

int main() {
	input();
	solve();
	
}