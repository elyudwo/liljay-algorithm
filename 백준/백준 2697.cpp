#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int asd = 0;
int qwe = 0;
int main(void)
{
	int t;
	cin >> t;
	int min_tmp = 9999;
	int rem;
	for(int i=0; i<t; i++) {
		int v[81];
		string str;
		cin >> str;
		for(int j=0; j<str.length(); j++) {
			v[j] = str[j] - '0';
		}
		
		for(int i=str.length()-1; i>0; i--) {
			if(v[i-1] >= v[i]) {
				continue;	
			}
			else if(v[i-1] < v[i]){
				for(int j=i; j<str.length(); j++) {
					if(v[j] > v[i-1]) {
						if(min_tmp < v[j]) {
							rem = j;
						}
					}
				}
				int tmp = v[i-1];
				v[i-1] = v[rem];
				v[rem] = tmp;
				
				sort(v+i,v+str.length());
				break;
			}
		}
		for(int i=0; i<str.length(); i++) {
			cout << v[i];
		}
	} 
	
	return 0;
}
