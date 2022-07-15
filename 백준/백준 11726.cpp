#include <iostream>

using namespace std;	//규칙성을 찾아서 점화식을 만든다 ! 

int d[1001];

int dp(int x) {
	if(x == 1) 	return 1;
	if(x == 2) 	return 2;
	if(d[x] != 0)	return d[x];
	return d[x] = (dp(x-1) + dp(x-2)) % 10007;
}

int main(void)
{
	int x;
	cin >> x;
	cout << dp(x);
	
	return 0;
}
