#include <iostream>
#include <set>
#include <queue>
#define INF 2e9

using namespace std;

char board[4][4];
bool check[(1 << 9)];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,-1,1,0,0};
int answer = INF; 
int tmp = 0;

int makeStrToInt() {
	int result = 0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(board[i+1][j+1] == '*') {
				result |= (1 << i * 3 + j);
			}
		}
	}
	return result;
}

void makeBoard() {
	for(int i=1; i<=3; i++) {
		string str;
		cin >> str;
		for(int j=1; j<=3; j++) {
			board[i][j] = str[j-1];
		}
	}
}

void init() {
	answer = INF;
	
	for(int i=0; i<(1 << 9); i++) {
		check[i] = false;
	}
	
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			board[i][j] = '.';
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		init();
		makeBoard();
		queue<pair<int, int> > q;
		int tmp = makeStrToInt();
		
		q.push({tmp, 0});
		check[tmp] = true;
		
		while(!q.empty()) {
			int num = q.front().first;
			int cnt = q.front().second;
			
			q.pop();
			
			if(num == 0) {
				cout << cnt << '\n';
				break;
			}
			for(int i=0; i<9; i++) {
				int tmp = num;
				
				for(int j=0; j<5; j++) {
					int nx = (i / 3) + dx[j];
					int ny = (i % 3) + dy[j];
					
					if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
					tmp ^= (1 << (nx * 3 + ny));
				}
				
				if(!check[tmp]) {
					check[tmp] = true;
					q.push({tmp, cnt + 1});
				}
			}
		}
		
	}
}