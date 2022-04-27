#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
int home[25][25];
bool c[25][25];
int danji = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<int> v;

int cnt[25];
int k = 0;

void dfs(int x,int y) 
{
	danji++;
	
	c[x][y] = true;
	
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!c[nx][ny] && home[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}

int main(void) 
{
	cin >> n;
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		for(int j=0; j<n; j++) {
			home[i][j] = str[j] - '0';
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!c[i][j] && home[i][j] == 1) {
				danji = 0;
				dfs(i,j);
				v.push_back(danji);
			}
		}
	}
	
	sort(v.begin(),v.end());
	
	cout << v.size() << endl;
	
	for(int i=0; i<v.size(); i++) 
		cout << v[i] << endl;
	
	return 0;
}
