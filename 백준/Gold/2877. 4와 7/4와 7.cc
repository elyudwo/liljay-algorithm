#include <iostream>
#include <cmath> 
#include <algorithm>

using namespace std;

int n; 

void input() {
	cin >> n;
}

string convert_binary() {
	string result = "";
	
	while(1) {
		int tmp = n % 2;
		result += to_string(tmp);
		n = n/2;
		if(n == 0) {
		    reverse(result.begin(), result.end());
		    return result; 
		}
	}
}

void solve() {
	int cnt = 1;
	long long sum = 0;
	
	if(n == 1) {
		cout << "4";
		return;
	}
	else if(n == 2) {
		cout << "7";
		return;
	}
	
	while(1) {
		sum += pow(2,cnt);
		if(n <= sum) { break; }
		cnt += 1;
	}
	
	int m = 0;
	for(int i=1; i<cnt; i++) { m += pow(2,i); }
	
	n -= (m+1);
	
	// 2진수로 바꾸자 
	
	string str = convert_binary();
	
	//cout << cnt << " " << str << endl;
	string tmp = "";
	if(str.size() < cnt) {
		for(int i=0; i<cnt - str.size(); i++) { tmp += "4"; }
	}
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '0') { tmp += "4"; }
		else { tmp += "7"; }
	}
	
	cout << tmp;
}

int main() {
	input();
	solve();
	
}