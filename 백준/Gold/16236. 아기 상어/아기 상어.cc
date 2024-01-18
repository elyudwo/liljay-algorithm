#include <iostream>
#include <deque>
#include <cmath> 
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
int x,y;
int weight = 2;
int eat = 0;
int fish_size = 0;
int arr[22][22];
int answer = 0;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
			if(arr[i][j] >= 1 && arr[i][j] <= 6) {
				fish_size++;
			}
			if(arr[i][j] == 9) {
				x = i;
				y = j;
				arr[i][j] = 0;
			}
		}
	}
}

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int bfs() {
	queue<tuple<int,int,int> > q;
	q.push({x, y, 0});
	
	bool check[21][21] = {false,};
	check[x][y] = true;
	
	int result = 20000000;
	vector<pair<int,int>> vec;
	
	while(!q.empty()) {
		auto[a, b, cnt] = q.front();
		
		q.pop();
		
		if(result < cnt) break;
		
		if(arr[a][b] < weight && arr[a][b] != 0) {
			result = cnt;
			vec.push_back({a,b});
			continue;
		}
		
		
		for(int i=0; i<4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			
			if(nx < 1 || ny < 1 || nx > n || ny > n || check[nx][ny] || arr[nx][ny] > weight) {
				continue;
			}
			
			check[nx][ny] = true;
			q.push({nx, ny, cnt + 1});
		}
	}
	
	if(result == 20000000) {
	    return 0;
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	x = vec[0].first;
	y = vec[0].second;
	arr[x][y] = 0;
	answer += result;
	
	eat++;
	if(eat == weight) {
	    eat = 0;
	    weight++;
	}
	
	return 1;
}

void solve() {
	while(bfs()) {
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}