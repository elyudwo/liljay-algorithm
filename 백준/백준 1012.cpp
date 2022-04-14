#include <iostream>
#include <vector>

using namespace std;

int veg[50][50];
int cnt = 0;
int T,M,N,K;
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

void dfs(int i, int j)
{
	veg[i][j] = 0;
	for(int i=0; i<4; i++)
	{
		int nx = j + dx[i];
		int ny = i + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        
        if(veg[ny][nx] == 1)
        	dfs(ny,nx);
	}			
}

int main(void)
{
	cin >> T;
	
	for(int i=0; i<T; i++)
	{	
		cnt = 0;
		cin >> M >> N >> K;

		for(int j=0; j<K; j++)
		{
			int a,b;
			cin >> a >> b;
			veg[a][b] = 1;
		}
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(veg[i][j] == 1)
				{
					cnt++;
					dfs(i,j);
				}
			}
		}
	} 
	
	cout << cnt;
	
	return 0;
}
