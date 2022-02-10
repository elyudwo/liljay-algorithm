#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int M,N;
	cin >> M;
	cin >> N;
	int count = M;
	int down=0;
	int sum = 0;
	int sosu[N-M];
	
	for(int i=0;i<=N-M;i++)
	{
	    sosu[i] = count;
	    count++;
	}
	
	for(int i=0;i<=N-M;i++)
	{
	    for(int j=sosu[i]-1; j>=1; j--)
	    {
	        if(j == 1)
	            down = sosu[i];    
	        else if(sosu[i] % j == 0)
	            break;
	    }
	    if(down!=0)
	        break;
	}
	
	
	
	for(int i=0;i<=N-M;i++)
	{
	    for(int j=sosu[i]-1; j>=1; j--)
	    {
	        if(j == 1)
	            sum += sosu[i];    
	        else if(sosu[i] % j == 0)
	            break;
	    }
	}
	if(sum == 0)
	    cout << -1;
	else
	{
	    cout << sum << endl;
	    cout << down;
	}
	
	
	return 0;
}
