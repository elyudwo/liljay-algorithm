#include <iostream>
#include <algorithm>
using namespace std;

int v[1000001];

int main(void)
{
	int n;
	cin >> n;
	
	v[2] = 1;
	v[3] = 1;
	v[4] = 2;
	
	for(int i = 5; i<=n; i++) {
		if(i%2 != 0 && i%3 != 0)
			v[i] = v[i-1] + 1;
		else if(i%2 == 0 && i%3 == 0) 
			v[i] = min(v[i/2] + 1,v[i/3] + 1);
		else if(i%2 == 0) 
			v[i] = min(v[i/2] + 1,v[i-1]+1);
		else if(i%3 == 0)
			v[i] = min(v[i/3] + 1,v[i-1] + 1);
	}
	cout << v[n];
	
	return 0;
}
