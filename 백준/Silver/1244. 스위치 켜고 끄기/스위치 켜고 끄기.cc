#include <iostream>
#include <vector>

using namespace std;

int n;
bool check[101];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		int tmp;
		cin >> tmp;
		if(tmp == 1) {
			check[i] = true;
		}
	}
}

void solve() {
	int t;
	cin >> t;
	while(t--) {
		int gender,num;
		cin >> gender >> num;
		
		// 남자일 경우 
		if(gender == 1) {
			int tmp = num;
			while(tmp <= n) {
				check[tmp] = !check[tmp];
				tmp = tmp + num;
			}
		}
		
		// 여자일 경우 
		else {
			int left = num - 1;
			int right = num + 1;
			int cnt = 0;
			check[num] = !check[num];
			
			while(1) {
				if(left < 1 || right > n || check[left] != check[right]) { break; }
				else {
					check[left] = !check[left];
					check[right] = !check[right];
					left--;
					right++;
				}
			}
		}
	}
	int cnt = 0;
	
	for(int i=1; i<=n; i++) {
		if(check[i]) {
			cout << "1" << " ";
		}
		else {
			cout << "0" << " ";
		}
		cnt++;
		if(cnt == 20) {
			cout << '\n';
			cnt = 0;
		}
	}
	
}

int main() {
	input();
	solve();
	
	
}