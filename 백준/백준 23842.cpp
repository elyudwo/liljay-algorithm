#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int v[10] = {6,2,5,5,4,5,6,3,7,6};
	
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				for(int q=0; q<10; q++) {
					if((v[i] + v[j] + v[k] + v[q] + v[(10*i + j + 10 * k + q) / 10] +v[(10*i + j + 10 * k + q) % 10] == n-4)) {
						if((10*i + j + 10 * k + q) > 99) continue;
						
						cout << i << j << "+" << k << q << "=" <<
						 (10*i + j + 10 * k + q)/10 <<(10*i+j+10*k+q) %10;
						return 0;
					}
				}
			}
		}	
	}
	
	cout << "impossible";
	
	
}
