#include <iostream>
#include <string>
using namespace std;

string v1[51];
string v2[51];
int n,m;

void change_num(int x1,int y1)
{
	int x2 = x1 + 2;
	int y2 = y1 + 2;
	
	if(x2 >= n && y2 >= m) {
		int minus1 = x2 - n;	
		int minus2 = y2 - n;
		if(minus1 == 1 && minus2 == 1) {
			for(int i=x1-1; i<=x1+1; i++) {
				for(int j=y1-1; j<=y1+1; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
		else if(minus1 == 1 && minus2 == 2) {
			for(int i=x1-1; i<=x1+1; i++) {
				for(int j=y1-2; j<=y1; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
		else if(minus1 == 2 && minus2 == 1) {
			for(int i=x1-2; i<=x1; i++) {
				for(int j=y1-1; j<=y1+1; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
		else if(minus1 == 2 && minus2 == 2) {
			for(int i=x1-2; i<=x1; i++) {
				for(int j=y1-2; j<=y1; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
 	}
	else if(x2 >= n) {
		int minus = x2 - (n-1);
		if(minus == 1) {
			for(int i=x1-1; i<=x1+1; i++) {
				for(int j=y1; j<=y1+2; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
		else if(minus == 2) {
			for(int i=x1-2; i<=x1; i++) {
				for(int j=y1; j<=y1+2; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
	}
	else if(y2 >= m) {
		int minus = y2 - (m-1);
		if(minus == 1) {
			for(int i=x1; i<=x1+2; i++) {
				for(int j=y1-1; j<=y1+1; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
		else if(minus == 2) {
			for(int i=x1; i<=x1+2; i++) {
				for(int j=y1-2; j<=y1; j++) {
					if(v1[i][j] == '0')	v1[i][j] = '1';
					else v1[i][j] = '0';
				}
			}
		}
	}
	else {
		for(int i=x1; i<=x1+2; i++) {
			for(int j=y1; j<=y1+2; j++) {
				if(v1[i][j] == '0')	v1[i][j] = '1';
				else v1[i][j] = '0';
			}
		}
	}	
}

int main(void) 
{
	cin >> n >> m;
	int cnt = 0;
	
	
	for(int i=0; i<n; i++) {
		cin >> v1[i];
	}
	
	for(int i=0; i<n; i++) {
		cin >> v2[i];
	}
	
	if(n < 3 || m < 3) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(v1[i][j] != v2[i][j]) {
					cout << "-1";
					return 0;
				}
			}
		}
		cout << "0";
		return 0;
	} 
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(v1[i][j] != v2[i][j]) {
				change_num(i,j);
				cnt++;
			}
		}
	}
	
	
	bool check = true;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(v1[i][j] != v2[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << cnt;
	
	return 0;
}
