#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;

// 진실을 아는 사람 저장 
vector<int> true_person;

// false 일 경우 거짓말 가능 
bool check_party[51];

// 파티에 오는 사람 
vector<int> party[51];

// 이 사람이 가는 파티 저장 
vector<int> person[51];

/*
1. 진실을 아는 사람들 큐에 저장한다. 
2. bfs 돌면서 진실을 아는 사람들이 간 파티에 있는 사람들도 큐에 저장한다. 
3. 전체 순회 하면서 거짓말 칠 수 있는 파티 구한다. 

*/

void input() {
	cin >> n >> m;
	int tmp,a,b;
	cin >> tmp;
	
	for(int i=0; i<tmp; i++) {
		cin >> a;
		true_person.push_back(a);
	}
	
	for(int i=0; i<m; i++) {
		cin >> a;
		for(int j=0; j<a; j++) {
			cin >> b;
			party[i].push_back(b);
			person[b].push_back(i);
		}
	}
}

void bfs() {
	queue<int> q;
	for(int i=0; i<true_person.size(); i++) {
		for(int j=0; j<person[true_person[i]].size(); j++) {
			q.push(person[true_person[i]][j]);
		}
	}
	
	while(!q.empty()) {
		// 파티 검색 
		int x = q.front();
		check_party[x] = true;
		q.pop();
		
		for(int i=0; i<party[x].size(); i++) {
			int pp = party[x][i];
			for(int j=0; j<person[pp].size(); j++) {
				if(check_party[person[pp][j]]) continue;
				q.push(person[pp][j]);
			}
		}
	}
} 


int main() {
	input();
	bfs();
	int result = 0;
	for(int i=0; i<m; i++) {
		if(!check_party[i]) result++;
	}
	cout << result;
}
