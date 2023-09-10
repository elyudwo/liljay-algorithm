#include <iostream>

using namespace std;

int n;
string str;
int alp[26] = {0,};

void input() {
	cin >> n;
	cin >> str;
}

bool checkAlp() {
	int result = 0;
	
	for(int i=0; i<26; i++) {
		if(alp[i]) { result++; }
	}
	
	if(result <= n) {
		return true;
	}
	return false;
} 

void solve() {
	int answer = 0;
	int left = 0;
	
	for(int i=0; i<str.size(); i++) {
		alp[str[i] - 'a']++;
		
		if(checkAlp()) { answer = max(answer, i - left + 1); }
		else {
			while(left < i && !checkAlp()) {
				//cout << "HI";
				alp[str[left] - 'a']--;
				left++;
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}