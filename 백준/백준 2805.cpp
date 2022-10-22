#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> vec;
int answer = 0;

int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	unsigned long long answer = 0;
	sort(vec.begin(),vec.end());
	
	unsigned long long result;
	unsigned long long l = 0;
	unsigned long long r = 200000000000000001;
	
	// ÀÌºÐ Å½»ö 
	while(l<=r) {
		result = (l+r) / 2;
		unsigned long long tmp = 0;
		for(int i=0; i<n; i++) {
			if(result < vec[i]) {
				tmp = tmp + vec[i] - result;
			}
		}
		if(tmp >= m) {
			answer = max(answer,result);
			l = result+1;
		}
		else {
			r = result-1;
		}
	}
	
	cout << answer;
	return 0;
}
