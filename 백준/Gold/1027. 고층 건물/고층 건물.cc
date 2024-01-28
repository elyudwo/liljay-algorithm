#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

int building[52];
int cnt[52] = {0,};
int answer = 0;
int n;

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) { cin >> building[i]; }
}

void solve() {
	for(int i=1; i<=n; i++) {
		double max_value = -1000000000;
		
		for(int j=i+1; j<=n; j++) {
			double tmp = double(building[j] - building[i]) / double(j-i);
			
			if(tmp > max_value) {
				max_value = tmp;
				cnt[i]++;
				cnt[j]++;
			}
		}
		
		answer = max(answer, cnt[i]);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}