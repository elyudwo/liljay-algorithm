#include <iostream>
#include <deque>

using namespace std;

int n,m,h;

// 높이, 가로, 세로 
int arr[101][101][101];
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dh[] = {0,0,0,0,-1,1};

struct pos {
	int h;
	int x;
	int y;
};

deque<pos> dq;

void input() {
	cin >> n >> m >> h;
	for(int i=0; i<h; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<n; k++) {
				cin >> arr[i][j][k];
				if(arr[i][j][k] == 1) {
					dq.push_back({i,j,k});
				}
			}
		}
	}
}

bool checkTomato() {
	for(int i=0; i<h; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<n; k++) {
				if(arr[i][j][k] == 0) {
					return false;
				}
			}
		}
	}
	
	return true;
}

bool move() {
	bool check = false;
	
	int size = dq.size();
	for(int i=0; i<size; i++) {
		for(int j=0; j<6; j++) {
			int nx = dx[j] + dq[0].x;
			int ny = dy[j] + dq[0].y;
			int nh = dh[j] + dq[0].h;
			if(nx < 0 || ny < 0 || nx >= m || ny >= n || nh < 0 || nh >= h) {
			    continue;
			}
			if(arr[nh][nx][ny] == 0) {
				arr[nh][nx][ny] = 1;
				dq.push_back({nh,nx,ny});
				check = true;
			}
		}
		dq.pop_front();
	}
	
	
	if(check) {
		return true;
	}
	return false;
}

void solve() {
	int answer = 0;
	
	while(1) {
		if(move()) {
			answer += 1;
		}
		else {
			break;
		}
	}
	
	if(!checkTomato()) {
		cout << "-1";
	}
	else {
		cout << answer;
	}
}

int main() {
	input();
	solve();
	
}