#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	
	int alp[26];
	for(int i=0;i<26;i++)
		alp[i] = -1;
		
	for(int i=0; i<str.length(); i++)
	{
		if(alp[str[i] - 'a'] != -1)
			continue;
		alp[str[i] - 'a'] = i;
	}
	
	for(int i=0; i<26; i++)
	{
		cout << alp[i] << ' ';
	}
	
	return 0;
}
