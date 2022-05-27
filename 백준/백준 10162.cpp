#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	
	int sum = t;
	
	int cnt[3] = {0,};
	
	if(t%10 != 0) {
		cout << "-1";
	}
	else {
		while(1) {
			if(sum == 0) {
				for(int i=0; i<3; i++) {
					cout << cnt[i] << " ";
				}
				break;
			}
			else if(sum >= 300) {
				sum = sum - 300;
				cnt[0]++;
			}
			else if(sum >= 60) {
				sum = sum -60;
				cnt[1]++;
			}
			else if(sum >= 10) {
				sum = sum -10;
				cnt[2]++;
			}
		}
	}
	
	return 0;
}
