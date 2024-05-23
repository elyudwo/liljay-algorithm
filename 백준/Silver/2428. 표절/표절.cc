#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
vector<int> vec;

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
	ll answer = 0;
	int left = 0;
	int right = 1;
	
	while(left <= right && right < n) {
		int l_value = vec[left];
		int r_value = vec[right];
		
//		cout << l_value << " " << r_value << "  ";
//		cout << left << " " << right << endl;
		
		if(l_value * 10 >= r_value * 9 && right < n - 1) {
			right++;
			continue;
		}
		
		if(l_value * 10 >= r_value * 9 && right == n - 1) {
			answer += right - left;
			left++;
			continue;
		}
		
		if(left == right) {
			right++;
			continue;
		}
		answer += right - left - 1;
		left++;
		
	}
	ll tmp = 0;
	answer = max(answer, tmp);
	cout << answer;
	
}

int main() {
	input();
	solve();
	
} 