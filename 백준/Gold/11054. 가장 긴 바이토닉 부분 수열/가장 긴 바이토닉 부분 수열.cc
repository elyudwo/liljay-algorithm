#include <iostream>
#include <vector>

using namespace std;

int n;
int dp_max[1002];
int dp_min[1002];

vector<int> vec;
 
void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
}

void solve() {
	int answer = 1;
	for(int i=0; i<=n; i++) {
		dp_max[i] = 1;
		dp_min[i] = 0;
	}
	
	for(int i=1; i<n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(vec[i] > vec[j]) {
				dp_max[i] = max(dp_max[i], dp_max[j] + 1);
			}
		}
	}	
	
	for(int i=n-1; i>=0; i--) {
		for(int j=i+1; j<n; j++) {
			if(vec[i] > vec[j]) {
				dp_min[i] = max(dp_min[i], dp_min[j] + 1);
			}
		}
	}	
	
	for(int i=0; i<n; i++) {
		answer = max(answer, dp_max[i] + dp_min[i]);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
		
}