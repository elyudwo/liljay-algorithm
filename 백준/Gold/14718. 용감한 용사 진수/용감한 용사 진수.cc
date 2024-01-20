#include <iostream>
#define INF 1e9
using namespace std;

int n, man;
int arr[101][3];

void input() {
	cin >> n >> man;
	for(int i=1; i<=n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		
	}
}

void solve() {
	int answer = INF;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				int tmp[3] = {arr[i][0], arr[j][1], arr[k][2]};
				
				int cnt = 0;
				int win = 0;
				
				for(int q=1; q<=n; q++) {
					if(arr[q][0] <= tmp[0] && arr[q][1] <= tmp[1] && arr[q][2] <= tmp[2]) {
						win++;
					}
				}
				
				if(win >= man) {
					answer = min(answer, tmp[0] + tmp[1] + tmp[2]);
				}
			}
		}
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