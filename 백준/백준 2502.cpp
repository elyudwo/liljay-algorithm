#include <iostream>
#include <vector>

using namespace std;

int dp[31];

vector<pair<int,int> > v;

int main(void)
{
	int d,k;
	cin >> d >> k;
	
	v.push_back({1,0});	// a,b
	v.push_back({0,1});
	
	for(int i=2; i<=d; i++) {
		int a,b;
		a = v[i-1].first + v[i-2].first;
		b = v[i-1].second + v[i-2].second;
		v.push_back({a,b});
	}
	
	int a_cnt = v[d-1].first;
	int b_cnt = v[d-1].second;
	
	
	int a,b = 1;
	
	int sum;
	
	while(1) {
		sum = a * a_cnt + b * b_cnt;
		if(sum == k) {
			cout << a << endl << b;
			break;
		}
		
		if(a < b) {
			a++;
		}
		else {
			b++;
			a = 1;
		}
		
	}
	
	
	return 0;
}
