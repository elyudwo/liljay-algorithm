#include <iostream>
#include <algorithm>
using namespace std;

int v[501][501];

int main(void)
{
	int n,m,b;
	cin >> n >> m >> b;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> v[i][j];
		}
	}
	
	int time = 2000000000;
	int height = -1;
	
	for(int i=0; i<=256; i++) {
		//가방에 들어있는 블록의 개수 
		int tmp = b;
		// dig == 파낸 블록 수 , fill == 채운 블록 수 
		int dig = 0;
		int fill = 0;
		int time_tmp = 0;
		
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=m; k++) {
				if(v[j][k] >= i) {
					dig = dig + v[j][k] - i;
					time_tmp = time_tmp + (v[j][k]-i) * 2;
				}
				else {
					fill = fill + i - v[j][k];
					time_tmp = time_tmp + (i-v[j][k]);
				}
			}
		}
		if(dig + tmp >= fill && time >= time_tmp) {
			time = time_tmp;
			height = i;
		}
	}
	
	cout << time << " " << height;
	
	return 0;
}
