#include <iostream>
#include <vector>
using namespace std;

int n,a,b;
vector<int> v[500001];
bool c[500001];
int cnt = 0;

int sum = 0;

int dfs(int x,int cnt)
{
	if(v[x].size() == 1 && x != 1) {
		return sum = sum + cnt;
	}
	for(int i=0; i<v[x].size(); i++) {
		if(!c[v[x][i]]) {
			c[v[x][i]] = true;
			dfs(v[x][i], cnt + 1);
			c[v[x][i]] = false;
		}
	}
	return 0;
}

int main(void)
{
	cin >> n;
	
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	c[1] = true;
	dfs(1,0);
	
	if(sum % 2 == 0)
		cout << "No";
	else
		cout << "Yes";
	
	return 0;
}
