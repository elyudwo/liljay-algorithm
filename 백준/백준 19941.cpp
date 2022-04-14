#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N,K;
	cin >> N >> K;	
	
	char h[N];
	
	for(int i=0;i<N;i++)
		cin >> h[i];	
	
	int i = 0;
	int cnt = 0;
	for(int i=0; i<N; i++)
	{
		if(h[i]!='P')	continue;	
		for(int j=i-K; j<=i+K; j++)
		{
			if(j>=0 && j<N && h[j] == 'H')
			{
				h[j] = '-';
				cnt++;
				break;
			}
		}
	} 
	
	
	cout << cnt;
	
	return 0;
}
