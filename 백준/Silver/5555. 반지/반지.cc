#include <iostream>
#include <string>

using namespace std;

string answer;
int result = 0;

void checkString(string tmp) {
	bool check = true;
	string rem = "";
	
	for(int i=0; i<answer.size(); i++) {
		rem += tmp[i];
	}
	int last = answer.size();
	
	if(rem == answer) {
		result += 1;
		return;
	}
	
	for(int i=0; i<tmp.size(); i++) {
		rem.erase(rem.begin());
		rem += tmp[last%10];
		last += 1;
		
		if(rem == answer) {
			result += 1;
			return;
		}
	}
	
}

int main() {
	cin >> answer;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		checkString(tmp);
	}
	
	cout << result;
}