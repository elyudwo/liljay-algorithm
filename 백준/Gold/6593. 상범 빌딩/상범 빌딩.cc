#include <iostream>
#include <queue>

using namespace std;

int l,r,c;
int answer = -1;
int S_f, S_x, S_y, E_f, E_x, E_y;
char arr[31][31][31];
bool check[31][31][31];
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int df[] = {0,0,0,0,-1,1};

void init() {
	answer = -1;
	for(int i=1; i<=l; i++) {
		for(int j=1; j<=r; j++) {
			for(int k=1; k<=c; k++) {
				check[i][j][k] = false;
			}
		}
	}
}

struct bum {
	int floor;
	int x;
	int y;
	int cnt;
};

void bfs() {
	queue<bum> q;
	q.push({S_f, S_x, S_y, 0});
	check[S_f][S_x][S_y] = true;
	
	while(!q.empty()) {
		int f = q.front().floor;
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		
		if(f == E_f && x == E_x && y == E_y) {
			answer = cnt;
			break;
		}
		
		q.pop();
		
		// 나머지 
		for(int i=0; i<6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nf = f + df[i];
			
			if(nx < 1 || ny < 1 || nf < 1 || nx > r || ny > c || nf > l || check[nf][nx][ny]) continue;
			if(arr[nf][nx][ny] == '#') continue;
			
			q.push({nf, nx, ny, cnt + 1});
			check[nf][nx][ny] = true;
		}
	}
}

int main() {
	while(1) {
		cin >> l >> r >> c;
		if(l == 0 && r == 0 && c == 0) { break; }
		
		for(int i=1; i<=l; i++) {
			for(int j=1; j<=r; j++) {
				for(int k=1; k<=c; k++) {
					cin >> arr[i][j][k]; 
					if(arr[i][j][k] == 'S') { S_f = i; S_x = j; S_y = k; }
					if(arr[i][j][k] == 'E') { E_f = i; E_x = j; E_y = k; }
				}
			}
		}
		
		bfs();
		
		if(answer != -1) {
			cout << "Escaped in " << answer << " minute(s)." << '\n';
		}
		else {
			cout << "Trapped!" << '\n';
		}
		init();
	}
	
	
}