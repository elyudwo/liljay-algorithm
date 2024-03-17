#include <iostream>
#include <map>

using namespace std;

int n,m;
map<int,int> ma;
bool check[10000001];

void input() {
	cin >> n;
	cin >> m;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		ma[tmp] += 1;
	}
}

// 1 2 3 4 5 7 

void solve() {
	int answer = 0;
	
	for(pair<int,int> p : ma) {
		if(p.first >= m) continue;
		int x = p.first;
		int y = m - p.first;
		
		if(check[x] || check[y]) continue;
		
		check[x] = true;
		check[y] = true;
		
		if(x == y) {
		    answer += ma[x] / 2;
		    continue;
		}
		
		int min_value = min(ma[x], ma[y]);
		answer += min_value;
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}