#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	vector<int> v;
	
	for(int i=0; i<n; i++) {
		v.push_back(i+1);
	}
	
	do {
		for(int i=0; i<n; i++) {
			printf("%d ",v[i]);
		}
		printf("\n");
	}while(next_permutation(v.begin(),v.end()));
	
	return 0;
}
