#include <iostream>
#include <vector>

using namespace std;

int c[101];
vector<int> v[101];
int count = 0;

void dfs(int x)
{
	c[x] = true;
	for(int i=0; i<v[x].size();i++)
	{
		int y = v[x][i];
		if(!c[y])
		{
			dfs(y);
			count ++;
		}
	}
}

int main(void)
{	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<M; i++)
	{
		int n,m;
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}
	
	dfs(1);
	cout << count;
	return 0;
}
