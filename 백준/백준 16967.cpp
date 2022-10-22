#include <iostream>

using namespace std;

int v[1001][1001];
int result[1001][1001];
int main(void)
{
	int h,w,x,y;
	cin >> h >> w >> x >> y;
	
	for(int i=0; i<h+x; i++) {
		for(int j=0; j<w+y; j++) {
			cin >> v[i][j];
		}
	}
	
	for(int i=x; i<x + (h-x); i++) {
		for(int j=y; j<y + (w - y); j++) {
			v[i][j] = v[i][j] - v[i-x][j-y];
		}
	}
	
	
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
