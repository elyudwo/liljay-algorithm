#include <iostream>

using namespace std;

int v[100001];

int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	int rem[100001] = {0,};
	
	while(m--) {
		int a,b,c;
		cin >> a >> b >> c;
		rem[a] = rem[a] + c;
		rem[b+1] = rem[b+1] -c;
	}
	
	for(int i=2; i<=n; i++) {
		rem[i] = rem[i] + rem[i-1];
	}
	
	for(int i=1; i<=n; i++) {
		v[i] = v[i] + rem[i];
	}
	for(int i=1; i<=n; i++) {
		cout << v[i] << " ";
	}

	return 0;
}
