#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k;
int result = 0;
int d[11];
bool check[11];
vector<pair<int,int> > graph[11];

void dijkstrea(int start) {
	priority_queue<pair<int,int> > pq;
	
	pq.push({0,start});
	d[start] = 0;
	
	while(!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(d[now]<dist) // 이미 최단경로를 체크한 노드인 경우 패스
            continue;
        
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = dist+graph[now][i].second; // 거쳐서 가는 노드의 비용을 계산
                                                  // 현재노드까지 비용 + 다음 노드 비용
            if(cost<d[graph[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[graph[now][i].first]=cost;
                pq.push(make_pair(-cost,graph[now][i].first));
            }
        }
	}
}

void input() {
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int tmp;
			cin >> tmp;
			graph[i].push_back({j,tmp});
		}
	}
	
	fill_n(d,11,10000000);
}

void solve() {
	int tmp = n;
	int dis = k;
	
	while(tmp--) {
		dijkstrea(dis);
		int min_tmp = 10000000;
		int a;
		for(int i=0; i<n; i++) {
			if(min_tmp > d[i] && !check[i]) {
				min_tmp = d[i];
				a = i;
			}
		}
		
		check[a] = true;
		result = result + min_tmp;
		dis = a;
		
		fill_n(d,11,10000000);
	}
}

int main() {
	input();
	solve();
	
	cout << result;
}
