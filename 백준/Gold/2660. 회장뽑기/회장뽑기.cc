#include <iostream>
#include <queue>

using namespace std;

int n;
vector<int> vec[51];
bool check[51];
int arr[51];

void input() {
	cin >> n;
	
	while(1) {
		int a,b;
		cin >> a >> b;
		if(a == -1 && b == -1) { break; }
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}

bool checkAll() {
	for(int i=1; i<=n; i++) {
		if(!check[i]) { return false; }
	}
	return true;
}

int bfs(int index) {
	queue<pair<int,int> > q;
	q.push({index,0});
	check[index] = true;
	int answer = 0;
	
	while(!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		answer = max(answer,cnt);	
		
		for(int i=0; i<vec[x].size(); i++) {
			if(!check[vec[x][i]]) {
				check[vec[x][i]] = true;
				q.push({vec[x][i],cnt+1});
			}
		}	
	}
	
	if(checkAll()) {
		return answer;
	}
	else {
		return 0;
	}
}

void init() {
	for(int i=1; i<=n; i++) {
		check[i] = false;
	}
}

void solve() {
	int min_tmp = 100000000;
	vector<int> answer;
	
	for(int i=1; i<=n; i++) {
		arr[i] = bfs(i);
		init();
		min_tmp = min(min_tmp,arr[i]);
	}
	
	for(int i=1; i<=n; i++) {
		if(arr[i] == min_tmp) {
			answer.push_back(i);
		}
	}
	
	cout << min_tmp << " " << answer.size() << '\n';
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i] << " ";
	}
	
}

int main() {
	input();
	solve();
	
}