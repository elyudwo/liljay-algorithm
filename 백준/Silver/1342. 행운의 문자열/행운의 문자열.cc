#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <time.h>
using namespace std;

string str;
string c;
bool check[11];
int answer = 0;
int alphabet[27];

void input() {
	cin >> str;
	for(int i=0; i<str.size(); i++) {
	    alphabet[str[i] - 'a']++;
	}
}

void dfs() {
	if(c.size() == str.size()) {
	    answer += 1;
		return;
	}
	
	for(int i=0; i<str.size(); i++) {
		if(check[i] || c[c.size()-1] == str[i]) continue;
		check[i] = true;
		c += str[i];
		dfs();
		c.pop_back();
		check[i] = false;
	}
}

int factorial(int num) {
    int result = 1;
    for(int i=1; i<=num; i++) {
        result *= i;
    }
    return result;
}

void solve() {
	dfs();
	for(int i=0; i<27; i++) {
	    if(alphabet[i] != 0) {
	        answer /= factorial(alphabet[i]);
	    }
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
}