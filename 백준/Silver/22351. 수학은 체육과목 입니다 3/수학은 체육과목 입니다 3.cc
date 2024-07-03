#include <iostream>
#include <string> 
using namespace std;

string result;
	
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int cnt = 0;

	cin >> result;
	
	for(int i=1; i<=2889; i++) {
		string tmp = "";
		for(int j=i; j<=2889; j++) {
			tmp += to_string(j);
			if(tmp.size() == result.size() && tmp == result) {
				cout << i << " " << j;
				return 0;
			}
			
			if(tmp.size() > result.size()) { break; }
		}
	}
}