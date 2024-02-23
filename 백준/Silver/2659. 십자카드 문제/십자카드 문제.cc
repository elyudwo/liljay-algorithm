#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;

int cnt = 1;
string dfs_str;
string min_str = "";
map<string, int> ma;

void input() {
	for(int i=0; i<4; i++) {
		int tmp;
		cin >> tmp;
		min_str += to_string(tmp);
	}
}

string checkMin(string str) {
    string answer = str;
	string rem = answer;
	
    for(int i=0; i<4; i++) {
        char tmp = rem[0];
        rem = rem.substr(1,3);
        rem.push_back(tmp);
        answer = min(rem, answer);
    }
    
    return answer;
}

void solve() {
    string result = checkMin(min_str);
    
    for(int i=1111; i<=9999; i++) {
        string tmp = to_string(i);
        if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0' || tmp[3] == '0') { continue; }
        tmp = checkMin(tmp);
        
        
        if(ma.count(tmp)) {
            continue;
        }
        ma[tmp] = cnt++;
    }
    
	cout << ma[result];
}

int main() {
	input();
	solve();
	
}