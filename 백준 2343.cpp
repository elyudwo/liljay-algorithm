#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int sum = 0;
int result = 0;
vector<int> vec;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
}

void solve() {
	int div = sum / m;
	int tmp = 0;
	
	for(int i=0; i<vec.size(); i++) {
		tmp = tmp + vec[i];
		if(tmp > div) {
			int a = fabs(tmp - div);
			int b = fabs(tmp - div - vec[i-1]);
			if(a > b) {
				result = max(result, tmp - vec[i-1]);
				tmp = vec[i];
			}
			else {
				result = max(result,tmp);
				tmp = 0;
			}
		}
		else if(tmp == div) {
			result = max(result,tmp);
			tmp = 0;
		}
	}
	
	result = max(result,tmp);
	
	cout << result;
}

int main() {
	input();
	solve();
	
}
