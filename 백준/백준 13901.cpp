#include <iostream>
#include <string>
using namespace std;

int v[1001][1001];
int mov[4];
// 2 == x
int dx[5] = {0,-1,1,0,0}; 
int dy[5] = {0,0,0,-1,1};
 
int main(void)
{
	int r,c,a,b;
	cin >> r >> c;
	int k;
	cin >> k;
	for(int i=0; i<k; i++) {
		cin >> a >> b;
		v[a][b] = 2;
	}
	int nx,ny;
	cin >> nx >> ny;
	v[nx][ny] = 1;
	int tmp_x,tmp_y;
	
	for(int i=0; i<4; i++) {
		cin >> mov[i];
	}
	
	while(1) {
		int cnt = 0;
		for(int i=0; i<4; i++) {
			tmp_x = nx + dx[mov[i]];
			tmp_y = ny + dy[mov[i]];
			if(tmp_x >= r || tmp_y >= c || tmp_x < 0 || tmp_y < 0 || v[tmp_x][tmp_y]) {
				cnt++;
				continue;
			}
		
			v[tmp_x][tmp_y] = 1;
			nx = tmp_x;
			ny = tmp_y;
		}
		if(cnt == 4) {
			break;
		}
	}
	
	
	cout << nx << " " << ny;
	
	return 0;
}
