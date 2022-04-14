#include <iostream>

using namespace std;

int main(void)
{
	int n,k;
	cin >> n >> k;
	
	int cnt = 0;
	
	while(1)
	{
		if(n%k == 0) {
			n = n / k;
			cnt++;
		}
		
		else {
			n = n - 1;
			cnt++;
		}
		
		if(n==1)
			break;
	} 
	
	cout << cnt; 
	
	return 0;
}
