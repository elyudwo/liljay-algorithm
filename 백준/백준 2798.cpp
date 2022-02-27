#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N,M;
	cin >> N >> M;
	int sum = 0;
	int arr[100] = {0,};
	int min = 9999999;
	int goal;
	for(int i=0; i<N; i++)
		cin >> arr[i];
	
	for(int i=0; i<N-2; i++)
	{
		for(int j=i+1; j<N-1; j++)
		{
			for(int k=j+1; k<N; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if(M - sum < min && M-sum >= 0)
				{
					min = M - sum;
					goal = sum;
				}
				
			}
		}
	}
	
	cout << goal;
	
	return 0;
}
