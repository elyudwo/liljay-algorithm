#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int N,M,K;
	cin >> N >> M >> K;
	
	int a[N];
	
	for(int i=0; i<N; i++)
		cin >> a[i];
	sort(a,a+N,compare);
	
	int sum = 0;
	
	int j = 0;
	for(int i=0; i<M; i++) {
		if(j == K) {
			j = 0;
			sum = sum + a[1];
			continue;
		}
		sum = sum + a[0];
		j++;
	}
	
	cout << sum;
	
	return 0;
}
