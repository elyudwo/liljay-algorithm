#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9
using namespace std;

int n,m,l, answer = INF;
vector<int> vec;

void input() {
	cin >> n >> m >> l;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	vec.push_back(0);
	vec.push_back(l);
	sort(vec.begin(), vec.end());
}

bool checkPossible(int mid) {
	int sum = 0;
	
	for(int i=0; i<vec.size()-1; i++) {
		int diff = vec[i+1] - vec[i] - 1;
		sum += diff / mid;
	}
	
	
	if(sum > m) {
		return false;
	}
	return true;
}

void solve() {
	int left = 1;
	int right = l;
	
	while(left <= right) {
		int mid = (left + right) / 2;
		if(checkPossible(mid)) {
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