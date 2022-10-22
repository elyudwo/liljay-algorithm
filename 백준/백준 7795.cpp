#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		vector<int> a;
		vector<int> b;
		cin >> n >> m;
		
		for(int i=0; i<n; i++) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		for(int i=0; i<m; i++) {
			int tmp;
			cin >> tmp;
			b.push_back(tmp);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		int tmp = 0;
		int sum = 0;
		
		for(int i=0; i<n; i++) {
			while(1) {
				if(tmp == m) {
					sum = sum + tmp;
					break;
				}
				
				if(a[i] > b[tmp] ) {
					tmp++;
				}
				else {
					sum = sum + tmp;
					break;
				}
			}
		}
		
		cout << sum << endl;
	}
	
	
	return 0;
}
