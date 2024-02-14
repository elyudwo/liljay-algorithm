#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<int> vec;
vector<int> sum;

void input() {
	cin >> n;
	int t = n;
	while(t--) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	for(int i=0; i<vec.size(); i++) {
		for(int j=0; j<vec.size(); j++) {
			sum.push_back(vec[i] + vec[j]);
		}
	}
	
	sort(vec.begin(), vec.end());
	sort(sum.begin(), sum.end());
}

bool exist(int x) {
	int left = 0;
	int right = sum.size()-1;
	
	while(left <= right) {
		int mid = (left + right) / 2;
		
		if(sum[mid] == x) {
			return true;
		}
		if(sum[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	return false;
	
}

void solve() {
	for(int i=n-1; i>=0; i--) {
		for(int j=i-1; j>=0; j--) {
			int tmp = vec[i] - vec[j];
			if(exist(tmp)) {
				cout << vec[i];
				return;
			}
		}
	}
}

int main() {
	input();
	solve();
	
}