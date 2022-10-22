#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

string str[100001];
int v[100001];

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	
	for(int i=0; i<n; i++) {
		cin >> str[i] >> v[i];		
	}
	
	for(int i=0; i<m; i++) {
		int a;
		scanf("%d",&a);
		int left = 0, right = n-1;
		int mid = 0;
		while(left <= right) {
			mid = (left+right) / 2;
			if(a <= v[mid]) 
				right = mid -1;
			else 
				left = mid + 1;
		}
		if(a > v[mid])
			printf("%s\n",str[mid+1].c_str());
		else 
			printf("%s\n",str[mid].c_str());
	}
	
	return 0;
}
