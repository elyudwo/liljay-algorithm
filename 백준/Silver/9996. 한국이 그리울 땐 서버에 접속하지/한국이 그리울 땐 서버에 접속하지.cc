#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int cnt_first = 0;
	int cnt_last = 0;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '*') {
			break;
		}
		else {
			cnt_first++;
		}
	}
	
	for(int i=str.length()-1; i>=0; i--) {
		if(str[i] == '*') {
			break;
		}
		else {
			cnt_last++;
		}
	}
	
	
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		bool check = false; 
		
		if(str.length()-2>=s.length()) {
			cout << "NE" << endl;
			continue;
		}
		
		
		for(int j=0; j<cnt_first; j++) {
			if(str[j] != s[j]) {
				cout << "NE" << endl;
				check = true;
				break;
			}
		}
		if(check) continue;
		
		int a1 = str.length() - 1;
		int a2 = s.length() - 1;
		
		for(int i=0; i<cnt_last; i++) {
			if(str[a1] != s[a2]) {
				cout << "NE" << endl;
				check = true;
				break;
			}
			else {
				a1--;
				a2--;
			}
		}
		
		
		if(check)	continue;
		
		cout << "DA" << endl;
	}
	
	
	return 0;
}