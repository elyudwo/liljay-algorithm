#include <iostream>
#include <algorithm>
#include <cmath>
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
	sort(v.begin(),v.end());
	int result = -1;
	int cnt = 0;
	do {
		int sum = 0;
		for(int i=0; i<n-1; i++) {
			sum = sum + abs(v[i] - v[i+1]);
		}
		if(result < sum) {
			result = sum;
		}
		
	}while(next_permutation(v.begin(),v.end()));
	
	
	cout << result ;
		
	return 0;
}
