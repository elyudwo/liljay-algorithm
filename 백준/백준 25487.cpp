#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int t,a,b,c;
	cin >> t;
	vector<int> cnt;
	for(int i=0; i<t; i++) {
		cin >> a >> b >> c;
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		int count = 0;
		do {
			vector<int> tmp;
			for(int i=0; i<3; i++) {
				tmp.push_back(v[i]);
			}
			bool check = true;
			
			
			if(tmp[2] % tmp[1] != tmp[1] % tmp[0]) {
				check = false;
			}
			if(tmp[0] % tmp[2] != tmp[1] % tmp[0]) {
				check = false;
			}
			if(tmp[2] % tmp[1] != tmp[0] % tmp[2]) {
				check = false;
			}
			
			if(check)	count++;
			
		}while(next_permutation(v.begin(),v.end()));
		
		cnt.push_back(count);
	}
	
	for(int i=0; i<cnt.size(); i++) {
		cout << cnt[i] << endl;
	}
	
	return 0;
}
