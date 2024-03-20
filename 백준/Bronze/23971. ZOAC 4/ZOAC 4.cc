#include <iostream>

using namespace std;

int h,w,n,m;

void input() {
	cin >> h >> w >> n >> m;
}

void solve() {
	n++; m++;
	long long garo = h / n;
	if(h % n != 0) { garo++; }
	long long sero = w / m;
	if(w % m != 0) { sero++; }
	long long answer = garo * sero;
	
	cout << answer;
}

int main() {
	input();
	solve();
} 