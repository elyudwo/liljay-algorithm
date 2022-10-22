#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> str;

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
	}
	
	sort(str.begin(),str.end());
	
	int cnt = 0;
	
	for(int i=0; i<m; i++) {
		string tmp;
		cin >> tmp;
		int l = 0;
		int r = n - 1;
		while(l <= r) {
			int mid = (l+r)/2;
			if(tmp < str[mid]) {
				r = mid - 1 ; 
			}
			else if(tmp > str[mid]) {
				l = mid + 1;
			}
			if(str[mid].substr(0,tmp.size()) == tmp) {
				cnt++;
				break;
			}
			
		}
	}
	
	cout << cnt;
	
	return 0;
}
