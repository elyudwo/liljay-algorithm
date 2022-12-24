#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

struct fireBall {
	int go;
	bool odd;
	bool even;
	int w;
	int v;
	int d;
	int much;
};

fireBall ball[51][51];
fireBall rem[51][51];

void zero(int a,int x,int y) {
	if(a == 1) {
		rem[x][y].go = 0;
		rem[x][y].odd = false;
		rem[x][y].even = false;
		rem[x][y].w = 0;
		rem[x][y].v = 0;
		rem[x][y].d = 0;
		rem[x][y].much = 0;
	}
	else {
		ball[x][y].go = 0;
		ball[x][y].odd = false;
		ball[x][y].even = false;
		ball[x][y].w = 0;
		ball[x][y].v = 0;
		ball[x][y].d = 0;
		ball[x][y].much = 0;
	}
}

void input() {
	cin >> n >> m >> k;
	int x,y,w,v,d;
	for(int i=0; i<m; i++) {
		cin >> x >> y >> w >> v >> d;
		ball[x][y].w = w;
		ball[x][y].v = v;
		ball[x][y].d = d;
		ball[x][y].much = 1;
	}
}


void splitRem() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(rem[i][j].much > 1) {
				if(rem[i][j].w/5 == 0) {
					zero(1,i,j);
				}
				else {
					rem[i][j].w /=5;
					rem[i][j].v /= rem[i][j].much;
					if(rem[i][j].odd && rem[i][j].even) {
						// go 가 1 이면 0,2,4,6
						rem[i][j].go = 1;
					}
					else {
						// go 가 2 이면 1,3,5,7
						rem[i][j].go = 2;
					}
					rem[i][j].much = 50;
				}
			}
		}
	}
}

void copy() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			ball[i][j] = rem[i][j];
			zero(1,i,j);
		}
	}
}



void move(int x,int y) {
	if(ball[x][y].much == 1) {
		int nx = (dx[ball[x][y].d] * ball[x][y].v + x) % (n);
		int ny = (dy[ball[x][y].d] * ball[x][y].v + y) % (n);
		if(nx == 0) { nx = n; }
		if(ny == 0) { ny = n; }
		cout << nx << " " << ny << endl;
		if(rem[nx][ny].much) {
			rem[nx][ny].w += ball[x][y].w;
			rem[nx][ny].v += ball[x][y].v;
			rem[nx][ny].much++;
			if(ball[x][y].d % 2 == 0) {
				rem[nx][ny].even = true;
			}
			else {
				rem[nx][ny].odd = true;
			}
		}
		else {
			rem[nx][ny] = ball[x][y];
			if(ball[x][y].d % 2 == 0) {
				rem[nx][ny].even = true;
			}
			else {
				rem[nx][ny].odd = true;
			}
		}
		zero(0,x,y);
	}
	
	else if(ball[x][y].much == 50) {
		if(ball[x][y].go == 1) {
			for(int i=0; i<9; i=i+2) {
				int nx = x + dx[i] * ball[x][y].v % n;
				int ny = y + dy[i] * ball[x][y].v % n;
				if(nx == 0) nx = n;
				if(ny == 0) ny = n;
				
				if(rem[nx][ny].much) {
					rem[nx][ny].w += ball[x][y].w;
					rem[nx][ny].v += ball[x][y].v;
					rem[nx][ny].much++;
					if(ball[x][y].d % 2 == 0) {
						rem[nx][ny].even = true;
					}
					else {
						rem[nx][ny].odd = true;
					}
				}
				else {
					rem[nx][ny] = ball[x][y];
					if(ball[x][y].d % 2 == 0) {
						rem[nx][ny].even = true;
					}
					else {
						rem[nx][ny].odd = true;
					}
				}
				
			}
		}
		else if(ball[x][y].go == 2) {
			for(int i=1; i<9; i=i+2) {
				int nx = x + dx[i] * ball[x][y].v % n;
				int ny = y + dy[i] * ball[x][y].v % n;
				if(nx == 0) nx = n;
				if(ny == 0) ny = n;
				
				if(rem[nx][ny].much) {
					rem[nx][ny].w += ball[x][y].w;
					rem[nx][ny].v += ball[x][y].v;
					rem[nx][ny].much++;
					if(ball[x][y].d % 2 == 0) {
						rem[nx][ny].even = true;
					}
					else {
						rem[nx][ny].odd = true;
					}
				}
				else {
					rem[nx][ny] = ball[x][y];
					if(ball[x][y].d % 2 == 0) {
						rem[nx][ny].even = true;
					}
					else {
						rem[nx][ny].odd = true;
					}
				}
			}
		}
	}
}

void solve() {
	int result = 0;
	for(int i=0; i<k; i++) {
		for(int j=1; j<=n; j++) {
			for(int q=1; q<=n; q++) {
				if(ball[j][q].much) {
					move(j,q);
				}
			}
		}
		splitRem();
		copy();
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(ball[i][j].much) {
				result += ball[i][j].w;
			}
		}
	}
	cout << result;
}

int main() {
	input();
	solve();
}
