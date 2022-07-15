#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string v[51];

int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	char a;
	int sum = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			a = v[i][j];
			for(int k=j+1; k<m; k++) {
				if(v[i][k] == a) {
					int lee = k-j;
					if(v[i+lee][k] == a) {
						if(v[i+lee][j] == a) {
							if(sum < (lee+1) * (lee+1)) {
								sum = (lee+1) * (lee+1);
							}
						}
					}
				}
			}
		}
	}
	cout << sum;
	
	return 0;
}
