#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int n,s;
vector<int> vec;
map<int,int> ma;

int gcd(int a, int b) {
	int mod = a % b;
	
	while(mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}
	
	return b;
}

void input() {
	cin >> n >> s;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
}

void solve() {
	int answer;
	if(n == 1) {
		answer = fabs(vec[0] - s);
		cout << answer;
		return;
	}
	
	answer = gcd(fabs(s-vec[0]),fabs(s-vec[1]));
	
	for(int i=2; i<n; i++) {
		answer = gcd(answer,fabs(s-vec[i]));
	}
	
	cout << answer;
}

int main() {
	input();
	solve();

}