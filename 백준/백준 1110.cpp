#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int i=0;
	int sum = n;
	while(1) {
		i++;
		
		int a = sum/10;
		int b = sum%10;
		
		sum = b * 10 + ((a+b)%10);
		
		if(sum == n) {
			break;
		}
	}
	
	cout << i;
	
	
	return 0;
}
