#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	m = m - 45;
	if(m < 0) {
		if(n == 0) {
			n = 23;
			m = 60 + m;
		}
		else {
			n--;
			m = 60 + m;
		}
	}
	
	cout << n << " " << m;
	
	return 0;
}
