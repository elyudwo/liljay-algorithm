#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	int count = 0;
	cin >> N;
	int M[N];
	for(int i=0;i<N;i++)
	{
		cin >> M[i];
	}
	for(int i=0;i<N;i++)
	{
	    if(M[i] == 1)
	        continue;
		for(int j=M[i]-1; j>=1; j--)
		{
		    if(j == 1)
		        count++;
		    else if((M[i] % j) == 0)
		        break;
		    
		}
	}
	cout << count;
	
	return 0;
}
