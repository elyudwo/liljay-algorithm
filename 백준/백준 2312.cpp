#include <iostream>
#include <map>

using namespace std;

void calculate(int tmp) {
	int a = tmp;
	map<int,int> ma;
	while(1) {
		if(a == 1) {
			break;
		}
		for(int i=2; i<100000; i++) {
			if(a % i == 0) {
				a = a / i;
				ma[i]++;
				break;
			}
		}
	}
	map<int,int>::iterator j;
	for(j = ma.begin(); j != ma.end(); j++) {
		cout << j->first << " " << j->second << endl;
	}
	
	
}

int main() {
	int n;
	cin >> n;
	int tmp;
	
	for(int i=0; i<n; i++) {
		cin >> tmp;
		calculate(tmp);	
	}
}
