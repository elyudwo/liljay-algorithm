#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	
	int cnt = 0;
	int t;
	cin >> t;
	
	vector<pair<int, int>> v[t+1];
	
	for(int i=0; i<t+1; i++) {
		int a,b;
		cin >> a >> b;
		v[i].push_back(a,b);
	}
	
	for(int i=0; i<t; i++) {
		if(v[i].first == v[t].first) {
			cnt = cnt + abs(v[i].second - v[t].second);
		}
		else if( (v[i].first+v[t].first == 3) || (v[i].first+v[t].first == 7) ) {
			
		}
		else {
			cnt = cnt + v[i].second 
		}
		
		
	}
	
	return 0;
}
