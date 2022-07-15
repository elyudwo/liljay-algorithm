#include <iostream>
#include <cmath>

using namespace std;

int v[501][501];

int main(void)
{
	int n,m,b;
	cin >> n >> m >> b;
	
	double sum = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v[i][j];
			sum = sum + v[i][j];
		}
	}
	sum = round(sum);
	double tmp;
	tmp = round(sum/(n*m));
	
	int time = 0;
	int cnt = 0;
	
	for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(v[i][j] > tmp) {
					time = time + (v[i][j] - tmp) * 2;
					b = b + v[i][j] - tmp;
				}
				else if(v[i][j] < tmp) {
					if(tmp - v[i][j] > b) {
						tmp--;
					}
				}
			}
		}
	
	return 0;
}
