#include <iostream>

using namespace std;

int arr_x[31];
int arr_y[31];

int x = 1;
int y = 1;

int main() {
	int d,k;
	cin >> d >> k;
	arr_x[1] = 1; arr_x[2] = 0;
	arr_y[1] = 0; arr_y[2] = 1;
	
	for(int i=3; i<=d; i++) {
		arr_x[i] = arr_x[i-2] + arr_x[i-1];
		arr_y[i] = arr_y[i-2] + arr_y[i-1];
	}
	
	// 3, 5
	int left = 1;
	int right = 1;
	
	while(1) {
		if(arr_x[d] * left + arr_y[d] * right == k) {
			cout << left << '\n' << right;
			break;
		}
		
		if(arr_x[d] * left + arr_y[d] * right > k) {
			right--;
			left++;
		}
		else {
			right++;
		}
	}
}