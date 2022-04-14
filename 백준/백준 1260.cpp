#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c1[1000];
int c2[1000];
vector<int> v[1001];
vector<int> a[1001];

void bfs(int a)
{
	queue<int> q;
	q.push(a);
	c2[a] = true;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for(int i=0; i<a[x].size(); i++)
		{
			int y = a[x][i];
			if(!c2[y])
			{
				q.push(y);
				c2[y] = true;
			}	
		}
	}
}


void dfs(int a)
{
	if(c1[a])	return;
	c1[a] = true;
	cout << a << ' ';
	for(int i=0; i<v[a].size(); i++)
	{
		int y = v[a][i];
		dfs(y);
	}
}

int main(void)
{
	int N,M,V;
	cin >> N >> M >> V;	
	
	for(int i=0; i<M; i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		a[a].push_back(b);
		a[b].push_back(a);
	}
	
	dfs(V);
	cout << endl;
	bfs(V);
	
	return 0;
}
