#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> vec;
long long answer = 0;

void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(),vec.end());
}

void solve() {
	long long left = 0;
	long long right = 2000000001;
	
	while(left <= right) {
		long long mid = (left + right) / 2;
		long long rem = k;
		
		for(int i=0; i<vec.size(); i++) {
			if(vec[i] < mid) {
				rem = rem - (mid-vec[i]);
			}
			else {
				break;
			}
			if(rem < 0) {
				break;
			}
		}
		
		if(rem < 0) {
			right = mid - 1;
		}
		else {
			answer = max(answer, mid);
			left = mid + 1;
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}