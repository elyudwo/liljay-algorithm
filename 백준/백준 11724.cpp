#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[1001];
int c[1001];
int cnt[1001];
int j = 0;

void dfs(int n) 
{
	if(c[n])	return ;
	c[n] = true;
	for(int i=0; i<v[n].size(); i++) {
		int y = v[n][i];
		dfs(y);
	}
	
}

int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int count = 0;
	
	for(int i=1; i<=n; i++) {
		if(!c[i])
		{
			count++;
			dfs(i);
		}
	}
	
	cout << count;
	
	return 0;
}
