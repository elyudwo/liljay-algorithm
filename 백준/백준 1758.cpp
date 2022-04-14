#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a,int b)
{
	return a>b;
}

int main(void)
{
	int n;
	cin >> n;
	int m[n];
	
	for(int i=0; i<n; i++)
		cin >> m[i];
	
	sort(m,m+n,compare);
	
	long long cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(m[i] - i <=0)
			continue;
		cnt= cnt + m[i] - i;
	}
	
	cout << cnt;
	
	return 0;
}
