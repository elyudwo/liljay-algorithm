#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vec;
string start,e,result;
int n,t,question;

void solve() {
	for(int i=0; i<question; i++) {
		for(int j=0; j<n-1; j++) {
			if(vec[i][j] == '-') {
				swap(start[j],start[j+1]);
			}
		}
	}
	
	for(int i=t-1; i>question; i--) {
		for(int j=0; j<n-1; j++) {
			if(vec[i][j] == '-') {
				swap(e[j],e[j+1]);
			}
		}
	}
	
	for(int i=0; i<start.length()-1; i++) {
		if(start[i] != e[i]) {
			if(i == start.length()-2) {
				result += "-";
				swap(start[i],start[i+1]);
			}
			else {
				result += "-*";
				swap(start[i],start[i+1]);
				i++;
			}
		}
		else {
			result += "*";
		}
	}
	
	if(start == e) {
		cout << result;
	}
	else {
		for(int i=0; i<start.length()-1; i++) {
			cout << "x";
		}
	}
	
}

void input() {
	cin >> n;
	cin >> t;
	cin >> e;
	
	for(int i=0; i<n; i++) {
		start += 'A' + i;
	}
	
	string tmp;
	for(int i=0; i<t; i++) {
		cin >> tmp;
		if(tmp[0] == '?') {
			question = i;
		}
		vec.push_back(tmp);
	}
}

int main() {
	input();
	solve();
}
