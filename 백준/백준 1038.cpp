#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result = -1;
int n,k;
vector<int> rem;
vector<int> v;

void dfs_permutation(int cnt,int y)
{
	if(cnt == y) {
		string tmp;
		for(int i=0; i<rem.size(); i++) {
			tmp = tmp + to_string(rem[i]);
		}
		
		int t = stoi(tmp);
		if(t <= n) {
			result = max(result,t);
		}
		return;
	}
	
	for(int i=0; i<v.size(); i++) {
		rem.push_back(v[i]);
		dfs_permutation(cnt+1,y);
		rem.pop_back();
	}
	
}


int main(void)
{
	cin >> n >> k;
	
	string str = to_string(n);
	
	for(int i=0; i<k; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(),v.end());
	
	dfs_permutation(0,str.length());
	dfs_permutation(0,str.length()-1);
	
	cout << result;
	
	return 0;
}
