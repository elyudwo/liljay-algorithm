#include <iostream>
#include <map>

using namespace std;

int p,s,a,c,g,t, answer = 0;
string str;
map<char,int> ma;

void input() {
	cin >> s >> p;
	cin >> str;
	cin >> a >> c >> g >> t;
}

void checkStr() {
	if(ma['A'] >= a && ma['C'] >= c && ma['G'] >= g && ma['T'] >= t) { answer += 1; }
}

void solve() {
	for(int i=0; i<p; i++) { ma[str[i]] += 1; }
	checkStr();
	
	for(int i=0; i<s-p; i++) {
		ma[str[i]] -= 1;
		ma[str[p+i]] += 1;
		checkStr();
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}