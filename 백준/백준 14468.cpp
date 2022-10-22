#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> result;
string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string str;

void Solve(char c)
{
	int index;
	bool check[26] = {false,};
	for(int i=0; i<52; i++) {
		if(str[i] == c) {
			index = i+1;
			break;
		}
	}
	
	for(int i=index; i<52; i++) {
		if(str[i] == c) {
			break;
		}
		if(check[str[i] - 'A']) {
			check[str[i] - 'A'] = false;
		}
		else if(!check[str[i] - 'A']) {
			check[str[i] - 'A'] = true;
		}
	}
	
	for(int i=0; i<26; i++) {
		if(check[i]) {
			string tmp1,tmp2;
			tmp1 = tmp1 + c + alp[i];
			tmp2 = tmp2 + c + alp[i];
			result[tmp1] = 1;
			result[tmp2] = 1;
		}
	}
	
} 

int main(void)
{
	cin >> str;
	
	for(int i=0; i<26; i++) {
		Solve(alp[i]);
	}
	
	cout << result.size()/2;
	
	return 0;
}
