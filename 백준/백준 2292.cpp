#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int i = 1;
	
	while(n > 0)
	{
		if(n == 1)
			break;
		n = n - 6*i; 
		i++;
		
	}	

	cout << i;
	
	return 0;
}
