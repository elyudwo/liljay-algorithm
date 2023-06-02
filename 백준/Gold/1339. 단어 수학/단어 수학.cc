#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
	
using namespace std;

int n;
vector<string> vec;
int v[26] = {0,};
vector<pair<int,char> > st;
int arr[26] = {0 ,};

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
}

bool cmp(pair<int,char> a, pair<int,char> b) {
	return a.first > b.first;
}

void solve() {
	for(string str : vec) {
		for(int i=0; i<str.size(); i++) { v[str[i] - 'A'] += pow(10, str.size()-i); }
	}
	
	for(int i=0; i<26; i++) {
		if(v[i] != 0) {
			st.push_back({v[i], char(i + 'A')});
		}
	}
	
	sort(st.begin(),st.end(),cmp);
	
	//cout << st[0].first << " " << st[1].first << endl;
	
	int cnt = 9;
	 
	for(pair<int,char> pa : st) {
		arr[pa.second - 'A'] = cnt;
		cnt -= 1;
	}
	int answer = 0;
	
	for(string str : vec) {
		int result = 0;
		int s = str.size()-1;
		for(int i=0; i<str.size(); i++) {
			result += pow(10,s) * arr[(str[i] - 'A')]; 
		    s -= 1;
		}
		answer += result;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}