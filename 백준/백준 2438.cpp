#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		string str;
		for(int j=1; j<=i; j++) {
			str = str + '*';
		}
		for(int k=4;k>=i; k--) {
			cout << " ";
		}
		cout << str << endl;
	}
	
	return 0;
}
