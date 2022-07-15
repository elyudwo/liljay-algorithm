#include <iostream>
#include <string>

using namespace std;

string str[201];
int v[201][201];

int main(void)
{
	int r,c,n;
	cin >> r >> c >> n;
	
	int time = 0;
	
	for(int i=0; i<r; i++) {
		cin >> str[i];
	}
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(str[i][j] == '.') {
				v[i][j] = 0;
			}		
			else if(str[i][j] == 'O') {
				v[i][j] = 1;
			}
		}
	}
	
	time++;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(v[i][j] == 0) {
				v[i][j] = time;
			}		
			else if(v[i][j] == 1) {
				v[i][j] = 2;
			}
		}
	}
	time++;
	
	
	
	while(1) {
		if(time % 2 == 0) {
			
		}
		else if(time % 2 == 1) {
			
		}
	}
	
	
	return 0;
}
