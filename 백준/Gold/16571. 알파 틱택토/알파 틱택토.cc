#include <iostream>

using namespace std;

int arr[5][5];
int stone_cnt = 0;
int now;

void input() {
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			cin >> arr[i][j];
			if(arr[i][j] != 0) {
				stone_cnt++;
			}
		}
	}
}

bool isFinished(int n) {
	// 가로, 세로 직선 
	for(int i=1; i<=3; i++) {
		if(arr[i][1] == n && arr[i][2] == n && arr[i][3] == n) {
			return true;
		}
		if(arr[1][i] == n && arr[2][i] == n && arr[3][i] == n) {
			return true;
		}
	}
	
	// 대각선
	if(arr[1][1] == n && arr[2][2] == n && arr[3][3] == n) {
		return true;
	}
	if(arr[1][3] == n && arr[2][2] == n && arr[3][1] == n) {
		return true;
	}
	return false;
}

int dfs(int turn) {
	int answer = 2;
	
	if(isFinished(3 - turn)) { return -1; }
	
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			if(arr[i][j] == 0) {
				arr[i][j] = turn;
				answer = min(answer, dfs(3 - turn));
				arr[i][j] = 0;
			}
		}
	}
	
	if(answer == 2 || answer == 0) {
		return 0;
	}
	
	return -answer;
}

void solve() {
	int result;
	
	result = dfs(stone_cnt % 2 + 1);
	if(result == 1) {
		cout << "W";
		return;
	}
	if(result == 0) {
		cout << "D";
		return;
	}
	cout << "L";
}

int main() {
	input();
	solve();
	
} 