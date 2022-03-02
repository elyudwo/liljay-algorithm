#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int T,N;
	cin >> T;
	
	int cnt = 0;
	int sum[T];
	while(cnt != T)
	{
		cin >> N;
		vector<pair<int,int> >	v;
		
		for(int i=0; i < N; i++)
		{
			int n,m;
			cin >> n >> m;
			v.push_back(pair<int, int>(n,m));
		}
		
		sort(v.begin(),v.end());
		int k = 1;
		int se = v[0].second;
		for(int i = 1; i < N; i++)
		{
			
			if(se > v[i].second)
			{
				k++;
				se = v[i].second;	
			}
		}
		
		sum[cnt] = k;
		cnt++;
	}
	
	for(int i=0; i < T; i++)
		cout << sum[i] << endl;
	
	return 0;
}
