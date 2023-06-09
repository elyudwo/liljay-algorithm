#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[19][19];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int finish = 0;
int answer_x,answer_y;

void input() {
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			cin >> arr[i][j];
		}
	}
}

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void checkLeftRight(int x, int y, int num) {
	int nx = x;
	int ny = y;
	int cnt = 1;
	vector<pair<int,int> > rem;
	rem.push_back({x,y});
	
	while(1) {
		nx = nx + dx[7];
		ny = ny + dy[7];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	nx = x;
	ny = y;
	
	while(1) {
		nx = nx + dx[3];
		ny = ny + dy[3];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	if(cnt == 5) {
		finish = num;
		sort(rem.begin(), rem.end(), cmp);
		
		answer_x = rem[0].first;
		answer_y = rem[0].second;
		
		return;
	}
}

void checkUpDown(int x, int y, int num) {
	int nx = x;
	int ny = y;
	int cnt = 1;
	vector<pair<int,int> > rem;
	rem.push_back({x,y});
	
	while(1) {
		nx = nx + dx[1];
		ny = ny + dy[1];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	nx = x;
	ny = y;
	
	while(1) {
		nx = nx + dx[5];
		ny = ny + dy[5];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	if(cnt == 5) {
		finish = num;
		sort(rem.begin(), rem.end(), cmp);
		
		answer_x = rem[0].first;
		answer_y = rem[0].second;
		return;
	}
}

void checkDiagFirst(int x, int y, int num) {
	int nx = x;
	int ny = y;
	int cnt = 1;
	vector<pair<int,int> > rem;
	rem.push_back({x,y});
	
	while(1) {
		nx = nx + dx[2];
		ny = ny + dy[2];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	nx = x;
	ny = y;
	
	while(1) {
		nx = nx + dx[6];
		ny = ny + dy[6];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	if(cnt == 5) {
		finish = num;
		sort(rem.begin(), rem.end(), cmp);
		
		answer_x = rem[0].first;
		answer_y = rem[0].second;
		return;
	}
}

void checkDiagSecond(int x, int y, int num) {
	int nx = x;
	int ny = y;
	int cnt = 1;
	vector<pair<int,int> > rem;
	rem.push_back({x,y});
	
	while(1) {
		nx = nx + dx[0];
		ny = ny + dy[0];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	nx = x;
	ny = y;
	
	while(1) {
		nx = nx + dx[4];
		ny = ny + dy[4];
		
		if(nx < 0 || ny < 0 || nx >= 19 || ny >= 19) { break; }
		if(arr[nx][ny] == num) { cnt += 1; rem.push_back({nx,ny}); }
		else { break; }
	}
	
	if(cnt == 5) {
		finish = num;
		sort(rem.begin(), rem.end(), cmp);
		
		answer_x = rem[0].first;
		answer_y = rem[0].second;
		return;
	}
}

void checkFinish(int x, int y, int num) {
	// 좌우
	checkLeftRight(x, y, num);
	if(finish != 0) { return; }
	
	// 위아래
	checkUpDown(x, y, num);
	if(finish != 0) { return; }
	
	//대각 1
	checkDiagFirst(x, y, num);
	if(finish != 0) { return; }
	
	//대각 2 
	checkDiagSecond(x, y, num);
	if(finish != 0) { return; }
}

void solve() {
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(arr[i][j] == 1 || arr[i][j] == 2) {
				checkFinish(i,j,arr[i][j]);
				if(finish != 0) {
					cout << finish << '\n';
					cout << answer_x+1 << " " << answer_y+1;
					return;
				}
			}
		}
	}
	
	cout << finish;
}

int main() {
	input();
	solve();
	
}