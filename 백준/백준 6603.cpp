#include <iostream>
#include <algorithm>

using namespace std;

bool check[14];
int n;
int v[14];

void dfs_permutation(int x,int cnt) 
{
	if(cnt == 6) {
		for(int i=0; i<n; i++) {
			if(check[i]) {
				cout << v[i] << " ";
			}
		}
		cout << endl;
	}
	
	for(int i=x; i<n; i++) {
		if(check[i])	continue;
		check[i] = true;
		dfs_permutation(i,cnt+1);
		check[i] = false;
	}
	
}

int main(void)
{
	while(1) {
		cin >> n;
		if(n == 0) {
			break;
		}
		for(int i=0; i<n; i++) {
			cin >> v[i];
		}
		
		dfs_permutation(0,0);
		cout << endl;
		
		for(int i=0; i<n; i++) {
			v[i] = 0;
			check[i] = false;
		}
		
	}
	
	return 0;
}
