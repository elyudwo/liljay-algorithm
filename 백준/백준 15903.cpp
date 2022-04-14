#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int n,m;
	cin >> n >> m;
	
	long long a[1000];
	long long sum = 0;
	
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	

	
	for(int i=0; i<m; i++)
	{
		sort(a,a+n);
		long long c = a[i] + a[i+1];
		a[i] = c;
		a[i+1] = c;
	
	}
	
	for(int i=0;i<n; i++)
	{
		sum = sum + a[i];
	}
	
	cout << sum;
	
	return 0;
}
