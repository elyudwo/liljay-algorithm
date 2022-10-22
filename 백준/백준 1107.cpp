#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int last = 0;
bool check[11];
int result = 1000000000; 
vector<char> rem;

//고장나지 않은 버튼 
vector<int> vec;
// 채널 번호 
string ch;

int string_to_int(string str)
{
    int j = 0;
    int tmp = 0;
    for(int i=str.length()-1; i>=0; i--) {
        int a = str[i] - '0';
        tmp = tmp + pow(10,j) * a;
        j++;
    }
    
    return tmp;
}

void dfs(int x)
{
	if(x == ch.length()) {
		string s = "";
		for(int i=0; i<rem.size(); i++) {
			s = s + rem[i];
		}
		int a,b;
		a = string_to_int(s);
		b = string_to_int(ch);
		if(result > fabs(a-b) + ch.length()) {
		    last = 1;
		    result = fabs(a-b) + ch.length();
		}
		return;
	}
	
	for(int i=0; i<vec.size(); i++) {
	    rem.push_back(vec[i]+'0');
	    dfs(x+1);
	    rem.pop_back();
	}
}

void dfs1(int x)
{
	if(x == ch.length()+1) {
		string s = "";
		for(int i=0; i<rem.size(); i++) {
			s = s + rem[i];
		}
		int a,b;
		a = string_to_int(s);
		b = string_to_int(ch);
		if(result > fabs(a-b) + ch.length() + 1) {
		    last = 2;
		    result = fabs(a-b) + ch.length() + 1;
		}
		return;
	}
	
	for(int i=0; i<vec.size(); i++) {
	    rem.push_back(vec[i]+'0');
	    dfs1(x+1);
	    rem.pop_back();
	}
}

void dfs2(int x)
{
	if(x == ch.length()-1) {
		string s = "";
		for(int i=0; i<rem.size(); i++) {
			s = s + rem[i];
		}
		int a,b;
		a = string_to_int(s);
		b = string_to_int(ch);
		if(result > fabs(a-b) + ch.length() - 1) {
		    last = 3;
		    result = fabs(a-b) + ch.length() -1;
		}
		return;
	}
	
	for(int i=0; i<vec.size(); i++) {
	    rem.push_back(vec[i]+'0');
	    dfs2(x+1);
	    rem.pop_back();
	}
}

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> ch;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		check[tmp] = true;
	}
	for(int i=0; i<=9; i++) {
		if(!check[i]) {
			vec.push_back(i);
		}
	}
	
	// 1. +,-만 눌러서 가는경우
	int a = string_to_int(ch);
	int b = 100;
	int c = fabs(a - b);
	if(result > c) {
		result = c;
	}
	
	// 2. 가장 가까운 번호를 눌러서 +,-로 가는 경우 
	dfs(0);
	dfs1(0);
	if(ch.length() != 1) {
		dfs2(0);
	}
	if(last == 1) {
		cout << result;
	}
	else if(last == 2) {
		cout << result;
	}
	else if(last == 3){
		cout << result;
	}
	else {
		cout << result;
	}
	
	return 0;
}
