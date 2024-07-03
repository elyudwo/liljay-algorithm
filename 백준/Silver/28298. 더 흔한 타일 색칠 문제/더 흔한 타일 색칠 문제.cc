#include <iostream>

using namespace std;

char arr[502][502];

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
	
	int answer = 0; 
	
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=k; j++) {
			int alp[26] = {0,};
			
			for(int q=i; q<=n; q = q + k) {
				for(int w=j; w<=m; w = w + k) {
					alp[arr[q][w] - 'A']++;
				}
			}
			
			// 가장 많이 있는 알파벳 
			int idx = -1;
			int max_value = -1;
			for(int q=0; q<26; q++) {
				if(alp[q] > max_value) {
					idx = q;
					max_value = alp[q];
				}
			}
			
			// 가장 많이 있는 알파벳으로 복사 
			int cnt = 0;
			char tmp = 'A' + idx;
			for(int q=i; q<=n; q = q + k) {
				for(int w=j; w<=m; w = w + k) {
					if(arr[q][w] != tmp) {
						arr[q][w] = tmp;
						cnt++;
					}
				}
			}
			
			answer += cnt;
		}
	}
	
	cout << answer << '\n';
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}