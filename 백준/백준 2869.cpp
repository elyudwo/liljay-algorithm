#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int M,N,i;
	int sum = 0;
	cin >> M;
	cin >> N;
	
	int k[N-M];
	
	for(M;M<=N;M++)
	{
		if(M%2!=0 && M%3!=0 && M%5!=0 && M%7!=0)
		{
			k[M] = M;
			sum += M;
		}
	}
	while(k[M])
	{
		i=k[M];
	}
	
	cout << sum << endl << i;
	
	
	return 0;
}
