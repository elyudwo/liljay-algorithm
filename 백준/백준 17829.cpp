#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;

int v[1024][1024];
int last;
int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	scanf("%d",&n);

	int lee;
	
	for(int i=1; i<=10; i++) {
		if(pow(2,i) == n) {
			lee = i;
			break;
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d",&v[i][j]);
		}
	}
	
	if(n == 2) {
		int result[4];
		result[0] = v[0][0];
		result[1] = v[0][1];
		result[2] = v[1][0];
		result[3] = v[1][1];
		sort(result,result+4);
		cout << result[2];
		return 0;
	}
	
	
	for(int i=lee; i >=2; i--) {
			int garo = 0;
		int sero = 0;
		int g_cnt = 0;
		int s_cnt = 0;
		for(int i=0; i<n/2; i++) {
			for(int j=0; j<n/2; j++) {
				int result[4];	
				result[0] = v[sero][garo];
				result[1] = v[sero][garo+1]; 
				result[2] = v[sero+1][garo]; 
				result[3] = v[sero+1][garo+1];
				
				sort(result,result+4);
				v[s_cnt][g_cnt++] = result[2]; 
				garo = garo + 2;
			}
			s_cnt++; 
			g_cnt = 0;
			garo = 0;
			sero = sero + 2;
		}
		
		if(lee == 2) {
			int result[4];
			result[0] = v[0][0];
			result[1] = v[0][1];
			result[2] = v[1][0];
			result[3] = v[1][1];
			sort(result,result+4);
			last = result[2];
			break;		
		}
		n = n/2;
		lee--;
	}
	
	
	cout << last;
	return 0;
}
