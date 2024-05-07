#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[2002];
vector<int> vec[2001];

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		int cnt;
		cin >> cnt;
		
		for(int j=0; j<cnt; j++) {
			int tmp;
			cin >> tmp;
			vec[i].push_back(tmp);
			arr[tmp]++;
		}
	}
}

void solve() {
	for(int i=1; i<=n; i++) {
		bool check = true;
		for(int j=0; j<vec[i].size(); j++) {
			if(arr[vec[i][j]] - 1 <= 0) {
				check = false;
			}
		}
		
		if(check) {
			cout << "1";
			return;
		}
	}
	
	cout << "0";
}

int main() {
	input();
	solve();
	
}