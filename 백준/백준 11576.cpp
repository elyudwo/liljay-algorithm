#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int a,b,m;
	cin >> a >> b;
	cin >> m;
	
	int tmp = 0;
	vector<string> result;
	for(int i=m-1; i>=0; i--) {
		int n;
		cin >> n;
		tmp = tmp + n*pow(a,i);
	}
	
	while(1) {
		int l = tmp % b;
		string str = to_string(l);
		result.push_back(str);
		tmp = tmp / b;
		
		if(tmp == 0) {
			break;
		}
	}
	
	for(int i=result.size()-1; i>=0; i--) {
		cout << result[i] << " ";
	}
	
	return 0;
}
