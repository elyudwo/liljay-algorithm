#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n,m,k;
vector<pair<int,int> > vec;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;
}

int main() {
	cin >> n >> m >> k;
	
	for(int i=0; i<k; i++) {
		int a,b;
		cin >> a >> b;
		vec.push_back({a, b});
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
//	cout << endl;
//	for(int i=0; i<vec.size(); i++) {
//		cout << vec[i].first << " " << vec[i].second << endl;
//	}
//	cout << endl;
	
	ll left = 0, right = 2e10;
	ll answer = 2e10;

	while(left <= right) {
		ll mid = (left + right) / 2;
		ll day = 0;
		ll sum = 0;
		
		for(int i=0; i<k; i++) {
			if(day == n) break;
			if(vec[i].second <= mid) {
				sum += vec[i].first; 
				day++;
			}
		}
		
		if(day < n) {
			left = mid + 1;
			continue;
		}
		
		if(sum >= m) {
			if(day == n) {
				answer = min(answer, mid);
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	if(answer == 2e10) {
		cout << "-1";
		return 0;
	}
	
	cout << answer;
	
	
}