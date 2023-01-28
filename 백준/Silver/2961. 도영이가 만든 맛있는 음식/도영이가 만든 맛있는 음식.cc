#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sour;
vector<int> bitter;
vector<int> vec;
int answer = 2000000001;
bool check[11];
int n;

void input() {	
	cin >> n;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		sour.push_back(a);
		bitter.push_back(b);
	}
}

void dfs(int index, int cnt) {
	if(vec.size() == cnt) {
		int s = 1;
		int b = 0;
		for(int i=0; i<cnt; i++) {
			s = s * sour[vec[i]];
			b = b + bitter[vec[i]];
		}
		int cmp = fabs(s-b);
		answer = min(answer,cmp);
		return;
	}
	
	for(int i=index; i<n; i++) {
		if(check[i]) continue;
		check[i] = true;
		vec.push_back(i);
		dfs(i,cnt);
		check[i] = false;
		vec.pop_back();
	}
}

void solve() {
	for(int i=1; i<=n; i++) {
		dfs(0,i);
	}
	cout << answer;
}

int main() {
	input();
	solve();
}