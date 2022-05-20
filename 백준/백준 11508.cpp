#include <iostream>
#include <algorithm> 
using namespace std;
int n;
int v[100001];
bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	cin >> n;
	int sum = 0;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];	
	}
	
	sort(v,v+n,compare);
	
	for(int i=0; i<n; i++) {
		if( (i+1) % 3 == 0) {
			continue;
		}
		sum = sum + v[i];
	}
	
	cout << sum;
	
	return 0;
}
