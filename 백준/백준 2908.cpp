#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int first,last;
	int first1,first2,first3;
	int last1,last2,last3;
	cin >> first >> last;
	
	first1 = first/100;
	first2 = first%100/10;
	first3 = first%100%10;
	
	last1 = last/100;
	last2 = last%100/10;
	last3 = last%100%10;
	
	int m[3] = {first3,first2,first1};
	int n[3] = {last3,last2,last1};
	
	if(m[0]>n[0])
	{
		for(int i=0;i<3;i++)
			cout<<m[i];
	}
	else if(m[0]<n[0])
	{
		for(int i=0;i<3;i++)
			cout<<n[i];
	}
	
	else if((m[0] == n[0]) && (m[1]>n[1]) )
	{
		for(int i=0;i<3;i++)
			cout<<m[i];
	}
	
	else if((m[0] == n[0]) && (m[1]<n[1]))
	{
		for(int i=0;i<3;i++)
			cout<<n[i];
	}
	
	
	else if((m[0] == n[0]) && (m[1]==n[1]) && (m[2] > n[2]) )
	{
		for(int i=0;i<3;i++)
			cout<<m[i];
	}
	
	else if((m[0] == n[0]) && (m[1]==n[1]) && (m[2] < n[2]) )
	{
		for(int i=0;i<3;i++)
			cout<<n[i];
	}
	
	return 0;
}
