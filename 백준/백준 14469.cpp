#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int,int> &a,const pair<int,int> &b) 
{
	if(a.first == b.first) {
		return a.second < b.second;
	}	
	return a.first < b.first;
}

int main(void)
{
	vector<pair<int,int>> v;
	
	int seconds = 0;
	
	int n;	cin >> n;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end(),compare);
	seconds = seconds + v[0].first + v[0].second;
	
	for(int i=1; i<n; i++) {
		if(v[i].first >= seconds) {
			seconds = v[i].first + v[i].second;
		}
		else {
			seconds = seconds + v[i].second;
		}
	}
	
	cout << seconds;
	
	return 0;
}
