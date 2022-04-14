#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v;
	
	for(int i=0;i<N; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	
	sort(v.begin(),v.end());
	long long sum = 0;
	for(int i=0; i<N; i++)
	{
		sum = sum + abs((i+1) - v[i]);
	}
	cout << sum;
		
	return 0;
}
