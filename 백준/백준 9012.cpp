#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	while(n--) {
		stack<char> s;
		bool check = false;
		string str;
		cin >> str;
		for(int i=0; i<str.length(); i++) {
			if(str[i] == '(') {
				s.push('(');
			}
			else if(str[i] == ')') {
				if(s.empty()) {
					cout << "NO" << endl;
					check = true;
					break;
				}
				else {
					s.pop();
				}
			}
		}
		
		if(s.size() != 0 && !check) {
			cout << "NO" << endl;
		}
		else if(s.size() == 0 && !check){
			cout << "YES" << endl;
		}
		
		
	}
	
	
	return 0;
}
