#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v[1001];

int main(void)
{
	int n,w,l;
	cin >> n >> w >> l;
	queue<int> q_start;
	deque < pair<int,int> > q;
	for(int i=0; i<n; i++) {
		cin >> v[i];
		q_start.push(v[i]);
	}
	int time = 0;
	while(!q.empty() || !q_start.empty()) {
		for(int i=0; i<q.size(); i++) {
			q[i].second = q[i].second - 1;
		}
		if(q.front().second == 0 && !q.empty()) {
			q.pop_front();
		}
		
		int sum = 0;
		for(int i=0; i<q.size(); i++) {
			sum = sum + q[i].first;
		}
		
		if(!q_start.empty() && sum + q_start.front() <= l && q.size() < w) {
			q.push_back({q_start.front(),w});
			q_start.pop();
		}
		
		time++;
	}

	
	cout << time;
	return 0;
}
