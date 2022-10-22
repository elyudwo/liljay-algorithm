#include <iostream>
#include <string>
using namespace std;

string str[1010];

int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,1,-1,1,-1,1,-1};

int v[1010][1010];

int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(str[i][j] != '.') {
				v[i][j] = -1;
				int cnt = str[i][j] - '0';
				for(int q=0; q<8; q++) {
					int nx = dx[q] + i;
					int ny = dy[q] + j;
					if(nx < 0 || ny < 0 || nx >=n || ny >= n)	continue;
					v[nx][ny] = v[nx][ny] + cnt;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(v[i][j] == -1) {
				cout << "*";
			}
			else if(v[i][j] >= 10) {
				cout << "M";
			}
			else {
				cout << v[i][j];
			}
		}
		cout << endl;
	}
	
	
	return 0;
}
