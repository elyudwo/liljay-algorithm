#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	string s;
	int count = 0;
	
	getline(cin, str);
	getline(cin, s);
	
	for(int i = 0; i < str.size(); i++)
	{
		bool same = true;
		for(int j = 0; j < s.size(); j++)
		{
			if(str[i+j] != s[j])
			{
				same = false;
				break;
			}
		}
		if(same)
		{
			count ++;
			i = i + s.size() -1;
		}
	}
	
	cout << count;
	
	return 0;
}
