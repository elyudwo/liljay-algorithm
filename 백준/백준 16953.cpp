#include <iostream>

using namespace std;

int main(void)
{
	int n,m;
	cin >> n >> m;
	int cnt = 1;
	
	while(1)
	{		
		if(m==n) {
			cout << cnt;
			break;
		}
		
		if(m < n) {
			cout << -1; 
			break;
		}
		
		if(m%2 == 0) {
			m = m / 2;
			cnt++;
		}
		else if (m%10 == 1) {
			m = m / 10;	
			cnt++;
		}
		else
		{
			cout << -1; 
			break;
		}
			
	}
	
	return 0;
}
