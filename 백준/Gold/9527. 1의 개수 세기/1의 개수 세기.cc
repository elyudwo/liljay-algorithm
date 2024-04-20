#include <iostream>
#include <algorithm>

using namespace std;

long long a, b;
long long arr[56];

void input() {
	cin >> a >> b;
}

long long calBitCnt(long long num) {
	long long result = num & 1;
     
	for(int i=55; i>0; i--) {
	    if(num & (1LL << i)) {
	        result += arr[i-1] + (num - (1LL << i) + 1);
	        num -= 1LL << i;
	    }
	}
	
	return result;
}

void solve() {
	arr[0] = 1;
	
	for(int i=1; i<=55; i++) {
		arr[i] = arr[i-1] * 2 + (1LL << (i));
	}
	
	long long small_value = calBitCnt(a-1);
	long long large_value = calBitCnt(b);
	
	cout << large_value - small_value;
}

int main() {
	input();
	solve();
} 