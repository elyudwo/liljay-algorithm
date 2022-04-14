#include <iostream>
#include <algorithm>

using namespace std;

int w[1001];

int main(void)
{
	int N,L;
	cin >> N >> L;
	
	for(int i=0; i<N; i++)
		cin >> w[i];
		
	sort(w,w+N);
	
	int j = w[0];
	int cnt = 1;
	for(int i=0; i<N; i++)
	{
		if(w[i]-j > L-1)
		{
			cnt ++;
			j = w[i];
		}
	}
		
	cout << cnt;
	return 0;
}
