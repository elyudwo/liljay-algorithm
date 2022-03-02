#include <iostream>

using namespace std;

int main(void)
{
	long long N;
	cin >> N;
	
	long long sum = 0;
	int cnt = 0;
	int i = 1;
	while(sum != N)
	{
		if(sum + i > N)
		{
			sum = sum - i;
			cnt--;
			if(sum + i < N)
			{
				cnt ++;
				break; 
			}
		}
		sum = sum + i;
		i++;
		cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
