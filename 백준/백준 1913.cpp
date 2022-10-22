#include <iostream>

using namespace std;

int v[1000][1000];

int main(void)
{
	int n,m;
	cin >> n;
	cin >> m;
	
	int tmp = n*n;
	
	v[n/2+1][n/2+1] = 1;
	
	for(int i=1; i<=n/2; i++) {
		for(int j=i; j<n-i+1; j++) {
			v[j][i] = tmp;
			tmp--;
		}
		for(int j=i; j<n-i+1; j++) {
			v[n-i+1][j] = tmp;
			tmp--;
		}
		for(int j=n-i+1; j>=i+1; j--) {
			v[j][n-i+1] = tmp;
			tmp--;
		}
		for(int j=n-i+1; j>i; j--) {
			v[i][j] = tmp; 
			tmp--;
		}
	}
	int q,w;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << v[i][j] << " ";
			if(v[i][j] == m) {
				q = i;
				w = j;
			}
		}
		cout << endl;
	}
	cout << q << " " << w << endl;
	
	return 0;
}
