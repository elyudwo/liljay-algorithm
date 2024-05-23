#include <iostream>

using namespace std;

int n, k;
int game_tb[10][10];
int answer = 0;
bool check[10] = {false,};
int now_hand[3][21];

void input() {
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> game_tb[i][j];
		}
	}
	
	
	for(int i=1; i<=2; i++) {
		for(int j=1; j<=20; j++) {
			cin >> now_hand[i][j];
		}
	}
}

int gh_mh_win[3] = {0,0,0};
int now_check[3] = {1,1,1};

int changeWho(int w) {
	if(w == 2) {
		return 1;
	}
	return 2;
}

// 지우 == 0, 경희 == 1, 민호 == 2 
void dfs(int turn, int who1, int who2) {
	if(answer) {
		return;
	}
	
//	cout << turn << " " << who1 << " " << who2 << " " << endl; 
//	cout << now_check[0] << " " << now_check[1] << " " << now_check[2] << endl;
	if(gh_mh_win[1] == k || gh_mh_win[2] == k) {
		return;
	}
	
	if(gh_mh_win[0] == k) {
		answer = 1;
		return;
	}
	if(turn > 20) { return; }
	
	if(who1 && who2) {
		int hand1 = now_hand[who1][now_check[who1]];
		int hand2 = now_hand[who2][now_check[who2]];
		now_check[who1]++;
		now_check[who2]++;
		
		if(game_tb[hand1][hand2] == 1) {
			gh_mh_win[max(who1, who2)]++;
			dfs(turn + 1, max(who1, who2), 0);
			gh_mh_win[max(who1, who2)]--;
		}
		else if(game_tb[hand1][hand2] == 0) {
			gh_mh_win[who2]++;
			dfs(turn + 1, who2, 0);
			gh_mh_win[who2]--;
		}
		else if(game_tb[hand1][hand2] == 2) {
			gh_mh_win[who1]++;
			dfs(turn + 1, who1, 0);
			gh_mh_win[who1]--;
		}
		
		now_check[who2]--;
		now_check[who1]--;
		return;
	}
	
	int who = max(who1, who2);
	int enemy_hand = now_hand[who][now_check[who]];
	 
	// 이기는 경우
	for(int i=1; i<=n; i++) {
		if(game_tb[i][enemy_hand] == 2 && !check[i]) {
			check[i] = true;
			now_check[who]++;
			gh_mh_win[0]++;
			dfs(turn + 1, 0, changeWho(who));
			check[i] = false;
			now_check[who]--;
			gh_mh_win[0]--;
		}
	}
	
	// 비기는 경우
	for(int i=1; i<=n; i++) {
		if(game_tb[i][enemy_hand] == 1 && !check[i]) {
			check[i] = true;
			gh_mh_win[who]++;
			now_check[who]++;
			dfs(turn + 1, who, changeWho(who));
			gh_mh_win[who]--;
			now_check[who]--;
			check[i] = false;
		}
	}
	
	
	// 지는 경우 
	for(int i=1; i<=n; i++) {
		if(game_tb[i][enemy_hand] == 0 && !check[i]) {
			check[i] = true;
			gh_mh_win[who]++;
			now_check[who]++;
			dfs(turn + 1, who, changeWho(who));
			gh_mh_win[who]--;
			now_check[who]--;
			check[i] = false;
		}
	}
}

void solve() {
	dfs(1, 0, 1);
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}