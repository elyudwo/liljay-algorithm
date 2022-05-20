#include <iostream>

using namespace std;

int main(void)
{
	int h,w;
	cin >> h >> w;
	
	string str[101];
	
	for(int i=0; i<h; i++) {
		cin >> str[i];
	}
	
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			if(str[i][j] == 'c') {
				cout << "0" << " ";
			}
			else {
				int k = j;
				int cnt = 0;
				while(1) {
					if(k == -1) {
						cout << "-1" << " ";
						break;
					}
					
					if(str[i][k] == 'c') {
						cout << cnt << " ";
						break;
					}
					else {
						cnt++;
						k--;
					}
					
					
					
				}
			}
		}
		cout << endl; 
	}
	
	
	
	return 0;
}
