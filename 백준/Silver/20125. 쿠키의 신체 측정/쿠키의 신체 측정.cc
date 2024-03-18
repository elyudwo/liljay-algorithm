#include <iostream>

using namespace std;

int n;
char arr[1005][1005];
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
			
		for(int j=1; j<=n; j++) {
			arr[i][j] = str[j-1];
		}
	}
}

void findAnotherBody(int x, int y) {
	cout << x << " " << y << '\n';
	
	int a,b;
	
	for(int i=0; i<3; i++) {
		int cnt = 0;
		int x_tmp = x;
		int y_tmp = y;
		
		while(1) {
			x_tmp = x_tmp + dx[i];
			y_tmp = y_tmp + dy[i];
			if(arr[x_tmp][y_tmp] != '*') {
				break;
			}
			a = x_tmp;
			b = y_tmp;
			cnt++;
		}
		cout << cnt << " ";
	}
	
	int left_x = a + 1;
	int left_y = b - 1;
	int cnt = 0;
	
	for(int i=left_x; i<=n; i++) {
		if(arr[i][left_y] == '*') {
			cnt++;
			continue;
		}
		break;
	}
	cout << cnt << " ";
	cnt = 0;
	
	int right_y = b + 1;
	for(int i=left_x; i<=n; i++) {
		if(arr[i][right_y] == '*') {
			cnt++;
			continue;
		}
		break;
	}
	cout << cnt << " ";
}

void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			bool check = true;
			for(int k=0; k<4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				
				if(arr[x][y] != '*') {
					check = false;
					break;
				}
			}
			
			if(check) {
				findAnotherBody(i, j);
				return;
			}
		}
	}
}

int main() {
	input();
	solve();
	
}