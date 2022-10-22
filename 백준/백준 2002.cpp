#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check[1001];

int main(void)
{
	int n;
	cin >> n;
	
	map<string,int> ma;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		ma[str] = i;
	}
	
	int tmp = 1;
	int result = 0;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		
		if(tmp == ma[str]) {
			tmp++;
			while(1) {
				if(check[tmp]) {
					check[tmp] = true;
					tmp++;
				}	
				else break;
			}
		}
		else if(tmp < ma[str]) {
			result++;
			check[ma[str]] = true;
		}
	}
	
	cout << result;
	
	return 0;
}
