#include <iostream>
#include <vector>

using namespace std;

int n,m;
int cnt = 0;
int ans = 0;
vector<int> v[100];
bool c[100];

void dfs(int a,int b,int num) 
{
	c[a] = true;
	if(a == b) {
		ans = num;
	}	
	for(int i=0; i<v[a].size(); i++) {
		if(!c[v[a][i]]) {
			cnt++;
			dfs(v[a][i],b,num+1);
		}
	}
}

int main(void) 
{
	int x,y;
	cin >> n >> x >> y >> m;
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(x,y,cnt);
	if(ans) {
		cout << ans;
	}
	else {
		cout << -1;
	}
	
	return 0;
}
