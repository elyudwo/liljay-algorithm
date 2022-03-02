#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main(void)
{
	int N;
	cin >> N;
	
	vector<pair<int, int> > v;
	
	for(int i=0; i<N; i++)
	{
		int n,m;
		cin >> n >> m;
		v.push_back(pair<int, int>(n, m));
	}
	
	stable_sort(v.begin(),v.end(),compare);
	
	int count = 0;
	
	for(int i=0; i<N; i++)
	{
		if(v[i].first == v[i+1].first && v[i].second != v[i+1].second)
		{
			count ++;
		}
	}
	
	cout << count;
	
	return 0;
}
