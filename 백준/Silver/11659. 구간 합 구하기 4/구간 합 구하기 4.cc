#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int arr[100001] = {0,};
int sum[100001] = {0,};

int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&arr[i]);
		sum[i] = sum[i-1] + arr[i];
	}
	
	for(int i=0; i<m; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n", sum[b] - sum[a-1]);
	}
	
}