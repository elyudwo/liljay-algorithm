#include <iostream>
#include <string>

using namespace std;

int n,x;
string answer = "";

void input() {
	cin >> n >> x;
}

void solve() {
	// 불가능한 경우 
	if(n * 26 < x || n * 1 > x) { cout << "!"; return; }


	int s = n;
	
	for(int i=0; i<s; i++) {
		int n_tmp = n-1;
		int x_tmp = x;
		
		if(n_tmp * 26 >= x-1) {
			answer += "A";
			x -= 1;
		}
		else {
			int tmp = x - n_tmp * 26;
			char c = 'A' + (tmp-1);
			answer += c;
			x -= tmp;
		}
		n -= 1;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}