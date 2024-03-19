#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
1. 가장 큰 기둥 찾기
2. 가장 큰 기둥 만나기 전까지는 올라가야함
3. 가장 큰 기둥 이후로는 내려가야함 

[반례] 
4. 가장 큰 기둥이 여러개일 경우?? 
*/

int n;
int tower[1001];
int max_tower = 0;
int max_cnt = 0;
int start = 1001;
int en = 0;
int left_tower = 1001;
int right_tower = 0;

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		tower[a] = b;
		max_tower = max(max_tower, b);	
		start = min(start, a);
		en = max(en, a);	
	}

	for(int i=0; i<n; i++) {
		if(tower[i] == max_tower) {
			max_cnt++;
			left_tower = min(left_tower, i);
			right_tower = max(right_tower, i);
		}
	}
}

void solve() {
	int now = tower[start], answer = 0;
	for(int i=start; i<left_tower; i++) {
		if(tower[i] > now) {
			now = tower[i];
		}
		
		answer += now;
	}
	
	now = tower[en];
	for(int i=en; i>right_tower; i--) {
		if(tower[i] > now) {
			now = tower[i];
		}
		answer += now;
	}
	
	answer += (right_tower - left_tower + 1) * max_tower;
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}