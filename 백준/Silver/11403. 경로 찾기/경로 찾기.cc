#include <iostream>

using namespace std;

int arr[101][101];

int main() {
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(arr[k][j] && arr[i][k]) {
					arr[i][j] = 1;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}