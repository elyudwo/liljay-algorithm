#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n,h,t;
	cin >> n >> h >> t;
	priority_queue<int> pq;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	
	int cnt = 0;
	while(1) {
		if(pq.top() >= h) {
			if(cnt == t) {
				cout << "NO" << endl << pq.top();
				return 0;
			}
			if(pq.top() == 1) {
				cnt++;
			}
			else {
				int tmp = pq.top()/2;
				pq.pop();
				pq.push(tmp);
				cnt++;
			}
		}
		else {
			cout << "YES" << endl << cnt;
			return 0;
		}
	}
	
	
	return 0;
}
