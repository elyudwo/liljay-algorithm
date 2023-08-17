#include <iostream>

using namespace std;

string str;
int answer = 2;

void dfs(string &str, int start, int end, bool check) {
	if(start >= end) {
		if(check) { answer = 1; }
		else { answer = 0; }
		return;
	}
	
	if(str[start] == str[end]) {
		dfs(str, start + 1, end - 1, check);
	}
	else {
		if(check) { return; }
		
		// 1. start 쪽 삭제 
		dfs(str, start+1, end, true);
		
		// 2. end 쪽 삭제 
		dfs(str, start, end-1, true);
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		cin >> str;
		dfs(str, 0, str.size()-1, false);
		cout << answer << '\n';
		answer = 2;
	}

}