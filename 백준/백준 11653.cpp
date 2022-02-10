#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int M=N; 
	
	for(int i=2;i<=N;i++)
	{
		while(M%i==0)
		{
			cout << i << endl;
			M = M / i;
			if(M==0)
				break;
		}
	}
	
	
	return 0;
}
