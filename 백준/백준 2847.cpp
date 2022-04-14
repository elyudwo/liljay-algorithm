#include <iostream>

using namespace std;

int num[100];

int main(void)
{
	int N;
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> num[i];
	}
	
	int i = 1;
	int cnt = 0;
	while(1)
	{
		if(num[N-i] <= num[N-i-1])
		{
			cnt = cnt + num[N-i-1] - num[N-i] + 1;
			num[N-i-1] = num[N-i] - 1;
			i++;
		}
		else
			i++;
		if(i==N)
			break;
	}
	cout << cnt;
	
	return 0;
}
