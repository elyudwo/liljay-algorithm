#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	
	while(1) {
		string str;
		cin >> str;
		
		if(str == "0") {
			break;
		}
		
		string lee = str;
		
		reverse(str.begin(),str.end());
		
		if(lee == str) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	
	return 0;
}
