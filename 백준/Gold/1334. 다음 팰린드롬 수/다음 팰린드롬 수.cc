#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

vector<string> v;

void convertStr(string tmp, int idx) {
	string rem = tmp.substr(0, tmp.size() / 2);
	if(tmp.size() % 2 == 1) { rem += tmp[tmp.size() / 2]; }
	string str = tmp.substr(0, tmp.size() / 2);
	reverse(str.begin(), str.end());
	v.push_back(rem + str);
	
	// 나머지 0으로 
	rem = tmp.substr(0, idx + 1);
	str = tmp.substr(0, idx + 1);
	string zero = "";
	
	int s = tmp.size();
	
	for(int i=0; i<s - (idx + 1) * 2; i++) { zero += "0"; }
//	cout << rem << " " << str << " " << zero << endl;
	
	reverse(str.begin(), str.end());
	
	v.push_back(rem + zero + str);
}

bool cmp(string a, string b) {
	if(a.size() == b.size()) {
		return a < b;
	}
	
	return a.size() < b.size();
}

void isBigger(string tmp) {
	string rem = tmp.substr(0, tmp.size() / 2);
	if(tmp.size() % 2 == 1) { rem += tmp[tmp.size() / 2]; }
	string str = tmp.substr(0, tmp.size() / 2);
	reverse(str.begin(), str.end());
	
	rem += str;
	
	if(rem > tmp) {
		v.push_back(rem);
	}
}

int main() {
	string str;
	cin >> str;
	
	bool check = false;
	for(int i=0; i<=str.size()/2; i++) {
		if(str.size() % 2 == 0 && i == str.size() / 2) continue;
		string tmp = str;
		int num = str[i] - '0';
		num++;
		if(num == 10) continue;
		
		check = true;
		char c = num + '0';
		tmp[i] = c;
		convertStr(tmp, i);
	}
	
	isBigger(str);
	if(!check) {
		string tmp = "1";
		for(int i=0; i<str.size() - 1; i++) {
			tmp += "0";
		}
		tmp += "1";
		v.push_back(tmp);
	}
	
//	for(int i = 0; i<v.size(); i++) {
//		cout << v[i] << endl;
//	}
	
	sort(v.begin(), v.end(), cmp);
	
	cout << v[0];
} 