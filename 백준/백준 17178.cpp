#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<pair<string,int> > v;
vector<pair<string,int> > rem;
map<string,int> ma;
stack<string> stk;
bool check = true;
int cnt = 1;


void deleteStk() {
	while(!stk.empty()) {
		if(ma[stk.top()] == cnt) {
			stk.pop();
			cnt++;
		}
		else {
			break;
		}
	}
}

bool solve() {
	bool result = true;
	
	for(int i=0; i<v.size(); i++) {
	    string tmp = v[i].first + to_string(v[i].second);
		if(ma[tmp] == cnt) {
			cnt++;
		}
		else {
			deleteStk();
			stk.push(tmp);
		}
	}
	deleteStk();
	if(!stk.empty()) {
		result = false;
	}
	
	return result;
}

bool cmp(pair<string,int> a, pair<string,int> b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int n;
	cin >> n;
	string str;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<5; j++) {
			cin >> str;
			string c1 = str.substr(0,1);
			string s1 = str.substr(2);
			int tmp = stoi(s1);
			v.push_back({c1,tmp});
		}
	}
	
	rem = v;
 	sort(rem.begin(),rem.end(),cmp);
 	
 	for(int i=0; i<rem.size(); i++) {
 		string tmp = rem[i].first + to_string(rem[i].second);
 		ma[tmp] = i+1;
	}
 	
	if(solve()) {
		cout << "GOOD";
	}
	else {
		cout << "BAD";
	}
}
