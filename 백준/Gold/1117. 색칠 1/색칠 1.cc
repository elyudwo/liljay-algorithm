#include <iostream>

using namespace std;

long long W, H, f, c, x1, y1, x2, y2;
long long double_g_first, double_g_last, g_one, g_double, s;

void input() {
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
}

void doubleSelect() {
	if(f == 0) {
		double_g_first = -1;
		double_g_last = -1;
	}
	else if(f + f >= W) {
		double_g_first = 0;
		double_g_last = W - f;
	}
	else if(f + f < W) {
		double_g_first = 0;
		double_g_last = f;
	}
	
}

void selectSero() {
    long long s_first, s_last;
    if(c == 0) {
        s_first = H;
        s_last = 0;
    }
    else {
        s_first = H/(c+1);
        s_last = 0;
    }
    
    if(y2 <= s_first) { s = y2 - y1; }
	else if(y1 < s_first && y1 > s_first) { s = s_first - y1; }
	
}

void selectGaro() {
    if(double_g_first == -1 && double_g_last == -1) {
        g_one = x2 - x1;
        g_double = 0;
        return;
    }
    
    // 더블 영역을 넘어갔을때
    if(x1 >= double_g_last) {
        g_one = x2 - x1;
        g_double = 0;
    }
    // 더블 영역 안넘어감
    else if(x2 < double_g_last) {
        g_double = x2 - x1;
        g_one = 0;
    }
    else if(x2 >= double_g_last && x1 < double_g_last) {
        g_double = double_g_last - x1;
        g_one = x2 - double_g_last;
    }
    
}

void solve() {
	long long sum = W * H;
	long long divi = 0;
	
	// 가로 두배 구간 설정
	doubleSelect();
	selectGaro();
	selectSero();
	
	if(c == 0) { divi = s * 1 * (g_one + g_double * 2); }
	else { divi = s * (c+1) * (g_one + g_double * 2); }
	
	sum = sum - divi;
	cout << sum;
}

int main() {
	input();
	solve();
	
}