#include <iostream>
#include <set>
#include <queue>
#define INF 2e9

using namespace std;

set<string> se;
char board[4][4];
bool visit[4][4];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,-1,1,0,0};

int answer = INF; 
int tmp = 0;

string makeStr() {
	string str = "";
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			str += board[i][j];
		}
	}
	return str;
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
	se.clear();
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			board[i][j] = '.';
			visit[i][j] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		init();
		makeBoard();
		queue<pair<string, int> > q;
		string tmp = makeStr();
		
		q.push({tmp, 0});
		
		while(!q.empty()) {
			string str = q.front().first;
			int cnt = q.front().second;
			
			q.pop();
			
			if(str == ".........") {
				cout << cnt << '\n';
				break;
			}
			for(int i=0; i<9; i++) {
				int x = i / 3;
				int y = i % 3;
				string tmp = str;
				
				for(int j=0; j<5; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];
					
					if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
					int idx = nx * 3 + ny;
					
					if(tmp[idx] == '*') { tmp[idx] = '.'; }
					else { tmp[idx] = '*'; }
				}
				
				if(!se.count(tmp)) {
					se.insert(tmp);
					q.push({tmp, cnt + 1});
				}
			}
		}
		
	}
}