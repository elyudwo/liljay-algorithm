#include <iostream>
#include <cmath> 
#include <string>
#include <algorithm>
using namespace std;

string result;

int main(void)
{
	int k;
	cin >> k;

	int i=1;
	int sum = 0;
	while(1) {
		int tmp = sum;
		sum = sum + pow(2,i);
		if(sum > k) {
			sum = sum - tmp; 
			break;
		}
		else if(sum == k) {		// 자릿수중 마지막 수는 전부다 7 
			for(int j=0; j<i; j++) {
				result = result + '7';
			}
			cout << result;
			return 0;
		}
		else {
			i++;
		}
	}
	
	for(int j=0; j<i; j++) {
		result = result + '4';
	}
	
	bool check = false;
	while(1) {
		if(sum == 1) {
			break;
		}
		for(int j=1; j<31 ; j++) {
			if(pow(2,j) > sum) {
				result[j-1] = '7';
				sum = sum - pow(2,j-1);
				break;
			}
			else if(pow(2,j) == sum) {
				for(int k=0; k<j; k++) {
					result[k] = '7';
				}
				break;
				check = true;
			}
			
		}
		if(check)	break;
		
	}
	
	reverse(result.begin(),result.end());
	cout << result;
	
	return 0;
}
