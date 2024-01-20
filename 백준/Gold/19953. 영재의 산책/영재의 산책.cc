#include <iostream>

using namespace std;

// 동, 남, 서, 북 
int d[4];
int v,m,t;
long long x,y;

void input() {
	cin >> v >> m >> t;
}

void makeCircle() {
	int tmp = v;
	
	if(t >= 1) {
		y += tmp;
	}
	if(t >= 2) {
		tmp = (tmp * m) % 10;
		x += tmp;
	}
	if(t >= 3) {
		tmp = (tmp * m) % 10;
		y -= tmp;
	}
	if(t >= 4) {
		tmp = (tmp * m) % 10;
		x -= tmp;
	}
	
	cout << x << " " << y;
}

void solve() {
	int tmp = v;
	
	if(t <= 4) {
		makeCircle();
		return;
	}
	
	for(int i=0; i<4; i++) {
		tmp = (tmp * m) % 10;
		d[i] = tmp;
//		cout << d[i] << " ";
	}
	
	y += v;
	t--;
	
	int circle = t / 4;
	int remain = t % 4;
	
	y += (d[3] - d[1]) * circle;
	x += (d[0] - d[2]) * circle;

	for(int i=0; i<remain; i++) {
		if(i == 0) { x += d[0]; }
		if(i == 1) { y -= d[1]; }
		if(i == 2) { x -= d[2]; }
	}
	
	
	cout << x << " " << y;
}

int main() {
	input();
	solve();
	
}