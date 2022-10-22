#include <iostream>
#include <string>
#include <map> 
#include <vector>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	
	for(int t=0; t<n; t++) {
		int a;
		cin >> a;
		map <string,int> ma;
		int cnt = 0;
		vector<string> tmp;
		for(int i=0; i<a; i++) {
			string str1,str2;
			cin >> str1 >> str2;
			if(ma[str2]) {
				ma[str2]++;
			}
			else {
				ma[str2] = 1;
				tmp.push_back(str2);
 			}
		}
		int result = 1;
		if(tmp.size() >= 1) {
			for(int i=0; i<tmp.size(); i++) {
				result = result * (ma[tmp[i]] + 1);
			}
			result--;
			cout << result << endl;
		}
		else {
			cout << "0" << endl;
		}
		
		
		
	}
	
	
	
	return 0;
}
