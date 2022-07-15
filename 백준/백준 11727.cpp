#include <iostream>

using namespace std;

int d[1001];

int dp(int n) {
	if(n == 1)	return 1;
	if(n == 2) 	return 3;
	if(d[n])	return d[n];
	return d[n] = (dp(n-1) + 2 * dp(n-2)) % 10007;
}

int main(void)
{
	int n;
	cin >> n;
	cout << dp(n);
	
	
	return 0;
}
