#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;

int n;
vector<int> vec;
vector<int> rem;
int result = 0;
bool check[9];
void dfs_permutation(int cnt)
{
	if(rem.size() == n) {
		int tmp = 0;
		for(int i=0; i<n-1; i++) {
			tmp = tmp + fabs(rem[i] - rem[i+1]);
		}
		
		result = max(result,tmp);
		return;
	}
	
	for(int i=0; i<n; i++) {
		if(check[i])	continue;
		check[i] = true;
		rem.push_back(vec[i]);
		dfs_permutation(cnt+1);
		rem.pop_back();
		check[i] = false;
	}
	
}

int main(void)
{
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	dfs_permutation(0);
	
	cout << result;
	
	return 0;
}
