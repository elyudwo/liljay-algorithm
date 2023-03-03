#include <iostream>
#include <vector>

using namespace std;

int n,m;
int answer = 999999999;
int arr[9][9];
int arr_tmp[9][9]; 

vector<pair<int,int> > vec;
vector<int> rem;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] != 0 && arr[i][j] != 6) {
				vec.push_back({i, j});
			}
		}
	}
}

void eraseAll() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			arr_tmp[i][j] = 0;
		}
	}
}

void init() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			arr_tmp[i][j] = arr[i][j];
		}
	}
}

int checkRec() {
	int result = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr_tmp[i][j] == 0) {
				result += 1;
			}
		}
	}
	
	return result;
}

void letsgo(int x, int y, bool check[4]) {
	if(check[0]) {
		for(int i=y; i<m; i++) {
			if(arr_tmp[x][i] == 6) { break; }
			if(arr_tmp[x][i] == 0) {
				arr_tmp[x][i] = 9;
			}
		}
	}
	if(check[1]) {
		for(int i=y; i>=0; i--) {
			if(arr_tmp[x][i] == 6) { break; }
			if(arr_tmp[x][i] == 0) {
				arr_tmp[x][i] = 9;
			}
		}
	}
	if(check[2]) {
		for(int i=x; i<n; i++) {
			if(arr_tmp[i][y] == 6) { break; }
			if(arr_tmp[i][y] == 0) {
				arr_tmp[i][y] = 9;
			}
		}
	}
	if(check[3]) {
		for(int i=x; i>=0; i--) {
			if(arr_tmp[i][y] == 6) { break; }
			if(arr_tmp[i][y] == 0) {
				arr_tmp[i][y] = 9;
			}
		}
	}
}

void go(int index, int dis) {
	int x = vec[index].first;
	int y = vec[index].second;
	bool check[4] = {false,false,false,false};
	
	if(arr[x][y] == 1) {
		if(dis == 1) {
			check[0] = true; 
		}
		if(dis == 2) {
			check[1] = true; 
		}
		if(dis == 3) {
			check[2] = true; 
		}
		if(dis == 4) {
			check[3] = true; 
		}
	}
	if(arr[x][y] == 2) {
		if(dis == 1) {
			check[0] = true; 
			check[1] = true; 
		}
		if(dis == 2) {
			check[2] = true; 
			check[3] = true; 
		}
		if(dis == 3) {
			check[0] = true; 
			check[1] = true; 
		}
		if(dis == 4) {
			check[2] = true; 
			check[3] = true; 
		}
	}
	if(arr[x][y] == 3) {
		if(dis == 1) {
			check[0] = true; 
			check[3] = true; 
		}
		if(dis == 2) {
			check[0] = true; 
			check[2] = true; 
		}
		if(dis == 3) {
			check[2] = true; 
			check[1] = true; 
		}
		if(dis == 4) {
			check[1] = true; 
			check[3] = true; 
		}
	}
	if(arr[x][y] == 4) {
		if(dis == 1) {
			check[0] = true; 
			check[1] = true; 
			check[3] = true; 
		}
		if(dis == 2) {
			check[0] = true; 
			check[2] = true; 
			check[3] = true; 
		}
		if(dis == 3) {
			check[0] = true; 
			check[1] = true; 
			check[2] = true; 
		}
		if(dis == 4) {
			check[1] = true;
			check[2] = true;
			check[3] = true;
		}
	}
	if(arr[x][y] == 5) {
		check[0] = true;
		check[1] = true;
		check[2] = true;
		check[3] = true;
	}
	
	letsgo(x,y,check);
}

void dfs() {
	if(rem.size() == vec.size()) {		
		init();
		for(int i=0; i<rem.size(); i++) {
			go(i, rem[i]);
		}
		
		int rec = checkRec();
		answer = min(rec, answer);
		
		
		return;
	}
	
	
	for(int i=1; i<=4; i++) {
		rem.push_back(i);
		dfs();
		rem.pop_back();
	}
}

void solve() {
	dfs();
	cout << answer;
}

int main() {
	input();
	solve();
	
}