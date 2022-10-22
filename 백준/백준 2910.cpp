#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

map<int,int> order;

bool cmp(const pair<int,int> a,const pair<int,int> b) {
	if(a.second == b.second) {
		return order[a.first] < order[b.first];
	}
	else {
		return a.second > b.second;
	}
}

int main(void)
{
	int n,c;
	cin >> n >> c;
	map<int,int> ma;
	map<int,int>:: iterator it;
	vector<pair<int,int> > vec;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		ma[tmp]++;
		if(order[tmp] == 0) order[tmp] = i+1;
	}
	
	for(it = ma.begin(); it!= ma.end(); it++) {
		vec.push_back({it->first,it->second});
	}
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i=0; i<vec.size(); i++) {
		for(int j=0; j<vec[i].second; j++) {
			cout << vec[i].first << " ";
		}
	}

	return 0;
}
