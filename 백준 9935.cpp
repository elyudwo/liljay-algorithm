#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str,bomb,tmp="";
	cin >> str;
	cin >> bomb;
	
	for(int i=0; i<str.size(); i++) {
		tmp += str[i];
		if(tmp.back() == bomb.back()) {
			bool check = true;
			if(tmp.size() < bomb.size()) { continue; }
			for(int j=0; j<bomb.size(); j++) {
				if(tmp[tmp.size()-bomb.size()+j]!=bomb[j]){
                    check = false;
                    break;
                }
			}
			if(check) {
				for(int j=0; j<bomb.size(); j++) { tmp.pop_back(); }
			}
			
		}
	}
	
	if(tmp.empty()) {
		cout << "FRULA" << "\n";
	}
	else {
	    cout << tmp << "\n";
	}
	return 0;
}
