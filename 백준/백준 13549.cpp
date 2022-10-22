#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
bool check[100001];

int bfs()
{
	int result;
	queue<pair<int,int> > q;	//first 위치 second 시간 
	q.push({n,0});
	
	while(!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
		
		
		if(x == k) {
			result = time;
			break;
		}
		
		if(x*2 >= 0 && x*2 <= 100000 && check[x*2] == false) {
			check[x * 2] = true;
			q.push({x*2,time});
		}
		if(x-1 >= 0 && check[x-1] == false) {
			check[x-1] = true;
			q.push({x-1,time+1});
		}
		if(x+1 <=100000 && check[x+1] == false) {
			check[x+1] = true;
			q.push({x+1,time+1});
		}
		
		
		
	}
	
	return result;
}

int main(void)
{
	cin >> n >> k;
	
	int result = bfs();
	cout << result;
	
	
	return 0;
}
