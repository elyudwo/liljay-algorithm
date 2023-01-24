#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> rem;
int n,m;

void dfs(int x) {
	if(rem.size() == m) {
		for(int i=0; i<m; i++) {
			cout << rem[i] << " ";
		}	
		cout << "\n";
		return;
	}	
	
	for(int i=x; i<vec.size(); i++) {
		rem.push_back(vec[i]);
		dfs(i);
		rem.pop_back();
	}
}

int main() {
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	
	dfs(0);
	
}