#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool check[1001] = {false,};

vector<pair<int,int> > vec[1001];
int dis[] = {0,};

int bfs(int s,int e) {
	queue<pair<int,int> > q;
	q.push({s,0});
	
	while(!q.empty()) {
		int x = q.front().first;
		int result = q.front().second;
		if(x == e) return result;
		q.pop();
		
		for(int i=0; i<vec[x].size(); i++) {
			result += vec[x][i].second;
			q.push({vec[x][i].first,result});
		}
	}	
}


int main() 
{
	int n,m,x;
	
	cin >> n >> m >> x;
	int maxTime = -1;
	
	for(int i=0; i<m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});
	}
	
	for(int i=1; i<=n; i++) {
		if(i == x)	continue;
		cout << bfs(i,x) << endl;
	}
	
	for(int i=1; i<=n; i++) {
		if(i == x)	continue;
		dis[i] = bfs(x,i);
		cout << i << " " << dis[i] << endl;
	}
	
	/*
	for(int i=1; i<=n; i++) {
		maxTime = max(bfs(i,x) + dis[i],maxTime);
	}
	
	cout << maxTime;
	*/
}
