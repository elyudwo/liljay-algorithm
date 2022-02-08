#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	char c[100];
	int key = 0;
	char alp[] = "abcdefghijklmnopqrstuvwxyz";
	cin >> c;
	for(int i=0;i<strlen(alp);i++)
	{
		for(int j=0;j<strlen(c);j++)
		{
			if(alp[i] == c[j])
			{
				cout << j << " ";
				key = 0;
				break;
			}
			else
				key = 1;
		}
		if(key == 1)
			cout << "-1 ";
	}
	return 0;
}
