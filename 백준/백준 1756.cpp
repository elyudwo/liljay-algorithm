#include <iostream>
#include <vector>

using namespace std;

vector<int> oven;
vector<int> pizza;

int main() {
	int d,n;
	int tmp = 0;
	int result = 0;
	int lee = 0;
	cin >> d >> n;

	cin >> tmp;
	oven.push_back(tmp);
	
	for(int i=1; i<d; i++) {
		cin >> tmp;
		if(tmp > oven[i-1]) {
			oven.push_back(oven[i-1]);	
		}
		else {
			oven.push_back(tmp);
		}
	}
	
	for(int i=0; i<n; i++) {
		cin >> tmp;
		pizza.push_back(tmp);
	}
	
	for(int i=oven.size()-1; i>=0; i--) {
		if(pizza[lee] <= oven[i]) {
			if(lee == pizza.size()-1) {
				result = i + 1;
				break;
			}
			else {
				lee++;
			}
		}
	}
	
	cout << result;
	return 0;
}
