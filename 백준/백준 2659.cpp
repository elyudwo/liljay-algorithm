#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<int,int> ma;
int math_cnt = 0;
string str;
vector<int> v;
int min_t = 10000;
bool check[10];
int shin[4];

void dfs(int cnt) 
{
	if(cnt == 4) {
		string lee[4];
		for(int i=0; i<4; i++) {
			int a = v[i];
			lee[0] = lee[0] + to_string(a);
		}
		lee[1] = lee[1] + v[1] + v[2] + v[3] + v[0];
		lee[2] = lee[2] + v[2] + v[3] + v[0] + v[1];
		lee[3] = lee[3] + v[3] + v[0] + v[1] + v[2];
		
		if(lee[0] == answer) {
			for(int i=0; i<4; i++) {
				shin[i] = stoi(lee[i]);
			}
			sort(shin,shin+4);
			
			for(int i=0; i<4; i++) {
				min_t = min(shin[i],min_t);
			}
			if(ma.find(min_t)) {
				cout << ma[min_t];
				return;
			}
			else {
				cout << ++math_cnt;
				return;
			}
		}
		
		for(int i=0; i<4; i++) {
			shin[i] = stoi(lee[i]);
		}
		sort(shin,shin+4);
		
		for(int i=0; i<4; i++) {
			min_t = min(shin[i],min_t);
		}
		if(ma.find(min_t)) {
			return;
		}
		else {
			ma.insert(min_t,++math_cnt);
		}
	}
	
	for(int i = 1; i<=9; i++) {
		if(check)	continue;
		check[i] = true;
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
		check[i] = false;
	}
	
}

int main(void)
{
	int answer[4];
	for(int i=0; i<4; i++) {
		cin >> answer[i];
	}
	sort(answer,answer + 4);
	for(int i=0; i<4; i++) {
		str = str + to_string(answer[i]);
	}
	
	
	dfs(0);
	
	
	return 0;
}
