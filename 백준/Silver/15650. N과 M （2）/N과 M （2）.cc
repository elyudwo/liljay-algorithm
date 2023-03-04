#include <iostream>
#include <vector>
using namespace std;
int n,m;

bool check[9];

void dfs(int x,int y) 
{
	if(y == m) {
		for(int i=1; i<=n; i++) {
			if(check[i] == true) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	
	for(int i=x; i<=n; i++) {
		if(check[i])	continue;
		check[i] = true;
		
		dfs(i,y+1);
		check[i] = false;
	}
	
}

int main(void)
{
	cin >> n >> m;
	
	dfs(1,0);	
		
	return 0;
}