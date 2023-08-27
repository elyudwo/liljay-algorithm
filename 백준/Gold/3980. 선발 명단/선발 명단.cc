#include <iostream>
#include <vector>

using namespace std;

int t;
int arr[12][12];
bool check[12];
vector<int> vec;
int answer = 0;

void dfs(int now) {
	if(vec.size() == 11) {
		int result = 0;
		for(int i=0; i<11; i++) { result += arr[i+1][vec[i]]; }
		answer = max(answer, result);
	}
	
	for(int i=1; i<=11; i++) {
		if(check[i] || arr[now][i] == 0) continue;
		check[i] = true;
		vec.push_back(i);
		dfs(now+1);
		vec.pop_back();
		check[i] = false;
	}
}

void solve() {
	dfs(1);
	cout << answer << '\n';
}

void init() {
	for(int i=1; i<=11; i++) {
		for(int j=1; j<=11; j++) {
			arr[i][j] = 0;
		}
	}
	answer = 0;
}

void input() {
	cin >> t;
	
	while(t--) {
		int stat;
		for(int i=1; i<=11; i++) {
			for(int j=1; j<=11; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
		
		init();
	}
}

int main() {
	input();
	
}