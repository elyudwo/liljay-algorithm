#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> vec[6];
bool check[400][400];
/*
1,1 -> 1, 2
-1,1 -> 0, 5
1,0 -> 0, 4
-1,-1 -> 4, 5
1,-1 -> 2, 3
-1,0 -> 1, 3
*/

int dx[] = {1, -1, 1, -1, 1, -1};
int dy[] = {1, 1, 0, -1, -1, 0};
int arr[23];

void dfs(int d, int x, int y, int cnt) {
//	cout << x << " " << y << endl;
	if(cnt > 22) return;
	
	
	for(int i=0; i<2; i++) {
		int idx = vec[d][i];
		int nx = x + dx[idx];
		int ny = y + dy[idx];
		
		if(check[nx][ny]) {
			arr[cnt + 1]++;
			continue;
		}
		check[nx][ny] = true;
		dfs(idx, nx, ny, cnt + 1);
		check[nx][ny] = false;
	}
	
}

int main() {
	vec[0].push_back(1); vec[0].push_back(2);
	vec[1].push_back(0); vec[1].push_back(5);
	vec[2].push_back(0); vec[2].push_back(4);
	vec[3].push_back(4); vec[3].push_back(5);
	vec[4].push_back(2); vec[4].push_back(3);
	vec[5].push_back(1); vec[5].push_back(3);
	int n;
	cin >> n;
	
	check[200][200] = true;
	check[199][200] = true;
	dfs(5, 199, 200, 0);
	
	cout << arr[n];
}