#include <iostream>
#include <map>
#include <algorithm>
 
using namespace std;

int main(void)
{

	int t;
	cin >> t;
	while(t--) {
		int n,m;
		scanf("%d",&n);
		int v[n+1];
		for(int i=0; i<n; i++) {
			scanf("%d",&v[i]);
		}
		sort(v,v+n);
		scanf("%d",&m);
		for(int i=0; i<m; i++) {
			int a;
			scanf("%d",&a);
			if(binary_search(v,v+n,a)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		
	}
	
	return 0;
}
