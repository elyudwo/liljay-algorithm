#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector <pair<int, int> > v(N);
	for(int i=0; i<N; i++)
	{
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(),v.end());
	int count = 0;
	int time = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(time<=v[i].second)
		{
			time = v[i].first;
			count ++;
		}
	}
	
	cout << count;
	
	return 0;
}
