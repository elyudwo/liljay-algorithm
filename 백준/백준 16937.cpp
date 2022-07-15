#include <iostream>
#include <vector>
using namespace std;
int n,m;

bool check[9];
int y = 3;

void print() 
{
	for(int i=1; i<=5; i++) {
			if(check[i]) {
				cout << i << " ";
			}
		}
	cout << endl;
}

void dfs(int x,int cnt) {
	if(cnt == 3) {
		print();
		return;
	}	
	
	for(int i=x; i<=5; i++) {
		if(check[i])	continue;
		check[i] = true;
		dfs(i,cnt+1);
		check[i] = false;
	}
	
}
int main(void)
{
	dfs(1,0);	
	return 0;
}
