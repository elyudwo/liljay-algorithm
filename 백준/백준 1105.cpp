#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string l,r;
	cin >> l >> r;
	
	int cnt = 0;
	
	if(l.length() != r.length()){
		cout << '0';
		return 0;
	}
		
	

	for(int i=0; i<l.length(); i++) {
		if(l[i] == r[i] && l[i] == '8')
			cnt++;
		else
			break;
		}
	
	
	cout << cnt;
	
	
	return 0;
}
