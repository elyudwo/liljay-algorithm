#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int m = N / 5;
	int cnt = 0;
	int b;
	while(1)
	{
		if(m < 0)
		{
			cout << -1;
			return 0;
		}
		
		if((N - (5*m))%3 == 0)
		{
			b = (N-(5*m)) / 3;
			break;	
		}
		m--;
	}
	
	cout << m + b;
	
	return 0;
}
