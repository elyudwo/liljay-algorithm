#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int,int> ma;
int n,k;
vector<int> vec;
vector<int> v;
   
bool cmp(int a, int b) {
	return a > b;
}   

void input() {
	cin >> n;
	cin >> k;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);		
	}
	
	sort(vec.begin(),vec.end());
	
	vector<int> minus_rem;
	
	for(int i=0; i<vec.size()-1; i++) {
		minus_rem.push_back(vec[i+1]-vec[i]);
	}
	
	sort(minus_rem.begin(),minus_rem.end(),cmp);
	
	if(minus_rem.size() >= k) {
		for(int i=0; i<k-1; i++) {
			ma[minus_rem[i]] += 1;
		}
	}
	else {
		for(int i=0; i<minus_rem.size(); i++) {
			ma[minus_rem[i]] += 1;
		}
	}
}


// 1 3 6 6 7 9

void solve() {
	int answer = 0;
	if(n == 1) {
		cout << "0";
		return;
	}
	int first = vec[0];
	
	for(int i=1; i<vec.size(); i++) {
		if(ma[vec[i] - vec[i-1]] >= 1) {
			ma[vec[i] - vec[i-1]] -= 1;
			answer = answer + vec[i-1] - first;
			first = vec[i];
			continue;
		}
		if(i == vec.size() - 1) {
			answer = answer + vec[i] - first;
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}