#include <iostream>

using namespace std;

int n;
int arr[1000002];

int main() {
	cin >> n;
	int answer = 0;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		
		if(arr[tmp+1]) {
			arr[tmp+1]--;
			arr[tmp]++;
			continue;
		}
		
		arr[tmp]++;
	}
	
	for(int i=0; i<=1000000; i++) {
		if(arr[i]) { answer += arr[i]; }
	}
	
	cout << answer;
}