#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int n,m;
bool check[100001];
vector<int> vec;

void input() {
	cin >> n;
	cin >> m;
	
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}	
}

bool can(int mid) {
	if(vec[0] > mid) { return false; }
	for(int i=1; i<vec.size(); i++) {
		if(vec[i] - vec[i-1] > mid * 2) { return false; }
	}
	if(n - vec[vec.size()-1] > mid) { return false; } 
	
	return true;
}

void solve() {
	int answer = INF;
	int left = 1;
	int right = 100000;
	
	while(left <= right) {
		int mid = (left + right) / 2;
		
		if(can(mid)) {
			answer = min(answer, mid);
			right = mid - 1;
			continue;
		}
		left = mid + 1;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}