#include <iostream>
#include <cmath>
using namespace std;

int n;

double calculateDist(double x1, double y1, double x2, double y2) {
	double xDiff = abs(x2 - x1);
	double yDiff = abs(y2 - y1);
	
	return sqrt(pow(xDiff,2) + pow(yDiff,2));
}

int main() {
	cin >> n;
	
	while(n--) {
		double x1,y1,r1,x2,y2,r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		double diff = calculateDist(x1, y1, x2, y2);
		
		double large = max(r1, r2);
		double small = min(r1, r2);
		
		if(x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1" << '\n';
			continue;
		}
		
		if(r1 + r2 == diff) {
			cout << "1" << '\n';
			continue;
		}
		
		if(r1 + r2 < diff || large > small + diff) {
			cout << "0" << '\n';
			continue;
		}
		
		if(large == small + diff) {
			cout << "1" << '\n';
			continue;
		}
		cout << "2" << '\n';
		
		
	}
}