#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int dp[100001];

int main(void)
{
	int n,k;
	cin >> n >> k;
	vector<pair<int,int> > v;
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	 
	for(int i=0; i<n; i++) {
		int rem[100001] = {0,};
		for(int j=0; j<=k; j++) {
			rem[j] = dp[j];
		}
		for(int j=0; j<100001; j++) {
			if(j + v[i].first <= k) {
				dp[j+v[i].first] = max(rem[j] + v[i].second,dp[j+v[i].first]);	
			}
			else if(j + v[i].first > k)	break;
		}
		for(int j=0; j<=k; j++) {
			cout << dp[j] << " ";
		}
		cout << endl;
	} 
	
	int max_value = -1;
	
	for(int i=0; i<=k; i++) {
		max_value = max(max_value,dp[i]);
	}
	
	cout << max_value;
	
	return 0;
}
