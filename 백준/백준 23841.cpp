#include <iostream>
#include <string> 
using namespace std;

string str[51];

int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(str[i][j]!='.' && j < m/2) {
				int plus = m/2 - j-1;
				str[i][m/2+plus] = str[i][j];
			}
			else if(str[i][j]!='.' && j >= m/2) {
				int minus = j - m/2 + 1;
				str[i][m/2-minus] = str[i][j];
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		cout << str[i] << endl;
	}
	
	
	return 0;
}
