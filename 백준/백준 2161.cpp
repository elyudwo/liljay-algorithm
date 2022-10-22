#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		v.push_back(i+1);
	}
	
	while(1) {
		cout << v[0] << " ";
		v.erase(v.begin());
		if(v.empty()) {
			break;
		}
		
		int tmp = v[0];
		v.erase(v.begin());
		v.push_back(tmp);
		
	}
	
	
	
	return 0;
}
