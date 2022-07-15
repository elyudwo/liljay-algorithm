#include <iostream>
#include <vector>
using namespace std;

string str_clock;
string str_rclock;
string result[100];
int cnt_tmp = 0;



int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int k;
		cin >> k;
		str_clock = str_clock + to_string(k);
	}
	
	for(int i=str_clock.length()-1; i>=0; i--) {
		if(str_clock[i] == '1') {
			str_rclock = str_rclock + '3';
		}
		else if(str_clock[i] == '2') {
			str_rclock = str_rclock + '4';
		}
		else if(str_clock[i] == '3') {
			str_rclock = str_rclock + '1';
		}
		else if(str_clock[i] == '4') {
			str_rclock = str_rclock + '2';
		}
	}
	
	int t;
	int cnt = 0;
	cin >> t;
	for(int i=0; i<t; i++) {
		string l,s;
		
		for(int j=0; j<n; j++) {
			int k;
			cin >> k;
			l = l + to_string(k);	// 돌리기 위한 string 
			s = s + to_string(k);	// result에 포함될경우 저장되기 위함 
		}
		
		for(int j=0; j<n; j++) {
			if(l == str_clock) {
				cnt++;
				result[cnt_tmp++] = s;
				break;
			}
			else if(l == str_rclock) {
				cnt++;
				result[cnt_tmp++] = s;
				break;
			}
			else {
			    char tmp = l[0];
	
            	for(int i=0; i<l.length()-1; i++) {
            		l[i] = l[i+1];
            	}
            	l[l.length()-1] = tmp;
			}
		}
	}
	
	cout << cnt << endl;
	
	for(int i=0; i<cnt_tmp; i++) {
		for(int j=0; j<n; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
