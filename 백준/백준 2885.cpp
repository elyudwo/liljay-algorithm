#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int k;
	cin >> k;
	int i = 0;
	int sum = 0;
	int rem;
	while(1) {
		if(pow(2,i) >= k) {
			i = pow(2,i);
			rem = i;
			break;
		}
		i++;
	}
	int spl = 0;
	while(1) {
		if(sum == k) {
			break;
		}
		else {
			if(sum+i <= k) {
				sum = sum + i;
			}
			else {
				i = i/2;
				spl++;	 
			}
			
		}
	}
	
	cout << rem << " " << spl;
	
	return 0;
}
