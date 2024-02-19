#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> vec;

void input() {
	cin >> n >> c;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);		
	}
	
	sort(vec.begin(), vec.end());
}

void solve() {
	int left = 1;
	int right = vec[n-1] - vec[0];
	int answer = 0;
	
	while(left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int before = vec[0];
		
		for(int i=1; i<n; i++) {
			if(vec[i] - before >= mid) {
				cnt++; 
				before = vec[i];
			}
		}
		
		if(cnt >= c) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	 
}