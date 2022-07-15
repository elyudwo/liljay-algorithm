#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector> 
using namespace std;

int main(void)
{
	int n,m;
	cin >> n >> m;
	vector<string> str;
	vector<string> answer;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		str.push_back(s);
	}
	
	sort(str.begin(),str.end());
	int cnt = 0;
	for(int i=0; i<m; i++) {
		string s;
		cin >> s;
		if(binary_search(str.begin(),str.end(),s)) {
			answer.push_back(s);
			cnt++;
		}
	}
	sort(answer.begin(),answer.end());
	cout << cnt << endl;
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i] << endl;
	}
	
	return 0;
}
