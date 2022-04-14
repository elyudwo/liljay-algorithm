#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{	
	int n,m;
	cin >> n >> m;
	
	
	int result = 0;
	int a;
	
	for(int i=0; i<n; i++) {
		
		int min = 9999;
		for(int j=0; j<m; j++) {
			cin >> a;
			if(min > a)
				min = a;
		}
		if(result < min)
			result = min;
	}	
	cout << result;
	
	return 0;
}
