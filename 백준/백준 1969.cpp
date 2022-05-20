#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
string str[1001];
string answer;

int main(void)
{
	cin >> n >> m;
	
	
	
	for(int i=0; i<n; i++) {
		cin >> str[i];		
	}
	
	
	for(int i=0; i<m; i++) {
		int cnt[4];
		int max_cnt = -1;
		int k = 0;
		
		for(int j=0; j<n; j++) {
			if(str[j][i] == 'T') {
				cnt[0]++;
			} 
			else if(str[j][i] == 'G') {
				cnt[1]++;
			}
			else if(str[j][i] == 'C') {
				cnt[2]++;
			}
			else if(str[j][i] == 'A') {
				cnt[3]++;
			}
		}
		
		
		for(int i=0; i<4; i++) {
			if(max_cnt <= cnt[i]) {
				max_cnt = cnt[i];
				k = i;
			}
		}
		
		if(k == 0) {
			answer = answer + 'T';
		}
		else if(k == 1) {
			answer = answer + 'G';
		}
		else if(k == 2) {
			answer = answer + 'C';
		}
		else if(k == 3) {
			answer = answer + 'A';
		}
		
		for(int i=0; i<4; i++) {
			cnt[i] = 0;
		}
	}
	
	
	int ancnt = 0;
	
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(answer[j] != str[i][j]) {
				ancnt = ancnt + 1;
			}
		}
	}
		
	cout << answer << endl << ancnt;
	
	
	return 0;
}
