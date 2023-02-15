#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_result = -1;
vector<int> vec;
vector<int> rem;
bool check[11];
int n;

int calculate() {
	int result = 0;
	vector<int> v = vec;
	
	for(int i=0; i<n-2; i++) {
		result = result + v[rem[i] - 1] * v[rem[i] + 1];
		for(int j=i+1; j<n-2; j++) {
			if(rem[j] > rem[i]) { rem[j]--; }
		}
		v.erase(v.begin() + rem[i]);
	}
	return result;
}

void dfs() {
	if(rem.size() == n-2) {
		// rem 은 인덱스 저장 
		max_result = max(max_result, calculate());
		return;
	}
	
	for(int i=1; i<n-1; i++) {
		if(check[i]) { continue; }
		check[i] = true;
		rem.push_back(i);
		dfs();
		check[i] = false;
		rem.pop_back();
	}
}

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
}

void solve() {
	dfs();
	cout << max_result;
}

int main() {
	input();
	solve();
	
	
}