#include <iostream>
#include <vector>
#include <algorithm>
#define INF 5000000000000 
using namespace std;

typedef long long ll;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		ll sum[4001] = {0,};
		ll answer = 0;
		vector<ll> vec;
		cin >> n;
		
		for(int i=0; i<n; i++) {
			ll tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		
		sort(vec.begin(), vec.end());
		
		sum[0] = vec[0];
		
		for(int i=1; i<vec.size(); i++) {
			sum[i] = sum[i-1] + vec[i];
		}
		
		for(int i=2; i<vec.size(); i++) {
			ll tmp = INF;
			
			tmp = min(tmp, vec[i-1] * i - sum[i-1]);
//			cout << tmp << "   ";
			for(int j=i; j<vec.size(); j++) {
				tmp = min(tmp, vec[j] * i - (sum[j] - sum[j-i]));
//				cout << tmp << "  ";
			
			}
			
			answer += tmp;
//			cout << answer << endl;
		}
		
		ll max_value = vec[vec.size()-1];
		answer += max_value * n - sum[vec.size()-1];
		
		cout << answer << '\n';
	}
}