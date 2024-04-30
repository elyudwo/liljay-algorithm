#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 300000000000000
using namespace std;

typedef long long ll;
vector<pair<int,int> > vec;
int sum = 0;
ll answer = INF;
ll n,m;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) {
        return a.first > b.first;
    }
    
    return a.second < b.second;
} 

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		sum += a;
		vec.push_back({a, b});
	}

    sort(vec.begin(), vec.end(), cmp);
}

void solve() {
    if(sum < m) { cout << "-1"; return; }
	
	ll meat_sum = 0, cost_tmp = 0;
	bool check = false;
	
	for(int i=0; i<vec.size(); i++) {
	    ll meat = vec[i].first;
	    ll cost = vec[i].second;
	    
	    meat_sum += meat;
	    
	    if(i != 0 && vec[i-1].second == cost) {
            if(!cost_tmp) { cost_tmp = cost * 2; }
            else { cost_tmp += cost; }
	    }
	    else { cost_tmp = 0; }
	    
	    if(meat_sum >= m) {
	        if(cost_tmp != 0) {
	            answer = min(answer, cost_tmp);
	            continue;
	        }
	        answer = min(answer, cost);
	    }
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
	
} 