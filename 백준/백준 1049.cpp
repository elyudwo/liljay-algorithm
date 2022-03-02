#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int N,M;
	cin >> N >> M;
	
	int pac[M];
	int sol[M];
	
	for(int i=0; i < M; i++)
	{
		cin >> pac[i] >> sol[i];
	}
	
	sort(pac, pac+M);
	sort(sol, sol+M);
	
	if(pac[0] <= sol[0] * 6)
	{
		int a = N / 6;
		int b = N % 6;
	
		int sum1 = (a+1) * pac[0];
		int sum2 = a * pac[0] + b * sol[0];
	
		if(sum1 >= sum2)
			cout << sum2;
		else if(sum1 <= sum2)
			cout << sum1;
	}
	
	else if(pac[0] >= sol[0] * 6)
	{
		int sum = N * sol[0];
		cout << sum;
	}
	
	return 0;
}
 
