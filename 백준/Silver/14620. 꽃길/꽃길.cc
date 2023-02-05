#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
	
int n;
int min_result = 999999999;
int arr[11][11];
vector<int> vec;
bool check[101];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,-1,1,0,0};

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
}

int checkPossible() {
	int x1,x2,y1,y2,z1,z2;
	int result = 0;
	bool c[101][101] = {false,};
	
	x1 = vec[0]/n; x2 = vec[0]%n;
	y1 = vec[1]/n; y2 = vec[1]%n;
	z1 = vec[2]/n; z2 = vec[2]%n;

	vector<pair<int,int> > v;
	v.push_back({x2,x1});
	v.push_back({y2,y1});
	v.push_back({z2,z1});
	
	for(int i=0; i<3; i++) {
		for(int j=0; j<5; j++) {
			int nx = v[i].first + dx[j];
			int ny = v[i].second + dy[j];
			if(nx < 0 || ny < 0 || nx >= n || ny >= n || c[nx][ny]) { return 0; }
			c[nx][ny] = true;
			result += arr[nx][ny];
		}	
	}
	
	return result;
}

void dfs(int index) {
	if(vec.size() == 3) {
		int tmp = checkPossible();
		if(tmp != 0) { min_result = min(min_result, tmp); }
		
		return;
	}
	
	for(int i=index; i<n*n; i++) {
		if(check[i]) { continue; }
		vec.push_back(i);
		check[i] = true;
		dfs(i);
		vec.pop_back();
		check[i] = false;
	}
}

void solve() {
	dfs(0);
	if(min_result == 999999999) {
		min_result = 0;
	}
	cout << min_result;
}

int main() {
	input();
	solve();
	
}