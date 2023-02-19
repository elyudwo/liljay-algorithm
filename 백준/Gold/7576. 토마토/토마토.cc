#include <iostream>
#include <deque>
using namespace std;

int m,n;
int day = 0;
int arr[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool check[1001][1001];

deque<pair<int,int> > vec;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 1) { 
				vec.push_back({i,j}); 
				check[i][j] = true;
			}
		}
	}
}

bool move() {
	bool result = false;
	int size = vec.size();
	
	for(int i=0; i<size; i++) {
		for(int k=0; k<4; k++) {
			int nx = vec[0].first + dx[k];
			int ny = vec[0].second + dy[k];
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || arr[nx][ny] == -1 || arr[nx][ny] == 1 || check[nx][ny]) { continue; }
			check[nx][ny] = true;
			result = true;
			vec.push_back({nx,ny});
			arr[nx][ny] = 1;
		}
		vec.pop_front();
	}
	
	return result;
}

bool checkZero() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(arr[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

void print() {
	cout << '\n';
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

void solve() {
	while(1) {
		if(!move()) {
			if(checkZero()) { cout << "-1"; }
			else { cout << day; }
			break;
		}
		
		day += 1;
	}
}

int main() { 
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}