#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long long n,m; 
string s1,s2;
vector<int> diff;
vector<int> zero;
vector<int> one;

void input() {
	cin >> n >> m;
	cin >> s1;
	cin >> s2;	
}

void solve() {
	// 서로 다른거 찾으면 뒤에서부터 맞춰오기
	
	long long sum = 0;
	long long x,y;
	long long answer = 0;
	
	
	for(int i=0; i<s1.size(); i++) {
		if(s1[i] != s2[i]) {
			if(s1[i] == '1') { one.push_back(i); }
			else { zero.push_back(i); }
		}
	}
	
	for(int i=0; i<one.size(); i++) {
		sum += fabs(one[i] - zero[i]);
	}
	
	if(sum%2 == 0) {
		x = sum/2;
		y = sum/2;
	}
	else {
		x = sum/2 + 1;
		y = sum/2;
	}
	
	answer += (x * x) + (y * y);
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}