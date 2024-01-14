#include <iostream>
#include <map>

using namespace std;

long long n,p,q;
map<long long, long long> ma;

void input() {
	cin >> n >> p >> q;
	ma[0] = 1;
	ma[1] = 2;
}

long long dfs(long long x) {
	if(ma[x] != 0) {
		return ma[x];
	}
	
	long long result = dfs(x / p) + dfs(x / q);
	ma[x] = result;
//	cout << x << " " << ma[x] << endl;
	return result;
}

void solve() {
	long long result = dfs(n);
	cout << result;
}

int main() {
	input();
	solve();
	
}