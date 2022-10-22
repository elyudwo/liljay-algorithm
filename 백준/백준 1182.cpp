#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int n,s;
bool check[21];
int result = 0;

void dfs_combination(int x,int cnt,int k)
{
	if(cnt == k) {
		int sum = 0;
		for(int i=0; i<n; i++) {
			if(check[i]) {
				sum = sum + vec[i];
			}
		}
		if(sum == s) {
			result++;
		}
		return;
	}
	
	for(int i=x; i<n; i++) {
		if(check[i])	continue;
		check[i] = true;
		dfs_combination(i,cnt+1,k);
		check[i] = false;
	}
}


int main(void)
{
	cin >> n >> s;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	for(int i=1; i<=n; i++) {
		dfs_combination(0,0,i);
	}
	
	cout << result;
	
	return 0;
}
