#include <iostream>

using namespace std;

long long arr[10001][3];



int main() {
	int t;
	cin >> t;
	
	arr[1][1] = 1;
	arr[2][1] = 1; arr[2][2] = 1;
	arr[3][1] = 1; arr[3][2] = 1; arr[3][3] = 1;
	
	for(int i=4; i<=10000; i++) {
		arr[i][1] = arr[i-1][1];
		arr[i][2] = arr[i-2][1] + arr[i-2][2];
		arr[i][3] = arr[i-3][1] + arr[i-3][2] + arr[i-3][3];
	}
	
	while(t--) {
		int tmp;
		cin >> tmp;
		cout << arr[tmp][1] + arr[tmp][2] + arr[tmp][3] << '\n';
	}
}