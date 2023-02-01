#include <iostream>
#include <map>
using namespace std;

map<long long,int> ma;
long long answer = -1;
long long max_tmp = -1;

void input() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		long long tmp;
		cin >> tmp;
		ma[tmp] = ma[tmp] + 1;
	}
}

void solve() {
	for(pair<long long,int> iter : ma) {
		if(ma[iter.first] > max_tmp) {
			answer = iter.first;
			max_tmp = ma[iter.first];
		}
		else if(ma[iter.first] == max_tmp && iter.first < answer) {
			answer = iter.first;
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
}