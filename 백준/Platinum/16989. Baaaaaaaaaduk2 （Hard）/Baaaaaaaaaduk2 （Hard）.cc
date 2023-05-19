#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int arr[1001][1001];
bool check[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0}; 
map<pair<int,int>,int> ma1;
map<vector<pair<int,int>>,int> ma2;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int,int> > q;
	q.push({a,b});
	int zero = 0;
	int stone = 1;
	
	vector<pair<int,int>> rem;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
			if(arr[nx][ny] == 0 && !check[nx][ny]) {
				rem.push_back({nx,ny});
				zero += 1;
			    check[nx][ny] = true;
			}
			else if(arr[nx][ny] == 2 && !check[nx][ny]) {
				stone += 1;
				check[nx][ny] = true;
				q.push({nx,ny});
			}
		}
	}
	
	sort(rem.begin(),rem.end());
	
	
	if(zero == 1) {
		int x = rem[0].first;
		int y = rem[0].second;
		ma1[{x,y}] += stone;
	}
	else if(zero == 2) {
		ma2[rem] += stone;
	}
	int size = rem.size();
	for(int i=0; i<size; i++) {
	    check[rem[i].first][rem[i].second] = false;
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!check[i][j] && arr[i][j] == 2) {
				check[i][j] = true;
				bfs(i,j);
			}
		}
	}
	
	
	int answer = 0;
	
	//cout << ma1.size() << " " << ma2.size() << endl;
	
	for(pair<vector<pair<int,int>>,int> m : ma2) {
		int tmp = ma1[m.first[0]] + ma1[m.first[1]];
		
		answer = max(answer,m.second + tmp);
	}
	
	vector<int> vec;
	for(auto m : ma1) {
		vec.push_back(m.second);
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	if(vec.size() == 1) {
	    answer = max(answer, vec[0]);
	}
	else if(vec.size() > 1) {
	    answer = max(answer, vec[0] + vec[1]);
	}
	
	cout << answer;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	input();
	solve();
	
}