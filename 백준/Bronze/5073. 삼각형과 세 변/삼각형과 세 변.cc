#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	while(1) {
		int a,b,c;
		cin >> a >> b >> c;
	
		if(a == 0 && b == 0 && c == 0) { break; }
		vector<int> vec;
		
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
				
		sort(vec.begin(), vec.end());
		if(vec[0] + vec[1] <= vec[2]) {
			cout << "Invalid\n";
			continue;
		}
		
		if(vec[0] == vec[1] && vec[1] == vec[2]) {
			cout << "Equilateral\n";
			continue;
		}
		if(vec[0] == vec[1] || vec[0] == vec[2] || vec[1] == vec[2]) {
			cout << "Isosceles\n";
			continue;
		}
		cout << "Scalene\n";
		
	}
}