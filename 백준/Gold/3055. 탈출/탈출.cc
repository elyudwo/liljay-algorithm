#include <iostream>
#include <queue>

using namespace std;

int n,m;
string arr[51];
bool dochiCheck[51][51];
bool check[51][51];
queue<pair<int,int> > dochi;
vector<pair<int,int> > water_rem;
bool result_check = false;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 'S') {
				dochi.push({i,j}); 
				dochiCheck[i][j] = true;
			}
			else if(arr[i][j] == '*') {
				check[i][j] = true;
				water_rem.push_back({i,j}); 
			}
		}
	}
}

void waterFlow() {
	vector<pair<int,int> > rem;
	
	for(int i=0; i<water_rem.size(); i++) {
		for(int j=0; j<4; j++) {
			int x = dx[j] + water_rem[i].first;
			int y = dy[j] + water_rem[i].second;
			
			if(x < 0 || y < 0 || x >= n || y >= m || check[x][y]) { continue; }
			if(arr[x][y] == '*' || arr[x][y] == 'X' || arr[x][y] == 'D') { continue; }
			check[x][y] = true;
			rem.push_back({x,y});
		}
	}
	 
	water_rem.clear();
	
	for(int i=0; i<rem.size(); i++) {
		int x = rem[i].first;
		int y = rem[i].second;
		
		water_rem.push_back({x,y});
		arr[x][y] = '*';
	}
}

bool goSemdochi() {
	bool result = false;
	bool check[51][51];
	int size = dochi.size();
	
	while(size--) {
		int x = dochi.front().first;
		int y = dochi.front().second;
		for(int i=0; i<4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if(dochiCheck[nx][ny] || arr[nx][ny] == 'X' || arr[nx][ny] == '*' || dochiCheck[nx][ny]) { continue; }
			
			if(arr[nx][ny] == 'D') {
				result_check = true;
				return true;
			}
			dochiCheck[nx][ny] = true;
			dochi.push({nx,ny});
			result = true;
		}
		
		dochi.pop();
	}
	
	return result;
}

void printWater() {
	for(int i=0; i<n; i++) {
		cout << arr[i] << endl;
	}
}

void solve() {
	int day = 0;
	
	while(1) {
		//cout << endl;
		//printWater();
		day += 1;
		waterFlow();
		
		if(!goSemdochi()) {
			cout << "KAKTUS";
			return;
		}
		
		if(result_check) {
			cout << day;
			return;
		}
	}
}

int main() {
	input();
	solve();
	
}