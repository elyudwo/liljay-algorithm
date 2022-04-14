#include <iostream>
#include <cmath>

using namespace std; 

int main(void)
{
	int N,M;
	cin >> N >> M;
	int rt;
	
	for(int i=N; i<=M; i++)
	{
		rt=sqrt(i);
		if(rt == 1 && i!=1)
		{
			cout << i << endl;
			continue;
		}	
		if(i%2)
		{
			for(int j=2;j<=rt;j++)
			{
				if(!(i%j))
					break;
				if(j == rt)
					cout << i << endl;
			}
		}
	}
	
	return 0;
}
