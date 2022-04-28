#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int rain[100][100];
vector<int> v;
bool c[100][100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int repo[100][100];

void dfs(int x,int y,int z)
{
	c[x][y] = true;
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx<0 || nx>=n || ny<0 || ny>=n)	continue;
		if(!c[nx][ny] && rain[nx][ny] > z) {
			dfs(nx,ny,z);
		}
	}
}

bool compare(int a,int b) {
	return a > b;	
}

int main(void)
{
	cin >> n;
	int maxrain = 0;
	int minrain = 0;
	int cnt;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int a;
			cin >> a;
			rain[i][j] = a;
			maxrain = max(maxrain,a);
			minrain = min(minrain,a);
		}
	}
	
	for(int k=minrain; k<=maxrain; k++) {
		cnt = 0;
		memset(c,false,sizeof(c));
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(rain[i][j] > k && !c[i][j]) {
					cnt++;
					dfs(i,j,k);
				}
			}
		}
		v.push_back(cnt);
		
	}
	
	sort(v.begin(),v.end(),compare);
	
	cout << v.front();
	
	return 0;
}
