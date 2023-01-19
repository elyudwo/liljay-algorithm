#include <iostream>

using namespace std;

void checkString(string str) {
	bool check = true;
	bool checkMo = false;
	int continueMo = 0;
	int continueZa = 0;
	char rem;
	
	for(int i=0; i<str.length(); i++) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ) {
			continueMo++;
			checkMo = true;
			continueZa = 0;
		}
		else {
			continueZa++;
			continueMo = 0;
		}
		if(continueMo >= 3 || continueZa >= 3) {
			check = false;
			break;
		}
		
		if(i != str.length()-1 && str[i] == str[i+1]) {
			if( !(str[i] == 'e' || str[i] == 'o') ) {
				check = false;
				break;
			}
		}
	}
	
	
	if(!checkMo) { check = false; }
	
	if(check) { cout << "<" << str << ">" << " is acceptable." << "\n"; }
	else { cout << "<" << str << ">" << " is not acceptable." << "\n"; }
}


int main() {
	while(1) {
		string str;
		cin >> str;
		if(str == "end") { break; }
		checkString(str);
	}
		
}
