#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	int cnt;
	
	cnt = cnt + N/500;
	N = N % 500;
	
	cnt = cnt + N/100;
	N = N % 100;
	
	cnt = cnt + N/50;
	N = N % 50;
	
	cnt = cnt + N/10;
	N = N % 10;	

	
	cout << cnt;
	
	return 0;
}
