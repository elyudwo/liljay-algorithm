#include <iostream>
#include <vector>

using namespace std;

// union-Find 여행 하려는 곳의 부모가 모두 같다면 성공 

int n,m;
vector<int> travle;
int arr[201];

void init() {
	for(int i=0; i<201; i++) {
		arr[i] = i;
	}
}

int find(int x) {
	if(arr[x] == x) { return x; }
	return arr[x] = find(arr[x]);
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) { return true; }
	return false;
}

void merge(int x,int y) {
	x = find(x);
	y = find(y);
	if(x == y) { return; }
	
	arr[y] = x;
}

void input() {
	cin >> n;
	cin >> m;
	int tmp;
	init();
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {		
			cin >> tmp;
			if(tmp == 1) {
				merge(i,j);
			}
		}
	}
	
	for(int i=0; i<m; i++) {
		cin >> tmp;
		travle.push_back(tmp);
	}
}

void solve() {
	for(int i=1; i<travle.size(); i++) {
		if(!isUnion(travle[i-1],travle[i])) {
			cout << "NO";
			return;
		}
	}
	
	cout << "YES";
	return;
}

int main() {
	input();
	solve();
	
}
