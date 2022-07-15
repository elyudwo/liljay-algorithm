#include <iostream>
#include <string>
using namespace std;

char v[1001];

int main(void)
{
	int t,n;
	cin >> t;
	
	for(int i=0; i<t; i++) {
		string str;
		cin >> n;
		for(int j=0; j<n; j++) {
			cin >> v[j];
		}
		str = str + v[0];
		
		for(int j=1; j<n; j++) {
			int a,b;
			a = int(str[0] - 'A');
			b = int(v[j] - 'A');
			
			if(a >= b) {
				string lee;
				lee+= v[j];
				str.insert(0,lee);
			}
			else if(a < b) {
				str = str + v[j];
			}
		}
		cout << str << endl;
	}
	
	return 0;
}
