#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<pair<int,int> > v;
int n, k;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return (10000 - a.first) * (10000 - a.first) + (10000 - a.second) * (10000 - a.second)
			> (10000 - b.first) * (10000 - b.first) + (10000 - b.second) * (10000 - b.second);
}

struct st {
	int x;
	int y;
	int cnt;
};

bool bfs(double energy) {
	queue<st> q;
	bool visit[1001] = {false, };
	q.push({0,0,0});
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		
		q.pop();
		
		if(cnt > k + 1) { continue; }
		
		if(x == 10000 && y == 10000) {
			return true;
		}
		
		for(int i=0; i<v.size(); i++) {
			int nx = v[i].first;
			int ny = v[i].second;
			if(visit[i]) { continue; }
			
			double sum = double(sqrt((nx - x) * (nx - x) + ((ny - y) * (ny - y))));
			if(sum > energy * 10) {
				continue;
			}
			visit[i] = true;
			q.push({nx, ny, cnt + 1});
		}
	}
	
	return false;
}

int main() {
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	v.push_back({10000, 10000});
	sort(v.begin(), v.end());
	
	int left = 0;
	int right = 2000;
	int answer = 1e9;
	
	while(left <= right) {
		int mid = (left + right) / 2;
//		cout << mid << endl;
		if(bfs(mid)) {
			right = mid - 1;
			answer = min(answer, mid);
			continue;
		}
		left = mid + 1;
	} 
	
	cout << answer; 
}