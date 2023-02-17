#include <iostream>
#include <string>
#include <map> 

using namespace std;

int n,m;
int answer = 0;
string str;
map<string,int> ma;
string ioi = "";

void input() {
	cin >> n >> m;
	cin >> str;
	
	for(int i=0; i<2*n+1; i++) {
		if(i%2 == 0) {
			ioi += "I";
		}
		else {
			ioi += "O";
		}
	}
}

void checkStr(string tmp) {
	if(tmp == ioi) { answer++; }
}

void solve() {
	string tmp = "";
	
	for(int i=0; i<2*n+1; i++) {
		tmp += str[i];
		checkStr(tmp);
	}
	
	for(int i=1; i<m-2*n; i++) {
		tmp.erase(tmp.begin());
		tmp.push_back(str[i+2*n]);
		checkStr(tmp);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}