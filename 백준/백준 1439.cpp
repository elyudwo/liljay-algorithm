#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	
	int cnt = 0;
	
	for(int i=0; i < str.length(); i++)
	{
		if(str[i+1] == str[i])
			continue;
		else if(str[i+1] != str[i])
			cnt++;
	}
	
	cout << cnt/2;
	
	return 0;
}
