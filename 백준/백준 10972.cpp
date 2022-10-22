#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}	
	
	do {
		if(!next_permutation(v.begin(),v.end())) {
			cout << -1;
			return 0;
		}
	
		for(int i=0; i<n; i++) {
			cout << v[i] << " ";
		}
		break;
	}while(next_permutation(v.begin(),v.end()));
	
	return 0;
}
