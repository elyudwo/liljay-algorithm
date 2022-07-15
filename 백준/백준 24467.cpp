#include <iostream>
#include <string>

using namespace std;

int v[6][7];

int main()
{
	int result = 0;
	int lee = 0;
	
	int cnt_t = 0;
	
	int check = 0;
	while(1) {
		string str;
		getline(cin,str);
		if(str == "") break;
		
		if(cnt_t >= 10) {
			lee = 1;
			break;
		}
		int cnt = 0;
		for(int i=0; i<str.length(); i++) {
			if(str[i] == '0') {
				cnt++;
			}
		}
		if(cnt == 0) {
			result = result + 5;
			cnt_t--;
		}
		else if(cnt == 1) {
			result = result + 1;
		}
		else if(cnt == 2) {
			result = result + 2;
		}
		else if(cnt == 3) {
			result = result + 3;
		}
		else if(cnt == 4) {
			result = result + 4;
			cnt_t--;
		}
		
		if(lee == 0) {
			if(result == 5) {
				lee = 4;
				result = 0;
			}
			else if(result > 5) {
				lee = 1;
				result = result - 5;
			}
			cnt--;
		}
		else if(lee == 1) {
			if(result == 5) {
				lee = 5;
				result = 0;
			}
			else if(result > 5) {
				lee = 2;
				result = result - 5;
			}
		}
		else if(lee == 2) {
			if(result >= 5) {
				lee = 3;
				result = result - 5;
			}
		}
		
		else if(lee == 3) {
			if(result > 5) {
				check = 3;
				
			}
		}
		
		else if(lee == 4) {
			if(result == 3) {
				result = 0;
				lee = 6;
			}
			else if(result >= 6) {
				result = result - 6;
				lee = 3;
			}
		}
		
		else if(lee == 5) {
			if(result > 6) {
				check = 3;
			}
		}
		
		else if(lee == 6) {
			if(result > 3) {
				check = 3;
			}
		}
		cnt_t++;	
	}
	
	if(check == 3) {
		cout << "WIN";
	}
	else {
		cout << "LOSE";
	}
	
	return 0;
}
