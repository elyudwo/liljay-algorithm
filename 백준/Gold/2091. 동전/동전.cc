#include <iostream>

using namespace std;

int x,a,b,c,d;

void input() {
	cin >> x >> a >> b >> c >> d;
}

void solve() {
    int coin = 100000;
    int answer_rem[4] = {0,0,0,0};
    
	for(int i=d; i>=0; i--) {
	    int tmp = i;
		int total = a * 1 + b * 5 + c * 10 + d * 25 - x;
		int answer[4] = {0, 0, 0, 0};
		if(i * 25 > total) continue;
	
		total -= i * 25;
		answer[3] = i;
		
		int ten = total / 10;
		
		if(ten > c) {
	        total = total - 10 * c; 
	        answer[2] = c; 
	        tmp += c;
		}	
		else { total = total - 10 * ten; answer[2] = ten; tmp += ten;}
		
		int five = total / 5;
		
		if(five > b) { total = total - 5 * b; answer[1] = b; tmp += b; }
		else { total = total - 5 * five; answer[1] = five; tmp += five; }
		
		int one = total / 1;
		total -= one;
		tmp += one;
		if(one > a) continue;
		answer[0] = one;
		
		if(total == 0 && coin > tmp) {
		    coin = tmp;
		    answer_rem[0] = a - answer[0];
		    answer_rem[1] = b - answer[1];
		    answer_rem[2] = c - answer[2];
		    answer_rem[3] = d - answer[3];
		}
	}

    for(int i=0; i<4; i++) {
		cout << answer_rem[i] << " ";
	}
	
}

int main() {
	input();
	solve();
	
}