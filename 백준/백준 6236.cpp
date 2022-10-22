#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void)
{
	int n,m;
	cin >> n >> m;
	int max_tmp = -1;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		max_tmp = max(max_tmp,tmp);
	} 
	
	long long l = 1;
	long long r = 2000000001;
	
	long long result = 2000000001;
	
	while(l<=r) {
		long long mid = (l+r) / 2;
		long long price = 0;
		long long cnt = 1;
		price = price + mid;
		
		if(mid < max_tmp) {
			l = mid + 1;
			continue;
		}
		
		for(int i=0; i<n; i++) {
			if(price >= v[i]) {
				price = price - v[i];
			}
			else if(price < v[i]){
				price = mid;
				cnt++;
				i--;
			}
		}
		
		if(cnt > m) {
			l = mid + 1;
		}
		else if(cnt <= m) {
			result = min(result,mid);
			r = mid - 1;
		}
	}
	cout << result;
	
	return 0;
}
