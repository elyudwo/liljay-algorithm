#include <iostream>
#include <algorithm>

using namespace std;

int hansoo(int x)
{
	int m1,m2,m3;
	int sum = 0;
	if(x<100)
		return x;
	else
	{
		for(int i=100;i<=x;i++)
		{
			m1 = i/100;
			m2 = i%100/10;
			m3 = i%10;
			
			if(m3-m2 == m2-m1)
				sum++;
				
		}
	}
	return (99+sum);
	
}


int main(void)
{
	int x;
	cin >> x;
	
	cout << hansoo(x);
	
	return 0;
}
