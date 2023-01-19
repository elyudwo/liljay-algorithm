#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

vector<int> vec;
int n,m;
int result = 0;

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int tmp; cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
}

void solve() {
	int first = 0;
	int second = vec.size()-1;
	
	while(1) {
		if(first > second || first == second) {break;}
		
		int tmp = vec[first] + vec[second];
		if(tmp < m) { first++; }
		else {
			result++;
			first++;
			second--;
		}
	}
	
	cout << result;
}

int main() {
	input();
	solve();
	
}
