#include <iostream>
#include <string>
using namespace std;

string str;
int left1,right1,up1,down1;
int v[101][101];
//³²,¼­,ºÏ,µ¿ RRRR
//³²,µ¿,ºÏ,¼­ LLLL
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int nx = 49;
int ny = 49;

int main(void)
{
	int n;
	cin >> n;
	cin >> str;
	v[nx][ny] = 1;
	int tmp = 0;
	
	for(int i=0; i<str.length(); i++) {
		if(str[i] == 'R') {
			if(tmp == 3) {
				tmp = 0;
			}
			else {
				tmp++;	
			}
			
		}
		else if(str[i] == 'L') {
			if(tmp == 0) {
				tmp = 3;
			}
			else {
				tmp--;
			}
		}
		else if(str[i] == 'F') {
			nx = dx[tmp] + nx;
			ny = dy[tmp] + ny;
			v[nx][ny] = 1;
		}
	}
	bool c1 = false;
	for(int i=0; i<101; i++) {
		for(int j=0; j<101; j++) {
			if(v[i][j] == 1) {
				up1 = i;
				c1 = true;
				break;
			}
		}
		if(c1) break;
	}
	
	c1 = false;
	for(int i=0; i<101; i++) {
		for(int j=0; j<101; j++) {
			if(v[j][i] == 1) {
				left1 = i;
				c1 = true;
				break;
			}
		}
		if(c1) break;
	}
	
	c1 = false;
	for(int i=100; i>=0; i--) {
		for(int j=0; j<101; j++) {
			if(v[j][i] == 1) {
				right1 = i;
				c1 = true;
				break;
			}
		}
		if(c1) break;
	}
	
	c1 = false;
	for(int i=100; i>=0; i--) {
		for(int j=0; j<101; j++) {
			if(v[i][j] == 1) {
				down1 = i;
				c1 = true;
				break;
			}
		}
		if(c1) break;
	}
	
	for(int i=up1; i<=down1; i++) {
		for(int j=left1; j<=right1; j++) {
			if(v[i][j] == 1) {
				cout << ".";
			}
			else {
				cout << "#";
			}
		}
		cout << '\n';
	}
	
	
	return 0;
}
