#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	
	int result = 0;
	int pole = 0;
	int razer = 0;
	
	for(int i=0; i<str.length(); i++) {
		if(i<str.length()-1 && str[i] == '(' && str[i+1] == ')') {
			result = result + pole;
			i++;
		}
		else if(str[i] == '(') {
			pole++;
		}
		else if(str[i] == ')') {
			pole--;
			result = result + 1;
		}
	}
	cout << result;
	
	return 0;
}
