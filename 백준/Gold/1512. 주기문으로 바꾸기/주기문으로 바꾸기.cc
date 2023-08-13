#include <iostream>
#include <string>

using namespace std;

int n;
string str;

void input() {
	cin >> n;
	cin >> str;	
}

void solve() {
	int answer = 3001;
	
	for(int i=n; i>=1; i--) {
		int result = 0;
		for(int j=0; j<i; j++) {
			int c[26] = {0,};
			int sum = 0, max_value = 0;
			
			for(int k=j; k<str.size(); k = k + i) {
				c[str[k] - 'A'] += 1;
				max_value = max(max_value, c[str[k] - 'A']);
				sum += 1;
			}
			result += (sum - max_value);
		}
		answer = min(answer, result);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}