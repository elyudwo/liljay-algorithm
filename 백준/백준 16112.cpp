#include <iostream>
#include <algorithm>
using namespace std;

long long v[300001];

bool compare(int a,int b) {
	return a > b;
}

int main(void)
{
	long long n,k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	
	sort(v,v+n);
	
	long long sum = 0;
	long long result = 0;
	for(int i=0; i<n; i++) {
		sum = sum + v[i];
	}
	
	 
	
	long long tmp = 0;
	for(int i=0; i<k; i++) {
		tmp = tmp + v[i];
		result = result + sum - tmp;
	}
	
	cout << result;
	
	return 0;
}
