#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int v[101];
bool c[101];

vector<int> lee;

void dfs(int x,int y)
{
	if(!c[y]) {
		c[y] = true;
		dfs(x,v[y]);
	}
	else if(y == x) {
		lee.push_back(x);
		return;
	}
	
	
}

int main(void)
{	
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	for(int i=1; i<=n; i++) {
		dfs(i,i);
		memset(c,false,sizeof(c));
	}
	
	cout << lee.size() << endl;
	for(int i=0; i<lee.size(); i++) {
		cout << lee[i] << endl;
	}
	
	return 0;
}
