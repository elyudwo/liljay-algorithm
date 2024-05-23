#include <iostream>
#include <algorithm>

using namespace std;

int v[301][301];

int main(void)
{
	int n,m,r;
	cin >> n >> m >> r;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&v[i][j]);
		}
	}	
	
	
	
	int turn_cnt = min(n,m)/2;
	
	for(int i=0; i<r; i++) {
		int rem[301][301];
		int g_first,g_last,s_first,s_last;
		g_first = 1;
		g_last = m;
		s_first = 1;	
		s_last = n;
		
		
		for(int j=0; j<turn_cnt; j++) {
			for(int q=s_first+1; q<=s_last; q++) {
				rem[q][s_first] = v[q-1][s_first];
			}
			for(int q=g_first+1; q<=g_last; q++) {
				rem[s_last][q] = v[s_last][q-1];
			}
			for(int q=s_last-1; q>=s_first; q--) {
				rem[q][g_last] = v[q+1][g_last];
			}
			for(int q=g_last-1; q>=g_first; q--) {
				rem[g_first][q] = v[g_first][q+1];
			}
			
			g_first++;
			g_last--;
			s_first++;
			s_last--;
		}
		
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=m; k++) {
				v[j][k] = rem[j][k];
			}
		}	
	}
	
	for(int j=1; j<=n; j++) {
		for(int k=1; k<=m; k++) {
			cout << v[j][k] << " ";
		}
		cout << endl;
	}
	
	
	
	return 0;
 } 