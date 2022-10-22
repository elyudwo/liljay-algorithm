#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int n,final;
int result = 10001;

vector<pair<int,int> > v;
vector<int> price;

//지름길을 타는경우와 안타는 경우 완전탐색 

void dfs(int x,int sum)
{
	for(int i=0; i<v.size(); i++) {
		if(x > v[i].first) {
			continue;
		}
		sum = sum + v[i].first - x;

		dfs(v[i].second,sum + price[i]);
		dfs(v[i].second,sum + v[i].second - v[i].first);
	}
	
	if(x > final) {
		return;
	}
	if(x < final) {
		sum = sum + final-x;
	}
	
	if(result > sum) {
		result = sum;
		return;
	}
	
}


int main(void)
{
	cin >> n >> final;
	for(int i=0; i<n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back({a,b});
		price.push_back(c);
	}
	sort(v.begin(),v.end());
	
	dfs(0,0);
	cout << result;
	
	return 0;
}
