#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string S;
	string T;
	cin >> S;
	cin >> T;
	
	while(1)
	{
		if(S.size() == T.size())
		{
			if(S == T)
			{
				cout << "1";
				break;
			}
			else
			{
				cout << "0";
				break;
			}
		}
		
		if(T[T.size() - 1] == 'A')
			T.pop_back();
		
		else
		{
			T.pop_back();
			reverse(T.begin(),T.end());
		}
		
	}
	
	return 0;
}
