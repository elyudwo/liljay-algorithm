#include <iostream>
#include <string>
using namespace std;

int v[1000001];

int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	for(int i=0; i<n; i++) {
		if(v[i] == 1) {
			cnt++;
			v[i+1] = !v[i+1];
			v[i+2] = !v[i+2];
		}
	}
	cout << cnt;
	
	return 0;
}
