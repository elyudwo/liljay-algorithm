#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

string str[5];

void rev_clock(string lee,int q)
{
	char c = lee[0];
	for(int j=1; j<lee.length(); j++) {
		lee[j-1] = lee[j];
	}
	lee[lee.length()-1] = c;
	for(int j=0; j<lee.length(); j++) {
	    str[q][j] = lee[j];
	}
}

void turn_clock(string lee,int q) 
{
	char c = lee[lee.length()-1];
	for(int j=lee.length()-2; j>=0; j--) {
		lee[j+1] = lee[j];
	}
	lee[0] = c;
	for(int j=0; j<lee.length(); j++) {
	    str[q][j] = lee[j];
	}
}

int main(void)
{
	int k;
	for(int i=1; i<5; i++) {
		cin >> str[i];	// 2와 6이 맞닿아있다 
	}
	cin >> k;
	
	
	for(int i=0; i<k; i++) {
		int a,b;
		cin >> a >> b;
		bool check[3] = {true,true,true};
		if(str[1][2] == str[2][6]) check[0] = false;
		if(str[2][2] == str[3][6]) check[1] = false;
		if(str[3][2] == str[4][6]) check[2] = false;
		
		if(a == 1) {
			if(b == 1) {
				turn_clock(str[1],1);
				if(check[0]) {
					rev_clock(str[2],2);
					if(check[1]) {
						turn_clock(str[3],3);
						if(check[2]) {
							rev_clock(str[4],4);
						}
					}
				}
			}
			else if(b == -1) {
				rev_clock(str[1],1);
				if(check[0]) {
					turn_clock(str[2],2);
					if(check[1]) {
						rev_clock(str[3],3);
						if(check[2]) {
							turn_clock(str[4],4);
						}
					}
				}
			}
		}
		else if(a == 2) {
			if(b == 1) {
				turn_clock(str[2],2);
				if(check[0]) 
					rev_clock(str[1],1);
				if(check[1]) {
					rev_clock(str[3],3);
					if(check[2])
						turn_clock(str[4],4);
				}
			}
			else if(b == -1) {
				rev_clock(str[2],2);
				if(check[0]) 
					turn_clock(str[1],1);
				if(check[1]) {
					turn_clock(str[3],3);
					if(check[2])
						rev_clock(str[4],4);
				}
			}
		}
		else if(a == 3) {
			if(b == 1) {
				turn_clock(str[3],3);
				if(check[1]) {
					rev_clock(str[2],2);
					if(check[0])
						turn_clock(str[1],1);
				}
				if(check[2]) 
					rev_clock(str[4],4);
				
			}
			else if(b == -1) {
				rev_clock(str[3],3);
				if(check[2]) 
					turn_clock(str[4],4);
				if(check[1]) {
					turn_clock(str[2],2);
					if(check[0])
						rev_clock(str[1],1);
				}
			}
		}
		else if(a == 4) {
			if(b == 1) {
				turn_clock(str[4],4);
				if(check[2]) {
					rev_clock(str[3],3);
					if(check[1]) {
						turn_clock(str[2],2);
						if(check[0]) 
							rev_clock(str[1],1);
					}
				}
			}
			else if(b == -1) {
				rev_clock(str[4],4);
				if(check[2]) {
					turn_clock(str[3],3);
					if(check[1]) {
						turn_clock(str[2],2);
						if(check[0])
							rev_clock(str[1],1);
					}
				}
			}
		}
	}

	int sum = 0;
	for(int i=1; i<=4; i++) {
		if(str[i][0] == '1' && i == 1) {
			sum = sum + 1;
		}
		else if(str[i][0] == '1' && i == 2) {
			sum = sum + 2;
		}
		else if(str[i][0] == '1' && i == 3) {
			sum = sum + 4;
		}
		else if(str[i][0] == '1' && i == 4) {
			sum = sum + 8;
		}
		
	}
	
	cout << sum;
	return 0;
}
