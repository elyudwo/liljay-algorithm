#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<int> vec;
long long arr[10];
long long sum[10];
int n;

void input() {
	cin >> n;
}

int calculateDigit() {
	int cnt = 0;
	int tmp = n;
	while(tmp != 0) {
		tmp = tmp / 10;
		cnt++;
	}
	return cnt;
}

void solve() {
	for(int i=1; i<=8; i++) {
	    arr[i] = i * 9 * pow(10, i-1);
		sum[i] = sum[i-1] + arr[i];
	}
	
	
	int s = calculateDigit();
	
	if(s == 9) {
	    cout << sum[8] + 9;
	    return;
	}
	
	string str = "";
	for(int i=0; i<s; i++) {
		str += "9";
	}
	int tmp = stoi(str) - n;
	
	
	
	cout << sum[s] - s * tmp;
	
}	
	
int main() {
	input();
	solve();
	
}