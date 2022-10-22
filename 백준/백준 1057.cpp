#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n,j,h;
	cin >> n >> j >> h;
	
	int tmp = n/2;
	int round = 1;
	
	if((j <= tmp && h > tmp)) {
		while(1) {
			int sum = pow(2,round);
			if(sum >= n) {
				break;
			}
			round++;
		}
		cout << round;
	}
	else {
		while(1) {
			tmp = tmp / 2;
			if(j <= tmp && h > tmp) {
				while(1) {
					int sum = pow(2,round);
					if(sum >= tmp) {
						break;
					}
					round++;
				}
				break;
			}
		}
		cout << round;
	}
	
	
	
	return 0;
}
