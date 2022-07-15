#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

vector<int> minute;
vector<int> score;
int total = 0;

int main(void)
{
	int n;
	cin >> n;
	
	int tmp = 0;
	
	for(int i=0; i<n+1; i++) {
		string str;
		getline(cin,str);
		
		string x[3];
		int lee = 0;
		
		string stringBuffer;
		istringstream ss(str);
		
		if(str[0] == '1') {

			while(getline(ss,stringBuffer,' ')) {
				x[lee++] = stringBuffer;
			}
			
			score.push_back(stoi(x[1]));
			minute.push_back(stoi(x[2]));
		    if(!score.empty()) {
		    	minute.back() = minute.back()-1;
				if(minute.back() == 0) {
					total = total + score.back();
					score.pop_back();
					minute.pop_back();
				}
			}
		}
		else if(str[0] == '0') {
		    if(!score.empty()) {
		    	minute.back() = minute.back()-1;
		
				if(minute.back() == 0) {
					total = total + score.back();
					score.pop_back();
					minute.pop_back();
				}
			}
			
		}
		
	}	
	cout << total;
	
	return 0;
}
