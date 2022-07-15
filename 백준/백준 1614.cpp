#include <iostream>

using namespace std;

int main(void)
{
	long long n,m;
	cin >> n >> m;
	bool lee = false;
	long long cnt = 0;
	long long sum = 0;
	
	if(n == 1) {
		while(1) {
			if(cnt == m) {
				break;
			}
			else {
				sum = sum + 8;
				cnt++;
			}
		}
	}
	else if(n == 2) {
		while(1) {
			sum = sum + 2;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
			sum = sum + 6;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
		}
	}
	else if(n == 3) {
		sum = sum + 3;
		cnt++;
		if(cnt == m+1) {
			sum--;
			lee = true;
		}
		while(1) {
			if(lee) {
				break;
			}
			sum = sum + 4;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
			sum = sum + 4;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
		}
	}
	else if(n == 4) {
		sum = sum + 4;
		cnt++;
		if(cnt == m+1) {
			sum--;
			lee = true;
		}
		while(1) {
			if(lee) {
				break;
			}
			sum = sum + 2;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
			sum = sum + 6;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
		}
	}
	else if(n == 5) {
		sum = sum + 5;
		cnt++;
		if(cnt == m+1) {
			sum--;
			lee = true;
		}
		while(1) {
			if(lee) {
				break;
			}
			sum = sum + 8;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
			sum = sum + 8;
			cnt++;
			if(cnt == m+1) {
				sum--;
				break;
			}
		}
	}
	
	
	cout << sum;

	return 0;
}
