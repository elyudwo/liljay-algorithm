#include <iostream>
#include <queue>

using namespace std;

string str[26];
char c[7] = {'|', '-', '+', '1', '2', '3', '4'};

int n,m;
int mos_x, mos_y;
int zag_x, zag_y;

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> str[i];
		for(int j=0; j<m; j++) {
			if(str[i][j] == 'M') {
				mos_x = i;
				mos_y = j;
			}
			if(str[i][j] == 'Z') {
				zag_x = i;
				zag_y = j;
			}
		}
	}
}

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool checkFlow(vector<int> vec) {
	for(int i=0; i<vec.size(); i++) {
		if(vec[i] == 1) {
			
		}
	}
}

bool bfs() {
	queue<pair<int,int> > q;
	bool check[26][26] = {false,};
	check[mos_x][mos_y] = true;
	
	for(int i=0; i<4; i++) {
		int x = dx[i] + mos_x;
		int y = dy[i] + mos_y;
		
		if(x < 0 || y < 0 || x >= n || y >= m || check[x][y] || str[x][y] == '.') { continue; }
		if(i == 0 && (str[x][y] == '-' || str[x][y] == '+' || str[x][y] =='1' || str[x][y] == '2')) { check[x][y] = true; q.push({x,y}); }
		else if(i == 1 && (str[x][y] == '-' || str[x][y] == '+' || str[x][y] == '3' || str[x][y] == '4')) { check[x][y] = true; q.push({x,y}); }
		else if(i == 2 && (str[x][y] == '|' || str[x][y] == '+' || str[x][y] == '4' || str[x][y] == '1')) { check[x][y] = true; q.push({x,y}); }
		else if(i == 3 && (str[x][y] == '|' || str[x][y] == '+' || str[x][y] == '2' || str[x][y] == '3')) { check[x][y] = true; q.push({x,y}); }
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		if(str[x][y] == 'Z') { return true; }
		
		if(str[x][y] == '|') {
			
			for(int i=2; i<4; i++) {
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			int nx = x + 1;
			int ny = y;
			
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x-1;
			ny = y;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
		else if(str[x][y] == '-') {
			int nx = x;
			int ny = y+1;
			
			for(int i=0; i<2; i++) {
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x;
			ny = y-1;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) { 
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
		else if(str[x][y] == '+') {
			
			for(int i=0; i<4; i++) {
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			int nx = x + 1;
			int ny = y;
			
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x-1;
			ny = y;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x;
			ny = y+1;
			
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x;
			ny = y-1;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) { 
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
		else if(str[x][y] == '1') {
			
			for(int i=0; i<4; i++) {
				if(i == 0 || i == 2) { continue; }
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			int nx = x;
			int ny = y+1;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			
			nx = x+1;
			ny = y;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
		else if(str[x][y] == '2') {
			
			for(int i=0; i<4; i++) {
				if(i == 0 || i == 3) { continue; }
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			
			int nx = x-1;
			int ny = y;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x;
			ny = y+1;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
		else if(str[x][y] == '3') {
			
			for(int i=0; i<4; i++) {
				if(i == 1 || i == 3) { continue; }
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			
			int nx = x-1;
			int ny = y;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x;
			ny = y-1;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
		else if(str[x][y] == '4') {
			
			for(int i=0; i<4; i++) {
				if(i == 1 || i == 2) { continue; }
				int tmp_x = dx[i] + x;
				int tmp_y = dy[i] + y;
				if(tmp_x < 0 || tmp_y < 0 || tmp_x >= n || tmp_y >= m || str[tmp_x][tmp_y] == '.') { return false; }
				
				if(i == 0 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '3' || str[tmp_x][tmp_y] == '4')) { return false;}
				else if(i == 1 && (str[tmp_x][tmp_y] == '|' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '2')) { return false;}
				else if(i == 2 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '2' || str[tmp_x][tmp_y] == '3')) { return false; }
				else if(i == 3 && (str[tmp_x][tmp_y] == '-' || str[tmp_x][tmp_y] == '1' || str[tmp_x][tmp_y] == '4'))  { return false; }
			}
			
			int nx = x;
			int ny = y-1;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
			
			nx = x+1;
			ny = y;
			if(!(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == '.')) {
				q.push({nx,ny});
				check[nx][ny] = true;
			}
		}
	}
	
	return false;
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(str[i][j] == '.') {
				for(int k=0; k<7; k++) {
					str[i][j] = c[k];
					if(bfs()) {
						cout << i+1 << " " << j+1 << " " << c[k];
						return;
					}
				}
				str[i][j] = '.';
			}
		}
	}
}

int main() {
	input();
	solve();
	
}