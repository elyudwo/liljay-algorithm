#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> vec;

void dfs_permutation(int x,int cnt)
{
	if(cnt == m) {
		for(int i=0; i<vec.size(); i++) {
			printf("%d ",vec[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=1; i<=n; i++) {
		vec.push_back(i);
		dfs_permutation(i,cnt+1);
		vec.pop_back();
	}
}


int main(void)
{
	scanf("%d %d",&n,&m);
	
	dfs_permutation(1,0);
	
	return 0;
}