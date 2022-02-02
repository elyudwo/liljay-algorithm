#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n,m;
	int a[10001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin >> m;
		a[m]++;
	}
	
	for(int i=0;i<10001;i++)
	{
		while(a[i]!=0)
		{
			cout << i;
			a[i]--;
		}
	}
	
	return 0;
}
