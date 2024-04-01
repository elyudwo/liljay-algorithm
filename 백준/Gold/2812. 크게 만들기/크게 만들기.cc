#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string str;
int n,k; 

void input() {
	cin >> n >> k;
	cin >> str;
	
}

void solve() {
	string answer = "";
	stack<char> real;
	
	for(int i=0; i<str.size(); i++) {
		if(!real.empty()) {
			while(k > 0 && !real.empty()) {
				if(real.top() < str[i]) {
					real.pop();
					k--;
					continue;
				}
				break;
			}
		}
		real.push(str[i]);
	}
	
	while(!real.empty()) {
		answer += real.top();
		real.pop();
	}
	reverse(answer.begin(), answer.end());
	
	while(k--) {
		answer.pop_back();
	}
	
	cout << answer;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}