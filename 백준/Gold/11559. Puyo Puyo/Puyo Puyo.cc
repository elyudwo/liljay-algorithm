#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string str[12];
bool puyocheck[12][6];
int cnt_tmp = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<pair<int,int> > dist;

int answer = 0;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

void input() {
	for(int i=0; i<12; i++) { cin >> str[i]; }
}

void dfs(int x, int y, char c) {
	puyocheck[x][y] = true;
	
	cnt_tmp += 1;
	dist.push_back({x,y});
	//cout << x << " " << y << endl;
	
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) { continue; }
		if(!puyocheck[nx][ny] && str[nx][ny] == c) {
			dfs(nx, ny, c);
		}
	}
}

bool puyo() {
	bool result = true;
	
	for(int i=11; i>=0; i--) {
		for(int j=0; j<6; j++) {
			if(str[i][j] != '.' && !puyocheck[i][j]) {
				dfs(i, j,str[i][j]); 
				if(cnt_tmp >= 4) {
					result = false;
				}
				else {
					for(int i=0; i<cnt_tmp; i++) {
					    if(dist.size() == 0) {
					        break;
					    }
					    dist.pop_back();
					}
				}
				cnt_tmp = 0;
			}
		}
	}
	
	
	return result;
}

void puyoCheckInit() {
	for(int i=0; i<12; i++) {
		for(int j=0; j<6; j++) {
			puyocheck[i][j] = false;
		}
	}
}

void solve() {
	/*
	1. 뒤에서부터 오면서 뿌요뿌요 생각
	2. 뿌요뿌요 지워주고 맨 아래부터 없으면 내려줌 
	3. 만약 뿌요뿌요 그다음 없으면 연쇄 멈춤 
	*/
	while(1) {
		bool check = puyo();
		
		if(check) { cout << answer; break; }
		else {
			// 뿌요 체크 된 나머지들 다 내려 
			sort(dist.begin(), dist.end(), cmp);
			for(pair<int,int> p : dist) {
				for(int i=p.first; i>0; i--) {
					str[i][p.second] = str[i-1][p.second];
					str[i-1][p.second] = '.';
				}
			}
			
			puyoCheckInit();
		}
		/*
		cout << endl << endl;
		for(int i=0; i<12; i++) {
		    cout << str[i] << endl;
		}
		*/
		answer += 1;
		dist.clear();
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}