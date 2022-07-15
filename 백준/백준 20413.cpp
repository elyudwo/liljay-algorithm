#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	string str;
	
	cin >> n;
	int v[4];
	cin >> v[0] >> v[1] >> v[2] >> v[3];
	cin >> str;
	int sum = 0;
	int rem = 0;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == 'B') {
			sum = sum + v[0] - 1 - rem;
			rem = v[0] - 1 - rem;
		}
		else if(str[i] == 'S') {
			sum = sum + v[1] - 1 - rem;
			rem = v[1] - 1 - rem;
		}
		else if(str[i] == 'G') {
			sum = sum + v[2] - 1 - rem;
			rem = v[2] - 1 - rem;
		}
		else if(str[i] == 'P') {
			sum = sum + v[3] - 1 - rem;
			rem = v[3] - 1 - rem;
		}
		else if(str[i] == 'D') {
			sum = sum + v[3];
		}
	}
	
	cout << sum;
	
	return 0;
}
