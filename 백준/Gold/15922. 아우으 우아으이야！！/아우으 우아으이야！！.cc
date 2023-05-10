#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int sum = 0;
	
	int left;
	int right;
	
	cin >> left >> right;
	if(n == 1) {
		cout << right - left;
		return 0;
	}
	for(int i=1; i<n; i++) {
		int a,b;
		cin >> a >> b;
		
		if(i == n-1) {
			if(a > right) {
				sum += right - left; 
				sum += b-a;
			}
			else if(b > right) {
				right = b; 
				sum += b-left;
			}
			else { sum += right - left; }
		}
		else {
			if(a > right) {
				sum += right - left; 
				left = a;
				right = b;
			}
			else if(b > right) { right = b; }
		}	
	}
	
	cout << sum;
	
}