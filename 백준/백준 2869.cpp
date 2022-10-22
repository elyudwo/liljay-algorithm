#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	double a,b,v;
	cin >> a >> b >> v;
	
	long long cnt = ceil((v-a) / (a-b));
	
	if(a == v) {
		cout << "1";
		return 0;
	}
	
	if(cnt == 0) {
		cout << "2";
		return 0;
	}
	
	
	cout << cnt+1;
	
	return 0;
}
