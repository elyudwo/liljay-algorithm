#include <iostream>
#include <queue>

using namespace std;
int n,k;
bool check[100001];
int dx[] = {2,1,-1};

void bfs(int x,int cnt)
{
	queue <pair <int,int> > q;
	q.push({x,cnt});
	check[x] = true;
	
	while(!q.empty()) {
		int nx_t = q.front().first;
		int cnt_t = q.front().second;
		q.pop();
		if(nx_t == k) {
			cout << cnt_t;
			break;
		} 
		
		for(int i=0; i<3; i++) {
			int nx;
			if(i == 0) {
				nx = nx_t * dx[i];
			}
			else {
				nx = nx_t + dx[i];
			}
			if(nx < 0 || nx > 100000)	continue;
			
			if(!check[nx]) {
				check[nx] = true;
				q.push({nx,cnt_t+1});
			}
		}
	}
 	
	
}


int main(void) 
{
	cin >> n >> k;
	check[n] = true;
	bfs(n,0);
	
	return 0;
}
