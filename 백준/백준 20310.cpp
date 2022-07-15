#include <iostream>
#include <string>

using namespace std;


int main(void)
{
	string str,answer;	
	cin >> str;
	
	for(int i=0; i<str.length()/4; i++) {
		answer = answer + '0';
	} 
	for(int i=0; i<str.length()/4; i++) {
		answer = answer + '1';
	} 
	
	cout << answer;
	return 0;
}
