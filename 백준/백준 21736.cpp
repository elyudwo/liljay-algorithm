#include <iostream>
#include <string>

using namespace std;

string str[601];
bool check[601][601];
int n,m;
int cnt = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dfs(int x,int y) 
{
	if(check[x][y])	return;
	check[x][y] = true;
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(str[nx][ny] == 'X')	continue;
		if(!check[nx][ny] && (str[nx][ny] =='O' || str[nx][ny] == 'P')) {
			if(str[nx][ny] == 'P') {
				cnt++;
				dfs(nx,ny);
			}
			else if (str[nx][ny] == 'O'){
				dfs(nx,ny);
			}
		}
		
 	}
	
}


int main(void)
{
	cin >> n >> m;
	int a,b;
	
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
	
	bool lee = false;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(str[i][j] == 'I') {
				dfs(i,j);
			}
		}
	}

	if(cnt == 0) {
		cout << "TT";
		lee = true;
	} 
	if(!lee) {
		cout << cnt;
	}
	
	
	
	return 0;
}
