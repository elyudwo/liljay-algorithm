#include <iostream>
#include <string>
#include <vector>
#include <map> 

using namespace std;

string str;
int n;
map<char,int> ma;
map<char,int> rem_ma;
int result = 0;

void input() {
	cin >> str;
	cin >> n;
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		ma[tmp[0]]++;
	}
}

int factorial(int a) {
	int r = 1;
	for(int i=1; i<=a; i++) {
		r = r * i;
	}
	return r;
}

void calculate(char c, int l) {
	int a = ma[c];
	
	result = result + factorial(a)/factorial(l);
	cout << result << endl;
}

void solve() {
	for(int i=0; i<3; i++) {
		rem_ma[str[i]]++;
	}
	
	for(pair<char,int> m : rem_ma) {
		calculate(m->first,m->second);
	}
	
	cout << result;
	
}

int main() {
	input();
	solve();
}
