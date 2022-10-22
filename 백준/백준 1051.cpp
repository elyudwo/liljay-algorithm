#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int v[51][51];

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	string str[51];
	for(int i=0; i<n; i++) {
		cin >> str[i];
		for(int j=0; j<str[i].size(); j++) {
		    v[i][j] = str[i][j] - '0';
		}
	}
	
	int max_tmp = 1;
	
	for(int i=0; i<n; i++) {
	    for(int j=0; j<m; j++) {
	        int cnt = 0;
	        for(int q=j+1; q<m; q++) {
	            cnt++;
	            if(v[i][j] == v[i][q]) {
	                if(i+cnt >= n)  continue;
	                if(v[i+cnt][j] == v[i][j] && v[i+cnt][q] == v[i][j]) {
	                    max_tmp = max(max_tmp,(cnt+1) * (cnt+1));
	                }
	            }
	        }
	    }
	}
	
	cout << max_tmp;
	
	return 0;
}
