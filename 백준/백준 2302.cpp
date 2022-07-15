#include <iostream>
#include <vector>
using namespace std;

int v[41];
int dp[41];

int main(void)
{
	int n,m;
	cin >> n;
	cin >> m;
	
	for(int i=1; i<41; i++) {
		v[i] = i;
	}
	
	for(int i=0; i<m; i++) {
		int a;
		cin >> a;
		v[a] = 0;
	}
	

	int cnt = 0;
	int sum = 1;
	
	for(int i=1; i<=n; i++) {
		if(v[i] != 0 && i == n) {
			cnt++;
			int tmp[42];
			tmp[0] = 1;
			tmp[1] = 1;
			tmp[2] = 2;
			if(cnt >= 3) {
				for(int i=3; i<=cnt; i++) {
					tmp[i] = tmp[i-2] + tmp[i-1];
				}
			}
			sum = sum * tmp[cnt];
			cnt = 0;
			
		}
		else if(v[i] != 0) {
			cnt++;
		}
		else if(v[i] == 0) {
			int tmp[42];
			tmp[0] = 1;
			tmp[1] = 1;
			tmp[2] = 2;
			if(cnt >= 3) {
				for(int i=3; i<=cnt; i++) {
					tmp[i] = tmp[i-2] + tmp[i-1];
				}
			}
			sum = sum * tmp[cnt];
			cnt = 0;
		}
	}
	
	cout << sum;
	
	return 0;
}
