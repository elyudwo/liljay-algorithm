#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000001

using namespace std;

int n;
vector<int> vec;
int max_value = INF;
int answer_left, answer_right;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);		
	}

	sort(vec.begin(), vec.end());
}

void solve() {
	int left = 0;
	int right = vec.size() - 1;
	
	while(left < right) {
		int tmp = vec[left] + vec[right];
//		cout << tmp << " ";
		if(abs(tmp) < max_value) {
			max_value = abs(tmp);
			answer_left = vec[left];
			answer_right = vec[right];
		}
		
		if(tmp < 0) {
			left++;
			continue;
		}
		right--;
	}
	
	cout << answer_left << " " << answer_right;
}

int main() {
	input();
	solve();
	
}