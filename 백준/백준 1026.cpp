#include <iostream>
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
	int A[N];
	int B[N];
	int result = 0;
	
	for(int i=0; i < N; i++)
	{
		cin >> A[i];
	}
	
	for(int i=0; i < N; i++)
	{
		cin >> B[i];
	}
	
	sort(B , B + N);
	sort(A, A + N, compare);	
	
	for(int i=0; i < N; i++)
	{
		result = result + A[i]*B[i];
	}
	
	cout << result;
	
	return 0;
}
