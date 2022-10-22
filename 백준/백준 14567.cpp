#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec[1001];
int result[1001];  
bool check[1001];

void dfs(int n,int cnt)
{
	result[n] = max(result[n],cnt);
	
	for(int i=0; i<vec[n].size(); i++) {
		check[vec[n][i]] = true;
		dfs(vec[n][i],cnt+1);
	}
}
	

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	
	for(int i=1; i<=n; i++) {
		if(!check[i]) {
			dfs(i,1);
		}
	}
	
	for(int i=1; i<=n; i++) {
		cout << result[i] << " ";
	}
	
	
	return 0;
}
