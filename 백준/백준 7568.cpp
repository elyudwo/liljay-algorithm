#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int rank = 1;
	pair<int,int> p[50];
	//pair 사용하는것 중요! 
	
	
	for(int i = 0;i < N; i++)
		cin >> p[i].first >> p[i].second;
	
	for(int i=0;i<N;i++)
	{
			
		for(int j=0;j<N;j++)
		{
			if((p[i].first < p[j].first) && (p[i].second < p[j].second))
				rank++; 
		}
		cout << rank << ' ';
		rank = 1;
	}
	
		
	return 0;
}
