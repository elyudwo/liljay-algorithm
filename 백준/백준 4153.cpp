#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	while(1) {
		int v[3];
		cin >> v[0] >> v[1] >> v[2];
		if(v[0] == 0 && v[1] == 0 && v[2] == 0)	break;
		sort(v,v+3);
		
		if(v[0] * v[0] + v[1]*v[1] == v[2] * v[2]) {
			cout << "right" <<endl;
		}
		else {
			cout << "wrong" << endl;
		}
		
	}
	
	return 0;
}
