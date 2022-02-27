#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int N;
	cin >> N;
	int num[N];
	int b,c;
	double a = 0;
	for(int i=0; i<N; i++)
	{
		cin >> num[i];
		a = a + num[i];
	}	
	cout << round(a/N) << endl;
	
	sort(num,num+N);
	b = num[N/2];
	cout << b << endl;
	
	int d = num[N-1] - num[0];
	
	int j = 0;
	int count[N]={0,0,0};
	while(j < N)
	{
		int k = num[j];
		for(int i=0; i<N; i++)
		{
			if(k == num[i])
			{
				count[j]++;
			}
		}
		j++;
	}
	
	sort(count,count+N);
	if(count[0] == count[N-1])
		cout << num[1] << endl;
	else
		cout << count[N-1] << endl;
		
	cout << d;
	
	return 0;
}
