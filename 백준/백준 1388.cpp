#include <iostream>
#include <string> 
using namespace std;

int n,m;

string v[51];
bool check[51][51];

void dfs(int x,int y,char c) 
{
	check[x][y] = true;
	if(c == '-') {
		if(v[x][y+1] == '-' && !check[x][y+1]) {
			dfs(x,y+1,c);
		}
	}
	else if(c == '|') {
		if(v[x+1][y] == '|' && !check[x+1][y]) {
			dfs(x+1,y,c);
		}
	}
} 

int main(void)
{
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	int cnt = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!check[i][j]) {
				dfs(i,j,v[i][j]);
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
