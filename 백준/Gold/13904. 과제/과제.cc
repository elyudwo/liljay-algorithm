#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

vector<pair<int,int> > vec;
int n;
bool check[1001];

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		vec.push_back({b,a});
	}
	
	sort(vec.begin(),vec.end(),cmp);
}

void solve() {
	int answer = 0;
	
	for(int i=0; i<vec.size(); i++) {
		int day = vec[i].second;
		
		while(1) {
			if(day == 0) { break; }
			if(!check[day]) {
				check[day] = true;
				answer += vec[i].first;
				break;
			}
			else { day -= 1; }
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}