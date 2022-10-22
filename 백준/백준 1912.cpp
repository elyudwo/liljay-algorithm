#include <iostream>
#include <cmath>

using namespace std;
int v[100001];
int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	int sum = 0;
	int result=-999999999;
	
	sum = v[0];
	result = sum;
	
	for(int i=1; i<n; i++) {
		if(v[i] < 0 && sum < 0 && abs(sum) >= abs(v[i])) {
			sum = v[i];
		}
		else if(v[i] < 0 && sum < 0 && abs(sum) < abs(v[i])) {
			continue;
		}
		else if(v[i] < 0 && sum <= abs(v[i])) {
			sum = 0;
		}
		else if(v[i] >= 0 && sum < 0) {
			sum = v[i];
		}
		else {
			sum = sum + v[i];
		}
		if(result < sum)	result = sum;
		
	}
	
	cout << result;
	
	return 0;
}
