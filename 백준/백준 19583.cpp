#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> ma;

int change_clock(string str) {
    int t,m;
    t = stoi(str.substr(0,2));
    m = stoi(str.substr(3,5));
    
    int a = t * 100 + m;
    
    return a;
}

int main(void)
{
	string s,e,q;
	cin >> s >> e >> q;
	int cnt = 0;
	string t,name;
	while(!cin.eof()) {
	    cin >> t >> name;
		if(change_clock(t) <= change_clock(s)) {
			ma[name] = 1;
		}
		else if(change_clock(t) >= change_clock(e) && change_clock(t) <= change_clock(q)) {
			if(ma[name] == 1) {
			    ma[name] = 2;
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
