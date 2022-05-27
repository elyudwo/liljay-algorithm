#include <iostream>
#include <algorithm>
using namespace std;


int main(void)
{
	int a,b;
	cin >> a >> b;
	
	int v[a];
	
	for(int i=0; i<a; i++) {
		cin >> v[i];
	}
	
	sort(v,v+a);
	
	int tall = b;
	
	for(int i=0; i<a; i++) {
		if(tall>=v[i]) {
			tall = tall + 1;
		}
		else {
			break;
		}
	}
	
	cout << tall;
	
	return 0;
}
