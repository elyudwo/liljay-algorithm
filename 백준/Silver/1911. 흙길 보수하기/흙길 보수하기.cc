#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;

int n,l;
vector<pair<double,double> > vec;

void input() {
	cin >> n >> l;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		vec.push_back({a,b});
	}	
	sort(vec.begin(), vec.end());
}

void solve() {
	double now = 0;
	int answer = 0;
			
	for(int i=0; i<vec.size(); i++) {
		if(now >= vec[i].second) { continue; }
		else {
			if(now < vec[i].first) {
				answer = answer + ceil((vec[i].second - vec[i].first) / l);
			
				int minus_tmp = ceil((vec[i].second - vec[i].first) / l) * l - (vec[i].second - vec[i].first);
				
				now = vec[i].second + minus_tmp;
			}
			else {
				answer = answer + ceil((vec[i].second - now) / l);
				int minus_tmp = ceil((vec[i].second - now) / l) * l - (vec[i].second - now);
				now = vec[i].second + minus_tmp;
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	

}