#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm> 
using namespace std;

string s,t;
bool check;
map<string,int> ma;

bool bfs()
{
	queue<string> q;
	q.push(t);
	
	while(!q.empty()) {
		string str = q.front();
		q.pop();
		if(str == s) {
			return true;
		}
		if(str.back() == 'A') {
			string tmp = str;
			tmp.pop_back();
			q.push(tmp);
			tmp = "";
		}
		string tmp = str;
		reverse(tmp.begin(),tmp.end());
		
		if(tmp.back() == 'B') {
			tmp.pop_back();
			q.push(tmp);
		}
	}
	return false;
}

int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> s;
	cin >> t;
	
	check = bfs();
	if(check)	cout << "1";
	if(!check)	cout << "0";
	
	return 0;
}
