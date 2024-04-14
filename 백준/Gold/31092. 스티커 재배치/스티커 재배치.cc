#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

/*
1. 붙이는건 같은 알파벳 중 가장 싼놈으로 붙이면 됨 

가지고 있는 알파벳을 떼서 붙이는거 vs 사는 것 
*/

int n, m, k;
char sticker_str[502];
int detach_cost[502];
int price[26];
int have_alp[26];
string find_str;

struct sticker {
	char alp;
	int detach;
};

vector<sticker> vec;

void input() {
	cin >> n >> m >> k;
	vec.push_back({'0', 0});
	
	for(int i=0; i<26; i++) {
		price[i] = INF;
		have_alp[i] = 0;
	}
	
	for(int i=0; i<m; i++) {
		char c;
		int d, a;
		cin >> c >> d >> a;
		vec.push_back({c, d});
		
		int idx = c - 'a'; 
		price[idx] = min(price[idx], a);
		have_alp[idx]++;
	}
	
	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;
		sticker_str[i] = vec[a].alp;
		detach_cost[i] = vec[a].detach;
	}
	
	cin >> find_str;
}

int changeStr(int idx) {
	int result = 0;
	bool check[502];
	
	// 공짜로 넣을 수 있는 것 
	int storage[26];
	
	for(int i=0; i<26; i++) { storage[i] = 0; }
	for(int i=0; i<=n; i++) { check[i] = false; }
	
	
	for(int i=idx; i<idx + k; i++) {
		char now_ch = sticker_str[i];
		char find_ch = find_str[i - idx];
		int now_idx = sticker_str[i] - 'a';
		int find_idx = find_ch - 'a';
		
		// 일단 다른거면 싹다 빼봐 
		if(now_ch != find_ch) {
			storage[now_idx]++;
			result += detach_cost[i]; 
			continue;
		}
	}
	
	for(int i=idx; i<idx + k; i++) {
		char now_ch = sticker_str[i];
		char find_ch = find_str[i - idx];
		int now_idx = now_ch - 'a';
		int find_idx = find_ch - 'a';
		
		if(now_ch == find_ch) continue;
		if(storage[find_idx]) {
			storage[find_idx]--;
			continue;
		}
		
		int min_value = INF;
		int min_idx = -1;
		
		for(int j=0; j<idx; j++) {
			if(sticker_str[j] == find_ch && min_value > detach_cost[j] && !check[j]) {
				min_value = detach_cost[j];
				min_idx = j;
			}
		}
		
		for(int j=idx + k; j<=n; j++) {
			if(sticker_str[j] == find_ch && min_value > detach_cost[j] && !check[j]) {
				min_value = detach_cost[j];
				min_idx = j;
			}
		}
		
		if(min_value == INF && price[find_idx] == INF) {
			return INF;
		}
		
		if(min_value < price[find_idx]) {
			result += min_value;
			check[min_idx] = true; 
		}
		else {
			result += price[find_idx];
		}
	}
	
	return result;
}

void solve() {
	int answer = INF;
	
	for(int i=1; i<=n - k + 1; i++) {
		answer = min(answer, changeStr(i));
	}
	
	if(answer == INF) {
		cout << "-1";
		return;
	}
	cout << answer;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	
}