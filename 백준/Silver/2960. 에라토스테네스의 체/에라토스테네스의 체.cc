#include <iostream>

using namespace std;

bool check[1001]; 

int main() {
	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	for(int i=2; i<=n; i++) {
		for(int j=i; j<=n; j=j+i) {
			if(!check[j]) {
				check[j] = true;
				cnt++;
				if(cnt == k) {
					cout << j;
					return 0;
				}
			}
		}
	}
}