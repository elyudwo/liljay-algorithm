#include <iostream>
#include <string.h>

using namespace std;

char str[51];
int sum = 0;
bool flag;
int len,tmp;
int main(void)
{
	cin >> str;
	len = strlen(str);
	
	for(int i=0; i <= len; i++)
	{	
		if(str[i] == '+' || str[i] == '-' || i == len)
		{
			if(flag == false)
			{
				sum = sum + tmp;
				tmp = 0;
			}
			else if(flag == true)
			{
				sum = sum - tmp;
				tmp = 0;
			}
			if(str[i] == '-')
				flag = true;
			// �ϴ� �տ� - �� ������ �ڿ� ����� ������ �� �������� 
		}
		else
		{
			tmp = tmp * 10;
			tmp += str[i] - '0';
		}
	}
	
	cout << sum; 
	return 0;
}
