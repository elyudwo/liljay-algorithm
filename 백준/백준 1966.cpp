#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



int main(void)
{
	int t;
	cin>>t;
	int n,m;
	int q[];
	
	for(int i=0;i<t;i++)
	{
		cin >> n >> m;
		for(int i=0;i<n;i++)
		{
			int k;
			cin >> k;
			q[i]=k;
		}
		sort(q,q.size());
		
		
	}
	
	return 0;
}

