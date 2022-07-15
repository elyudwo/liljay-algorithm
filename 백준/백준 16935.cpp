#include <iostream>

using namespace std;

int v[101][101];
bool check = false;
int main(void)
{
	int n,m,r;
	cin >> n >> m >> r;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> v[i][j];
		}
	}
	while(r--) {
		int a;
		cin >> a;
		int tmp[101][101];
		if(a == 1) {
			if(!check) {
				for(int i=0; i<n; i++) {
					for(int j=1; j<=m; j++) {
						tmp[n-i][j] = v[i+1][j];
					}
				}
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}	
			}
			else {
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						tmp[i][j] = v[m-i+1][j];
					}
				}
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
		}
		
		else if(a == 2) {
			if(!check) {
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						tmp[i][j] = v[i][m-j+1];
					}
				}
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
			else {
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						tmp[i][j] = v[i][n-j+1];
					}
				}
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
			
		}
		else if(a == 3) {
			if(!check) {
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						tmp[i][j] = v[n-j+1][i];
					}
				} 
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						v[i][j] = tmp[i][j];
					}
				}
				check = true;
			}
			else {
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						tmp[i][j] = v[m-j+1][i];
					}
				}
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}
				check = false;
			}
		}
		
		else if(a == 4) {
			if(!check) {
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						tmp[i][j] = v[j][m-i+1];
					}
				}
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						v[i][j] = tmp[i][j];
					}
				}
				check = true;
			}
			else {
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						tmp[i][j] = v[j][n-i+1];
					}
				}
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}
				check = false;
			}
		}
		
		else if(a == 5) {
			if(!check) {
				for(int i=1; i<=n/2; i++) {
					for(int j=1; j<=m/2; j++) {
						tmp[i][j] = v[n/2+i][j];
					}
				}
				for(int i=1; i<=n/2; i++) {
					for(int j=m/2+1; j<=m; j++) {
						tmp[i][j] = v[i][j-m/2];
					}
				}
				for(int i=n/2+1; i<=n; i++) {
					for(int j=1; j<=m/2; j++) {
						tmp[i][j] = v[i][m/2+j];
					}
				}
				for(int i=n/2+1; i<=n; i++) {
					for(int j=m/2+1; j<=m; j++) {
						tmp[i][j] = v[i-n/2][j];
					}
				}
				
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
			else {
				for(int i=1; i<=m/2; i++) {
					for(int j=1; j<=n/2; j++) {
						tmp[i][j] = v[m/2+i][j];
					}
				}
				for(int i=1; i<=m/2; i++) {
					for(int j=n/2+1; j<=n; j++) {
						tmp[i][j] = v[i][j-n/2];
					}
				}
				for(int i=m/2+1; i<=m; i++) {
					for(int j=1; j<=n/2; j++) {
						tmp[i][j] = v[i][n/2+j];
					}
				}
				for(int i=m/2+1; i<=m; i++) {
					for(int j=n/2+1; j<=n; j++) {
						tmp[i][j] = v[i-m/2][j];
					}
				}
				
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
		}
		
		else if(a == 6) {
			if(!check) {
				for(int i=1; i<=n/2; i++) {
					for(int j=1; j<=m/2; j++) {
						tmp[i][j] = v[i][m/2+j];
					}
				}
				for(int i=1; i<=n/2; i++) {
					for(int j=m/2+1; j<=m; j++) {
						tmp[i][j] = v[n/2+i][j];
					}
				}
				for(int i=n/2+1; i<=n; i++) {
					for(int j=1; j<=m/2; j++) {
						tmp[i][j] = v[i-n/2][j];
					}
				}
				for(int i=n/2+1; i<=n; i++) {
					for(int j=m/2+1; j<=m; j++) {
						tmp[i][j] = v[i][j-m/2];
					}
				}
				
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=m; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
			else {
				for(int i=1; i<=m/2; i++) {
					for(int j=1; j<=n/2; j++) {
						tmp[i][j] = v[i][n/2+j];
					}
				}
				for(int i=1; i<=m/2; i++) {
					for(int j=n/2+1; j<=n; j++) {
						tmp[i][j] = v[m/2+i][j];
					}
				}
				for(int i=m/2+1; i<=m; i++) {
					for(int j=1; j<=n/2; j++) {
						tmp[i][j] = v[i-m/2][j];
					}
				}
				for(int i=m/2+1; i<=m; i++) {
					for(int j=n/2+1; j<=n; j++) {
						tmp[i][j] = v[i][j-n/2];
					}
				}
				
				for(int i=1; i<=m; i++) {
					for(int j=1; j<=n; j++) {
						v[i][j] = tmp[i][j];
					}
				}
			}
		}
	}
	if(check) {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}
