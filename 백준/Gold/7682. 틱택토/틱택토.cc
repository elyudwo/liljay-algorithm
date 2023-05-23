#include <iostream>

using namespace std;
string str;
char c[3][3];

bool isPossible() {
	int x_cnt = 0;
	int o_cnt = 0;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == 'X') { x_cnt += 1; }
		else if(str[i] == 'O') { o_cnt += 1; }
	}
	
	bool win_check[2] = {false,false};
	
	// (0,0) 에서 가는 경우 
	char tmp = c[0][0];
	
	if(tmp != '.') {
		if(tmp == c[1][1] && tmp == c[2][2]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
		if(tmp == c[1][0] && tmp == c[2][0]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
		if(tmp == c[0][1] && tmp == c[0][2]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
	}
	
	
	// (0,1) 에서 가는 경우
	tmp = c[0][1];
	if(tmp != '.') {
		if(tmp == c[1][1] && tmp == c[2][1]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
	}
	
	//(0,2) 에서 가는 경우
	tmp = c[0][2];
	if(tmp != '.') {
		if(tmp == c[1][1] && tmp == c[2][0]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
		if(tmp == c[1][2] && tmp == c[2][2]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
	}
	
	
	//(1,0) 에서 가는 경우
	tmp = c[1][0];
	if(tmp != '.') {
		if(tmp == c[1][1] && tmp == c[1][2]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		}
	}
	
	//(2,0) 에서 가는 경우
	tmp = c[2][0];
	if(tmp != '.') {
		if(tmp == c[2][1] && tmp == c[2][2]) {
			if(tmp == 'O') { win_check[0] = true; }
			else if(tmp == 'X') { win_check[1] = true; }
		} 
	}
	 
	if((win_check[0] && !win_check[1]) && x_cnt == o_cnt) { return true; }
	if(win_check[1] && !win_check[0] && x_cnt == o_cnt+1) { return true; }
	if(!win_check[0] && !win_check[1] && (x_cnt == 5 && o_cnt == 4)) { return true; }
	
	return false;
}

void solve() {
	for(int i=0; i<9; i++) { c[i/3][i%3] = str[i]; }
	if(isPossible()) { cout << "valid\n"; }
	else { cout << "invalid\n"; }
}

void input() {
	while(1) {
		cin >> str;
		if(str == "end") { return; }
		solve();
	}
}

int main() {
	input();
}