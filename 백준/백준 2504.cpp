#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	
	int sum = 0;
	
	
	int cnt = 1;
	bool small = false;
	bool middle = false;
	
	int small_cnt,middle_cnt = 0;
	
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '(') {
			small = true;
			small_cnt += 1;
		}
		else if(str[i] == '[') {
			middle = true;
			middle_cnt += 1;
		}
		else if(str[i] == ']') {
			if(str[i-1] == '(') {
				cout << "0";
				return 0;
			}
			
			if(middle_cnt == 0) {
				cout << "0";
				return 0;
			}
			else {
				middle_cnt -= 1;
			}
		}
		else if(str[i] == ')') {
			if(str[i-1] == '[') {
				cout << "0";
				return 0;
			}
			
			if(small_cnt == 0) {
				cout << "0";
				return 0;
			}
			else {
				small_cnt -= 1;
			}
		}
	}	
	
	
	return 0;
}
