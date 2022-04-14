#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int main(void) 
{
	int n;
	cin >> n;
	
	string str[n];
	
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
	
	int cnt = 0;
	
	for(int i=0; i<n; i++) {
		int k = str[i][0];
		for(int j=0; j<str[i].length(); j++) {
			if(k != str[i][j]) {
				cnt++;
				k = str[i][j];
			}
		}	
	}
	
	int m[n][2];
	
	for(int i=0; i<n; i++) {
		m[i][0] = str[i][0];
		m[i][1] = str[i][str[i].length()-1];
	}
	
	vector<int> idx(n);
	for(int i=0; i<n; i++) 
		idx[i] = i;
	
	int ans = -1;
	do {
		int cnt = 0;
		for(int i=0; i<n-1; i++) {
			if(str[idx[i]][str[idx[i]].size()-1] != str[idx[i+1]][0]) {
				cnt += 1;
			}
		}
		if(ans == -1 || ans > cnt) {
			ans = cnt;
		}
	}while(next_permutation(idx.begin(),idx.end()));

	cout << cnt + ans;
	
	return 0;
}
