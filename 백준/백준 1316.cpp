#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int sum = 0;
	
	string word;
	for(int i=0;i<n;i++)
	{
		cin >> word;
		bool check = true;
		for(int j=0;j<word.size();j++)
		{
			for(int k=0;k<j;k++)
			{
				if(word[j]!=word[j-1] && word[j]==word[k])
					check = false;
			}
		}
		if(check == true)
			sum++;
	}
	cout << sum;
	
	
	
	return 0;
}
