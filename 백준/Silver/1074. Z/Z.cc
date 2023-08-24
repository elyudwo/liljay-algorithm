#include <iostream>
#include <cmath>

using namespace std;

int n,r,c;
int answer = 0;

void input() {
	cin >> n >> r >> c;
}

void divide(int x, int y, int now) {
	//cout << x << " " << y << " " << answer << endl;
	if(x == r && y == c) {
		cout << answer;
		return;
	}
	
	if(r < x + now && r >= x && c < y + now && c >= y) {
		divide(x, y, now/2);
		divide(x, y + now/2, now/2);
		divide(x + now/2, y, now/2);
		divide(x + now/2, y + now/2, now/2);
	}
	else {
		answer += now * now;
	}
}

void solve() {
	divide(0,0,pow(2,n));
}

int main() {
	input();
	solve();
	
}