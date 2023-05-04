#include <iostream>
#include <algorithm>
using namespace std;

string str;
int g[100001], tg[100001], sa[100001];
int n,t;

void input() {
	cin >> str;
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

void solve() {
	manber(str);
	
	for(int i=0; i<n; i++) {
		cout << sa[i]  << '\n';
	}
}

int main() {
	input();
	solve();
	
}