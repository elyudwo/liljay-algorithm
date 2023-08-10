#include <iostream>
#include <vector>

using namespace std;

int n,k;
int cnt = 0;
vector<int> vec;

void dfs(int sum) {
	if(sum > n) { return; }
	if(sum == n) {
		cnt += 1;
		if(cnt == k) {
			for(int i=0; i<vec.size()-1; i++) {
				cout << vec[i] << "+";
			}
			cout << vec[vec.size()-1];
		}
		return;
	}
	
	for(int i=1; i<=3; i++) {
		vec.push_back(i);
		dfs(sum + i);
		vec.pop_back();
	}
	
}

int main() {
	
	cin >> n >> k;
	dfs(0);
	
	if(cnt < k) {
		cout << "-1";
	} 
}