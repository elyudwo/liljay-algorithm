#include <iostream>
#include <vector>

using namespace std;

int n;
bool c[100001];
int p[100001]; 
vector<int> v[100001];

void dfs(int n) 
{
	if(c[n])	return;
	c[n] = true;
	
	for(int i=0; i<v[n].size(); i++) {
		if(!c[v[n][i]]) {
			p[v[n][i]] = n;
			dfs(v[n][i]);	
		}
		
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
	cin >> n;

	for(int i=0; i<n-1; i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1);
	
	for(int i=2; i<=n; i++) {
		cout << p[i] << "\n";
	}

	return 0;
}
