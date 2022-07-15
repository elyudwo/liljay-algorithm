#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		string str,ans;
		cin >> str;
		int cnt = 0;
		do {
			ans = str;
			if(++cnt == 2) {
				break;
			}
		}while(next_permutation(str.begin(),str.end()));
		cout << ans << endl;
	}
	
	
	return 0;
}
