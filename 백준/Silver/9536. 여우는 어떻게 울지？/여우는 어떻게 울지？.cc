#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
 
int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    string buffer; //버퍼 제거
		getline(cin, buffer);
		map<string,int> ma;
		vector<string> vec;
		
		string str;
		getline(cin,str);
		string tmp = "";
		     
		for(int i=0; i<str.size(); i++) {
			if(str[i] == ' ') {
				ma[tmp] = 1;
				vec.push_back(tmp);
				tmp = "";
			}
			else { tmp += str[i]; }
		}
		
		ma[tmp] = 1;
		vec.push_back(tmp);
		
		while(1) {
			string a,b,c;
			cin >> a >> b >> c; 
			
			if(a == "what") {
				break;
			}
			ma[c] = 0;
		}
		
		for(int i=0; i<vec.size(); i++) {
		    if(ma[vec[i]] >= 1) {
		        cout << vec[i] << " ";
		    }
		} 
		cout << '\n';
		
	}
}