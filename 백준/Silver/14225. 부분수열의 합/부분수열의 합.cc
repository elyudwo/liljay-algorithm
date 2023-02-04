#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> vec;
vector<int> rem;
bool check[21];
int n;
set<int> s;
int min_num = 999999999;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
}

void dfs(int x,int index) {
	if(rem.size() == x) {
		int answer = 0;
		for(int i=0; i<rem.size(); i++) {
			answer += rem[i];
		}
		s.insert(answer);
		min_num = min(min_num,answer);
		return;
	}
	
	for(int i=index; i<vec.size(); i++) {
		if(check[i]) continue;
		rem.push_back(vec[i]);
		check[i] = true;
		dfs(x,i);
		rem.pop_back();
		check[i] = false;
	}
	
}

void checkAnswer() {
	for(int i=1; i<=20000000; i++) {
		if(s.find(i) == s.end()) {
			cout << i;
			return;
		}
	}
}

void solve() {
	for(int i=1; i<=vec.size(); i++) {
		dfs(i,0);
	}
	
	checkAnswer();
}


int main() {
	input();
	solve();
	
}