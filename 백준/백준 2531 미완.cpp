#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	int n,d,k,c;
	cin >> n >> d >> k >> c;
	
	int v[n];
		
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	int result = -1;
	
	for(int i=0; i<n; i++) {
		int tmp = 0;
		map <int,int> ma;
		bool check = false;
		for(int j=i; j<k; j++) {
			if(ma[v[j]] == 1) {
				continue;
			}
			else if(v[j] == c) {
				check = true;
			}
			else {
				ma[v[j]] = 1;
				tmp++;
			}
		}
		if(check)	tmp++;
		result = max(result,tmp);
		
	}
	cout << result;
	
	return 0;
}
