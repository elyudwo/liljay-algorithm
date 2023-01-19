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
		
		if(d[now]<dist) // �̹� �ִܰ�θ� üũ�� ����� ��� �н�
            continue;
        
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = dist+graph[now][i].second; // ���ļ� ���� ����� ����� ���
                                                  // ��������� ��� + ���� ��� ���
            if(cost<d[graph[now][i].first]) // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
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
