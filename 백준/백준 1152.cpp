#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string str;
	getline(cin,str);
	// cin 은 space 이전의 값만 가져오고
	// getline 은 space 값 까지 가져온다 
	 
	int sum = 0;
	bool flag = true;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == ' ')
			flag = true;
		else if(flag)
		{
			flag = false;
			sum++;
		}
			
	}
	
	cout << sum;
	
	return 0;
}
