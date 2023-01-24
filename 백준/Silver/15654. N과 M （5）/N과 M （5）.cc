#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> vec;
vector<int> rem;
bool check[10001] = {false,};

void dfs(int cnt) {
	if(cnt == m) {
		for(int i=0; i<m; i++) {
			cout << rem[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=0; i<vec.size(); i++) {
		if(check[vec[i]]) continue;
		check[vec[i]] = true;
		rem.push_back(vec[i]);
		dfs(cnt+1);
		check[vec[i]] = false;
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