#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int M[N];
	for(int i=0; i<N; i++)
		cin >> M[i];
	sort(M,M+N);	
	int sum[N];
	int K = 0;
	sum[0] = M[0];
	for(int i=0; i < N-1; i++)
		sum[i+1] =sum[i] + M[i+1];
	
	
	for(int i=0; i<N; i++)
		K = K + sum[i];
	cout << K;
	
	return 0;
}
