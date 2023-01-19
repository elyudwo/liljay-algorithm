#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;

// ������ �ƴ� ��� ���� 
vector<int> true_person;

// false �� ��� ������ ���� 
bool check_party[51];

// ��Ƽ�� ���� ��� 
vector<int> party[51];

// �� ����� ���� ��Ƽ ���� 
vector<int> person[51];

/*
1. ������ �ƴ� ����� ť�� �����Ѵ�. 
2. bfs ���鼭 ������ �ƴ� ������� �� ��Ƽ�� �ִ� ����鵵 ť�� �����Ѵ�. 
3. ��ü ��ȸ �ϸ鼭 ������ ĥ �� �ִ� ��Ƽ ���Ѵ�. 

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
		// ��Ƽ �˻� 
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
