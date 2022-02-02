#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n[10000] = {1,};
	int sum;
	
	for(int i=0;i<=10000;i++)
	{
		if(i<10)
		{
			n[i+i]=1;
		}
		else if(i<100)
		{
			n[i+i/10+i%10]=1;
		}
		else if(i<1000)
		{
			n[i+i/100+i%100/10+i%10] = 1;
		}
		else if(i<10000)
		{
			sum=i+(i/1000)+(i%1000/100)+(i%100/10)+(i%10);
			if(sum<10000)
				n[sum]=1;
		}
	}
	
	for(int j=1;j<10000;j++)
	{
		if(!n[j])
		{
			cout << j <<endl;
		}
		
	}
	
	return 0;
}
