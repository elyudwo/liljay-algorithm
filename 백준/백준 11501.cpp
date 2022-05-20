#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,n;


vector<int> lee;

int main(void)
{
	cin >> t;
	for(int i=0; i<t; i++) {
		vector<int> v;
		
		cin >> n;
		
		for(int i=0; i<n; i++) {
			int a
			cin >> a;
			v.push_back(a);
		}
		
		long long sum = 0;
		int max_value = -1;
		
		for(int i=n-1; i>=0; i--) {
			max_value = max(max_value,v[i]);
			sum = sum + max_value-v[i];
		}
		cout << sum << endl;
	}	
	
	return 0;
}
