#include <iostream>
#include <map>
#include <algorithm> 
using namespace std;

int v[100001];

int main(void) 
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&v[i]);
	}
	
	sort(v,v+n);
	
	scanf("%d",&m);
	
	for(int i=0; i<m; i++) {
		int a;
		scanf("%d",&a);
		if(binary_search(v,v+n,a))	printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}
