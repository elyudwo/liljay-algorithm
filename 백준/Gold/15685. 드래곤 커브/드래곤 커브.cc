#include <iostream>
#include <vector> 
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int arr[101][101];
int answer = 0;

// 0 1 2 1 2 3 2 1

void makeCurve(int x, int y, int d, int g) {
	vector<int> dis;
	dis.push_back(d);
	arr[x][y] = 1;
	
	// 0 세대 
	int nx = x + dx[d];
	int ny = y + dy[d];
	arr[nx][ny] = 1;
	x = nx;
	y = ny;
	
	for(int i=0; i<g; i++) {
		int size = dis.size()-1;
		for(int j=size; j>=0; j--) {
			int now_dis = (dis[j] + 1) % 4;
			
			nx = x + dx[now_dis];
			ny = y + dy[now_dis];
			dis.push_back(now_dis);
			arr[nx][ny] = 1;
			x = nx;
			y = ny;
		}
	}
}

void input() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x,y,d,g;
		cin >> y >> x >> d >> g;
		makeCurve(x,y,d,g);
	}
}

void print() {
	for(int i=0; i<=10; i++) {
		for(int j=0; j<=10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {
	for(int i=0; i<100; i++) {
		for(int j=0; j<100; j++) {
			if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) {
				answer += 1;
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}