#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int sum = 0;
	
	for(int i=0; i<n; i++) {
		if(i == n-1) {
			cout << 0;
			break;
		}
		int a = i;
		string str = to_string(a);
		for(int i=0; i<str.size(); i++) {
			sum = sum + (str[i] - '0');
		}
		sum = sum + i;
		
		if(sum == n) {
			cout << sum;
			break;
		}
		
		
	}
	
	
}
