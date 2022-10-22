#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int> ma;

int main(void)
{
	int n;
	cin >> n;
	int result = -1;
	string str = "";
	for(int i=0; i<1000; i++) {
		str = str + "z";
	}
	
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		ma[tmp]++;
		if(ma[tmp] > result) {
			result = ma[tmp];
			str = tmp;
		}
		else if(ma[tmp] == result) {
			if(str > tmp) {
				str = tmp;
			}
		}
	}
	
	cout << str;
	
	return 0;
}
