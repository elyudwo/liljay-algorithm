#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while(t--) {
		int x1,y1,r1,x2,y2,r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double sum = 0;
		sum = sqrt(fabs((x2 - x1) * (x2 - x1)) + fabs((y2 - y1) * (y2 - y1)));
		if(sum == 0) {
			if(r1 == r2) {
				cout << "-1" << endl;
				continue;
			}
			else {
				cout << "0" << endl;
				continue;
			}
		}
		else if(sum == r1 + r2){
			cout << "1" << endl;
		}
		else if(sum >= fabs(r1-r2) && sum <= fabs(r1 + r2)){
			cout << "2" << endl;
		}		
	}
	
	return 0;
}
