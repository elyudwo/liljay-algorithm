#include <iostream>
#include <algorithm> 
using namespace std;

int v[200001];

int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	sort(v,v+n);
	
	cout << v[(n-1)/2];
	
	return 0;
}
