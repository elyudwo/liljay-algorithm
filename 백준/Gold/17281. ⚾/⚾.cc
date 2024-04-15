#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer = 0;
int inning[51][10];
vector<int> hitter;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=9; j++) {
			cin >> inning[i][j]; 
		}
	}
}

int calScore(vector<int> hitter_tmp) {
	int result = 0;
	int idx = 0;
	int now_hitter = hitter_tmp[idx++];
	
	for(int i=1; i<=n; i++) {
		int o_count = 0;
		bool check[4] = {false,};
		
		while(o_count != 3) {
			// 아웃인 경우 
			if(!inning[i][now_hitter]) {
				o_count++;
				now_hitter = hitter_tmp[(idx++) % 9];
				continue;
			}
			
			if(inning[i][now_hitter] == 1) {
				if(check[3]) {
					result++;
					check[3] = false;
				}
				
				if(check[2]) {
					check[2] = false;
					check[3] = true;
				}
				
				if(check[1]) {
					check[1] = false;
					check[2] = true;
				}
				check[1] = true;
			}
			if(inning[i][now_hitter] == 2) {
				if(check[3]) {
					result++;
					check[3] = false;
				}
				
				if(check[2]) {
					result++;
					check[2] = false;
				}
				
				if(check[1]) {
					check[1] = false;
					check[3] = true;
				}
				check[2] = true;
			}
			if(inning[i][now_hitter] == 3) {
				if(check[3]) {
					result++;
					check[3] = false;
				}
				
				if(check[2]) {
					result++;
					check[2] = false;
				}
				
				if(check[1]) {
					result++;
					check[1] = false;
				}
				check[3] = true;
			}
			if(inning[i][now_hitter] == 4) {
				if(check[3]) {
					result++;
					check[3] = false;
				}
				
				if(check[2]) {
					result++;
					check[2] = false;
				}
				
				if(check[1]) {
					result++;
					check[1] = false;
				}
				result++;
			}
			now_hitter = hitter_tmp[(idx++) % 9];
		}
	}
	
	return result;
}

void solve() {
	for(int i=2; i<=9; i++) { hitter.push_back(i); }
	
	do {
		vector<int> hitter_tmp;
		for(auto it = hitter.begin(); it != hitter.end(); it++) {
			hitter_tmp.push_back(*it);
		}
		hitter_tmp.insert(hitter_tmp.begin() + 3, 1);
		
// 		for(int i=0; i<9; i++) {
// 		    cout << hitter_tmp[i] << " ";
// 		}
// 		cout << "\n";
		
		answer = max(answer, calScore(hitter_tmp));
	} while (next_permutation(hitter.begin(), hitter.end()));
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}