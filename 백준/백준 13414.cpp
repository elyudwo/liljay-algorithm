#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool compare(const pair<string,int>& a, const pair<string,int>& b)
{
	return a.second < b.second;
}

int main(void)
{
	int n,m;
	cin >> n >> m;
	map<string,int> v;
	vector<pair<string,int>> lee;
	for(int i=0; i<m; i++) {
		string str;
		cin >> str;
		v[str] = i;
	}
	
	for(auto &i : v) {
		v.push_back(i);
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0; i<n; i++) {
		cout << v[i].first << endl;
	}
	return 0;
}
