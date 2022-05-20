#include <iostream>

using namespace std;


int main(void)
{
	int t;
	cin >> t;
	
	
	
	for(int i=0; i<t; i++) {
		long long int sum = 1;
		long long int divi = 1;
		int a,b;
		cin >> a >> b;
		
		if(a == 0) {
			cout << 0 << endl;
			continue;
			
		}
		
		for(int i=b; i>b-a; i--) {
			sum = sum * i;
			sum = sum / divi;
			divi++;
		}
		
		cout << sum << endl;
	}
	
	
	return 0;
}
