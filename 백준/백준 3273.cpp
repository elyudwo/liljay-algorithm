#include <iostream>
#include <algorithm> 
using namespace std;
int v[100001];
int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	sort(v,v+n);
	int cnt = 0;
	int x;
	cin >> x;
	for(int i=0; i<n; i++) {
		if(v[i] >= x)	break;
		int a = x - v[i];
		
		if(a <= v[i])	break;
		
		if(binary_search(v,v+n,a)) cnt++;
		else continue;
		
	}
	
	cout << cnt;
	
	return 0;
}
