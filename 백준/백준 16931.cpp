#include <iostream>

using namespace std;

int v[101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v[i][j];
		}
	}
	
	int result = 0;
	int cnt = 0;
	result = result + 2 * n*m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			for(int q=0; q<4; q++) {
				bool check = true;
				int nx = i + dx[q];
				int ny = j + dy[q];
				
				if(nx < 0 || ny < 0 || nx >=n || ny >= m) {
					result = result + v[i][j];
					cnt++;
					check = false;
				}	
				if(check) {
					int sum = v[i][j] - v[nx][ny];
					if(sum > 0) {
						result = result + sum;
					}
				}
			}
		}
	}
	cout << result;
	
	return 0;
}
