#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	
	int shin[T];
	int h = 0;
	for(int i=0; i<T; i++)
	{
		int sum = 0;
		int N;
		cin >> N;
		int M[N];
		for(int i=0; i<N; i++)
			cin >> M[i];
		int i = 0;
		int k = 0;
		
		
		while(1)
		{
			if(!M[i+1])
				break;
			else if(M[i] <= M[i+1] && M[i+1])
				i++;
			else
			{
				for(int j=i; j>=k; j--)
					sum = sum + M[i] - M[j];
				k = i;
				i++;
			}
		
		}
		shin[h] = sum;
		h++;
	}
	
	
	
	for(int i=0; i<T; i++)
	{
		if(shin[i] < 0)
			shin[i] = 0;
	}
	
	for(int i=0; i<T; i++)
		cout << shin[i] << endl;
	
	return 0;
}

