#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int n,m;
	cin >> n >> m;
	int book[n];
	
	for(int i=0; i<n; i++)
		cin >> book[i];
	
	sort(book,book+n);	
	
	float a = n/m;
	a = ceil(a);
	
	int cnt = 0;
	int j = 0;
	int k = n-1;
	if(abs(book[0]) > abs(book[n-1]))
	{
		for(int i=0; i<a-1; i++)
		{
			if( (book[k] > 0 && book[k-m-1] < 0) || (book[k] < 0 && book[k-m-1] > 0) )
			{
				cnt = cnt + abs(book[k]) * 2 + abs(book[k-m-1]) * 2;
				k = k - m;
			}
			else
			{
				cnt = cnt + abs(book[k]) * 2;
				k = k - m;
			}		
		}	
		cnt = cnt + abs(book[0]);
	}
	else
	{
		for(int i=0; i<a-1; i++)
		{
			if( (book[j] > 0 && book[j+m] < 0) || (book[j] < 0 && book[j+m] > 0) )
			{
				cnt = cnt + abs(book[j]) * 2 + abs(book[j+m]) * 2;
				j = j + m;
			}
			else
			{
				cnt = cnt + abs(book[j]) * 2;
				j = j + m;	
			}
					
		}	
		cnt = cnt + abs(book[n-1]);
	}
		
	
	cout << cnt;
		
	return 0;
}
