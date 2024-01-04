#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int idx; 
	vector<string> croatian = {"c=","c-","dz=","d-","lj","nj","s=","z="};
	
	for(int i=0; i < croatian.size(); i++)
	{
		while(1)
		{
			idx = str.find(croatian[i]);
			if(idx == string::npos)
				break;
			str.replace(idx,croatian[i].length(),"#");
		}
	}	
	cout << str.length();
	
	return 0;
}