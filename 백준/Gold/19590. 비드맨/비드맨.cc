#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

vector<long long> vec;
int n;

bool cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(), vec.end(), cmp);
}

void solve() {
	long long bob = 0;
	
	for(int i=1; i<n; i++) {
		bob += vec[i];
	}
	
	if(bob > vec[0]) {
		if((bob + vec[0]) % 2 == 0) {
			cout << "0";
			return;
		}
		cout << "1";
		return;
	}
	
	cout << vec[0] - bob;

}

int main() {
	input();
	solve();
}