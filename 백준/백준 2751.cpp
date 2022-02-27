#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int num[1000001];
	int n; 
	for(int i=0; i < N; i++)
	{
		cin >> n;
		num[i] = n;
	}
	sort(num,num+N);
	for(int i=0; i < N; i++)
		cout << num[i] << endl;
	
	return 0;
}
