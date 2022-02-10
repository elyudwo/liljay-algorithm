#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	
	int n[25];
	for(int i=0;i<26;i++)
		n[i] = -1;
	
	for(int i=0;i<26;i++)
	{
		n[str[i]-'a'] = i;
	}
	
	for(int i=0;i<26;i++)
	{
		cout << n[i] << " ";
	}
	
	return 0;
}
