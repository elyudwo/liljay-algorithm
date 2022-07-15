#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check[8];
int n,m;
vector<int> v;

void print() {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

void dfs(int cnt)
{
	if(cnt == m) {
		print();
		return;
	}
	
	for(int i=1; i<=n; i++) {
		if(check[i])	continue;
		check[i] = true;
		v.push_back(i);
		dfs(cnt+1);
		v.pop_back();
		check[i] = false;
	}
	
}


int main(void)
{
	cin >> n >> m;
	
	dfs(0);
	return 0;
}
