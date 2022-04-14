#include <iostream>

using namespace std;

int main(void)
{
	int N,K;
	cin >> N >> K; 
	int sum = 0;
	
	for(int i=1; i<=K ;i++)
		sum = sum + i;
		
	N = N - sum;
	
	if(N<0)
	{
		cout << -1;
		return 0;
	}
	if(N % K == 0)	
		cout << K-1;
	else if(N % K !=0)	
		cout << K;
	
	
	return 0;
}
