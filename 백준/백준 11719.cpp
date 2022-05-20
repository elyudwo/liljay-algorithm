#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	for(int i=0; i<100; i++) {
		string str;
		getline(cin,str);
		cout << str << endl;
	}
	
	return 0;
}
