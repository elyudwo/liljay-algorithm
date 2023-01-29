#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int> ma;

int stringToInt(string str) {
	int result = 0;
	for(int i=0; i<str.size(); i++) {
		result = result + (str[i] - '0') * (str[i] - '0');
	}
	return result;
}

void solve() {
	string n;
	cin >> n;
	ma[n] = 1;
	
	if(n == "1") {
		cout << "HAPPY";
		return;
	}
	
	while(1) {
	    int rem;
		rem = stringToInt(n);
		n = to_string(rem);
		if(ma[n] == 1) {
			cout << "UNHAPPY";
			break;
		}
		if(rem == 1) {
			cout << "HAPPY";
			break;
		}
		ma[n] = 1;
	}
}

int main() {
	solve();
	
	
}