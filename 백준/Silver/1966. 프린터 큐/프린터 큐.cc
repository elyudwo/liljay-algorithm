#include <iostream>
#include <queue>

using namespace std;

int t;
int arr[10] = {0, };

bool checkFront(int idx) {
	for(int i=idx + 1; i<=9; i++) {
		if(arr[i]) {
			return false;
		}
	}
	
	return true;
}

void init() {
	for(int i=1; i<=9; i++) { arr[i] = 0; }
}

int main() {
	cin >> t;
	
	while(t--) {
		init();
		int n, m;
		queue<pair<int,int> > q;
		
		cin >> n >> m;
		
		// 입력 
		for(int i=0; i<n; i++) {
			int tmp;
			cin >> tmp;
			arr[tmp]++;
			q.push({tmp, i});
		}
		
		// 삭제
		int cnt = 1; 
		while(!q.empty()) {
			int x = q.front().first;
			int idx = q.front().second;
			
			if(idx == m && checkFront(x)) {
				break;
			}
			
			if(!checkFront(x)) {
				q.pop();
				q.push({x, idx});
			} 
			else {
				cnt++;
				q.pop();
				arr[x]--;
			}
		}
		cout << cnt << '\n';
	}
	
	
}