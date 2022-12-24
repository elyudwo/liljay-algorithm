#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> consent;
int n,m;

bool cmp(int a,int b) {
	return a > b;
}

void input() {
	cin >> n >> m;
	int tmp;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
}
	
void solve() {
	sort(vec.begin(),vec.end(),cmp);
	int time = 0; 
	for(int i=0; i<m; i++) {
		consent.push_back(vec[0]);
		vec.erase(vec.begin());
		if(vec.empty()) {
			break;
		}
	}
	
	while(1) {
		if(vec.size() == 0) {
			if(consent.empty()) {
				break;
			}
			sort(consent.begin(),consent.end(),cmp);
			time = time + consent[0];
			break;
		}
		sort(consent.begin(),consent.end(),cmp);
		time += consent[m-1];
		for(int i=0; i<consent.size(); i++) {
			consent[i] = consent[i] - consent[consent.size()-1];
		}
		
		for(int i=consent.size()-1; i>=0; i--) {
			if(consent[i] == 0) {
				consent[i] = consent[i] + vec[0];
				vec.erase(vec.begin());
			}
			if(vec.empty()) {
				break;
			}
		}
	}
	
	cout << time;
}

int main() {
	input();
	solve();
}
