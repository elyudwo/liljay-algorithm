#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int cnt = 0;
	int rem = 0;
	
	for(int i=1; i<=str.length()/2; i++) {
		for(int j=0; j<str.length(); j++) {
			string tmp1,tmp2;
			rem = i + j;
			
			if(i + j >= str.length())	break;
			if(rem + i >= str.length())	break;
			
			tmp1 = str.substr(j,j+i);
			tmp2 = str.substr(rem,rem+i-1);
			cout << tmp1 << " " << tmp2 << endl;
			if(tmp1 == tmp2) {
				cnt = i * 2;
			}
		}
	}
	
	cout << cnt;	
	
	return 0;
}
