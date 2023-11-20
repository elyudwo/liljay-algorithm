#include <iostream>

using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	
	for(int i=0; i<m; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		cout << sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1] << '\n';
	}
}