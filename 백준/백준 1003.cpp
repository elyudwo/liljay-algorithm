#include <iostream>

using namespace std;

int dp_zero[41];
int dp_one[41];
int main(void)
{
	int t;
	cin >> t;
	
	dp_zero[0] = 1;	dp_one[0] = 0;
	dp_zero[1] = 0; dp_one[1] = 1;
	dp_zero[2] = 1; dp_one[2] = 1;
	dp_zero[3] = 1; dp_one[3] = 2;
	dp_zero[4] = 2; dp_one[4] = 3;
	
	for(int i=5; i<=41; i++) {
		dp_zero[i] = dp_zero[i-2] + dp_zero[i-1];
		dp_one[i] = dp_one[i-2] + dp_one[i-1];
	}
	
	
	while(t--) {
		int n;
		cin >> n;
		
		cout << dp_zero[n] << " " << dp_one[n] << endl;
	}
	
	return 0;
}
