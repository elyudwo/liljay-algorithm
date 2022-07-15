#include <iostream>
#include <algorithm>

using namespace std; 
int v[300001];

bool compare(int a,int b) {
	return a > b;
}

int main(void)
{
	int n;
	int result = 0;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	return 0;
}
