#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		int R;
		string str;
		cin >> R >> str; 
		
		for(int k=0;k<str.length();k++)
		{
			for(int j=0;j<R;j++)
			{
				cout << str[k];
				// string�� ����� ���ĺ����� �迭�� �˼��ִ� 
			}
		}
		cout << endl;
	}
	
	
	return 0;
}
