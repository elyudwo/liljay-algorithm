#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,k;

struct emp {
	int num,d,h,l;
};

struct cmp {
    bool operator()(emp a, emp b) {
    	if(a.d == b.d) {
    		if(a.h == b.h) {
    			return a.l > b.l;
    		}
    		return a.h < b.h;
    	}
    	return a.d < b.d;
    }
};

queue<emp> arr[100001];
priority_queue<emp, vector<emp>, cmp> pq;

void input() {
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		
		arr[i%m].push({i,a,b,i%m});
	}
}

void solve() {
	for(int i=0; i<m; i++) {
		pq.push(arr[i].front());
		arr[i].pop();
	}
	
	int cnt = 0;
	
	while(1) {
		int l = pq.top().l;
		int num = pq.top().num;
		
		if(num == k) { break; }
		
		pq.pop();
		if(!arr[l].empty()) {
			pq.push({arr[l].front()});
			arr[l].pop();
		}
		
		
		cnt += 1;
	}
	
	cout << cnt;
}

int main() {
	input();
	solve();
	
}