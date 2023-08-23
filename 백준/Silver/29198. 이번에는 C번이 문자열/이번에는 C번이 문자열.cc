#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
vector<string> vec;

void input() {
	cin >> n >> m >> k;
	
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end());
}

void solve() {
	string answer = "";
	for(int i=0; i<k; i++) {
		answer += vec[i];
	}
	sort(answer.begin(), answer.end());
	cout << answer;
}

int main() {
	input();
	solve();
	
}