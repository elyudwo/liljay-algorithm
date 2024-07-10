#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>

using namespace std;

int n, m, answer = 0;
set<string> se;
vector<char> v;
string str = "";

void dfs() {
	if(str.size() == n) {
		bool check[m] = {false,};
		for(int i=0; i<str.size(); i++) {
			for(int j=0; j<m; j++) {
				if(str[i] == v[j]) {
					check[j] = true;
				}
			}
		}
		
		for(int i=0; i<m; i++) { if(!check[i]) { return; } }
		answer++;
		return;
	}
	
	for(int i=0; i<10; i++) {
	    char c = i + '0';
		str.push_back(c);
		dfs();
		str.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		char tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	dfs();
	
	
	cout << answer;
} 