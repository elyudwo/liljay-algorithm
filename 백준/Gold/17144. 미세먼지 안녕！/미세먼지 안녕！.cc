#include <iostream>
#include <vector>
using namespace std;

int arr[51][51];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<pair<int,int> > vec;
int r,c,t;
int rem[51][51];

void input() {
	cin >> r >> c >> t;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == -1) {
				vec.push_back({i,j});
			}
		}
	}
}

void init() {
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			rem[i][j] = 0;
		}
	}
}

void copy() {
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			arr[i][j] = rem[i][j];
		}
	}
	arr[vec[0].first][vec[0].second] = -1;
	arr[vec[1].first][vec[1].second] = -1;
	
}

void diffusion() {
	init();
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			int cnt = 0;
			for(int k=0; k<4; k++) {
				int nx = dx[k] + i;
				int ny = dy[k] + j;
				if(nx < 0 || ny < 0 || nx >=r || ny >= c || arr[nx][ny] == -1) continue;
				rem[nx][ny] = rem[nx][ny] + arr[i][j]/5;
				cnt++;
			}
			rem[i][j] = rem[i][j] + arr[i][j] - (arr[i][j]/5 * cnt);
		}
	}
	
	copy();
}

void activate() {
	
	// 반시계 방향 
	for(int i=2; i<c; i++) {
		int nx = vec[0].first;
		int ny = vec[0].second + i;
		rem[nx][ny] = arr[nx][ny-1];
	}
	
	for(int i=vec[0].first-1; i>=0; i--) {
		rem[i][c-1] = arr[i+1][c-1];
	}
	
	for(int i=c-2; i>=0; i--) {
		rem[0][i] = arr[0][i+1];
	}
	
	for(int i=1; i<vec[0].first; i++) {
		rem[i][0] = arr[i-1][0];
	}
	
	for(int i=1; i<vec[0].first; i++) {
		for(int j=1; j<c-1; j++) {
			rem[i][j] = arr[i][j];
		}
	}
	
	
	// 시계 방향
	for(int i=2; i<c; i++) {
		int nx = vec[1].first;
		int ny = vec[1].second + i;
		rem[nx][ny] = arr[nx][ny-1];
	}
	
	for(int i=vec[1].first+1; i<r; i++) {
		rem[i][c-1] = arr[i-1][c-1];	
	}
	
	for(int i=c-2; i>=0; i--) {
		rem[r-1][i] = arr[r-1][i+1];
	}
	
	for(int i=r-2; i>vec[1].first; i--) {
		rem[i][0] = arr[i+1][0];
	}
	
	for(int i=vec[1].first+1; i<r-1; i++) {
		for(int j=1; j<c-1; j++) {
			rem[i][j] = arr[i][j];
		}
	}
	
	rem[vec[0].first][vec[0].second+1] = 0;
	rem[vec[1].first][vec[1].second+1] = 0;
	
	
	copy();
}

void print() {
	cout << '\n';
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	
	
	
	cout << '\n';
}

void solve() {
	while(t--) {
		diffusion();
		activate();
	}
	
	int answer = 0;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(arr[i][j] != -1) {
				answer += arr[i][j];
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}