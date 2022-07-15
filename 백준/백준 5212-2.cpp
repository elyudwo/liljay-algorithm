#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main(void)
{
	char v[12][12];
	int n,m;
	cin >> n >> m;
	
	vector<pair<int,int>> lee;
	
	for(int i=0; i<=12; i++) {
		for(int j=0; j<=12; j++) {
			v[i][j] = '.';
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> v[i][j];
		}
	}
	int cnt;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cnt = 0;
			if(v[i][j] == 'X') {
				for(int k=0; k<4; k++) {
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					
					if(v[nx][ny] == '.') {
						cnt++;
					}
				}
				if(cnt >= 3) {
					lee.push_back({i,j});
				}
			}
		}
	}
	
	for(int i=0; i<lee.size(); i++) {
		v[lee[i].first][lee[i].second] = '.';
	}
	
	int min_x = 11;
	int max_x = 0;
	int min_y = 11;
	int max_y = 0;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(v[i][j] == 'X') {
				min_x = min(min_x,i);
				max_x = max(max_x,i);
				min_y = min(min_y,j);
				max_y = max(max_y,j);
				}
			}
		}
	
	for(int i=min_x; i<=max_x; i++) {
		for(int j=min_y; j<=max_y; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
	
	
	return 0;
}
