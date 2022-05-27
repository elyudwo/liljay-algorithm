#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v[100];
bool check[100];
int cnt[100]={0,};
int lee=1;

void dfs(int x,int y,int count) 
{
	if(check[x])	return;
	if(x == y)	{
		cnt[lee] = cnt[lee] + count;
		return;
	}

	check[x] = true;
	
	for(int i=0; i<v[x].size(); i++) {
		if(!check[v[x][i]]) {
			dfs(v[x][i],y,count + 1);
		}
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
	
	for(; lee<=n; lee++) {
		for(int k=1;k<=n; k++) {
			for(int j=0; j<=n; j++) {
				check[j] = false;
			}
			if(lee==k) continue;
			else {
				dfs(lee,k,0);
			}
		
		}
	}
	
	int min_cnt = 9999;
	for(int i=1; i<=n; i++) {
		min_cnt = min(min_cnt,cnt[i]);
	}
	
	
	for(int i=1; i<=n; i++) {
		if(min_cnt == cnt[i]) {
			cout << i;
			break;
		}
	}
	
	
	
	return 0;
}
