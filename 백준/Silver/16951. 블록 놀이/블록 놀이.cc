#include <iostream>
#include <vector>
#define INF 1001
using namespace std;

int n, k;
vector<int> rem;

void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		rem.push_back(tmp);
	}	
}

void solve() {
	int answer = INF;
	
	for(int i=0; i<n; i++) {
		int tmp = 0;
		vector<int> vec = rem;
		bool check = false;
		
		for(int j=i-1; j>=0; j--) {
			if(vec[j+1] - k != vec[j]) {
				vec[j] = vec[j+1] - k;
				if(vec[j] < 1) {
					check = true;
					break;
				}
				tmp++;
			}
		}
		
		for(int j=i+1; j<n; j++) {
			if(vec[j-1] + k != vec[j]) {
				vec[j] = vec[j-1] + k;
				if(vec[j] < 1) {
					check = true;
					break;
				}
				tmp++;
			}
		}
		
		if(check) { continue; }
		answer = min(answer, tmp);
	} 
	
	if(answer == INF) {
		cout << "0";
		return;
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}