#include <iostream>

using namespace std;

int v[151];
bool check[151];
int main(void)
{
	int n,k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		v[i] = a;
	}
	
	
	
	check[0] = true;
	bool lee = false;
	int cnt = 1;
	int tmp = v[0];
	
	for(int i=0; i<n; i++) {
		if(tmp == k) {
			lee = true;
			break;
		}
		else if(!check[tmp]) {
			check[tmp] = true;
			cnt++;
			tmp = v[tmp];
		}
	}
	
	if(lee) {
		int hello = 1;
		tmp = v[0];
		while(1) {
			if(tmp == k) {
				break;
			}
			hello++;
			tmp = v[tmp];
			
		}
		cout << hello;
	}
	else {
		cout << "-1";
	}
	
	return 0;
}
