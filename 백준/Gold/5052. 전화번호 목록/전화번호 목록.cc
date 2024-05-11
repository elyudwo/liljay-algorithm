#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(int n) {
	vector<string> vec;
	unordered_map<string, int> ma;		
	
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		vec.push_back(str);
		ma[str] = 1;
	}
	
	for(string str : vec) {
	    string tmp = "";
		for(int i=0; i<str.size() - 1; i++) {
			tmp += str[i];
			if(ma[tmp] == 1) {
				cout << "NO\n";
				return;
			}
		}
	}
	
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		solve(n);
	}
	
}