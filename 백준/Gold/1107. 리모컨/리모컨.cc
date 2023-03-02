#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m;
int answer = 2000000000;
bool check[10];

string rem = "";
string str;

void input() {
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		check[tmp] = true;
	}
}

void dfs(int cnt) {
	if(rem.size() == cnt) {
		int a = stoi(rem);
		int tmp = fabs(a-n) + rem.size();
		answer = min(tmp, answer);
		return;
	}
	
	for(int i=0; i<=9; i++) {
	    if(check[i]) { continue; }
	    rem += (i+'0');
		dfs(cnt);
		rem.pop_back();
	}
}

void solve() {
	if(n == 100) {
		cout << "0";
		return;
	}
	
	//  + or - 로 가는 경우의 수 
	int tmp = fabs(n-100);
	answer = min(answer,tmp);
	
	// 버튼 눌러서 가는 경우 
	str = to_string(n);
	
	if(str.size() == 1) {
	    dfs(str.size());
	    dfs(str.size()+1);
	}
	else {
	    dfs(str.size());
    	dfs(str.size()+1);
    	dfs(str.size()-1);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
}