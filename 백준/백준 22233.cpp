#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> s;

vector<string> split(string str)
{
	vector<string> rem;
	string tmp;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == ',') {
			rem.push_back(tmp);
			tmp = "";
		}
		else tmp = tmp + str[i];
	}
	rem.push_back(tmp);
	return rem;
} 


int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	
	
	for(int i=0; i<m; i++) {
		string str;
		cin >> str;
		vector<string> tmp = split(str);
		
		for(int j=0; j<tmp.size(); j++) {
			s.erase(tmp[j]);
		}
		
		cout << s.size() << '\n';
	}
	
	return 0;
}
