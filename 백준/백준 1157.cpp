#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	for(int i=0;i<str.length();i++)
	{
		str[i] = toupper(str[i]);
		//toupper�� �̿��� �빮�ڷ� �ٲܼ����ְ�
		//transform(str.begin(), str.end(), str.begin(), (int(*)(int))toupper);
		//transform �Լ� �� �̿��� �ٲܼ��� �ִ� 
	} 
	 
	int sum[26]={0,};
	for(int i=0; i<str.length(); i++)
	{
		sum[str[i]-'A']++;
	}
	
	int max = 0;
	int cnt = 0;
	int target;
	
	for(int i=0;i<26;i++)
	{
		if(max<sum[i])
		{
			max = sum[i];
			cnt = 0;
			target = i;
		}
		if(max == sum[i])
			cnt++;
	}
	if(cnt > 1)
		cout << "?";
	else
		cout << (char)(target+'A');
	
	
	return 0;
}
