#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	int sum = 0;
	cin >> n;
	char k[n];
	cin >> k;
	for(int i=0;i<n;i++)
	{
		sum += k[i] - '0';
		// char형 정수에 0을 빼면 int 형 정수값으로 변환됨 
	}
	cout << sum;
	return 0;
}
