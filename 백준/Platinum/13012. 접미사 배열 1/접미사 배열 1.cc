#include <iostream>
#include <algorithm>

using namespace std;

string rem;
int n,t;
int g[100001], tg[100001], sa[100001];

void input() {
	cin >> rem;
}

bool cmp(int x, int y) {
	if(g[x] == g[y]) {
		return g[x+t] < g[y+t];
	}
	
	return g[x] < g[y];
}

void manber(string str) {
	t = 1;
	n = str.size();
	
	for(int i=0; i<n; i++) {
		sa[i] = i;
		g[i] = str[i];
	}
	
	while(t < n) {
		g[n] = -1;
		sort(sa,sa+n,cmp);
		tg[sa[0]] = 0;
		
		for(int i=0; i<n-1; i++) {
			tg[sa[i+1]] = tg[sa[i]] + cmp(sa[i], sa[i + 1]);
		}
		for(int i=0; i<n; i++) {
			g[i] = tg[i];
		}
		
		t <<= 1;
	}
}

// str 과 길이가 같으면서 사전순으로 앞선 문자열 

// abca
// 3012


void solve() {
	manber(rem);
	
	string manber_rem = "";
	
	if(rem[sa[0]] > 'a') { cout << "1"; return; }
	
	for(int i=1; i<rem.size(); i++) {
		char p = rem[sa[i-1]];
		char c = rem[sa[i]];
		
		if(p < c-1) { cout << "1"; return; }
		else if(p == c-1) {
			if(sa[i] + 1 == rem.size()) { continue; }
			if(sa[i-1] + 1 == rem.size() || g[sa[i-1] + 1] <= g[sa[i] + 1]) {
				cout << "1";
				return;
			}
		}
		
	}
	
	cout << "0";
	
}

int main() {
	input();
	solve();
	
}