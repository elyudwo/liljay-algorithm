#include <iostream>
#include <string>
using namespace std;

int h1,c1,o1,h2,c2,o2,h3,c3,o3;

string str;

void plus1(int index, char c, int num) {
	if(index == 1) {
		if(c == 'C') {
			c1 = c1 + num;
		}
		else if(c == 'O') {
			o1 = o1 + num;
		}
		else if(c == 'H') {
			h1 += num;
		}
	}
	else if(index == 2) {
		if(c == 'C') {
			c2 += num;
		}
		else if(c == 'O') {
			o2 += num;
		}
		else if(c == 'H') {
			h2 += num;
		}
	}
	else {
		if(c == 'C') {
			c3 += num;
		}
		else if(c == 'O') {
			o3 += num;
		}
		else if(c == 'H') {
			h3 += num;
		}
	}
}

void input() {
	cin >> str;
	h1 = 0; c1 = 0; o1 = 0;
	h2 = 0; c2 = 0; o2 = 0;
	h3 = 0; c3 = 0; o3 = 0;
	bool second_check = false;
	bool third_check = false;
	
	for(int i=0; i<str.size(); i++) {
		if(!second_check && !third_check) {
			if(str[i] == 'C' || str[i] == 'O' || str[i] == 'H') {
				if(str[i+1] >= '1' && str[i+1] <= '9') {
					int num = str[i+1] - '0';
					plus1(1, str[i], num); 
				}
				else {
					plus1(1,str[i],1);
				}
			}
			
			if(str[i] == '+') { second_check = true; }
		}
		if(second_check && !third_check) {
			if(str[i] == 'C' || str[i] == 'O' || str[i] == 'H') {
				if(str[i+1] >= '1' && str[i+1] <= '9') {
					plus1(2, str[i], str[i+1] - '0'); 
				}
				else {
					plus1(2,str[i],1);
				}	
			}
			
			if(str[i] == '=') { third_check = true; }
		}
		if(second_check && third_check) {
			if(str[i] == 'C' || str[i] == 'O' || str[i] == 'H') {
				if(i != str.size()-1) {
					if(str[i+1] >= '1' && str[i+1] <= '9') {
						plus1(3, str[i], str[i+1] - '0'); 
					}
					else {
						plus1(3,str[i],1);
					}
				}
				else {
					plus1(3, str[i], 1); 
				}
			}
		}
	}
	
}

void solve() {
	for(int i=1; i<=10; i++) {
		for(int j=1; j<=10; j++) {
			for(int k=1; k<=10; k++) {
				if((h1 * i + h2 * j == h3 * k) && (o1 * i + o2 * j == o3 * k) && (c1 * i + c2 * j == c3 * k)) {
					cout << i << " " << j << " " << k;
					return;
				}
			}
		}
	}
}

int main() {
	input();
	solve();
	
}