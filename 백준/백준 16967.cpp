#include <iostream>

using namespace std;

int v[601][601];
int lee[601][601];
int main(void)
{
	int h,w,x,y;
	cin >> h >> w >> x >> y;
	
	for(int i=0; i<h+x; i++) {
		for(int j=0; j<w+y; j++) {
			cin >> v[i][j];	
		}
	}
	// ±³ÁýÇÕ
	for(int i=x; i<h; i++) {
		for(int j=y; j<w; j++) {
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
