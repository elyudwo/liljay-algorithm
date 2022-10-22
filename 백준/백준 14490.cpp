#include <iostream>
#include <string> 
using namespace std;

string str;
int n,m;

void split_string(string str)
{
	string tmp1 = "";
	string tmp2 = "";
	bool check = false;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == ':') {
			check = true;
			continue;
		}
		if(check) {
			tmp2 = tmp2 + str[i];
		}
		else {
			tmp1 = tmp1 + str[i];
		}
	}
	
	n = stoi(tmp1);
	m = stoi(tmp2);
	return;
	
}

int main(void)
{
	cin >> str;
	
	split_string(str);
	
	int tmp;
	if(n >= m) {
		for(int i=1; i<=m; i++) {
			if(n%i == 0 && m%i == 0) {
				tmp = i;	
			}
		}
		n = n/tmp;
		m = m/tmp;
		
		cout << n << ":" << m;
	}
	else {
		for(int i=1; i<=n; i++) {
			if(n%i == 0 && m%i == 0) {
				tmp = i;	
			}
		}
		n = n/tmp;
		m = m/tmp;
		
		cout << n << ":" << m;
	}
	
	return 0;
}
