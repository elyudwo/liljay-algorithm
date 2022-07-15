#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,long long>> v; 

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main(void)
{
	long long n,m,k;
	cin >> n >> m >> k;
	
	for(int i=0; i<k; i++) {
		int a;
		long long b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	long long sum = 0;
	
	sort(v.begin(),v.end(),cmp);
	
	
	
	
	return 0;
}
