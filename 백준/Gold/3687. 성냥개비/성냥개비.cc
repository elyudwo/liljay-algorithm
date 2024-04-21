#include <iostream>

using namespace std;

int num_cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int small_cnt[8] = {-1, -1, 1, 7, 4, 2, 0, 8};
string big_answer[101];
string small_answer[101];
int dp[101]; 

string calculateBig(int num) {
	string result = "";
	if(num == 2) { return "1"; }
	if(num % 2 == 1) {
		result += "7";
		num -= 3;
	}
	
	while(num > 0) {
		result += "1";
		num -= 2;
	}
	
	return result;
} 

void calculateSmall() {
	for(int i=2; i<=100; i++) {
	    dp[i] = 51;
	}
	
	for(int i=2; i<=7; i++) {
		small_answer[i] = to_string(small_cnt[i]);
		dp[i] = 1;
	}
	small_answer[6] = "6";
	small_answer[8] = "10";
	dp[8] = 2;
	
	
	for(int i=9; i<=100; i++) {
		for(int j=2; j<=7; j++) {
			string str = small_answer[i-j];
			str += to_string(small_cnt[j]);
			if(dp[i] > dp[i-j] + 1) {
			    dp[i] = dp[i-j] + 1;
			    small_answer[i] = str;
			    continue;
			}
			
			if(dp[i] == dp[i-j] + 1 && small_answer[i] > str) {
				small_answer[i] = str;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	calculateSmall();
	
	for(int i=2; i<=100; i++) {
		big_answer[i] = calculateBig(i);
	}
	
// 	for(int i=2; i<=100; i++) {
// 	    cout << big_answer[i] << " " << small_answer[i] << "  ";
// 	}
	
	
	while(t--) {
		int n;
		cin >> n;
		
		cout << small_answer[n] << " " << big_answer[n] << '\n';
	}
}