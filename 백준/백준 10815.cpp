#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n,m,a;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> a;
		cout << binary_search(v.begin(),v.end(),a) << ' ';
	}
	
	return 0;
}
