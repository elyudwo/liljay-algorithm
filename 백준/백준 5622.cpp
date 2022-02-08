#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int sum = 0;
	for(int i=0;i<str.length();i++)
	{
		if(int(str[i])>=65 && int(str[i])<68)
			sum += 3;
		else if(int(str[i])>=68 && int(str[i])<71)
			sum += 4;
		else if(int(str[i])>=71 && int(str[i])<74)
			sum += 5;
		else if(int(str[i])>=74 && int(str[i])<77)
			sum += 6;
		else if(int(str[i])>=77 && int(str[i])<80)
			sum += 7;
		else if(int(str[i])>=80 && int(str[i])<83)
			sum += 8;
		else if(int(str[i])>=83 && int(str[i])<86)
			sum += 9;	
		else if(int(str[i])>=86 && int(str[i])<90)
			sum += 10;
		else if(int(str[i])>=7)
			sum += 11;
	}
	cout << sum;
	
	return 0;
}
