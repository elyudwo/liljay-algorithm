#include <iostream>
	
using namespace std;
	
int main() {
	string s,t;
	while(cin >> s >> t) {
		int index = 0;
		
		bool check = false;
		
		for(int i=0; i<t.size(); i++) {
			if(t[i] == s[index]) { index++; }
			if(index == s.size()) {
				check = true;
				break;
			}
		}
		
		if(check) { cout << "Yes"; }
		else { cout << "No"; }
		cout << '\n';
	}
}	