#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;

vector<int> vec[100001];

int n;		
int compare = 0;

bool cmp(int a, int b) {
	return fabs(compare - a) < fabs(compare - b);
}

void inputVec() {
	for(int i=0; i<n; i++) {
		int tmp;
		int a,b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
}

int main() {
	int t;
	cin >> t;
	
	
	while(t--) {
		cin >> n;
		inputVec();
		vector<pair<int,int> > dist;
		
		for(int i=0; i<100001; i++) {
			if(vec[i].size() == 0) { continue; }
			
			sort(vec[i].begin(), vec[i].end(), cmp);
			for(int j=0; j<vec[i].size(); j++) {
				dist.push_back({i, vec[i][j]});
			}	
			compare = vec[i][vec[i].size()-1];
		}
		
		int m;
		cin >> m;
		for(int i=0; i<m; i++) {
			int tmp;
			cin >> tmp;
			cout << dist[tmp-1].first << " " << dist[tmp-1].second << "\n";
		}
		
		for(int i=0; i<100001; i++) {
			vec[i].clear();
		}
		compare = 0;
	}
 
		
}